%{

/******************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/

#include <string.h>          // for strlen
  int n;
  int stop;

%}

%%

"#include ".*"classes.hh".*$ {
                               for (n = 0; yytext[n]; n++)
                                 {
                                   if (strncmp(yytext+n, "classes.hh", 10) == 0)
                             	     {
	                               printf("classesDirect.hh");
	                               printf("%s", (yytext + n + 10));
	                               break;
                                     }
                                   else
                                     putchar(yytext[n]);
                                 }
                             }

get_[a-zA-Z0-9]*"()"       { 
                             stop = (strlen(yytext) - 2);
			     for (n = 4; n < stop; n++)
			       putchar(yytext[n]);
                           }
.                          ECHO;
\n                         ECHO;

%%

int yywrap()
{
  return 1;
}

int main()
{
  yylex();
  return 0;
}
