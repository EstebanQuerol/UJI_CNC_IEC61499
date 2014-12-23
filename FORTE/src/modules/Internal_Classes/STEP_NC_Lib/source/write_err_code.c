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

This is a C program to read a file of error message symbols (usually
prepared by lex_errors followed by sort) and write a file with
#defines for error codes.

Each line of the input file is an error message symbol.

*/

#include <string.h>
#include <stdio.h>

main()
{
  char buffer[200];
  int k; /* numbers output */

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

  for(k = 4; gets(buffer) != NULL; )
    {
      printf("#define %s %d\n", buffer, k++);
    }
  printf("#define ISO14649_MAX_ERROR %d\n", (k-1));
  return 0;
}
