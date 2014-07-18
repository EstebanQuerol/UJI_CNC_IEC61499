/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 *******************************************************************************/
#include <string.h>
#include "cyg/kernel/kapi.h"
#include "avrctl.h"
#include "L_S_PORT.h"
#include "L_BUTTON.h"

extern "C" {
#include <cyg/hal/platform_i2c.h>
#include <cyg/hal/i2c_at91sam7sxxx.h>
}

CL_AVR_ctl::Tfrom_avr CL_AVR_ctl::stDataFromAvr[2];
CL_AVR_ctl::Tfrom_avr *CL_AVR_ctl::stIOFromAvr = NULL;

// Input data is double buffered by buffer flipping
cyg_uint32 CL_AVR_ctl::snFromBuf;

CL_AVR_ctl::Tto_avr CL_AVR_ctl::stIOtoAvr;
static cyg_uint8 nDataToAvr[6 + CL_AVR_ctl::sc_nNXTMotorPortsMax];

// Following needed for AVR thread creation
//TODO: Understand why 2K is used
static const cyg_ucount32 nReceiveThreadStackSize = (1312 / sizeof(int)); // was 1536 was 2048; must be local address is available

int pReceiveThreadStack[nReceiveThreadStackSize];
cyg_handle_t unReceiveThreadHandle;
cyg_thread stReceiveThreadObj;

CL_AVR_ctl::TAVRState CL_AVR_ctl::eAvr_state = e_UNINITIALIZED;

// TODO: look into using CThread start() instead
void CL_AVR_ctl::initAVR(void){
  /** initialize AVR if not already initialized */
  if(e_FAILED > eAvr_state){
    cyg_thread_create(12, // cyg_addrword_t sched_info
    receiveThread, // cyg_thread_entry_t *entry
    0, // cyg_addrword_t entry_data
    "AVR thread", // char *name
    &pReceiveThreadStack, // void *stack_base
    nReceiveThreadStackSize, // cyg_ucount32 stack_size
    &unReceiveThreadHandle, // cyg_handle_t *handle
    &stReceiveThreadObj); // cyg_thread *thread

    cyg_thread_resume(unReceiveThreadHandle);

  }
}

//TODO: when moving to CThread change this to void CL_AVR_ctl::run(){
void CL_AVR_ctl::receiveThread(cyg_addrword_t){
  cyg_uint32 nToggleCnt = 0;
  cyg_uint32 nTrys = 30;

  if(e_UNINITIALIZED == eAvr_state){

    at91sam7sxxx_i2c_init(); //i2c init for motors and ?

    memset(&stIOtoAvr, 0, sizeof(stIOtoAvr));
    initMotor();
    sendToAVR();

    snFromBuf = 0;
    stIOFromAvr = &stDataFromAvr[1];

    eAvr_state = e_INITIALIZED;
  }

  while(1){
    cyg_thread_delay(2); // 2 clock cycles = 3MHz*2=.6ms=600ms... at91 ARM7 p.18 clock rate 30MHz=.3ms
    //(old comment:(in case correct: every 2 ms ?)
    nToggleCnt++;

    switch (eAvr_state){

      case e_INITIALIZED:
        if(!atmega48_link_init()){
          cyg_uint32 a_unPortNum;
          eAvr_state = e_READY;
          /* reset all sensor ports */
          for(a_unPortNum = 1; FORTE_L_S_PORT::sc_nNXTSensorPortsMax >= a_unPortNum; a_unPortNum++){
            FORTE_L_S_PORT::lmsInit1Port(a_unPortNum);
          }
        }
        else{
          if(!nTrys){
            eAvr_state = e_FAILED;
          }
        }

        break;
      case e_FAILED:
        nTrys = 0;
        cyg_thread_exit();
        break;
      case e_COMMAND_PENDING:
        if(nToggleCnt & 0x1){
          if(!sendToAVR())
            eAvr_state = e_READY;
        }
        //no break here
      case e_READY:

        if(!(nToggleCnt & 0x1)){
          receiveFromAVR();
        }
        break;

      default:
        break;
    }
  }
}

