/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

/* canon.cc

This file contains two sets of functions:
1. functions for the interpreter to call to tell the rest of the world to
   do something. These all return nothing.
2. functions for the interpreter to call to get information from the rest
   of the world. These all return some type of information.
These functions implement the interface between the RS274NGC interpreter
and some external environment.

This version of canon.cc also includes a third set of stuff: a dummy
model of the external world. The dummy model is used by the second set
of interface functions.

*/

/************************************************************************/

#include "canon.hh"
#include <math.h>
#include <stdio.h>
#include <string.h>
#define SET_TO =
#define IS ==
#define AND &&
#define OR ||

/* where to print */
extern FILE * _outfile;

/* Dummy world model */

static CANON_PLANE       _active_plane = CANON_PLANE_XY;
static int               _current_tool_index = 0;
static double            _feed_rate = 0.0;
static int               _flood = 0;
static double            _length_unit_factor = 1; /* 1 for MM 25.4 for inch */
static CANON_UNITS       _length_unit_type = CANON_UNITS_MM;
static int               _line_number = 1;
static int               _mist = 0;
static CANON_MOTION_MODE _motion_mode = CANON_CONTINUOUS;
static double            _probe_position_x = 0;
static double            _probe_position_y = 0;
static double            _probe_position_z = 0;
static double            _program_origin_x = 0;
static double            _program_origin_y = 0;
static double            _program_origin_z = 0;
static double            _program_position_x = 0;
static double            _program_position_y = 0;
static double            _program_position_z = 0;
static double            _spindle_speed;
static CANON_DIRECTION   _spindle_turning;
static double            _tool_length_offset = 0;
int                      _tool_max = 68;         /*Not static. Driver reads  */
CANON_TOOL_TABLE         _tools[CANON_TOOL_MAX]; /*Not static. Driver writes */
static double            _traverse_rate;
FILE * _outfile=NULL;      /* where to print, set in main */

/************************************************************************/

/* Canonical "Do it" functions

This is a set of dummy definitions for the canonical machining functions
given in canon.hh. These functions just print themselves and, if necessary,
update the dummy world model. On each output line is printed:
1. an output line number (sequential, starting with 1).
2. an input line number read from the input (or ... if not provided).
3. a printed representation of the function call which was made.

If an interpreter which makes these calls is compiled with this set of
definitions, it can be used as a translator by redirecting output from
stdout to a file.

*/

#define PRINT0(control) if (1) {                     \
          if(_outfile==NULL){_outfile=stdout;}       \
          fprintf(_outfile, "%5d ", _line_number++); \
          fprintf(_outfile, control);                \
          } else

#define PRINT1(control, arg1) if (1) {               \
          if(_outfile==NULL){_outfile=stdout;}       \
          fprintf(_outfile, "%5d ", _line_number++); \
          fprintf(_outfile, control, arg1);          \
          } else

#define PRINT2(control, arg1, arg2) if (1) {         \
          if(_outfile==NULL){_outfile=stdout;}       \
          fprintf(_outfile, "%5d ", _line_number++); \
          fprintf(_outfile, control, arg1, arg2);    \
          } else

#define PRINT3(control, arg1, arg2, arg3) if (1) {      \
          if(_outfile==NULL){_outfile=stdout;}          \
          fprintf(_outfile, "%5d ", _line_number++);    \
          fprintf(_outfile, control, arg1, arg2, arg3); \
          } else

#define PRINT4(control, arg1, arg2, arg3, arg4) if (1) {      \
          if(_outfile==NULL){_outfile=stdout;}                \
          fprintf(_outfile, "%5d ", _line_number++);          \
          fprintf(_outfile, control, arg1, arg2, arg3, arg4); \
          } else

#define PRINT5(control, arg1, arg2, arg3, arg4, arg5) if (1) {      \
          if(_outfile==NULL){_outfile=stdout;}                      \
          fprintf(_outfile, "%5d ", _line_number++);                \
          fprintf(_outfile, control, arg1, arg2, arg3, arg4, arg5); \
          } else

