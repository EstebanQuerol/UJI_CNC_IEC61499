/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _BASICFB_H_
#define _BASICFB_H_

#include "funcbloc.h"
#include "./datatypes/forte_uint.h"


#ifndef FORTE_BASIC_FB_DATA_ARRAY  //with this check we can overwrite this define in a platform specific file (e.g., config.h)

/*! Define that adds the data array to a Basic FB
 * May be overwritten by a platform specific version that adapts for example some alignment requirements
 */
#define FORTE_BASIC_FB_DATA_ARRAY(a_nNumEOs, a_nNumDIs, a_nNumDOs, a_nNumIntVars, a_nNumAdapters) \
  union{ \
    TForteByte m_anFBConnData[genFBConnDataSizeTemplate<a_nNumEOs, a_nNumDIs, a_nNumDOs>::value]; \
  };\
  union{ \
    TForteByte m_anFBVarsData[genBasicFBVarsDataSizeTemplate<a_nNumDIs, a_nNumDOs, a_nNumIntVars, a_nNumAdapters>::value]; \
  };

#endif



/*!\ingroup CORE
 * \brief structure to hold the data needed for creating the internal vars
 *
 */
struct SInternalVarsInformation{
  int m_nNumIntVars; //!< Number of internal vars
  const CStringDictionary::TStringId *const m_aunIntVarsNames; //!< List of the internalvarsnames
  const CStringDictionary::TStringId *const m_aunIntVarsDataTypeNames; //!< List of the data type names for the internal vars
};

/*!\ingroup CORE
 *
 * \brief Class for handling firmware basic function blocks.
 *
 * @author GuGr
 * @version 20090801/mmm - added const CStringDictionary::TStringId pa_nInstanceNameId to constructor parameters
 * @version 20060207/AZ - Removed number of EOs in CFunctionBlock-Constructor
 * @version 20060206/AZ - Changed event connection handling
 * @version 20051019/GuGr - First version as basis for interface description
 */
class CBasicFB : public CFunctionBlock {
public:
/*!\brief The main constructur for a basic function block.
 */
  CBasicFB(CResource *pa_poSrcRes,
           const SFBInterfaceSpec *pa_pstInterfaceSpec,
           const CStringDictionary::TStringId pa_nInstanceNameId,
           const SInternalVarsInformation *pa_pstVarInternals,
           TForteByte *pa_acFBConnData, TForteByte *pa_acBasicFBVarsData);
  virtual ~CBasicFB();

/*!\brief Get the pointer to a variable of the FB.
 *
 * \param pa_acVarName Reference to the varible name.
 * \return Pointer to the variable or 0. The variable may be input, output or in
 *         the case of a BFB an internal var.
 */
  virtual CIEC_ANY* getVar(const char *pa_acVarName);

  virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);

/*!\brief Get the pointer to a internal variable of the basic FB.
 *
 * \param pa_nInternalName StringId of the internal variable name.
 * \return Pointer to the internal variable or 0.
 */
  CIEC_ANY *getInternalVar(CStringDictionary::TStringId pa_nInternalName){
    unsigned int unVarId = getPortId(pa_nInternalName, cm_pstVarInternals->m_nNumIntVars, cm_pstVarInternals->m_aunIntVarsNames);
    return (cg_unInvalidPortId == unVarId) ? 0 : getVarInternal(unVarId);
  }

  template<unsigned int ta_nNumDIs, unsigned int ta_nNumDOs, unsigned int ta_nNumIntVars, unsigned int ta_nNumAdapters=0>
  struct genBasicFBVarsDataSizeTemplate{
      enum { value = ((sizeof(TDataConnectionPtr) + sizeof(CIEC_ANY)) * ta_nNumIntVars +
                     genFBVarsDataSizeTemplate<ta_nNumDIs, ta_nNumDOs, ta_nNumAdapters>::value)
           };
  };

  static size_t genBasicFBVarsDataSize(unsigned int pa_nNumDIs, unsigned int pa_nNumDOs, unsigned int pa_nNumIntVars, unsigned int pa_nNumAdapters=0){
        return ((sizeof(TDataConnectionPtr) + sizeof(CIEC_ANY)) * pa_nNumIntVars +
                genFBVarsDataSize(pa_nNumDIs, pa_nNumDOs, pa_nNumAdapters));
  };

protected:
  /*! \brief Get the internal variable with given number
   *
   * Attention this function will not perform any range checks on the pa_nVarIntNum parameter!
   * @param pa_nVarIntNum number of the internal variable starting with 0
   * @return pointer to the internal variable
   */
  CIEC_ANY *getVarInternal(unsigned int pa_nVarIntNum){
    return m_aoInternals + pa_nVarIntNum;
  }

  CIEC_UINT m_nECCState; //! the current state of the ecc. start value is 0 = initial state id
  const SInternalVarsInformation * const cm_pstVarInternals; //!< struct holding the information on the internal vars.
private:
  CIEC_ANY *m_aoInternals;                 //!< A list of pointers to the internal variables.
};

#endif /*_BASICFB_H_*/
