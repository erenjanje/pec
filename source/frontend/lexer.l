%option reentrant
%option header-file="flexer.h"
%option outfile="flexer.c"
%option nounistd
%option never-interactive
%option noyywrap
%option bison-bridge

%top{
#include "barser.h"
}

ID [a-z_][a-zA-Z0-9_]*

%%

ID { return 0; }

%%

    const char* ZORT = "zartzurtzartzurt";
