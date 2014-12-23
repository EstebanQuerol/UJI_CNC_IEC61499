/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

#include <stdio.h>            // for fopen, etc.
#include <stdlib.h>           // for exit
#include "iso14649classesDirect.hh" // for inputFile, etc.

extern int parseOneFile(const char * fileName, char * report, bool quiet);
extern void parseManyFiles(char * fileName, char * report);
extern void printDouble(double num);
extern inputFile * tree;

void printApproval(approval * approve, int spaces);
void printAxis2(axis2placement3d * sys, int spaces);
void printBoss(boss * feat, int spaces);
void printBottomCondition(holeBottomCondition * bottom, int spaces);
void printCartPoint(cartesianPoint * pt, int spaces);
void printChannel(channel * chan, int spaces);
void printClosedPocket(closedPocket * feat, int spaces);
void printDateAndTime(dateAndTime * dat, int spaces);
void printDirection(direction * dir, int spaces);
void printDrillingTypeOp(drillingTypeOperation * op, int spaces);
void printEffect(inProcessGeometry * effect, int spaces);
void printElement(executable * ex, int spaces);
void printElements(parenExecutableList * liz, int spaces);
void printMachiningFeature(machiningFeature * feat, int spaces);
void printMachiningWorkingstep(machiningWorkingstep * step, int spaces);
void printManufacturingFeature(manufacturingFeature * feat, int spaces);
void printMillingTypeOp(millingTypeOperation * op, int spaces);
void printNcFunction(ncFunction * func, int spaces);
void printOperation(machiningOperation * op, int spaces);
void printOwner(personAndAddress * owner, int spaces);
void printPlanarFace(planarFace * feat, int spaces);
void printPlane(char * use, plane * plain, int spaces);
void printPocket(pocket * feat, int spaces);
void printProgramStructure(programStructure * struc, int spaces);
void printProject(project * proj);
void printRapidMovement(rapidMovement * step, int spaces);
void printRoundHole(roundHole * feat, int spaces);
void printSetup(setup * set, int spaces);
void printTree();
void printTwo5Feature(two5DmanufacturingFeature * feat, int spaces);
void printUnknown(char * thing, int spaces);
void printWorkingstep(workingstep * step, int spaces);
void printWorkpiece(workpiece * work, int spaces);
void printWorkpieces(parenWorkpieceList * workpieces, int spaces);
void printWorkplan(workplan * plan, int spaces);


/********************************************************************/

/* main

This is the main routine for the iso14649parser. The parser may be used
two different ways.

A. The parser may be used to parse one ISO 14649 Part 21 file
corresponding to Parts 10 and 11 of ISO 14649. To use it that way, it
should be called with one argument which is the path to the file,
and the file must have a .stp suffix.
For example: bin/iso14649parser data/ex1.stp.
When the parser is used this way, it:
1. reads and stores the contents of the file. If there are errors
   in parsing, an error message is printed for each error describing
   the error and printing the line of the input file that caused the
   error, up to the point at which the error occurred.
2. prints the number of errors it found,
3. prints the file out again, and
4. if there were no errors, prints part of the parse tree that was created
   by parsing the file.

B. The parser may also be used to parse many such files. To use it that way,
it should be called with one argument which is the path to a file
containing the paths to the files to parse, and the file must not have
a .stp suffix.
For example: bin/iso14649parser data/filenames
When the parser is used this way, for each input file it:
1. prints the name of the file,
2. reads and stores the contents of the file, printing error messages
   as described above, and
3. prints the number of errors it found.

The reprinting of the input file is accomplished here by the call of
tree->printSelf(). The functions that do the printing are defined in
iso14649classes.cc. These functions are complete. If the input file
is formatted using the same format rules as are implemented in
iso14649classes.cc (spaces, upper case letters, leading and trailing
zeros in numbers, etc.), the output will be identical to the input.

The printing of the parse tree is accomplished by the call to printTree,
the subordinate functions of which are in this file. Only the part of
the tree near the root is printed. The printTree function was written
as an aid in debugging, and once it showed enough to be useful for
that purpose, development stopped.

Each function prints information about an item and then calls the
printers for the components of the item. Depth in the hierarchy is
indicated by depth of indenting.

*/

