/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef SOCKHAND_H_
#define SOCKHAND_H_


#include <sockLib.h>
#include <selectLib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//these two should be the last includes in the list
#include "../fdselecthand.h"
#include "../bsdsocketinterf.h"


//! Type needed by the class CIPCommLayer
class CIPComSocketHandler : public CFDSelectHandler, public CBSDSocketInterface{
  public:
    //! Type needed by the class CIPCommLayer
    typedef CFDSelectHandler::TFileDescriptor TSocketDescriptor;

    static const TSocketDescriptor scm_nInvalidSocketDescriptor = CFDSelectHandler::scm_nInvalidFileDescriptor;
  private:
    //as this class is just a place holder for the others we don't want to have an instance of it
    CIPComSocketHandler();
    CIPComSocketHandler(const CIPComSocketHandler&);
    CIPComSocketHandler& operator =(const CIPComSocketHandler &);
    ~CIPComSocketHandler();
};

#endif /* SOCKHAND_H_ */