#define PRINT6(control, arg1, arg2, arg3, arg4, arg5, arg6) if (1) {       \
          if(_outfile==NULL){_outfile=stdout;}                             \
          fprintf(_outfile,  "%5d ", _line_number++);                      \
          fprintf(_outfile,  control, arg1, arg2, arg3, arg4, arg5, arg6); \
          } else

#define PRINT7(control, arg1, arg2, arg3, arg4, arg5, arg6, arg7) if (1) { \
          if(_outfile==NULL){_outfile=stdout;}                             \
          fprintf(_outfile, "%5d ", _line_number++);                       \
          fprintf(_outfile, control,arg1,arg2,arg3,arg4,arg5,arg6,arg7);   \
          } else

#define PRINT10(control,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10) \
          if (1) {                                                          \
          if(_outfile==NULL){_outfile=stdout;}                              \
	  fprintf(_outfile,  "%5d ", _line_number++);                       \
          fprintf(_outfile, control,                                        \
                   arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);     \
          } else

/* Representation */

void SET_ORIGIN_OFFSETS(double x, double y, double z)
{
  fprintf(_outfile, "%5d ", _line_number++);
  fprintf(_outfile, "SET_ORIGIN_OFFSETS(%.4f, %.4f, %.4f)\n", x, y, z);
  _program_position_x SET_TO _program_position_x + _program_origin_x - x;
  _program_position_y SET_TO _program_position_y + _program_origin_y - y;
  _program_position_z SET_TO _program_position_z + _program_origin_z - z;
  _program_origin_x SET_TO x;
  _program_origin_y SET_TO y;
  _program_origin_z SET_TO z;
}

void USE_LENGTH_UNITS(CANON_UNITS in_unit)
{
  if (in_unit IS CANON_UNITS_INCHES)
    {
      PRINT0("USE_LENGTH_UNITS(CANON_UNITS_INCHES)\n");
      if (_length_unit_type IS CANON_UNITS_MM)
        {
          _length_unit_type SET_TO CANON_UNITS_INCHES;
          _length_unit_factor SET_TO 25.4;
          _program_origin_x SET_TO (_program_origin_x / 25.4);
          _program_origin_y SET_TO (_program_origin_y / 25.4);
          _program_origin_z SET_TO (_program_origin_z / 25.4);
          _program_position_x SET_TO (_program_position_x / 25.4);
          _program_position_y SET_TO (_program_position_y / 25.4);
          _program_position_z SET_TO (_program_position_z / 25.4);
        }
    }
  else if (in_unit IS CANON_UNITS_MM)
    {
      PRINT0("USE_LENGTH_UNITS(CANON_UNITS_MM)\n");
      if (_length_unit_type IS CANON_UNITS_INCHES)
        {
          _length_unit_type SET_TO CANON_UNITS_MM;
          _length_unit_factor SET_TO 1.0;
          _program_origin_x SET_TO (_program_origin_x * 25.4);
          _program_origin_y SET_TO (_program_origin_y * 25.4);
          _program_origin_z SET_TO (_program_origin_z * 25.4);
          _program_position_x SET_TO (_program_position_x * 25.4);
          _program_position_y SET_TO (_program_position_y * 25.4);
          _program_position_z SET_TO (_program_position_z * 25.4);
        }
    }
  else
    PRINT0("USE_LENGTH_UNITS(UNKNOWN)\n");
}

/* Free Space Motion */
void SET_TRAVERSE_RATE(double rate)
{
  PRINT1("SET_TRAVERSE_RATE(%.4f)\n", rate);
  _traverse_rate SET_TO rate;
}

void STRAIGHT_TRAVERSE(double x, double y, double z)
{
  fprintf(_outfile, "%5d ", _line_number++);
  fprintf(_outfile, "STRAIGHT_TRAVERSE(%.4f, %.4f, %.4f)\n", x, y, z);
  _program_position_x SET_TO x;
  _program_position_y SET_TO y;
  _program_position_z SET_TO z;
}

/* Machining Attributes */
void SET_FEED_RATE(double rate)
{
  PRINT1("SET_FEED_RATE(%.4f)\n", rate);
  _feed_rate SET_TO rate;
}

