forte_add_module(UJI_FMS "Source code for the UJI_FMS using 61499 FBS")
#This module uses boost libraries. Developed on boost_1_57_0
SET(BOOST_ROOT_PATH "C:\boost_1_57_0" CACHE PATH "Path to boost 1_57_0 root directory.")
forte_add_include_directories(${BOOST_ROOT_PATH})

forte_add_link_directories(${BOOST_ROOT_PATH}/stage/lib)
forte_add_link_library(libboost_serialization-vc120-mt-gd-1_57.lib)

forte_add_subdirectory(FMS_61499_FBS)
forte_add_subdirectory(FMS_CPP_Classes)