int main(       /* ARGUMENTS                     */
 int argc,      /* number of arguments plus one  */
 char * argv[]) /* text of command and arguments */
{
  if ((argc != 2) && (argc != 3))
    {
      fprintf(stderr,
	      "Usage: %s <input file name>\n",
	      argv[0]);
      fprintf(stderr,
	      "   Or: %s <input file name> <output file name>\n",
	      argv[0]);
      exit(1);
    }
  if (strcmp((argv[1] + strlen(argv[1]) - 4), ".stp") == 0)
    { // argv[1] is a Part 21 file name
      if (parseOneFile(argv[1], ((argc == 3) ? argv[2] : 0), false) == 0)
	{
	  tree->printSelf();
	  printTree();
	}
    }
  else
    { // argv[1] is the name of a file containing Part 21 file names
      parseManyFiles(argv[1], ((argc == 3) ? argv[2] : 0));
    }
  return 0;
}

/********************************************************************/

/* printApproval

Called By:  printProject 

Side Effects: This prints an approval.

*/

void printApproval(  /* ARGUMENTS                      */
 approval * approve, /* approval to print              */
 int spaces)         /* number of spaces starting line */
{
   int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  if (approve)
    printf("approval #%d\n", approve->iId->val);
  else
    printf("approval NONE\n");
}

/********************************************************************/

/* printAxis2

Called By:
  printPlane
  printRoundHole
  printSetup

Side Effects: This prints an axis2placement3d

*/

void printAxis2(         /* ARGUMENTS                      */
 axis2placement3d * sys, /* axis2placement3d to print      */
 int spaces)             /* number of spaces starting line */
{
  int n;
  
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("axis2placement3d #%d '%s'\n",
	 sys->iId->val, sys->name);
  printCartPoint(sys->location, (spaces+2));
  printDirection(sys->axis, (spaces+2));
  printDirection(sys->refDirection, (spaces+2));
}

/********************************************************************/

/* printBoss

Called By:  printMachiningFeature

Side Effects: This prints a boss.

*/

void printBoss( /* ARGUMENTS                      */
 boss * feat,   /* boss to print                  */
 int spaces)    /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("boss #%d '%s'\n",
	 feat->iId->val, feat->itsId);
}

/********************************************************************/

/* printBottomCondition

Called By:  printRoundHole

Side Effects: This prints a holeBottomCondition.

*/

void printBottomCondition(     /* ARGUMENTS                      */
 holeBottomCondition * bottom, /* holeBottomCondition to print   */
 int spaces)                   /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  if (bottom->isA(flatHoleBottom_E))
    printf("flatHoleBottom\n");
  else if (bottom->isA(flatWithRadiusHoleBottom_E))
    {
      printf("flatHoleBottom radius \n");
    }
  else if (bottom->isA(sphericalHoleBottom_E));
  else if (bottom->isA(conicalHoleBottom_E));
  else if (bottom->isA(throughBottomCondition_E))
    printf("throughHoleBottom\n");
}

/********************************************************************/

/* printCartPoint

Called By:  printAxis2

Side Effects: This prints a cartesianPoint

*/

void printCartPoint(  /* ARGUMENTS                      */
 cartesianPoint * pt, /* cartesianPoint to print        */
 int spaces)          /* number of spaces starting line */
{
  std::list <real *> * coords;
  std::list<real *>::iterator iter;
  int n;
  
  coords = pt->coordinates->theList;
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("cartesianPoint #%d '%s' (", pt->iId->val, pt->name);
  for (iter = coords->begin(); ; )
    {
      printDouble((*iter)->val);
      if (++iter == coords->end())
	break;
      printf(",");
    }
  printf(")\n");
}

/********************************************************************/

/* printChannel

Called By:  printWorkplan

Side Effects: This prints a channel.

*/

void printChannel( /* ARGUMENTS                      */
 channel * chan,   /* channel to print               */
 int spaces)       /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("channel ");
  if (chan)
    printf("YES\n");
  else
    printf("NO\n");
}

/********************************************************************/

/* printClosedPocket

Called By:  printPocket

Side Effects: This prints a closedPocket.

*/