void SET_FEED_REFERENCE(CANON_FEED_REFERENCE reference)
{
  PRINT1("SET_FEED_REFERENCE(%s)\n",
         (reference IS CANON_WORKPIECE) ? "CANON_WORKPIECE" : "CANON_XYZ");
}

extern void SET_MOTION_CONTROL_MODE(CANON_MOTION_MODE mode)
{
  if (mode IS CANON_EXACT_STOP)
    {
      PRINT0("SET_MOTION_CONTROL_MODE(CANON_EXACT_STOP)\n");
      _motion_mode SET_TO CANON_EXACT_STOP;
    }
  else if (mode IS CANON_EXACT_PATH)
    {
      PRINT0("SET_MOTION_CONTROL_MODE(CANON_EXACT_PATH)\n");
      _motion_mode SET_TO CANON_EXACT_PATH;
    }
  else if (mode IS CANON_CONTINUOUS)
    {
      PRINT0("SET_MOTION_CONTROL_MODE(CANON_CONTINUOUS)\n");
      _motion_mode SET_TO CANON_CONTINUOUS;
    }
  else
    PRINT0("SET_MOTION_CONTROL_MODE(UNKNOWN)\n");
}

void SELECT_PLANE(CANON_PLANE in_plane)
{
  PRINT1("SELECT_PLANE(CANON_PLANE_%s)\n",
         ((in_plane IS CANON_PLANE_XY) ? "XY" :
          (in_plane IS CANON_PLANE_YZ) ? "YZ" :
          (in_plane IS CANON_PLANE_XZ) ? "XZ" : "UNKNOWN"));
  _active_plane SET_TO in_plane;
}

void SET_CUTTER_RADIUS_COMPENSATION(double radius)
{PRINT1("SET_CUTTER_RADIUS_COMPENSATION(%.4f)\n", radius);}

void START_CUTTER_RADIUS_COMPENSATION(int side)
{PRINT1("START_CUTTER_RADIUS_COMPENSATION(%s)\n",
        (side IS CANON_SIDE_LEFT)  ? "LEFT"  :
        (side IS CANON_SIDE_RIGHT) ? "RIGHT" : "UNKNOWN");
}

void STOP_CUTTER_RADIUS_COMPENSATION()
{PRINT0 ("STOP_CUTTER_RADIUS_COMPENSATION()\n");}

void START_SPEED_FEED_SYNCH()
{PRINT0 ("START_SPEED_FEED_SYNCH()\n");}

void STOP_SPEED_FEED_SYNCH()
{PRINT0 ("STOP_SPEED_FEED_SYNCH()\n");}

/* Machining Functions */

void ARC_FEED(
 double first_end, double second_end,
 double first_axis, double second_axis, int rotation, double axis_end_point)
{
  fprintf(_outfile, "%5d ", _line_number++);
  fprintf(_outfile, "ARC_FEED(%.4f, %.4f, %.4f, %.4f, %d, %.4f)\n",
	  first_end, second_end, first_axis, second_axis,
	  rotation, axis_end_point);
  if (_active_plane IS CANON_PLANE_XY)
    {
      _program_position_x SET_TO first_end;
      _program_position_y SET_TO second_end;
      _program_position_z SET_TO axis_end_point;
    }
  else if (_active_plane IS CANON_PLANE_YZ)
    {
      _program_position_x SET_TO axis_end_point;
      _program_position_y SET_TO first_end;
      _program_position_z SET_TO second_end;
    }
  else /* if (_active_plane IS CANON_PLANE_XZ) */
    {
      _program_position_x SET_TO second_end;
      _program_position_y SET_TO axis_end_point;
      _program_position_z SET_TO first_end;
    }
}

void STRAIGHT_FEED(double x, double y, double z)
{
  fprintf(_outfile, "%5d ", _line_number++);
  fprintf(_outfile, "STRAIGHT_FEED(%.4f, %.4f, %.4f)\n", x, y, z);
  _program_position_x SET_TO x;
  _program_position_y SET_TO y;
  _program_position_z SET_TO z;
}


