/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

/*

This is a C program to read a file (usually prepared by lex_errors
followed by sort) and write an array of error messages.

Each line of the input file is an error message symbol.

Normal usage of the write_err_array executable is in "make_errors".

Each line of the output file is of the form:
<index number comment> <error string>

This may be compiled with
gcc -o write_err_array write_err_array.c

*/

#include <string.h>
#include <stdio.h>

main()
{
  char buffer[200];
  int n; /* index number of message */
  int k; /* index of character on line */
  
  printf(
"/************************************************************************\n"
"  DISCLAIMER:\n"
"  This software was produced by the National Institute of Standards\n"
"  and Technology (NIST), an agency of the U.S. government, and by statute\n"
"  is not subject to copyright in the United States.  Recipients of this\n"
"  software assume all responsibility associated with its operation,\n"
"  modification, maintenance, and subsequent redistribution.\n"
"\n"
"  See NIST Administration Manual 4.09.07 b and Appendix I.\n"
"************************************************************************/\n"
"\n");

  printf("char * _iso14649_errors[] = {\n");
  printf("/*   0 */ \"No error\",\n"); /* for ISO14649_OK      */
  printf("/*   1 */ \"No error\",\n"); /* for ISO14649_EXIT    */
  printf("/*   2 */ \"No error\",\n"); /* for ISO14649_FINISH  */
  printf("/*   3 */ \"No error\",\n"); /* for ISO14649_ENDFILE */
  for(n = 4; gets(buffer) != NULL; )
    {
      printf("/* %3d */ \"", n++);
      putchar(buffer[0]);
      for (k=1; buffer[k] != 0; k++)
	{
	  putchar(((buffer[k] >= 'A') &&
		   (buffer[k] <= 'Z')) ? (buffer[k]  + 32) :
		  (buffer[k] == '_') ? ' ' : buffer[k]);
	}
      printf("\",\n");
    }
  printf("\"The End\"};\n");
  return 0;
}