void printClosedPocket( /* ARGUMENTS                      */
 closedPocket * feat,   /* closedPocket to print          */
 int spaces)            /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("closedPocket #%d '%s'\n",
	 feat->iId->val, feat->itsId);
}

/********************************************************************/

/* printDateAndTime

Called By:  printProject 

Side Effects: This prints a dateAndTime.

*/

void printDateAndTime( /* ARGUMENTS                      */
 dateAndTime * dat,    /* dateAndTime to print           */
 int spaces)           /* number of spaces starting line */
{
   int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  if (dat)
    printf("date and time #%d\n", dat->iId->val);
  else
    printf("date and time NONE\n");
}

/********************************************************************/

/* printDirection

Called By: printAxis2

Side Effects: This prints a direction.

*/

void printDirection( /* ARGUMENTS                      */
 direction * dir,    /* direction to print             */
 int spaces)         /* number of spaces starting line */
{
  std::list <real *> * coords;
  std::list<real *>::iterator iter;
  int n;
  
  coords = dir->directionRatios->theList;
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("direction #%d '%s' (", dir->iId->val, dir->name);
  for (iter = coords->begin(); ; )
    {
      printDouble((*iter)->val);
      if (++iter == coords->end())
	break;
      printf(",");
    }
  printf(")\n");
}

/********************************************************************/

/* printDrillingTypeOp

Called By:  printOperation

Side Effects: This prints a drillingTypeOperation.

*/

void printDrillingTypeOp(    /* ARGUMENTS                      */
 drillingTypeOperation * op, /* drillingTypeOperation to print */
 int spaces)                 /* number of spaces starting line */
{
  int n;
  
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("drilling operation #%d '%s'\n", 
	 (dynamic_cast<instance *>(op))->iId->val,
	 op->itsId);
}

/********************************************************************/

/* printEffect

Called By:
  printMachiningWorkingstep
  printWorkplan

Side Effects: This prints "effect YES" if effect is non-NULL and
              "effect NO" if effect is NULL.

*/

void printEffect(            /* ARGUMENTS                      */
 inProcessGeometry * effect, /* inProcessGeometry              */
 int spaces)                 /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("effect ");
  if (effect)
    printf("YES\n");
  else
    printf("not given\n");
}

/********************************************************************/

/* printElement

Called By:  printElements

Side Effects: This prints an executable.

*/

void printElement( /* ARGUMENTS                      */
 executable * ex,  /* executable to print            */
 int spaces)       /* number of spaces starting line */
{
  if (ex->isA(ncFunction_E))
    printNcFunction(dynamic_cast<ncFunction *>(ex), spaces);
  else if (ex->isA(programStructure_E))
    printProgramStructure(dynamic_cast<programStructure *>(ex), spaces);
  else if (ex->isA(workingstep_E))
    printWorkingstep(dynamic_cast<workingstep *>(ex), spaces);
  else
    printUnknown("executable", spaces);
}

/********************************************************************/

/* printElements

Called By:  printWorkplan

Side Effects: This prints a list of executables.

*/

void printElements(         /* ARGUMENTS                      */
 parenExecutableList * liz, /* list of executables to print   */
 int spaces)                /* number of spaces starting line */
{
  int n;
  std::list<executable *> * theList;
  std::list<executable *>::iterator iter;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("elements");
  theList = liz->theList;
  if (theList->begin() == theList->end())
    printf(" NONE\n");
  else
    {
      printf("\n");
      for (iter = theList->begin(); iter != theList->end(); ++iter)
	{
	  printElement(*iter, (spaces+2));
	}
    }
}

/********************************************************************/

/* printMachiningFeature

Called By:  printTwo5Feature

Side Effects: This prints a machiningFeature.

*/

void printMachiningFeature( /* ARGUMENTS                      */
 machiningFeature * feat,   /* machiningFeature to print      */
 int spaces)                /* number of spaces starting line */
{
  if (feat->isA(boss_E))
    printBoss(dynamic_cast<boss *>(feat), spaces);
  else if (feat->isA(planarFace_E))
    printPlanarFace(dynamic_cast<planarFace *>(feat), spaces);
  else if (feat->isA(pocket_E))
    printPocket(dynamic_cast<pocket *>(feat), spaces);
  else if (feat->isA(roundHole_E))
    printRoundHole(dynamic_cast<roundHole *>(feat), spaces);
  else
    printUnknown("machiningFeature", spaces);
}

