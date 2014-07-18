/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_S_PORT
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-08-30/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _L_S_PORT_H_
#define _L_S_PORT_H_

#include <funcbloc.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_L_S_PORT : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L_S_PORT)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*> (getDI(0));
    }
    ;

    CIEC_UINT &PORT(){
      return *static_cast<CIEC_UINT*> (getDI(1));
    }
    ;

    CIEC_UINT &T(){
      return *static_cast<CIEC_UINT*> (getDI(2));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*> (getDO(0));
    }
    ;

    CIEC_UINT &ST(){
      return *static_cast<CIEC_UINT*> (getDO(1));
    }
    ;

    static const TEventID scm_nEventINITID = 0;
    static const TEventID scm_nEventREQID = 1;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventINITOID = 0;
    static const TEventID scm_nEventCNFID = 1;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(2, 3, 2, 0)
    ;

    void executeEvent(int pa_nEIID);
    static void lmsRS485PortInit(void);
    static TForteUInt32 lmsGetSensorPluggedIntoPort(TForteUInt32 pa_nPort);

    //TODO: move supported sensors, max sensor and motor constants into LMS_DEV
    // Supported Sensors

    static const TForteUInt32 e_LIGHTLED = 1;
    static const TForteUInt32 e_LIGHTDETECTOR = 2;
    static const TForteUInt32 e_LIGHTSENSOR = 101; // sensor with multiple parts will start at 100
    static const TForteUInt32 e_TOUCH = 3;
    static const TForteUInt32 e_SOUND = 4;
    static const TForteUInt32 e_ADSENSOR = 5;
    //    static const TForteUInt32        e_ULTRASONIC=6;                future
    //    static const TForteUInt32        e_RGB_LIGHT_LED_RED=7;         future
    //    static const TForteUInt32        e_RGB_LED_GREEN=8;             future
    //    static const TForteUInt32        e_RGB_LED_BLUE=9;              future
    //    static const TForteUInt32        e_COLOR_NXT2=102 ;             future

    //TODO: support exacter port error codes
    //     e_PORT_ALREADY_USED,
    //     e_PORT_NUMBER_UNDEFINED,
    //     e_SENSOR_TYPE_UNDEFINED,
    //     e_SHOULD_NEVER_GET_HERE

  public:
    static const TForteUInt32 e_UNUSED = 0; // has to be public since used in initialization
    static const TForteUInt32 sc_nRS485Port4 = 3; // Port 4, but array index 3

    static const TForteUInt32 sc_nNXTSensorPortsMax = 4;
    static const TForteUInt32 sc_anSensorPortPin[4];

    static void lmsInit1Port(TForteUInt32 pa_nPort);

    static bool lmsPlugIntoPort(TForteUInt32 pa_nPort, TForteUInt32 pa_nInputType);

    static bool lmsIsADsensor(TForteUInt32 pa_nInputType);
    static bool lmsIsLTsensor(TForteUInt32 pa_nInputType);

    FUNCTION_BLOCK_CTOR(FORTE_L_S_PORT){};

  virtual ~FORTE_L_S_PORT(){};

};

#endif //close the ifdef sequence from the beginning of the file
