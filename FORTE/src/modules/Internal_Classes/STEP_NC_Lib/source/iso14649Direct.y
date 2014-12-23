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

#include <string.h>  // for strlen, strcpy, strcat
#include <stdio.h>   // for fopen, etc.
#include <stdlib.h>  // for exit
#include "iso14649classesDirect.hh"

#define YYERROR_VERBOSE
#define YYDEBUG 1
#define INSTANCEMAX 100000

/********************************************************************/

#define WRITE_LINKER(TYP) \
std::list<TYP **> TYP ## _refs;\
std::list<int> TYP ## _nums;\
\
void link_ ## TYP()\
{\
  std::list<TYP **>::iterator refIter;\
  std::list<int>::iterator numIter;\
  for (refIter = TYP ## _refs.begin(),\
	 numIter = TYP ## _nums.begin();\
       refIter != TYP ## _refs.end();\
       refIter++, numIter++)\
    {\
      if (instances[*numIter] == 0)\
	 {\
	   fprintf(report,\
		   "Error: referenced instance #%d does not exist\n",\
		   *numIter);\
	   numErrors++;\
	 }\
      else if (instances[*numIter]->isA(TYP ## _E))\
	{\
	  **refIter = dynamic_cast<TYP *>(instances[*numIter]);\
	}\
      else\
	{\
	  fprintf(report, "Error: #%d used incorrectly\n",\
		  instances[*numIter]->iId->val);\
	  numErrors++;\
	}\
    }\
  TYP ## _refs.clear();\
  TYP ## _nums.clear();\
}


/********************************************************************/

/*

The lineText array is used for saving everything on a line up to the end
of the line, 4096 characters, or an error, whichever comes first. The
lineText is used (printed by yyerror) only if there is an error. This 
lets the user see the point in the Part 21 file at which an error occurred.
Lines longer than 4096 characters will not overflow the lineText array.

*/

extern FILE * yyin;
extern int yylex();

int numErrors = 0;
char lineText[4096];
char lexMessage[80];
FILE * report;
inputFile * tree;
char errorMessage[256];
instance * instances[INSTANCEMAX] = {0};

/********************************************************************/

WRITE_LINKER(address)
WRITE_LINKER(advancedBrepShapeRepresentation)
WRITE_LINKER(advancedFace)
WRITE_LINKER(airStrategy)
WRITE_LINKER(alongPath)
WRITE_LINKER(andExpression)
WRITE_LINKER(angleTaper)
WRITE_LINKER(apLiftPathAngle)
WRITE_LINKER(apLiftPathTangent)
WRITE_LINKER(approachLiftPath)
WRITE_LINKER(approachRetractStrategy)
WRITE_LINKER(approval)
WRITE_LINKER(approvalStatus)
WRITE_LINKER(apRetractAngle)
WRITE_LINKER(apRetractTangent)
WRITE_LINKER(assignment)
WRITE_LINKER(axis1placement)
WRITE_LINKER(axis2placement3d)
WRITE_LINKER(axisTrajectory)
WRITE_LINKER(backBoring)
WRITE_LINKER(backsideCounterbore)
WRITE_LINKER(backsideCountersink)
WRITE_LINKER(ballEndmill)
WRITE_LINKER(bezierCurve)
WRITE_LINKER(bezierSurface)
WRITE_LINKER(bidirectionalContour)
WRITE_LINKER(bidirectionalMilling)
WRITE_LINKER(binaryBooleanExpression)
WRITE_LINKER(blindBottomCondition)
WRITE_LINKER(block)
WRITE_LINKER(booleanExpression)
WRITE_LINKER(boring)
WRITE_LINKER(boringOperation)
WRITE_LINKER(boringTool)
WRITE_LINKER(boss)
WRITE_LINKER(bottomAndSideFinishMilling)
WRITE_LINKER(bottomAndSideMilling)
WRITE_LINKER(bottomAndSideRoughMilling)
WRITE_LINKER(boundedCurve)
WRITE_LINKER(boundedPCurve)
WRITE_LINKER(boundedSurface)
WRITE_LINKER(boundingGeometrySelect)
WRITE_LINKER(bSplineCurve)
WRITE_LINKER(bSplineCurveWithKnots)
WRITE_LINKER(bSplineSurface)
WRITE_LINKER(bSplineSurfaceWithKnots)
WRITE_LINKER(bullnoseEndmill)
WRITE_LINKER(calendarDate)
WRITE_LINKER(cartesianPoint)
WRITE_LINKER(catalogueThread)
WRITE_LINKER(centerDrill)
WRITE_LINKER(centerDrilling)
WRITE_LINKER(centerMilling)
WRITE_LINKER(chamfer)
WRITE_LINKER(channel)
WRITE_LINKER(circle)
WRITE_LINKER(circularClosedProfile)
WRITE_LINKER(circularClosedShapeProfile)
WRITE_LINKER(circularOffset)
WRITE_LINKER(circularOmit)
WRITE_LINKER(circularPath)
WRITE_LINKER(circularPattern)
WRITE_LINKER(closedPocket)
WRITE_LINKER(closedProfile)
WRITE_LINKER(closedShell)
WRITE_LINKER(combinedDrillAndReamer)
WRITE_LINKER(combinedDrillAndTap)
WRITE_LINKER(comparisonEqual)
WRITE_LINKER(comparisonGreater)
WRITE_LINKER(comparisonGreaterEqual)
WRITE_LINKER(comparisonLess)
WRITE_LINKER(comparisonLessEqual)
WRITE_LINKER(comparisonNotEqual)
WRITE_LINKER(comparisonExpression)
WRITE_LINKER(completeCircularPath)
WRITE_LINKER(compositeCurve)
WRITE_LINKER(compositeCurveSegment)
WRITE_LINKER(compoundFeature)
WRITE_LINKER(compoundFeatureSelect)
WRITE_LINKER(conic)
WRITE_LINKER(conicalHoleBottom)
WRITE_LINKER(connectDirect)
WRITE_LINKER(connectedFaceSet)
WRITE_LINKER(connector)
WRITE_LINKER(connectSecplane)
WRITE_LINKER(contourBidirectional)
WRITE_LINKER(contourParallel)
WRITE_LINKER(contourSpiral)
WRITE_LINKER(coordinatedUniversalTimeOffset)
WRITE_LINKER(counterbore)
WRITE_LINKER(counterboreHole)
WRITE_LINKER(counterboreParent)
WRITE_LINKER(countersink)
WRITE_LINKER(counterSinking)
WRITE_LINKER(countersinkParent)
WRITE_LINKER(countersunkHole)
WRITE_LINKER(curve)
WRITE_LINKER(curveWithNormalVector)
WRITE_LINKER(curveWithSurfaceNormalSelect)
WRITE_LINKER(cutterContactTrajectory)
WRITE_LINKER(cutterLocationTrajectory)
WRITE_LINKER(cuttingComponent)
WRITE_LINKER(cuttingEdgeTechnologicalData)
WRITE_LINKER(cuttingTool)
WRITE_LINKER(date)
WRITE_LINKER(dateAndTime)
WRITE_LINKER(definedThread)
WRITE_LINKER(definitionalRepresentation)
WRITE_LINKER(descriptiveParameter)
WRITE_LINKER(diameterTaper)
WRITE_LINKER(direction)
WRITE_LINKER(displayMessage)
WRITE_LINKER(dovetailMill)
WRITE_LINKER(drill)
WRITE_LINKER(drilling)
WRITE_LINKER(drillingOperation)
WRITE_LINKER(drillingTypeOperation)
WRITE_LINKER(drillingTypeStrategy)
WRITE_LINKER(edge)
WRITE_LINKER(edgeCurve)
WRITE_LINKER(edgeLoop)
WRITE_LINKER(edgeRound)
WRITE_LINKER(elementarySurface)
WRITE_LINKER(ellipse)
WRITE_LINKER(endmill)
WRITE_LINKER(exchangePallet)
WRITE_LINKER(executable)
WRITE_LINKER(explicitStrategy)
WRITE_LINKER(face)
WRITE_LINKER(facemill)
WRITE_LINKER(faceBoundParent)
WRITE_LINKER(faceBound)
WRITE_LINKER(faceOuterBound)
WRITE_LINKER(faceSurface)
WRITE_LINKER(feedstop)
WRITE_LINKER(fiveAxesVarTiltYaw)
WRITE_LINKER(fiveAxesConstTiltYaw)
WRITE_LINKER(flatHoleBottom)
WRITE_LINKER(flatSlotEndType)
WRITE_LINKER(flatWithRadiusHoleBottom)
WRITE_LINKER(freeformOperation)
WRITE_LINKER(freeformStrategy)
WRITE_LINKER(generalClosedProfile)
WRITE_LINKER(generalOutsideProfile)
WRITE_LINKER(generalPath)
WRITE_LINKER(generalPattern)
WRITE_LINKER(generalPocketBottomCondition)
WRITE_LINKER(generalProfile)
WRITE_LINKER(generalProfileFloor)
WRITE_LINKER(generalShapeProfile)
WRITE_LINKER(geometricRepresentationItem)
WRITE_LINKER(helix)
WRITE_LINKER(holeBottomCondition)
WRITE_LINKER(hyperbola)
WRITE_LINKER(ifStatement)
WRITE_LINKER(indexPallet)
WRITE_LINKER(indexTable)
WRITE_LINKER(inProcessGeometry)
WRITE_LINKER(leadingLineStrategy)
WRITE_LINKER(limitsAndFits)
WRITE_LINKER(line)
WRITE_LINKER(linearPath)
WRITE_LINKER(linearProfile)
WRITE_LINKER(loadTool)
WRITE_LINKER(localTime)
WRITE_LINKER(loop)
WRITE_LINKER(loopSlotEndType)
WRITE_LINKER(machinedSurface)
WRITE_LINKER(machineFunctions)
WRITE_LINKER(machiningFeature)
WRITE_LINKER(machiningOperation)
WRITE_LINKER(machiningTool)
WRITE_LINKER(machiningWorkingstep)
WRITE_LINKER(manifoldSolidBrep)
WRITE_LINKER(manufacturingFeature)
WRITE_LINKER(material)
WRITE_LINKER(millingCutter)
WRITE_LINKER(millingCuttingTool)
WRITE_LINKER(millingMachineFunctions)
WRITE_LINKER(millingMachiningOperation)
WRITE_LINKER(millingTechnology)
WRITE_LINKER(millingThreadingTool)
WRITE_LINKER(millingToolBody)
WRITE_LINKER(millingToolDimension)
WRITE_LINKER(millingTypeOperation)
WRITE_LINKER(multipleArityBooleanExpression)
WRITE_LINKER(multistepDrilling)
WRITE_LINKER(ncFunction)
WRITE_LINKER(ncConstant)
WRITE_LINKER(ncVariable)
WRITE_LINKER(ngonClosedProfile)
WRITE_LINKER(nonSequential)
WRITE_LINKER(notExpression)
WRITE_LINKER(numericParameter)
WRITE_LINKER(openPocket)
WRITE_LINKER(openProfile)
WRITE_LINKER(openShellParent)
WRITE_LINKER(openShell)
WRITE_LINKER(openSlotEndType)
WRITE_LINKER(operation)
WRITE_LINKER(optionalStop)
WRITE_LINKER(orExpression)
WRITE_LINKER(orientedEdge)
WRITE_LINKER(ordinalDate)
WRITE_LINKER(parabola)
WRITE_LINKER(parallel)
WRITE_LINKER(parameterisedPath)
WRITE_LINKER(partialAreaDefinition)
WRITE_LINKER(partialCircularPath)
WRITE_LINKER(partialCircularProfile)
WRITE_LINKER(partialCircularShapeProfile)
WRITE_LINKER(pcurve)
WRITE_LINKER(pcurveParent)
WRITE_LINKER(person)
WRITE_LINKER(personAndAddress)
WRITE_LINKER(placement)
WRITE_LINKER(planarFace)
WRITE_LINKER(planarPocketBottomCondition)
WRITE_LINKER(planarProfileFloor)
WRITE_LINKER(plane)
WRITE_LINKER(planeCcStrategy)
WRITE_LINKER(planeClStrategy)
WRITE_LINKER(planeFinishMilling)
WRITE_LINKER(planeMilling)
WRITE_LINKER(planeRoughMilling)
WRITE_LINKER(plungeStrategy)
WRITE_LINKER(plungeHelix)
WRITE_LINKER(plungeRamp)
WRITE_LINKER(plungeToolaxis)
WRITE_LINKER(plungeZigzag)
WRITE_LINKER(plusMinusValue)
WRITE_LINKER(pocket)
WRITE_LINKER(pocketBottomCondition)
WRITE_LINKER(point)
WRITE_LINKER(polyline)
WRITE_LINKER(processModel)
WRITE_LINKER(processModelList)
WRITE_LINKER(profile)
WRITE_LINKER(profileFeature)
WRITE_LINKER(profileFloor)
WRITE_LINKER(profileSelect)
WRITE_LINKER(programStructure)
WRITE_LINKER(programStop)
WRITE_LINKER(project)
WRITE_LINKER(propertyParameter)
WRITE_LINKER(quasiUniformCurve)
WRITE_LINKER(quasiUniformSurface)
WRITE_LINKER(radiusedPocketBottomCondition)
WRITE_LINKER(radiusedSlotEndType)
WRITE_LINKER(rapidMovement)
WRITE_LINKER(rationalBSplineCurve)
WRITE_LINKER(rationalBSplineSurface)
WRITE_LINKER(reamer)
WRITE_LINKER(reaming)
WRITE_LINKER(rectangularClosedProfile)
WRITE_LINKER(rectangularClosedShapeProfile)
WRITE_LINKER(rectangularOffset)
WRITE_LINKER(rectangularOmit)
WRITE_LINKER(rectangularOpenShapeProfile)
WRITE_LINKER(rectangularPattern)
WRITE_LINKER(region)
WRITE_LINKER(regionProjection)
WRITE_LINKER(regionSurfaceList)
WRITE_LINKER(replicateFeature)
WRITE_LINKER(representationParent)
WRITE_LINKER(representation)
WRITE_LINKER(representationItem)
WRITE_LINKER(restrictedAreaSelect)
WRITE_LINKER(rightCircularCylinder)
WRITE_LINKER(roundedEnd)
WRITE_LINKER(roundedUProfile)
WRITE_LINKER(roundHole)
WRITE_LINKER(rvalue)
WRITE_LINKER(selective)
WRITE_LINKER(setMark)
WRITE_LINKER(setup)
WRITE_LINKER(setupInstruction)
WRITE_LINKER(shapeProfile)
WRITE_LINKER(shapeRepresentationParent)
WRITE_LINKER(shapeRepresentation)
WRITE_LINKER(sideMill)
WRITE_LINKER(sideMilling)
WRITE_LINKER(sideFinishMilling)
WRITE_LINKER(sideRoughMilling)
WRITE_LINKER(slot)
WRITE_LINKER(slotEndType)
WRITE_LINKER(solidModel)
WRITE_LINKER(spadeDrill)
WRITE_LINKER(specification)
WRITE_LINKER(specificationUsageConstraint)
WRITE_LINKER(sphericalCap)
WRITE_LINKER(sphericalHoleBottom)
WRITE_LINKER(sphericalSurface)
WRITE_LINKER(squareUProfile)
WRITE_LINKER(step)
WRITE_LINKER(surface)
WRITE_LINKER(surfaceOfLinearExtrusion)
WRITE_LINKER(surfaceOfRevolution)
WRITE_LINKER(surfaceTextureParameter)
WRITE_LINKER(sweptSurface)
WRITE_LINKER(tap)
WRITE_LINKER(taperedTap)
WRITE_LINKER(tapParent)
WRITE_LINKER(taperedDrill)
WRITE_LINKER(taperedEndmill)
WRITE_LINKER(taperedReamer)
WRITE_LINKER(taperSelect)
WRITE_LINKER(tapping)
WRITE_LINKER(technology)
WRITE_LINKER(teeProfile)
WRITE_LINKER(thread)
WRITE_LINKER(threadDrilling)
WRITE_LINKER(threadMill)
WRITE_LINKER(threeAxes)
WRITE_LINKER(threeAxesTiltedTool)
WRITE_LINKER(throughBottomCondition)
WRITE_LINKER(throughPocketBottomCondition)
WRITE_LINKER(throughProfileFloor)
WRITE_LINKER(tolerancedLengthMeasure)
WRITE_LINKER(tolerances)
WRITE_LINKER(toleranceSelect)
WRITE_LINKER(toolBody)
WRITE_LINKER(toolDirection)
WRITE_LINKER(toolDirectionForMilling)
WRITE_LINKER(toolLengthProbing)
WRITE_LINKER(toolpath)
WRITE_LINKER(toolpathFeature)
WRITE_LINKER(toolpathList)
WRITE_LINKER(toolpathSpeed)
WRITE_LINKER(toolpathSpeedprofile)
WRITE_LINKER(toolProbing)
WRITE_LINKER(toolRadiusProbing)
WRITE_LINKER(topologicalRegion)
WRITE_LINKER(topologicalRepresentationItem)
WRITE_LINKER(touchProbe)
WRITE_LINKER(touchProbing)
WRITE_LINKER(trajectory)
WRITE_LINKER(transitionFeature)
WRITE_LINKER(travelPath)
WRITE_LINKER(trimmedCurve)
WRITE_LINKER(trimmingSelect)
WRITE_LINKER(tSlotMill)
WRITE_LINKER(twistDrillParent)
WRITE_LINKER(twistDrill)
WRITE_LINKER(twoAxes)
WRITE_LINKER(two5DmanufacturingFeature)
WRITE_LINKER(two5DmillingOperation)
WRITE_LINKER(two5DmillingStrategy)
WRITE_LINKER(unaryBooleanExpression)
WRITE_LINKER(unidirectionalMilling)
WRITE_LINKER(uniformCurve)
WRITE_LINKER(uniformSurface)
WRITE_LINKER(unloadTool)
WRITE_LINKER(userDefinedTool)
WRITE_LINKER(uvStrategy)
WRITE_LINKER(vector)
WRITE_LINKER(veeProfile)
WRITE_LINKER(vertex)
WRITE_LINKER(vertexLoop)
WRITE_LINKER(vertexPoint)
WRITE_LINKER(waitForMark)
WRITE_LINKER(weekOfYearAndDayDate)
WRITE_LINKER(whileStatement)
WRITE_LINKER(woodruffKeyseatMill)
WRITE_LINKER(woodruffSlotEndType)
WRITE_LINKER(workingstep)
WRITE_LINKER(workpiece)
WRITE_LINKER(workpieceCompleteProbing)
WRITE_LINKER(workpieceProbing)
WRITE_LINKER(workpieceSetup)
WRITE_LINKER(workplan)
WRITE_LINKER(xorExpression)

/********************************************************************/

/* linkAll

The instances array, which is used by all the linking functions called
here, is not needed after linking is finished. That array needs to be
cleared in order to parse another file, so it is cleared at the
end of this function.

*/

void linkAll()
{
  int n;

  link_address();
  link_advancedBrepShapeRepresentation();
  link_advancedFace();
  link_airStrategy();
  link_alongPath();
  link_andExpression();
  link_angleTaper();
  link_apLiftPathAngle();
  link_apLiftPathTangent();
  link_approachLiftPath();
  link_approachRetractStrategy();
  link_approval();
  link_approvalStatus();
  link_apRetractAngle();
  link_apRetractTangent();
  link_assignment();
  link_axis1placement();
  link_axis2placement3d();
  link_axisTrajectory();
  link_backBoring();
  link_backsideCounterbore();
  link_backsideCountersink();
  link_ballEndmill();
  link_bezierCurve();
  link_bezierSurface();
  link_bidirectionalContour();
  link_bidirectionalMilling();
  link_binaryBooleanExpression();
  link_blindBottomCondition();
  link_block();
  link_booleanExpression();
  link_boring();
  link_boringOperation();
  link_boringTool();
  link_boss();
  link_bottomAndSideFinishMilling();
  link_bottomAndSideMilling();
  link_bottomAndSideRoughMilling();
  link_boundedCurve();
  link_boundedPCurve();
  link_boundedSurface();
  link_boundingGeometrySelect();
  link_bSplineCurve();
  link_bSplineCurveWithKnots();
  link_bSplineSurface();
  link_bSplineSurfaceWithKnots();
  link_bullnoseEndmill();
  link_calendarDate();
  link_cartesianPoint();
  link_catalogueThread();
  link_centerDrill();
  link_centerDrilling();
  link_centerMilling();
  link_chamfer();
  link_channel();
  link_circle();
  link_circularClosedProfile();
  link_circularClosedShapeProfile();
  link_circularOffset();
  link_circularOmit();
  link_circularPath();
  link_circularPattern();
  link_closedPocket();
  link_closedProfile();
  link_closedShell();
  link_combinedDrillAndReamer();
  link_combinedDrillAndTap();
  link_comparisonEqual();
  link_comparisonGreater();
  link_comparisonGreaterEqual();
  link_comparisonLess();
  link_comparisonLessEqual();
  link_comparisonNotEqual();
  link_comparisonExpression();
  link_completeCircularPath();
  link_compositeCurve();
  link_compositeCurveSegment();
  link_compoundFeature();
  link_compoundFeatureSelect();
  link_conic();
  link_conicalHoleBottom();
  link_connectDirect();
  link_connectedFaceSet();
  link_connector();
  link_connectSecplane();
  link_contourBidirectional();
  link_contourParallel();
  link_contourSpiral();
  link_coordinatedUniversalTimeOffset();
  link_counterbore();
  link_counterboreHole();
  link_counterboreParent();
  link_countersink();
  link_counterSinking();
  link_countersinkParent();
  link_countersunkHole();
  link_curve();
  link_curveWithNormalVector();
  link_curveWithSurfaceNormalSelect();
  link_cutterContactTrajectory();
  link_cutterLocationTrajectory();
  link_cuttingComponent();
  link_cuttingEdgeTechnologicalData();
  link_cuttingTool();
  link_date();
  link_dateAndTime();
  link_definedThread();
  link_definitionalRepresentation();
  link_descriptiveParameter();
  link_diameterTaper();
  link_direction();
  link_displayMessage();
  link_dovetailMill();
  link_drill();
  link_drilling();
  link_drillingOperation();
  link_drillingTypeOperation();
  link_drillingTypeStrategy();
  link_edge();
  link_edgeCurve();
  link_edgeLoop();
  link_edgeRound();
  link_elementarySurface();
  link_ellipse();
  link_endmill();
  link_exchangePallet();
  link_executable();
  link_explicitStrategy();
  link_face();
  link_facemill();
  link_faceBoundParent();
  link_faceBound();
  link_faceOuterBound();
  link_faceSurface();
  link_feedstop();
  link_fiveAxesVarTiltYaw();
  link_fiveAxesConstTiltYaw();
  link_flatHoleBottom();
  link_flatSlotEndType();
  link_flatWithRadiusHoleBottom();
  link_freeformOperation();
  link_freeformStrategy();
  link_generalClosedProfile();
  link_generalOutsideProfile();
  link_generalPath();
  link_generalPattern();
  link_generalPocketBottomCondition();
  link_generalProfile();
  link_generalProfileFloor();
  link_generalShapeProfile();
  link_geometricRepresentationItem();
  link_helix();
  link_holeBottomCondition();
  link_hyperbola();
  link_ifStatement();
  link_indexPallet();
  link_indexTable();
  link_inProcessGeometry();
  link_leadingLineStrategy();
  link_limitsAndFits();
  link_line();
  link_linearPath();
  link_linearProfile();
  link_loadTool();
  link_localTime();
  link_loop();
  link_loopSlotEndType();
  link_machinedSurface();
  link_machineFunctions();
  link_machiningFeature();
  link_machiningOperation();
  link_machiningTool();
  link_machiningWorkingstep();
  link_manifoldSolidBrep();
  link_manufacturingFeature();
  link_material();
  link_millingCutter();
  link_millingCuttingTool();
  link_millingMachineFunctions();
  link_millingMachiningOperation();
  link_millingTechnology();
  link_millingThreadingTool();
  link_millingToolBody();
  link_millingToolDimension();
  link_millingTypeOperation();
  link_multipleArityBooleanExpression();
  link_multistepDrilling();
  link_ncFunction();
  link_ncConstant();
  link_ncVariable();
  link_ngonClosedProfile();
  link_nonSequential();
  link_notExpression();
  link_numericParameter();
  link_openPocket();
  link_openProfile();
  link_openShellParent();
  link_openShell();
  link_openSlotEndType();
  link_operation();
  link_optionalStop();
  link_orExpression();
  link_orientedEdge();
  link_ordinalDate();
  link_parabola();
  link_parallel();
  link_parameterisedPath();
  link_partialAreaDefinition();
  link_partialCircularPath();
  link_partialCircularProfile();
  link_partialCircularShapeProfile();
  link_pcurve();
  link_pcurveParent();
  link_person();
  link_personAndAddress();
  link_placement();
  link_planarFace();
  link_planarPocketBottomCondition();
  link_planarProfileFloor();
  link_plane();
  link_planeCcStrategy();
  link_planeClStrategy();
  link_planeFinishMilling();
  link_planeMilling();
  link_planeRoughMilling();
  link_plungeStrategy();
  link_plungeHelix();
  link_plungeRamp();
  link_plungeToolaxis();
  link_plungeZigzag();
  link_plusMinusValue();
  link_pocket();
  link_pocketBottomCondition();
  link_point();
  link_polyline();
  link_processModel();
  link_processModelList();
  link_profile();
  link_profileFeature();
  link_profileFloor();
  link_profileSelect();
  link_programStructure();
  link_programStop();
  link_project();
  link_propertyParameter();
  link_quasiUniformCurve();
  link_quasiUniformSurface();
  link_radiusedPocketBottomCondition();
  link_radiusedSlotEndType();
  link_rapidMovement();
  link_rationalBSplineCurve();
  link_rationalBSplineSurface();
  link_reamer();
  link_reaming();
  link_rectangularClosedProfile();
  link_rectangularClosedShapeProfile();
  link_rectangularOffset();
  link_rectangularOmit();
  link_rectangularOpenShapeProfile();
  link_rectangularPattern();
  link_region();
  link_regionProjection();
  link_regionSurfaceList();
  link_replicateFeature();
  link_representationParent();
  link_representation();
  link_representationItem();
  link_restrictedAreaSelect();
  link_rightCircularCylinder();
  link_roundedEnd();
  link_roundedUProfile();
  link_roundHole();
  link_rvalue();
  link_selective();
  link_setMark();
  link_setup();
  link_setupInstruction();
  link_shapeProfile();
  link_shapeRepresentationParent();
  link_shapeRepresentation();
  link_sideMill();
  link_sideMilling();
  link_sideFinishMilling();
  link_sideRoughMilling();
  link_slot();
  link_slotEndType();
  link_solidModel();
  link_spadeDrill();
  link_specification();
  link_specificationUsageConstraint();
  link_sphericalCap();
  link_sphericalHoleBottom();
  link_sphericalSurface();
  link_squareUProfile();
  link_step();
  link_surface();
  link_surfaceOfLinearExtrusion();
  link_surfaceOfRevolution();
  link_surfaceTextureParameter();
  link_sweptSurface();
  link_tap();
  link_taperedTap();
  link_tapParent();
  link_taperedDrill();
  link_taperedEndmill();
  link_taperedReamer();
  link_taperSelect();
  link_tapping();
  link_technology();
  link_teeProfile();
  link_thread();
  link_threadDrilling();
  link_threadMill();
  link_threeAxes();
  link_threeAxesTiltedTool();
  link_throughBottomCondition();
  link_throughPocketBottomCondition();
  link_throughProfileFloor();
  link_tolerancedLengthMeasure();
  link_tolerances();
  link_toleranceSelect();
  link_toolBody();
  link_toolDirection();
  link_toolDirectionForMilling();
  link_toolLengthProbing();
  link_toolpath();
  link_toolpathFeature();
  link_toolpathList();
  link_toolpathSpeed();
  link_toolpathSpeedprofile();
  link_toolProbing();
  link_toolRadiusProbing();
  link_topologicalRegion();
  link_topologicalRepresentationItem();
  link_touchProbe();
  link_touchProbing();
  link_trajectory();
  link_transitionFeature();
  link_travelPath();
  link_trimmedCurve();
  link_trimmingSelect();
  link_tSlotMill();
  link_twistDrillParent();
  link_twistDrill();
  link_twoAxes();
  link_two5DmanufacturingFeature();
  link_two5DmillingOperation();
  link_two5DmillingStrategy();
  link_unaryBooleanExpression();
  link_unidirectionalMilling();
  link_uniformCurve();
  link_uniformSurface();
  link_unloadTool();
  link_userDefinedTool();
  link_uvStrategy();
  link_vector();
  link_veeProfile();
  link_vertex();
  link_vertexLoop();
  link_vertexPoint();
  link_waitForMark();
  link_weekOfYearAndDayDate();
  link_whileStatement();
  link_woodruffKeyseatMill();
  link_woodruffSlotEndType();
  link_workingstep();
  link_workpiece();
  link_workpieceCompleteProbing();
  link_workpieceProbing();
  link_workpieceSetup();
  link_workplan();
  link_xorExpression();
  for (n = 0; n < INSTANCEMAX; n++)
    {
      instances[n] = 0;
    }
}

/********************************************************************/

/* yyerror

If lexMessage contains a message, lexMessage[0] will not be 0,
and a syntax error will have occurred, since BAD will have been
returned by the lexer. In this case, only the lexMessage is
printed, since reporting the syntax error (s) only adds confusion.

*/

int yyerror(char * s)
{
  int n;

  if (lexMessage[0])
    {
      fprintf(report, "Error: %s\n", lexMessage);
      lexMessage[0] = 0;
    }
  else
    fprintf(report, "Error: %s\n", s);
  fprintf(report, "%s\n", lineText);
  for (n = 0; lineText[n] != 0; n++);
  if (lineText[n-1] != '\n')
    fprintf(report, "\n");
  return 0;
}

/********************************************************************/

int yyparse();

/********************************************************************/

/* parseManyFiles

This parses all the input files whose names are given in the
file whose name is fileNameFile. As it runs, it prints the name
of each file it parses followed by either "0 errors" or some error
messages followed by "N errors".

*/

void parseManyFiles(
 char * fileNameFile,
 char * reportName)
{
  FILE * fileList;
  static char fileName[256];
  int nameLength;

  fileList = fopen(fileNameFile, "r");
  if (fileList == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n",
              fileNameFile);
      exit(1);
    }
  if (reportName)
    {
      report = fopen(reportName, "wb");
      if (report == 0)
        {
          fprintf(stderr, "unable to open file %s for writing\n",
                  reportName);
	  exit(1);
	}
    }
  else
    report = stdout;
  lexMessage[0] = 0;
  while (fgets(fileName, 256, fileList))
    {
      nameLength = strlen(fileName);
      if (nameLength == 255)
	{
	  fprintf(stderr, "file name too long: %s\n", fileName);
	  exit(1);
        }
      while ((fileName[nameLength - 1] == 10) ||
             (fileName[nameLength - 1] == 13))
	{ // get rid of the end of line character(s)
	  fileName[nameLength - 1] = 0;
	  nameLength--;
	}
      if (strcmp((fileName + nameLength - 4), ".stp"))
	{
	  fprintf(stderr, "file name does not end in .stp: %s\n",
                  fileName);
	  exit(1);
	}
      fprintf(report, "*****************************************\n\n");
      fprintf(report, "%s\n\n", fileName);
      yyin = fopen(fileName, "rb");
      if (yyin == 0)
	{
	  fprintf(stderr, "unable to open file %s for reading\n",
                  fileName);
	  exit(1);
	}
      yyparse();
      fclose(yyin);
      if (numErrors == 0)
	linkAll();
      fprintf(report, "%d errors\n\n", numErrors);
      if (tree)
	{
	  delete tree;
	  tree = 0;
	}
      numErrors = 0;
    }
  fclose(fileList);
  fprintf(report, "\n");
  if (report != stdout)
    fclose(report);
}

/********************************************************************/

/* parseOneFile

This parses one input file.

*/

int parseOneFile(
 const char * part21Name,
 char * reportName,
 bool quiet)
{
  if (reportName)
    {
      report = fopen(reportName, "wb");
      if (report == 0)
        {
          fprintf(stderr, "unable to open file %s for writing\n",
                  reportName);
	  exit(1);
	}
    }
  else
    report = stdout;
  lexMessage[0] = 0;
  yyin = fopen(part21Name, "rb");
  if (yyin == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n",
              part21Name);
      exit(1);
    }
  yyparse();
  fclose(yyin);
  if (numErrors == 0)
    linkAll();
  else if (tree)
    {
      delete tree;
      tree = 0;
    }
  if (!quiet || numErrors)
    fprintf(report, "%d error%s\n",
	    numErrors, ((numErrors == 1) ? "" : "s"));
  if (report != stdout)
    fclose(report);
  return numErrors;
}