// --- directly AVR related -------------------------------------------------------

cyg_uint32 CL_AVR_ctl::sendToAVR(void){
  cyg_uint32 nCheckByte = 0;
  cyg_uint8 *nInBuf = nDataToAvr;
  cyg_uint8 *nOutBuf = (cyg_uint8 *) (&stIOtoAvr);
  cyg_uint8 *nEndChk = nOutBuf + sizeof(stIOtoAvr);

  while(nOutBuf < nEndChk){
    nCheckByte += *nOutBuf;
    *nInBuf++ = *nOutBuf++;
  }

  *nInBuf = ~nCheckByte;

  return atmega48_send(nDataToAvr, sizeof(nDataToAvr));
}

cyg_int32 CL_AVR_ctl::receiveFromAVR(void){
  memset(&stDataFromAvr[snFromBuf], 0, sizeof(Tfrom_avr));
  atmega48_receive((cyg_uint8 *) &stDataFromAvr[snFromBuf], sizeof(Tfrom_avr));

  return unpackReceivedData();
}

cyg_int32 CL_AVR_ctl::unpackReceivedData(void){
  cyg_uint8 nCheck_sum = 0;
  cyg_uint8 *n_p;
  cyg_uint8 *nEnd;

  // calc the checksum
  n_p = (cyg_uint8 *) (&stDataFromAvr[snFromBuf]);
  nEnd = n_p + sizeof(Tfrom_avr);
  while(n_p < nEnd){
    nCheck_sum += *n_p++;
  }
  if(0xff != nCheck_sum)
    return scm_nErrAvrChecksum;

  stIOFromAvr = &stDataFromAvr[snFromBuf];

  snFromBuf = ((snFromBuf + 1) & 0x1); // get next buffer

  FORTE_L_BUTTON::updateButtons(stIOFromAvr->nButtonsVal);

  return scm_nErrAvrnum;
}

//--- Sensors ----------------------------------------------------------------------
int CL_AVR_ctl::getSensorState(cyg_uint32 pa_nInputPortPin){
  int rc = 0;
  if(FORTE_L_S_PORT::sc_nNXTSensorPortsMax > pa_nInputPortPin){
    rc = stIOFromAvr->nADvalue[pa_nInputPortPin];
  }
  return rc;
}

//------> Control the power supplied to an input sensor
// The power to the sensor is controlled by a bit in
// each of the two nibbles of the byte. There is one
// bit for each of the four sensors. if the low nibble
// bit is set then the sensor is "ACTIVE" and 9v is
// supplied to it but it will be pulsed off to allow
// the sensor to be be read. A 1 in the high nibble
// indicates that it is a 9v always on sensor and
// 9v will be supplied constantly. If both bits are
// clear then 9v is not supplied to the sensor.
// Having both bits set is currently not supported.
//
//  Need to use to set the power for color sensor!!
void CL_AVR_ctl::sensorAvrSetInPwr(cyg_uint32 pa_nInputPortPin, cyg_uint32 pa_nPowerType){
  if(FORTE_L_S_PORT::sc_nNXTSensorPortsMax > pa_nInputPortPin && pa_nPowerType <= 2){
    cyg_uint32 val = (pa_nPowerType & 0x2 ? 0x10 << pa_nInputPortPin : 0) | ((pa_nPowerType & 1) << pa_nInputPortPin);
    stIOtoAvr.nInputPower &= ~(0x11 << pa_nInputPortPin);
    stIOtoAvr.nInputPower |= (val & 0xFF);
    if(e_READY == eAvr_state)
      eAvr_state = e_COMMAND_PENDING;
  }
}

int CL_AVR_ctl::sensorAvrGetInPwr(cyg_uint32 pa_nOutputPort){
  int rc = 0;
  if(FORTE_L_S_PORT::sc_nNXTSensorPortsMax > pa_nOutputPort)
    rc = ((stIOtoAvr.nInputPower & (0x11 << pa_nOutputPort)) >> pa_nOutputPort);
  return rc;
}

