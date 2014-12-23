
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

This file defines classes used to represent data in Part 21 files.
The meaning of each class definition is documented. In the
documentation, punctuation marks and special characters that should
appear in program files are enclosed in quotes.

A class is defined for each production in the EBNF file that does not
define a list or give the spelling of a token and is not an optional
parent.

Each expression from the EBNF definition for a production that
corresponds to an attribute in the EXPRESS model used by the EBNF file
is represented by a data member of the class. The name of the data
member is the EXPRESS attribute name given in the comments at the end
of the EBNF file. Each represented item is either a list or a class,
and they are represented as follows.

   Each list data member is represented by a pointer to a C++ standard
   library list of pointers to the class for the item of which the list
   is composed. For example, std::list<cartesianPoint *> * theList

   Every other data member is represented by a pointer to the class for
   that item. 

Classes are not defined for optional parents. If there is an optional
attribute, its value is a pointer to the optional child, but the
pointer may be NULL. No pointer to a non-optional attribute may be NULL.

Each class from which no other class is derived has two constructors
and a destructor. One of the constructors takes no arguments, and sets
nothing. The other constructor takes as many arguments as there are
data members and sets all the data members.

*/

#include <list>

class aString;
class address;
class advancedBrepShapeRepresentation;
class advancedFace;
class aheadOrBehind;
class aheadOrBehindAhead;
class aheadOrBehindBehind;
class aheadOrBehindExact;
class airStrategy;
class alongPath;
class andExpression;
class angleTaper;
class apLiftPathAngle;
class apLiftPathTangent;
class apRetractAngle;
class apRetractTangent;
class approachLiftPath;
class approachRetractStrategy;
class approval;
class approvalStatus;
class assignment;
class axis1placement;
class axis2placement3d;
class axisTrajectory;
class bSplineCurve;
class bSplineCurveForm;
class bSplineCurveFormCircularArc;
class bSplineCurveFormEllipticArc;
class bSplineCurveFormHyperbolicArc;
class bSplineCurveFormParabolicArc;
class bSplineCurveFormPolylineForm;
class bSplineCurveFormUnspecified;
class bSplineCurveWithKnots;
class bSplineSurface;
class bSplineSurfaceForm;
class bSplineSurfaceFormConicalSurf;
class bSplineSurfaceFormCylindricalSurf;
class bSplineSurfaceFormGeneralizedCone;
class bSplineSurfaceFormPlaneSurf;
class bSplineSurfaceFormQuadricSurf;
class bSplineSurfaceFormRuledSurf;
class bSplineSurfaceFormSphericalSurf;
class bSplineSurfaceFormSurfOfLinearExtrusion;
class bSplineSurfaceFormSurfOfRevolution;
class bSplineSurfaceFormToroidalSurf;
class bSplineSurfaceFormUnspecified;
class bSplineSurfaceWithKnots;
class backBoring;
class backsideCounterbore;
class backsideCountersink;
class ballEndmill;
class bezierCurve;
class bezierSurface;
class bidirectionalContour;
class bidirectionalMilling;
class binaryBooleanExpression;
class blindBottomCondition;
class block;
class boolean;
class booleanExpression;
class booleanFalse;
class booleanTrue;
class boring;
class boringOperation;
class boringTool;
class boss;
class bottomAndSideFinishMilling;
class bottomAndSideMilling;
class bottomAndSideRoughMilling;
class bottomOrSide;
class bottomOrSideBottom;
class bottomOrSideBottomAndSide;
class bottomOrSideSide;
class boundedCurve;
class boundedPCurve;
class boundedSurface;
class boundingGeometrySelect;
class bullnoseEndmill;
class calendarDate;
class cartesianPoint;
class catalogueThread;
class centerDrill;
class centerDrilling;
class centerMilling;
class chamfer;
class channel;
class circle;
class circularClosedProfile;
class circularClosedShapeProfile;
class circularOffset;
class circularOmit;
class circularPath;
class circularPattern;
class closedPocket;
class closedProfile;
class closedShell;
class combinedDrillAndReamer;
class combinedDrillAndTap;
class comparisonEqual;
class comparisonExpression;
class comparisonGreater;
class comparisonGreaterEqual;
class comparisonLess;
class comparisonLessEqual;
class comparisonNotEqual;
class completeCircularPath;
class compositeCurve;
class compositeCurveSegment;
class compoundFeature;
class compoundFeatureSelect;
class conic;
class conicalHoleBottom;
class connectDirect;
class connectSecplane;
class connectedFaceSet;
class connector;
class contactType;
class contactTypeFront;
class contactTypeSide;
class contourBidirectional;
class contourParallel;
class contourSpiral;
class coordinatedUniversalTimeOffset;
class counterSinking;
class counterbore;
class counterboreHole;
class counterboreParent;
class countersink;
class countersinkParent;
class countersunkHole;
class curve;
class curveWithNormalVector;
class curveWithSurfaceNormalSelect;
class cutmodeType;
class cutmodeTypeClimb;
class cutmodeTypeConventional;
class cutterContactTrajectory;
class cutterLocationTrajectory;
class cuttingComponent;
class cuttingEdgeTechnologicalData;
class cuttingTool;
class dataSection;
class dataStarter;
class date;
class dateAndTime;
class definedThread;
class definitionalRepresentation;
class descriptiveParameter;
class diameterTaper;
class direction;
class displayMessage;
class dovetailMill;
class drill;
class drilling;
class drillingOperation;
class drillingTypeOperation;
class drillingTypeStrategy;
class edge;
class edgeCurve;
class edgeLoop;
class edgeRound;
class elementarySurface;
class ellipse;
class endSection;
class endmill;
class exchangePallet;
class executable;
class explicitStrategy;
class face;
class faceBound;
class faceBoundParent;
class faceOuterBound;
class faceSurface;
class facemill;
class feedstop;
class fileDescription;
class fileEnd;
class fileName;
class fileSchema;
class fileStart;
class fittingType;
class fittingTypeHole;
class fittingTypeShaft;
class fiveAxesConstTiltYaw;
class fiveAxesVarTiltYaw;
class flatHoleBottom;
class flatSlotEndType;
class flatWithRadiusHoleBottom;
class freeformOperation;
class freeformStrategy;
class generalClosedProfile;
class generalOutsideProfile;
class generalPath;
class generalPattern;
class generalPocketBottomCondition;
class generalProfile;
class generalProfileFloor;
class generalShapeProfile;
class geometricRepresentationItem;
class hand;
class handLeft;
class handNeutral;
class handRight;
class headerSection;
class headerStarter;
class helix;
class holeBottomCondition;
class hyperbola;
class ifStatement;
class inProcessGeometry;
class indexPallet;
class indexTable;
class inputFile;
class instance;
class instanceId;
class integer;
class knotType;
class knotTypePiecewiseBezierKnots;
class knotTypeQuasiUniformKnots;
class knotTypeUniformKnots;
class knotTypeUnspecified;
class leadingLineStrategy;
class leftOrRight;
class leftOrRightLeft;
class leftOrRightRight;
class limitsAndFits;
class line;
class linearPath;
class linearProfile;
class loadTool;
class localTime;
class logical;
class logicalFalse;
class logicalTrue;
class logicalUnknown;
class loop;
class loopSlotEndType;
class machineFunctions;
class machinedSurface;
class machiningFeature;
class machiningOperation;
class machiningTool;
class machiningWorkingstep;
class manifoldSolidBrep;
class manufacturingFeature;
class material;
class millingCutter;
class millingCuttingTool;
class millingMachineFunctions;
class millingMachiningOperation;
class millingTechnology;
class millingThreadingTool;
class millingToolBody;
class millingToolDimension;
class millingTypeOperation;
class multipleArityBooleanExpression;
class multistepDrilling;
class ncConstant;
class ncFunction;
class ncVariable;
class ngonClosedProfile;
class nonSequential;
class notExpression;
class numericParameter;
class offsetVector;
class openPocket;
class openProfile;
class openShell;
class openShellParent;
class openSlotEndType;
class operation;
class optionalStop;
class orExpression;
class ordinalDate;
class orientedEdge;
class parabola;
class parallel;
class parameterisedPath;
class parenAxis2placement3dListFull;
class parenBooleanExpressionListFull;
class parenBossList;
class parenBoundedCurveListFull;
class parenBoundedSurfaceListFull;
class parenCartesianPointList;
class parenCartesianPointListFull;
class parenCircularOffsetList;
class parenCircularOmitList;
class parenCompositeCurveSegmentListFull;
class parenCompoundFeatureSelectListFull;
class parenCuttingComponentListFull;
class parenExecutableList;
class parenExecutableListFull;
class parenFaceBoundListFull;
class parenFaceListFull;
class parenIntegerListFull;
class parenMachinedSurfaceListFull;
class parenMachiningFeatureListFull;
class parenMachiningOperationList;
class parenNcVariableListFull;
class parenOrientedEdgeListFull;
class parenParenCartesianPointListFullListFull;
class parenParenRealListFullListFull;
class parenProcessModelLiszt;
class parenPropertyParameterList;
class parenRealListFull;
class parenRectangularOffsetList;
class parenRectangularOmitList;
class parenRepresentationItemListFull;
class parenSetupInstructionList;
class parenSlotEndTypeList;
class parenSpecificationUsageConstraintList;
class parenStringList;
class parenStringListFull;
class parenToolpathLisztFull;
class parenTrimmingSelectListFull;
class parenWorkpieceList;
class parenWorkpieceSetupList;
class partialAreaDefinition;
class partialCircularPath;
class partialCircularProfile;
class partialCircularShapeProfile;
class pathmodeType;
class pathmodeTypeForward;
class pathmodeTypeZigzag;
class pcurve;
class pcurveParent;
class person;
class personAndAddress;
class placement;
class planarFace;
class planarPocketBottomCondition;
class planarProfileFloor;
class plane;
class planeCcStrategy;
class planeClStrategy;
class planeFinishMilling;
class planeMilling;
class planeRoughMilling;
class plungeHelix;
class plungeRamp;
class plungeStrategy;
class plungeToolaxis;
class plungeZigzag;
class plusMinusValue;
class pocket;
class pocketBottomCondition;
class point;
class polyline;
class processModel;
class processModelList;
class profile;
class profileFeature;
class profileFloor;
class profileSelect;
class programStop;
class programStructure;
class project;
class propertyParameter;
class quasiUniformCurve;
class quasiUniformSurface;
class radiusedPocketBottomCondition;
class radiusedSlotEndType;
class rapidMovement;
class rationalBSplineCurve;
class rationalBSplineSurface;
class real;
class reamer;
class reaming;
class rectangularClosedProfile;
class rectangularClosedShapeProfile;
class rectangularOffset;
class rectangularOmit;
class rectangularOpenShapeProfile;
class rectangularPattern;
class region;
class regionProjection;
class regionSurfaceList;
class replicateFeature;
class representation;
class representationContext;
class representationItem;
class representationParent;
class restrictedAreaSelect;
class rightCircularCylinder;
class rotDirection;
class rotDirectionCcw;
class rotDirectionCw;
class roundHole;
class roundedEnd;
class roundedUProfile;
class rvalue;
class selective;
class setMark;
class setup;
class setupInstruction;
class shapeProfile;
class shapeRepresentation;
class shapeRepresentationParent;
class sideFinishMilling;
class sideMill;
class sideMilling;
class sideRoughMilling;
class slot;
class slotEndType;
class solidModel;
class spadeDrill;
class specification;
class specificationUsageConstraint;
class speedName;
class sphericalCap;
class sphericalHoleBottom;
class sphericalSurface;
class squareUProfile;
class step;
class strokeConnectionStrategy;
class strokeConnectionStrategyDegouge;
class strokeConnectionStrategyLiftShiftPlunge;
class strokeConnectionStrategyLoopBack;
class strokeConnectionStrategyStraightline;
class surface;
class surfaceOfLinearExtrusion;
class surfaceOfRevolution;
class surfaceTextureParameter;
class sweptSurface;
class tSlotMill;
class tap;
class tapParent;
class taperSelect;
class taperedDrill;
class taperedEndmill;
class taperedReamer;
class taperedTap;
class tapping;
class technology;
class teeProfile;
class thread;
class threadDrilling;
class threadMill;
class threeAxes;
class threeAxesTiltedTool;
class throughBottomCondition;
class throughPocketBottomCondition;
class throughProfileFloor;
class toleranceSelect;
class tolerancedLengthMeasure;
class tolerances;
class toolBody;
class toolDirection;
class toolDirectionForMilling;
class toolLengthProbing;
class toolProbing;
class toolRadiusProbing;
class toolReferencePoint;
class toolReferencePointCcp;
class toolReferencePointTcp;
class toolpath;
class toolpathFeature;
class toolpathList;
class toolpathSpeed;
class toolpathSpeedprofile;
class toolpathType;
class toolpathTypeApproach;
class toolpathTypeConnect;
class toolpathTypeContact;
class toolpathTypeLift;
class toolpathTypeNonContact;
class toolpathTypeTrajectoryPath;
class topologicalRegion;
class topologicalRepresentationItem;
class touchProbe;
class touchProbing;
class trajectory;
class transitionCode;
class transitionCodeContSameGradient;
class transitionCodeContSameGradientSameCurvature;
class transitionCodeContinuous;
class transitionCodeDiscontinuous;
class transitionFeature;
class travelPath;
class trimmedCurve;
class trimmingPreference;
class trimmingPreferenceCartesian;
class trimmingPreferenceParameter;
class trimmingPreferenceUnspecified;
class trimmingSelect;
class twistDrill;
class twistDrillParent;
class two5DmanufacturingFeature;
class two5DmillingOperation;
class two5DmillingStrategy;
class twoAxes;
class unaryBooleanExpression;
class unidirectionalMilling;
class uniformCurve;
class uniformSurface;
class unloadTool;
class userDefinedTool;
class uvStrategy;
class vector;
class veeProfile;
class vertex;
class vertexLoop;
class vertexPoint;
class waitForMark;
class weekOfYearAndDayDate;
class whileStatement;
class woodruffKeyseatMill;
class woodruffSlotEndType;
class workingstep;
class workpiece;
class workpieceCompleteProbing;
class workpieceProbing;
class workpieceSetup;
class workplan;
class xorExpression;
class iso14649CppBase;

/********************************************************************/

enum iso14649ClassEName {
aString_E,
address_E,
advancedBrepShapeRepresentation_E,
advancedFace_E,
aheadOrBehind_E,
aheadOrBehindAhead_E,
aheadOrBehindBehind_E,
aheadOrBehindExact_E,
airStrategy_E,
alongPath_E,
andExpression_E,
angleTaper_E,
apLiftPathAngle_E,
apLiftPathTangent_E,
apRetractAngle_E,
apRetractTangent_E,
approachLiftPath_E,
approachRetractStrategy_E,
approval_E,
approvalStatus_E,
assignment_E,
axis1placement_E,
axis2placement3d_E,
axisTrajectory_E,
bSplineCurve_E,
bSplineCurveForm_E,
bSplineCurveFormCircularArc_E,
bSplineCurveFormEllipticArc_E,
bSplineCurveFormHyperbolicArc_E,
bSplineCurveFormParabolicArc_E,
bSplineCurveFormPolylineForm_E,
bSplineCurveFormUnspecified_E,
bSplineCurveWithKnots_E,
bSplineSurface_E,
bSplineSurfaceForm_E,
bSplineSurfaceFormConicalSurf_E,
bSplineSurfaceFormCylindricalSurf_E,
bSplineSurfaceFormGeneralizedCone_E,
bSplineSurfaceFormPlaneSurf_E,
bSplineSurfaceFormQuadricSurf_E,
bSplineSurfaceFormRuledSurf_E,
bSplineSurfaceFormSphericalSurf_E,
bSplineSurfaceFormSurfOfLinearExtrusion_E,
bSplineSurfaceFormSurfOfRevolution_E,
bSplineSurfaceFormToroidalSurf_E,
bSplineSurfaceFormUnspecified_E,
bSplineSurfaceWithKnots_E,
backBoring_E,
backsideCounterbore_E,
backsideCountersink_E,
ballEndmill_E,
bezierCurve_E,
bezierSurface_E,
bidirectionalContour_E,
bidirectionalMilling_E,
binaryBooleanExpression_E,
blindBottomCondition_E,
block_E,
boolean_E,
booleanExpression_E,
booleanFalse_E,
booleanTrue_E,
boring_E,
boringOperation_E,
boringTool_E,
boss_E,
bottomAndSideFinishMilling_E,
bottomAndSideMilling_E,
bottomAndSideRoughMilling_E,
bottomOrSide_E,
bottomOrSideBottom_E,
bottomOrSideBottomAndSide_E,
bottomOrSideSide_E,
boundedCurve_E,
boundedPCurve_E,
boundedSurface_E,
boundingGeometrySelect_E,
bullnoseEndmill_E,
calendarDate_E,
cartesianPoint_E,
catalogueThread_E,
centerDrill_E,
centerDrilling_E,
centerMilling_E,
chamfer_E,
channel_E,
circle_E,
circularClosedProfile_E,
circularClosedShapeProfile_E,
circularOffset_E,
circularOmit_E,
circularPath_E,
circularPattern_E,
closedPocket_E,
closedProfile_E,
closedShell_E,
combinedDrillAndReamer_E,
combinedDrillAndTap_E,
comparisonEqual_E,
comparisonExpression_E,
comparisonGreater_E,
comparisonGreaterEqual_E,
comparisonLess_E,
comparisonLessEqual_E,
comparisonNotEqual_E,
completeCircularPath_E,
compositeCurve_E,
compositeCurveSegment_E,
compoundFeature_E,
compoundFeatureSelect_E,
conic_E,
conicalHoleBottom_E,
connectDirect_E,
connectSecplane_E,
connectedFaceSet_E,
connector_E,
contactType_E,
contactTypeFront_E,
contactTypeSide_E,
contourBidirectional_E,
contourParallel_E,
contourSpiral_E,
coordinatedUniversalTimeOffset_E,
counterSinking_E,
counterbore_E,
counterboreHole_E,
counterboreParent_E,
countersink_E,
countersinkParent_E,
countersunkHole_E,
curve_E,
curveWithNormalVector_E,
curveWithSurfaceNormalSelect_E,
cutmodeType_E,
cutmodeTypeClimb_E,
cutmodeTypeConventional_E,
cutterContactTrajectory_E,
cutterLocationTrajectory_E,
cuttingComponent_E,
cuttingEdgeTechnologicalData_E,
cuttingTool_E,
dataSection_E,
dataStarter_E,
date_E,
dateAndTime_E,
definedThread_E,
definitionalRepresentation_E,
descriptiveParameter_E,
diameterTaper_E,
direction_E,
displayMessage_E,
dovetailMill_E,
drill_E,
drilling_E,
drillingOperation_E,
drillingTypeOperation_E,
drillingTypeStrategy_E,
edge_E,
edgeCurve_E,
edgeLoop_E,
edgeRound_E,
elementarySurface_E,
ellipse_E,
endSection_E,
endmill_E,
exchangePallet_E,
executable_E,
explicitStrategy_E,
face_E,
faceBound_E,
faceBoundParent_E,
faceOuterBound_E,
faceSurface_E,
facemill_E,
feedstop_E,
fileDescription_E,
fileEnd_E,
fileName_E,
fileSchema_E,
fileStart_E,
fittingType_E,
fittingTypeHole_E,
fittingTypeShaft_E,
fiveAxesConstTiltYaw_E,
fiveAxesVarTiltYaw_E,
flatHoleBottom_E,
flatSlotEndType_E,
flatWithRadiusHoleBottom_E,
freeformOperation_E,
freeformStrategy_E,
generalClosedProfile_E,
generalOutsideProfile_E,
generalPath_E,
generalPattern_E,
generalPocketBottomCondition_E,
generalProfile_E,
generalProfileFloor_E,
generalShapeProfile_E,
geometricRepresentationItem_E,
hand_E,
handLeft_E,
handNeutral_E,
handRight_E,
headerSection_E,
headerStarter_E,
helix_E,
holeBottomCondition_E,
hyperbola_E,
ifStatement_E,
inProcessGeometry_E,
indexPallet_E,
indexTable_E,
inputFile_E,
instance_E,
instanceId_E,
integer_E,
knotType_E,
knotTypePiecewiseBezierKnots_E,
knotTypeQuasiUniformKnots_E,
knotTypeUniformKnots_E,
knotTypeUnspecified_E,
leadingLineStrategy_E,
leftOrRight_E,
leftOrRightLeft_E,
leftOrRightRight_E,
limitsAndFits_E,
line_E,
linearPath_E,
linearProfile_E,
loadTool_E,
localTime_E,
logical_E,
logicalFalse_E,
logicalTrue_E,
logicalUnknown_E,
loop_E,
loopSlotEndType_E,
machineFunctions_E,
machinedSurface_E,
machiningFeature_E,
machiningOperation_E,
machiningTool_E,
machiningWorkingstep_E,
manifoldSolidBrep_E,
manufacturingFeature_E,
material_E,
millingCutter_E,
millingCuttingTool_E,
millingMachineFunctions_E,
millingMachiningOperation_E,
millingTechnology_E,
millingThreadingTool_E,
millingToolBody_E,
millingToolDimension_E,
millingTypeOperation_E,
multipleArityBooleanExpression_E,
multistepDrilling_E,
ncConstant_E,
ncFunction_E,
ncVariable_E,
ngonClosedProfile_E,
nonSequential_E,
notExpression_E,
numericParameter_E,
offsetVector_E,
openPocket_E,
openProfile_E,
openShell_E,
openShellParent_E,
openSlotEndType_E,
operation_E,
optionalStop_E,
orExpression_E,
ordinalDate_E,
orientedEdge_E,
parabola_E,
parallel_E,
parameterisedPath_E,
parenAxis2placement3dListFull_E,
parenBooleanExpressionListFull_E,
parenBossList_E,
parenBoundedCurveListFull_E,
parenBoundedSurfaceListFull_E,
parenCartesianPointList_E,
parenCartesianPointListFull_E,
parenCircularOffsetList_E,
parenCircularOmitList_E,
parenCompositeCurveSegmentListFull_E,
parenCompoundFeatureSelectListFull_E,
parenCuttingComponentListFull_E,
parenExecutableList_E,
parenExecutableListFull_E,
parenFaceBoundListFull_E,
parenFaceListFull_E,
parenIntegerListFull_E,
parenMachinedSurfaceListFull_E,
parenMachiningFeatureListFull_E,
parenMachiningOperationList_E,
parenNcVariableListFull_E,
parenOrientedEdgeListFull_E,
parenParenCartesianPointListFullListFull_E,
parenParenRealListFullListFull_E,
parenProcessModelLiszt_E,
parenPropertyParameterList_E,
parenRealListFull_E,
parenRectangularOffsetList_E,
parenRectangularOmitList_E,
parenRepresentationItemListFull_E,
parenSetupInstructionList_E,
parenSlotEndTypeList_E,
parenSpecificationUsageConstraintList_E,
parenStringList_E,
parenStringListFull_E,
parenToolpathLisztFull_E,
parenTrimmingSelectListFull_E,
parenWorkpieceList_E,
parenWorkpieceSetupList_E,
partialAreaDefinition_E,
partialCircularPath_E,
partialCircularProfile_E,
partialCircularShapeProfile_E,
pathmodeType_E,
pathmodeTypeForward_E,
pathmodeTypeZigzag_E,
pcurve_E,
pcurveParent_E,
person_E,
personAndAddress_E,
placement_E,
planarFace_E,
planarPocketBottomCondition_E,
planarProfileFloor_E,
plane_E,
planeCcStrategy_E,
planeClStrategy_E,
planeFinishMilling_E,
planeMilling_E,
planeRoughMilling_E,
plungeHelix_E,
plungeRamp_E,
plungeStrategy_E,
plungeToolaxis_E,
plungeZigzag_E,
plusMinusValue_E,
pocket_E,
pocketBottomCondition_E,
point_E,
polyline_E,
processModel_E,
processModelList_E,
profile_E,
profileFeature_E,
profileFloor_E,
profileSelect_E,
programStop_E,
programStructure_E,
project_E,
propertyParameter_E,
quasiUniformCurve_E,
quasiUniformSurface_E,
radiusedPocketBottomCondition_E,
radiusedSlotEndType_E,
rapidMovement_E,
rationalBSplineCurve_E,
rationalBSplineSurface_E,
real_E,
reamer_E,
reaming_E,
rectangularClosedProfile_E,
rectangularClosedShapeProfile_E,
rectangularOffset_E,
rectangularOmit_E,
rectangularOpenShapeProfile_E,
rectangularPattern_E,
region_E,
regionProjection_E,
regionSurfaceList_E,
replicateFeature_E,
representation_E,
representationContext_E,
representationItem_E,
representationParent_E,
restrictedAreaSelect_E,
rightCircularCylinder_E,
rotDirection_E,
rotDirectionCcw_E,
rotDirectionCw_E,
roundHole_E,
roundedEnd_E,
roundedUProfile_E,
rvalue_E,
selective_E,
setMark_E,
setup_E,
setupInstruction_E,
shapeProfile_E,
shapeRepresentation_E,
shapeRepresentationParent_E,
sideFinishMilling_E,
sideMill_E,
sideMilling_E,
sideRoughMilling_E,
slot_E,
slotEndType_E,
solidModel_E,
spadeDrill_E,
specification_E,
specificationUsageConstraint_E,
speedName_E,
sphericalCap_E,
sphericalHoleBottom_E,
sphericalSurface_E,
squareUProfile_E,
step_E,
strokeConnectionStrategy_E,
strokeConnectionStrategyDegouge_E,
strokeConnectionStrategyLiftShiftPlunge_E,
strokeConnectionStrategyLoopBack_E,
strokeConnectionStrategyStraightline_E,
surface_E,
surfaceOfLinearExtrusion_E,
surfaceOfRevolution_E,
surfaceTextureParameter_E,
sweptSurface_E,
tSlotMill_E,
tap_E,
tapParent_E,
taperSelect_E,
taperedDrill_E,
taperedEndmill_E,
taperedReamer_E,
taperedTap_E,
tapping_E,
technology_E,
teeProfile_E,
thread_E,
threadDrilling_E,
threadMill_E,
threeAxes_E,
threeAxesTiltedTool_E,
throughBottomCondition_E,
throughPocketBottomCondition_E,
throughProfileFloor_E,
toleranceSelect_E,
tolerancedLengthMeasure_E,
tolerances_E,
toolBody_E,
toolDirection_E,
toolDirectionForMilling_E,
toolLengthProbing_E,
toolProbing_E,
toolRadiusProbing_E,
toolReferencePoint_E,
toolReferencePointCcp_E,
toolReferencePointTcp_E,
toolpath_E,
toolpathFeature_E,
toolpathList_E,
toolpathSpeed_E,
toolpathSpeedprofile_E,
toolpathType_E,
toolpathTypeApproach_E,
toolpathTypeConnect_E,
toolpathTypeContact_E,
toolpathTypeLift_E,
toolpathTypeNonContact_E,
toolpathTypeTrajectoryPath_E,
topologicalRegion_E,
topologicalRepresentationItem_E,
touchProbe_E,
touchProbing_E,
trajectory_E,
transitionCode_E,
transitionCodeContSameGradient_E,
transitionCodeContSameGradientSameCurvature_E,
transitionCodeContinuous_E,
transitionCodeDiscontinuous_E,
transitionFeature_E,
travelPath_E,
trimmedCurve_E,
trimmingPreference_E,
trimmingPreferenceCartesian_E,
trimmingPreferenceParameter_E,
trimmingPreferenceUnspecified_E,
trimmingSelect_E,
twistDrill_E,
twistDrillParent_E,
two5DmanufacturingFeature_E,
two5DmillingOperation_E,
two5DmillingStrategy_E,
twoAxes_E,
unaryBooleanExpression_E,
unidirectionalMilling_E,
uniformCurve_E,
uniformSurface_E,
unloadTool_E,
userDefinedTool_E,
uvStrategy_E,
vector_E,
veeProfile_E,
vertex_E,
vertexLoop_E,
vertexPoint_E,
waitForMark_E,
weekOfYearAndDayDate_E,
whileStatement_E,
woodruffKeyseatMill_E,
woodruffSlotEndType_E,
workingstep_E,
workpiece_E,
workpieceCompleteProbing_E,
workpieceProbing_E,
workpieceSetup_E,
workplan_E,
xorExpression_E,
iso14649CppBase_E};

/********************************************************************/

/* iso14649CppBase

This is the base class for all other classes. It has virtual
functions printSelf and isA.

*/

class iso14649CppBase
{
public:
  iso14649CppBase();
  virtual ~iso14649CppBase();
  virtual void printSelf() = 0;
  virtual int isA(int aType) = 0;
};

/********************************************************************/

/* inputFile

This is a class for the single definition of inputFile.
It represents the following items:

fileStart headerSection dataSection fileEnd

*/

class inputFile :
  public iso14649CppBase
{
public:
  inputFile();
  inputFile(
    fileStart * inputStartIn,
    headerSection * inputHeaderIn,
    dataSection * inputDataIn,
    fileEnd * inputEndIn);
  ~inputFile();
  int isA(int aType);
  void printSelf();
  fileStart * inputStart;
  headerSection * inputHeader;
  dataSection * inputData;
  fileEnd * inputEnd;
};

/********************************************************************/

/* instance

This is the instance class.

*/

class instance :
  public iso14649CppBase
{
public:
  instance();
  instance(instanceId * iIdIn);
  ~instance();
  int isA(int aType) = 0;
  void printSelf() = 0;
  instanceId * iId;
};

/********************************************************************/

/* address

This is a class for the single definition of address.
It represents the following items:

ADDRESS '(' optString ',' optString ',' optString ',' optString ',' optString ',' optString ',' optString ',' optString ',' optString ',' optString ',' optString ',' optString ',' ')'

*/

class address :
  public instance
{
public:
  address();
  address(
    aString * internalLocationIn,
    aString * streetNumberIn,
    aString * streetIn,
    aString * postalBoxIn,
    aString * townIn,
    aString * regionIn,
    aString * postalCodeIn,
    aString * countryIn,
    aString * facsimileNumberIn,
    aString * telephoneNumberIn,
    aString * electronicMailAddressIn,
    aString * telexNumberIn);
  ~address();
  int isA(int aType);
  void printSelf();
  aString * internalLocation;
  aString * streetNumber;
  aString * street;
  aString * postalBox;
  aString * town;
  aString * region;
  aString * postalCode;
  aString * country;
  aString * facsimileNumber;
  aString * telephoneNumber;
  aString * electronicMailAddress;
  aString * telexNumber;
};

/********************************************************************/

/* aheadOrBehind

This is a parent class.

*/