/********************************************************************/

%}

%union {
  inputFile                        * val1;
  instance                         * val2;
  address                          * val3;
  advancedBrepShapeRepresentation  * val4;
  advancedFace                     * val5;
  aheadOrBehind                    * val6;
  aheadOrBehindAhead               * val7;
  aheadOrBehindBehind              * val8;
  aheadOrBehindExact               * val9;
  alongPath                        * val10;
  andExpression                    * val11;
  angleTaper                       * val12;
  apLiftPathAngle                  * val13;
  apLiftPathTangent                * val14;
  approval                         * val15;
  approvalStatus                   * val16;
  apRetractAngle                   * val17;
  apRetractTangent                 * val18;
  assignment                       * val19;
  aString                          * val20;
  axis1placement                   * val21;
  axis2placement3d                 * val22;
  std::list<axis2placement3d *>    * val23;
  axisTrajectory                   * val24;
  backBoring                       * val25;
  backsideCounterbore              * val26;
  backsideCountersink              * val27;
  ballEndmill                      * val28;
  bezierCurve                      * val29;
  bezierSurface                    * val30;
  bidirectionalContour             * val31;
  bidirectionalMilling             * val32;
  block                            * val33;
  boolean                          * val34;
  std::list<booleanExpression *>   * val35;
  booleanFalse                     * val36;
  booleanTrue                      * val37;
  boring                           * val38;
  boringTool                       * val39;
  boss                             * val40;
  std::list<boss *>                * val41;
  bottomAndSideFinishMilling       * val42;
  bottomAndSideRoughMilling        * val43;
  bottomOrSide                     * val44;
  bottomOrSideBottom               * val45;
  bottomOrSideSide                 * val46;
  bottomOrSideBottomAndSide        * val47;
  std::list<boundedCurve *>        * val48;
  boundedPCurve                    * val49;
  std::list<boundedSurface *>      * val50;
  bSplineCurveForm                 * val51;
  bSplineCurveFormPolylineForm     * val52;
  bSplineCurveFormCircularArc      * val53;
  bSplineCurveFormEllipticArc      * val54;
  bSplineCurveFormParabolicArc     * val55;
  bSplineCurveFormHyperbolicArc    * val56;
  bSplineCurveFormUnspecified      * val57;
  bSplineCurveWithKnots            * val58;
  bSplineSurfaceForm               * val59;
  bSplineSurfaceFormConicalSurf    * val60;
  bSplineSurfaceFormCylindricalSurf * val61;
  bSplineSurfaceFormGeneralizedCone * val62;
  bSplineSurfaceFormPlaneSurf      * val63;
  bSplineSurfaceFormQuadricSurf    * val64;
  bSplineSurfaceFormRuledSurf      * val65;
  bSplineSurfaceFormSphericalSurf  * val66;
  bSplineSurfaceFormSurfOfLinearExtrusion * val67;
  bSplineSurfaceFormSurfOfRevolution * val68;
  bSplineSurfaceFormToroidalSurf   * val69;
  bSplineSurfaceFormUnspecified    * val70;
  bSplineSurfaceWithKnots          * val71;
  bullnoseEndmill                  * val72;
  calendarDate                     * val73;
  cartesianPoint                   * val74;
  std::list<cartesianPoint *>      * val75;
  catalogueThread                  * val76;
  centerDrill                      * val77;
  centerDrilling                   * val78;
  centerMilling                    * val79;
  chamfer                          * val80;
  channel                          * val81;
  circle                           * val82;
  circularClosedProfile            * val83;
  circularClosedShapeProfile       * val84;
  circularOffset                   * val85;
  std::list<circularOffset *>      * val86;
  circularOmit                     * val87;
  std::list<circularOmit *>        * val88;
  circularPattern                  * val89;
  closedPocket                     * val90;
  closedShell                      * val91;
  combinedDrillAndReamer           * val92;
  combinedDrillAndTap              * val93;
  comparisonEqual                  * val94;
  comparisonGreater                * val95;
  comparisonGreaterEqual           * val96;
  comparisonLess                   * val97;
  comparisonLessEqual              * val98;
  comparisonNotEqual               * val99;
  completeCircularPath             * val100;
  compositeCurve                   * val101;
  compositeCurveSegment            * val102;
  std::list<compositeCurveSegment *> * val103;
  std::list<compoundFeatureSelect *> * val104;
  conicalHoleBottom                * val105;
  connectDirect                    * val106;
  connectSecplane                  * val107;
  contactType                      * val108;
  contactTypeSide                  * val109;
  contactTypeFront                 * val110;
  contourBidirectional             * val111;
  contourParallel                  * val112;
  contourSpiral                    * val113;
  coordinatedUniversalTimeOffset   * val114;
  counterbore                      * val115;
  counterboreHole                  * val116;
  countersink                      * val117;
  counterSinking                   * val118;
  countersunkHole                  * val119;
  curveWithNormalVector            * val120;
  cutmodeType                      * val121;
  cutmodeTypeClimb                 * val122;
  cutmodeTypeConventional          * val123;
  cutterContactTrajectory          * val124;
  cutterLocationTrajectory         * val125;
  cuttingComponent                 * val126;
  std::list<cuttingComponent *>    * val127;
  cuttingEdgeTechnologicalData     * val128;
  dataSection                      * val129;
  dataStarter                      * val130;
  dateAndTime                      * val131;
  definedThread                    * val132;
  definitionalRepresentation       * val133;
  descriptiveParameter             * val134;
  diameterTaper                    * val135;
  direction                        * val136;
  displayMessage                   * val137;
  dovetailMill                     * val138;
  drilling                         * val139;
  drillingTypeStrategy             * val140;
  edgeCurve                        * val141;
  edgeLoop                         * val142;
  edgeRound                        * val143;
  ellipse                          * val144;
  endSection                       * val145;
  exchangePallet                   * val146;
  std::list<executable *>          * val147;
  explicitStrategy                 * val148;
  std::list<face *>                * val149;
  facemill                         * val150;
  faceBound                        * val151;
  std::list<faceBound *>           * val152;
  faceOuterBound                   * val153;
  feedstop                         * val154;
  fileDescription                  * val155;
  fileEnd                          * val156;
  fileName                         * val157;
  fileSchema                       * val158;
  fileStart                        * val159;
  fittingType                      * val160;
  fittingTypeHole                  * val161;
  fittingTypeShaft                 * val162;
  fiveAxesVarTiltYaw               * val163;
  fiveAxesConstTiltYaw             * val164;
  flatHoleBottom                   * val165;
  flatSlotEndType                  * val166;
  flatWithRadiusHoleBottom         * val167;
  freeformOperation                * val168;
  generalClosedProfile             * val169;
  generalOutsideProfile            * val170;
  generalPath                      * val171;
  generalPattern                   * val172;
  generalPocketBottomCondition     * val173;
  generalProfile                   * val174;
  generalProfileFloor              * val175;
  generalShapeProfile              * val176;
  hand                             * val177;
  handLeft                         * val178;
  handNeutral                      * val179;
  handRight                        * val180;
  headerSection                    * val181;
  headerStarter                    * val182;
  helix                            * val183;
  hyperbola                        * val184;
  ifStatement                      * val185;
  indexPallet                      * val186;
  indexTable                       * val187;
  inProcessGeometry                * val188;
  instanceId                       * val189;
  std::list<instance *>            * val190;
  integer                          * val191;
  std::list<integer *>             * val192;
  knotType                         * val193;
  knotTypePiecewiseBezierKnots     * val194;
  knotTypeQuasiUniformKnots        * val195;
  knotTypeUniformKnots             * val196;
  knotTypeUnspecified              * val197;
  leadingLineStrategy              * val198;
  leftOrRight                      * val199;
  leftOrRightLeft                  * val200;
  leftOrRightRight                 * val201;
  limitsAndFits                    * val202;
  line                             * val203;
  linearPath                       * val204;
  linearProfile                    * val205;
  loadTool                         * val206;
  localTime                        * val207;
  logical                          * val208;
  logicalFalse                     * val209;
  logicalTrue                      * val210;
  logicalUnknown                   * val211;
  loopSlotEndType                  * val212;
  machinedSurface                  * val213;
  std::list<machinedSurface *>     * val214;
  std::list<machiningFeature *>    * val215;
  std::list<machiningOperation *>  * val216;
  machiningWorkingstep             * val217;
  manifoldSolidBrep                * val218;
  material                         * val219;
  millingCuttingTool               * val220;
  millingMachineFunctions          * val221;
  millingTechnology                * val222;
  millingThreadingTool             * val223;
  millingToolDimension             * val224;
  multistepDrilling                * val225;
  ncConstant                       * val226;
  ncVariable                       * val227;
  std::list<ncVariable *>          * val228;
  ngonClosedProfile                * val229;
  nonSequential                    * val230;
  notExpression                    * val231;
  numericParameter                 * val232;
  offsetVector                     * val233;
  openPocket                       * val234;
  openShell                        * val235;
  openSlotEndType                  * val236;
  optionalStop                     * val237;
  orExpression                     * val238;
  orientedEdge                     * val239;
  std::list<orientedEdge *>        * val240;
  ordinalDate                      * val241;
  parabola                         * val242;
  parallel                         * val243;
  parenAxis2placement3dListFull    * val244;
  parenBooleanExpressionListFull   * val245;
  parenBossList                    * val246;
  parenBoundedCurveListFull        * val247;
  parenBoundedSurfaceListFull      * val248;
  parenCartesianPointList          * val249;
  parenCartesianPointListFull      * val250;
  std::list<parenCartesianPointListFull *> * val251;
  parenCircularOffsetList          * val252;
  parenCircularOmitList            * val253;
  parenCompositeCurveSegmentListFull * val254;
  parenCompoundFeatureSelectListFull * val255;
  parenCuttingComponentListFull    * val256;
  parenExecutableList              * val257;
  parenExecutableListFull          * val258;
  parenFaceBoundListFull           * val259;
  parenFaceListFull                * val260;
  parenIntegerListFull             * val261;
  parenMachinedSurfaceListFull     * val262;
  parenMachiningFeatureListFull    * val263;
  parenMachiningOperationList      * val264;
  parenNcVariableListFull          * val265;
  parenOrientedEdgeListFull        * val266;
  parenParenCartesianPointListFullListFull * val267;
  parenParenRealListFullListFull   * val268;
  parenProcessModelLiszt           * val269;
  parenPropertyParameterList       * val270;
  parenRealListFull                * val271;
  std::list<parenRealListFull *>   * val272;
  parenRectangularOffsetList       * val273;
  parenRectangularOmitList         * val274;
  parenRepresentationItemListFull  * val275;
  parenSetupInstructionList        * val276;
  parenSlotEndTypeList             * val277;
  parenSpecificationUsageConstraintList * val278;
  parenStringList                  * val279;
  parenStringListFull              * val280;
  parenToolpathLisztFull           * val281;
  parenTrimmingSelectListFull      * val282;
  parenWorkpieceList               * val283;
  parenWorkpieceSetupList          * val284;
  partialAreaDefinition            * val285;
  partialCircularPath              * val286;
  partialCircularProfile           * val287;
  partialCircularShapeProfile      * val288;
  pathmodeType                     * val289;
  pathmodeTypeForward              * val290;
  pathmodeTypeZigzag               * val291;
  pcurve                           * val292;
  person                           * val293;
  personAndAddress                 * val294;
  planarFace                       * val295;
  planarPocketBottomCondition      * val296;
  planarProfileFloor               * val297;
  plane                            * val298;
  planeCcStrategy                  * val299;
  planeClStrategy                  * val300;
  planeFinishMilling               * val301;
  planeRoughMilling                * val302;
  plungeHelix                      * val303;
  plungeRamp                       * val304;
  plungeToolaxis                   * val305;
  plungeZigzag                     * val306;
  plusMinusValue                   * val307;
  polyline                         * val308;
  processModel                     * val309;
  processModelList                 * val310;
  std::list<processModel *>        * val311;
  programStop                      * val312;
  project                          * val313;
  std::list<propertyParameter *>   * val314;
  quasiUniformCurve                * val315;
  quasiUniformSurface              * val316;
  radiusedPocketBottomCondition    * val317;
  radiusedSlotEndType              * val318;
  rapidMovement                    * val319;
  rationalBSplineCurve             * val320;
  rationalBSplineSurface           * val321;
  real                             * val322;
  std::list<real *>                * val323;
  reaming                          * val324;
  rectangularClosedProfile         * val325;
  rectangularClosedShapeProfile    * val326;
  rectangularOffset                * val327;
  std::list<rectangularOffset *>   * val328;
  rectangularOmit                  * val329;
  std::list<rectangularOmit *>     * val330;
  rectangularOpenShapeProfile      * val331;
  rectangularPattern               * val332;
  regionProjection                 * val333;
  regionSurfaceList                * val334;
  representation                   * val335;
  representationContext            * val336;
  std::list<representationItem *>  * val337;
  rightCircularCylinder            * val338;
  rotDirection                     * val339;
  rotDirectionCw                   * val340;
  rotDirectionCcw                  * val341;
  roundedEnd                       * val342;
  roundedUProfile                  * val343;
  roundHole                        * val344;
  selective                        * val345;
  setMark                          * val346;
  setup                            * val347;
  setupInstruction                 * val348;
  std::list<setupInstruction *>    * val349;
  shapeRepresentation              * val350;
  sideMill                         * val351;
  sideFinishMilling                * val352;
  sideRoughMilling                 * val353;
  slot                             * val354;
  std::list<slotEndType *>         * val355;
  spadeDrill                       * val356;
  specification                    * val357;
  specificationUsageConstraint     * val358;
  std::list<specificationUsageConstraint *> * val359;
  speedName                        * val360;
  sphericalCap                     * val361;
  sphericalHoleBottom              * val362;
  sphericalSurface                 * val363;
  squareUProfile                   * val364;
  step                             * val365;
  std::list<char *>                * val366;
  strokeConnectionStrategy         * val367;
  strokeConnectionStrategyDegouge  * val368;
  strokeConnectionStrategyLiftShiftPlunge * val369;
  strokeConnectionStrategyLoopBack * val370;
  strokeConnectionStrategyStraightline * val371;
  surfaceOfLinearExtrusion         * val372;
  surfaceOfRevolution              * val373;
  surfaceTextureParameter          * val374;
  tap                              * val375;
  taperedTap                       * val376;
  taperedDrill                     * val377;
  taperedEndmill                   * val378;
  taperedReamer                    * val379;
  tapping                          * val380;
  teeProfile                       * val381;
  threadDrilling                   * val382;
  threadMill                       * val383;
  threeAxes                        * val384;
  threeAxesTiltedTool              * val385;
  throughBottomCondition           * val386;
  throughPocketBottomCondition     * val387;
  throughProfileFloor              * val388;
  tolerancedLengthMeasure          * val389;
  tolerances                       * val390;
  toolLengthProbing                * val391;
  toolpathFeature                  * val392;
  toolpathList                     * val393;
  std::list<toolpath *>            * val394;
  toolpathSpeed                    * val395;
  toolpathSpeedprofile             * val396;
  toolpathType                     * val397;
  toolpathTypeApproach             * val398;
  toolpathTypeConnect              * val399;
  toolpathTypeContact              * val400;
  toolpathTypeLift                 * val401;
  toolpathTypeNonContact           * val402;
  toolpathTypeTrajectoryPath       * val403;
  toolRadiusProbing                * val404;
  toolReferencePoint               * val405;
  toolReferencePointCcp            * val406;
  toolReferencePointTcp            * val407;
  topologicalRegion                * val408;
  touchProbe                       * val409;
  transitionCode                   * val410;
  transitionCodeContinuous         * val411;
  transitionCodeContSameGradient   * val412;
  transitionCodeContSameGradientSameCurvature * val413;
  transitionCodeDiscontinuous      * val414;
  trimmedCurve                     * val415;
  trimmingPreference               * val416;
  trimmingPreferenceCartesian      * val417;
  trimmingPreferenceParameter      * val418;
  trimmingPreferenceUnspecified    * val419;
  trimmingSelect                   * val420;
  std::list<trimmingSelect *>      * val421;
  tSlotMill                        * val422;
  twistDrill                       * val423;
  twoAxes                          * val424;
  unidirectionalMilling            * val425;
  uniformCurve                     * val426;
  uniformSurface                   * val427;
  unloadTool                       * val428;
  userDefinedTool                  * val429;
  uvStrategy                       * val430;
  vector                           * val431;
  veeProfile                       * val432;
  vertexLoop                       * val433;
  vertexPoint                      * val434;
  waitForMark                      * val435;
  weekOfYearAndDayDate             * val436;
  whileStatement                   * val437;
  woodruffKeyseatMill              * val438;
  woodruffSlotEndType              * val439;
  workpiece                        * val440;
  workpieceCompleteProbing         * val441;
  std::list<workpiece *>           * val442;
  workpieceProbing                 * val443;
  workpieceSetup                   * val444;
  std::list<workpieceSetup *>      * val445;
  workplan                         * val446;
  xorExpression                    * val447;
  char                             * sval;
  int                                ival;
  double                             rval;
}

