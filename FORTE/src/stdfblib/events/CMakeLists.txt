#############################################################################
# Event FB
#############################################################################
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
SET(SOURCE_GROUP ${SOURCE_GROUP}\\events)

forte_add_sourcefile_hcpp(E_CTU  E_CTUD  E_DELAY  E_D_FF    E_MERGE)
forte_add_sourcefile_hcpp( E_REND   E_RS     E_SELECT  E_SR)
forte_add_sourcefile_hcpp(E_CYCLE   E_DEMUX  E_F_TRIG  E_PERMIT) 
forte_add_sourcefile_hcpp(E_RESTART E_R_TRIG E_SPLIT   E_SWITCH)
forte_add_sourcefile_hcpp(GEN_E_DEMUX GEN_E_MUX)
forte_add_sourcefile_hcpp(ATimeOut E_TimeOut)
