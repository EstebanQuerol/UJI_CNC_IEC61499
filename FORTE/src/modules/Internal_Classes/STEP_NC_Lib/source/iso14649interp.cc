/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

/* iso14649.cc

OVERVIEW

This is an ISO 14649 interpreter for 3-axis machining. It reads STEP
Part 21 files corresponding to the data model described in Parts 10
and 11 of ISO 14649 and interprets them. The output of the interpreter
is calls to canonical machining commands.  The interpreter software is
all in standard C++. All software required to run the interpreter is
included in the distribution of which this iso14649.cc file is a
part. No license is required to use the software. The software may be
compiled and run on any computer for which a standard C++ compiler is
available.

This interpreter implements only a modest portion of Parts 10 and 11.
Enough has been implemented to handle Example 1 in Annex E of Part 11
plus the equivalent of that example written using explicit toolpaths.

The interpreter includes toolpath generators for rough and finish
plane milling, rough and finish rectangular pocket milling, drilling,
multistep drilling, reaming, center drilling, countersinking, and
counterboring.

ISO 14649 Part 10 and Part 11 references are to the International
Standard, second edition, both dated 2004-12-15.

PRIMARY FILES

The following files are required in order to compile the interpreter.
Some of them were built automatically using a parser-builder, sebnf2pars,
which was also built at NIST and is distributed separately.

driver.cc
---------
This contains the main routine for the interpreter and a simple
text-based user interface for running the interpreter.

iso14649.cc
-----------
This contains the kernel of the interpreter and two of the four sets
of kernel interface functions declared in canon.hh. The two sets are:
1. interface functions to call to tell the interpreter what to do.
   These all return a status value.
2. interface functions to call to get information from the interpreter.

Kernel interface function names all begin with "iso14649_".

iso14649.hh
-----------
This is the header file for iso14649.cc. It contains the world model
used in the interpreter, a number of #defines, and declarations of the
kernel interface functions.

iso14649classes.hh
------------------

This is the header file for the C++ classes used in the interpreter.
It was generated automatically by sebnf2pars. Constructors, data
access methods, and "isA" identifying methods are defined in this
file. Printers and destructors are declared. The printers enable
printing out a Part 21 file that has been read in or generated.

The classes cover about three-quarters of Parts 10 and 11 (much more
than the interpreter covers).

iso14649classes.cc
------------------
This file defines the printers and destructors declared in the header file.
It was generated automatically by sebnf2pars.

iso14649Lex.cc
--------------
This is the lexer for the parser that reads in a Part 21 file.
It was prepared automatically by running iso14649.lex through the
flex processor.

iso14649YACC.cc
---------------
This is the parser that reads in a Part 21 file. As it runs, it builds a
parse tree using the C++ classes. It was prepared automatically by running
iso14649.y through bison.

iso14649YACC.hh
---------------
This is the header file used by iso14649YACC.cc and iso14649Lex.cc.
It was prepared automatically by running iso14649.y through bison.

canon.cc
--------
This is an implementation of the canonical machining functions in
which the functions just print themselves. If the interpreter were
connected to a machining center, a different implementation of these
functions would drive the machining center.

canon.hh
--------
This is the header file for canon.cc. It declares the canonical machining
functions and describes what should happen when each one is executed.

iso14649_err.c
--------------
This is an array of error messages. It was prepared automatically by
the Makefile using lex_errors and write_err_array.

iso14649_err.h
--------------
This is a long list of #defines used with error messages. It was
prepared automatically by the Makefile using lex_errors and write_err_code.


SECONDARY FILES

The following files are not needed for compiling the interpreter but
were used in the process of building the primary files.

iso14649.y
----------
This is the YACC file for the parser. It was generated automatically
by sebnf2pars.

iso14649.lex
------------
This is the Lex file for the lexer. It was generated automatically
by sebnf2pars.

error code generators
---------------------
These are: lex_errors.lex, lex_errors.cc, write_err_array.c, and
write_err_code.c. They set up the error message handling system
used in the interpreter.



ERROR HANDLING

Error handling is by returning a status value of either a non-error
code (ISO14649_OK, ISO14649_EXIT, etc.) or some specific error code
from each function where there is a possibility of error.  If an error
occurs, processing is always stopped, and control is passed back up
through the function call hierarchy to an interface function; the
error code is also passed back up. The stack of functions called is
also recorded. The external program calling an interface function may
then handle the error further as it sees fit.

Error recovery in this interpreter is weak. In most cases, if there
is an error, it is necessary to restart the interpreter.

CALCULATING VALUES

Since returned values are usually used as just described to handle the
possibility of errors, an alternative method of passing calculated
values is required. In general, if function A needs a value for
variable V calculated by function B, this is handled by passing a
pointer to V from A to B, and B calculates and sets V.

SECURITY PLANE

The handling of security planes is as follows.

1. All security planes are required here to be planes (the spec (Part
10 section 4.6.4.1.2, page 64) requires only elementary surface, which
includes sphere and plane). All security planes are required here to
be parallel to the machine XY plane.

2. A workplan has a setup which has security plane given in the
coordinate system (c_sys) of the setup (section 4.6.4.1.2).

3. A workingstep (Part 10 section 4.6.2, page 55) also has a security
plane. The spec does not say how to deal with two security planes. We
use the workingstep's security plane here whenever possible.

A. If the workingstep is a rapid_movement or transition_feature, the
security plane is supposed to be located in the coordinate system of
the workpiece with which it is associated (section 4.6.2). This works
for transition_feature, which has an associated workpiece. Unfortunately,
there is no association between a rapid_movement and a workpiece, so here
we assume the secplane of a rapid_movement is given in the setup
coordinate system.
 
B. If its_feature of the workingstep is a region or
two5DmanufacturingFeature (the only other choices from transition_feature),
the secplane is located in the coordinate system of the feature.

COORDINATE SYSTEMS

The coordinate system chain (see Part 10 Fig 39, page 64) with axis
placement attribute names in square brackets is:

machine coordinate system
  |
  |
setup [itsOrigin]
  |
  | (a workpieceSetup is one of the its_workpiece_setup list of a setup)
  |
workpieceSetup[itsOrigin] (locates the its_workpiece of the workpieceSetup)
  |
  | (a manufacturingFeature has an its_workpiece, which is a workpiece)
  |
region[featurePlacement] or two5DmanufacturingFeature[featurePlacement]
  |
  |
feature component (depth, bottom, etc) or workingstep security plane

This chain is not appropriate for a program because to run the same
program on different machines, it will usually be necessary to locate
the setup in different places in machine coordinates. This locating
should be done by the machinist, and the controller must be told
where the setup is located. This information should not be in the
program. Thus, here, all coordinate values are being given in setup
coordinates, and (to work around current model), the placement of
the setup must either not be given (which is allowed), or the placement
must be the same as the default placement (in the same place as the
coordinate system to which the placement is referenced).

Since this interpreter is for a 3-axis machining center, it is assumed
that the Z-axis of the setup will always be placed parallel to the
Z-axis of the machine coordinate system. Each feature for which a
toolpath is to be generated must have its Z-axis parallel to the setup
Z-axis (and, hence, the machine Z-axis).

To deal with coordinate systems, when a file is read, the location of
the (one and only) workpiece (given in setup coordinates) is stored in
_world.workpiece_place, and each time an operation on a feature is to
be executed, the location of the feature in setup coordinates is
calculated and stored in _world.feature_place.

The _world.feature_place is used in toolpath generating functions in
one of two ways:
1. The feature is located in setup coordinates (by find_location) by
   using the _world.feature_place. Toolpath locations for canonical
   machining function calls are generated directly from the feature.
2. Locations for tool paths are generated initially in a feature's
   coordinate system and the tool paths are saved in pseudocode. Then
   the pseudocode is relocated (by transform_code) using the
   _world.feature_place. Canonical machining function calls are
   generated (by run_code) from the relocated pseudocode.

ORDER OF PERFORMING MACHINE FUNCTIONS AND TECHNOLOGY

The ISO 14649 spec does not say whether machine functions should be
executed before technology or vice versa. Since milling machine
functions include turning on coolant, and it is very important that
coolant be flowing before any cutting starts, this interpreter
executes machine functions before executing technology. 

RESTRICTIONS

This interpreter imposes and checks over 200 restrictions on the
contents of the Part 21 files it interprets. Many of the restrictions
are stated in ISO 14649. Many others are specific to this interpreter.
In most cases, the interpreter will refuse to proceed if a restriction
is violated. The underlying philosophy is that avoiding crashing a
machining center has the highest priority.


ERROR CODE NAMING CONVENTIONS

1. Errors that result from bad data describe a rule that has been
violated. Rules usually include the word MUST. For example:
COUNTERBORE_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS.

2. Errors that result because the spec is only partially implemented
start with CANNOT_HANDLE or CAN_HANDLE_ONLY. For example:
CANNOT_HANDLE_PROFILE_PLACEMENT or CAN_HANDLE_ONLY_PLUNGE_APPROACH.

3. Errors that can result only if this software has a bug in it
contain the word BUG. For example: BUG_IN_ENTERING_POCKET.

UNDERSCORES AND NAMING

ISO 14649 uses underscores between parts of names (its_workpiece_setup,
for example). Names constructed with underscores have been changed by
removing the underscore and changing the letter following the
underscore to upper case (unless the character preceding the
underscore is an upper case letter or a digit, in which case the only
change is to remove the underscore). For example, the name above is
changed to itsWorkpieceSetup, and two5D_milling_operation is changed
to two5DmillingOperation. The change was made in order to use modified
ISO standard EBNF (which does not allow underscores in names) in the
process of generating C++ classes, without having to spell out every
name.

*/

/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "iso14649interp.hh"

/*

Function prototypes for static functions

*/

static int change_tool(machiningTool * the_tool, int set_flag);
static int check_and_store();
static int check_counterbore_hole(counterboreHole * the_cbore_hole,
  roundHole ** the_hole, double * lower_diameter);
static int check_countersunk_hole(countersunkHole * the_csunk_hole,
  double * upper_hole_angle, roundHole ** the_hole);
static int check_direction_ratios(parenRealListFull * ratios);
static int check_horizontal_plane(elementarySurface * surf);
static int check_op_center_drilling
  (centerDrilling * the_center_drilling, elementarySurface * depth_plane);
static int check_op_counter_boring
  (roundHole * the_hole, boring * the_boring, double lower_diameter);
static int check_op_counter_sinking
  (roundHole * the_hole, counterSinking * the_sinking);
static int check_op_drilling(drilling * the_drilling);
static int check_op_finish_both(bottomAndSideFinishMilling * the_finish);
static int check_op_finish_plane(planeFinishMilling * the_finish);
static int check_op_freeform(freeformOperation * the_freeform);
static int check_op_multistep_drilling(multistepDrilling * the_drilling);
static int check_op_reaming(reaming * the_reaming);
static int check_op_rough_both(bottomAndSideRoughMilling * the_rough);
static int check_op_rough_plane(planeRoughMilling * the_rough);
static int check_op_two5D(two5DmillingOperation * the_op,
  real * axial, real * radial, real * allow_side, real * allow_bottom);
static int check_placement(axis2placement3d * place);
static int check_planar_face(planarFace * the_face, double * plane_length,
  double * plane_width, double * plane_depth);
static int check_plane_milling_strategies(planeMilling * the_cut,
 double diameter, approachRetractStrategy ** enter_strategy,
 approachRetractStrategy ** leave_strategy,
 two5DmillingStrategy ** inside_strategy);
static int check_rectangular_pocket(closedPocket * the_pocket,
  double * pocket_length, double * pocket_width, double * pocket_depth,
  double * pocket_radius);
static int check_rectangular_pocket_strategies(double pocket_length,
  double pocket_width, double pocket_depth, double pocket_radius,
  bottomAndSideMilling * the_cut, endmill * the_endmill, double * stepover, 
  approachRetractStrategy ** enter_strategy,
  approachRetractStrategy ** leave_strategy,
  two5DmillingStrategy ** inside_strategy, int is_finish);
static int check_tool_center_drill
  (machiningTool * the_tool, double * flute_length);
static int check_tool_counterbore(machiningTool * the_tool,
  roundHole * the_hole, double * cut_depth);
static int check_tool_countersink(machiningTool * the_tool,
  roundHole * the_hole, double * cut_depth, double upper_hole_angle);
static int check_tool_cutting(machiningTool * the_tool);
static int check_tool_dimension(millingToolDimension * dimension,
  int edgeRadius_flag, int toolTopAngle_flag, int circumferenceAngle_flag);
static int check_tool_drill(machiningTool * the_tool, double * flute_length);
static int check_tool_endmill
  (machiningTool * the_tool, endmill ** the_endmill);
static int check_tool_plane(machiningTool * the_tool,
  endmill ** the_endmill, facemill ** the_facemill);
static int check_tool_reamer(machiningTool * the_tool, double * flute_length);
static int check_tools(std::list<executable *> * executables);
static int cut_feature(machiningFeature * the_feature,
  millingMachineFunctions * funcs, millingTechnology * tech,
  machiningOperation * the_operation);
static int cut_straight(double length, double depth, double retract_z,
  double pass_depth, approachRetractStrategy * enter,
  approachRetractStrategy * leave, double diameter, double code[][7],
  int * lines);
static double dist(cartesianPoint * p1, cartesianPoint * p2);
static int enter_pocket_pass(plungeStrategy * enter, double start_x,
  double start_y, double start_z, double end_x, double end_z, double aux,
  double code[][7], int * lines);
static int enter_pocket_pass_helix(plungeHelix * hely, double start_x,
  double start_y, double start_z, double end_x, double end_z, int turns,
  double code[][7], int * lines);
static int enter_pocket_pass_zigzag(plungeZigzag * ziggy, double start_x,
  double start_z, double end_x, double end_z, double offset_x,
  double code[][7], int * lines);
static int execute_executable();
static int execute_machining(machiningWorkingstep * the_machining);
static int execute_nc_function(ncFunction * the_nc_function);
static int execute_rapid(rapidMovement * the_rapid);
static int execute_rapid_setup(std::list<toolpath *> * toolpaths);
static int execute_workingstep(workingstep * the_workingstep);
static int find_drill_tip_length
  (machiningTool * the_tool, double * tip_length);
static int find_cutting_depths(double * depth, double * depth1,
  double * depth2, double flute_length, double tip_length,
  elementarySurface * depth_plane, real * overcut,
  real * cutting_depth, drillingTypeStrategy * strat);
static int find_if_vertical(direction * axis, int * vertical);
static void find_instances(iso14649ClassEName instanceType,
  std::list<instance *> * fillMe, std::list<instance *> * source);
static int find_location(axis2placement3d * place1,
  axis2placement3d * place2, axis2placement3d * place3);
static int find_pocket_plunge_start(double length, double width,
  double plunge_depth, plungeStrategy * enter,
  double * start_x, double * start_y, double * aux);
static int find_pocket_plunge_start_helix(double width, double plunge_depth,
  plungeHelix * hely, double * start_x, double * start_y, double * turns,
  double end_x);
static int find_pocket_plunge_start_ramp(double length, double width,
  double plunge_depth, plungeRamp * the_ramp, double * start_x,
  double * start_y, double end_x);
static int find_pocket_plunge_start_toolaxis
  (double * start_x, double * start_y, double end_x);
static int find_pocket_plunge_start_zigzag(double length, double width,
  double plunge_depth, plungeZigzag * ziggy, double * start_x,
  double * start_y, double * offset_x, double end_x);
static int find_retract_z(double top_z, real * op_retract,
  double default_retract, double * retract_z);
static int find_tool_index(machiningTool * the_tool, int * index);
static int finish_mill_both_closed_pocket(closedPocket * the_pocket,
  bottomAndSideFinishMilling * the_finish, endmill * the_endmill);
static int follow_circle_forward(circle * circl, boolean * ahead,
  cartesianPoint * end, double code[][7], int * lines);
static int follow_compositeCurve_forward(compositeCurve * comp,
  toolpathType * pathType, cartesianPoint ** join, double code[][7],
  int * lines);
static int follow_curve_backward(boundedCurve * curv, toolpathType * pathType,
  cartesianPoint ** join, double code[][7], int * lines);
static int follow_curve_forward(boundedCurve * curv, toolpathType * pathType,
  cartesianPoint ** join, double code[][7], int * lines);
static int follow_helix_forward(helix * hely, cartesianPoint * start,
  cartesianPoint * end, double code[][7], int * lines);
static int follow_polyline_forward(polyline * poly, toolpathType * pathType,
  cartesianPoint ** join, double code[][7], int * lines);
static int follow_trimmedCurve_forward(trimmedCurve * trimmed,
  toolpathType * pathType, cartesianPoint ** join, double code[][7],
  int * lines);
static double getAxisX(axis2placement3d * placement);
static double getAxisY(axis2placement3d * placement);
static double getAxisZ(axis2placement3d * placement);
static double getCartX(cartesianPoint * point);
static double getCartY(cartesianPoint * point);
static double getCartZ(cartesianPoint * point);
static double getDirX(direction * dir);
static double getDirY(direction * dir);
static double getDirZ(direction * dir);
static double getPtX(axis2placement3d * placement);
static double getPtY(axis2placement3d * placement);
static double getPtZ(axis2placement3d * placement);
static double get_real(std::list<real *> * reals, int index);
static double getRefX(axis2placement3d * placement);
static double getRefY(axis2placement3d * placement);
static double getRefZ(axis2placement3d * placement);
static int handle_feed(real * feedrate, real * feedrate_per_tooth,
  real * factor, machiningTool * tool);
static int handle_feed_override(boolean * disable);
static int handle_machine_functions(millingMachineFunctions * the_functions);
static int handle_speed(real * spindle_speed, real * surface_speed,
  real * factor, machiningTool * tool);
static int handle_speed_override(boolean * disable);
static int handle_synch(boolean * synch);
static int handle_technology
  (millingTechnology * the_technology, machiningTool * the_tool);
static int handle_technology_rapid(millingTechnology * the_technology);
static int handle_technology_some(millingTechnology * the_technology);
static int handle_tool(machiningTool * the_tool, int set_flag);
static int handle_unload_tool(machiningTool * the_tool);
static int init_place(axis2placement3d * place);
static int is_default_placement(axis2placement3d * place);
static int mill_circular_pocket(double length, double z_now, double stepover,
  double tool_diameter, int spiral, double code[][7], int * lines);
static int mill_planar(planarFace * the_face, planeMilling * the_milling,
  millingCutter * the_mill);
static int mill_planar_bi(double length, double width, int passes,
  double diameter, double pass_depth, double stepover, double overage,
  double retract, bidirectionalMilling * bi, double code[][7], int * lines);
static int mill_planar_regular(double plane_length, double plane_width,
  double plane_depth, double diameter, double pass_depth, double stepover,
  double overcut, planeMilling * the_cut);
static int mill_planar_uni(double length, double width, int passes,
  double diameter, double pass_depth, double stepover, double overage,
  double retract, unidirectionalMilling * uni, double code[][7], int * lines);
static int mill_rectangular_pocket(double pocket_length,
  double pocket_width, double pocket_depth, double pocket_radius,
  double stepover, double tool_diameter, bottomAndSideMilling * the_cut,
  double code[][7], int * lines);
static int mill_rectangular_pocket_regular(double length, double width,
  double depth, double radius, double retract_z, double pass_depth,
  double stepover, approachRetractStrategy * enter,
  approachRetractStrategy * leave, two5DmillingStrategy * inside,
  double tool_diameter, double code[][7], int * lines);
static int mill_regular_pocket(double length, double width, double radius,
  double z_now, double stepover, double tool_diameter, int spiral,
  double code[][7], int * lines);
static int mill_semicircle_end_pocket(double length, double width,
  double z_now, double stepover, double tool_diameter, int spiral,
  double code[][7], int * lines);
static int op_center_drilling
  (machiningFeature * the_feature, centerDrilling * the_center_drilling);
static int op_counter_boring(counterboreHole * the_cbore_hole,
  millingMachineFunctions * funcs, millingTechnology * tech,
  boring * the_boring);
static int op_counter_sinking(countersunkHole * the_csunk_hole,
  millingMachineFunctions * funcs, millingTechnology * tech,
  counterSinking * the_sinking);
static int op_drilling(machiningFeature * the_feature,
  millingMachineFunctions * funcs, millingTechnology * tech,
  drilling * the_drilling);
static int op_finish_milling_both(machiningFeature * the_feature,
  bottomAndSideFinishMilling * the_finish);
static int op_finish_milling_plane
  (machiningFeature * the_feature, planeFinishMilling * the_finish);
static int op_finish_milling_side
  (machiningFeature * the_feature, sideFinishMilling * the_finish);
static int op_freeform(machiningFeature * the_feature,
  millingMachineFunctions * funcs, millingTechnology * tech,
  freeformOperation * the_freeform);
static int op_multistep_drilling
  (machiningFeature * the_feature, multistepDrilling * the_drilling);
static int op_reaming
  (machiningFeature * the_feature, reaming * the_reaming);
static int op_rough_milling_both
  (machiningFeature * the_feature, bottomAndSideRoughMilling * the_rough);
static int op_rough_milling_plane
  (machiningFeature * the_feature, planeRoughMilling * the_rough);
static int op_rough_milling_side
  (machiningFeature * the_feature, sideRoughMilling * the_rough);
static int op_trajectory
  (cutterLocationTrajectory * traj, cartesianPoint ** join);
static int op_trajectory_rapid
  (cutterLocationTrajectory * traj, cartesianPoint ** join);
static int plunge_pocket(double depth, double retract_z, double code[][7],
  int * lines);
void put1(std::list<real *> * reals, double valIn);
void put2(std::list<real *> * reals, double valIn);
void put3(std::list<real *> * reals, double valIn);
static int reset_place(axis2placement3d * place);
static int rough_mill_both_closed_pocket(closedPocket * the_pocket,
  bottomAndSideRoughMilling * the_rough, endmill * the_endmill);
static int run_code(double code[][7], int lines);
static int set_security_z_now(elementarySurface * secplane);
static int start_cut(double new_x, double new_y, double retract_z);
static double tand(double degrees);
static int transform_code
  (double code[][7], int lines, axis2placement3d * place);
static int write_arc(double end_x, double end_y, double center_x,
  double center_y, int rotation, double end_z, double code[][7],
  int * lines);
static int write_feed
  (double x, double y, double z, double code[][7], int * lines);
static int write_feed_y
  (double x, double y, double z, double code[][7], int * lines);
static int write_traverse
  (double x, double y, double z, double code[][7], int * lines);
static int write_traverse_y
  (double x, double y, double z, double code[][7], int * lines);

/***********************************************************************/

/*

Global variable declaration

*/

extern char * _iso14649_errors[];
world _world;

/***********************************************************************/
/***********************************************************************/

/*

The functions in this section are the interpreter kernel functions

*/

/***********************************************************************/

/* change_tool

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. find_tool_index returns an error code.
   2. If the tool were changed, the new tool would be too long to retract
      above the security plane of the setup:
      TOOL_MUST_NOT_BE_TOO_LONG_TO_RETRACT_TO_SETUP_SECURITY_PLANE.

Side Effects: See below

Called By:
  handle_tool
  handle_unload_tool

If the spindle is turning, this stops it and does not restart it.  If
mist or flood coolant is on, this turns it off and does not turn it
back on.  This calls the canonical CHANGE_TOOL function to change the
tool.  The CHANGE_TOOL function leaves the spindle fully retracted
and, if there is a tool in the spindle when CHANGE_TOOL is called,
that tool is put back into the tool rack.

the_tool may be NULL when this is called. In this case, the tool currently
in the spindle will be removed from the spindle.

Before the call to CHANGE_TOOL, the spindle is fully retracted and, if
values of _world.change_x and _world.change_y are not NULL, the
controlled point is moved there. The spindle is not moved after the
change (but it may move during the change).

In ISO 14649, the controlled point is at the tool tip. This means that
in the canonical machining view, the correct tool length offset must
always be used. Hence, this always calls USE_TOOL_LENGTH_OFFSET.

The current location is not updated here because CHANGE_TOOL may move
it later (since the CHANGE_TOOL command may be put on a queue).

If change_tool is called via execute_nc_function, to find where the
controlled point is, the set_flag argument here will be 1, and in this
case, the _world.action_flag is set here to ISO14649_SET_POSITION. See
documentation of iso14649_read for the rest of how this works.

The other way change_tool can be called is in the middle of executing
a workingstep. In this case, although the XY location is temporarily
lost, it is re-found during execution of the workingstep.

*/

static int change_tool(    /* ARGUMENTS                         */
 machiningTool * the_tool, /* the tool to put in the spindle    */
 int set_flag)             /* 1=set _world.action_flag, 0=don't */
{
  static char name[] = "change_tool";
  int index;
  double length;

  if (_world.spindle_turning != CANON_STOPPED)
    {
      STOP_SPINDLE_TURNING();
      _world.spindle_turning = CANON_STOPPED;
    }
  if (_world.flood != OFF)
    {
      FLOOD_OFF();
      _world.flood = OFF;
    }
  if (_world.mist != OFF)
    {
      MIST_OFF();
      _world.mist = OFF;
    }
  if (_world.current_z != _world.retracted_z)
    SPINDLE_RETRACT();
  USE_TOOL_LENGTH_OFFSET(0.0);
  IFF(find_tool_index(the_tool, &index));
  length = ((the_tool == 0) ? 0.0 : _world.tool_table[index].length);
  CHK(((_world.retracted_z - length) < _world.security_z_setup),
      TOOL_MUST_NOT_BE_TOO_LONG_TO_RETRACT_TO_SETUP_SECURITY_PLANE);
  if (_world.change_x && _world.change_y)
    STRAIGHT_TRAVERSE(_world.change_x->get_val(), _world.change_y->get_val(),
		      _world.retracted_z);
  if (the_tool == 0)
    CHANGE_TOOL("");
  else
    {
      CHANGE_TOOL(the_tool->get_itsId());
      USE_TOOL_LENGTH_OFFSET(length);
    }
  _world.current_tool_index = index;
  if (set_flag)
    _world.action_flag = ISO14649_SET_POSITION;
  return ISO14649_OK;
}

/***********************************************************************/

/* check_and_store

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The file does not have exactly one project instance:
      FILE_MUST_HAVE_EXACTLY_ONE_PROJECT.
   2. The file does not have exactly one workpiece instance:
      FILE_MUST_HAVE_EXACTLY_ONE_WORKPIECE.
   3. The file does not have exactly one setup instance:
      FILE_MUST_HAVE_EXACTLY_ONE_SETUP.
   4. The file does not have exactly one workpieceSetup instance:
      FILE_MUST_HAVE_EXACTLY_ONE_WORKPIECE_SETUP.
   5. The one project instance does not have exactly one workpiece instance:
      PROJECT_MUST_HAVE_EXACTLY_ONE_WORKPIECE.
   6. The project's one workpiece is not the file's one workpiece
      PROJECT_WORKPIECE_MUST_BE_FILE_WORKPIECE.
   7. The project's main_workplan's setup is not the file's one setup:
      PROJECT_MAIN_WORKPLAN_SETUP_MUST_BE_FILE_SETUP;
   8. The one setup does not have exactly one workpieceSetup:
      THE_SETUP_MUST_HAVE_EXACTLY_ONE_WORKPIECE_SETUP.
   9. The setup's one workpieceSetup is not the file's one workpieceSetup:
      SETUP_WORKPIECE_SETUP_MUST_BE_FILE_WORKPIECE_SETUP.
  10. the_workpieceSetup's its_workpiece is not the file's one workpiece:
      WORKPIECE_SETUP_WORKPIECE_MUST_BE_FILE_WORKPIECE
  11. The main_workplan of the_project is NULL: MAIN_WORKPLAN_MUST_NOT_BE_NULL.
  12. init_place returns an error code.
  13. is_default_placement returns an error code.
  14. check_horizontal_plane returns an error code.

Side Effects: See below

Called By: iso14649_open

This checks things as described above, and:
1. The workpiece is saved in _world.a_workpiece.
2. The project's main workplan is saved in _world.a_workplan.
3. The list of executables of the workplan is saved in _world.execs.
4. The Z coordinate of the point on the security plane of the setup
      is saved in _world.security_z_setup and _world.security_z_now.
5. The placement in the setup coordinate system of the workpiece is
      saved in _world.workpiece_place.

The itsOrigin of the_setup may be NULL (Part 10, Section 4.6.4.1.2,
Page 60).  In the spec, this means the setup placement is the machine
coordinate system. But here we diverge from the spec. To be
machine_independent, no placement of the setup in machine coordinates
should be given, so NULL is fine but does not mean anything. If
itsOrigin is NULL, this function makes a placement with default
values and inserts it as the value of itsOrigin. This function,
alternatively, allows itsOrigin to be the default placement, but
that also means nothing.

*/

static int check_and_store()  /* NO ARGUMENTS */
{
  static char name[] = "check_and_store";
  std::list<instance *> projects;
  project * the_project;
  std::list<instance *> workpieces;
  workpiece * the_workpiece;
  std::list<instance *> setups;
  setup * the_setup;
  std::list<instance *> workpiece_setups;
  axis2placement3d * a_place;
  workpieceSetup * the_workpiece_setup;
  std::list<workpiece *> * projectWorkpieces;
  std::list<workpieceSetup *> * projectWorkpieceSetups;
  plane * z_plane;
  parenExecutableList * liz;

  find_instances(project_E, &projects,
		 _world.design->get_inputData()->get_items());
  find_instances(workpiece_E, &workpieces,
		 _world.design->get_inputData()->get_items());
  find_instances(setup_E, &setups,
		 _world.design->get_inputData()->get_items());
  find_instances(workpieceSetup_E, &workpiece_setups,
		 _world.design->get_inputData()->get_items());
  CHK((projects.size() != 1), FILE_MUST_HAVE_EXACTLY_ONE_PROJECT);
  the_project = dynamic_cast<project *>(projects.front());
  CHK((workpieces.size() != 1), FILE_MUST_HAVE_EXACTLY_ONE_WORKPIECE);
  the_workpiece = dynamic_cast<workpiece *>(workpieces.front());
  CHK((setups.size() != 1), FILE_MUST_HAVE_EXACTLY_ONE_SETUP);
  the_setup = dynamic_cast<setup *>(setups.front());
  CHK((workpiece_setups.size() != 1),
      FILE_MUST_HAVE_EXACTLY_ONE_WORKPIECE_SETUP);
  the_workpiece_setup =
    dynamic_cast<workpieceSetup *>(workpiece_setups.front());
  projectWorkpieces = the_project->get_itsWorkpieces()->get_theList();
  CHK((projectWorkpieces->size() != 1),
      PROJECT_MUST_HAVE_EXACTLY_ONE_WORKPIECE);
  CHK((projectWorkpieces->front() != the_workpiece),
      PROJECT_WORKPIECE_MUST_BE_FILE_WORKPIECE);
  CHK((the_project->get_mainWorkplan() == 0),
      MAIN_WORKPLAN_MUST_NOT_BE_NULL);
  CHK((the_project->get_mainWorkplan()->get_itsSetup()->get_iId()->get_val() !=
       the_setup->get_iId()->get_val()),
      PROJECT_MAIN_WORKPLAN_SETUP_MUST_BE_FILE_SETUP);
  projectWorkpieceSetups = the_setup->get_itsWorkpieceSetup()->get_theList();
  CHK((projectWorkpieceSetups->size() != 1),
      THE_SETUP_MUST_HAVE_EXACTLY_ONE_WORKPIECE_SETUP);
  CHK((projectWorkpieceSetups->front() != the_workpiece_setup),
      SETUP_WORKPIECE_SETUP_MUST_BE_FILE_WORKPIECE_SETUP);
  CHK((the_workpiece_setup->get_itsWorkpiece() != the_workpiece),
      WORKPIECE_SETUP_WORKPIECE_MUST_BE_FILE_WORKPIECE);
  if (the_setup->get_itsOrigin() == 0)
    {
      a_place = new axis2placement3d;
      IFF(init_place(a_place));
      the_setup->set_itsOrigin(a_place);
    }
  else
    IFF(is_default_placement(the_setup->get_itsOrigin()));
  IFF(check_horizontal_plane
      (dynamic_cast<elementarySurface *>(the_setup->get_itsSecplane())));
  z_plane = dynamic_cast<plane *>(the_setup->get_itsSecplane());
  a_place = dynamic_cast<axis2placement3d *>(z_plane->get_position());
  _world.security_z_setup = getPtZ(a_place);
  _world.security_z_now = _world.security_z_setup;
  _world.a_workpiece = the_workpiece;
  _world.a_workplan =
    dynamic_cast<workplan *>(the_project->get_mainWorkplan());
  liz = _world.a_workplan->get_itsElements();
  _world.execs = liz->get_theList();
  _world.workpiece_place = the_workpiece_setup->get_itsOrigin();
  return ISO14649_OK;
}

/***********************************************************************/

/* check_counterbore_hole

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The elements list of the counterbore hole is NULL:
      COUNTERBORE_HOLE_ELEMENTS_MUST_NOT_BE_NULL.
   2. The elements list of the counterbore hole does not have exactly two
      elements: COUNTERBORE_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS.
   3. The first element is NULL:
      FIRST_ELEMENT_OF_COUNTERBORE_HOLE_MUST_NOT_BE_NULL.
   4. The second element is NULL:
      SECOND_ELEMENT_OF_COUNTERBORE_HOLE_MUST_NOT_BE_NULL.
   5. The first subhole is not a roundHole:
      FIRST_ELEMENT_OF_COUNTERBORE_HOLE_MUST_BE_A_ROUND_HOLE.
   6. The second subhole is not a roundHole:
      SECOND_ELEMENT_OF_COUNTERBORE_HOLE_MUST_BE_A_ROUND_HOLE.
   7. check_placement applied to either subhole returns an error code.
   8. find_if_vertical applied to either subhole returns an error code.
   9. The first subhole is not vertical:
      FIRST_SUBHOLE_OF_COUNTERBORE_HOLE_MUST_BE_VERTICAL.
  10. The second subhole is not vertical:
      SECOND_SUBHOLE_OF_COUNTERBORE_HOLE_MUST_BE_VERTICAL.
  11. The two subholes are not coaxial:
      SUBHOLES_OF_COUNTERBORE_HOLE_MUST_BE_COAXIAL.
  12. The two subholes are in the same location:
      COUNTERBORE_HOLE_SUBHOLES_MUST_NOT_BE_IN_SAME_PLACE.
  13. The diameter of the upper subhole is not greater than the diameter
      of the lower subhole:
      UPPER_HOLE_DIAMETER_OF_COUNTERBORE_HOLE_MUST_BE_GREATER_THAN_LOWER.
  14. check_horizontal_plane applied to the bottom of the upper subhole
      returns an error code.
  15. The lower subhole does not begin at the bottom of the upper subhole:
      UPPER_AND_LOWER_HOLES_OF_COUNTERBORE_HOLE_MUST_MATE_VERTICALLY.
  16. The change_in_diameter of the upper hole is not NULL:
      UPPER_HOLE_OF_COUNTERBORE_HOLE_MUST_NOT_TAPER.

Side Effects: This sets the value of upper_hole.

Called By: op_counter_boring

This checks a counterboreHole.

The upper hole of a counterboreHole must not be tapered. Either the first
or second hole of a counterboreHole may be the upper hole.

This is requiring that:
1. the first and second holes be co-axial
2. the axes of the first and second holes be vertical.
3. the bottom of the upper hole is at the top of the lower hole.

Remember the placement of the two holes is in terms of the coordinate
system of the counterboreHole, and the placement of the bottom of each
hole is in the coordinate system of the hole.

It has already been checked that the_feature is not NULL, that its
placement is OK and that the axis of the_feature is vertical in the
setup coordinate system. In principle, the_feature does not need to
have its axis be vertical in the setup coordinate system, as long as
the two holes that make up the_feature have their axes vertical in the
setup coordinate system, but modeling the_feature that way would be
strange and checking it is too much trouble.

*/

static int check_counterbore_hole( /* ARGUMENTS                        */
 counterboreHole * bore_hole,      /* the counterboreHole              */
 roundHole ** upper_hole,          /* upper hole, found and set here   */
 double * lower_diameter)          /* diameter of lower hole, set here */
{
  static char name[] = "check_counterbore_hole";
  roundHole * lower_hole;
  compoundFeatureSelect * element0;
  compoundFeatureSelect * element1;
  roundHole * hole0;
  roundHole * hole1;
  int vertical;
  double z0;
  double z1;
  double upper_z;         // Z coordinate of top of upper hole
  double lower_z;         // Z coordinate of top of lower hole
  double height;          // height of upper hole
  double upper_diameter;  // diameter of upper hole

  CHK((bore_hole->get_elements() == 0),
      COUNTERBORE_HOLE_ELEMENTS_MUST_NOT_BE_NULL);
  CHK((bore_hole->get_elements()->get_theList()->size() != 2),
      COUNTERBORE_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS);
  element0 = bore_hole->get_elements()->get_theList()->front();
  element1 = bore_hole->get_elements()->get_theList()->back();
  CHK((element0 == 0), FIRST_ELEMENT_OF_COUNTERBORE_HOLE_MUST_NOT_BE_NULL);
  CHK((element1 == 0), SECOND_ELEMENT_OF_COUNTERBORE_HOLE_MUST_NOT_BE_NULL);
  CHK(((NOT(element0->isA(machiningFeature_E))) ||
       (NOT((dynamic_cast<machiningFeature *>(element0))->isA(roundHole_E)))),
      FIRST_ELEMENT_OF_COUNTERBORE_HOLE_MUST_BE_A_ROUND_HOLE);
  CHK(((NOT(element1->isA(machiningFeature_E))) ||
       (NOT((dynamic_cast<machiningFeature *>(element1))->isA(roundHole_E)))),
      SECOND_ELEMENT_OF_COUNTERBORE_HOLE_MUST_BE_A_ROUND_HOLE);
  hole0 = dynamic_cast<roundHole *>(element0);
  hole1 = dynamic_cast<roundHole *>(element1);
  IFF(check_placement(hole0->get_featurePlacement()));
  IFF(check_placement(hole1->get_featurePlacement()));
  IFF(find_if_vertical(hole0->get_featurePlacement()->get_axis(), &vertical));
  CHK((NOT(vertical)), FIRST_SUBHOLE_OF_COUNTERBORE_HOLE_MUST_BE_VERTICAL);
  IFF(find_if_vertical(hole1->get_featurePlacement()->get_axis(), &vertical));
  CHK((NOT(vertical)), SECOND_SUBHOLE_OF_COUNTERBORE_HOLE_MUST_BE_VERTICAL);
  CHK((hypot((getPtX(hole0->get_featurePlacement()) -
	      getPtX(hole1->get_featurePlacement())),
	     (getPtY(hole0->get_featurePlacement()) -
	      getPtY(hole1->get_featurePlacement()))) > ISO14649_TINY),
      SUBHOLES_OF_COUNTERBORE_HOLE_MUST_BE_COAXIAL);
  z0 = getPtZ(hole0->get_featurePlacement());
  z1 = getPtZ(hole1->get_featurePlacement());
  CHK((z0 == z1), COUNTERBORE_HOLE_SUBHOLES_MUST_NOT_BE_IN_SAME_PLACE);
  if (z0 > z1)
    {
      *upper_hole = hole0;
      lower_hole = hole1;
      upper_z = z0;
      lower_z = z1;
    }
  else /* if (z1 > z0) */
    {
      *upper_hole = hole1;
      lower_hole = hole0;
      upper_z = z1;
      lower_z = z0;
    }
  *lower_diameter = lower_hole->get_diameter()->get_theoreticalSize();
  upper_diameter = (*upper_hole)->get_diameter()->get_theoreticalSize();
  CHK((upper_diameter <= *lower_diameter),
      UPPER_HOLE_DIAMETER_OF_COUNTERBORE_HOLE_MUST_BE_GREATER_THAN_LOWER);
  IFF(check_horizontal_plane((*upper_hole)->get_depth()));
  height = -getPtZ((*upper_hole)->get_depth()->get_position());
  CHK((fabs((upper_z - height) - lower_z) > ISO14649_TINY),
      UPPER_AND_LOWER_HOLES_OF_COUNTERBORE_HOLE_MUST_MATE_VERTICALLY);
  CHK(((*upper_hole)->get_changeInDiameter() != 0),
      UPPER_HOLE_OF_COUNTERBORE_HOLE_MUST_NOT_TAPER);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_countersunk_hole

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The elements list of the countersunk hole is NULL:
      COUNTERSUNK_HOLE_ELEMENTS_MUST_NOT_BE_NULL.
   2. The elements list of the countersunk hole does not have exactly two
      elements: COUNTERSUNK_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS.
   3. The first element is NULL:
      FIRST_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_NOT_BE_NULL.
   4. The second element is NULL:
      SECOND_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_NOT_BE_NULL.
   5. The first subhole is not a roundHole:
      FIRST_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_BE_A_ROUND_HOLE.
   6. The second subhole is not a roundHole:
      SECOND_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_BE_A_ROUND_HOLE.
   7. check_placement applied to either subhole returns an error code.
   8. find_if_vertical applied to either subhole returns an error code.
   9. The first subhole is not vertical:
      FIRST_SUBHOLE_OF_COUNTERSUNK_HOLE_MUST_BE_VERTICAL.
  10. The second subhole is not vertical:
      SECOND_SUBHOLE_OF_COUNTERSUNK_HOLE_MUST_BE_VERTICAL.
  11. The two subholes are not coaxial:
      SUBHOLES_OF_COUNTERSUNK_HOLE_MUST_BE_COAXIAL.
  12. The two subholes are in the same location:
      COUNTERSUNK_HOLE_SUBHOLES_MUST_NOT_BE_IN_SAME_PLACE.
  13. The diameter of the upper subhole is not greater than the diameter
      of the lower subhole:
      UPPER_HOLE_DIAMETER_OF_COUNTERSUNK_HOLE_MUST_BE_GREATER_THAN_LOWER.
  14. check_horizontal_plane applied to the bottom of the upper subhole
      returns an error code.
  15. The lower subhole does not begin at the bottom of the upper subhole:
      UPPER_AND_LOWER_HOLES_OF_COUNTERSUNK_HOLE_MUST_MATE_VERTICALLY.
  16. The diameter at the bottom of the upper hole is not the same as
      the diameter at the top of the lower hole.
      UPPER_AND_LOWER_HOLES_OF_COUNTERSUNK_HOLE_MUST_MATE_IN_DIAMETER.
  17. The change_in_diameter of the upper hole is NULL:
      UPPER_HOLE_OF_COUNTERSUNK_HOLE_MUST_TAPER.
  18. The change_in_diameter of the upper hole is neither a diameter_taper
      nor an angle_taper:
      UPPER_HOLE_TAPER_MUST_BE_DIAMETER_TAPER_OR_ANGLE_TAPER.

Side Effects: This sets the value of upper_hole.

Called By: op_counter_sinking

This checks a countersunkHole.

The upper hole of a countersunkHole must be tapered. Either the first
or second hole of a countersunkHole may be the upper hole.

This is requiring that:
1. the first and second holes be co-axial
2. the axes of the first and second holes be vertical.
3. the bottom of the upper hole is at the top of the lower hole.

Remember the placement of the two holes is in terms of the coordinate
system of the countersunkHole, and the placement of the bottom of each
hole is in the coordinate system of the hole.

It has already been checked that the_feature is not NULL, that its
placement is OK and that the axis of the_feature is vertical in the setup
coordinate system. In principle, the_feature does not need to have its axis
be vertical in the setup coordinate system, as long as the two holes that
make up the_feature have their axes vertical in the setup coordinate
system, but modeling the_feature that way would be strange and checking it
is too much trouble.

*/

static int check_countersunk_hole( /* ARGUMENTS                          */
 countersunkHole * sunk_hole,      /* the countersunkHole                */
 double * upper_hole_angle,        /* angle from side to horiz, set here */
 roundHole ** upper_hole)          /* upper hole, found and set here     */
{
  static char name[] = "check_countersunk_hole";
  roundHole * lower_hole;
  compoundFeatureSelect * element0;
  compoundFeatureSelect * element1;
  roundHole * hole0;
  roundHole * hole1;
  int vertical;
  double z0;
  double z1;
  double upper_z;         // Z coordinate of top of upper hole
  double lower_z;         // Z coordinate of top of lower hole
  double height;          // height of upper hole
  double lower_diameter;  // diameter of lower hole
  double upper_diameter1; // diameter at top of upper hole
  double upper_diameter2; // diameter at bottom of upper hole
  taperSelect * taper;    // taper of upper hole

  CHK((sunk_hole->get_elements() == 0),
      COUNTERSUNK_HOLE_ELEMENTS_MUST_NOT_BE_NULL);
  CHK((sunk_hole->get_elements()->get_theList()->size() != 2),
      COUNTERSUNK_HOLE_MUST_HAVE_EXACTLY_TWO_ELEMENTS);
  element0 = sunk_hole->get_elements()->get_theList()->front();
  element1 = sunk_hole->get_elements()->get_theList()->back();
  CHK((element0 == 0), FIRST_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_NOT_BE_NULL);
  CHK((element1 == 0), SECOND_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_NOT_BE_NULL);
  CHK(((NOT(element0->isA(machiningFeature_E))) ||
       (NOT((dynamic_cast<machiningFeature *>(element0))->isA(roundHole_E)))),
      FIRST_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_BE_A_ROUND_HOLE);
  CHK(((NOT(element1->isA(machiningFeature_E))) ||
       (NOT((dynamic_cast<machiningFeature *>(element1))->isA(roundHole_E)))),
      SECOND_ELEMENT_OF_COUNTERSUNK_HOLE_MUST_BE_A_ROUND_HOLE);
  hole0 = dynamic_cast<roundHole *>(element0);
  hole1 = dynamic_cast<roundHole *>(element1);
  IFF(check_placement(hole0->get_featurePlacement()));
  IFF(check_placement(hole1->get_featurePlacement()));
  IFF(find_if_vertical(hole0->get_featurePlacement()->get_axis(), &vertical));
  CHK((NOT(vertical)), FIRST_SUBHOLE_OF_COUNTERSUNK_HOLE_MUST_BE_VERTICAL);
  IFF(find_if_vertical(hole1->get_featurePlacement()->get_axis(), &vertical));
  CHK((NOT(vertical)), SECOND_SUBHOLE_OF_COUNTERSUNK_HOLE_MUST_BE_VERTICAL);
  CHK((hypot((getPtX(hole0->get_featurePlacement()) -
	      getPtX(hole1->get_featurePlacement())),
	     (getPtY(hole0->get_featurePlacement()) -
	      getPtY(hole1->get_featurePlacement()))) > ISO14649_TINY),
      SUBHOLES_OF_COUNTERSUNK_HOLE_MUST_BE_COAXIAL);
  z0 = getPtZ(hole0->get_featurePlacement());
  z1 = getPtZ(hole1->get_featurePlacement());
  CHK((z0 == z1), COUNTERSUNK_HOLE_SUBHOLES_MUST_NOT_BE_IN_SAME_PLACE);
  if (z0 > z1)
    {
      *upper_hole = hole0;
      lower_hole = hole1;
      upper_z = z0;
      lower_z = z1;
    }
  else /* if (z1 > z0) */
    {
      *upper_hole = hole1;
      lower_hole = hole0;
      upper_z = z1;
      lower_z = z0;
    }
  lower_diameter = lower_hole->get_diameter()->get_theoreticalSize();
  upper_diameter1 = (*upper_hole)->get_diameter()->get_theoreticalSize();
  CHK((upper_diameter1 <= lower_diameter),
      UPPER_HOLE_DIAMETER_OF_COUNTERSUNK_HOLE_MUST_BE_GREATER_THAN_LOWER);
  IFF(check_horizontal_plane((*upper_hole)->get_depth()));
  height =  -getPtZ((*upper_hole)->get_depth()->get_position());
  CHK((fabs((upper_z - height) - lower_z) > ISO14649_TINY),
      UPPER_AND_LOWER_HOLES_OF_COUNTERSUNK_HOLE_MUST_MATE_VERTICALLY);
  taper = (*upper_hole)->get_changeInDiameter();
  CHK((taper == 0), UPPER_HOLE_OF_COUNTERSUNK_HOLE_MUST_TAPER);
  if (taper->isA(diameterTaper_E))
    {
      upper_diameter2 =
	(dynamic_cast<diameterTaper *>(taper))->
	get_finalDiameter()->get_theoreticalSize();
      *upper_hole_angle =
	((180/M_PI) * atan2(height,((upper_diameter1 - upper_diameter2)/2.0)));
    }
  else if (taper->isA(angleTaper_E))
    {
      upper_diameter2 =
	(upper_diameter1 -
	 (2 * height * 
	  tand((dynamic_cast<angleTaper *>(taper))->get_angle()->get_val())));
      *upper_hole_angle =
	(90 - (dynamic_cast<angleTaper *>(taper))->get_angle()->get_val());
    }
  else
    CHK(1, UPPER_HOLE_TAPER_MUST_BE_DIAMETER_TAPER_OR_ANGLE_TAPER);
  CHK((fabs(upper_diameter2 - lower_diameter) > ISO14649_TINY),
      UPPER_AND_LOWER_HOLES_OF_COUNTERSUNK_HOLE_MUST_MATE_IN_DIAMETER);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_direction_ratios

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The ratios are NULL: DIRECTION_RATIOS_MUST_NOT_BE_NULL.
   2. There are not exactly 3 elements:
      NUMBER_OF_DIRECTION_RATIOS_MUST_BE_THREE.
   3. All three direction ratios are zero:
      DIRECTION_RATIOS_MUST_NOT_ALL_BE_ZERO.
   4. Any of the direction ratios is NULL:
      DIRECTION_RATIO_MUST_BE_GIVEN.

Side Effects: None

Called By:
  check_placement
  check_planar_face
  check_plane_milling_strategies

*/

static int check_direction_ratios( /* ARGUMENTS                 */
 parenRealListFull * ratios)       /* direction ratios to check */
{
  static char name[] = "check_direction_ratios";
  std::list<real *> * rats;
  std::list<real *>::iterator iter;
  bool lengthZero;
  int n;

  lengthZero = true;
  CHK((ratios == 0), DIRECTION_RATIOS_MUST_NOT_BE_NULL);
  rats = ratios->get_theList();
  for (n=0, iter = rats->begin(); iter != rats->end(); ++iter, n++)
    {
      CHK(((*iter) == 0), DIRECTION_RATIO_MUST_BE_GIVEN);
      if ((*iter)->get_val() != 0.0)
	lengthZero = false;
    }
  CHK((n != 3), NUMBER_OF_DIRECTION_RATIOS_MUST_BE_THREE);
  CHK((lengthZero == true), DIRECTION_RATIOS_MUST_NOT_ALL_BE_ZERO);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_horizontal_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The surf is NULL: SURFACE_MUST_NOT_BE_NULL.
   2. The surf isn't a plane: SURFACE_MUST_BE_A_PLANE.
   3. check_placement returns an error code.
   4. The plane is not horizontal in the coordinate system in which it
      is located: PLANE_MUST_BE_HORIZONTAL.
   5. find_if_vertical returns an error code.

Side Effects: None

Called By:
  check_countersunk_hole
  check_counterbore_hole
  check_planar_face
  check_rectangular_pocket
  find_cutting_depths
  op_center_drilling
  set_security_z_now

*/

static int check_horizontal_plane( /* ARGUMENTS                      */
 elementarySurface * surf)         /* the (should be) plane to check */
{
  static char name[] = "check_horizontal_plane";
  axis2placement3d * place;
  plane * the_plane;
  int vertical;
  
  CHK((surf == 0), SURFACE_MUST_NOT_BE_NULL);
  CHK((NOT(surf->isA(plane_E))), SURFACE_MUST_BE_A_PLANE);
  the_plane = dynamic_cast<plane *>(surf);
  place = dynamic_cast<axis2placement3d *>(the_plane->get_position());
  IFF(check_placement(place));
  IFF(find_if_vertical(place->get_axis(), &vertical));
  CHK((NOT vertical), PLANE_MUST_BE_HORIZONTAL);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_center_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. itsMachiningStrategy is not NULL:
      CENTER_DRILLING_MUST_NOT_HAVE_STRATEGY.
   2. overcutLength is not NULL,
      CENTER_DRILLING_MUST_NOT_HAVE_OVERCUT_LENGTH.
   3. The cutting depth is NULL:
      CENTER_DRILLING_MUST_HAVE_CUTTING_DEPTH.
   4. The cutting depth is not positive:
      CUTTING_DEPTH_MUST_BE_POSITIVE
   5.The cutting depth is greater than the feature depth:
      CENTER_DRILLING_CUTTING_DEPTH_MUST_NOT_BE_GREATER_THAN_DEPTH.
   6. The retractPlane is negative: RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   7. The feed on retract ratio is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   8. The dwell time is negative: DWELL_TIME_MUST_NOT_BE_NEGATIVE.

Side Effects: None

Called By: op_center_drilling

*/

static int check_op_center_drilling(   /* ARGUMENTS                        */
 centerDrilling * the_center_drilling, /* the center drilling to check     */
 elementarySurface * depth_plane)      /* depth plane of feature being cut */
{
  static char name[] = "check_op_center_drilling";
  double cutting_depth;

  CHK((the_center_drilling->get_itsMachiningStrategy()),
      CENTER_DRILLING_MUST_NOT_HAVE_STRATEGY);
  CHK(the_center_drilling->get_overcutLength(),
      CENTER_DRILLING_MUST_NOT_HAVE_OVERCUT_LENGTH);
  CHK((the_center_drilling->get_cuttingDepth() == 0),
      CENTER_DRILLING_MUST_HAVE_CUTTING_DEPTH);
  cutting_depth = the_center_drilling->get_cuttingDepth()->get_val();
  CHK((cutting_depth <= 0), CUTTING_DEPTH_MUST_BE_POSITIVE);
  CHK((cutting_depth > (0 - getPtZ(depth_plane->get_position()))),
       CENTER_DRILLING_CUTTING_DEPTH_MUST_NOT_BE_GREATER_THAN_DEPTH);
  CHK(((the_center_drilling->get_retractPlane() != 0) &&
       (the_center_drilling->get_retractPlane()->get_val() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_center_drilling->get_feedOnRetract() != 0) &&
       (the_center_drilling->get_feedOnRetract()->get_val() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_center_drilling->get_dwellTimeBottom() != 0) &&
       (the_center_drilling->get_dwellTimeBottom()->get_val() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_counter_boring

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The counterboring operation does not belong to the hole being
      countersunk: OPERATION_MUST_BELONG_TO_FEATURE;
   2. The operation has a machining_strategy:
      COUNTERBORING_MUST_NOT_HAVE_STRATEGY.
   3. The operation has overcut length:
      COUNTERBORING_MUST_NOT_HAVE_OVERCUT_LENGTH.
   4. A negative retract plane distance is given:
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   5. A feed on retract ratio is given that is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   6. A negative dwell time is given:  DWELL_TIME_MUST_NOT_BE_NEGATIVE.
   7. The previousDiameter of the boring differs from lower_diameter:
      PREVIOUS_DIAMETER_MUST_NOT_DIFFER_FROM_LOWER_HOLE_DIAMETER.

Side Effects: None

Called By: op_counter_boring

This checks a boring operation used for counterboring a hole.

This is not checking anything that requires data about the tool.
That is done in check_tool_countersink.

*/

static int check_op_counter_boring( /* ARGUMENTS                        */
 roundHole * the_hole,              /* hole to be made by counterboring */
 boring * the_boring,               /* counterboring operation to check */
 double lower_diameter)             /* diameter of lower hole           */
{
  static char name[] = "check_op_counter_boring";
  std::list<machiningOperation *> * feature_ops;
  std::list<machiningOperation *>::iterator iter;

  feature_ops = the_hole->get_itsOperations()->get_theList();
  for (iter = feature_ops->begin(); iter != feature_ops->end(); ++iter)
    {
      if (the_boring == *iter)
	break;
    }
  CHK((iter == feature_ops->end()), OPERATION_MUST_BELONG_TO_FEATURE);
  CHK(the_boring->get_itsMachiningStrategy(),
      COUNTERBORING_MUST_NOT_HAVE_STRATEGY);
  CHK((the_boring->get_overcutLength() != 0),
      COUNTERBORING_MUST_NOT_HAVE_OVERCUT_LENGTH);
  CHK(((the_boring->get_retractPlane() != 0) &&
       (the_boring->get_retractPlane()->get_val() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_boring->get_feedOnRetract() != 0) &&
       (the_boring->get_feedOnRetract()->get_val() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_boring->get_dwellTimeBottom() != 0) &&
       (the_boring->get_dwellTimeBottom()->get_val() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);
  CHK(((the_boring->get_previousDiameter() == 0) OR
       (fabs(the_boring->get_previousDiameter()->get_val() - lower_diameter) >
	ISO14649_TINY)),
      PREVIOUS_DIAMETER_MUST_NOT_DIFFER_FROM_LOWER_HOLE_DIAMETER);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_counter_sinking

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The countersinking operation does not belong to the hole being
      countersunk: OPERATION_MUST_BELONG_TO_FEATURE;
   2. The operation has a machining_strategy:
      COUNTERSINKING_MUST_NOT_HAVE_STRATEGY.
   3. The operation has overcut length:
      COUNTERSINKING_MUST_NOT_HAVE_OVERCUT_LENGTH.
   4. A negative retract plane distance is given:
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   5. A feed on retract ratio is given that is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   6. A negative dwell time is given:  DWELL_TIME_MUST_NOT_BE_NEGATIVE.     

Side Effects: None

Called By: op_counter_sinking

This checks a countersinking operation.

This is not checking anything that requires data about the tool.
That is done in check_tool_countersink.

*/

static int check_op_counter_sinking( /* ARGUMENTS                         */
 roundHole * the_hole,               /* the hole to be countersunk        */
 counterSinking * the_sinking)       /* countersinking operation to check */
{
  static char name[] = "check_op_counter_sinking";
  std::list<machiningOperation *> * feature_ops;
  std::list<machiningOperation *>::iterator iter;

  feature_ops = the_hole->get_itsOperations()->get_theList();
  for (iter = feature_ops->begin(); iter != feature_ops->end(); ++iter)
    {
      if (the_sinking == *iter)
	break;
    }
  CHK((iter == feature_ops->end()), OPERATION_MUST_BELONG_TO_FEATURE);
  CHK(the_sinking->get_itsMachiningStrategy(),
      COUNTERSINKING_MUST_NOT_HAVE_STRATEGY);
  CHK(the_sinking->get_overcutLength(),
      COUNTERSINKING_MUST_NOT_HAVE_OVERCUT_LENGTH);
  CHK(((the_sinking->get_retractPlane()) &&
       (the_sinking->get_retractPlane()->get_val() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_sinking->get_feedOnRetract()) &&
       (the_sinking->get_feedOnRetract()->get_val() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_sinking->get_dwellTimeBottom()) &&
       (the_sinking->get_dwellTimeBottom()->get_val() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The retractPlane is negative: RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   2. The feed on retract ratio is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   3. The dwell time is negative: DWELL_TIME_MUST_NOT_BE_NEGATIVE.

Side Effects: None

Called By: op_drilling

This checks a drilling operation.

*/

static int check_op_drilling( /* ARGUMENTS                       */
 drilling * the_drilling)     /* the drilling operation to check */
{
  static char name[] = "check_op_drilling";

  CHK(((the_drilling->get_retractPlane() != 0) &&
       (the_drilling->get_retractPlane()->get_val() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_drilling->get_feedOnRetract() != 0) &&
       (the_drilling->get_feedOnRetract()->get_val() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_drilling->get_dwellTimeBottom() != 0) &&
       (the_drilling->get_dwellTimeBottom()->get_val() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_finish_both

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. overcutLength is not NULL:
      FINISH_MILLING_BOTH_MUST_NOT_HAVE_OVERCUT_LENGTH.
   2. an approach or retract strategy that is not a plunge strategy is used:
      FINISH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY.
   3. check_op_two5D returns an error code.

Side Effects: None

Called By: op_finish_milling_both

C++ data for bottomAndSideFinishMilling
---------------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions; 
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract;             [opt]
two5DmillingStrategy *    itsMachiningStrategy;[opt] (two5DMillingOperation)
real *                    axialCuttingDepth;   [opt] (bottomAndSideMilling)
real *                    radialCuttingDepth;  [opt]
real *                    allowanceSide;       [opt]
real *                    allowanceBottom;     [opt]
<no attributes>                                     (bottomAndSideFinishMilling)

This is logically identical to check_op_rough_both. It checks finish
milling of the bottom and sides of a pocket.

*/

static int check_op_finish_both(          /* ARGUMENTS                     */
 bottomAndSideFinishMilling * the_finish) /* finish milling oper. to check */
{
  static char name[] = "check_op_finish_both";

  IFF(check_op_two5D(the_finish,
		     the_finish->get_axialCuttingDepth(),
		     the_finish->get_radialCuttingDepth(),
		     the_finish->get_allowanceSide(),
		     the_finish->get_allowanceBottom()));
  CHK(the_finish->get_overcutLength(),
      FINISH_MILLING_BOTH_MUST_NOT_HAVE_OVERCUT_LENGTH);
  CHK((the_finish->get_approach() &&
       (NOT(the_finish->get_approach()->isA(plungeStrategy_E)))),
      FINISH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);
  CHK((the_finish->get_retract() &&
       (NOT(the_finish->get_retract()->isA(plungeStrategy_E)))),
      FINISH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_finish_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_two5D returns an error code.

Side Effects: None

Called By: op_finish_milling_plane

C++ data for planeFinishMilling
-------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions;
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract; [opt]
two5DmillingStrategy *    itsMachiningStrategy;[opt] (two5DMillingOperation)
real *                    axialCuttingDepth;   [opt] (planeMilling)
real *                    allowanceBottom;     [opt]
<no attributes>                                      (planeFinishMilling)

Notes:

For a planeFinishMilling operation, radialCuttingDepth is not an
attribute (unlike in sideMilling and bottomAndSideMilling, which
have it). If itsMachiningStrategy is given, however, the
radialCuttingDepth follows from its overlap attribute. The
radialCuttingDepth given here to check_op_two5D is 1, a value known
to be OK as far as check_op_two5D is concerned. The overlap is checked
in check_plane_milling_strategies.

The overcutLength is also checked in check_plane_milling_strategies
(not here) because acceptable values depend on the strategy.

*/

static int check_op_finish_plane( /* ARGUMENTS                         */
 planeFinishMilling * the_finish) /* finish milling operation to check */
{
  static char name[] = "check_op_finish_plane";

  IFF(check_op_two5D(the_finish, the_finish->get_axialCuttingDepth(),
		     0, 0, the_finish->get_allowanceBottom()));
  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_freeform

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. An approach or retract strategy that has a tool_orientation is used:
      TOOL_ORIENTATION_MUST_BE_NULL.
   2. An approach or retract strategy is used that is not a plunge stratagy:
      FREEFORM_MILLING_CAN_HANDLE_ONLY_PLUNGE_STRATEGY
   3. retractPlane is not NULL and is negative:
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   4. itsToolpath is NULL:
      FREEFORM_MILLING_MUST_HAVE_A_TOOLPATH.
   5. itsMachiningStrategy is given:
      CANNOT_HANDLE_FREEFORM_MACHINING_STRATEGY.

Called By: op_freeform

Side Effects: None

C++ data for freeformOperation
------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions;
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract;             [opt]
freeformStrategy *        itsMachiningStrategy;[opt] (freeformOperation)

This checks a freeform operation.

*/

static int check_op_freeform(      /* ARGUMENTS                   */
 freeformOperation * the_freeform) /* freeform operation to check */
{
  static char name[] = "check_op_freeform";

  if (the_freeform->get_approach())
    {
      CHK(the_freeform->get_approach()->get_toolOrientation(),
	  TOOL_ORIENTATION_MUST_BE_NULL);
      CHK((NOT(the_freeform->get_approach()->isA(plungeStrategy_E))),
	  FREEFORM_MILLING_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);
    }
  if (the_freeform->get_retract())
    {
      CHK(the_freeform->get_retract()->get_toolOrientation(),
	  TOOL_ORIENTATION_MUST_BE_NULL);
      CHK((NOT(the_freeform->get_retract()->isA(plungeStrategy_E))),
	  FREEFORM_MILLING_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);
    }
  CHK((the_freeform->get_retractPlane() &&
       (the_freeform->get_retractPlane()->get_val() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK((NOT(the_freeform->get_itsToolpath())),
      FREEFORM_MILLING_MUST_HAVE_A_TOOLPATH);
  CHK(the_freeform->get_itsMachiningStrategy(),
      CANNOT_HANDLE_FREEFORM_MACHINING_STRATEGY);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_multistep_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. A drilling strategy is given:
      CANNOT_HANDLE_STRATEGY_FOR_MULTISTEP_DRILLING.
   2. retractPlane is not NULL and is negative:
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   3. feedOnRetract is not NULL and not greater
      than ISO14649_TINY: FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   4. dwellTimeBottom is not NULL and is negative:
      BOTTOM_DWELL_TIME_MUST_NOT_BE_NEGATIVE.
   5. dwellTimeStep is not NULL and is negative:
      STEP_DWELL_TIME_MUST_NOT_BE_NEGATIVE.
   6. depthOfStep is not positive: PECK_AMOUNT_MUST_BE_POSITIVE.

Side Effects: None

Called By: op_multistep_drilling

This checks a multistep drilling operation.

*/

static int check_op_multistep_drilling( /* ARGUMENTS                       */
 multistepDrilling * the_drilling)      /* the multistep drilling to check */
{
  static char name[] = "check_op_multistep_drilling";

  CHK(the_drilling->get_itsMachiningStrategy(),
      CANNOT_HANDLE_STRATEGY_FOR_MULTISTEP_DRILLING);
  CHK(((the_drilling->get_retractPlane() != 0) &&
       (the_drilling->get_retractPlane()->get_val() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK(((the_drilling->get_feedOnRetract() != 0) &&
       (the_drilling->get_feedOnRetract()->get_val() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK(((the_drilling->get_dwellTimeBottom() != 0) &&
       (the_drilling->get_dwellTimeBottom()->get_val() < 0.0)),
      BOTTOM_DWELL_TIME_MUST_NOT_BE_NEGATIVE);
  CHK(((the_drilling->get_dwellTimeStep() != 0) &&
       (the_drilling->get_dwellTimeStep()->get_val() < 0.0)),
      STEP_DWELL_TIME_MUST_NOT_BE_NEGATIVE);
  CHK((the_drilling->get_depthOfStep() <= 0),
      PECK_AMOUNT_MUST_BE_POSITIVE);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_reaming

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The retractPlane is negative: RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   2. The feed on retract ratio is negative or tiny:
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY.
   3. The dwell time is negative: DWELL_TIME_MUST_NOT_BE_NEGATIVE.
   4. depthOfTestcut isn't NULL: REAMING_MUST_NOT_HAVE_DEPTH_OF_TESTCUT.
   5. waitingPosition isn't NULL: REAMING_MUST_NOT_HAVE_WAITING_POSITION.

Side Effects: None

Called By: op_reaming

This checks a reaming operation.

*/

static int check_op_reaming( /* ARGUMENTS                      */
 reaming * the_reaming)      /* the reaming operation to check */
{
  static char name[] = "check_op_reaming";

  CHK((the_reaming->get_retractPlane() &&
       (the_reaming->get_retractPlane()->get_val() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK((the_reaming->get_feedOnRetract() &&
       (the_reaming->get_feedOnRetract()->get_val() < ISO14649_TINY)),
      FEED_ON_RETRACT_MUST_NOT_BE_NEGATIVE_OR_TINY);
  CHK((the_reaming->get_dwellTimeBottom() &&
       (the_reaming->get_dwellTimeBottom()->get_val() < 0.0)),
      DWELL_TIME_MUST_NOT_BE_NEGATIVE);
  CHK(the_reaming->get_depthOfTestcut(),
      REAMING_MUST_NOT_HAVE_DEPTH_OF_TESTCUT);
  CHK(the_reaming->get_waitingPosition(),
      REAMING_MUST_NOT_HAVE_WAITING_POSITION);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_rough_both

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. overcutLength is not NULL:
      ROUGH_MILLING_BOTH_MUST_NOT_HAVE_OVERCUT_LENGTH.
   2. an approach or retract strategy that is not a plunge strategy is used:
      ROUGH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY.
   3. check_op_two5D returns an error code.

Side Effects: None

Called By: op_rough_milling_both

C++ data for bottomAndSideRoughMilling
--------------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions; 
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract;             [opt]
two5DmillingStrategy *    itsMachiningStrategy;[opt] (two5DMillingOperation)
real *                    axialCuttingDepth;   [opt] (bottomAndSideMilling)
real *                    radialCuttingDepth;  [opt]
real *                    allowanceSide;       [opt]
real *                    allowanceBottom;     [opt]
<no attributes>                                      (bottomAndSideRoughMilling)

This is logically identical to check_op_finish_both. It checks rough
milling of the bottom and sides of a pocket.

*/

static int check_op_rough_both(         /* ARGUMENTS                        */
 bottomAndSideRoughMilling * the_rough) /* rough milling operation to check */
{
  static char name[] = "check_op_rough_both";

  IFF(check_op_two5D(the_rough,
		     the_rough->get_axialCuttingDepth(),
		     the_rough->get_radialCuttingDepth(),
		     the_rough->get_allowanceSide(),
		     the_rough->get_allowanceBottom()));
  CHK(the_rough->get_overcutLength(),
      ROUGH_MILLING_BOTH_MUST_NOT_HAVE_OVERCUT_LENGTH);
  CHK((the_rough->get_approach() &&
       (NOT(the_rough->get_approach()->isA(plungeStrategy_E)))),
      ROUGH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);
  CHK((the_rough->get_retract() &&
       (NOT(the_rough->get_retract()->isA(plungeStrategy_E)))),
      ROUGH_MILLING_BOTH_CAN_HANDLE_ONLY_PLUNGE_STRATEGY);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_rough_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_two5D returns an error code.

Side Effects: None

Called By: op_rough_milling_plane

C++ data for planeRoughMilling
------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions;
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract; [opt]
two5DmillingStrategy *    itsMachiningStrategy;[opt] (two5DMillingOperation)
real *                    axialCuttingDepth;   [opt] (planeMilling)
real *                    allowanceBottom;     [opt]
<no attributes>                                      (planeRoughMilling)

Notes:

For a planeRoughMilling operation, radialCuttingDepth is not an
attribute (unlike in sideMilling and bottomAndSideMilling, which have
it). If itsMachiningStrategy is given, however, the radialCuttingDepth
follows from its overlap attribute. The radialCuttingDepth given here
to check_op_two5D is 1, a value known to be OK as far as
check_op_two5D is concerned. The overlap is checked in
check_plane_milling_strategies.

The overcutLength is also checked in check_plane_milling_strategies
(not here) because acceptable values depend on the strategy.

*/

static int check_op_rough_plane( /* ARGUMENTS                        */
 planeRoughMilling * the_rough)  /* rough milling operation to check */
{
  static char name[] = "check_op_rough_plane";

  IFF(check_op_two5D(the_rough, the_rough->get_axialCuttingDepth(),
		     0, 0, the_rough->get_allowanceBottom()));
  return ISO14649_OK;
}

/***********************************************************************/

/* check_op_two5D

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. An approach or retract strategy that has a tool_orientation is used:
      TOOL_ORIENTATION_MUST_BE_NULL.
   2. retractPlane is not NULL and is negative:
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE.
   3. axialCuttingDepth is not NULL and is negative:
      AXIAL_CUTTING_DEPTH_MUST_NOT_BE_NEGATIVE.
   4. radialCuttingDepth is not NULL and is negative:
      RADIAL_CUTTING_DEPTH_MUST_NOT_BE_NEGATIVE.
   5. allowanceSide is not NULL and is negative:
      ALLOWANCE_SIDE_MUST_NOT_BE_NEGATIVE.
   6. allowanceBottom is not NULL and is negative:
      ALLOWANCE_BOTTOM_MUST_NOT_BE_NEGATIVE.

Side Effects: None

Called By:
  check_op_finish_both
  check_op_finish_plane
  check_op_rough_both
  check_op_rough_plane

C++ data for two5DmillingOperation
----------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions;
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract; [opt]
two5DmillingStrategy *    itsMachiningStrategy;[opt] (two5DMillingOperation)

This checks a two4DmillingOperation.

*/

static int check_op_two5D(       /* ARGUMENTS                 */
 two5DmillingOperation * the_op, /* operation to check        */
 real * axial,                   /* axial depth to check      */
 real * radial,                  /* radial depth to check     */
 real * allow_side,              /* side allowance to check   */
 real * allow_bottom)            /* bottom allowance to check */
{
  static char name[] = "check_op_two5D";

  CHK((the_op->get_approach() &&
       the_op->get_approach()->get_toolOrientation()),
      TOOL_ORIENTATION_MUST_BE_NULL);
  CHK((the_op->get_retract() &&
       the_op->get_retract()->get_toolOrientation()),
      TOOL_ORIENTATION_MUST_BE_NULL);
  CHK((the_op->get_retractPlane() &&
       (the_op->get_retractPlane()->get_val() < 0)),
      RETRACT_PLANE_MUST_NOT_BE_NEGATIVE);
  CHK((axial && (axial->get_val() < 0)),
      AXIAL_CUTTING_DEPTH_MUST_NOT_BE_NEGATIVE);
  CHK((radial && (radial->get_val() < 0)),
      RADIAL_CUTTING_DEPTH_MUST_NOT_BE_NEGATIVE);
  CHK((allow_side && (allow_side->get_val() < 0)),
      ALLOWANCE_SIDE_MUST_NOT_BE_NEGATIVE);
  CHK((allow_bottom && (allow_bottom->get_val() < 0)),
      ALLOWANCE_BOTTOM_MUST_NOT_BE_NEGATIVE);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_placement

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The place is NULL: PLACEMENT_MUST_NOT_BE_NULL
   2. The location of place is NULL: PLACEMENT_LOCATION_MUST_NOT_BE_NULL.
   3. The axis of place is NULL: PLACEMENT_AXIS_MUST_NOT_BE_NULL.
   4. The ref_direction of place is NULL:
      PLACEMENT_REF_DIRECTION_MUST_NOT_BE_NULL.
   5. The coordinates of the location of place is NULL:
      PLACEMENT_COORDINATES_MUST_NOT_BE_NULL.
   6. check_direction_ratios applied to the direction_ratios of the axis
      or the ref_direction of place returns an error code.
   7. There are not exactly three origin coordinates:
      PLACEMENT_ORIGIN_MUST_HAVE_THREE_COORDS.
   8. Any of the coordinates of the origin is ISO14649_BAD_REAL:
      PLACEMENT_ORIGIN_COORDINATE_VALUES_MUST_ALL_BE_GIVEN.
   9. Any of the coordinates of the axis is ISO14649_BAD_REAL:
      PLACEMENT_AXIS_COORDINATE_VALUES_MUST_ALL_BE_GIVEN.
  10. Any of the coordinates of the ref_direction is ISO14649_BAD_REAL:
      PLACEMENT_REF_DIRECTION_COORDINATE_VALUES_MUST_ALL_BE_GIVEN.
  11. The square of the axis length is less than ISO14649_TINY:
      AXIS_LENGTH_OF_PLACEMENT_MUST_NOT_BE_TINY.
  12. The square of the ref_direction length is less than ISO14649_TINY:
      REF_DIRECTION_LENGTH_OF_PLACEMENT_MUST_NOT_BE_TINY.
  13. The dot product of the axis and ref_direction is more than ISO14649_TINY:
      AXIS_OF_PLACEMENT_MUST_BE_PERPENDICULAR_TO_REF_DIRECTION.


Side Effects:  None

Called By:
  check_counterbore_hole
  check_countersunk_hole
  check_horizontal_plane
  find_location
  is_default_placement

This checks that an axis2placement3d is in good format. This is not
requiring the axis or ref_direction to be normalized.

*/

static int check_placement( /* ARGUMENTS               */
 axis2placement3d * place)  /* axis placement to check */
{
  static char name[] = "check_placement";
  double axis_x;
  double axis_y;
  double axis_z;
  double ref_x;
  double ref_y;
  double ref_z;

  CHK((place == 0), PLACEMENT_MUST_NOT_BE_NULL);
  CHK((place->get_location() == 0), PLACEMENT_LOCATION_MUST_NOT_BE_NULL);
  CHK((place->get_axis() == 0), PLACEMENT_AXIS_MUST_NOT_BE_NULL);
  CHK((place->get_refDirection() == 0),
      PLACEMENT_REF_DIRECTION_MUST_NOT_BE_NULL);
  IFF(check_direction_ratios(place->get_axis()->get_directionRatios()));
  IFF(check_direction_ratios(place->get_refDirection()->get_directionRatios()));
  CHK((place->get_location()->get_coordinates()->get_theList()->size() != 3),
      PLACEMENT_ORIGIN_MUST_HAVE_THREE_COORDS);
  CHK(((getPtX(place) == ISO14649_BAD_REAL) OR
       (getPtY(place) == ISO14649_BAD_REAL) OR
       (getPtZ(place) == ISO14649_BAD_REAL)), 
      PLACEMENT_ORIGIN_COORDINATE_VALUES_MUST_ALL_BE_GIVEN);
  axis_x = getAxisX(place);
  axis_y = getAxisY(place);
  axis_z = getAxisZ(place);
  CHK(((axis_x == ISO14649_BAD_REAL) OR
       (axis_y == ISO14649_BAD_REAL) OR
       (axis_z == ISO14649_BAD_REAL)), 
      PLACEMENT_AXIS_COORDINATE_VALUES_MUST_ALL_BE_GIVEN);
  ref_x = getRefX(place);
  ref_y = getRefY(place);
  ref_z = getRefZ(place);
  CHK(((ref_x == ISO14649_BAD_REAL) OR
       (ref_y == ISO14649_BAD_REAL) OR
       (ref_z == ISO14649_BAD_REAL)),
      PLACEMENT_REF_DIRECTION_COORDINATE_VALUES_MUST_ALL_BE_GIVEN);
  CHK((((axis_x * axis_x) + (axis_y * axis_y) + (axis_z * axis_z))
       < ISO14649_TINY), AXIS_LENGTH_OF_PLACEMENT_MUST_NOT_BE_TINY);
  CHK((((ref_x * ref_x) + (ref_y * ref_y) + (ref_z * ref_z))
       < ISO14649_TINY), REF_DIRECTION_LENGTH_OF_PLACEMENT_MUST_NOT_BE_TINY);
  CHK((fabs((axis_x * ref_x) + (axis_y * ref_y) + (axis_z * ref_z))
       > ISO14649_TINY),
      AXIS_OF_PLACEMENT_MUST_BE_PERPENDICULAR_TO_REF_DIRECTION);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_planar_face

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The courseOfTravel of the_face is NULL:
      PLANAR_FACE_COURSE_OF_TRAVEL_MUST_NOT_BE_NULL.
   2. The courseOfTravel has a placement:
      CANNOT_HANDLE_PLACEMENT_OF_COURSE_OF_TRAVEL.
   3. The courseOfTravel distance is NULL:
      COURSE_OF_TRAVEL_DISTANCE_MUST_NOT_BE_NULL.
   4. The courseOfTravel distance itsTheoreticalSize is not positive:
      WIDTH_OF_PLANAR_FACE_MUST_BE_POSITIVE.
   5. The courseOfTravel direction is NULL:
      COURSE_OF_TRAVEL_DIRECTION_MUST_NOT_BE_NULL
   6. check_direction_ratios applied to the directionRatios in the
      courseOfTravel direction returns an error code.
   7. The X and Z directionRatios in the courseOfTravel are not both 0:
      CAN_HANDLE_ONLY_COURSE_OF_TRAVEL_PARALLEL_TO_FEATURE_Y_AXIS.
   8. The Y directionRatio in the courseOfTravel is not positive:
      CAN_HANDLE_ONLY_COURSE_OF_TRAVEL_PARALLEL_TO_POSITIVE_FEATURE_Y_AXIS.
   9. The removalBoundary of the_face is NULL:
      PLANAR_FACE_REMOVAL_BOUNDARY_MUST_NOT_BE_NULL.
  10. The removalBoundary has a placement:
      CANNOT_HANDLE_PLACEMENT_OF_REMOVAL_BOUNDARY.
  11. The removalBoundary profile_length is NULL:
      REMOVAL_BOUNDARY_PROFILE_LENGTH_MUST_NOT_BE_NULL.
  12. The itsParameterUnit of the removalBoundary profileLength is
      NULL or not 'MM' or 'mm': LENGTH_UNITS_MUST_BE_MILLIMETERS.
  13. The itsParameterValue of the removalBoundary profileLength is
      not positive: LENGTH_OF_PLANAR_FACE_MUST_BE_POSITIVE.
  14. The set itsBoss is NULL: PLANAR_FACE_ITS_BOSS_MUST_NOT_BE_NULL.
  15. The set itsBoss is not empty: CANNOT_HANDLE_BOSS_ON_PLANAR_FACE.
  16. check_horizontal_plane applied to the depth returns an error code.
  17. The depth plane of the_face is not below the top:
      PLANE_DEPTH_MUST_BE_BELOW_PLANE_TOP.

Side Effects: The values of plane_length, plane_width, and plane_depth
              are set.

Called By: mill_planar

C++ data for planarFace
-----------------------
char *                        itsId;              (manufacturingFeature)
workpiece *                   itsWorkpiece;
parenMachiningOperationList * itsOperations;
axis2placement3d *            featurePlacement;   (two5DmanufacturingFeature)
elementarySurface *           depth;              (machiningFeature)
linearPath *                  courseOfTravel;     (planarFace)
linearProfile *               removalBoundary;
closedProfile *               faceBoundary;  [opt]
parenBossList *               itsBoss;

C++ data for linearProfile
-----------------------
axis2placement3d * placement;     [opt] (profile)
<no attributes>                         (open_profile)
numericParameter * profileLength;       (linearProfile);

C++ data for linearPath
-----------------------
axis2placement3d *        placement;    [opt] (travel_path)
tolerancedLengthMeasure * distance;           (linearPath)
direction *               itsDirection;

Notes:

This is ignoring the faceBoundary since it is not used in determining
the tool path.

The removalBoundary lies along the positive X-axis of its native
coordinate system (starting at the origin), so it lies on the feature
X-axis when the placement of the removalBoundary is NULL (which is
required here).

We are requiring the courseOfTravel to be along the positive Y-axis
of the feature here. This is done by requiring that its itsDirection
be along the Y-axis and its placement be NULL.

*/

static int check_planar_face( /* ARGUMENTS                              */
 planarFace * the_face,       /* the planar face being checked          */
 double * plane_length,       /* length (X-size) of the_face, set here  */
 double * plane_width,        /* width (Y-size) of the_face, set here   */
 double * plane_depth)        /* depth of the_face, set positive here   */
{
  static char name[] = "check_planar_face";
  direction * dir;
  numericParameter * profile_length;

  CHK((the_face->get_courseOfTravel() == 0),
      PLANAR_FACE_COURSE_OF_TRAVEL_MUST_NOT_BE_NULL);
  CHK((the_face->get_courseOfTravel()->get_placement() != 0),
      CANNOT_HANDLE_PLACEMENT_OF_COURSE_OF_TRAVEL);
  CHK((the_face->get_courseOfTravel()->get_distance() == 0),
      COURSE_OF_TRAVEL_DISTANCE_MUST_NOT_BE_NULL);
  *plane_width =
    the_face->get_courseOfTravel()->get_distance()->get_theoreticalSize();
  CHK((*plane_width <= 0.0), WIDTH_OF_PLANAR_FACE_MUST_BE_POSITIVE);
  CHK((the_face->get_courseOfTravel()->get_itsDirection() == 0),
      COURSE_OF_TRAVEL_DIRECTION_MUST_NOT_BE_NULL);
  dir = the_face->get_courseOfTravel()->get_itsDirection();
  IFF(check_direction_ratios(dir->get_directionRatios()));
  CHK(((getDirX(dir) != 0) OR (getDirZ(dir) != 0)),
      CAN_HANDLE_ONLY_COURSE_OF_TRAVEL_PARALLEL_TO_FEATURE_Y_AXIS);
  CHK((getDirY(dir) <= 0),
      CAN_HANDLE_ONLY_COURSE_OF_TRAVEL_PARALLEL_TO_POSITIVE_FEATURE_Y_AXIS);
  CHK((the_face->get_removalBoundary() == 0),
      PLANAR_FACE_REMOVAL_BOUNDARY_MUST_NOT_BE_NULL);
  CHK((the_face->get_removalBoundary()->get_placement() != 0),
      CANNOT_HANDLE_PLACEMENT_OF_REMOVAL_BOUNDARY);
  profile_length = the_face->get_removalBoundary()->get_profileLength();
  CHK((profile_length == 0),
      REMOVAL_BOUNDARY_PROFILE_LENGTH_MUST_NOT_BE_NULL);
  CHK(((profile_length->get_itsParameterUnit() == 0) OR
       (strcmp(profile_length->get_itsParameterUnit(), "MM") &&
	strcmp(profile_length->get_itsParameterUnit(), "mm"))),
      LENGTH_UNITS_MUST_BE_MILLIMETERS);
  *plane_length = profile_length->get_itsParameterValue();
  CHK((*plane_length <= 0), LENGTH_OF_PLANAR_FACE_MUST_BE_POSITIVE);
  CHK((the_face->get_itsBoss() == 0),
      PLANAR_FACE_ITS_BOSS_MUST_NOT_BE_NULL);
  CHK((the_face->get_itsBoss()->get_theList()->size() != 0),
      CANNOT_HANDLE_BOSS_ON_PLANAR_FACE);
  IFF(check_horizontal_plane(the_face->get_depth()));
  *plane_depth = -getPtZ(the_face->get_depth()->get_position());
  CHK((*plane_depth <= 0), PLANE_DEPTH_MUST_BE_BELOW_PLANE_TOP);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_plane_milling_strategies

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. An approach strategy is given that is not a plunge_toolaxis:
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_APPROACH_FOR_PLANE_MILLING.
   2. An inside strategy is given with an overlap that is not between 0
      and 1: OVERLAP_MUST_BE_BETWEEN_ZERO_AND_ONE.
   3. A unidirectionalMilling strategy is given with an overcutLength
      that is not at least 1.2 times the tool diameter:
      OVERCUT_FOR_UNIDIRECTIONAL_MUST_BE_AT_LEAST_1POINT2_TOOL_DIAMETERS.
   4. A feedDirection is given, but check_direction_ratios applied to
      its direction_ratios returns an error code.
   5. A feedDirection is given that is not parallel to the X of Y-axis
      of the planarFace:
      FEED_DIRECTION_MUST_PARALLEL_X_OR_Y_AXIS_OF_PLANAR_FACE.
   6. A bidirectionalMilling strategy is given with a connection strategy
      that is not straightline:
      CANNOT_HANDLE_NON_STRAIGHTLINE_CONNECTION_STRATEGY.
   7. A bidirectionalMilling strategy is given with an overcutLength
      that is not at least 0.5 times the tool diameter:
      OVERCUT_FOR_BIDIRECTIONAL_MUST_BE_AT_LEAST_HALF_A_TOOL_DIAMETER.
   8. An inside strategy is given that is neither unidirectionalMilling
      nor bidirectionalMilling:
      CAN_HANDLE_ONLY_UNIDIRECTIONAL_AND_BIDIRECTIONAL_PLANE_MILLING.
   9. A retract strategy is given that is not a plunge_toolaxis:
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT_FOR_PLANE_MILLING.

Side Effects:  See below

Called By: mill_planar

Some type of strategy is needed for each of the three phases of
milling (enter, inside, leave), but they are optional in the_cut. If a
strategy is missing for any phase, this makes a strategy for that
phase and inserts it in the_cut. The inside strategy this inserts (if
none is given) is bidirectionalMilling, with overlap of 0.2, feedDirection
parallel to the positive X-axis of the feature, the stepover direction
to the right of the feedDirection, and a straight line connection
between cuts.

The overlap of 0.2 is used to get the cleanest cut, as well as to
minimize the number of cuts.

If an approach strategy is given, it must be a plungeToolaxis.

If a retract strategy is given, it must be a plungeToolaxis.

If an inside strategy is given, it must be a unidirectionalMilling or
bidirectionalMilling.

It is not clear from Part 11 what coordinate system a milling strategy
uses for specifying directions. The best choice would seem to be the
coordinate system of the feature, so that is what is assumed here.

If the_cut does not give an overcutLength, overcut is set in mill_planar
as 1.25 times the tool diameter. For unidirectionalMilling this is needed
to avoid collisions when plunging. For bidirectionalMilling this gets the
tool clear of the planarFace before it changes direction, leaving a
better surface finish than if that is not done. If the_cut does give
an overcutLength, it is checked here that overcutLength at least 1.2
times the tool diameter for unidirectionalMilling (to avoid collisions)
and at least 0.5 times tool diameter for bidirectionalMilling (to ensure
the entire surface gets cut).  This is assuming that Figure 1 in Part 11
is correct in its depiction of the meaning of overcutLength (I would
not have defined it that way).

C++ data for unidirectionalMilling
----------------------------------
real *        overlap;             [opt] (two5DMillingStrategy)
boolean *     allowMultiplePasses; [opt]
direction *   feedDirection;       [opt] (unidirectionalMilling) 
cutmodeType * cutmode;             [opt]

C++ data for bidirectionalMilling
---------------------------------
real *                     overlap;                [opt] (two5DMillingStrategy)
boolean *                  allowMultiplePasses;    [opt]
direction *                feedDirectionIn,        [opt] (bidirectionalMilling) 
leftOrRight *              stepoverDirectionIn,    [opt]
strokeConnectionStrategy * itsStrokeConnectionStrategy [opt]

*/

static int check_plane_milling_strategies(  /* ARGUMENTS                    */
 planeMilling * the_cut,                    /* milling operation to do      */
 double diameter,                           /* tool diameter                */
 approachRetractStrategy ** enter_strategy, /* approach set here if missing */
 approachRetractStrategy ** leave_strategy, /* retract set here if missing  */
 two5DmillingStrategy ** inside_strategy)   /* inside set here if missing   */
{
  static char name[] = "check_plane_milling_strategies";
  std::list<real *> * components;
  direction * dir;
  strokeConnectionStrategy * con;
  double overlap;
  double overcut;
  bidirectionalMilling * bi;
  unidirectionalMilling * uni;
  
  if (the_cut->get_approach() == 0)
    {
      *enter_strategy = new plungeToolaxis(0);
      the_cut->set_approach(*enter_strategy);
    }
  else
    CHK((NOT(the_cut->get_approach()->isA(plungeToolaxis_E))),
	CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_APPROACH_FOR_PLANE_MILLING);
  if (the_cut->get_itsMachiningStrategy() == 0)
    {
      components = new std::list<real *>;
      components->push_back(new real(1.0));
      components->push_back(new real(0.0));
      components->push_back(new real(0.0));
      overlap = 0.2;
      *inside_strategy =
	new bidirectionalMilling(new real(overlap), new booleanTrue,
				 new direction("FIRST_CUT",
					  new parenRealListFull(components)),
				 new leftOrRightRight,
				 new strokeConnectionStrategyStraightline);
      the_cut->set_itsMachiningStrategy(*inside_strategy);
    }
  else if (the_cut->get_itsMachiningStrategy()->isA(unidirectionalMilling_E))
    {
      uni = dynamic_cast<unidirectionalMilling *>
	(the_cut->get_itsMachiningStrategy());
      if (uni->get_overlap())
	{
	  overlap = uni->get_overlap()->get_val();
	  CHK((((overlap <= 0) OR (overlap >= 1))),
	      OVERLAP_MUST_BE_BETWEEN_ZERO_AND_ONE);
	}
      if (the_cut->get_overcutLength())
	{
	  overcut = the_cut->get_overcutLength()->get_val();
	  CHK((overcut < (1.2 * diameter)),
	   OVERCUT_FOR_UNIDIRECTIONAL_MUST_BE_AT_LEAST_1POINT2_TOOL_DIAMETERS);
	}
      if (uni->get_feedDirection())
	{
	  dir = uni->get_feedDirection();
	  IFF(check_direction_ratios(dir->get_directionRatios()));
	  CHK(((getDirZ(dir) != 0) OR
	       ((getDirX(dir) == 0) && (getDirY(dir) == 0)) OR
	       (getDirX(dir) != 0) && (getDirY(dir) != 0)),
	      FEED_DIRECTION_MUST_PARALLEL_X_OR_Y_AXIS_OF_PLANAR_FACE);
	}
    }
  else if (the_cut->get_itsMachiningStrategy()->isA(bidirectionalMilling_E))
    {
      bi = dynamic_cast<bidirectionalMilling *>
	(the_cut->get_itsMachiningStrategy());
      con = bi->get_itsStrokeConnectionStrategy();
      CHK((con && (NOT(con->isA(strokeConnectionStrategyStraightline_E)))),
	  CANNOT_HANDLE_NON_STRAIGHTLINE_CONNECTION_STRATEGY);
      if (bi->get_overlap())
	{
	  overlap = bi->get_overlap()->get_val();
	  CHK((((overlap <= 0) OR (overlap >= 1))),
	      OVERLAP_MUST_BE_BETWEEN_ZERO_AND_ONE);
	}
      if (the_cut->get_overcutLength())
	{
	  overcut = the_cut->get_overcutLength()->get_val();
	  CHK((overcut < (0.5 * diameter)),
	      OVERCUT_FOR_BIDIRECTIONAL_MUST_BE_AT_LEAST_HALF_A_TOOL_DIAMETER);
	}
      if (bi->get_feedDirection())
	{
	  dir = bi->get_feedDirection();
	  IFF(check_direction_ratios(dir->get_directionRatios()));
	  CHK(((getDirZ(dir) != 0) OR
	       ((getDirX(dir) == 0) && (getDirY(dir) == 0)) OR
	       (getDirX(dir) != 0) && (getDirY(dir) != 0)),
	      FEED_DIRECTION_MUST_PARALLEL_X_OR_Y_AXIS_OF_PLANAR_FACE);
	}
    }
  else
    {
      CHK(1, CAN_HANDLE_ONLY_UNIDIRECTIONAL_AND_BIDIRECTIONAL_PLANE_MILLING);
    }
  if (the_cut->get_retract() == 0)
    {
      *leave_strategy = new plungeToolaxis();
      the_cut->set_retract(*leave_strategy);
    }
  else
    CHK((NOT(the_cut->get_retract()->isA(plungeToolaxis_E))),
	CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT_FOR_PLANE_MILLING);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_rectangular_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The boundary of the pocket is NULL: POCKET_BOUNDARY_MUST_NOT_BE_NULL.
   2. The boundary of the pocket is not a rectangularClosedProfile:
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE.
   3. The placement of the profile is not NULL:
      CANNOT_HANDLE_PROFILE_PLACEMENT.
   4. The profile width is NULL: POCKET_PROFILE_WIDTH_MUST_NOT_BE_NULL.
   5. The profile length is NULL: POCKET_PROFILE_LENGTH_MUST_NOT_BE_NULL.
   6. The profile width is not positive: POCKET_WIDTH_MUST_BE_POSITIVE.
   7. The profile length is not positive: POCKET_LENGTH_MUST_BE_POSITIVE.
   8. The profile width exceeds length: POCKET_WIDTH_MUST_NOT_EXCEED_LENGTH.
   9. The boss set of the pocket is NULL: POCKET_BOSS_SET_MUST_NOT_BE_NULL.
  10. The boss set of the pocket is not empty: CANNOT_HANDLE_BOSSES_IN_POCKET.
  11. The tolerance on the pocket width is NULL:
      POCKET_WIDTH_TOLERANCE_MUST_NOT_BE_NULL.
  12. The tolerance on the pocket length is NULL:
      POCKET_LENGTH_TOLERANCE_MUST_NOT_BE_NULL.
  13. The tolerance on the pocket length, width, or orthogonal_radius is not
      a plus_minus_value: CAN_HANDLE_ONLY_PLUS_MINUS_VALUE_TOLERANCE.
  14. A limit in the tolerance on the pocket length, width, or
      orthogonal_radius is negative: TOLERANCE_LIMITS_MUST_NOT_BE_NEGATIVE.
  15. The sum of upper and lower tolerances on the length, width, or
      orthogonal_radius is less than 0.01:
      CANNOT_HOLD_MILLING_TOLERANCE_TIGHTER_THAN_ONE_HUNDREDTH_MM.
  16. check_horizontal_plane applied to the pocket depth returns an error code.
  17. The z-coordinate of the pocket depth location is not negative:
      POCKET_DEPTH_MUST_BE_BELOW_POCKET_TOP.
  18. The pocket slope is neither NULL nor zero:
      CANNOT_HANDLE_SLOPED_POCKET.
  19. The pocket planar_radius is neither NULL nor zero:
      CANNOT_HANDLE_POCKET_WITH_FILLET_AT_BOTTOM.
  20. The pocket orthogonal_radius is NULL:
      POCKET_CORNER_RADIUS_MUST_NOT_BE_NULL.
  21. The pocket orthogonal_radius is not positive:
      POCKET_CORNER_RADIUS_MUST_BE_POSITIVE.
  22. The pocket orthogonal_radius is greater than half the pocket width:
      POCKET_CORNER_RADIUS_MUST_NOT_EXCEED_HALF_POCKET_WIDTH.

Side Effects:  This sets the values of pocket_length, pocket_width,
      pocket_depth, and pocket_radius.

Called By:
  finish_mill_both_closed_pocket
  rough_mill_both_closed_pocket

C++ data for closedPocket
-------------------------
char *                        itsId;                 (manufacturingFeature)
workpiece *                   itsWorkpiece;
parenMachiningOperationList * itsOperations;
axis2placement3d *            featurePlacement;      (two5DmanufacturingFeature)
elementarySurface *           depth;                 (machiningFeature)
parenBossList *               itsBoss;               (pocket)
real *                        slope;            [opt]
pocketBottomCondition *       bottomCondition;
tolerancedLengthMeasure *     planarRadius;     [opt]
tolerancedLengthMeasure *     orthogonalRadius; [opt]
closedProfile *               featureBoundary;       (closedPocket)

C++ data for rectangularClosedProfile
-------------------------------------
axis2placement3d *        placement;     [opt] (profile)
<no attributes>                                (closedProfile)
tolerancedLengthMeasure * profileWidth;        (rectangularClosedProfile)
tolerancedLengthMeasure * profileLength;

Requiring the placement of the profile to be NULL could be removed, but it
would take a lot of code to deal with a placement.

*/

static int check_rectangular_pocket( /* ARGUMENTS                         */
 closedPocket * the_pocket,          /* the pocket being checked          */
 double * pocket_length,             /* length of pocket, set here        */
 double * pocket_width,              /* width of pocket, set here         */
 double * pocket_depth,              /* depth of pocket, set here         */
 double * pocket_radius)             /* corner radius of pocket, set here */
{
  static char name[] = "check_rectangular_pocket";
  rectangularClosedProfile * bound;
  plusMinusValue * tolerate;

  bound = dynamic_cast<rectangularClosedProfile *>
    (the_pocket->get_featureBoundary());
  CHK((bound == 0), POCKET_BOUNDARY_MUST_NOT_BE_NULL);
  CHK((NOT(bound->isA(rectangularClosedProfile_E))),
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE);
  CHK((bound->get_placement() != 0), CANNOT_HANDLE_PROFILE_PLACEMENT);
  CHK((bound->get_profileWidth() == 0),
      POCKET_PROFILE_WIDTH_MUST_NOT_BE_NULL);
  CHK((bound->get_profileLength() == 0),
      POCKET_PROFILE_LENGTH_MUST_NOT_BE_NULL);
  *pocket_width = bound->get_profileWidth()->get_theoreticalSize();
  *pocket_length = bound->get_profileLength()->get_theoreticalSize();
  CHK((*pocket_width <= 0), POCKET_WIDTH_MUST_BE_POSITIVE);
  CHK((*pocket_length <= 0), POCKET_LENGTH_MUST_BE_POSITIVE);
  CHK((*pocket_length < *pocket_width), POCKET_WIDTH_MUST_NOT_EXCEED_LENGTH);
  CHK((the_pocket->get_itsBoss() == 0), POCKET_BOSS_SET_MUST_NOT_BE_NULL);
  CHK((the_pocket->get_itsBoss()->get_theList()->size() != 0),
      CANNOT_HANDLE_BOSSES_IN_POCKET);
  tolerate = bound->get_profileWidth()->get_implicitTolerance();
  CHK((tolerate == 0), POCKET_WIDTH_TOLERANCE_MUST_NOT_BE_NULL);
  CHK((NOT(tolerate->isA(plusMinusValue_E))),
      CAN_HANDLE_ONLY_PLUS_MINUS_VALUE_TOLERANCE);
  CHK(((tolerate->get_upperLimit() < 0) OR (tolerate->get_lowerLimit() < 0)),
      TOLERANCE_LIMITS_MUST_NOT_BE_NEGATIVE);
  CHK(((tolerate->get_upperLimit() + tolerate->get_lowerLimit()) < 0.01),
      CANNOT_HOLD_MILLING_TOLERANCE_TIGHTER_THAN_ONE_HUNDREDTH_MM);
  tolerate = bound->get_profileLength()->get_implicitTolerance();
  CHK((tolerate == 0), POCKET_LENGTH_TOLERANCE_MUST_NOT_BE_NULL);
  CHK((NOT(tolerate->isA(plusMinusValue_E))),
      CAN_HANDLE_ONLY_PLUS_MINUS_VALUE_TOLERANCE);
  CHK(((tolerate->get_upperLimit() < 0) OR (tolerate->get_lowerLimit() < 0)),
      TOLERANCE_LIMITS_MUST_NOT_BE_NEGATIVE);
  CHK(((tolerate->get_upperLimit() + tolerate->get_lowerLimit()) < 0.01),
      CANNOT_HOLD_MILLING_TOLERANCE_TIGHTER_THAN_ONE_HUNDREDTH_MM);
  IFF(check_horizontal_plane(the_pocket->get_depth()));
  *pocket_depth = -getPtZ(the_pocket->get_depth()->get_position());
  CHK((*pocket_depth <= 0), POCKET_DEPTH_MUST_BE_BELOW_POCKET_TOP);
  CHK(((the_pocket->get_slope()) &&
       (the_pocket->get_slope()->get_val() != 0.0)),
      CANNOT_HANDLE_SLOPED_POCKET);
  CHK(((the_pocket->get_planarRadius() != 0) &&
       (the_pocket->get_planarRadius()->get_theoreticalSize() != 0.0)),
      CANNOT_HANDLE_POCKET_WITH_FILLET_AT_BOTTOM);
  CHK((the_pocket->get_orthogonalRadius() == 0),
      POCKET_CORNER_RADIUS_MUST_NOT_BE_NULL);
  *pocket_radius = the_pocket->get_orthogonalRadius()->get_theoreticalSize();
  CHK((*pocket_radius <= 0.0), POCKET_CORNER_RADIUS_MUST_BE_POSITIVE);
  CHK((*pocket_radius > ((*pocket_width + ISO14649_TINY) / 2.0)),
      POCKET_CORNER_RADIUS_MUST_NOT_EXCEED_HALF_POCKET_WIDTH);
  tolerate = the_pocket->get_orthogonalRadius()->get_implicitTolerance();
  CHK((NOT(tolerate->isA(plusMinusValue_E))),
      CAN_HANDLE_ONLY_PLUS_MINUS_VALUE_TOLERANCE);
  CHK(((tolerate->get_upperLimit() < 0) OR (tolerate->get_lowerLimit() < 0)),
      TOLERANCE_LIMITS_MUST_NOT_BE_NEGATIVE);
  CHK(((tolerate->get_upperLimit() + tolerate->get_lowerLimit()) < 0.01),
      CANNOT_HOLD_MILLING_TOLERANCE_TIGHTER_THAN_ONE_HUNDREDTH_MM);

  return ISO14649_OK;
}

/***********************************************************************/

/* check_rectangular_pocket_strategies

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The endmill will not fit into the pocket and leave the required
      side allowance: POCKET_MUST_NOT_BE_NARROWER_THAN_TOOL.
   2. The endmill will not fit into the corner of the pocket and leave
      the required side allowance: TOOL_MUST_FIT_IN_CORNERS_OF_POCKET.
   3. There is room only to plungeToolaxis on retract, but some other
      strategy is used:
      MUST_USE_PLUNGE_TOOLAXIS_TO_RETRACT_WHEN_POCKET_SAME_SIZE_AS_TOOL.
   4. There is room only to plungeToolaxis on approach, but some other
      strategy is used:
      MUST_USE_PLUNGE_TOOLAXIS_TO_APPROACH_WHEN_POCKET_SAME_SIZE_AS_TOOL.
   5. The overlap given in the inside strategy of the_cut is used and
      is not between 0 and 1:  OVERLAP_MUST_BE_BETWEEN_ZERO_AND_ONE.

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  rough_mill_both_closed_pocket

This is checking that the_endmill can be used to make the_pocket using
the strategies specified in the_cut.

Some type of strategy is needed for each of the three phases of milling
(enter, inside, leave), but they are optional in the_cut. If a strategy is
missing for any phase, this makes a strategy for that phase and inserts it
in the_cut.

The rules for selecting an approach strategy are as follows. Zigzag and
helix angles are 10 degrees in all cases.
1. If the width of the pocket is the width of the tool:
   a. Make a zigzag if the length of the pocket is greater than tool diameter.
   b. Plunge straight down if the length of the pocket is the tool diameter.
2. Otherwise, if width of the pocket is less than 1.4 times the tool diameter:
   a. Make a zigzag if length of pocket is more than 1.5 times tool diameter. 
   b. Make a helix that fits if not.
3. Otherwise, if width of the pocket is less than 1.8 times the tool diameter,
   make the largest helix that fits. The radius will be at least 0.2 times
   the tool diameter.
4. Otherwise, make a helix whose radius is 0.4 times tool diameter.

The endmill must already have been checked by check_tool_endmill when this
is called (because errors caught there will cause the system to crash here).

This assumes that width is not greater than length (which is checked by
check_rectangular_pocket).

This assumes the orthogonalRadius is not NULL (which is checked by
check_rectangular_pocket).

the_cut may be rough milling or finish milling.

This sets the stepover as follows.  The inside_strategy may include an
optional overlap attribute, which may be used to determine stepover.
The stepover, however, is also the optional attribute radialCuttingDepth
of the_cut. The spec does not say which one takes precedence if both
are used. Here, the radialCuttingDepth takes precedence. If neither is
given, the stepover is set here to the radius of the endmill.

*/

static int check_rectangular_pocket_strategies(/* ARGUMENTS                  */
 double pocket_length,                       /* length of pocket             */
 double pocket_width,                        /* width of pocket              */
 double pocket_depth,                        /* depth of pocket              */
 double pocket_radius,                       /* corner radius of pocket      */
 bottomAndSideMilling * the_cut,             /* milling operation to do      */
 endmill * the_endmill,                      /* endmill to cut pocket with   */
 double * stepover,                          /* stepover set here            */
 approachRetractStrategy ** enter_strategy,  /* approach set here if missing */
 approachRetractStrategy ** leave_strategy,  /* retract set here if missing  */
 two5DmillingStrategy ** inside_strategy,    /* inside set here if missing   */
 int is_finish)                              /* 1=finish cut, 0=rough cut    */
{
  static char name[] = "check_rectangular_pocket_strategies";
  double diameter;       /* endmill diameter */
  double extra_width;    /* amount of space available in width direction  */
  double extra_length;   /* amount of space available in length direction */
  double side;           /* side allowance */
  double overlap;        /* overlap for finding stepover */
  
  diameter = the_endmill->get_dimension()->get_diameter();
  side = (the_cut->get_allowanceSide() ?
	  the_cut->get_allowanceSide()->get_val() :
	  is_finish ? 0 : ISO14649_ALLOW);
  extra_width  = (pocket_width  - (diameter + (2 * side)));
  extra_length = (pocket_length - (diameter + (2 * side)));
  CHK((extra_width < -(ISO14649_TINY)), POCKET_MUST_NOT_BE_NARROWER_THAN_TOOL);
  CHK(((pocket_radius - side) < ((diameter / 2.0) - ISO14649_TINY)),
      TOOL_MUST_FIT_IN_CORNERS_OF_POCKET);
  if (the_cut->get_itsMachiningStrategy() == 0)
    {
      *inside_strategy =
	new contourParallel(0, new booleanTrue, new rotDirectionCw,
			    new cutmodeTypeConventional);
      the_cut->set_itsMachiningStrategy(*inside_strategy);
    }
  if (the_cut->get_radialCuttingDepth())
    *stepover = the_cut->get_radialCuttingDepth()->get_val();
  else
    {
      if (the_cut->get_itsMachiningStrategy()->get_overlap())
	{
	  overlap =
	    the_cut->get_itsMachiningStrategy()->get_overlap()->get_val();
	  CHK(((overlap < 0) OR (overlap > 1.0)),
	      OVERLAP_MUST_BE_BETWEEN_ZERO_AND_ONE);
	}
      else
	overlap = 0.5;
      *stepover = (diameter * (1 - overlap));
    }
  if (the_cut->get_retract() == 0)
    {
      *leave_strategy = new plungeToolaxis();
      the_cut->set_retract(*leave_strategy);
    }
  else if (extra_length < ISO14649_TINY)
    CHK((NOT(the_cut->get_retract()->isA(plungeToolaxis_E))),
        MUST_USE_PLUNGE_TOOLAXIS_TO_RETRACT_WHEN_POCKET_SAME_SIZE_AS_TOOL);
  if (the_cut->get_approach() == 0)
    {
      if (extra_width < ISO14649_TINY)
	{
	  if (extra_length < ISO14649_TINY)
	    *enter_strategy = new plungeToolaxis(0);
	  else
	    *enter_strategy =
	      new plungeZigzag(0, 10.0, MIN(extra_length, (3 * diameter)));
	}
      else if (extra_width < (diameter * 0.4))
	{
	  if (extra_length < (1.25 * extra_width))
	    *enter_strategy =
	      new plungeHelix(0, (extra_width / 2.0), 10.0);
	  else
	    *enter_strategy =
	      new plungeZigzag(0, 10.0, MIN(extra_length, (3 * diameter)));
	}
      else if (extra_width < (diameter * 0.8))
	*enter_strategy = new plungeHelix(0, (extra_width/2.0), 10.0);
      else
	*enter_strategy = new plungeHelix(0, (diameter * 0.4), 10.0);
      the_cut->set_approach(*enter_strategy);
    }
  else if (extra_length < ISO14649_TINY)
    CHK((NOT(the_cut->get_approach()->isA(plungeToolaxis_E))),
        MUST_USE_PLUNGE_TOOLAXIS_TO_APPROACH_WHEN_POCKET_SAME_SIZE_AS_TOOL);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_center_drill

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cuttingTool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not a centerDrill:
      TOOL_BODY_MUST_BE_A_CENTER_DRILL.
   5. check_tool_dimension returns an error code.

Side Effects:  flute_length is set.

Called By: op_center_drilling

C++ data for centerDrill
------------------------
<no attributes>                                  (tool_body)
millingToolDimension * dimension;                (millingToolBody)
integer *              numberOfTeeth;      [opt]
hand *                 handOfCut;          [opt]
boolean *              coolantThroughTool; [opt]
real *                 pilotLength;        [opt]
<no attributes>                                  (centerDrill)

C++ data for cuttingTool
------------------------
char *                          itsId;                       (machiningTool)
toolBody *                      itsToolBody;                 (cuttingTool)
parenCuttingComponentListFull * itsCuttingEdge;
real *                          overallAssemblyLength;  [opt]

The toolTopAngle of the dimension must be given. This is checked in
check_tool_dimension.

*/

static int check_tool_center_drill( /* ARGUMENTS                   */
 machiningTool * the_tool,          /* the (should be) centerDrill */
 double * flute_length)             /* flute_length, set here      */
{
  static char name[] = "check_tool_center_drill";
  toolBody * body;
  millingToolDimension * dimension;

  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isA(cuttingTool_E))
    body = (dynamic_cast<cuttingTool *>(the_tool))->get_itsToolBody();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isA(centerDrill_E))
    dimension = (dynamic_cast<centerDrill *>(body))->get_dimension();
  else
    CHK(1, TOOL_BODY_MUST_BE_A_CENTER_DRILL);
  IFF(check_tool_dimension(dimension, 0, 1, 0));
  *flute_length = dimension->get_cuttingEdgeLength()->get_val();
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_counterbore

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cuttingTool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not an endmill: TOOL_BODY_MUST_BE_AN_ENDMILL.
   5. The diameter of the hole differs from the diameter of the endmill:
      ENDMILL_DIAMETER_MUST_EQUAL_HOLE_DIAMETER.
   6. The given cut_depth is not NULL and it is the wrong
      depth: COUNTERBORE_DEPTH_MUST_EQUAL_CUTTING_DEPTH.
   7. The edge_length of the endmill is less than the depth of the
      hole: HOLE_MUST_NOT_BE_DEEPER_THAN_ENDMILL_IS_LONG.
   8. check_tool_dimension returns an error code.

Side Effects: See below

Called By: op_counter_boring

C++ data for cuttingTool
------------------------
char *                          itsId;                       (machiningTool)
toolBody *                      itsToolBody;                 (cuttingTool)
parenCuttingComponentListFull * itsCuttingEdge;
real *                          overallAssemblyLength;  [opt]

C++ data for endmill
-----------
<no attributes>                                  (tool_body)
millingToolDimension * dimension;                (millingToolBody)
integer *              numberOfTeeth;      [opt]
hand *                 handOfCut;          [opt]
boolean *              coolantThroughTool; [opt]
real *                 pilotLength;        [opt]

If the cut_depth is ISO14649_BAD_REAL, it is set to the correct depth.
Otherwise, this checks that cut_depth already is the correct depth.

The edgeRadius, toolTopAngle, and toolCircumferenceAngle of the
dimension must all be zero or not given. This is checked in
check_tool_dimension. I.e., the endmill must have a flat end and not
be tapered.

*/

static int check_tool_counterbore( /* ARGUMENTS                         */
 machiningTool * the_tool,         /* tool to check                     */
 roundHole * upper_hole,           /* hole to be counterbored by tool   */
 double * cut_depth)               /* cutting depth given in operation  */
{
  static char name[] = "check_tool_counterbore";
  toolBody * body;
  endmill * the_endmill;
  millingToolDimension * dimension;
  double edge_length;
  double depth;

  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isA(cuttingTool_E))
    body = (dynamic_cast<cuttingTool *>(the_tool))->get_itsToolBody();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isA(endmill_E))
    {
      the_endmill = dynamic_cast<endmill *>(body);
      dimension = the_endmill->get_dimension();
    }
  else
    CHK(1, TOOL_BODY_MUST_BE_AN_ENDMILL);
  IFF(check_tool_dimension(dimension, -1, -1, -1));

  edge_length = dimension->get_cuttingEdgeLength()->get_val();
  depth = -getPtZ(upper_hole->get_depth()->get_position());
  CHK((edge_length < depth), HOLE_MUST_NOT_BE_DEEPER_THAN_ENDMILL_IS_LONG);
  CHK((fabs(dimension->get_diameter() -
	    upper_hole->get_diameter()->get_theoreticalSize()) >
       ISO14649_TINY), ENDMILL_DIAMETER_MUST_EQUAL_HOLE_DIAMETER);
  if (*cut_depth == ISO14649_BAD_REAL)
    *cut_depth = depth;
  else
    CHK((fabs(*cut_depth - depth) > ISO14649_TINY),
	COUNTERBORE_DEPTH_MUST_EQUAL_CUTTING_DEPTH);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_countersink

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cuttingTool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not a countersink:
      TOOL_BODY_MUST_BE_A_COUNTERSINK.
   5. The toolTopAngle differs from the upper_hole_angle:
      TOOL_TAPER_MUST_EQUAL_HOLE_TAPER.
   6. The bottom diameter of the hole is smaller than twice the
      countersink_radius of the tool:
      COUNTERSINK_CUTTING_PORTION_MUST_REACH_HOLE_BOTTOM.
   7. The top diameter of the hole is larger than the diameter of the
      countersink: HOLE_DIAMETER_MUST_NOT_EXCEED_COUNTERSINK_DIAMETER.
   8. The given cut_depth is not NULL and it is the wrong
      depth: COUNTERSINK_DEPTH_MUST_MATCH_HOLE_DEPTH.
   9. check_tool_dimension returns an error code.

Side Effects: See below

Called By: op_counter_sinking

C++ data for cuttingTool
------------------------
char *                          itsId;                       (machiningTool)
toolBody *                      itsToolBody;                 (cuttingTool)
parenCuttingComponentListFull * itsCuttingEdge;
real *                          overallAssemblyLength;  [opt]

C++ data for countersink
------------------------
<no attributes>                                  (tool_body)
millingToolDimension * dimension;                (millingToolBody)
integer *              numberOfTeeth;      [opt]
hand *                 handOfCut;          [opt]
boolean *              coolantThroughTool; [opt]
real *                 pilotLength;        [opt]
real*                  countersinkRadius   [opt] (countersink)

Part 111 does not say which parameters from Figure 2 (the
millingToolDimension parameters listed immediately above) should be
used to define a countersink. In the case where the cutting portion of
the tool is outside the diameter at an angle given by the tool
circumference angle, all seven parameters could be used; this allows
the non-cutting tip to be shaped many ways. In the case where the
cutting portion of the tool is inside the diameter, it could be done
with toolTopAngle, cuttingEdgeLength, and diameter; this does not
allow the tip to be shaped. The example in Part 11 uses the second
method, so that method is used here.  Where edgeRadius is zero or not
used and toolCircumferenceAngle is zero or not used, the
toolTopAngle should equal atan2(cutting_edge_length, (diameter / 2)),
but that is not being checked here.

If the cutDepth is ISO14649_BAD_REAL, it is set to the correct depth.
Otherwise, this checks that cutDepth already is the correct depth. The
correct depth is the depth at which the tool flutes are just touching the
sides of the tapered hole.

The toolTopAngle of the dimension must be given. This is checked in
check_tool_dimension.

The toolTopAngle of the countersink must be the same as the
upper_hole_angle.

*/

static int check_tool_countersink( /* ARGUMENTS                         */
 machiningTool * the_tool,         /* tool to check                     */
 roundHole * upper_hole,           /* hole to be countersunk by tool    */
 double * cut_depth,               /* cutting depth given in operation  */
 double angle)                     /* angle from bottom to side of hole */
{
  static char name[] = "check_tool_countersink";
  toolBody * body;
  countersink * csinker;
  millingToolDimension * dimension;
  double diameter1;
  double diameter2;
  double height;
  double depth;

  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isA(cuttingTool_E))
    body = (dynamic_cast<cuttingTool *>(the_tool))->get_itsToolBody();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isA(countersink_E))
    {
      csinker = dynamic_cast<countersink *>(body);
      dimension = csinker->get_dimension();
    }
  else
    CHK(1, TOOL_BODY_MUST_BE_A_COUNTERSINK);
  IFF(check_tool_dimension(dimension, 0, 1, 0));
  CHK((fabs(angle - dimension->get_toolTopAngle()->get_val()) > ISO14649_TINY),
      TOOL_TAPER_MUST_EQUAL_HOLE_TAPER);
  diameter1 = upper_hole->get_diameter()->get_theoreticalSize();
  height = -getPtZ(upper_hole->get_depth()->get_position());
  diameter2 = (diameter1 - (2 * (height / tand(angle))));
  CHK((diameter2 < (2 * csinker->get_countersinkRadius()->get_val())),
      COUNTERSINK_CUTTING_PORTION_MUST_REACH_HOLE_BOTTOM);
  CHK((diameter1 > dimension->get_diameter()),
      HOLE_DIAMETER_MUST_NOT_EXCEED_COUNTERSINK_DIAMETER);
  depth = ((diameter1 / 2.0) * tand(angle));
  if (*cut_depth == ISO14649_BAD_REAL)
    *cut_depth = depth;
  else
    CHK((fabs(*cut_depth - depth) > ISO14649_TINY),
        COUNTERSINK_DEPTH_MUST_MATCH_HOLE_DEPTH);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_cutting

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cuttingTool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.

Side Effects: None

Called By: op_freeform

This does not check much since the intent of the freeform cutting is
unknown.

*/

static int check_tool_cutting( /* ARGUMENTS */
 machiningTool * the_tool)     /* the tool  */
{
  static char name[] = "check_tool_cutting";
  toolBody * body;

  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isA(cuttingTool_E))
    body = (dynamic_cast<cuttingTool *>(the_tool))->get_itsToolBody();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_dimension

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. dimension is NULL: DIMENSION_MUST_NOT_BE_NULL.
   2. diameter is not positive: TOOL_DIAMETER_MUST_BE_POSITIVE.
   3. cutting_edge_length is NULL:
      CUTTING_EDGE_LENGTH_MUST_BE_GIVEN.
   4. cutting_edge_length is not positive:
      CUTTING_EDGE_LENGTH_MUST_BE_POSITIVE.
   5. toolTopAngle is required but is NULL:
      TOOL_TOP_ANGLE_MUST_BE_GIVEN.
   6. toolTopAngle is not NULL but is negative:
      TOOL_TOP_ANGLE_MUST_NOT_BE_NEGATIVE.
   7. toolTopAngle is not NULL but is not less than 90 degrees:
      TOOL_TOP_ANGLE_MUST_BE_LESS_THAN_NINETY_DEGREES.
   8. toolTopAngle is required to be NULL or zero, but is not:
      TOOL_TOP_ANGLE_MUST_BE_ZERO_OR_NOT_GIVEN.
   9. toolCircumferenceAngle is required but is NULL:
      TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_GIVEN.
  10. toolCircumferenceAngle is not NULL but is negative:
      TOOL_CIRCUMFERENCE_ANGLE_MUST_NOT_BE_NEGATIVE.
  11. toolCircumferenceAngle is not NULL but is not less than 90 degrees:
      TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_LESS_THAN_NINETY_DEGREES.
  12. toolCircumferenceAngle is required to be NULL or zero, but is not:
      TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_ZERO_OR_NOT_GIVEN.
  13. edgeRadius is required but is NULL:
      EDGE_RADIUS_MUST_BE_GIVEN
  14. edgeRadius is not NULL but is negative:
      EDGE_RADIUS_MUST_NOT_BE_NEGATIVE.
  15. edgeRadius is required to be NULL or zero, but is not:
      EDGE_RADIUS_MUST_BE_ZERO_OR_NOT_GIVEN.

Side Effects:  none

Called By:
  check_tool_center_drill
  check_tool_counterbore
  check_tool_countersink
  check_tool_drill
  check_tool_endmill
  check_tool_plane
  check_tool_reamer
  
For each of the three flags, -1 means the value must be NULL or
zero, 1 means the value must be given, and 0 means there is neither
requirement.

Any value that is not NULL must be in range.

This does not check anything about edgeCenterVertical or
edgeCenterHorizontal.

C++ data for millingToolDimension
---------------------------------
double diameter:                     (millingToolDimension)
real * toolTopAngle;           [opt]
real * toolCircumferenceAngle; [opt]
real * cuttingEdgeLength;      [opt]
real * edgeRadius;             [opt]
real * edgeCenterVertical;     [opt]
real * edgeCenterHorizontal;   [opt]

*/

static int check_tool_dimension(   /* ARGUMENTS                   */
 millingToolDimension * dimension, /* the dimension to check      */
 int edgeRadius_flag,              /* flag for edgeRadius         */
 int toolTopAngle_flag,            /* flag for toolTopAngle       */
 int circumferenceAngle_flag)      /* flag for circumferenceAngle */
{
  static char name[] = "check_tool_dimension";
  double a; // toolTopAngle
  double b; // toolCircumferenceAngle
  double d; // diameter
  double e; // cutting_edge_length
  double r; // edgeRadius

  CHK((dimension == 0), DIMENSION_MUST_NOT_BE_NULL);

  d = dimension->get_diameter();
  CHK((d <= 0), TOOL_DIAMETER_MUST_BE_POSITIVE);

  CHK((dimension->get_cuttingEdgeLength() == 0),
      CUTTING_EDGE_LENGTH_MUST_BE_GIVEN);
  e = dimension->get_cuttingEdgeLength()->get_val();
  CHK((e <= 0), CUTTING_EDGE_LENGTH_MUST_BE_POSITIVE);
  
  if (dimension->get_toolTopAngle() == 0)
    CHK((toolTopAngle_flag == 1), TOOL_TOP_ANGLE_MUST_BE_GIVEN);
  else
    {
      a = dimension->get_toolTopAngle()->get_val();
      CHK((a < 0), TOOL_TOP_ANGLE_MUST_NOT_BE_NEGATIVE);
      CHK((a >= 90), TOOL_TOP_ANGLE_MUST_BE_LESS_THAN_NINETY_DEGREES);
      CHK(((toolTopAngle_flag == -1) && (a != 0)),
	  TOOL_TOP_ANGLE_MUST_BE_ZERO_OR_NOT_GIVEN);
    }
  
  if (dimension->get_toolCircumferenceAngle() == 0)
    CHK((circumferenceAngle_flag == 1),
        TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_GIVEN);
  else
    {
      b = dimension->get_toolCircumferenceAngle()->get_val();
      CHK((b < 0), TOOL_CIRCUMFERENCE_ANGLE_MUST_NOT_BE_NEGATIVE);
      CHK((b >= 90),
	  TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_LESS_THAN_NINETY_DEGREES);
      CHK(((circumferenceAngle_flag == -1) && (b != 0)),
	  TOOL_CIRCUMFERENCE_ANGLE_MUST_BE_ZERO_OR_NOT_GIVEN);
    }

  if (dimension->get_edgeRadius() == 0)
    CHK((edgeRadius_flag == 1), EDGE_RADIUS_MUST_BE_GIVEN);
  else
    {
      r = dimension->get_edgeRadius()->get_val();
      CHK((r < 0), EDGE_RADIUS_MUST_NOT_BE_NEGATIVE);
      CHK(((edgeRadius_flag == -1) && (r != 0)),
	  EDGE_RADIUS_MUST_BE_ZERO_OR_NOT_GIVEN);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_drill

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cuttingTool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not a drill: TOOL_BODY_MUST_BE_A_TWIST_DRILL.
   5. check_tool_dimension returns an error code.

Side Effects:  flute_length is set.

Called By:
   op_drilling
   op_multistep_drilling

C++ data for cuttingTool
------------------------
char *                          itsId;                       (machiningTool)
toolBody *                      itsToolBody;                 (cuttingTool)
parenCuttingComponentListFull * itsCuttingEdge;
real *                          overallAssemblyLength;  [opt]

C++ data for twistDrill
-----------------------
<no attributes>                                  (tool_body)
millingToolDimension * dimension;                (millingToolBody)
integer *              numberOfTeeth;      [opt]
hand *                 handOfCut;          [opt]
boolean *              coolantThroughTool; [opt]
real *                 pilotLength;        [opt]
<no attributes>                                  (drill)
<no attributes>                                  (twistDrill)

The toolTopAngle of the dimension must be given. This is checked in
check_tool_dimension.

*/

static int check_tool_drill( /* ARGUMENTS                  */
 machiningTool * the_tool,   /* the (should be) twistDrill */
 double * flute_length)      /* flute_length, set here     */
{
  static char name[] = "check_tool_drill";
  toolBody * body;
  millingToolDimension * dimension;

  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isA(cuttingTool_E))
    body = (dynamic_cast<cuttingTool *>(the_tool))->get_itsToolBody();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isA(twistDrill_E))
    dimension = (dynamic_cast<drill *>(body))->get_dimension();
  else
    CHK(1, TOOL_BODY_MUST_BE_A_TWIST_DRILL);
  IFF(check_tool_dimension(dimension, 0, 1, 0));
  *flute_length = dimension->get_cuttingEdgeLength()->get_val();
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_endmill

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cuttingTool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not an endmill: TOOL_BODY_MUST_BE_AN_ENDMILL.
   5. check_tool_dimension returns an error code.

Side Effects: the_endmill is set

Called By:
   op_finish_milling_both
   op_rough_milling_both

C++ data for cuttingTool
------------------------
char *                          itsId;                       (machiningTool)
toolBody *                      itsToolBody;                 (cuttingTool)
parenCuttingComponentListFull * itsCuttingEdge;
real *                          overallAssemblyLength;  [opt]

C++ data for endmill
--------------------
<no attributes>                                  (toolBody)
millingToolDimension * dimension;                (millingToolBody)
integer *              numberOfTeeth;      [opt]
hand *                 handOfCut;          [opt]
boolean *              coolantThroughTool; [opt]
real *                 pilotLength;        [opt]
<no attributes>                                  (millingCutter)
<no attributes>                                  (endmill)

The edgeRadius, toolTopAngle, and toolCircumferenceAngle of the
dimension must all be zero or not given. This is checked in
check_tool_dimension. I.e., the endmill must have a flat end and not
be tapered.

*/

static int check_tool_endmill( /* ARGUMENTS               */
 machiningTool * the_tool,     /* the (should be) endmill */
 endmill ** the_endmill)       /* the endmill, set here   */
{
  static char name[] = "check_tool_endmill";
  toolBody * body;
  millingToolDimension * dimension;
  
  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isA(cuttingTool_E))
    body = (dynamic_cast<cuttingTool *>(the_tool))->get_itsToolBody();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isA(endmill_E))
    {
      *the_endmill = dynamic_cast<endmill *>(body);
      dimension = (*the_endmill)->get_dimension();
    }
  else
    CHK(1, TOOL_BODY_MUST_BE_AN_ENDMILL);
  IFF(check_tool_dimension(dimension, -1, -1, -1));
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cuttingTool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is neither an endmill nor a facemill:
      TOOL_BODY_MUST_BE_AN_ENDMILL_OR_A_FACEMILL.
   5. check_tool_dimension returns an error code.

Side Effects: the_endmill or the_facemill is set.

Called By:
  op_finish_milling_plane
  op_rough_milling_plane

Notes:

This is requiring that the edge radius of the endmill or facemill be
zero or not given. This requirement could be relaxed, but checking the
operation would then be a little harder, since the effective cutting
diameter of the tool would be reduced.

*/

static int check_tool_plane( /* ARGUMENTS                                  */
 machiningTool * the_tool,   /* the (should be) endmill or facemill        */
 endmill ** the_endmill,     /* the endmill, set here if tool is endmill   */
 facemill ** the_facemill)   /* the facemill, set here if tool is facemill */
{
  static char name[] = "check_tool_plane";
  toolBody * body;
  millingToolDimension * dimension;
  
  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isA(cuttingTool_E))
    body = (dynamic_cast<cuttingTool *>(the_tool))->get_itsToolBody();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isA(endmill_E))
    {
      *the_endmill = dynamic_cast<endmill *>(body);
      dimension = (*the_endmill)->get_dimension();
    }
  else if (body->isA(facemill_E))
    {
      *the_facemill = dynamic_cast<facemill *>(body);
      dimension = (*the_facemill)->get_dimension();
    }
  else
    CHK(1, TOOL_BODY_MUST_BE_AN_ENDMILL_OR_A_FACEMILL);
  IFF(check_tool_dimension(dimension, -1, -1, -1));
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tool_reamer

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cuttingTool: MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not a reamer: TOOL_BODY_MUST_BE_A_REAMER.
   5. check_tool_dimension returns an error code.

Side Effects: flute_length is set

Called By: op_reaming

C++ data for cuttingTool
------------------------
char *                          itsId;                       (machiningTool)
toolBody *                      itsToolBody;                 (cuttingTool)
parenCuttingComponentListFull * itsCuttingEdge;
real *                          overallAssemblyLength;  [opt]

C++ data for reamer
-------------------
<no attributes>                                  (tool_body)
millingToolDimension * dimension;                (millingToolBody)
integer *              numberOfTeeth;      [opt]
hand *                 handOfCut;          [opt]
boolean *              coolantThroughTool; [opt]
real *                 pilotLength;        [opt]
<no attributes>                                  (reamer)

The edgeRadius, toolTopAngle, and toolCircumferenceAngle of the
dimension must all be zero or not given. This is checked in
check_tool_dimension. I.e., the reamer must have a flat end and not
be tapered.

*/

static int check_tool_reamer( /* ARGUMENTS              */
 machiningTool * the_tool,    /* the (should be) reamer */
 double * flute_length)       /* flute length, set here */
{
  static char name[] = "check_tool_reamer";
  toolBody * body;
  millingToolDimension * dimension;
  
  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  if (the_tool->isA(cuttingTool_E))
    body = (dynamic_cast<cuttingTool *>(the_tool))->get_itsToolBody();
  else
    CHK(1, MACHINING_TOOL_MUST_BE_A_CUTTING_TOOL);
  CHK((body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
  if (body->isA(reamer_E))
    dimension = (dynamic_cast<reamer *>(body))->get_dimension();
  else
    CHK(1, TOOL_BODY_MUST_BE_A_REAMER);
  IFF(check_tool_dimension(dimension, -1, -1, -1));
  *flute_length = dimension->get_cuttingEdgeLength()->get_val();
  return ISO14649_OK;
}

/***********************************************************************/

/* check_tools

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The tool for a machiningWorkingstep is not a cuttingTool:
      TOOL_FOR_MACHINING_MUST_BE_A_CUTTING_TOOL.
   2. The toolBody of a tool for machining is not a millingToolBody:
      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY.
   3. The diameter of a tool for machining associated with a
      machiningWorkingstep is not within 0.001 mm of the diameter of the
      same tool given in the tool table:
      TOOL_DIAMETERS_MUST_BE_SAME_FOR_SAME_TOOL.
   4. The list of cuttingComponents for a tool does not have exactly one
      member: TOOL_FOR_MACHINING_MUST_HAVE_HAVE_EXACTLY_ONE_COMPONENT.
   5. A tool required by the ISO 14649 program cannot be found in the
      tool table: REQUIRED_TOOL_MUST_BE_IN_TOOL_TABLE.
   6. The handedness of a tool is not given: TOOL_HANDEDNESS_MUST_BE_GIVEN.


Side Effects: See below

Called By: iso14649_open

This checks that:
1. all the tools required by an ISO 14649 program are present on the
   machine (as determined by matching ids with the _world.tool_table).
2. the _world.tool_table has the same diameter for each tool as does the
   program.
3. all the tools in the ISO program have a value for handedness. This
   check is included so that values for spindle speed (negative for
   right-handed tools) can be checked. It is expected that many programs
   will have a mismatch between spindle speed and handedness.

The ISO 14649 program has a number for the tool length offset, but that
number is not expected to be correct. The number is reset to the tool length
offset recorded in the _world.tool_table. (Per discussion with Fred
Proctor in December 2002).

*/

static int check_tools(                 /* ARGUMENTS                        */
 std::list<executable *> * executables) /* the list of executables to check */
{
  static char name[] = "check_tools";
  int index;
  machiningWorkingstep * a_mach;
  executable * an_ex;
  cuttingTool * a_tool;
  millingToolBody * mill_body;
  std::list<executable *>::iterator iter;
  cuttingComponent * comp;

  for (iter = executables->begin(); iter != executables->end(); ++iter)
    {
      an_ex = *iter;
      if (an_ex->isA(machiningWorkingstep_E))
	{
	  a_mach = dynamic_cast<machiningWorkingstep *>(an_ex);
	  for (index = 0; index <= _world.tool_max; index++)
	    {
	      if (strcmp(a_mach->get_itsOperation()->get_itsTool()->get_itsId(),
			 _world.tool_table[index].id) == 0)
		{
		  CHK((NOT(a_mach->get_itsOperation()->
			   get_itsTool()->isA(cuttingTool_E))),
		      TOOL_FOR_MACHINING_MUST_BE_A_CUTTING_TOOL);
		  a_tool = dynamic_cast<cuttingTool *>
		    (a_mach->get_itsOperation()->get_itsTool());
		  CHK((NOT(a_tool->get_itsToolBody()->isA(millingToolBody_E))),
		      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY);
		  mill_body =
		    dynamic_cast<millingToolBody *>(a_tool->get_itsToolBody());
		  CHK(((fabs(mill_body->get_dimension()->get_diameter() -
			    _world.tool_table[index].diameter)) > 0.001),
		      TOOL_DIAMETERS_MUST_BE_SAME_FOR_SAME_TOOL);
		  CHK((mill_body->get_handOfCut() == 0),
		      TOOL_HANDEDNESS_MUST_BE_GIVEN);
		  CHK((a_tool->get_itsCuttingEdge()->get_theList()->size()
		       != 1),
		      TOOL_FOR_MACHINING_MUST_HAVE_EXACTLY_ONE_COMPONENT);
		  comp = a_tool->get_itsCuttingEdge()->get_theList()->front();
		  comp->set_toolOffsetLength(_world.tool_table[index].length);
		  break;
		}
	    }
	  CHK((index > _world.tool_max), REQUIRED_TOOL_MUST_BE_IN_TOOL_TABLE);
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* cut_feature

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_feature is NULL: FEATURE_MUST_NOT_BE_NULL.
   2. the_operation is NULL: OPERATION_MUST_NOT_BE_NULL.
   3. the_operation is not one of its_operations of the_feature:
      OPERATION_MUST_BELONG_TO_FEATURE.
   4. the_operation is not one of the types listed below:
      MACHINING_OPERATION_TYPE_MUST_BE_DEFINED_TYPE.
   5. handle_machine_functions returns an error code.
   6. handle_technology returns an error code.
   7. a backboring operation is called for: CANNOT_HANDLE_BACKBORING.
   8. a boring operation is called for: CANNOT_HANDLE_BORING.
   9. a tapping operation is called for: CANNOT_HANDLE_TAPPING.
  10. a threadDrilling operation is called for: CANNOT_HANDLE_THREAD_DRILLING.
  11. Any of the specific feature cutting functions returns an error code.

Side Effects: See below

Called By: execute_machining

The_operation normally makes part or all of the_feature. If an
explicit toolpath is given, however, the operation may do something
else. In addition, some operations (such as a drillingTypeOperation
when cuttingDepth is given) may make more or less than the feature,
even if toolpath is not given. The_operation must be one of the 16
instantiable types marked with an asterisk in the hierarchy below.
This checks to see which of the instantiable types of operation
the_operation is and calls a subordinate function to handle that type.

The C++ machiningOperation hierarchy (instantiable types marked with *) is:

machiningOperation
  millingMachiningOperation
    drillingTypeOperation
      drillingOperation
        drilling *
        centerDrilling *
        counterSinking *
        multistepDrilling *
      boringOperation
        boring *
        reaming *
      backBoring *
      tapping *
      threadDrilling *
    millingTypeOperation
      freeformOperation *
      two5DmillingOperation
        planeMilling
          planeRoughMilling *
          planeFinishMilling *
        sideMilling
          sideRoughMilling *
          sideFinishMilling *
        bottomAndSideMilling
          bottomAndSideRoughMilling *
          bottomAndSideFinishMilling *

This handles only machiningFeatures. countersunkHole is not a
machiningFeature, so this does not do countersinking. That is done elsewhere.

*/

static int cut_feature(              /* ARGUMENTS                          */
 machiningFeature * the_feature,     /* feature to make                    */
 millingMachineFunctions * funcs,    /* milling machine functions          */
 millingTechnology * tech,           /* milling technology                 */
 machiningOperation * the_operation) /* machining op to perform on feature */
{
  static char name[] = "cut_feature";
  std::list<machiningOperation *> * feature_ops;
  std::list<machiningOperation *>::iterator iter;
  
  CHK((the_feature == 0), FEATURE_MUST_NOT_BE_NULL);
  CHK((the_operation == 0), OPERATION_MUST_NOT_BE_NULL);
  feature_ops = the_feature->get_itsOperations()->get_theList();
  for (iter = feature_ops->begin(); iter != feature_ops->end(); ++iter)
    {
      if (the_operation == (*iter))
	break;
    }
  CHK((iter == feature_ops->end()), OPERATION_MUST_BELONG_TO_FEATURE);
  if ((NOT(the_operation->isA(drilling_E))) &&
      (NOT(the_operation->isA(freeformOperation_E))))
    {
      IFF(handle_machine_functions(funcs));
      IFF(handle_technology(tech, the_operation->get_itsTool()));
    }
  if (the_operation->isA(backBoring_E))
    CHK(1, CANNOT_HANDLE_BACKBORING);
  else if (the_operation->isA(boring_E))
    CHK(1, CANNOT_HANDLE_BORING);
  else if (the_operation->isA(bottomAndSideFinishMilling_E))
    IFF(op_finish_milling_both
	(the_feature,
	 dynamic_cast<bottomAndSideFinishMilling *>(the_operation)));
  else if (the_operation->isA(bottomAndSideRoughMilling_E))
    IFF(op_rough_milling_both
	(the_feature,
	 dynamic_cast<bottomAndSideRoughMilling *>(the_operation)));
  else if (the_operation->isA(centerDrilling_E))
    IFF(op_center_drilling
	(the_feature, dynamic_cast<centerDrilling *>(the_operation)));
  else if (the_operation->isA(drilling_E))
    IFF(op_drilling(the_feature, funcs, tech,
		    dynamic_cast<drilling *>(the_operation)));
  else if (the_operation->isA(freeformOperation_E))
    IFF(op_freeform(the_feature, funcs, tech,
		    dynamic_cast<freeformOperation *>(the_operation)));
  else if (the_operation->isA(multistepDrilling_E))
    IFF(op_multistep_drilling
	(the_feature, dynamic_cast<multistepDrilling *>(the_operation)));
  else if (the_operation->isA(planeFinishMilling_E))
    IFF(op_finish_milling_plane
	(the_feature, dynamic_cast<planeFinishMilling *>(the_operation)));
  else if (the_operation->isA(planeRoughMilling_E))
    IFF(op_rough_milling_plane
	(the_feature, dynamic_cast<planeRoughMilling *>(the_operation)));
  else if (the_operation->isA(reaming_E))
    IFF(op_reaming
	(the_feature, dynamic_cast<reaming *>(the_operation)));
  else if (the_operation->isA(sideFinishMilling_E))
    IFF(op_finish_milling_side
	(the_feature, dynamic_cast<sideFinishMilling *>(the_operation)));
  else if (the_operation->isA(sideRoughMilling_E))
    IFF(op_rough_milling_side
	(the_feature, dynamic_cast<sideRoughMilling *>(the_operation)));
  else if (the_operation->isA(tapping_E))
    CHK(1, CANNOT_HANDLE_TAPPING);
  else if (the_operation->isA(threadDrilling_E))
    CHK(1, CANNOT_HANDLE_THREAD_DRILLING);
  else
    CHK(1, MACHINING_OPERATION_TYPE_MUST_BE_DEFINED_TYPE);
  return ISO14649_OK;
}

/***********************************************************************/

/* cut_straight

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. write_traverse returns an error code.
   3. A non-plunge approach strategy is used: CAN_HANDLE_ONLY_PLUNGE_APPROACH
   4. A plungeHelix approach strategy is used:
      POCKET_WIDTH_MUST_EXCEED_TOOL_DIAMETER_FOR_PLUNGE_HELIX.
   5. A non-plungeToolaxis retract strategy is used:
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT.
   6. enter_pocket_pass returns an error code.
   7. find_pocket_plunge_start returns an error code.

Side Effects: See below

Called By: mill_rectangular_pocket

This is for cutting a straight groove the width of the tool. The
actual feature being cut is not required to be a groove. The center
line of the groove lies on the X-axis, and the middle of the groove
is at the origin.

The approach method must be either a plungeToolaxis, a plungeRamp,
or a plungeZigzag. There is no room for a plungeHelix. The first
plunge is from retract above the XY plane to pass_depth below it.
Subsequent plunges are all to one pass_depth deeper. Each plunge
ends at end2, the -X end of the groove.

After each plunge, the tool cuts to end1, the +X end of the groove.

This is making the minimum number of passes required (as determined
from the depth and the pass_depth), but rather than [making all but
the last pass be exactly pass_depth thick and cutting whatever
thickness is left in the last pass], this makes all passes the same
thickness, which may be less than pass_depth.

This does the approach move to get to the next pass depth at the
beginning of each pass, rather than doing the approach move to full
depth once. This seems to be how the spec wants it. See Part 11,
section 4.2.6.2, for example.

This is not changing the feedrate for slotting or plunging because it
is slotting or plunging all the time. It is assumed the program was
written with the feedrate set appropriately for slotting.

This will do a pure zigzag (with no retract and move between passes)
by setting the zigzag width to the distance between tool centers at
the ends of the groove and setting the zigzag angle to exactly (at
five decimal places) the angle required to move one pass depth in Z while
moving the zigzag width horizontally.

*/

static int cut_straight(          /* ARGUMENTS                     */
 double length,                   /* length of cut                 */
 double depth,                    /* (positive) total depth of cut */
 double retract,                  /* amount of retract at feedrate */
 double pass_depth,               /* (positive) depth in one pass  */
 approachRetractStrategy * enter, /* approach strategy             */
 approachRetractStrategy * leave, /* retract strategy              */
 double diameter,                 /* diameter of tool              */
 double code[][7],                /* code array to write in        */
 int * lines)                     /* code array index              */
{
  static char name[] = "cut_straight";
  int passes;              // number of passes
  int n;                   // index for passes
  double end1;             // tool tip X coordinate at +X end of groove
  double end2;             // tool tip X coordinate at -X end of groove
  double z_now;            // current Z coordinate
  plungeStrategy * entry;  // plunge entry strategy
  double start_x;          // X coordinate of start point
  double start_y;          // Y coordinate of start point
  double aux;

  CHK((NOT(enter->isA(plungeStrategy_E))),
      CAN_HANDLE_ONLY_PLUNGE_APPROACH);
  CHK((enter->isA(plungeHelix_E)),
      POCKET_WIDTH_MUST_EXCEED_TOOL_DIAMETER_FOR_PLUNGE_HELIX);
  entry = dynamic_cast<plungeStrategy *>(enter);
  passes = (1 + (int)((depth - ISO14649_TINY) / pass_depth));
  pass_depth = (depth / passes);
  end1 = ((length - diameter) / 2.0);
  end2 = -end1;
  z_now = -pass_depth;
  IFF(find_pocket_plunge_start((length - diameter), 0, (retract + pass_depth), 
			       entry, &start_x, &start_y, &aux));
  IFF(write_feed(start_x, start_y, retract, code, lines)); /* start point */
  IFF(enter_pocket_pass(entry, start_x, start_y, retract, end2,
			z_now, aux, code, lines));
  IFF(write_feed(end1, 0, z_now, code, lines));
  if (passes > 1)
    IFF(find_pocket_plunge_start((length - diameter), 0, pass_depth, 
				 entry, &start_x, &start_y, &aux));
  for (n = 1; n < passes; n++)
    {
      if ((fabs(end1 - start_x) > ISO14649_TINY) OR
	  (fabs(start_y) > ISO14649_TINY))
	{
	  IFF(write_feed(end1, 0, (z_now + pass_depth), code, lines));
	  IFF(write_traverse(start_x, start_y, (z_now + pass_depth),
			     code, lines));
	  IFF(write_feed(start_x, start_y, z_now, code, lines));
	}
      z_now = (z_now - pass_depth);
      IFF(enter_pocket_pass(entry, start_x, start_y, (z_now + pass_depth),
			    end2, z_now, aux, code, lines));
      IFF(write_feed(end1, 0, z_now, code, lines));
    }
  if (leave->isA(plungeToolaxis_E))
    IFF(write_feed(end1, 0, retract, code, lines));
  else
    CHK(1, CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT);
  return ISO14649_OK;
}

/***********************************************************************/

/* dist

Returned Value: double
  This returns the distance between two cartesianPoints, unless either
  one of the points is null or the coordinates of one of the points
  is null, in which case it returns 10000000.0.

Side Effects: none

Called By:
  follow_polyline_forward
  follow_trimmedCurve_forward

This is not checking that both lists have three entries. It will return
an incorrect value if any entry is missing (but it won't crash).

*/

static double dist(   /* ARGUMENTS    */
 cartesianPoint * p1, /* first point  */
 cartesianPoint * p2) /* second point */
{
  double result;
  double d;
  std::list<real *> * list1;
  std::list<real *> * list2;
  std::list<real *>::iterator iter1;
  std::list<real *>::iterator iter2;
  
  result = 0;
  if ((!p1) || (!p2))
    return 10000000.0;
  list1 = p1->get_coordinates()->get_theList();
  list2 = p2->get_coordinates()->get_theList();
  if ((!list1) || (!list2))
    return 10000000.0;
  for (iter1 = list1->begin(), iter2 = list2->begin();
       ((iter1 != list1->end()) && (iter2 != list2->end()));
       ++iter1, ++iter2)
    {
      d = ((*iter1)->get_val() - (*iter2)->get_val());
      result = (result + (d * d));
    }
  return sqrt(result);
}

/***********************************************************************/

/* enter_pocket_pass

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. The end of the entry is not at (end_x, 0): BUG_IN_ENTERING_POCKET.
   3. The plunge strategy is not one of the four subtypes:
      PLUNGE_STRATEGY_TYPE_MUST_BE_DEFINED_TYPE.
   4. enter_pocket_pass_helix returns an error code.
   5. enter_pocket_pass_zigzag returns an error code.

Side Effects: See below

Called By:
  cut_straight
  mill_rectangular_pocket_regular

In all cases, the tool tip starts at (start_x, start_y, start_z)

In all cases, the end of the starting motion is
at X = (length - width)/-2.0    Y = 0.0

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

In case of a plungeToolaxis, the start point X and Y coordinates
are the same as those of end point.

In case of a plungeRamp, a straight cut is made from the start point
to the end point. See documentation of find_pocket_plunge_start_ramp for
how the start point is selected.

For plungeZigzag, aux is the X-offset from the start point to
the second point.

For plungeHelix, aux is the number of turns for write_arc, as a double.

The value of aux is irrelevant for plungeToolaxis and plungeRamp.

*/

static int enter_pocket_pass( /* ARGUMENTS                    */
 plungeStrategy * enter,      /* plunge entry strategy to use */
 double start_x,              /* X coordinate of start point  */
 double start_y,              /* Y coordinate of start point  */
 double start_z,              /* Z coordinate of start point  */
 double end_x,                /* X coordinate of end point    */
 double end_z,                /* Z coordinate of end point    */
 double aux,                  /* see above                    */
 double code[][7],            /* code array to write in       */
 int * lines)                 /* code array index             */
{
  static char name[] = "enter_pocket_pass";

  if (enter->isA(plungeToolaxis_E))
    {
      CHK(((start_x != end_x) OR (start_y != 0)), BUG_IN_ENTERING_POCKET);
      IFF(write_feed(end_x, 0, end_z, code, lines));
    }
  else if(enter->isA(plungeRamp_E))
    {
      IFF(write_feed(end_x, 0, end_z, code, lines));
    }
  else if (enter->isA(plungeZigzag_E))
    IFF(enter_pocket_pass_zigzag(dynamic_cast<plungeZigzag *>(enter), start_x,
				 start_z, end_x, end_z, aux, code, lines));
  else if (enter->isA(plungeHelix_E))
    IFF(enter_pocket_pass_helix(dynamic_cast<plungeHelix *>(enter), start_x,
				start_y, start_z, end_x, end_z, (int)aux,
				code, lines));
  else
    CHK(1, PLUNGE_STRATEGY_TYPE_MUST_BE_DEFINED_TYPE);

  return ISO14649_OK;
}

/***********************************************************************/

/* enter_pocket_pass_helix

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_arc returns an error code.

Side Effects: See below

Called By: enter_pocket_pass

The action of this function is coordinated with the action of
find_pocket_plunge_start_helix, which finds the start_x, start_y and
turns used here. See documentation of find_pocket_plunge_start_helix
for how the start point is found.

The helix is clockwise, starts at (start_x, start_y), is centered on
(end_x, 0) and ends at (end_x, -radius), i.e. at 6 o'clock. A
clockwise semicircle is made at constant depth after the helix is
made, with its radius half the helix radius, so that the tool tip ends
at (end_x, 0) traveling in the +X direction.

*/

static int enter_pocket_pass_helix( /* ARGUMENTS                     */
 plungeHelix * hely,                /* zigzag entry strategy         */
 double start_x,                    /* X coordinate of start point   */
 double start_y,                    /* Y coordinate of start point   */
 double start_z,                    /* Z coordinate of start point   */
 double end_x,                      /* X coordinate of end point     */
 double end_z,                      /* Z coordinate of end point     */
 int turns,                         /* number of turns for write_arc */
 double code[][7],                  /* code array to write in        */
 int * lines)                       /* code array index              */
{
  static char name[] = "enter_pocket_pass_helix";

  IFF(write_arc(end_x, -(hely->get_radius()), end_x, 0,
		turns, end_z, code, lines));
  IFF(write_arc(end_x, 0, end_x, (hely->get_radius() / -2),
		-1, end_z, code, lines));
  return ISO14649_OK;
}

/***********************************************************************/

/* enter_pocket_pass_zigzag

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.

Side Effects: See below

Called By: enter_pocket_pass

The zigzag is on the X axis, starting at start_x. The first move is to
ramp down along the X axis by offset_x (towards +X if offset_x is
positive, towards -X if offset X is negative). The second and
subsequent moves except the last is to ramp down in the opposite
direction by the ramp width. The last move is to ramp down to the
end point.

The action of this function is coordinated with the action of
find_pocket_plunge_start_zigzag, which finds the start_x, start_y, and
offset_x used here. See documentation of find_pocket_plunge_start_zigzag
for how the start point and offset_x are found.

*/

static int enter_pocket_pass_zigzag( /* ARGUMENTS                      */
 plungeZigzag * ziggy,               /* zigzag entry strategy          */
 double start_x,                     /* X coordinate of start point    */
 double start_z,                     /* Z coordinate of start point    */
 double end_x,                       /* X coordinate of end point      */
 double end_z,                       /* Z coordinate of end point      */
 double offset_x,                    /* X offset, start_x to 2nd point */
 double code[][7],                   /* code array to write in         */
 int * lines)                        /* code array index               */
{
  static char name[] = "enter_pocket_pass_zigzag";
  double angle;     /* angle of zigzag     */
  double distance;  /* length of zigzag    */
  double x1;        /* zigzag +X end value */
  double x2;        /* zigzag -X end value */
  double z_now;
  double x_now;
  double zig_depth;
  
  angle = ziggy->get_angle();
  distance = ziggy->get_width();
  if (offset_x > 0)
    {
      x1 = (start_x + offset_x);
      x2 = (x1 - distance);
      x_now = x1;
    }
  else
    {
      x2 = (start_x + offset_x);
      x1 = (x2 + distance);
      x_now = x2;
    }
  zig_depth = (fabs(offset_x) * tand(angle));
  z_now = (start_z - zig_depth);
  IFF(write_feed(x_now, 0, z_now, code, lines));
  zig_depth = (distance * tand(angle));
  z_now = (z_now - zig_depth);
  for (; z_now > (end_z + ISO14649_TINY); z_now = (z_now - zig_depth))
    {
      x_now = ((x_now == x1) ? x2 : x1);
      IFF(write_feed(x_now, 0, z_now, code, lines));
    }
  if (fabs(x_now - end_x) > ISO14649_TINY)
    IFF(write_feed(end_x, 0, end_z, code, lines));
  return ISO14649_OK;
}

/***********************************************************************/

/* execute_executable

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. *(_world.iter) is NULL: EXECUTABLE_MUST_NOT_BE_NULL.
   2. *(_world.iter) is a program_structure: CANNOT_HANDLE_PROGRAM_STRUCTURE.
   3. *(_world.iter) is an unknown type: EXECUTABLE_TYPE_MUST_BE_DEFINED_TYPE.
   4. execute_workingstep returns an error code.
   5. execute_nc_function returns an error code.

Side Effects: This executes the executable that is _world.a_exec.
_world.name_text is set to the name of _world.a_exec at the beginning.

Called By: iso14649_execute

*/

static int execute_executable() /* NO ARGUMENTS */
{
  static char name[] = "execute_executable";
  executable * the_exec;
  
  the_exec = *(_world.iter);
  CHK((the_exec == 0), EXECUTABLE_MUST_NOT_BE_NULL);
  strcpy(_world.name_text, the_exec->get_itsId());
  if (the_exec->isA(workingstep_E))
    IFF(execute_workingstep(dynamic_cast<workingstep *>(the_exec)));
  else if (the_exec->isA(ncFunction_E))
    IFF(execute_nc_function(dynamic_cast<ncFunction *>(the_exec)));
  else if (the_exec->isA(programStructure_E))
    CHK(1, CANNOT_HANDLE_PROGRAM_STRUCTURE);
  else
    CHK(1, EXECUTABLE_TYPE_MUST_BE_DEFINED_TYPE);
  return ISO14649_OK;
}

/****************************************************************************/

/* execute_machining

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The operation to perform is NULL: OPERATION_MUST_NOT_BE_NULL.
   2. The feature to machine is NULL: FEATURE_MUST_NOT_BE_NULL.
   3. The feature to machine is a region: CANNOT_MACHINE_A_REGION.
   4. The feature to machine is a transitionFeature:
      CANNOT_HANDLE_TRANSITION_FEATURE.
   5. The feature to machine is a replicateFeature:
      CANNOT_HANDLE_REPLICATE_FEATURE.
   6. The feature to machine is a compound_feature that is not a
      countersunkHole or a counterboreHole: CANNOT_HANDLE_COMPOUND_FEATURE.
   7. The feature to machine is of unknown type:
      MANUFACTURING_FEATURE_TYPE_MUST_BE_DEFINED_TYPE.
   8. The machine_functions of the workingstep is not a
      millingMachineFunctions:
      MACHINE_FUNCTIONS_MUST_BE_MILLING_MACHINE_FUNCTIONS.
   9. The technology of the workingstep is not millingTechnology:
      TECHNOLOGY_MUST_BE_MILLING_TECHNOLOGY.
  10. After being located in setup coordinates, the Z axis of the
      feature is not parallel to the Z axis of the machine:
      FEATURE_Z_AXIS_MUST_BE_PARALLEL_TO_MACHINE_Z_AXIS.
  11. handle_tool returns an error code.
  12. find_location returns an error code.
  13. find_if_vertical returns an error code.
  14. cut_feature returns an error code.
  15. op_counter_sinking returns an error code.
  16. op_counter_boring returns an error code.
  17. The feature is not a machiningFeature, a countersunkHole, or
      a counterboreHole: CANNOT_PERFORM_OPERATION_ON_FEATURE.
  18. set_security_z_now returns an error code.

Side Effects: See below

Called By: execute_workingstep

the_machining is known not to be NULL when this is called, so that
is not checked here.

This function (hence this interpreter) does not deal with itsEffect
of the_machining.

This interpreter is using the setup coordinate system at all times.
This function calculates the position of the feature in the setup
coordinate system and stores it in _world.feature_place. See
discussion of coordinate systems at the beginning of this file. The
axis of the native coordinate system of the placed feature is required
to be parallel to the Z axis of the setup.  That is checked here.

C++ data for machiningWorkingstep
---------------------------------
char * itsId;                            (executable)
elementarySurface * itsSecplane;         (workingstep)
manufacturingFeature * itsFeature;       (machiningWorkingstep)
machiningOperation * itsOperation;
inProcessGeometry * itsEffect;     [opt]

*/

static int execute_machining(          /* ARGUMENTS                       */
 machiningWorkingstep * the_machining) /* machiningWorkingstep to execute */
{
  static char name[] = "execute_machining";
  manufacturingFeature * the_feature;
  two5DmanufacturingFeature * the_feat;
  machiningOperation * the_operation;
  millingMachineFunctions * funcs;
  millingTechnology * tech;
  int vertical;

  the_operation = the_machining->get_itsOperation();
  the_feature = the_machining->get_itsFeature();
  
  CHK((the_operation == 0), OPERATION_MUST_NOT_BE_NULL);
  if (the_operation->get_itsMachineFunctions()->isA(millingMachineFunctions_E))
    funcs = dynamic_cast<millingMachineFunctions *>
      (the_operation->get_itsMachineFunctions());
  else
    CHK(1, MACHINE_FUNCTIONS_MUST_BE_MILLING_MACHINE_FUNCTIONS);
  if (the_operation->get_itsTechnology()->isA(millingTechnology_E))
    tech = dynamic_cast<millingTechnology *>
      (the_operation->get_itsTechnology());
  else
    CHK(1, TECHNOLOGY_MUST_BE_MILLING_TECHNOLOGY);
  CHK((the_feature == 0), FEATURE_MUST_NOT_BE_NULL);
  if (the_feature->isA(two5DmanufacturingFeature_E))
    {
      the_feat = dynamic_cast<two5DmanufacturingFeature *>(the_feature);
      if (the_feat->isA(machiningFeature_E));
      else if (the_feat->isA(replicateFeature_E))
	CHK(1, CANNOT_HANDLE_REPLICATE_FEATURE);
      else if (the_feat->isA(compoundFeature_E))
	{
	  if (the_feat->isA(countersunkHole_E) &&
	      the_operation->isA(counterSinking_E));
	  else if (the_feat->isA(counterboreHole_E) &&
		   the_operation->isA(boring_E));
	  else
	    CHK(1, CANNOT_HANDLE_COMPOUND_FEATURE);
	}
      else
	CHK(1, MANUFACTURING_FEATURE_TYPE_MUST_BE_DEFINED_TYPE);
    }
  else if (the_feature->isA(region_E))
    CHK(1, CANNOT_MACHINE_A_REGION);
  else if (the_feature->isA(transitionFeature_E))
    CHK(1, CANNOT_HANDLE_TRANSITION_FEATURE);
  else
    CHK(1, MANUFACTURING_FEATURE_TYPE_MUST_BE_DEFINED_TYPE);
  
  IFF(handle_tool(the_operation->get_itsTool(), 0));
  IFF(find_location(_world.workpiece_place, the_feat->get_featurePlacement(),
		    &(_world.feature_place)));
  IFF(find_if_vertical(_world.feature_place.get_axis(), &vertical));
  CHK((NOT(vertical)), FEATURE_Z_AXIS_MUST_BE_PARALLEL_TO_MACHINE_Z_AXIS);
  IFF(set_security_z_now(the_machining->get_itsSecplane()));
  if ((the_feat->isA(machiningFeature_E)) ||
      (the_operation->isA(freeformOperation_E)))
    IFF(cut_feature(dynamic_cast<machiningFeature *>(the_feat), 
		    funcs, tech, the_operation));
  else if (the_feat->isA(countersunkHole_E))
    IFF(op_counter_sinking(dynamic_cast<countersunkHole *>(the_feat),
			   funcs, tech,
			   dynamic_cast<counterSinking *>(the_operation)));
  else if (the_feat->isA(counterboreHole_E))
    IFF(op_counter_boring(dynamic_cast<counterboreHole *>(the_feat),
			  funcs, tech,
			  dynamic_cast<boring *>(the_operation)));
  else
    CHK(1, CANNOT_PERFORM_OPERATION_ON_FEATURE);
  _world.security_z_now = _world.security_z_setup;
  return ISO14649_OK;
}

/****************************************************************************/

/* execute_nc_function

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The ncFunction is a setMark: CANNOT_HANDLE_SET_MARK.
   2. The ncFunction is a waitForMark: CANNOT_HANDLE_WAIT_FOR_MARK.
   3. The ncFunction is an indexPallet: CANNOT_HANDLE_INDEX_PALLET.
   4. The ncFunction is an indexTable: CANNOT_HANDLE_INDEX_TABLE.
   5. handle_tool returns an error code.
   6. handle_unload_tool returns an error code.

Side Effects: See below

Called By: execute_executable

This executes the ncFunction that is the_nc_function.  If the
ncFunction is loadTool or unloadTool and either of those calls
change_tool, the XY-position at the end of the operation is
unknown. For those two ncFunctions, this will cause change_tool (if
it is called) to set _world.action_flag to ISO14649_SET_POSITION. Then
when the next iso14649_read starts up, it will get and record the
position.  The Z position after a tool change is always fully
retracted.

*/

static int execute_nc_function( /* ARGUMENTS                 */
 ncFunction * the_nc_function)  /* the ncFunction to execute */
{
  static char name[] = "execute_nc_function";

  if (the_nc_function->isA(loadTool_E))
    IFF(handle_tool((dynamic_cast<loadTool *>(the_nc_function))->
		    get_itsTool(), 1));
  else if (the_nc_function->isA(unloadTool_E))
    IFF(handle_unload_tool((dynamic_cast<unloadTool *>(the_nc_function))->
			   get_itsTool()));
  else if (the_nc_function->isA(displayMessage_E))
    MESSAGE((dynamic_cast<displayMessage *>(the_nc_function))->get_itsText());
  else if (the_nc_function->isA(optionalStop_E))
    OPTIONAL_PROGRAM_STOP();
  else if (the_nc_function->isA(programStop_E))
    PROGRAM_STOP();
  else if (the_nc_function->isA(setMark_E))
    CHK(1, CANNOT_HANDLE_SET_MARK);
  else if (the_nc_function->isA(waitForMark_E))
    CHK(1, CANNOT_HANDLE_WAIT_FOR_MARK);
  else if (the_nc_function->isA(exchangePallet_E))
    PALLET_SHUTTLE();
  else if (the_nc_function->isA(indexPallet_E))
    CHK(1, CANNOT_HANDLE_INDEX_PALLET);
  else if (the_nc_function->isA(indexTable_E))
    CHK(1, CANNOT_HANDLE_INDEX_TABLE);
  return ISO14649_OK;
}

/****************************************************************************/

/* execute_rapid

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. A toolDirection is given: CANNOT_HANDLE_TOOL_DIRECTION.
   2. A toolpath is given, but the toolpath list is NULL:
      TOOLPATH_LIST_MUST_NOT_BE_NULL.
   3. A toolpath list is given, but it is empty:
      TOOLPATH_LIST_MUST_NOT_BE_EMPTY.
   4. execute_rapid_setup returns an error code.
   5. No toolpath is given and the security plane is not a plane:
      SECPLANE_MUST_BE_A_PLANE.
   6. The rapidMovement does not have a toolpath:
      CANNOT_HANDLE_RAPID_MOVEMENT_WITHOUT_TOOLPATH

Side Effects: See below

Called By: execute_workingstep

rapidMovement is a subtype of both workingstep and operation

C++ data for rapidMovement
--------------------------

char * itsId;                           (executable)
elementarySurface * its_secplane;       (workingstep)
toolpathList * itsToolpath;       [opt] (operation)
toolDirection * itsToolDirection; [opt]  

If no toolpath list is given, all this does is set the
_world.rapid_secplane, which will be used by the next function that
moves the tool. If a toolpath list is given, this sets
_world.rapid_secplane to 0 and follows the given path.

*/

static int execute_rapid( /* ARGUMENTS                   */
 rapidMovement * rapid)   /* the rapid motion to execute */
{
  static char name[] = "execute_rapid";
  std::list<toolpath *> * the_path;
  std::list<toolpath *>::iterator iter;

  CHK(rapid->get_itsToolDirection(), CANNOT_HANDLE_TOOL_DIRECTION);
  if (rapid->get_itsToolpath())
    {
      _world.rapid_secplane = 0;
      CHK((rapid->get_itsToolpath()->get_itsList() == 0),
	  TOOLPATH_LIST_MUST_NOT_BE_NULL);
      the_path = rapid->get_itsToolpath()->get_itsList()->get_theList();
      CHK((the_path->size() == 0), TOOLPATH_LIST_MUST_NOT_BE_EMPTY);
      IFF(execute_rapid_setup(the_path));
    }
  else
    {
      CHK((NOT(rapid->get_itsSecplane()->isA(plane_E))),
	  SECPLANE_MUST_BE_A_PLANE);
      _world.rapid_secplane =
	dynamic_cast<plane *>(rapid->get_itsSecplane());
      CHK(1, CANNOT_HANDLE_RAPID_MOVEMENT_WITHOUT_TOOLPATH);
    }
  return ISO14649_OK;
}

/****************************************************************************/

/* execute_rapid_setup

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. A segment of the toolpath has non-NULL itsSpeed:
      CANNOT_HANDLE_SPEED_IN_TOOLPATH.
   2. The itsMachineFunctions of a segment is not a millingMachineFunctions:
      MACHINE_FUNCTIONS_MUST_BE_MILLING_MACHINE_FUNCTIONS.
   3. handle_machine_functions returns an error code.
   4. the itsTechnology of a segment is not a millingTechnology:
      TECHNOLOGY_MUST_BE_MILLING_TECHNOLOGY.
   5. handle_technology_rapid returns an error code.
   6. op_trajectory_rapid returns an error code.
   7. A segment of the toolpath is neither a cutterLocationTrajectory not
      a feedstop:  CAN_HANDLE_ONLY_FEEDSTOP_AND_CUTTER_LOCATION_TRAJECTORY.
      
Side Effects: See below

Called By: execute_rapid

This executes a rapidMovement that has an explicit toolpath. The coordinate
system of the toolpath is assumed to be the setup coordinate system, since
no feature is associated with a rapidMovement.

RapidMovement has the strange property that the rapidMovement itself
does not have any technology or machineFunctions attached to it, but
every cutterLocationTrajectory in itsToolpaths may have its own
technology and machineFunctions. It may be desired to stop the spindle
during a rapid move. This could be done by putting an oriented spindle
stop in the machine functions of the previous workingstep, but except
in backboring, there is usually no reason to orient the tool during a
rapid move. The only other apparent way to stop the tool during a
rapid move is to put a millingTechnology with zero spindle speed into
the first segment of the rapid motion. This function processes the
technology so that that can be done.

*/

static int execute_rapid_setup(     /* ARGUMENTS               */
 std::list<toolpath *> * toolpaths) /* path to follow rapidly  */
{
  static char name[] = "execute_rapid_setup";
  technology * tech;                      // technology from segment
  millingTechnology * millingTech;        // milling technology from segment
  machineFunctions * funcs;               // machine functions from segment
  millingMachineFunctions * millingFuncs; // milling machine functions from seg
  std::list<toolpath *>::iterator iter;
  toolpath * segment;
  cartesianPoint * join;

  join = 0;
  for (iter = toolpaths->begin(); iter != toolpaths->end(); ++iter)
    {
      segment = *iter;
      tech = segment->get_itsTechnology();
      funcs = segment->get_itsMachineFunctions();
      CHK(segment->get_itsSpeed(), CANNOT_HANDLE_SPEED_IN_TOOLPATH);
      funcs = segment->get_itsMachineFunctions();
      if (funcs)
	{
	  CHK((NOT(funcs->isA(millingMachineFunctions_E))),
	      MACHINE_FUNCTIONS_MUST_BE_MILLING_MACHINE_FUNCTIONS);
	  millingFuncs = dynamic_cast<millingMachineFunctions *>(funcs);
	  IFF(handle_machine_functions(millingFuncs));
	}
      if (tech)
	{
	  CHK((NOT(tech->isA(millingTechnology_E))),
	      TECHNOLOGY_MUST_BE_MILLING_TECHNOLOGY);
	  millingTech = dynamic_cast<millingTechnology *>(tech);
	  IFF(handle_technology_rapid(millingTech));
	}
      if (segment->isA(cutterLocationTrajectory_E))
	{
	  IFF(op_trajectory_rapid
	      (dynamic_cast<cutterLocationTrajectory *>(segment), &join));
	}
      else if (segment->isA(feedstop_E))
	{
	  DWELL((dynamic_cast<feedstop *>(segment))->get_dwell());
	}
      else
	CHK(1, CAN_HANDLE_ONLY_FEEDSTOP_AND_CUTTER_LOCATION_TRAJECTORY);
    }

  return ISO14649_OK;
}

/****************************************************************************/

/* execute_workingstep

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. execute_machining returns an error code.
   2. execute_rapid returns an error code.
   3. The workingstep is a touchProbing: CANNOT_EXECUTE_TOUCH_PROBING.
   4. The workingstep type is bad: WORKINGSTEP_TYPE_MUST_BE_DEFINED_TYPE.

Side Effects: See below

Called By: execute_executable

This executes the workingstep that is the_workingstep. It works by calling
either execute_machining or execute_rapid.

the_workingstep is known not to be NULL when this is called, so that
is not checked here.

*/

static int execute_workingstep( /* ARGUMENTS                  */
 workingstep * the_workingstep) /* the workingstep to execute */
{
  static char name[] = "execute_workingstep";

  if (the_workingstep->isA(machiningWorkingstep_E))
    IFF(execute_machining
	(dynamic_cast<machiningWorkingstep *>(the_workingstep)));
  else if (the_workingstep->isA(rapidMovement_E))
    IFF(execute_rapid(dynamic_cast<rapidMovement *>(the_workingstep)));
  else if (the_workingstep->isA(touchProbing_E))
    CHK(1, CANNOT_EXECUTE_TOUCH_PROBING);
  else
    CHK(1, WORKINGSTEP_TYPE_MUST_BE_DEFINED_TYPE);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_drill_tip_length

Returned Value: int (ISO14649_OK)

Side Effects: tip_length is set.

Called By:
  op_drilling
  op_multistep_drilling

This is not checking data, so check_tool_drill, which performs the checks
required to prevent this function from crashing, must be called first
with the same tool as its first argument.

See Figure 2 in section 4.3.1 of ISO 14649 Part 111. The letter variables
in this function correspond to the figure.

The machiningTool must be a cuttingTool. It therefore has a toolBody
(itsToolBody). The toolBody must be a drill.  The drill has a
dimension (millingToolDimension). The toolDimension has a (diameter)
and an angle (toolTopAngle). The diameter is the diameter at the end
of the cylindrical or upper conical part of the drill before any
edgeRadius is applied. If there is an edgeRadius, the rounding caused
by the edge radius will make the upper part of the drill end sooner
than otherwise.

The tip_lengths below are all parallel to the drill axis.

let:
h1 = tip length before edge rounding
h2 = tip length from edge rounding
R = drillRadius
r = edgeRadius
a = toolTopAngle
b = toolCircumferenceAngle
arm = the distance from where the top part of the drill would end
      without rounding to where it ends after rounding

The equations are:
tip_length = (h1 + h2)
h1 = (R * tan(a))
h2 = (arm * cos(b))
arm = (r / tan((90 + a + b) / 2))

Note that, assuming the toroidal rounding caused by the edgeRadius is
tangent to the two surfaces it rounds, the edgeCenterVertical and
edgeCenterHorizontal are redundant information that may be incorrect.
We are ignoring those attributes.

*/

static int find_drill_tip_length( /* ARGUMENTS               */
 machiningTool * the_tool,        /* the (should be) drill   */
 double * tip_length)             /* length of tip, set here */
{
  toolBody * body;
  millingToolDimension * dimension;
  double arm;
  double h1;
  double h2;
  double a;
  double b;
  double R;
  double r;
  double c;   /* conversion factor to get radians from degrees */

  c = (M_PI / 180.0);
  body = (dynamic_cast<cuttingTool *>(the_tool))->get_itsToolBody();
  dimension = (dynamic_cast<drill *>(body))->get_dimension();
  a = dimension->get_toolTopAngle()->get_val();
  R = (dimension->get_diameter() / 2.0);
  h1 = (R * tan(a * c));
  if ((dimension->get_edgeRadius() == 0) OR
      (dimension->get_edgeRadius()->get_val() == 0.0))
    *tip_length = h1;
  else
    {
      r = dimension->get_edgeRadius()->get_val();
      b = (dimension->get_toolCircumferenceAngle() ?
	   dimension->get_toolCircumferenceAngle()->get_val() : 0.0);
      arm = (r / tan(((90 + a + b) / 2.0) * c));
      h2 = (arm * cos(b * c));
      *tip_length = (h1 + h2);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* find_cutting_depths

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_horizontal_plane returns an error code.
   2. Both cuttingDepth and overcut have been given:
      MUST_NOT_HAVE_BOTH_CUTTING_DEPTH_AND_OVERCUT.
   3. An overcut length has been given that is not positive:
      OVERCUT_MUST_BE_POSITIVE.
   4. The given or calculated cutting depth is not positive:
      CUTTING_DEPTH_MUST_BE_POSITIVE.
   5. The depth of the start is not less than the cuttingDepth:
      START_DEPTH_MUST_BE_LESS_THAN_CUTTING_DEPTH.
   6. The depth of the end is not less than the cuttingDepth:
      END_DEPTH_MUST_BE_LESS_THAN_CUTTING_DEPTH.
   7. The depth of the end is not greater than the depth of the start:
      END_DEPTH_MUST_BE_GREATER_THAN_START_DEPTH.
   8. The total amount to cut is more than the flute_length:
      HOLE_MUST_NOT_BE_DEEPER_THAN_FLUTE_LENGTH.

Side Effects: See below

Called By:
   op_drilling
   op_multistep_drilling
   op_reaming

This sets depth, depth1, and depth2.

For the canonical machining commands, the controlled point is at the tip of
the tool. A reamer is required by check_tool_ream to have a flat end, so
the flutes extend to the end of the tool. For a drill, however, the three
depths in the data all refer to the location of the plane where the conical
tip of the drill is joined to the end of the cylindrical part of the
drill. The depth, depth1, and depth2 arguments set here are the values to
put into canonical commands for cutting.

depth is the Z coordinate of the tool tip at which to stop going deeper and
is determined as follows.

1. cutting_depth is checked or set

  If there is a cutting_depth:
  a. There must not be an overcut.
  b. The cutting_depth must be positive.

  Otherwise, if there is an overcut:
  a. The overcut must be positive.
  b. The cutting_depth is set to [the hole depth (the negative of the
     Z-coordinate of a point on depth plane) plus the overcut].

  Otherwise, the cutting_depth is set to the hole depth (Z-coordinate of
  point on depth plane).

2. depth is set to [the Z coordinate of the top of the feature minus
   [the cutting_depth plus the length of the tool tip]]. 

If there is a depthOfStart and there is [reducedCutAtStart and/or
reducedFeedAtStart], depth1 is set. It must be positive above depth.

If there is a depthOfEnd and there is [reducedCutAtEnd and/or
reducedFeedAtEnd], depth2 is set. If must be above depth and, if
depth1 is set, below depth1.

The depth_plane must exist and be a plane. The placement of the plane is
given in terms of the placement of the feature. It is required here
(but not in the spec) that the axis of the placement of the plane be
vertical. Note that the Z coordinate of the location should be negative.

*/

static int find_cutting_depths(    /* ARGUMENTS                        */
 double * depth,                   /* Z coord of hole bottom set here  */
 double * depth1,                  /* Z coord of end of start set here */
 double * depth2,                  /* Z coord of start of end set here */
 double flute_length,              /* flute length of tool             */
 double tip_length,                /* length of tool tip, may be 0     */
 elementarySurface * depth_plane,  /* plane that is depth of hole      */
 real * overcut,                   /* amount to overcut, may be NULL   */
 real * cutting_depth,             /* depth to cut to, may be NULL     */
 drillingTypeStrategy * strat)     /* cutting strategy, may be NULL    */
{
  static char name[] = "find_cutting_depths";
  double cutting_val;
  double top;
  double start;
  double end;

  *depth1 = ISO14649_BAD_REAL;
  *depth2 = ISO14649_BAD_REAL;
  IFF(check_horizontal_plane(depth_plane));
  top = getPtZ(&(_world.feature_place));
  if (cutting_depth)
    {
      CHK((overcut),
	  MUST_NOT_HAVE_BOTH_CUTTING_DEPTH_AND_OVERCUT);
    }
  else if (overcut)
    {
      CHK((overcut <= 0), OVERCUT_MUST_BE_POSITIVE);
      cutting_val =
	(overcut->get_val() - getPtZ(depth_plane->get_position()));
    }
  else
    {
      cutting_val = (0 - getPtZ(depth_plane->get_position()));
    }
  CHK((cutting_val <= 0), CUTTING_DEPTH_MUST_BE_POSITIVE);
  CHK(((cutting_val + tip_length) > flute_length),
      HOLE_MUST_NOT_BE_DEEPER_THAN_FLUTE_LENGTH);
  *depth = (top - (cutting_val + tip_length));
  if (strat)
    {
      if (strat->get_depthOfStart())
	{
	  start = strat->get_depthOfStart()->get_val();
	  CHK((start >= cutting_val),
	      START_DEPTH_MUST_BE_LESS_THAN_CUTTING_DEPTH);
	  *depth1 = (top - (start + tip_length));
	}
      if (strat->get_depthOfEnd())
	{
	  end = strat->get_depthOfEnd()->get_val();
	  CHK((end >= cutting_val),
	      END_DEPTH_MUST_BE_LESS_THAN_CUTTING_DEPTH);
	  CHK((end <= start), END_DEPTH_MUST_BE_GREATER_THAN_START_DEPTH);
	  *depth2 = (top - (end + tip_length));
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* find_if_vertical

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. axis is NULL: DIRECTION_MUST_NOT_BE_NULL.

Side Effects: If the X and Y components of the axis are almost 0 and
the Z component is almost 1, vertical is set to 1. Otherwise,
vertical is set to 0. "Almost" means within ISO14649_TINY.

Called By:
  check_counterbore_hole
  check_countersunk_hole
  check_horizontal_plane
  execute_machining
  follow_circle_forward
  follow_helix_forward
  transform_code

*/

static int find_if_vertical( /* ARGUMENTS                            */
 direction * axis,           /* axis that should be vertical         */
 int * vertical)             /* 0=not vertical, 1=vertical, set here */
{
  static char name[] = "find_if_vertical";

  CHK((axis == 0), DIRECTION_MUST_NOT_BE_NULL);
  if ((fabs(getDirX(axis)) > ISO14649_TINY) OR
      (fabs(getDirY(axis)) > ISO14649_TINY) OR
      (fabs(getDirZ(axis) - 1.0)  > ISO14649_TINY))
    *vertical = 0;
  else
    *vertical = 1;
  return ISO14649_OK;
}

/***********************************************************************/

/* find_instances

Returned Value: none

Called By: check_and_store

This looks through one list of pointers to instances (source), and addss
the ones with the given instanceType to another list of instances (fillMe).
The fillMe list is normally empty when this is called, but that is not
required.

*/

static void find_instances(       /* ARGUMENTS                        */
 iso14649ClassEName instanceType, /* the type of instance to look for */
 std::list<instance *> * fillMe,  /* the list to fill                 */
 std::list<instance *> * source)  /* the list to get instances from   */
{
  std::list<instance *>::iterator iter;
  for (iter = source->begin();
       iter != source->end();
       iter++)
    {
      if ((*iter)->isA(instanceType))
	fillMe->push_back(*iter);
    }
} 

/***********************************************************************/

/* find_location

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_placement returns an error code when applied to place1, place2,
      or place3.

Side Effects: See below

Called By:
  execute_machining
  op_counter_boring
  op_counter_sinking

Given place1 (an axis placement for coordinate system B in terms of
coordinate system A) and place2 (an axis placement for coordinate
system C in terms of coordinate system B), this stores in place3 the
correct values for the placement of coordinate system C in terms of
coordinate system A.

It is assumed that all three coordinate systems are fully constructed
before this function is called.

The direction ratios of the y-axis of place1 are computed by taking
the cross product of the z-axis and the x-axis.

place1 and place3 may be the same, since all data is extracted from
place1 before any data is set in place3. Similarly, place2 and place3
may be the same.

It might be useful to check for more things being NULL.

*/

static int find_location(     /* ARGUMENTS                     */
  axis2placement3d * place1,  /* placement of B in A           */
  axis2placement3d * place2,  /* placement of C in B           */
  axis2placement3d * place3)  /* placement of C in A, set here */
{
  static char name[] = "find_location";

  double tx;
  double ty;
  double tz;
  double ix;
  double iy;
  double iz;
  double kx;
  double ky;
  double kz;
  double jx;
  double jy;
  double jz;
  double ex;
  double wy;
  double ze;
  std::list<real *> * coords;

  IFF(check_placement(place1));
  IFF(check_placement(place2));
  IFF(check_placement(place3));
  tx = getPtX(place1);
  ty = getPtY(place1);
  tz = getPtZ(place1);
  ix = getRefX(place1);
  iy = getRefY(place1);
  iz = getRefZ(place1);
  kx = getAxisX(place1);
  ky = getAxisY(place1);
  kz = getAxisZ(place1);
  jx = ((ky * iz) - (kz * iy));
  jy = ((kz * ix) - (kx * iz));
  jz = ((kx * iy) - (ky * ix));

  ex = getPtX(place2);
  wy = getPtY(place2);
  ze = getPtZ(place2);
  coords = place3->get_location()->get_coordinates()->get_theList();
  put1(coords, (tx + (ex * ix) + (wy * jx) + (ze * kx)));
  put2(coords, (ty + (ex * iy) + (wy * jy) + (ze * ky)));
  put3(coords, (tz + (ex * iz) + (wy * jz) + (ze * kz)));

  ex = getAxisX(place2);
  wy = getAxisY(place2);
  ze = getAxisZ(place2);  
  coords = place3->get_axis()->get_directionRatios()->get_theList();
  put1(coords, ((ex * ix) + (wy * jx) + (ze * kx)));
  put2(coords, ((ex * iy) + (wy * jy) + (ze * ky)));
  put3(coords, ((ex * iz) + (wy * jz) + (ze * kz)));
      
  ex = getRefX(place2);
  wy = getRefY(place2);
  ze = getRefZ(place2);
  coords = place3->get_refDirection()->get_directionRatios()->get_theList();
  put1(coords, ((ex * ix) + (wy * jx) + (ze * kx)));
  put2(coords, ((ex * iy) + (wy * jy) + (ze * ky)));
  put3(coords, ((ex * iz) + (wy * jz) + (ze * kz)));

  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. find_pocket_plunge_start_toolaxis returns an error code.
   2. find_pocket_plunge_start_ramp returns an error code.
   3. find_pocket_plunge_start_zigzag returns an error code.
   4. find_pocket_plunge_start_helix returns an error code.
   5. The plunge strategy is not one of the four subtypes:
      PLUNGE_STRATEGY_TYPE_MUST_BE_DEFINED_TYPE.

Side Effects: See below

Called By:
  cut_straight
  mill_rectangular_pocket_regular

This finds the start point for rectangular pockets (except plunge
pockets). The pocket has its centerline on the X-axis and has its
middle at the origin.

In all cases, the end of the starting motion should be
at X = (length - width)/-2.0    Y = 0.0

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

For a plungeZigzag, aux is set to the X-offset from the start
point to the second point. The third point can be found from the
length of the zigzag.

For a plungeHelix, aux is set to the number of turns in the helix.

The value of aux is not set by plungeToolaxis, or plungeRamp.

*/

static int find_pocket_plunge_start( /* ARGUMENTS                           */
 double length,                      /* length of tool path                 */
 double width,                       /* width of tool path                  */
 double plunge_depth,                /* depth of plunge                     */
 plungeStrategy * enter,             /* entry strategy to use               */
 double * start_x,                   /* X coord of start, set here          */
 double * start_y,                   /* Y coord of start, set here          */
 double * aux)                       /* aux value maybe set here, see above */
{
  static char name[] = "find_pocket_plunge_start";
  double end_x;

  end_x = ((length - width) / -2.0);
  if (enter->isA(plungeToolaxis_E))
    IFF(find_pocket_plunge_start_toolaxis(start_x, start_y, end_x));
  else if(enter->isA(plungeRamp_E))
    IFF(find_pocket_plunge_start_ramp(length, width, plunge_depth,
				      dynamic_cast<plungeRamp *>(enter),
				      start_x, start_y, end_x));
  else if (enter->isA(plungeZigzag_E))
    IFF(find_pocket_plunge_start_zigzag(length, width, plunge_depth,
					dynamic_cast<plungeZigzag *>(enter),
					start_x, start_y, aux, end_x));
  else if (enter->isA(plungeHelix_E))
    IFF(find_pocket_plunge_start_helix(width, plunge_depth,
				       dynamic_cast<plungeHelix *>(enter),
				       start_x, start_y, aux, end_x));
  else
    CHK(1, PLUNGE_STRATEGY_TYPE_MUST_BE_DEFINED_TYPE);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start_helix

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the helix radius is greater than half the tool path width:
      HELIX_MUST_FIT_IN_POCKET.

Side Effects: See below

Called By: find_pocket_plunge_start

The action of this function is coordinated with the action of
enter_pocket_pass_helix, which uses the start point and number of turns
found here.

The helix goes clockwise so that conventional cutting is done with a
right-handed tool.

The helix ends at (end_x, -radius), i.e. at 6 o'clock. This is so
that the helix may be followed by a clockwise semicircle of half the
radius of the helix with its center at (end_x, -radius/2), so that the
tool ends up at (end_x, 0) traveling in the +X direction. This
function calculates where the helix has to start to end in the right
place.

*/

static int find_pocket_plunge_start_helix(/* ARGUMENTS                       */
 double width,                            /* width of tool path              */
 double plunge_depth,                     /* depth of plunge                 */
 plungeHelix * hely,                      /* helix entry strategy            */
 double * start_x,                        /* X coord of start, set here      */
 double * start_y,                        /* Y coord of start, set here      */
 double * turns,                          /* turns for write_arc, set here   */
 double end_x)                            /* X coord of -X end of centerline */
{
  static char name[] = "find_pocket_plunge_start_helix";
  double turn_depth;
  double radius;
  int whole_turns;
  double fraction;      // fraction of a turn past whole number of turns

  radius = hely->get_radius();
  CHK((radius > (width / 2)), HELIX_MUST_FIT_IN_POCKET);
  turn_depth = ((2 * M_PI * radius) * tand(hely->get_angle()));
  whole_turns = (int) (plunge_depth / turn_depth);
  fraction = ((plunge_depth - (whole_turns * turn_depth)) / turn_depth);
  *start_x = (end_x + (radius * cos((2 * M_PI * fraction) - (M_PI / 2))));
  *start_y = (radius * sin((2 * M_PI * fraction) - (M_PI / 2)));
  *turns = (double)(-whole_turns - 1);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start_ramp

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The ramp width is greater than the length of the pocket:
      RAMP_MUST_FIT_IN_POCKET.

Side Effects: See below

Called By: find_pocket_plunge_start

The action of this function is coordinated with the action of
enter_pocket_pass, which uses the start point found here.

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

If there is room to put the whole ramp along the centerline on the -X
side of the end point, it is placed there so that the XY direction of
the tool does not need to change between the ramp and the first cut.
Otherwise, if there is room to put the whole ramp along the centerline
on the +X side of the end point (and end at the end point), it is
placed there. Otherwise, if there is room for the ramp along the
centerline in the pocket, it starts at the +X area and ends as close
to the end as possible. Otherwise the ramp does not fit along the
centerline and it is an error. We could try fitting the ramp
diagonally across the pocket (since there is the most room in that
direction) but are not doing that.

*/

static int find_pocket_plunge_start_ramp( /* ARGUMENTS                       */
 double length,                           /* length of tool path             */
 double width,                            /* width of tool path              */
 double plunge_depth,                     /* depth of plunge                 */
 plungeRamp * the_ramp,                   /* ramp entry strategy             */
 double * start_x,                        /* X coord of start, set here      */
 double * start_y,                        /* Y coord of start, set here      */
 double end_x)                            /* X coord of -X end of centerline */
{
  static char name[] = "find_pocket_plunge_start_ramp";
  double distance;                        // ramp length

  *start_y = 0.0;
  distance = (plunge_depth / tand(the_ramp->get_angle()));
  if (distance < (width / 2.0))
    *start_x = (end_x - distance);
  else if (distance < (length - (width / 2.0)))
    *start_x = (end_x + distance);
  else if (distance < length)
    *start_x = (length / 2.0);
  else
    CHK(1, RAMP_MUST_FIT_IN_POCKET);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start_toolaxis

Returned Value: int (ISO14649_OK)

Side Effects: See below

Called By: find_pocket_plunge_start

The action of this function is coordinated with the action of
enter_pocket_pass, which uses the start point found here.

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

start_x and start_y are set. The start point is the end point, since
the tool plunges straight down.

*/

static int find_pocket_plunge_start_toolaxis( /* ARGUMENTS                   */
 double * start_x,                        /* X coord of start, set here      */
 double * start_y,                        /* Y coord of start, set here      */
 double end_x)                            /* X coord of -X end of centerline */
{
  *start_y = 0.0;
  *start_x = end_x;
  return ISO14649_OK;
}

/***********************************************************************/

/* find_pocket_plunge_start_zigzag

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The zigzag width is greater than the length of the pocket:
      ZIGZAG_MUST_FIT_IN_POCKET.

Side Effects: See below

Called By: find_pocket_plunge_start

The action of this function is coordinated with the action of
enter_pocket_pass_zigzag, which uses the start point found here.

The length and width arguments here are reduced from the length and width
of the pocket by one tool_diameter.

The zigzag is always placed on the centerline of the pocket as far
towards -X as possible. The final zig is always moving towards +X if
possible (always possible except for a groove pocket). The zigzag is
traced backwards (using the given width and angle) from the bottom up
to find the start point.

Half the width of the tool path is the distance available in the -X
direction from end_x.

offset_x is set to the X offset from the start point to the second
point. The third point can be found from the length of the zigzag.

*/

static int find_pocket_plunge_start_zigzag( /* ARGUMENTS                     */
 double length,                           /* length of tool path             */
 double width,                            /* width of tool path              */
 double plunge_depth,                     /* depth of plunge                 */
 plungeZigzag * ziggy,                    /* zigzag entry strategy           */
 double * start_x,                        /* X coord of start, set here      */
 double * start_y,                        /* Y coord of start, set here      */
 double * offset_x,                       /* X offset start_x to 2nd point   */
 double end_x)                            /* X coord of -X end of centerline */
{
  static char name[] = "find_pocket_plunge_start_zigzag";
  double angle;                           // zigzag angle
  double distance;                        // zigzag length
  double depth;                           // working depth
  double zig_depth;                       // depth increment on one zig

  *start_y = 0.0;
  angle = ziggy->get_angle();
  distance = ziggy->get_width();
  *offset_x = 1;
  depth = plunge_depth;
  if (distance < (width / 2.0))
    {
      zig_depth = (distance * tand(angle));
      for (; depth > (zig_depth + ISO14649_TINY);
	   depth = (depth - zig_depth))
	*offset_x = (NOT(*offset_x));
      *start_x = (*offset_x ? (end_x - (depth / tand(angle))) :
		       ((end_x - distance) + (depth / tand(angle))));
    }
  else if (distance < (length + ISO14649_TINY))
    {
      zig_depth = ((width / 2.0) * tand(angle));
      if (depth < (zig_depth + ISO14649_TINY))
	*start_x = (end_x - (depth / tand(angle)));
      else
	{
	  depth = (depth - zig_depth);
	  zig_depth = (distance * tand(angle));
	  *offset_x = 0;
	  for (; depth > (zig_depth + ISO14649_TINY);
	       depth = (depth - zig_depth))
	    *offset_x = (NOT(*offset_x));
	  *start_x = 
	    (*offset_x ? (((length/-2.0) + distance) - (depth / tand(angle))):
	     ((length / -2.0) + (depth / tand(angle))));
	}
    }
  else
    CHK(1, ZIGZAG_MUST_FIT_IN_POCKET);
  *offset_x = (*offset_x ? (depth / tand(angle)) :
		    -(depth / tand(angle)));
  return ISO14649_OK;
}

/***********************************************************************/

/* find_retract_z

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The retract distance would move the tool tip above the security plane:
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE.

Side Effects: This sets retract_z to default_retract above top_z if
op_retract is NULL and to op_retract above top_z if not.

Called By:
  mill_planar_regular
  mill_rectangular_pocket
  op_center_drilling
  op_counter_boring
  op_counter_sinking
  op_drilling
  op_multistep_drilling
  op_reaming

*/

static int find_retract_z( /* ARGUMENTS                         */
 double top_z,             /* z coord of target point           */
 real * op_retract,        /* retract amount given in operation */
 double default_retract,   /* default retract amount            */
 double * retract_z)       /* retract location, set here        */
{
  static char name[] = "find_retract_z";

  *retract_z = 
    (top_z + (op_retract ? op_retract->get_val() : default_retract));
  CHK((*retract_z > _world.security_z_now),
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
  return ISO14649_OK;
}

/***********************************************************************/

/* find_tool_index

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The id of no tool in the changer matches the id of the_tool:
      TOOL_MUST_BE_IN_TOOLCHANGER.

Side Effects: See below

Called By: change_tool

If the_tool is NULL, this sets *index to 0.

Otherwise, this finds the tool by going through the tool_table in
index order and matching the id of the_tool with the id of the tool in
the tool table at the given index. It sets *index the first time the
two match. It does not check that there are not two or more tools with
the same id.

Tool index numbers start with 1.

*/

static int find_tool_index( /* ARGUMENTS                             */
 machiningTool * the_tool,  /* the tool to find in the tool table    */
 int * index)               /* index of tool in tool table, set here */
{
  static char name[] = "find_tool_index";
  
  if (the_tool == 0)
    *index = 0;
  else
    {
      for (*index = 1; *index <= _world.tool_max; (*index)++)
	if (strcmp(the_tool->get_itsId(), _world.tool_table[*index].id) == 0)
	  break;
      CHK((*index > _world.tool_max), TOOL_MUST_BE_IN_TOOLCHANGER);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* finish_mill_both_closed_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The boundary of the pocket is NULL: POCKET_BOUNDARY_MUST_NOT_BE_NULL.
   2. The boundary of the pocket is not a rectangularClosedProfile:
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE.
   3. check_rectangular_pocket returns an error code.
   4. check_rectangular_pocket_strategies returns an error code.
   5. mill_rectangular_pocket returns an error code.
   6. transform_code returns an error code.
   7. run_code returns an error code.
   8. start_cut returns an error code.
   9. The final retract goes above the security plane:
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE.

Side Effects: See below

Called By: op_finish_milling_both


C++ data for bottomAndSideFinishMilling
---------------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions; 
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract;             [opt]
two5DmillingStrategy *    itsMachiningStrategy;[opt] (two5DMillingOperation)
real *                    axialCuttingDepth;   [opt] (bottomAndSideMilling)
real *                    radialCuttingDepth;  [opt]
real *                    allowanceSide;       [opt]
real *                    allowanceBottom;     [opt]
<no attributes>                                     (bottomAndSideFinishMilling)

itsToolpath is used only if the operation is a freeformOperation; it is not
   used here.
itsToolDirection (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are twoAxes and threeAxes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retractPlane is the Z-coordinate of the retract plane in the coordinate
   system of the feature, which is the same as the distance between the
   top of the feature and the point to which to retract.
startPoint is ignored. The spec (Part 10, sec 4.7.2) allows this.
itsTool is handled before this function is called.
technology is handled before this function is called. This results
   in _world.feed_rate being set.
itsMachineFunctions is handled before this function is called.
overcutLength must not be used for pockets (Part 11, sec 4.2.3).

C++ data for closedPocket
-------------------------
char *                        itsId;                 (manufacturingFeature)
workpiece *                   itsWorkpiece;
parenMachiningOperationList * itsOperations;
axis2placement3d *            featurePlacement;      (two5DmanufacturingFeature)
elementarySurface *           depth;                 (machiningFeature)
parenBossList *               itsBoss;               (pocket)
real *                        slope;            [opt]
pocketBottomCondition *       bottomCondition;
tolerancedLengthMeasure *     planarRadius;     [opt]
tolerancedLengthMeasure *     orthogonalRadius; [opt]
closedProfile *               featureBoundary;       (closedPocket)

C++ data for rectangularClosedProfile
-------------------------------------
axis2placement3d *        placement;     [opt] (profile)
<no attributes>                                (closedProfile)
tolerancedLengthMeasure * profileWidth;        (rectangularClosedProfile)
tolerancedLengthMeasure * profileLength;

This requires the pocket to have a rectangularClosedProfile. It would
be fairly easy to add circularClosedProfile.

The code is generated initially in feature coordinates. Then it is
transformed into setup coordinates.

Each line of code consists of seven doubles. See the run_code function
for what they mean.

The first line of code serves only to mark the point above which (by one
retract distance) the tool should be moved by the start_cut function.

Local variables pocket_length, pocket_width, pocket_depth are set in
check_rectangular_pocket, which has to deal with them anyway.

check_rectangular_pocket_strategies may insert milling strategies in
the_finish. After code is generated here, these strategies are removed
from the_finish (since the_finish may be used elsewhere) and deleted.

*/

static int finish_mill_both_closed_pocket( /* ARGUMENTS                */
 closedPocket * the_pocket,                /* pocket to finish mill    */
 bottomAndSideFinishMilling * the_finish,  /* finish milling operation */
 endmill * the_endmill)                    /* tool to use              */
{
  static char name[] = "finish_mill_both_closed_pocket";
  double code[ISO14649_CODE_SIZE][7];
  int lines;           // number of lines of code
  approachRetractStrategy * enter_strategy;
  approachRetractStrategy * leave_strategy;
  two5DmillingStrategy * inside_strategy;
  double pocket_length;
  double pocket_width;
  double pocket_depth;
  double pocket_radius;
  double stepover;

  lines = 0;
  enter_strategy = 0;
  leave_strategy = 0;
  inside_strategy = 0;
  CHK((the_pocket->get_featureBoundary() == 0),
      POCKET_BOUNDARY_MUST_NOT_BE_NULL);
  CHK((NOT(the_pocket->get_featureBoundary()->isA(rectangularClosedProfile_E))),
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE);
  IFF(check_rectangular_pocket(the_pocket, &pocket_length, &pocket_width,
			       &pocket_depth, &pocket_radius));
  IFF(check_rectangular_pocket_strategies
      (pocket_length, pocket_width, pocket_depth, pocket_radius, the_finish,
       the_endmill, &stepover, &enter_strategy, &leave_strategy,
       &inside_strategy, 1));
  IFF(mill_rectangular_pocket
      (pocket_length, pocket_width, pocket_depth, pocket_radius, stepover,
       the_endmill->get_dimension()->get_diameter(), the_finish, code, &lines));
  IFF(transform_code(code, lines, &(_world.feature_place)));
  CHK((code[0][3] > _world.security_z_now),
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
  IFF(start_cut(code[0][1], code[0][2], code[0][3]));
  IFF(run_code((code + 1), (lines - 1)));
  if (enter_strategy)
    {
      delete enter_strategy;
      the_finish->set_approach(0);
    }
  if (leave_strategy)
    {
      delete leave_strategy;
      the_finish->set_retract(0);
    }
  if (inside_strategy)
    {
      delete inside_strategy;
      the_finish->set_itsMachiningStrategy(0);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* follow_circle_forward

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. find_if_vertical returns an error code.
   2. The axis of the circle is not parallel to the machine Z axis:
      CIRCLE_Z_AXIS_MUST_BE_PARALLEL_TO_MACHINE_Z_AXIS.
   3. write_arc returns an error code.

Side Effects: write_arc is called, and it writes code for following the
  circular arc from start point to end point.

Called By: follow_trimmedCurve_forward

*/

static int follow_circle_forward( /* ARGUMENTS                         */
 circle * circl,                  /* the circle to follow              */
 boolean * ahead,                 /* true=counterclockwise, false=cw   */
 cartesianPoint * end,            /* end point                         */
 double code[][7],                /* code array to build               */
 int * lines)                     /* number of lines of code, set here */
{
  static char name[] = "follow_circle_forward";
  cartesianPoint * center;
  int vertical;
  int turns;

  IFF(find_if_vertical(circl->get_position()->get_axis(), &vertical));
  CHK((NOT(vertical)), CIRCLE_Z_AXIS_MUST_BE_PARALLEL_TO_MACHINE_Z_AXIS);
  center = circl->get_position()->get_location();
  turns = (ahead->isA(booleanTrue_E)) ? 1 : -1;
  IFF(write_arc(getCartX(end), getCartY(end), getCartX(center),
		getCartY(center), turns, getCartZ(end), code, lines));
  return ISO14649_OK;
}

/***********************************************************************/

/* follow_compositeCurve_forward

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. A segment is not the last segment of the curve, and its transition
      code is not contSameGradientSameCurvature, contSameGradient, or 
      continuous: COMPOSITE_CURVE_MUST_BE_CONTINUOUS.
   2. follow_curve_forward returns an error code.
   3. follow_curve_backward returns an error code.
   4. A segment is not a boundedCurve:
      COMPOSITE_CURVE_SEGMENT_MUST_BE_A_BOUNDED_CURVE.

Side Effects: code is written to follow the composite curve.

Called By: follow_curve_forward

A composite curve is a set of bounded curves joined end-to-end. The
follow_curve_forward function called here will check that the curves
join properly.

*/

static int follow_compositeCurve_forward( /* ARGUMENTS                       */
 compositeCurve * comp,                /* compositeCurve to follow forward   */
 toolpathType * pathType,              /* connect or trajectoryPath          */
 cartesianPoint ** join,               /* should be join point, may be reset */
 double code[][7],                     /* code array to build                */
 int * lines)                          /* number of lines of code, set here  */
{
  static char name[] = "follow_compositeCurve_forward";
  std::list<compositeCurveSegment *> * segments;
  std::list<compositeCurveSegment *>::iterator iter;
  compositeCurveSegment * seg;
  boundedCurve * curv;

  segments = comp->get_segments()->get_theList();
  for (iter = segments->begin(); iter != segments->end(); ++iter)
    {
      seg = *iter;
      CHK(((seg != segments->back()) &&
	   (!(seg->get_transition()->isA(transitionCodeContinuous_E))) &&
	   (!(seg->get_transition()->isA(transitionCodeContSameGradient_E))) &&
	   (!(seg->get_transition()->isA
	      (transitionCodeContSameGradientSameCurvature_E)))),
	  COMPOSITE_CURVE_MUST_BE_CONTINUOUS);
      if (seg->get_parentCurve()->isA(boundedCurve_E))
	{
	  curv = dynamic_cast<boundedCurve *>(seg->get_parentCurve());
	  if (seg->get_sameSense()->isA(booleanTrue_E))
	    IFF(follow_curve_forward(curv, pathType, join, code, lines));
	  else
	    IFF(follow_curve_backward(curv, pathType, join, code, lines));
	}
      else
	CHK(1, COMPOSITE_CURVE_SEGMENT_MUST_BE_A_BOUNDED_CURVE);
    }
  
  return ISO14649_OK;
}

/***********************************************************************/

/* follow_curve_backward

Returned Value: int
   This returns CANNOT_FOLLOW_BOUNDED_CURVE_BACKWARD.

Side Effects: none

Called By:
  follow_compositeCurve_forward
  op_trajectory
  op_trajectory_rapid

Dealing with a reversed trajectory is a pain, since not only does the
order of segments need to be reversed, in addition, each segment must be
reversed. Moreover, in some cases, each segment has its own direction flag.

So, currently, this is a stub that returns an error code.

*/

static int follow_curve_backward( /* ARGUMENTS                          */
 boundedCurve * curv,             /* curve to follow backward           */
 toolpathType * pathType,         /* connect or trajectoryPath          */
 cartesianPoint ** join,          /* should be join point, may be reset */
 double code[][7],                /* code array to build                */
 int * lines)                     /* number of lines of code, set here  */
{
  static char name[] = "follow_curve_backward";
  CHK(1, CANNOT_FOLLOW_BOUNDED_CURVE_BACKWARD);
  return ISO14649_OK;
}

/***********************************************************************/

/* follow_curve_forward

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. follow_polyline_forward returns an error code.
   2. follow_trimmedCurve_forward returns an error code.
   3. follow_compositeCurve_forward returns an error code.

Side Effects: code is written for following the curve.

Called By:
  follow_compositeCurve_forward
  op_trajectory
  op_trajectory_rapid

*/

static int follow_curve_forward( /* ARGUMENTS                          */
 boundedCurve * curv,            /* curve to follow forward            */
 toolpathType * pathType,        /* connect or trajectoryPath          */
 cartesianPoint ** join,         /* should be join point, may be reset */
 double code[][7],               /* code array to build                */
 int * lines)                    /* number of lines of code, set here  */
{
  static char name[] = "follow_curve_forward";
  if (curv->isA(polyline_E))
    IFF(follow_polyline_forward(dynamic_cast<polyline *>(curv),
				pathType, join, code, lines));
  else if (curv->isA(trimmedCurve_E))
    IFF(follow_trimmedCurve_forward(dynamic_cast<trimmedCurve *>(curv),
				    pathType, join, code, lines));
  else if (curv->isA(compositeCurve_E))
    IFF(follow_compositeCurve_forward(dynamic_cast<compositeCurve *>(curv),
				      pathType, join, code, lines));
  return ISO14649_OK;
}

/***********************************************************************/

/* follow_helix_forward

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. find_if_vertical returns an error code.
   2. The axis of the helix is not parallel to the machine Z-axis:
      HELIX_Z_AXIS_MUST_BE_PARALLEL_TO_MACHINE_Z_AXIS.
   3. The pitch of the helix is zero: HELIX_PITCH_MUST_NOT_BE_ZERO.
   4. write_arc returns an error code.

Side Effects: code is written for following the helix forward.

Called By: follow_trimmedCurve_forward

The (1 - ISO14649_TINY) is used so that an integer number of turns will
be calculated correctly. In a canonical ARC_FEED command, turns is the
number of whole or partial turns. For a helix, it makes sense to make
go all the way around multiple times.

This does not need to test the sense agreement since the helix is an
open curve. The travel and pitch determine the sign of turns (positive
for counterclockwise, negative for clockwise).

*/

static int follow_helix_forward( /* ARGUMENTS                         */
 helix * hely,                   /* the helix to follow               */
 cartesianPoint * start,         /* start point                       */
 cartesianPoint * end,           /* end point                         */
 double code[][7],               /* code array to build               */
 int * lines)                    /* number of lines of code, set here */
{
  static char name[] = "follow_helix_forward";
  cartesianPoint * center;
  int vertical;
  double travel;
  int turns;
  double rotation; // number of complete circles

  IFF(find_if_vertical(hely->get_position()->get_axis(), &vertical));
  CHK((NOT(vertical)), HELIX_Z_AXIS_MUST_BE_PARALLEL_TO_MACHINE_Z_AXIS);
  CHK((hely->get_pitch() == 0.0), HELIX_PITCH_MUST_NOT_BE_ZERO);
  center = hely->get_position()->get_location();
  travel = (getCartZ(end) - getCartZ(start));
  rotation = (travel / hely->get_pitch());
  if (rotation > 0)
    turns = (int)((1 - ISO14649_TINY) + rotation);
  else if (rotation < 0)
    turns = (int)((ISO14649_TINY - 1) + rotation);
  else
    turns = 0;
  IFF(write_arc(getCartX(end), getCartY(end), getCartX(center),
		getCartY(center), turns, getCartZ(end), code, lines));
  return ISO14649_OK;
}

/***********************************************************************/

/* follow_polyline_forward

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The polyline has fewer than two points:
      POLYLINE_MUST_HAVE_AT_LEAST_TWO_POINTS
   2. There is join point where a previous segment should end at the
      start point of the polyline, but there is a gap between those
      two points: TRAJECTORY_MUST_NOT_HAVE_GAP.
   3. write_feed returns an error code.
   4. write_traverse returns an error code.
   5. the pathType is neither a trajectoryPath nor a connect:
      CAN_HANDLE_ONLY_CONNECT_AND_TRAJECTORYPATH_PATH_TYPES.

Side Effects: code is written for following the polyline forward.

Called By: follow_curve_forward

*/

static int follow_polyline_forward( /* ARGUMENTS                          */
 polyline * poly,                   /* polyline to follow forward         */
 toolpathType * pathType,           /* connect or trajectoryPath          */
 cartesianPoint ** join,            /* should be join point, may be reset */
 double code[][7],                  /* code array to build                */
 int * lines)                       /* number of lines of code, set here  */
{
  static char name[] = "follow_polyline_forward";
  std::list<cartesianPoint *> * pts;
  std::list<cartesianPoint *>::iterator iter;
  cartesianPoint * aPoint;
  
  pts = poly->get_points()->get_theList();
  CHK((pts->size() < 2), POLYLINE_MUST_HAVE_AT_LEAST_TWO_POINTS);
  aPoint = pts->front();
  if (*join)
    { // already started, so check join
      CHK(((*join != aPoint) && (dist(*join, aPoint) != 0.0)),
	  TRAJECTORY_MUST_NOT_HAVE_GAP);
    }
  else // not started, so record first point
    {
      aPoint = pts->front();
      IFF(write_feed(getCartX(aPoint), getCartY(aPoint), getCartZ(aPoint),
		     code, lines));
    }
  iter = pts->begin();
  for (++iter; iter != pts->end(); ++iter)
    {
      aPoint = *iter;
      if (pathType->isA(toolpathTypeTrajectoryPath_E))
	IFF(write_feed(getCartX(aPoint), getCartY(aPoint), getCartZ(aPoint),
		       code, lines));
      else if (pathType->isA(toolpathTypeConnect_E))
	IFF(write_traverse(getCartX(aPoint), getCartY(aPoint), getCartZ(aPoint),
		       code, lines));
      else
	CHK(1, CAN_HANDLE_ONLY_CONNECT_AND_TRAJECTORYPATH_PATH_TYPES);
    }
  *join = aPoint;
  return ISO14649_OK;
}

/***********************************************************************/

/* follow_trimmedCurve_forward

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The trim1 list or the trim2 list of the trimmedCurve does not have
      exactly one member: TRIM_LIST_MUST_HAVE_ONE_ELEMENT
   2. A member of a trim list is not a cartesian point:
      TRIM_ELEMENT_MUST_BE_A_CARTESIAN_POINT.
   3. There is join point where a previous segment should end at the
      start point of the trimmedCurve, but there is a gap between those
      two points: TRAJECTORY_MUST_NOT_HAVE_GAP.
   4. write_feed returns an error code.
   5. write_traverse returns an error code.
   6. the pathType is neither a trajectoryPath nor a connect for a line:
      CAN_HANDLE_ONLY_CONNECT_AND_TRAJECTORYPATH_PATH_TYPES.
   7. The pathType is not a trajectoryPath for a circle:
      CAN_HANDLE_ONLY_TRAJECTORYPATH_PATH_TYPE_FOR_CIRCLE.
   8. The pathType is not a trajectoryPath for a helix:
      CAN_HANDLE_ONLY_TRAJECTORYPATH_PATH_TYPE_FOR_HELIX.
   9. The trimmedCurve is not a line, circle, or helix:
      CAN_HANDLE_ONLY_LINE_AND_CIRCLE_AND_HELIX_IN_A_TRIMMED_CURVE.
  10. follow_circle_forward returns an error code.
  11. follow_helix_forward returns an error code.

Side Effects: code is written for following the trimmedCurve forward.

Called By: follow_curve_forward

When the basis curve of the trimmedCurve is a line, it can be ignored;
all that is needed is the end points. 

This is not checking that the end points actually lie on the basis curve.

Since this only goes along one curve, the start point (which will result
in a traverse command being written only if [after transformation] it
differs from the previous location) is always recorded. If the trimmed
curve is first segment of a freeform path, a traverse command will
be written as desired. Otherwise, it will not.

The join check for different points here requires zero distance so that
start_cut will not insert a traverse command.

*/

static int follow_trimmedCurve_forward( /* ARGUMENTS                         */
 trimmedCurve * trimmed,                /* trimmedCurve to follow forward    */
 toolpathType * pathType,               /* connect or trajectoryPath         */
 cartesianPoint ** join,                /* should be join point, may be reset*/
 double code[][7],                      /* code array to build               */
 int * lines)                           /* number of lines of code, set here */
{
  static char name[] = "follow_trimmedCurve_forward";
  curve * basis;
  cartesianPoint * start;
  cartesianPoint * end;

  basis = trimmed->get_basisCurve();
  CHK((trimmed->get_trim1()->get_theList()->size() != 1),
      TRIM_LIST_MUST_HAVE_ONE_ELEMENT);
  CHK((NOT(trimmed->get_trim1()->get_theList()
	   ->front()->isA(cartesianPoint_E))),
      TRIM_ELEMENT_MUST_BE_A_CARTESIAN_POINT);
  start = dynamic_cast<cartesianPoint *>
    (trimmed->get_trim1()->get_theList()->front());
  if (*join)
    { // already started, so check join
      CHK(((*join != start) && (dist(*join, start) != 0.0)),
	  TRAJECTORY_MUST_NOT_HAVE_GAP);
    }
  else // not started, so record first point
    IFF(write_feed(getCartX(start), getCartY(start), getCartZ(start),
		   code, lines));
  CHK((trimmed->get_trim2()->get_theList()->size() != 1),
      TRIM_LIST_MUST_HAVE_ONE_ELEMENT);
  CHK((NOT(trimmed->get_trim2()->get_theList()
	   ->front()->isA(cartesianPoint_E))),
      TRIM_ELEMENT_MUST_BE_A_CARTESIAN_POINT);
  end = dynamic_cast<cartesianPoint *>
    (trimmed->get_trim2()->get_theList()->front());
  if (basis->isA(line_E))
    {
      if (pathType->isA(toolpathTypeTrajectoryPath_E))
	IFF(write_feed(getCartX(end), getCartY(end), getCartZ(end),
		       code, lines));
      else if (pathType->isA(toolpathTypeConnect_E))
	IFF(write_traverse(getCartX(end), getCartY(end), getCartZ(end),
			   code, lines));
      else
	CHK(1, CAN_HANDLE_ONLY_CONNECT_AND_TRAJECTORYPATH_PATH_TYPES);

    }
  else if (basis->isA(circle_E))
    {
      CHK((!(pathType->isA(toolpathTypeTrajectoryPath_E))),
	  CAN_HANDLE_ONLY_TRAJECTORYPATH_PATH_TYPE_FOR_CIRCLE);
      IFF(follow_circle_forward(dynamic_cast<circle *>(basis),
				trimmed->get_senseAgreement(),
				end, code, lines));
    }
  else if (basis->isA(helix_E))
    {
      CHK((!(pathType->isA(toolpathTypeTrajectoryPath_E))),
	  CAN_HANDLE_ONLY_TRAJECTORYPATH_PATH_TYPE_FOR_HELIX);
      IFF(follow_helix_forward(dynamic_cast<helix *>(basis),
			       start, end, code, lines));
    }
  else
    CHK(1, CAN_HANDLE_ONLY_LINE_AND_CIRCLE_AND_HELIX_IN_A_TRIMMED_CURVE);
  *join = end;
    
  return ISO14649_OK;
}

/***********************************************************************/

/* getAxisX

Returned Value: double (see below)

Side Effects: none

Called By:
  check_placement
  find_location
  is_default_placement

This returns the X value of the axis of an axis2placement3d. If the
list of direction ratios of the axis of the placement is empty, this
returns ISO14649_BAD_REAL.

*/

static double getAxisX(        /* ARGUMENTS                    */
 axis2placement3d * placement) /* placement to find axis X for */
{
  return get_real(placement->get_axis()->get_directionRatios()->get_theList(),
		  0);
}

/***********************************************************************/

/* getAxisY

Returned Value: double (see below)

Side Effects: none

Called By:
  check_placement
  find_location
  is_default_placement


This returns the Y value of the axis of an axis2placement3d. If the list of
direction ratios of the axis of the placement has fewer than two
entries, this returns ISO14649_BAD_REAL.

*/

static double getAxisY(        /* ARGUMENTS                    */
 axis2placement3d * placement) /* placement to find axis Y for */
{
  return get_real(placement->get_axis()->get_directionRatios()->get_theList(),
		  1);
}

/***********************************************************************/

/* getAxisZ

Returned Value: double (see below)

Side Effects: none

Called By:
  check_placement
  find_location
  is_default_placement


This returns the Z value of the axis of an axis2placement3d. If the list of
direction ratios of the axis of the placement has fewer than three
entries, this returns ISO14649_BAD_REAL.

*/

static double getAxisZ(        /* ARGUMENTS                    */
 axis2placement3d * placement) /* placement to find axis Z for */
{
  return get_real(placement->get_axis()->get_directionRatios()->get_theList(),
		  2);
}

/***********************************************************************/

/* getCartX

Returned Value: double (see below)

Side Effects: none

Called By:
  follow_circle_forward
  follow_helix_forward
  follow_polyline_forward
  follow_trimmedCurve_forward

This returns the X value of a cartesianPoint. If the list of coordinates
of the cartesianPoint is empty, this returns ISO14649_BAD_REAL.

*/

static double getCartX(  /* ARGUMENTS           */
 cartesianPoint * point) /* point to find X for */
{
  return get_real(point->get_coordinates()->get_theList(), 0);
}

/***********************************************************************/

/* getCartY

Returned Value: double (see below)

Side Effects: none

Called By:
  follow_circle_forward
  follow_helix_forward
  follow_polyline_forward
  follow_trimmedCurve_forward

This returns the Y value of a cartesianPoint. If the list of coordinates
of the cartesianPoint is empty, this returns ISO14649_BAD_REAL.

*/

static double getCartY(  /* ARGUMENTS           */
 cartesianPoint * point) /* point to find Y for */
{
  return get_real(point->get_coordinates()->get_theList(), 1);
}

/***********************************************************************/

/* getCartZ

Returned Value: double (see below)

Side Effects: none

Called By:
  follow_circle_forward
  follow_helix_forward
  follow_polyline_forward
  follow_trimmedCurve_forward

This returns the Z value of a cartesianPoint. If the list of coordinates
of the cartesianPoint is empty, this returns ISO14649_BAD_REAL.

*/

static double getCartZ(  /* ARGUMENTS           */
 cartesianPoint * point) /* point to find Z for */
{
  return get_real(point->get_coordinates()->get_theList(), 2);
}

/***********************************************************************/

/* getDirX

Returned Value: double (see below)

Side Effects: none

Called By:
  check_planar_face
  check_plane_milling_strategies
  find_if_vertical
  mill_planar_bi
  mill_planar_uni

This returns the X value of a direction. If the list of direction
ratios of the direction is empty, this returns ISO14649_BAD_REAL.

*/

static double getDirX( /* ARGUMENTS               */
 direction * dir)      /* direction to find X for */
{
  return get_real(dir->get_directionRatios()->get_theList(), 0);
}

/***********************************************************************/

/* getDirY

Returned Value: double (see below)

Side Effects: none

Called By:
  check_planar_face
  check_plane_milling_strategies
  find_if_vertical
  mill_planar_bi
  mill_planar_uni

This returns the Y value of a direction. If the list of direction
ratios of the direction has fewer than two entries, this returns
ISO14649_BAD_REAL.

*/

static double getDirY( /* ARGUMENTS               */
 direction * dir)      /* direction to find Y for */
{
  return get_real(dir->get_directionRatios()->get_theList(), 1);
}

/***********************************************************************/

/* getDirZ

Returned Value: double (see below)

Side Effects: none

Called By:
  check_planar_face
  check_plane_milling_strategies
  find_if_vertical

This returns the Z value of a direction. If the list of direction
ratios of the direction has fewer than three entries, this returns
ISO14649_BAD_REAL.

*/

static double getDirZ( /* ARGUMENTS               */
 direction * dir)      /* direction to find Z for */
{
  return get_real(dir->get_directionRatios()->get_theList(), 2);
}

/***********************************************************************/

/* getPtX

Returned Value: double (see below)

Called By:
  check_counterbore_hole
  check_countersunk_hole
  check_placement
  find_location
  is_default_placement
  op_center_drilling
  op_counter_boring
  op_counter_sinking
  op_drilling
  op_multistep_drilling
  op_reaming
  transform_code

This returns the X value of the location of an axis2placement3d. If
the list of coordinates of the location of the placement is empty,
this returns ISO14649_BAD_REAL.

*/

static double getPtX(          /* ARGUMENTS                        */
 axis2placement3d * placement) /* placement to find location X for */
{
  return get_real(placement->get_location()->get_coordinates()->
		  get_theList(), 0);
}

/***********************************************************************/

/* getPtY

Returned Value: double
  check_counterbore_hole
  check_countersunk_hole
  check_placement
  find_location
  is_default_placement
  op_center_drilling
  op_counter_boring
  op_counter_sinking
  op_drilling
  op_multistep_drilling
  op_reaming
  transform_code

Called By:

This returns the Y value of the location of an axis2placement3d. If
the list of coordinates of the location of the placement has fewer
than two entries, this returns ISO14649_BAD_REAL.

*/

static double getPtY(          /* ARGUMENTS                        */
 axis2placement3d * placement) /* placement to find location Y for */
{
  return get_real(placement->get_location()->get_coordinates()->
		  get_theList(), 1);
}

/***********************************************************************/

/* getPtZ

Returned Value: double

Called By:
  check_and_store
  check_counterbore_hole
  check_countersunk_hole
  check_op_center_drilling
  check_placement
  check_planar_face
  check_rectangular_pocket
  check_tool_counterbore
  check_tool_countersink
  find_cutting_depths
  find_location
  is_default_placement
  op_center_drilling
  op_counter_boring
  op_counter_sinking
  op_drilling
  op_multistep_drilling
  op_reaming
  transform_code

This returns the Z value of the location of an axis2placement3d. If
the list of coordinates of the location of the placement has fewer
than three entries, this returns ISO14649_BAD_REAL.

*/

static double getPtZ(          /* ARGUMENTS                        */
 axis2placement3d * placement) /* placement to find location Z for */
{
  return get_real(placement->get_location()->get_coordinates()->
		  get_theList(), 2);
}

/***********************************************************************/

/* get_real

Returned Value: double

Called By:
  getAxisX
  getAxisY
  getAxisZ
  getCartX
  getCartY
  getCartZ
  getDirX
  getDirY
  getDirZ
  getPtX
  getPtY
  getPtZ
  getRefX
  getRefY
  getRefZ

This returns a double that is the value of the real number at the
indexth position in a list of real. If the index is beyond the end
of the list, this returns ISO14649_BAD_REAL.

*/

static double get_real(     /* ARGUMENTS                */
 std::list<real *> * reals, /* list of reals to look in */
 int index)                 /* position to choose       */
{
  int n;

  std::list<real *>::iterator iter;
  for (iter = reals->begin(), n = 0;
       ((n < index) && (iter != reals->end()));
       n++, ++iter);
  return ((iter == reals->end()) ? ISO14649_BAD_REAL :
	  (*iter)->get_val());
}

/***********************************************************************/

/* getRefX

Returned Value: double

Called By:
  check_placement
  find_location
  is_default_placement
  transform_code

This returns the X value of the refDirection of an axis2placement3d.
If the list of direction ratios of the refDirection of the placement
is empty, this returns ISO14649_BAD_REAL.

*/

static double getRefX(         /* ARGUMENTS                            */
 axis2placement3d * placement) /* placement to find refDirection X for */
{
  return get_real(placement->get_refDirection()->
		  get_directionRatios()->get_theList(), 0);
}

/***********************************************************************/

/* getRefY

Returned Value: double

Called By:
  check_placement
  find_location
  is_default_placement
  transform_code

This returns the Y value of the refDirection of an axis2placement3d. 
If the list of direction ratios of the refDirection of the placement
has fewer than two entries, this returns ISO14649_BAD_REAL.

*/

static double getRefY(         /* ARGUMENTS                            */
 axis2placement3d * placement) /* placement to find refDirection Y for */
{
  return get_real(placement->get_refDirection()->
		  get_directionRatios()->get_theList(), 1);
}

/***********************************************************************/

/* getRefZ

Returned Value: double

Called By:
  check_placement
  find_location
  is_default_placement

This returns the Z value of the refDirection of an axis2placement3d.
If the list of direction ratios of the refDirection of the placement
has fewer than three entries, this returns ISO14649_BAD_REAL.

*/

static double getRefZ(         /* ARGUMENTS                            */
 axis2placement3d * placement) /* placement to find refDirection Z for */
{
  return get_real(placement->get_refDirection()->
		  get_directionRatios()->get_theList(), 2);
}

/***********************************************************************/

/* handle_feed

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. Both feedrate and feedrate_per_tooth are given:
      MUST_NOT_HAVE_BOTH_FEEDRATE_AND_FEEDRATE_PER_TOOTH.
   2. tool is NULL: TOOL_MUST_NOT_BE_NULL.
   3. tool is not a cuttingTool: TOOL_MUST_BE_A_CUTTING_TOOL.
   4. The body of tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   5. The body of tool is not a millingToolBody:
      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY.
   6. The body of the tool has NULL for numberOfTeeth:
      NUMBER_OF_TEETH_MUST_BE_GIVEN.
   7. The numberOfTeeth is given but not positive:
      NUMBER_OF_TEETH_MUST_BE_BE_POSITIVE.
   8. Neither feedrate nor feedrate_per_tooth is given:
      MUST_HAVE_FEEDRATE_OR_FEEDRATE_PER_TOOTH.

Side Effects: See below

Called By:
  handle_technology
  op_drilling

This deals with setting feed rate from either the given feed rate or
the given surface_speed and the spindle speed (which must have been
set previously). It calls SET_FEED_RATE if the desired feed rate
differs from the currently set feed rate.

ISO 14649, Part 10, section 4.2.1 gives the following (inconsistent) units:
length            millimetres
speed_measure     meters per second
rot_speed_measure revolutions per second (RPS)

Feed rate in meters per second is not consistent with the EMC and the _world,
which use millimeters per minute. If feedrate is given, this function
converts to millimeters per minute.

If feedrate_per_tooth is given, this function calculates the feedrate based
on the number of teeth according to the equation:
  feedrate [in mm/min] =
   (feedrate/tooth [in mm]) * (teeth/revolution) * _world.speed [in revs/min]))

_world.speed is never negative.

*/

static int handle_feed(     /* ARGUMENTS                               */
 real * feedrate,           /* feedrate to use if not NULL             */
 real * feedrate_per_tooth, /* feedrate_per_tooth to use if not NULL   */
 real * factor,             /* factor by which to multiply if not NULL */
 machiningTool * tool)      /* the tool being used                     */
{
  static char name[] = "handle_feed";
  double feedval;
  cuttingTool * a_cutter;
  toolBody * a_body;
  millingToolBody * mill_body;
  int teeth;

  if (feedrate)
    {
      CHK((feedrate_per_tooth),
	  MUST_NOT_HAVE_BOTH_FEEDRATE_AND_FEEDRATE_PER_TOOTH);
      feedval = (feedrate->get_val() * 60000);
    }
  else if (feedrate_per_tooth)
    {
      CHK((tool == 0), TOOL_MUST_NOT_BE_NULL);
      CHK((NOT(tool->isA(cuttingTool_E))), TOOL_MUST_BE_A_CUTTING_TOOL);
      a_cutter = dynamic_cast<cuttingTool *>(tool);
      a_body = a_cutter->get_itsToolBody();
      CHK((a_body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
      CHK((NOT(a_body->isA(millingToolBody_E))),
	  TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY);
      mill_body = dynamic_cast<millingToolBody *>(a_body);
      CHK((mill_body->get_numberOfTeeth() == 0),
	  NUMBER_OF_TEETH_MUST_BE_GIVEN);
      teeth = mill_body->get_numberOfTeeth()->get_val();
      CHK((teeth < 1), NUMBER_OF_TEETH_MUST_BE_POSITIVE);
      feedval = (feedrate_per_tooth->get_val() * teeth * _world.speed);
    }
  else
    CHK(1, MUST_HAVE_FEEDRATE_OR_FEEDRATE_PER_TOOTH);
  if (factor)
    feedval = (feedval * factor->get_val());
  if (feedval != _world.feedrate)
    {
      SET_FEED_RATE(feedval);
      _world.feedrate = feedval;
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_feed_override

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. disable is NULL or neither true nor false: DISABLE_MUST_BE_TRUE_OR_FALSE.

Side Effects: See below

Called By:
  handle_technology
  handle_technology_rapid
  handle_technology_some

If feed_override should be disabled and isn't, it is disabled.
If feed_override should be enabled and isn't, it is enabled.

*/

static int handle_feed_override( /* ARGUMENTS                        */
 boolean * disable)              /* whether to disable feed override */
{
  static char name[] = "handle_feed_override";

  CHK((disable == 0), DISABLE_MUST_BE_TRUE_OR_FALSE);
  if (disable->isA(booleanTrue_E))
    {
      if (_world.feed_override == ON)
	{
	  DISABLE_FEED_OVERRIDE();
	  _world.feed_override = OFF;
	}
    }
  else if (disable->isA(booleanFalse_E))
    {
      if (_world.feed_override == OFF)
	{
	  ENABLE_FEED_OVERRIDE();
	  _world.feed_override = ON;
	}
    }
  else
    CHK(1, DISABLE_MUST_BE_TRUE_OR_FALSE);
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_machine_functions

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The (optional) coolant pressure is present:
      CANNOT_HANDLE_COOLANT_PRESSURE.
   2. The (optional) through pressure is present:
      CANNOT_HANDLE_THROUGH_PRESSURE.
   3. Through spindle coolant is required:
      CANNOT_HANDLE_THROUGH_SPINDLE_COOLANT.
   4. The list of axes to clamp is not empty: CANNOT_HANDLE_AXIS_CLAMPING.
   5. The (optional) process model list is not null or empty:
      CANNOT_HANDLE_PROCESS_MODEL.
   6. The other_functions set is NULL: OTHER_FUNCTIONS_MUST_NOT_BE_NULL.
   7. The other functions set is not empty: CANNOT_HANDLE_OTHER_FUNCTIONS.
   8. Coolant is neither on nor off: COOLANT_MUST_BE_TRUE_OR_FALSE.

Side Effects: See below

Called By:
  cut_feature
  execute_rapid_setup
  op_counter_boring
  op_counter_sinking
  op_drilling
  op_freeform

This function requires some attributes to have specific values, as follows.
coolantPressure: not used (i.e. NULL)
throughSpindleCoolant: false
axisClamping: empty list of property_parameter
throughPressure: not used (i.e. NULL)
itsProcessModel: not used (i.e. NULL)
otherFunctions: empty set of property_parameter

Other attribute values are used as follows.
coolant: if true, turn flood on if not on; if false, turn flood off if not off.
mist: if true, turn mist on if not on; if false, turn mist off if not off.
orientedSpindleStop: not handled here, but may be used later.

This is not doing anything with chipRemoval; the (boolean) value of
this attribute is irrelevant.

*/

static int handle_machine_functions(      /* ARGUMENTS                    */
 millingMachineFunctions * the_functions) /* the machine functions to use */
{
  static char name[] = "handle_machine_functions";

  if (the_functions->get_coolant()->isA(booleanTrue_E))
    {
      if (_world.flood == OFF)
	{
	  FLOOD_ON();
	  _world.flood = ON;
	}
    }
  else if (the_functions->get_coolant()->isA(booleanFalse_E))
    {
      if (_world.flood == ON)
	{
	  FLOOD_OFF();
	  _world.flood = OFF;
	}
    }
  else
    CHK(1, COOLANT_MUST_BE_TRUE_OR_FALSE);
  if (the_functions->get_mist()) // is optional so need to check
    {
      if ((the_functions->get_mist()->isA(booleanTrue_E)) &&
	  (_world.mist == OFF))
	{
	  MIST_ON();
	  _world.mist = ON;
	}
      else if (the_functions->get_mist()->isA(booleanFalse_E) &&
	       (_world.mist == ON))
	{
	  MIST_OFF();
	  _world.mist = OFF;
	}
    }
  CHK(the_functions->get_coolantPressure(),
      CANNOT_HANDLE_COOLANT_PRESSURE);
  CHK(the_functions->get_throughPressure(),
      CANNOT_HANDLE_THROUGH_PRESSURE);
  CHK((the_functions->get_throughSpindleCoolant()->isA(booleanTrue_E)),
      CANNOT_HANDLE_THROUGH_SPINDLE_COOLANT);
  CHK((the_functions->get_axisClamping()->get_theList()->size() != 0),
      CANNOT_HANDLE_AXIS_CLAMPING);
  CHK((the_functions->get_itsProcessModel() &&
       the_functions->get_itsProcessModel()->get_itsList()->
       get_theList()->size() != 0),
      CANNOT_HANDLE_PROCESS_MODEL);
  CHK((the_functions->get_otherFunctions() == 0),
      OTHER_FUNCTIONS_MUST_NOT_BE_NULL);
  CHK((the_functions->get_otherFunctions()->get_theList()->size() != 0),
      CANNOT_HANDLE_OTHER_FUNCTIONS);
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_speed

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. the_tool is not a cuttingTool: TOOL_MUST_BE_A_CUTTING_TOOL.
   3. The body of the_tool is NULL: TOOL_BODY_MUST_NOT_BE_NULL.
   4. The body of the_tool is not a millingToolBody:
      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY.
   5. Both surface speed and spindle speed are given:
      MUST_NOT_HAVE_BOTH_SPINDLE_SPEED_AND_SURFACE_SPEED.
   6. The diameter of the current tool is zero: TOOL_DIAMETER_MUST_NOT_BE_ZERO.
   7. Neither surface speed nor spindle speed is given:
      MUST_HAVE_SPINDLE_SPEED_OR_SURFACE_SPEED.
   8. A left-handed tool is to be turned clockwise:
      MUST_NOT_CUT_WITH_LEFT_HAND_TOOL_TURNING_CLOCKWISE.
   9. A right-handed tool is to be turned counterclockwise:
      MUST_NOT_CUT_WITH_RIGHT_HAND_TOOL_TURNING_COUNTERCLOCKWISE.

Side Effects: See below

Called By:
  handle_technology
  op_drilling

This deals with setting spindle speed from either the given
spindle_speed or the given surface_speed. It calls SET_SPINDLE_SPEED
if the desired speed differs from the currently set speed. If the
_world.spindle_turning needs to be changed, this also calls one of
START_SPINDLE_CLOCKWISE, START_SPINDLE_COUNTERCLOCKWISE, or
STOP_SPINDLE_TURNING.

ISO 14649, Part 10, section 4.2.1 gives the following (inconsistent) units:
length            millimetres
speed_measure     meters per second
rot_speed_measure revolutions per second (RPS)

Rotational speed in RPS is not consistent with the EMC and the _world,
which use revolutions per minute (RPM). This function converts to RPM.
In addition, 14649 speed may positive, negative, or zero while the
_world speed is always positive or zero.  The argument to
SET_SPINDLE_SPEED must be positive or zero.

This function is starting the spindle in the correct direction if the
speed is not zero. It is not certain in this function is the best place
to start the spindle; spindle starting might be moved elsewhere.

We are assuming here that negative surface speed means clockwise rotation,
although 14649 is not clear about this.

This is not checking that factor is in any particular range.
It might be useful to require that if factor is not NULL, its value
is between zero and one, or at least is positive.

*/

static int handle_speed(   /* ARGUMENTS                               */
 real * spindle_speed,     /* spindle speed to use if not NULL        */
 real * surface_speed,     /* surface speed to use if not NULL        */
 real * factor,            /* factor by which to multiply if not NULL */
 machiningTool * the_tool) /* the tool whose speed is being set       */
{
  static char name[] = "handle_speed";
  double diameter;
  double new_speed;
  double old_speed;
  cuttingTool * a_cutter;
  toolBody * a_body;
  millingToolBody * mill_body;
  
  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  CHK((NOT(the_tool->isA(cuttingTool_E))), TOOL_MUST_BE_A_CUTTING_TOOL);
  a_cutter = dynamic_cast<cuttingTool *>(the_tool);
  a_body = a_cutter->get_itsToolBody();
  CHK((a_body == 0), TOOL_BODY_MUST_NOT_BE_NULL);
  CHK((NOT(a_body->isA(millingToolBody_E))),
      TOOL_BODY_FOR_MACHINING_MUST_BE_A_MILLING_TOOL_BODY);
  mill_body = dynamic_cast<millingToolBody *>(a_body);
  if (spindle_speed)
    {
      CHK((surface_speed), MUST_NOT_HAVE_BOTH_SPINDLE_SPEED_AND_SURFACE_SPEED);
      new_speed = (spindle_speed->get_val() * -60);
    }
  else if (surface_speed)
    {
      diameter = _world.tool_table[_world.current_tool_index].diameter;
      CHK((diameter == 0), TOOL_DIAMETER_MUST_NOT_BE_ZERO);
      new_speed = ((-1000 * surface_speed->get_val()) / (diameter * M_PI));
    }
  else
    CHK(1, MUST_HAVE_SPINDLE_SPEED_OR_SURFACE_SPEED);
  if (factor)
    new_speed = (new_speed * factor->get_val());
  old_speed = _world.speed;  // always zero or positive
  if (new_speed > 0)
    {
      CHK((mill_body->get_handOfCut()->isA(handLeft_E)),
	  MUST_NOT_CUT_WITH_LEFT_HAND_TOOL_TURNING_CLOCKWISE);
      if (new_speed != old_speed)
	{
	  SET_SPINDLE_SPEED(new_speed);
	  _world.speed = new_speed;
	}
      if (_world.spindle_turning != CANON_CLOCKWISE)
	{
	  START_SPINDLE_CLOCKWISE();
	  _world.spindle_turning = CANON_CLOCKWISE;
	}
    }
  else if (new_speed < 0)
    {
      CHK((mill_body->get_handOfCut()->isA(handRight_E)),
	  MUST_NOT_CUT_WITH_RIGHT_HAND_TOOL_TURNING_COUNTERCLOCKWISE);
      if (-new_speed != old_speed)
	{
	  SET_SPINDLE_SPEED(-new_speed);
	  _world.speed = -new_speed;
	}
      if (_world.spindle_turning != CANON_COUNTERCLOCKWISE)
	{
	  START_SPINDLE_COUNTERCLOCKWISE();
	  _world.spindle_turning = CANON_COUNTERCLOCKWISE;
	}
    }
  else /* if (new_speed == 0) */
    {
      if (_world.spindle_turning != CANON_STOPPED)
	{
	  STOP_SPINDLE_TURNING();
	  _world.spindle_turning = CANON_STOPPED;
	}
      if (0.0 != old_speed)
	{
	  SET_SPINDLE_SPEED(0.0);
	  _world.speed = 0.0;
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_speed_override

Returned Value: int 
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The speed_override is neither enabled nor disabled:
      DISABLE_MUST_BE_TRUE_OR_FALSE.

Side Effects: See below

Called By:
  handle_technology
  handle_technology_rapid
  handle_technology_some

If speed_override should be disabled and isn't, it is disabled.
If speed_override should be enabled and isn't, it is enabled.

*/

static int handle_speed_override( /* ARGUMENTS                         */
 boolean * disable)               /* whether to disable speed override */
{
  static char name[] = "handle_speed_override";

  CHK((disable == 0), DISABLE_MUST_BE_TRUE_OR_FALSE);
  if (disable->isA(booleanTrue_E))
    {
      if (_world.speed_override == ON)
	{
	  DISABLE_SPEED_OVERRIDE();
	  _world.speed_override = OFF;
	}
    }
  else if (disable->isA(booleanFalse_E))
    {
      if (_world.speed_override == OFF)
	{
	  ENABLE_SPEED_OVERRIDE();
	  _world.speed_override = ON;
	}
    }
  else
    CHK(1, DISABLE_MUST_BE_TRUE_OR_FALSE);

  return ISO14649_OK;
}

/***********************************************************************/

/* handle_speed_rapid

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. Spindle speed is NULL:
      SPINDLE_SPEED_MUST_BE_GIVEN_IN_TECHNOLOGY_FOR_RAPID

Side Effects: See below

Called By: handle_technology_rapid

This deals with setting spindle speed from the given spindle_speed.
It calls SET_SPINDLE_SPEED if the desired speed differs from the
currently set speed. If the _world.spindle_turning needs to be changed,
this also calls one of START_SPINDLE_CLOCKWISE,
 START_SPINDLE_COUNTERCLOCKWISE, or STOP_SPINDLE_TURNING.

ISO 14649, Part 10, section 4.2.1 gives the following (inconsistent) units:
length            millimetres
speed_measure     meters per second
rot_speed_measure revolutions per second (RPS)

Rotational speed in RPS is not consistent with the EMC and the _world,
which use revolutions per minute (RPM). This function converts to RPM.
In addition, 14649 speed may positive, negative, or zero while the
_world speed is always positive or zero.  The argument to
SET_SPINDLE_SPEED must be positive or zero.

This function is starting the spindle in the correct direction if the
speed is not zero. It is not certain in this function is the best place
to start the spindle; spindle starting might be moved elsewhere.

We are assuming here that negative surface speed means clockwise rotation,
although 14649 is not clear about this.

This is not checking that factor is in any particular range.
It might be useful to require that if factor is not NULL, its value
is between zero and one, or at least is positive.

*/

static int handle_speed_rapid( /* ARGUMENTS                             */
 real * spindle_speed)         /* spindle speed to use, may be negative */
{
  static char name[] = "handle_speed_rapid";
  double new_speed;
  double old_speed;

  if (spindle_speed)
    {
      new_speed = (spindle_speed->get_val() * -60);
    }
  else
    CHK(1, SPINDLE_SPEED_MUST_BE_GIVEN_IN_TECHNOLOGY_FOR_RAPID);

  old_speed = _world.speed; // always zero or positive
  if (new_speed > 0)
    {
      if (new_speed != old_speed)
	{
	  SET_SPINDLE_SPEED(new_speed);
	  _world.speed = new_speed;
	}
      if (_world.spindle_turning != CANON_CLOCKWISE)
	{
	  START_SPINDLE_CLOCKWISE();
	  _world.spindle_turning = CANON_CLOCKWISE;
	}
    }
  else if (new_speed < 0)
    {
      if (-new_speed != old_speed)
	{
	  SET_SPINDLE_SPEED(-new_speed);
	  _world.speed = -new_speed;
	}
      if (_world.spindle_turning != CANON_COUNTERCLOCKWISE)
	{
	  START_SPINDLE_COUNTERCLOCKWISE();
	  _world.spindle_turning = CANON_COUNTERCLOCKWISE;
	}
    }
  else /* if (new_speed == 0) */
    {
      if (_world.spindle_turning != CANON_STOPPED)
	{
	  STOP_SPINDLE_TURNING();
	  _world.spindle_turning = CANON_STOPPED;
	}
      if (0.0 != old_speed)
	{
	  SET_SPINDLE_SPEED(0.0);
	  _world.speed = 0.0;
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_synch

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. synch is neither true nor false: SYNCH_MUST_BE_TRUE_OR_FALSE.

Side Effects: See below

Called By:
  handle_technology
  handle_technology_rapid
  handle_technology_some

If speed and feed should be synchronized and aren't, they are synchronized.
If speed and feed should be not synchronized and are, they are unsynchronized.

*/

static int handle_synch( /* ARGUMENTS                             */
 boolean * synch)        /* whether to synchronize feed and speed */
{
  static char name[] = "handle_synch";

  CHK((synch == 0), SYNCH_MUST_BE_TRUE_OR_FALSE);
  if (synch->isA(booleanTrue_E))
    {
      if (_world.speed_feed_mode == CANON_INDEPENDENT)
	{
	  START_SPEED_FEED_SYNCH();
	  _world.speed_feed_mode = CANON_SYNCHED;
	}
    }
  else if (synch->isA(booleanFalse_E))
    {
      if (_world.speed_feed_mode == CANON_SYNCHED)
	{
	  STOP_SPEED_FEED_SYNCH();
	  _world.speed_feed_mode = CANON_INDEPENDENT;
	}
    }
  else
    CHK(1, SYNCH_MUST_BE_TRUE_OR_FALSE);

  return ISO14649_OK;
}

/***********************************************************************/

/* handle_technology

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. handle_speed returns an error code.
   2. handle_feed returns an error code.
   3. handle_synch returns an error code.
   4. handle_feed_override returns an error code.
   5. handle_speed_override returns an error code.
   6. itsAdaptiveControl is not NULL: CANNOT_HANDLE_ADAPTIVE_CONTROL.

Side Effects: See below

Called By:
  cut_feature
  op_counter_boring
  op_counter_sinking
  op_freeform

This deals with: (1) setting spindle speed, (2) setting feed rate,
(3) setting or unsetting feed-speed synchronization, (4) enabling/disabling
feed override, (5) enabling/disabling speed override.

handle_speed must be called before handle_feed, because if feedrate_per_tooth
is given, the feedrate depends on the speed.

C++ data for millingTechnology
------------------------------
real *               feedrate;                   [opt] (technology)
toolReferencePoint * feedrateReference;
real *               cutspeed;                   [opt] (millingTechnology)
real *               spindle;                    [opt]
real *               feedratePerTooth;           [opt]
boolean *            synchronizeSpindleWithFeed;
boolean *            inhibitFeedrateOverride;
boolean *            inhibitSpindleOverride;
boolean *            itsAdaptiveControl;         [opt]

*/

static int handle_technology(        /* ARGUMENTS             */
 millingTechnology * the_technology, /* the technology to use */
 machiningTool * tool)               /* the tool to use       */
{
  static char name[] = "handle_technology";
  
  IFF(handle_speed(the_technology->get_spindle(),
		   the_technology->get_cutspeed(), 0, tool));
  IFF(handle_feed(the_technology->get_feedrate(),
		  the_technology->get_feedratePerTooth(), 0, tool));
  IFF(handle_synch(the_technology->get_synchronizeSpindleWithFeed()));
  IFF(handle_feed_override(the_technology->get_inhibitFeedrateOverride()));
  IFF(handle_speed_override(the_technology->get_inhibitSpindleOverride()));
  CHK((the_technology->get_itsAdaptiveControl() != 0),
      CANNOT_HANDLE_ADAPTIVE_CONTROL);
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_technology_rapid

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. a cutspeed is given: MUST_NOT_USE_CUTSPEED_IN_RAPID.
   2. a feedratePerTooth is given: MUST_NOT_USE_FEEDRATE_PER_TOOTH_IN_RAPID.
   3. feedrate is NULL: FEEDRATE_MUST_BE_GIVEN_FOR_RAPID.
   4. handle_speed_rapid returns an error code.
   5. handle_synch returns an error code.
   6. handle_feed_override returns an error code.
   7. handle_speed_override returns an error code.
   8. itsAdaptiveControl is not NULL: CANNOT_HANDLE_ADAPTIVE_CONTROL.

Side Effects: See below

Called By: 

This deals with: (1) setting spindle speed, (2) setting feed rate,
(3) setting or unsetting feed-speed synchronization, (4) enabling/disabling
feed override, (5) enabling/disabling speed override.

The feedrate is not used for the rapid motion, even if it is reset. Having
a feedrate of some sort is required by the second WHERE rule in Section 4.2.4
of Part 11. This does not seem to make sense for a rapid move, but it is
observed here. Since there may not be a tool, feedratePerTooth and cutspeed,
which require a tool, are not allowed here.

C++ data for millingTechnology
------------------------------
real *               feedrate;                   [opt] (technology)
toolReferencePoint * feedrateReference;
real *               cutspeed;                   [opt] (millingTechnology)
real *               spindle;                    [opt]
real *               feedratePerTooth;           [opt]
boolean *            synchronizeSpindleWithFeed;
boolean *            inhibitFeedrateOverride;
boolean *            inhibitSpindleOverride;
boolean *            itsAdaptiveControl;         [opt]

*/

static int handle_technology_rapid( /* ARGUMENTS             */
 millingTechnology * tech)          /* the technology to use */
{
  static char name[] = "handle_technology";
  double feedval;
  real * feedrate;
  
  CHK(tech->get_cutspeed(), MUST_NOT_USE_CUTSPEED_IN_RAPID);
  CHK(tech->get_feedratePerTooth(), MUST_NOT_USE_FEEDRATE_PER_TOOTH_IN_RAPID);
  feedrate = tech->get_feedrate();
  CHK((feedrate == 0), FEEDRATE_MUST_BE_GIVEN_FOR_RAPID);
  IFF(handle_speed_rapid(tech->get_spindle()));
  feedval = (feedrate->get_val() * 60000);
  if (feedval != _world.feedrate)
    {
      SET_FEED_RATE(feedval);
      _world.feedrate = feedval;
    }
  IFF(handle_synch(tech->get_synchronizeSpindleWithFeed()));
  IFF(handle_feed_override(tech->get_inhibitFeedrateOverride()));
  IFF(handle_speed_override(tech->get_inhibitSpindleOverride()));
  CHK(tech->get_itsAdaptiveControl(), CANNOT_HANDLE_ADAPTIVE_CONTROL);
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_technology_some

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. handle_synch returns an error code.
   2. handle_feed_override returns an error code.
   3. handle_speed_override returns an error code.
   4. itsAdaptiveControl is not NULL: CANNOT_HANDLE_ADAPTIVE_CONTROL.

Side Effects: See below

Called By: op_drilling

This is the same as handle technology, except that it does not deal with:
(1) setting spindle speed or (2) setting feed rate.

*/

static int handle_technology_some(   /* ARGUMENTS             */
 millingTechnology * the_technology) /* the technology to use */
{
  static char name[] = "handle_technology_some";
  
  IFF(handle_synch(the_technology->get_synchronizeSpindleWithFeed()));
  IFF(handle_feed_override(the_technology->get_inhibitFeedrateOverride()));
  IFF(handle_speed_override(the_technology->get_inhibitSpindleOverride()));
  CHK((the_technology->get_itsAdaptiveControl() != 0),
      CANNOT_HANDLE_ADAPTIVE_CONTROL);
  return ISO14649_OK;
}

/***********************************************************************/

/* handle_tool

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is NULL: TOOL_MUST_NOT_BE_NULL.
   2. change_tool returns an error code.

Side Effects: If the_tool is not the current tool, the tool is changed.

Called By:
  execute_machining
  execute_nc_function

*/

static int handle_tool(    /* ARGUMENTS                             */
 machiningTool * the_tool, /* the tool to use                       */
 int set_flag)             /* whether to set the _world.action_flag */
{
  static char name[] = "handle_tool";

  CHK((the_tool == 0), TOOL_MUST_NOT_BE_NULL);
  if (strcmp(the_tool->get_itsId(),
	     _world.tool_table[_world.current_tool_index].id) != 0)
    IFF(change_tool(the_tool, set_flag));
  return ISO14649_OK;
}

/****************************************************************************/

/* handle_unload_tool

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_tool is not NULL: THE_TOOL_MUST_BE_NULL_IN_UNLOAD_TOOL
   2. change_tool returns an error code.

Side Effects: See below

Called By: execute_nc_function

In ISO 14649, Part 11, section 4.2.1.5, which describes the
unloadTool command, makes the_tool argument optional and says it must
be used if two tools are in use at the same time. In the EMC, only one
tool can be in use at a time, so this data is never needed. To avoid
having to check for the error of trying to unload a tool that is not
in the spindle, this function requires that the_tool be NULL.

If the_tool is null, and the current tool index is not zero (meaning
there is no tool in the spindle), this takes the current tool out
of the spindle and sets the current tool index to zero.

It is not an error to call this function if there is no tool in the
spindle.

*/

static int handle_unload_tool( /* ARGUMENTS               */
 machiningTool * the_tool)     /* must be null, see above */
{
  static char name[] = "handle_unload_tool";

  CHK((the_tool != 0), THE_TOOL_MUST_BE_NULL_IN_UNLOAD_TOOL);
  if (_world.current_tool_index)
    IFF(change_tool(0, 1));
  return ISO14649_OK;
}

/****************************************************************************/

/* init_place

Returned Value: int (ISO14649_OK)

Side Effects: This sets the place to the default location: origin at
(0,0,0), Z-axis of (0,0,1), X-axis of (1,0,0).  The place, which must
already exist, gets all new components (on the assumption that the
components are all NULL or are garbage pointers or can be discarded).

Called By:
  check_and_store
  iso14649_init
  op_counter_boring
  op_counter_sinking

*/

static int init_place(      /* ARGUMENTS                   */
 axis2placement3d * place)  /* placement filled out here   */
{
  parenRealListFull * origin_coords; 
  parenRealListFull * axis_ratios; 
  parenRealListFull * ref_ratios;
  std::list<real *> * reals;

  reals = new std::list<real *>;
  origin_coords = new parenRealListFull(reals);
  reals = new std::list<real *>;
  axis_ratios = new parenRealListFull(reals);
  reals = new std::list<real *>;
  ref_ratios = new parenRealListFull(reals);
  place->set_location(new cartesianPoint("point", origin_coords));
  place->set_axis(new direction("direction", axis_ratios));
  place->set_refDirection(new direction("direction", ref_ratios));
  reset_place(place);
  return ISO14649_OK;
}

/***********************************************************************/

/* is_default_placement

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_placement returns an error code.
   2. The origin is not at (0, 0, 0):
      DEFAULT_PLACEMENT_ORIGIN_MUST_BE_AT_ZERO_ZERO_ZERO,
   3. The axis is not (0, 0, 1):
      DEFAULT_PLACEMENT_AXIS_MUST_BE_ZERO_ZERO_ONE.
   4. The ref_direction is not (1, 0, 0):
      DEFAULT_PLACEMENT_REF_DIRECTION_MUST_BE_ONE_ZERO_ZERO.

Side Effects:  None

Called By:  check_and_store

Note that this is checking exact values, not using a tolerance. This may
need to be changed.

*/

static int is_default_placement( /* ARGUMENTS               */
 axis2placement3d * place)       /* axis placement to check */
{
  static char name[] = "is_default_placement";

  IFF(check_placement(place));
  CHK(((getPtX(place) != 0.0) OR
       (getPtY(place) != 0.0) OR
       (getPtZ(place) != 0.0)),
      DEFAULT_PLACEMENT_ORIGIN_MUST_BE_AT_ZERO_ZERO_ZERO);
  CHK(((getAxisX(place) != 0.0) OR
       (getAxisY(place) != 0.0) OR
       (getAxisZ(place) != 1.0)),
      DEFAULT_PLACEMENT_AXIS_MUST_BE_ZERO_ZERO_ONE);
  CHK(((getRefX(place) != 1.0) OR
       (getRefY(place) != 0.0) OR
       (getRefZ(place) != 0.0)),
      DEFAULT_PLACEMENT_REF_DIRECTION_MUST_BE_ONE_ZERO_ZERO);
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_circular_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. write_arc returns an error code.

Side Effects:  the code array is written into, and the lines index is
   increased.

Called By: mill_rectangular_pocket_regular

When this starts up, the tool tip is at the center of the circular
pocket and inserted to the correct depth.

This recalculates stepover so that all stepovers are the same size
(rather then having one last one be smaller than the others if
necessary).

When spiral is 1, this moves one stepover towards +X, makes a circle
counterclockwise, etc, until it is done.

When spiral is -1, the direction of path rotation is switched to
clockwise by reversing the direction of arcs.

*/

static int mill_circular_pocket( /* ARGUMENTS                        */
 double length,                  /* length (and width) of pocket     */
 double z_now,                   /* Z coordinate at cutting depth    */
 double stepover,                /* horizontal stepover              */
 double tool_diameter,           /* diameter of tool                 */
 int spiral,                     /* 1=counterclockwise, -1=clockwise */
 double code[][7],               /* code array to write in           */
 int * lines)                    /* code array index                 */
{
  static char name[] = "mill_circular_pocket";
  double total;      // total of all stepovers
  double radius_now; // radius of current circle
  int passes;        // number of stepovers
  int n;

  total = ((length - tool_diameter) / 2.0);
  passes = (1 + (int)((total - ISO14649_TINY) / stepover));
  stepover = (total / passes);
  radius_now = 0;
  for (n = 0; n < passes; n++)
    {
      radius_now = (radius_now + stepover);
      IFF(write_feed(radius_now, 0, z_now, code, lines));
      IFF(write_arc(radius_now, 0, 0, 0, spiral, z_now, code, lines));
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_planar

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_planar_face returns an error code.
   2. check_plane_milling_strategies returns an error code.
   3. mill_planar_regular returns an error code.

Side Effects: See below

Called By:
  op_finish_milling_plane
  op_rough_milling_plane

C++ data for planeMilling
-------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions;
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract; [opt]
two5DmillingStrategy *    itsMachiningStrategy;[opt] (two5DMillingOperation)
real *                    axialCuttingDepth;   [opt] (planeMilling)
real *                    allowanceBottom;     [opt]

check_plane_milling_strategies may insert milling strategies in
the_milling. After code is generated here, these strategies are removed
from the_milling (since the_milling may be used elsewhere) and deleted.

If the_cut does not give an overcutLength, overcut is set here as 1.25
times the tool diameter. For unidirectionalMilling this is needed to avoid
collisions when plunging. For bidirectionalMilling this gets the tool
clear of the planarFace before it changes direction, leaving a better
surface finish than if that is not done.

If the cut does not have a passDepth, pass_depth is set to half of
the diameter or half of the edge_length, whichever is less. This is
to make the pass_depth reasonable for either an endmill (for which
diameter is usually much less than edge_length) or a facemill (for
which edge_length is usually much less than diameter).

Notes:

This is assuming that there is no material to collide with to the sides
of the bottom of the face being milled. A solid modeler would be needed
to verify that this is a correct assumption.

Since only a plungeToolaxis strategy is currently being handled for
approach and retract, the enter_strategy and leave_strategy are not
really required; their existence can be assumed. If it becomes
possible to handle other approach and retract strategies, the
enter_strategy and leave_strategy will be needed.

*/

static int mill_planar(    /* ARGUMENTS                               */
 planarFace * the_face,    /* planar face to make                     */
 planeMilling * the_cut,   /* planeFinishMilling or planeRoughMilling */
 millingCutter * the_mill) /* an endmill or facemill                  */
{
  static char name[] = "mill_planar";
  approachRetractStrategy * enter_strategy;
  approachRetractStrategy * leave_strategy;
  two5DmillingStrategy * inside_strategy;
  double stepover;
  double overlap;      // overlap used to find horizontal stepover
  double diameter;     // diameter of cutter
  double plane_length; // X-size of rectangle, set in check_planar_face
  double plane_width;  // Y-size of rectangle, set in check_planar_face
  double plane_depth;  // positive depth set in check_planar_face
  double pass_depth;   // see above
  double edge_length;  // edge length of the_mill
  double overcut;      // as given, or 1.25 times diameter if NULL

  diameter = the_mill->get_dimension()->get_diameter();
  edge_length = the_mill->get_dimension()->get_cuttingEdgeLength()->get_val();
  enter_strategy = 0;
  leave_strategy = 0;
  inside_strategy = 0;
  IFF(check_planar_face(the_face, &plane_length, &plane_width, &plane_depth));
  IFF(check_plane_milling_strategies(the_cut, diameter, &enter_strategy,
				     &leave_strategy, &inside_strategy));
  overlap = (the_cut->get_itsMachiningStrategy()->get_overlap() ?
	     the_cut->get_itsMachiningStrategy()->get_overlap()->get_val() :
	     0.2);
  stepover = (diameter * (1 - overlap));
  pass_depth = (the_cut->get_axialCuttingDepth() ?
		the_cut->get_axialCuttingDepth()->get_val() :
		MIN((diameter / 2.0), (edge_length / 2.0)));
  overcut = (the_cut->get_overcutLength() ? 
	     the_cut->get_overcutLength()->get_val() : (diameter * 1.25));
  IFF(mill_planar_regular(plane_length, plane_width, plane_depth, diameter,
			  pass_depth, stepover, overcut, the_cut));
  if (enter_strategy)
    {
      delete enter_strategy;
      the_cut->set_approach(0);
    }
  if (leave_strategy)
    {
      delete leave_strategy;
      the_cut->set_retract(0);
    }
  if (inside_strategy)
    {
      delete inside_strategy;
      the_cut->set_itsMachiningStrategy(0);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_planar_bi

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The function pointed at by feeder returns an error code.
   2. The function pointed at by traverser returns an error code.

Side Effects: See below

Called By: mill_planar_regular

This generates pseudocode in feature coordinates for milling a
rectangular patch of planarFace in the first quadrant with a side on
the X-axis and another side on the Y-axis.

C++ data for bidirectionalMilling
---------------------------------
real *                     overlap;                [opt] (two5DMillingStrategy)
boolean *                  allowMultiplePasses;    [opt]
direction *                feedDirectionIn,        [opt] (bidirectionalMilling) 
leftOrRight *              stepoverDirectionIn,    [opt]
strokeConnectionStrategy * itsStrokeConnectionStrategy [opt]

Section 4.2.8.1.2 of Part 11 says feedDirection is the direction of the
first cut (we are assuming the directions are in terms of the coordinate
system of the feature).

It has already been checked that if the feedDirection exists it is parallel
to the +X, -X, +Y, or -Y axis, but it might not exist.

The pass_depth has been selected so that the mill_depth is divisible
evenly by the pass_depth.

This handles 8 cases (the 4 possible starting directions times the 2
first stepover sides).

This is moving the cutter at the given feed rate (not at traverse rate)
between horizontal cuts. Traverse rate could be used instead. That would
save time but is more risky. Between vertical passes, a traverse is made
while retracted from the last XY location back to the first. That is not
risky because anything that might be collided with has been milled away
or already hit.

On each cut except (probably) the last this cuts a horizontal strip one
stepover wide.

This is not being clever about the last horizontal cut of each pass, which
could, for example, be made down the center of the last strip of material
or be made so that only a small part of the cutter sticks off the edge
of material.

*/

static int mill_planar_bi(  /* ARGUMENTS                      */
 double length,             /* length (X-size) of face to cut */
 double width,              /* width (Y-size) of face to cut  */
 int passes,                /* number of passes to make       */
 double diameter,           /* diameter of cutter             */
 double pass_depth,         /* positive vertical pass_depth   */
 double stepover,           /* horizontal stepover            */
 double overage,            /* clearance tool center to edge  */
 double retract,            /* amount by which to retract     */
 bidirectionalMilling * bi, /* bidirectional milling strategy */
 double code[][7],          /* code array to write in         */
 int * lines)               /* code array index               */
{
  static char name[] = "mill_planar_bi";
  int cuts;                  // number of horizontal cuts to make
  double x1;                 // first (and odd numbered) X position
  double x2;                 // second (and even numbered) X position
  double y1;                 // first Y position
  double x_now;              // current X position, gets updated
  double y_now;              // current Y position, gets updated
  double z_now;              // current Z position, gets updated
  direction * dir;           // given feed direction
  int direction1;            // 1=+X, 2=-X, 3=+Y, 4=-Y
  int n;                     // vertical pass counter
  int m;                     // horizontal cut counter
  int sign;                  // set to +1 or -1 for Y increments
  int (*feeder)(double, double, double, double[][7], int *);
  int (*traverser)(double, double, double, double[][7], int *);

  dir = bi->get_feedDirection();
  direction1 = ((dir == 0)      ? 1 :
		     (getDirX(dir) > 0) ? 1 :
		     (getDirX(dir) < 0) ? 2 :
		     (getDirY(dir) > 0) ? 3 : 4);
  if (direction1 < 3) // cuts parallel to X-axis
    {
      feeder = write_feed;
      traverser = write_traverse;
      cuts = (1 + (int)((width - ISO14649_TINY) / stepover));
      if (direction1 == 1) // first cut in +X direction
	{
	  x1 = -overage;
	  x2 = (length + overage);
	  if (bi->get_stepoverDirection()->isA(leftOrRightLeft_E))
	    {
	      sign = +1;
	      y1 = (stepover - (diameter / 2.0));
	    }
	  else // if bi->stepover_direction is right or not given
	    {
	      sign = -1;
	      y1 = (width - (stepover - (diameter / 2.0)));
	    }
	}
      else // if (direction1 == 2), first cut in -X direction
	{
	  x1 = (length + overage);
	  x2 = -overage;
	  if (bi->get_stepoverDirection()->isA(leftOrRightLeft_E))
	    {
	      sign = -1;
	      y1 = (width - (stepover - (diameter / 2.0)));
	    }
	  else // if bi->get_stepoverDirection() is right or not given
	    {
	      sign = +1;
	      y1 = (stepover - (diameter / 2.0));
	    }
	}
    }
  else // cuts parallel to Y-axis
    {
      feeder = write_feed_y;
      traverser = write_traverse_y;
      cuts = (1 + (int)((length - ISO14649_TINY) / stepover));
      if (direction1 == 3) // first cut in +Y direction
	{
	  x1 = -overage;
	  x2 = (width + overage);
	  if (bi->get_stepoverDirection()->isA(leftOrRightLeft_E))
	    {
	      sign = +1;
	      y1 = (-length + (stepover - (diameter / 2.0)));
	    }
	  else // if bi->get_stepoverDirection() is right or not given
	    {
	      sign = -1;
	      y1 = -(stepover - (diameter / 2.0));
	    }
	}
      else // if (direction1 == 4), first cut in -Y direction
	{
	  x1 = (width + overage);
	  x2 = -overage;
	  if (bi->get_stepoverDirection()->isA(leftOrRightLeft_E))
	    {
	      sign = -1;
	      y1 = -(stepover - (diameter / 2.0));
	    }
	  else // if bi->get_stepoverDirection() is right or not given
	    {
	      sign = +1;
	      y1 = (-length + (stepover - (diameter / 2.0)));
	    }
	}
    }
  IFF(feeder(x1, y1, retract, code, lines));
  z_now = 0;
  for (n = 0; n < passes; n++)
    {
      y_now = y1;
      x_now = x1;
      z_now = (z_now - pass_depth);
      IFF(feeder(x_now, y_now, z_now, code, lines));
      for (m = 0; m < cuts; m++)
	{
	  x_now = ((x_now == x1) ? x2: x1);
	  IFF(feeder(x_now, y_now, z_now, code, lines));
	  if (m < (cuts - 1))
	    {
	      y_now = (y_now + (sign * stepover));
	      IFF(feeder(x_now, y_now, z_now, code, lines));
	    }
	}
      IFF(traverser(x_now, y_now, retract, code, lines));
      if (n < (passes - 1))
	IFF(traverser(x1, y1, retract, code, lines));
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_planar_regular

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. A retract above the current security plane is programmed:
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE.
   2. A milling strategy not unidirectionalMilling or
      bidirectionalMilling is given:
      CAN_HANDLE_ONLY_UNIDIRECTIONAL_AND_BIDIRECTIONAL_PLANE_MILLING.
   3. mill_planar_bi returns an error code.
   4. mill_planar_uni returns an error code.
   5. start_cut returns an error code.
   6. run_code returns an error code.
   7. find_retract_z returns an error code.
   8. transform_code returns an error code.

Side Effects: See below

Called By: mill_planar

This cuts a rectangular patch of planar face in the first quadrant. One
side of the rectangle lies on the X-axis, another on the Y-axis. First
it generates pseudocode; then it executes the pseudocode.

The plane_depth is positive.

Notes:

The current location is not explicitly updated here since run_code
(which is called here) does the updating.

*/

static int mill_planar_regular( /* ARGUMENTS                       */
 double plane_length,           /* length (X-size) of face to cut  */
 double plane_width,            /* width (Y-size) of face to cut   */
 double plane_depth,            /* depth without bottom allowance  */
 double diameter,               /* diameter of cutter              */
 double pass_depth,             /* given pass_depth, reset here    */
 double stepover,               /* horizontal stepover             */
 double overcut,                /* amount of overcut to use        */
 planeMilling * the_cut)        /* plane milling operation to do   */   
{
  static char name[] = "mill_planar_regular";
  double code[ISO14649_CODE_SIZE][7]; // lines of code
  int lines;                          // number of lines of code
  double mill_depth;                  // depth to which to cut
  int passes;                         // number of passes to make
  double retract;                     // amount by which to retract
  two5DmillingStrategy * strat;       // strategy to use
  
  lines = 0;
  mill_depth =
    (the_cut->get_allowanceBottom() ?
     (plane_depth - the_cut->get_allowanceBottom()->get_val()) :
     (the_cut->isA(planeRoughMilling_E)) ?
     (plane_depth - ISO14649_ALLOW) : plane_depth);
  passes = (1 + (int)((mill_depth - ISO14649_TINY) / pass_depth));
  pass_depth = (mill_depth / passes);
  IFF(find_retract_z(0, the_cut->get_retractPlane(), ISO14649_UP, &retract));
  strat = the_cut->get_itsMachiningStrategy();
  if (strat->isA(bidirectionalMilling_E))
    IFF(mill_planar_bi(plane_length, plane_width, passes, diameter,
		       pass_depth, stepover, (overcut - (diameter/2)), retract,
		       dynamic_cast<bidirectionalMilling *>(strat),
		       code, &lines));
  else if (strat->isA(unidirectionalMilling_E))
    IFF(mill_planar_uni(plane_length, plane_width, passes, diameter,
			pass_depth, stepover, (overcut -(diameter/2)),
			retract, dynamic_cast<unidirectionalMilling *>(strat),
			code, &lines));
  else
    CHK(1, CAN_HANDLE_ONLY_UNIDIRECTIONAL_AND_BIDIRECTIONAL_PLANE_MILLING);
  IFF(transform_code(code, lines, &(_world.feature_place)));
  CHK((code[0][3] > _world.security_z_now),
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
  IFF(start_cut(code[0][1], code[0][2], code[0][3]));
  IFF(run_code((code + 1), (lines - 1)));
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_planar_uni

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The function pointed at by feeder returns an error code.
   2. The function pointed at by traverser returns an error code.

Side Effects: See below

Called By: mill_planar_regular

This generates pseudocode in feature coordinates for milling a
rectangular patch of planarFace in the first quadrant with a side on
the X-axis and another side on the Y-axis.

C++ data for unidirectionalMilling
----------------------------------
real *        overlap;             [opt] (two5DMillingStrategy)
boolean *     allowMultiplePasses; [opt]
direction *   feedDirection;       [opt] (unidirectionalMilling) 
cutmodeType * cutmode;             [opt]

Section 4.2.8.1.2 of Part 11 says feedDirection is the direction of the
first cut (we are assuming the directions are in terms of the coordinate
system of the feature).

It has already been checked that if the feedDirection exists it is parallel
to the +X, -X, +Y, or -Y axis, but it might not exist.

The pass_depth has been selected so that the mill_depth is divisible
evenly by the pass_depth.

This handles 8 cases (the 4 possible starting directions times the 2
first stepover sides).

On each cut except (probably) the last, this cuts a horizontal strip one
stepover wide.

If cutmode is not given, this defaults to conventional.

This is not being clever about the last horizontal cut of each pass, which
could, for example, be made down the center of the last strip of material
or be made so that only a small part of the cutter sticks off the edge
of material.

This is assuming a right-handed tool. This could be checked.

*/
static int mill_planar_uni(    /* ARGUMENTS                       */
 double length,                /* length (X-size) of face to cut  */
 double width,                 /* width (Y-size) of face to cut   */
 int passes,                   /* number of passes to make        */
 double diameter,              /* diameter of cutter              */
 double pass_depth,            /* positive vertical pass_depth    */
 double stepover,              /* horizontal stepover             */
 double overage,               /* clearance tool center to edge   */
 double retract,               /* amount by which to retract      */
 unidirectionalMilling * uni,  /* unidirectional milling strategy */
 double code[][7],             /* code array to write in          */
 int * lines)                  /* code array index                */
{
  static char name[] = "mill_planar_uni";
  int cuts;                  // number of horizontal cuts to make
  double x1;                 // first (and odd numbered) X position
  double x2;                 // second (and even numbered) X position
  double y1;                 // first Y position
  double y_now;              // current Y position, gets updated
  double z_now;              // current Z position, gets updated
  direction * dir;           // given feed direction
  int direction1;            // 1=+X, 2=-X, 3=+Y, 4=-Y
  int n;                     // vertical pass counter
  int m;                     // horizontal cut counter
  int sign;                  // set to +1 or -1 for Y increments
  int (*feeder)(double, double, double, double[][7], int *);
  int (*traverser)(double, double, double, double[][7], int *);

  dir = uni->get_feedDirection();
  direction1 = ((dir == 0)      ? 1 :
		     (getDirX(dir) > 0) ? 1 :
		     (getDirX(dir) < 0) ? 2 :
		     (getDirY(dir) > 0) ? 3 : 4);
  if (direction1 < 3) // cuts parallel to X-axis
    {
      feeder = write_feed;
      traverser = write_traverse;
      cuts = (1 + (int)((width - ISO14649_TINY) / stepover));
      if (direction1 == 1) // first cut in +X direction
	{
	  x1 = -overage;
	  x2 = (length + overage);
	  if (uni->get_cutmode()->isA(cutmodeTypeClimb_E))
	    {
	      sign = -1;
	      y1 = (width - (stepover - (diameter / 2.0)));
	    }
	  else // if uni->get_cutmode() is conventional or not given
	    {
	      sign = +1;
	      y1 = (stepover - (diameter / 2.0));
	    }
	}
      else // if (direction1 == 2), first cut in -X direction
	{
	  x1 = (length + overage);
	  x2 = -overage;
	  if (uni->get_cutmode()->isA(cutmodeTypeClimb_E))
	    {
	      sign = +1;
	      y1 = (stepover - (diameter / 2.0));
	    }
	  else // if uni->get_cutmode() is conventional or not given
	    {
	      sign = -1;
	      y1 = (width - (stepover - (diameter / 2.0)));
	    }
	}
    }
  else // cuts parallel to Y-axis
    {
      feeder = write_feed_y;
      traverser = write_traverse_y;
      cuts = (1 + (int)((length - ISO14649_TINY) / stepover));
      if (direction1 == 3) // first cut in +Y direction
	{
	  x1 = -overage;
	  x2 = (width + overage);
	  if (uni->get_cutmode()->isA(cutmodeTypeClimb_E))
	    {
	      sign = -1;
	      y1 = -(stepover - (diameter / 2.0));
	    }
	  else // if uni->get_cutmode() is conventional or not given
	    {
	      sign = +1;
	      y1 = (-length + (stepover - (diameter / 2.0)));
	    }
	}
      else // if (direction1 == 4), first cut in -Y direction
	{
	  x1 = (width + overage);
	  x2 = -overage;
	  if (uni->get_cutmode()->isA(cutmodeTypeClimb_E))
	    {
	      sign = +1;
	      y1 = (-length + (stepover - (diameter / 2.0)));
	    }
	  else // if uni->get_cutmode() is conventional or not given
	    {
	      sign = -1;
	      y1 = -(stepover - (diameter / 2.0));
	    }
	}
    }
  IFF(feeder(x1, y1, retract, code, lines));
  z_now = 0;
  for (n = 0; n < passes; n++)
    {
      y_now = y1;
      z_now = (z_now - pass_depth);
      IFF(feeder(x1, y_now, z_now, code, lines));
      for (m = 0; m < cuts; m++)
	{
	  IFF(feeder(x2, y_now, z_now, code, lines));
	  IFF(traverser(x2, y_now, retract, code, lines));
	  if (m < (cuts - 1))
	    {
	      y_now = (y_now + (sign * stepover));
	      IFF(traverser(x1, y_now, retract, code, lines));
	      IFF(feeder(x1, y_now, z_now, code, lines));
	    }
	}
      if (n < (passes - 1))
	IFF(traverser(x1, y1, retract, code, lines));
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_rectangular_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The pocket depth is not positive: POCKET_DEPTH_MUST_BE_POSITIVE.
   2. find_retract_z returns an error code.
   3. The pocket width is less than the tool diameter:
      POCKET_MUST_NOT_BE_NARROWER_THAN_TOOL.
   4. plunge_pocket returns an error code.
   5. cut_straight returns an error code.
   6. mill_rectangular_pocket_regular returns an error code.

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  rough_mill_both_closed_pocket

C++ data for closedPocket
-------------------------
char *                        itsId;                 (manufacturingFeature)
workpiece *                   itsWorkpiece;
parenMachiningOperationList * itsOperations;
axis2placement3d *            featurePlacement;      (two5DmanufacturingFeature)
elementarySurface *           depth;                 (machiningFeature)
parenBossList *               itsBoss;               (pocket)
real *                        slope;            [opt]
pocketBottomCondition *       bottomCondition;
tolerancedLengthMeasure *     planarRadius;     [opt]
tolerancedLengthMeasure *     orthogonalRadius; [opt]
closedProfile *               featureBoundary;       (closedPocket)

C++ data for rectangularClosedProfile
-------------------------------------
axis2placement3d *        placement;     [opt] (profile)
<no attributes>                                (closedProfile)
tolerancedLengthMeasure * profileWidth;        (rectangularClosedProfile)
tolerancedLengthMeasure * profileLength;

C++ data for bottomAndSideMilling
---------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions; 
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract;             [opt]
two5DmillingStrategy *    itsMachiningStrategy;[opt] (two5DMillingOperation)
real *                    axialCuttingDepth;   [opt] (bottomAndSideMilling)
real *                    radialCuttingDepth;  [opt]
real *                    allowanceSide;       [opt]
real *                    allowanceBottom;     [opt]

Note:
<no attributes> (bottomAndSideRoughMilling)
<no attributes> (bottomAndSideFinishMilling)

This writes code into the code argument assuming the pocket is in default
position (at the origin).

The first point in the code must be the highest point reached during
machining so that checking that the transformed first point is below
the security plane will insure that all tool motion is below the
security plane.

axialCuttingDepth (pass_depth) may be NULL. check_op_finish_both or
check_op_rough_both has already checked that it is positive if it is
given. This sets pass_depth to one tool radius if it is NULL.

If the allowanceBottom is not NULL, the cutting depth is set to the value
of the allowanceBottom less than the pocket depth.
If the allowanceBottom is NULL, and this is rough milling, the
cutting depth is set to ISO14649_ALLOW less than the pocket depth.
If the allowanceBottom is NULL, and this is finish milling, the
cutting depth is set to the pocket depth.

The allowanceSide may be NULL. If so, and this is rough
milling, the side allowance is set to ISO14649_ALLOW. If so and
this is finish milling, the side allowance is set to zero.

*/

static int mill_rectangular_pocket(  /* ARGUMENTS              */
 double pocket_length,               /* length of final pocket */
 double pocket_width,                /* width of final pocket  */
 double pocket_depth,                /* depth of final pocket  */
 double pocket_radius,               /* radius of final pocket */
 double stepover,                    /* stepover for cutting   */
 double tool_diameter,               /* diameter of tool       */
 bottomAndSideMilling * the_cut,     /* operation to execute   */
 double code[][7],                   /* code array to write in */
 int * lines)                        /* code array index       */
{
  static char name[] = "mill_rectangular_pocket";
  double side;         // thickness to leave on sides
  double retract;      // amount by which to retract
  double mill_length;  // length of pocket to make
  double mill_width;   // width of pocket to make
  double mill_depth;   // depth of pocket to make
  double extra_length; // length of toolpath
  double extra_width;  // width of toolpath
  double pass_depth;   // pass depth

  mill_depth =
    (the_cut->get_allowanceBottom() ?
     (pocket_depth - the_cut->get_allowanceBottom()->get_val()) :
     (the_cut->isA(bottomAndSideRoughMilling_E)) ?
     (pocket_depth - ISO14649_ALLOW) : pocket_depth);
  CHK((mill_depth <= 0), POCKET_DEPTH_MUST_BE_POSITIVE);
  side =
    (the_cut->get_allowanceSide() ?
     the_cut->get_allowanceSide()->get_val() :
     (the_cut->isA(bottomAndSideRoughMilling_E)) ?
     ISO14649_ALLOW : 0.0);
  mill_length = (pocket_length - (2 * side));
  mill_width  = (pocket_width  - (2 * side));
  extra_length = (mill_length - tool_diameter);
  extra_width  = (mill_width  - tool_diameter);
  pass_depth = (the_cut->get_axialCuttingDepth() ?
		the_cut->get_axialCuttingDepth()->get_val() :
		(tool_diameter / 2.0));
  CHK((extra_width < -(ISO14649_TINY)), POCKET_MUST_NOT_BE_NARROWER_THAN_TOOL);
  IFF(find_retract_z(0, the_cut->get_retractPlane(), ISO14649_UP, &retract));
  if (extra_width < ISO14649_TINY)
    {
      if (extra_length < ISO14649_TINY)
	IFF(plunge_pocket(mill_depth, retract, code, lines));
      else
	IFF(cut_straight(mill_length, mill_depth, retract, pass_depth,
			 the_cut->get_approach(), the_cut->get_retract(),
			 tool_diameter, code, lines));
    }
  else
    IFF(mill_rectangular_pocket_regular
	(mill_length, mill_width, mill_depth, (pocket_radius - side),
	 retract, pass_depth, stepover, the_cut->get_approach(),
	 the_cut->get_retract(), the_cut->get_itsMachiningStrategy(),
	 tool_diameter, code, lines));
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_rectangular_pocket_regular

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The milling strategy is not contourParallel:
      CAN_HANDLE_ONLY_CONTOUR_PARALLEL_MILLING_STRATEGY.
   2. The approach strategy is not a subtype of plungeStrategy:
      CAN_HANDLE_ONLY_PLUNGE_APPROACH.
   3. The retract strategy is not plungeToolaxis:
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT.
   4. The combination of path direction and cutmode would require cutting
      outside in (rather then inside out): CANNOT_HANDLE_OUTSIDE_IN_CUTTING.
   5. find_pocket_plunge_start returns an error code.
   6. write_feed returns an error code.
   7. enter_pocket_pass returns an error code.
   8. mill_circular_pocket returns an error code.
   9. mill_semicircle_end_pocket returns an error code.
  10. mill_regular_pocket returns an error code.
  11. write_traverse returns an error code.

Side Effects: See below

Called By: mill_rectangular_pocket

This generates code to mill a rectangular pocket.

This is assuming a right-handed tool is being used.

It would be helpful if the inside_strategy included a reduced feed for
slotting, which occurs intermittently during rough milling (on
stepovers and during entry, for example). This is cutting the feed
rate in half for for slotting (which may not be necessary during
finish milling but should not be harmful).

All entry strategies result in the tool tip getting to (end2, 0).

*/

static int mill_rectangular_pocket_regular( /* ARGUMENTS                   */
 double length,                             /* length of pocket to make    */
 double width,                              /* width of pocket to make     */
 double depth,                              /* depth of pocket to make     */
 double radius,                             /* corner radius of p. to make */
 double retract,                            /* amount by which to retract  */
 double pass_depth,                         /* vertical pass depth         */
 double stepover,                           /* horizontal stepover         */
 approachRetractStrategy * enter,           /* approach strategy to use    */
 approachRetractStrategy * leave,           /* retract strategy to use     */
 two5DmillingStrategy * inside_strategy,    /* milling strategy to use     */
 double tool_diameter,                      /* diameter of endmill         */
 double code[][7],                          /* code array to write in      */
 int * lines)                               /* code array index            */
{
  static char name[] = "mill_rectangular_pocket_regular";
  contourParallel * inside;
  int spiral;              // 1=ccw,          -1=cw
  int mode;                // 1=conventional, -1=climb
  double end1;             // X coordinate of +X end of centerline
  double end2;             // X coordinate of -X end of centerline
  int passes;              // number of vertical passes to make
  double start_x;          // X coordinate of start point of plunge
  double start_y;          // Y coordinate of start point of plunge
  double z_now;            // current Z coordinate
  plungeStrategy * entry;  // plunge entry strategy
  int n;                   // counter for vertical passes
  double aux;              // offset_x or turns

  CHK((NOT(inside_strategy->isA(contourParallel_E))),
      CAN_HANDLE_ONLY_CONTOUR_PARALLEL_MILLING_STRATEGY);
  CHK((NOT(enter->isA(plungeStrategy_E))),
      CAN_HANDLE_ONLY_PLUNGE_APPROACH);
  CHK((NOT(leave->isA(plungeToolaxis_E))),
      CAN_HANDLE_ONLY_PLUNGE_TOOLAXIS_RETRACT);
  entry = dynamic_cast<plungeStrategy *>(enter);
  inside = dynamic_cast<contourParallel *>(inside_strategy);
  if (inside->get_rotationDirection()->isA(rotDirectionCw_E))
    {
      CHK((inside->get_cutmode()->isA(cutmodeTypeClimb_E)),
	  CANNOT_HANDLE_OUTSIDE_IN_CUTTING);
      spiral = -1;
      mode = 1;
    }
  else if (inside->get_rotationDirection()->isA(rotDirectionCcw_E))
    {
      CHK((inside->get_cutmode()->isA(cutmodeTypeConventional_E)),
	  CANNOT_HANDLE_OUTSIDE_IN_CUTTING);
      spiral = 1;
      mode = -1;
    }
  else // if (inside->get_rotationDirection() == 0)
    {
      if (inside->get_cutmode()->isA(cutmodeTypeClimb_E))
	{
	  spiral = 1;
	  mode = -1;
	}
      else
	{
	  spiral = -1;
	  mode = 1;
	}
    }
  passes = (1 + (int)((depth - ISO14649_TINY) / pass_depth));
  pass_depth = (depth / passes);
  end1 = ((length - width) / 2.0);
  end2 = -end1;
  z_now = -pass_depth;
  IFF(find_pocket_plunge_start
      ((length - tool_diameter), (width - tool_diameter),
       (retract + pass_depth), entry, &start_x, &start_y, &aux));
  IFF(write_feed(start_x, start_y, retract, code, lines)); // first point
  IFF(enter_pocket_pass(entry, start_x, start_y, retract,
			end2, z_now, aux, code, lines));
  if ((width - (2 * radius)) < ISO14649_TINY)
    {
      if ((end1 - end2) < ISO14649_TINY)
	IFF(mill_circular_pocket(length, z_now, stepover, tool_diameter,
				 spiral, code, lines));
      else
	IFF(mill_semicircle_end_pocket(length, width, z_now, stepover,
				       tool_diameter, spiral, code, lines));
    }
  else
    IFF(mill_regular_pocket(length, width, radius, z_now, stepover,
			    tool_diameter, spiral, code, lines));
  if (passes > 1)
    IFF(find_pocket_plunge_start
	((length - tool_diameter), (width - tool_diameter), pass_depth, 
	 entry, &start_x, &start_y, &aux));
  for (n = 1; n < passes; n++)
    {
      IFF(write_feed(code[*lines - 1][1], code[*lines - 1][2],
		     (z_now + pass_depth), code, lines));
      IFF(write_traverse(start_x, start_y, (z_now + pass_depth),
			     code, lines));
      IFF(write_feed(start_x, start_y, z_now, code, lines));
      z_now = (z_now - pass_depth);
      IFF(enter_pocket_pass(entry, start_x, start_y, (z_now + pass_depth),
			    end2, z_now, aux, code, lines));
      if ((width - (2 * radius)) < ISO14649_TINY)
	{
	  if ((end1 - end2) < ISO14649_TINY)
	    IFF(mill_circular_pocket(length, z_now, stepover, tool_diameter,
				     spiral, code, lines));
	  else
	    IFF(mill_semicircle_end_pocket(length, width, z_now, stepover,
					  tool_diameter, spiral, code, lines));
	}
      else
	IFF(mill_regular_pocket(length, width, radius, z_now, stepover,
				tool_diameter, spiral, code, lines));
    }
  if (leave->isA(plungeToolaxis_E))
    IFF(write_feed(code[*lines - 1][1], code[*lines - 1][2],
		   retract, code, lines));
  else; // currently cannot happen because of check above

  return ISO14649_OK;
}

/***********************************************************************/

/* mill_regular_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. write_arc returns an error code.

Side Effects:  The code array is written into, and the lines index is
   increased.

Called By: mill_rectangular_pocket_regular

The entry routine is expected to have left the tool tip at
X=(length - width)/-2.0, Y=0, Z=Z_now, which is at one end of
the (Voronoi) centerline of the pocket.

Center_offset is the offset along X or Y (they are the same) of the
center of the corner arc from the end of the centerline. This is
((width / 2.0) - corner_radius). Radius_now is set initially to minus
center_offset.  Offset_now is set initially to zero.

When spiral is 1, this cuts straight towards +X to the other end of
the centerline (X=end1) and then does the following repeatedly.
1. increase offset_now and radius_now by one stepover
2. cut straight towards +X to X = (end1 + offset_now); distance is one stepover
3. While corner arcs are not needed (radius_now is not positive):
  a. cut straight towards +Y to Y = offset_now
  b. cut straight towards -X to X = (end2 - offset_now)
  c. cut straight towards -Y to Y = -offset_now
  d. cut straight towards +X to X = (end1 + offset_now)
  e. cut straight towards +Y to Y = 0

3. When corner arcs are needed (radius_now is positive):
  a. cut straight towards +Y to Y = center_offset
  b. cut a quarter circle counterclockwise using (end1, 0) as center
  c. cut cut straight towards -X to X = (end2 - center_offset)
  d. cut a quarter circle counterclockwise using (end2, 0) as center
  e. cut straight towards -Y to Y = -center_offset
  f. cut a quarter circle counterclockwise using (end2, 0) as center
  g. cut straight towards +X to X = (end1 + center_offset)
  h. cut a quarter circle counterclockwise using (end1, 0) as center
  i. cut straight towards +Y to Y = 0

When spiral is -1, the direction of path rotation is switched to clockwise
by reversing the sign of all Y values and the direction of arcs.

It would be good to reduce the feedrate for the initial cut, since that
is slotting.

*/
static int mill_regular_pocket( /* ARGUMENTS                        */
 double length,                 /* length of pocket                 */
 double width,                  /* width of pocket                  */
 double radius,                 /* corner radius of pocket          */
 double z_now,                  /* Z coordinate at cutting depth    */
 double stepover,               /* horizontal stepover              */
 double tool_diameter,          /* diameter of tool                 */
 int spiral,                    /* 1=counterclockwise, -1=clockwise */
 double code[][7],              /* code array to write in           */
 int * lines)                   /* code array index                 */
{
  static char name[] = "mill_regular_pocket";
  double total;         // total of all stepovers
  double radius_now;    // radius of current arc
  double offset_now;    // current sum of stepovers
  double end1;          // +X end of centerline
  double end2;          // -X end of centerline
  double center_offset; // X or Y offset of arc center from end1
  int passes;           // number of stepovers
  int n;                // pass index

  total = ((width - tool_diameter) / 2.0);
  passes = (1 + (int)((total - ISO14649_TINY) / stepover));
  stepover = (total / passes);
  end1 = ((length - width) / 2.0);
  end2 = -end1;
  center_offset = ((width / 2.0) - radius);
  radius_now = -center_offset;
  offset_now = 0;
  IFF(write_feed(end1, 0, z_now, code, lines));
  for (n = 0; n < passes; n++)
    {
      radius_now = (radius_now + stepover);
      offset_now = (offset_now + stepover);
      IFF(write_feed((end1 + offset_now), 0, z_now, code, lines));
      if (radius_now < ISO14649_TINY)
	{
	  IFF(write_feed((end1+offset_now), (offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_feed((end2-offset_now), (offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_feed((end2-offset_now), (-offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_feed((end1+offset_now), (-offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_feed((end1+offset_now), 0, z_now, code, lines));
	}
      else
	{
	  IFF(write_feed((end1 + offset_now), (center_offset * spiral),
			 z_now, code, lines));
	  IFF(write_arc((end1 + center_offset), (offset_now * spiral),
			(end1 + center_offset), (center_offset * spiral),
			spiral, z_now, code, lines));
	  IFF(write_feed((end2 - center_offset), (offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_arc((end2 - offset_now), (center_offset * spiral),
			(end2 - center_offset), (center_offset * spiral),
			spiral, z_now, code, lines));
	  IFF(write_feed((end2 - offset_now), (-center_offset * spiral),
			 z_now, code, lines));
	  IFF(write_arc((end2 - center_offset), (-offset_now * spiral),
			(end2 - center_offset), (-center_offset * spiral),
			spiral, z_now, code, lines));
	  IFF(write_feed((end1 + center_offset), (-offset_now * spiral),
			 z_now, code, lines));
	  IFF(write_arc((end1 + offset_now), (-center_offset * spiral),
			(end1 + center_offset), (-center_offset * spiral),
			spiral, z_now, code, lines));
	  IFF(write_feed((end1 + offset_now), 0, z_now, code, lines));
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* mill_semicircle_end_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.
   2. write_arc returns an error code.

Side Effects:  the code array is written into, and the lines index is
   increased.

Called By: mill_rectangular_pocket_regular

The entry routine is expected to have left the tool tip at
X=(length - width)/-2.0, Y=0, Z=Z_now, which is at one end of
the (Voronoi) centerline of the pocket.

When spiral is 1, this cuts straight towards +X to the other end of the
centerline (X=end1) and then does the following repeatedly:
1. cut straight towards +X to X = (end1 + radius_now); distance is one stepover
2. cut a quarter circle counterclockwise using (end1, 0) as center
3. cut straight towards -X to X = end2
4. cut a semicircle counterclockwise using (end2, 0) as center
5. cut straight towards -X to X = end1
6. cut a quarter circle counterclockwise using (end1, 0) as center

When spiral is -1, the direction of path rotation is switched to clockwise
by reversing the sign of all Y values and the direction of arcs.

It would be good to reduce the feedrate for the initial cut, since that
is slotting.

*/

static int mill_semicircle_end_pocket( /* ARGUMENTS                        */
 double length,                        /* length of pocket                 */
 double width,                         /* width of pocket                  */
 double z_now,                         /* Z coordinate at cutting depth    */
 double stepover,                      /* horizontal stepover              */
 double tool_diameter,                 /* diameter of tool                 */
 int spiral,                           /* 1=counterclockwise, -1=clockwise */
 double code[][7],                     /* code array to write in           */
 int * lines)                          /* code array index                 */
{
  static char name[] = "mill_semicircle_end_pocket";
  double total;      // total of all stepovers
  double radius_now; // radius of current arc
  double end1;       // +X end of centerline
  double end2;       // -X end of centerline
  int passes;        // number of stepovers
  int n;             // pass index

  total = ((width - tool_diameter) / 2.0);
  passes = (1 + (int)((total - ISO14649_TINY) / stepover));
  stepover = (total / passes);
  end1 = ((length - width) / 2.0);
  end2 = -end1;
  radius_now = 0;
  IFF(write_feed(end1, 0, z_now, code, lines));
  for (n = 0; n < passes; n++)
    {
      radius_now = (radius_now + stepover);
      IFF(write_feed((end1 + radius_now), 0, z_now, code, lines));
      IFF(write_arc(end1, (radius_now * spiral), end1, 0, spiral,
		    z_now, code, lines));
      IFF(write_feed(end2, (radius_now * spiral), z_now, code, lines));
      IFF(write_arc(end2, (-radius_now * spiral), end2, 0, spiral,
		    z_now, code, lines));
      IFF(write_feed(end1, (-radius_now * spiral), z_now, code, lines));
      IFF(write_arc((end1 + radius_now), 0, end1, 0, spiral,
		    z_now, code, lines));
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* op_center_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_center_drilling returns an error code.
   2. check_tool_center_drill returns an error code.
   3. check_horizontal_plane returns an error code.
   4. find_retract_z returns an error code.
   5. The center drilling depth is more than the flute length of the center
      drill: CENTER_DRILLING_DEPTH_MUST_NOT_EXCEED_CENTER_DRILL_FLUTE_LENGTH.
   6. start_cut returns an error code.

Side Effects: See below

Called By: cut_feature

This centerDrillings the given feature. Any type of feature may be
centerDrillinged.

The sequence of actions (and calculations) is:

1. Rapid vertical up to current security_z if not retracted.
2. Rapid horizontal to X=0, Y=0 in the coordinate system of the feature.
   Note that any kind of feature can be centerDrillinged.
3. Rapid vertical down to retract_z.
4. Cut vertically down to (top_of_feature - cutting_depth).
5. If there is a dwell time, dwell for that amount of time.
6. Reset feed if the retract feed differs from the current feed.
7. Retract vertically up to the retract_z.
8. Update current location and feed.

cut_feature has already checked that neither argument is NULL, so that
is not rechecked here.

C++ data for centerDrilling
---------------------------
toolpathList *         itsToolpath;          [opt] (operation)
toolDirection *        itsToolDirection;     [opt]
char *                 itsId;                      (machiningOperation)
real *                 retractPlane;         [opt]
cartesianPoint *       startPoint;           [opt]
machiningTool *        itsTool;
technology *           itsTechnology;
machineFunctions *     itsMachineFunctions;
real *                 overcutLength;        [opt] (millingMachiningOperation)
real *                 cuttingDepth;         [opt] (drillingTypeOperation)
real *                 previousDiameter;     [opt]
real *                 dwellTimeBottom;      [opt]
real *                 feedOnRetract;        [opt]
drillingTypeStrategy * itsMachiningStrategy; [opt]
<no attributes>                                    (drillingOperation)
<no attributes>                                    (centerDrilling)

itsToolpath is used only if the operation is a freeformOperation; it is not
   used here.
itsToolDirection (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retractPlane is the Z-coordinate of the retract plane in the feature
   coordinate system.
startPoint is ignored. The spec (Part 10, sec 4.7.2) allows this.
itsTool is handled before this function is called.
technology is handled before this function is called.
itsMachineFunctions is handled before this function is called.
overcutLength is required (in check_op_center_drilling, not in the spec)
   to be NULL.
cuttingDepth here (not in the spec) must be given, must be positive,
   and must be less than the feature depth.
previousDiameter is ignored; it is for information only.
dwellTimeBottom is used as the time in seconds for which the tool dwells
   at the bottom of the hole.
feedOnRetract is used
itsMachiningStrategy is required here (not in the spec) to be NULL.

If the optional retractPlane is given, retract_z is set to that amount
above the top of the hole.  If not, retract_z is set to ISO14649_UP
millimeters above the top of the hole.

*/

static int op_center_drilling(          /* ARGUMENTS                      */
 machiningFeature * the_feature,        /* feature to center drill        */
 centerDrilling * the_center_drilling)  /* center drilling op to perform  */
{
  static char name[] = "op_center_drilling";
  elementarySurface * depth_plane; // plane that is depth of hole
  double feat_x;                   // in setup c_sys
  double feat_y;                   // in setup c_sys
  double feat_z;                   // in setup c_sys
  double retract_z;                // in setup c_sys
  double feedrate;
  double flute_length;

  depth_plane = the_feature->get_depth();
  IFF(check_horizontal_plane(depth_plane));
  feat_x = getPtX(&(_world.feature_place));
  feat_y = getPtY(&(_world.feature_place));
  feat_z = getPtZ(&(_world.feature_place));
  IFF(check_op_center_drilling(the_center_drilling, depth_plane));
  IFF(check_tool_center_drill(the_center_drilling->get_itsTool(),
			      &flute_length));
  CHK((the_center_drilling->get_cuttingDepth()->get_val() > flute_length),
      CENTER_DRILLING_DEPTH_MUST_NOT_EXCEED_CENTER_DRILL_FLUTE_LENGTH);
  IFF(find_retract_z(feat_z, the_center_drilling->get_retractPlane(),
		     ISO14649_UP, &retract_z));
  IFF(start_cut(feat_x, feat_y, retract_z));
  STRAIGHT_FEED(feat_x, feat_y,
		(feat_z - the_center_drilling->get_cuttingDepth()->get_val()));
  if ((the_center_drilling->get_feedOnRetract() != 0) &&
      (the_center_drilling->get_feedOnRetract()->get_val() != 1.0))
    {
      feedrate =
	(the_center_drilling->get_feedOnRetract()->get_val() * _world.feedrate);
      SET_FEED_RATE(feedrate);
      _world.feedrate = feedrate;      
    }
  if (the_center_drilling->get_dwellTimeBottom() != 0)
    DWELL(the_center_drilling->get_dwellTimeBottom()->get_val());
  STRAIGHT_FEED(feat_x, feat_y, retract_z);
  _world.current_x = feat_x;
  _world.current_y = feat_y;
  _world.current_z = retract_z;

  return ISO14649_OK;
}

/***********************************************************************/

/* op_counter_boring

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_cbore_hole is NULL: FEATURE_MUST_NOT_BE_NULL.
   2. the_boring is NULL: OPERATION_MUST_NOT_BE_NULL.
   3. the_boring is not one of the operations belonging to the_cbore_hole:
      OPERATION_MUST_BELONG_TO_FEATURE.
   4. init_place returns an error code.
   5. check_counterbore_hole returns an error code.
   6. check_op_counter_boring returns an error code.
   7. check_tool_counterbore returns an error code.
   8. find_location returns an error code.
   9. find_retract_z returns an error code.
  10. handle_machine_functions returns an error code.
  11. handle_technology returns an error code.
  12. start_cut returns an error code.

Side Effects: See below

Called By: execute_machining

This is an operation on a compoundFeature. The counterboreHole should
have this operation in its list of operations. The upper hole of the
counterboreHole should also have this operation in its list of
operations.

If the boring operation is applied to a counterbore hole, it is
considered to be a counterboring operation (a plunge with an endmill
to enlarge an existing hole, but not the full depth of the existing
hole).  The counterboring operation forms the geometry of the upper
hole. The diameters of the hole and tool must match, and if the
cutting depth is given, it must be the correct value for making the
upper hole to its full depth.

There are more coordinate systems to deal with in a counterboreHole
than with other feature types, since the holes are placed in terms of
the coordinate system of the feature. The two component holes must
be co-axial and their Z-axes must be (0, 0, 1). This helps. The origins
of the holes are not required to be anywhere in particular, except that
the coaxial and mating requirements must be satisfied. The find_location
function is used to deal with the coordinate systems.

This is not checking that the lower hole of a counterbore hole is made
before the upper hole, but that is a requirement. The plunge movement
of counterboring may be a disaster (broken tool, melted material, etc.)
if the lower hole does not already exist.

C++ data for boring
-------------------
toolpathList *         itsToolpath;          [opt] (operation)
toolDirection *        itsToolDirection;     [opt]
char *                 itsId;                      (machiningOperation)
real *                 retractPlane;         [opt]
cartesianPoint *       startPoint;           [opt]
machiningTool *        itsTool;
technology *           itsTechnology;
machineFunctions *     itsMachineFunctions;
real *                 overcutLength;        [opt] (millingMachiningOperation)
real *                 cuttingDepth;         [opt] (drillingTypeOperation)
real *                 previousDiameter;     [opt]
real *                 dwellTimeBottom;      [opt]
real *                 feedOnRetract;        [opt]
drillingTypeStrategy * itsMachiningStrategy; [opt]
boolean *              spindleStopAtBottom;        (boringOperation)
real *                 depthOfTestcut;       [opt]
cartesianPoint *       waitingPosition;      [opt]
<no attributes>                                    (boring)

itsToolpath is used only if the operation is a freeformOperation; it is not
   used here.
itsToolDirection (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retractPlane is the Z-coordinate of the retract plane in the
   coordinate system of the upper hole (not of the counterboreHole).
startPoint is ignored. The spec (Part 10, sec 4.7.2) allows this.
itsTool is handled before this function is called.
technology is handled before this function is called.
itsMachineFunctions is handled before this function is called.
overcutLength is required (in check_op_counter_boring, not in the spec)
   to be NULL.
cuttingDepth, if given, must be the depth required to make the upper
   hole of the counterbore hole. It is assumed that for counterboring
   (like center drilling - see description of cutting depth for
    drilling_type_operation, sec. 4.2.12, p 25) cutting depth is
   measured from the lowest point of the cutting tip to the highest
   part of the hole.
previousDiameter must be the diameter of the lower hole. It is not
   used for anything, but the hope is that having to provide a value
   will remind the program author to make the lower hole first.
dwellTimeBottom is used as the time in seconds for which the tool dwells
   at the bottom of the hole.
feedOnRetract is used
itsMachiningStrategy is required (in check_op_counter_boring) to be NULL.
   The strategy data could be used, however, so it might be used in
   future versions. It would be unusual but not unthinkable to use strategy
   data for counterboring.

If the optional retractPlane is given, retract_z is set to that
amount above the origin of the coordinate system of upper_hole.  If not,
retract_z is set to ISO14649_UP millimeters above the top of upper_hole.

The sequence of actions is:

1. Rapid vertical up to current security_z if not retracted.
2. Rapid horizontal to above the center of the hole.
3. Rapid vertical down to retract_z.
4. Cut vertically down to (top_of_hole - cutting_depth).
5. If there is a dwell time, dwell for that amount of time.
6. Reset feed if the retract feed differs from the current feed.
7. Retract vertically up to the retract_z.
8. Update current location and feed.


*/

static int op_counter_boring(      /* ARGUMENTS                   */
 counterboreHole * the_cbore_hole, /* counterboreHole to bore     */
 millingMachineFunctions * funcs,  /* milling machine functions   */
 millingTechnology * tech,         /* milling technology          */
 boring * the_boring)              /* counterboring op to perform */
{
  static char name[] = "op_counter_boring";
  roundHole * upper_hole;  // hole to cbore, found in check_cbore_hole
  double cut_depth;
  double retract_z;        // in setup c_sys
  double cbore_x;          // in setup c_sys
  double cbore_y;          // in setup c_sys
  double cbore_z;          // in setup c_sys
  axis2placement3d cbore_place;
  std::list<machiningOperation *> * feature_ops;
  std::list<machiningOperation *>::iterator iter;
  double feedrate;
  double lower_diameter;
  
  CHK((the_cbore_hole == 0), FEATURE_MUST_NOT_BE_NULL);
  CHK((the_boring == 0), OPERATION_MUST_NOT_BE_NULL);
  feature_ops = the_cbore_hole->get_itsOperations()->get_theList();
  for (iter = feature_ops->begin(); iter != feature_ops->end(); ++iter)
    {
      if (the_boring == *iter)
	break;
    }
  CHK((iter == feature_ops->end()),
      OPERATION_MUST_BELONG_TO_FEATURE);
  IFF(init_place(&cbore_place));
  cut_depth = the_boring->get_cuttingDepth()->get_val();
  IFF(check_counterbore_hole(the_cbore_hole, &upper_hole, &lower_diameter));
  IFF(check_op_counter_boring(upper_hole, the_boring, lower_diameter));
  IFF(check_tool_counterbore(the_boring->get_itsTool(),
			     upper_hole, &cut_depth));
  IFF(find_location(&(_world.feature_place),
		    upper_hole->get_featurePlacement(), &cbore_place));
  cbore_x = getPtX(&cbore_place);
  cbore_y = getPtY(&cbore_place);
  cbore_z = getPtZ(&cbore_place);
  IFF(find_retract_z(cbore_z, the_boring->get_retractPlane(),
		     ISO14649_UP, &retract_z));
  IFF(handle_machine_functions(funcs));
  IFF(handle_technology(tech, the_boring->get_itsTool()));
  IFF(start_cut(cbore_x, cbore_y, retract_z));
  STRAIGHT_FEED(cbore_x, cbore_y, (cbore_z - cut_depth));
  if ((the_boring->get_feedOnRetract() != 0) &&
      (the_boring->get_feedOnRetract()->get_val() != 1.0))
    {
      feedrate = (the_boring->get_feedOnRetract()->get_val() * _world.feedrate);
      SET_FEED_RATE(feedrate);
      _world.feedrate = feedrate;      
    }
  if (the_boring->get_dwellTimeBottom() != 0)
    DWELL(the_boring->get_dwellTimeBottom()->get_val());
  STRAIGHT_FEED(cbore_x, cbore_y, retract_z);
  _world.current_x = cbore_x;
  _world.current_y = cbore_y;
  _world.current_z = retract_z;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_counter_sinking

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. the_csunk_hole is NULL: FEATURE_MUST_NOT_BE_NULL.
   2. the_sinking is NULL: OPERATION_MUST_NOT_BE_NULL.
   3. the_sinking is not one of the operations belonging to the_csunk_hole:
      OPERATION_MUST_BELONG_TO_FEATURE.
   4. init_place returns an error code.
   5. check_countersunk_hole returns an error code.
   6. check_op_counter_sinking returns an error code.
   7. check_tool_countersink returns an error code.
   8. find_location returns an error code.
   9. find_retract_z returns an error code.
  10. handle_machine_functions returns an error code.
  11. handle_technology returns an error code.
  12. start_cut returns an error code.

Side Effects: See below

Called By: execute_machining

This is an operation on a compoundFeature. The countersunkHole should
have this operation in its list of operations. The upper hole of the
countersunkHole should also have this operation in its list of
operations.

Unlike the other subtypes of drilling, this is allowing only countersunk
holes to have the counterSinking operation applied to them, and only in
such a way as to form the geometry of the upper hole. In particular, the
taper angles of the hole and tool must match, and if the cutting depth
is given, it must be the correct value for making the upper diameter.

There are more coordinate systems to deal with in a countersunkHole
than with other feature types, since the holes are placed in terms of
the coordinate system of the feature. The two component holes must
be co-axial and their Z-axes must be (0, 0, 1). This helps. The origins
of the holes are not required to be anywhere in particular, except that
the coaxial and mating requirements must be satisfied. The find_location
function is used to deal with the coordinate systems.

This is not requiring the lower hole of a countersunk hole be made before
the upper hole.

C++ data for counterSinking
---------------------------
toolpathList *         itsToolpath;          [opt] (operation)
toolDirection *        itsToolDirection;     [opt]
char *                 itsId;                      (machiningOperation)
real *                 retractPlane;         [opt]
cartesianPoint *       startPoint;           [opt]
machiningTool *        itsTool;
technology *           itsTechnology;
machineFunctions *     itsMachineFunctions;
real *                 overcutLength;        [opt] (millingMachiningOperation)
real *                 cuttingDepth;         [opt] (drillingTypeOperation)
real *                 previousDiameter;     [opt]
real *                 dwellTimeBottom;      [opt]
real *                 feedOnRetract;        [opt]
drillingTypeStrategy * itsMachiningStrategy; [opt]
<no attributes>                                    (drillingOperation)
<no attributes>                                    (counterSinking)

itsToolpath is used only if the operation is a freeformOperation; it is not
   used here.
itsToolDirection (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retractPlane is the Z-coordinate of the retract plane in the
   coordinate system of the upper hole (not of the countersunkHole).
startPoint is ignored. The spec (Part 10, sec 4.7.2) allows this.
itsTool is handled before this function is called.
technology is handled before this function is called.
itsMachineFunctions is handled before this function is called.
overcutLength is required (in check_op_counter_sinking, not in the spec)
   to be NULL.
cuttingDepth, if given, must be the depth required to make the upper
   hole of the countersunk hole. It is assumed that for countersinking
   (like center drilling - see description of cutting depth for
    drilling_type_operation, sec. 4.2.12, p 25) cutting depth is
   measured from the lowest point of the cutting tip to the highest
   part of the hole.
previousDiameter is ignored; it is for information only.
dwellTimeBottom is used as the time in seconds for which the tool dwells
   at the bottom of the hole.
feedOnRetract is used
itsMachiningStrategy is required (in check_op_counter_sinking) to be NULL.
   The strategy data could be used, however, so it might be used in
   future versions. It would be unusual but not unthinkable to use strategy
   data for countersinking.

If the optional retractPlane is given, retract_z is set to that
amount above the origin of the coordinate system of upper_hole.  If not,
retract_z is set to ISO14649_UP millimeters above the top of upper_hole.

The sequence of actions is:

1. Rapid vertical up to current security_z if not retracted.
2. Rapid horizontal to above the center of the hole.
3. Rapid vertical down to retract_z.
4. Cut vertically down to (top_of_hole - cutting_depth).
5. If there is a dwell time, dwell for that amount of time.
6. Reset feed if the retract feed differs from the current feed.
7. Retract vertically up to the retract_z.
8. Update current location and feed.


*/

static int op_counter_sinking(      /* ARGUMENTS                      */
 countersunkHole * the_csunk_hole,  /* countersunkHole to countersink */
 millingMachineFunctions * funcs,   /* milling machine functions      */
 millingTechnology * tech,          /* milling technology             */
 counterSinking * the_sinking)      /* countersinking op to perform   */
{
  static char name[] = "op_counter_sinking";
  roundHole * upper_hole;  /* hole to csink, found in check_csunk_hole */
  double cut_depth;
  double retract_z;     // in setup c_sys
  double csink_x;       // in setup c_sys
  double csink_y;       // in setup c_sys
  double csink_z;       // in setup c_sys
  axis2placement3d csink_place;
  std::list<machiningOperation *> * feature_ops;
  std::list<machiningOperation *>::iterator iter;
  double feedrate;
  double upper_hole_angle; // angle from bottom to side
  
  CHK((the_csunk_hole == 0), FEATURE_MUST_NOT_BE_NULL);
  CHK((the_sinking == 0), OPERATION_MUST_NOT_BE_NULL);
  feature_ops = the_csunk_hole->get_itsOperations()->get_theList();
  for (iter = feature_ops->begin(); iter != feature_ops->end(); ++iter)
    {
      if (the_sinking == *iter)
	break;
    }
  CHK((iter == feature_ops->end()),
      OPERATION_MUST_BELONG_TO_FEATURE);
  IFF(init_place(&csink_place));
  cut_depth = the_sinking->get_cuttingDepth()->get_val();
  IFF(check_countersunk_hole(the_csunk_hole, &upper_hole_angle, &upper_hole));
  IFF(check_op_counter_sinking(upper_hole, the_sinking));
  IFF(check_tool_countersink(the_sinking->get_itsTool(), upper_hole, &cut_depth,
			     upper_hole_angle));
  IFF(find_location(&(_world.feature_place),
		    upper_hole->get_featurePlacement(), &csink_place));
  csink_x = getPtX(&csink_place);
  csink_y = getPtY(&csink_place);
  csink_z = getPtZ(&csink_place);
  IFF(find_retract_z(csink_z, the_sinking->get_retractPlane(),
		     ISO14649_UP, &retract_z));
  IFF(handle_machine_functions(funcs));
  IFF(handle_technology(tech, the_sinking->get_itsTool()));
  IFF(start_cut(csink_x, csink_y, retract_z));
  STRAIGHT_FEED(csink_x, csink_y, (csink_z - cut_depth));
  if ((the_sinking->get_feedOnRetract() != 0) &&
      (the_sinking->get_feedOnRetract()->get_val() != 1.0))
    {
      feedrate =
	(the_sinking->get_feedOnRetract()->get_val() * _world.feedrate);
      SET_FEED_RATE(feedrate);
      _world.feedrate = feedrate;      
    }
  if (the_sinking->get_dwellTimeBottom() != 0)
    DWELL(the_sinking->get_dwellTimeBottom()->get_val());
  STRAIGHT_FEED(csink_x, csink_y, retract_z);
  _world.current_x = csink_x;
  _world.current_y = csink_y;
  _world.current_z = retract_z;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_drilling return an error code.
   2. check_tool_drill return an error code.
   3. find_drill_tip_length returns an error code.
   4. find_cutting_depths returns an error code.
   5. find_retract_z returns an error code.
   6. handle_machine_functions returns an error code.
   7. handle_technology_some returns an error code.
   8. start_cut returns an error code.
   9. handle_speed returns an error code.
  10. handle_feed returns an error code.

Side Effects: See below

Called By: cut_feature

cut_feature has already checked that neither argument is NULL, so that
is not rechecked here.

See documentation of find_cutting_depths for how depth, depth1, and
depth2 are set. If depth1 or depth2 is set to ISO14649_BAD_REAL, that is
regarded as not being set at all. After these depths are found, the
sequence of actions (and calculations) is:

1. rapid vertical up to current security_z if not retracted.
2. rapid horizontal to X=0, Y=0 in the coordinate system of the feature.
   Note that any kind of feature can be drilled.
3. rapid vertical down to retract_z.
4. If depth1 is set, call handle_speed and handle_feed with the factors
   for starting the cut, and cut vertically down to depth1.
5. Call handle_speed and handle_feed with NULL factors.
6. If depth2 is set
    a. Cut vertically down to depth2.
    b. Call handle_speed and handle_feed with the factors for finishing
       the cut.
7. Cut vertically down to depth.
8. If there is a dwell time, dwell for that amount of time.
9. Call handle_speed and handle_feed with the factors for retracting.
10. Retract vertically up to retract_z.
11. Update current location.

C++ data for drilling
---------------------
toolpathList *         itsToolpath;          [opt] (operation)
toolDirection *        itsToolDirection;     [opt]
char *                 itsId;                      (machiningOperation)
real *                 retractPlane;         [opt]
cartesianPoint *       startPoint;           [opt]
machiningTool *        itsTool;
technology *           itsTechnology;
machineFunctions *     itsMachineFunctions;
real *                 overcutLength;        [opt] (millingMachiningOperation)
real *                 cuttingDepth;         [opt] (drillingTypeOperation)
real *                 previousDiameter;     [opt]
real *                 dwellTimeBottom;      [opt]
real *                 feedOnRetract;        [opt]
drillingTypeStrategy * itsMachiningStrategy; [opt]
<no attributes>                                    (drillingOperation)
<no attributes>                                    (drilling)

itsToolDirection (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
itsId is ignored.
retractPlane is the Z-coordinate of the retract plane in the feature
   coordinate system.
startPoint is ignored. The spec (Part 10, sec 4.7.2) allows this.
itsTool is handled before this function is called.
itsTechnology is handled by calling handle_technology_some and calling
   handle_speed and handle_feed.
itsMachineFunctions is handled before this function is called.
overcutLength is for through features (Part 11, sec 4.2.3). We are requiring
   here that if given: (1) it must be positive and (2) cuttingDepth may
   not be used.
cuttingDepth, if given, may specify drilling less or more than the hole.
   We are requiring here that it must be positive if given.
previousDiameter is ignored; it is for information only.
dwellTimeBottom, if given, is used as the time in seconds for which the
   tool dwells at the bottom of the hole.
feedOnRetract, if given, is used as a multiplier for the feed rate
   during the retract motion.

C++ data for drillingTypeStrategy
---------------------------------
real * reducedCutAtStart;   [opt] (drillingTypeStrategy)
real * reducedFeedAtStart;  [opt]
real * depthOfStart;        [opt]
real * reducedCutAtEnd;     [opt]
real * reducedFeedAtEnd;    [opt]
real * depthOfEnd;          [opt]

WHERE
WR1: EXISTS(depthOfStart) OR
     NOT (EXISTS(reducedCutAtStart) OR EXISTS(reducedFeedAtStart));
WR2: EXISTS(depthOfEnd) OR
     NOT (EXISTS(reducedcutAtEnd) OR EXISTS(reducedFeedAtEnd));

The find_cutting depths function checks the attributes of the drilling
strategy, so they are not rechecked here.

This is not resetting spindle speed prior to retracting. The spindle
speed may have been reduced at the end of the hole by the strategy.

If the optional retractPlane is given, retract_z is set to that
amount above the top of the hole.  If not, retract_z is set to one
drill tip length above the top of the hole.

The spec (Part 11, section 4.2.12.1, page 28) is ambiguous about
how reduced feed should be applied when feed per tooth is given
and reduced speed is used. It may be that the reduction is applied
to feed calculated (1) before speed was changed or (2) after the 
speed was changed. Here, since handle_speed and handle_feed are
called, the reduction is applied after the speed is changed.

This avoids changing speed and feed more than necessary by calling
handle_technology_some near the beginning to deal with the technology
items other than feed and speed, and then calling handle_speed and
handle_feed whenever feed and/or speed might change. Those functions
change feed and speed only if they differ from the current settings.

*/

static int op_drilling(           /* ARGUMENTS                         */
 machiningFeature * the_feature,  /* feature to make                   */
 millingMachineFunctions * funcs, /* milling machine functions         */
 millingTechnology * tech,        /* milling technology                */
 drilling * the_drilling)         /* drilling op to perform on feature */
{
  static char name[] = "op_drilling";
  double tip_length;    // length of tip of tool
  double feat_x;        // in setup c_sys
  double feat_y;        // in setup c_sys
  double feat_z;        // in setup c_sys
  double retract_z;     // retract z in setup c_sys
  real * feed;          // feed rate from tech
  real * feedPerTooth;  // feed per tooth from tech
  real * spindleSpeed;  // spindle speed from tech
  real * surfaceSpeed;  // surface speed from tech
  double depth;         // tip z coordinate at bottom in setup  c_sys
  double depth1;        // tip z coordinate at end of start in setup c_sys
  double depth2;        // tip z coordinate at start of end in setup c_sys
  machiningTool * tool; // the should be drill to use
  double flute_length;  // drill flute length to drill tip
  drillingTypeStrategy * strat; // drilling strategy to use, NULL OK

  feat_x = getPtX(&(_world.feature_place));
  feat_y = getPtY(&(_world.feature_place));
  feat_z = getPtZ(&(_world.feature_place));
  strat = the_drilling->get_itsMachiningStrategy();
  tool = the_drilling->get_itsTool();
  feed = tech->get_feedrate();
  feedPerTooth = tech->get_feedratePerTooth();
  spindleSpeed = tech->get_spindle();
  surfaceSpeed = tech->get_cutspeed();
  IFF(check_op_drilling(the_drilling));
  IFF(check_tool_drill(tool, &flute_length));
  IFF(find_drill_tip_length(tool, &tip_length));
  IFF(find_cutting_depths(&depth, &depth1, &depth2, flute_length, tip_length,
			  the_feature->get_depth(),
			  the_drilling->get_overcutLength(),
			  the_drilling->get_cuttingDepth(), strat));
  IFF(find_retract_z(feat_z, the_drilling->get_retractPlane(),
		     tip_length, &retract_z));
  IFF(handle_machine_functions(funcs));
  IFF(handle_technology_some(tech));
  if (depth1 != ISO14649_BAD_REAL)
    {
      IFF(handle_speed(spindleSpeed, surfaceSpeed,
		       strat->get_reducedCutAtStart(), tool));
      IFF(handle_feed(feed, feedPerTooth,
		      strat->get_reducedFeedAtStart(), tool));
    }
  IFF(start_cut(feat_x, feat_y, retract_z));
  if (depth1 != ISO14649_BAD_REAL)
    STRAIGHT_FEED(feat_x, feat_y, depth1);
  IFF(handle_speed(spindleSpeed, surfaceSpeed, 0, tool));
  IFF(handle_feed(feed, feedPerTooth, 0, tool));
  if (depth2 != ISO14649_BAD_REAL)
    {
      STRAIGHT_FEED(feat_x, feat_y, depth2);
      handle_speed(spindleSpeed, surfaceSpeed,
		   strat->get_reducedCutAtEnd(), tool);
      handle_feed(feed, feedPerTooth, strat->get_reducedFeedAtEnd(), tool);
    }
  STRAIGHT_FEED(feat_x, feat_y, depth);
  if (the_drilling->get_dwellTimeBottom() != 0)
    DWELL(the_drilling->get_dwellTimeBottom()->get_val());
  handle_feed(feed, feedPerTooth, the_drilling->get_feedOnRetract(), tool);
  STRAIGHT_FEED(feat_x, feat_y, retract_z);
  _world.current_x = feat_x;
  _world.current_y = feat_y;
  _world.current_z = retract_z;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_finish_milling_both

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_finish_both returns an error code.
   2. check_tool_endmill returns an error code.
   3. finish_mill_both_closed_pocket returns an error code.
   4. the_feature is not a closedPocket:
      CAN_HANDLE_ONLY_CLOSED_POCKET_FOR_FINISH_MILL_BOTTOM_AND_SIDE.

Side Effects: Code is generated to finish mill the sides and bottom of
   the feature, which must be a closed pocket.

Called By: cut_feature

*/

static int op_finish_milling_both(        /* ARGUMENTS                */
 machiningFeature * the_feature,          /* feature to finish mill   */
 bottomAndSideFinishMilling * the_finish) /* finish milling operation */
{
  static char name[] = "op_finish_milling_both";
  endmill * the_endmill;

  IFF(check_op_finish_both(the_finish));
  IFF(check_tool_endmill(the_finish->get_itsTool(), &the_endmill));
  if (the_feature->isA(closedPocket_E))
    IFF(finish_mill_both_closed_pocket
	(dynamic_cast<closedPocket *>(the_feature), the_finish, the_endmill));
  else
    CHK(1, CAN_HANDLE_ONLY_CLOSED_POCKET_FOR_FINISH_MILL_BOTTOM_AND_SIDE);
  return ISO14649_OK;
}

/***********************************************************************/

/* op_finish_milling_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_finish_plane returns an error code.
   2. check_tool_plane returns an error code.
   3. The_feature is not a planarFace:
      FEATURE_FOR_PLANE_MILLING_MUST_BE_PLANAR_FACE
   4. The tool is neither an endmill nor a facemill:
      TOOL_FOR_PLANE_MILLING_MUST_BE_ENDMILL_OR_FACEMILL.
   5. mill_planar returns an error code.

Side Effects: Code is generated to cut the plane face.

Called By: cut_feature

Notes:

planeMilling may be done using either a facemill or an endmill. Using a
facemill is feasible when entry from the side is possible. planeMilling
could also be done with a fly_cutter, but fly_cutter is not among the
tools provided by Part 111.

Error 4 above should never happen, since check_tool_plane checks the
same thing.

*/

static int op_finish_milling_plane( /* ARGUMENTS                */
 machiningFeature * the_feature,    /* feature to finish mill   */
 planeFinishMilling * the_finish)   /* finish milling operation */
{
  static char name[] = "op_finish_milling_plane";
  endmill * the_endmill;
  facemill * the_facemill;

  the_endmill = 0;
  the_facemill = 0;
  IFF(check_op_finish_plane(the_finish));
  IFF(check_tool_plane(the_finish->get_itsTool(), &the_endmill, &the_facemill));
  if (the_feature->isA(planarFace_E))
    {
      if (the_endmill)
	IFF(mill_planar(dynamic_cast<planarFace *>(the_feature),
			 the_finish, the_endmill));
      else if (the_facemill)
	IFF(mill_planar(dynamic_cast<planarFace *>(the_feature),
			the_finish, the_facemill));
      else
	CHK(1, TOOL_FOR_PLANE_MILLING_MUST_BE_ENDMILL_OR_FACEMILL);
    }
  else
    CHK(1, FEATURE_FOR_PLANE_MILLING_MUST_BE_PLANAR_FACE);
  return ISO14649_OK;
}

/***********************************************************************/

/* op_finish_milling_side

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. This function is called: CANNOT_HANDLE_SIDE_FINISH_MILLING

Side Effects: None

Called By: cut_feature

*/

static int op_finish_milling_side( /* ARGUMENTS                      */
 machiningFeature * the_feature,   /* feature to finish mill         */
 sideFinishMilling * the_finish)   /* finish milling operation to do */
{
  static char name[] = "op_finish_milling_side";

  CHK(1, CANNOT_HANDLE_SIDE_FINISH_MILLING);
  return ISO14649_OK;
}


/***********************************************************************/

/* op_freeform

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_freeform returns an error code.
   2. check_tool_cutting returns an error code.
   3. itsMachineFunctions is not a millingMachineFunctions:
      MACHINE_FUNCTIONS_MUST_BE_MILLING_MACHINE_FUNCTIONS.
   4. handle_machine_functions returns an error code.
   5. itsTechnology is not a millingTechnology:
      TECHNOLOGY_MUST_BE_MILLING_TECHNOLOGY.
   6. handle_technology returns an error code.
   7. op_trajectory returns an error code.
   8. A segment of the toolpath is neither a cutterLocationTrajectory nor a
      feedstop: CAN_HANDLE_ONLY_FEEDSTOP_AND_CUTTER_LOCATION_TRAJECTORY.

Side Effects: None

Called By: cut_feature

This does not attempt to verify that the given combination of tool and
toolpath makes the given feature. It also does not check whether the
tool will crash.

Each component of itsToolpath may have its own technology which
overrides that of the_freeform. This keeps track of which technology
is current. If the current technology differs from the technology to
use next (which is the technology of the next component if it has one
and the technology of the_freeform otherwise), then handle_technology
is called. A similar situation exists with itsMachineFunctions.

When this is called, it has been checked that itsTechnology is a
millingTechnology and itsMachineFunctions is a millingMachineFunctions,
so it is safe to cast them. The components are checked here.

In a freeformOperation, the data should not contain gaps between the
end of one segment of the path and the beginning of the next segment.
This is not explicit in the spec (see Part 10, section 4.8), but is
required in this interpreter. Since all segments come from a
trimmedCurve, polyline, or compositeCurve, and we are not allowing
trimming by parameter, the start point and end point of every segment
is known to be a cartesianPoint. This function checks that there are
no gaps by maintaining a pointer to a cartesianPoint which is at the
end of the last segment processed and checking that first point of the
current segment is either the same cartesianPoint or is a different
cartesianPoint that is in almost the same place (within
ISO14649_TINY).  The join point is a NULL pointer at first. When the
first segment is processed, the join point is set to the end of that
segment.

C++ data for freeformOperation
----------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions;
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract;             [opt]
freeformStrategy *        itsMachiningStrategy;[opt] (freeformOperation)

*/

static int op_freeform(               /* ARGUMENTS                         */
 machiningFeature * theFeature,       /* feature to make                   */
 millingMachineFunctions * freeFuncs, /* milling machine functions from op */
 millingTechnology * freeTech,        /* milling technology from op        */
 freeformOperation * theFreeform)     /* freeform op to perform on feature */
{
  static char name[] = "op_freeform";
  technology * tech;                      // milling technology from segment
  millingTechnology * currentTech;        // current milling technology
  machineFunctions * funcs;               // milling machine functions from seg
  millingMachineFunctions * currentFuncs; // current milling machine functions
  std::list<toolpath *> * toolpaths;
  std::list<toolpath *>::iterator iter;
  toolpath * segment;
  machiningTool * theTool;
  cartesianPoint * join;

  currentTech = 0;
  currentFuncs = 0;
  join = 0;
  IFF(check_op_freeform(theFreeform));
  theTool = theFreeform->get_itsTool();
  IFF(check_tool_cutting(theTool));
  toolpaths = theFreeform->get_itsToolpath()->get_itsList()->get_theList();
  for (iter = toolpaths->begin(); iter != toolpaths->end(); ++iter)
    {
      segment = *iter;
      tech = segment->get_itsTechnology();
      funcs = segment->get_itsMachineFunctions();
      if (funcs)
	{
	  CHK((NOT(funcs->isA(millingMachineFunctions_E))),
	      MACHINE_FUNCTIONS_MUST_BE_MILLING_MACHINE_FUNCTIONS);
	  currentFuncs = dynamic_cast<millingMachineFunctions *>(funcs);
	  IFF(handle_machine_functions(currentFuncs));
	}
      else if (currentFuncs != freeFuncs)
	{
	  currentFuncs = freeFuncs;
	  IFF(handle_machine_functions(freeFuncs));
	}
      if (tech)
	{
	  CHK((NOT(tech->isA(millingTechnology_E))),
	      TECHNOLOGY_MUST_BE_MILLING_TECHNOLOGY);
	  currentTech = dynamic_cast<millingTechnology *>(tech);
	  IFF(handle_technology(currentTech, theTool));
	}
      else if (currentTech != freeTech)
	{
	  currentTech = freeTech;
	  IFF(handle_technology(freeTech, theTool));
	}
      if (segment->isA(cutterLocationTrajectory_E))
	{
	  IFF(op_trajectory(dynamic_cast<cutterLocationTrajectory *>(segment),
			    &join));
	}
      else if (segment->isA(feedstop_E))
	{
	  DWELL((dynamic_cast<feedstop *>(segment))->get_dwell());
	}
      else
	CHK(1, CAN_HANDLE_ONLY_FEEDSTOP_AND_CUTTER_LOCATION_TRAJECTORY);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* op_multistep_drilling

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_multistep_drilling returns an error code.
   2. check_tool_drill returns an error code.
   3. find_cutting_depths returns an error code.
   4. find_drill_tip_length returns an error code.
   5. find_retract_z returns an error code.
   6. start_cut returns an error code.

Side Effects: See below

Called By: cut_feature

cut_feature has already checked that neither argument is NULL, so that
is not rechecked here.

See documentation of find_cutting_depths for how depth and depth1 are
set.  After these depths are found, checks are made as described above.

1. If (optional double) retractPlane is given, retract_z
   is set to be that distance above the top of the feature; otherwise,
   retract_z is set to be one tool tip length above the top of the
   feature.
2. dwell_time is set initially to dwellTimeStep and later to 
   dwellTimeBottom.
3. retract_by is set initially to retractDistance from the_drilling
   and later to -1 (to cause a retract to the retract plane).
4. peck is set to depthOfStep from the_drilling.
5. If retract_feed is set to the_drilling->get_feedOnRetract() if
   that is not NULL, and to 1 if it is.


The sequence of actions (including settings and calculations) is:

1. rapid vertical up to current security_z if not retracted.
2. rapid horizontal to X=0, Y=0 in the coordinate system of the feature.
   Note that any kind of feature can be drilled.
3. rapid vertical down to retractPlane.
4. Start a "for" loop which does the following.
   A. If depth1 is below or at depth, set depth1 to depth, set dwell_time
      to dwellTimeBottom, and set retract_by to -1.
   B. Cut vertically down to depth1.
   C. If dwell_time is given and not zero, dwell for that amount of time.
   D. If retract_feed is not equal to 1, reset feed.
   E. If retract_by is positive, retract vertically up by that
      amount; otherwise, retract vertically up to the retract plane.
   F. If retract_feed is not equal to 1, reset feed.
   G. If depth1 is depth, get out of the loop, otherwise, make depth1
      deeper by peck.
5. Update current location.

C++ data for multistepDrilling
------------------------------
toolpathList *         itsToolpath;          [opt] (operation)
toolDirection *        itsToolDirection;     [opt]
char *                 itsId;                      (machiningOperation)
real *                 retractPlane;         [opt]
cartesianPoint *       startPoint;           [opt]
machiningTool *        itsTool;
technology *           itsTechnology;
machineFunctions *     itsMachineFunctions;
real *                 overcutLength;        [opt] (millingMachiningOperation)
real *                 cuttingDepth;         [opt] (drillingTypeOperation)
real *                 previousDiameter;     [opt]
real *                 dwellTimeBottom;      [opt]
real *                 feedOnRetract;        [opt]
drillingTypeStrategy * itsMachiningStrategy; [opt]
<no attributes>                                    (drillingOperation)
double                 retractDistance;            (multistepDrilling)
double                 firstDepth;
double                 depthOfStep;
real *                 dwellTimeStep;        [opt]

itsToolpath is used only if the operation is a freeformOperation; it is not
   used here.
itsToolDirection (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retractPlane is the Z-coordinate of the retract plane in the coordinate
   system of the feature, which is the same as the distance between the
   top of the feature and the point to which to retract.
startPoint is ignored. The spec (Part 10, sec 4.7.2) allows this.
itsTool is handled before this function is called.
technology is handled before this function is called. This results
   in _world.feed_rate being set.
itsMachineFunctions is handled before this function is called.
overcutLength is for through holes (Part 11, sec 4.2.3). We are requiring
   here that if given: (1) it must be positive and (2) cuttingDepth may
   not be used.
cuttingDepth, if given, may specify drilling less or more than the hole.
   We are requiring here that it must be positive if given.
previousDiameter is ignored; it is for information only.
dwellTimeBottom is used as the time in seconds for which the tool dwells
   at the bottom of the hole.
feedOnRetract is used.
itsMachiningStrategy is required here (not in the spec) to be NULL for
   multistep drilling. It could be used, but to use it simultaneously
   with the multistepDrilling attributes (the last four from the list
   above) would be a major pain. A dummy machining strategy is
   constructed here so that find_cutting_depths will calculate
   depth1.
retractDistance is used.
firstDepth is used.
depthOfStep is used.
dwellTimeStep is used.

There are two reasonable ways to use depthOfStep. The first is to
add depthOfStep to the depth at each step until the result to too
big and then make the last step whatever is needed to get to the
bottom. The second is to calculate how many steps would be needed if
the first procedure were followed and then divide the total depth
to be cut in steps by that number to get an actual step depth (which
is usually a little smaller than depthOfStep, and the last step is
no smaller than the other steps). We are using the first procedure
here.

*/

static int op_multistep_drilling(   /* ARGUMENTS                         */
 machiningFeature * the_feature,    /* feature to make                   */
 multistepDrilling * the_drilling)  /* drilling op to perform on feature */
{
  static char name[] = "op_multistep_drilling";
  double tip_length;
  double flute_length;
  double feat_x;
  double feat_y;
  double feat_z;
  double retract_z;           // retract z in setup coord_sys
  double depth;               // tip z coordinate at bottom in setup coord_sys
  double depth1;              // resettable depth
  double depth2;              // dummy needed by find_cutting_depths
  double peck;                // depthOfStep from the_drilling
  double retract_by;          // retract distance from the_drilling or -1
  double retract_feed;        // feedOnRetract from the_drilling or 1
  double dwell_time;          // dwell time of step or bottom
  drillingTypeStrategy strat; // passes deepness to find_cutting_depths
  double deepness;            // value of startDepth
  real startDepth;            // part of strat

  feat_x = getPtX(&(_world.feature_place));
  feat_y = getPtY(&(_world.feature_place));
  feat_z = getPtZ(&(_world.feature_place));
  IFF(check_op_multistep_drilling(the_drilling));
  IFF(check_tool_drill(the_drilling->get_itsTool(), &flute_length));
  IFF(find_drill_tip_length(the_drilling->get_itsTool(), &tip_length));
  dwell_time = (the_drilling->get_dwellTimeStep() ?
		the_drilling->get_dwellTimeStep()->get_val() : 0.0);
  peck = the_drilling->get_depthOfStep();
  retract_feed = (the_drilling->get_feedOnRetract() ?
		  the_drilling->get_feedOnRetract()->get_val() : 1.0);
  retract_by = the_drilling->get_retractDistance();
  deepness = the_drilling->get_firstDepth();
  startDepth.set_val(deepness);
  strat.set_depthOfStart(&startDepth);
  strat.set_depthOfEnd(0);
  IFF(find_cutting_depths(&depth, &depth1, &depth2, flute_length, tip_length,
			  the_feature->get_depth(),
			  the_drilling->get_overcutLength(),
			  the_drilling->get_cuttingDepth(), &strat));
  IFF(find_retract_z(feat_z, the_drilling->get_retractPlane(),
		     tip_length, &retract_z));
  IFF(start_cut(feat_x, feat_y, retract_z));
  for (; ; depth1 = (depth1 - peck))
    {
      if (depth1 <= (depth + ISO14649_TINY))
	{
	  depth1 = depth;
	  dwell_time = (the_drilling->get_dwellTimeBottom() ?
			the_drilling->get_dwellTimeBottom()->get_val() : 0.0);
	  retract_by = -1.0;
	}
      STRAIGHT_FEED(feat_x, feat_y, depth1);
      if (dwell_time != 0.0)
	DWELL(dwell_time);
      if (retract_feed != 1.0)
	SET_FEED_RATE(retract_feed * _world.feedrate);
      STRAIGHT_FEED(feat_x, feat_y,
		    ((retract_by > 0) ? (depth1 + retract_by) : retract_z));
      if (retract_feed != 1.0)
	SET_FEED_RATE(_world.feedrate);
      if (depth1 == depth)
	break;
    }
  _world.current_x = feat_x;
  _world.current_y = feat_y;
  _world.current_z = retract_z;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_reaming

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_reaming returns an error code.
   2. check_tool_reamer returns an error code.
   3. find_cutting_depths returns an error code.
   4. find_retract_z returns an error code.
   5. start_cut returns an error code.
   6. spindleStopAtBottom is neither true nor false:
      SPINDLE_STOP_AT_BOTTOM_MUST_BE_TRUE_OR_FALSE.

Side Effects: Code is generated to ream

Called By: cut_feature

cut_feature has already checked that neither argument is NULL, so that
is not rechecked here.

See documentation of find_cutting_depths for how depth, depth1, and
depth2 are set. If depth1 or depth2 is set to ISO14649_BAD_REAL, that is
regarded as not being set at all. After these depths are found, the
sequence of actions (and calculations) is:

1. rapid vertical up to current security_z if not retracted.
2. rapid horizontal to X=0, Y=0 in the coordinate system of the feature.
   Note that any kind of feature can be drilled.
3. rapid vertical down to retract_z.
4A. If depth1 is set
    a. Set feed and/or speed and cut vertically down to depth1.
    b. If depth2 is set and equals depth1 set feed and/or speed and cut
       vertically down to depth.
    c. If depth2 is set and does not equal depth1, set feed and/or
       speed and cut vertically down to depth2. Then reset feed and/or
       speed and cut vertically down to depth.
    d. if depth2 is not set, reset feed and/or speed and cut vertically
       down to depth.
4B. Otherwise if depth2 is set
    a. Cut vertically down to depth2.
    b. Set feed and/or speed and cut vertically down to depth.
4C. Otherwise cut vertically down to depth.
5. If there is a dwell time, dwell for that amount of time.
6. Stop the spindle is there is a spindle stop at the bottom.
7. Reset feed if the retract feed differs from the current feed
   (which might happen if there is a feedOnRetract and/or a
    reduced_feed_at_end).
8. Retract vertically up to retract_z.
9. Update current location, feed, and speed.

Note that feed and speed canonical commands may have just been issued
(by handle_technology) that will be negated immediately by other feed
and speed canonical commands issued here. It may be worth the trouble
to avoid this, but we are living with it for now.

C++ data for reaming
---------------------
toolpathList *         itsToolpath;          [opt] (operation)
toolDirection *        itsToolDirection;     [opt]
char *                 itsId;                      (machiningOperation)
real *                 retractPlane;         [opt]
cartesianPoint *       startPoint;           [opt]
machiningTool *        itsTool;
technology *           itsTechnology;
machineFunctions *     itsMachineFunctions;
real *                 overcutLength;        [opt] (millingMachiningOperation)
real *                 cuttingDepth;         [opt] (drillingTypeOperation)
real *                 previousDiameter;     [opt]
real *                 dwellTimeBottom;      [opt]
real *                 feedOnRetract;        [opt]
drillingTypeStrategy * itsMachiningStrategy; [opt]
boolean *              spindleStopAtBottom;        (boringOperation)
real *                 depthOfTestcut;       [opt]
cartesianPoint *       waitingPosition;      [opt]
<no attributes>                                    (reaming)

itsToolpath is used only if the operation is a freeformOperation; it is not
   used here.
itsToolDirection (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
itsId is ignored.
retractPlane is the Z-coordinate of the retract plane in the feature
   coordinate system.
startPoint is ignored. The spec (Part 10, sec 4.7.2) allows this.
itsTool is handled before this function is called.
itsTechnology is handled before this function is called.
itsMachineFunctions is handled before this function is called.
overcutLength is for through features (Part 11, sec 4.2.3). We are requiring
   here that if given: (1) it must be positive and (2) cuttingDepth may
   not be used.
cuttingDepth, if given, may specify reaming less or more than the hole.
   We are requiring here that it must be positive if given.
previousDiameter is ignored; it is for information only. It might be
   a good idea to require that the previous diameter be given and that
   it be no more than a tiny bit smaller than the reaming tool diameter.
dwellTimeBottom, if given, is used as the time in seconds for which the
   tool dwells at the bottom of the hole.
feedOnRetract, if given, is used as a multiplier for the feed rate
   during the retract motion.
spindleStopAtBottom if true means stop the spindle at the bottom.
depthOfTestcut is for boring. Here it is required to be NULL.
waitingPosition is for boring. Here it is required to be NULL.

C++ data for drillingTypeStrategy
---------------------------------
real * reducedCutAtStart;   [opt] (drillingTypeStrategy)
real * reducedFeedAtStart;  [opt]
real * depthOfStart;        [opt]
real * reducedCutAtEnd;     [opt]
real * reducedFeedAtEnd;    [opt]
real * depthOfEnd;          [opt]

WHERE
WR1: EXISTS(depthOfStart) OR
     NOT (EXISTS(reducedCutAtStart) OR EXISTS(reducedFeedAtStart));
WR2: EXISTS(depthOfEnd) OR
     NOT (EXISTS(reducedcutAtEnd) OR EXISTS(reducedFeedAtEnd));

The find_cutting_depths function checks the attributes of the drilling
strategy, so they are not rechecked here.

During the operation, _world.feedrate is kept fixed, since it is
needed as the basis for calculating current feedrate. When all motion
is finished, _world.feedrate is set to the feedrate in use at the end
of the operation. Similarly for spindle speed.

If the optional retractPlane is given, retract_z is set to that
amount above the top of the hole.  If not, retract_z is set to
ISO14649_UP above the top of the hole.

*/

static int op_reaming(           /* ARGUMENTS         */
 machiningFeature * the_feature, /* feature to ream   */
 reaming * the_reaming)          /* reaming operation */
{
  static char name[] = "op_reaming";

  double feat_x;       // in setup c_sys
  double feat_y;       // in setup c_sys
  double feat_z;       // in setup c_sys
  double retract_z;    // retract z in setup c_sys
  double feedrate;     // current feed rate
  double speed;        // current spindle speed
  double depth;        // tip z coordinate at bottom in setup  c_sys
  double depth1;       // tip z coordinate at end of start in setup c_sys
  double depth2;       // tip z coordinate at start of end in setup c_sys
  double flute_length; // reamer flute length to reamer tip
  drillingTypeStrategy * strat; // cutting strategy to use

  feat_x = getPtX(&(_world.feature_place));
  feat_y = getPtY(&(_world.feature_place));
  feat_z = getPtZ(&(_world.feature_place));
  strat = the_reaming->get_itsMachiningStrategy();
  feedrate = _world.feedrate;
  speed = _world.speed;
  IFF(check_op_reaming(the_reaming));
  IFF(check_tool_reamer(the_reaming->get_itsTool(), &flute_length));
  IFF(find_cutting_depths(&depth, &depth1, &depth2, flute_length, 0,
			  the_feature->get_depth(),
			  the_reaming->get_overcutLength(),
			  the_reaming->get_cuttingDepth(), strat));
  IFF(find_retract_z(feat_z, the_reaming->get_retractPlane(),
		     ISO14649_UP, &retract_z));
  IFF(start_cut(feat_x, feat_y, retract_z));
  if (depth1 != ISO14649_BAD_REAL)
    {
      if (strat->get_reducedCutAtStart() != 0)
	{
	  speed = (_world.speed * strat->get_reducedCutAtStart()->get_val());
	  SET_SPINDLE_SPEED(speed);
	}
      if (strat->get_reducedFeedAtStart() != 0)
	{
	  feedrate =
	    (_world.feedrate * strat->get_reducedFeedAtStart()->get_val());
	  SET_FEED_RATE(feedrate);
	}
      STRAIGHT_FEED(feat_x, feat_y, depth1);
      if (feedrate != _world.feedrate)
	{
	  feedrate = _world.feedrate;
	  SET_FEED_RATE(feedrate);
	}
      if (speed != _world.speed)
	{
	  speed = _world.speed;
	  SET_SPINDLE_SPEED(speed);
	}
    }
  if (depth2 != ISO14649_BAD_REAL)
    {
      STRAIGHT_FEED(feat_x, feat_y, depth2);
      if (strat->get_reducedCutAtEnd() != 0)
	{
	  speed = (_world.speed * strat->get_reducedCutAtEnd()->get_val());
	  SET_SPINDLE_SPEED(speed);
	}
      if (strat->get_reducedFeedAtEnd() != 0)
	{
	  feedrate =
	    (_world.feedrate * strat->get_reducedFeedAtEnd()->get_val());
	  SET_FEED_RATE(feedrate);
	}
    }
  STRAIGHT_FEED(feat_x, feat_y, depth);
  if (the_reaming->get_feedOnRetract() == 0)
    {
      if (feedrate != _world.feedrate)
	{
	  feedrate = _world.feedrate;
	  SET_FEED_RATE(feedrate);
	}
    }
  else if (feedrate !=
	   (the_reaming->get_feedOnRetract()->get_val() * _world.feedrate))
    {
      feedrate =
	(the_reaming->get_feedOnRetract()->get_val() * _world.feedrate);
      SET_FEED_RATE(feedrate);
    }
  if (the_reaming->get_dwellTimeBottom() != 0)
    DWELL(the_reaming->get_dwellTimeBottom()->get_val());
  if (the_reaming->get_spindleStopAtBottom()->isA(booleanTrue_E))
    {
      STOP_SPINDLE_TURNING();
      SET_SPINDLE_SPEED(0.0);
      speed = 0.0;
      _world.spindle_turning = CANON_STOPPED;
    }
  else
    CHK((NOT(the_reaming->get_spindleStopAtBottom()->isA(booleanFalse_E))),
        SPINDLE_STOP_AT_BOTTOM_MUST_BE_TRUE_OR_FALSE);
  STRAIGHT_FEED(feat_x, feat_y, retract_z);
  _world.current_x = feat_x;
  _world.current_y = feat_y;
  _world.current_z = retract_z;
  _world.feedrate = feedrate;
  _world.speed = speed;
  return ISO14649_OK;
}

/***********************************************************************/

/* op_rough_milling_both

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_rough_both returns an error code.
   2. check_tool_endmill returns an error code.
   3. rough_mill_both_closed_pocket returns an error code.
   4. the_feature is not a closedPocket:
      CAN_HANDLE_ONLY_CLOSED_POCKET_FOR_ROUGH_MILL_BOTTOM_AND_SIDE.

Side Effects: Code is generated to rough mill the sides and bottom of
   the feature, which must be a closed pocket.

Called By: cut_feature

*/

static int op_rough_milling_both(       /* ARGUMENTS               */
 machiningFeature * the_feature,        /* feature to rough mill   */
 bottomAndSideRoughMilling * the_rough) /* rough milling operation */
{
  static char name[] = "op_rough_milling_both";
  endmill * the_endmill;

  IFF(check_op_rough_both(the_rough));
  IFF(check_tool_endmill(the_rough->get_itsTool(), &the_endmill));
  if (the_feature->isA(closedPocket_E))
    IFF(rough_mill_both_closed_pocket
	(dynamic_cast<closedPocket *>(the_feature), the_rough, the_endmill));
  else
    CHK(1, CAN_HANDLE_ONLY_CLOSED_POCKET_FOR_ROUGH_MILL_BOTTOM_AND_SIDE);
  return ISO14649_OK;
}


/***********************************************************************/

/* op_rough_milling_plane

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_op_rough_plane returns an error code.
   2. check_tool_plane returns an error code.
   3. The_feature is not a planarFace:
      FEATURE_FOR_PLANE_MILLING_MUST_BE_PLANAR_FACE
   4. The tool is neither an endmill nor a facemill:
      TOOL_FOR_PLANE_MILLING_MUST_BE_ENDMILL_OR_FACEMILL.
   5. mill_planar returns an error code.

Side Effects: Code is generated to cut the plane face.

Called By: cut_feature

Notes:

planeMilling may be done using either a facemill or an endmill. Using a
facemill is feasible when entry from the side is possible.

Error 4 above should never happen, since check_tool_plane checks the
same thing.

*/

static int op_rough_milling_plane( /* ARGUMENTS               */
 machiningFeature * the_feature,   /* feature to rough mill   */
 planeRoughMilling * the_rough)    /* rough milling operation */
{
  static char name[] = "op_rough_milling_plane";
  endmill * the_endmill;
  facemill * the_facemill;

  the_endmill = 0;
  the_facemill = 0;
  IFF(check_op_rough_plane(the_rough));
  IFF(check_tool_plane(the_rough->get_itsTool(), &the_endmill, &the_facemill));
  if (the_feature->isA(planarFace_E))
    {
      if (the_endmill)
	IFF(mill_planar(dynamic_cast<planarFace *>(the_feature),
			the_rough, the_endmill));
      else if (the_facemill)
	IFF(mill_planar(dynamic_cast<planarFace *>(the_feature),
			the_rough, the_facemill));
      else
	CHK(1, TOOL_FOR_PLANE_MILLING_MUST_BE_ENDMILL_OR_FACEMILL);
    }
  else
    CHK(1, FEATURE_FOR_PLANE_MILLING_MUST_BE_PLANAR_FACE);
  return ISO14649_OK;
}

/***********************************************************************/

/* op_rough_milling_side

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. This function is called: CANNOT_HANDLE_SIDE_ROUGH_MILLING

Side Effects: None

Called By: cut_feature

*/

static int op_rough_milling_side( /* ARGUMENTS                     */
 machiningFeature * the_feature,  /* feature to rough mill         */
 sideRoughMilling * the_rough)    /* rough milling operation to do */
{
  static char name[] = "op_rough_milling_side";

  CHK(1, CANNOT_HANDLE_SIDE_ROUGH_MILLING);
  return ISO14649_OK;
}


/***********************************************************************/

/* op_trajectory

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. itsSpeed is given: CANNOT_HANDLE_SPEED_PROFILE.
   2. itsToolaxis: CANNOT_HANDLE_TOOLAXIS.
   3. the pathType is neither connect nor trajectoryPath:
      CAN_HANDLE_ONLY_CONNECT_OR_TRAJECTORYPATH_TOOLPATH_TYPE.
   4. follow_curve_forward returns an error code.
   5. follow_curve_backward returns an error code.
   6. transform_code returns an error code.
   7. start_cut returns an error code.
   9. run_code returns an error code.

Called By: op_freeform

C++ data for cutterLocationTrajectory
-------------------------------------

boolean *              itsPriority;               (toolpath)
toolpathType *         itsType;
toolpathSpeedprofile * itsSpeed;            [opt]
technology *           itsTechnology;       [opt]
machineFunctions *     itsMachineFunctions; [opt]
boolean *              itsDirection;        [opt] (trajectory)
boundedCurve *         basiccurve;                (cutterLocationTrajectory)
boundedCurve *         itsToolaxis;         [opt]
boundedCurve *         surfaceNormal;       [opt]

This is assuming that the toolpath is given as a cutter location
trajectory in feature coordinates. The spec allows either feature
coordinates or workpiece coordinates (and provides no method of
specifying which it is!). See Part 10, Sec. 4.8.4, page 79.

This is handling only two values (connect and trajectoryPath) of the
six possible values of toolpathType. Approach, lift, nonContact, and
contact are not handled. In this interpreter, connect means to move
at traverse rate, and trajectoryPath means to move at feed rate. The
spec is not specific about the meanings. See Part 10, section 4.8.1.1
page 77.

This is ignoring surfaceNormal.

When running the code, the command in code[0] (i.e. code[0][0]) is not
used. code[0][0] is expected to be CANON_STRAIGHT_FEED or
CANON_STRAIGHT_TRAVERSE, so that the rest of code[0] contains the
coordinates of the first point of the trajectory. Those coordinates
are used in start_cut.

*/

static int op_trajectory(         /* ARGUMENTS                   */
 cutterLocationTrajectory * traj, /* the trajectory to follow    */
 cartesianPoint ** join)          /* should point to start point */
{
  static char name[] = "op_trajectory";
  double code[ISO14649_CODE_SIZE][7];
  int lines;           // number of lines of code
  bool first;
  toolpathType * pathType;

  CHK(traj->get_itsSpeed(), CANNOT_HANDLE_SPEED_PROFILE);
  CHK(traj->get_itsToolaxis(), CANNOT_HANDLE_TOOLAXIS);
  pathType = traj->get_itsType();
  CHK(((!(pathType->isA(toolpathTypeConnect_E))) &&
       (!(pathType->isA(toolpathTypeTrajectoryPath_E)))),
      CAN_HANDLE_ONLY_CONNECT_OR_TRAJECTORYPATH_TOOLPATH_TYPE);
  lines = 0;
  first = (*join == 0);
  if ((NOT(traj->get_itsDirection())) ||
      (traj->get_itsDirection()->isA(booleanTrue_E)))
    IFF(follow_curve_forward(traj->get_basiccurve(),
			     pathType, join, code, &lines));
  else // if (traj->get_itsDirection()->isA(booleanFalse_E))
    IFF(follow_curve_backward(traj->get_basiccurve(),
			      pathType, join, code, &lines));    
  IFF(transform_code(code, lines, &(_world.feature_place)));
  if (first)
    {
      CHK((code[0][3] > _world.security_z_now),
	  RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
      IFF(start_cut(code[0][1], code[0][2], code[0][3]));
      IFF(run_code((code + 1), (lines - 1)));
    }
  else
    {
      IFF(run_code(code, lines));
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* op_trajectory_rapid

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. itsSpeed is given: CANNOT_HANDLE_SPEED_PROFILE.
   2. itsToolaxis: CANNOT_HANDLE_TOOLAXIS.
   3. follow_curve_forward returns an error code.
   4. follow_curve_backward returns an error code.
   5. the tool is required to retract above the security plane:
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE.
   6. the tool path does not start with a straight line:
      CAN_HANDLE_ONLY_STRAIGHT_LINE_MOVE_AT_START_OF_RAPID.
   7. the tool path does not start at the current location of the tool:
      RAPID_MUST_START_AT_CURRENT_LOCATION.
   8. run_code returns an error code.

Called By: execute_rapid_setup

C++ data for cutterLocationTrajectory
-------------------------------------

boolean *              itsPriority;               (toolpath)
toolpathType *         itsType;
toolpathSpeedprofile * itsSpeed;            [opt]
technology *           itsTechnology;       [opt]
machineFunctions *     itsMachineFunctions; [opt]
boolean *              itsDirection;        [opt] (trajectory)
boundedCurve *         basiccurve;                (cutterLocationTrajectory)
boundedCurve *         itsToolaxis;         [opt]
boundedCurve *         surfaceNormal;       [opt]

This is assuming that the toolpath is given as a cutter location
trajectory in setup coordinates. The spec allows either feature
coordinates or workpiece coordinates (and provides no method of
specifying which it is!). See Part 10, Sec. 4.8.4, page 79.

This is ignoring surfaceNormal and itsType of traj. However, it is
using trajectoryPath as the type in the calls to follow_curve_forward
and follow_curve_backward. This is done so that curved portions of
the path not cause an error. There is no canonical command for moving
along a curved path at traverse rate, so any curved portions will
be handled at the current feed rate.

The code that is generated may (almost certainly does) contain
CANON_STRAIGHT_FEED in code[n][0] for many n. Before running the
code, those are all changed to CANON_STRAIGHT_TRAVERSE.

When running the code, the command in code[0] (i.e. code[0][0]) is not
used. code[0][0] is expected to be CANON_STRAIGHT_FEED or
CANON_STRAIGHT_TRAVERSE, so that the rest of code[0] contains the
coordinates of the first point of the trajectory. Those coordinates
are used in start_cut.

*/

static int op_trajectory_rapid(   /* ARGUMENTS                   */
 cutterLocationTrajectory * traj, /* the trajectory to follow    */
 cartesianPoint ** join)          /* should point to start point */
{
  static char name[] = "op_trajectory_rapid";
  double code[ISO14649_CODE_SIZE][7];
  int lines;           // number of lines of code
  int n;               // index for lines of code
  toolpathTypeTrajectoryPath pathType;

  CHK(traj->get_itsSpeed(), CANNOT_HANDLE_SPEED_PROFILE);
  CHK(traj->get_itsToolaxis(), CANNOT_HANDLE_TOOLAXIS);
  lines = 0;
  if ((NOT(traj->get_itsDirection())) ||
      (traj->get_itsDirection()->isA(booleanTrue_E)))
    IFF(follow_curve_forward(traj->get_basiccurve(), &pathType,
			     join, code, &lines));
  else
    IFF(follow_curve_backward(traj->get_basiccurve(), &pathType,
			      join, code, &lines));    
  CHK((code[0][3] > _world.security_z_now),
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
  for (n = 0; n < lines; n++)
    {
      if (code[n][0] == CANON_STRAIGHT_FEED)
	code[n][0] = CANON_STRAIGHT_TRAVERSE;
    }
  CHK((code[0][0] != CANON_STRAIGHT_TRAVERSE),
      CAN_HANDLE_ONLY_STRAIGHT_LINE_MOVE_AT_START_OF_RAPID);
  CHK(((fabs(code[0][1] - _world.current_x) > ISO14649_TINY) ||
       (fabs(code[0][2] - _world.current_y) > ISO14649_TINY) ||
       (fabs(code[0][3] - _world.current_z) > ISO14649_TINY)),
      RAPID_MUST_START_AT_CURRENT_LOCATION);
  IFF(run_code((code + 1), (lines - 1)));
  return ISO14649_OK;
}

/***********************************************************************/

/* plunge_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. write_feed returns an error code.

Side Effects: This writes three lines of code to plunge into and back
out of a pocket whose center is at X=0, Y=0.

Called By: mill_rectangular_pocket

*/

static int plunge_pocket( /* ARGUMENTS                        */
 double depth,            /* Z coordinate to which to plunge  */
 double retract_z,        /* Z coordinate to which to retract */
 double code[][7],        /* code array to write in           */
 int * lines)             /* code array index                 */
{
  static char name[] = "plunge_pocket";

  IFF(write_feed(0, 0, retract_z, code, lines));
  IFF(write_feed(0, 0, -depth, code, lines));
  IFF(write_feed(0, 0, retract_z, code, lines));
  return ISO14649_OK;
}


/***********************************************************************/

/* put1

Returned Value: none

Called By:
  find_location
  reset_place

This puts a value into the first entry of a list of reals.
This is assuming that reals is not NULL.

If the first entry exists when this is called, its val is reset to
valIn.  If not, this inserts a new real with val valIn as the first
element of the list.

*/

void put1(                  /* ARGUMENTS                       */
 std::list<real *> * reals, /* list of reals to put valIn into */
 double valIn)
{
  std::list<real *>::iterator iter;
  iter = reals->begin();
  if (iter == reals->end())
    reals->push_back(new real(valIn));
  else
    (*iter)->set_val(valIn);
}

/***********************************************************************/

/* put2

Returned Value: none

Called By:
  find_location
  reset_place

This puts a value into the second entry of a list of reals.
This is assuming that reals is not NULL.

If the second entry exists when this is called, its val is reset to valIn.

If the second entry does not exist when this is called but the first
entry exists, this inserts a new real with val=valIn as the second
element of the list.

If neither the first entry nor the second entry exists when this is
called, this inserts a new real with val=0 as the first entry and
inserts a new real with val=valIn as the second entry.

*/

void put2(                  /* ARGUMENTS                       */
 std::list<real *> * reals, /* list of reals to put valIn into */
 double valIn)
{
  std::list<real *>::iterator iter;
  iter = reals->begin();
  if (iter == reals->end())
    { // list has 0 entries
      reals->push_back(new real(0.0));
      reals->push_back(new real(valIn));
    }
  else
    { // list has at least 1 entry
      ++iter;
      if (iter == reals->end())
	{ // list has 1 entry
	  reals->push_back(new real(valIn));
	}
      else
	{ // list has at least 2 entries
	  (*iter)->set_val(valIn);
	}
    }
}

/***********************************************************************/

/* put3

Returned Value: none

Called By:
  find_location
  reset_place

This puts a value into the third entry of a list of reals.
This is assuming that reals is not NULL.

If the third entry exists when this is called, its val is reset to valIn.

If the third entry does not exist when this is called but the first
and second entries exist, a new real with val=valIn is inserted as the
third element of the list.

If the second and third entries do not exist when this is called but
the first entry exists, this inserts a new real with val=0 as the
second element of the list and a new real with val=valIn as the third
element of the list.

If no entries exist when this is called, this inserts a new real with
val=0 as the first entry, inserts a new real with val=0 as the second
entry, and inserts a new real with val=valIn as the third entry.

*/

void put3(                  /* ARGUMENTS                       */
 std::list<real *> * reals, /* list of reals to put valIn into */
 double valIn)
{
  std::list<real *>::iterator iter;
  iter = reals->begin();
  if (iter == reals->end())
    { // list has 0 entries
      reals->push_back(new real(0.0));
      reals->push_back(new real(0.0));
      reals->push_back(new real(valIn));
    }
  else
    { // list has at least 1 entry
      ++iter;
      if (iter == reals->end())
	{ // list has 1 entry
	  reals->push_back(new real(0.0));
	  reals->push_back(new real(valIn));
	}
      else
	{ // list has at least 2 entries
	  ++iter;
	  if (iter == reals->end())
	    { // list has 2 entries
	      reals->push_back(new real(valIn));
	    }
	  else
	    { // list has at least 3 entries
	      (*iter)->set_val(valIn);
	    }
	}
    }
}

/***********************************************************************/

/* reset_place

Returned Value: int (ISO14649_OK)

Side Effects: This resets the place to the default location:
origin at (0,0,0), Z-axis of (0,0,1), X-axis of (1,0,0). The
lists of reals must already exist.

Called By: init_place

*/

static int reset_place(    /* ARGUMENTS                   */
 axis2placement3d * place) /* the axis placement to reset */
{
  std::list<real *> * coords;

  coords = place->get_location()->get_coordinates()->get_theList();
  put1(coords, 0.0);
  put2(coords, 0.0);
  put3(coords, 0.0);
  coords = place->get_axis()->get_directionRatios()->get_theList();
  put1(coords, 0.0);
  put2(coords, 0.0);
  put3(coords, 1.0);
  coords = place->get_refDirection()->get_directionRatios()->get_theList();
  put1(coords, 1.0);
  put2(coords, 0.0);
  put3(coords, 0.0);
  return ISO14649_OK;
}

/***********************************************************************/

/* rough_mill_both_closed_pocket

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. The boundary of the pocket is NULL: POCKET_BOUNDARY_MUST_NOT_BE_NULL.
   2. The boundary of the pocket is not a rectangularClosedProfile:
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE.
   3. check_rectangular_pocket returns an error code.
   4. check_rectangular_pocket_strategies returns an error code.
   5. mill_rectangular_pocket returns an error code.
   6. transform_code returns an error code.
   7. run_code returns an error code.
   8. start_cut returns an error code.
   9. The final retract goes above the security plane:
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE.

Side Effects: See below

Called By: op_rough_milling_both

C++ data for bottomAndSideRoughMilling
---------------------------------------
toolpathList *            itsToolpath;         [opt] (operation)
toolDirection *           itsToolDirection;    [opt]
char *                    itsId;                     (machiningOperation)
real *                    retractPlane;        [opt]
cartesianPoint *          startPoint;          [opt]
machiningTool *           itsTool;
technology *              itsTechnology;
machineFunctions *        itsMachineFunctions; 
real *                    overcutLength;       [opt] (millingMachiningOperation)
approachRetractStrategy * approach;            [opt] (millingTypeOperation)
approachRetractStrategy * retract;             [opt]
two5DmillingStrategy *    itsMachiningStrategy;[opt] (two5DMillingOperation)
real *                    axialCuttingDepth;   [opt] (bottomAndSideMilling)
real *                    radialCuttingDepth;  [opt]
real *                    allowanceSide;       [opt]
real *                    allowanceBottom;     [opt]
<no attributes>                                      (bottomAndSideRoughMilling)

itsToolpath is used only if the operation is a freeformOperation; it is not
   used here.
itsToolDirection (Part 10, sec 4.7.1.2) is not a direction at all. It is
   a specification of how many axes must be controlled simultaneously. The
   only choices are two_axes and three_axes. Since this interpreter is
   written for a machine that can control three axes simultaneously, the
   value of this attribute is ignored.
retractPlane is the Z-coordinate of the retract plane in the coordinate
   system of the feature, which is the same as the distance between the
   top of the feature and the point to which to retract.
startPoint is ignored. The spec (Part 10, sec 4.7.2) allows this.
itsTool is handled before this function is called.
technology is handled before this function is called. This results
   in _world.feed_rate being set.
itsMachineFunctions is handled before this function is called.
overcutLength must not be used for pockets (Part 11, sec 4.2.3).

C++ data for closedPocket
-------------------------
char *                        itsId;                 (manufacturingFeature)
workpiece *                   itsWorkpiece;
parenMachiningOperationList * itsOperations;
axis2placement3d *            featurePlacement;      (two5DmanufacturingFeature)
elementarySurface *           depth;                 (machiningFeature)
parenBossList *               itsBoss;               (pocket)
real *                        slope;            [opt]
pocketBottomCondition *       bottomCondition;
tolerancedLengthMeasure *     planarRadius;     [opt]
tolerancedLengthMeasure *     orthogonalRadius; [opt]
closedProfile *               featureBoundary;       (closedPocket)

C++ data for rectangularClosedProfile
-------------------------------------
axis2placement3d *        placement;     [opt] (profile)
<no attributes>                                (closedProfile)
tolerancedLengthMeasure * profileWidth;        (rectangularClosedProfile)
tolerancedLengthMeasure * profileLength;

This requires the pocket to have a rectangular closed profile. It would
be fairly easy to add circular_closedProfile.

The code is generated initially in feature coordinates. Then it is
transformed into setup coordinates.

Each line of code consists of seven doubles. See run_code function
for what they mean.

The first line of code serves only to mark the point above which (by one
retract distance) the tool should be moved by the start_cut function.

Local variables pocket_length, pocket_width, pocket_depth are set in
check_rectangular_pocket, which has to deal with them anyway.

check_rectangular_pocket_strategies may insert milling strategies in
the_rough. After code is generated here, these strategies are removed
from the_rough (since the_rough may be used elsewhere) and deleted.

*/

static int rough_mill_both_closed_pocket( /* ARGUMENTS                   */
 closedPocket * the_pocket,               /* closed pocket to rough mill */
 bottomAndSideRoughMilling * the_rough,   /* rough milling operation     */
 endmill * the_endmill)                   /* endmill to use              */
{
  static char name[] = "rough_mill_both_closed_pocket";
  double code[ISO14649_CODE_SIZE][7];
  int lines;                                // number of lines of code
  approachRetractStrategy * enter_strategy;
  approachRetractStrategy * leave_strategy;
  two5DmillingStrategy * inside_strategy;
  double pocket_length;
  double pocket_width;
  double pocket_depth;
  double pocket_radius;
  double stepover;

  lines = 0;
  enter_strategy = 0;
  leave_strategy = 0;
  inside_strategy = 0;
  CHK((the_pocket->get_featureBoundary() == 0),
      POCKET_BOUNDARY_MUST_NOT_BE_NULL);
  CHK((NOT(the_pocket->get_featureBoundary()->isA(rectangularClosedProfile_E))),
      POCKET_MUST_HAVE_RECTANGULAR_CLOSED_PROFILE);
  IFF(check_rectangular_pocket(the_pocket, &pocket_length, &pocket_width,
			       &pocket_depth, &pocket_radius));
  IFF(check_rectangular_pocket_strategies
      (pocket_length, pocket_width, pocket_depth, pocket_radius, the_rough,
       the_endmill, &stepover, &enter_strategy, &leave_strategy,
       &inside_strategy, 0));
  IFF(mill_rectangular_pocket
      (pocket_length, pocket_width, pocket_depth, pocket_radius, stepover,
       the_endmill->get_dimension()->get_diameter(), the_rough, code, &lines));
  IFF(transform_code(code, lines, &(_world.feature_place)));
  CHK((code[0][3] > _world.security_z_now),
      RETRACT_MUST_NOT_GO_ABOVE_SECURITY_PLANE);
  IFF(start_cut(code[0][1], code[0][2], code[0][3]));
  IFF(run_code((code + 1), (lines - 1)));
  if (enter_strategy)
    {
      delete enter_strategy;
      the_rough->set_approach(0);
    }
  if (leave_strategy)
    {
      delete leave_strategy;
      the_rough->set_retract(0);
    }
  if (inside_strategy)
    {
      delete inside_strategy;
      the_rough->set_itsMachiningStrategy(0);
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* run_code

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. An unknown command code is used:
      COMMAND_CODE_TYPE_MUST_BE_MOTION_SPEED_OR_FEED
   2. The last command is not a motion command:
      LAST_COMMAND_CODE_TYPE_MUST_BE_FEED_OR_TRAVERSE.

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  mill_planar_regular
  op_trajectory
  op_trajectory_rapid
  rough_mill_both_closed_pocket

This takes an array of coded commands and executes them in order.

This requires that the last line of code be a motion command (straight
feed, straight traverse, or arc) so that the current position can be
updated from the last line of code. The current position is updated.

The seven places in a code array (named ray) have the following meanings.
ray[0] codes the command.

If ray[0] == CANON_STRAIGHT_FEED or CANON_STRAIGHT_TRAVERSE, then
   ray[1] == x coordinate of end
   ray[2] == y coordinate of end
   ray[3] == z coordinate of end
   ray[4] to ray[6] are irrelevant

If ray[0] == CANON_ARC_FEED, and the XY plane is active, then
   ray[1] == x coordinate of end of arc
   ray[2] == y coordinate of end of arc
   ray[3] == x coordinate of center of arc
   ray[4] == y coordinate of center of arc
   ray[5] == number of full or partial circles, positive counterclockwise
   ray[6] == z coordinate of end of arc (which may be helical)
   Meanings are analogous if the YZ or ZX plane is active.

If ray[0] == CANON_SET_FEED_RATE, then
   ray[1] == feed rate in current length units (mm) per minute
   ray[2] to ray[6] are irrelevant

If ray[0] == CANON_SET_SPINDLE_SPEED, then
   ray[1] == spindle speed in rpm
   ray[2] to ray[6] are irrelevant

*/

static int run_code( /* ARGUMENTS               */
 double code[][7],   /* code array to run from  */
 int lines)          /* number of lines of code */
{
  static char name[] = "run_code";
  int n;

  for (n = 0; n < lines; n++)
    {
      switch ((int)code[n][0])
	{
	case CANON_STRAIGHT_FEED:
	  STRAIGHT_FEED(code[n][1], code[n][2], code[n][3]);
	  break;
	case CANON_ARC_FEED:
	  ARC_FEED(code[n][1], code[n][2], code[n][3],
		   code[n][4], (int)code[n][5], code[n][6]);
	  break;
	case CANON_STRAIGHT_TRAVERSE:
	  STRAIGHT_TRAVERSE(code[n][1], code[n][2], code[n][3]);
	  break;
	case CANON_SET_FEED_RATE:
	  SET_FEED_RATE(code[n][1]);
	  break;
	case CANON_SET_SPINDLE_SPEED:
	  SET_SPINDLE_SPEED(code[n][1]);
	  break;
	default:
	  CHK(1, COMMAND_CODE_TYPE_MUST_BE_MOTION_SPEED_OR_FEED);
	  break;
	}
    }
  n--;
  if (((int)code[n][0] == CANON_STRAIGHT_FEED) OR
      ((int)code[n][0] == CANON_STRAIGHT_TRAVERSE))
    {
      _world.current_x = code[n][1];
      _world.current_y = code[n][2];
      _world.current_z = code[n][3];
    }
  else if ((int)code[n][0] == CANON_ARC_FEED)
    {
      _world.current_x = code[n][1];
      _world.current_y = code[n][2];
      _world.current_z = code[n][6];
    }
  else
    CHK(1, LAST_COMMAND_CODE_TYPE_MUST_BE_FEED_OR_TRAVERSE);
  
  return ISO14649_OK;
}

/***********************************************************************/

/* set_security_z_now

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. check_horizontal_plane returns an error code.

Side Effects: See below

Called By: execute_machining

This checks that the secplane is a plane and its normal is vertical in
the coordinate system in which it is located (which is the feature
coordinate system, which is already known to have its Z axis
vertical).  Then it sets _world.security_z_now to the sum of the Z
values of (1) the location of the feature in the setup coordinate
system and (2) the location of the secplane in the feature coordinate
system.

*/

static int set_security_z_now( /* ARGUMENTS                      */
 elementarySurface * secplane) /* the (should be) plane to check */
{
  static char name[] = "set_security_z_now";
  
  IFF(check_horizontal_plane(secplane));
  _world.security_z_now = (getPtZ(&(_world.feature_place)) +
			   getPtZ(secplane->get_position()));
  return ISO14649_OK;
}

/***********************************************************************/

/* start_cut

Returned Value: int (ISO14649_OK)

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  mill_planar_regular
  op_center_drilling
  op_counter_boring
  op_counter_sinking
  op_drilling
  op_multistep_drilling
  op_reaming
  op_trajectory
  rough_mill_both_closed_pocket

This does the following
1. If the x or y coordinate of the end point differs from that
   of the current point, this (1) retracts at traverse rate towards +Z
   from the current location to the security plane, (2)traverses
   on the security plane to above the end point, and (3) updates the
   current point.
2. If the z coordinate of the end point differs from that of the 
   current point, this traverses along -Z to the end point.

Note that if the end point is the same as the current point, this
does nothing.

*/

static int start_cut(  /* ARGUMENTS                 */
 double end_x,         /* x coordinate of end point */
 double end_y,         /* y coordinate of end point */
 double end_z)         /* z coordinate of end point */
{
  if ((fabs(_world.current_x - end_x) > ISO14649_TINY) ||
      (fabs(_world.current_y - end_y) > ISO14649_TINY))
    {
      if (_world.current_z < _world.security_z_now)
	{
	  STRAIGHT_TRAVERSE(_world.current_x, _world.current_y,
			    _world.security_z_now);
	  _world.current_z = _world.security_z_now;
	}
      STRAIGHT_TRAVERSE(end_x, end_y, _world.current_z);
    }
  if (fabs(_world.current_z - end_z) > ISO14649_TINY)
    STRAIGHT_TRAVERSE(end_x, end_y, end_z);
  return ISO14649_OK;
}

/***********************************************************************/

/* tand

Returned Value: double (the tangent of the "degrees" angle)

Side Effects: None

Called By:
  check_countersunk_hole
  check_tool_countersink
  enter_pocket_pass_zigzag
  find_pocket_plunge_start_helix
  find_pocket_plunge_start_ramp
  find_pocket_plunge_start_zigzag

This is not checking for the argument being a multiple of 90 degrees,
which is a little risky. The caller should check.

*/

static double tand( /* ARGUMENTS        */
 double degrees)    /* angle in degrees */
{
  return tan((M_PI / 180.0) * degrees);
}

/***********************************************************************/

/* transform_code

Returned Value:
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. find_if_vertical returns an error code.
   2. The Z axis of the place to which to move the code is not vertical:
      Z_AXIS_MUST_BE_VERTICAL

Side Effects: See below

Called By:
  finish_mill_both_closed_pocket
  mill_planar_regular
  op_trajectory
  rough_mill_both_closed_pocket

This takes an array of code and changes the coordinate values (which
are originally in the "place" coordinate system) so they are in the
setup coordinate system. Only those code lines whose first entry
is CANON_STRAIGHT_FEED, CANON_ARC_FEED, or CANON_STRAIGHT_TRAVERSE
get their values changed. The place coordinate system must have its
Z-axis vertical in the setup coordinate system.

*/

static int transform_code(  /* ARGUMENTS                */
 double code[][7],          /* code array to transform  */
 int lines,                 /* number of lines of code  */
 axis2placement3d * place)  /* place to move code to    */
{
  static char name[] = "transform_code";
  int vertical;
  double place_angle;
  double point_angle;
  double dx;
  double dy;
  double dz;
  double arm;
  int n;

  dx = getPtX(place);
  dy = getPtY(place);
  dz = getPtZ(place);
  place_angle = atan2(getRefY(place), getRefX(place));
  IFF(find_if_vertical(place->get_axis(), &vertical));
  CHK((NOT vertical), Z_AXIS_MUST_BE_VERTICAL);
  for (n = 0; n < lines; n++)
    {
      if (((int)code[n][0] == CANON_STRAIGHT_FEED) OR
	  ((int)code[n][0] == CANON_STRAIGHT_TRAVERSE))
	{
	  arm = hypot(code[n][1], code[n][2]);
	  point_angle = atan2(code[n][2], code[n][1]);
	  code[n][1] = (dx + (arm * cos(place_angle + point_angle)));
	  code[n][2] = (dy + (arm * sin(place_angle + point_angle)));
	  code[n][3] = (dz + code[n][3]);
	}
      else if ((int)code[n][0] == CANON_ARC_FEED)
	{
	  arm = hypot(code[n][1], code[n][2]);
	  point_angle = atan2(code[n][2], code[n][1]);
	  code[n][1] = (dx + (arm * cos(place_angle + point_angle)));
	  code[n][2] = (dy + (arm * sin(place_angle + point_angle)));
	  arm = hypot(code[n][3], code[n][4]);
	  point_angle = atan2(code[n][4], code[n][3]);
	  code[n][3] = (dx + (arm * cos(place_angle + point_angle)));
	  code[n][4] = (dy + (arm * sin(place_angle + point_angle)));
	  code[n][6] = (dz + code[n][6]);
	}
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* write_arc

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  enter_pocket_pass_helix
  follow_circle_forward
  follow_helix_forward
  mill_circular_pocket
  mill_regular_pocket
  mill_semicircle_end_pocket

This writes one line of code representing cutting a circular or
helical arc.  Lines is increased by one.

The arc written here is conceptually the same as a CANON_ARC with a
vertical axis.

If rotation is positive, the arc is traversed counterclockwise as
viewed from the positive Z axis. If rotation is negative, the arc is
traversed clockwise. If rotation is 0, end_x and end_y must
be the same as the corresponding coordinates of the current point and
no arc is made (but there may be translation parallel to the Z axis).
If rotation is 1, more than 0 but not more than 360 degrees of arc
should be made. In general, if rotation is n, the amount of rotation
in the arc should be more than ([n-1] x 360) but not more than (n x
360).

*/

static int write_arc( /* ARGUMENTS                  */
 double end_x,        /* X coordinate at end        */
 double end_y,        /* Y coordinate at end        */
 double center_x,     /* X coordinate at center     */
 double center_y,     /* Y coordinate at center     */
 int rotation,        /* number of turns, see above */ 
 double end_z,        /* Z coordinate at end        */
 double code[][7],    /* code array to write in     */
 int * lines)         /* code array index           */
{
  static char name[] = "write_arc";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] = CANON_ARC_FEED;
  code[*lines][1] = end_x;
  code[*lines][2] = end_y;
  code[*lines][3] = center_x;
  code[*lines][4] = center_y;
  code[*lines][5] = (double)rotation;
  code[*lines][6] = end_z;
  (*lines)++;
  return ISO14649_OK;
}

/***********************************************************************/

/* write_feed

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  cut_straight
  enter_pocket_pass
  enter_pocket_pass_zigzag
  follow_polyline_forward
  follow_trimmedCurve_forward
  mill_circular_pocket
  mill_planar_bi
  mill_planar_uni
  mill_rectangular_pocket_regular
  mill_regular_pocket
  mill_semicircle_end_pocket
  plunge_pocket

This writes one line of code representing a straight feed cut. Lines
is increased by one.

*/

static int write_feed( /* ARGUMENTS               */
 double x,             /* X coordinate at end     */
 double y,             /* Y coordinate at end     */
 double z,             /* Z coordinate at end     */
 double code[][7],     /* code array to write in  */
 int * lines)          /* code array index        */
{
  static char name[] = "write_feed";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] = CANON_STRAIGHT_FEED;
  code[*lines][1] = x;
  code[*lines][2] = y;
  code[*lines][3] = z;
  (*lines)++;
  return ISO14649_OK;
}

/***********************************************************************/

/* write_feed_y

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  mill_planar_bi (via "feeder" function pointer)
  mill_planar_uni (via "feeder" function pointer)

This writes one line of code representing a straight feed cut rotated
90 degrees counterclockwise. This function exists so that rotated code
may be generated directly. To do the rotation, x is put into
code[*lines][2], and -y is put into code[*lines][1].

Lines is increased by one. 

*/

static int write_feed_y( /* ARGUMENTS               */
 double x,               /* X coordinate at end     */
 double y,               /* Y coordinate at end     */
 double z,               /* Z coordinate at end     */
 double code[][7],       /* code array to write in  */
 int * lines)            /* code array index        */
{
  static char name[] = "write_feed_y";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] = CANON_STRAIGHT_FEED;
  code[*lines][1] = -y;
  code[*lines][2] = x;
  code[*lines][3] = z;
  (*lines)++;
  return ISO14649_OK;
}

/***********************************************************************/

/* write_traverse

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  cut_straight
  follow_polyline_forward
  follow_trimmedCurve_forward
  mill_planar_bi
  mill_planar_uni
  mill_rectangular_pocket_regular

This writes one line of code representing a straight traverse. Lines
is increased by one.

*/

static int write_traverse( /* ARGUMENTS               */
 double x,                 /* X coordinate at end     */
 double y,                 /* Y coordinate at end     */
 double z,                 /* Z coordinate at end     */
 double code[][7],         /* code array to write in  */
 int * lines)              /* code array index        */
{
  static char name[] = "write_traverse";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] = CANON_STRAIGHT_TRAVERSE;
  code[*lines][1] = x;
  code[*lines][2] = y;
  code[*lines][3] = z;
  (*lines)++;
  return ISO14649_OK;
}


/***********************************************************************/

/* write_traverse_y

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, it returns ISO14649_OK.
   1. There are more than ISO14649_CODE_SIZE lines of code:
      CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE.

Side Effects: See below

Called By:
  mill_planar_bi (via "traverser" function pointer)
  mill_planar_uni (via "traverser" function pointer)

This writes one line of code representing a straight traverse rotated
90 degrees counterclockwise. This function exists so that rotated code
may be generated directly. To do the rotation, x is put into
code[*lines][2], and -y is put into code[*lines][1].

Lines is increased by one.

*/

static int write_traverse_y( /* ARGUMENTS               */
 double x,                   /* X coordinate at end     */
 double y,                   /* Y coordinate at end     */
 double z,                   /* Z coordinate at end     */
 double code[][7],           /* code array to write in  */
 int * lines)                /* code array index        */
{
  static char name[] = "write_traverse_y";

  CHK((*lines >= ISO14649_CODE_SIZE), CANNOT_HANDLE_THIS_MANY_LINES_OF_CODE);
  code[*lines][0] = CANON_STRAIGHT_TRAVERSE;
  code[*lines][1] = -y;
  code[*lines][2] = x;
  code[*lines][3] = z;
  (*lines)++;
  return ISO14649_OK;
}

/***********************************************************************/
/***********************************************************************/

/*

The functions in this section of this file are functions for
external programs to call to tell the iso14649 interpreter
what to do. They are declared in iso14649.hh.

*/

/***********************************************************************/

/* iso14649_close

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, this returns ISO14649_OK.
   1. iso14649_reset returns an error code.

Side Effects: See below

Called By: external programs

PROGRAM_END is called.

iso14649_reset is called (see documentation of that function).
This does not need to close the iso14649 file because it is closed
automatically immediately after it is read.

This removes the parse tree that has been saved in _world.design
so that memory is not leaked.

*/

int iso14649_close() /* NO ARGUMENTS */
{
  static char name[] = "iso14649_close";
  PROGRAM_END();
  delete _world.design;
  _world.design = 0;
  IFF(iso14649_reset());

  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_execute

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   If _world.action_flag is ISO14649_NO_ACTION, this returns ISO14649_OK.
   Otherwise, this returns ISO14649_FINISH.
   1. execute_executable returns an error code.

Side Effects: See below

Called By: external programs

This executes the most recently selected executable.
Calls to canonical machining commands are made.

The only kernel function that sets the _world.action_flag to something other
than ISO14649_NO_ACTION is change_tool.

*/

int iso14649_execute()  /* NO ARGUMENTS */
{
  static char name[] = "iso14649_execute";

  IFF(execute_executable());
  return ((_world.action_flag == ISO14649_NO_ACTION) ? ISO14649_OK :
	  ISO14649_FINISH);
}

/***********************************************************************/

/* iso14649_exit

Returned Value: int (ISO14649_OK)

Side Effects: None

Called By: external programs

Nothing needs to be done on exiting.

*/

int iso14649_exit() /* NO ARGUMENTS */
{
  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_init

Returned Value: int ISO14649_OK

Side Effects: See below

Called By: external programs

All values in the _world structure are reset.
All STEP data is wiped out.
A USE_LENGTH_UNITS canonical command call is made.
A SET_FEED_REFERENCE canonical command call is made.
A SET_ORIGIN_OFFSETS canonical command call is made.
An INIT_CANON call is made.

Some Z values set here (e.g. retracted_z and security_z_now) are based
on having the machine origin on the machine table. Actual machines
usually have Z=0 where the spindle is fully retracted, so that all
other Z values are negative.

*/

int iso14649_init() /* NO ARGUMENTS */
{
  INIT_CANON();
  USE_LENGTH_UNITS(CANON_UNITS_MM);
  SET_ORIGIN_OFFSETS(0.0, 0.0, 0.0);
  SET_FEED_REFERENCE(CANON_XYZ);
  _world.a_workpiece = 0;
  _world.a_workplan = 0;
  _world.action_flag = ISO14649_NO_ACTION;
  _world.change_x = 0;
  _world.change_y = 0;
//_world.control_mode set in iso14649_synch
//_world.current_tool_index set in iso14649_synch
//_world.current_x set in iso14649_synch
//_world.current_y set in iso14649_synch
//_world.current_z set in iso14649_synch
  if (_world.design)
    {
      delete _world.design;
      _world.design = 0;
    }
  _world.execs = 0;
  _world.exit = 0;
  init_place(&(_world.feature_place));
  _world.feed_override = ON;
//_world.feedrate set in iso14649_synch
  _world.filename[0] = 0;
//_world.flood set in iso14649_synch
//_world.iter not settable
//_world.mist set in iso14649_synch
  _world.name_text[0] = 0;
  _world.rapid_secplane = 0;
  _world.retracted_z = 250.0; //
  _world.security_z_now = 0.0;
  _world.security_z_setup = 0.0;
//_world.speed set in iso14649_synch
  _world.speed_feed_mode = CANON_INDEPENDENT;
  _world.speed_override = ON;
//_world.spindle_turning set in iso14649_synch
  _world.stack[0][0] = 0; // does not actually need initialization
  _world.stack_index = 0;
  _world.status = ISO14649_OK;
  _world.tool_length_offset = 0.0;
//_world.tool_max set in iso14649_synch
//_world.tool_table set in iso14649_synch
//_world.traverse_rate set in iso14649_synch
  _world.workpiece_place = 0;

  // Synch rest of settings to external world
  iso14649_synch();

  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_load_tool_table

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, this returns ISO14649_OK.
   1. _world.tool_max is larger than CANON_TOOL_MAX:
      TOOL_MAX_MUST_NOT_EXCEED_CANON_TOOL_MAX.

Side Effects:
   _world.tool_table[] is modified.

Called By:
   iso14649_synch
   external programs

This function copies tool tables from the external world into the
tool_table array in the _world.

The CANON_TOOL_MAX is an upper limit for this software. The
_world.tool_max is intended to be set for a particular machine.

*/

int iso14649_load_tool_table() /* NO ARGUMENTS */
{
  static char name[] = "iso14649_load_tool_table";
  int n;
  CANON_TOOL_TABLE a_table;

  CHK((_world.tool_max > CANON_TOOL_MAX),
      TOOL_MAX_MUST_NOT_EXCEED_CANON_TOOL_MAX);
  for (n = 0; n <= _world.tool_max; n++)
    {
      a_table = GET_EXTERNAL_TOOL_TABLE(n);
      strcpy(_world.tool_table[n].id, a_table.id);
      _world.tool_table[n].length = a_table.length;
      _world.tool_table[n].diameter = a_table.diameter;
    }
  for(; n <= CANON_TOOL_MAX; n++)
    {
      _world.tool_table[n].id[0] = 0;
      _world.tool_table[n].length = 0;
      _world.tool_table[n].diameter = 0;
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_open

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise it returns ISO14649_FINISH.
   1. A file is already open: A_FILE_MUST_NOT_BE_ALREADY_OPEN.
   2. The name of the file is too long: FILE_NAME_MUST_NOT_BE_TOO_LONG.
   3. The file cannot be read: INPUT_FILE_MUST_BE_READABLE.
   4. check_and_store returns an error code.
   5. check_tools returns an error code.

Side Effects: See below

Called By: external programs

The file is opened and read into a working structure.
The working structure is saved in _world.design.
The file name is copied into _world.filename.
It is checked that all the tools required by the program are
in the machine.

See documentation of iso14649_read regarding the setting of the
action_flag and the return value.

*/

int iso14649_open(       /* ARGUMENTS                                 */
 const char * file_name) /* name of input ISO 14649 STEP Part 21 file */
{
  static char name[] = "iso14649_open";

  CHK((_world.design != 0), A_FILE_MUST_NOT_BE_ALREADY_OPEN);
  CHK((strlen(file_name) > (ISO14649_TEXT_SIZE - 1)),
      FILE_NAME_MUST_NOT_BE_TOO_LONG);
  if (parseOneFile(file_name, 0, true))
    CHK(1, INPUT_FILE_MUST_BE_READABLE);
  else
    _world.design = tree;
  IFF(check_and_store());
  IFF(check_tools(_world.execs));
  SPINDLE_RETRACT();
  _world.action_flag = ISO14649_SET_RETRACT;

  strcpy(_world.filename, file_name);
  return ISO14649_FINISH;
}

/***********************************************************************/

/* iso14649_read

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise, if all workingsteps have been executed, this returns
   ISO14649_ENDFILE.
   Otherwise it returns ISO14649_OK.
   1. The external queue is not empty: EXTERNAL_QUEUE_MUST_BE_EMPTY
   2. When the spindle is fully retracted, the tool tip is below the
      setup security plane:
      TOOL_MUST_BE_ABLE_TO_RETRACT_TO_SETUP_SECURITY_PLANE.
   3. The value of the action_flag is not ISO14649_SET_RETRACT,
      ISO14649_SET_POSITION, or ISO14649_NO_ACTION:
      ACTION_FLAG_VALUE_MUST_HAVE_KNOWN_MEANING.

Side Effects: See below

Called By: external programs

This does not actually read anything. It sets _world.iter to the next
workingstep to be executed. If started is zero, that will be
_world.execs->begin() (and started will be set to 1).  Otherwise, it
will be ++(_world.iter).

When _world.iter gets to be _world.execs->end(), either all
workingsteps have been executed or there were no workingsteps in the
first place. This serves as the signal to set starter back to zero
and return ISO14649_ENDFILE.

If the _world.action_flag is set to ISO14649_SET_RETRACT, this sets
the current position and sets _world.retracted_z to the current
z_position plus the current tool length offset (so that retracted_z
represents the fully retracted position when no tool is being
used). _world.action_flag is set to ISO14649_SET_RETRACT only by
ISO14649_open, since the location of the setup is changed when and
only when a new program is opened (changing the location has the side
effect of changing the value of the fully retracted position). To
insure that the spindle is fully retracted when this function is
called, the last motion commanded by iso14649_open is a
SPINDLE_RETRACT.  Also, iso14649_open returns ISO14649_FINISH so that
the controller will empty the motion queue before calling
iso14649_read. It may happen that the spindle cannot be retracted far
enough to get the tool above security_z_setup (which is also set while
executing iso14649_open). That is checked here.

If the _world.action_flag is set to ISO14649_SET_POSITION, this sets
the current position. The flag is set that way when change_tool is
called. The tool change operation may change the position of the
controlled point.

*/

int iso14649_read() /* NO ARGUMENTS */
{
  static char name[] = "iso14649_read";
  static int started = 0;

  if ((_world.action_flag == ISO14649_SET_RETRACT) OR
      (_world.action_flag == ISO14649_SET_POSITION))
    {
      CHK((NOT(GET_EXTERNAL_QUEUE_EMPTY())), EXTERNAL_QUEUE_MUST_BE_EMPTY);
      _world.current_x = GET_EXTERNAL_POSITION_X();
      _world.current_y = GET_EXTERNAL_POSITION_Y();
      _world.current_z = GET_EXTERNAL_POSITION_Z();
      if (_world.action_flag == ISO14649_SET_RETRACT)
	{
	  _world.retracted_z =
	    (_world.current_z + GET_EXTERNAL_TOOL_LENGTH_OFFSET());
	  CHK((_world.current_z < _world.security_z_setup),
	      TOOL_MUST_BE_ABLE_TO_RETRACT_TO_SETUP_SECURITY_PLANE);
	}
      _world.action_flag = ISO14649_NO_ACTION;
    }
  else if (_world.action_flag != ISO14649_NO_ACTION)
    CHK(1, ACTION_FLAG_VALUE_MUST_HAVE_KNOWN_MEANING);
  if (started)
    ++(_world.iter);
  else
    {
      _world.iter = _world.execs->begin();
      started = 1;
    }
  if (_world.iter == _world.execs->end())
    {
      started = 0;
      return ISO14649_ENDFILE;
    }
  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_reset

Returned Value: int (ISO14649_OK)

Side Effects: See below

Called By:
  external programs
  iso14649_close

This is intended to reset only those parts of the world model that
need to be reset after executing one workingstep (successfully or
not).

This function currently does nothing, so it might be eliminated. A
better change would be to upgrade the function so that it may be
called after an error occurs to clean up the environment well enough
that it is possible to continue executing the program. Currently, an
attempt to continue after an error is usually unsuccessful and results
in a system crash. Resetting adequately after an error is very
difficult and is most likely to result in the same error occurring
again, even if successful.

*/

int iso14649_reset() /* NO ARGUMENTS */
{
  
  return ISO14649_OK;
}

/***********************************************************************/

/* iso14649_synch

Returned Value: int
   If any of the following errors occur, this returns the error code shown.
   Otherwise it returns ISO14649_OK.
   1. iso14649_load_tool_table returns an error code.

Side Effects: See below

Called By:
  external programs
  iso14649_init

This function synchronizes values in the interpreter's world model
(_world) with values in some external world model that is better
informed and is programmed to respond to GET_EXTERNAL_... function
calls.

Values in the _world model that may be obtained by calling
GET_EXTERNAL... functions are updated by calling those functions.
Also, the tool table is reloaded.

*/

int iso14649_synch() /* NO ARGUMENTS */
{
  static char name[] = "iso14649_synch";
  _world.control_mode = GET_EXTERNAL_MOTION_CONTROL_MODE();
  _world.current_tool_index = GET_EXTERNAL_TOOL_INDEX();
  _world.current_x = GET_EXTERNAL_POSITION_X();
  _world.current_y = GET_EXTERNAL_POSITION_Y();
  _world.current_z = GET_EXTERNAL_POSITION_Z();
  _world.feedrate = GET_EXTERNAL_FEED_RATE();
  _world.flood = (GET_EXTERNAL_FLOOD() != 0) ? ON : OFF;
  _world.mist = (GET_EXTERNAL_MIST() != 0) ? ON : OFF;
  _world.speed = GET_EXTERNAL_SPEED();
  _world.spindle_turning = GET_EXTERNAL_SPINDLE();
  _world.tool_max = GET_EXTERNAL_TOOL_MAX();
  _world.traverse_rate = GET_EXTERNAL_TRAVERSE_RATE();

  IFF(iso14649_load_tool_table());
  return ISO14649_OK;
}

/****************************************************************************/
/****************************************************************************/

/*

The functions in this section of this file are functions for external
programs to call to get information from the iso14649 interpreter. They
are declared in iso14649.hh.

*/

/***********************************************************************/

/* iso14649_current_action

Returned Value: none

Side Effects: See below

Called By: external programs

This makes a string describing the state of the _world and (if the
string is shorter than max_size) copies it into action_text. If the
string is not shorter than max_size, this copies an empty string into
action_text.

*/

void iso14649_current_action( /* ARGUMENTS                            */
 char * action_text,          /* string to copy file name into        */
 int max_size)                /* maximum number of characters to copy */
{
  char buffer[1000];
  sprintf(buffer, "Executed workingstep %s\n", (*(_world.iter))->get_itsId());
  if ((int)strlen(buffer) < max_size)
    strcpy(action_text, buffer);
  else
    action_text[0] = 0;
}

/***********************************************************************/

/* iso14649_error_text

Returned Value: none

Side Effects: see below

Called By: external programs

This copies the error string whose index in the _iso14649_errors array
is error_code into the error_text array -- unless the error_code is
an out-of-bounds index or the length of the error string is not less
than max_size, in which case an empty string is put into the
error_text. The length of the error_text array should be at least
max_size.

*/

void iso14649_error_text( /* ARGUMENTS                            */
 int error_code,          /* code number of error                 */
 char * error_text,       /* char array to copy error text into   */
 int max_size)            /* maximum number of characters to copy */
{
  if (((error_code > -1) && (error_code <= ISO14649_MAX_ERROR)) &&
      ((int)strlen(_iso14649_errors[error_code]) < max_size))
    {
      strcpy(error_text, _iso14649_errors[error_code]);
    }
  else
    error_text[0] = 0;
}

/***********************************************************************/

/* iso14649_file_name

Returned Value: none

Side Effects: See below

Called By: external programs

If the name of the currently open ISO 14649 file is shorter than max_size,
this copies it into action_text. If not, this copies as much of 
"name too long" as will fit into action_text.

If no ISO 14649 file is open, the file name will be the empty string.

*/

void iso14649_file_name( /* ARGUMENTS                            */
 char * file_name,       /* string to copy into                  */
 int max_size)           /* maximum number of characters to copy */
{
  int n;
  char buffer[14];

  if ((int)strlen(_world.filename) < max_size)
    strcpy(file_name, _world.filename);
  else
    {
      strcpy(buffer, "name too long");
      for (n = 0; ((n < 14) && (n < (max_size - 1))); n++)
	file_name[n] = buffer[n];
      file_name[n] = 0;
    }
}

/***********************************************************************/

/* iso14649_name_text

Returned Value: none

Side Effects: See below

Called By: external programs

If the name of the currently selected workingstep is shorter than
max_size, this copies it into name_text. If not, this copies an empty
string into name_text.

*/

void iso14649_name_text( /* ARGUMENTS                            */
 char * name_text,       /* string to copy into                  */
 int max_size)           /* maximum number of characters to copy */
{
  char buffer[1000];
  
  if(_world.iter != _world.execs->end())
    sprintf(buffer, "%s", (*(_world.iter))->get_itsId());
  else
    buffer[0] = 0;
  if ((int)strlen(buffer) < max_size)
    strcpy(name_text, buffer);
  else
    name_text[0] = 0;
}

/***********************************************************************/

/* iso14649_stack_name

Returned Value: none

Side Effects: see below

Called By: external programs

This copies at most (max_size - 1) non-null characters from the
string whose index in the _world.stack array is stack_index into the
function_name string and puts a NULL after the last non-null character --
unless the stack_index is an out-of-bounds index, in which case an
empty string is put into the function_name.

This function is intended to be used several times in a row to get the
stack of function calls that existed when the most recent error
occurred. It should be called first with stack_index equal to 0,
next with stack_index equal to 1, and so on, stopping when an
empty string is returned for the name.

*/

void iso14649_stack_name( /* ARGUMENTS                            */
 int stack_index,         /* index into stack of function names   */
 char * function_name,    /* string: to copy function name into   */
 int max_size)            /* maximum number of characters to copy */
{
  int n;
  char * the_name;

  if ((stack_index > -1) && (stack_index < 20))
    {
      the_name = _world.stack[stack_index];
      for (n = 0; n < (max_size - 1); n++)
        {
          if (the_name[n] != 0)
            function_name[n] = the_name[n];
          else
            break;
        }
      function_name[n] = 0;
    }
  else
    function_name[0] = 0;
}

/***********************************************************************/