%type <val1> inputFile
%type <val2> instance
%type <val2> instancePlus
%type <val3> address
%type <val3> optAddress
%type <val4> advancedBrepShapeRepresentation
%type <val4> optAdvancedBrepShapeRepresentation
%type <val4> optBoundingGeometrySelect
%type <val4> optRestrictedAreaSelect
%type <val5> advancedFace
%type <val6> aheadOrBehind
%type <val7> aheadOrBehindAhead
%type <val8> aheadOrBehindBehind
%type <val9> aheadOrBehindExact
%type <val10> alongPath
%type <val10> optApproachRetractStrategy
%type <val11> andExpression
%type <val12> angleTaper
%type <val12> optTaperSelect
%type <val13> apLiftPathAngle
%type <val14> apLiftPathTangent
%type <val15> approval
%type <val15> optApproval
%type <val16> approvalStatus
%type <val17> apRetractAngle
%type <val18> apRetractTangent
%type <val19> assignment
%type <val19> optExecutable
%type <val20> aString
%type <val20> optString
%type <val21> axis1placement
%type <val22> axis2placement3d
%type <val22> optAxis2placement3d
%type <val23> axis2placement3dList
%type <val24> axisTrajectory
%type <val25> backBoring
%type <val26> backsideCounterbore
%type <val27> backsideCountersink
%type <val28> ballEndmill
%type <val29> bezierCurve
%type <val29> optBoundedCurve
%type <val30> bezierSurface
%type <val31> bidirectionalContour
%type <val31> optTwo5DmillingStrategy
%type <val32> bidirectionalMilling
%type <val33> block
%type <val34> boolean
%type <val34> optBoolean
%type <val35> booleanExpressionList
%type <val36> booleanFalse
%type <val37> booleanTrue
%type <val38> boring
%type <val39> boringTool
%type <val40> boss
%type <val41> bossList
%type <val42> bottomAndSideFinishMilling
%type <val43> bottomAndSideRoughMilling
%type <val44> bottomOrSide
%type <val45> bottomOrSideBottom
%type <val46> bottomOrSideSide
%type <val47> bottomOrSideBottomAndSide
%type <val48> boundedCurveList
%type <val49> boundedPCurve
%type <val50> boundedSurfaceList
%type <val51> bSplineCurveForm
%type <val52> bSplineCurveFormPolylineForm
%type <val53> bSplineCurveFormCircularArc
%type <val54> bSplineCurveFormEllipticArc
%type <val55> bSplineCurveFormParabolicArc
%type <val56> bSplineCurveFormHyperbolicArc
%type <val57> bSplineCurveFormUnspecified
%type <val58> bSplineCurveWithKnots
%type <val59> bSplineSurfaceForm
%type <val60> bSplineSurfaceFormConicalSurf
%type <val61> bSplineSurfaceFormCylindricalSurf
%type <val62> bSplineSurfaceFormGeneralizedCone
%type <val63> bSplineSurfaceFormPlaneSurf
%type <val64> bSplineSurfaceFormQuadricSurf
%type <val65> bSplineSurfaceFormRuledSurf
%type <val66> bSplineSurfaceFormSphericalSurf
%type <val67> bSplineSurfaceFormSurfOfLinearExtrusion
%type <val68> bSplineSurfaceFormSurfOfRevolution
%type <val69> bSplineSurfaceFormToroidalSurf
%type <val70> bSplineSurfaceFormUnspecified
%type <val71> bSplineSurfaceWithKnots
%type <val72> bullnoseEndmill
%type <val73> calendarDate
%type <val74> cartesianPoint
%type <val74> optCartesianPoint
%type <val75> cartesianPointList
%type <val76> catalogueThread
%type <val77> centerDrill
%type <val78> centerDrilling
%type <val79> centerMilling
%type <val80> chamfer
%type <val81> channel
%type <val81> optChannel
%type <val82> circle
%type <val83> circularClosedProfile
%type <val83> optClosedProfile
%type <val84> circularClosedShapeProfile
%type <val85> circularOffset
%type <val86> circularOffsetList
%type <val87> circularOmit
%type <val88> circularOmitList
%type <val89> circularPattern
%type <val90> closedPocket
%type <val91> closedShell
%type <val92> combinedDrillAndReamer
%type <val93> combinedDrillAndTap
%type <val94> comparisonEqual
%type <val95> comparisonGreater
%type <val96> comparisonGreaterEqual
%type <val97> comparisonLess
%type <val98> comparisonLessEqual
%type <val99> comparisonNotEqual
%type <val100> completeCircularPath
%type <val101> compositeCurve
%type <val102> compositeCurveSegment
%type <val103> compositeCurveSegmentList
%type <val104> compoundFeatureSelectList
%type <val105> conicalHoleBottom
%type <val106> connectDirect
%type <val107> connectSecplane
%type <val108> contactType
%type <val108> optContactType
%type <val109> contactTypeSide
%type <val110> contactTypeFront
%type <val111> contourBidirectional
%type <val112> contourParallel
%type <val113> contourSpiral
%type <val114> coordinatedUniversalTimeOffset
%type <val115> counterbore
%type <val116> counterboreHole
%type <val117> countersink
%type <val118> counterSinking
%type <val119> countersunkHole
%type <val120> curveWithNormalVector
%type <val121> cutmodeType
%type <val121> optCutmodeType
%type <val122> cutmodeTypeClimb
%type <val123> cutmodeTypeConventional
%type <val124> cutterContactTrajectory
%type <val125> cutterLocationTrajectory
%type <val126> cuttingComponent
%type <val127> cuttingComponentList
%type <val128> cuttingEdgeTechnologicalData
%type <val128> optCuttingEdgeTechnologicalData
%type <val129> dataSection
%type <val130> dataStarter
%type <val131> dateAndTime
%type <val131> optDateAndTime
%type <val132> definedThread
%type <val133> definitionalRepresentation
%type <val134> descriptiveParameter
%type <val134> optDescriptiveParameter
%type <val135> diameterTaper
%type <val136> direction
%type <val136> optDirection
%type <val137> displayMessage
%type <val138> dovetailMill
%type <val139> drilling
%type <val140> drillingTypeStrategy
%type <val140> optDrillingTypeStrategy
%type <val141> edgeCurve
%type <val142> edgeLoop
%type <val143> edgeRound
%type <val144> ellipse
%type <val145> endSection
%type <val146> exchangePallet
%type <val147> executableList
%type <val148> explicitStrategy
%type <val149> faceList
%type <val150> facemill
%type <val151> faceBound
%type <val152> faceBoundList
%type <val153> faceOuterBound
%type <val154> feedstop
%type <val155> fileDescription
%type <val156> fileEnd
%type <val157> fileName
%type <val158> fileSchema
%type <val159> fileStart
%type <val160> fittingType
%type <val160> optFittingType
%type <val161> fittingTypeHole
%type <val162> fittingTypeShaft
%type <val163> fiveAxesVarTiltYaw
%type <val164> fiveAxesConstTiltYaw
%type <val165> flatHoleBottom
%type <val166> flatSlotEndType
%type <val167> flatWithRadiusHoleBottom
%type <val168> freeformOperation
%type <val169> generalClosedProfile
%type <val170> generalOutsideProfile
%type <val171> generalPath
%type <val172> generalPattern
%type <val173> generalPocketBottomCondition
%type <val174> generalProfile
%type <val174> optOpenProfile
%type <val175> generalProfileFloor
%type <val176> generalShapeProfile
%type <val177> hand
%type <val177> optHand
%type <val178> handLeft
%type <val179> handNeutral
%type <val180> handRight
%type <val181> headerSection
%type <val182> headerStarter
%type <val183> helix
%type <val184> hyperbola
%type <val185> ifStatement
%type <val186> indexPallet
%type <val187> indexTable
%type <val188> inProcessGeometry
%type <val188> optInProcessGeometry
%type <val189> instanceId
%type <val190> instancePlusList
%type <val191> integer
%type <val191> optInteger
%type <val192> integerList
%type <val193> knotType
%type <val194> knotTypePiecewiseBezierKnots
%type <val195> knotTypeQuasiUniformKnots
%type <val196> knotTypeUniformKnots
%type <val197> knotTypeUnspecified
%type <val198> leadingLineStrategy
%type <val198> optFreeformStrategy
%type <val199> leftOrRight
%type <val199> optLeftOrRight
%type <val200> leftOrRightLeft
%type <val201> leftOrRightRight
%type <val202> limitsAndFits
%type <val203> line
%type <val204> linearPath
%type <val205> linearProfile
%type <val206> loadTool
%type <val207> localTime
%type <val208> logical
%type <val209> logicalFalse
%type <val210> logicalTrue
%type <val211> logicalUnknown
%type <val212> loopSlotEndType
%type <val213> machinedSurface
%type <val214> machinedSurfaceList
%type <val215> machiningFeatureList
%type <val216> machiningOperationList
%type <val217> machiningWorkingstep
%type <val218> manifoldSolidBrep
%type <val219> material
%type <val219> optMaterial
%type <val220> millingCuttingTool
%type <val220> optMachiningTool
%type <val221> millingMachineFunctions
%type <val221> optMachineFunctions
%type <val222> millingTechnology
%type <val222> optMillingTechnology
%type <val222> optTechnology
%type <val223> millingThreadingTool
%type <val224> millingToolDimension
%type <val225> multistepDrilling
%type <val226> ncConstant
%type <val227> ncVariable
%type <val228> ncVariableList
%type <val229> ngonClosedProfile
%type <val230> nonSequential
%type <val231> notExpression
%type <val232> numericParameter
%type <val233> offsetVector
%type <val233> optOffsetVector
%type <val234> openPocket
%type <val235> openShell
%type <val236> openSlotEndType
%type <val237> optionalStop
%type <val238> orExpression
%type <val239> orientedEdge
%type <val240> orientedEdgeList
%type <val241> ordinalDate
%type <val242> parabola
%type <val243> parallel
%type <val244> parenAxis2placement3dListFull
%type <val245> parenBooleanExpressionListFull
%type <val246> parenBossList
%type <val247> parenBoundedCurveListFull
%type <val248> parenBoundedSurfaceListFull
%type <val249> parenCartesianPointList
%type <val250> parenCartesianPointListFull
%type <val251> parenCartesianPointListFullList
%type <val252> parenCircularOffsetList
%type <val253> parenCircularOmitList
%type <val254> parenCompositeCurveSegmentListFull
%type <val255> parenCompoundFeatureSelectListFull
%type <val256> parenCuttingComponentListFull
%type <val257> parenExecutableList
%type <val258> parenExecutableListFull
%type <val259> parenFaceBoundListFull
%type <val260> parenFaceListFull
%type <val261> parenIntegerListFull
%type <val262> parenMachinedSurfaceListFull
%type <val263> parenMachiningFeatureListFull
%type <val264> parenMachiningOperationList
%type <val265> parenNcVariableListFull
%type <val265> optParenNcVariableListFull
%type <val266> parenOrientedEdgeListFull
%type <val267> parenParenCartesianPointListFullListFull
%type <val268> parenParenRealListFullListFull
%type <val269> parenProcessModelLiszt
%type <val270> parenPropertyParameterList
%type <val271> parenRealListFull
%type <val272> parenRealListFullList
%type <val273> parenRectangularOffsetList
%type <val274> parenRectangularOmitList
%type <val275> parenRepresentationItemListFull
%type <val276> parenSetupInstructionList
%type <val277> parenSlotEndTypeList
%type <val278> parenSpecificationUsageConstraintList
%type <val279> parenStringList
%type <val280> parenStringListFull
%type <val280> optParenStringListFull
%type <val281> parenToolpathLisztFull
%type <val282> parenTrimmingSelectListFull
%type <val283> parenWorkpieceList
%type <val284> parenWorkpieceSetupList
%type <val285> partialAreaDefinition
%type <val286> partialCircularPath
%type <val287> partialCircularProfile
%type <val288> partialCircularShapeProfile
%type <val289> pathmodeType
%type <val290> pathmodeTypeForward
%type <val291> pathmodeTypeZigzag
%type <val292> pcurve
%type <val293> person
%type <val294> personAndAddress
%type <val294> optPersonAndAddress
%type <val295> planarFace
%type <val296> planarPocketBottomCondition
%type <val297> planarProfileFloor
%type <val298> plane
%type <val299> planeCcStrategy
%type <val300> planeClStrategy
%type <val301> planeFinishMilling
%type <val302> planeRoughMilling
%type <val303> plungeHelix
%type <val304> plungeRamp
%type <val305> plungeToolaxis
%type <val306> plungeZigzag
%type <val307> plusMinusValue
%type <val308> polyline
%type <val309> processModel
%type <val310> processModelList
%type <val310> optProcessModelList
%type <val311> processModelLiszt
%type <val312> programStop
%type <val313> project
%type <val314> propertyParameterList
%type <val315> quasiUniformCurve
%type <val316> quasiUniformSurface
%type <val317> radiusedPocketBottomCondition
%type <val318> radiusedSlotEndType
%type <val319> rapidMovement
%type <val320> rationalBSplineCurve
%type <val321> rationalBSplineSurface
%type <val322> real
%type <val322> optReal
%type <val323> realList
%type <val324> reaming
%type <val325> rectangularClosedProfile
%type <val326> rectangularClosedShapeProfile
%type <val327> rectangularOffset
%type <val328> rectangularOffsetList
%type <val329> rectangularOmit
%type <val330> rectangularOmitList
%type <val331> rectangularOpenShapeProfile
%type <val332> rectangularPattern
%type <val333> regionProjection
%type <val334> regionSurfaceList
%type <val335> representation
%type <val336> representationContext
%type <val337> representationItemList
%type <val338> rightCircularCylinder
%type <val339> rotDirection
%type <val339> optRotDirection
%type <val340> rotDirectionCw
%type <val341> rotDirectionCcw
%type <val342> roundedEnd
%type <val343> roundedUProfile
%type <val344> roundHole
%type <val345> selective
%type <val346> setMark
%type <val347> setup
%type <val347> optSetup
%type <val348> setupInstruction
%type <val349> setupInstructionList
%type <val350> shapeRepresentation
%type <val351> sideMill
%type <val352> sideFinishMilling
%type <val353> sideRoughMilling
%type <val354> slot
%type <val355> slotEndTypeList
%type <val356> spadeDrill
%type <val357> specification
%type <val358> specificationUsageConstraint
%type <val359> specificationUsageConstraintList
%type <val360> speedName
%type <val361> sphericalCap
%type <val362> sphericalHoleBottom
%type <val363> sphericalSurface
%type <val364> squareUProfile
%type <val365> step
%type <val366> stringList
%type <val367> strokeConnectionStrategy
%type <val367> optStrokeConnectionStrategy
%type <val368> strokeConnectionStrategyDegouge
%type <val369> strokeConnectionStrategyLiftShiftPlunge
%type <val370> strokeConnectionStrategyLoopBack
%type <val371> strokeConnectionStrategyStraightline
%type <val372> surfaceOfLinearExtrusion
%type <val373> surfaceOfRevolution
%type <val374> surfaceTextureParameter
%type <val375> tap
%type <val376> taperedTap
%type <val377> taperedDrill
%type <val378> taperedEndmill
%type <val379> taperedReamer
%type <val380> tapping
%type <val381> teeProfile
%type <val382> threadDrilling
%type <val383> threadMill
%type <val384> threeAxes
%type <val384> optToolDirection
%type <val385> threeAxesTiltedTool
%type <val386> throughBottomCondition
%type <val387> throughPocketBottomCondition
%type <val388> throughProfileFloor
%type <val389> tolerancedLengthMeasure
%type <val389> optTolerancedLengthMeasure
%type <val390> tolerances
%type <val391> toolLengthProbing
%type <val392> toolpathFeature
%type <val393> toolpathList
%type <val393> optToolpathList
%type <val394> toolpathLiszt
%type <val395> toolpathSpeed
%type <val396> optToolpathSpeedprofile
%type <val397> toolpathType
%type <val398> toolpathTypeApproach
%type <val399> toolpathTypeConnect
%type <val400> toolpathTypeContact
%type <val401> toolpathTypeLift
%type <val402> toolpathTypeNonContact
%type <val403> toolpathTypeTrajectoryPath
%type <val404> toolRadiusProbing
%type <val405> toolReferencePoint
%type <val406> toolReferencePointCcp
%type <val407> toolReferencePointTcp
%type <val408> topologicalRegion
%type <val409> touchProbe
%type <val410> transitionCode
%type <val411> transitionCodeContinuous
%type <val412> transitionCodeContSameGradient
%type <val413> transitionCodeContSameGradientSameCurvature
%type <val414> transitionCodeDiscontinuous
%type <val415> trimmedCurve
%type <val416> trimmingPreference
%type <val417> trimmingPreferenceCartesian
%type <val418> trimmingPreferenceParameter
%type <val419> trimmingPreferenceUnspecified
%type <val421> trimmingSelectList
%type <val422> tSlotMill
%type <val423> twistDrill
%type <val424> twoAxes
%type <val425> unidirectionalMilling
%type <val426> uniformCurve
%type <val427> uniformSurface
%type <val428> unloadTool
%type <val429> userDefinedTool
%type <val430> uvStrategy
%type <val431> vector
%type <val432> veeProfile
%type <val432> optVeeProfile
%type <val433> vertexLoop
%type <val434> vertexPoint
%type <val435> waitForMark
%type <val436> weekOfYearAndDayDate
%type <val437> whileStatement
%type <val438> woodruffKeyseatMill
%type <val439> woodruffSlotEndType
%type <val440> workpiece
%type <val440> optWorkpiece
%type <val441> workpieceCompleteProbing
%type <val442> workpieceList
%type <val443> workpieceProbing
%type <val444> workpieceSetup
%type <val445> workpieceSetupList
%type <val446> workplan
%type <val447> xorExpression

%token ADDRESS
%token ADVANCEDBREPSHAPEREPRESENTATION
%token ADVANCEDFACE
%token AHEADORBEHINDAHEAD
%token AHEADORBEHINDBEHIND
%token AHEADORBEHINDEXACT
%token ALONGPATH
%token ANDEXPRESSION
%token ANGLETAPER
%token APLIFTPATHANGLE
%token APLIFTPATHTANGENT
%token APPROVAL
%token APPROVALSTATUS
%token APRETRACTANGLE
%token APRETRACTTANGENT
%token ASSIGNMENT
%token AXIS1PLACEMENT
%token AXIS2PLACEMENT3D
%token AXISTRAJECTORY
%token BACKBORING
%token BACKSIDECOUNTERBORE
%token BACKSIDECOUNTERSINK
%token BALLENDMILL
%token BEZIERCURVE
%token BEZIERSURFACE
%token BIDIRECTIONALCONTOUR
%token BIDIRECTIONALMILLING
%token BLOCK
%token BORING
%token BORINGTOOL
%token BOSS
%token BOTTOMANDSIDEFINISHMILLING
%token BOTTOMANDSIDEROUGHMILLING
%token BOTTOMORSIDEBOTTOM
%token BOTTOMORSIDEBOTTOMANDSIDE
%token BOTTOMORSIDESIDE
%token BOUNDEDPCURVE
%token BSPLINECURVEFORMCIRCULARARC
%token BSPLINECURVEFORMELLIPTICARC
%token BSPLINECURVEFORMHYPERBOLICARC
%token BSPLINECURVEFORMPARABOLICARC
%token BSPLINECURVEFORMPOLYLINEFORM
%token BSPLINECURVEFORMUNSPECIFIED
%token BSPLINECURVEWITHKNOTS
%token BSPLINESURFACEFORMCONICALSURF
%token BSPLINESURFACEFORMCYLINDRICALSURF
%token BSPLINESURFACEFORMGENERALIZEDCONE
%token BSPLINESURFACEFORMPLANESURF
%token BSPLINESURFACEFORMQUADRICSURF
%token BSPLINESURFACEFORMRULEDSURF
%token BSPLINESURFACEFORMSPHERICALSURF
%token BSPLINESURFACEFORMSURFOFLINEAREXTRUSION
%token BSPLINESURFACEFORMSURFOFREVOLUTION
%token BSPLINESURFACEFORMTOROIDALSURF
%token BSPLINESURFACEFORMUNSPECIFIED
%token BSPLINESURFACEWITHKNOTS
%token BULLNOSEENDMILL
%token C
%token CALENDARDATE
%token CARTESIANPOINT
%token CATALOGUETHREAD
%token CENTERDRILL
%token CENTERDRILLING
%token CENTERMILLING
%token CHAMFER
%token CHANNEL
%token CIRCLE
%token CIRCULARCLOSEDPROFILE
%token CIRCULARCLOSEDSHAPEPROFILE
%token CIRCULAROFFSET
%token CIRCULAROMIT
%token CIRCULARPATTERN
%token CLOSEDPOCKET
%token CLOSEDSHELL
%token COMBINEDDRILLANDREAMER
%token COMBINEDDRILLANDTAP
%token COMPARISONEQUAL
%token COMPARISONGREATER
%token COMPARISONGREATEREQUAL
%token COMPARISONLESS
%token COMPARISONLESSEQUAL
%token COMPARISONNOTEQUAL
%token COMPLETECIRCULARPATH
%token COMPOSITECURVE
%token COMPOSITECURVESEGMENT
%token CONICALHOLEBOTTOM
%token CONNECTDIRECT
%token CONNECTSECPLANE
%token CONTACTTYPEFRONT
%token CONTACTTYPESIDE
%token CONTOURBIDIRECTIONAL
%token CONTOURPARALLEL
%token CONTOURSPIRAL
%token COORDINATEDUNIVERSALTIMEOFFSET
%token COUNTERBORE
%token COUNTERBOREHOLE
%token COUNTERSINK
%token COUNTERSINKING
%token COUNTERSUNKHOLE
%token CURVEWITHNORMALVECTOR
%token CUTMODETYPECLIMB
%token CUTMODETYPECONVENTIONAL
%token CUTTERCONTACTTRAJECTORY
%token CUTTERLOCATIONTRAJECTORY
%token CUTTINGCOMPONENT
%token CUTTINGEDGETECHNOLOGICALDATA
%token DATA
%token DATEANDTIME
%token DEFINEDTHREAD
%token DEFINITIONALREPRESENTATION
%token DESCRIPTIVEPARAMETER
%token DIAMETERTAPER
%token DIRECTION
%token DISPLAYMESSAGE
%token DOVETAILMILL
%token DRILLING
%token DRILLINGTYPESTRATEGY
%token EDGECURVE
%token EDGELOOP
%token EDGEROUND
%token ELLIPSE
%token ENDSEC
%token EXCHANGEPALLET
%token EXPLICITSTRATEGY
%token FACEBOUND
%token FACEMILL
%token FACEOUTERBOUND
%token FALSE
%token FEEDSTOP
%token FILEDESCRIPTION
%token FILEEND
%token FILENAME
%token FILESCHEMA
%token FILESTART
%token FITTINGTYPEHOLE
%token FITTINGTYPESHAFT
%token FIVEAXESCONSTTILTYAW
%token FIVEAXESVARTILTYAW
%token FLATHOLEBOTTOM
%token FLATSLOTENDTYPE
%token FLATWITHRADIUSHOLEBOTTOM
%token FREEFORMOPERATION
%token GENERALCLOSEDPROFILE
%token GENERALOUTSIDEPROFILE
%token GENERALPATH
%token GENERALPATTERN
%token GENERALPOCKETBOTTOMCONDITION
%token GENERALPROFILE
%token GENERALPROFILEFLOOR
%token GENERALSHAPEPROFILE
%token HEADER
%token HELIX
%token HYPERBOLA
%token IFSTATEMENT
%token INDEXPALLET
%token INDEXTABLE
%token INPROCESSGEOMETRY
%token KNOTTYPEPIECEWISEBEZIERKNOTS
%token KNOTTYPEQUASIUNIFORMKNOTS
%token KNOTTYPEUNIFORMKNOTS
%token KNOTTYPEUNSPECIFIED
%token LEADINGLINESTRATEGY
%token LEFT
%token LIMITSANDFITS
%token LINE
%token LINEARPATH
%token LINEARPROFILE
%token LOADTOOL
%token LOCALTIME
%token LOOPSLOTENDTYPE
%token MACHINEDSURFACE
%token MACHININGWORKINGSTEP
%token MANIFOLDSOLIDBREP
%token MATERIAL
%token MILLINGCUTTINGTOOL
%token MILLINGMACHINEFUNCTIONS
%token MILLINGTECHNOLOGY
%token MILLINGTHREADINGTOOL
%token MILLINGTOOLDIMENSION
%token MULTISTEPDRILLING
%token NCCONSTANT
%token NCVARIABLE
%token NEUTRAL
%token NGONCLOSEDPROFILE
%token NONSEQUENTIAL
%token NOTEXPRESSION
%token NUMERICPARAMETER
%token OFFSETVECTOR
%token OPENPOCKET
%token OPENSHELL
%token OPENSLOTENDTYPE
%token OPTIONALSTOP
%token ORDINALDATE
%token OREXPRESSION
%token ORIENTEDEDGE
%token PARABOLA
%token PARALLEL
%token PARTIALAREADEFINITION
%token PARTIALCIRCULARPATH
%token PARTIALCIRCULARPROFILE
%token PARTIALCIRCULARSHAPEPROFILE
%token PATHMODETYPEFORWARD
%token PATHMODETYPEZIGZAG
%token PCURVE
%token PERSON
%token PERSONANDADDRESS
%token PLANARFACE
%token PLANARPOCKETBOTTOMCONDITION
%token PLANARPROFILEFLOOR
%token PLANE
%token PLANECCSTRATEGY
%token PLANECLSTRATEGY
%token PLANEFINISHMILLING
%token PLANEROUGHMILLING
%token PLUNGEHELIX
%token PLUNGERAMP
%token PLUNGETOOLAXIS
%token PLUNGEZIGZAG
%token PLUSMINUSVALUE
%token POLYLINE
%token PROCESSMODEL
%token PROCESSMODELLIST
%token PROGRAMSTOP
%token PROJECT
%token QUASIUNIFORMCURVE
%token QUASIUNIFORMSURFACE
%token RADIUSEDPOCKETBOTTOMCONDITION
%token RADIUSEDSLOTENDTYPE
%token RAPIDMOVEMENT
%token RATIONALBSPLINECURVE
%token RATIONALBSPLINESURFACE
%token REAMING
%token RECTANGULARCLOSEDPROFILE
%token RECTANGULARCLOSEDSHAPEPROFILE
%token RECTANGULAROFFSET
%token RECTANGULAROMIT
%token RECTANGULAROPENSHAPEPROFILE
%token RECTANGULARPATTERN
%token REGIONPROJECTION
%token REGIONSURFACELIST
%token REPRESENTATION
%token REPRESENTATIONCONTEXT
%token RIGHT
%token RIGHTCIRCULARCYLINDER
%token ROTDIRECTIONCCW
%token ROTDIRECTIONCW
%token ROUNDEDEND
%token ROUNDEDUPROFILE
%token ROUNDHOLE
%token SELECTIVE
%token SETMARK
%token SETUP
%token SETUPINSTRUCTION
%token SHAPEREPRESENTATION
%token SIDEFINISHMILLING
%token SIDEMILL
%token SIDEROUGHMILLING
%token SLOT
%token SPADEDRILL
%token SPECIFICATION
%token SPECIFICATIONUSAGECONSTRAINT
%token SPEEDNAMERAPID
%token SPHERICALCAP
%token SPHERICALHOLEBOTTOM
%token SPHERICALSURFACE
%token SQUAREUPROFILE
%token STEP
%token STROKECONNECTIONSTRATEGYDEGOUGE
%token STROKECONNECTIONSTRATEGYLIFTSHIFTPLUNGE
%token STROKECONNECTIONSTRATEGYLOOPBACK
%token STROKECONNECTIONSTRATEGYSTRAIGHTLINE
%token SURFACEOFLINEAREXTRUSION
%token SURFACEOFREVOLUTION
%token SURFACETEXTUREPARAMETER
%token TAP
%token TAPEREDDRILL
%token TAPEREDENDMILL
%token TAPEREDREAMER
%token TAPEREDTAP
%token TAPPING
%token TEEPROFILE
%token THREADDRILLING
%token THREADMILL
%token THREEAXES
%token THREEAXESTILTEDTOOL
%token THROUGHBOTTOMCONDITION
%token THROUGHPOCKETBOTTOMCONDITION
%token THROUGHPROFILEFLOOR
%token TOLERANCEDLENGTHMEASURE
%token TOLERANCES
%token TOOLLENGTHPROBING
%token TOOLPATHFEATURE
%token TOOLPATHLIST
%token TOOLPATHSPEED
%token TOOLPATHTYPEAPPROACH
%token TOOLPATHTYPECONNECT
%token TOOLPATHTYPECONTACT
%token TOOLPATHTYPELIFT
%token TOOLPATHTYPENONCONTACT
%token TOOLPATHTYPETRAJECTORYPATH
%token TOOLRADIUSPROBING
%token TOOLREFERENCEPOINTCCP
%token TOOLREFERENCEPOINTTCP
%token TOPOLOGICALREGION
%token TOUCHPROBE
%token TRANSITIONCODECONTINUOUS
%token TRANSITIONCODECONTSAMEGRADIENT
%token TRANSITIONCODECONTSAMEGRADIENTSAMECURVATURE
%token TRANSITIONCODEDISCONTINUOUS
%token TRIMMEDCURVE
%token TRIMMINGPREFERENCECARTESIAN
%token TRIMMINGPREFERENCEPARAMETER
%token TRIMMINGPREFERENCEUNSPECIFIED
%token TRUE
%token TSLOTMILL
%token TWISTDRILL
%token TWOAXES
%token UNIDIRECTIONALMILLING
%token UNIFORMCURVE
%token UNIFORMSURFACE
%token UNKNOWN
%token UNLOADTOOL
%token USERDEFINEDTOOL
%token UVSTRATEGY
%token VECTOR
%token VEEPROFILE
%token VERTEXLOOP
%token VERTEXPOINT
%token WAITFORMARK
%token WEEKOFYEARANDDAYDATE
%token WHILESTATEMENT
%token WOODRUFFKEYSEATMILL
%token WOODRUFFSLOTENDTYPE
%token WORKPIECE
%token WORKPIECECOMPLETEPROBING
%token WORKPIECEPROBING
%token WORKPIECESETUP
%token WORKPLAN
%token XOREXPRESSION
%token <sval> CHARSTRING
%token <ival> INTSTRING
%token <rval> REALSTRING

%token BAD
%token COLON
%token DOLLAR
%token EQUALS
%token LBOX
%token LPAREN
%token RBOX
%token RPAREN
%token SEMICOLON
%token SHARP
%token SLASH

%start inputFile

%%

inputFile :
	  fileStart headerSection dataSection fileEnd
	    { $$ = new inputFile($1, $2, $3, $4);
	      tree = $$; }
	;

