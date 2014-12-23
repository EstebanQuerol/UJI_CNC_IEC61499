/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

 /* This is a lex program to read a file of C++ code and             */
 /* write a file of error codes. Each line of the output file        */
 /* has an error code.                                               */
 /* An error code is everything at the end of a CHK statement,       */
 /* just before a right parenthesis followed by a semicolon. Working */
 /* backwards, the start of the error code is the character after    */
 /* the first blank, tab, or comma.                                  */
 /* Example: CHK((NOT vertical), Z_AXIS_MUST_BE_VERTICAL);           */

 /* The first lex rule looks for text of the form:                   */
 /* <beginning of line>CHK(<anything not a semicolon> semicolon      */
 /* This may span several lines. The rule pulls out the error code   */
 /* that comes just before the punctuation at the end of the line.   */

 /* The second and third lex rules skip everything else.             */

W  [ \t]*

%%
  int m;

^{W}("CHK"){W}\([^\;]*\;  {
             for (m = (strlen(yytext) - 1);
		  ((yytext[m] != 32) && (yytext[m] != 9) && (yytext[m] != 44));
		  m--);
	     for (m++; yytext[m+1] != ';'; m++)
	       putchar(yytext[m]);
	     putchar('\n');}

\n     ;
.*     ;

%%

int yywrap()
{
  return 1;
}

main()
{
  yylex();
}

