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
   File : driver.cc

This file contains the source code for an emulation of using the ISO14649
interpreter from the EMC system.

*/

#include "iso14649interp.hh"
#include <stdio.h>    /* gets, etc. */
#include <stdlib.h>   /* exit       */
#include <string.h>   /* strcpy     */

/*********************************************************************/

void get_user_input(char * tool_file_name, char * input_file_name,
  char * output_file_name, int * stop_on_err, int * print_stack, int * quit);
void interpret_from_file
  (char * input_file_name, int stop_on_err, int print_stack);
int read_tool_file(char * file_name);
void report_error(int error_code, int print_stack);

/*********************************************************************/

/* report_error

Returned Value: none

Side effects: an error message is printed on stderr

Called by:
  interpret_from_file

This

1. calls iso14649_error_text to get the text of the error message whose
code is error_code and prints the message,

2. calls iso14649_step_name to get the name of the workingstep during
execution of which the error occurred and prints the text, and

3. if print_stack is on, repeatedly calls iso14649_stack_name to get
the names of the functions on the function call stack and prints the
names. The first function named is the one that sent the error
message.


*/

void report_error( /* ARGUMENTS                            */
 int error_code,   /* the code number of the error message */
 int print_stack)  /* print stack if ON, otherwise not     */
{
  char buffer[ISO14649_TEXT_SIZE];
  int k;

  iso14649_error_text(error_code, buffer, ISO14649_TEXT_SIZE);
  fprintf(stderr, "%s\n",
          ((buffer[0] == 0) ? "Unknown error, bad error code" : buffer));
  iso14649_name_text(buffer, ISO14649_TEXT_SIZE);
  fprintf(stderr, "%s\n", buffer);
  if (print_stack == ON)
    {
      for (k = 0; ; k++)
        {
          iso14649_stack_name(k, buffer, ISO14649_TEXT_SIZE);
          if (buffer[0] != 0)
            fprintf(stderr, "%s\n", buffer);
          else
            break;
        }
    }
}

/***********************************************************************/

/* get_user_input

Returned Value: none

This prints the current status as follows.

 CURRENT SETTINGS
tool file name: <name>
input file name: <name>
output file name: <name>
continue interpreting after error: <YES or NO>
print stack on error: <YES or NO>

Then it gives the user seven choices:

1 = start interpreting
2 = change tool file
3 = change input file
4 = change output file
5 = stop on error [or continue on error]
6 = do not print stack on error [or print stack on error]
7 = quit


Interpretation starts when option 1 is chosen. If option 7 is chosen,
the system exits. Until one of those two choices is made, the
status and user choices are given repeatedly.

If the user enters 2, 3, or 4, the user is prompted to enter a
file name.

If the user enters 5, the setting of whether to stop interpreting
in case of error is toggled. The initial setting is to stop.

If the user enters 6, the setting of whether to print the stack in
case of error is toggled. The initial setting is to print on error.

User instructions are printed to stderr (with fprintf) so that output
can be redirected to a file. When output is redirected and user
instructions are printed to stdout (with printf), the instructions get
redirected and the user does not see them.

*/