class aheadOrBehind :
  public iso14649CppBase
{
public:
  aheadOrBehind();
  ~aheadOrBehind();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* aheadOrBehindAhead

This is a class for the single definition of aheadOrBehindAhead.
It represents the following items:

AHEADORBEHINDAHEAD

*/

class aheadOrBehindAhead :
  public aheadOrBehind
{
public:
  aheadOrBehindAhead();
  ~aheadOrBehindAhead();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* aheadOrBehindBehind

This is a class for the single definition of aheadOrBehindBehind.
It represents the following items:

AHEADORBEHINDBEHIND

*/

class aheadOrBehindBehind :
  public aheadOrBehind
{
public:
  aheadOrBehindBehind();
  ~aheadOrBehindBehind();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* aheadOrBehindExact

This is a class for the single definition of aheadOrBehindExact.
It represents the following items:

AHEADORBEHINDEXACT

*/

class aheadOrBehindExact :
  public aheadOrBehind
{
public:
  aheadOrBehindExact();
  ~aheadOrBehindExact();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* approachRetractStrategy

This is a parent class.

*/

class approachRetractStrategy :
  public iso14649CppBase
{
public:
  approachRetractStrategy();
  approachRetractStrategy(
    direction * toolOrientationIn);
  ~approachRetractStrategy();
  int isA(int aType);
  void printSelf() = 0;
  direction * toolOrientation;
};

/********************************************************************/

/* approval

This is a class for the single definition of approval.
It represents the following items:

APPROVAL '(' approvalStatus ',' CHARSTRING ')'

*/

class approval :
  public instance
{
public:
  approval();
  approval(
    approvalStatus * statusIn,
    char * levelIn);
  ~approval();
  int isA(int aType);
  void printSelf();
  approvalStatus * status;
  char * level;
};

/********************************************************************/

/* approvalStatus

This is a class for the single definition of approvalStatus.
It represents the following items:

APPROVALSTATUS '(' CHARSTRING ')'

*/

class approvalStatus :
  public instance
{
public:
  approvalStatus();
  approvalStatus(
    char * nameIn);
  ~approvalStatus();
  int isA(int aType);
  void printSelf();
  char * name;
};

/********************************************************************/

/* aString

This is a class for the single definition of aString.
It represents the following items:

CHARSTRING

*/

class aString :
  public iso14649CppBase
{
public:
  aString();
  aString(
    char * theStringIn);
  ~aString();
  int isA(int aType);
  void printSelf();
  char * theString;
};

/********************************************************************/

/* boolean

This is a parent class.

*/

class boolean :
  public iso14649CppBase
{
public:
  boolean();
  ~boolean();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* booleanExpression

This is a parent class.

*/

class booleanExpression :
  public iso14649CppBase
{
public:
  booleanExpression();
  ~booleanExpression();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* booleanFalse

This is a class for the single definition of booleanFalse.
It represents the following items:

FALSE

*/

class booleanFalse :
  public boolean
{
public:
  booleanFalse();
  ~booleanFalse();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* booleanTrue

This is a class for the single definition of booleanTrue.
It represents the following items:

TRUE

*/

class booleanTrue :
  public boolean
{
public:
  booleanTrue();
  ~booleanTrue();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bottomOrSide

This is a parent class.

*/

class bottomOrSide :
  public iso14649CppBase
{
public:
  bottomOrSide();
  ~bottomOrSide();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* bottomOrSideBottom

This is a class for the single definition of bottomOrSideBottom.
It represents the following items:

BOTTOMORSIDEBOTTOM

*/

class bottomOrSideBottom :
  public bottomOrSide
{
public:
  bottomOrSideBottom();
  ~bottomOrSideBottom();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bottomOrSideSide

This is a class for the single definition of bottomOrSideSide.
It represents the following items:

BOTTOMORSIDESIDE

*/

class bottomOrSideSide :
  public bottomOrSide
{
public:
  bottomOrSideSide();
  ~bottomOrSideSide();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bottomOrSideBottomAndSide

This is a class for the single definition of bottomOrSideBottomAndSide.
It represents the following items:

BOTTOMORSIDEBOTTOMANDSIDE

*/

class bottomOrSideBottomAndSide :
  public bottomOrSide
{
public:
  bottomOrSideBottomAndSide();
  ~bottomOrSideBottomAndSide();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineCurveForm

This is a parent class.

*/

class bSplineCurveForm :
  public iso14649CppBase
{
public:
  bSplineCurveForm();
  ~bSplineCurveForm();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* bSplineCurveFormPolylineForm

This is a class for the single definition of bSplineCurveFormPolylineForm.
It represents the following items:

BSPLINECURVEFORMPOLYLINEFORM

*/

class bSplineCurveFormPolylineForm :
  public bSplineCurveForm
{
public:
  bSplineCurveFormPolylineForm();
  ~bSplineCurveFormPolylineForm();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineCurveFormCircularArc

This is a class for the single definition of bSplineCurveFormCircularArc.
It represents the following items:

BSPLINECURVEFORMCIRCULARARC

*/

class bSplineCurveFormCircularArc :
  public bSplineCurveForm
{
public:
  bSplineCurveFormCircularArc();
  ~bSplineCurveFormCircularArc();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineCurveFormEllipticArc

This is a class for the single definition of bSplineCurveFormEllipticArc.
It represents the following items:

BSPLINECURVEFORMELLIPTICARC

*/

class bSplineCurveFormEllipticArc :
  public bSplineCurveForm
{
public:
  bSplineCurveFormEllipticArc();
  ~bSplineCurveFormEllipticArc();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineCurveFormParabolicArc

This is a class for the single definition of bSplineCurveFormParabolicArc.
It represents the following items:

BSPLINECURVEFORMPARABOLICARC

*/

class bSplineCurveFormParabolicArc :
  public bSplineCurveForm
{
public:
  bSplineCurveFormParabolicArc();
  ~bSplineCurveFormParabolicArc();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineCurveFormHyperbolicArc

This is a class for the single definition of bSplineCurveFormHyperbolicArc.
It represents the following items:

BSPLINECURVEFORMHYPERBOLICARC

*/

class bSplineCurveFormHyperbolicArc :
  public bSplineCurveForm
{
public:
  bSplineCurveFormHyperbolicArc();
  ~bSplineCurveFormHyperbolicArc();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineCurveFormUnspecified

This is a class for the single definition of bSplineCurveFormUnspecified.
It represents the following items:

BSPLINECURVEFORMUNSPECIFIED

*/

class bSplineCurveFormUnspecified :
  public bSplineCurveForm
{
public:
  bSplineCurveFormUnspecified();
  ~bSplineCurveFormUnspecified();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceForm

This is a parent class.

*/

class bSplineSurfaceForm :
  public iso14649CppBase
{
public:
  bSplineSurfaceForm();
  ~bSplineSurfaceForm();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* bSplineSurfaceFormConicalSurf

This is a class for the single definition of bSplineSurfaceFormConicalSurf.
It represents the following items:

BSPLINESURFACEFORMCONICALSURF

*/

class bSplineSurfaceFormConicalSurf :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormConicalSurf();
  ~bSplineSurfaceFormConicalSurf();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormCylindricalSurf

This is a class for the single definition of bSplineSurfaceFormCylindricalSurf.
It represents the following items:

BSPLINESURFACEFORMCYLINDRICALSURF

*/

class bSplineSurfaceFormCylindricalSurf :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormCylindricalSurf();
  ~bSplineSurfaceFormCylindricalSurf();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormGeneralizedCone

This is a class for the single definition of bSplineSurfaceFormGeneralizedCone.
It represents the following items:

BSPLINESURFACEFORMGENERALIZEDCONE

*/

class bSplineSurfaceFormGeneralizedCone :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormGeneralizedCone();
  ~bSplineSurfaceFormGeneralizedCone();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormPlaneSurf

This is a class for the single definition of bSplineSurfaceFormPlaneSurf.
It represents the following items:

BSPLINESURFACEFORMPLANESURF

*/

class bSplineSurfaceFormPlaneSurf :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormPlaneSurf();
  ~bSplineSurfaceFormPlaneSurf();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormQuadricSurf

This is a class for the single definition of bSplineSurfaceFormQuadricSurf.
It represents the following items:

BSPLINESURFACEFORMQUADRICSURF

*/

class bSplineSurfaceFormQuadricSurf :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormQuadricSurf();
  ~bSplineSurfaceFormQuadricSurf();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormRuledSurf

This is a class for the single definition of bSplineSurfaceFormRuledSurf.
It represents the following items:

BSPLINESURFACEFORMRULEDSURF

*/

class bSplineSurfaceFormRuledSurf :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormRuledSurf();
  ~bSplineSurfaceFormRuledSurf();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormSphericalSurf

This is a class for the single definition of bSplineSurfaceFormSphericalSurf.
It represents the following items:

BSPLINESURFACEFORMSPHERICALSURF

*/

class bSplineSurfaceFormSphericalSurf :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormSphericalSurf();
  ~bSplineSurfaceFormSphericalSurf();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormSurfOfLinearExtrusion

This is a class for the single definition of bSplineSurfaceFormSurfOfLinearExtrusion.
It represents the following items:

BSPLINESURFACEFORMSURFOFLINEAREXTRUSION

*/

class bSplineSurfaceFormSurfOfLinearExtrusion :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormSurfOfLinearExtrusion();
  ~bSplineSurfaceFormSurfOfLinearExtrusion();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormSurfOfRevolution

This is a class for the single definition of bSplineSurfaceFormSurfOfRevolution.
It represents the following items:

BSPLINESURFACEFORMSURFOFREVOLUTION

*/

class bSplineSurfaceFormSurfOfRevolution :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormSurfOfRevolution();
  ~bSplineSurfaceFormSurfOfRevolution();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormToroidalSurf

This is a class for the single definition of bSplineSurfaceFormToroidalSurf.
It represents the following items:

BSPLINESURFACEFORMTOROIDALSURF

*/

class bSplineSurfaceFormToroidalSurf :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormToroidalSurf();
  ~bSplineSurfaceFormToroidalSurf();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineSurfaceFormUnspecified

This is a class for the single definition of bSplineSurfaceFormUnspecified.
It represents the following items:

BSPLINESURFACEFORMUNSPECIFIED

*/

class bSplineSurfaceFormUnspecified :
  public bSplineSurfaceForm
{
public:
  bSplineSurfaceFormUnspecified();
  ~bSplineSurfaceFormUnspecified();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* channel

This is a class for the single definition of channel.
It represents the following items:

CHANNEL '(' CHARSTRING ')'

*/

class channel :
  public instance
{
public:
  channel();
  channel(
    char * itsIdIn);
  ~channel();
  int isA(int aType);
  void printSelf();
  char * itsId;
};

/********************************************************************/

/* circularOffset

This is a class for the single definition of circularOffset.
It represents the following items:

CIRCULAROFFSET '(' REALSTRING ',' INTSTRING ')'

*/

class circularOffset :
  public instance
{
public:
  circularOffset();
  circularOffset(
    double angularOffsetIn,
    int indexIn);
  ~circularOffset();
  int isA(int aType);
  void printSelf();
  double angularOffset;
  int index;
};

/********************************************************************/

/* circularOmit

This is a class for the single definition of circularOmit.
It represents the following items:

CIRCULAROMIT '(' INTSTRING ')'

*/

class circularOmit :
  public instance
{
public:
  circularOmit();
  circularOmit(
    int indexIn);
  ~circularOmit();
  int isA(int aType);
  void printSelf();
  int index;
};

/********************************************************************/

/* comparisonExpression

This is a parent class.

*/

class comparisonExpression :
  public booleanExpression
{
public:
  comparisonExpression();
  comparisonExpression(
    ncVariable * operand1In,
    rvalue * operand2In);
  ~comparisonExpression();
  int isA(int aType);
  void printSelf() = 0;
  ncVariable * operand1;
  rvalue * operand2;
};

/********************************************************************/

/* compositeCurveSegment

This is a class for the single definition of compositeCurveSegment.
It represents the following items:

COMPOSITECURVESEGMENT '(' transitionCode ',' boolean ',' curve ')'

*/

class compositeCurveSegment :
  public instance
{
public:
  compositeCurveSegment();
  compositeCurveSegment(
    transitionCode * transitionIn,
    boolean * sameSenseIn,
    curve * parentCurveIn);
  ~compositeCurveSegment();
  int isA(int aType);
  void printSelf();
  transitionCode * transition;
  boolean * sameSense;
  curve * parentCurve;
};

/********************************************************************/

/* compoundFeatureSelect

This is a parent class.

*/

class compoundFeatureSelect :
  public iso14649CppBase
{
public:
  compoundFeatureSelect();
  ~compoundFeatureSelect();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* contactType

This is a parent class.

*/

class contactType :
  public iso14649CppBase
{
public:
  contactType();
  ~contactType();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* contactTypeSide

This is a class for the single definition of contactTypeSide.
It represents the following items:

CONTACTTYPESIDE

*/

class contactTypeSide :
  public contactType
{
public:
  contactTypeSide();
  ~contactTypeSide();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* contactTypeFront

This is a class for the single definition of contactTypeFront.
It represents the following items:

CONTACTTYPEFRONT

*/

class contactTypeFront :
  public contactType
{
public:
  contactTypeFront();
  ~contactTypeFront();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* coordinatedUniversalTimeOffset

This is a class for the single definition of coordinatedUniversalTimeOffset.
It represents the following items:

COORDINATEDUNIVERSALTIMEOFFSET '(' INTSTRING optInteger aheadOrBehind ')'

*/

class coordinatedUniversalTimeOffset :
  public instance
{
public:
  coordinatedUniversalTimeOffset();
  coordinatedUniversalTimeOffset(
    int hourOffsetIn,
    integer * minuteOffsetIn,
    aheadOrBehind * senseIn);
  ~coordinatedUniversalTimeOffset();
  int isA(int aType);
  void printSelf();
  int hourOffset;
  integer * minuteOffset;
  aheadOrBehind * sense;
};

/********************************************************************/

/* curveWithSurfaceNormalSelect

This is a parent class.

*/

class curveWithSurfaceNormalSelect :
  public iso14649CppBase
{
public:
  curveWithSurfaceNormalSelect();
  ~curveWithSurfaceNormalSelect();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* cutmodeType

This is a parent class.

*/

class cutmodeType :
  public iso14649CppBase
{
public:
  cutmodeType();
  ~cutmodeType();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* cutmodeTypeClimb

This is a class for the single definition of cutmodeTypeClimb.
It represents the following items:

CUTMODETYPECLIMB

*/

class cutmodeTypeClimb :
  public cutmodeType
{
public:
  cutmodeTypeClimb();
  ~cutmodeTypeClimb();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* cutmodeTypeConventional

This is a class for the single definition of cutmodeTypeConventional.
It represents the following items:

CUTMODETYPECONVENTIONAL

*/

class cutmodeTypeConventional :
  public cutmodeType
{
public:
  cutmodeTypeConventional();
  ~cutmodeTypeConventional();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* cutterContactTrajectory

This is a class for the single definition of cutterContactTrajectory.
It represents the following items:

CUTTERCONTACTTRAJECTORY '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ',' optBoolean ',' curveWithSurfaceNormalSelect ',' optBoundedCurve ',' optContactType ')'

*/

class cutterContactTrajectory :
  public instance
{
public:
  cutterContactTrajectory();
  cutterContactTrajectory(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    boolean * itsDirectionIn,
    curveWithSurfaceNormalSelect * basiccurveIn,
    boundedCurve * itsToolaxisIn,
    contactType * itsContactTypeIn);
  ~cutterContactTrajectory();
  int isA(int aType);
  void printSelf();
  boolean * itsPriority;
  toolpathType * itsType;
  toolpathSpeedprofile * itsSpeed;
  technology * itsTechnology;
  machineFunctions * itsMachineFunctions;
  boolean * itsDirection;
  curveWithSurfaceNormalSelect * basiccurve;
  boundedCurve * itsToolaxis;
  contactType * itsContactType;
};

/********************************************************************/

/* cuttingComponent

This is a class for the single definition of cuttingComponent.
It represents the following items:

CUTTINGCOMPONENT '(' REALSTRING ',' optMaterial ',' optCuttingEdgeTechnologicalData ',' optReal ',' optMillingTechnology ')'

*/

class cuttingComponent :
  public instance
{
public:
  cuttingComponent();
  cuttingComponent(
    double toolOffsetLengthIn,
    material * itsMaterialIn,
    cuttingEdgeTechnologicalData * technologicalDataIn,
    real * expectedToolLifeIn,
    millingTechnology * itsTechnologyIn);
  ~cuttingComponent();
  int isA(int aType);
  void printSelf();
  double toolOffsetLength;
  material * itsMaterial;
  cuttingEdgeTechnologicalData * technologicalData;
  real * expectedToolLife;
  millingTechnology * itsTechnology;
};

/********************************************************************/

/* cuttingEdgeTechnologicalData

This is a class for the single definition of cuttingEdgeTechnologicalData.
It represents the following items:

CUTTINGEDGETECHNOLOGICALDATA '(' optReal ',' optReal ',' optReal ')'

*/

class cuttingEdgeTechnologicalData :
  public instance
{
public:
  cuttingEdgeTechnologicalData();
  cuttingEdgeTechnologicalData(
    real * cuttingAngleIn,
    real * freeAngleIn,
    real * auxAngleIn);
  ~cuttingEdgeTechnologicalData();
  int isA(int aType);
  void printSelf();
  real * cuttingAngle;
  real * freeAngle;
  real * auxAngle;
};

/********************************************************************/

/* dataSection

This is a class for the single definition of dataSection.
It represents the following items:

dataStarter instancePlusList endSection

*/

class dataSection :
  public iso14649CppBase
{
public:
  dataSection();
  dataSection(
    dataStarter * dataStartIn,
    std::list<instance *> * itemsIn,
    endSection * sectionEndIn);
  ~dataSection();
  int isA(int aType);
  void printSelf();
  dataStarter * dataStart;
  std::list<instance *> * items;
  endSection * sectionEnd;
};

/********************************************************************/

/* dataStarter

This is a class for the single definition of dataStarter.
It represents the following items:

DATA ';'

*/

class dataStarter :
  public iso14649CppBase
{
public:
  dataStarter();
  ~dataStarter();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* date

This is a parent class.

*/

class date :
  public iso14649CppBase
{
public:
  date();
  date(
    int yearComponentIn);
  ~date();
  int isA(int aType);
  void printSelf() = 0;
  int yearComponent;
};

/********************************************************************/

/* dateAndTime

This is a class for the single definition of dateAndTime.
It represents the following items:

DATEANDTIME '(' date ',' localTime ')'

*/

class dateAndTime :
  public instance
{
public:
  dateAndTime();
  dateAndTime(
    date * dateComponentIn,
    localTime * timeComponentIn);
  ~dateAndTime();
  int isA(int aType);
  void printSelf();
  date * dateComponent;
  localTime * timeComponent;
};

/********************************************************************/

/* drillingTypeStrategy

This is a class for the single definition of drillingTypeStrategy.
It represents the following items:

DRILLINGTYPESTRATEGY '(' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ')'

*/

class drillingTypeStrategy :
  public instance
{
public:
  drillingTypeStrategy();
  drillingTypeStrategy(
    real * reducedCutAtStartIn,
    real * reducedFeedAtStartIn,
    real * depthOfStartIn,
    real * reducedCutAtEndIn,
    real * reducedFeedAtEndIn,
    real * depthOfEndIn);
  ~drillingTypeStrategy();
  int isA(int aType);
  void printSelf();
  real * reducedCutAtStart;
  real * reducedFeedAtStart;
  real * depthOfStart;
  real * reducedCutAtEnd;
  real * reducedFeedAtEnd;
  real * depthOfEnd;
};

/********************************************************************/

/* endSection

This is a class for the single definition of endSection.
It represents the following items:

ENDSEC ';'

*/

class endSection :
  public iso14649CppBase
{
public:
  endSection();
  ~endSection();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* executable

This is a parent class.

*/

class executable :
  public iso14649CppBase
{
public:
  executable();
  executable(
    char * itsIdIn);
  ~executable();
  int isA(int aType);
  void printSelf() = 0;
  char * itsId;
};

/********************************************************************/

/* fileDescription

This is a class for the single definition of fileDescription.
It represents the following items:

FILEDESCRIPTION '(' parenStringListFull ',' CHARSTRING ')' ';'

*/

class fileDescription :
  public iso14649CppBase
{
public:
  fileDescription();
  fileDescription(
    parenStringListFull * descriptionIn,
    char * implementationLevelIn);
  ~fileDescription();
  int isA(int aType);
  void printSelf();
  parenStringListFull * description;
  char * implementationLevel;
};

/********************************************************************/

/* fileEnd

This is a class for the single definition of fileEnd.
It represents the following items:

FILEEND ';'

*/

class fileEnd :
  public iso14649CppBase
{
public:
  fileEnd();
  ~fileEnd();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* fileName

This is a class for the single definition of fileName.
It represents the following items:

FILENAME '(' CHARSTRING ',' CHARSTRING ',' parenStringListFull ',' parenStringListFull ',' CHARSTRING ',' CHARSTRING ',' CHARSTRING ')' ';'

*/

class fileName :
  public iso14649CppBase
{
public:
  fileName();
  fileName(
    char * nameIn,
    char * timeStampIn,
    parenStringListFull * authorIn,
    parenStringListFull * organizationIn,
    char * preprocessorVersionIn,
    char * originatingSystemIn,
    char * authorizationIn);
  ~fileName();
  int isA(int aType);
  void printSelf();
  char * name;
  char * timeStamp;
  parenStringListFull * author;
  parenStringListFull * organization;
  char * preprocessorVersion;
  char * originatingSystem;
  char * authorization;
};

/********************************************************************/

/* fileSchema

This is a class for the single definition of fileSchema.
It represents the following items:

FILESCHEMA '(' parenStringList ')' ';'

*/

class fileSchema :
  public iso14649CppBase
{
public:
  fileSchema();
  fileSchema(
    parenStringList * schemaIdentifiersIn);
  ~fileSchema();
  int isA(int aType);
  void printSelf();
  parenStringList * schemaIdentifiers;
};

/********************************************************************/

/* fileStart

This is a class for the single definition of fileStart.
It represents the following items:

FILESTART ';'

*/

class fileStart :
  public iso14649CppBase
{
public:
  fileStart();
  ~fileStart();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* fittingType

This is a parent class.

*/

class fittingType :
  public iso14649CppBase
{
public:
  fittingType();
  ~fittingType();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* fittingTypeHole

This is a class for the single definition of fittingTypeHole.
It represents the following items:

FITTINGTYPEHOLE

*/

class fittingTypeHole :
  public fittingType
{
public:
  fittingTypeHole();
  ~fittingTypeHole();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* fittingTypeShaft

This is a class for the single definition of fittingTypeShaft.
It represents the following items:

FITTINGTYPESHAFT

*/

class fittingTypeShaft :
  public fittingType
{
public:
  fittingTypeShaft();
  ~fittingTypeShaft();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* freeformStrategy

This is a parent class.

*/

class freeformStrategy :
  public iso14649CppBase
{
public:
  freeformStrategy();
  freeformStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn);
  ~freeformStrategy();
  int isA(int aType);
  void printSelf() = 0;
  pathmodeType * pathmode;
  cutmodeType * cutmode;
  tolerances * itsMillingTolerances;
  real * stepover;
};

/********************************************************************/

/* hand

This is a parent class.

*/

class hand :
  public iso14649CppBase
{
public:
  hand();
  ~hand();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* handLeft

This is a class for the single definition of handLeft.
It represents the following items:

LEFT

*/

class handLeft :
  public hand
{
public:
  handLeft();
  ~handLeft();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* handNeutral

This is a class for the single definition of handNeutral.
It represents the following items:

NEUTRAL

*/

class handNeutral :
  public hand
{
public:
  handNeutral();
  ~handNeutral();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* handRight

This is a class for the single definition of handRight.
It represents the following items:

RIGHT

*/

class handRight :
  public hand
{
public:
  handRight();
  ~handRight();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* headerSection

This is a class for the single definition of headerSection.
It represents the following items:

headerStarter fileDescription fileName fileSchema endSection

*/

class headerSection :
  public iso14649CppBase
{
public:
  headerSection();
  headerSection(
    headerStarter * headerStartIn,
    fileDescription * headerDescriptionIn,
    fileName * headerNameIn,
    fileSchema * headerSchemaIn,
    endSection * sectionEndIn);
  ~headerSection();
  int isA(int aType);
  void printSelf();
  headerStarter * headerStart;
  fileDescription * headerDescription;
  fileName * headerName;
  fileSchema * headerSchema;
  endSection * sectionEnd;
};

/********************************************************************/

/* headerStarter

This is a class for the single definition of headerStarter.
It represents the following items:

HEADER ';'

*/

class headerStarter :
  public iso14649CppBase
{
public:
  headerStarter();
  ~headerStarter();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* holeBottomCondition

This is a parent class.

*/

class holeBottomCondition :
  public iso14649CppBase
{
public:
  holeBottomCondition();
  ~holeBottomCondition();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* inProcessGeometry

This is a class for the single definition of inProcessGeometry.
It represents the following items:

INPROCESSGEOMETRY '(' optAdvancedBrepShapeRepresentation ',' optAdvancedBrepShapeRepresentation ',' optAdvancedBrepShapeRepresentation ')'

*/

class inProcessGeometry :
  public instance
{
public:
  inProcessGeometry();
  inProcessGeometry(
    advancedBrepShapeRepresentation * asIsIn,
    advancedBrepShapeRepresentation * toBeIn,
    advancedBrepShapeRepresentation * removalIn);
  ~inProcessGeometry();
  int isA(int aType);
  void printSelf();
  advancedBrepShapeRepresentation * asIs;
  advancedBrepShapeRepresentation * toBe;
  advancedBrepShapeRepresentation * removal;
};

/********************************************************************/

/* instanceId

This is a class for the single definition of instanceId.
It represents the following items:

'#' INTSTRING

*/

class instanceId :
  public iso14649CppBase
{
public:
  instanceId();
  instanceId(
    int valIn);
  ~instanceId();
  int isA(int aType);
  void printSelf();
  int val;
};

/********************************************************************/

/* integer

This is a class for the single definition of integer.
It represents the following items:

INTSTRING

*/

class integer :
  public iso14649CppBase
{
public:
  integer();
  integer(
    int valIn);
  ~integer();
  int isA(int aType);
  void printSelf();
  int val;
};

/********************************************************************/

/* knotType

This is a parent class.

*/

class knotType :
  public iso14649CppBase
{
public:
  knotType();
  ~knotType();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* knotTypePiecewiseBezierKnots

This is a class for the single definition of knotTypePiecewiseBezierKnots.
It represents the following items:

KNOTTYPEPIECEWISEBEZIERKNOTS

*/

class knotTypePiecewiseBezierKnots :
  public knotType
{
public:
  knotTypePiecewiseBezierKnots();
  ~knotTypePiecewiseBezierKnots();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* knotTypeQuasiUniformKnots

This is a class for the single definition of knotTypeQuasiUniformKnots.
It represents the following items:

KNOTTYPEQUASIUNIFORMKNOTS

*/

class knotTypeQuasiUniformKnots :
  public knotType
{
public:
  knotTypeQuasiUniformKnots();
  ~knotTypeQuasiUniformKnots();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* knotTypeUniformKnots

This is a class for the single definition of knotTypeUniformKnots.
It represents the following items:

KNOTTYPEUNIFORMKNOTS

*/

class knotTypeUniformKnots :
  public knotType
{
public:
  knotTypeUniformKnots();
  ~knotTypeUniformKnots();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* knotTypeUnspecified

This is a class for the single definition of knotTypeUnspecified.
It represents the following items:

KNOTTYPEUNSPECIFIED

*/

class knotTypeUnspecified :
  public knotType
{
public:
  knotTypeUnspecified();
  ~knotTypeUnspecified();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* leadingLineStrategy

This is a class for the single definition of leadingLineStrategy.
It represents the following items:

LEADINGLINESTRATEGY '(' pathmodeType ',' cutmodeType ',' tolerances ',' optReal ',' boundedCurve ')'

*/

class leadingLineStrategy :
  public instance,
  public freeformStrategy
{
public:
  leadingLineStrategy();
  leadingLineStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn,
    boundedCurve * itsLineIn);
  ~leadingLineStrategy();
  int isA(int aType);
  void printSelf();
  boundedCurve * itsLine;
};

/********************************************************************/

/* leftOrRight

This is a parent class.

*/

class leftOrRight :
  public iso14649CppBase
{
public:
  leftOrRight();
  ~leftOrRight();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* leftOrRightLeft

This is a class for the single definition of leftOrRightLeft.
It represents the following items:

LEFT

*/

class leftOrRightLeft :
  public leftOrRight
{
public:
  leftOrRightLeft();
  ~leftOrRightLeft();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* leftOrRightRight

This is a class for the single definition of leftOrRightRight.
It represents the following items:

RIGHT

*/

class leftOrRightRight :
  public leftOrRight
{
public:
  leftOrRightRight();
  ~leftOrRightRight();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* localTime

This is a class for the single definition of localTime.
It represents the following items:

LOCALTIME '(' INTSTRING optInteger optReal coordinatedUniversalTimeOffset ')'

*/

class localTime :
  public instance
{
public:
  localTime();
  localTime(
    int hourComponentIn,
    integer * minuteComponentIn,
    real * secondComponentIn,
    coordinatedUniversalTimeOffset * zoneIn);
  ~localTime();
  int isA(int aType);
  void printSelf();
  int hourComponent;
  integer * minuteComponent;
  real * secondComponent;
  coordinatedUniversalTimeOffset * zone;
};

/********************************************************************/

/* logical

This is a parent class.

*/

class logical :
  public iso14649CppBase
{
public:
  logical();
  ~logical();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* logicalFalse

This is a class for the single definition of logicalFalse.
It represents the following items:

FALSE

*/

class logicalFalse :
  public logical
{
public:
  logicalFalse();
  ~logicalFalse();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* logicalTrue

This is a class for the single definition of logicalTrue.
It represents the following items:

TRUE

*/

class logicalTrue :
  public logical
{
public:
  logicalTrue();
  ~logicalTrue();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* logicalUnknown

This is a class for the single definition of logicalUnknown.
It represents the following items:

UNKNOWN

*/

class logicalUnknown :
  public logical
{
public:
  logicalUnknown();
  ~logicalUnknown();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* machinedSurface

This is a class for the single definition of machinedSurface.
It represents the following items:

MACHINEDSURFACE '(' machiningFeature ',' bottomOrSide ')'

*/

class machinedSurface :
  public instance
{
public:
  machinedSurface();
  machinedSurface(
    machiningFeature * itsMachiningFeatureIn,
    bottomOrSide * surfaceElementIn);
  ~machinedSurface();
  int isA(int aType);
  void printSelf();
  machiningFeature * itsMachiningFeature;
  bottomOrSide * surfaceElement;
};

/********************************************************************/

/* machineFunctions

This is a parent class.

*/

class machineFunctions :
  public iso14649CppBase
{
public:
  machineFunctions();
  ~machineFunctions();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* machiningTool

This is a parent class.

*/

class machiningTool :
  public iso14649CppBase
{
public:
  machiningTool();
  machiningTool(
    char * itsIdIn);
  ~machiningTool();
  int isA(int aType);
  void printSelf() = 0;
  char * itsId;
};

/********************************************************************/

/* manufacturingFeature

This is a parent class.

*/

class manufacturingFeature :
  public iso14649CppBase
{
public:
  manufacturingFeature();
  manufacturingFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn);
  ~manufacturingFeature();
  int isA(int aType);
  void printSelf() = 0;
  char * itsId;
  workpiece * itsWorkpiece;
  parenMachiningOperationList * itsOperations;
};

/********************************************************************/

/* material

This is a class for the single definition of material.
It represents the following items:

MATERIAL '(' CHARSTRING ',' CHARSTRING ',' parenPropertyParameterList ')'

*/

class material :
  public instance
{
public:
  material();
  material(
    char * standardIdentifierIn,
    char * materialIdentifierIn,
    parenPropertyParameterList * materialPropertyIn);
  ~material();
  int isA(int aType);
  void printSelf();
  char * standardIdentifier;
  char * materialIdentifier;
  parenPropertyParameterList * materialProperty;
};

/********************************************************************/

/* millingMachineFunctions

This is a class for the single definition of millingMachineFunctions.
It represents the following items:

MILLINGMACHINEFUNCTIONS '(' boolean ',' optReal ',' optBoolean ',' boolean ',' optReal ',' parenStringList ',' boolean ',' optDirection ',' optProcessModelList ',' parenPropertyParameterList ')'

*/

class millingMachineFunctions :
  public instance,
  public machineFunctions
{
public:
  millingMachineFunctions();
  millingMachineFunctions(
    boolean * coolantIn,
    real * coolantPressureIn,
    boolean * mistIn,
    boolean * throughSpindleCoolantIn,
    real * throughPressureIn,
    parenStringList * axisClampingIn,
    boolean * chipRemovalIn,
    direction * orientedSpindleStopIn,
    processModelList * itsProcessModelIn,
    parenPropertyParameterList * otherFunctionsIn);
  ~millingMachineFunctions();
  int isA(int aType);
  void printSelf();
  boolean * coolant;
  real * coolantPressure;
  boolean * mist;
  boolean * throughSpindleCoolant;
  real * throughPressure;
  parenStringList * axisClamping;
  boolean * chipRemoval;
  direction * orientedSpindleStop;
  processModelList * itsProcessModel;
  parenPropertyParameterList * otherFunctions;
};

/********************************************************************/

/* millingToolDimension

This is a class for the single definition of millingToolDimension.
It represents the following items:

MILLINGTOOLDIMENSION '(' REALSTRING ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ')'

*/

class millingToolDimension :
  public instance
{
public:
  millingToolDimension();
  millingToolDimension(
    double diameterIn,
    real * toolTopAngleIn,
    real * toolCircumferenceAngleIn,
    real * cuttingEdgeLengthIn,
    real * edgeRadiusIn,
    real * edgeCenterVerticalIn,
    real * edgeCenterHorizontalIn);
  ~millingToolDimension();
  int isA(int aType);
  void printSelf();
  double diameter;
  real * toolTopAngle;
  real * toolCircumferenceAngle;
  real * cuttingEdgeLength;
  real * edgeRadius;
  real * edgeCenterVertical;
  real * edgeCenterHorizontal;
};

/********************************************************************/

/* multipleArityBooleanExpression

This is a parent class.

*/

class multipleArityBooleanExpression :
  public booleanExpression
{
public:
  multipleArityBooleanExpression();
  multipleArityBooleanExpression(
    parenBooleanExpressionListFull * operandsIn);
  ~multipleArityBooleanExpression();
  int isA(int aType);
  void printSelf() = 0;
  parenBooleanExpressionListFull * operands;
};

/********************************************************************/

/* ncFunction

This is a parent class.

*/

class ncFunction :
  public executable
{
public:
  ncFunction();
  ncFunction(
    char * itsIdIn);
  ~ncFunction();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* offsetVector

This is a class for the single definition of offsetVector.
It represents the following items:

OFFSETVECTOR '(' parenNcVariableListFull ',' optParenNcVariableListFull ')'

*/

class offsetVector :
  public iso14649CppBase
{
public:
  offsetVector();
  offsetVector(
    parenNcVariableListFull * translateIn,
    parenNcVariableListFull * rotateIn);
  ~offsetVector();
  int isA(int aType);
  void printSelf();
  parenNcVariableListFull * translate;
  parenNcVariableListFull * rotate;
};

/********************************************************************/

/* operation

This is a parent class.

*/

class operation :
  public iso14649CppBase
{
public:
  operation();
  operation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn);
  ~operation();
  int isA(int aType);
  void printSelf() = 0;
  toolpathList * itsToolpath;
  toolDirection * itsToolDirection;
};

/********************************************************************/

/* optionalStop

This is a class for the single definition of optionalStop.
It represents the following items:

OPTIONALSTOP '(' CHARSTRING ')'

*/

class optionalStop :
  public instance,
  public ncFunction
{
public:
  optionalStop();
  optionalStop(
    char * itsIdIn);
  ~optionalStop();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* orExpression

This is a class for the single definition of orExpression.
It represents the following items:

OREXPRESSION '(' parenBooleanExpressionListFull ')'

*/

class orExpression :
  public instance,
  public multipleArityBooleanExpression
{
public:
  orExpression();
  orExpression(
    parenBooleanExpressionListFull * operandsIn);
  ~orExpression();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* ordinalDate

This is a class for the single definition of ordinalDate.
It represents the following items:

ORDINALDATE '(' INTSTRING ',' INTSTRING ')'

*/

class ordinalDate :
  public instance,
  public date
{
public:
  ordinalDate();
  ordinalDate(
    int yearComponentIn,
    int dayComponentIn);
  ~ordinalDate();
  int isA(int aType);
  void printSelf();
  int dayComponent;
};

/********************************************************************/

/* parenAxis2placement3dListFull

This is a class for the single definition of parenAxis2placement3dListFull.
It represents the following items:

'(' axis2placement3dList ')'

*/

class parenAxis2placement3dListFull :
  public iso14649CppBase
{
public:
  parenAxis2placement3dListFull();
  parenAxis2placement3dListFull(
    std::list<axis2placement3d *> * theListIn);
  ~parenAxis2placement3dListFull();
  int isA(int aType);
  void printSelf();
  std::list<axis2placement3d *> * theList;
};

/********************************************************************/

/* parenBooleanExpressionListFull

This is a class for the single definition of parenBooleanExpressionListFull.
It represents the following items:

'(' booleanExpressionList ')'

*/

class parenBooleanExpressionListFull :
  public iso14649CppBase
{
public:
  parenBooleanExpressionListFull();
  parenBooleanExpressionListFull(
    std::list<booleanExpression *> * theListIn);
  ~parenBooleanExpressionListFull();
  int isA(int aType);
  void printSelf();
  std::list<booleanExpression *> * theList;
};

/********************************************************************/

/* parenBossList

This is a class for the list parenBossList.
It represents the following items:

'(' bossList ')'
  or
'(' ')'

*/

class parenBossList :
  public iso14649CppBase
{
public:
  parenBossList();
  parenBossList(
    std::list<boss *> * theListIn);
  ~parenBossList();
  int isA(int aType);
  void printSelf();
  std::list<boss *> * theList;
};

/********************************************************************/

/* parenBoundedCurveListFull

This is a class for the single definition of parenBoundedCurveListFull.
It represents the following items:

'(' boundedCurveList ')'

*/

class parenBoundedCurveListFull :
  public iso14649CppBase
{
public:
  parenBoundedCurveListFull();
  parenBoundedCurveListFull(
    std::list<boundedCurve *> * theListIn);
  ~parenBoundedCurveListFull();
  int isA(int aType);
  void printSelf();
  std::list<boundedCurve *> * theList;
};

/********************************************************************/

/* parenBoundedSurfaceListFull

This is a class for the single definition of parenBoundedSurfaceListFull.
It represents the following items:

'(' boundedSurfaceList ')'

*/

class parenBoundedSurfaceListFull :
  public iso14649CppBase
{
public:
  parenBoundedSurfaceListFull();
  parenBoundedSurfaceListFull(
    std::list<boundedSurface *> * theListIn);
  ~parenBoundedSurfaceListFull();
  int isA(int aType);
  void printSelf();
  std::list<boundedSurface *> * theList;
};

/********************************************************************/

/* parenCartesianPointList

This is a class for the list parenCartesianPointList.
It represents the following items:

'(' cartesianPointList ')'
  or
'(' ')'

*/

class parenCartesianPointList :
  public iso14649CppBase
{
public:
  parenCartesianPointList();
  parenCartesianPointList(
    std::list<cartesianPoint *> * theListIn);
  ~parenCartesianPointList();
  int isA(int aType);
  void printSelf();
  std::list<cartesianPoint *> * theList;
};

/********************************************************************/

/* parenCartesianPointListFull

This is a class for the single definition of parenCartesianPointListFull.
It represents the following items:

'(' cartesianPointList ')'

*/

class parenCartesianPointListFull :
  public iso14649CppBase
{
public:
  parenCartesianPointListFull();
  parenCartesianPointListFull(
    std::list<cartesianPoint *> * theListIn);
  ~parenCartesianPointListFull();
  int isA(int aType);
  void printSelf();
  std::list<cartesianPoint *> * theList;
};

/********************************************************************/

/* parenCircularOffsetList

This is a class for the list parenCircularOffsetList.
It represents the following items:

'(' circularOffsetList ')'
  or
'(' ')'

*/

class parenCircularOffsetList :
  public iso14649CppBase
{
public:
  parenCircularOffsetList();
  parenCircularOffsetList(
    std::list<circularOffset *> * theListIn);
  ~parenCircularOffsetList();
  int isA(int aType);
  void printSelf();
  std::list<circularOffset *> * theList;
};

/********************************************************************/

/* parenCircularOmitList

This is a class for the list parenCircularOmitList.
It represents the following items:

'(' circularOmitList ')'
  or
'(' ')'

*/

class parenCircularOmitList :
  public iso14649CppBase
{
public:
  parenCircularOmitList();
  parenCircularOmitList(
    std::list<circularOmit *> * theListIn);
  ~parenCircularOmitList();
  int isA(int aType);
  void printSelf();
  std::list<circularOmit *> * theList;
};

/********************************************************************/

/* parenCompositeCurveSegmentListFull

This is a class for the single definition of parenCompositeCurveSegmentListFull.
It represents the following items:

'(' compositeCurveSegmentList ')'

*/

class parenCompositeCurveSegmentListFull :
  public iso14649CppBase
{
public:
  parenCompositeCurveSegmentListFull();
  parenCompositeCurveSegmentListFull(
    std::list<compositeCurveSegment *> * theListIn);
  ~parenCompositeCurveSegmentListFull();
  int isA(int aType);
  void printSelf();
  std::list<compositeCurveSegment *> * theList;
};

/********************************************************************/

/* parenCompoundFeatureSelectListFull

This is a class for the single definition of parenCompoundFeatureSelectListFull.
It represents the following items:

'(' compoundFeatureSelectList ')'

*/

class parenCompoundFeatureSelectListFull :
  public iso14649CppBase
{
public:
  parenCompoundFeatureSelectListFull();
  parenCompoundFeatureSelectListFull(
    std::list<compoundFeatureSelect *> * theListIn);
  ~parenCompoundFeatureSelectListFull();
  int isA(int aType);
  void printSelf();
  std::list<compoundFeatureSelect *> * theList;
};

/********************************************************************/

/* parenCuttingComponentListFull

This is a class for the single definition of parenCuttingComponentListFull.
It represents the following items:

'(' cuttingComponentList ')'

*/

class parenCuttingComponentListFull :
  public iso14649CppBase
{
public:
  parenCuttingComponentListFull();
  parenCuttingComponentListFull(
    std::list<cuttingComponent *> * theListIn);
  ~parenCuttingComponentListFull();
  int isA(int aType);
  void printSelf();
  std::list<cuttingComponent *> * theList;
};

/********************************************************************/

/* parenExecutableList

This is a class for the list parenExecutableList.
It represents the following items:

'(' executableList ')'
  or
'(' ')'

*/

class parenExecutableList :
  public iso14649CppBase
{
public:
  parenExecutableList();
  parenExecutableList(
    std::list<executable *> * theListIn);
  ~parenExecutableList();
  int isA(int aType);
  void printSelf();
  std::list<executable *> * theList;
};

/********************************************************************/

/* parenExecutableListFull

This is a class for the single definition of parenExecutableListFull.
It represents the following items:

'(' executableList ')'

*/

class parenExecutableListFull :
  public iso14649CppBase
{
public:
  parenExecutableListFull();
  parenExecutableListFull(
    std::list<executable *> * theListIn);
  ~parenExecutableListFull();
  int isA(int aType);
  void printSelf();
  std::list<executable *> * theList;
};

/********************************************************************/

/* parenFaceBoundListFull

This is a class for the single definition of parenFaceBoundListFull.
It represents the following items:

'(' faceBoundList ')'

*/

class parenFaceBoundListFull :
  public iso14649CppBase
{
public:
  parenFaceBoundListFull();
  parenFaceBoundListFull(
    std::list<faceBound *> * theListIn);
  ~parenFaceBoundListFull();
  int isA(int aType);
  void printSelf();
  std::list<faceBound *> * theList;
};

/********************************************************************/

/* parenFaceListFull

This is a class for the single definition of parenFaceListFull.
It represents the following items:

'(' faceList ')'

*/

class parenFaceListFull :
  public iso14649CppBase
{
public:
  parenFaceListFull();
  parenFaceListFull(
    std::list<face *> * theListIn);
  ~parenFaceListFull();
  int isA(int aType);
  void printSelf();
  std::list<face *> * theList;
};

/********************************************************************/

/* parenIntegerListFull

This is a class for the single definition of parenIntegerListFull.
It represents the following items:

'(' integerList ')'

*/

class parenIntegerListFull :
  public iso14649CppBase
{
public:
  parenIntegerListFull();
  parenIntegerListFull(
    std::list<integer *> * theListIn);
  ~parenIntegerListFull();
  int isA(int aType);
  void printSelf();
  std::list<integer *> * theList;
};

/********************************************************************/

/* parenMachinedSurfaceListFull

This is a class for the single definition of parenMachinedSurfaceListFull.
It represents the following items:

'(' machinedSurfaceList ')'

*/

class parenMachinedSurfaceListFull :
  public iso14649CppBase
{
public:
  parenMachinedSurfaceListFull();
  parenMachinedSurfaceListFull(
    std::list<machinedSurface *> * theListIn);
  ~parenMachinedSurfaceListFull();
  int isA(int aType);
  void printSelf();
  std::list<machinedSurface *> * theList;
};

/********************************************************************/

/* parenMachiningFeatureListFull

This is a class for the single definition of parenMachiningFeatureListFull.
It represents the following items:

'(' machiningFeatureList ')'

*/

class parenMachiningFeatureListFull :
  public iso14649CppBase
{
public:
  parenMachiningFeatureListFull();
  parenMachiningFeatureListFull(
    std::list<machiningFeature *> * theListIn);
  ~parenMachiningFeatureListFull();
  int isA(int aType);
  void printSelf();
  std::list<machiningFeature *> * theList;
};

/********************************************************************/

/* parenMachiningOperationList

This is a class for the list parenMachiningOperationList.
It represents the following items:

'(' machiningOperationList ')'
  or
'(' ')'

*/

class parenMachiningOperationList :
  public iso14649CppBase
{
public:
  parenMachiningOperationList();
  parenMachiningOperationList(
    std::list<machiningOperation *> * theListIn);
  ~parenMachiningOperationList();
  int isA(int aType);
  void printSelf();
  std::list<machiningOperation *> * theList;
};

/********************************************************************/

/* parenNcVariableListFull

This is a class for the single definition of parenNcVariableListFull.
It represents the following items:

'(' ncVariableList ')'

*/

class parenNcVariableListFull :
  public iso14649CppBase
{
public:
  parenNcVariableListFull();
  parenNcVariableListFull(
    std::list<ncVariable *> * theListIn);
  ~parenNcVariableListFull();
  int isA(int aType);
  void printSelf();
  std::list<ncVariable *> * theList;
};

/********************************************************************/

/* parenOrientedEdgeListFull

This is a class for the single definition of parenOrientedEdgeListFull.
It represents the following items:

'(' orientedEdgeList ')'

*/

class parenOrientedEdgeListFull :
  public iso14649CppBase
{
public:
  parenOrientedEdgeListFull();
  parenOrientedEdgeListFull(
    std::list<orientedEdge *> * theListIn);
  ~parenOrientedEdgeListFull();
  int isA(int aType);
  void printSelf();
  std::list<orientedEdge *> * theList;
};

/********************************************************************/

/* parenParenCartesianPointListFullListFull

This is a class for the single definition of parenParenCartesianPointListFullListFull.
It represents the following items:

'(' parenCartesianPointListFullList ')'

*/

class parenParenCartesianPointListFullListFull :
  public iso14649CppBase
{
public:
  parenParenCartesianPointListFullListFull();
  parenParenCartesianPointListFullListFull(
    std::list<parenCartesianPointListFull *> * theListIn);
  ~parenParenCartesianPointListFullListFull();
  int isA(int aType);
  void printSelf();
  std::list<parenCartesianPointListFull *> * theList;
};

/********************************************************************/

/* parenParenRealListFullListFull

This is a class for the single definition of parenParenRealListFullListFull.
It represents the following items:

'(' parenRealListFullList ')'

*/

class parenParenRealListFullListFull :
  public iso14649CppBase
{
public:
  parenParenRealListFullListFull();
  parenParenRealListFullListFull(
    std::list<parenRealListFull *> * theListIn);
  ~parenParenRealListFullListFull();
  int isA(int aType);
  void printSelf();
  std::list<parenRealListFull *> * theList;
};

/********************************************************************/

/* parenProcessModelLiszt

This is a class for the single definition of parenProcessModelLiszt.
It represents the following items:

'(' processModelLiszt ')'

*/

class parenProcessModelLiszt :
  public iso14649CppBase
{
public:
  parenProcessModelLiszt();
  parenProcessModelLiszt(
    std::list<processModel *> * theListIn);
  ~parenProcessModelLiszt();
  int isA(int aType);
  void printSelf();
  std::list<processModel *> * theList;
};

/********************************************************************/

/* parenPropertyParameterList

This is a class for the list parenPropertyParameterList.
It represents the following items:

'(' propertyParameterList ')'
  or
'(' ')'

*/

class parenPropertyParameterList :
  public iso14649CppBase
{
public:
  parenPropertyParameterList();
  parenPropertyParameterList(
    std::list<propertyParameter *> * theListIn);
  ~parenPropertyParameterList();
  int isA(int aType);
  void printSelf();
  std::list<propertyParameter *> * theList;
};

/********************************************************************/

/* parenRealListFull

This is a class for the single definition of parenRealListFull.
It represents the following items:

'(' realList ')'

*/

class parenRealListFull :
  public iso14649CppBase
{
public:
  parenRealListFull();
  parenRealListFull(
    std::list<real *> * theListIn);
  ~parenRealListFull();
  int isA(int aType);
  void printSelf();
  std::list<real *> * theList;
};

/********************************************************************/

/* parenRectangularOffsetList

This is a class for the list parenRectangularOffsetList.
It represents the following items:

'(' rectangularOffsetList ')'
  or
'(' ')'

*/

class parenRectangularOffsetList :
  public iso14649CppBase
{
public:
  parenRectangularOffsetList();
  parenRectangularOffsetList(
    std::list<rectangularOffset *> * theListIn);
  ~parenRectangularOffsetList();
  int isA(int aType);
  void printSelf();
  std::list<rectangularOffset *> * theList;
};

/********************************************************************/

/* parenRectangularOmitList

This is a class for the list parenRectangularOmitList.
It represents the following items:

'(' rectangularOmitList ')'
  or
'(' ')'

*/

class parenRectangularOmitList :
  public iso14649CppBase
{
public:
  parenRectangularOmitList();
  parenRectangularOmitList(
    std::list<rectangularOmit *> * theListIn);
  ~parenRectangularOmitList();
  int isA(int aType);
  void printSelf();
  std::list<rectangularOmit *> * theList;
};

/********************************************************************/

/* parenRepresentationItemListFull

This is a class for the single definition of parenRepresentationItemListFull.
It represents the following items:

'(' representationItemList ')'

*/

class parenRepresentationItemListFull :
  public iso14649CppBase
{
public:
  parenRepresentationItemListFull();
  parenRepresentationItemListFull(
    std::list<representationItem *> * theListIn);
  ~parenRepresentationItemListFull();
  int isA(int aType);
  void printSelf();
  std::list<representationItem *> * theList;
};

/********************************************************************/

/* parenSetupInstructionList

This is a class for the list parenSetupInstructionList.
It represents the following items:

'(' setupInstructionList ')'
  or
'(' ')'

*/

class parenSetupInstructionList :
  public iso14649CppBase
{
public:
  parenSetupInstructionList();
  parenSetupInstructionList(
    std::list<setupInstruction *> * theListIn);
  ~parenSetupInstructionList();
  int isA(int aType);
  void printSelf();
  std::list<setupInstruction *> * theList;
};

/********************************************************************/

/* parenSlotEndTypeList

This is a class for the list parenSlotEndTypeList.
It represents the following items:

'(' slotEndTypeList ')'
  or
'(' ')'

*/

class parenSlotEndTypeList :
  public iso14649CppBase
{
public:
  parenSlotEndTypeList();
  parenSlotEndTypeList(
    std::list<slotEndType *> * theListIn);
  ~parenSlotEndTypeList();
  int isA(int aType);
  void printSelf();
  std::list<slotEndType *> * theList;
};

/********************************************************************/

/* parenSpecificationUsageConstraintList

This is a class for the list parenSpecificationUsageConstraintList.
It represents the following items:

'(' specificationUsageConstraintList ')'
  or
'(' ')'

*/

class parenSpecificationUsageConstraintList :
  public iso14649CppBase
{
public:
  parenSpecificationUsageConstraintList();
  parenSpecificationUsageConstraintList(
    std::list<specificationUsageConstraint *> * theListIn);
  ~parenSpecificationUsageConstraintList();
  int isA(int aType);
  void printSelf();
  std::list<specificationUsageConstraint *> * theList;
};

/********************************************************************/

/* parenStringList

This is a class for the list parenStringList.
It represents the following items:

'(' stringList ')'
  or
'(' ')'

*/

class parenStringList :
  public iso14649CppBase
{
public:
  parenStringList();
  parenStringList(
    std::list<char *> * theListIn);
  ~parenStringList();
  int isA(int aType);
  void printSelf();
  std::list<char *> * theList;
};

/********************************************************************/

/* parenStringListFull

This is a class for the single definition of parenStringListFull.
It represents the following items:

'(' stringList ')'

*/

class parenStringListFull :
  public iso14649CppBase
{
public:
  parenStringListFull();
  parenStringListFull(
    std::list<char *> * theListIn);
  ~parenStringListFull();
  int isA(int aType);
  void printSelf();
  std::list<char *> * theList;
};

/********************************************************************/

/* parenToolpathLisztFull

This is a class for the single definition of parenToolpathLisztFull.
It represents the following items:

'(' toolpathLiszt ')'

*/

class parenToolpathLisztFull :
  public iso14649CppBase
{
public:
  parenToolpathLisztFull();
  parenToolpathLisztFull(
    std::list<toolpath *> * theListIn);
  ~parenToolpathLisztFull();
  int isA(int aType);
  void printSelf();
  std::list<toolpath *> * theList;
};

/********************************************************************/

/* parenTrimmingSelectListFull

This is a class for the single definition of parenTrimmingSelectListFull.
It represents the following items:

'(' trimmingSelectList ')'

*/

class parenTrimmingSelectListFull :
  public iso14649CppBase
{
public:
  parenTrimmingSelectListFull();
  parenTrimmingSelectListFull(
    std::list<trimmingSelect *> * theListIn);
  ~parenTrimmingSelectListFull();
  int isA(int aType);
  void printSelf();
  std::list<trimmingSelect *> * theList;
};

/********************************************************************/

/* parenWorkpieceList

This is a class for the list parenWorkpieceList.
It represents the following items:

'(' workpieceList ')'
  or
'(' ')'

*/

class parenWorkpieceList :
  public iso14649CppBase
{
public:
  parenWorkpieceList();
  parenWorkpieceList(
    std::list<workpiece *> * theListIn);
  ~parenWorkpieceList();
  int isA(int aType);
  void printSelf();
  std::list<workpiece *> * theList;
};

/********************************************************************/

/* parenWorkpieceSetupList

This is a class for the list parenWorkpieceSetupList.
It represents the following items:

'(' workpieceSetupList ')'
  or
'(' ')'

*/

class parenWorkpieceSetupList :
  public iso14649CppBase
{
public:
  parenWorkpieceSetupList();
  parenWorkpieceSetupList(
    std::list<workpieceSetup *> * theListIn);
  ~parenWorkpieceSetupList();
  int isA(int aType);
  void printSelf();
  std::list<workpieceSetup *> * theList;
};

/********************************************************************/

/* partialAreaDefinition

This is a class for the single definition of partialAreaDefinition.
It represents the following items:

PARTIALAREADEFINITION '(' REALSTRING ',' axis2placement3d ',' optReal ')'

*/

class partialAreaDefinition :
  public instance
{
public:
  partialAreaDefinition();
  partialAreaDefinition(
    double effectiveLengthIn,
    axis2placement3d * placementIn,
    real * maximumLengthIn);
  ~partialAreaDefinition();
  int isA(int aType);
  void printSelf();
  double effectiveLength;
  axis2placement3d * placement;
  real * maximumLength;
};

/********************************************************************/

/* pathmodeType

This is a parent class.

*/

class pathmodeType :
  public iso14649CppBase
{
public:
  pathmodeType();
  ~pathmodeType();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* pathmodeTypeForward

This is a class for the single definition of pathmodeTypeForward.
It represents the following items:

PATHMODETYPEFORWARD

*/

class pathmodeTypeForward :
  public pathmodeType
{
public:
  pathmodeTypeForward();
  ~pathmodeTypeForward();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* pathmodeTypeZigzag

This is a class for the single definition of pathmodeTypeZigzag.
It represents the following items:

PATHMODETYPEZIGZAG

*/

class pathmodeTypeZigzag :
  public pathmodeType
{
public:
  pathmodeTypeZigzag();
  ~pathmodeTypeZigzag();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* person

This is a class for the single definition of person.
It represents the following items:

PERSON '(' CHARSTRING ',' optString ',' optString ',' optParenStringListFull ',' optParenStringListFull ',' optParenStringListFull ',' ')'

*/

class person :
  public instance
{
public:
  person();
  person(
    char * idIn,
    aString * lastNameIn,
    aString * firstNameIn,
    parenStringListFull * middleNamesIn,
    parenStringListFull * prefixTitlesIn,
    parenStringListFull * suffixTitlesIn);
  ~person();
  int isA(int aType);
  void printSelf();
  char * id;
  aString * lastName;
  aString * firstName;
  parenStringListFull * middleNames;
  parenStringListFull * prefixTitles;
  parenStringListFull * suffixTitles;
};

/********************************************************************/

/* personAndAddress

This is a class for the single definition of personAndAddress.
It represents the following items:

PERSONANDADDRESS '(' person ',' optAddress ')'

*/

class personAndAddress :
  public instance
{
public:
  personAndAddress();
  personAndAddress(
    person * itsPersonIn,
    address * itsAddressIn);
  ~personAndAddress();
  int isA(int aType);
  void printSelf();
  person * itsPerson;
  address * itsAddress;
};

/********************************************************************/

/* planeCcStrategy

This is a class for the single definition of planeCcStrategy.
It represents the following items:

PLANECCSTRATEGY '(' pathmodeType ',' cutmodeType ',' tolerances ',' optReal ',' direction ')'

*/

class planeCcStrategy :
  public instance,
  public freeformStrategy
{
public:
  planeCcStrategy();
  planeCcStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn,
    direction * itsPlaneNormalIn);
  ~planeCcStrategy();
  int isA(int aType);
  void printSelf();
  direction * itsPlaneNormal;
};

/********************************************************************/

/* planeClStrategy

This is a class for the single definition of planeClStrategy.
It represents the following items:

PLANECLSTRATEGY '(' pathmodeType ',' cutmodeType ',' tolerances ',' optReal ',' direction ')'

*/

class planeClStrategy :
  public instance,
  public freeformStrategy
{
public:
  planeClStrategy();
  planeClStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn,
    direction * itsPlaneNormalIn);
  ~planeClStrategy();
  int isA(int aType);
  void printSelf();
  direction * itsPlaneNormal;
};

/********************************************************************/

/* plungeStrategy

This is a parent class.

*/

class plungeStrategy :
  public approachRetractStrategy
{
public:
  plungeStrategy();
  plungeStrategy(
    direction * toolOrientationIn);
  ~plungeStrategy();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* plungeHelix

This is a class for the single definition of plungeHelix.
It represents the following items:

PLUNGEHELIX '(' optDirection ',' REALSTRING ',' REALSTRING ')'

*/

class plungeHelix :
  public instance,
  public plungeStrategy
{
public:
  plungeHelix();
  plungeHelix(
    direction * toolOrientationIn,
    double radiusIn,
    double angleIn);
  ~plungeHelix();
  int isA(int aType);
  void printSelf();
  double radius;
  double angle;
};

/********************************************************************/

/* plungeRamp

This is a class for the single definition of plungeRamp.
It represents the following items:

PLUNGERAMP '(' optDirection ',' REALSTRING ')'

*/

class plungeRamp :
  public instance,
  public plungeStrategy
{
public:
  plungeRamp();
  plungeRamp(
    direction * toolOrientationIn,
    double angleIn);
  ~plungeRamp();
  int isA(int aType);
  void printSelf();
  double angle;
};

/********************************************************************/

/* plungeToolaxis

This is a class for the single definition of plungeToolaxis.
It represents the following items:

PLUNGETOOLAXIS '(' optDirection ')'

*/

class plungeToolaxis :
  public instance,
  public plungeStrategy
{
public:
  plungeToolaxis();
  plungeToolaxis(
    direction * toolOrientationIn);
  ~plungeToolaxis();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* plungeZigzag

This is a class for the single definition of plungeZigzag.
It represents the following items:

PLUNGEZIGZAG '(' optDirection ',' REALSTRING ',' REALSTRING ')'

*/

class plungeZigzag :
  public instance,
  public plungeStrategy
{
public:
  plungeZigzag();
  plungeZigzag(
    direction * toolOrientationIn,
    double angleIn,
    double widthIn);
  ~plungeZigzag();
  int isA(int aType);
  void printSelf();
  double angle;
  double width;
};

/********************************************************************/

/* pocketBottomCondition

This is a parent class.

*/

class pocketBottomCondition :
  public iso14649CppBase
{
public:
  pocketBottomCondition();
  ~pocketBottomCondition();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* processModel

This is a class for the single definition of processModel.
It represents the following items:

PROCESSMODEL '(' CHARSTRING ',' CHARSTRING ')'

*/

class processModel :
  public instance
{
public:
  processModel();
  processModel(
    char * iniDataFileIn,
    char * itsTypeIn);
  ~processModel();
  int isA(int aType);
  void printSelf();
  char * iniDataFile;
  char * itsType;
};

/********************************************************************/

/* processModelList

This is a class for the single definition of processModelList.
It represents the following items:

PROCESSMODELLIST '(' parenProcessModelLiszt ')'

*/

class processModelList :
  public instance
{
public:
  processModelList();
  processModelList(
    parenProcessModelLiszt * itsListIn);
  ~processModelList();
  int isA(int aType);
  void printSelf();
  parenProcessModelLiszt * itsList;
};

/********************************************************************/

/* profile

This is a parent class.

*/

class profile :
  public iso14649CppBase
{
public:
  profile();
  profile(
    axis2placement3d * placementIn);
  ~profile();
  int isA(int aType);
  void printSelf() = 0;
  axis2placement3d * placement;
};

/********************************************************************/

/* profileSelect

This is a parent class.

*/

class profileSelect :
  public iso14649CppBase
{
public:
  profileSelect();
  ~profileSelect();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* programStructure

This is a parent class.

*/

class programStructure :
  public executable
{
public:
  programStructure();
  programStructure(
    char * itsIdIn);
  ~programStructure();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* programStop

This is a class for the single definition of programStop.
It represents the following items:

PROGRAMSTOP '(' CHARSTRING ')'

*/

class programStop :
  public instance,
  public ncFunction
{
public:
  programStop();
  programStop(
    char * itsIdIn);
  ~programStop();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* project

This is a class for the single definition of project.
It represents the following items:

PROJECT '(' CHARSTRING ',' workplan ',' parenWorkpieceList ',' optPersonAndAddress ',' optDateAndTime ',' optApproval ')'

*/

class project :
  public instance
{
public:
  project();
  project(
    char * itsIdIn,
    workplan * mainWorkplanIn,
    parenWorkpieceList * itsWorkpiecesIn,
    personAndAddress * itsOwnerIn,
    dateAndTime * itsReleaseIn,
    approval * itsStatusIn);
  ~project();
  int isA(int aType);
  void printSelf();
  char * itsId;
  workplan * mainWorkplan;
  parenWorkpieceList * itsWorkpieces;
  personAndAddress * itsOwner;
  dateAndTime * itsRelease;
  approval * itsStatus;
};

/********************************************************************/

/* propertyParameter

This is a parent class.

*/

class propertyParameter :
  public iso14649CppBase
{
public:
  propertyParameter();
  propertyParameter(
    char * parameterNameIn);
  ~propertyParameter();
  int isA(int aType);
  void printSelf() = 0;
  char * parameterName;
};

/********************************************************************/

/* radiusedPocketBottomCondition

This is a class for the single definition of radiusedPocketBottomCondition.
It represents the following items:

RADIUSEDPOCKETBOTTOMCONDITION '(' cartesianPoint ',' tolerancedLengthMeasure ')'

*/

class radiusedPocketBottomCondition :
  public instance,
  public pocketBottomCondition
{
public:
  radiusedPocketBottomCondition();
  radiusedPocketBottomCondition(
    cartesianPoint * floorRadiusCenterIn,
    tolerancedLengthMeasure * floorRadiusIn);
  ~radiusedPocketBottomCondition();
  int isA(int aType);
  void printSelf();
  cartesianPoint * floorRadiusCenter;
  tolerancedLengthMeasure * floorRadius;
};

/********************************************************************/

/* rectangularOffset

This is a class for the single definition of rectangularOffset.
It represents the following items:

RECTANGULAROFFSET '(' direction ',' REALSTRING ',' INTSTRING ',' INTSTRING ')'

*/

class rectangularOffset :
  public instance
{
public:
  rectangularOffset();
  rectangularOffset(
    direction * offsetDirectionIn,
    double offsetDistanceIn,
    int rowIndexIn,
    int columnIndexIn);
  ~rectangularOffset();
  int isA(int aType);
  void printSelf();
  direction * offsetDirection;
  double offsetDistance;
  int rowIndex;
  int columnIndex;
};

/********************************************************************/

/* rectangularOmit

This is a class for the single definition of rectangularOmit.
It represents the following items:

RECTANGULAROMIT '(' INTSTRING ',' INTSTRING ')'

*/

class rectangularOmit :
  public instance
{
public:
  rectangularOmit();
  rectangularOmit(
    int rowIndexIn,
    int columnIndexIn);
  ~rectangularOmit();
  int isA(int aType);
  void printSelf();
  int rowIndex;
  int columnIndex;
};

/********************************************************************/

/* region

This is a parent class.

*/

class region :
  public manufacturingFeature
{
public:
  region();
  region(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn);
  ~region();
  int isA(int aType);
  void printSelf() = 0;
  axis2placement3d * featurePlacement;
};

/********************************************************************/

/* regionProjection

This is a class for the single definition of regionProjection.
It represents the following items:

REGIONPROJECTION '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' optAxis2placement3d ',' boundedCurve ',' direction ',' tolerancedLengthMeasure ')'

*/

class regionProjection :
  public instance,
  public region
{
public:
  regionProjection();
  regionProjection(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    boundedCurve * projCurveIn,
    direction * projDirIn,
    tolerancedLengthMeasure * depthIn);
  ~regionProjection();
  int isA(int aType);
  void printSelf();
  boundedCurve * projCurve;
  direction * projDir;
  tolerancedLengthMeasure * depth;
};

/********************************************************************/

/* regionSurfaceList

This is a class for the single definition of regionSurfaceList.
It represents the following items:

REGIONSURFACELIST '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' optAxis2placement3d ',' parenBoundedSurfaceListFull ')'

*/

class regionSurfaceList :
  public instance,
  public region
{
public:
  regionSurfaceList();
  regionSurfaceList(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    parenBoundedSurfaceListFull * surfaceListIn);
  ~regionSurfaceList();
  int isA(int aType);
  void printSelf();
  parenBoundedSurfaceListFull * surfaceList;
};

/********************************************************************/

/* representationParent

This is a parent class.

*/

class representationParent :
  public iso14649CppBase
{
public:
  representationParent();
  representationParent(
    char * nameIn,
    parenRepresentationItemListFull * itemsIn,
    representationContext * contextOfItemsIn);
  ~representationParent();
  int isA(int aType);
  void printSelf() = 0;
  char * name;
  parenRepresentationItemListFull * items;
  representationContext * contextOfItems;
};

/********************************************************************/

/* representation

This is a class for the single definition of representation.
It represents the following items:

REPRESENTATION '(' CHARSTRING ',' parenRepresentationItemListFull ',' representationContext ')'

*/

class representation :
  public instance,
  public representationParent
{
public:
  representation();
  representation(
    char * nameIn,
    parenRepresentationItemListFull * itemsIn,
    representationContext * contextOfItemsIn);
  ~representation();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* representationContext

This is a class for the single definition of representationContext.
It represents the following items:

REPRESENTATIONCONTEXT '(' CHARSTRING ',' CHARSTRING ')'

*/

class representationContext :
  public iso14649CppBase
{
public:
  representationContext();
  representationContext(
    char * contextIdentifierIn,
    char * contextTypeIn);
  ~representationContext();
  int isA(int aType);
  void printSelf();
  char * contextIdentifier;
  char * contextType;
};

/********************************************************************/

/* representationItem

This is a parent class.

*/

class representationItem :
  public iso14649CppBase
{
public:
  representationItem();
  representationItem(
    char * nameIn);
  ~representationItem();
  int isA(int aType);
  void printSelf() = 0;
  char * name;
};

/********************************************************************/

/* restrictedAreaSelect

This is a parent class.

*/

class restrictedAreaSelect :
  public iso14649CppBase
{
public:
  restrictedAreaSelect();
  ~restrictedAreaSelect();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* rotDirection

This is a parent class.

*/

class rotDirection :
  public iso14649CppBase
{
public:
  rotDirection();
  ~rotDirection();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* rotDirectionCw

This is a class for the single definition of rotDirectionCw.
It represents the following items:

ROTDIRECTIONCW

*/

class rotDirectionCw :
  public rotDirection
{
public:
  rotDirectionCw();
  ~rotDirectionCw();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* rotDirectionCcw

This is a class for the single definition of rotDirectionCcw.
It represents the following items:

ROTDIRECTIONCCW

*/

class rotDirectionCcw :
  public rotDirection
{
public:
  rotDirectionCcw();
  ~rotDirectionCcw();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* rvalue

This is a parent class.

*/

class rvalue :
  public iso14649CppBase
{
public:
  rvalue();
  ~rvalue();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* selective

This is a class for the single definition of selective.
It represents the following items:

SELECTIVE '(' CHARSTRING ',' parenExecutableListFull ')'

*/

class selective :
  public instance,
  public programStructure
{
public:
  selective();
  selective(
    char * itsIdIn,
    parenExecutableListFull * itsElementsIn);
  ~selective();
  int isA(int aType);
  void printSelf();
  parenExecutableListFull * itsElements;
};

/********************************************************************/

/* setMark

This is a class for the single definition of setMark.
It represents the following items:

SETMARK '(' CHARSTRING ')'

*/

class setMark :
  public instance,
  public ncFunction
{
public:
  setMark();
  setMark(
    char * itsIdIn);
  ~setMark();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* setup

This is a class for the single definition of setup.
It represents the following items:

SETUP '(' CHARSTRING ',' optAxis2placement3d ',' elementarySurface ',' parenWorkpieceSetupList ')'

*/

class setup :
  public instance
{
public:
  setup();
  setup(
    char * itsIdIn,
    axis2placement3d * itsOriginIn,
    elementarySurface * itsSecplaneIn,
    parenWorkpieceSetupList * itsWorkpieceSetupIn);
  ~setup();
  int isA(int aType);
  void printSelf();
  char * itsId;
  axis2placement3d * itsOrigin;
  elementarySurface * itsSecplane;
  parenWorkpieceSetupList * itsWorkpieceSetup;
};

/********************************************************************/

/* setupInstruction

This is a class for the single definition of setupInstruction.
It represents the following items:

SETUPINSTRUCTION '(' optString ',' optString ')'

*/

class setupInstruction :
  public instance
{
public:
  setupInstruction();
  setupInstruction(
    aString * descriptionIn,
    aString * externalDocumentIn);
  ~setupInstruction();
  int isA(int aType);
  void printSelf();
  aString * description;
  aString * externalDocument;
};

/********************************************************************/

/* shapeRepresentationParent

This is a parent class.

*/

class shapeRepresentationParent :
  public representationParent
{
public:
  shapeRepresentationParent();
  shapeRepresentationParent(
    char * nameIn,
    parenRepresentationItemListFull * itemsIn,
    representationContext * contextOfItemsIn);
  ~shapeRepresentationParent();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* shapeRepresentation

This is a class for the single definition of shapeRepresentation.
It represents the following items:

SHAPEREPRESENTATION '(' CHARSTRING ',' parenRepresentationItemListFull ',' representationContext ')'

*/

class shapeRepresentation :
  public instance,
  public shapeRepresentationParent
{
public:
  shapeRepresentation();
  shapeRepresentation(
    char * nameIn,
    parenRepresentationItemListFull * itemsIn,
    representationContext * contextOfItemsIn);
  ~shapeRepresentation();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* slotEndType

This is a parent class.

*/

class slotEndType :
  public iso14649CppBase
{
public:
  slotEndType();
  ~slotEndType();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* specification

This is a class for the single definition of specification.
It represents the following items:

SPECIFICATION '(' parenSpecificationUsageConstraintList ',' CHARSTRING ',' optString ',' optString ')'

*/

class specification :
  public instance
{
public:
  specification();
  specification(
    parenSpecificationUsageConstraintList * constraintIn,
    char * specificationIdIn,
    aString * specificationDescriptionIn,
    aString * specificationClassIn);
  ~specification();
  int isA(int aType);
  void printSelf();
  parenSpecificationUsageConstraintList * constraint;
  char * specificationId;
  aString * specificationDescription;
  aString * specificationClass;
};

/********************************************************************/

/* specificationUsageConstraint

This is a class for the single definition of specificationUsageConstraint.
It represents the following items:

SPECIFICATIONUSAGECONSTRAINT '(' ',' CHARSTRING ',' CHARSTRING ')'

*/

class specificationUsageConstraint :
  public instance
{
public:
  specificationUsageConstraint();
  specificationUsageConstraint(
    char * elementIn,
    char * classIdIn);
  ~specificationUsageConstraint();
  int isA(int aType);
  void printSelf();
  char * element;
  char * classId;
};

/********************************************************************/

/* strokeConnectionStrategy

This is a parent class.

*/

class strokeConnectionStrategy :
  public iso14649CppBase
{
public:
  strokeConnectionStrategy();
  ~strokeConnectionStrategy();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* strokeConnectionStrategyDegouge

This is a class for the single definition of strokeConnectionStrategyDegouge.
It represents the following items:

STROKECONNECTIONSTRATEGYDEGOUGE

*/

class strokeConnectionStrategyDegouge :
  public strokeConnectionStrategy
{
public:
  strokeConnectionStrategyDegouge();
  ~strokeConnectionStrategyDegouge();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* strokeConnectionStrategyLiftShiftPlunge

This is a class for the single definition of strokeConnectionStrategyLiftShiftPlunge.
It represents the following items:

STROKECONNECTIONSTRATEGYLIFTSHIFTPLUNGE

*/

class strokeConnectionStrategyLiftShiftPlunge :
  public strokeConnectionStrategy
{
public:
  strokeConnectionStrategyLiftShiftPlunge();
  ~strokeConnectionStrategyLiftShiftPlunge();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* strokeConnectionStrategyLoopBack

This is a class for the single definition of strokeConnectionStrategyLoopBack.
It represents the following items:

STROKECONNECTIONSTRATEGYLOOPBACK

*/

class strokeConnectionStrategyLoopBack :
  public strokeConnectionStrategy
{
public:
  strokeConnectionStrategyLoopBack();
  ~strokeConnectionStrategyLoopBack();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* strokeConnectionStrategyStraightline

This is a class for the single definition of strokeConnectionStrategyStraightline.
It represents the following items:

STROKECONNECTIONSTRATEGYSTRAIGHTLINE

*/

class strokeConnectionStrategyStraightline :
  public strokeConnectionStrategy
{
public:
  strokeConnectionStrategyStraightline();
  ~strokeConnectionStrategyStraightline();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* surfaceTextureParameter

This is a class for the single definition of surfaceTextureParameter.
It represents the following items:

SURFACETEXTUREPARAMETER '(' REALSTRING ',' CHARSTRING ',' CHARSTRING ',' optString ',' parenMachinedSurfaceListFull ')'

*/

class surfaceTextureParameter :
  public instance
{
public:
  surfaceTextureParameter();
  surfaceTextureParameter(
    double itsValueIn,
    char * parameterNameIn,
    char * measuringMethodIn,
    aString * parameterIndexIn,
    parenMachinedSurfaceListFull * appliedSurfacesIn);
  ~surfaceTextureParameter();
  int isA(int aType);
  void printSelf();
  double itsValue;
  char * parameterName;
  char * measuringMethod;
  aString * parameterIndex;
  parenMachinedSurfaceListFull * appliedSurfaces;
};

/********************************************************************/

/* taperSelect

This is a parent class.

*/

class taperSelect :
  public iso14649CppBase
{
public:
  taperSelect();
  ~taperSelect();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* technology

This is a parent class.

*/

class technology :
  public iso14649CppBase
{
public:
  technology();
  technology(
    real * feedrateIn,
    toolReferencePoint * feedrateReferenceIn);
  ~technology();
  int isA(int aType);
  void printSelf() = 0;
  real * feedrate;
  toolReferencePoint * feedrateReference;
};

/********************************************************************/

/* throughBottomCondition

This is a class for the single definition of throughBottomCondition.
It represents the following items:

THROUGHBOTTOMCONDITION '(' ')'

*/

class throughBottomCondition :
  public instance,
  public holeBottomCondition
{
public:
  throughBottomCondition();
  ~throughBottomCondition();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* throughPocketBottomCondition

This is a class for the single definition of throughPocketBottomCondition.
It represents the following items:

THROUGHPOCKETBOTTOMCONDITION '(' ')'

*/

class throughPocketBottomCondition :
  public instance,
  public pocketBottomCondition
{
public:
  throughPocketBottomCondition();
  ~throughPocketBottomCondition();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* throughProfileFloor

This is a class for the single definition of throughProfileFloor.
It represents the following items:

THROUGHPROFILEFLOOR '(' ')'

*/

class throughProfileFloor :
  public instance,
  public profileSelect
{
public:
  throughProfileFloor();
  ~throughProfileFloor();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* tolerancedLengthMeasure

This is a class for the single definition of tolerancedLengthMeasure.
It represents the following items:

TOLERANCEDLENGTHMEASURE '(' REALSTRING ',' plusMinusValue ')'

*/

class tolerancedLengthMeasure :
  public instance
{
public:
  tolerancedLengthMeasure();
  tolerancedLengthMeasure(
    double theoreticalSizeIn,
    plusMinusValue * implicitToleranceIn);
  ~tolerancedLengthMeasure();
  int isA(int aType);
  void printSelf();
  double theoreticalSize;
  plusMinusValue * implicitTolerance;
};

/********************************************************************/

/* tolerances

This is a class for the single definition of tolerances.
It represents the following items:

TOLERANCES '(' REALSTRING ',' REALSTRING ')'

*/

class tolerances :
  public instance
{
public:
  tolerances();
  tolerances(
    double chordalToleranceIn,
    double scallopHeightIn);
  ~tolerances();
  int isA(int aType);
  void printSelf();
  double chordalTolerance;
  double scallopHeight;
};

/********************************************************************/

/* toleranceSelect

This is a parent class.

*/

class toleranceSelect :
  public iso14649CppBase
{
public:
  toleranceSelect();
  ~toleranceSelect();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* toolBody

This is a parent class.

*/

class toolBody :
  public iso14649CppBase
{
public:
  toolBody();
  ~toolBody();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* toolDirection

This is a parent class.

*/

class toolDirection :
  public iso14649CppBase
{
public:
  toolDirection();
  ~toolDirection();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* toolDirectionForMilling

This is a parent class.

*/

class toolDirectionForMilling :
  public iso14649CppBase
{
public:
  toolDirectionForMilling();
  ~toolDirectionForMilling();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* toolpath

This is a parent class.

*/

class toolpath :
  public iso14649CppBase
{
public:
  toolpath();
  toolpath(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn);
  ~toolpath();
  int isA(int aType);
  void printSelf() = 0;
  boolean * itsPriority;
  toolpathType * itsType;
  toolpathSpeedprofile * itsSpeed;
  technology * itsTechnology;
  machineFunctions * itsMachineFunctions;
};

/********************************************************************/

/* toolpathList

This is a class for the single definition of toolpathList.
It represents the following items:

TOOLPATHLIST '(' parenToolpathLisztFull ')'

*/

class toolpathList :
  public instance
{
public:
  toolpathList();
  toolpathList(
    parenToolpathLisztFull * itsListIn);
  ~toolpathList();
  int isA(int aType);
  void printSelf();
  parenToolpathLisztFull * itsList;
};

/********************************************************************/

/* toolpathSpeedprofile

This is a mixed parent class.

*/

class toolpathSpeedprofile :
  public iso14649CppBase
{
public:
  toolpathSpeedprofile();
  ~toolpathSpeedprofile();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolpathType

This is a parent class.

*/

class toolpathType :
  public iso14649CppBase
{
public:
  toolpathType();
  ~toolpathType();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* toolpathTypeApproach

This is a class for the single definition of toolpathTypeApproach.
It represents the following items:

TOOLPATHTYPEAPPROACH

*/

class toolpathTypeApproach :
  public toolpathType
{
public:
  toolpathTypeApproach();
  ~toolpathTypeApproach();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolpathTypeConnect

This is a class for the single definition of toolpathTypeConnect.
It represents the following items:

TOOLPATHTYPECONNECT

*/

class toolpathTypeConnect :
  public toolpathType
{
public:
  toolpathTypeConnect();
  ~toolpathTypeConnect();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolpathTypeContact

This is a class for the single definition of toolpathTypeContact.
It represents the following items:

TOOLPATHTYPECONTACT

*/

class toolpathTypeContact :
  public toolpathType
{
public:
  toolpathTypeContact();
  ~toolpathTypeContact();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolpathTypeLift

This is a class for the single definition of toolpathTypeLift.
It represents the following items:

TOOLPATHTYPELIFT

*/

class toolpathTypeLift :
  public toolpathType
{
public:
  toolpathTypeLift();
  ~toolpathTypeLift();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolpathTypeNonContact

This is a class for the single definition of toolpathTypeNonContact.
It represents the following items:

TOOLPATHTYPENONCONTACT

*/

class toolpathTypeNonContact :
  public toolpathType
{
public:
  toolpathTypeNonContact();
  ~toolpathTypeNonContact();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolpathTypeTrajectoryPath

This is a class for the single definition of toolpathTypeTrajectoryPath.
It represents the following items:

TOOLPATHTYPETRAJECTORYPATH

*/

class toolpathTypeTrajectoryPath :
  public toolpathType
{
public:
  toolpathTypeTrajectoryPath();
  ~toolpathTypeTrajectoryPath();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolReferencePoint

This is a parent class.

*/

class toolReferencePoint :
  public iso14649CppBase
{
public:
  toolReferencePoint();
  ~toolReferencePoint();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* toolReferencePointCcp

This is a class for the single definition of toolReferencePointCcp.
It represents the following items:

TOOLREFERENCEPOINTCCP

*/

class toolReferencePointCcp :
  public toolReferencePoint
{
public:
  toolReferencePointCcp();
  ~toolReferencePointCcp();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolReferencePointTcp

This is a class for the single definition of toolReferencePointTcp.
It represents the following items:

TOOLREFERENCEPOINTTCP

*/

class toolReferencePointTcp :
  public toolReferencePoint
{
public:
  toolReferencePointTcp();
  ~toolReferencePointTcp();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* topologicalRepresentationItem

This is a parent class.

*/

class topologicalRepresentationItem :
  public representationItem
{
public:
  topologicalRepresentationItem();
  topologicalRepresentationItem(
    char * nameIn);
  ~topologicalRepresentationItem();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* touchProbe

This is a class for the single definition of touchProbe.
It represents the following items:

TOUCHPROBE '(' CHARSTRING ')'

*/

class touchProbe :
  public instance
{
public:
  touchProbe();
  touchProbe(
    char * itsIdIn);
  ~touchProbe();
  int isA(int aType);
  void printSelf();
  char * itsId;
};

/********************************************************************/

/* trajectory

This is a parent class.

*/

class trajectory :
  public toolpath
{
public:
  trajectory();
  trajectory(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    boolean * itsDirectionIn);
  ~trajectory();
  int isA(int aType);
  void printSelf() = 0;
  boolean * itsDirection;
};

/********************************************************************/

/* transitionCode

This is a parent class.

*/

class transitionCode :
  public iso14649CppBase
{
public:
  transitionCode();
  ~transitionCode();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* transitionCodeContinuous

This is a class for the single definition of transitionCodeContinuous.
It represents the following items:

TRANSITIONCODECONTINUOUS

*/

class transitionCodeContinuous :
  public transitionCode
{
public:
  transitionCodeContinuous();
  ~transitionCodeContinuous();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* transitionCodeContSameGradient

This is a class for the single definition of transitionCodeContSameGradient.
It represents the following items:

TRANSITIONCODECONTSAMEGRADIENT

*/

class transitionCodeContSameGradient :
  public transitionCode
{
public:
  transitionCodeContSameGradient();
  ~transitionCodeContSameGradient();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* transitionCodeContSameGradientSameCurvature

This is a class for the single definition of transitionCodeContSameGradientSameCurvature.
It represents the following items:

TRANSITIONCODECONTSAMEGRADIENTSAMECURVATURE

*/

class transitionCodeContSameGradientSameCurvature :
  public transitionCode
{
public:
  transitionCodeContSameGradientSameCurvature();
  ~transitionCodeContSameGradientSameCurvature();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* transitionCodeDiscontinuous

This is a class for the single definition of transitionCodeDiscontinuous.
It represents the following items:

TRANSITIONCODEDISCONTINUOUS

*/

class transitionCodeDiscontinuous :
  public transitionCode
{
public:
  transitionCodeDiscontinuous();
  ~transitionCodeDiscontinuous();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* transitionFeature

This is a parent class.

*/

class transitionFeature :
  public compoundFeatureSelect,
  public manufacturingFeature
{
public:
  transitionFeature();
  transitionFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    machiningFeature * firstFeatureIn,
    machiningFeature * secondFeatureIn);
  ~transitionFeature();
  int isA(int aType);
  void printSelf() = 0;
  machiningFeature * firstFeature;
  machiningFeature * secondFeature;
};

/********************************************************************/

/* travelPath

This is a parent class.

*/

class travelPath :
  public iso14649CppBase
{
public:
  travelPath();
  travelPath(
    axis2placement3d * placementIn);
  ~travelPath();
  int isA(int aType);
  void printSelf() = 0;
  axis2placement3d * placement;
};

/********************************************************************/

/* trimmingPreference

This is a parent class.

*/

class trimmingPreference :
  public iso14649CppBase
{
public:
  trimmingPreference();
  ~trimmingPreference();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* trimmingPreferenceCartesian

This is a class for the single definition of trimmingPreferenceCartesian.
It represents the following items:

TRIMMINGPREFERENCECARTESIAN

*/

class trimmingPreferenceCartesian :
  public trimmingPreference
{
public:
  trimmingPreferenceCartesian();
  ~trimmingPreferenceCartesian();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* trimmingPreferenceParameter

This is a class for the single definition of trimmingPreferenceParameter.
It represents the following items:

TRIMMINGPREFERENCEPARAMETER

*/

class trimmingPreferenceParameter :
  public trimmingPreference
{
public:
  trimmingPreferenceParameter();
  ~trimmingPreferenceParameter();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* trimmingPreferenceUnspecified

This is a class for the single definition of trimmingPreferenceUnspecified.
It represents the following items:

TRIMMINGPREFERENCEUNSPECIFIED

*/

class trimmingPreferenceUnspecified :
  public trimmingPreference
{
public:
  trimmingPreferenceUnspecified();
  ~trimmingPreferenceUnspecified();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* trimmingSelect

This is a mixed parent class.

*/

class trimmingSelect :
  public iso14649CppBase
{
public:
  trimmingSelect();
  ~trimmingSelect();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* twoAxes

This is a class for the single definition of twoAxes.
It represents the following items:

TWOAXES '(' ')'

*/

class twoAxes :
  public instance,
  public toolDirection
{
public:
  twoAxes();
  ~twoAxes();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* two5DmanufacturingFeature

This is a parent class.

*/

class two5DmanufacturingFeature :
  public manufacturingFeature
{
public:
  two5DmanufacturingFeature();
  two5DmanufacturingFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn);
  ~two5DmanufacturingFeature();
  int isA(int aType);
  void printSelf() = 0;
  axis2placement3d * featurePlacement;
};

/********************************************************************/

/* two5DmillingStrategy

This is a parent class.

*/

class two5DmillingStrategy :
  public iso14649CppBase
{
public:
  two5DmillingStrategy();
  two5DmillingStrategy(
    real * overlapIn,
    boolean * allowMultiplePassesIn);
  ~two5DmillingStrategy();
  int isA(int aType);
  void printSelf() = 0;
  real * overlap;
  boolean * allowMultiplePasses;
};

/********************************************************************/

/* unaryBooleanExpression

This is a parent class.

*/

class unaryBooleanExpression :
  public booleanExpression
{
public:
  unaryBooleanExpression();
  unaryBooleanExpression(
    booleanExpression * operandIn);
  ~unaryBooleanExpression();
  int isA(int aType);
  void printSelf() = 0;
  booleanExpression * operand;
};

/********************************************************************/

/* unidirectionalMilling

This is a class for the single definition of unidirectionalMilling.
It represents the following items:

UNIDIRECTIONALMILLING '(' optReal ',' optBoolean ',' optDirection ',' optCutmodeType ')'

*/

class unidirectionalMilling :
  public instance,
  public two5DmillingStrategy
{
public:
  unidirectionalMilling();
  unidirectionalMilling(
    real * overlapIn,
    boolean * allowMultiplePassesIn,
    direction * feedDirectionIn,
    cutmodeType * cutmodeIn);
  ~unidirectionalMilling();
  int isA(int aType);
  void printSelf();
  direction * feedDirection;
  cutmodeType * cutmode;
};

/********************************************************************/

/* unloadTool

This is a class for the single definition of unloadTool.
It represents the following items:

UNLOADTOOL '(' CHARSTRING ',' optMachiningTool ')'

*/

class unloadTool :
  public instance,
  public ncFunction
{
public:
  unloadTool();
  unloadTool(
    char * itsIdIn,
    machiningTool * itsToolIn);
  ~unloadTool();
  int isA(int aType);
  void printSelf();
  machiningTool * itsTool;
};

/********************************************************************/

/* uvStrategy

This is a class for the single definition of uvStrategy.
It represents the following items:

UVSTRATEGY '(' pathmodeType ',' cutmodeType ',' tolerances ',' optReal ',' direction ',' direction ')'

*/

class uvStrategy :
  public instance,
  public freeformStrategy
{
public:
  uvStrategy();
  uvStrategy(
    pathmodeType * pathmodeIn,
    cutmodeType * cutmodeIn,
    tolerances * itsMillingTolerancesIn,
    real * stepoverIn,
    direction * forwardDirectionIn,
    direction * sidewardDirectionIn);
  ~uvStrategy();
  int isA(int aType);
  void printSelf();
  direction * forwardDirection;
  direction * sidewardDirection;
};

/********************************************************************/

/* vertex

This is a parent class.

*/

class vertex :
  public topologicalRepresentationItem
{
public:
  vertex();
  vertex(
    char * nameIn);
  ~vertex();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* vertexPoint

This is a class for the single definition of vertexPoint.
It represents the following items:

VERTEXPOINT '(' CHARSTRING ',' point ')'

*/

class vertexPoint :
  public instance,
  public vertex
{
public:
  vertexPoint();
  vertexPoint(
    char * nameIn,
    point * vertexGeometryIn);
  ~vertexPoint();
  int isA(int aType);
  void printSelf();
  point * vertexGeometry;
};

/********************************************************************/

/* waitForMark

This is a class for the single definition of waitForMark.
It represents the following items:

WAITFORMARK '(' CHARSTRING ',' channel ')'

*/

class waitForMark :
  public instance,
  public ncFunction
{
public:
  waitForMark();
  waitForMark(
    char * itsIdIn,
    channel * itsChannelIn);
  ~waitForMark();
  int isA(int aType);
  void printSelf();
  channel * itsChannel;
};

/********************************************************************/

/* weekOfYearAndDayDate

This is a class for the single definition of weekOfYearAndDayDate.
It represents the following items:

WEEKOFYEARANDDAYDATE '(' INTSTRING ',' INTSTRING ',' optInteger ')'

*/

class weekOfYearAndDayDate :
  public instance,
  public date
{
public:
  weekOfYearAndDayDate();
  weekOfYearAndDayDate(
    int yearComponentIn,
    int weekComponentIn,
    integer * dayComponentIn);
  ~weekOfYearAndDayDate();
  int isA(int aType);
  void printSelf();
  int weekComponent;
  integer * dayComponent;
};

/********************************************************************/

/* whileStatement

This is a class for the single definition of whileStatement.
It represents the following items:

WHILESTATEMENT '(' CHARSTRING ',' booleanExpression ',' executable ')'

*/

class whileStatement :
  public instance,
  public programStructure
{
public:
  whileStatement();
  whileStatement(
    char * itsIdIn,
    booleanExpression * conditionIn,
    executable * bodyIn);
  ~whileStatement();
  int isA(int aType);
  void printSelf();
  booleanExpression * condition;
  executable * body;
};

/********************************************************************/

/* woodruffSlotEndType

This is a class for the single definition of woodruffSlotEndType.
It represents the following items:

WOODRUFFSLOTENDTYPE '(' tolerancedLengthMeasure ')'

*/

class woodruffSlotEndType :
  public instance,
  public slotEndType
{
public:
  woodruffSlotEndType();
  woodruffSlotEndType(
    tolerancedLengthMeasure * radiusIn);
  ~woodruffSlotEndType();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * radius;
};

/********************************************************************/

/* workingstep

This is a parent class.

*/

class workingstep :
  public executable
{
public:
  workingstep();
  workingstep(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn);
  ~workingstep();
  int isA(int aType);
  void printSelf() = 0;
  elementarySurface * itsSecplane;
};

/********************************************************************/

/* workpiece

This is a class for the single definition of workpiece.
It represents the following items:

WORKPIECE '(' CHARSTRING ',' optMaterial ',' optReal ',' optWorkpiece ',' optAdvancedBrepShapeRepresentation ',' optBoundingGeometrySelect ',' parenCartesianPointList ')'

*/

class workpiece :
  public instance
{
public:
  workpiece();
  workpiece(
    char * itsIdIn,
    material * itsMaterialIn,
    real * globalToleranceIn,
    workpiece * itsRawpieceIn,
    advancedBrepShapeRepresentation * itsGeometryIn,
    boundingGeometrySelect * itsBoundingGeometryIn,
    parenCartesianPointList * clampingPositionsIn);
  ~workpiece();
  int isA(int aType);
  void printSelf();
  char * itsId;
  material * itsMaterial;
  real * globalTolerance;
  workpiece * itsRawpiece;
  advancedBrepShapeRepresentation * itsGeometry;
  boundingGeometrySelect * itsBoundingGeometry;
  parenCartesianPointList * clampingPositions;
};

/********************************************************************/

/* workpieceSetup

This is a class for the single definition of workpieceSetup.
It represents the following items:

WORKPIECESETUP '(' workpiece ',' axis2placement3d ',' optOffsetVector ',' optRestrictedAreaSelect ',' parenSetupInstructionList ')'

*/

class workpieceSetup :
  public instance
{
public:
  workpieceSetup();
  workpieceSetup(
    workpiece * itsWorkpieceIn,
    axis2placement3d * itsOriginIn,
    offsetVector * itsOffsetIn,
    restrictedAreaSelect * itsRestrictedAreaIn,
    parenSetupInstructionList * itsInstructionsIn);
  ~workpieceSetup();
  int isA(int aType);
  void printSelf();
  workpiece * itsWorkpiece;
  axis2placement3d * itsOrigin;
  offsetVector * itsOffset;
  restrictedAreaSelect * itsRestrictedArea;
  parenSetupInstructionList * itsInstructions;
};

/********************************************************************/

/* workplan

This is a class for the single definition of workplan.
It represents the following items:

WORKPLAN '(' CHARSTRING ',' parenExecutableList ',' optChannel ',' optSetup ',' optInProcessGeometry ')'

*/

class workplan :
  public instance,
  public programStructure
{
public:
  workplan();
  workplan(
    char * itsIdIn,
    parenExecutableList * itsElementsIn,
    channel * itsChannelIn,
    setup * itsSetupIn,
    inProcessGeometry * itsEffectIn);
  ~workplan();
  int isA(int aType);
  void printSelf();
  parenExecutableList * itsElements;
  channel * itsChannel;
  setup * itsSetup;
  inProcessGeometry * itsEffect;
};

/********************************************************************/

/* airStrategy

This is a parent class.

*/

class airStrategy :
  public approachRetractStrategy
{
public:
  airStrategy();
  airStrategy(
    direction * toolOrientationIn);
  ~airStrategy();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* alongPath

This is a class for the single definition of alongPath.
It represents the following items:

ALONGPATH '(' optDirection ',' toolpathList ')'

*/

class alongPath :
  public instance,
  public approachRetractStrategy
{
public:
  alongPath();
  alongPath(
    direction * toolOrientationIn,
    toolpathList * pathIn);
  ~alongPath();
  int isA(int aType);
  void printSelf();
  toolpathList * path;
};

/********************************************************************/

/* andExpression

This is a class for the single definition of andExpression.
It represents the following items:

ANDEXPRESSION '(' parenBooleanExpressionListFull ')'

*/

class andExpression :
  public instance,
  public multipleArityBooleanExpression
{
public:
  andExpression();
  andExpression(
    parenBooleanExpressionListFull * operandsIn);
  ~andExpression();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* angleTaper

This is a class for the single definition of angleTaper.
It represents the following items:

ANGLETAPER '(' real ')'

*/

class angleTaper :
  public instance,
  public taperSelect
{
public:
  angleTaper();
  angleTaper(
    real * angleIn);
  ~angleTaper();
  int isA(int aType);
  void printSelf();
  real * angle;
};

/********************************************************************/

/* apRetractAngle

This is a class for the single definition of apRetractAngle.
It represents the following items:

APRETRACTANGLE '(' optDirection ',' REALSTRING ',' REALSTRING ')'

*/

class apRetractAngle :
  public instance,
  public airStrategy
{
public:
  apRetractAngle();
  apRetractAngle(
    direction * toolOrientationIn,
    double angleIn,
    double travelLengthIn);
  ~apRetractAngle();
  int isA(int aType);
  void printSelf();
  double angle;
  double travelLength;
};

/********************************************************************/

/* apRetractTangent

This is a class for the single definition of apRetractTangent.
It represents the following items:

APRETRACTTANGENT '(' optDirection ',' REALSTRING ')'

*/

class apRetractTangent :
  public instance,
  public airStrategy
{
public:
  apRetractTangent();
  apRetractTangent(
    direction * toolOrientationIn,
    double radiusIn);
  ~apRetractTangent();
  int isA(int aType);
  void printSelf();
  double radius;
};

/********************************************************************/

/* assignment

This is a class for the single definition of assignment.
It represents the following items:

ASSIGNMENT '(' CHARSTRING ',' ncVariable ',' rvalue ')'

*/

class assignment :
  public instance,
  public programStructure
{
public:
  assignment();
  assignment(
    char * itsIdIn,
    ncVariable * itsLvalueIn,
    rvalue * itsRvalueIn);
  ~assignment();
  int isA(int aType);
  void printSelf();
  ncVariable * itsLvalue;
  rvalue * itsRvalue;
};

/********************************************************************/

/* axisTrajectory

This is a class for the single definition of axisTrajectory.
It represents the following items:

AXISTRAJECTORY '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ',' optBoolean ',' parenStringListFull ',' parenBoundedCurveListFull ')'

*/

class axisTrajectory :
  public instance,
  public trajectory
{
public:
  axisTrajectory();
  axisTrajectory(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    boolean * itsDirectionIn,
    parenStringListFull * axisListIn,
    parenBoundedCurveListFull * commandsIn);
  ~axisTrajectory();
  int isA(int aType);
  void printSelf();
  parenStringListFull * axisList;
  parenBoundedCurveListFull * commands;
};

/********************************************************************/

/* bidirectionalContour

This is a class for the single definition of bidirectionalContour.
It represents the following items:

BIDIRECTIONALCONTOUR '(' optReal ',' optBoolean ',' optDirection ',' optLeftOrRight optRotDirection optCutmodeType ')'

*/

class bidirectionalContour :
  public instance,
  public two5DmillingStrategy
{
public:
  bidirectionalContour();
  bidirectionalContour(
    real * overlapIn,
    boolean * allowMultiplePassesIn,
    direction * feedDirectionIn,
    leftOrRight * stepoverDirectionIn,
    rotDirection * rotationDirectionIn,
    cutmodeType * spiralCutmodeIn);
  ~bidirectionalContour();
  int isA(int aType);
  void printSelf();
  direction * feedDirection;
  leftOrRight * stepoverDirection;
  rotDirection * rotationDirection;
  cutmodeType * spiralCutmode;
};

/********************************************************************/

/* bidirectionalMilling

This is a class for the single definition of bidirectionalMilling.
It represents the following items:

BIDIRECTIONALMILLING '(' optReal ',' optBoolean ',' optDirection ',' optLeftOrRight ',' optStrokeConnectionStrategy ')'

*/

class bidirectionalMilling :
  public instance,
  public two5DmillingStrategy
{
public:
  bidirectionalMilling();
  bidirectionalMilling(
    real * overlapIn,
    boolean * allowMultiplePassesIn,
    direction * feedDirectionIn,
    leftOrRight * stepoverDirectionIn,
    strokeConnectionStrategy * itsStrokeConnectionStrategyIn);
  ~bidirectionalMilling();
  int isA(int aType);
  void printSelf();
  direction * feedDirection;
  leftOrRight * stepoverDirection;
  strokeConnectionStrategy * itsStrokeConnectionStrategy;
};

/********************************************************************/

/* binaryBooleanExpression

This is a parent class.

*/

class binaryBooleanExpression :
  public booleanExpression
{
public:
  binaryBooleanExpression();
  binaryBooleanExpression(
    booleanExpression * operand1In,
    booleanExpression * operand2In);
  ~binaryBooleanExpression();
  int isA(int aType);
  void printSelf() = 0;
  booleanExpression * operand1;
  booleanExpression * operand2;
};

/********************************************************************/

/* blindBottomCondition

This is a parent class.

*/

class blindBottomCondition :
  public holeBottomCondition
{
public:
  blindBottomCondition();
  ~blindBottomCondition();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* boundingGeometrySelect

This is a parent class.

*/

class boundingGeometrySelect :
  public restrictedAreaSelect
{
public:
  boundingGeometrySelect();
  ~boundingGeometrySelect();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* calendarDate

This is a class for the single definition of calendarDate.
It represents the following items:

CALENDARDATE '(' INTSTRING ',' INTSTRING ',' INTSTRING ')'

*/

class calendarDate :
  public instance,
  public date
{
public:
  calendarDate();
  calendarDate(
    int yearComponentIn,
    int dayComponentIn,
    int monthComponentIn);
  ~calendarDate();
  int isA(int aType);
  void printSelf();
  int dayComponent;
  int monthComponent;
};

/********************************************************************/

/* centerMilling

This is a class for the single definition of centerMilling.
It represents the following items:

CENTERMILLING '(' optReal ',' optBoolean ')'

*/

class centerMilling :
  public instance,
  public two5DmillingStrategy
{
public:
  centerMilling();
  centerMilling(
    real * overlapIn,
    boolean * allowMultiplePassesIn);
  ~centerMilling();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* chamfer

This is a class for the single definition of chamfer.
It represents the following items:

CHAMFER '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' machiningFeature ',' machiningFeature ',' REALSTRING ',' tolerancedLengthMeasure ')'

*/

class chamfer :
  public instance,
  public transitionFeature
{
public:
  chamfer();
  chamfer(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    machiningFeature * firstFeatureIn,
    machiningFeature * secondFeatureIn,
    double angleToPlaneIn,
    tolerancedLengthMeasure * firstOffsetAmountIn);
  ~chamfer();
  int isA(int aType);
  void printSelf();
  double angleToPlane;
  tolerancedLengthMeasure * firstOffsetAmount;
};

/********************************************************************/

/* circularPath

This is a parent class.

*/

class circularPath :
  public travelPath
{
public:
  circularPath();
  circularPath(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * radiusIn);
  ~circularPath();
  int isA(int aType);
  void printSelf() = 0;
  tolerancedLengthMeasure * radius;
};

/********************************************************************/

/* closedProfile

This is a parent class.

*/

class closedProfile :
  public profile
{
public:
  closedProfile();
  closedProfile(
    axis2placement3d * placementIn);
  ~closedProfile();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* comparisonEqual

This is a class for the single definition of comparisonEqual.
It represents the following items:

COMPARISONEQUAL '(' ncVariable ',' rvalue ')'

*/

class comparisonEqual :
  public instance,
  public comparisonExpression
{
public:
  comparisonEqual();
  comparisonEqual(
    ncVariable * operand1In,
    rvalue * operand2In);
  ~comparisonEqual();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* comparisonGreater

This is a class for the single definition of comparisonGreater.
It represents the following items:

COMPARISONGREATER '(' ncVariable ',' rvalue ')'

*/

class comparisonGreater :
  public instance,
  public comparisonExpression
{
public:
  comparisonGreater();
  comparisonGreater(
    ncVariable * operand1In,
    rvalue * operand2In);
  ~comparisonGreater();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* comparisonGreaterEqual

This is a class for the single definition of comparisonGreaterEqual.
It represents the following items:

COMPARISONGREATEREQUAL '(' ncVariable ',' rvalue ')'

*/

class comparisonGreaterEqual :
  public instance,
  public comparisonExpression
{
public:
  comparisonGreaterEqual();
  comparisonGreaterEqual(
    ncVariable * operand1In,
    rvalue * operand2In);
  ~comparisonGreaterEqual();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* comparisonLess

This is a class for the single definition of comparisonLess.
It represents the following items:

COMPARISONLESS '(' ncVariable ',' rvalue ')'

*/

class comparisonLess :
  public instance,
  public comparisonExpression
{
public:
  comparisonLess();
  comparisonLess(
    ncVariable * operand1In,
    rvalue * operand2In);
  ~comparisonLess();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* comparisonLessEqual

This is a class for the single definition of comparisonLessEqual.
It represents the following items:

COMPARISONLESSEQUAL '(' ncVariable ',' rvalue ')'

*/

class comparisonLessEqual :
  public instance,
  public comparisonExpression
{
public:
  comparisonLessEqual();
  comparisonLessEqual(
    ncVariable * operand1In,
    rvalue * operand2In);
  ~comparisonLessEqual();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* comparisonNotEqual

This is a class for the single definition of comparisonNotEqual.
It represents the following items:

COMPARISONNOTEQUAL '(' ncVariable ',' rvalue ')'

*/

class comparisonNotEqual :
  public instance,
  public comparisonExpression
{
public:
  comparisonNotEqual();
  comparisonNotEqual(
    ncVariable * operand1In,
    rvalue * operand2In);
  ~comparisonNotEqual();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* completeCircularPath

This is a class for the single definition of completeCircularPath.
It represents the following items:

COMPLETECIRCULARPATH '(' optAxis2placement3d ',' tolerancedLengthMeasure ')'

*/

class completeCircularPath :
  public instance,
  public circularPath
{
public:
  completeCircularPath();
  completeCircularPath(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * radiusIn);
  ~completeCircularPath();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* compoundFeature

This is a parent class.

*/

class compoundFeature :
  public two5DmanufacturingFeature
{
public:
  compoundFeature();
  compoundFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    parenCompoundFeatureSelectListFull * elementsIn);
  ~compoundFeature();
  int isA(int aType);
  void printSelf() = 0;
  parenCompoundFeatureSelectListFull * elements;
};

/********************************************************************/

/* conicalHoleBottom

This is a class for the single definition of conicalHoleBottom.
It represents the following items:

CONICALHOLEBOTTOM '(' real ',' optTolerancedLengthMeasure ')'

*/

class conicalHoleBottom :
  public instance,
  public blindBottomCondition
{
public:
  conicalHoleBottom();
  conicalHoleBottom(
    real * tipAngleIn,
    tolerancedLengthMeasure * tipRadiusIn);
  ~conicalHoleBottom();
  int isA(int aType);
  void printSelf();
  real * tipAngle;
  tolerancedLengthMeasure * tipRadius;
};

/********************************************************************/

/* connectedFaceSet

This is a parent class.

*/

class connectedFaceSet :
  public topologicalRepresentationItem
{
public:
  connectedFaceSet();
  connectedFaceSet(
    char * nameIn,
    parenFaceListFull * cfsFacesIn);
  ~connectedFaceSet();
  int isA(int aType);
  void printSelf() = 0;
  parenFaceListFull * cfsFaces;
};

/********************************************************************/

/* contourBidirectional

This is a class for the single definition of contourBidirectional.
It represents the following items:

CONTOURBIDIRECTIONAL '(' optReal ',' optBoolean ',' optDirection ',' optLeftOrRight optRotDirection optCutmodeType ')'

*/

class contourBidirectional :
  public instance,
  public two5DmillingStrategy
{
public:
  contourBidirectional();
  contourBidirectional(
    real * overlapIn,
    boolean * allowMultiplePassesIn,
    direction * feedDirectionIn,
    leftOrRight * stepoverDirectionIn,
    rotDirection * rotationDirectionIn,
    cutmodeType * spiralCutmodeIn);
  ~contourBidirectional();
  int isA(int aType);
  void printSelf();
  direction * feedDirection;
  leftOrRight * stepoverDirection;
  rotDirection * rotationDirection;
  cutmodeType * spiralCutmode;
};

/********************************************************************/

/* contourParallel

This is a class for the single definition of contourParallel.
It represents the following items:

CONTOURPARALLEL '(' optReal ',' optBoolean ',' rotDirection ',' optCutmodeType ')'

*/

class contourParallel :
  public instance,
  public two5DmillingStrategy
{
public:
  contourParallel();
  contourParallel(
    real * overlapIn,
    boolean * allowMultiplePassesIn,
    rotDirection * rotationDirectionIn,
    cutmodeType * cutmodeIn);
  ~contourParallel();
  int isA(int aType);
  void printSelf();
  rotDirection * rotationDirection;
  cutmodeType * cutmode;
};

/********************************************************************/

/* contourSpiral

This is a class for the single definition of contourSpiral.
It represents the following items:

CONTOURSPIRAL '(' optReal ',' optBoolean ',' rotDirection ',' optCutmodeType ')'

*/

class contourSpiral :
  public instance,
  public two5DmillingStrategy
{
public:
  contourSpiral();
  contourSpiral(
    real * overlapIn,
    boolean * allowMultiplePassesIn,
    rotDirection * rotationDirectionIn,
    cutmodeType * cutmodeIn);
  ~contourSpiral();
  int isA(int aType);
  void printSelf();
  rotDirection * rotationDirection;
  cutmodeType * cutmode;
};

/********************************************************************/

/* counterboreHole

This is a class for the single definition of counterboreHole.
It represents the following items:

COUNTERBOREHOLE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' parenCompoundFeatureSelectListFull ')'

*/

class counterboreHole :
  public instance,
  public compoundFeature
{
public:
  counterboreHole();
  counterboreHole(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    parenCompoundFeatureSelectListFull * elementsIn);
  ~counterboreHole();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* countersunkHole

This is a class for the single definition of countersunkHole.
It represents the following items:

COUNTERSUNKHOLE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' parenCompoundFeatureSelectListFull ')'

*/

class countersunkHole :
  public instance,
  public compoundFeature
{
public:
  countersunkHole();
  countersunkHole(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    parenCompoundFeatureSelectListFull * elementsIn);
  ~countersunkHole();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* curveWithNormalVector

This is a class for the single definition of curveWithNormalVector.
It represents the following items:

CURVEWITHNORMALVECTOR '(' boundedCurve ',' boundedCurve ')'

*/

class curveWithNormalVector :
  public instance,
  public curveWithSurfaceNormalSelect
{
public:
  curveWithNormalVector();
  curveWithNormalVector(
    boundedCurve * basiccurveIn,
    boundedCurve * surfaceNormalIn);
  ~curveWithNormalVector();
  int isA(int aType);
  void printSelf();
  boundedCurve * basiccurve;
  boundedCurve * surfaceNormal;
};

/********************************************************************/

/* cutterLocationTrajectory

This is a class for the single definition of cutterLocationTrajectory.
It represents the following items:

CUTTERLOCATIONTRAJECTORY '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ',' optBoolean ',' boundedCurve ',' optBoundedCurve ',' optBoundedCurve ')'

*/

class cutterLocationTrajectory :
  public instance,
  public trajectory
{
public:
  cutterLocationTrajectory();
  cutterLocationTrajectory(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    boolean * itsDirectionIn,
    boundedCurve * basiccurveIn,
    boundedCurve * itsToolaxisIn,
    boundedCurve * surfaceNormalIn);
  ~cutterLocationTrajectory();
  int isA(int aType);
  void printSelf();
  boundedCurve * basiccurve;
  boundedCurve * itsToolaxis;
  boundedCurve * surfaceNormal;
};

/********************************************************************/

/* cuttingTool

This is a parent class.

*/

class cuttingTool :
  public machiningTool
{
public:
  cuttingTool();
  cuttingTool(
    char * itsIdIn,
    toolBody * itsToolBodyIn,
    parenCuttingComponentListFull * itsCuttingEdgeIn,
    real * overallAssemblyLengthIn);
  ~cuttingTool();
  int isA(int aType);
  void printSelf() = 0;
  toolBody * itsToolBody;
  parenCuttingComponentListFull * itsCuttingEdge;
  real * overallAssemblyLength;
};

/********************************************************************/

/* definitionalRepresentation

This is a class for the single definition of definitionalRepresentation.
It represents the following items:

DEFINITIONALREPRESENTATION '(' CHARSTRING ',' parenRepresentationItemListFull ',' representationContext ')'

*/

class definitionalRepresentation :
  public instance,
  public representationParent
{
public:
  definitionalRepresentation();
  definitionalRepresentation(
    char * nameIn,
    parenRepresentationItemListFull * itemsIn,
    representationContext * contextOfItemsIn);
  ~definitionalRepresentation();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* descriptiveParameter

This is a class for the single definition of descriptiveParameter.
It represents the following items:

DESCRIPTIVEPARAMETER '(' CHARSTRING ',' CHARSTRING ')'

*/

class descriptiveParameter :
  public instance,
  public propertyParameter
{
public:
  descriptiveParameter();
  descriptiveParameter(
    char * parameterNameIn,
    char * descriptiveStringIn);
  ~descriptiveParameter();
  int isA(int aType);
  void printSelf();
  char * descriptiveString;
};

/********************************************************************/

/* diameterTaper

This is a class for the single definition of diameterTaper.
It represents the following items:

DIAMETERTAPER '(' tolerancedLengthMeasure ')'

*/

class diameterTaper :
  public instance,
  public taperSelect
{
public:
  diameterTaper();
  diameterTaper(
    tolerancedLengthMeasure * finalDiameterIn);
  ~diameterTaper();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * finalDiameter;
};

/********************************************************************/

/* displayMessage

This is a class for the single definition of displayMessage.
It represents the following items:

DISPLAYMESSAGE '(' CHARSTRING ',' CHARSTRING ')'

*/

class displayMessage :
  public instance,
  public ncFunction
{
public:
  displayMessage();
  displayMessage(
    char * itsIdIn,
    char * itsTextIn);
  ~displayMessage();
  int isA(int aType);
  void printSelf();
  char * itsText;
};

/********************************************************************/

/* edge

This is a parent class.

*/

class edge :
  public topologicalRepresentationItem
{
public:
  edge();
  edge(
    char * nameIn,
    vertex * edgeStartIn,
    vertex * edgeEndIn);
  ~edge();
  int isA(int aType);
  void printSelf() = 0;
  vertex * edgeStart;
  vertex * edgeEnd;
};

/********************************************************************/

/* edgeCurve

This is a class for the single definition of edgeCurve.
It represents the following items:

EDGECURVE '(' CHARSTRING ',' vertex ',' vertex ',' curve ',' boolean ')'

*/

class edgeCurve :
  public instance,
  public edge
{
public:
  edgeCurve();
  edgeCurve(
    char * nameIn,
    vertex * edgeStartIn,
    vertex * edgeEndIn,
    curve * edgeGeometryIn,
    boolean * sameSenseIn);
  ~edgeCurve();
  int isA(int aType);
  void printSelf();
  curve * edgeGeometry;
  boolean * sameSense;
};

/********************************************************************/

/* edgeRound

This is a class for the single definition of edgeRound.
It represents the following items:

EDGEROUND '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' machiningFeature ',' machiningFeature ',' tolerancedLengthMeasure ',' optTolerancedLengthMeasure ',' optTolerancedLengthMeasure ')'

*/

class edgeRound :
  public instance,
  public transitionFeature
{
public:
  edgeRound();
  edgeRound(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    machiningFeature * firstFeatureIn,
    machiningFeature * secondFeatureIn,
    tolerancedLengthMeasure * radiusIn,
    tolerancedLengthMeasure * firstOffsetAmountIn,
    tolerancedLengthMeasure * secondOffsetAmountIn);
  ~edgeRound();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * radius;
  tolerancedLengthMeasure * firstOffsetAmount;
  tolerancedLengthMeasure * secondOffsetAmount;
};

/********************************************************************/

/* exchangePallet

This is a class for the single definition of exchangePallet.
It represents the following items:

EXCHANGEPALLET '(' CHARSTRING ')'

*/

class exchangePallet :
  public instance,
  public ncFunction
{
public:
  exchangePallet();
  exchangePallet(
    char * itsIdIn);
  ~exchangePallet();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* explicitStrategy

This is a class for the single definition of explicitStrategy.
It represents the following items:

EXPLICITSTRATEGY '(' optReal ',' optBoolean ')'

*/

class explicitStrategy :
  public instance,
  public two5DmillingStrategy
{
public:
  explicitStrategy();
  explicitStrategy(
    real * overlapIn,
    boolean * allowMultiplePassesIn);
  ~explicitStrategy();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* face

This is a parent class.

*/

class face :
  public topologicalRepresentationItem
{
public:
  face();
  face(
    char * nameIn,
    parenFaceBoundListFull * boundsIn);
  ~face();
  int isA(int aType);
  void printSelf() = 0;
  parenFaceBoundListFull * bounds;
};

/********************************************************************/

/* faceBoundParent

This is a parent class.

*/

class faceBoundParent :
  public topologicalRepresentationItem
{
public:
  faceBoundParent();
  faceBoundParent(
    char * nameIn,
    loop * boundIn,
    boolean * orientationIn);
  ~faceBoundParent();
  int isA(int aType);
  void printSelf() = 0;
  loop * bound;
  boolean * orientation;
};

/********************************************************************/

/* faceBound

This is a class for the single definition of faceBound.
It represents the following items:

FACEBOUND '(' CHARSTRING ',' loop ',' boolean ')'

*/

class faceBound :
  public instance,
  public faceBoundParent
{
public:
  faceBound();
  faceBound(
    char * nameIn,
    loop * boundIn,
    boolean * orientationIn);
  ~faceBound();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* faceOuterBound

This is a class for the single definition of faceOuterBound.
It represents the following items:

FACEOUTERBOUND '(' CHARSTRING ',' loop ',' boolean ')'

*/

class faceOuterBound :
  public instance,
  public faceBoundParent
{
public:
  faceOuterBound();
  faceOuterBound(
    char * nameIn,
    loop * boundIn,
    boolean * orientationIn);
  ~faceOuterBound();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* faceSurface

This is a parent class.

*/

class faceSurface :
  public face
{
public:
  faceSurface();
  faceSurface(
    char * nameIn,
    parenFaceBoundListFull * boundsIn,
    surface * faceGeometryIn,
    boolean * sameSenseIn);
  ~faceSurface();
  int isA(int aType);
  void printSelf() = 0;
  surface * faceGeometry;
  boolean * sameSense;
};

/********************************************************************/

/* feedstop

This is a class for the single definition of feedstop.
It represents the following items:

FEEDSTOP '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ',' REALSTRING ')'

*/

class feedstop :
  public instance,
  public toolpath
{
public:
  feedstop();
  feedstop(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    double dwellIn);
  ~feedstop();
  int isA(int aType);
  void printSelf();
  double dwell;
};

/********************************************************************/

/* fiveAxesVarTiltYaw

This is a class for the single definition of fiveAxesVarTiltYaw.
It represents the following items:

FIVEAXESVARTILTYAW '(' ')'

*/

class fiveAxesVarTiltYaw :
  public instance,
  public toolDirectionForMilling
{
public:
  fiveAxesVarTiltYaw();
  ~fiveAxesVarTiltYaw();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* fiveAxesConstTiltYaw

This is a class for the single definition of fiveAxesConstTiltYaw.
It represents the following items:

FIVEAXESCONSTTILTYAW '(' REALSTRING ',' REALSTRING ')'

*/

class fiveAxesConstTiltYaw :
  public instance,
  public toolDirectionForMilling
{
public:
  fiveAxesConstTiltYaw();
  fiveAxesConstTiltYaw(
    double tiltAngleIn,
    double yawAngleIn);
  ~fiveAxesConstTiltYaw();
  int isA(int aType);
  void printSelf();
  double tiltAngle;
  double yawAngle;
};

/********************************************************************/

/* flatHoleBottom

This is a class for the single definition of flatHoleBottom.
It represents the following items:

FLATHOLEBOTTOM '(' ')'

*/

class flatHoleBottom :
  public instance,
  public blindBottomCondition
{
public:
  flatHoleBottom();
  ~flatHoleBottom();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* flatSlotEndType

This is a class for the single definition of flatSlotEndType.
It represents the following items:

FLATSLOTENDTYPE '(' tolerancedLengthMeasure ',' tolerancedLengthMeasure ')'

*/

class flatSlotEndType :
  public instance,
  public slotEndType
{
public:
  flatSlotEndType();
  flatSlotEndType(
    tolerancedLengthMeasure * cornerRadius1In,
    tolerancedLengthMeasure * cornerRadius2In);
  ~flatSlotEndType();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * cornerRadius1;
  tolerancedLengthMeasure * cornerRadius2;
};

/********************************************************************/

/* flatWithRadiusHoleBottom

This is a class for the single definition of flatWithRadiusHoleBottom.
It represents the following items:

FLATWITHRADIUSHOLEBOTTOM '(' tolerancedLengthMeasure ')'

*/

class flatWithRadiusHoleBottom :
  public instance,
  public blindBottomCondition
{
public:
  flatWithRadiusHoleBottom();
  flatWithRadiusHoleBottom(
    tolerancedLengthMeasure * cornerRadiusIn);
  ~flatWithRadiusHoleBottom();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * cornerRadius;
};

/********************************************************************/

/* generalClosedProfile

This is a class for the single definition of generalClosedProfile.
It represents the following items:

GENERALCLOSEDPROFILE '(' optAxis2placement3d ',' boundedCurve ')'

*/

class generalClosedProfile :
  public instance,
  public closedProfile
{
public:
  generalClosedProfile();
  generalClosedProfile(
    axis2placement3d * placementIn,
    boundedCurve * closedProfileShapeIn);
  ~generalClosedProfile();
  int isA(int aType);
  void printSelf();
  boundedCurve * closedProfileShape;
};

/********************************************************************/

/* generalPath

This is a class for the single definition of generalPath.
It represents the following items:

GENERALPATH '(' optAxis2placement3d ',' boundedCurve ')'

*/

class generalPath :
  public instance,
  public travelPath
{
public:
  generalPath();
  generalPath(
    axis2placement3d * placementIn,
    boundedCurve * sweptPathIn);
  ~generalPath();
  int isA(int aType);
  void printSelf();
  boundedCurve * sweptPath;
};

/********************************************************************/

/* generalPocketBottomCondition

This is a class for the single definition of generalPocketBottomCondition.
It represents the following items:

GENERALPOCKETBOTTOMCONDITION '(' region ')'

*/

class generalPocketBottomCondition :
  public instance,
  public pocketBottomCondition
{
public:
  generalPocketBottomCondition();
  generalPocketBottomCondition(
    region * shapeIn);
  ~generalPocketBottomCondition();
  int isA(int aType);
  void printSelf();
  region * shape;
};

/********************************************************************/

/* geometricRepresentationItem

This is a parent class.

*/

class geometricRepresentationItem :
  public representationItem
{
public:
  geometricRepresentationItem();
  geometricRepresentationItem(
    char * nameIn);
  ~geometricRepresentationItem();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* ifStatement

This is a class for the single definition of ifStatement.
It represents the following items:

IFSTATEMENT '(' CHARSTRING ',' booleanExpression ',' executable ',' optExecutable ')'

*/

class ifStatement :
  public instance,
  public programStructure
{
public:
  ifStatement();
  ifStatement(
    char * itsIdIn,
    booleanExpression * conditionIn,
    executable * trueBranchIn,
    executable * falseBranchIn);
  ~ifStatement();
  int isA(int aType);
  void printSelf();
  booleanExpression * condition;
  executable * trueBranch;
  executable * falseBranch;
};

/********************************************************************/

/* indexPallet

This is a class for the single definition of indexPallet.
It represents the following items:

INDEXPALLET '(' CHARSTRING ',' INTSTRING ')'

*/

class indexPallet :
  public instance,
  public ncFunction
{
public:
  indexPallet();
  indexPallet(
    char * itsIdIn,
    int its_indexIn);
  ~indexPallet();
  int isA(int aType);
  void printSelf();
  int its_index;
};

/********************************************************************/

/* indexTable

This is a class for the single definition of indexTable.
It represents the following items:

INDEXTABLE '(' CHARSTRING ',' INTSTRING ')'

*/

class indexTable :
  public instance,
  public ncFunction
{
public:
  indexTable();
  indexTable(
    char * itsIdIn,
    int its_indexIn);
  ~indexTable();
  int isA(int aType);
  void printSelf();
  int its_index;
};

/********************************************************************/

/* limitsAndFits

This is a class for the single definition of limitsAndFits.
It represents the following items:

LIMITSANDFITS '(' REALSTRING ',' REALSTRING ',' optFittingType ')'

*/

class limitsAndFits :
  public instance,
  public toleranceSelect
{
public:
  limitsAndFits();
  limitsAndFits(
    double deviationIn,
    double gradeIn,
    fittingType * itsFittingTypeIn);
  ~limitsAndFits();
  int isA(int aType);
  void printSelf();
  double deviation;
  double grade;
  fittingType * itsFittingType;
};

/********************************************************************/

/* linearPath

This is a class for the single definition of linearPath.
It represents the following items:

LINEARPATH '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' direction ')'

*/

class linearPath :
  public instance,
  public travelPath
{
public:
  linearPath();
  linearPath(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * distanceIn,
    direction * itsDirectionIn);
  ~linearPath();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * distance;
  direction * itsDirection;
};

/********************************************************************/

/* loadTool

This is a class for the single definition of loadTool.
It represents the following items:

LOADTOOL '(' CHARSTRING ',' machiningTool ')'

*/

class loadTool :
  public instance,
  public ncFunction
{
public:
  loadTool();
  loadTool(
    char * itsIdIn,
    machiningTool * itsToolIn);
  ~loadTool();
  int isA(int aType);
  void printSelf();
  machiningTool * itsTool;
};

/********************************************************************/

/* loop

This is a parent class.

*/

class loop :
  public topologicalRepresentationItem
{
public:
  loop();
  loop(
    char * nameIn);
  ~loop();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* loopSlotEndType

This is a class for the single definition of loopSlotEndType.
It represents the following items:

LOOPSLOTENDTYPE '(' ')'

*/

class loopSlotEndType :
  public instance,
  public slotEndType
{
public:
  loopSlotEndType();
  ~loopSlotEndType();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* machiningFeature

This is a parent class.

*/

class machiningFeature :
  public compoundFeatureSelect,
  public two5DmanufacturingFeature
{
public:
  machiningFeature();
  machiningFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn);
  ~machiningFeature();
  int isA(int aType);
  void printSelf() = 0;
  elementarySurface * depth;
};

/********************************************************************/

/* machiningOperation

This is a parent class.

*/

class machiningOperation :
  public operation
{
public:
  machiningOperation();
  machiningOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn);
  ~machiningOperation();
  int isA(int aType);
  void printSelf() = 0;
  char * itsId;
  real * retractPlane;
  cartesianPoint * startPoint;
  machiningTool * itsTool;
  technology * itsTechnology;
  machineFunctions * itsMachineFunctions;
};

/********************************************************************/

/* machiningWorkingstep

This is a class for the single definition of machiningWorkingstep.
It represents the following items:

MACHININGWORKINGSTEP '(' CHARSTRING ',' elementarySurface ',' manufacturingFeature ',' machiningOperation ',' optInProcessGeometry ')'

*/

class machiningWorkingstep :
  public instance,
  public workingstep
{
public:
  machiningWorkingstep();
  machiningWorkingstep(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    manufacturingFeature * itsFeatureIn,
    machiningOperation * itsOperationIn,
    inProcessGeometry * itsEffectIn);
  ~machiningWorkingstep();
  int isA(int aType);
  void printSelf();
  manufacturingFeature * itsFeature;
  machiningOperation * itsOperation;
  inProcessGeometry * itsEffect;
};

/********************************************************************/

/* millingCuttingTool

This is a class for the single definition of millingCuttingTool.
It represents the following items:

MILLINGCUTTINGTOOL '(' CHARSTRING ',' toolBody ',' parenCuttingComponentListFull ',' optReal ',' optDirection ',' optReal ')'

*/

class millingCuttingTool :
  public instance,
  public cuttingTool
{
public:
  millingCuttingTool();
  millingCuttingTool(
    char * itsIdIn,
    toolBody * itsToolBodyIn,
    parenCuttingComponentListFull * itsCuttingEdgeIn,
    real * overallAssemblyLengthIn,
    direction * directionForSpindleOrientationIn,
    real * toolHolderDiameterForSpindleOrientationIn);
  ~millingCuttingTool();
  int isA(int aType);
  void printSelf();
  direction * directionForSpindleOrientation;
  real * toolHolderDiameterForSpindleOrientation;
};

/********************************************************************/

/* millingMachiningOperation

This is a parent class.

*/

class millingMachiningOperation :
  public machiningOperation
{
public:
  millingMachiningOperation();
  millingMachiningOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn);
  ~millingMachiningOperation();
  int isA(int aType);
  void printSelf() = 0;
  real * overcutLength;
};

/********************************************************************/

/* millingTechnology

This is a class for the single definition of millingTechnology.
It represents the following items:

MILLINGTECHNOLOGY '(' optReal ',' toolReferencePoint ',' optReal ',' optReal ',' optReal ',' boolean ',' boolean ',' boolean ',' optBoolean ')'

*/

class millingTechnology :
  public instance,
  public technology
{
public:
  millingTechnology();
  millingTechnology(
    real * feedrateIn,
    toolReferencePoint * feedrateReferenceIn,
    real * cutspeedIn,
    real * spindleIn,
    real * feedratePerToothIn,
    boolean * synchronizeSpindleWithFeedIn,
    boolean * inhibitFeedrateOverrideIn,
    boolean * inhibitSpindleOverrideIn,
    boolean * itsAdaptiveControlIn);
  ~millingTechnology();
  int isA(int aType);
  void printSelf();
  real * cutspeed;
  real * spindle;
  real * feedratePerTooth;
  boolean * synchronizeSpindleWithFeed;
  boolean * inhibitFeedrateOverride;
  boolean * inhibitSpindleOverride;
  boolean * itsAdaptiveControl;
};

/********************************************************************/

/* millingToolBody

This is a parent class.

*/

class millingToolBody :
  public toolBody
{
public:
  millingToolBody();
  millingToolBody(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~millingToolBody();
  int isA(int aType);
  void printSelf() = 0;
  millingToolDimension * dimension;
  integer * numberOfTeeth;
  hand * handOfCut;
  boolean * coolantThroughTool;
  real * pilotLength;
};

/********************************************************************/

/* millingTypeOperation

This is a parent class.

*/

class millingTypeOperation :
  public millingMachiningOperation
{
public:
  millingTypeOperation();
  millingTypeOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn);
  ~millingTypeOperation();
  int isA(int aType);
  void printSelf() = 0;
  approachRetractStrategy * approach;
  approachRetractStrategy * retract;
};

/********************************************************************/

/* ncConstant

This is a class for the single definition of ncConstant.
It represents the following items:

NCCONSTANT '(' CHARSTRING ',' optReal ')'

*/

class ncConstant :
  public instance,
  public rvalue
{
public:
  ncConstant();
  ncConstant(
    char * itsNameIn,
    real * initialValueIn);
  ~ncConstant();
  int isA(int aType);
  void printSelf();
  char * itsName;
  real * initialValue;
};

/********************************************************************/

/* ncVariable

This is a class for the single definition of ncVariable.
It represents the following items:

NCVARIABLE '(' CHARSTRING ',' optReal ')'

*/

class ncVariable :
  public instance,
  public rvalue
{
public:
  ncVariable();
  ncVariable(
    char * itsNameIn,
    real * initialValueIn);
  ~ncVariable();
  int isA(int aType);
  void printSelf();
  char * itsName;
  real * initialValue;
};

/********************************************************************/

/* ngonClosedProfile

This is a class for the single definition of ngonClosedProfile.
It represents the following items:

NGONCLOSEDPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' INTSTRING ',' boolean ')'

*/

class ngonClosedProfile :
  public instance,
  public closedProfile
{
public:
  ngonClosedProfile();
  ngonClosedProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * diameterIn,
    int numberOfSidesIn,
    boolean * circumscribedOrAcrossFlatsIn);
  ~ngonClosedProfile();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * diameter;
  int numberOfSides;
  boolean * circumscribedOrAcrossFlats;
};

/********************************************************************/

/* nonSequential

This is a class for the single definition of nonSequential.
It represents the following items:

NONSEQUENTIAL '(' CHARSTRING ',' parenExecutableListFull ')'

*/

class nonSequential :
  public instance,
  public programStructure
{
public:
  nonSequential();
  nonSequential(
    char * itsIdIn,
    parenExecutableListFull * itsElementsIn);
  ~nonSequential();
  int isA(int aType);
  void printSelf();
  parenExecutableListFull * itsElements;
};

/********************************************************************/

/* notExpression

This is a class for the single definition of notExpression.
It represents the following items:

NOTEXPRESSION '(' booleanExpression ')'

*/

class notExpression :
  public instance,
  public unaryBooleanExpression
{
public:
  notExpression();
  notExpression(
    booleanExpression * operandIn);
  ~notExpression();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* numericParameter

This is a class for the single definition of numericParameter.
It represents the following items:

NUMERICPARAMETER '(' CHARSTRING ',' REALSTRING ',' CHARSTRING ')'

*/

class numericParameter :
  public instance,
  public propertyParameter
{
public:
  numericParameter();
  numericParameter(
    char * parameterNameIn,
    double itsParameterValueIn,
    char * itsParameterUnitIn);
  ~numericParameter();
  int isA(int aType);
  void printSelf();
  double itsParameterValue;
  char * itsParameterUnit;
};

/********************************************************************/

/* openProfile

This is a parent class.

*/

class openProfile :
  public profile
{
public:
  openProfile();
  openProfile(
    axis2placement3d * placementIn);
  ~openProfile();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* openShellParent

This is a parent class.

*/

class openShellParent :
  public connectedFaceSet
{
public:
  openShellParent();
  openShellParent(
    char * nameIn,
    parenFaceListFull * cfsFacesIn);
  ~openShellParent();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* openShell

This is a class for the single definition of openShell.
It represents the following items:

OPENSHELL '(' CHARSTRING ',' parenFaceListFull ')'

*/

class openShell :
  public instance,
  public openShellParent
{
public:
  openShell();
  openShell(
    char * nameIn,
    parenFaceListFull * cfsFacesIn);
  ~openShell();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* openSlotEndType

This is a class for the single definition of openSlotEndType.
It represents the following items:

OPENSLOTENDTYPE '(' ')'

*/

class openSlotEndType :
  public instance,
  public slotEndType
{
public:
  openSlotEndType();
  ~openSlotEndType();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* orientedEdge

This is a class for the single definition of orientedEdge.
It represents the following items:

ORIENTEDEDGE '(' CHARSTRING ',' vertex ',' vertex ',' edge ',' boolean ')'

*/

class orientedEdge :
  public instance,
  public edge
{
public:
  orientedEdge();
  orientedEdge(
    char * nameIn,
    vertex * edgeStartIn,
    vertex * edgeEndIn,
    edge * edgeElementIn,
    boolean * orientationIn);
  ~orientedEdge();
  int isA(int aType);
  void printSelf();
  edge * edgeElement;
  boolean * orientation;
};

/********************************************************************/

/* parallel

This is a class for the single definition of parallel.
It represents the following items:

PARALLEL '(' CHARSTRING ',' parenExecutableListFull ')'

*/

class parallel :
  public instance,
  public programStructure
{
public:
  parallel();
  parallel(
    char * itsIdIn,
    parenExecutableListFull * branchesIn);
  ~parallel();
  int isA(int aType);
  void printSelf();
  parenExecutableListFull * branches;
};

/********************************************************************/

/* parameterisedPath

This is a parent class.

*/

class parameterisedPath :
  public toolpath
{
public:
  parameterisedPath();
  parameterisedPath(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn);
  ~parameterisedPath();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* partialCircularPath

This is a class for the single definition of partialCircularPath.
It represents the following items:

PARTIALCIRCULARPATH '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' REALSTRING ')'

*/

class partialCircularPath :
  public instance,
  public circularPath
{
public:
  partialCircularPath();
  partialCircularPath(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * radiusIn,
    double sweepAngleIn);
  ~partialCircularPath();
  int isA(int aType);
  void printSelf();
  double sweepAngle;
};

/********************************************************************/

/* partialCircularProfile

This is a class for the single definition of partialCircularProfile.
It represents the following items:

PARTIALCIRCULARPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' REALSTRING ')'

*/

class partialCircularProfile :
  public instance,
  public openProfile
{
public:
  partialCircularProfile();
  partialCircularProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * radiusIn,
    double sweepAngleIn);
  ~partialCircularProfile();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * radius;
  double sweepAngle;
};

/********************************************************************/

/* placement

This is a parent class.

*/

class placement :
  public geometricRepresentationItem
{
public:
  placement();
  placement(
    char * nameIn,
    cartesianPoint * locationIn);
  ~placement();
  int isA(int aType);
  void printSelf() = 0;
  cartesianPoint * location;
};

/********************************************************************/

/* planarFace

This is a class for the single definition of planarFace.
It represents the following items:

PLANARFACE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' linearProfile ',' optClosedProfile ',' parenBossList ')'

*/

class planarFace :
  public instance,
  public machiningFeature
{
public:
  planarFace();
  planarFace(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * courseOfTravelIn,
    linearProfile * removalBoundaryIn,
    closedProfile * faceBoundaryIn,
    parenBossList * itsBossIn);
  ~planarFace();
  int isA(int aType);
  void printSelf();
  linearPath * courseOfTravel;
  linearProfile * removalBoundary;
  closedProfile * faceBoundary;
  parenBossList * itsBoss;
};

/********************************************************************/

/* planarPocketBottomCondition

This is a class for the single definition of planarPocketBottomCondition.
It represents the following items:

PLANARPOCKETBOTTOMCONDITION '(' ')'

*/

class planarPocketBottomCondition :
  public instance,
  public pocketBottomCondition
{
public:
  planarPocketBottomCondition();
  ~planarPocketBottomCondition();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* plusMinusValue

This is a class for the single definition of plusMinusValue.
It represents the following items:

PLUSMINUSVALUE '(' REALSTRING ',' REALSTRING ',' INTSTRING ')'

*/

class plusMinusValue :
  public instance,
  public toleranceSelect
{
public:
  plusMinusValue();
  plusMinusValue(
    double upperLimitIn,
    double lowerLimitIn,
    int significantDigitsIn);
  ~plusMinusValue();
  int isA(int aType);
  void printSelf();
  double upperLimit;
  double lowerLimit;
  int significantDigits;
};

/********************************************************************/

/* pocket

This is a parent class.

*/

class pocket :
  public machiningFeature
{
public:
  pocket();
  pocket(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    parenBossList * itsBossIn,
    real * slopeIn,
    pocketBottomCondition * bottomConditionIn,
    tolerancedLengthMeasure * planarRadiusIn,
    tolerancedLengthMeasure * orthogonalRadiusIn);
  ~pocket();
  int isA(int aType);
  void printSelf() = 0;
  parenBossList * itsBoss;
  real * slope;
  pocketBottomCondition * bottomCondition;
  tolerancedLengthMeasure * planarRadius;
  tolerancedLengthMeasure * orthogonalRadius;
};

/********************************************************************/

/* point

This is a parent class.

*/

class point :
  public geometricRepresentationItem
{
public:
  point();
  point(
    char * nameIn);
  ~point();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* profileFeature

This is a parent class.

*/

class profileFeature :
  public machiningFeature
{
public:
  profileFeature();
  profileFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * profileSweptShapeIn);
  ~profileFeature();
  int isA(int aType);
  void printSelf() = 0;
  linearPath * profileSweptShape;
};

/********************************************************************/

/* profileFloor

This is a parent class.

*/

class profileFloor :
  public profileSelect
{
public:
  profileFloor();
  profileFloor(
    real * floorRadiusIn,
    boolean * startOrEndIn);
  ~profileFloor();
  int isA(int aType);
  void printSelf() = 0;
  real * floorRadius;
  boolean * startOrEnd;
};

/********************************************************************/

/* radiusedSlotEndType

This is a class for the single definition of radiusedSlotEndType.
It represents the following items:

RADIUSEDSLOTENDTYPE '(' ')'

*/

class radiusedSlotEndType :
  public instance,
  public slotEndType
{
public:
  radiusedSlotEndType();
  ~radiusedSlotEndType();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* rapidMovement

This is a class for the single definition of rapidMovement.
It represents the following items:

RAPIDMOVEMENT '(' CHARSTRING ',' elementarySurface ',' optToolpathList ',' optToolDirection ')'

*/

class rapidMovement :
  public instance,
  public operation,
  public workingstep
{
public:
  rapidMovement();
  rapidMovement(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn);
  ~rapidMovement();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* real

This is a class for the single definition of real.
It represents the following items:

REALSTRING

*/

class real :
  public toolpathSpeedprofile,
  public trimmingSelect
{
public:
  real();
  real(
    double valIn);
  ~real();
  int isA(int aType);
  void printSelf();
  double val;
};

/********************************************************************/

/* reamer

This is a parent class.

*/

class reamer :
  public millingToolBody
{
public:
  reamer();
  reamer(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~reamer();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* rectangularClosedProfile

This is a class for the single definition of rectangularClosedProfile.
It represents the following items:

RECTANGULARCLOSEDPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' tolerancedLengthMeasure ')'

*/

class rectangularClosedProfile :
  public instance,
  public closedProfile
{
public:
  rectangularClosedProfile();
  rectangularClosedProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * profileWidthIn,
    tolerancedLengthMeasure * profileLengthIn);
  ~rectangularClosedProfile();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * profileWidth;
  tolerancedLengthMeasure * profileLength;
};

/********************************************************************/

/* replicateFeature

This is a parent class.

*/

class replicateFeature :
  public two5DmanufacturingFeature
{
public:
  replicateFeature();
  replicateFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    two5DmanufacturingFeature * replicateBaseFeatureIn);
  ~replicateFeature();
  int isA(int aType);
  void printSelf() = 0;
  two5DmanufacturingFeature * replicateBaseFeature;
};

/********************************************************************/

/* rightCircularCylinder

This is a class for the single definition of rightCircularCylinder.
It represents the following items:

RIGHTCIRCULARCYLINDER '(' CHARSTRING ',' axis1placement ',' REALSTRING ',' REALSTRING ')'

*/

class rightCircularCylinder :
  public instance,
  public boundingGeometrySelect,
  public geometricRepresentationItem
{
public:
  rightCircularCylinder();
  rightCircularCylinder(
    char * nameIn,
    axis1placement * positionIn,
    double heightIn,
    double radiusIn);
  ~rightCircularCylinder();
  int isA(int aType);
  void printSelf();
  axis1placement * position;
  double height;
  double radius;
};

/********************************************************************/

/* roundedEnd

This is a class for the single definition of roundedEnd.
It represents the following items:

ROUNDEDEND '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' partialCircularProfile ')'

*/

class roundedEnd :
  public instance,
  public machiningFeature
{
public:
  roundedEnd();
  roundedEnd(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * courseOfTravelIn,
    partialCircularProfile * partialCircularBoundaryIn);
  ~roundedEnd();
  int isA(int aType);
  void printSelf();
  linearPath * courseOfTravel;
  partialCircularProfile * partialCircularBoundary;
};

/********************************************************************/

/* roundedUProfile

This is a class for the single definition of roundedUProfile.
It represents the following items:

ROUNDEDUPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ')'

*/

class roundedUProfile :
  public instance,
  public openProfile
{
public:
  roundedUProfile();
  roundedUProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * widthIn);
  ~roundedUProfile();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * width;
};

/********************************************************************/

/* roundHole

This is a class for the single definition of roundHole.
It represents the following items:

ROUNDHOLE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' tolerancedLengthMeasure ',' optTaperSelect ',' holeBottomCondition ')'

*/

class roundHole :
  public instance,
  public machiningFeature
{
public:
  roundHole();
  roundHole(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    tolerancedLengthMeasure * diameterIn,
    taperSelect * changeInDiameterIn,
    holeBottomCondition * bottomConditionIn);
  ~roundHole();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * diameter;
  taperSelect * changeInDiameter;
  holeBottomCondition * bottomCondition;
};

/********************************************************************/

/* shapeProfile

This is a parent class.

*/

class shapeProfile :
  public profileFeature
{
public:
  shapeProfile();
  shapeProfile(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * profileSweptShapeIn,
    profileSelect * floorConditionIn,
    direction * removalDirectionIn);
  ~shapeProfile();
  int isA(int aType);
  void printSelf() = 0;
  profileSelect * floorCondition;
  direction * removalDirection;
};

/********************************************************************/

/* slot

This is a class for the single definition of slot.
It represents the following items:

SLOT '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' travelPath ',' openProfile ',' parenSlotEndTypeList ')'

*/

class slot :
  public instance,
  public machiningFeature
{
public:
  slot();
  slot(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    travelPath * courseOfTravelIn,
    openProfile * sweptShapeIn,
    parenSlotEndTypeList * endConditionsIn);
  ~slot();
  int isA(int aType);
  void printSelf();
  travelPath * courseOfTravel;
  openProfile * sweptShape;
  parenSlotEndTypeList * endConditions;
};

/********************************************************************/

/* solidModel

This is a parent class.

*/

class solidModel :
  public geometricRepresentationItem
{
public:
  solidModel();
  solidModel(
    char * nameIn);
  ~solidModel();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* speedName

This is a class for the single definition of speedName.
It represents the following items:

SPEEDNAMERAPID

*/

class speedName :
  public toolpathSpeedprofile
{
public:
  speedName();
  ~speedName();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* sphericalCap

This is a class for the single definition of sphericalCap.
It represents the following items:

SPHERICALCAP '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' numericParameter ',' numericParameter ')'

*/

class sphericalCap :
  public instance,
  public machiningFeature
{
public:
  sphericalCap();
  sphericalCap(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    numericParameter * internalAngleIn,
    numericParameter * radiusIn);
  ~sphericalCap();
  int isA(int aType);
  void printSelf();
  numericParameter * internalAngle;
  numericParameter * radius;
};

/********************************************************************/

/* sphericalHoleBottom

This is a class for the single definition of sphericalHoleBottom.
It represents the following items:

SPHERICALHOLEBOTTOM '(' tolerancedLengthMeasure ')'

*/

class sphericalHoleBottom :
  public instance,
  public blindBottomCondition
{
public:
  sphericalHoleBottom();
  sphericalHoleBottom(
    tolerancedLengthMeasure * radiusIn);
  ~sphericalHoleBottom();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * radius;
};

/********************************************************************/

/* squareUProfile

This is a class for the single definition of squareUProfile.
It represents the following items:

SQUAREUPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' tolerancedLengthMeasure ',' REALSTRING ',' tolerancedLengthMeasure ',' REALSTRING ')'

*/

class squareUProfile :
  public instance,
  public openProfile
{
public:
  squareUProfile();
  squareUProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * widthIn,
    tolerancedLengthMeasure * firstRadiusIn,
    double firstAngleIn,
    tolerancedLengthMeasure * secondRadiusIn,
    double secondAngleIn);
  ~squareUProfile();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * width;
  tolerancedLengthMeasure * firstRadius;
  double firstAngle;
  tolerancedLengthMeasure * secondRadius;
  double secondAngle;
};

/********************************************************************/

/* step

This is a class for the single definition of step.
It represents the following items:

STEP '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' optVeeProfile ',' parenBossList ')'

*/

class step :
  public instance,
  public machiningFeature
{
public:
  step();
  step(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * openBoundaryIn,
    veeProfile * wallBoundaryIn,
    parenBossList * itsBossIn);
  ~step();
  int isA(int aType);
  void printSelf();
  linearPath * openBoundary;
  veeProfile * wallBoundary;
  parenBossList * itsBoss;
};

/********************************************************************/

/* surface

This is a parent class.

*/

class surface :
  public geometricRepresentationItem
{
public:
  surface();
  surface(
    char * nameIn);
  ~surface();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* sweptSurface

This is a parent class.

*/

class sweptSurface :
  public surface
{
public:
  sweptSurface();
  sweptSurface(
    char * nameIn,
    curve * sweptCurveIn);
  ~sweptSurface();
  int isA(int aType);
  void printSelf() = 0;
  curve * sweptCurve;
};

/********************************************************************/

/* tapParent

This is a parent class.

*/

class tapParent :
  public millingToolBody
{
public:
  tapParent();
  tapParent(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~tapParent();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* taperedReamer

This is a class for the single definition of taperedReamer.
It represents the following items:

TAPEREDREAMER '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class taperedReamer :
  public instance,
  public reamer
{
public:
  taperedReamer();
  taperedReamer(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * taperAngleIn);
  ~taperedReamer();
  int isA(int aType);
  void printSelf();
  real * taperAngle;
};

/********************************************************************/

/* teeProfile

This is a class for the single definition of teeProfile.
It represents the following items:

TEEPROFILE '(' optAxis2placement3d REALSTRING REALSTRING tolerancedLengthMeasure tolerancedLengthMeasure tolerancedLengthMeasure tolerancedLengthMeasure tolerancedLengthMeasure tolerancedLengthMeasure ')'

*/

class teeProfile :
  public instance,
  public openProfile
{
public:
  teeProfile();
  teeProfile(
    axis2placement3d * placementIn,
    double firstAngleIn,
    double secondAngleIn,
    tolerancedLengthMeasure * crossBarWidthIn,
    tolerancedLengthMeasure * crossBarDepthIn,
    tolerancedLengthMeasure * radiusIn,
    tolerancedLengthMeasure * widthIn,
    tolerancedLengthMeasure * firstOffsetIn,
    tolerancedLengthMeasure * secondOffsetIn);
  ~teeProfile();
  int isA(int aType);
  void printSelf();
  double firstAngle;
  double secondAngle;
  tolerancedLengthMeasure * crossBarWidth;
  tolerancedLengthMeasure * crossBarDepth;
  tolerancedLengthMeasure * radius;
  tolerancedLengthMeasure * width;
  tolerancedLengthMeasure * firstOffset;
  tolerancedLengthMeasure * secondOffset;
};

/********************************************************************/

/* thread

This is a parent class.

*/

class thread :
  public machiningFeature
{
public:
  thread();
  thread(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    partialAreaDefinition * partialProfileIn,
    parenMachiningFeatureListFull * appliedShapeIn,
    boolean * innerOrOuterThreadIn,
    descriptiveParameter * qualifierIn,
    descriptiveParameter * fitClassIn,
    descriptiveParameter * formIn,
    double majorDiameterIn,
    numericParameter * numberOfThreadsIn,
    descriptiveParameter * threadHandIn);
  ~thread();
  int isA(int aType);
  void printSelf() = 0;
  partialAreaDefinition * partialProfile;
  parenMachiningFeatureListFull * appliedShape;
  boolean * innerOrOuterThread;
  descriptiveParameter * qualifier;
  descriptiveParameter * fitClass;
  descriptiveParameter * form;
  double majorDiameter;
  numericParameter * numberOfThreads;
  descriptiveParameter * threadHand;
};

/********************************************************************/

/* threeAxes

This is a class for the single definition of threeAxes.
It represents the following items:

THREEAXES '(' ')'

*/

class threeAxes :
  public instance,
  public toolDirection
{
public:
  threeAxes();
  ~threeAxes();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* threeAxesTiltedTool

This is a class for the single definition of threeAxesTiltedTool.
It represents the following items:

THREEAXESTILTEDTOOL '(' direction ')'

*/

class threeAxesTiltedTool :
  public instance,
  public toolDirectionForMilling
{
public:
  threeAxesTiltedTool();
  threeAxesTiltedTool(
    direction * itsToolDirectionIn);
  ~threeAxesTiltedTool();
  int isA(int aType);
  void printSelf();
  direction * itsToolDirection;
};

/********************************************************************/

/* toolpathFeature

This is a class for the single definition of toolpathFeature.
It represents the following items:

TOOLPATHFEATURE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ')'

*/

class toolpathFeature :
  public instance,
  public machiningFeature
{
public:
  toolpathFeature();
  toolpathFeature(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn);
  ~toolpathFeature();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolpathSpeed

This is a class for the single definition of toolpathSpeed.
It represents the following items:

TOOLPATHSPEED '(' bSplineCurve ')'

*/

class toolpathSpeed :
  public instance,
  public toolpathSpeedprofile
{
public:
  toolpathSpeed();
  toolpathSpeed(
    bSplineCurve * speedIn);
  ~toolpathSpeed();
  int isA(int aType);
  void printSelf();
  bSplineCurve * speed;
};

/********************************************************************/

/* topologicalRegion

This is a class for the single definition of topologicalRegion.
It represents the following items:

TOPOLOGICALREGION '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' optAxis2placement3d ',' CHARSTRING ',' parenFaceListFull ')'

*/

class topologicalRegion :
  public instance,
  public openShellParent,
  public region
{
public:
  topologicalRegion();
  topologicalRegion(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    char * nameIn,
    parenFaceListFull * cfsFacesIn);
  ~topologicalRegion();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* touchProbing

This is a parent class.

*/

class touchProbing :
  public operation,
  public workingstep
{
public:
  touchProbing();
  touchProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn);
  ~touchProbing();
  int isA(int aType);
  void printSelf() = 0;
  ncVariable * measuredOffset;
};

/********************************************************************/

/* two5DmillingOperation

This is a parent class.

*/

class two5DmillingOperation :
  public millingTypeOperation
{
public:
  two5DmillingOperation();
  two5DmillingOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn);
  ~two5DmillingOperation();
  int isA(int aType);
  void printSelf() = 0;
  two5DmillingStrategy * itsMachiningStrategy;
};

/********************************************************************/

/* userDefinedTool

This is a class for the single definition of userDefinedTool.
It represents the following items:

USERDEFINEDTOOL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' CHARSTRING ')'

*/

class userDefinedTool :
  public instance,
  public millingToolBody
{
public:
  userDefinedTool();
  userDefinedTool(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    char * identifierIn);
  ~userDefinedTool();
  int isA(int aType);
  void printSelf();
  char * identifier;
};

/********************************************************************/

/* vector

This is a class for the single definition of vector.
It represents the following items:

VECTOR '(' CHARSTRING ',' direction ',' REALSTRING ')'

*/

class vector :
  public instance,
  public geometricRepresentationItem
{
public:
  vector();
  vector(
    char * nameIn,
    direction * orientationIn,
    double magnitudeIn);
  ~vector();
  int isA(int aType);
  void printSelf();
  direction * orientation;
  double magnitude;
};

/********************************************************************/

/* veeProfile

This is a class for the single definition of veeProfile.
It represents the following items:

VEEPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ',' REALSTRING ',' REALSTRING ')'

*/

class veeProfile :
  public instance,
  public openProfile
{
public:
  veeProfile();
  veeProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * profileRadiusIn,
    double profileAngleIn,
    double tiltAngleIn);
  ~veeProfile();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * profileRadius;
  double profileAngle;
  double tiltAngle;
};

/********************************************************************/

/* vertexLoop

This is a class for the single definition of vertexLoop.
It represents the following items:

VERTEXLOOP '(' CHARSTRING ',' vertex ')'

*/

class vertexLoop :
  public instance,
  public loop
{
public:
  vertexLoop();
  vertexLoop(
    char * nameIn,
    vertex * loopVertexIn);
  ~vertexLoop();
  int isA(int aType);
  void printSelf();
  vertex * loopVertex;
};

/********************************************************************/

/* workpieceCompleteProbing

This is a class for the single definition of workpieceCompleteProbing.
It represents the following items:

WORKPIECECOMPLETEPROBING '(' CHARSTRING ',' elementarySurface ',' optToolpathList ',' optToolDirection ',' ncVariable ',' workpiece ',' tolerancedLengthMeasure ',' touchProbe ',' offsetVector ')'

*/

class workpieceCompleteProbing :
  public instance,
  public touchProbing
{
public:
  workpieceCompleteProbing();
  workpieceCompleteProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn,
    workpiece * itsWorkpieceIn,
    tolerancedLengthMeasure * probingDistanceIn,
    touchProbe * itsProbeIn,
    offsetVector * computedOffsetIn);
  ~workpieceCompleteProbing();
  int isA(int aType);
  void printSelf();
  workpiece * itsWorkpiece;
  tolerancedLengthMeasure * probingDistance;
  touchProbe * itsProbe;
  offsetVector * computedOffset;
};

/********************************************************************/

/* workpieceProbing

This is a class for the single definition of workpieceProbing.
It represents the following items:

WORKPIECEPROBING '(' CHARSTRING ',' elementarySurface ',' optToolpathList ',' optToolDirection ',' ncVariable ',' axis2placement3d ',' workpiece ',' direction ',' tolerancedLengthMeasure ',' touchProbe ')'

*/

class workpieceProbing :
  public instance,
  public touchProbing
{
public:
  workpieceProbing();
  workpieceProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn,
    axis2placement3d * startPositionIn,
    workpiece * itsWorkpieceIn,
    direction * itsDirectionIn,
    tolerancedLengthMeasure * expectedValueIn,
    touchProbe * itsProbeIn);
  ~workpieceProbing();
  int isA(int aType);
  void printSelf();
  axis2placement3d * startPosition;
  workpiece * itsWorkpiece;
  direction * itsDirection;
  tolerancedLengthMeasure * expectedValue;
  touchProbe * itsProbe;
};

/********************************************************************/

/* xorExpression

This is a class for the single definition of xorExpression.
It represents the following items:

XOREXPRESSION '(' booleanExpression ',' booleanExpression ')'

*/

class xorExpression :
  public instance,
  public binaryBooleanExpression
{
public:
  xorExpression();
  xorExpression(
    booleanExpression * operand1In,
    booleanExpression * operand2In);
  ~xorExpression();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* advancedBrepShapeRepresentation

This is a class for the single definition of advancedBrepShapeRepresentation.
It represents the following items:

ADVANCEDBREPSHAPEREPRESENTATION '(' CHARSTRING ',' parenRepresentationItemListFull ',' representationContext ')'

*/

class advancedBrepShapeRepresentation :
  public instance,
  public boundingGeometrySelect,
  public shapeRepresentationParent
{
public:
  advancedBrepShapeRepresentation();
  advancedBrepShapeRepresentation(
    char * nameIn,
    parenRepresentationItemListFull * itemsIn,
    representationContext * contextOfItemsIn);
  ~advancedBrepShapeRepresentation();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* advancedFace

This is a class for the single definition of advancedFace.
It represents the following items:

ADVANCEDFACE '(' CHARSTRING ',' parenFaceBoundListFull ',' surface ',' boolean ')'

*/

class advancedFace :
  public instance,
  public faceSurface
{
public:
  advancedFace();
  advancedFace(
    char * nameIn,
    parenFaceBoundListFull * boundsIn,
    surface * faceGeometryIn,
    boolean * sameSenseIn);
  ~advancedFace();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* approachLiftPath

This is a parent class.

*/

class approachLiftPath :
  public parameterisedPath
{
public:
  approachLiftPath();
  approachLiftPath(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    cartesianPoint * fixPointIn,
    direction * fixPointDirIn);
  ~approachLiftPath();
  int isA(int aType);
  void printSelf() = 0;
  cartesianPoint * fixPoint;
  direction * fixPointDir;
};

/********************************************************************/

/* axis1placement

This is a class for the single definition of axis1placement.
It represents the following items:

AXIS1PLACEMENT '(' CHARSTRING ',' cartesianPoint ',' direction ')'

*/

class axis1placement :
  public instance,
  public placement
{
public:
  axis1placement();
  axis1placement(
    char * nameIn,
    cartesianPoint * locationIn,
    direction * axisIn);
  ~axis1placement();
  int isA(int aType);
  void printSelf();
  direction * axis;
};

/********************************************************************/

/* axis2placement3d

This is a class for the single definition of axis2placement3d.
It represents the following items:

AXIS2PLACEMENT3D '(' CHARSTRING ',' cartesianPoint ',' direction ',' optDirection ')'

*/

class axis2placement3d :
  public instance,
  public placement
{
public:
  axis2placement3d();
  axis2placement3d(
    char * nameIn,
    cartesianPoint * locationIn,
    direction * axisIn,
    direction * refDirectionIn);
  ~axis2placement3d();
  int isA(int aType);
  void printSelf();
  direction * axis;
  direction * refDirection;
};

/********************************************************************/

/* block

This is a class for the single definition of block.
It represents the following items:

BLOCK '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ',' REALSTRING ',' REALSTRING ')'

*/

class block :
  public instance,
  public boundingGeometrySelect,
  public geometricRepresentationItem
{
public:
  block();
  block(
    char * nameIn,
    axis2placement3d * positionIn,
    double xIn,
    double yIn,
    double zIn);
  ~block();
  int isA(int aType);
  void printSelf();
  axis2placement3d * position;
  double x;
  double y;
  double z;
};

/********************************************************************/

/* boringTool

This is a class for the single definition of boringTool.
It represents the following items:

BORINGTOOL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class boringTool :
  public instance,
  public millingToolBody
{
public:
  boringTool();
  boringTool(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~boringTool();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* boss

This is a class for the single definition of boss.
It represents the following items:

BOSS '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' closedProfile ',' optReal ')'

*/

class boss :
  public instance,
  public machiningFeature
{
public:
  boss();
  boss(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    closedProfile * itsBoundaryIn,
    real * slopeIn);
  ~boss();
  int isA(int aType);
  void printSelf();
  closedProfile * itsBoundary;
  real * slope;
};

/********************************************************************/

/* bottomAndSideMilling

This is a parent class.

*/

class bottomAndSideMilling :
  public two5DmillingOperation
{
public:
  bottomAndSideMilling();
  bottomAndSideMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn,
    real * allowanceBottomIn);
  ~bottomAndSideMilling();
  int isA(int aType);
  void printSelf() = 0;
  real * axialCuttingDepth;
  real * radialCuttingDepth;
  real * allowanceSide;
  real * allowanceBottom;
};

/********************************************************************/

/* bottomAndSideRoughMilling

This is a class for the single definition of bottomAndSideRoughMilling.
It represents the following items:

BOTTOMANDSIDEROUGHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ',' optReal ',' optReal ')'

*/

class bottomAndSideRoughMilling :
  public instance,
  public bottomAndSideMilling
{
public:
  bottomAndSideRoughMilling();
  bottomAndSideRoughMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn,
    real * allowanceBottomIn);
  ~bottomAndSideRoughMilling();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* boundedSurface

This is a parent class.

*/

class boundedSurface :
  public surface
{
public:
  boundedSurface();
  boundedSurface(
    char * nameIn);
  ~boundedSurface();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* bSplineSurface

This is a parent class.

*/

class bSplineSurface :
  public boundedSurface
{
public:
  bSplineSurface();
  bSplineSurface(
    char * nameIn,
    integer * uDegreeIn,
    integer * vDegreeIn,
    parenParenCartesianPointListFullListFull * controlPointsListIn,
    bSplineSurfaceForm * surfaceFormIn,
    logical * uClosedIn,
    logical * vClosedIn,
    logical * selfIntersectIn);
  ~bSplineSurface();
  int isA(int aType);
  void printSelf() = 0;
  integer * uDegree;
  integer * vDegree;
  parenParenCartesianPointListFullListFull * controlPointsList;
  bSplineSurfaceForm * surfaceForm;
  logical * uClosed;
  logical * vClosed;
  logical * selfIntersect;
};

/********************************************************************/

/* bSplineSurfaceWithKnots

This is a class for the single definition of bSplineSurfaceWithKnots.
It represents the following items:

BSPLINESURFACEWITHKNOTS '(' CHARSTRING ',' integer ',' integer ',' parenParenCartesianPointListFullListFull ',' bSplineSurfaceForm ',' logical ',' logical ',' logical ',' parenIntegerListFull ',' parenIntegerListFull ',' parenRealListFull ',' parenRealListFull ',' knotType ')'

*/

class bSplineSurfaceWithKnots :
  public instance,
  public bSplineSurface
{
public:
  bSplineSurfaceWithKnots();
  bSplineSurfaceWithKnots(
    char * nameIn,
    integer * uDegreeIn,
    integer * vDegreeIn,
    parenParenCartesianPointListFullListFull * controlPointsListIn,
    bSplineSurfaceForm * surfaceFormIn,
    logical * uClosedIn,
    logical * vClosedIn,
    logical * selfIntersectIn,
    parenIntegerListFull * uMultiplicitiesIn,
    parenIntegerListFull * vMultiplicitiesIn,
    parenRealListFull * uKnotsIn,
    parenRealListFull * vKnotsIn,
    knotType * knotSpecIn);
  ~bSplineSurfaceWithKnots();
  int isA(int aType);
  void printSelf();
  parenIntegerListFull * uMultiplicities;
  parenIntegerListFull * vMultiplicities;
  parenRealListFull * uKnots;
  parenRealListFull * vKnots;
  knotType * knotSpec;
};

/********************************************************************/

/* cartesianPoint

This is a class for the single definition of cartesianPoint.
It represents the following items:

CARTESIANPOINT '(' CHARSTRING ',' parenRealListFull ')'

*/

class cartesianPoint :
  public instance,
  public point,
  public trimmingSelect
{
public:
  cartesianPoint();
  cartesianPoint(
    char * nameIn,
    parenRealListFull * coordinatesIn);
  ~cartesianPoint();
  int isA(int aType);
  void printSelf();
  parenRealListFull * coordinates;
};

/********************************************************************/

/* catalogueThread

This is a class for the single definition of catalogueThread.
It represents the following items:

CATALOGUETHREAD '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' partialAreaDefinition ',' parenMachiningFeatureListFull ',' boolean ',' optDescriptiveParameter ',' descriptiveParameter ',' descriptiveParameter ',' REALSTRING ',' numericParameter ',' descriptiveParameter ',' specification ')'

*/

class catalogueThread :
  public instance,
  public thread
{
public:
  catalogueThread();
  catalogueThread(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    partialAreaDefinition * partialProfileIn,
    parenMachiningFeatureListFull * appliedShapeIn,
    boolean * innerOrOuterThreadIn,
    descriptiveParameter * qualifierIn,
    descriptiveParameter * fitClassIn,
    descriptiveParameter * formIn,
    double majorDiameterIn,
    numericParameter * numberOfThreadsIn,
    descriptiveParameter * threadHandIn,
    specification * documentationIn);
  ~catalogueThread();
  int isA(int aType);
  void printSelf();
  specification * documentation;
};

/********************************************************************/

/* centerDrill

This is a class for the single definition of centerDrill.
It represents the following items:

CENTERDRILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class centerDrill :
  public instance,
  public millingToolBody
{
public:
  centerDrill();
  centerDrill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~centerDrill();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* circularClosedProfile

This is a class for the single definition of circularClosedProfile.
It represents the following items:

CIRCULARCLOSEDPROFILE '(' optAxis2placement3d ',' tolerancedLengthMeasure ')'

*/

class circularClosedProfile :
  public instance,
  public closedProfile
{
public:
  circularClosedProfile();
  circularClosedProfile(
    axis2placement3d * placementIn,
    tolerancedLengthMeasure * diameterIn);
  ~circularClosedProfile();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * diameter;
};

/********************************************************************/

/* circularClosedShapeProfile

This is a class for the single definition of circularClosedShapeProfile.
It represents the following items:

CIRCULARCLOSEDSHAPEPROFILE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' profileSelect ',' direction ',' circularClosedProfile ')'

*/

class circularClosedShapeProfile :
  public instance,
  public shapeProfile
{
public:
  circularClosedShapeProfile();
  circularClosedShapeProfile(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * profileSweptShapeIn,
    profileSelect * floorConditionIn,
    direction * removalDirectionIn,
    circularClosedProfile * closedBoundaryIn);
  ~circularClosedShapeProfile();
  int isA(int aType);
  void printSelf();
  circularClosedProfile * closedBoundary;
};

/********************************************************************/

/* circularPattern

This is a class for the single definition of circularPattern.
It represents the following items:

CIRCULARPATTERN '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' two5DmanufacturingFeature ',' REALSTRING ',' INTSTRING ',' parenCircularOffsetList ',' parenCircularOmitList ',' optTolerancedLengthMeasure ',' REALSTRING ')'

*/

class circularPattern :
  public instance,
  public replicateFeature
{
public:
  circularPattern();
  circularPattern(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    two5DmanufacturingFeature * replicateBaseFeatureIn,
    double angleIncrementIn,
    int numberOfFeatureIn,
    parenCircularOffsetList * relocatedBaseFeatureIn,
    parenCircularOmitList * missingBaseFeatureIn,
    tolerancedLengthMeasure * baseFeatureDiameterIn,
    double baseFeatureRotationIn);
  ~circularPattern();
  int isA(int aType);
  void printSelf();
  double angleIncrement;
  int numberOfFeature;
  parenCircularOffsetList * relocatedBaseFeature;
  parenCircularOmitList * missingBaseFeature;
  tolerancedLengthMeasure * baseFeatureDiameter;
  double baseFeatureRotation;
};

/********************************************************************/

/* closedPocket

This is a class for the single definition of closedPocket.
It represents the following items:

CLOSEDPOCKET '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' parenBossList ',' optReal ',' pocketBottomCondition ',' optTolerancedLengthMeasure ',' optTolerancedLengthMeasure ',' closedProfile ')'

*/

class closedPocket :
  public instance,
  public pocket
{
public:
  closedPocket();
  closedPocket(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    parenBossList * itsBossIn,
    real * slopeIn,
    pocketBottomCondition * bottomConditionIn,
    tolerancedLengthMeasure * planarRadiusIn,
    tolerancedLengthMeasure * orthogonalRadiusIn,
    closedProfile * featureBoundaryIn);
  ~closedPocket();
  int isA(int aType);
  void printSelf();
  closedProfile * featureBoundary;
};

/********************************************************************/

/* closedShell

This is a class for the single definition of closedShell.
It represents the following items:

CLOSEDSHELL '(' CHARSTRING ',' parenFaceListFull ')'

*/

class closedShell :
  public instance,
  public connectedFaceSet
{
public:
  closedShell();
  closedShell(
    char * nameIn,
    parenFaceListFull * cfsFacesIn);
  ~closedShell();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* combinedDrillAndReamer

This is a class for the single definition of combinedDrillAndReamer.
It represents the following items:

COMBINEDDRILLANDREAMER '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class combinedDrillAndReamer :
  public instance,
  public reamer
{
public:
  combinedDrillAndReamer();
  combinedDrillAndReamer(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * drillLengthIn);
  ~combinedDrillAndReamer();
  int isA(int aType);
  void printSelf();
  real * drillLength;
};

/********************************************************************/

/* combinedDrillAndTap

This is a class for the single definition of combinedDrillAndTap.
It represents the following items:

COMBINEDDRILLANDTAP '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal optReal ')'

*/

class combinedDrillAndTap :
  public instance,
  public tapParent
{
public:
  combinedDrillAndTap();
  combinedDrillAndTap(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * drillLengthIn);
  ~combinedDrillAndTap();
  int isA(int aType);
  void printSelf();
  real * drillLength;
};

/********************************************************************/

/* connector

This is a parent class.

*/

class connector :
  public parameterisedPath
{
public:
  connector();
  connector(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn);
  ~connector();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* connectSecplane

This is a class for the single definition of connectSecplane.
It represents the following items:

CONNECTSECPLANE '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ',' optDirection ',' optDirection ')'

*/

class connectSecplane :
  public instance,
  public connector
{
public:
  connectSecplane();
  connectSecplane(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    direction * upDirIn,
    direction * downDirIn);
  ~connectSecplane();
  int isA(int aType);
  void printSelf();
  direction * upDir;
  direction * downDir;
};

/********************************************************************/

/* counterboreParent

This is a parent class.

*/

class counterboreParent :
  public millingToolBody
{
public:
  counterboreParent();
  counterboreParent(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~counterboreParent();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* countersinkParent

This is a parent class.

*/

class countersinkParent :
  public millingToolBody
{
public:
  countersinkParent();
  countersinkParent(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~countersinkParent();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* curve

This is a parent class.

*/

class curve :
  public geometricRepresentationItem
{
public:
  curve();
  curve(
    char * nameIn);
  ~curve();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* definedThread

This is a class for the single definition of definedThread.
It represents the following items:

DEFINEDTHREAD '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' partialAreaDefinition ',' parenMachiningFeatureListFull ',' boolean ',' optDescriptiveParameter ',' descriptiveParameter ',' descriptiveParameter ',' REALSTRING ',' numericParameter ',' descriptiveParameter ',' REALSTRING ',' optReal ',' optReal ')'

*/

class definedThread :
  public instance,
  public thread
{
public:
  definedThread();
  definedThread(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    partialAreaDefinition * partialProfileIn,
    parenMachiningFeatureListFull * appliedShapeIn,
    boolean * innerOrOuterThreadIn,
    descriptiveParameter * qualifierIn,
    descriptiveParameter * fitClassIn,
    descriptiveParameter * formIn,
    double majorDiameterIn,
    numericParameter * numberOfThreadsIn,
    descriptiveParameter * threadHandIn,
    double pitchDiameterIn,
    real * minorDiameterIn,
    real * crestIn);
  ~definedThread();
  int isA(int aType);
  void printSelf();
  double pitchDiameter;
  real * minorDiameter;
  real * crest;
};

/********************************************************************/

/* direction

This is a class for the single definition of direction.
It represents the following items:

DIRECTION '(' CHARSTRING ',' parenRealListFull ')'

*/

class direction :
  public instance,
  public geometricRepresentationItem
{
public:
  direction();
  direction(
    char * nameIn,
    parenRealListFull * directionRatiosIn);
  ~direction();
  int isA(int aType);
  void printSelf();
  parenRealListFull * directionRatios;
};

/********************************************************************/

/* drill

This is a parent class.

*/

class drill :
  public millingToolBody
{
public:
  drill();
  drill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~drill();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* drillingTypeOperation

This is a parent class.

*/

class drillingTypeOperation :
  public millingMachiningOperation
{
public:
  drillingTypeOperation();
  drillingTypeOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn);
  ~drillingTypeOperation();
  int isA(int aType);
  void printSelf() = 0;
  real * cuttingDepth;
  real * previousDiameter;
  real * dwellTimeBottom;
  real * feedOnRetract;
  drillingTypeStrategy * itsMachiningStrategy;
};

/********************************************************************/

/* edgeLoop

This is a class for the single definition of edgeLoop.
It represents the following items:

EDGELOOP '(' CHARSTRING ',' parenOrientedEdgeListFull ')'

*/

class edgeLoop :
  public instance,
  public loop
{
public:
  edgeLoop();
  edgeLoop(
    char * nameIn,
    parenOrientedEdgeListFull * edgeListIn);
  ~edgeLoop();
  int isA(int aType);
  void printSelf();
  parenOrientedEdgeListFull * edgeList;
};

/********************************************************************/

/* elementarySurface

This is a parent class.

*/

class elementarySurface :
  public surface
{
public:
  elementarySurface();
  elementarySurface(
    char * nameIn,
    axis2placement3d * positionIn);
  ~elementarySurface();
  int isA(int aType);
  void printSelf() = 0;
  axis2placement3d * position;
};

/********************************************************************/

/* freeformOperation

This is a class for the single definition of freeformOperation.
It represents the following items:

FREEFORMOPERATION '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optFreeformStrategy ')'

*/

class freeformOperation :
  public instance,
  public millingTypeOperation
{
public:
  freeformOperation();
  freeformOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    freeformStrategy * itsMachiningStrategyIn);
  ~freeformOperation();
  int isA(int aType);
  void printSelf();
  freeformStrategy * itsMachiningStrategy;
};

/********************************************************************/

/* generalOutsideProfile

This is a class for the single definition of generalOutsideProfile.
It represents the following items:

GENERALOUTSIDEPROFILE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' profile ')'

*/

class generalOutsideProfile :
  public instance,
  public profileFeature
{
public:
  generalOutsideProfile();
  generalOutsideProfile(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * profileSweptShapeIn,
    profile * featureBoundaryIn);
  ~generalOutsideProfile();
  int isA(int aType);
  void printSelf();
  profile * featureBoundary;
};

/********************************************************************/

/* generalPattern

This is a class for the single definition of generalPattern.
It represents the following items:

GENERALPATTERN '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' two5DmanufacturingFeature ',' parenAxis2placement3dListFull ')'

*/

class generalPattern :
  public instance,
  public replicateFeature
{
public:
  generalPattern();
  generalPattern(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    two5DmanufacturingFeature * replicateBaseFeatureIn,
    parenAxis2placement3dListFull * replicateLocationsIn);
  ~generalPattern();
  int isA(int aType);
  void printSelf();
  parenAxis2placement3dListFull * replicateLocations;
};

/********************************************************************/

/* generalProfile

This is a class for the single definition of generalProfile.
It represents the following items:

GENERALPROFILE '(' optAxis2placement3d ',' boundedCurve ')'

*/

class generalProfile :
  public instance,
  public openProfile
{
public:
  generalProfile();
  generalProfile(
    axis2placement3d * placementIn,
    boundedCurve * itsProfileIn);
  ~generalProfile();
  int isA(int aType);
  void printSelf();
  boundedCurve * itsProfile;
};

/********************************************************************/

/* generalProfileFloor

This is a class for the single definition of generalProfileFloor.
It represents the following items:

GENERALPROFILEFLOOR '(' optReal ',' boolean ',' face ')'

*/

class generalProfileFloor :
  public instance,
  public profileFloor
{
public:
  generalProfileFloor();
  generalProfileFloor(
    real * floorRadiusIn,
    boolean * startOrEndIn,
    face * floorIn);
  ~generalProfileFloor();
  int isA(int aType);
  void printSelf();
  face * floor;
};

/********************************************************************/

/* generalShapeProfile

This is a class for the single definition of generalShapeProfile.
It represents the following items:

GENERALSHAPEPROFILE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' profileSelect ',' direction ',' profile ')'

*/

class generalShapeProfile :
  public instance,
  public shapeProfile
{
public:
  generalShapeProfile();
  generalShapeProfile(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * profileSweptShapeIn,
    profileSelect * floorConditionIn,
    direction * removalDirectionIn,
    profile * profileBoundaryIn);
  ~generalShapeProfile();
  int isA(int aType);
  void printSelf();
  profile * profileBoundary;
};

/********************************************************************/

/* helix

This is a class for the single definition of helix.
It represents the following items:

HELIX '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ',' REALSTRING ')'

*/

class helix :
  public instance,
  public curve
{
public:
  helix();
  helix(
    char * nameIn,
    axis2placement3d * positionIn,
    double radiusIn,
    double pitchIn);
  ~helix();
  int isA(int aType);
  void printSelf();
  axis2placement3d * position;
  double radius;
  double pitch;
};

/********************************************************************/

/* line

This is a class for the single definition of line.
It represents the following items:

LINE '(' CHARSTRING ',' cartesianPoint ',' vector ')'

*/

class line :
  public instance,
  public curve
{
public:
  line();
  line(
    char * nameIn,
    cartesianPoint * pntIn,
    vector * dirIn);
  ~line();
  int isA(int aType);
  void printSelf();
  cartesianPoint * pnt;
  vector * dir;
};

/********************************************************************/

/* linearProfile

This is a class for the single definition of linearProfile.
It represents the following items:

LINEARPROFILE '(' optAxis2placement3d ',' numericParameter ')'

*/

class linearProfile :
  public instance,
  public openProfile
{
public:
  linearProfile();
  linearProfile(
    axis2placement3d * placementIn,
    numericParameter * profileLengthIn);
  ~linearProfile();
  int isA(int aType);
  void printSelf();
  numericParameter * profileLength;
};

/********************************************************************/

/* manifoldSolidBrep

This is a class for the single definition of manifoldSolidBrep.
It represents the following items:

MANIFOLDSOLIDBREP '(' CHARSTRING ',' closedShell ')'

*/

class manifoldSolidBrep :
  public instance,
  public solidModel
{
public:
  manifoldSolidBrep();
  manifoldSolidBrep(
    char * nameIn,
    closedShell * outerIn);
  ~manifoldSolidBrep();
  int isA(int aType);
  void printSelf();
  closedShell * outer;
};

/********************************************************************/

/* millingCutter

This is a parent class.

*/

class millingCutter :
  public millingToolBody
{
public:
  millingCutter();
  millingCutter(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~millingCutter();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* millingThreadingTool

This is a class for the single definition of millingThreadingTool.
It represents the following items:

MILLINGTHREADINGTOOL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class millingThreadingTool :
  public instance,
  public millingToolBody
{
public:
  millingThreadingTool();
  millingThreadingTool(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~millingThreadingTool();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* openPocket

This is a class for the single definition of openPocket.
It represents the following items:

OPENPOCKET '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' parenBossList ',' optReal ',' pocketBottomCondition ',' optTolerancedLengthMeasure ',' optTolerancedLengthMeasure ',' openProfile ',' optOpenProfile ')'

*/

class openPocket :
  public instance,
  public pocket
{
public:
  openPocket();
  openPocket(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    parenBossList * itsBossIn,
    real * slopeIn,
    pocketBottomCondition * bottomConditionIn,
    tolerancedLengthMeasure * planarRadiusIn,
    tolerancedLengthMeasure * orthogonalRadiusIn,
    openProfile * openBoundaryIn,
    openProfile * wallBoundaryIn);
  ~openPocket();
  int isA(int aType);
  void printSelf();
  openProfile * openBoundary;
  openProfile * wallBoundary;
};

/********************************************************************/

/* partialCircularShapeProfile

This is a class for the single definition of partialCircularShapeProfile.
It represents the following items:

PARTIALCIRCULARSHAPEPROFILE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' profileSelect ',' direction ',' partialCircularProfile ')'

*/

class partialCircularShapeProfile :
  public instance,
  public shapeProfile
{
public:
  partialCircularShapeProfile();
  partialCircularShapeProfile(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * profileSweptShapeIn,
    profileSelect * floorConditionIn,
    direction * removalDirectionIn,
    partialCircularProfile * openBoundaryIn);
  ~partialCircularShapeProfile();
  int isA(int aType);
  void printSelf();
  partialCircularProfile * openBoundary;
};

/********************************************************************/

/* pcurveParent

This is a parent class.

*/

class pcurveParent :
  public curve
{
public:
  pcurveParent();
  pcurveParent(
    char * nameIn,
    surface * basisSurfaceIn,
    definitionalRepresentation * referenceToCurveIn);
  ~pcurveParent();
  int isA(int aType);
  void printSelf() = 0;
  surface * basisSurface;
  definitionalRepresentation * referenceToCurve;
};

/********************************************************************/

/* planarProfileFloor

This is a class for the single definition of planarProfileFloor.
It represents the following items:

PLANARPROFILEFLOOR '(' optReal ',' boolean ',' plane ')'

*/

class planarProfileFloor :
  public instance,
  public profileFloor
{
public:
  planarProfileFloor();
  planarProfileFloor(
    real * floorRadiusIn,
    boolean * startOrEndIn,
    plane * floorIn);
  ~planarProfileFloor();
  int isA(int aType);
  void printSelf();
  plane * floor;
};

/********************************************************************/

/* plane

This is a class for the single definition of plane.
It represents the following items:

PLANE '(' CHARSTRING ',' axis2placement3d ')'

*/

class plane :
  public instance,
  public elementarySurface
{
public:
  plane();
  plane(
    char * nameIn,
    axis2placement3d * positionIn);
  ~plane();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* planeMilling

This is a parent class.

*/

class planeMilling :
  public two5DmillingOperation
{
public:
  planeMilling();
  planeMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * allowanceBottomIn);
  ~planeMilling();
  int isA(int aType);
  void printSelf() = 0;
  real * axialCuttingDepth;
  real * allowanceBottom;
};

/********************************************************************/

/* planeRoughMilling

This is a class for the single definition of planeRoughMilling.
It represents the following items:

PLANEROUGHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ')'

*/

class planeRoughMilling :
  public instance,
  public planeMilling
{
public:
  planeRoughMilling();
  planeRoughMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * allowanceBottomIn);
  ~planeRoughMilling();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* quasiUniformSurface

This is a class for the single definition of quasiUniformSurface.
It represents the following items:

QUASIUNIFORMSURFACE '(' CHARSTRING ',' integer ',' integer ',' parenParenCartesianPointListFullListFull ',' bSplineSurfaceForm ',' logical ',' logical ',' logical ')'

*/

class quasiUniformSurface :
  public instance,
  public bSplineSurface
{
public:
  quasiUniformSurface();
  quasiUniformSurface(
    char * nameIn,
    integer * uDegreeIn,
    integer * vDegreeIn,
    parenParenCartesianPointListFullListFull * controlPointsListIn,
    bSplineSurfaceForm * surfaceFormIn,
    logical * uClosedIn,
    logical * vClosedIn,
    logical * selfIntersectIn);
  ~quasiUniformSurface();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* rationalBSplineSurface

This is a class for the single definition of rationalBSplineSurface.
It represents the following items:

RATIONALBSPLINESURFACE '(' CHARSTRING ',' integer ',' integer ',' parenParenCartesianPointListFullListFull ',' bSplineSurfaceForm ',' logical ',' logical ',' logical parenParenRealListFullListFull ')'

*/

class rationalBSplineSurface :
  public instance,
  public bSplineSurface
{
public:
  rationalBSplineSurface();
  rationalBSplineSurface(
    char * nameIn,
    integer * uDegreeIn,
    integer * vDegreeIn,
    parenParenCartesianPointListFullListFull * controlPointsListIn,
    bSplineSurfaceForm * surfaceFormIn,
    logical * uClosedIn,
    logical * vClosedIn,
    logical * selfIntersectIn,
    parenParenRealListFullListFull * weightsDataIn);
  ~rationalBSplineSurface();
  int isA(int aType);
  void printSelf();
  parenParenRealListFullListFull * weightsData;
};

/********************************************************************/

/* rectangularClosedShapeProfile

This is a class for the single definition of rectangularClosedShapeProfile.
It represents the following items:

RECTANGULARCLOSEDSHAPEPROFILE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' profileSelect ',' direction ',' rectangularClosedProfile ')'

*/

class rectangularClosedShapeProfile :
  public instance,
  public shapeProfile
{
public:
  rectangularClosedShapeProfile();
  rectangularClosedShapeProfile(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * profileSweptShapeIn,
    profileSelect * floorConditionIn,
    direction * removalDirectionIn,
    rectangularClosedProfile * closedBoundaryIn);
  ~rectangularClosedShapeProfile();
  int isA(int aType);
  void printSelf();
  rectangularClosedProfile * closedBoundary;
};

/********************************************************************/

/* rectangularOpenShapeProfile

This is a class for the single definition of rectangularOpenShapeProfile.
It represents the following items:

RECTANGULAROPENSHAPEPROFILE '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' elementarySurface ',' linearPath ',' profileSelect ',' direction ',' squareUProfile ')'

*/

class rectangularOpenShapeProfile :
  public instance,
  public shapeProfile
{
public:
  rectangularOpenShapeProfile();
  rectangularOpenShapeProfile(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    elementarySurface * depthIn,
    linearPath * profileSweptShapeIn,
    profileSelect * floorConditionIn,
    direction * removalDirectionIn,
    squareUProfile * openBoundaryIn);
  ~rectangularOpenShapeProfile();
  int isA(int aType);
  void printSelf();
  squareUProfile * openBoundary;
};

/********************************************************************/

/* rectangularPattern

This is a class for the single definition of rectangularPattern.
It represents the following items:

RECTANGULARPATTERN '(' CHARSTRING ',' workpiece ',' parenMachiningOperationList ',' axis2placement3d ',' two5DmanufacturingFeature tolerancedLengthMeasure ',' direction ',' optInteger ',' INTSTRING ',' optTolerancedLengthMeasure ',' optDirection ',' parenRectangularOffsetList ',' parenRectangularOmitList ')'

*/

class rectangularPattern :
  public instance,
  public replicateFeature
{
public:
  rectangularPattern();
  rectangularPattern(
    char * itsIdIn,
    workpiece * itsWorkpieceIn,
    parenMachiningOperationList * itsOperationsIn,
    axis2placement3d * featurePlacementIn,
    two5DmanufacturingFeature * replicateBaseFeatureIn,
    tolerancedLengthMeasure * spacingIn,
    direction * itsDirectionIn,
    integer * numberOfRowsIn,
    int numberOfColumnsIn,
    tolerancedLengthMeasure * rowSpacingIn,
    direction * rowLayoutDirectionIn,
    parenRectangularOffsetList * relocatedBaseFeatureIn,
    parenRectangularOmitList * missingBaseFeatureIn);
  ~rectangularPattern();
  int isA(int aType);
  void printSelf();
  tolerancedLengthMeasure * spacing;
  direction * itsDirection;
  integer * numberOfRows;
  int numberOfColumns;
  tolerancedLengthMeasure * rowSpacing;
  direction * rowLayoutDirection;
  parenRectangularOffsetList * relocatedBaseFeature;
  parenRectangularOmitList * missingBaseFeature;
};

/********************************************************************/

/* sideMill

This is a class for the single definition of sideMill.
It represents the following items:

SIDEMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class sideMill :
  public instance,
  public millingCutter
{
public:
  sideMill();
  sideMill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * lengthMeasureIn);
  ~sideMill();
  int isA(int aType);
  void printSelf();
  real * lengthMeasure;
};

/********************************************************************/

/* sideMilling

This is a parent class.

*/

class sideMilling :
  public two5DmillingOperation
{
public:
  sideMilling();
  sideMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn);
  ~sideMilling();
  int isA(int aType);
  void printSelf() = 0;
  real * axialCuttingDepth;
  real * radialCuttingDepth;
  real * allowanceSide;
};

/********************************************************************/

/* sideFinishMilling

This is a class for the single definition of sideFinishMilling.
It represents the following items:

SIDEFINISHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ',' optReal ')'

*/

class sideFinishMilling :
  public instance,
  public sideMilling
{
public:
  sideFinishMilling();
  sideFinishMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn);
  ~sideFinishMilling();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* sideRoughMilling

This is a class for the single definition of sideRoughMilling.
It represents the following items:

SIDEROUGHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ',' optReal ')'

*/

class sideRoughMilling :
  public instance,
  public sideMilling
{
public:
  sideRoughMilling();
  sideRoughMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn);
  ~sideRoughMilling();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* spadeDrill

This is a class for the single definition of spadeDrill.
It represents the following items:

SPADEDRILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class spadeDrill :
  public instance,
  public drill
{
public:
  spadeDrill();
  spadeDrill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~spadeDrill();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* sphericalSurface

This is a class for the single definition of sphericalSurface.
It represents the following items:

SPHERICALSURFACE '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ')'

*/

class sphericalSurface :
  public instance,
  public elementarySurface
{
public:
  sphericalSurface();
  sphericalSurface(
    char * nameIn,
    axis2placement3d * positionIn,
    double radiusIn);
  ~sphericalSurface();
  int isA(int aType);
  void printSelf();
  double radius;
};

/********************************************************************/

/* surfaceOfLinearExtrusion

This is a class for the single definition of surfaceOfLinearExtrusion.
It represents the following items:

SURFACEOFLINEAREXTRUSION '(' CHARSTRING ',' curve ',' vector ')'

*/

class surfaceOfLinearExtrusion :
  public instance,
  public sweptSurface
{
public:
  surfaceOfLinearExtrusion();
  surfaceOfLinearExtrusion(
    char * nameIn,
    curve * sweptCurveIn,
    vector * extrusionAxisIn);
  ~surfaceOfLinearExtrusion();
  int isA(int aType);
  void printSelf();
  vector * extrusionAxis;
};

/********************************************************************/

/* surfaceOfRevolution

This is a class for the single definition of surfaceOfRevolution.
It represents the following items:

SURFACEOFREVOLUTION '(' CHARSTRING ',' curve ',' axis1placement ')'

*/

class surfaceOfRevolution :
  public instance,
  public sweptSurface
{
public:
  surfaceOfRevolution();
  surfaceOfRevolution(
    char * nameIn,
    curve * sweptCurveIn,
    axis1placement * axisPositionIn);
  ~surfaceOfRevolution();
  int isA(int aType);
  void printSelf();
  axis1placement * axisPosition;
};

/********************************************************************/

/* tap

This is a class for the single definition of tap.
It represents the following items:

TAP '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class tap :
  public instance,
  public tapParent
{
public:
  tap();
  tap(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~tap();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* taperedTap

This is a class for the single definition of taperedTap.
It represents the following items:

TAPEREDTAP '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class taperedTap :
  public instance,
  public tapParent
{
public:
  taperedTap();
  taperedTap(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * taperAngleIn);
  ~taperedTap();
  int isA(int aType);
  void printSelf();
  real * taperAngle;
};

/********************************************************************/

/* tapping

This is a class for the single definition of tapping.
It represents the following items:

TAPPING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy boolean ')'

*/

class tapping :
  public instance,
  public drillingTypeOperation
{
public:
  tapping();
  tapping(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * compensationChuckIn);
  ~tapping();
  int isA(int aType);
  void printSelf();
  boolean * compensationChuck;
};

/********************************************************************/

/* threadDrilling

This is a class for the single definition of threadDrilling.
It represents the following items:

THREADDRILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy boolean ')'

*/

class threadDrilling :
  public instance,
  public drillingTypeOperation
{
public:
  threadDrilling();
  threadDrilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * helicalMovementOnForwardIn);
  ~threadDrilling();
  int isA(int aType);
  void printSelf();
  boolean * helicalMovementOnForward;
};

/********************************************************************/

/* threadMill

This is a class for the single definition of threadMill.
It represents the following items:

THREADMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class threadMill :
  public instance,
  public millingCutter
{
public:
  threadMill();
  threadMill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~threadMill();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* toolProbing

This is a parent class.

*/

class toolProbing :
  public touchProbing
{
public:
  toolProbing();
  toolProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn,
    cartesianPoint * offsetIn,
    double maxWearIn,
    machiningTool * itsToolIn);
  ~toolProbing();
  int isA(int aType);
  void printSelf() = 0;
  cartesianPoint * offset;
  double maxWear;
  machiningTool * itsTool;
};

/********************************************************************/

/* toolRadiusProbing

This is a class for the single definition of toolRadiusProbing.
It represents the following items:

TOOLRADIUSPROBING '(' CHARSTRING ',' elementarySurface ',' optToolpathList ',' optToolDirection ',' ncVariable ',' cartesianPoint ',' REALSTRING ',' machiningTool ')'

*/

class toolRadiusProbing :
  public instance,
  public toolProbing
{
public:
  toolRadiusProbing();
  toolRadiusProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn,
    cartesianPoint * offsetIn,
    double maxWearIn,
    machiningTool * itsToolIn);
  ~toolRadiusProbing();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* tSlotMill

This is a class for the single definition of tSlotMill.
It represents the following items:

TSLOTMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class tSlotMill :
  public instance,
  public millingCutter
{
public:
  tSlotMill();
  tSlotMill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * cuttingThicknessIn);
  ~tSlotMill();
  int isA(int aType);
  void printSelf();
  real * cuttingThickness;
};

/********************************************************************/

/* twistDrillParent

This is a parent class.

*/

class twistDrillParent :
  public drill
{
public:
  twistDrillParent();
  twistDrillParent(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~twistDrillParent();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* twistDrill

This is a class for the single definition of twistDrill.
It represents the following items:

TWISTDRILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class twistDrill :
  public instance,
  public twistDrillParent
{
public:
  twistDrill();
  twistDrill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~twistDrill();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* uniformSurface

This is a class for the single definition of uniformSurface.
It represents the following items:

UNIFORMSURFACE '(' CHARSTRING ',' integer ',' integer ',' parenParenCartesianPointListFullListFull ',' bSplineSurfaceForm ',' logical ',' logical ',' logical ')'

*/

class uniformSurface :
  public instance,
  public bSplineSurface
{
public:
  uniformSurface();
  uniformSurface(
    char * nameIn,
    integer * uDegreeIn,
    integer * vDegreeIn,
    parenParenCartesianPointListFullListFull * controlPointsListIn,
    bSplineSurfaceForm * surfaceFormIn,
    logical * uClosedIn,
    logical * vClosedIn,
    logical * selfIntersectIn);
  ~uniformSurface();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* woodruffKeyseatMill

This is a class for the single definition of woodruffKeyseatMill.
It represents the following items:

WOODRUFFKEYSEATMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class woodruffKeyseatMill :
  public instance,
  public millingCutter
{
public:
  woodruffKeyseatMill();
  woodruffKeyseatMill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * cutterWidthIn);
  ~woodruffKeyseatMill();
  int isA(int aType);
  void printSelf();
  real * cutterWidth;
};

/********************************************************************/

/* apLiftPathAngle

This is a class for the single definition of apLiftPathAngle.
It represents the following items:

APLIFTPATHANGLE '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ',' cartesianPoint ',' optDirection ',' REALSTRING ',' REALSTRING ')'

*/

class apLiftPathAngle :
  public instance,
  public approachLiftPath
{
public:
  apLiftPathAngle();
  apLiftPathAngle(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    cartesianPoint * fixPointIn,
    direction * fixPointDirIn,
    double angleIn,
    double benddistIn);
  ~apLiftPathAngle();
  int isA(int aType);
  void printSelf();
  double angle;
  double benddist;
};

/********************************************************************/

/* apLiftPathTangent

This is a class for the single definition of apLiftPathTangent.
It represents the following items:

APLIFTPATHTANGENT '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ',' cartesianPoint ',' optDirection ',' REALSTRING ')'

*/

class apLiftPathTangent :
  public instance,
  public approachLiftPath
{
public:
  apLiftPathTangent();
  apLiftPathTangent(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    cartesianPoint * fixPointIn,
    direction * fixPointDirIn,
    double radiusIn);
  ~apLiftPathTangent();
  int isA(int aType);
  void printSelf();
  double radius;
};

/********************************************************************/

/* backBoring

This is a class for the single definition of backBoring.
It represents the following items:

BACKBORING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ')'

*/

class backBoring :
  public instance,
  public drillingTypeOperation
{
public:
  backBoring();
  backBoring(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn);
  ~backBoring();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* backsideCounterbore

This is a class for the single definition of backsideCounterbore.
It represents the following items:

BACKSIDECOUNTERBORE '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class backsideCounterbore :
  public instance,
  public counterboreParent
{
public:
  backsideCounterbore();
  backsideCounterbore(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~backsideCounterbore();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* backsideCountersink

This is a class for the single definition of backsideCountersink.
It represents the following items:

BACKSIDECOUNTERSINK '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class backsideCountersink :
  public instance,
  public countersinkParent
{
public:
  backsideCountersink();
  backsideCountersink(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * countersinkRadiusIn);
  ~backsideCountersink();
  int isA(int aType);
  void printSelf();
  real * countersinkRadius;
};

/********************************************************************/

/* bezierSurface

This is a class for the single definition of bezierSurface.
It represents the following items:

BEZIERSURFACE '(' CHARSTRING ',' integer ',' integer ',' parenParenCartesianPointListFullListFull ',' bSplineSurfaceForm ',' logical ',' logical ',' logical ')'

*/

class bezierSurface :
  public instance,
  public bSplineSurface
{
public:
  bezierSurface();
  bezierSurface(
    char * nameIn,
    integer * uDegreeIn,
    integer * vDegreeIn,
    parenParenCartesianPointListFullListFull * controlPointsListIn,
    bSplineSurfaceForm * surfaceFormIn,
    logical * uClosedIn,
    logical * vClosedIn,
    logical * selfIntersectIn);
  ~bezierSurface();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* boringOperation

This is a parent class.

*/

class boringOperation :
  public drillingTypeOperation
{
public:
  boringOperation();
  boringOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * spindleStopAtBottomIn,
    real * depthOfTestcutIn,
    cartesianPoint * waitingPositionIn);
  ~boringOperation();
  int isA(int aType);
  void printSelf() = 0;
  boolean * spindleStopAtBottom;
  real * depthOfTestcut;
  cartesianPoint * waitingPosition;
};

/********************************************************************/

/* bottomAndSideFinishMilling

This is a class for the single definition of bottomAndSideFinishMilling.
It represents the following items:

BOTTOMANDSIDEFINISHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ',' optReal ',' optReal ')'

*/

class bottomAndSideFinishMilling :
  public instance,
  public bottomAndSideMilling
{
public:
  bottomAndSideFinishMilling();
  bottomAndSideFinishMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * radialCuttingDepthIn,
    real * allowanceSideIn,
    real * allowanceBottomIn);
  ~bottomAndSideFinishMilling();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* boundedCurve

This is a parent class.

*/

class boundedCurve :
  public curve
{
public:
  boundedCurve();
  boundedCurve(
    char * nameIn);
  ~boundedCurve();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* boundedPCurve

This is a class for the single definition of boundedPCurve.
It represents the following items:

BOUNDEDPCURVE '(' CHARSTRING ',' surface ',' definitionalRepresentation ')'

*/

class boundedPCurve :
  public instance,
  public curveWithSurfaceNormalSelect,
  public pcurveParent
{
public:
  boundedPCurve();
  boundedPCurve(
    char * nameIn,
    surface * basisSurfaceIn,
    definitionalRepresentation * referenceToCurveIn);
  ~boundedPCurve();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bSplineCurve

This is a parent class.

*/

class bSplineCurve :
  public boundedCurve
{
public:
  bSplineCurve();
  bSplineCurve(
    char * nameIn,
    int degreeIn,
    parenCartesianPointList * controlPointsListIn,
    bSplineCurveForm * curveFormIn,
    logical * closedCurveIn,
    logical * selfIntersectIn);
  ~bSplineCurve();
  int isA(int aType);
  void printSelf() = 0;
  int degree;
  parenCartesianPointList * controlPointsList;
  bSplineCurveForm * curveForm;
  logical * closedCurve;
  logical * selfIntersect;
};

/********************************************************************/

/* bSplineCurveWithKnots

This is a class for the single definition of bSplineCurveWithKnots.
It represents the following items:

BSPLINECURVEWITHKNOTS '(' CHARSTRING ',' INTSTRING ',' parenCartesianPointList ',' bSplineCurveForm ',' logical ',' logical parenIntegerListFull ',' parenRealListFull ',' knotType ')'

*/

class bSplineCurveWithKnots :
  public instance,
  public bSplineCurve
{
public:
  bSplineCurveWithKnots();
  bSplineCurveWithKnots(
    char * nameIn,
    int degreeIn,
    parenCartesianPointList * controlPointsListIn,
    bSplineCurveForm * curveFormIn,
    logical * closedCurveIn,
    logical * selfIntersectIn,
    parenIntegerListFull * knotMultiplicitesIn,
    parenRealListFull * knotsIn,
    knotType * knotSpecIn);
  ~bSplineCurveWithKnots();
  int isA(int aType);
  void printSelf();
  parenIntegerListFull * knotMultiplicites;
  parenRealListFull * knots;
  knotType * knotSpec;
};

/********************************************************************/

/* compositeCurve

This is a class for the single definition of compositeCurve.
It represents the following items:

COMPOSITECURVE '(' CHARSTRING ',' parenCompositeCurveSegmentListFull ',' logical ')'

*/

class compositeCurve :
  public instance,
  public boundedCurve
{
public:
  compositeCurve();
  compositeCurve(
    char * nameIn,
    parenCompositeCurveSegmentListFull * segmentsIn,
    logical * selfIntersectIn);
  ~compositeCurve();
  int isA(int aType);
  void printSelf();
  parenCompositeCurveSegmentListFull * segments;
  logical * selfIntersect;
};

/********************************************************************/

/* conic

This is a parent class.

*/

class conic :
  public curve
{
public:
  conic();
  conic(
    char * nameIn,
    axis2placement3d * positionIn);
  ~conic();
  int isA(int aType);
  void printSelf() = 0;
  axis2placement3d * position;
};

/********************************************************************/

/* connectDirect

This is a class for the single definition of connectDirect.
It represents the following items:

CONNECTDIRECT '(' boolean ',' toolpathType ',' optToolpathSpeedprofile ',' optTechnology ',' optMachineFunctions ')'

*/

class connectDirect :
  public instance,
  public connector
{
public:
  connectDirect();
  connectDirect(
    boolean * itsPriorityIn,
    toolpathType * itsTypeIn,
    toolpathSpeedprofile * itsSpeedIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn);
  ~connectDirect();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* counterbore

This is a class for the single definition of counterbore.
It represents the following items:

COUNTERBORE '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class counterbore :
  public instance,
  public counterboreParent
{
public:
  counterbore();
  counterbore(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~counterbore();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* countersink

This is a class for the single definition of countersink.
It represents the following items:

COUNTERSINK '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class countersink :
  public instance,
  public countersinkParent
{
public:
  countersink();
  countersink(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * countersinkRadiusIn);
  ~countersink();
  int isA(int aType);
  void printSelf();
  real * countersinkRadius;
};

/********************************************************************/

/* dovetailMill

This is a class for the single definition of dovetailMill.
It represents the following items:

DOVETAILMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class dovetailMill :
  public instance,
  public millingCutter
{
public:
  dovetailMill();
  dovetailMill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * includedAngleIn);
  ~dovetailMill();
  int isA(int aType);
  void printSelf();
  real * includedAngle;
};

/********************************************************************/

/* drillingOperation

This is a parent class.

*/

class drillingOperation :
  public drillingTypeOperation
{
public:
  drillingOperation();
  drillingOperation(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn);
  ~drillingOperation();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* ellipse

This is a class for the single definition of ellipse.
It represents the following items:

ELLIPSE '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ',' REALSTRING ')'

*/

class ellipse :
  public instance,
  public conic
{
public:
  ellipse();
  ellipse(
    char * nameIn,
    axis2placement3d * positionIn,
    double semiAxis1In,
    double semiAxis2In);
  ~ellipse();
  int isA(int aType);
  void printSelf();
  double semiAxis1;
  double semiAxis2;
};

/********************************************************************/

/* endmill

This is a parent class.

*/

class endmill :
  public millingCutter
{
public:
  endmill();
  endmill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~endmill();
  int isA(int aType);
  void printSelf() = 0;
};

/********************************************************************/

/* facemill

This is a class for the single definition of facemill.
It represents the following items:

FACEMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class facemill :
  public instance,
  public millingCutter
{
public:
  facemill();
  facemill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~facemill();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* hyperbola

This is a class for the single definition of hyperbola.
It represents the following items:

HYPERBOLA '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ',' REALSTRING ')'

*/

class hyperbola :
  public instance,
  public conic
{
public:
  hyperbola();
  hyperbola(
    char * nameIn,
    axis2placement3d * positionIn,
    double semiAxisIn,
    double semiImagAxisIn);
  ~hyperbola();
  int isA(int aType);
  void printSelf();
  double semiAxis;
  double semiImagAxis;
};

/********************************************************************/

/* multistepDrilling

This is a class for the single definition of multistepDrilling.
It represents the following items:

MULTISTEPDRILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ',' REALSTRING ',' REALSTRING ',' REALSTRING ',' optReal ')'

*/

class multistepDrilling :
  public instance,
  public drillingOperation
{
public:
  multistepDrilling();
  multistepDrilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    double retractDistanceIn,
    double firstDepthIn,
    double depthOfStepIn,
    real * dwellTimeStepIn);
  ~multistepDrilling();
  int isA(int aType);
  void printSelf();
  double retractDistance;
  double firstDepth;
  double depthOfStep;
  real * dwellTimeStep;
};

/********************************************************************/

/* parabola

This is a class for the single definition of parabola.
It represents the following items:

PARABOLA '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ')'

*/

class parabola :
  public instance,
  public conic
{
public:
  parabola();
  parabola(
    char * nameIn,
    axis2placement3d * positionIn,
    double focalDistIn);
  ~parabola();
  int isA(int aType);
  void printSelf();
  double focalDist;
};

/********************************************************************/

/* pcurve

This is a class for the single definition of pcurve.
It represents the following items:

PCURVE '(' CHARSTRING ',' surface ',' definitionalRepresentation ')'

*/

class pcurve :
  public instance,
  public pcurveParent
{
public:
  pcurve();
  pcurve(
    char * nameIn,
    surface * basisSurfaceIn,
    definitionalRepresentation * referenceToCurveIn);
  ~pcurve();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* planeFinishMilling

This is a class for the single definition of planeFinishMilling.
It represents the following items:

PLANEFINISHMILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optApproachRetractStrategy ',' optApproachRetractStrategy ',' optTwo5DmillingStrategy ',' optReal ',' optReal ')'

*/

class planeFinishMilling :
  public instance,
  public planeMilling
{
public:
  planeFinishMilling();
  planeFinishMilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    approachRetractStrategy * approachIn,
    approachRetractStrategy * retractIn,
    two5DmillingStrategy * itsMachiningStrategyIn,
    real * axialCuttingDepthIn,
    real * allowanceBottomIn);
  ~planeFinishMilling();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* polyline

This is a class for the single definition of polyline.
It represents the following items:

POLYLINE '(' CHARSTRING ',' parenCartesianPointListFull ')'

*/

class polyline :
  public instance,
  public boundedCurve
{
public:
  polyline();
  polyline(
    char * nameIn,
    parenCartesianPointListFull * pointsIn);
  ~polyline();
  int isA(int aType);
  void printSelf();
  parenCartesianPointListFull * points;
};

/********************************************************************/

/* quasiUniformCurve

This is a class for the single definition of quasiUniformCurve.
It represents the following items:

QUASIUNIFORMCURVE '(' CHARSTRING ',' INTSTRING ',' parenCartesianPointList ',' bSplineCurveForm ',' logical ',' logical ')'

*/

class quasiUniformCurve :
  public instance,
  public bSplineCurve
{
public:
  quasiUniformCurve();
  quasiUniformCurve(
    char * nameIn,
    int degreeIn,
    parenCartesianPointList * controlPointsListIn,
    bSplineCurveForm * curveFormIn,
    logical * closedCurveIn,
    logical * selfIntersectIn);
  ~quasiUniformCurve();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* rationalBSplineCurve

This is a class for the single definition of rationalBSplineCurve.
It represents the following items:

RATIONALBSPLINECURVE '(' CHARSTRING ',' INTSTRING ',' parenCartesianPointList ',' bSplineCurveForm ',' logical ',' logical ',' parenRealListFull ')'

*/

class rationalBSplineCurve :
  public instance,
  public bSplineCurve
{
public:
  rationalBSplineCurve();
  rationalBSplineCurve(
    char * nameIn,
    int degreeIn,
    parenCartesianPointList * controlPointsListIn,
    bSplineCurveForm * curveFormIn,
    logical * closedCurveIn,
    logical * selfIntersectIn,
    parenRealListFull * weightsDataIn);
  ~rationalBSplineCurve();
  int isA(int aType);
  void printSelf();
  parenRealListFull * weightsData;
};

/********************************************************************/

/* reaming

This is a class for the single definition of reaming.
It represents the following items:

REAMING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ',' boolean ',' optReal ',' optCartesianPoint ')'

*/

class reaming :
  public instance,
  public boringOperation
{
public:
  reaming();
  reaming(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * spindleStopAtBottomIn,
    real * depthOfTestcutIn,
    cartesianPoint * waitingPositionIn);
  ~reaming();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* taperedDrill

This is a class for the single definition of taperedDrill.
It represents the following items:

TAPEREDDRILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class taperedDrill :
  public instance,
  public twistDrillParent
{
public:
  taperedDrill();
  taperedDrill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * taperAngleIn);
  ~taperedDrill();
  int isA(int aType);
  void printSelf();
  real * taperAngle;
};

/********************************************************************/

/* taperedEndmill

This is a class for the single definition of taperedEndmill.
It represents the following items:

TAPEREDENDMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ',' optReal ')'

*/

class taperedEndmill :
  public instance,
  public endmill
{
public:
  taperedEndmill();
  taperedEndmill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn,
    real * taperAngleIn);
  ~taperedEndmill();
  int isA(int aType);
  void printSelf();
  real * taperAngle;
};

/********************************************************************/

/* toolLengthProbing

This is a class for the single definition of toolLengthProbing.
It represents the following items:

TOOLLENGTHPROBING '(' CHARSTRING ',' elementarySurface ',' optToolpathList ',' optToolDirection ',' ncVariable ',' cartesianPoint ',' REALSTRING ',' machiningTool ')'

*/

class toolLengthProbing :
  public instance,
  public toolProbing
{
public:
  toolLengthProbing();
  toolLengthProbing(
    char * itsIdIn,
    elementarySurface * itsSecplaneIn,
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    ncVariable * measuredOffsetIn,
    cartesianPoint * offsetIn,
    double maxWearIn,
    machiningTool * itsToolIn);
  ~toolLengthProbing();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* trimmedCurve

This is a class for the single definition of trimmedCurve.
It represents the following items:

TRIMMEDCURVE '(' CHARSTRING ',' curve ',' parenTrimmingSelectListFull ',' parenTrimmingSelectListFull ',' boolean ',' trimmingPreference ')'

*/

class trimmedCurve :
  public instance,
  public boundedCurve
{
public:
  trimmedCurve();
  trimmedCurve(
    char * nameIn,
    curve * basisCurveIn,
    parenTrimmingSelectListFull * trim1In,
    parenTrimmingSelectListFull * trim2In,
    boolean * senseAgreementIn,
    trimmingPreference * masterRepresentationIn);
  ~trimmedCurve();
  int isA(int aType);
  void printSelf();
  curve * basisCurve;
  parenTrimmingSelectListFull * trim1;
  parenTrimmingSelectListFull * trim2;
  boolean * senseAgreement;
  trimmingPreference * masterRepresentation;
};

/********************************************************************/

/* uniformCurve

This is a class for the single definition of uniformCurve.
It represents the following items:

UNIFORMCURVE '(' CHARSTRING ',' INTSTRING ',' parenCartesianPointList ',' bSplineCurveForm ',' logical ',' logical ')'

*/

class uniformCurve :
  public instance,
  public bSplineCurve
{
public:
  uniformCurve();
  uniformCurve(
    char * nameIn,
    int degreeIn,
    parenCartesianPointList * controlPointsListIn,
    bSplineCurveForm * curveFormIn,
    logical * closedCurveIn,
    logical * selfIntersectIn);
  ~uniformCurve();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* ballEndmill

This is a class for the single definition of ballEndmill.
It represents the following items:

BALLENDMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class ballEndmill :
  public instance,
  public endmill
{
public:
  ballEndmill();
  ballEndmill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~ballEndmill();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bezierCurve

This is a class for the single definition of bezierCurve.
It represents the following items:

BEZIERCURVE '(' CHARSTRING ',' INTSTRING ',' parenCartesianPointList ',' bSplineCurveForm ',' logical ',' logical ')'

*/

class bezierCurve :
  public instance,
  public bSplineCurve
{
public:
  bezierCurve();
  bezierCurve(
    char * nameIn,
    int degreeIn,
    parenCartesianPointList * controlPointsListIn,
    bSplineCurveForm * curveFormIn,
    logical * closedCurveIn,
    logical * selfIntersectIn);
  ~bezierCurve();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* boring

This is a class for the single definition of boring.
It represents the following items:

BORING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ',' boolean ',' optReal ',' optCartesianPoint ')'

*/

class boring :
  public instance,
  public boringOperation
{
public:
  boring();
  boring(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn,
    boolean * spindleStopAtBottomIn,
    real * depthOfTestcutIn,
    cartesianPoint * waitingPositionIn);
  ~boring();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* bullnoseEndmill

This is a class for the single definition of bullnoseEndmill.
It represents the following items:

BULLNOSEENDMILL '(' millingToolDimension ',' optInteger ',' optHand ',' optBoolean ',' optReal ')'

*/

class bullnoseEndmill :
  public instance,
  public endmill
{
public:
  bullnoseEndmill();
  bullnoseEndmill(
    millingToolDimension * dimensionIn,
    integer * numberOfTeethIn,
    hand * handOfCutIn,
    boolean * coolantThroughToolIn,
    real * pilotLengthIn);
  ~bullnoseEndmill();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* centerDrilling

This is a class for the single definition of centerDrilling.
It represents the following items:

CENTERDRILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ')'

*/

class centerDrilling :
  public instance,
  public drillingOperation
{
public:
  centerDrilling();
  centerDrilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn);
  ~centerDrilling();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* circle

This is a class for the single definition of circle.
It represents the following items:

CIRCLE '(' CHARSTRING ',' axis2placement3d ',' REALSTRING ')'

*/

class circle :
  public instance,
  public conic
{
public:
  circle();
  circle(
    char * nameIn,
    axis2placement3d * positionIn,
    double radiusIn);
  ~circle();
  int isA(int aType);
  void printSelf();
  double radius;
};

/********************************************************************/

/* counterSinking

This is a class for the single definition of counterSinking.
It represents the following items:

COUNTERSINKING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ')'

*/

class counterSinking :
  public instance,
  public drillingOperation
{
public:
  counterSinking();
  counterSinking(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn);
  ~counterSinking();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

/* drilling

This is a class for the single definition of drilling.
It represents the following items:

DRILLING '(' optToolpathList ',' optToolDirection ',' CHARSTRING ',' optReal ',' optCartesianPoint ',' machiningTool ',' technology ',' machineFunctions ',' optReal ',' optReal ',' optReal ',' optReal ',' optReal ',' optDrillingTypeStrategy ')'

*/

class drilling :
  public instance,
  public drillingOperation
{
public:
  drilling();
  drilling(
    toolpathList * itsToolpathIn,
    toolDirection * itsToolDirectionIn,
    char * itsIdIn,
    real * retractPlaneIn,
    cartesianPoint * startPointIn,
    machiningTool * itsToolIn,
    technology * itsTechnologyIn,
    machineFunctions * itsMachineFunctionsIn,
    real * overcutLengthIn,
    real * cuttingDepthIn,
    real * previousDiameterIn,
    real * dwellTimeBottomIn,
    real * feedOnRetractIn,
    drillingTypeStrategy * itsMachiningStrategyIn);
  ~drilling();
  int isA(int aType);
  void printSelf();
};

/********************************************************************/