//-- HW modes -----------------------------------------------------------------------
void CL_AVR_ctl::setSambaMode(void){

  stIOtoAvr.nPower = 0xA5;
  stIOtoAvr.nPwmFreq = 0x5A;
  stIOtoAvr.nPwmOutPercent[0] = 0;
  stIOtoAvr.nPwmOutPercent[1] = 0;
  stIOtoAvr.nPwmOutPercent[2] = 0;
  stIOtoAvr.nPwmOutPercent[3] = 0;
  stIOtoAvr.nOutputMode = 0;
  stIOtoAvr.nInputPower = 0;

  if(e_READY == eAvr_state)
    eAvr_state = e_COMMAND_PENDING;
}

void CL_AVR_ctl::setShutdownMode(void){
  stIOtoAvr.nPower = 0x5A;
  stIOtoAvr.nPwmFreq = 0x00;

  stIOtoAvr.nPwmOutPercent[0] = 0;
  stIOtoAvr.nPwmOutPercent[1] = 0;
  stIOtoAvr.nPwmOutPercent[2] = 0;
  stIOtoAvr.nPwmOutPercent[3] = 0;
  stIOtoAvr.nOutputMode = 0;
  stIOtoAvr.nInputPower = 0;

  if(e_READY == eAvr_state)
    eAvr_state = e_COMMAND_PENDING;
}

// ---- Motor -----------------------------------------------------------------------
//--- percent power last sent to the motor on port #pa_nOutputPort
void CL_AVR_ctl::initMotor(){
  // Motor initialization goes through the i2c btw avr and arm7
  stIOtoAvr.nPower = 0;
  stIOtoAvr.nPwmFreq = 8;
  stIOtoAvr.nPwmOutPercent[0] = 0;
  stIOtoAvr.nPwmOutPercent[1] = 0;
  stIOtoAvr.nPwmOutPercent[2] = 0;
  stIOtoAvr.nPwmOutPercent[3] = 0;
  stIOtoAvr.nOutputMode = 0;
  stIOtoAvr.nInputPower = 0;

  stIOtoAvr.nOutputMode &= ~(1 << 0); // output port = 0 = A
  stIOtoAvr.nOutputMode &= ~(1 << 1); // output port = 1 = B
  stIOtoAvr.nOutputMode &= ~(1 << 2); // output port = 2 = C
}

void CL_AVR_ctl::motorAvrSetPwrBrake(cyg_uint32 pa_nOutputPort, cyg_int32 pa_nPercent, int pa_nBrake){

  // cyg_bool is really int so b can't passed in as bool
  if(sc_nNXTMotorPortsMax > pa_nOutputPort){
    stIOtoAvr.nPwmOutPercent[pa_nOutputPort] = pa_nPercent;
    if(0 == pa_nBrake)
      stIOtoAvr.nOutputMode |= (1 << pa_nOutputPort);
    else
      stIOtoAvr.nOutputMode &= ~(1 << pa_nOutputPort);
    if(e_READY == eAvr_state)
      eAvr_state = e_COMMAND_PENDING;
  }
}

int CL_AVR_ctl::motorAvrGetPwr(cyg_uint32 pa_nOutputPort){
  int rc = 0;
  if(sc_nNXTMotorPortsMax > pa_nOutputPort)
    rc = stIOtoAvr.nPwmOutPercent[pa_nOutputPort];
  return rc;
}

unsigned int CL_AVR_ctl::motorAvrGetBrake(cyg_uint32 pa_nOutputPort){
  unsigned int rc = 0;
  if(sc_nNXTMotorPortsMax > pa_nOutputPort)
    rc = ((stIOtoAvr.nOutputMode & (1 << pa_nOutputPort)) >> pa_nOutputPort);
  return rc;
}

//--- Battery Power  related --------------------------------------------------------
unsigned int CL_AVR_ctl::getBattery(void){
  return stIOFromAvr->nBattery;
}