void get_user_input(       /* ARGUMENTS                                   */
 char * tool_file_name,    /* name of tool file, reset here               */
 char * input_file_name,   /* name of input file, reset here              */
 char * output_file_name,  /* name of output file, reset here             */
 int * stop_on_err,        /* whether to stop on error, reset here        */
 int * print_stack,        /* whether to print stack on error, reset here */
 int * quit)               /* whether to quit, reset here                 */
{
  char buffer[80];
  int choice;
  for(; ;)
    {
      fprintf(stderr, "\nCURRENT SETTINGS\n");
      fprintf(stderr, "tool file name: %s\n", tool_file_name);
      fprintf(stderr, "input file name: %s\n", input_file_name);
      fprintf(stderr, "output file name: %s\n", output_file_name);
      fprintf(stderr, "continue interpreting after error: %s\n",
	      ((*stop_on_err == 1) ? "NO" : "YES"));
      fprintf(stderr, "print stack on error: %s\n",
	      ((*print_stack == 1) ? "YES" : "NO"));
      
      fprintf(stderr, "enter a number:\n");
      fprintf(stderr, "1 = start interpreting\n");
      fprintf(stderr, "2 = change tool file\n");
      fprintf(stderr, "3 = change input file\n");
      fprintf(stderr, "4 = change output file\n");
      fprintf(stderr, "5 = %s on error\n",
	      ((*stop_on_err == 0) ? "stop" : "continue"));
      fprintf(stderr, "6 = %sprint stack on error\n",
              ((*print_stack == 0) ? "" : "do not "));
      fprintf(stderr, "7 = quit\n");

      fprintf(stderr, "enter choice => ");
      fflush(stderr);
      fgets(buffer, 80, stdin);
      if (sscanf(buffer, "%d", &choice) != 1)
        continue;
      if (choice == 1)
        break;
      else if (choice == 2)
        {
	  fprintf(stderr, "enter tool file name => ");
	  fflush(stderr);
	  fgets(tool_file_name, 80, stdin); /* now zap newline */
	  tool_file_name[strlen(tool_file_name) - 1] = 0;
        }
      else if (choice == 3)
        {
	  fprintf(stderr, "enter input file name => ");
	  fflush(stderr);
	  fgets(input_file_name, 80, stdin); /* now zap newline */
	  input_file_name[strlen(input_file_name) - 1] = 0;
        }
      else if (choice == 4)
	{
	  fprintf(stderr, "enter output file name => ");
	  fflush(stderr);
	  fgets(output_file_name, 80, stdin); /* now zap newline */
	  output_file_name[strlen(output_file_name) - 1] = 0;
	}
      else if (choice == 5)
        *stop_on_err = ((*stop_on_err == 0) ? 1 : 0);
      else if (choice == 6)
        *print_stack = ((*print_stack == 0) ? 1 : 0);
      else if (choice == 7)
	{
	  *quit = 1;
	  break;
	}
    }
}

/***********************************************************************/

/* interpret_from_file

Returned Value: none

Side Effects:
   An open iso14649 file is interpreted.

Called By:
   main

This emulates the way the EMC system uses the interpreter.

If the stop_on_err argument is 0, an error does not stop interpretation.

If the stop_on_err argument is 1, an error stops interpretation.

Two interface functions may return ISO14649_FINISH, rather than
ISO14649_OK. This is an indication that everything is OK, but
the caller should empty the motion queue before calling iso14649_read.
This driver has no queue, so nothing needs to be done.

*/

void interpret_from_file( /* ARGUMENTS                           */
 char * input_file_name,  /* name of ISO 14649 file to interpret */
 int stop_on_err,         /* what to do if error                 */
 int print_stack)         /* option which is ON or OFF           */
{
  int status;

  status = iso14649_init();
  if (status != ISO14649_OK)
    {
      report_error(status, print_stack);
      return;
    }
  status = iso14649_synch();
  if (status != ISO14649_OK)
    {
      report_error(status, print_stack);
      return;
    }
  status = iso14649_open(input_file_name);
  if (status != ISO14649_FINISH)
    {
      report_error(status, print_stack);
      return;
    }
  for(; ;)
    {
      status = iso14649_read();
      if (status == ISO14649_ENDFILE)
	break;
      else if (status != ISO14649_OK)
	{
	  report_error(status, print_stack);
	  if (stop_on_err == 1) // 1 means stop
	    break;
          else // if (stop_on_err == 0) -- 0 means continue
            continue;
        }
      status = iso14649_execute();
      if ((status != ISO14649_OK) && (status != ISO14649_FINISH))
        {
          report_error(status, print_stack);
          if (stop_on_err == 1) // 1 means stop
            break;
	  else
	    iso14649_reset();
        }
    }
  status = iso14649_close();
  if (status != ISO14649_OK)
    report_error(status, print_stack);

}

/************************************************************************/

/* read_tool_file

Returned Value: int
  If any of the following errors occur, this returns 1.
  Otherwise, it returns 0.
  1. The file named by the user cannot be opened.
  2. No blank line is found.
  3. A line of data cannot be read.
  4. A tool index number is less than 1 or >= _tool_max

Side Effects:
  Values in the tool table of the machine setup are changed,
  as specified in the file.

Called By: main

Tool File Format
-----------------
Everything above the first blank line is read and ignored, so any sort
of header material may be used.

Everything after the first blank line should be data. Each line of
data should have four or more items separated by white space. The four
required items are index, tool id, tool length offset, and tool diameter.
Other items might be the holder id and tool description, but these are
optional and will not be read. Here is a sample line:

20  1419  4.299  1.0   1 inch carbide end mill

The tool_table is indexed by index number. If a machining center has
a tool carousel, the index number might serve to identify the slot in
which the tool is placed, but this is not required.

*/