instance :
	  address
	    { $$ = $1; }
	| advancedBrepShapeRepresentation
	    { $$ = $1; }
	| advancedFace
	    { $$ = $1; }
	| alongPath
	    { $$ = $1; }
	| andExpression
	    { $$ = $1; }
	| angleTaper
	    { $$ = $1; }
	| apLiftPathAngle
	    { $$ = $1; }
	| apLiftPathTangent
	    { $$ = $1; }
	| approval
	    { $$ = $1; }
	| approvalStatus
	    { $$ = $1; }
	| apRetractAngle
	    { $$ = $1; }
	| apRetractTangent
	    { $$ = $1; }
	| assignment
	    { $$ = $1; }
	| axis1placement
	    { $$ = $1; }
	| axis2placement3d
	    { $$ = $1; }
	| axisTrajectory
	    { $$ = $1; }
	| backBoring
	    { $$ = $1; }
	| backsideCounterbore
	    { $$ = $1; }
	| backsideCountersink
	    { $$ = $1; }
	| ballEndmill
	    { $$ = $1; }
	| bezierCurve
	    { $$ = $1; }
	| bezierSurface
	    { $$ = $1; }
	| bidirectionalContour
	    { $$ = $1; }
	| bidirectionalMilling
	    { $$ = $1; }
	| block
	    { $$ = $1; }
	| boring
	    { $$ = $1; }
	| boringTool
	    { $$ = $1; }
	| boss
	    { $$ = $1; }
	| bottomAndSideFinishMilling
	    { $$ = $1; }
	| bottomAndSideRoughMilling
	    { $$ = $1; }
	| boundedPCurve
	    { $$ = $1; }
	| bSplineCurveWithKnots
	    { $$ = $1; }
	| bSplineSurfaceWithKnots
	    { $$ = $1; }
	| bullnoseEndmill
	    { $$ = $1; }
	| calendarDate
	    { $$ = $1; }
	| cartesianPoint
	    { $$ = $1; }
	| catalogueThread
	    { $$ = $1; }
	| centerDrill
	    { $$ = $1; }
	| centerDrilling
	    { $$ = $1; }
	| centerMilling
	    { $$ = $1; }
	| chamfer
	    { $$ = $1; }
	| channel
	    { $$ = $1; }
	| circle
	    { $$ = $1; }
	| circularClosedProfile
	    { $$ = $1; }
	| circularClosedShapeProfile
	    { $$ = $1; }
	| circularOffset
	    { $$ = $1; }
	| circularOmit
	    { $$ = $1; }
	| circularPattern
	    { $$ = $1; }
	| closedPocket
	    { $$ = $1; }
	| closedShell
	    { $$ = $1; }
	| combinedDrillAndReamer
	    { $$ = $1; }
	| combinedDrillAndTap
	    { $$ = $1; }
	| completeCircularPath
	    { $$ = $1; }
	| comparisonEqual
	    { $$ = $1; }
	| comparisonGreater
	    { $$ = $1; }
	| comparisonGreaterEqual
	    { $$ = $1; }
	| comparisonLess
	    { $$ = $1; }
	| comparisonLessEqual
	    { $$ = $1; }
	| comparisonNotEqual
	    { $$ = $1; }
	| compositeCurve
	    { $$ = $1; }
	| compositeCurveSegment
	    { $$ = $1; }
	| conicalHoleBottom
	    { $$ = $1; }
	| connectDirect
	    { $$ = $1; }
	| connectSecplane
	    { $$ = $1; }
	| contourBidirectional
	    { $$ = $1; }
	| contourParallel
	    { $$ = $1; }
	| contourSpiral
	    { $$ = $1; }
	| coordinatedUniversalTimeOffset
	    { $$ = $1; }
	| counterbore
	    { $$ = $1; }
	| counterboreHole
	    { $$ = $1; }
	| countersink
	    { $$ = $1; }
	| counterSinking
	    { $$ = $1; }
	| countersunkHole
	    { $$ = $1; }
	| curveWithNormalVector
	    { $$ = $1; }
	| cutterContactTrajectory
	    { $$ = $1; }
	| cutterLocationTrajectory
	    { $$ = $1; }
	| cuttingComponent
	    { $$ = $1; }
	| cuttingEdgeTechnologicalData
	    { $$ = $1; }
	| dateAndTime
	    { $$ = $1; }
	| definedThread
	    { $$ = $1; }
	| definitionalRepresentation
	    { $$ = $1; }
	| descriptiveParameter
	    { $$ = $1; }
	| diameterTaper
	    { $$ = $1; }
	| displayMessage
	    { $$ = $1; }
	| dovetailMill
	    { $$ = $1; }
	| drilling
	    { $$ = $1; }
	| drillingTypeStrategy
	    { $$ = $1; }
	| direction
	    { $$ = $1; }
	| edgeCurve
	    { $$ = $1; }
	| edgeLoop
	    { $$ = $1; }
	| edgeRound
	    { $$ = $1; }
	| ellipse
	    { $$ = $1; }
	| exchangePallet
	    { $$ = $1; }
	| explicitStrategy
	    { $$ = $1; }
	| feedstop
	    { $$ = $1; }
	| faceBound
	    { $$ = $1; }
	| faceOuterBound
	    { $$ = $1; }
	| facemill
	    { $$ = $1; }
	| fiveAxesConstTiltYaw
	    { $$ = $1; }
	| fiveAxesVarTiltYaw
	    { $$ = $1; }
	| flatHoleBottom
	    { $$ = $1; }
	| flatSlotEndType
	    { $$ = $1; }
	| flatWithRadiusHoleBottom
	    { $$ = $1; }
	| freeformOperation
	    { $$ = $1; }
	| generalClosedProfile
	    { $$ = $1; }
	| generalPath
	    { $$ = $1; }
	| generalPattern
	    { $$ = $1; }
	| generalPocketBottomCondition
	    { $$ = $1; }
	| generalOutsideProfile
	    { $$ = $1; }
	| generalProfile
	    { $$ = $1; }
	| generalProfileFloor
	    { $$ = $1; }
	| generalShapeProfile
	    { $$ = $1; }
	| helix
	    { $$ = $1; }
	| hyperbola
	    { $$ = $1; }
	| ifStatement
	    { $$ = $1; }
	| indexPallet
	    { $$ = $1; }
	| indexTable
	    { $$ = $1; }
	| inProcessGeometry
	    { $$ = $1; }
	| leadingLineStrategy
	    { $$ = $1; }
	| limitsAndFits
	    { $$ = $1; }
	| line
	    { $$ = $1; }
	| linearPath
	    { $$ = $1; }
	| linearProfile
	    { $$ = $1; }
	| loadTool
	    { $$ = $1; }
	| localTime
	    { $$ = $1; }
	| loopSlotEndType
	    { $$ = $1; }
	| machinedSurface
	    { $$ = $1; }
	| machiningWorkingstep
	    { $$ = $1; }
	| manifoldSolidBrep
	    { $$ = $1; }
	| material
	    { $$ = $1; }
	| millingCuttingTool
	    { $$ = $1; }
	| millingMachineFunctions
	    { $$ = $1; }
	| millingTechnology
	    { $$ = $1; }
	| millingThreadingTool
	    { $$ = $1; }
	| millingToolDimension
	    { $$ = $1; }
	| multistepDrilling
	    { $$ = $1; }
	| ncConstant
	    { $$ = $1; }
	| ncVariable
	    { $$ = $1; }
	| ngonClosedProfile
	    { $$ = $1; }
	| nonSequential
	    { $$ = $1; }
	| notExpression
	    { $$ = $1; }
	| numericParameter
	    { $$ = $1; }
	| openPocket
	    { $$ = $1; }
	| openShell
	    { $$ = $1; }
	| openSlotEndType
	    { $$ = $1; }
	| optionalStop
	    { $$ = $1; }
	| ordinalDate
	    { $$ = $1; }
	| orExpression
	    { $$ = $1; }
	| orientedEdge
	    { $$ = $1; }
	| parabola
	    { $$ = $1; }
	| parallel
	    { $$ = $1; }
	| partialAreaDefinition
	    { $$ = $1; }
	| partialCircularPath
	    { $$ = $1; }
	| partialCircularProfile
	    { $$ = $1; }
	| partialCircularShapeProfile
	    { $$ = $1; }
	| pcurve
	    { $$ = $1; }
	| person
	    { $$ = $1; }
	| personAndAddress
	    { $$ = $1; }
	| planarFace
	    { $$ = $1; }
	| planarPocketBottomCondition
	    { $$ = $1; }
	| planarProfileFloor
	    { $$ = $1; }
	| plane
	    { $$ = $1; }
	| planeCcStrategy
	    { $$ = $1; }
	| planeClStrategy
	    { $$ = $1; }
	| planeFinishMilling
	    { $$ = $1; }
	| planeRoughMilling
	    { $$ = $1; }
	| plungeHelix
	    { $$ = $1; }
	| plungeRamp
	    { $$ = $1; }
	| plungeToolaxis
	    { $$ = $1; }
	| plungeZigzag
	    { $$ = $1; }
	| plusMinusValue
	    { $$ = $1; }
	| polyline
	    { $$ = $1; }
	| processModel
	    { $$ = $1; }
	| processModelList
	    { $$ = $1; }
	| programStop
	    { $$ = $1; }
	| project
	    { $$ = $1; }
	| quasiUniformCurve
	    { $$ = $1; }
	| quasiUniformSurface
	    { $$ = $1; }
	| radiusedPocketBottomCondition
	    { $$ = $1; }
	| radiusedSlotEndType
	    { $$ = $1; }
	| rapidMovement
	    { $$ = $1; }
	| rationalBSplineCurve
	    { $$ = $1; }
	| rationalBSplineSurface
	    { $$ = $1; }
	| reaming
	    { $$ = $1; }
	| rectangularClosedProfile
	    { $$ = $1; }
	| rectangularClosedShapeProfile
	    { $$ = $1; }
	| rectangularOpenShapeProfile
	    { $$ = $1; }
	| rectangularPattern
	    { $$ = $1; }
	| rectangularOffset
	    { $$ = $1; }
	| rectangularOmit
	    { $$ = $1; }
	| regionProjection
	    { $$ = $1; }
	| regionSurfaceList
	    { $$ = $1; }
	| representation
	    { $$ = $1; }
	| rightCircularCylinder
	    { $$ = $1; }
	| roundedEnd
	    { $$ = $1; }
	| roundedUProfile
	    { $$ = $1; }
	| roundHole
	    { $$ = $1; }
	| selective
	    { $$ = $1; }
	| setMark
	    { $$ = $1; }
	| setup
	    { $$ = $1; }
	| setupInstruction
	    { $$ = $1; }
	| shapeRepresentation
	    { $$ = $1; }
	| sideFinishMilling
	    { $$ = $1; }
	| sideMill
	    { $$ = $1; }
	| sideRoughMilling
	    { $$ = $1; }
	| slot
	    { $$ = $1; }
	| spadeDrill
	    { $$ = $1; }
	| specification
	    { $$ = $1; }
	| specificationUsageConstraint
	    { $$ = $1; }
	| sphericalCap
	    { $$ = $1; }
	| sphericalHoleBottom
	    { $$ = $1; }
	| sphericalSurface
	    { $$ = $1; }
	| squareUProfile
	    { $$ = $1; }
	| step
	    { $$ = $1; }
	| surfaceOfLinearExtrusion
	    { $$ = $1; }
	| surfaceOfRevolution
	    { $$ = $1; }
	| surfaceTextureParameter
	    { $$ = $1; }
	| tap
	    { $$ = $1; }
	| taperedDrill
	    { $$ = $1; }
	| taperedEndmill
	    { $$ = $1; }
	| taperedReamer
	    { $$ = $1; }
	| taperedTap
	    { $$ = $1; }
	| tapping
	    { $$ = $1; }
	| teeProfile
	    { $$ = $1; }
	| threadDrilling
	    { $$ = $1; }
	| threadMill
	    { $$ = $1; }
	| threeAxes
	    { $$ = $1; }
	| threeAxesTiltedTool
	    { $$ = $1; }
	| throughBottomCondition
	    { $$ = $1; }
	| throughPocketBottomCondition
	    { $$ = $1; }
	| throughProfileFloor
	    { $$ = $1; }
	| tolerancedLengthMeasure
	    { $$ = $1; }
	| tolerances
	    { $$ = $1; }
	| toolLengthProbing
	    { $$ = $1; }
	| toolpathFeature
	    { $$ = $1; }
	| toolpathList
	    { $$ = $1; }
	| toolpathSpeed
	    { $$ = $1; }
	| toolRadiusProbing
	    { $$ = $1; }
	| topologicalRegion
	    { $$ = $1; }
	| touchProbe
	    { $$ = $1; }
	| trimmedCurve
	    { $$ = $1; }
	| tSlotMill
	    { $$ = $1; }
	| twistDrill
	    { $$ = $1; }
	| twoAxes
	    { $$ = $1; }
	| unidirectionalMilling
	    { $$ = $1; }
	| uniformCurve
	    { $$ = $1; }
	| uniformSurface
	    { $$ = $1; }
	| unloadTool
	    { $$ = $1; }
	| userDefinedTool
	    { $$ = $1; }
	| uvStrategy
	    { $$ = $1; }
	| vector
	    { $$ = $1; }
	| veeProfile
	    { $$ = $1; }
	| vertexLoop
	    { $$ = $1; }
	| vertexPoint
	    { $$ = $1; }
	| waitForMark
	    { $$ = $1; }
	| weekOfYearAndDayDate
	    { $$ = $1; }
	| whileStatement
	    { $$ = $1; }
	| woodruffKeyseatMill
	    { $$ = $1; }
	| woodruffSlotEndType
	    { $$ = $1; }
	| workpiece
	    { $$ = $1; }
	| workpieceCompleteProbing
	    { $$ = $1; }
	| workpieceProbing
	    { $$ = $1; }
	| workpieceSetup
	    { $$ = $1; }
	| workplan
	    { $$ = $1; }
	| xorExpression
	    { $$ = $1; }
	;

address :
	  ADDRESS LPAREN optString C optString C optString C optString C optString C optString C optString C optString C optString C optString C optString C optString C RPAREN
	    { $$ = new address($3, $5, $7, $9, $11, $13, $15, $17, $19, $21, $23, $25); }
	;

advancedBrepShapeRepresentation :
	  ADVANCEDBREPSHAPEREPRESENTATION LPAREN CHARSTRING C parenRepresentationItemListFull C representationContext RPAREN
	    { $$ = new advancedBrepShapeRepresentation($3, $5, $7); }
	;

advancedFace :
	  ADVANCEDFACE LPAREN CHARSTRING C parenFaceBoundListFull C instanceId C boolean RPAREN
	    { $$ = new advancedFace($3, $5, 0, $9);
	      surface_refs.push_back(&($$->faceGeometry));
	      surface_nums.push_back($7->val);
	      delete $7;
	    }
	;

aheadOrBehind :
	  aheadOrBehindAhead
	    { $$ = $1; }
	| aheadOrBehindExact
	    { $$ = $1; }
	| aheadOrBehindBehind
	    { $$ = $1; }
	;

aheadOrBehindAhead :
	  AHEADORBEHINDAHEAD
	    { $$ = new aheadOrBehindAhead(); }
	;

aheadOrBehindBehind :
	  AHEADORBEHINDBEHIND
	    { $$ = new aheadOrBehindBehind(); }
	;

aheadOrBehindExact :
	  AHEADORBEHINDEXACT
	    { $$ = new aheadOrBehindExact(); }
	;

alongPath :
	  ALONGPATH LPAREN optDirection C instanceId RPAREN
	    { $$ = new alongPath($3, 0);
	      if ($3)
		{
		  $$->toolOrientation = 0;
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      toolpathList_refs.push_back(&($$->path));
	      toolpathList_nums.push_back($5->val);
	      delete $5;
	    }
	;

andExpression :
	  ANDEXPRESSION LPAREN parenBooleanExpressionListFull RPAREN
	    { $$ = new andExpression($3); }
	;

angleTaper :
	  ANGLETAPER LPAREN real RPAREN
	    { $$ = new angleTaper($3); }
	;

apLiftPathAngle :
	  APLIFTPATHANGLE LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions C instanceId C optDirection C REALSTRING C REALSTRING RPAREN
	    { $$ = new apLiftPathAngle($3, $5, $7, $9, $11, 0, $15, $17, $19);
	      if (($7) && ($7->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($7);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->iId->val);
		  delete v->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsTechnology = 0;
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsMachineFunctions = 0;
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      cartesianPoint_refs.push_back(&($$->fixPoint));
	      cartesianPoint_nums.push_back($13->val);
	      delete $13;
	      if ($15)
		{
		  $$->fixPointDir = 0;
		  direction_refs.push_back(&($$->fixPointDir));
		  direction_nums.push_back($15->iId->val);
		  delete $15->iId;
		  delete $15;
		}
	    }
	;

apLiftPathTangent :
	  APLIFTPATHTANGENT LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions C instanceId C optDirection C REALSTRING RPAREN
	    { $$ = new apLiftPathTangent($3, $5, $7, $9, $11, 0, $15, $17);
	      if (($7) && ($7->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($7);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->iId->val);
		  delete v->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsTechnology = 0;
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsMachineFunctions = 0;
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      cartesianPoint_refs.push_back(&($$->fixPoint));
	      cartesianPoint_nums.push_back($13->val);
	      delete $13;
	      if ($15)
		{
		  $$->fixPointDir = 0;
		  direction_refs.push_back(&($$->fixPointDir));
		  direction_nums.push_back($15->iId->val);
		  delete $15->iId;
		  delete $15;
		}
	    }
	;

approval :
	  APPROVAL LPAREN instanceId C CHARSTRING RPAREN
	    { $$ = new approval(0, $5);
	      approvalStatus_refs.push_back(&($$->status));
	      approvalStatus_nums.push_back($3->val);
	      delete $3;
	    }
	;

approvalStatus :
	  APPROVALSTATUS LPAREN CHARSTRING RPAREN
	    { $$ = new approvalStatus($3); }
	;

apRetractAngle :
	  APRETRACTANGLE LPAREN optDirection C REALSTRING C REALSTRING RPAREN
	    { $$ = new apRetractAngle($3, $5, $7);
	      if ($3)
		{
		  $$->toolOrientation = 0;
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	    }
	;

apRetractTangent :
	  APRETRACTTANGENT LPAREN optDirection C REALSTRING RPAREN
	    { $$ = new apRetractTangent($3, $5);
	      if ($3)
		{
		  $$->toolOrientation = 0;
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	    }
	;

assignment :
	  ASSIGNMENT LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new assignment($3, 0, 0);
	      ncVariable_refs.push_back(&($$->itsLvalue));
	      ncVariable_nums.push_back($5->val);
	      delete $5;
	      rvalue_refs.push_back(&($$->itsRvalue));
	      rvalue_nums.push_back($7->val);
	      delete $7;
	    }
	;

aString :
	  CHARSTRING
	    { $$ = new aString($1); }
	;

axis1placement :
	  AXIS1PLACEMENT LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new axis1placement($3, 0, 0);
	      cartesianPoint_refs.push_back(&($$->location));
	      cartesianPoint_nums.push_back($5->val);
	      delete $5;
	      direction_refs.push_back(&($$->axis));
	      direction_nums.push_back($7->val);
	      delete $7;
	    }
	;

axis2placement3d :
	  AXIS2PLACEMENT3D LPAREN CHARSTRING C instanceId C instanceId C optDirection RPAREN
	    { $$ = new axis2placement3d($3, 0, 0, $9);
	      cartesianPoint_refs.push_back(&($$->location));
	      cartesianPoint_nums.push_back($5->val);
	      delete $5;
	      direction_refs.push_back(&($$->axis));
	      direction_nums.push_back($7->val);
	      delete $7;
	      if ($9)
		{
		  $$->refDirection = 0;
		  direction_refs.push_back(&($$->refDirection));
		  direction_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	    }
	;

axis2placement3dList :
	  instanceId
	    { $$ = new std::list<axis2placement3d *>;
	      $$->push_back(0);
	      axis2placement3d_refs.push_back(&($$->back()));
	      axis2placement3d_nums.push_back($1->val);
	    }
	| axis2placement3dList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      axis2placement3d_refs.push_back(&($$->back()));
	      axis2placement3d_nums.push_back($3->val);
	    }
	;

axisTrajectory :
	  AXISTRAJECTORY LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions C optBoolean C parenStringListFull C parenBoundedCurveListFull RPAREN
	    { $$ = new axisTrajectory($3, $5, $7, $9, $11, $13, $15, $17);
	      if (($7) && ($7->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($7);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->iId->val);
		  delete v->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsTechnology = 0;
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsMachineFunctions = 0;
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	    }
	;

backBoring :
	  BACKBORING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy RPAREN
	    { $$ = new backBoring($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($29)
		{
		  $$->itsMachiningStrategy = 0;
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->iId->val);
		  delete $29->iId;
		  delete $29;
		}
	    }
	;

backsideCounterbore :
	  BACKSIDECOUNTERBORE LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new backsideCounterbore(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

backsideCountersink :
	  BACKSIDECOUNTERSINK LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new backsideCountersink(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

ballEndmill :
	  BALLENDMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new ballEndmill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

bezierCurve :
	  BEZIERCURVE LPAREN CHARSTRING C INTSTRING C parenCartesianPointList C bSplineCurveForm C logical C logical RPAREN
	    { $$ = new bezierCurve($3, $5, $7, $9, $11, $13); }
	;

bezierSurface :
	  BEZIERSURFACE LPAREN CHARSTRING C integer C integer C parenParenCartesianPointListFullListFull C bSplineSurfaceForm C logical C logical C logical RPAREN
	    { $$ = new bezierSurface($3, $5, $7, $9, $11, $13, $15, $17); }
	;

bidirectionalContour :
	  BIDIRECTIONALCONTOUR LPAREN optReal C optBoolean C optDirection C optLeftOrRight optRotDirection optCutmodeType RPAREN
	    { $$ = new bidirectionalContour($3, $5, $7, $9, $10, $11);
	      if ($7)
		{
		  $$->feedDirection = 0;
		  direction_refs.push_back(&($$->feedDirection));
		  direction_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	    }
	;

bidirectionalMilling :
	  BIDIRECTIONALMILLING LPAREN optReal C optBoolean C optDirection C optLeftOrRight C optStrokeConnectionStrategy RPAREN
	    { $$ = new bidirectionalMilling($3, $5, $7, $9, $11);
	      if ($7)
		{
		  $$->feedDirection = 0;
		  direction_refs.push_back(&($$->feedDirection));
		  direction_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	    }
	;

block :
	  BLOCK LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING C REALSTRING RPAREN
	    { $$ = new block($3, 0, $7, $9, $11);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	    }
	;

boolean :
	  booleanTrue
	    { $$ = $1; }
	| booleanFalse
	    { $$ = $1; }
	;

booleanExpressionList :
	  instanceId
	    { $$ = new std::list<booleanExpression *>;
	      $$->push_back(0);
	      booleanExpression_refs.push_back(&($$->back()));
	      booleanExpression_nums.push_back($1->val);
	    }
	| booleanExpressionList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      booleanExpression_refs.push_back(&($$->back()));
	      booleanExpression_nums.push_back($3->val);
	    }
	;

booleanFalse :
	  FALSE
	    { $$ = new booleanFalse(); }
	;

booleanTrue :
	  TRUE
	    { $$ = new booleanTrue(); }
	;

boring :
	  BORING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy C boolean C optReal C optCartesianPoint RPAREN
	    { $$ = new boring($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33, $35);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($29)
		{
		  $$->itsMachiningStrategy = 0;
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->iId->val);
		  delete $29->iId;
		  delete $29;
		}
	      if ($35)
		{
		  $$->waitingPosition = 0;
		  cartesianPoint_refs.push_back(&($$->waitingPosition));
		  cartesianPoint_nums.push_back($35->iId->val);
		  delete $35->iId;
		  delete $35;
		}
	    }
	;

boringTool :
	  BORINGTOOL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new boringTool(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

boss :
	  BOSS LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C optReal RPAREN
	    { $$ = new boss($3, 0, $7, 0, 0, 0, $15);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      closedProfile_refs.push_back(&($$->itsBoundary));
	      closedProfile_nums.push_back($13->val);
	      delete $13;
	    }
	;

bossList :
	  instanceId
	    { $$ = new std::list<boss *>;
	      $$->push_back(0);
	      boss_refs.push_back(&($$->back()));
	      boss_nums.push_back($1->val);
	    }
	| bossList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      boss_refs.push_back(&($$->back()));
	      boss_nums.push_back($3->val);
	    }
	;

bottomAndSideFinishMilling :
	  BOTTOMANDSIDEFINISHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal C optReal C optReal RPAREN
	    { $$ = new bottomAndSideFinishMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($21)
		{
		  $$->approach = 0;
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	      if ($23)
		{
		  $$->retract = 0;
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->iId->val);
		  delete $23->iId;
		  delete $23;
		}
	      if ($25)
		{
		  $$->itsMachiningStrategy = 0;
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->iId->val);
		  delete $25->iId;
		  delete $25;
		}
	    }
	;

bottomAndSideRoughMilling :
	  BOTTOMANDSIDEROUGHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal C optReal C optReal RPAREN
	    { $$ = new bottomAndSideRoughMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($21)
		{
		  $$->approach = 0;
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	      if ($23)
		{
		  $$->retract = 0;
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->iId->val);
		  delete $23->iId;
		  delete $23;
		}
	      if ($25)
		{
		  $$->itsMachiningStrategy = 0;
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->iId->val);
		  delete $25->iId;
		  delete $25;
		}
	    }
	;

bottomOrSide :
	  bottomOrSideBottom
	    { $$ = $1; }
	| bottomOrSideSide
	    { $$ = $1; }
	| bottomOrSideBottomAndSide
	    { $$ = $1; }
	;

bottomOrSideBottom :
	  BOTTOMORSIDEBOTTOM
	    { $$ = new bottomOrSideBottom(); }
	;

bottomOrSideSide :
	  BOTTOMORSIDESIDE
	    { $$ = new bottomOrSideSide(); }
	;

bottomOrSideBottomAndSide :
	  BOTTOMORSIDEBOTTOMANDSIDE
	    { $$ = new bottomOrSideBottomAndSide(); }
	;

boundedCurveList :
	  instanceId
	    { $$ = new std::list<boundedCurve *>;
	      $$->push_back(0);
	      boundedCurve_refs.push_back(&($$->back()));
	      boundedCurve_nums.push_back($1->val);
	    }
	| boundedCurveList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      boundedCurve_refs.push_back(&($$->back()));
	      boundedCurve_nums.push_back($3->val);
	    }
	;

boundedPCurve :
	  BOUNDEDPCURVE LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new boundedPCurve($3, 0, 0);
	      surface_refs.push_back(&($$->basisSurface));
	      surface_nums.push_back($5->val);
	      delete $5;
	      definitionalRepresentation_refs.push_back(&($$->referenceToCurve));
	      definitionalRepresentation_nums.push_back($7->val);
	      delete $7;
	    }
	;

boundedSurfaceList :
	  instanceId
	    { $$ = new std::list<boundedSurface *>;
	      $$->push_back(0);
	      boundedSurface_refs.push_back(&($$->back()));
	      boundedSurface_nums.push_back($1->val);
	    }
	| boundedSurfaceList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      boundedSurface_refs.push_back(&($$->back()));
	      boundedSurface_nums.push_back($3->val);
	    }
	;

bSplineCurveForm :
	  bSplineCurveFormPolylineForm
	    { $$ = $1; }
	| bSplineCurveFormCircularArc
	    { $$ = $1; }
	| bSplineCurveFormEllipticArc
	    { $$ = $1; }
	| bSplineCurveFormParabolicArc
	    { $$ = $1; }
	| bSplineCurveFormHyperbolicArc
	    { $$ = $1; }
	| bSplineCurveFormUnspecified
	    { $$ = $1; }
	;

bSplineCurveFormPolylineForm :
	  BSPLINECURVEFORMPOLYLINEFORM
	    { $$ = new bSplineCurveFormPolylineForm(); }
	;

bSplineCurveFormCircularArc :
	  BSPLINECURVEFORMCIRCULARARC
	    { $$ = new bSplineCurveFormCircularArc(); }
	;

bSplineCurveFormEllipticArc :
	  BSPLINECURVEFORMELLIPTICARC
	    { $$ = new bSplineCurveFormEllipticArc(); }
	;

bSplineCurveFormParabolicArc :
	  BSPLINECURVEFORMPARABOLICARC
	    { $$ = new bSplineCurveFormParabolicArc(); }
	;

bSplineCurveFormHyperbolicArc :
	  BSPLINECURVEFORMHYPERBOLICARC
	    { $$ = new bSplineCurveFormHyperbolicArc(); }
	;

bSplineCurveFormUnspecified :
	  BSPLINECURVEFORMUNSPECIFIED
	    { $$ = new bSplineCurveFormUnspecified(); }
	;

bSplineCurveWithKnots :
	  BSPLINECURVEWITHKNOTS LPAREN CHARSTRING C INTSTRING C parenCartesianPointList C bSplineCurveForm C logical C logical parenIntegerListFull C parenRealListFull C knotType RPAREN
	    { $$ = new bSplineCurveWithKnots($3, $5, $7, $9, $11, $13, $14, $16, $18); }
	;

bSplineSurfaceForm :
	  bSplineSurfaceFormPlaneSurf
	    { $$ = $1; }
	| bSplineSurfaceFormCylindricalSurf
	    { $$ = $1; }
	| bSplineSurfaceFormConicalSurf
	    { $$ = $1; }
	| bSplineSurfaceFormSphericalSurf
	    { $$ = $1; }
	| bSplineSurfaceFormToroidalSurf
	    { $$ = $1; }
	| bSplineSurfaceFormSurfOfRevolution
	    { $$ = $1; }
	| bSplineSurfaceFormRuledSurf
	    { $$ = $1; }
	| bSplineSurfaceFormGeneralizedCone
	    { $$ = $1; }
	| bSplineSurfaceFormQuadricSurf
	    { $$ = $1; }
	| bSplineSurfaceFormSurfOfLinearExtrusion
	    { $$ = $1; }
	| bSplineSurfaceFormUnspecified
	    { $$ = $1; }
	;

bSplineSurfaceFormConicalSurf :
	  BSPLINESURFACEFORMCONICALSURF
	    { $$ = new bSplineSurfaceFormConicalSurf(); }
	;

bSplineSurfaceFormCylindricalSurf :
	  BSPLINESURFACEFORMCYLINDRICALSURF
	    { $$ = new bSplineSurfaceFormCylindricalSurf(); }
	;

bSplineSurfaceFormGeneralizedCone :
	  BSPLINESURFACEFORMGENERALIZEDCONE
	    { $$ = new bSplineSurfaceFormGeneralizedCone(); }
	;

bSplineSurfaceFormPlaneSurf :
	  BSPLINESURFACEFORMPLANESURF
	    { $$ = new bSplineSurfaceFormPlaneSurf(); }
	;

bSplineSurfaceFormQuadricSurf :
	  BSPLINESURFACEFORMQUADRICSURF
	    { $$ = new bSplineSurfaceFormQuadricSurf(); }
	;

bSplineSurfaceFormRuledSurf :
	  BSPLINESURFACEFORMRULEDSURF
	    { $$ = new bSplineSurfaceFormRuledSurf(); }
	;

bSplineSurfaceFormSphericalSurf :
	  BSPLINESURFACEFORMSPHERICALSURF
	    { $$ = new bSplineSurfaceFormSphericalSurf(); }
	;

bSplineSurfaceFormSurfOfLinearExtrusion :
	  BSPLINESURFACEFORMSURFOFLINEAREXTRUSION
	    { $$ = new bSplineSurfaceFormSurfOfLinearExtrusion(); }
	;

bSplineSurfaceFormSurfOfRevolution :
	  BSPLINESURFACEFORMSURFOFREVOLUTION
	    { $$ = new bSplineSurfaceFormSurfOfRevolution(); }
	;

bSplineSurfaceFormToroidalSurf :
	  BSPLINESURFACEFORMTOROIDALSURF
	    { $$ = new bSplineSurfaceFormToroidalSurf(); }
	;

bSplineSurfaceFormUnspecified :
	  BSPLINESURFACEFORMUNSPECIFIED
	    { $$ = new bSplineSurfaceFormUnspecified(); }
	;

bSplineSurfaceWithKnots :
	  BSPLINESURFACEWITHKNOTS LPAREN CHARSTRING C integer C integer C parenParenCartesianPointListFullListFull C bSplineSurfaceForm C logical C logical C logical C parenIntegerListFull C parenIntegerListFull C parenRealListFull C parenRealListFull C knotType RPAREN
	    { $$ = new bSplineSurfaceWithKnots($3, $5, $7, $9, $11, $13, $15, $17, $19, $21, $23, $25, $27); }
	;

bullnoseEndmill :
	  BULLNOSEENDMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new bullnoseEndmill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

calendarDate :
	  CALENDARDATE LPAREN INTSTRING C INTSTRING C INTSTRING RPAREN
	    { $$ = new calendarDate($3, $5, $7); }
	;

cartesianPoint :
	  CARTESIANPOINT LPAREN CHARSTRING C parenRealListFull RPAREN
	    { $$ = new cartesianPoint($3, $5); }
	;

cartesianPointList :
	  instanceId
	    { $$ = new std::list<cartesianPoint *>;
	      $$->push_back(0);
	      cartesianPoint_refs.push_back(&($$->back()));
	      cartesianPoint_nums.push_back($1->val);
	    }
	| cartesianPointList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      cartesianPoint_refs.push_back(&($$->back()));
	      cartesianPoint_nums.push_back($3->val);
	    }
	;

catalogueThread :
	  CATALOGUETHREAD LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C parenMachiningFeatureListFull C boolean C optDescriptiveParameter C instanceId C instanceId C REALSTRING C instanceId C instanceId C instanceId RPAREN
	    { $$ = new catalogueThread($3, 0, $7, 0, 0, 0, $15, $17, $19, 0, 0, $25, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      partialAreaDefinition_refs.push_back(&($$->partialProfile));
	      partialAreaDefinition_nums.push_back($13->val);
	      delete $13;
	      if ($19)
		{
		  $$->qualifier = 0;
		  descriptiveParameter_refs.push_back(&($$->qualifier));
		  descriptiveParameter_nums.push_back($19->iId->val);
		  delete $19->iId;
		  delete $19;
		}
	      descriptiveParameter_refs.push_back(&($$->fitClass));
	      descriptiveParameter_nums.push_back($21->val);
	      delete $21;
	      descriptiveParameter_refs.push_back(&($$->form));
	      descriptiveParameter_nums.push_back($23->val);
	      delete $23;
	      numericParameter_refs.push_back(&($$->numberOfThreads));
	      numericParameter_nums.push_back($27->val);
	      delete $27;
	      descriptiveParameter_refs.push_back(&($$->threadHand));
	      descriptiveParameter_nums.push_back($29->val);
	      delete $29;
	      specification_refs.push_back(&($$->documentation));
	      specification_nums.push_back($31->val);
	      delete $31;
	    }
	;

centerDrill :
	  CENTERDRILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new centerDrill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

centerDrilling :
	  CENTERDRILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy RPAREN
	    { $$ = new centerDrilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($29)
		{
		  $$->itsMachiningStrategy = 0;
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->iId->val);
		  delete $29->iId;
		  delete $29;
		}
	    }
	;