/* This models backing the probe off 0.01 inch or 0.254 mm from the probe
point towards the previous location after the probing, if the probe
point is not the same as the previous point -- which it should not be. */

void STRAIGHT_PROBE(double x, double y, double z)
{
  double distance;
  double dx, dy, dz;
  double backoff;

  dx SET_TO (_program_position_x - x);
  dy SET_TO (_program_position_y - y);
  dz SET_TO (_program_position_z - z);
  distance SET_TO sqrt((dx * dx) + (dy * dy) + (dz * dz));

  fprintf(_outfile, "%5d ", _line_number++);
  fprintf(_outfile, "STRAIGHT_PROBE(%.4f, %.4f, %.4f)\n", x, y, z);
  _probe_position_x SET_TO x;
  _probe_position_y SET_TO y;
  _probe_position_z SET_TO z;
  if (distance IS 0)
    {
      _program_position_x SET_TO _program_position_x;
      _program_position_y SET_TO _program_position_y;
      _program_position_z SET_TO _program_position_z;
    }
  else
    {
      backoff SET_TO ((_length_unit_type IS CANON_UNITS_MM) ? 0.254 : 0.01);
      _program_position_x SET_TO (x + (backoff * (dx / distance)));
      _program_position_y SET_TO (y + (backoff * (dy / distance)));
      _program_position_z SET_TO (z + (backoff * (dz / distance)));
    }
}

/*
void PARAMETRIC_2D_CURVE_FEED(FunctionPtr f1, FunctionPtr f2,
                              double start_parameter_value,
                              double end_parameter_value) {}

void PARAMETRIC_3D_CURVE_FEED(FunctionPtr xfcn, FunctionPtr yfcn,
        FunctionPtr zfcn, double start_parameter_value,
                              double end_parameter_value) {}
*/

void DWELL(double seconds)
{PRINT1("DWELL(%.4f)\n", seconds);}

/* Spindle Functions */

/* SPINDLE_RETRACT and SPINDLE_RETRACT_TRAVERSE use 250 mm above the    */
/* setup origin as the retract position, which is in the ballpark for a */
/* medium-sized machining center with the setup origin on the table.    */

void SPINDLE_RETRACT_TRAVERSE()
{
  PRINT0("SPINDLE_RETRACT_TRAVERSE()\n");
  _program_position_z SET_TO (250.0 - _tool_length_offset);
}

void START_SPINDLE_CLOCKWISE()
{
  PRINT0("START_SPINDLE_CLOCKWISE()\n");
  _spindle_turning SET_TO ((_spindle_speed IS 0) ? CANON_STOPPED :
                                                   CANON_CLOCKWISE);
}

void START_SPINDLE_COUNTERCLOCKWISE()
{
  PRINT0("START_SPINDLE_COUNTERCLOCKWISE()\n");
  _spindle_turning SET_TO ((_spindle_speed IS 0) ? CANON_STOPPED :
                                                   CANON_COUNTERCLOCKWISE);
}

void SET_SPINDLE_SPEED(double rpm)
{
  PRINT1("SET_SPINDLE_SPEED(%.4f)\n", rpm);
  _spindle_speed SET_TO rpm;
}

void STOP_SPINDLE_TURNING()
{
  PRINT0("STOP_SPINDLE_TURNING()\n");
  _spindle_turning SET_TO CANON_STOPPED;
}

/* SPINDLE_RETRACT and SPINDLE_RETRACT_TRAVERSE use 250 mm above the    */
/* setup origin as the retract position, which is in the ballpark for a */
/* medium-sized machining center with the setup origin on the table.    */

void SPINDLE_RETRACT()
{
  PRINT0("SPINDLE_RETRACT()\n");
  _program_position_z SET_TO (250.0 - _tool_length_offset);

}

void ORIENT_SPINDLE(double orientation, CANON_DIRECTION direction)
{PRINT2("ORIENT_SPINDLE(%.4f, %s)\n", orientation,
        (direction IS CANON_CLOCKWISE) ? "CANON_CLOCKWISE" :
                                         "CANON_COUNTERCLOCKWISE");
}

