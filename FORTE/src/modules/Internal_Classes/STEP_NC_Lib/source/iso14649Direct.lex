%{

/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

#include <string.h>          // for strdup, etc.
#include <ctype.h>           // for isalpha
#include "iso14649classesDirect.hh"
#include "iso14649YACCDirect.hh"

#define ECH  for (k=0; ((k < yyleng) && (lineTextIndex < 4095));)\
    lineText[lineTextIndex++] = yytext[k++];\
    lineText[lineTextIndex] = 0

extern char lineText[];
extern char lexMessage[];
int lineTextIndex;
char stringText[4096];
int j;      // index for stringText
double num; // number to parse reals into
int k;      // utility index, used in ECH compiler macro

void shiftUpcase(
 char * text)
{
  int n;
  int first;
  char c;

  for (first = 0; text[first] <= ' '; first++);
  for (n = first; text[n] > ' '; n++)
    {
      c = text[n];
      text[n - first] = (islower(c) ? toupper(c) : c);
    }
  text[n - first] = 0;
}

%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]

_ [ \t\n\r]*

%x COMMENT
%x INSTRING
%x INID

%%

{_}{A}{D}{D}{R}{E}{S}{S}{_}             {ECH; return ADDRESS;}
{_}{A}{D}{V}{A}{N}{C}{E}{D}"_"{B}{R}{E}{P}"_"{S}{H}{A}{P}{E}"_"{R}{E}{P}{R}{E}{S}{E}{N}{T}{A}{T}{I}{O}{N}{_} {ECH; return ADVANCEDBREPSHAPEREPRESENTATION;}
{_}{A}{D}{V}{A}{N}{C}{E}{D}"_"{F}{A}{C}{E}{_} {ECH; return ADVANCEDFACE;}
{_}"."{A}{H}{E}{A}{D}"."{_}             {ECH; return AHEADORBEHINDAHEAD;}
{_}"."{B}{E}{H}{I}{N}{D}"."{_}          {ECH; return AHEADORBEHINDBEHIND;}
{_}"."{E}{X}{A}{C}{T}"."{_}             {ECH; return AHEADORBEHINDEXACT;}
{_}{A}{L}{O}{N}{G}"_"{P}{A}{T}{H}{_}    {ECH; return ALONGPATH;}
{_}{A}{N}{D}"_"{E}{X}{P}{R}{E}{S}{S}{I}{O}{N}{_} {ECH; return ANDEXPRESSION;}
{_}{A}{N}{G}{L}{E}"_"{T}{A}{P}{E}{R}{_} {ECH; return ANGLETAPER;}
{_}{A}{P}"_"{L}{I}{F}{T}"_"{P}{A}{T}{H}"_"{A}{N}{G}{L}{E}{_} {ECH; return APLIFTPATHANGLE;}
{_}{A}{P}"_"{L}{I}{F}{T}"_"{P}{A}{T}{H}"_"{T}{A}{N}{G}{E}{N}{T}{_} {ECH; return APLIFTPATHTANGENT;}
{_}{A}{P}{P}{R}{O}{V}{A}{L}{_}          {ECH; return APPROVAL;}
{_}{A}{P}{P}{R}{O}{V}{A}{L}"_"{S}{T}{A}{T}{U}{S}{_} {ECH; return APPROVALSTATUS;}
{_}{A}{P}"_"{R}{E}{T}{R}{A}{C}{T}"_"{A}{N}{G}{L}{E}{_} {ECH; return APRETRACTANGLE;}
{_}{A}{P}"_"{R}{E}{T}{R}{A}{C}{T}"_"{T}{A}{N}{G}{E}{N}{T}{_} {ECH; return APRETRACTTANGENT;}
{_}{A}{S}{S}{I}{G}{N}{M}{E}{N}{T}{_}    {ECH; return ASSIGNMENT;}
{_}{A}{X}{I}{S}"1""_"{P}{L}{A}{C}{E}{M}{E}{N}{T}{_} {ECH; return AXIS1PLACEMENT;}
{_}{A}{X}{I}{S}"2""_"{P}{L}{A}{C}{E}{M}{E}{N}{T}"_""3"{D}{_} {ECH; return AXIS2PLACEMENT3D;}
{_}{A}{X}{I}{S}"_"{T}{R}{A}{J}{E}{C}{T}{O}{R}{Y}{_} {ECH; return AXISTRAJECTORY;}
{_}{B}{A}{C}{K}"_"{B}{O}{R}{I}{N}{G}{_} {ECH; return BACKBORING;}
{_}{B}{A}{C}{K}{S}{I}{D}{E}"_"{C}{O}{U}{N}{T}{E}{R}{B}{O}{R}{E}{_} {ECH; return BACKSIDECOUNTERBORE;}
{_}{B}{A}{C}{K}{S}{I}{D}{E}"_"{C}{O}{U}{N}{T}{E}{R}{S}{I}{N}{K}{_} {ECH; return BACKSIDECOUNTERSINK;}
{_}{B}{A}{L}{L}"_"{E}{N}{D}{M}{I}{L}{L}{_} {ECH; return BALLENDMILL;}
{_}{B}{E}{Z}{I}{E}{R}"_"{C}{U}{R}{V}{E}{_} {ECH; return BEZIERCURVE;}
{_}{B}{E}{Z}{I}{E}{R}"_"{S}{U}{R}{F}{A}{C}{E}{_} {ECH; return BEZIERSURFACE;}
{_}{B}{I}{D}{I}{R}{E}{C}{T}{I}{O}{N}{A}{L}"_"{C}{O}{N}{T}{O}{U}{R}{_} {ECH; return BIDIRECTIONALCONTOUR;}
{_}{B}{I}{D}{I}{R}{E}{C}{T}{I}{O}{N}{A}{L}"_"{M}{I}{L}{L}{I}{N}{G}{_} {ECH; return BIDIRECTIONALMILLING;}
{_}{B}{L}{O}{C}{K}{_}                   {ECH; return BLOCK;}
{_}{B}{O}{R}{I}{N}{G}{_}                {ECH; return BORING;}
{_}{B}{O}{R}{I}{N}{G}"_"{T}{O}{O}{L}{_} {ECH; return BORINGTOOL;}
{_}{B}{O}{S}{S}{_}                      {ECH; return BOSS;}
{_}{B}{O}{T}{T}{O}{M}"_"{A}{N}{D}"_"{S}{I}{D}{E}"_"{F}{I}{N}{I}{S}{H}"_"{M}{I}{L}{L}{I}{N}{G}{_} {ECH; return BOTTOMANDSIDEFINISHMILLING;}
{_}{B}{O}{T}{T}{O}{M}"_"{A}{N}{D}"_"{S}{I}{D}{E}"_"{R}{O}{U}{G}{H}"_"{M}{I}{L}{L}{I}{N}{G}{_} {ECH; return BOTTOMANDSIDEROUGHMILLING;}
{_}"."{B}{O}{T}{T}{O}{M}"."{_}          {ECH; return BOTTOMORSIDEBOTTOM;}
{_}"."{B}{O}{T}{T}{O}{M}"_"{A}{N}{D}"_"{S}{I}{D}{E}"."{_} {ECH; return BOTTOMORSIDEBOTTOMANDSIDE;}
{_}"."{S}{I}{D}{E}"."{_}                {ECH; return BOTTOMORSIDESIDE;}
{_}{B}{O}{U}{N}{D}{E}{D}"_"{P}{C}{U}{R}{V}{E}{_} {ECH; return BOUNDEDPCURVE;}
{_}"."{C}{I}{R}{C}{U}{L}{A}{R}"_"{A}{R}{C}"."{_} {ECH; return BSPLINECURVEFORMCIRCULARARC;}
{_}"."{E}{L}{L}{I}{P}{T}{I}{C}"_"{A}{R}{C}"."{_} {ECH; return BSPLINECURVEFORMELLIPTICARC;}
{_}"."{H}{Y}{P}{E}{R}{B}{O}{L}{I}{C}"_"{A}{R}{C}"."{_} {ECH; return BSPLINECURVEFORMHYPERBOLICARC;}
{_}"."{P}{A}{R}{A}{B}{O}{L}{I}{C}"_"{A}{R}{C}"."{_} {ECH; return BSPLINECURVEFORMPARABOLICARC;}
{_}"."{P}{O}{L}{Y}{L}{I}{N}{E}"_"{F}{O}{R}{M}"."{_} {ECH; return BSPLINECURVEFORMPOLYLINEFORM;}
{_}"."{U}{N}{S}{P}{E}{C}{I}{F}{I}{E}{D}"."{_} {ECH; return BSPLINECURVEFORMUNSPECIFIED;}
{_}{B}"_"{S}{P}{L}{I}{N}{E}"_"{C}{U}{R}{V}{E}"_"{W}{I}{T}{H}"_"{K}{N}{O}{T}{S}{_} {ECH; return BSPLINECURVEWITHKNOTS;}
{_}"."{C}{O}{N}{I}{C}{A}{L}"_"{S}{U}{R}{F}"."{_} {ECH; return BSPLINESURFACEFORMCONICALSURF;}
{_}"."{C}{Y}{L}{I}{N}{D}{R}{I}{C}{A}{L}"_"{S}{U}{R}{F}"."{_} {ECH; return BSPLINESURFACEFORMCYLINDRICALSURF;}
{_}"."{G}{E}{N}{E}{R}{A}{L}{I}{Z}{E}{D}"_"{C}{O}{N}{E}"."{_} {ECH; return BSPLINESURFACEFORMGENERALIZEDCONE;}
{_}"."{P}{L}{A}{N}{E}"_"{S}{U}{R}{F}"."{_} {ECH; return BSPLINESURFACEFORMPLANESURF;}
{_}"."{Q}{U}{A}{D}{R}{I}{C}"_"{S}{U}{R}{F}"."{_} {ECH; return BSPLINESURFACEFORMQUADRICSURF;}
{_}"."{R}{U}{L}{E}{D}"_"{S}{U}{R}{F}"."{_} {ECH; return BSPLINESURFACEFORMRULEDSURF;}
{_}"."{S}{P}{H}{E}{R}{I}{C}{A}{L}"_"{S}{U}{R}{F}"."{_} {ECH; return BSPLINESURFACEFORMSPHERICALSURF;}
{_}"."{S}{U}{R}{F}"_"{O}{F}"_"{L}{I}{N}{E}{A}{R}"_"{E}{X}{T}{R}{U}{S}{I}{O}{N}"."{_} {ECH; return BSPLINESURFACEFORMSURFOFLINEAREXTRUSION;}
{_}"."{S}{U}{R}{F}"_"{O}{F}"_"{R}{E}{V}{O}{L}{U}{T}{I}{O}{N}"."{_} {ECH; return BSPLINESURFACEFORMSURFOFREVOLUTION;}
{_}"."{T}{O}{R}{O}{I}{D}{A}{L}"_"{S}{U}{R}{F}"."{_} {ECH; return BSPLINESURFACEFORMTOROIDALSURF;}
{_}"."{U}{N}{S}{P}{E}{C}{I}{F}{I}{E}{D}"."{_} {ECH; return BSPLINESURFACEFORMUNSPECIFIED;}
{_}{B}"_"{S}{P}{L}{I}{N}{E}"_"{S}{U}{R}{F}{A}{C}{E}"_"{W}{I}{T}{H}"_"{K}{N}{O}{T}{S}{_} {ECH; return BSPLINESURFACEWITHKNOTS;}
{_}{B}{U}{L}{L}{N}{O}{S}{E}"_"{E}{N}{D}{M}{I}{L}{L}{_} {ECH; return BULLNOSEENDMILL;}
{_}{C}{A}{L}{E}{N}{D}{A}{R}"_"{D}{A}{T}{E}{_} {ECH; return CALENDARDATE;}
{_}{C}{A}{R}{T}{E}{S}{I}{A}{N}"_"{P}{O}{I}{N}{T}{_} {ECH; return CARTESIANPOINT;}
{_}{C}{A}{T}{A}{L}{O}{G}{U}{E}"_"{T}{H}{R}{E}{A}{D}{_} {ECH; return CATALOGUETHREAD;}
{_}{C}{E}{N}{T}{E}{R}"_"{D}{R}{I}{L}{L}{_} {ECH; return CENTERDRILL;}
{_}{C}{E}{N}{T}{E}{R}"_"{D}{R}{I}{L}{L}{I}{N}{G}{_} {ECH; return CENTERDRILLING;}
{_}{C}{E}{N}{T}{E}{R}"_"{M}{I}{L}{L}{I}{N}{G}{_} {ECH; return CENTERMILLING;}
{_}{C}{H}{A}{M}{F}{E}{R}{_}             {ECH; return CHAMFER;}
{_}{C}{H}{A}{N}{N}{E}{L}{_}             {ECH; return CHANNEL;}
{_}{C}{I}{R}{C}{L}{E}{_}                {ECH; return CIRCLE;}
{_}{C}{I}{R}{C}{U}{L}{A}{R}"_"{C}{L}{O}{S}{E}{D}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return CIRCULARCLOSEDPROFILE;}
{_}{C}{I}{R}{C}{U}{L}{A}{R}"_"{C}{L}{O}{S}{E}{D}"_"{S}{H}{A}{P}{E}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return CIRCULARCLOSEDSHAPEPROFILE;}
{_}{C}{I}{R}{C}{U}{L}{A}{R}"_"{O}{F}{F}{S}{E}{T}{_} {ECH; return CIRCULAROFFSET;}
{_}{C}{I}{R}{C}{U}{L}{A}{R}"_"{O}{M}{I}{T}{_} {ECH; return CIRCULAROMIT;}
{_}{C}{I}{R}{C}{U}{L}{A}{R}"_"{P}{A}{T}{T}{E}{R}{N}{_} {ECH; return CIRCULARPATTERN;}
{_}{C}{L}{O}{S}{E}{D}"_"{P}{O}{C}{K}{E}{T}{_} {ECH; return CLOSEDPOCKET;}
{_}{C}{L}{O}{S}{E}{D}"_"{S}{H}{E}{L}{L}{_} {ECH; return CLOSEDSHELL;}
{_}{C}{O}{M}{B}{I}{N}{E}{D}"_"{D}{R}{I}{L}{L}"_"{A}{N}{D}"_"{R}{E}{A}{M}{E}{R}{_} {ECH; return COMBINEDDRILLANDREAMER;}
{_}{C}{O}{M}{B}{I}{N}{E}{D}"_"{D}{R}{I}{L}{L}"_"{A}{N}{D}"_"{T}{A}{P}{_} {ECH; return COMBINEDDRILLANDTAP;}
{_}{C}{O}{M}{P}{A}{R}{I}{S}{O}{N}"_"{E}{Q}{U}{A}{L}{_} {ECH; return COMPARISONEQUAL;}
{_}{C}{O}{M}{P}{A}{R}{I}{S}{O}{N}"_"{G}{R}{E}{A}{T}{E}{R}{_} {ECH; return COMPARISONGREATER;}
{_}{C}{O}{M}{P}{A}{R}{I}{S}{O}{N}"_"{G}{R}{E}{A}{T}{E}{R}"_"{E}{Q}{U}{A}{L}{_} {ECH; return COMPARISONGREATEREQUAL;}
{_}{C}{O}{M}{P}{A}{R}{I}{S}{O}{N}"_"{L}{E}{S}{S}{_} {ECH; return COMPARISONLESS;}
{_}{C}{O}{M}{P}{A}{R}{I}{S}{O}{N}"_"{L}{E}{S}{S}"_"{E}{Q}{U}{A}{L}{_} {ECH; return COMPARISONLESSEQUAL;}
{_}{C}{O}{M}{P}{A}{R}{I}{S}{O}{N}"_"{N}{O}{T}"_"{E}{Q}{U}{A}{L}{_} {ECH; return COMPARISONNOTEQUAL;}
{_}{C}{O}{M}{P}{L}{E}{T}{E}"_"{C}{I}{R}{C}{U}{L}{A}{R}"_"{P}{A}{T}{H}{_} {ECH; return COMPLETECIRCULARPATH;}
{_}{C}{O}{M}{P}{O}{S}{I}{T}{E}"_"{C}{U}{R}{V}{E}{_} {ECH; return COMPOSITECURVE;}
{_}{C}{O}{M}{P}{O}{S}{I}{T}{E}"_"{C}{U}{R}{V}{E}"_"{S}{E}{G}{M}{E}{N}{T}{_} {ECH; return COMPOSITECURVESEGMENT;}
{_}{C}{O}{N}{I}{C}{A}{L}"_"{H}{O}{L}{E}"_"{B}{O}{T}{T}{O}{M}{_} {ECH; return CONICALHOLEBOTTOM;}
{_}{C}{O}{N}{N}{E}{C}{T}"_"{D}{I}{R}{E}{C}{T}{_} {ECH; return CONNECTDIRECT;}
{_}{C}{O}{N}{N}{E}{C}{T}"_"{S}{E}{C}{P}{L}{A}{N}{E}{_} {ECH; return CONNECTSECPLANE;}
{_}"."{F}{R}{O}{N}{T}"."{_}             {ECH; return CONTACTTYPEFRONT;}
{_}"."{S}{I}{D}{E}"."{_}                {ECH; return CONTACTTYPESIDE;}
{_}{C}{O}{N}{T}{O}{U}{R}"_"{B}{I}{D}{I}{R}{E}{C}{T}{I}{O}{N}{A}{L}{_} {ECH; return CONTOURBIDIRECTIONAL;}
{_}{C}{O}{N}{T}{O}{U}{R}"_"{P}{A}{R}{A}{L}{L}{E}{L}{_} {ECH; return CONTOURPARALLEL;}
{_}{C}{O}{N}{T}{O}{U}{R}"_"{S}{P}{I}{R}{A}{L}{_} {ECH; return CONTOURSPIRAL;}
{_}{C}{O}{O}{R}{D}{I}{N}{A}{T}{E}{D}"_"{U}{N}{I}{V}{E}{R}{S}{A}{L}"_"{T}{I}{M}{E}"_"{O}{F}{F}{S}{E}{T}{_} {ECH; return COORDINATEDUNIVERSALTIMEOFFSET;}
{_}{C}{O}{U}{N}{T}{E}{R}{B}{O}{R}{E}{_} {ECH; return COUNTERBORE;}
{_}{C}{O}{U}{N}{T}{E}{R}{B}{O}{R}{E}"_"{H}{O}{L}{E}{_} {ECH; return COUNTERBOREHOLE;}
{_}{C}{O}{U}{N}{T}{E}{R}{S}{I}{N}{K}{_} {ECH; return COUNTERSINK;}
{_}{C}{O}{U}{N}{T}{E}{R}"_"{S}{I}{N}{K}{I}{N}{G}{_} {ECH; return COUNTERSINKING;}
{_}{C}{O}{U}{N}{T}{E}{R}{S}{U}{N}{K}"_"{H}{O}{L}{E}{_} {ECH; return COUNTERSUNKHOLE;}
{_}{C}{U}{R}{V}{E}"_"{W}{I}{T}{H}"_"{N}{O}{R}{M}{A}{L}"_"{V}{E}{C}{T}{O}{R}{_} {ECH; return CURVEWITHNORMALVECTOR;}
{_}"."{C}{L}{I}{M}{B}"."{_}             {ECH; return CUTMODETYPECLIMB;}
{_}"."{C}{O}{N}{V}{E}{N}{T}{I}{O}{N}{A}{L}"."{_} {ECH; return CUTMODETYPECONVENTIONAL;}
{_}{C}{U}{T}{T}{E}{R}"_"{C}{O}{N}{T}{A}{C}{T}"_"{T}{R}{A}{J}{E}{C}{T}{O}{R}{Y}{_} {ECH; return CUTTERCONTACTTRAJECTORY;}
{_}{C}{U}{T}{T}{E}{R}"_"{L}{O}{C}{A}{T}{I}{O}{N}"_"{T}{R}{A}{J}{E}{C}{T}{O}{R}{Y}{_} {ECH; return CUTTERLOCATIONTRAJECTORY;}
{_}{C}{U}{T}{T}{I}{N}{G}"_"{C}{O}{M}{P}{O}{N}{E}{N}{T}{_} {ECH; return CUTTINGCOMPONENT;}
{_}{C}{U}{T}{T}{I}{N}{G}"_"{E}{D}{G}{E}"_"{T}{E}{C}{H}{N}{O}{L}{O}{G}{I}{C}{A}{L}"_"{D}{A}{T}{A}{_} {ECH; return CUTTINGEDGETECHNOLOGICALDATA;}
{_}{D}{A}{T}{A}{_}                      {ECH; return DATA;}
{_}{D}{A}{T}{E}"_"{A}{N}{D}"_"{T}{I}{M}{E}{_} {ECH; return DATEANDTIME;}
{_}{D}{E}{F}{I}{N}{E}{D}"_"{T}{H}{R}{E}{A}{D}{_} {ECH; return DEFINEDTHREAD;}
{_}{D}{E}{F}{I}{N}{I}{T}{I}{O}{N}{A}{L}"_"{R}{E}{P}{R}{E}{S}{E}{N}{T}{A}{T}{I}{O}{N}{_} {ECH; return DEFINITIONALREPRESENTATION;}
{_}{D}{E}{S}{C}{R}{I}{P}{T}{I}{V}{E}"_"{P}{A}{R}{A}{M}{E}{T}{E}{R}{_} {ECH; return DESCRIPTIVEPARAMETER;}
{_}{D}{I}{A}{M}{E}{T}{E}{R}"_"{T}{A}{P}{E}{R}{_} {ECH; return DIAMETERTAPER;}
{_}{D}{I}{R}{E}{C}{T}{I}{O}{N}{_}       {ECH; return DIRECTION;}
{_}{D}{I}{S}{P}{L}{A}{Y}"_"{M}{E}{S}{S}{A}{G}{E}{_} {ECH; return DISPLAYMESSAGE;}
{_}{D}{O}{V}{E}{T}{A}{I}{L}"_"{M}{I}{L}{L}{_} {ECH; return DOVETAILMILL;}
{_}{D}{R}{I}{L}{L}{I}{N}{G}{_}          {ECH; return DRILLING;}
{_}{D}{R}{I}{L}{L}{I}{N}{G}"_"{T}{Y}{P}{E}"_"{S}{T}{R}{A}{T}{E}{G}{Y}{_} {ECH; return DRILLINGTYPESTRATEGY;}
{_}{E}{D}{G}{E}"_"{C}{U}{R}{V}{E}{_}    {ECH; return EDGECURVE;}
{_}{E}{D}{G}{E}"_"{L}{O}{O}{P}{_}       {ECH; return EDGELOOP;}
{_}{E}{D}{G}{E}"_"{R}{O}{U}{N}{D}{_}    {ECH; return EDGEROUND;}
{_}{E}{L}{L}{I}{P}{S}{E}{_}             {ECH; return ELLIPSE;}
{_}{E}{N}{D}{S}{E}{C}{_}                {ECH; return ENDSEC;}
{_}{E}{X}{C}{H}{A}{N}{G}{E}"_"{P}{A}{L}{L}{E}{T}{_} {ECH; return EXCHANGEPALLET;}
{_}{E}{X}{P}{L}{I}{C}{I}{T}"_"{S}{T}{R}{A}{T}{E}{G}{Y}{_} {ECH; return EXPLICITSTRATEGY;}
{_}{F}{A}{C}{E}"_"{B}{O}{U}{N}{D}{_}    {ECH; return FACEBOUND;}
{_}{F}{A}{C}{E}{M}{I}{L}{L}{_}          {ECH; return FACEMILL;}
{_}{F}{A}{C}{E}"_"{O}{U}{T}{E}{R}"_"{B}{O}{U}{N}{D}{_} {ECH; return FACEOUTERBOUND;}
{_}"."{F}"."{_}                         {ECH; return FALSE;}
{_}{F}{E}{E}{D}{S}{T}{O}{P}{_}          {ECH; return FEEDSTOP;}
{_}{F}{I}{L}{E}"_"{D}{E}{S}{C}{R}{I}{P}{T}{I}{O}{N}{_} {ECH; return FILEDESCRIPTION;}
{_}{E}{N}{D}"-"{I}{S}{O}"-""1""0""3""0""3""-""2""1"{_} {ECH; return FILEEND;}
{_}{F}{I}{L}{E}"_"{N}{A}{M}{E}{_}       {ECH; return FILENAME;}
{_}{F}{I}{L}{E}"_"{S}{C}{H}{E}{M}{A}{_} {ECH; return FILESCHEMA;}
{_}{I}{S}{O}"-""1""0""3""0""3""-""2""1"{_} {ECH; return FILESTART;}
{_}"."{H}{O}{L}{E}"."{_}                {ECH; return FITTINGTYPEHOLE;}
{_}"."{S}{H}{A}{F}{T}"."{_}             {ECH; return FITTINGTYPESHAFT;}
{_}{F}{I}{V}{E}"_"{A}{X}{E}{S}"_"{C}{O}{N}{S}{T}"_"{T}{I}{L}{T}"_"{Y}{A}{W}{_} {ECH; return FIVEAXESCONSTTILTYAW;}
{_}{F}{I}{V}{E}"_"{A}{X}{E}{S}"_"{V}{A}{R}"_"{T}{I}{L}{T}"_"{Y}{A}{W}{_} {ECH; return FIVEAXESVARTILTYAW;}
{_}{F}{L}{A}{T}"_"{H}{O}{L}{E}"_"{B}{O}{T}{T}{O}{M}{_} {ECH; return FLATHOLEBOTTOM;}
{_}{F}{L}{A}{T}"_"{S}{L}{O}{T}"_"{E}{N}{D}"_"{T}{Y}{P}{E}{_} {ECH; return FLATSLOTENDTYPE;}
{_}{F}{L}{A}{T}"_"{W}{I}{T}{H}"_"{R}{A}{D}{I}{U}{S}"_"{H}{O}{L}{E}"_"{B}{O}{T}{T}{O}{M}{_} {ECH; return FLATWITHRADIUSHOLEBOTTOM;}
{_}{F}{R}{E}{E}{F}{O}{R}{M}"_"{O}{P}{E}{R}{A}{T}{I}{O}{N}{_} {ECH; return FREEFORMOPERATION;}
{_}{G}{E}{N}{E}{R}{A}{L}"_"{C}{L}{O}{S}{E}{D}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return GENERALCLOSEDPROFILE;}
{_}{G}{E}{N}{E}{R}{A}{L}"_"{O}{U}{T}{S}{I}{D}{E}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return GENERALOUTSIDEPROFILE;}
{_}{G}{E}{N}{E}{R}{A}{L}"_"{P}{A}{T}{H}{_} {ECH; return GENERALPATH;}
{_}{G}{E}{N}{E}{R}{A}{L}"_"{P}{A}{T}{T}{E}{R}{N}{_} {ECH; return GENERALPATTERN;}
{_}{G}{E}{N}{E}{R}{A}{L}"_"{P}{O}{C}{K}{E}{T}"_"{B}{O}{T}{T}{O}{M}"_"{C}{O}{N}{D}{I}{T}{I}{O}{N}{_} {ECH; return GENERALPOCKETBOTTOMCONDITION;}
{_}{G}{E}{N}{E}{R}{A}{L}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return GENERALPROFILE;}
{_}{G}{E}{N}{E}{R}{A}{L}"_"{P}{R}{O}{F}{I}{L}{E}"_"{F}{L}{O}{O}{R}{_} {ECH; return GENERALPROFILEFLOOR;}
{_}{G}{E}{N}{E}{R}{A}{L}"_"{S}{H}{A}{P}{E}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return GENERALSHAPEPROFILE;}
{_}{H}{E}{A}{D}{E}{R}{_}                {ECH; return HEADER;}
{_}{H}{E}{L}{I}{X}{_}                   {ECH; return HELIX;}
{_}{H}{Y}{P}{E}{R}{B}{O}{L}{A}{_}       {ECH; return HYPERBOLA;}
{_}{I}{F}"_"{S}{T}{A}{T}{E}{M}{E}{N}{T}{_} {ECH; return IFSTATEMENT;}
{_}{I}{N}{D}{E}{X}"_"{P}{A}{L}{L}{E}{T}{_} {ECH; return INDEXPALLET;}
{_}{I}{N}{D}{E}{X}"_"{T}{A}{B}{L}{E}{_} {ECH; return INDEXTABLE;}
{_}{I}{N}"_"{P}{R}{O}{C}{E}{S}{S}"_"{G}{E}{O}{M}{E}{T}{R}{Y}{_} {ECH; return INPROCESSGEOMETRY;}
{_}"."{P}{I}{E}{C}{E}{W}{I}{S}{E}"_"{B}{E}{Z}{I}{E}{R}"_"{K}{N}{O}{T}{S}"."{_} {ECH; return KNOTTYPEPIECEWISEBEZIERKNOTS;}
{_}"."{Q}{U}{A}{S}{I}"_"{U}{N}{I}{F}{O}{R}{M}"_"{K}{N}{O}{T}{S}"."{_} {ECH; return KNOTTYPEQUASIUNIFORMKNOTS;}
{_}"."{U}{N}{I}{F}{O}{R}{M}"_"{K}{N}{O}{T}{S}"."{_} {ECH; return KNOTTYPEUNIFORMKNOTS;}
{_}"."{U}{N}{S}{P}{E}{C}{I}{F}{I}{E}{D}"."{_} {ECH; return KNOTTYPEUNSPECIFIED;}
{_}{L}{E}{A}{D}{I}{N}{G}"_"{L}{I}{N}{E}"_"{S}{T}{R}{A}{T}{E}{G}{Y}{_} {ECH; return LEADINGLINESTRATEGY;}
{_}"."{L}{E}{F}{T}"."{_}                {ECH; return LEFT;}
{_}{L}{I}{M}{I}{T}{S}{A}{N}{D}{F}{I}{T}{S}{_} {ECH; return LIMITSANDFITS;}
{_}{L}{I}{N}{E}{_}                      {ECH; return LINE;}
{_}{L}{I}{N}{E}{A}{R}"_"{P}{A}{T}{H}{_} {ECH; return LINEARPATH;}
{_}{L}{I}{N}{E}{A}{R}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return LINEARPROFILE;}
{_}{L}{O}{A}{D}"_"{T}{O}{O}{L}{_}       {ECH; return LOADTOOL;}
{_}{L}{O}{C}{A}{L}"_"{T}{I}{M}{E}{_}    {ECH; return LOCALTIME;}
{_}{L}{O}{O}{P}"_"{S}{L}{O}{T}"_"{E}{N}{D}"_"{T}{Y}{P}{E}{_} {ECH; return LOOPSLOTENDTYPE;}
{_}{M}{A}{C}{H}{I}{N}{E}{D}"_"{S}{U}{R}{F}{A}{C}{E}{_} {ECH; return MACHINEDSURFACE;}
{_}{M}{A}{C}{H}{I}{N}{I}{N}{G}"_"{W}{O}{R}{K}{I}{N}{G}{S}{T}{E}{P}{_} {ECH; return MACHININGWORKINGSTEP;}
{_}{M}{A}{N}{I}{F}{O}{L}{D}"_"{S}{O}{L}{I}{D}"_"{B}{R}{E}{P}{_} {ECH; return MANIFOLDSOLIDBREP;}
{_}{M}{A}{T}{E}{R}{I}{A}{L}{_}          {ECH; return MATERIAL;}
{_}{M}{I}{L}{L}{I}{N}{G}"_"{C}{U}{T}{T}{I}{N}{G}"_"{T}{O}{O}{L}{_} {ECH; return MILLINGCUTTINGTOOL;}
{_}{M}{I}{L}{L}{I}{N}{G}"_"{M}{A}{C}{H}{I}{N}{E}"_"{F}{U}{N}{C}{T}{I}{O}{N}{S}{_} {ECH; return MILLINGMACHINEFUNCTIONS;}
{_}{M}{I}{L}{L}{I}{N}{G}"_"{T}{E}{C}{H}{N}{O}{L}{O}{G}{Y}{_} {ECH; return MILLINGTECHNOLOGY;}
{_}{M}{I}{L}{L}{I}{N}{G}{T}{H}{R}{E}{A}{D}{I}{N}{G}{T}{O}{O}{L}{_} {ECH; return MILLINGTHREADINGTOOL;}
{_}{M}{I}{L}{L}{I}{N}{G}"_"{T}{O}{O}{L}"_"{D}{I}{M}{E}{N}{S}{I}{O}{N}{_} {ECH; return MILLINGTOOLDIMENSION;}
{_}{M}{U}{L}{T}{I}{S}{T}{E}{P}"_"{D}{R}{I}{L}{L}{I}{N}{G}{_} {ECH; return MULTISTEPDRILLING;}
{_}{N}{C}"_"{C}{O}{N}{S}{T}{A}{N}{T}{_} {ECH; return NCCONSTANT;}
{_}{N}{C}"_"{V}{A}{R}{I}{A}{B}{L}{E}{_} {ECH; return NCVARIABLE;}
{_}"."{N}{E}{U}{T}{R}{A}{L}"."{_}       {ECH; return NEUTRAL;}
{_}{N}{G}{O}{N}"_"{C}{L}{O}{S}{E}{D}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return NGONCLOSEDPROFILE;}
{_}{N}{O}{N}"_"{S}{E}{Q}{U}{E}{N}{T}{I}{A}{L}{_} {ECH; return NONSEQUENTIAL;}
{_}{N}{O}{T}"_"{E}{X}{P}{R}{E}{S}{S}{I}{O}{N}{_} {ECH; return NOTEXPRESSION;}
{_}{N}{U}{M}{E}{R}{I}{C}"_"{P}{A}{R}{A}{M}{E}{T}{E}{R}{_} {ECH; return NUMERICPARAMETER;}
{_}{O}{F}{F}{S}{E}{T}"_"{V}{E}{C}{T}{O}{R}{_} {ECH; return OFFSETVECTOR;}
{_}{O}{P}{E}{N}"_"{P}{O}{C}{K}{E}{T}{_} {ECH; return OPENPOCKET;}
{_}{O}{P}{E}{N}"_"{S}{H}{E}{L}{L}{_}    {ECH; return OPENSHELL;}
{_}{O}{P}{E}{N}"_"{S}{L}{O}{T}"_"{E}{N}{D}"_"{T}{Y}{P}{E}{_} {ECH; return OPENSLOTENDTYPE;}
{_}{O}{P}{T}{I}{O}{N}{A}{L}"_"{S}{T}{O}{P}{_} {ECH; return OPTIONALSTOP;}
{_}{O}{R}{D}{I}{N}{A}{L}"_"{D}{A}{T}{E}{_} {ECH; return ORDINALDATE;}
{_}{O}{R}"_"{E}{X}{P}{R}{E}{S}{S}{I}{O}{N}{_} {ECH; return OREXPRESSION;}
{_}{O}{R}{I}{E}{N}{T}{E}{D}"_"{E}{D}{G}{E}{_} {ECH; return ORIENTEDEDGE;}
{_}{P}{A}{R}{A}{B}{O}{L}{A}{_}          {ECH; return PARABOLA;}
{_}{P}{A}{R}{A}{L}{L}{E}{L}{_}          {ECH; return PARALLEL;}
{_}{P}{A}{R}{T}{I}{A}{L}"_"{A}{R}{E}{A}"_"{D}{E}{F}{I}{N}{I}{T}{I}{O}{N}{_} {ECH; return PARTIALAREADEFINITION;}
{_}{P}{A}{R}{T}{I}{A}{L}"_"{C}{I}{R}{C}{U}{L}{A}{R}"_"{P}{A}{T}{H}{_} {ECH; return PARTIALCIRCULARPATH;}
{_}{P}{A}{R}{T}{I}{A}{L}"_"{C}{I}{R}{C}{U}{L}{A}{R}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return PARTIALCIRCULARPROFILE;}
{_}{P}{A}{R}{T}{I}{A}{L}"_"{C}{I}{R}{C}{U}{L}{A}{R}"_"{S}{H}{A}{P}{E}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return PARTIALCIRCULARSHAPEPROFILE;}
{_}"."{F}{O}{R}{W}{A}{R}{D}"."{_}       {ECH; return PATHMODETYPEFORWARD;}
{_}"."{Z}{I}{G}{Z}{A}{G}"."{_}          {ECH; return PATHMODETYPEZIGZAG;}
{_}{P}{C}{U}{R}{V}{E}{_}                {ECH; return PCURVE;}
{_}{P}{E}{R}{S}{O}{N}{_}                {ECH; return PERSON;}
{_}{P}{E}{R}{S}{O}{N}"_"{A}{N}{D}"_"{A}{D}{D}{R}{E}{S}{S}{_} {ECH; return PERSONANDADDRESS;}
{_}{P}{L}{A}{N}{A}{R}"_"{F}{A}{C}{E}{_} {ECH; return PLANARFACE;}
{_}{P}{L}{A}{N}{A}{R}"_"{P}{O}{C}{K}{E}{T}"_"{B}{O}{T}{T}{O}{M}"_"{C}{O}{N}{D}{I}{T}{I}{O}{N}{_} {ECH; return PLANARPOCKETBOTTOMCONDITION;}
{_}{P}{L}{A}{N}{A}{R}"_"{P}{R}{O}{F}{I}{L}{E}"_"{F}{L}{O}{O}{R}{_} {ECH; return PLANARPROFILEFLOOR;}
{_}{P}{L}{A}{N}{E}{_}                   {ECH; return PLANE;}
{_}{P}{L}{A}{N}{E}"_"{C}{C}"_"{S}{T}{R}{A}{T}{E}{G}{Y}{_} {ECH; return PLANECCSTRATEGY;}
{_}{P}{L}{A}{N}{E}"_"{C}{L}"_"{S}{T}{R}{A}{T}{E}{G}{Y}{_} {ECH; return PLANECLSTRATEGY;}
{_}{P}{L}{A}{N}{E}"_"{F}{I}{N}{I}{S}{H}"_"{M}{I}{L}{L}{I}{N}{G}{_} {ECH; return PLANEFINISHMILLING;}
{_}{P}{L}{A}{N}{E}"_"{R}{O}{U}{G}{H}"_"{M}{I}{L}{L}{I}{N}{G}{_} {ECH; return PLANEROUGHMILLING;}
{_}{P}{L}{U}{N}{G}{E}"_"{H}{E}{L}{I}{X}{_} {ECH; return PLUNGEHELIX;}
{_}{P}{L}{U}{N}{G}{E}"_"{R}{A}{M}{P}{_} {ECH; return PLUNGERAMP;}
{_}{P}{L}{U}{N}{G}{E}"_"{T}{O}{O}{L}{A}{X}{I}{S}{_} {ECH; return PLUNGETOOLAXIS;}
{_}{P}{L}{U}{N}{G}{E}"_"{Z}{I}{G}{Z}{A}{G}{_} {ECH; return PLUNGEZIGZAG;}
{_}{P}{L}{U}{S}"_"{M}{I}{N}{U}{S}"_"{V}{A}{L}{U}{E}{_} {ECH; return PLUSMINUSVALUE;}
{_}{P}{O}{L}{Y}{L}{I}{N}{E}{_}          {ECH; return POLYLINE;}
{_}{P}{R}{O}{C}{E}{S}{S}"_"{M}{O}{D}{E}{L}{_} {ECH; return PROCESSMODEL;}
{_}{P}{R}{O}{C}{E}{S}{S}"_"{M}{O}{D}{E}{L}"_"{L}{I}{S}{T}{_} {ECH; return PROCESSMODELLIST;}
{_}{P}{R}{O}{G}{R}{A}{M}"_"{S}{T}{O}{P}{_} {ECH; return PROGRAMSTOP;}
{_}{P}{R}{O}{J}{E}{C}{T}{_}             {ECH; return PROJECT;}
{_}{Q}{U}{A}{S}{I}"_"{U}{N}{I}{F}{O}{R}{M}"_"{C}{U}{R}{V}{E}{_} {ECH; return QUASIUNIFORMCURVE;}
{_}{Q}{U}{A}{S}{I}"_"{U}{N}{I}{F}{O}{R}{M}"_"{S}{U}{R}{F}{A}{C}{E}{_} {ECH; return QUASIUNIFORMSURFACE;}
{_}{R}{A}{D}{I}{U}{S}{E}{D}"_"{P}{O}{C}{K}{E}{T}"_"{B}{O}{T}{T}{O}{M}"_"{C}{O}{N}{D}{I}{T}{I}{O}{N}{_} {ECH; return RADIUSEDPOCKETBOTTOMCONDITION;}
{_}{R}{A}{D}{I}{U}{S}{E}{D}"_"{S}{L}{O}{T}"_"{E}{N}{D}"_"{T}{Y}{P}{E}{_} {ECH; return RADIUSEDSLOTENDTYPE;}
{_}{R}{A}{P}{I}{D}"_"{M}{O}{V}{E}{M}{E}{N}{T}{_} {ECH; return RAPIDMOVEMENT;}
{_}{R}{A}{T}{I}{O}{N}{A}{L}"_"{B}"_"{S}{P}{L}{I}{N}{E}"_"{C}{U}{R}{V}{E}{_} {ECH; return RATIONALBSPLINECURVE;}
{_}{R}{A}{T}{I}{O}{N}{A}{L}"_"{B}"_"{S}{P}{L}{I}{N}{E}"_"{S}{U}{R}{F}{A}{C}{E}{_} {ECH; return RATIONALBSPLINESURFACE;}
{_}{R}{E}{A}{M}{I}{N}{G}{_}             {ECH; return REAMING;}
{_}{R}{E}{C}{T}{A}{N}{G}{U}{L}{A}{R}"_"{C}{L}{O}{S}{E}{D}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return RECTANGULARCLOSEDPROFILE;}
{_}{R}{E}{C}{T}{A}{N}{G}{U}{L}{A}{R}"_"{C}{L}{O}{S}{E}{D}"_"{S}{H}{A}{P}{E}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return RECTANGULARCLOSEDSHAPEPROFILE;}
{_}{R}{E}{C}{T}{A}{N}{G}{U}{L}{A}{R}"_"{O}{F}{F}{S}{E}{T}{_} {ECH; return RECTANGULAROFFSET;}
{_}{R}{E}{C}{T}{A}{N}{G}{U}{L}{A}{R}{O}{M}{I}{T}{_} {ECH; return RECTANGULAROMIT;}
{_}{R}{E}{C}{T}{A}{N}{G}{U}{L}{A}{R}"_"{O}{P}{E}{N}"_"{S}{H}{A}{P}{E}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return RECTANGULAROPENSHAPEPROFILE;}
{_}{R}{E}{C}{T}{A}{N}{G}{U}{L}{A}{R}"_"{P}{A}{T}{T}{E}{R}{N}{_} {ECH; return RECTANGULARPATTERN;}
{_}{R}{E}{G}{I}{O}{N}"_"{P}{R}{O}{J}{E}{C}{T}{I}{O}{N}{_} {ECH; return REGIONPROJECTION;}
{_}{R}{E}{G}{I}{O}{N}"_"{S}{U}{R}{F}{A}{C}{E}"_"{L}{I}{S}{T}{_} {ECH; return REGIONSURFACELIST;}
{_}{R}{E}{P}{R}{E}{S}{E}{N}{T}{A}{T}{I}{O}{N}{_} {ECH; return REPRESENTATION;}
{_}{R}{E}{P}{R}{E}{S}{E}{N}{T}{A}{T}{I}{O}{N}{C}{O}{N}{T}{E}{X}{T}{_} {ECH; return REPRESENTATIONCONTEXT;}
{_}"."{R}{I}{G}{H}{T}"."{_}             {ECH; return RIGHT;}
{_}{R}{I}{G}{H}{T}"_"{C}{I}{R}{C}{U}{L}{A}{R}"_"{C}{Y}{L}{I}{N}{D}{E}{R}{_} {ECH; return RIGHTCIRCULARCYLINDER;}
{_}"."{C}{C}{W}"."{_}                   {ECH; return ROTDIRECTIONCCW;}
{_}"."{C}{W}"."{_}                      {ECH; return ROTDIRECTIONCW;}
{_}{R}{O}{U}{N}{D}{E}{D}"_"{E}{N}{D}{_} {ECH; return ROUNDEDEND;}
{_}{R}{O}{U}{N}{D}{E}{D}"_"{U}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return ROUNDEDUPROFILE;}
{_}{R}{O}{U}{N}{D}"_"{H}{O}{L}{E}{_}    {ECH; return ROUNDHOLE;}
{_}{S}{E}{L}{E}{C}{T}{I}{V}{E}{_}       {ECH; return SELECTIVE;}
{_}{S}{E}{T}"_"{M}{A}{R}{K}{_}          {ECH; return SETMARK;}
{_}{S}{E}{T}{U}{P}{_}                   {ECH; return SETUP;}
{_}{S}{E}{T}{U}{P}"_"{I}{N}{S}{T}{R}{U}{C}{T}{I}{O}{N}{_} {ECH; return SETUPINSTRUCTION;}
{_}{S}{H}{A}{P}{E}"_"{R}{E}{P}{R}{E}{S}{E}{N}{T}{A}{T}{I}{O}{N}{_} {ECH; return SHAPEREPRESENTATION;}
{_}{S}{I}{D}{E}"_"{F}{I}{N}{I}{S}{H}"_"{M}{I}{L}{L}{I}{N}{G}{_} {ECH; return SIDEFINISHMILLING;}
{_}{S}{I}{D}{E}"_"{M}{I}{L}{L}{_}       {ECH; return SIDEMILL;}
{_}{S}{I}{D}{E}"_"{R}{O}{U}{G}{H}"_"{M}{I}{L}{L}{I}{N}{G}{_} {ECH; return SIDEROUGHMILLING;}
{_}{S}{L}{O}{T}{_}                      {ECH; return SLOT;}
{_}{S}{P}{A}{D}{E}"_"{D}{R}{I}{L}{L}{_} {ECH; return SPADEDRILL;}
{_}{S}{P}{E}{C}{I}{F}{I}{C}{A}{T}{I}{O}{N}{_} {ECH; return SPECIFICATION;}
{_}{S}{P}{E}{C}{I}{F}{I}{C}{A}{T}{I}{O}{N}"_"{U}{S}{A}{G}{E}"_"{C}{O}{N}{S}{T}{R}{A}{I}{N}{T}{_} {ECH; return SPECIFICATIONUSAGECONSTRAINT;}
{_}"."{R}{A}{P}{I}{D}"."{_}             {ECH; return SPEEDNAMERAPID;}
{_}{S}{P}{H}{E}{R}{I}{C}{A}{L}"_"{C}{A}{P}{_} {ECH; return SPHERICALCAP;}
{_}{S}{P}{H}{E}{R}{I}{C}{A}{L}"_"{H}{O}{L}{E}"_"{B}{O}{T}{T}{O}{M}{_} {ECH; return SPHERICALHOLEBOTTOM;}
{_}{S}{P}{H}{E}{R}{I}{C}{A}{L}"_"{S}{U}{R}{F}{A}{C}{E}{_} {ECH; return SPHERICALSURFACE;}
{_}{S}{Q}{U}{A}{R}{E}"_"{U}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return SQUAREUPROFILE;}
{_}{S}{T}{E}{P}{_}                      {ECH; return STEP;}
{_}"."{D}{E}{G}{O}{U}{G}{E}"."{_}       {ECH; return STROKECONNECTIONSTRATEGYDEGOUGE;}
{_}"."{L}{I}{F}{T}"_"{S}{H}{I}{F}{T}"_"{P}{L}{U}{N}{G}{E}"."{_} {ECH; return STROKECONNECTIONSTRATEGYLIFTSHIFTPLUNGE;}
{_}"."{L}{O}{O}{P}"_"{B}{A}{C}{K}"."{_} {ECH; return STROKECONNECTIONSTRATEGYLOOPBACK;}
{_}"."{S}{T}{R}{A}{I}{G}{H}{T}{L}{I}{N}{E}"."{_} {ECH; return STROKECONNECTIONSTRATEGYSTRAIGHTLINE;}
{_}{S}{U}{R}{F}{A}{C}{E}"_"{O}{F}"_"{L}{I}{N}{E}{A}{R}"_"{E}{X}{T}{R}{U}{S}{I}{O}{N}{_} {ECH; return SURFACEOFLINEAREXTRUSION;}
{_}{S}{U}{R}{F}{A}{C}{E}"_"{O}{F}"_"{R}{E}{V}{O}{L}{U}{T}{I}{O}{N}{_} {ECH; return SURFACEOFREVOLUTION;}
{_}{S}{U}{R}{F}{A}{C}{E}"_"{T}{E}{X}{T}{U}{R}{E}"_"{P}{A}{R}{A}{M}{E}{T}{E}{R}{_} {ECH; return SURFACETEXTUREPARAMETER;}
{_}{T}{A}{P}{_}                         {ECH; return TAP;}
{_}{T}{A}{P}{E}{R}{E}{D}"_"{D}{R}{I}{L}{L}{_} {ECH; return TAPEREDDRILL;}
{_}{T}{A}{P}{E}{R}{E}{D}"_"{E}{N}{D}{M}{I}{L}{L}{_} {ECH; return TAPEREDENDMILL;}
{_}{T}{A}{P}{E}{R}{E}{D}"_"{R}{E}{A}{M}{E}{R}{_} {ECH; return TAPEREDREAMER;}
{_}{T}{A}{P}{E}{R}{E}{D}"_"{T}{A}{P}{_} {ECH; return TAPEREDTAP;}
{_}{T}{A}{P}{P}{I}{N}{G}{_}             {ECH; return TAPPING;}
{_}{T}{E}{E}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return TEEPROFILE;}
{_}{T}{H}{R}{E}{A}{D}"_"{D}{R}{I}{L}{L}{I}{N}{G}{_} {ECH; return THREADDRILLING;}
{_}{T}{H}{R}{E}{A}{D}"_"{M}{I}{L}{L}{_} {ECH; return THREADMILL;}
{_}{T}{H}{R}{E}{E}"_"{A}{X}{E}{S}{_}    {ECH; return THREEAXES;}
{_}{T}{H}{R}{E}{E}"_"{A}{X}{E}{S}"_"{T}{I}{L}{T}{E}{D}"_"{T}{O}{O}{L}{_} {ECH; return THREEAXESTILTEDTOOL;}
{_}{T}{H}{R}{O}{U}{G}{H}"_"{B}{O}{T}{T}{O}{M}"_"{C}{O}{N}{D}{I}{T}{I}{O}{N}{_} {ECH; return THROUGHBOTTOMCONDITION;}
{_}{T}{H}{R}{O}{U}{G}{H}"_"{P}{O}{C}{K}{E}{T}"_"{B}{O}{T}{T}{O}{M}"_"{C}{O}{N}{D}{I}{T}{I}{O}{N}{_} {ECH; return THROUGHPOCKETBOTTOMCONDITION;}
{_}{T}{H}{R}{O}{U}{G}{H}"_"{P}{R}{O}{F}{I}{L}{E}"_"{F}{L}{O}{O}{R}{_} {ECH; return THROUGHPROFILEFLOOR;}
{_}{T}{O}{L}{E}{R}{A}{N}{C}{E}{D}"_"{L}{E}{N}{G}{T}{H}"_"{M}{E}{A}{S}{U}{R}{E}{_} {ECH; return TOLERANCEDLENGTHMEASURE;}
{_}{T}{O}{L}{E}{R}{A}{N}{C}{E}{S}{_}    {ECH; return TOLERANCES;}
{_}{T}{O}{O}{L}"_"{L}{E}{N}{G}{T}{H}"_"{P}{R}{O}{B}{I}{N}{G}{_} {ECH; return TOOLLENGTHPROBING;}
{_}{T}{O}{O}{L}{P}{A}{T}{H}"_"{F}{E}{A}{T}{U}{R}{E}{_} {ECH; return TOOLPATHFEATURE;}
{_}{T}{O}{O}{L}{P}{A}{T}{H}"_"{L}{I}{S}{T}{_} {ECH; return TOOLPATHLIST;}
{_}{T}{O}{O}{L}{P}{A}{T}{H}"_"{S}{P}{E}{E}{D}{_} {ECH; return TOOLPATHSPEED;}
{_}"."{A}{P}{P}{R}{O}{A}{C}{H}"."{_}    {ECH; return TOOLPATHTYPEAPPROACH;}
{_}"."{C}{O}{N}{N}{E}{C}{T}"."{_}       {ECH; return TOOLPATHTYPECONNECT;}
{_}"."{C}{O}{N}{T}{A}{C}{T}"."{_}       {ECH; return TOOLPATHTYPECONTACT;}
{_}"."{L}{I}{F}{T}"."{_}                {ECH; return TOOLPATHTYPELIFT;}
{_}"."{N}{O}{N}{C}{O}{N}{T}{A}{C}{T}"."{_} {ECH; return TOOLPATHTYPENONCONTACT;}
{_}"."{T}{R}{A}{J}{E}{C}{T}{O}{R}{Y}"_"{P}{A}{T}{H}"."{_} {ECH; return TOOLPATHTYPETRAJECTORYPATH;}
{_}{T}{O}{O}{L}"_"{R}{A}{D}{I}{U}{S}"_"{P}{R}{O}{B}{I}{N}{G}{_} {ECH; return TOOLRADIUSPROBING;}
{_}"."{C}{C}{P}"."{_}                   {ECH; return TOOLREFERENCEPOINTCCP;}
{_}"."{T}{C}{P}"."{_}                   {ECH; return TOOLREFERENCEPOINTTCP;}
{_}{T}{O}{P}{O}{L}{O}{G}{I}{C}{A}{L}"_"{R}{E}{G}{I}{O}{N}{_} {ECH; return TOPOLOGICALREGION;}
{_}{T}{O}{U}{C}{H}"_"{P}{R}{O}{B}{E}{_} {ECH; return TOUCHPROBE;}
{_}"."{C}{O}{N}{T}{I}{N}{U}{O}{U}{S}"."{_} {ECH; return TRANSITIONCODECONTINUOUS;}
{_}"."{C}{O}{N}{T}"_"{S}{A}{M}{E}"_"{G}{R}{A}{D}{I}{E}{N}{T}"."{_} {ECH; return TRANSITIONCODECONTSAMEGRADIENT;}
{_}"."{C}{O}{N}{T}"_"{S}{A}{M}{E}"_"{G}{R}{A}{D}{I}{E}{N}{T}"_"{S}{A}{M}{E}"_"{C}{U}{R}{V}{A}{T}{U}{R}{E}"."{_} {ECH; return TRANSITIONCODECONTSAMEGRADIENTSAMECURVATURE;}
{_}"."{D}{I}{S}{C}{O}{N}{T}{I}{N}{U}{O}{U}{S}"."{_} {ECH; return TRANSITIONCODEDISCONTINUOUS;}
{_}{T}{R}{I}{M}{M}{E}{D}"_"{C}{U}{R}{V}{E}{_} {ECH; return TRIMMEDCURVE;}
{_}"."{C}{A}{R}{T}{E}{S}{I}{A}{N}"."{_} {ECH; return TRIMMINGPREFERENCECARTESIAN;}
{_}"."{P}{A}{R}{A}{M}{E}{T}{E}{R}"."{_} {ECH; return TRIMMINGPREFERENCEPARAMETER;}
{_}"."{U}{N}{S}{P}{E}{C}{I}{F}{I}{E}{D}"."{_} {ECH; return TRIMMINGPREFERENCEUNSPECIFIED;}
{_}"."{T}"."{_}                         {ECH; return TRUE;}
{_}{T}"_"{S}{L}{O}{T}"_"{M}{I}{L}{L}{_} {ECH; return TSLOTMILL;}
{_}{T}{W}{I}{S}{T}"_"{D}{R}{I}{L}{L}{_} {ECH; return TWISTDRILL;}
{_}{T}{W}{O}"_"{A}{X}{E}{S}{_}          {ECH; return TWOAXES;}
{_}{U}{N}{I}{D}{I}{R}{E}{C}{T}{I}{O}{N}{A}{L}"_"{M}{I}{L}{L}{I}{N}{G}{_} {ECH; return UNIDIRECTIONALMILLING;}
{_}{U}{N}{I}{F}{O}{R}{M}"_"{C}{U}{R}{V}{E}{_} {ECH; return UNIFORMCURVE;}
{_}{U}{N}{I}{F}{O}{R}{M}"_"{S}{U}{R}{F}{A}{C}{E}{_} {ECH; return UNIFORMSURFACE;}
{_}"."{U}"."{_}                         {ECH; return UNKNOWN;}
{_}{U}{N}{L}{O}{A}{D}"_"{T}{O}{O}{L}{_} {ECH; return UNLOADTOOL;}
{_}{U}{S}{E}{R}"_"{D}{E}{F}{I}{N}{E}{D}"_"{T}{O}{O}{L}{_} {ECH; return USERDEFINEDTOOL;}
{_}{U}{V}"_"{S}{T}{R}{A}{T}{E}{G}{Y}{_} {ECH; return UVSTRATEGY;}
{_}{V}{E}{C}{T}{O}{R}{_}                {ECH; return VECTOR;}
{_}{V}{E}{E}"_"{P}{R}{O}{F}{I}{L}{E}{_} {ECH; return VEEPROFILE;}
{_}{V}{E}{R}{T}{E}{X}"_"{L}{O}{O}{P}{_} {ECH; return VERTEXLOOP;}
{_}{V}{E}{R}{T}{E}{X}"_"{P}{O}{I}{N}{T}{_} {ECH; return VERTEXPOINT;}
{_}{W}{A}{I}{T}"_"{F}{O}{R}"_"{M}{A}{R}{K}{_} {ECH; return WAITFORMARK;}
{_}{W}{E}{E}{E}{K}"_"{O}{F}"_"{Y}{E}{A}{R}"_"{A}{N}{D}"_"{D}{A}{Y}"_"{D}{A}{T}{E}{_} {ECH; return WEEKOFYEARANDDAYDATE;}
{_}{W}{H}{I}{L}{E}"_"{S}{T}{A}{T}{E}{M}{E}{N}{T}{_} {ECH; return WHILESTATEMENT;}
{_}{W}{O}{O}{R}{D}{R}{U}{F}{F}"_"{K}{E}{Y}{S}{E}{A}{T}"_"{M}{I}{L}{L}{_} {ECH; return WOODRUFFKEYSEATMILL;}
{_}{W}{O}{O}{D}{R}{U}{F}{F}"_"{S}{L}{O}{T}"_"{E}{N}{D}"_"{T}{Y}{P}{E}{_} {ECH; return WOODRUFFSLOTENDTYPE;}
{_}{W}{O}{R}{K}{P}{I}{E}{C}{E}{_}       {ECH; return WORKPIECE;}
{_}{W}{O}{R}{K}{P}{I}{E}{C}{E}"_"{C}{O}{M}{P}{L}{E}{T}{E}"_"{P}{R}{O}{B}{I}{N}{G}{_} {ECH; return WORKPIECECOMPLETEPROBING;}
{_}{W}{O}{R}{K}{P}{I}{E}{C}{E}"_"{P}{R}{O}{B}{I}{N}{G}{_} {ECH; return WORKPIECEPROBING;}
{_}{W}{O}{R}{K}{P}{I}{E}{C}{E}"_"{S}{E}{T}{U}{P}{_} {ECH; return WORKPIECESETUP;}
{_}{W}{O}{R}{K}{P}{L}{A}{N}{_}          {ECH; return WORKPLAN;}
{_}{X}{O}{R}"_"{E}{X}{P}{R}{E}{S}{S}{I}{O}{N}{_} {ECH; return XOREXPRESSION;}
{_}"/*"                                 {ECH; BEGIN(COMMENT);}
<COMMENT>.                              {ECH;}
<COMMENT>\n                             {ECH;}
<COMMENT>"*/"{_}                        {ECH; BEGIN(INITIAL);}
{_}'                                    {ECH; j=0; BEGIN INSTRING;}
<INSTRING>('')                          {ECH; stringText[j++] = '\'';}
<INSTRING>'{_}                          {ECH; BEGIN INITIAL;
                                         stringText[j] = 0;
                                         yylval.sval = strdup(stringText);
                                         return CHARSTRING;}