centerMilling :
	  CENTERMILLING LPAREN optReal C optBoolean RPAREN
	    { $$ = new centerMilling($3, $5); }
	;

chamfer :
	  CHAMFER LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C REALSTRING C instanceId RPAREN
	    { $$ = new chamfer($3, 0, $7, 0, 0, $13, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      machiningFeature_refs.push_back(&($$->firstFeature));
	      machiningFeature_nums.push_back($9->val);
	      delete $9;
	      machiningFeature_refs.push_back(&($$->secondFeature));
	      machiningFeature_nums.push_back($11->val);
	      delete $11;
	      tolerancedLengthMeasure_refs.push_back(&($$->firstOffsetAmount));
	      tolerancedLengthMeasure_nums.push_back($15->val);
	      delete $15;
	    }
	;

channel :
	  CHANNEL LPAREN CHARSTRING RPAREN
	    { $$ = new channel($3); }
	;

circle :
	  CIRCLE LPAREN CHARSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new circle($3, 0, $7);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	    }
	;

circularClosedProfile :
	  CIRCULARCLOSEDPROFILE LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new circularClosedProfile($3, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->diameter));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	    }
	;

circularClosedShapeProfile :
	  CIRCULARCLOSEDSHAPEPROFILE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new circularClosedShapeProfile($3, 0, $7, 0, 0, 0, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      linearPath_refs.push_back(&($$->profileSweptShape));
	      linearPath_nums.push_back($13->val);
	      delete $13;
	      profileSelect_refs.push_back(&($$->floorCondition));
	      profileSelect_nums.push_back($15->val);
	      delete $15;
	      direction_refs.push_back(&($$->removalDirection));
	      direction_nums.push_back($17->val);
	      delete $17;
	      circularClosedProfile_refs.push_back(&($$->closedBoundary));
	      circularClosedProfile_nums.push_back($19->val);
	      delete $19;
	    }
	;

circularOffset :
	  CIRCULAROFFSET LPAREN REALSTRING C INTSTRING RPAREN
	    { $$ = new circularOffset($3, $5); }
	;

circularOffsetList :
	  instanceId
	    { $$ = new std::list<circularOffset *>;
	      $$->push_back(0);
	      circularOffset_refs.push_back(&($$->back()));
	      circularOffset_nums.push_back($1->val);
	    }
	| circularOffsetList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      circularOffset_refs.push_back(&($$->back()));
	      circularOffset_nums.push_back($3->val);
	    }
	;

circularOmit :
	  CIRCULAROMIT LPAREN INTSTRING RPAREN
	    { $$ = new circularOmit($3); }
	;

circularOmitList :
	  instanceId
	    { $$ = new std::list<circularOmit *>;
	      $$->push_back(0);
	      circularOmit_refs.push_back(&($$->back()));
	      circularOmit_nums.push_back($1->val);
	    }
	| circularOmitList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      circularOmit_refs.push_back(&($$->back()));
	      circularOmit_nums.push_back($3->val);
	    }
	;