void USE_NO_SPINDLE_FORCE()
{PRINT0("USE_NO_SPINDLE_FORCE()\n");}

/* Tool Functions */

void USE_TOOL_LENGTH_OFFSET(double length)
{
  PRINT1("USE_TOOL_LENGTH_OFFSET(%.4f)\n", length);
  _tool_length_offset SET_TO length;
}

void CHANGE_TOOL(char * tool_id)
{
  if (tool_id IS NULL)
    PRINT0("CHANGE_TOOL(\"\")\n");
  else
    PRINT1("CHANGE_TOOL(%s)\n", tool_id);
}

void SELECT_TOOL(char * tool_id)
{
  if (tool_id IS NULL)
    PRINT0("SELECT_TOOL(\"\")\n");
  else
    PRINT1("SELECT_TOOL(%s)\n", tool_id);
}


/* Misc Functions */

void CLAMP_AXIS(CANON_AXIS axis)
{PRINT1("CLAMP_AXIS(%s)\n",
        (axis IS CANON_AXIS_X) ? "CANON_AXIS_X" :
        (axis IS CANON_AXIS_Y) ? "CANON_AXIS_Y" :
        (axis IS CANON_AXIS_Z) ? "CANON_AXIS_Z" : "UNKNOWN");}

void COMMENT(char *s)
{PRINT1("COMMENT(\"%s\")\n", s);}

void DISABLE_FEED_OVERRIDE()
{PRINT0("DISABLE_FEED_OVERRIDE()\n");}

void DISABLE_SPEED_OVERRIDE()
{PRINT0("DISABLE_SPEED_OVERRIDE()\n");}

void ENABLE_FEED_OVERRIDE()
{PRINT0("ENABLE_FEED_OVERRIDE()\n");}

void ENABLE_SPEED_OVERRIDE()
{PRINT0("ENABLE_SPEED_OVERRIDE()\n");}

void FLOOD_OFF()
{
  PRINT0("FLOOD_OFF()\n");
  _flood SET_TO 0;
}

void FLOOD_ON()
{
  PRINT0("FLOOD_ON()\n");
  _flood SET_TO 1;
}

void INIT_CANON()
{
}

void MESSAGE(char *s)
{PRINT1("MESSAGE(\"%s\")\n", s);}

void MIST_OFF()
{
  PRINT0("MIST_OFF()\n");
  _mist SET_TO 0;
}

void MIST_ON()
{
  PRINT0("MIST_ON()\n");
  _mist SET_TO 1;
}

void PALLET_SHUTTLE()
{PRINT0("PALLET_SHUTTLE()\n");}

void TURN_PROBE_OFF()
{PRINT0("TURN_PROBE_OFF()\n");}

void TURN_PROBE_ON()
{PRINT0("TURN_PROBE_ON()\n");}

void UNCLAMP_AXIS(CANON_AXIS axis)
{PRINT1("UNCLAMP_AXIS(%s)\n",
        (axis IS CANON_AXIS_X) ? "CANON_AXIS_X" :
        (axis IS CANON_AXIS_Y) ? "CANON_AXIS_Y" :
        (axis IS CANON_AXIS_Z) ? "CANON_AXIS_Z" : "UNKNOWN");}

/* Program Functions */

void PROGRAM_STOP()
{PRINT0("PROGRAM_STOP()\n");}

void OPTIONAL_PROGRAM_STOP()
{PRINT0("OPTIONAL_PROGRAM_STOP()\n");}

void PROGRAM_END()
{PRINT0("PROGRAM_END()\n");
 _line_number = 1;}


/*************************************************************************/

/* Canonical "Give me information" functions

In general, returned values are valid only if any canonical do it commands
that may have been called for have been executed to completion. If a function
returns a valid value regardless of execution, that is noted in the comments
below.

*/

/* The interpreter is not using this function
// Returns the system angular unit factor, in units / degree
extern double GET_EXTERNAL_ANGLE_UNIT_FACTOR()
{
  return 1;
}
*/