/********************************************************************/

/* printMachiningWorkingstep

Called By:  printWorkingstep

Side Effects: This prints a machiningWorkingstep

*/

void printMachiningWorkingstep( /* ARGUMENTS                      */
 machiningWorkingstep * step,   /* machiningWorkingstep to print  */
 int spaces)                    /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("machiningWorkingstep #%d '%s'\n", 
	 step->iId->val, step->itsId);
  if (step->itsSecplane->isA(plane_E))
    printPlane("security",
	       dynamic_cast<plane *>(step->itsSecplane), (spaces+2));
  else
    {
      for (n=0; n < spaces; n++)
	putchar(' ');
      printf("security plane is not a plane\n");
    }
  printManufacturingFeature(step->itsFeature, (spaces+2));
  printOperation(step->itsOperation, (spaces+2));
  printEffect(step->itsEffect, (spaces+2));
}

/********************************************************************/

/* printManufacturingFeature

Called By:  printMachiningWorkingstep

Side Effects: This prints a manufacturingFeature.

*/

void printManufacturingFeature( /* ARGUMENTS                      */
 manufacturingFeature * feat,   /* manufacturingFeature to print  */
 int spaces)                    /* number of spaces starting line */
{
  int n;

  if (feat->isA(region_E))
    {
      for (n=0; n < spaces; n++)
	putchar(' ');
      printf("region #%d '%s' CANNOT HANDLE REGION\n", 
	     (dynamic_cast<instance *>(feat))->iId->val,
	     feat->itsId);
    }
  else if (feat->isA(two5DmanufacturingFeature_E))
    printTwo5Feature(dynamic_cast<two5DmanufacturingFeature *>(feat),
		     spaces);
  else if (feat->isA(transitionFeature_E))
    {
      for (n=0; n < spaces; n++)
	putchar(' ');
      printf("transitionFeature #%d '%s' CANNOT HANDLE TRANSITION FEATURE\n", 
	     (dynamic_cast<instance *>(feat))->iId->val,
	     feat->itsId);
    }
}

/********************************************************************/

/* printMillingTypeOp

Called By: printOperation

Side Effects: This prints a millingTypeOperation.

*/

void printMillingTypeOp(    /* ARGUMENTS                      */
 millingTypeOperation * op, /* millingTypeOperation to print  */
 int spaces)                /* number of spaces starting line */
{
  int n;
  
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("milling operation #%d '%s'\n", 
	 (dynamic_cast<instance *>(op))->iId->val,
	 op->itsId);
}

/********************************************************************/

/* printNcFunction

Called By:  printElement

Side Effects: This prints an ncFunction.

*/

void printNcFunction( /* ARGUMENTS                      */
 ncFunction * func,   /* the ncFunction to print        */
 int spaces)          /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("ncFunction #%d \n", 
	 (dynamic_cast<instance *>(func))->iId->val);
}

/********************************************************************/

/* printOperation

Called By:  printMachiningWorkingstep

Side Effects: This prints a machiningOperation.

*/

void printOperation(      /* ARGUMENTS                       */
 machiningOperation * op, /* the machiningOperation to print */
 int spaces)              /* number of spaces starting line  */
{
  if (op->isA(drillingTypeOperation_E))
    printDrillingTypeOp(dynamic_cast<drillingTypeOperation *>(op), spaces);
  else if (op->isA(millingTypeOperation_E))
    printMillingTypeOp(dynamic_cast<millingTypeOperation *>(op), spaces);
  else
    printUnknown("machiningOperation", spaces);
}

/********************************************************************/

/* printOwner

Called By:  printProject

Side Effects:  This prints a personAndAddress.

Owner is optional, so it may be NULL.

*/

void printOwner(           /* ARGUMENTS                      */
 personAndAddress * owner, /* the personAndAddress to print  */
 int spaces)               /* number of spaces starting line */
{
  int n;
  
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("owner ");
  if (owner)
    printf("#%d '%s'\n", owner->iId->val,
	   owner->itsPerson->id);
  else
    printf(" NONE\n");
}