circularPattern :
	  CIRCULARPATTERN LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C REALSTRING C INTSTRING C parenCircularOffsetList C parenCircularOmitList C optTolerancedLengthMeasure C REALSTRING RPAREN
	    { $$ = new circularPattern($3, 0, $7, 0, 0, $13, $15, $17, $19, $21, $23);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      two5DmanufacturingFeature_refs.push_back(&($$->replicateBaseFeature));
	      two5DmanufacturingFeature_nums.push_back($11->val);
	      delete $11;
	      if ($21)
		{
		  $$->baseFeatureDiameter = 0;
		  tolerancedLengthMeasure_refs.push_back(&($$->baseFeatureDiameter));
		  tolerancedLengthMeasure_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	    }
	;

closedPocket :
	  CLOSEDPOCKET LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C parenBossList C optReal C instanceId C optTolerancedLengthMeasure C optTolerancedLengthMeasure C instanceId RPAREN
	    { $$ = new closedPocket($3, 0, $7, 0, 0, $13, $15, 0, $19, $21, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      pocketBottomCondition_refs.push_back(&($$->bottomCondition));
	      pocketBottomCondition_nums.push_back($17->val);
	      delete $17;
	      if ($19)
		{
		  $$->planarRadius = 0;
		  tolerancedLengthMeasure_refs.push_back(&($$->planarRadius));
		  tolerancedLengthMeasure_nums.push_back($19->iId->val);
		  delete $19->iId;
		  delete $19;
		}
	      if ($21)
		{
		  $$->orthogonalRadius = 0;
		  tolerancedLengthMeasure_refs.push_back(&($$->orthogonalRadius));
		  tolerancedLengthMeasure_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	      closedProfile_refs.push_back(&($$->featureBoundary));
	      closedProfile_nums.push_back($23->val);
	      delete $23;
	    }
	;

closedShell :
	  CLOSEDSHELL LPAREN CHARSTRING C parenFaceListFull RPAREN
	    { $$ = new closedShell($3, $5); }
	;

combinedDrillAndReamer :
	  COMBINEDDRILLANDREAMER LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new combinedDrillAndReamer(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

combinedDrillAndTap :
	  COMBINEDDRILLANDTAP LPAREN instanceId C optInteger C optHand C optBoolean C optReal optReal RPAREN
	    { $$ = new combinedDrillAndTap(0, $5, $7, $9, $11, $12);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

comparisonEqual :
	  COMPARISONEQUAL LPAREN instanceId C instanceId RPAREN
	    { $$ = new comparisonEqual(0, 0);
	      ncVariable_refs.push_back(&($$->operand1));
	      ncVariable_nums.push_back($3->val);
	      delete $3;
	      rvalue_refs.push_back(&($$->operand2));
	      rvalue_nums.push_back($5->val);
	      delete $5;
	    }
	;

comparisonGreater :
	  COMPARISONGREATER LPAREN instanceId C instanceId RPAREN
	    { $$ = new comparisonGreater(0, 0);
	      ncVariable_refs.push_back(&($$->operand1));
	      ncVariable_nums.push_back($3->val);
	      delete $3;
	      rvalue_refs.push_back(&($$->operand2));
	      rvalue_nums.push_back($5->val);
	      delete $5;
	    }
	;

comparisonGreaterEqual :
	  COMPARISONGREATEREQUAL LPAREN instanceId C instanceId RPAREN
	    { $$ = new comparisonGreaterEqual(0, 0);
	      ncVariable_refs.push_back(&($$->operand1));
	      ncVariable_nums.push_back($3->val);
	      delete $3;
	      rvalue_refs.push_back(&($$->operand2));
	      rvalue_nums.push_back($5->val);
	      delete $5;
	    }
	;

comparisonLess :
	  COMPARISONLESS LPAREN instanceId C instanceId RPAREN
	    { $$ = new comparisonLess(0, 0);
	      ncVariable_refs.push_back(&($$->operand1));
	      ncVariable_nums.push_back($3->val);
	      delete $3;
	      rvalue_refs.push_back(&($$->operand2));
	      rvalue_nums.push_back($5->val);
	      delete $5;
	    }
	;

comparisonLessEqual :
	  COMPARISONLESSEQUAL LPAREN instanceId C instanceId RPAREN
	    { $$ = new comparisonLessEqual(0, 0);
	      ncVariable_refs.push_back(&($$->operand1));
	      ncVariable_nums.push_back($3->val);
	      delete $3;
	      rvalue_refs.push_back(&($$->operand2));
	      rvalue_nums.push_back($5->val);
	      delete $5;
	    }
	;

comparisonNotEqual :
	  COMPARISONNOTEQUAL LPAREN instanceId C instanceId RPAREN
	    { $$ = new comparisonNotEqual(0, 0);
	      ncVariable_refs.push_back(&($$->operand1));
	      ncVariable_nums.push_back($3->val);
	      delete $3;
	      rvalue_refs.push_back(&($$->operand2));
	      rvalue_nums.push_back($5->val);
	      delete $5;
	    }
	;

completeCircularPath :
	  COMPLETECIRCULARPATH LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new completeCircularPath($3, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	    }
	;

compositeCurve :
	  COMPOSITECURVE LPAREN CHARSTRING C parenCompositeCurveSegmentListFull C logical RPAREN
	    { $$ = new compositeCurve($3, $5, $7); }
	;

compositeCurveSegment :
	  COMPOSITECURVESEGMENT LPAREN transitionCode C boolean C instanceId RPAREN
	    { $$ = new compositeCurveSegment($3, $5, 0);
	      curve_refs.push_back(&($$->parentCurve));
	      curve_nums.push_back($7->val);
	      delete $7;
	    }
	;

compositeCurveSegmentList :
	  instanceId
	    { $$ = new std::list<compositeCurveSegment *>;
	      $$->push_back(0);
	      compositeCurveSegment_refs.push_back(&($$->back()));
	      compositeCurveSegment_nums.push_back($1->val);
	    }
	| compositeCurveSegmentList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      compositeCurveSegment_refs.push_back(&($$->back()));
	      compositeCurveSegment_nums.push_back($3->val);
	    }
	;

compoundFeatureSelectList :
	  instanceId
	    { $$ = new std::list<compoundFeatureSelect *>;
	      $$->push_back(0);
	      compoundFeatureSelect_refs.push_back(&($$->back()));
	      compoundFeatureSelect_nums.push_back($1->val);
	    }
	| compoundFeatureSelectList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      compoundFeatureSelect_refs.push_back(&($$->back()));
	      compoundFeatureSelect_nums.push_back($3->val);
	    }
	;

conicalHoleBottom :
	  CONICALHOLEBOTTOM LPAREN real C optTolerancedLengthMeasure RPAREN
	    { $$ = new conicalHoleBottom($3, $5);
	      if ($5)
		{
		  $$->tipRadius = 0;
		  tolerancedLengthMeasure_refs.push_back(&($$->tipRadius));
		  tolerancedLengthMeasure_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	    }
	;

connectDirect :
	  CONNECTDIRECT LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions RPAREN
	    { $$ = new connectDirect($3, $5, $7, $9, $11);
	      if (($7) && ($7->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($7);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->iId->val);
		  delete v->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsTechnology = 0;
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsMachineFunctions = 0;
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	    }
	;

connectSecplane :
	  CONNECTSECPLANE LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions C optDirection C optDirection RPAREN
	    { $$ = new connectSecplane($3, $5, $7, $9, $11, $13, $15);
	      if (($7) && ($7->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($7);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->iId->val);
		  delete v->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsTechnology = 0;
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsMachineFunctions = 0;
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      if ($13)
		{
		  $$->upDir = 0;
		  direction_refs.push_back(&($$->upDir));
		  direction_nums.push_back($13->iId->val);
		  delete $13->iId;
		  delete $13;
		}
	      if ($15)
		{
		  $$->downDir = 0;
		  direction_refs.push_back(&($$->downDir));
		  direction_nums.push_back($15->iId->val);
		  delete $15->iId;
		  delete $15;
		}
	    }
	;

contactType :
	  contactTypeSide
	    { $$ = $1; }
	| contactTypeFront
	    { $$ = $1; }
	;

contactTypeSide :
	  CONTACTTYPESIDE
	    { $$ = new contactTypeSide(); }
	;

contactTypeFront :
	  CONTACTTYPEFRONT
	    { $$ = new contactTypeFront(); }
	;

contourBidirectional :
	  CONTOURBIDIRECTIONAL LPAREN optReal C optBoolean C optDirection C optLeftOrRight optRotDirection optCutmodeType RPAREN
	    { $$ = new contourBidirectional($3, $5, $7, $9, $10, $11);
	      if ($7)
		{
		  $$->feedDirection = 0;
		  direction_refs.push_back(&($$->feedDirection));
		  direction_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	    }
	;

contourParallel :
	  CONTOURPARALLEL LPAREN optReal C optBoolean C rotDirection C optCutmodeType RPAREN
	    { $$ = new contourParallel($3, $5, $7, $9); }
	;

contourSpiral :
	  CONTOURSPIRAL LPAREN optReal C optBoolean C rotDirection C optCutmodeType RPAREN
	    { $$ = new contourSpiral($3, $5, $7, $9); }
	;

coordinatedUniversalTimeOffset :
	  COORDINATEDUNIVERSALTIMEOFFSET LPAREN INTSTRING optInteger aheadOrBehind RPAREN
	    { $$ = new coordinatedUniversalTimeOffset($3, $4, $5); }
	;

counterbore :
	  COUNTERBORE LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new counterbore(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

counterboreHole :
	  COUNTERBOREHOLE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C parenCompoundFeatureSelectListFull RPAREN
	    { $$ = new counterboreHole($3, 0, $7, 0, $11);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	    }
	;

countersink :
	  COUNTERSINK LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new countersink(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

counterSinking :
	  COUNTERSINKING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy RPAREN
	    { $$ = new counterSinking($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($29)
		{
		  $$->itsMachiningStrategy = 0;
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->iId->val);
		  delete $29->iId;
		  delete $29;
		}
	    }
	;

countersunkHole :
	  COUNTERSUNKHOLE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C parenCompoundFeatureSelectListFull RPAREN
	    { $$ = new countersunkHole($3, 0, $7, 0, $11);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	    }
	;

curveWithNormalVector :
	  CURVEWITHNORMALVECTOR LPAREN instanceId C instanceId RPAREN
	    { $$ = new curveWithNormalVector(0, 0);
	      boundedCurve_refs.push_back(&($$->basiccurve));
	      boundedCurve_nums.push_back($3->val);
	      delete $3;
	      boundedCurve_refs.push_back(&($$->surfaceNormal));
	      boundedCurve_nums.push_back($5->val);
	      delete $5;
	    }
	;

cutmodeType :
	  cutmodeTypeClimb
	    { $$ = $1; }
	| cutmodeTypeConventional
	    { $$ = $1; }
	;

cutmodeTypeClimb :
	  CUTMODETYPECLIMB
	    { $$ = new cutmodeTypeClimb(); }
	;

cutmodeTypeConventional :
	  CUTMODETYPECONVENTIONAL
	    { $$ = new cutmodeTypeConventional(); }
	;

cutterContactTrajectory :
	  CUTTERCONTACTTRAJECTORY LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions C optBoolean C instanceId C optBoundedCurve C optContactType RPAREN
	    { $$ = new cutterContactTrajectory($3, $5, $7, $9, $11, $13, 0, $17, $19);
	      if (($7) && ($7->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($7);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->iId->val);
		  delete v->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsTechnology = 0;
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsMachineFunctions = 0;
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      curveWithSurfaceNormalSelect_refs.push_back(&($$->basiccurve));
	      curveWithSurfaceNormalSelect_nums.push_back($15->val);
	      delete $15;
	      if ($17)
		{
		  $$->itsToolaxis = 0;
		  boundedCurve_refs.push_back(&($$->itsToolaxis));
		  boundedCurve_nums.push_back($17->iId->val);
		  delete $17->iId;
		  delete $17;
		}
	    }
	;

cutterLocationTrajectory :
	  CUTTERLOCATIONTRAJECTORY LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions C optBoolean C instanceId C optBoundedCurve C optBoundedCurve RPAREN
	    { $$ = new cutterLocationTrajectory($3, $5, $7, $9, $11, $13, 0, $17, $19);
	      if (($7) && ($7->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($7);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->iId->val);
		  delete v->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsTechnology = 0;
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsMachineFunctions = 0;
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      boundedCurve_refs.push_back(&($$->basiccurve));
	      boundedCurve_nums.push_back($15->val);
	      delete $15;
	      if ($17)
		{
		  $$->itsToolaxis = 0;
		  boundedCurve_refs.push_back(&($$->itsToolaxis));
		  boundedCurve_nums.push_back($17->iId->val);
		  delete $17->iId;
		  delete $17;
		}
	      if ($19)
		{
		  $$->surfaceNormal = 0;
		  boundedCurve_refs.push_back(&($$->surfaceNormal));
		  boundedCurve_nums.push_back($19->iId->val);
		  delete $19->iId;
		  delete $19;
		}
	    }
	;

cuttingComponent :
	  CUTTINGCOMPONENT LPAREN REALSTRING C optMaterial C optCuttingEdgeTechnologicalData C optReal C optMillingTechnology RPAREN
	    { $$ = new cuttingComponent($3, $5, $7, $9, $11);
	      if ($5)
		{
		  $$->itsMaterial = 0;
		  material_refs.push_back(&($$->itsMaterial));
		  material_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($7)
		{
		  $$->technologicalData = 0;
		  cuttingEdgeTechnologicalData_refs.push_back(&($$->technologicalData));
		  cuttingEdgeTechnologicalData_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	      if ($11)
		{
		  $$->itsTechnology = 0;
		  millingTechnology_refs.push_back(&($$->itsTechnology));
		  millingTechnology_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	    }
	;

cuttingComponentList :
	  instanceId
	    { $$ = new std::list<cuttingComponent *>;
	      $$->push_back(0);
	      cuttingComponent_refs.push_back(&($$->back()));
	      cuttingComponent_nums.push_back($1->val);
	    }
	| cuttingComponentList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      cuttingComponent_refs.push_back(&($$->back()));
	      cuttingComponent_nums.push_back($3->val);
	    }
	;

cuttingEdgeTechnologicalData :
	  CUTTINGEDGETECHNOLOGICALDATA LPAREN optReal C optReal C optReal RPAREN
	    { $$ = new cuttingEdgeTechnologicalData($3, $5, $7); }
	;

dataSection :
	  dataStarter instancePlusList endSection
	    { $$ = new dataSection($1, $2, $3); }
	;

dataStarter :
	  DATA SEMICOLON
	    { $$ = new dataStarter(); }
	;

dateAndTime :
	  DATEANDTIME LPAREN instanceId C instanceId RPAREN
	    { $$ = new dateAndTime(0, 0);
	      date_refs.push_back(&($$->dateComponent));
	      date_nums.push_back($3->val);
	      delete $3;
	      localTime_refs.push_back(&($$->timeComponent));
	      localTime_nums.push_back($5->val);
	      delete $5;
	    }
	;

definedThread :
	  DEFINEDTHREAD LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C parenMachiningFeatureListFull C boolean C optDescriptiveParameter C instanceId C instanceId C REALSTRING C instanceId C instanceId C REALSTRING C optReal C optReal RPAREN
	    { $$ = new definedThread($3, 0, $7, 0, 0, 0, $15, $17, $19, 0, 0, $25, 0, 0, $31, $33, $35);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      partialAreaDefinition_refs.push_back(&($$->partialProfile));
	      partialAreaDefinition_nums.push_back($13->val);
	      delete $13;
	      if ($19)
		{
		  $$->qualifier = 0;
		  descriptiveParameter_refs.push_back(&($$->qualifier));
		  descriptiveParameter_nums.push_back($19->iId->val);
		  delete $19->iId;
		  delete $19;
		}
	      descriptiveParameter_refs.push_back(&($$->fitClass));
	      descriptiveParameter_nums.push_back($21->val);
	      delete $21;
	      descriptiveParameter_refs.push_back(&($$->form));
	      descriptiveParameter_nums.push_back($23->val);
	      delete $23;
	      numericParameter_refs.push_back(&($$->numberOfThreads));
	      numericParameter_nums.push_back($27->val);
	      delete $27;
	      descriptiveParameter_refs.push_back(&($$->threadHand));
	      descriptiveParameter_nums.push_back($29->val);
	      delete $29;
	    }
	;

definitionalRepresentation :
	  DEFINITIONALREPRESENTATION LPAREN CHARSTRING C parenRepresentationItemListFull C representationContext RPAREN
	    { $$ = new definitionalRepresentation($3, $5, $7); }
	;

descriptiveParameter :
	  DESCRIPTIVEPARAMETER LPAREN CHARSTRING C CHARSTRING RPAREN
	    { $$ = new descriptiveParameter($3, $5); }
	;

diameterTaper :
	  DIAMETERTAPER LPAREN instanceId RPAREN
	    { $$ = new diameterTaper(0);
	      tolerancedLengthMeasure_refs.push_back(&($$->finalDiameter));
	      tolerancedLengthMeasure_nums.push_back($3->val);
	      delete $3;
	    }
	;

direction :
	  DIRECTION LPAREN CHARSTRING C parenRealListFull RPAREN
	    { $$ = new direction($3, $5); }
	;

displayMessage :
	  DISPLAYMESSAGE LPAREN CHARSTRING C CHARSTRING RPAREN
	    { $$ = new displayMessage($3, $5); }
	;

dovetailMill :
	  DOVETAILMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new dovetailMill(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

drilling :
	  DRILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy RPAREN
	    { $$ = new drilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($29)
		{
		  $$->itsMachiningStrategy = 0;
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->iId->val);
		  delete $29->iId;
		  delete $29;
		}
	    }
	;

drillingTypeStrategy :
	  DRILLINGTYPESTRATEGY LPAREN optReal C optReal C optReal C optReal C optReal C optReal RPAREN
	    { $$ = new drillingTypeStrategy($3, $5, $7, $9, $11, $13); }
	;

edgeCurve :
	  EDGECURVE LPAREN CHARSTRING C instanceId C instanceId C instanceId C boolean RPAREN
	    { $$ = new edgeCurve($3, 0, 0, 0, $11);
	      vertex_refs.push_back(&($$->edgeStart));
	      vertex_nums.push_back($5->val);
	      delete $5;
	      vertex_refs.push_back(&($$->edgeEnd));
	      vertex_nums.push_back($7->val);
	      delete $7;
	      curve_refs.push_back(&($$->edgeGeometry));
	      curve_nums.push_back($9->val);
	      delete $9;
	    }
	;

edgeLoop :
	  EDGELOOP LPAREN CHARSTRING C parenOrientedEdgeListFull RPAREN
	    { $$ = new edgeLoop($3, $5); }
	;

edgeRound :
	  EDGEROUND LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C optTolerancedLengthMeasure C optTolerancedLengthMeasure RPAREN
	    { $$ = new edgeRound($3, 0, $7, 0, 0, 0, $15, $17);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      machiningFeature_refs.push_back(&($$->firstFeature));
	      machiningFeature_nums.push_back($9->val);
	      delete $9;
	      machiningFeature_refs.push_back(&($$->secondFeature));
	      machiningFeature_nums.push_back($11->val);
	      delete $11;
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($13->val);
	      delete $13;
	      if ($15)
		{
		  $$->firstOffsetAmount = 0;
		  tolerancedLengthMeasure_refs.push_back(&($$->firstOffsetAmount));
		  tolerancedLengthMeasure_nums.push_back($15->iId->val);
		  delete $15->iId;
		  delete $15;
		}
	      if ($17)
		{
		  $$->secondOffsetAmount = 0;
		  tolerancedLengthMeasure_refs.push_back(&($$->secondOffsetAmount));
		  tolerancedLengthMeasure_nums.push_back($17->iId->val);
		  delete $17->iId;
		  delete $17;
		}
	    }
	;

ellipse :
	  ELLIPSE LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new ellipse($3, 0, $7, $9);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	    }
	;

endSection :
	  ENDSEC SEMICOLON
	    { $$ = new endSection(); }
	;

exchangePallet :
	  EXCHANGEPALLET LPAREN CHARSTRING RPAREN
	    { $$ = new exchangePallet($3); }
	;

executableList :
	  instanceId
	    { $$ = new std::list<executable *>;
	      $$->push_back(0);
	      executable_refs.push_back(&($$->back()));
	      executable_nums.push_back($1->val);
	    }
	| executableList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      executable_refs.push_back(&($$->back()));
	      executable_nums.push_back($3->val);
	    }
	;

explicitStrategy :
	  EXPLICITSTRATEGY LPAREN optReal C optBoolean RPAREN
	    { $$ = new explicitStrategy($3, $5); }
	;

faceList :
	  instanceId
	    { $$ = new std::list<face *>;
	      $$->push_back(0);
	      face_refs.push_back(&($$->back()));
	      face_nums.push_back($1->val);
	    }
	| faceList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      face_refs.push_back(&($$->back()));
	      face_nums.push_back($3->val);
	    }
	;

facemill :
	  FACEMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new facemill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

faceBound :
	  FACEBOUND LPAREN CHARSTRING C instanceId C boolean RPAREN
	    { $$ = new faceBound($3, 0, $7);
	      loop_refs.push_back(&($$->bound));
	      loop_nums.push_back($5->val);
	      delete $5;
	    }
	;

faceBoundList :
	  instanceId
	    { $$ = new std::list<faceBound *>;
	      $$->push_back(0);
	      faceBound_refs.push_back(&($$->back()));
	      faceBound_nums.push_back($1->val);
	    }
	| faceBoundList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      faceBound_refs.push_back(&($$->back()));
	      faceBound_nums.push_back($3->val);
	    }
	;

faceOuterBound :
	  FACEOUTERBOUND LPAREN CHARSTRING C instanceId C boolean RPAREN
	    { $$ = new faceOuterBound($3, 0, $7);
	      loop_refs.push_back(&($$->bound));
	      loop_nums.push_back($5->val);
	      delete $5;
	    }
	;

feedstop :
	  FEEDSTOP LPAREN boolean C toolpathType C optToolpathSpeedprofile C optTechnology C optMachineFunctions C REALSTRING RPAREN
	    { $$ = new feedstop($3, $5, $7, $9, $11, $13);
	      if (($7) && ($7->isA(toolpathSpeed_E)))
		{
		  toolpathSpeed * v;
		  v = dynamic_cast<toolpathSpeed *>($7);
		  $$->itsSpeed = 0;
		  toolpathSpeedprofile_refs.push_back(&($$->itsSpeed));
		  toolpathSpeedprofile_nums.push_back(v->iId->val);
		  delete v->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsTechnology = 0;
		  technology_refs.push_back(&($$->itsTechnology));
		  technology_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsMachineFunctions = 0;
		  machineFunctions_refs.push_back(&($$->itsMachineFunctions));
		  machineFunctions_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	    }
	;

fileDescription :
	  FILEDESCRIPTION LPAREN parenStringListFull C CHARSTRING RPAREN SEMICOLON
	    { $$ = new fileDescription($3, $5); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

fileEnd :
	  FILEEND SEMICOLON
	    { $$ = new fileEnd(); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

fileName :
	  FILENAME LPAREN CHARSTRING C CHARSTRING C parenStringListFull C parenStringListFull C CHARSTRING C CHARSTRING C CHARSTRING RPAREN SEMICOLON
	    { $$ = new fileName($3, $5, $7, $9, $11, $13, $15); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

fileSchema :
	  FILESCHEMA LPAREN parenStringList RPAREN SEMICOLON
	    { $$ = new fileSchema($3); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

fileStart :
	  FILESTART SEMICOLON
	    { $$ = new fileStart(); }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

fittingType :
	  fittingTypeShaft
	    { $$ = $1; }
	| fittingTypeHole
	    { $$ = $1; }
	;

fittingTypeHole :
	  FITTINGTYPEHOLE
	    { $$ = new fittingTypeHole(); }
	;

fittingTypeShaft :
	  FITTINGTYPESHAFT
	    { $$ = new fittingTypeShaft(); }
	;

fiveAxesVarTiltYaw :
	  FIVEAXESVARTILTYAW LPAREN RPAREN
	    { $$ = new fiveAxesVarTiltYaw(); }
	;

fiveAxesConstTiltYaw :
	  FIVEAXESCONSTTILTYAW LPAREN REALSTRING C REALSTRING RPAREN
	    { $$ = new fiveAxesConstTiltYaw($3, $5); }
	;

flatHoleBottom :
	  FLATHOLEBOTTOM LPAREN RPAREN
	    { $$ = new flatHoleBottom(); }
	;

flatSlotEndType :
	  FLATSLOTENDTYPE LPAREN instanceId C instanceId RPAREN
	    { $$ = new flatSlotEndType(0, 0);
	      tolerancedLengthMeasure_refs.push_back(&($$->cornerRadius1));
	      tolerancedLengthMeasure_nums.push_back($3->val);
	      delete $3;
	      tolerancedLengthMeasure_refs.push_back(&($$->cornerRadius2));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	    }
	;

flatWithRadiusHoleBottom :
	  FLATWITHRADIUSHOLEBOTTOM LPAREN instanceId RPAREN
	    { $$ = new flatWithRadiusHoleBottom(0);
	      tolerancedLengthMeasure_refs.push_back(&($$->cornerRadius));
	      tolerancedLengthMeasure_nums.push_back($3->val);
	      delete $3;
	    }
	;

freeformOperation :
	  FREEFORMOPERATION LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optFreeformStrategy RPAREN
	    { $$ = new freeformOperation($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($21)
		{
		  $$->approach = 0;
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	      if ($23)
		{
		  $$->retract = 0;
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->iId->val);
		  delete $23->iId;
		  delete $23;
		}
	      if ($25)
		{
		  $$->itsMachiningStrategy = 0;
		  freeformStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  freeformStrategy_nums.push_back($25->iId->val);
		  delete $25->iId;
		  delete $25;
		}
	    }
	;

generalClosedProfile :
	  GENERALCLOSEDPROFILE LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new generalClosedProfile($3, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      boundedCurve_refs.push_back(&($$->closedProfileShape));
	      boundedCurve_nums.push_back($5->val);
	      delete $5;
	    }
	;

generalOutsideProfile :
	  GENERALOUTSIDEPROFILE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new generalOutsideProfile($3, 0, $7, 0, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      linearPath_refs.push_back(&($$->profileSweptShape));
	      linearPath_nums.push_back($13->val);
	      delete $13;
	      profile_refs.push_back(&($$->featureBoundary));
	      profile_nums.push_back($15->val);
	      delete $15;
	    }
	;

generalPath :
	  GENERALPATH LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new generalPath($3, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      boundedCurve_refs.push_back(&($$->sweptPath));
	      boundedCurve_nums.push_back($5->val);
	      delete $5;
	    }
	;

generalPattern :
	  GENERALPATTERN LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C parenAxis2placement3dListFull RPAREN
	    { $$ = new generalPattern($3, 0, $7, 0, 0, $13);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      two5DmanufacturingFeature_refs.push_back(&($$->replicateBaseFeature));
	      two5DmanufacturingFeature_nums.push_back($11->val);
	      delete $11;
	    }
	;

generalPocketBottomCondition :
	  GENERALPOCKETBOTTOMCONDITION LPAREN instanceId RPAREN
	    { $$ = new generalPocketBottomCondition(0);
	      region_refs.push_back(&($$->shape));
	      region_nums.push_back($3->val);
	      delete $3;
	    }
	;

generalProfile :
	  GENERALPROFILE LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new generalProfile($3, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      boundedCurve_refs.push_back(&($$->itsProfile));
	      boundedCurve_nums.push_back($5->val);
	      delete $5;
	    }
	;

generalProfileFloor :
	  GENERALPROFILEFLOOR LPAREN optReal C boolean C instanceId RPAREN
	    { $$ = new generalProfileFloor($3, $5, 0);
	      face_refs.push_back(&($$->floor));
	      face_nums.push_back($7->val);
	      delete $7;
	    }
	;

generalShapeProfile :
	  GENERALSHAPEPROFILE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new generalShapeProfile($3, 0, $7, 0, 0, 0, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      linearPath_refs.push_back(&($$->profileSweptShape));
	      linearPath_nums.push_back($13->val);
	      delete $13;
	      profileSelect_refs.push_back(&($$->floorCondition));
	      profileSelect_nums.push_back($15->val);
	      delete $15;
	      direction_refs.push_back(&($$->removalDirection));
	      direction_nums.push_back($17->val);
	      delete $17;
	      profile_refs.push_back(&($$->profileBoundary));
	      profile_nums.push_back($19->val);
	      delete $19;
	    }
	;

hand :
	  handLeft
	    { $$ = $1; }
	| handRight
	    { $$ = $1; }
	| handNeutral
	    { $$ = $1; }
	;

handLeft :
	  LEFT
	    { $$ = new handLeft(); }
	;

handNeutral :
	  NEUTRAL
	    { $$ = new handNeutral(); }
	;

handRight :
	  RIGHT
	    { $$ = new handRight(); }
	;

headerSection :
	  headerStarter fileDescription fileName fileSchema endSection
	    { $$ = new headerSection($1, $2, $3, $4, $5); }
	;

headerStarter :
	  HEADER SEMICOLON
	    { $$ = new headerStarter(); }
	;

helix :
	  HELIX LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new helix($3, 0, $7, $9);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	    }
	;

hyperbola :
	  HYPERBOLA LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new hyperbola($3, 0, $7, $9);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	    }
	;

ifStatement :
	  IFSTATEMENT LPAREN CHARSTRING C instanceId C instanceId C optExecutable RPAREN
	    { $$ = new ifStatement($3, 0, 0, $9);
	      booleanExpression_refs.push_back(&($$->condition));
	      booleanExpression_nums.push_back($5->val);
	      delete $5;
	      executable_refs.push_back(&($$->trueBranch));
	      executable_nums.push_back($7->val);
	      delete $7;
	      if ($9)
		{
		  $$->falseBranch = 0;
		  executable_refs.push_back(&($$->falseBranch));
		  executable_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	    }
	;

indexPallet :
	  INDEXPALLET LPAREN CHARSTRING C INTSTRING RPAREN
	    { $$ = new indexPallet($3, $5); }
	;

indexTable :
	  INDEXTABLE LPAREN CHARSTRING C INTSTRING RPAREN
	    { $$ = new indexTable($3, $5); }
	;

inProcessGeometry :
	  INPROCESSGEOMETRY LPAREN optAdvancedBrepShapeRepresentation C optAdvancedBrepShapeRepresentation C optAdvancedBrepShapeRepresentation RPAREN
	    { $$ = new inProcessGeometry($3, $5, $7);
	      if ($3)
		{
		  $$->asIs = 0;
		  advancedBrepShapeRepresentation_refs.push_back(&($$->asIs));
		  advancedBrepShapeRepresentation_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->toBe = 0;
		  advancedBrepShapeRepresentation_refs.push_back(&($$->toBe));
		  advancedBrepShapeRepresentation_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($7)
		{
		  $$->removal = 0;
		  advancedBrepShapeRepresentation_refs.push_back(&($$->removal));
		  advancedBrepShapeRepresentation_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	    }
	;

instanceId :
	  SHARP INTSTRING
	    { $$ = new instanceId($2); }
	;

instancePlusList :
	  instancePlus
	    { $$ = new std::list<instance *>;
	      $$->push_back($1); }
	| instancePlusList instancePlus
	    { $$ = $1;
	      $$->push_back($2); }
	;

instancePlus :
	  instanceId EQUALS instance SEMICOLON
	    { int n;
	      $$ = $3;
	      $3->iId = $1;
	      n = $1->val;
	      if (n < INSTANCEMAX)
		{
		  if (instances[n])
		    {
		      fprintf(report, "instanceId %d reused\n", n);
		      numErrors++;
		    }
		  else
		    instances[n] = $$;
		}
	      else
		{
		  fprintf(report, "instanceId %d is too large\n", n);
		  numErrors++;
		}
	    }
	| error SEMICOLON
	  {
	    numErrors++;
	    yyerrok;
	  }
	;

integer :
	  INTSTRING
	    { $$ = new integer($1); }
	;

integerList :
	  integer
	    { $$ = new std::list<integer *>;
	      $$->push_back($1); }
	| integerList C integer
	    { $$ = $1;
	      $$->push_back($3); }
	;

knotType :
	  knotTypeUniformKnots
	    { $$ = $1; }
	| knotTypeQuasiUniformKnots
	    { $$ = $1; }
	| knotTypePiecewiseBezierKnots
	    { $$ = $1; }
	| knotTypeUnspecified
	    { $$ = $1; }
	;

knotTypePiecewiseBezierKnots :
	  KNOTTYPEPIECEWISEBEZIERKNOTS
	    { $$ = new knotTypePiecewiseBezierKnots(); }
	;

knotTypeQuasiUniformKnots :
	  KNOTTYPEQUASIUNIFORMKNOTS
	    { $$ = new knotTypeQuasiUniformKnots(); }
	;

knotTypeUniformKnots :
	  KNOTTYPEUNIFORMKNOTS
	    { $$ = new knotTypeUniformKnots(); }
	;

knotTypeUnspecified :
	  KNOTTYPEUNSPECIFIED
	    { $$ = new knotTypeUnspecified(); }
	;

leadingLineStrategy :
	  LEADINGLINESTRATEGY LPAREN pathmodeType C cutmodeType C instanceId C optReal C instanceId RPAREN
	    { $$ = new leadingLineStrategy($3, $5, 0, $9, 0);
	      tolerances_refs.push_back(&($$->itsMillingTolerances));
	      tolerances_nums.push_back($7->val);
	      delete $7;
	      boundedCurve_refs.push_back(&($$->itsLine));
	      boundedCurve_nums.push_back($11->val);
	      delete $11;
	    }
	;

leftOrRight :
	  leftOrRightLeft
	    { $$ = $1; }
	| leftOrRightRight
	    { $$ = $1; }
	;

leftOrRightLeft :
	  LEFT
	    { $$ = new leftOrRightLeft(); }
	;

leftOrRightRight :
	  RIGHT
	    { $$ = new leftOrRightRight(); }
	;

limitsAndFits :
	  LIMITSANDFITS LPAREN REALSTRING C REALSTRING C optFittingType RPAREN
	    { $$ = new limitsAndFits($3, $5, $7); }
	;

line :
	  LINE LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new line($3, 0, 0);
	      cartesianPoint_refs.push_back(&($$->pnt));
	      cartesianPoint_nums.push_back($5->val);
	      delete $5;
	      vector_refs.push_back(&($$->dir));
	      vector_nums.push_back($7->val);
	      delete $7;
	    }
	;

linearPath :
	  LINEARPATH LPAREN optAxis2placement3d C instanceId C instanceId RPAREN
	    { $$ = new linearPath($3, 0, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->distance));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	      direction_refs.push_back(&($$->itsDirection));
	      direction_nums.push_back($7->val);
	      delete $7;
	    }
	;

linearProfile :
	  LINEARPROFILE LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new linearProfile($3, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      numericParameter_refs.push_back(&($$->profileLength));
	      numericParameter_nums.push_back($5->val);
	      delete $5;
	    }
	;

loadTool :
	  LOADTOOL LPAREN CHARSTRING C instanceId RPAREN
	    { $$ = new loadTool($3, 0);
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($5->val);
	      delete $5;
	    }
	;

localTime :
	  LOCALTIME LPAREN INTSTRING optInteger optReal instanceId RPAREN
	    { $$ = new localTime($3, $4, $5, 0);
	      coordinatedUniversalTimeOffset_refs.push_back(&($$->zone));
	      coordinatedUniversalTimeOffset_nums.push_back($6->val);
	      delete $6;
	    }
	;

logical :
	  logicalTrue
	    { $$ = $1; }
	| logicalFalse
	    { $$ = $1; }
	| logicalUnknown
	    { $$ = $1; }
	;

logicalFalse :
	  FALSE
	    { $$ = new logicalFalse(); }
	;

logicalTrue :
	  TRUE
	    { $$ = new logicalTrue(); }
	;

logicalUnknown :
	  UNKNOWN
	    { $$ = new logicalUnknown(); }
	;

loopSlotEndType :
	  LOOPSLOTENDTYPE LPAREN RPAREN
	    { $$ = new loopSlotEndType(); }
	;

machinedSurface :
	  MACHINEDSURFACE LPAREN instanceId C bottomOrSide RPAREN
	    { $$ = new machinedSurface(0, $5);
	      machiningFeature_refs.push_back(&($$->itsMachiningFeature));
	      machiningFeature_nums.push_back($3->val);
	      delete $3;
	    }
	;

machinedSurfaceList :
	  instanceId
	    { $$ = new std::list<machinedSurface *>;
	      $$->push_back(0);
	      machinedSurface_refs.push_back(&($$->back()));
	      machinedSurface_nums.push_back($1->val);
	    }
	| machinedSurfaceList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      machinedSurface_refs.push_back(&($$->back()));
	      machinedSurface_nums.push_back($3->val);
	    }
	;

machiningFeatureList :
	  instanceId
	    { $$ = new std::list<machiningFeature *>;
	      $$->push_back(0);
	      machiningFeature_refs.push_back(&($$->back()));
	      machiningFeature_nums.push_back($1->val);
	    }
	| machiningFeatureList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      machiningFeature_refs.push_back(&($$->back()));
	      machiningFeature_nums.push_back($3->val);
	    }
	;

machiningOperationList :
	  instanceId
	    { $$ = new std::list<machiningOperation *>;
	      $$->push_back(0);
	      machiningOperation_refs.push_back(&($$->back()));
	      machiningOperation_nums.push_back($1->val);
	    }
	| machiningOperationList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      machiningOperation_refs.push_back(&($$->back()));
	      machiningOperation_nums.push_back($3->val);
	    }
	;

machiningWorkingstep :
	  MACHININGWORKINGSTEP LPAREN CHARSTRING C instanceId C instanceId C instanceId C optInProcessGeometry RPAREN
	    { $$ = new machiningWorkingstep($3, 0, 0, 0, $11);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->val);
	      delete $5;
	      manufacturingFeature_refs.push_back(&($$->itsFeature));
	      manufacturingFeature_nums.push_back($7->val);
	      delete $7;
	      machiningOperation_refs.push_back(&($$->itsOperation));
	      machiningOperation_nums.push_back($9->val);
	      delete $9;
	      if ($11)
		{
		  $$->itsEffect = 0;
		  inProcessGeometry_refs.push_back(&($$->itsEffect));
		  inProcessGeometry_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	    }
	;

manifoldSolidBrep :
	  MANIFOLDSOLIDBREP LPAREN CHARSTRING C instanceId RPAREN
	    { $$ = new manifoldSolidBrep($3, 0);
	      closedShell_refs.push_back(&($$->outer));
	      closedShell_nums.push_back($5->val);
	      delete $5;
	    }
	;

material :
	  MATERIAL LPAREN CHARSTRING C CHARSTRING C parenPropertyParameterList RPAREN
	    { $$ = new material($3, $5, $7); }
	;

millingCuttingTool :
	  MILLINGCUTTINGTOOL LPAREN CHARSTRING C instanceId C parenCuttingComponentListFull C optReal C optDirection C optReal RPAREN
	    { $$ = new millingCuttingTool($3, 0, $7, $9, $11, $13);
	      toolBody_refs.push_back(&($$->itsToolBody));
	      toolBody_nums.push_back($5->val);
	      delete $5;
	      if ($11)
		{
		  $$->directionForSpindleOrientation = 0;
		  direction_refs.push_back(&($$->directionForSpindleOrientation));
		  direction_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	    }
	;

millingMachineFunctions :
	  MILLINGMACHINEFUNCTIONS LPAREN boolean C optReal C optBoolean C boolean C optReal C parenStringList C boolean C optDirection C optProcessModelList C parenPropertyParameterList RPAREN
	    { $$ = new millingMachineFunctions($3, $5, $7, $9, $11, $13, $15, $17, $19, $21);
	      if ($17)
		{
		  $$->orientedSpindleStop = 0;
		  direction_refs.push_back(&($$->orientedSpindleStop));
		  direction_nums.push_back($17->iId->val);
		  delete $17->iId;
		  delete $17;
		}
	      if ($19)
		{
		  $$->itsProcessModel = 0;
		  processModelList_refs.push_back(&($$->itsProcessModel));
		  processModelList_nums.push_back($19->iId->val);
		  delete $19->iId;
		  delete $19;
		}
	    }
	;

millingTechnology :
	  MILLINGTECHNOLOGY LPAREN optReal C toolReferencePoint C optReal C optReal C optReal C boolean C boolean C boolean C optBoolean RPAREN
	    { $$ = new millingTechnology($3, $5, $7, $9, $11, $13, $15, $17, $19); }
	;

millingThreadingTool :
	  MILLINGTHREADINGTOOL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new millingThreadingTool(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

millingToolDimension :
	  MILLINGTOOLDIMENSION LPAREN REALSTRING C optReal C optReal C optReal C optReal C optReal C optReal RPAREN
	    { $$ = new millingToolDimension($3, $5, $7, $9, $11, $13, $15); }
	;

multistepDrilling :
	  MULTISTEPDRILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy C REALSTRING C REALSTRING C REALSTRING C optReal RPAREN
	    { $$ = new multistepDrilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33, $35, $37);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($29)
		{
		  $$->itsMachiningStrategy = 0;
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->iId->val);
		  delete $29->iId;
		  delete $29;
		}
	    }
	;

ncConstant :
	  NCCONSTANT LPAREN CHARSTRING C optReal RPAREN
	    { $$ = new ncConstant($3, $5); }
	;

ncVariable :
	  NCVARIABLE LPAREN CHARSTRING C optReal RPAREN
	    { $$ = new ncVariable($3, $5); }
	;

ncVariableList :
	  instanceId
	    { $$ = new std::list<ncVariable *>;
	      $$->push_back(0);
	      ncVariable_refs.push_back(&($$->back()));
	      ncVariable_nums.push_back($1->val);
	    }
	| ncVariableList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      ncVariable_refs.push_back(&($$->back()));
	      ncVariable_nums.push_back($3->val);
	    }
	;

ngonClosedProfile :
	  NGONCLOSEDPROFILE LPAREN optAxis2placement3d C instanceId C INTSTRING C boolean RPAREN
	    { $$ = new ngonClosedProfile($3, 0, $7, $9);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->diameter));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	    }
	;

nonSequential :
	  NONSEQUENTIAL LPAREN CHARSTRING C parenExecutableListFull RPAREN
	    { $$ = new nonSequential($3, $5); }
	;

notExpression :
	  NOTEXPRESSION LPAREN instanceId RPAREN
	    { $$ = new notExpression(0);
	      booleanExpression_refs.push_back(&($$->operand));
	      booleanExpression_nums.push_back($3->val);
	      delete $3;
	    }
	;

numericParameter :
	  NUMERICPARAMETER LPAREN CHARSTRING C REALSTRING C CHARSTRING RPAREN
	    { $$ = new numericParameter($3, $5, $7); }
	;

offsetVector :
	  OFFSETVECTOR LPAREN parenNcVariableListFull C optParenNcVariableListFull RPAREN
	    { $$ = new offsetVector($3, $5); }
	;

openPocket :
	  OPENPOCKET LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C parenBossList C optReal C instanceId C optTolerancedLengthMeasure C optTolerancedLengthMeasure C instanceId C optOpenProfile RPAREN
	    { $$ = new openPocket($3, 0, $7, 0, 0, $13, $15, 0, $19, $21, 0, $25);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      pocketBottomCondition_refs.push_back(&($$->bottomCondition));
	      pocketBottomCondition_nums.push_back($17->val);
	      delete $17;
	      if ($19)
		{
		  $$->planarRadius = 0;
		  tolerancedLengthMeasure_refs.push_back(&($$->planarRadius));
		  tolerancedLengthMeasure_nums.push_back($19->iId->val);
		  delete $19->iId;
		  delete $19;
		}
	      if ($21)
		{
		  $$->orthogonalRadius = 0;
		  tolerancedLengthMeasure_refs.push_back(&($$->orthogonalRadius));
		  tolerancedLengthMeasure_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	      openProfile_refs.push_back(&($$->openBoundary));
	      openProfile_nums.push_back($23->val);
	      delete $23;
	      if ($25)
		{
		  $$->wallBoundary = 0;
		  openProfile_refs.push_back(&($$->wallBoundary));
		  openProfile_nums.push_back($25->iId->val);
		  delete $25->iId;
		  delete $25;
		}
	    }
	;

openShell :
	  OPENSHELL LPAREN CHARSTRING C parenFaceListFull RPAREN
	    { $$ = new openShell($3, $5); }
	;

openSlotEndType :
	  OPENSLOTENDTYPE LPAREN RPAREN
	    { $$ = new openSlotEndType(); }
	;

optAddress :
	  instanceId
	    { $$ = new address(0,0,0,0,0,0,0,0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optAdvancedBrepShapeRepresentation :
	  instanceId
	    { $$ = new advancedBrepShapeRepresentation(0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optApproachRetractStrategy :
	  instanceId
	    { $$ = new alongPath(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optApproval :
	  instanceId
	    { $$ = new approval(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optAxis2placement3d :
	  instanceId
	    { $$ = new axis2placement3d(0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optBoolean :
	  boolean
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optBoundedCurve :
	  instanceId
	    { $$ = new bezierCurve(0,0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optBoundingGeometrySelect :
	  instanceId
	    { $$ = new advancedBrepShapeRepresentation(0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optCartesianPoint :
	  instanceId
	    { $$ = new cartesianPoint(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optChannel :
	  instanceId
	    { $$ = new channel(0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optClosedProfile :
	  instanceId
	    { $$ = new circularClosedProfile(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optContactType :
	  contactType
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optCutmodeType :
	  cutmodeType
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optCuttingEdgeTechnologicalData :
	  instanceId
	    { $$ = new cuttingEdgeTechnologicalData(0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optDateAndTime :
	  instanceId
	    { $$ = new dateAndTime(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optDescriptiveParameter :
	  instanceId
	    { $$ = new descriptiveParameter(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optDirection :
	  instanceId
	    { $$ = new direction(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optDrillingTypeStrategy :
	  instanceId
	    { $$ = new drillingTypeStrategy(0,0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optExecutable :
	  instanceId
	    { $$ = new assignment(0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optFittingType :
	  fittingType
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optFreeformStrategy :
	  instanceId
	    { $$ = new leadingLineStrategy(0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optHand :
	  hand
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optionalStop :
	  OPTIONALSTOP LPAREN CHARSTRING RPAREN
	    { $$ = new optionalStop($3); }
	;

optInProcessGeometry :
	  instanceId
	    { $$ = new inProcessGeometry(0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optInteger :
	  integer
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optLeftOrRight :
	  leftOrRight
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optMachineFunctions :
	  instanceId
	    { $$ = new millingMachineFunctions(0,0,0,0,0,0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optMachiningTool :
	  instanceId
	    { $$ = new millingCuttingTool(0,0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optMaterial :
	  instanceId
	    { $$ = new material(0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optMillingTechnology :
	  instanceId
	    { $$ = new millingTechnology(0,0,0,0,0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optOffsetVector :
	  offsetVector
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optOpenProfile :
	  instanceId
	    { $$ = new generalProfile(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optParenNcVariableListFull :
	  parenNcVariableListFull
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optParenStringListFull :
	  parenStringListFull
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optPersonAndAddress :
	  instanceId
	    { $$ = new personAndAddress(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optProcessModelList :
	  instanceId
	    { $$ = new processModelList(0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optReal :
	  real
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optRestrictedAreaSelect :
	  instanceId
	    { $$ = new advancedBrepShapeRepresentation(0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optRotDirection :
	  rotDirection
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optSetup :
	  instanceId
	    { $$ = new setup(0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optString :
	  aString
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optStrokeConnectionStrategy :
	  strokeConnectionStrategy
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optTaperSelect :
	  instanceId
	    { $$ = new angleTaper(0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optTechnology :
	  instanceId
	    { $$ = new millingTechnology(0,0,0,0,0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optTolerancedLengthMeasure :
	  instanceId
	    { $$ = new tolerancedLengthMeasure(0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optToolDirection :
	  instanceId
	    { $$ = new threeAxes();
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optToolpathList :
	  instanceId
	    { $$ = new toolpathList(0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optToolpathSpeedprofile :
	  instanceId
	    { toolpathSpeed * v;
	      v = new toolpathSpeed(0);
	      v->iId = $1;
	      $$ = v;
	    }
	| real
	    { $$ = $1; }
	| speedName
	    { $$ = $1; }
	| DOLLAR
	    { $$ = 0; }
	;

optTwo5DmillingStrategy :
	  instanceId
	    { $$ = new bidirectionalContour(0,0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optVeeProfile :
	  instanceId
	    { $$ = new veeProfile(0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

optWorkpiece :
	  instanceId
	    { $$ = new workpiece(0,0,0,0,0,0,0);
	      $$->iId = $1;
	    }
	| DOLLAR
	    { $$ = 0; }
	;

orExpression :
	  OREXPRESSION LPAREN parenBooleanExpressionListFull RPAREN
	    { $$ = new orExpression($3); }
	;

orientedEdge :
	  ORIENTEDEDGE LPAREN CHARSTRING C instanceId C instanceId C instanceId C boolean RPAREN
	    { $$ = new orientedEdge($3, 0, 0, 0, $11);
	      vertex_refs.push_back(&($$->edgeStart));
	      vertex_nums.push_back($5->val);
	      delete $5;
	      vertex_refs.push_back(&($$->edgeEnd));
	      vertex_nums.push_back($7->val);
	      delete $7;
	      edge_refs.push_back(&($$->edgeElement));
	      edge_nums.push_back($9->val);
	      delete $9;
	    }
	;

orientedEdgeList :
	  instanceId
	    { $$ = new std::list<orientedEdge *>;
	      $$->push_back(0);
	      orientedEdge_refs.push_back(&($$->back()));
	      orientedEdge_nums.push_back($1->val);
	    }
	| orientedEdgeList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      orientedEdge_refs.push_back(&($$->back()));
	      orientedEdge_nums.push_back($3->val);
	    }
	;

ordinalDate :
	  ORDINALDATE LPAREN INTSTRING C INTSTRING RPAREN
	    { $$ = new ordinalDate($3, $5); }
	;

parabola :
	  PARABOLA LPAREN CHARSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new parabola($3, 0, $7);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	    }
	;

parallel :
	  PARALLEL LPAREN CHARSTRING C parenExecutableListFull RPAREN
	    { $$ = new parallel($3, $5); }
	;

parenAxis2placement3dListFull :
	  LPAREN axis2placement3dList RPAREN
	    { $$ = new parenAxis2placement3dListFull($2); }
	;

parenBooleanExpressionListFull :
	  LPAREN booleanExpressionList RPAREN
	    { $$ = new parenBooleanExpressionListFull($2); }
	;

parenBossList :
	  LPAREN bossList RPAREN
	    { $$ = new parenBossList($2); }
	| LPAREN RPAREN
	    { $$ = new parenBossList(new std::list<boss *>); }
	;

parenBoundedCurveListFull :
	  LPAREN boundedCurveList RPAREN
	    { $$ = new parenBoundedCurveListFull($2); }
	;

parenBoundedSurfaceListFull :
	  LPAREN boundedSurfaceList RPAREN
	    { $$ = new parenBoundedSurfaceListFull($2); }
	;

parenCartesianPointList :
	  LPAREN cartesianPointList RPAREN
	    { $$ = new parenCartesianPointList($2); }
	| LPAREN RPAREN
	    { $$ = new parenCartesianPointList(new std::list<cartesianPoint *>); }
	;

parenCartesianPointListFull :
	  LPAREN cartesianPointList RPAREN
	    { $$ = new parenCartesianPointListFull($2); }
	;

parenCartesianPointListFullList :
	  parenCartesianPointListFull
	    { $$ = new std::list<parenCartesianPointListFull *>;
	      $$->push_back($1); }
	| parenCartesianPointListFullList C parenCartesianPointListFull
	    { $$ = $1;
	      $$->push_back($3); }
	;

parenCircularOffsetList :
	  LPAREN circularOffsetList RPAREN
	    { $$ = new parenCircularOffsetList($2); }
	| LPAREN RPAREN
	    { $$ = new parenCircularOffsetList(new std::list<circularOffset *>); }
	;

parenCircularOmitList :
	  LPAREN circularOmitList RPAREN
	    { $$ = new parenCircularOmitList($2); }
	| LPAREN RPAREN
	    { $$ = new parenCircularOmitList(new std::list<circularOmit *>); }
	;

parenCompositeCurveSegmentListFull :
	  LPAREN compositeCurveSegmentList RPAREN
	    { $$ = new parenCompositeCurveSegmentListFull($2); }
	;

parenCompoundFeatureSelectListFull :
	  LPAREN compoundFeatureSelectList RPAREN
	    { $$ = new parenCompoundFeatureSelectListFull($2); }
	;

parenCuttingComponentListFull :
	  LPAREN cuttingComponentList RPAREN
	    { $$ = new parenCuttingComponentListFull($2); }
	;

parenExecutableList :
	  LPAREN executableList RPAREN
	    { $$ = new parenExecutableList($2); }
	| LPAREN RPAREN
	    { $$ = new parenExecutableList(new std::list<executable *>); }
	;

parenExecutableListFull :
	  LPAREN executableList RPAREN
	    { $$ = new parenExecutableListFull($2); }
	;

parenFaceBoundListFull :
	  LPAREN faceBoundList RPAREN
	    { $$ = new parenFaceBoundListFull($2); }
	;

parenFaceListFull :
	  LPAREN faceList RPAREN
	    { $$ = new parenFaceListFull($2); }
	;

parenIntegerListFull :
	  LPAREN integerList RPAREN
	    { $$ = new parenIntegerListFull($2); }
	;

parenMachinedSurfaceListFull :
	  LPAREN machinedSurfaceList RPAREN
	    { $$ = new parenMachinedSurfaceListFull($2); }
	;

parenMachiningFeatureListFull :
	  LPAREN machiningFeatureList RPAREN
	    { $$ = new parenMachiningFeatureListFull($2); }
	;

parenMachiningOperationList :
	  LPAREN machiningOperationList RPAREN
	    { $$ = new parenMachiningOperationList($2); }
	| LPAREN RPAREN
	    { $$ = new parenMachiningOperationList(new std::list<machiningOperation *>); }
	;

parenNcVariableListFull :
	  LPAREN ncVariableList RPAREN
	    { $$ = new parenNcVariableListFull($2); }
	;

parenOrientedEdgeListFull :
	  LPAREN orientedEdgeList RPAREN
	    { $$ = new parenOrientedEdgeListFull($2); }
	;

parenParenCartesianPointListFullListFull :
	  LPAREN parenCartesianPointListFullList RPAREN
	    { $$ = new parenParenCartesianPointListFullListFull($2); }
	;

parenParenRealListFullListFull :
	  LPAREN parenRealListFullList RPAREN
	    { $$ = new parenParenRealListFullListFull($2); }
	;

parenProcessModelLiszt :
	  LPAREN processModelLiszt RPAREN
	    { $$ = new parenProcessModelLiszt($2); }
	;

parenPropertyParameterList :
	  LPAREN propertyParameterList RPAREN
	    { $$ = new parenPropertyParameterList($2); }
	| LPAREN RPAREN
	    { $$ = new parenPropertyParameterList(new std::list<propertyParameter *>); }
	;

parenRealListFull :
	  LPAREN realList RPAREN
	    { $$ = new parenRealListFull($2); }
	;

parenRealListFullList :
	  parenRealListFull
	    { $$ = new std::list<parenRealListFull *>;
	      $$->push_back($1); }
	| parenRealListFullList C parenRealListFull
	    { $$ = $1;
	      $$->push_back($3); }
	;

parenRectangularOffsetList :
	  LPAREN rectangularOffsetList RPAREN
	    { $$ = new parenRectangularOffsetList($2); }
	| LPAREN RPAREN
	    { $$ = new parenRectangularOffsetList(new std::list<rectangularOffset *>); }
	;

parenRectangularOmitList :
	  LPAREN rectangularOmitList RPAREN
	    { $$ = new parenRectangularOmitList($2); }
	| LPAREN RPAREN
	    { $$ = new parenRectangularOmitList(new std::list<rectangularOmit *>); }
	;

parenRepresentationItemListFull :
	  LPAREN representationItemList RPAREN
	    { $$ = new parenRepresentationItemListFull($2); }
	;

parenSetupInstructionList :
	  LPAREN setupInstructionList RPAREN
	    { $$ = new parenSetupInstructionList($2); }
	| LPAREN RPAREN
	    { $$ = new parenSetupInstructionList(new std::list<setupInstruction *>); }
	;

parenSlotEndTypeList :
	  LPAREN slotEndTypeList RPAREN
	    { $$ = new parenSlotEndTypeList($2); }
	| LPAREN RPAREN
	    { $$ = new parenSlotEndTypeList(new std::list<slotEndType *>); }
	;

parenSpecificationUsageConstraintList :
	  LPAREN specificationUsageConstraintList RPAREN
	    { $$ = new parenSpecificationUsageConstraintList($2); }
	| LPAREN RPAREN
	    { $$ = new parenSpecificationUsageConstraintList(new std::list<specificationUsageConstraint *>); }
	;

parenStringList :
	  LPAREN stringList RPAREN
	    { $$ = new parenStringList($2); }
	| LPAREN RPAREN
	    { $$ = new parenStringList(new std::list<char *>); }
	;

parenStringListFull :
	  LPAREN stringList RPAREN
	    { $$ = new parenStringListFull($2); }
	;

parenToolpathLisztFull :
	  LPAREN toolpathLiszt RPAREN
	    { $$ = new parenToolpathLisztFull($2); }
	;

parenTrimmingSelectListFull :
	  LPAREN trimmingSelectList RPAREN
	    { $$ = new parenTrimmingSelectListFull($2); }
	;

parenWorkpieceList :
	  LPAREN workpieceList RPAREN
	    { $$ = new parenWorkpieceList($2); }
	| LPAREN RPAREN
	    { $$ = new parenWorkpieceList(new std::list<workpiece *>); }
	;

parenWorkpieceSetupList :
	  LPAREN workpieceSetupList RPAREN
	    { $$ = new parenWorkpieceSetupList($2); }
	| LPAREN RPAREN
	    { $$ = new parenWorkpieceSetupList(new std::list<workpieceSetup *>); }
	;

partialAreaDefinition :
	  PARTIALAREADEFINITION LPAREN REALSTRING C instanceId C optReal RPAREN
	    { $$ = new partialAreaDefinition($3, 0, $7);
	      axis2placement3d_refs.push_back(&($$->placement));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	    }
	;

partialCircularPath :
	  PARTIALCIRCULARPATH LPAREN optAxis2placement3d C instanceId C REALSTRING RPAREN
	    { $$ = new partialCircularPath($3, 0, $7);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	    }
	;

partialCircularProfile :
	  PARTIALCIRCULARPROFILE LPAREN optAxis2placement3d C instanceId C REALSTRING RPAREN
	    { $$ = new partialCircularProfile($3, 0, $7);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	    }
	;

partialCircularShapeProfile :
	  PARTIALCIRCULARSHAPEPROFILE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new partialCircularShapeProfile($3, 0, $7, 0, 0, 0, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      linearPath_refs.push_back(&($$->profileSweptShape));
	      linearPath_nums.push_back($13->val);
	      delete $13;
	      profileSelect_refs.push_back(&($$->floorCondition));
	      profileSelect_nums.push_back($15->val);
	      delete $15;
	      direction_refs.push_back(&($$->removalDirection));
	      direction_nums.push_back($17->val);
	      delete $17;
	      partialCircularProfile_refs.push_back(&($$->openBoundary));
	      partialCircularProfile_nums.push_back($19->val);
	      delete $19;
	    }
	;

pathmodeType :
	  pathmodeTypeForward
	    { $$ = $1; }
	| pathmodeTypeZigzag
	    { $$ = $1; }
	;

pathmodeTypeForward :
	  PATHMODETYPEFORWARD
	    { $$ = new pathmodeTypeForward(); }
	;

pathmodeTypeZigzag :
	  PATHMODETYPEZIGZAG
	    { $$ = new pathmodeTypeZigzag(); }
	;

pcurve :
	  PCURVE LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new pcurve($3, 0, 0);
	      surface_refs.push_back(&($$->basisSurface));
	      surface_nums.push_back($5->val);
	      delete $5;
	      definitionalRepresentation_refs.push_back(&($$->referenceToCurve));
	      definitionalRepresentation_nums.push_back($7->val);
	      delete $7;
	    }
	;

person :
	  PERSON LPAREN CHARSTRING C optString C optString C optParenStringListFull C optParenStringListFull C optParenStringListFull C RPAREN
	    { $$ = new person($3, $5, $7, $9, $11, $13); }
	;

personAndAddress :
	  PERSONANDADDRESS LPAREN instanceId C optAddress RPAREN
	    { $$ = new personAndAddress(0, $5);
	      person_refs.push_back(&($$->itsPerson));
	      person_nums.push_back($3->val);
	      delete $3;
	      if ($5)
		{
		  $$->itsAddress = 0;
		  address_refs.push_back(&($$->itsAddress));
		  address_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	    }
	;

planarFace :
	  PLANARFACE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId C optClosedProfile C parenBossList RPAREN
	    { $$ = new planarFace($3, 0, $7, 0, 0, 0, 0, $17, $19);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      linearPath_refs.push_back(&($$->courseOfTravel));
	      linearPath_nums.push_back($13->val);
	      delete $13;
	      linearProfile_refs.push_back(&($$->removalBoundary));
	      linearProfile_nums.push_back($15->val);
	      delete $15;
	      if ($17)
		{
		  $$->faceBoundary = 0;
		  closedProfile_refs.push_back(&($$->faceBoundary));
		  closedProfile_nums.push_back($17->iId->val);
		  delete $17->iId;
		  delete $17;
		}
	    }
	;

planarPocketBottomCondition :
	  PLANARPOCKETBOTTOMCONDITION LPAREN RPAREN
	    { $$ = new planarPocketBottomCondition(); }
	;

planarProfileFloor :
	  PLANARPROFILEFLOOR LPAREN optReal C boolean C instanceId RPAREN
	    { $$ = new planarProfileFloor($3, $5, 0);
	      plane_refs.push_back(&($$->floor));
	      plane_nums.push_back($7->val);
	      delete $7;
	    }
	;

plane :
	  PLANE LPAREN CHARSTRING C instanceId RPAREN
	    { $$ = new plane($3, 0);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	    }
	;

planeCcStrategy :
	  PLANECCSTRATEGY LPAREN pathmodeType C cutmodeType C instanceId C optReal C instanceId RPAREN
	    { $$ = new planeCcStrategy($3, $5, 0, $9, 0);
	      tolerances_refs.push_back(&($$->itsMillingTolerances));
	      tolerances_nums.push_back($7->val);
	      delete $7;
	      direction_refs.push_back(&($$->itsPlaneNormal));
	      direction_nums.push_back($11->val);
	      delete $11;
	    }
	;

planeClStrategy :
	  PLANECLSTRATEGY LPAREN pathmodeType C cutmodeType C instanceId C optReal C instanceId RPAREN
	    { $$ = new planeClStrategy($3, $5, 0, $9, 0);
	      tolerances_refs.push_back(&($$->itsMillingTolerances));
	      tolerances_nums.push_back($7->val);
	      delete $7;
	      direction_refs.push_back(&($$->itsPlaneNormal));
	      direction_nums.push_back($11->val);
	      delete $11;
	    }
	;

planeFinishMilling :
	  PLANEFINISHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal RPAREN
	    { $$ = new planeFinishMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($21)
		{
		  $$->approach = 0;
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	      if ($23)
		{
		  $$->retract = 0;
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->iId->val);
		  delete $23->iId;
		  delete $23;
		}
	      if ($25)
		{
		  $$->itsMachiningStrategy = 0;
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->iId->val);
		  delete $25->iId;
		  delete $25;
		}
	    }
	;

planeRoughMilling :
	  PLANEROUGHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal RPAREN
	    { $$ = new planeRoughMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($21)
		{
		  $$->approach = 0;
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	      if ($23)
		{
		  $$->retract = 0;
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->iId->val);
		  delete $23->iId;
		  delete $23;
		}
	      if ($25)
		{
		  $$->itsMachiningStrategy = 0;
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->iId->val);
		  delete $25->iId;
		  delete $25;
		}
	    }
	;

plungeHelix :
	  PLUNGEHELIX LPAREN optDirection C REALSTRING C REALSTRING RPAREN
	    { $$ = new plungeHelix($3, $5, $7);
	      if ($3)
		{
		  $$->toolOrientation = 0;
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	    }
	;

plungeRamp :
	  PLUNGERAMP LPAREN optDirection C REALSTRING RPAREN
	    { $$ = new plungeRamp($3, $5);
	      if ($3)
		{
		  $$->toolOrientation = 0;
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	    }
	;

plungeToolaxis :
	  PLUNGETOOLAXIS LPAREN optDirection RPAREN
	    { $$ = new plungeToolaxis($3);
	      if ($3)
		{
		  $$->toolOrientation = 0;
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	    }
	;

plungeZigzag :
	  PLUNGEZIGZAG LPAREN optDirection C REALSTRING C REALSTRING RPAREN
	    { $$ = new plungeZigzag($3, $5, $7);
	      if ($3)
		{
		  $$->toolOrientation = 0;
		  direction_refs.push_back(&($$->toolOrientation));
		  direction_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	    }
	;

plusMinusValue :
	  PLUSMINUSVALUE LPAREN REALSTRING C REALSTRING C INTSTRING RPAREN
	    { $$ = new plusMinusValue($3, $5, $7); }
	;

polyline :
	  POLYLINE LPAREN CHARSTRING C parenCartesianPointListFull RPAREN
	    { $$ = new polyline($3, $5); }
	;

processModel :
	  PROCESSMODEL LPAREN CHARSTRING C CHARSTRING RPAREN
	    { $$ = new processModel($3, $5); }
	;

processModelList :
	  PROCESSMODELLIST LPAREN parenProcessModelLiszt RPAREN
	    { $$ = new processModelList($3); }
	;

processModelLiszt :
	  instanceId
	    { $$ = new std::list<processModel *>;
	      $$->push_back(0);
	      processModel_refs.push_back(&($$->back()));
	      processModel_nums.push_back($1->val);
	    }
	| processModelLiszt C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      processModel_refs.push_back(&($$->back()));
	      processModel_nums.push_back($3->val);
	    }
	;

programStop :
	  PROGRAMSTOP LPAREN CHARSTRING RPAREN
	    { $$ = new programStop($3); }
	;

project :
	  PROJECT LPAREN CHARSTRING C instanceId C parenWorkpieceList C optPersonAndAddress C optDateAndTime C optApproval RPAREN
	    { $$ = new project($3, 0, $7, $9, $11, $13);
	      workplan_refs.push_back(&($$->mainWorkplan));
	      workplan_nums.push_back($5->val);
	      delete $5;
	      if ($9)
		{
		  $$->itsOwner = 0;
		  personAndAddress_refs.push_back(&($$->itsOwner));
		  personAndAddress_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsRelease = 0;
		  dateAndTime_refs.push_back(&($$->itsRelease));
		  dateAndTime_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      if ($13)
		{
		  $$->itsStatus = 0;
		  approval_refs.push_back(&($$->itsStatus));
		  approval_nums.push_back($13->iId->val);
		  delete $13->iId;
		  delete $13;
		}
	    }
	;

propertyParameterList :
	  instanceId
	    { $$ = new std::list<propertyParameter *>;
	      $$->push_back(0);
	      propertyParameter_refs.push_back(&($$->back()));
	      propertyParameter_nums.push_back($1->val);
	    }
	| propertyParameterList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      propertyParameter_refs.push_back(&($$->back()));
	      propertyParameter_nums.push_back($3->val);
	    }
	;

quasiUniformCurve :
	  QUASIUNIFORMCURVE LPAREN CHARSTRING C INTSTRING C parenCartesianPointList C bSplineCurveForm C logical C logical RPAREN
	    { $$ = new quasiUniformCurve($3, $5, $7, $9, $11, $13); }
	;

quasiUniformSurface :
	  QUASIUNIFORMSURFACE LPAREN CHARSTRING C integer C integer C parenParenCartesianPointListFullListFull C bSplineSurfaceForm C logical C logical C logical RPAREN
	    { $$ = new quasiUniformSurface($3, $5, $7, $9, $11, $13, $15, $17); }
	;

radiusedPocketBottomCondition :
	  RADIUSEDPOCKETBOTTOMCONDITION LPAREN instanceId C instanceId RPAREN
	    { $$ = new radiusedPocketBottomCondition(0, 0);
	      cartesianPoint_refs.push_back(&($$->floorRadiusCenter));
	      cartesianPoint_nums.push_back($3->val);
	      delete $3;
	      tolerancedLengthMeasure_refs.push_back(&($$->floorRadius));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	    }
	;

radiusedSlotEndType :
	  RADIUSEDSLOTENDTYPE LPAREN RPAREN
	    { $$ = new radiusedSlotEndType(); }
	;

rapidMovement :
	  RAPIDMOVEMENT LPAREN CHARSTRING C instanceId C optToolpathList C optToolDirection RPAREN
	    { $$ = new rapidMovement($3, 0, $7, $9);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->val);
	      delete $5;
	      if ($7)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	    }
	;

rationalBSplineCurve :
	  RATIONALBSPLINECURVE LPAREN CHARSTRING C INTSTRING C parenCartesianPointList C bSplineCurveForm C logical C logical C parenRealListFull RPAREN
	    { $$ = new rationalBSplineCurve($3, $5, $7, $9, $11, $13, $15); }
	;

rationalBSplineSurface :
	  RATIONALBSPLINESURFACE LPAREN CHARSTRING C integer C integer C parenParenCartesianPointListFullListFull C bSplineSurfaceForm C logical C logical C logical parenParenRealListFullListFull RPAREN
	    { $$ = new rationalBSplineSurface($3, $5, $7, $9, $11, $13, $15, $17, $18); }
	;

real :
	  REALSTRING
	    { $$ = new real($1); }
	;

realList :
	  real
	    { $$ = new std::list<real *>;
	      $$->push_back($1); }
	| realList C real
	    { $$ = $1;
	      $$->push_back($3); }
	;

reaming :
	  REAMING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy C boolean C optReal C optCartesianPoint RPAREN
	    { $$ = new reaming($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31, $33, $35);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($29)
		{
		  $$->itsMachiningStrategy = 0;
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->iId->val);
		  delete $29->iId;
		  delete $29;
		}
	      if ($35)
		{
		  $$->waitingPosition = 0;
		  cartesianPoint_refs.push_back(&($$->waitingPosition));
		  cartesianPoint_nums.push_back($35->iId->val);
		  delete $35->iId;
		  delete $35;
		}
	    }
	;

rectangularClosedProfile :
	  RECTANGULARCLOSEDPROFILE LPAREN optAxis2placement3d C instanceId C instanceId RPAREN
	    { $$ = new rectangularClosedProfile($3, 0, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->profileWidth));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	      tolerancedLengthMeasure_refs.push_back(&($$->profileLength));
	      tolerancedLengthMeasure_nums.push_back($7->val);
	      delete $7;
	    }
	;

rectangularClosedShapeProfile :
	  RECTANGULARCLOSEDSHAPEPROFILE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new rectangularClosedShapeProfile($3, 0, $7, 0, 0, 0, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      linearPath_refs.push_back(&($$->profileSweptShape));
	      linearPath_nums.push_back($13->val);
	      delete $13;
	      profileSelect_refs.push_back(&($$->floorCondition));
	      profileSelect_nums.push_back($15->val);
	      delete $15;
	      direction_refs.push_back(&($$->removalDirection));
	      direction_nums.push_back($17->val);
	      delete $17;
	      rectangularClosedProfile_refs.push_back(&($$->closedBoundary));
	      rectangularClosedProfile_nums.push_back($19->val);
	      delete $19;
	    }
	;

rectangularOffset :
	  RECTANGULAROFFSET LPAREN instanceId C REALSTRING C INTSTRING C INTSTRING RPAREN
	    { $$ = new rectangularOffset(0, $5, $7, $9);
	      direction_refs.push_back(&($$->offsetDirection));
	      direction_nums.push_back($3->val);
	      delete $3;
	    }
	;

rectangularOffsetList :
	  instanceId
	    { $$ = new std::list<rectangularOffset *>;
	      $$->push_back(0);
	      rectangularOffset_refs.push_back(&($$->back()));
	      rectangularOffset_nums.push_back($1->val);
	    }
	| rectangularOffsetList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      rectangularOffset_refs.push_back(&($$->back()));
	      rectangularOffset_nums.push_back($3->val);
	    }
	;

rectangularOmit :
	  RECTANGULAROMIT LPAREN INTSTRING C INTSTRING RPAREN
	    { $$ = new rectangularOmit($3, $5); }
	;

rectangularOmitList :
	  instanceId
	    { $$ = new std::list<rectangularOmit *>;
	      $$->push_back(0);
	      rectangularOmit_refs.push_back(&($$->back()));
	      rectangularOmit_nums.push_back($1->val);
	    }
	| rectangularOmitList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      rectangularOmit_refs.push_back(&($$->back()));
	      rectangularOmit_nums.push_back($3->val);
	    }
	;

rectangularOpenShapeProfile :
	  RECTANGULAROPENSHAPEPROFILE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new rectangularOpenShapeProfile($3, 0, $7, 0, 0, 0, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      linearPath_refs.push_back(&($$->profileSweptShape));
	      linearPath_nums.push_back($13->val);
	      delete $13;
	      profileSelect_refs.push_back(&($$->floorCondition));
	      profileSelect_nums.push_back($15->val);
	      delete $15;
	      direction_refs.push_back(&($$->removalDirection));
	      direction_nums.push_back($17->val);
	      delete $17;
	      squareUProfile_refs.push_back(&($$->openBoundary));
	      squareUProfile_nums.push_back($19->val);
	      delete $19;
	    }
	;

rectangularPattern :
	  RECTANGULARPATTERN LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId instanceId C instanceId C optInteger C INTSTRING C optTolerancedLengthMeasure C optDirection C parenRectangularOffsetList C parenRectangularOmitList RPAREN
	    { $$ = new rectangularPattern($3, 0, $7, 0, 0, 0, 0, $16, $18, $20, $22, $24, $26);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      two5DmanufacturingFeature_refs.push_back(&($$->replicateBaseFeature));
	      two5DmanufacturingFeature_nums.push_back($11->val);
	      delete $11;
	      tolerancedLengthMeasure_refs.push_back(&($$->spacing));
	      tolerancedLengthMeasure_nums.push_back($12->val);
	      delete $12;
	      direction_refs.push_back(&($$->itsDirection));
	      direction_nums.push_back($14->val);
	      delete $14;
	      if ($20)
		{
		  $$->rowSpacing = 0;
		  tolerancedLengthMeasure_refs.push_back(&($$->rowSpacing));
		  tolerancedLengthMeasure_nums.push_back($20->iId->val);
		  delete $20->iId;
		  delete $20;
		}
	      if ($22)
		{
		  $$->rowLayoutDirection = 0;
		  direction_refs.push_back(&($$->rowLayoutDirection));
		  direction_nums.push_back($22->iId->val);
		  delete $22->iId;
		  delete $22;
		}
	    }
	;

regionProjection :
	  REGIONPROJECTION LPAREN CHARSTRING C instanceId C parenMachiningOperationList C optAxis2placement3d C instanceId C instanceId C instanceId RPAREN
	    { $$ = new regionProjection($3, 0, $7, $9, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      if ($9)
		{
		  $$->featurePlacement = 0;
		  axis2placement3d_refs.push_back(&($$->featurePlacement));
		  axis2placement3d_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      boundedCurve_refs.push_back(&($$->projCurve));
	      boundedCurve_nums.push_back($11->val);
	      delete $11;
	      direction_refs.push_back(&($$->projDir));
	      direction_nums.push_back($13->val);
	      delete $13;
	      tolerancedLengthMeasure_refs.push_back(&($$->depth));
	      tolerancedLengthMeasure_nums.push_back($15->val);
	      delete $15;
	    }
	;

regionSurfaceList :
	  REGIONSURFACELIST LPAREN CHARSTRING C instanceId C parenMachiningOperationList C optAxis2placement3d C parenBoundedSurfaceListFull RPAREN
	    { $$ = new regionSurfaceList($3, 0, $7, $9, $11);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      if ($9)
		{
		  $$->featurePlacement = 0;
		  axis2placement3d_refs.push_back(&($$->featurePlacement));
		  axis2placement3d_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	    }
	;

representation :
	  REPRESENTATION LPAREN CHARSTRING C parenRepresentationItemListFull C representationContext RPAREN
	    { $$ = new representation($3, $5, $7); }
	;

representationContext :
	  REPRESENTATIONCONTEXT LPAREN CHARSTRING C CHARSTRING RPAREN
	    { $$ = new representationContext($3, $5); }
	;

representationItemList :
	  instanceId
	    { $$ = new std::list<representationItem *>;
	      $$->push_back(0);
	      representationItem_refs.push_back(&($$->back()));
	      representationItem_nums.push_back($1->val);
	    }
	| representationItemList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      representationItem_refs.push_back(&($$->back()));
	      representationItem_nums.push_back($3->val);
	    }
	;

rightCircularCylinder :
	  RIGHTCIRCULARCYLINDER LPAREN CHARSTRING C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new rightCircularCylinder($3, 0, $7, $9);
	      axis1placement_refs.push_back(&($$->position));
	      axis1placement_nums.push_back($5->val);
	      delete $5;
	    }
	;

rotDirection :
	  rotDirectionCw
	    { $$ = $1; }
	| rotDirectionCcw
	    { $$ = $1; }
	;

rotDirectionCw :
	  ROTDIRECTIONCW
	    { $$ = new rotDirectionCw(); }
	;

rotDirectionCcw :
	  ROTDIRECTIONCCW
	    { $$ = new rotDirectionCcw(); }
	;

roundedEnd :
	  ROUNDEDEND LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new roundedEnd($3, 0, $7, 0, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      linearPath_refs.push_back(&($$->courseOfTravel));
	      linearPath_nums.push_back($13->val);
	      delete $13;
	      partialCircularProfile_refs.push_back(&($$->partialCircularBoundary));
	      partialCircularProfile_nums.push_back($15->val);
	      delete $15;
	    }
	;

roundedUProfile :
	  ROUNDEDUPROFILE LPAREN optAxis2placement3d C instanceId RPAREN
	    { $$ = new roundedUProfile($3, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->width));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	    }
	;

roundHole :
	  ROUNDHOLE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C optTaperSelect C instanceId RPAREN
	    { $$ = new roundHole($3, 0, $7, 0, 0, 0, $15, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      tolerancedLengthMeasure_refs.push_back(&($$->diameter));
	      tolerancedLengthMeasure_nums.push_back($13->val);
	      delete $13;
	      if ($15)
		{
		  $$->changeInDiameter = 0;
		  taperSelect_refs.push_back(&($$->changeInDiameter));
		  taperSelect_nums.push_back($15->iId->val);
		  delete $15->iId;
		  delete $15;
		}
	      holeBottomCondition_refs.push_back(&($$->bottomCondition));
	      holeBottomCondition_nums.push_back($17->val);
	      delete $17;
	    }
	;

selective :
	  SELECTIVE LPAREN CHARSTRING C parenExecutableListFull RPAREN
	    { $$ = new selective($3, $5); }
	;

setMark :
	  SETMARK LPAREN CHARSTRING RPAREN
	    { $$ = new setMark($3); }
	;

setup :
	  SETUP LPAREN CHARSTRING C optAxis2placement3d C instanceId C parenWorkpieceSetupList RPAREN
	    { $$ = new setup($3, $5, 0, $9);
	      if ($5)
		{
		  $$->itsOrigin = 0;
		  axis2placement3d_refs.push_back(&($$->itsOrigin));
		  axis2placement3d_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($7->val);
	      delete $7;
	    }
	;

setupInstruction :
	  SETUPINSTRUCTION LPAREN optString C optString RPAREN
	    { $$ = new setupInstruction($3, $5); }
	;

setupInstructionList :
	  instanceId
	    { $$ = new std::list<setupInstruction *>;
	      $$->push_back(0);
	      setupInstruction_refs.push_back(&($$->back()));
	      setupInstruction_nums.push_back($1->val);
	    }
	| setupInstructionList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      setupInstruction_refs.push_back(&($$->back()));
	      setupInstruction_nums.push_back($3->val);
	    }
	;

shapeRepresentation :
	  SHAPEREPRESENTATION LPAREN CHARSTRING C parenRepresentationItemListFull C representationContext RPAREN
	    { $$ = new shapeRepresentation($3, $5, $7); }
	;

sideMill :
	  SIDEMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new sideMill(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

sideFinishMilling :
	  SIDEFINISHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal C optReal RPAREN
	    { $$ = new sideFinishMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($21)
		{
		  $$->approach = 0;
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	      if ($23)
		{
		  $$->retract = 0;
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->iId->val);
		  delete $23->iId;
		  delete $23;
		}
	      if ($25)
		{
		  $$->itsMachiningStrategy = 0;
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->iId->val);
		  delete $25->iId;
		  delete $25;
		}
	    }
	;

sideRoughMilling :
	  SIDEROUGHMILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optApproachRetractStrategy C optApproachRetractStrategy C optTwo5DmillingStrategy C optReal C optReal C optReal RPAREN
	    { $$ = new sideRoughMilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $31);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($21)
		{
		  $$->approach = 0;
		  approachRetractStrategy_refs.push_back(&($$->approach));
		  approachRetractStrategy_nums.push_back($21->iId->val);
		  delete $21->iId;
		  delete $21;
		}
	      if ($23)
		{
		  $$->retract = 0;
		  approachRetractStrategy_refs.push_back(&($$->retract));
		  approachRetractStrategy_nums.push_back($23->iId->val);
		  delete $23->iId;
		  delete $23;
		}
	      if ($25)
		{
		  $$->itsMachiningStrategy = 0;
		  two5DmillingStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  two5DmillingStrategy_nums.push_back($25->iId->val);
		  delete $25->iId;
		  delete $25;
		}
	    }
	;

slot :
	  SLOT LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId C parenSlotEndTypeList RPAREN
	    { $$ = new slot($3, 0, $7, 0, 0, 0, 0, $17);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      travelPath_refs.push_back(&($$->courseOfTravel));
	      travelPath_nums.push_back($13->val);
	      delete $13;
	      openProfile_refs.push_back(&($$->sweptShape));
	      openProfile_nums.push_back($15->val);
	      delete $15;
	    }
	;

slotEndTypeList :
	  instanceId
	    { $$ = new std::list<slotEndType *>;
	      $$->push_back(0);
	      slotEndType_refs.push_back(&($$->back()));
	      slotEndType_nums.push_back($1->val);
	    }
	| slotEndTypeList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      slotEndType_refs.push_back(&($$->back()));
	      slotEndType_nums.push_back($3->val);
	    }
	;

spadeDrill :
	  SPADEDRILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new spadeDrill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

specification :
	  SPECIFICATION LPAREN parenSpecificationUsageConstraintList C CHARSTRING C optString C optString RPAREN
	    { $$ = new specification($3, $5, $7, $9); }
	;

specificationUsageConstraint :
	  SPECIFICATIONUSAGECONSTRAINT LPAREN C CHARSTRING C CHARSTRING RPAREN
	    { $$ = new specificationUsageConstraint($4, $6); }
	;

specificationUsageConstraintList :
	  instanceId
	    { $$ = new std::list<specificationUsageConstraint *>;
	      $$->push_back(0);
	      specificationUsageConstraint_refs.push_back(&($$->back()));
	      specificationUsageConstraint_nums.push_back($1->val);
	    }
	| specificationUsageConstraintList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      specificationUsageConstraint_refs.push_back(&($$->back()));
	      specificationUsageConstraint_nums.push_back($3->val);
	    }
	;

speedName :
	  SPEEDNAMERAPID
	    { $$ = new speedName(); }
	;

sphericalCap :
	  SPHERICALCAP LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new sphericalCap($3, 0, $7, 0, 0, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      numericParameter_refs.push_back(&($$->internalAngle));
	      numericParameter_nums.push_back($13->val);
	      delete $13;
	      numericParameter_refs.push_back(&($$->radius));
	      numericParameter_nums.push_back($15->val);
	      delete $15;
	    }
	;

sphericalHoleBottom :
	  SPHERICALHOLEBOTTOM LPAREN instanceId RPAREN
	    { $$ = new sphericalHoleBottom(0);
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($3->val);
	      delete $3;
	    }
	;

sphericalSurface :
	  SPHERICALSURFACE LPAREN CHARSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new sphericalSurface($3, 0, $7);
	      axis2placement3d_refs.push_back(&($$->position));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	    }
	;

squareUProfile :
	  SQUAREUPROFILE LPAREN optAxis2placement3d C instanceId C instanceId C REALSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new squareUProfile($3, 0, 0, $9, 0, $13);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->width));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	      tolerancedLengthMeasure_refs.push_back(&($$->firstRadius));
	      tolerancedLengthMeasure_nums.push_back($7->val);
	      delete $7;
	      tolerancedLengthMeasure_refs.push_back(&($$->secondRadius));
	      tolerancedLengthMeasure_nums.push_back($11->val);
	      delete $11;
	    }
	;

step :
	  STEP LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId C instanceId C optVeeProfile C parenBossList RPAREN
	    { $$ = new step($3, 0, $7, 0, 0, 0, $15, $17);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	      linearPath_refs.push_back(&($$->openBoundary));
	      linearPath_nums.push_back($13->val);
	      delete $13;
	      if ($15)
		{
		  $$->wallBoundary = 0;
		  veeProfile_refs.push_back(&($$->wallBoundary));
		  veeProfile_nums.push_back($15->iId->val);
		  delete $15->iId;
		  delete $15;
		}
	    }
	;

stringList :
	  CHARSTRING
	    { $$ = new std::list<char *>;
	      $$->push_back($1); }
	| stringList C CHARSTRING
	    { $$ = $1;
	      $$->push_back($3); }
	;

strokeConnectionStrategy :
	  strokeConnectionStrategyStraightline
	    { $$ = $1; }
	| strokeConnectionStrategyLiftShiftPlunge
	    { $$ = $1; }
	| strokeConnectionStrategyDegouge
	    { $$ = $1; }
	| strokeConnectionStrategyLoopBack
	    { $$ = $1; }
	;

strokeConnectionStrategyDegouge :
	  STROKECONNECTIONSTRATEGYDEGOUGE
	    { $$ = new strokeConnectionStrategyDegouge(); }
	;

strokeConnectionStrategyLiftShiftPlunge :
	  STROKECONNECTIONSTRATEGYLIFTSHIFTPLUNGE
	    { $$ = new strokeConnectionStrategyLiftShiftPlunge(); }
	;

strokeConnectionStrategyLoopBack :
	  STROKECONNECTIONSTRATEGYLOOPBACK
	    { $$ = new strokeConnectionStrategyLoopBack(); }
	;

strokeConnectionStrategyStraightline :
	  STROKECONNECTIONSTRATEGYSTRAIGHTLINE
	    { $$ = new strokeConnectionStrategyStraightline(); }
	;

surfaceOfLinearExtrusion :
	  SURFACEOFLINEAREXTRUSION LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new surfaceOfLinearExtrusion($3, 0, 0);
	      curve_refs.push_back(&($$->sweptCurve));
	      curve_nums.push_back($5->val);
	      delete $5;
	      vector_refs.push_back(&($$->extrusionAxis));
	      vector_nums.push_back($7->val);
	      delete $7;
	    }
	;

surfaceOfRevolution :
	  SURFACEOFREVOLUTION LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new surfaceOfRevolution($3, 0, 0);
	      curve_refs.push_back(&($$->sweptCurve));
	      curve_nums.push_back($5->val);
	      delete $5;
	      axis1placement_refs.push_back(&($$->axisPosition));
	      axis1placement_nums.push_back($7->val);
	      delete $7;
	    }
	;

surfaceTextureParameter :
	  SURFACETEXTUREPARAMETER LPAREN REALSTRING C CHARSTRING C CHARSTRING C optString C parenMachinedSurfaceListFull RPAREN
	    { $$ = new surfaceTextureParameter($3, $5, $7, $9, $11); }
	;

tap :
	  TAP LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new tap(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

taperedTap :
	  TAPEREDTAP LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new taperedTap(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

taperedDrill :
	  TAPEREDDRILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new taperedDrill(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

taperedEndmill :
	  TAPEREDENDMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new taperedEndmill(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

taperedReamer :
	  TAPEREDREAMER LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new taperedReamer(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

tapping :
	  TAPPING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy boolean RPAREN
	    { $$ = new tapping($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $30);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($29)
		{
		  $$->itsMachiningStrategy = 0;
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->iId->val);
		  delete $29->iId;
		  delete $29;
		}
	    }
	;

teeProfile :
	  TEEPROFILE LPAREN optAxis2placement3d REALSTRING REALSTRING instanceId instanceId instanceId instanceId instanceId instanceId RPAREN
	    { $$ = new teeProfile($3, $4, $5, 0, 0, 0, 0, 0, 0);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->crossBarWidth));
	      tolerancedLengthMeasure_nums.push_back($6->val);
	      delete $6;
	      tolerancedLengthMeasure_refs.push_back(&($$->crossBarDepth));
	      tolerancedLengthMeasure_nums.push_back($7->val);
	      delete $7;
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($8->val);
	      delete $8;
	      tolerancedLengthMeasure_refs.push_back(&($$->width));
	      tolerancedLengthMeasure_nums.push_back($9->val);
	      delete $9;
	      tolerancedLengthMeasure_refs.push_back(&($$->firstOffset));
	      tolerancedLengthMeasure_nums.push_back($10->val);
	      delete $10;
	      tolerancedLengthMeasure_refs.push_back(&($$->secondOffset));
	      tolerancedLengthMeasure_nums.push_back($11->val);
	      delete $11;
	    }
	;

threadDrilling :
	  THREADDRILLING LPAREN optToolpathList C optToolDirection C CHARSTRING C optReal C optCartesianPoint C instanceId C instanceId C instanceId C optReal C optReal C optReal C optReal C optReal C optDrillingTypeStrategy boolean RPAREN
	    { $$ = new threadDrilling($3, $5, $7, $9, $11, 0, 0, 0, $19, $21, $23, $25, $27, $29, $30);
	      if ($3)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      if ($5)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($11)
		{
		  $$->startPoint = 0;
		  cartesianPoint_refs.push_back(&($$->startPoint));
		  cartesianPoint_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($13->val);
	      delete $13;
	      technology_refs.push_back(&($$->itsTechnology));
	      technology_nums.push_back($15->val);
	      delete $15;
	      machineFunctions_refs.push_back(&($$->itsMachineFunctions));
	      machineFunctions_nums.push_back($17->val);
	      delete $17;
	      if ($29)
		{
		  $$->itsMachiningStrategy = 0;
		  drillingTypeStrategy_refs.push_back(&($$->itsMachiningStrategy));
		  drillingTypeStrategy_nums.push_back($29->iId->val);
		  delete $29->iId;
		  delete $29;
		}
	    }
	;

threadMill :
	  THREADMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new threadMill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

threeAxes :
	  THREEAXES LPAREN RPAREN
	    { $$ = new threeAxes(); }
	;

threeAxesTiltedTool :
	  THREEAXESTILTEDTOOL LPAREN instanceId RPAREN
	    { $$ = new threeAxesTiltedTool(0);
	      direction_refs.push_back(&($$->itsToolDirection));
	      direction_nums.push_back($3->val);
	      delete $3;
	    }
	;

throughBottomCondition :
	  THROUGHBOTTOMCONDITION LPAREN RPAREN
	    { $$ = new throughBottomCondition(); }
	;

throughPocketBottomCondition :
	  THROUGHPOCKETBOTTOMCONDITION LPAREN RPAREN
	    { $$ = new throughPocketBottomCondition(); }
	;

throughProfileFloor :
	  THROUGHPROFILEFLOOR LPAREN RPAREN
	    { $$ = new throughProfileFloor(); }
	;

tolerancedLengthMeasure :
	  TOLERANCEDLENGTHMEASURE LPAREN REALSTRING C instanceId RPAREN
	    { $$ = new tolerancedLengthMeasure($3, 0);
	      plusMinusValue_refs.push_back(&($$->implicitTolerance));
	      plusMinusValue_nums.push_back($5->val);
	      delete $5;
	    }
	;

tolerances :
	  TOLERANCES LPAREN REALSTRING C REALSTRING RPAREN
	    { $$ = new tolerances($3, $5); }
	;

toolLengthProbing :
	  TOOLLENGTHPROBING LPAREN CHARSTRING C instanceId C optToolpathList C optToolDirection C instanceId C instanceId C REALSTRING C instanceId RPAREN
	    { $$ = new toolLengthProbing($3, 0, $7, $9, 0, 0, $15, 0);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->val);
	      delete $5;
	      if ($7)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      ncVariable_refs.push_back(&($$->measuredOffset));
	      ncVariable_nums.push_back($11->val);
	      delete $11;
	      cartesianPoint_refs.push_back(&($$->offset));
	      cartesianPoint_nums.push_back($13->val);
	      delete $13;
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($17->val);
	      delete $17;
	    }
	;

toolpathFeature :
	  TOOLPATHFEATURE LPAREN CHARSTRING C instanceId C parenMachiningOperationList C instanceId C instanceId RPAREN
	    { $$ = new toolpathFeature($3, 0, $7, 0, 0);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      axis2placement3d_refs.push_back(&($$->featurePlacement));
	      axis2placement3d_nums.push_back($9->val);
	      delete $9;
	      elementarySurface_refs.push_back(&($$->depth));
	      elementarySurface_nums.push_back($11->val);
	      delete $11;
	    }
	;

toolpathList :
	  TOOLPATHLIST LPAREN parenToolpathLisztFull RPAREN
	    { $$ = new toolpathList($3); }
	;

toolpathLiszt :
	  instanceId
	    { $$ = new std::list<toolpath *>;
	      $$->push_back(0);
	      toolpath_refs.push_back(&($$->back()));
	      toolpath_nums.push_back($1->val);
	    }
	| toolpathLiszt C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      toolpath_refs.push_back(&($$->back()));
	      toolpath_nums.push_back($3->val);
	    }
	;

toolpathSpeed :
	  TOOLPATHSPEED LPAREN instanceId RPAREN
	    { $$ = new toolpathSpeed(0);
	      bSplineCurve_refs.push_back(&($$->speed));
	      bSplineCurve_nums.push_back($3->val);
	      delete $3;
	    }
	;

toolpathType :
	  toolpathTypeApproach
	    { $$ = $1; }
	| toolpathTypeLift
	    { $$ = $1; }
	| toolpathTypeConnect
	    { $$ = $1; }
	| toolpathTypeNonContact
	    { $$ = $1; }
	| toolpathTypeContact
	    { $$ = $1; }
	| toolpathTypeTrajectoryPath
	    { $$ = $1; }
	;

toolpathTypeApproach :
	  TOOLPATHTYPEAPPROACH
	    { $$ = new toolpathTypeApproach(); }
	;

toolpathTypeConnect :
	  TOOLPATHTYPECONNECT
	    { $$ = new toolpathTypeConnect(); }
	;

toolpathTypeContact :
	  TOOLPATHTYPECONTACT
	    { $$ = new toolpathTypeContact(); }
	;

toolpathTypeLift :
	  TOOLPATHTYPELIFT
	    { $$ = new toolpathTypeLift(); }
	;

toolpathTypeNonContact :
	  TOOLPATHTYPENONCONTACT
	    { $$ = new toolpathTypeNonContact(); }
	;

toolpathTypeTrajectoryPath :
	  TOOLPATHTYPETRAJECTORYPATH
	    { $$ = new toolpathTypeTrajectoryPath(); }
	;

toolRadiusProbing :
	  TOOLRADIUSPROBING LPAREN CHARSTRING C instanceId C optToolpathList C optToolDirection C instanceId C instanceId C REALSTRING C instanceId RPAREN
	    { $$ = new toolRadiusProbing($3, 0, $7, $9, 0, 0, $15, 0);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->val);
	      delete $5;
	      if ($7)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      ncVariable_refs.push_back(&($$->measuredOffset));
	      ncVariable_nums.push_back($11->val);
	      delete $11;
	      cartesianPoint_refs.push_back(&($$->offset));
	      cartesianPoint_nums.push_back($13->val);
	      delete $13;
	      machiningTool_refs.push_back(&($$->itsTool));
	      machiningTool_nums.push_back($17->val);
	      delete $17;
	    }
	;

toolReferencePoint :
	  toolReferencePointTcp
	    { $$ = $1; }
	| toolReferencePointCcp
	    { $$ = $1; }
	;

toolReferencePointCcp :
	  TOOLREFERENCEPOINTCCP
	    { $$ = new toolReferencePointCcp(); }
	;

toolReferencePointTcp :
	  TOOLREFERENCEPOINTTCP
	    { $$ = new toolReferencePointTcp(); }
	;

topologicalRegion :
	  TOPOLOGICALREGION LPAREN CHARSTRING C instanceId C parenMachiningOperationList C optAxis2placement3d C CHARSTRING C parenFaceListFull RPAREN
	    { $$ = new topologicalRegion($3, 0, $7, $9, $11, $13);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($5->val);
	      delete $5;
	      if ($9)
		{
		  $$->featurePlacement = 0;
		  axis2placement3d_refs.push_back(&($$->featurePlacement));
		  axis2placement3d_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	    }
	;

touchProbe :
	  TOUCHPROBE LPAREN CHARSTRING RPAREN
	    { $$ = new touchProbe($3); }
	;

transitionCode :
	  transitionCodeDiscontinuous
	    { $$ = $1; }
	| transitionCodeContinuous
	    { $$ = $1; }
	| transitionCodeContSameGradient
	    { $$ = $1; }
	| transitionCodeContSameGradientSameCurvature
	    { $$ = $1; }
	;

transitionCodeContinuous :
	  TRANSITIONCODECONTINUOUS
	    { $$ = new transitionCodeContinuous(); }
	;

transitionCodeContSameGradient :
	  TRANSITIONCODECONTSAMEGRADIENT
	    { $$ = new transitionCodeContSameGradient(); }
	;

transitionCodeContSameGradientSameCurvature :
	  TRANSITIONCODECONTSAMEGRADIENTSAMECURVATURE
	    { $$ = new transitionCodeContSameGradientSameCurvature(); }
	;

transitionCodeDiscontinuous :
	  TRANSITIONCODEDISCONTINUOUS
	    { $$ = new transitionCodeDiscontinuous(); }
	;

trimmedCurve :
	  TRIMMEDCURVE LPAREN CHARSTRING C instanceId C parenTrimmingSelectListFull C parenTrimmingSelectListFull C boolean C trimmingPreference RPAREN
	    { $$ = new trimmedCurve($3, 0, $7, $9, $11, $13);
	      curve_refs.push_back(&($$->basisCurve));
	      curve_nums.push_back($5->val);
	      delete $5;
	    }
	;

trimmingPreference :
	  trimmingPreferenceCartesian
	    { $$ = $1; }
	| trimmingPreferenceParameter
	    { $$ = $1; }
	| trimmingPreferenceUnspecified
	    { $$ = $1; }
	;

trimmingPreferenceCartesian :
	  TRIMMINGPREFERENCECARTESIAN
	    { $$ = new trimmingPreferenceCartesian(); }
	;

trimmingPreferenceParameter :
	  TRIMMINGPREFERENCEPARAMETER
	    { $$ = new trimmingPreferenceParameter(); }
	;

trimmingPreferenceUnspecified :
	  TRIMMINGPREFERENCEUNSPECIFIED
	    { $$ = new trimmingPreferenceUnspecified(); }
	;

trimmingSelectList :
	  instanceId
	    { $$ = new std::list<trimmingSelect *>;
	      $$->push_back(0);
	      trimmingSelect_refs.push_back(&($$->back()));
	      trimmingSelect_nums.push_back($1->val);
	    }
	| real
	    { $$ = new std::list<trimmingSelect *>;
	      $$->push_back($1);
	    }
	| trimmingSelectList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      trimmingSelect_refs.push_back(&($$->back()));
	      trimmingSelect_nums.push_back($3->val);
	    }
	| trimmingSelectList C real
	    { $$ = $1;
	      $$->push_back($3);
	    }
	;

tSlotMill :
	  TSLOTMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new tSlotMill(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

twistDrill :
	  TWISTDRILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal RPAREN
	    { $$ = new twistDrill(0, $5, $7, $9, $11);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

twoAxes :
	  TWOAXES LPAREN RPAREN
	    { $$ = new twoAxes(); }
	;

unidirectionalMilling :
	  UNIDIRECTIONALMILLING LPAREN optReal C optBoolean C optDirection C optCutmodeType RPAREN
	    { $$ = new unidirectionalMilling($3, $5, $7, $9);
	      if ($7)
		{
		  $$->feedDirection = 0;
		  direction_refs.push_back(&($$->feedDirection));
		  direction_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	    }
	;

uniformCurve :
	  UNIFORMCURVE LPAREN CHARSTRING C INTSTRING C parenCartesianPointList C bSplineCurveForm C logical C logical RPAREN
	    { $$ = new uniformCurve($3, $5, $7, $9, $11, $13); }
	;

uniformSurface :
	  UNIFORMSURFACE LPAREN CHARSTRING C integer C integer C parenParenCartesianPointListFullListFull C bSplineSurfaceForm C logical C logical C logical RPAREN
	    { $$ = new uniformSurface($3, $5, $7, $9, $11, $13, $15, $17); }
	;

unloadTool :
	  UNLOADTOOL LPAREN CHARSTRING C optMachiningTool RPAREN
	    { $$ = new unloadTool($3, $5);
	      if ($5)
		{
		  $$->itsTool = 0;
		  machiningTool_refs.push_back(&($$->itsTool));
		  machiningTool_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	    }
	;

userDefinedTool :
	  USERDEFINEDTOOL LPAREN instanceId C optInteger C optHand C optBoolean C optReal C CHARSTRING RPAREN
	    { $$ = new userDefinedTool(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

uvStrategy :
	  UVSTRATEGY LPAREN pathmodeType C cutmodeType C instanceId C optReal C instanceId C instanceId RPAREN
	    { $$ = new uvStrategy($3, $5, 0, $9, 0, 0);
	      tolerances_refs.push_back(&($$->itsMillingTolerances));
	      tolerances_nums.push_back($7->val);
	      delete $7;
	      direction_refs.push_back(&($$->forwardDirection));
	      direction_nums.push_back($11->val);
	      delete $11;
	      direction_refs.push_back(&($$->sidewardDirection));
	      direction_nums.push_back($13->val);
	      delete $13;
	    }
	;

vector :
	  VECTOR LPAREN CHARSTRING C instanceId C REALSTRING RPAREN
	    { $$ = new vector($3, 0, $7);
	      direction_refs.push_back(&($$->orientation));
	      direction_nums.push_back($5->val);
	      delete $5;
	    }
	;

veeProfile :
	  VEEPROFILE LPAREN optAxis2placement3d C instanceId C REALSTRING C REALSTRING RPAREN
	    { $$ = new veeProfile($3, 0, $7, $9);
	      if ($3)
		{
		  $$->placement = 0;
		  axis2placement3d_refs.push_back(&($$->placement));
		  axis2placement3d_nums.push_back($3->iId->val);
		  delete $3->iId;
		  delete $3;
		}
	      tolerancedLengthMeasure_refs.push_back(&($$->profileRadius));
	      tolerancedLengthMeasure_nums.push_back($5->val);
	      delete $5;
	    }
	;

vertexLoop :
	  VERTEXLOOP LPAREN CHARSTRING C instanceId RPAREN
	    { $$ = new vertexLoop($3, 0);
	      vertex_refs.push_back(&($$->loopVertex));
	      vertex_nums.push_back($5->val);
	      delete $5;
	    }
	;

vertexPoint :
	  VERTEXPOINT LPAREN CHARSTRING C instanceId RPAREN
	    { $$ = new vertexPoint($3, 0);
	      point_refs.push_back(&($$->vertexGeometry));
	      point_nums.push_back($5->val);
	      delete $5;
	    }
	;

waitForMark :
	  WAITFORMARK LPAREN CHARSTRING C instanceId RPAREN
	    { $$ = new waitForMark($3, 0);
	      channel_refs.push_back(&($$->itsChannel));
	      channel_nums.push_back($5->val);
	      delete $5;
	    }
	;

weekOfYearAndDayDate :
	  WEEKOFYEARANDDAYDATE LPAREN INTSTRING C INTSTRING C optInteger RPAREN
	    { $$ = new weekOfYearAndDayDate($3, $5, $7); }
	;

whileStatement :
	  WHILESTATEMENT LPAREN CHARSTRING C instanceId C instanceId RPAREN
	    { $$ = new whileStatement($3, 0, 0);
	      booleanExpression_refs.push_back(&($$->condition));
	      booleanExpression_nums.push_back($5->val);
	      delete $5;
	      executable_refs.push_back(&($$->body));
	      executable_nums.push_back($7->val);
	      delete $7;
	    }
	;

woodruffKeyseatMill :
	  WOODRUFFKEYSEATMILL LPAREN instanceId C optInteger C optHand C optBoolean C optReal C optReal RPAREN
	    { $$ = new woodruffKeyseatMill(0, $5, $7, $9, $11, $13);
	      millingToolDimension_refs.push_back(&($$->dimension));
	      millingToolDimension_nums.push_back($3->val);
	      delete $3;
	    }
	;

woodruffSlotEndType :
	  WOODRUFFSLOTENDTYPE LPAREN instanceId RPAREN
	    { $$ = new woodruffSlotEndType(0);
	      tolerancedLengthMeasure_refs.push_back(&($$->radius));
	      tolerancedLengthMeasure_nums.push_back($3->val);
	      delete $3;
	    }
	;

workpiece :
	  WORKPIECE LPAREN CHARSTRING C optMaterial C optReal C optWorkpiece C optAdvancedBrepShapeRepresentation C optBoundingGeometrySelect C parenCartesianPointList RPAREN
	    { $$ = new workpiece($3, $5, $7, $9, $11, $13, $15);
	      if ($5)
		{
		  $$->itsMaterial = 0;
		  material_refs.push_back(&($$->itsMaterial));
		  material_nums.push_back($5->iId->val);
		  delete $5->iId;
		  delete $5;
		}
	      if ($9)
		{
		  $$->itsRawpiece = 0;
		  workpiece_refs.push_back(&($$->itsRawpiece));
		  workpiece_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsGeometry = 0;
		  advancedBrepShapeRepresentation_refs.push_back(&($$->itsGeometry));
		  advancedBrepShapeRepresentation_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	      if ($13)
		{
		  $$->itsBoundingGeometry = 0;
		  boundingGeometrySelect_refs.push_back(&($$->itsBoundingGeometry));
		  boundingGeometrySelect_nums.push_back($13->iId->val);
		  delete $13->iId;
		  delete $13;
		}
	    }
	;

workpieceCompleteProbing :
	  WORKPIECECOMPLETEPROBING LPAREN CHARSTRING C instanceId C optToolpathList C optToolDirection C instanceId C instanceId C instanceId C instanceId C offsetVector RPAREN
	    { $$ = new workpieceCompleteProbing($3, 0, $7, $9, 0, 0, 0, 0, $19);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->val);
	      delete $5;
	      if ($7)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      ncVariable_refs.push_back(&($$->measuredOffset));
	      ncVariable_nums.push_back($11->val);
	      delete $11;
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($13->val);
	      delete $13;
	      tolerancedLengthMeasure_refs.push_back(&($$->probingDistance));
	      tolerancedLengthMeasure_nums.push_back($15->val);
	      delete $15;
	      touchProbe_refs.push_back(&($$->itsProbe));
	      touchProbe_nums.push_back($17->val);
	      delete $17;
	    }
	;

workpieceList :
	  instanceId
	    { $$ = new std::list<workpiece *>;
	      $$->push_back(0);
	      workpiece_refs.push_back(&($$->back()));
	      workpiece_nums.push_back($1->val);
	    }
	| workpieceList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      workpiece_refs.push_back(&($$->back()));
	      workpiece_nums.push_back($3->val);
	    }
	;

workpieceProbing :
	  WORKPIECEPROBING LPAREN CHARSTRING C instanceId C optToolpathList C optToolDirection C instanceId C instanceId C instanceId C instanceId C instanceId C instanceId RPAREN
	    { $$ = new workpieceProbing($3, 0, $7, $9, 0, 0, 0, 0, 0, 0);
	      elementarySurface_refs.push_back(&($$->itsSecplane));
	      elementarySurface_nums.push_back($5->val);
	      delete $5;
	      if ($7)
		{
		  $$->itsToolpath = 0;
		  toolpathList_refs.push_back(&($$->itsToolpath));
		  toolpathList_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsToolDirection = 0;
		  toolDirection_refs.push_back(&($$->itsToolDirection));
		  toolDirection_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      ncVariable_refs.push_back(&($$->measuredOffset));
	      ncVariable_nums.push_back($11->val);
	      delete $11;
	      axis2placement3d_refs.push_back(&($$->startPosition));
	      axis2placement3d_nums.push_back($13->val);
	      delete $13;
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($15->val);
	      delete $15;
	      direction_refs.push_back(&($$->itsDirection));
	      direction_nums.push_back($17->val);
	      delete $17;
	      tolerancedLengthMeasure_refs.push_back(&($$->expectedValue));
	      tolerancedLengthMeasure_nums.push_back($19->val);
	      delete $19;
	      touchProbe_refs.push_back(&($$->itsProbe));
	      touchProbe_nums.push_back($21->val);
	      delete $21;
	    }
	;

workpieceSetup :
	  WORKPIECESETUP LPAREN instanceId C instanceId C optOffsetVector C optRestrictedAreaSelect C parenSetupInstructionList RPAREN
	    { $$ = new workpieceSetup(0, 0, $7, $9, $11);
	      workpiece_refs.push_back(&($$->itsWorkpiece));
	      workpiece_nums.push_back($3->val);
	      delete $3;
	      axis2placement3d_refs.push_back(&($$->itsOrigin));
	      axis2placement3d_nums.push_back($5->val);
	      delete $5;
	      if ($9)
		{
		  $$->itsRestrictedArea = 0;
		  restrictedAreaSelect_refs.push_back(&($$->itsRestrictedArea));
		  restrictedAreaSelect_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	    }
	;

workpieceSetupList :
	  instanceId
	    { $$ = new std::list<workpieceSetup *>;
	      $$->push_back(0);
	      workpieceSetup_refs.push_back(&($$->back()));
	      workpieceSetup_nums.push_back($1->val);
	    }
	| workpieceSetupList C instanceId
	    { $$ = $1;
	      $$->push_back(0);
	      workpieceSetup_refs.push_back(&($$->back()));
	      workpieceSetup_nums.push_back($3->val);
	    }
	;

workplan :
	  WORKPLAN LPAREN CHARSTRING C parenExecutableList C optChannel C optSetup C optInProcessGeometry RPAREN
	    { $$ = new workplan($3, $5, $7, $9, $11);
	      if ($7)
		{
		  $$->itsChannel = 0;
		  channel_refs.push_back(&($$->itsChannel));
		  channel_nums.push_back($7->iId->val);
		  delete $7->iId;
		  delete $7;
		}
	      if ($9)
		{
		  $$->itsSetup = 0;
		  setup_refs.push_back(&($$->itsSetup));
		  setup_nums.push_back($9->iId->val);
		  delete $9->iId;
		  delete $9;
		}
	      if ($11)
		{
		  $$->itsEffect = 0;
		  inProcessGeometry_refs.push_back(&($$->itsEffect));
		  inProcessGeometry_nums.push_back($11->iId->val);
		  delete $11->iId;
		  delete $11;
		}
	    }
	;

xorExpression :
	  XOREXPRESSION LPAREN instanceId C instanceId RPAREN
	    { $$ = new xorExpression(0, 0);
	      booleanExpression_refs.push_back(&($$->operand1));
	      booleanExpression_nums.push_back($3->val);
	      delete $3;
	      booleanExpression_refs.push_back(&($$->operand2));
	      booleanExpression_nums.push_back($5->val);
	      delete $5;
	    }
	;

%%