/* Returns the system feed rate */
double GET_EXTERNAL_FEED_RATE()
{
  return _feed_rate;
}

/* Returns the system flood coolant setting zero = off, non-zero = on */
int GET_EXTERNAL_FLOOD()
{
  return _flood;
}

/* Returns the system length unit factor, in units per mm */
extern double GET_EXTERNAL_LENGTH_UNIT_FACTOR()
{
  return 1/_length_unit_factor;
}

/* Returns the system length unit type */
CANON_UNITS GET_EXTERNAL_LENGTH_UNIT_TYPE()
{
  return _length_unit_type;
}

/* Returns the system mist coolant setting zero = off, non-zero = on */
extern int GET_EXTERNAL_MIST()
{
  return _mist;
}

// Returns the current motion control mode
extern CANON_MOTION_MODE GET_EXTERNAL_MOTION_CONTROL_MODE()
{
  return _motion_mode;
}


/* The interpreter is not using these three GET_EXTERNAL_ORIGIN functions

// returns the current x-axis origin offset
double GET_EXTERNAL_ORIGIN_X()
{
  return _program_origin_x;
}

// returns the current y-axis origin offset
double GET_EXTERNAL_ORIGIN_Y()
{
  return _program_origin_y;
}

// returns the current z-axis origin offset
double GET_EXTERNAL_ORIGIN_Z()
{
  return _program_origin_z;
}

*/

CANON_PLANE GET_EXTERNAL_PLANE()
{
  return _active_plane;
}

/* returns the current x-axis position */
double GET_EXTERNAL_POSITION_X()
{
  return _program_position_x;
}

/* returns the current y-axis position */
double GET_EXTERNAL_POSITION_Y()
{
  return _program_position_y;
}

/* returns the current z-axis position */
double GET_EXTERNAL_POSITION_Z()
{
  return _program_position_z;
}

/* returns the x-axis position at the last probe trip. This is only valid
   once the probe command has executed to completion. */
double GET_EXTERNAL_PROBE_POSITION_X()
{
  return _probe_position_x;
}

/* returns the y-axis position at the last probe trip. This is only valid
   once the probe command has executed to completion. */
double GET_EXTERNAL_PROBE_POSITION_Y()
{
  return _probe_position_y;
}

/* returns the z-axis position at the last probe trip. This is only valid
   once the probe command has executed to completion. */
double GET_EXTERNAL_PROBE_POSITION_Z()
{
  return _probe_position_z;
}

/* Returns the value for any analog non-contact probing. */
/* This is a dummy of a dummy, returning a useless value. */
/* It is not expected this will ever be called. */
extern double GET_EXTERNAL_PROBE_VALUE()
{
  return 1.0;
}

/* Returns zero if queue is not empty, non-zero if the queue is empty */
/* In the stand-alone interpreter, there is no queue, so it is always empty */
extern int GET_EXTERNAL_QUEUE_EMPTY()
{
  return 1;
}

/* Returns the system value for spindle speed in rpm */
double GET_EXTERNAL_SPEED()
{
  return _spindle_speed;
}

/* Returns the system value for direction of spindle turning */
extern CANON_DIRECTION GET_EXTERNAL_SPINDLE()
{
  return _spindle_turning;
}

/* Returns the system value for the index in the tool_table of the
tool currently in the spindle. Return value zero means there is no
tool in the spindle. */
extern int GET_EXTERNAL_TOOL_INDEX()
{
  return _current_tool_index;
}

/* Returns maximum number of tools */
int GET_EXTERNAL_TOOL_MAX()
{
  return _tool_max;
}

extern double GET_EXTERNAL_TOOL_LENGTH_OFFSET()
{
  return _tool_length_offset;
}

/* Returns the CANON_TOOL_TABLE structure associated with the tool
   having the given index */
extern CANON_TOOL_TABLE GET_EXTERNAL_TOOL_TABLE(int index)
{
  return _tools[index];
}

/* Returns the system traverse rate */
double GET_EXTERNAL_TRAVERSE_RATE()
{
  return _traverse_rate;
}
