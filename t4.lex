%{
#include <stdlib.h>
#include <string.h>
#include "t4.tab.h"

extern YYSTYPE yylval;
int entero;
double doble;
char *str;
char *tipo;
%}

%%
[0-9][0-9]*							{entero = atoi(yytext); return NUMENT;/*se encontro un numero entero*/}
[0−9][0−9]*"."[0−9][0−9]*	{doble = atof(yytext); return NUMF;/*se encontro un numero flotante*/}
":="		{ return ASIGNACION;/* Se encontró una asignacion */}
"("       	{ return PARENI;/* Se encontró un "(" */}
")"       	{ return PAREND;/* Se encontró un ")" */}
"+"       	{ return SUMA;/* Se encontró un símbolo de suma */}
"-"       	{ return RESTA;/* Se encontró un símbolo de resta */}
"*"       	{ return MULTI;/* Se encontró un símbolo de multiplicación */}
"/"       	{ return DIVIDE;/* Se encontró un símbolo de división */}
">"			{ return MAYORQ;/* Se encontró un mayo que */}
"<"			{ return MENORQ;/* Se encontró un menor que*/}
"="			{ return IGUAL;/* Se encontró un igual que*/}
";"			{ return PTOYCOMA;/* Se encontró un punto y coma*/}
"if"		{ return IF;/* Se encontró un if*/} 
"then"		{ return THEN;/* Se encontró un then*/}
"while"		{ return WHILE;/* Se encontró un while*/}
"do"		{ return DO;/* Se encontró un do*/}
"begin"		{ return BEG;/* Se encontró un begin*/}
"end" 		{ return END;/* Se encontró un end*/}
"repeat"	{ return REPEAT;/* Se encontró un repeat*/}
"until"		{ return UNTIL;/* Se encontró un until*/}
"print"		{ return PRINT;/* Se encontró un print*/}
"read"		{ return READ;/* Se encontró un read*/}
"int"		{ return INT;/* Se encontró un int*/}
"float"		{ return FLOAT;/* Se encontró un float*/}
[a-z,A-Z]([0-9][a-z,A-Z])* 			{str = strdup(yytext); return ID;/*se encontró un id*/}
%%


