/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateDrive
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-08-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "iCreateDrive.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_iCreateDrive, g_nStringIdiCreateDrive)

const CStringDictionary::TStringId FORTE_iCreateDrive::scm_anDataInputNames[] = {g_nStringIdRadius, g_nStringIdSpeed, g_nStringIdLtSpeed, g_nStringIdRtSpeed, g_nStringIdClockwise};

const CStringDictionary::TStringId FORTE_iCreateDrive::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_iCreateDrive::scm_anDataOutputNames[] = {g_nStringIdRadiusOut, g_nStringIdSpeeds, g_nStringIdVelocity, g_nStringIdVelocityLt, g_nStringIdVelocityRt, g_nStringIdAngle, g_nStringIdAngleTotal, g_nStringIdDistance};

const CStringDictionary::TStringId FORTE_iCreateDrive::scm_anDataOutputTypeIds[] = {g_nStringIdINT, g_nStringIdARRAY, 3, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT};

const TForteInt16 FORTE_iCreateDrive::scm_anEIWithIndexes[] = {-1, 0, 3, 5, 8, -1};
const TDataIOID FORTE_iCreateDrive::scm_anEIWith[] = {1, 0, 255, 1, 255, 1, 4, 255, 3, 2, 255};
const CStringDictionary::TStringId FORTE_iCreateDrive::scm_anEventInputNames[] = {g_nStringIdStop, g_nStringIdArc, g_nStringIdStraight, g_nStringIdSpin, g_nStringIdDirect, g_nStringIdGetInfo};

const TDataIOID FORTE_iCreateDrive::scm_anEOWith[] = {0, 255, 2, 3, 4, 5, 6, 7, 255, 1, 255};
const TForteInt16 FORTE_iCreateDrive::scm_anEOWithIndexes[] = {-1, 0, -1, -1, -1, 2, 9};
const CStringDictionary::TStringId FORTE_iCreateDrive::scm_anEventOutputNames[] = {g_nStringIdStopO, g_nStringIdArcO, g_nStringIdStraightO, g_nStringIdSpinO, g_nStringIdDirectO, g_nStringIdGetInfoO};

const SFBInterfaceSpec FORTE_iCreateDrive::scm_stFBInterfaceSpec = {
  6,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  6,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  8,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_iCreateDrive::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventStopID:
      create_stop();
      sendOutputEvent(scm_nEventStopOID);
      break;
    case scm_nEventArcID:
      create_drive(Speed(), Radius());
      RadiusOut() = Radius();
      sendOutputEvent(scm_nEventArcOID);
      break;
    case scm_nEventStraightID:
      create_drive_straight(Speed());
      sendOutputEvent(scm_nEventStraightOID);
      break;
    case scm_nEventSpinID:
      if(true == Clockwise())
        create_spin_CW(Speed());
      else
        create_spin_CCW(Speed());
      sendOutputEvent(scm_nEventSpinOID);
      break;
    case scm_nEventDirectID:
      create_drive_direct(LtSpeed(), RtSpeed());
      sendOutputEvent(scm_nEventDirectOID);
      break;
    case scm_nEventGetInfoID:
      create_velocity();
      Velocity() = static_cast<TForteInt16>(gc_vel);
      VelocityLt() = static_cast<TForteInt16>(gc_lvel);
      VelocityRt() = static_cast<TForteInt16>(gc_rvel);

      create_angle();
      Angle() = static_cast<TForteInt16>(gc_angle);
      AngleTotal() = static_cast<TForteInt16>(gc_total_angle);

      create_distance();
      Distance() = static_cast<TForteInt16>(gc_distance);

      sendOutputEvent(scm_nEventGetInfoOID);
      break;
  }
}