/********************************************************************/

/* printPlanarFace

Called By:

Side Effects: This prints a planarFace.

*/

void printPlanarFace( /* ARGUMENTS                      */
 planarFace * feat,   /* planarFace to print            */
 int spaces)          /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("planarFace #%d '%s'\n",
	 feat->iId->val, feat->itsId);
}

/********************************************************************/

/* printPlane

Called By:
  printMachiningWorkingstep
  printRoundHole
  printSetup

Side Effects: This prints a plane.

*/

void printPlane( /* ARGUMENTS                      */
 char * use,     /* usually "depth" or "security"  */
 plane * plain,  /* the plane to print             */
 int spaces)     /* number of spaces starting line */
{
  int n;
  
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("%s plane #%d '%s'\n", use,
	 plain->iId->val, plain->name);
  printAxis2(plain->position, (spaces+2));
}

/********************************************************************/

/* printPocket

Called By:  printMachiningFeature

Side Effects: This prints a pocket.

*/

void printPocket( /* ARGUMENTS                      */
 pocket * feat,   /* the pocket to print            */
 int spaces)      /* number of spaces starting line */
{
  if (feat->isA(closedPocket_E))
    printClosedPocket(dynamic_cast<closedPocket *>(feat), spaces);
  else
    printUnknown("pocket", spaces);
}

/********************************************************************/

/* printProgramStructure

Called By:  printElement

Side Effects: This prints a programStructure.

*/

void printProgramStructure( /* ARGUMENTS                      */
 programStructure * struc,  /* programStructure to print      */
 int spaces)                /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("programStructure #%d \n", 
	 (dynamic_cast<instance *>(struc))->iId->val);
}

/********************************************************************/

/* printProject

Called By:  printTree

Side Effects: This prints a project.

*/

void printProject( /* ARGUMENTS            */
 project * proj)   /* the project to print */
{
  printf("project #%d '%s'\n", proj->iId->val, proj->itsId);
  printWorkplan(proj->mainWorkplan, 2);
  printWorkpieces(proj->itsWorkpieces, 2);
  printOwner(proj->itsOwner, 2);
  printDateAndTime(proj->itsRelease, 2);
  printApproval(proj->itsStatus, 2);
}

/********************************************************************/

/* printRapidMovement

Called By:  printWorkingstep

Side Effects: This prints a rapidMovement.

*/

void printRapidMovement( /* ARGUMENTS                      */
 rapidMovement * step,   /* rapidMovement to print         */
 int spaces)             /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("rapidMovement #%d '%s'\n", 
	 step->iId->val, step->itsId);
}

/********************************************************************/

/* printRoundHole

Called By:  printMachiningFeature

Side Effects: This prints a roundHole.

*/

void printRoundHole( /* ARGUMENTS                      */
 roundHole * feat,   /* roundHole to print             */
 int spaces)         /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("roundHole #%d '%s'\n",
	 feat->iId->val, feat->itsId);
  spaces = (spaces+2);
  printAxis2(feat->featurePlacement, spaces);
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("diameter ");
  printDouble(feat->diameter->theoreticalSize);
  printf("\n");
  if (feat->depth->isA(plane_E))
    printPlane("depth", dynamic_cast<plane *>(feat->depth), spaces);
  printBottomCondition(feat->bottomCondition, spaces);
}

/********************************************************************/

/* printSetup

Called By:  printWorkplan

Side Effects: This prints a setup.

*/

void printSetup( /* ARGUMENTS                      */
 setup * set,    /* setup to print                 */
 int spaces)     /* number of spaces starting line */
{
  int n;
  elementarySurface * surf;
  
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("setup #%d '%s'\n", set->iId->val, set->itsId);
  printAxis2(set->itsOrigin, (spaces+2));
  surf = dynamic_cast<elementarySurface *>(set->itsSecplane);
  if (surf->isA(plane_E))
    printPlane("security", dynamic_cast<plane *>(surf), (spaces+2));
  else
    {
      for (n=0; n < spaces; n++)
	putchar(' ');
      printf("security plane is not a plane\n");
    }
}

/********************************************************************/

