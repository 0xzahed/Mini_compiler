%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.tab.h"
%}

%%

[ \t]           ; 
\n              { return '\n'; }
[0-9]+          { yylval.ival = atoi(yytext); return NUMBER; }
\"[^\"]*\"      { 
    yytext[yyleng-1] = '\0';
    yylval.sval = strdup(yytext+1);
    return STRING; 
}
"true"          { yylval.bval = 1; return BOOLEAN; }
"false"         { yylval.bval = 0; return BOOLEAN; }
"int"           { return INT; }
"return"        { return RETURN; }
"if"            { return IF; }
"then"          { return THEN; }
"else"          { return ELSE; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"length"        { return LENGTH; }
"substr"        { return SUBSTR; }
"min"           { return MIN; }
"max"           { return MAX; }
"print"         { return PRINT; }
[a-zA-Z][a-zA-Z0-9]* { 
    yylval.sval = strdup(yytext);
    return IDENTIFIER; 
}
"="             { return ASSIGN; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULT; }
"/"             { return DIV; }
"%"             { return MOD; }
"^"             { return POWER; }
"<"             { return LT; }
">"             { return GT; }
"&&"            { return AND; }
"||"            { return CONCAT; }
"**"            { return REPEAT; }
"++"            { return INC; }
"--"            { return DEC; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
":"             { return ':'; }
";"             { return ';'; }
","             { return ','; }

.               { fprintf(stderr, "Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}