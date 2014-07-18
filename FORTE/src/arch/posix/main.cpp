/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <fortealloc.h>
#include <stdio.h>
#include <signal.h>
#include "../../forte.h"
#include <RMT_DEV.h>

#ifdef CONFIG_POWERLINK_USERSTACK
#include <EplWrapper.h>
#endif

/*!\brief Check if the correct endianess has been configured.
 *
 * If the right endianess is not set this function will end FORTE.
 */
void checkEndianess();

//this keeps away a lot of rtti and exception handling stuff
extern "C" void __cxa_pure_virtual(void){
  //TODO maybe add some reporting here
  //Although we should never get here
  //if we are here something very very bad has happened e.g., stack overflow or other memory corruption

}

RMT_DEV *poDev = 0;

void endForte(int pa_nSig){
  (void) pa_nSig;
  if(0 != poDev){
    poDev->changeFBExecutionState(cg_nMGM_CMD_Kill);
  }
}

/*!\brief Creates the Device-Object
 * \param pa_acMGRID A string containing IP and Port like [IP]:[Port]
 */
void createDev(const char *pa_acMGRID){

  signal(SIGINT, endForte);
  signal(SIGTERM, endForte);
  signal(SIGHUP, endForte);

#ifdef CONFIG_POWERLINK_USERSTACK
  CEplStackWrapper::eplMainInit();
#endif

  poDev = new RMT_DEV;

  poDev->setMGR_ID(pa_acMGRID);
  poDev->startDevice();
  poDev->MGR.getResourceEventExecution()->joinEventChainExecutionThread();
  delete poDev;
}

/*!\brief Lists the help for FORTE
 *
 */
void listHelp(){
  printf("\nUsage of FORTE:\n");
  printf("   -h\t lists this help.\n");
  printf("\n");
  printf("   -c\t sets the destination for the connection.\n");
  printf("     \t Usage: forte -c <IP>:<Port>");
  printf("\n");
}

int main(int argc, char *arg[]){

  checkEndianess();

  DEVLOG_INFO("Memory size CFunctionBlock : %d \n", sizeof(CFunctionBlock));
  DEVLOG_INFO("Memory size CDevice : %d \n", sizeof(CDevice));
  DEVLOG_INFO("Memory size CResource : %d \n", sizeof(CResource));
  DEVLOG_INFO("Memory size CConnection : %d \n", sizeof(CConnection));
  DEVLOG_INFO("Memory size CDataConnection : %d \n", sizeof(CDataConnection));
  DEVLOG_INFO("Memory size CEventConnection : %d \n", sizeof(CEventConnection));

  DEVLOG_INFO("Memory size int : %d \n", sizeof(int));
  DEVLOG_INFO("Memory size long : %d \n", sizeof(long));

  DEVLOG_INFO("Memory size int8_t : %d \n", sizeof(int8_t));
  DEVLOG_INFO("Memory size int16_t : %d \n", sizeof(int16_t));
  DEVLOG_INFO("Memory size int32_t : %d \n", sizeof(int32_t));
  DEVLOG_INFO("Memory size int64_t : %d \n", sizeof(int64_t));

  if(argc <= 1){ //! Default Value (localhost:61499)
    createDev("localhost:61499");
  }
  else{
    if(strcmp("-c", arg[1]) == 0){ //! sets the destination for the connection
      createDev(arg[2]);
    }
    else{ //! Lists the help for FORTE
      listHelp();
    }
  }
  return 0;
}

void checkEndianess(){
  int i = 1;
  char *p = (char *) &i;
  if(p[0] == 1){
    //we are on a little endian platform
#ifdef FORTE_BIG_ENDIAN
    DEVLOG_ERROR("Wrong endianess configured! You are on a little endian platform and have configured big endian!\n");
    exit(-1);
#endif
  }
  else{
    //we are on a big endian platform
#ifdef FORTE_LITTLE_ENDIAN
    DEVLOG_ERROR("Wrong endianess configured! You are on a big endian platform and have configured little endian!\n");
    exit(-1);
#endif
  }
}