/* printTree

Called By:  main

Side Effects: This prints the data section of a parse tree.

This is expecting the first item in the data section of the tree to be
a project. It would be useful to change this to look through the items
(a list of instances) and find the project, since there is no requirement
that the project be the first item.

*/

void printTree() /* NO ARGUMENTS */
{
  dataSection * input;
  std::list<instance *> * items;

  input = tree->inputData;
  items = input->items;
  if (items->front()->isA(project_E))
    {
      printProject(dynamic_cast<project *>(items->front()));
    }
  else
    printf("first item is not a project\n");
}

/********************************************************************/

/* printTwo5Feature

Called By:  printManufacturingFeature

Side Effects: This prints a two5DmanufacturingFeature.

*/

void printTwo5Feature(             /* ARGUMENTS                          */
 two5DmanufacturingFeature * feat, /* two5DmanufacturingFeature to print */
 int spaces)                       /* number of spaces starting line     */
{
  int n;

  if (feat->isA(compoundFeature_E))
    {
      for (n=0; n < spaces; n++)
	putchar(' ');
      printf("compoundFeature\n");
    }
  else if (feat->isA(machiningFeature_E))
    printMachiningFeature(dynamic_cast<machiningFeature *>(feat), spaces);
  else
    printUnknown("two5DmanufacturingFeature", spaces);
}

/********************************************************************/

/* printUnknown

Called By:
  printElement
  printMachiningFeature
  printOperation
  printPocket
  printTwo5Feature
  printWorkingstep

Side Effects: This prints an item of unknown subtype.

*/

void printUnknown( /* ARGUMENTS                      */
 char * thing,     /* supertype of unknown thing     */
 int spaces)       /* number of spaces starting line */
{
  int n;

  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("Unknown %s type\n", thing);
}

/********************************************************************/

/* printWorkingstep

Called By:  printElement

Side Effects: This prints a workingstep.

*/

void printWorkingstep( /* ARGUMENTS                      */
 workingstep * step,   /* workingstep to print           */
 int spaces)           /* number of spaces starting line */
{
  if (step->isA(machiningWorkingstep_E))
    printMachiningWorkingstep(dynamic_cast<machiningWorkingstep *>(step),
			      spaces);
  else if (step->isA(rapidMovement_E))
      printRapidMovement(dynamic_cast<rapidMovement *>(step), spaces);
  else
    printUnknown("workingstep", spaces);
}

/********************************************************************/

/* printWorkpiece

Called By:  printWorkpieces

Side Effects: This prints a workpiece.

*/

void printWorkpiece( /* ARGUMENTS                      */
 workpiece * work,   /* workpiece to print             */
 int spaces)         /* number of spaces starting line */
{
  int n;
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("workpiece #%d '%s'\n", work->iId->val, work->itsId);
}

/********************************************************************/

/* printWorkpieces

Called By:  printProject

Side Effects: This prints a list of workpieces.

*/

void printWorkpieces(             /* ARGUMENTS                      */
 parenWorkpieceList * workpieces, /* list of workpieces to print    */
 int spaces)                      /* number of spaces starting line */
{
  int n;
  std::list<workpiece *> * theList;
  std::list<workpiece *>::iterator iter;
  
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("workpieces");
  theList = workpieces->theList;
  if (theList->begin() == theList->end())
    printf(" NONE\n");
  else
    {
      printf("\n");
      for (iter = theList->begin(); iter != theList->end(); ++iter)
	{
	  printWorkpiece(*iter, (spaces+2));
	}
    }
}

/********************************************************************/

/* printWorkplan

Called By:  printProject

Side Effects: This prints a workplan.

*/

void printWorkplan( /* ARGUMENTS                      */
 workplan * plan,   /* workplan to print              */
 int spaces)        /* number of spaces starting line */
{
  int n;
  
  for (n=0; n < spaces; n++)
    putchar(' ');
  printf("workplan #%d '%s'\n", plan->iId->val, plan->itsId);
  printElements(plan->itsElements, (spaces+2));
  printChannel(plan->itsChannel, (spaces+2));
  printSetup(dynamic_cast<setup *>(plan->itsSetup), (spaces+2));
  printEffect(plan->itsEffect, (spaces+2));
}

/********************************************************************/

