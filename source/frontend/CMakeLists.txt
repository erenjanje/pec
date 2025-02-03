find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

flex_target(flex "meta/flexer.l" "meta/flexer.cpp" DEFINES_FILE "meta/flexer.hpp")

bison_target(bison "meta/barser.y" ${CMAKE_CURRENT_SOURCE_DIR}/meta/barser.cpp DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/meta/barser.hpp)

add_library(frontend STATIC "parser.cpp" "parser.hpp" ${FLEX_flex_OUTPUTS} ${BISON_bison_OUTPUTS})
