find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

flex_target(flex "lexer.l" "flexer.c" DEFINES_FILE "flexer.h")

bison_target(bison "parser.y" ${CMAKE_CURRENT_SOURCE_DIR}/barser.c DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/barser.h)

add_library(frontend STATIC "parser.cpp" "parser.cpp" ${FLEX_flex_OUTPUTS} ${BISON_bison_OUTPUTS})
