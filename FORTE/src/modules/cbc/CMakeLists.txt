forte_add_module(CBC "Function Blocks for KIPR CBCv2 BotBall (Chumby based Linux)")

if(FORTE_MODULE_CBC)

if(FORTE_ARCHITECTURE_POSIX)
else(FORTE_ARCHITECTURE_POSIX)
	MESSAGE("The Function Blocks for KIPR CBCv2 BotBall are only supported for FORTE on Posix platforms. Disabled Module!")
    set(FORTE_MODULE_POWERLINK OFF)
endif(FORTE_ARCHITECTURE_POSIX)

forte_add_include_directories(${PROJECT_BINARY_DIR}/libc/includes)
forte_add_link_directories(${PROJECT_BINARY_DIR}/libc/lib)

# Have libc under bin/cbc by default, but the location can be changed
forte_add_link_library(${PROJECT_BINARY_DIR}/libc/lib/libcbc.a 
					   ${PROJECT_BINARY_DIR}/libc/lib/libshared.a 
					   ${PROJECT_BINARY_DIR}/libc/lib/libtrack.a 
					   -static-libgcc)

#Rename forte to forte.bin in CMake
forte_add_post_build_command(COMMAND cp forte forte.bin
                             WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src
                             COMMENT "Create target image (forte.bin)...")
                             


                             
forte_add_sourcefile_hcpp(Beeper
						  CBC_OFF)
#############################################################################
# CBC FBs MOTORs
#############################################################################

forte_add_sourcefile_hcpp(MotorDC
						  MotorPOS 
						  MotorPWR 
						  MotorVEL
						  Servo)

#############################################################################
# CBC FBs SENSORs
#############################################################################

forte_add_sourcefile_hcpp(Digital
                          Analog
                          Analog08 
                          Analog10
                          Button
                          BlackButton 
						  ButtonA 
						  ButtonB 
						  DownButton 
						  UpButton 
						  LeftButton 
						  RightButton)

#############################################################################
# CBC FBs CAMERA
#############################################################################
forte_add_sourcefile_hcpp(TrkBlob
						  TrkBox 
						  TrkEclipse 
						  TrkCentroid
						  Camera)

#############################################################################
# CBC FBs iRobot iCREATE
#############################################################################
forte_add_sourcefile_hcpp(iCreateAdvButton 
						  iCreatePlayButton
						  iCreateAdvLED
						  iCreateBattery
						  iCreateBumper 
						  iCreateCliffSensors
						  iCreateDemo 		
						  iCreateDrive 				   
						  iCreateDropBump 						  
						  iCreateIR 
						  iCreateMgt
						  iCreatePlayLED 
						  iCreatePowerLED
						  iCreateWall
						  iCreateWheels)

endif(FORTE_MODULE_CBC)