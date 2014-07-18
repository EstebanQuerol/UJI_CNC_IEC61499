forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
SET(SOURCE_GROUP ${SOURCE_GROUP}\\arch)

add_subdirectory(ecos)
add_subdirectory(netos)
add_subdirectory(posix)
add_subdirectory(win32)
add_subdirectory(be_m1)

forte_add_sourcefile_hcpp(timerha devlog)