int read_tool_file( /* ARGUMENTS         */
 char * file_name)  /* name of tool file */
{
  FILE * tool_file_port;
  char buffer[1000];
  int index;
  char tool_id[80];
  double offset;
  double diameter;
  int fields;

  tool_file_port = fopen(file_name, "r");
  if (tool_file_port == NULL)
    {
      fprintf(stderr, "Cannot open %s\n", file_name);
      return 1;
    }
  for(;;)    // read and discard header, checking for blank line
    {
      if (fgets(buffer, 1000, tool_file_port) == NULL)
        {
          fprintf(stderr, "Bad tool file format\n");
          return 1;
        }
      else if (buffer[0] == '\n')
        break;
    }

  for (index = 0; index <= _tool_max; index++) // initialize
    {
      _tools[index].id[0] = 0;
      _tools[index].length = 0;
      _tools[index].diameter = 0;
    }
  for (; (fgets(buffer, 1000, tool_file_port) != NULL); )
    {
      if (sscanf(buffer, "%d %[\']", &index, tool_id) == 2)
	fields = sscanf(buffer, "%d \'%[^\']\' %lf %lf", &index,
                 tool_id, &offset, &diameter);
      else if (sscanf(buffer, "%d %[\"]", &index, tool_id) == 2)
	fields = sscanf(buffer, "%d \"%[^\"]\" %lf %lf", &index,
                 tool_id, &offset, &diameter);
      else
	fields = sscanf(buffer, "%d %s %lf %lf", &index,
			     tool_id, &offset, &diameter);
      if (fields < 4)
        {
          fprintf(stderr, "Bad input line \"%s\" in tool file\n", buffer);
          return 1;
        }
      if ((index < 0) OR (index > _tool_max)) // zero and max both OK
        {
          fprintf(stderr, "Out of range tool index number %d\n", index);
          return 1;
        }
      strcpy(_tools[index].id, tool_id);
      _tools[index].length = offset;
      _tools[index].diameter = diameter;
    }
  fclose(tool_file_port);

  return 0;
}

/************************************************************************/

/* main

The executable should be called with no arguments. If one or more
arguments is given, the interpreter prints:
Usage: iso14649
and exits with value 1.

This main routine repeatedly asks the user for input and then
interprets a file. The main thing the user must provide is the name of
a STEP Part 21 file using the ARM EXPRESS model of ISO 14649 Parts 10
and 11. The file should contain a machining program.

See the documentation of get_user_input for other user choices.

The output file is opened here since it has nothing to do with the
interface functions for calling the interpreter, but is used only
by the version of the canonical machining functions used with this
stand-alone interpreter.

*/

int main(      /* ARGUMENTS                     */
 int argc,     /* number of arguments plus one  */
 char ** argv) /* text of command and arguments */
{
  char input_file_name[80];
  char output_file_name[80];
  char tool_file_name[80];
  int stop_on_err; // 1=stop if error,   0=don't
  int quit;        // 1=quit,            0=don't
  int print_stack; // 1=print the stack, 0=don't

  if (argc != 1)
    {
      fprintf(stderr, "Usage: %s\n", argv[0]);
      return(1);
    }
  strcpy(input_file_name, "data/ex1.stp");
  strcpy(output_file_name, "stdout");
  strcpy(tool_file_name, "data/iso14649.tool_ex1");
  stop_on_err = 1;
  quit = 0;
  print_stack = 1;
  for (; ;)
    {
      get_user_input(tool_file_name, input_file_name, output_file_name,
		     &stop_on_err, &print_stack, &quit);
      if (quit)
	break;
      if (strcmp(output_file_name, "stdout") == 0)
	_outfile = stdout;
      else
	{
	  _outfile = fopen(output_file_name, "w");
	  if (_outfile == NULL)
	    {
	      fprintf(stderr, "could not open output file %s\n",
		      output_file_name);
	      continue;
	    }
	}
      if (read_tool_file(tool_file_name) != 0)
	continue;
      interpret_from_file(input_file_name, stop_on_err, print_stack);
      if (strcmp(output_file_name, "stdout"))
	fclose(_outfile);
    }
  iso14649_exit();
  return(0);
}

/***********************************************************************/
