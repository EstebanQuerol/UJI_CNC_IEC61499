/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: L_BUTTON
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2011-09-14/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _L_BUTTON_H_
#define _L_BUTTON_H_

#include <funcbloc.h>
#include <forte_uint.h>
#include <forte_bool.h>

class FORTE_L_BUTTON : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_L_BUTTON)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_UINT &B(){
      return *static_cast<CIEC_UINT*>(getDI(1));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_BOOL &Q(){
      return *static_cast<CIEC_BOOL*>(getDO(1));
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

    FORTE_FB_DATA_ARRAY(2, 2, 2, 0)
    ;

    void executeEvent(int pa_nEIID);

    // Button value / states
    static TForteUInt16 sm_unButtonVal;
    static TForteUInt16 sm_unPrevButtonVal;
    static TForteUInt16 sm_unDebounceCounter; // was 25 (timing problem so 3) scm_unButtonDebounceCnt;
    // based on sample rate of                     //now 3 was 25; due to timing problem
    static const TForteUInt16 scm_unButtonDebounceCnt = 3; // now 1= no debouncing was 3 orig

    static TForteUInt16 s_ButtonNum;

    // ---- Buttons -------------------------------------------------------------------------
    // buttons are L ENTER R / ESC
    // measured values  (should RETEST with batteries and different NXT)
    // so other classes and FBs can test the buttons pressed

    static const TForteUInt16 sc_nButton_ENTER = 2047; //0x01 Measured avg. 2053 0x01
    static const TForteUInt16 sc_nButton_ESC = 1023; // 0x02  Measured avg. 1017 0x08
    static const TForteUInt16 sc_nButton_RIGHT = 407; // 0x04  Measured avg. 403 0x04
    static const TForteUInt16 sc_nButton_LEFT = 127; //  0x08 Measured avg. 125  0x02

    static const TForteUInt16 sc_nButton_ENTERandESC = 3070; // 0x03=(1||2) Measured avg. 3068
    static const TForteUInt16 sc_nButton_ENTERandLEFT = 2456; // 0x05=(1||4)  Measured avg. 2451
    static const TForteUInt16 sc_nButton_ENTERandRIGHT = 2178; // 0x09=(1||8)  Measured avg. 2173

    static const TForteUInt16 sc_nButton_LEFTandRIGHT = 215; // Measured avg. 200-230 avg=215
    // sc_nButton_LEFTandESC     750-990 avg =870  same as RIGHTandESC = cannot uniquely recognize
    // sc_nButton_RIGHTandESC    750-990 avg =870  same as LEFTandESC  = cannot uniquely recognize

    static const TForteUInt16 sc_nButton_LOWEST = 125; // =B_LEFT;
    static const TForteUInt16 sc_nButton_HIGH = 3080;

    static const TForteUInt16 sc_nENTERButtonPushed = 0x01;
    static const TForteUInt16 sc_nRIGHTButtonPushed = 0x02;
    static const TForteUInt16 sc_nLEFTButtonPushed = 0x04;
    static const TForteUInt16 sc_nESCButtonPushed = 0x08;

    static const TForteUInt16 sc_nButton_Shutdown;

    static bool s_bInDebounceState;

    static TForteUInt16 getButtonVal(void);
    static TForteUInt16 getButtonNum(void);
    static const bool isAButtonPressed();
    static cyg_uint16 buttonsDecode();
    static void checkShutdown();

  public:
    static void updateButtons(TForteUInt16 pa_unCurrentButtonVal);

    FUNCTION_BLOCK_CTOR(FORTE_L_BUTTON){
  };

  virtual ~FORTE_L_BUTTON(){};
};

#endif //close the ifdef sequence from the beginning of the file
