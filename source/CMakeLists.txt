add_executable(pec "pec.cpp")

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
set_target_properties(pec PROPERTIES DEBUG_POSTFIX _msvc_debug)
else()
set_target_properties(pec PROPERTIES DEBUG_POSTFIX _debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
endif()

add_subdirectory("frontend")

target_link_libraries(pec PRIVATE frontend)