<INSTRING>[ -&(-~\t]                    {ECH; stringText[j++]=yytext[0];}
<INSTRING>\n                            {ECH;
                                         sprintf(lexMessage,
                                                 "newline in string");
                                         BEGIN INITIAL;
                                         return BAD;}
<INSTRING>.                             {ECH;
                                         sprintf(lexMessage,
                                              "bad character in string");
                                         BEGIN INITIAL;
                                         return BAD;}
<INID>[0-9]+{_}                         {ECH;
                                         sscanf(yytext, "%d", &k);
                                         yylval.ival = k;
                                         BEGIN INITIAL;
                                         return INTSTRING;}
<INID>.                                 {ECH;
                                         sprintf(lexMessage,
                                              "bad character in iId");
                                         BEGIN INITIAL;
                                         return BAD;}
{_}"$"{_}                               {ECH; return DOLLAR;}
{_}","{_}                               {ECH; return C;}
{_}":"{_}                               {ECH; return COLON;}
{_}"="{_}                               {ECH; return EQUALS;}
{_}"["{_}                               {ECH; return LBOX;}
{_}"("{_}                               {ECH; return LPAREN;}
{_}"]"{_}                               {ECH; return RBOX;}
{_}")"{_}                               {ECH; return RPAREN;}
{_}";"{_}                               {ECH;
                                           lineTextIndex = 0;
                                           return SEMICOLON;}
{_}"#"                                  {ECH; BEGIN INID; return SHARP;}
{_}"/"{_}                               {ECH; return SLASH;}
{_}[0-9]+{_}                            {ECH;
                                         sscanf(yytext, "%d", &k);
                                         yylval.ival = k;
                                         return INTSTRING;}
{_}(-?|"+")(([0-9]+"."[0-9]+)|("."[0-9]+)){_} {ECH;
                                         sscanf(yytext, "%lf", &num);
                                         yylval.rval = num;
                                         return REALSTRING;}
{_}(-?|"+")([0-9]+".")/[^a-zA-Z]{_}     {ECH;
                                         sscanf(yytext, "%lf", &num);
                                         yylval.rval = num;
                                         return REALSTRING;}
.                                 {ECH;
                                   sprintf(lexMessage, "bad character");
                                   BEGIN INITIAL;
                                   return BAD;}

%%

int yywrap()
{
  return 1;
}
