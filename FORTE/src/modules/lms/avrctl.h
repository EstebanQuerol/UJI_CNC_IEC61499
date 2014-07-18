/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 *******************************************************************************/

#ifndef CL_AVR_CTL_H_
#define CL_AVR_CTL_H_

#include "cyg/kernel/kapi.h"
#include <forte_uint.h>
#include "L_S_PORT.h"

class CL_AVR_ctl{

  public:
    static const unsigned int sc_nNXTMotorPortsMax = 3;

    // no constructor / destructor if all methods are static
    // --- directly AVR related -------------------------------------------------------
    static void initAVR(void);

    //--- Sensors ----------------------------------------------------------------------
    static int getSensorState(cyg_uint32 pa_nInputPortPin); //rtn might be used
    static void sensorAvrSetInPwr(cyg_uint32 pa_nInputPortPin, cyg_uint32 pa_nPowerType);
    static int sensorAvrGetInPwr(cyg_uint32 pa_nInputPortPin); //rtn might be used

    //-- HW modes -----------------------------------------------------------------------
    static void setSambaMode(void);
    static void setShutdownMode(void);

    // ---- Motor -----------------------------------------------------------------------
    static void motorAvrSetPwrBrake(cyg_uint32 pa_nOutputPort, cyg_int32 pa_nPercent, int pa_nBrake);
    static int motorAvrGetPwr(cyg_uint32 pa_nOutputPort);
    static unsigned int motorAvrGetBrake(cyg_uint32 pa_nOutputPort);

    //--- Battery Power  related --------------------------------------------------------
    static unsigned int getBattery(void);
    

  private:

    // --- directly AVR related -------------------------------------------------------
    static cyg_uint32 sendToAVR(void); // rtn needed   !!! can be changed to unsigned int???
    static cyg_int32 receiveFromAVR(void); // rtn not checked, but leave for error chking later

    static cyg_int32 unpackReceivedData(void); // rtn not checked, but leave for error chking later

    static void receiveThread(cyg_addrword_t pa_index);
    static void initMotor();

    static const unsigned int scm_nErrAvrChecksum = -1;
    static const unsigned int scm_nErrAvrnum = 0;

    // The following Raw values are read/written directly to the AVR. so byte
    // order, packing etc. must match
    typedef struct {
        // Raw values
        cyg_uint8 nPower;
        cyg_uint8 nPwmFreq; // pwm = power mgt
        cyg_int8 nPwmOutPercent[CL_AVR_ctl::sc_nNXTMotorPortsMax];
        cyg_int8 nPad;
        cyg_uint8 nOutputMode;
        cyg_uint8 nInputPower;
    }__attribute__((packed)) Tto_avr;

    typedef struct {
        // Raw values
        cyg_uint16 nADvalue[FORTE_L_S_PORT::sc_nNXTSensorPortsMax]; // raw 10 bit Analog to digital value
        cyg_uint16 nButtonsVal;
        cyg_uint16 nBattery;
        cyg_uint8 nChkSum; // pad / extra space for a ChkSum
    }__attribute__((packed)) Tfrom_avr;

    static Tfrom_avr stDataFromAvr[2];
    static Tfrom_avr *stIOFromAvr;

    static Tto_avr stIOtoAvr;

    // Input data is double buffered by buffer flipping
    static cyg_uint32 snFromBuf;

    typedef enum EAVRState{
      e_UNINITIALIZED = 0, e_INITIALIZED, e_FAILED, e_READY, e_COMMAND_PENDING
    } TAVRState;

    static TAVRState eAvr_state;
};

#endif /* CL_AVR_CTL_H_ */
