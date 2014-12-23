
/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

#include "iso14649classesDirect.hh"
#include <stdio.h>   // for printf, etc.

void printDouble(
 double num)
{
  int n;
  int k;
  char buffer[50];

  k = sprintf(buffer, "%f", num);
  for (n = (k-1); ((buffer[n] == '0') && (buffer[n-1] != '.')); n--)
    buffer[n] = 0;
  printf("%s", buffer);
}

void printString(
 char * aString)
{
  int n;
  putchar('\'');
  for (n=0; aString[n]; n++)
    {
      putchar(aString[n]);
      if (aString[n] == '\'')
	putchar('\''); // if apostrophe, print another apostrophe
    }
  putchar('\'');
}


/********************************************************************/

/* iso14649CppBase */

iso14649CppBase::iso14649CppBase(){}

iso14649CppBase::~iso14649CppBase(){}

/********************************************************************/

/* inputFile */

inputFile::inputFile(){}

inputFile::inputFile(
 fileStart * inputStartIn,
 headerSection * inputHeaderIn,
 dataSection * inputDataIn,
 fileEnd * inputEndIn)
{
  inputStart = inputStartIn;
  inputHeader = inputHeaderIn;
  inputData = inputDataIn;
  inputEnd = inputEndIn;
}

inputFile::~inputFile()
{
  delete inputStart;
  delete inputHeader;
  delete inputData;
  delete inputEnd;
}

int inputFile::isA(int aType)
    { return (aType == inputFile_E); }

void inputFile::printSelf()
{
  inputStart->printSelf();
  inputHeader->printSelf();
  inputData->printSelf();
  inputEnd->printSelf();
}

/********************************************************************/

/* instance */

instance::instance(){}

instance::instance(instanceId * iIdIn)
{
  iId = iIdIn;
}

instance::~instance(){}

/********************************************************************/

/* address */

address::address(){}

address::address(
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
 aString * telexNumberIn)
{
  internalLocation = internalLocationIn;
  streetNumber = streetNumberIn;
  street = streetIn;
  postalBox = postalBoxIn;
  town = townIn;
  region = regionIn;
  postalCode = postalCodeIn;
  country = countryIn;
  facsimileNumber = facsimileNumberIn;
  telephoneNumber = telephoneNumberIn;
  electronicMailAddress = electronicMailAddressIn;
  telexNumber = telexNumberIn;
}

address::~address()
{
  delete internalLocation;
  delete streetNumber;
  delete street;
  delete postalBox;
  delete town;
  delete region;
  delete postalCode;
  delete country;
  delete facsimileNumber;
  delete telephoneNumber;
  delete electronicMailAddress;
  delete telexNumber;
}

int address::isA(int aType)
    { return (aType == address_E); }

void address::printSelf()
{
  printf("ADDRESS");
  printf("(");
  if (internalLocation)
    internalLocation->printSelf();
  else
    printf("$");
  printf(",");
  if (streetNumber)
    streetNumber->printSelf();
  else
    printf("$");
  printf(",");
  if (street)
    street->printSelf();
  else
    printf("$");
  printf(",");
  if (postalBox)
    postalBox->printSelf();
  else
    printf("$");
  printf(",");
  if (town)
    town->printSelf();
  else
    printf("$");
  printf(",");
  if (region)
    region->printSelf();
  else
    printf("$");
  printf(",");
  if (postalCode)
    postalCode->printSelf();
  else
    printf("$");
  printf(",");
  if (country)
    country->printSelf();
  else
    printf("$");
  printf(",");
  if (facsimileNumber)
    facsimileNumber->printSelf();
  else
    printf("$");
  printf(",");
  if (telephoneNumber)
    telephoneNumber->printSelf();
  else
    printf("$");
  printf(",");
  if (electronicMailAddress)
    electronicMailAddress->printSelf();
  else
    printf("$");
  printf(",");
  if (telexNumber)
    telexNumber->printSelf();
  else
    printf("$");
  printf(",");
  printf(")");
}

/********************************************************************/

/* aheadOrBehind */

aheadOrBehind::aheadOrBehind(){}


aheadOrBehind::~aheadOrBehind(){}

int aheadOrBehind::isA(int aType)
    { return (aType == aheadOrBehind_E); }

/********************************************************************/

/* aheadOrBehindAhead */

aheadOrBehindAhead::aheadOrBehindAhead(){}


aheadOrBehindAhead::~aheadOrBehindAhead()
{
}

int aheadOrBehindAhead::isA(int aType)
    { return ((aType == aheadOrBehindAhead_E) ||
	      (aType == aheadOrBehind_E));
    }

void aheadOrBehindAhead::printSelf()
{
  printf(".AHEAD.");
}

/********************************************************************/

/* aheadOrBehindBehind */

aheadOrBehindBehind::aheadOrBehindBehind(){}


aheadOrBehindBehind::~aheadOrBehindBehind()
{
}

int aheadOrBehindBehind::isA(int aType)
    { return ((aType == aheadOrBehindBehind_E) ||
	      (aType == aheadOrBehind_E));
    }

void aheadOrBehindBehind::printSelf()
{
  printf(".BEHIND.");
}

/********************************************************************/

/* aheadOrBehindExact */

aheadOrBehindExact::aheadOrBehindExact(){}


aheadOrBehindExact::~aheadOrBehindExact()
{
}

int aheadOrBehindExact::isA(int aType)
    { return ((aType == aheadOrBehindExact_E) ||
	      (aType == aheadOrBehind_E));
    }

void aheadOrBehindExact::printSelf()
{
  printf(".EXACT.");
}

/********************************************************************/

/* approachRetractStrategy */

approachRetractStrategy::approachRetractStrategy(){}

approachRetractStrategy::approachRetractStrategy(
 direction * toolOrientationIn)
{
  toolOrientation = toolOrientationIn;
}

approachRetractStrategy::~approachRetractStrategy(){}

int approachRetractStrategy::isA(int aType)
    { return (aType == approachRetractStrategy_E); }

/********************************************************************/

/* approval */

approval::approval(){}

approval::approval(
 approvalStatus * statusIn,
 char * levelIn)
{
  status = statusIn;
  level = levelIn;
}

approval::~approval()
{
  delete level;
}

int approval::isA(int aType)
    { return (aType == approval_E); }

void approval::printSelf()
{
  printf("APPROVAL");
  printf("(");
  status->iId->printSelf();
  printf(",");
  printString(level);
  printf(")");
}

/********************************************************************/

/* approvalStatus */

approvalStatus::approvalStatus(){}

approvalStatus::approvalStatus(
 char * nameIn)
{
  name = nameIn;
}

approvalStatus::~approvalStatus()
{
  delete name;
}

int approvalStatus::isA(int aType)
    { return (aType == approvalStatus_E); }

void approvalStatus::printSelf()
{
  printf("APPROVAL_STATUS");
  printf("(");
  printString(name);
  printf(")");
}

/********************************************************************/

/* aString */

aString::aString(){}

aString::aString(
 char * theStringIn)
{
  theString = theStringIn;
}

aString::~aString()
{
  delete theString;
}

int aString::isA(int aType)
    { return (aType == aString_E); }

void aString::printSelf()
{
  printString(theString);
}

/********************************************************************/

/* boolean */

boolean::boolean(){}


boolean::~boolean(){}

int boolean::isA(int aType)
    { return (aType == boolean_E); }

/********************************************************************/

/* booleanExpression */

booleanExpression::booleanExpression(){}


booleanExpression::~booleanExpression(){}

int booleanExpression::isA(int aType)
    { return (aType == booleanExpression_E); }

/********************************************************************/

/* booleanFalse */

booleanFalse::booleanFalse(){}


booleanFalse::~booleanFalse()
{
}

int booleanFalse::isA(int aType)
    { return ((aType == booleanFalse_E) ||
	      (aType == boolean_E));
    }

void booleanFalse::printSelf()
{
  printf(".F.");
}

/********************************************************************/

/* booleanTrue */

booleanTrue::booleanTrue(){}


booleanTrue::~booleanTrue()
{
}

int booleanTrue::isA(int aType)
    { return ((aType == booleanTrue_E) ||
	      (aType == boolean_E));
    }

void booleanTrue::printSelf()
{
  printf(".T.");
}

/********************************************************************/

/* bottomOrSide */

bottomOrSide::bottomOrSide(){}


bottomOrSide::~bottomOrSide(){}

int bottomOrSide::isA(int aType)
    { return (aType == bottomOrSide_E); }

/********************************************************************/

/* bottomOrSideBottom */

bottomOrSideBottom::bottomOrSideBottom(){}


bottomOrSideBottom::~bottomOrSideBottom()
{
}

int bottomOrSideBottom::isA(int aType)
    { return ((aType == bottomOrSideBottom_E) ||
	      (aType == bottomOrSide_E));
    }

void bottomOrSideBottom::printSelf()
{
  printf(".BOTTOM.");
}

/********************************************************************/

/* bottomOrSideSide */

bottomOrSideSide::bottomOrSideSide(){}


bottomOrSideSide::~bottomOrSideSide()
{
}

int bottomOrSideSide::isA(int aType)
    { return ((aType == bottomOrSideSide_E) ||
	      (aType == bottomOrSide_E));
    }

void bottomOrSideSide::printSelf()
{
  printf(".SIDE.");
}

/********************************************************************/

/* bottomOrSideBottomAndSide */

bottomOrSideBottomAndSide::bottomOrSideBottomAndSide(){}


bottomOrSideBottomAndSide::~bottomOrSideBottomAndSide()
{
}

int bottomOrSideBottomAndSide::isA(int aType)
    { return ((aType == bottomOrSideBottomAndSide_E) ||
	      (aType == bottomOrSide_E));
    }

void bottomOrSideBottomAndSide::printSelf()
{
  printf(".BOTTOM_AND_SIDE.");
}

/********************************************************************/

/* bSplineCurveForm */

bSplineCurveForm::bSplineCurveForm(){}


bSplineCurveForm::~bSplineCurveForm(){}

int bSplineCurveForm::isA(int aType)
    { return (aType == bSplineCurveForm_E); }

/********************************************************************/

/* bSplineCurveFormPolylineForm */

bSplineCurveFormPolylineForm::bSplineCurveFormPolylineForm(){}


bSplineCurveFormPolylineForm::~bSplineCurveFormPolylineForm()
{
}

int bSplineCurveFormPolylineForm::isA(int aType)
    { return ((aType == bSplineCurveFormPolylineForm_E) ||
	      (aType == bSplineCurveForm_E));
    }

void bSplineCurveFormPolylineForm::printSelf()
{
  printf(".POLYLINE_FORM.");
}

/********************************************************************/

/* bSplineCurveFormCircularArc */

bSplineCurveFormCircularArc::bSplineCurveFormCircularArc(){}


bSplineCurveFormCircularArc::~bSplineCurveFormCircularArc()
{
}

int bSplineCurveFormCircularArc::isA(int aType)
    { return ((aType == bSplineCurveFormCircularArc_E) ||
	      (aType == bSplineCurveForm_E));
    }

void bSplineCurveFormCircularArc::printSelf()
{
  printf(".CIRCULAR_ARC.");
}

/********************************************************************/

/* bSplineCurveFormEllipticArc */

bSplineCurveFormEllipticArc::bSplineCurveFormEllipticArc(){}


bSplineCurveFormEllipticArc::~bSplineCurveFormEllipticArc()
{
}

int bSplineCurveFormEllipticArc::isA(int aType)
    { return ((aType == bSplineCurveFormEllipticArc_E) ||
	      (aType == bSplineCurveForm_E));
    }

void bSplineCurveFormEllipticArc::printSelf()
{
  printf(".ELLIPTIC_ARC.");
}

/********************************************************************/

/* bSplineCurveFormParabolicArc */

bSplineCurveFormParabolicArc::bSplineCurveFormParabolicArc(){}


bSplineCurveFormParabolicArc::~bSplineCurveFormParabolicArc()
{
}

int bSplineCurveFormParabolicArc::isA(int aType)
    { return ((aType == bSplineCurveFormParabolicArc_E) ||
	      (aType == bSplineCurveForm_E));
    }

void bSplineCurveFormParabolicArc::printSelf()
{
  printf(".PARABOLIC_ARC.");
}

/********************************************************************/

/* bSplineCurveFormHyperbolicArc */

bSplineCurveFormHyperbolicArc::bSplineCurveFormHyperbolicArc(){}


bSplineCurveFormHyperbolicArc::~bSplineCurveFormHyperbolicArc()
{
}

int bSplineCurveFormHyperbolicArc::isA(int aType)
    { return ((aType == bSplineCurveFormHyperbolicArc_E) ||
	      (aType == bSplineCurveForm_E));
    }

void bSplineCurveFormHyperbolicArc::printSelf()
{
  printf(".HYPERBOLIC_ARC.");
}

/********************************************************************/

/* bSplineCurveFormUnspecified */

bSplineCurveFormUnspecified::bSplineCurveFormUnspecified(){}


bSplineCurveFormUnspecified::~bSplineCurveFormUnspecified()
{
}

int bSplineCurveFormUnspecified::isA(int aType)
    { return ((aType == bSplineCurveFormUnspecified_E) ||
	      (aType == bSplineCurveForm_E));
    }

void bSplineCurveFormUnspecified::printSelf()
{
  printf(".UNSPECIFIED.");
}

/********************************************************************/

/* bSplineSurfaceForm */

bSplineSurfaceForm::bSplineSurfaceForm(){}


bSplineSurfaceForm::~bSplineSurfaceForm(){}

int bSplineSurfaceForm::isA(int aType)
    { return (aType == bSplineSurfaceForm_E); }

/********************************************************************/

/* bSplineSurfaceFormConicalSurf */

bSplineSurfaceFormConicalSurf::bSplineSurfaceFormConicalSurf(){}


bSplineSurfaceFormConicalSurf::~bSplineSurfaceFormConicalSurf()
{
}

int bSplineSurfaceFormConicalSurf::isA(int aType)
    { return ((aType == bSplineSurfaceFormConicalSurf_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormConicalSurf::printSelf()
{
  printf(".CONICAL_SURF.");
}

/********************************************************************/

/* bSplineSurfaceFormCylindricalSurf */

bSplineSurfaceFormCylindricalSurf::bSplineSurfaceFormCylindricalSurf(){}


bSplineSurfaceFormCylindricalSurf::~bSplineSurfaceFormCylindricalSurf()
{
}

int bSplineSurfaceFormCylindricalSurf::isA(int aType)
    { return ((aType == bSplineSurfaceFormCylindricalSurf_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormCylindricalSurf::printSelf()
{
  printf(".CYLINDRICAL_SURF.");
}

/********************************************************************/

/* bSplineSurfaceFormGeneralizedCone */

bSplineSurfaceFormGeneralizedCone::bSplineSurfaceFormGeneralizedCone(){}


bSplineSurfaceFormGeneralizedCone::~bSplineSurfaceFormGeneralizedCone()
{
}

int bSplineSurfaceFormGeneralizedCone::isA(int aType)
    { return ((aType == bSplineSurfaceFormGeneralizedCone_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormGeneralizedCone::printSelf()
{
  printf(".GENERALIZED_CONE.");
}

/********************************************************************/

/* bSplineSurfaceFormPlaneSurf */

bSplineSurfaceFormPlaneSurf::bSplineSurfaceFormPlaneSurf(){}


bSplineSurfaceFormPlaneSurf::~bSplineSurfaceFormPlaneSurf()
{
}

int bSplineSurfaceFormPlaneSurf::isA(int aType)
    { return ((aType == bSplineSurfaceFormPlaneSurf_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormPlaneSurf::printSelf()
{
  printf(".PLANE_SURF.");
}

/********************************************************************/

/* bSplineSurfaceFormQuadricSurf */

bSplineSurfaceFormQuadricSurf::bSplineSurfaceFormQuadricSurf(){}


bSplineSurfaceFormQuadricSurf::~bSplineSurfaceFormQuadricSurf()
{
}

int bSplineSurfaceFormQuadricSurf::isA(int aType)
    { return ((aType == bSplineSurfaceFormQuadricSurf_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormQuadricSurf::printSelf()
{
  printf(".QUADRIC_SURF.");
}

/********************************************************************/

/* bSplineSurfaceFormRuledSurf */

bSplineSurfaceFormRuledSurf::bSplineSurfaceFormRuledSurf(){}


bSplineSurfaceFormRuledSurf::~bSplineSurfaceFormRuledSurf()
{
}

int bSplineSurfaceFormRuledSurf::isA(int aType)
    { return ((aType == bSplineSurfaceFormRuledSurf_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormRuledSurf::printSelf()
{
  printf(".RULED_SURF.");
}

/********************************************************************/

/* bSplineSurfaceFormSphericalSurf */

bSplineSurfaceFormSphericalSurf::bSplineSurfaceFormSphericalSurf(){}


bSplineSurfaceFormSphericalSurf::~bSplineSurfaceFormSphericalSurf()
{
}

int bSplineSurfaceFormSphericalSurf::isA(int aType)
    { return ((aType == bSplineSurfaceFormSphericalSurf_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormSphericalSurf::printSelf()
{
  printf(".SPHERICAL_SURF.");
}

/********************************************************************/

/* bSplineSurfaceFormSurfOfLinearExtrusion */

bSplineSurfaceFormSurfOfLinearExtrusion::bSplineSurfaceFormSurfOfLinearExtrusion(){}


bSplineSurfaceFormSurfOfLinearExtrusion::~bSplineSurfaceFormSurfOfLinearExtrusion()
{
}

int bSplineSurfaceFormSurfOfLinearExtrusion::isA(int aType)
    { return ((aType == bSplineSurfaceFormSurfOfLinearExtrusion_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormSurfOfLinearExtrusion::printSelf()
{
  printf(".SURF_OF_LINEAR_EXTRUSION.");
}

/********************************************************************/

/* bSplineSurfaceFormSurfOfRevolution */

bSplineSurfaceFormSurfOfRevolution::bSplineSurfaceFormSurfOfRevolution(){}


bSplineSurfaceFormSurfOfRevolution::~bSplineSurfaceFormSurfOfRevolution()
{
}

int bSplineSurfaceFormSurfOfRevolution::isA(int aType)
    { return ((aType == bSplineSurfaceFormSurfOfRevolution_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormSurfOfRevolution::printSelf()
{
  printf(".SURF_OF_REVOLUTION.");
}

/********************************************************************/

/* bSplineSurfaceFormToroidalSurf */

bSplineSurfaceFormToroidalSurf::bSplineSurfaceFormToroidalSurf(){}


bSplineSurfaceFormToroidalSurf::~bSplineSurfaceFormToroidalSurf()
{
}

int bSplineSurfaceFormToroidalSurf::isA(int aType)
    { return ((aType == bSplineSurfaceFormToroidalSurf_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormToroidalSurf::printSelf()
{
  printf(".TOROIDAL_SURF.");
}

/********************************************************************/

/* bSplineSurfaceFormUnspecified */

bSplineSurfaceFormUnspecified::bSplineSurfaceFormUnspecified(){}


bSplineSurfaceFormUnspecified::~bSplineSurfaceFormUnspecified()
{
}

int bSplineSurfaceFormUnspecified::isA(int aType)
    { return ((aType == bSplineSurfaceFormUnspecified_E) ||
	      (aType == bSplineSurfaceForm_E));
    }

void bSplineSurfaceFormUnspecified::printSelf()
{
  printf(".UNSPECIFIED.");
}

/********************************************************************/

/* channel */

channel::channel(){}

channel::channel(
 char * itsIdIn)
{
  itsId = itsIdIn;
}

channel::~channel()
{
  delete itsId;
}

int channel::isA(int aType)
    { return (aType == channel_E); }

void channel::printSelf()
{
  printf("CHANNEL");
  printf("(");
  printString(itsId);
  printf(")");
}

/********************************************************************/

/* circularOffset */

circularOffset::circularOffset(){}

circularOffset::circularOffset(
 double angularOffsetIn,
 int indexIn)
{
  angularOffset = angularOffsetIn;
  index = indexIn;
}

circularOffset::~circularOffset()
{
}

int circularOffset::isA(int aType)
    { return (aType == circularOffset_E); }

void circularOffset::printSelf()
{
  printf("CIRCULAR_OFFSET");
  printf("(");
  printDouble(angularOffset);
  printf(",");
  printf("%d", index);
  printf(")");
}

/********************************************************************/

/* circularOmit */

circularOmit::circularOmit(){}

circularOmit::circularOmit(
 int indexIn)
{
  index = indexIn;
}

circularOmit::~circularOmit()
{
}

int circularOmit::isA(int aType)
    { return (aType == circularOmit_E); }

void circularOmit::printSelf()
{
  printf("CIRCULAR_OMIT");
  printf("(");
  printf("%d", index);
  printf(")");
}

/********************************************************************/

/* comparisonExpression */

comparisonExpression::comparisonExpression(){}

comparisonExpression::comparisonExpression(
 ncVariable * operand1In,
 rvalue * operand2In)
{
  operand1 = operand1In;
  operand2 = operand2In;
}

comparisonExpression::~comparisonExpression(){}

int comparisonExpression::isA(int aType)
    { return ((aType == comparisonExpression_E) ||
	      (aType == booleanExpression_E));
    }

/********************************************************************/

/* compositeCurveSegment */

compositeCurveSegment::compositeCurveSegment(){}

compositeCurveSegment::compositeCurveSegment(
 transitionCode * transitionIn,
 boolean * sameSenseIn,
 curve * parentCurveIn)
{
  transition = transitionIn;
  sameSense = sameSenseIn;
  parentCurve = parentCurveIn;
}

compositeCurveSegment::~compositeCurveSegment()
{
  delete transition;
  delete sameSense;
}

int compositeCurveSegment::isA(int aType)
    { return (aType == compositeCurveSegment_E); }

void compositeCurveSegment::printSelf()
{
  printf("COMPOSITE_CURVE_SEGMENT");
  printf("(");
  transition->printSelf();
  printf(",");
  sameSense->printSelf();
  printf(",");
  (dynamic_cast<instance *>(parentCurve))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* compoundFeatureSelect */

compoundFeatureSelect::compoundFeatureSelect(){}


compoundFeatureSelect::~compoundFeatureSelect(){}

int compoundFeatureSelect::isA(int aType)
    { return (aType == compoundFeatureSelect_E); }

/********************************************************************/

/* contactType */

contactType::contactType(){}


contactType::~contactType(){}

int contactType::isA(int aType)
    { return (aType == contactType_E); }

/********************************************************************/

/* contactTypeSide */

contactTypeSide::contactTypeSide(){}


contactTypeSide::~contactTypeSide()
{
}

int contactTypeSide::isA(int aType)
    { return ((aType == contactTypeSide_E) ||
	      (aType == contactType_E));
    }

void contactTypeSide::printSelf()
{
  printf(".SIDE.");
}

/********************************************************************/

/* contactTypeFront */

contactTypeFront::contactTypeFront(){}


contactTypeFront::~contactTypeFront()
{
}

int contactTypeFront::isA(int aType)
    { return ((aType == contactTypeFront_E) ||
	      (aType == contactType_E));
    }

void contactTypeFront::printSelf()
{
  printf(".FRONT.");
}

/********************************************************************/

/* coordinatedUniversalTimeOffset */

coordinatedUniversalTimeOffset::coordinatedUniversalTimeOffset(){}

coordinatedUniversalTimeOffset::coordinatedUniversalTimeOffset(
 int hourOffsetIn,
 integer * minuteOffsetIn,
 aheadOrBehind * senseIn)
{
  hourOffset = hourOffsetIn;
  minuteOffset = minuteOffsetIn;
  sense = senseIn;
}

coordinatedUniversalTimeOffset::~coordinatedUniversalTimeOffset()
{
  delete minuteOffset;
  delete sense;
}

int coordinatedUniversalTimeOffset::isA(int aType)
    { return (aType == coordinatedUniversalTimeOffset_E); }

void coordinatedUniversalTimeOffset::printSelf()
{
  printf("COORDINATED_UNIVERSAL_TIME_OFFSET");
  printf("(");
  printf("%d", hourOffset);
  if (minuteOffset)
    minuteOffset->printSelf();
  else
    printf("$");
  sense->printSelf();
  printf(")");
}

/********************************************************************/

/* curveWithSurfaceNormalSelect */

curveWithSurfaceNormalSelect::curveWithSurfaceNormalSelect(){}


curveWithSurfaceNormalSelect::~curveWithSurfaceNormalSelect(){}

int curveWithSurfaceNormalSelect::isA(int aType)
    { return (aType == curveWithSurfaceNormalSelect_E); }

/********************************************************************/

/* cutmodeType */

cutmodeType::cutmodeType(){}


cutmodeType::~cutmodeType(){}

int cutmodeType::isA(int aType)
    { return (aType == cutmodeType_E); }

/********************************************************************/

/* cutmodeTypeClimb */

cutmodeTypeClimb::cutmodeTypeClimb(){}


cutmodeTypeClimb::~cutmodeTypeClimb()
{
}

int cutmodeTypeClimb::isA(int aType)
    { return ((aType == cutmodeTypeClimb_E) ||
	      (aType == cutmodeType_E));
    }

void cutmodeTypeClimb::printSelf()
{
  printf(".CLIMB.");
}

/********************************************************************/

/* cutmodeTypeConventional */

cutmodeTypeConventional::cutmodeTypeConventional(){}


cutmodeTypeConventional::~cutmodeTypeConventional()
{
}

int cutmodeTypeConventional::isA(int aType)
    { return ((aType == cutmodeTypeConventional_E) ||
	      (aType == cutmodeType_E));
    }

void cutmodeTypeConventional::printSelf()
{
  printf(".CONVENTIONAL.");
}

/********************************************************************/

/* cutterContactTrajectory */

cutterContactTrajectory::cutterContactTrajectory(){}

cutterContactTrajectory::cutterContactTrajectory(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 boolean * itsDirectionIn,
 curveWithSurfaceNormalSelect * basiccurveIn,
 boundedCurve * itsToolaxisIn,
 contactType * itsContactTypeIn)
{
  itsPriority = itsPriorityIn;
  itsType = itsTypeIn;
  itsSpeed = itsSpeedIn;
  itsTechnology = itsTechnologyIn;
  itsMachineFunctions = itsMachineFunctionsIn;
  itsDirection = itsDirectionIn;
  basiccurve = basiccurveIn;
  itsToolaxis = itsToolaxisIn;
  itsContactType = itsContactTypeIn;
}

cutterContactTrajectory::~cutterContactTrajectory()
{
  delete itsPriority;
  delete itsType;
  delete itsDirection;
  delete itsContactType;
}

int cutterContactTrajectory::isA(int aType)
    { return (aType == cutterContactTrajectory_E); }

void cutterContactTrajectory::printSelf()
{
  printf("CUTTER_CONTACT_TRAJECTORY");
  printf("(");
  itsPriority->printSelf();
  printf(",");
  itsType->printSelf();
  printf(",");
  if (itsSpeed)
    itsSpeed->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachineFunctions)
    (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsDirection)
    itsDirection->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(basiccurve))->iId->printSelf();
  printf(",");
  if (itsToolaxis)
    (dynamic_cast<instance *>(itsToolaxis))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsContactType)
    itsContactType->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* cuttingComponent */

cuttingComponent::cuttingComponent(){}

cuttingComponent::cuttingComponent(
 double toolOffsetLengthIn,
 material * itsMaterialIn,
 cuttingEdgeTechnologicalData * technologicalDataIn,
 real * expectedToolLifeIn,
 millingTechnology * itsTechnologyIn)
{
  toolOffsetLength = toolOffsetLengthIn;
  itsMaterial = itsMaterialIn;
  technologicalData = technologicalDataIn;
  expectedToolLife = expectedToolLifeIn;
  itsTechnology = itsTechnologyIn;
}

cuttingComponent::~cuttingComponent()
{
  delete expectedToolLife;
}

int cuttingComponent::isA(int aType)
    { return (aType == cuttingComponent_E); }

void cuttingComponent::printSelf()
{
  printf("CUTTING_COMPONENT");
  printf("(");
  printDouble(toolOffsetLength);
  printf(",");
  if (itsMaterial)
    itsMaterial->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (technologicalData)
    technologicalData->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (expectedToolLife)
    expectedToolLife->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    itsTechnology->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* cuttingEdgeTechnologicalData */

cuttingEdgeTechnologicalData::cuttingEdgeTechnologicalData(){}

cuttingEdgeTechnologicalData::cuttingEdgeTechnologicalData(
 real * cuttingAngleIn,
 real * freeAngleIn,
 real * auxAngleIn)
{
  cuttingAngle = cuttingAngleIn;
  freeAngle = freeAngleIn;
  auxAngle = auxAngleIn;
}

cuttingEdgeTechnologicalData::~cuttingEdgeTechnologicalData()
{
  delete cuttingAngle;
  delete freeAngle;
  delete auxAngle;
}

int cuttingEdgeTechnologicalData::isA(int aType)
    { return (aType == cuttingEdgeTechnologicalData_E); }

void cuttingEdgeTechnologicalData::printSelf()
{
  printf("CUTTING_EDGE_TECHNOLOGICAL_DATA");
  printf("(");
  if (cuttingAngle)
    cuttingAngle->printSelf();
  else
    printf("$");
  printf(",");
  if (freeAngle)
    freeAngle->printSelf();
  else
    printf("$");
  printf(",");
  if (auxAngle)
    auxAngle->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* dataSection */

dataSection::dataSection(){}

dataSection::dataSection(
 dataStarter * dataStartIn,
 std::list<instance *> * itemsIn,
 endSection * sectionEndIn)
{
  dataStart = dataStartIn;
  items = itemsIn;
  sectionEnd = sectionEndIn;
}

dataSection::~dataSection()
{
  delete dataStart;
  {
    std::list<instance *>::iterator iter;
    for (iter = items->begin(); iter != items->end(); ++iter)
      {
        delete *iter;
      }
  }
  delete items;
  delete sectionEnd;
}

int dataSection::isA(int aType)
    { return (aType == dataSection_E); }

void dataSection::printSelf()
{
  dataStart->printSelf();
  if (items->begin() != items->end())
    {
      std::list<instance *>::iterator iter;
      for (iter = items->begin();
           iter != items->end();
           iter++)
        {
          (*iter)->iId->printSelf();
          printf("=");
          (*iter)->printSelf();
          printf(";\n");
        }
    }
  sectionEnd->printSelf();
}

/********************************************************************/

/* dataStarter */

dataStarter::dataStarter(){}


dataStarter::~dataStarter()
{
}

int dataStarter::isA(int aType)
    { return (aType == dataStarter_E); }

void dataStarter::printSelf()
{
  printf("DATA");
  printf(";\n");
}

/********************************************************************/

/* date */

date::date(){}

date::date(
 int yearComponentIn)
{
  yearComponent = yearComponentIn;
}

date::~date(){}

int date::isA(int aType)
    { return (aType == date_E); }

/********************************************************************/

/* dateAndTime */

dateAndTime::dateAndTime(){}

dateAndTime::dateAndTime(
 date * dateComponentIn,
 localTime * timeComponentIn)
{
  dateComponent = dateComponentIn;
  timeComponent = timeComponentIn;
}

dateAndTime::~dateAndTime()
{
}

int dateAndTime::isA(int aType)
    { return (aType == dateAndTime_E); }

void dateAndTime::printSelf()
{
  printf("DATE_AND_TIME");
  printf("(");
  (dynamic_cast<instance *>(dateComponent))->iId->printSelf();
  printf(",");
  timeComponent->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* drillingTypeStrategy */

drillingTypeStrategy::drillingTypeStrategy(){}

drillingTypeStrategy::drillingTypeStrategy(
 real * reducedCutAtStartIn,
 real * reducedFeedAtStartIn,
 real * depthOfStartIn,
 real * reducedCutAtEndIn,
 real * reducedFeedAtEndIn,
 real * depthOfEndIn)
{
  reducedCutAtStart = reducedCutAtStartIn;
  reducedFeedAtStart = reducedFeedAtStartIn;
  depthOfStart = depthOfStartIn;
  reducedCutAtEnd = reducedCutAtEndIn;
  reducedFeedAtEnd = reducedFeedAtEndIn;
  depthOfEnd = depthOfEndIn;
}

drillingTypeStrategy::~drillingTypeStrategy()
{
  delete reducedCutAtStart;
  delete reducedFeedAtStart;
  delete depthOfStart;
  delete reducedCutAtEnd;
  delete reducedFeedAtEnd;
  delete depthOfEnd;
}

int drillingTypeStrategy::isA(int aType)
    { return (aType == drillingTypeStrategy_E); }

void drillingTypeStrategy::printSelf()
{
  printf("DRILLING_TYPE_STRATEGY");
  printf("(");
  if (reducedCutAtStart)
    reducedCutAtStart->printSelf();
  else
    printf("$");
  printf(",");
  if (reducedFeedAtStart)
    reducedFeedAtStart->printSelf();
  else
    printf("$");
  printf(",");
  if (depthOfStart)
    depthOfStart->printSelf();
  else
    printf("$");
  printf(",");
  if (reducedCutAtEnd)
    reducedCutAtEnd->printSelf();
  else
    printf("$");
  printf(",");
  if (reducedFeedAtEnd)
    reducedFeedAtEnd->printSelf();
  else
    printf("$");
  printf(",");
  if (depthOfEnd)
    depthOfEnd->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* endSection */

endSection::endSection(){}


endSection::~endSection()
{
}

int endSection::isA(int aType)
    { return (aType == endSection_E); }

void endSection::printSelf()
{
  printf("ENDSEC");
  printf(";\n");
}

/********************************************************************/

/* executable */

executable::executable(){}

executable::executable(
 char * itsIdIn)
{
  itsId = itsIdIn;
}

executable::~executable(){}

int executable::isA(int aType)
    { return (aType == executable_E); }

/********************************************************************/

/* fileDescription */

fileDescription::fileDescription(){}

fileDescription::fileDescription(
 parenStringListFull * descriptionIn,
 char * implementationLevelIn)
{
  description = descriptionIn;
  implementationLevel = implementationLevelIn;
}

fileDescription::~fileDescription()
{
  delete description;
  delete implementationLevel;
}

int fileDescription::isA(int aType)
    { return (aType == fileDescription_E); }

void fileDescription::printSelf()
{
  printf("FILE_DESCRIPTION");
  printf("(");
  description->printSelf();
  printf(",");
  printString(implementationLevel);
  printf(")");
  printf(";\n");
}

/********************************************************************/

/* fileEnd */

fileEnd::fileEnd(){}


fileEnd::~fileEnd()
{
}

int fileEnd::isA(int aType)
    { return (aType == fileEnd_E); }

void fileEnd::printSelf()
{
  printf("END-ISO-10303-21");
  printf(";\n");
}

/********************************************************************/

/* fileName */

fileName::fileName(){}

fileName::fileName(
 char * nameIn,
 char * timeStampIn,
 parenStringListFull * authorIn,
 parenStringListFull * organizationIn,
 char * preprocessorVersionIn,
 char * originatingSystemIn,
 char * authorizationIn)
{
  name = nameIn;
  timeStamp = timeStampIn;
  author = authorIn;
  organization = organizationIn;
  preprocessorVersion = preprocessorVersionIn;
  originatingSystem = originatingSystemIn;
  authorization = authorizationIn;
}

fileName::~fileName()
{
  delete name;
  delete timeStamp;
  delete author;
  delete organization;
  delete preprocessorVersion;
  delete originatingSystem;
  delete authorization;
}

int fileName::isA(int aType)
    { return (aType == fileName_E); }

void fileName::printSelf()
{
  printf("FILE_NAME");
  printf("(");
  printString(name);
  printf(",");
  printString(timeStamp);
  printf(",");
  author->printSelf();
  printf(",");
  organization->printSelf();
  printf(",");
  printString(preprocessorVersion);
  printf(",");
  printString(originatingSystem);
  printf(",");
  printString(authorization);
  printf(")");
  printf(";\n");
}

/********************************************************************/

/* fileSchema */

fileSchema::fileSchema(){}

fileSchema::fileSchema(
 parenStringList * schemaIdentifiersIn)
{
  schemaIdentifiers = schemaIdentifiersIn;
}

fileSchema::~fileSchema()
{
  delete schemaIdentifiers;
}

int fileSchema::isA(int aType)
    { return (aType == fileSchema_E); }

void fileSchema::printSelf()
{
  printf("FILE_SCHEMA");
  printf("(");
  schemaIdentifiers->printSelf();
  printf(")");
  printf(";\n");
}

/********************************************************************/

/* fileStart */

fileStart::fileStart(){}


fileStart::~fileStart()
{
}

int fileStart::isA(int aType)
    { return (aType == fileStart_E); }

void fileStart::printSelf()
{
  printf("ISO-10303-21");
  printf(";\n");
}

/********************************************************************/

/* fittingType */

fittingType::fittingType(){}


fittingType::~fittingType(){}

int fittingType::isA(int aType)
    { return (aType == fittingType_E); }

/********************************************************************/

/* fittingTypeHole */

fittingTypeHole::fittingTypeHole(){}


fittingTypeHole::~fittingTypeHole()
{
}

int fittingTypeHole::isA(int aType)
    { return ((aType == fittingTypeHole_E) ||
	      (aType == fittingType_E));
    }

void fittingTypeHole::printSelf()
{
  printf(".HOLE.");
}

/********************************************************************/

/* fittingTypeShaft */

fittingTypeShaft::fittingTypeShaft(){}


fittingTypeShaft::~fittingTypeShaft()
{
}

int fittingTypeShaft::isA(int aType)
    { return ((aType == fittingTypeShaft_E) ||
	      (aType == fittingType_E));
    }

void fittingTypeShaft::printSelf()
{
  printf(".SHAFT.");
}

/********************************************************************/

/* freeformStrategy */

freeformStrategy::freeformStrategy(){}

freeformStrategy::freeformStrategy(
 pathmodeType * pathmodeIn,
 cutmodeType * cutmodeIn,
 tolerances * itsMillingTolerancesIn,
 real * stepoverIn)
{
  pathmode = pathmodeIn;
  cutmode = cutmodeIn;
  itsMillingTolerances = itsMillingTolerancesIn;
  stepover = stepoverIn;
}

freeformStrategy::~freeformStrategy(){}

int freeformStrategy::isA(int aType)
    { return (aType == freeformStrategy_E); }

/********************************************************************/

/* hand */

hand::hand(){}


hand::~hand(){}

int hand::isA(int aType)
    { return (aType == hand_E); }

/********************************************************************/

/* handLeft */

handLeft::handLeft(){}


handLeft::~handLeft()
{
}

int handLeft::isA(int aType)
    { return ((aType == handLeft_E) ||
	      (aType == hand_E));
    }

void handLeft::printSelf()
{
  printf(".LEFT.");
}

/********************************************************************/

/* handNeutral */

handNeutral::handNeutral(){}


handNeutral::~handNeutral()
{
}

int handNeutral::isA(int aType)
    { return ((aType == handNeutral_E) ||
	      (aType == hand_E));
    }

void handNeutral::printSelf()
{
  printf(".NEUTRAL.");
}

/********************************************************************/

/* handRight */

handRight::handRight(){}


handRight::~handRight()
{
}

int handRight::isA(int aType)
    { return ((aType == handRight_E) ||
	      (aType == hand_E));
    }

void handRight::printSelf()
{
  printf(".RIGHT.");
}

/********************************************************************/

/* headerSection */

headerSection::headerSection(){}

headerSection::headerSection(
 headerStarter * headerStartIn,
 fileDescription * headerDescriptionIn,
 fileName * headerNameIn,
 fileSchema * headerSchemaIn,
 endSection * sectionEndIn)
{
  headerStart = headerStartIn;
  headerDescription = headerDescriptionIn;
  headerName = headerNameIn;
  headerSchema = headerSchemaIn;
  sectionEnd = sectionEndIn;
}

headerSection::~headerSection()
{
  delete headerStart;
  delete headerDescription;
  delete headerName;
  delete headerSchema;
  delete sectionEnd;
}

int headerSection::isA(int aType)
    { return (aType == headerSection_E); }

void headerSection::printSelf()
{
  headerStart->printSelf();
  headerDescription->printSelf();
  headerName->printSelf();
  headerSchema->printSelf();
  sectionEnd->printSelf();
}

/********************************************************************/

/* headerStarter */

headerStarter::headerStarter(){}


headerStarter::~headerStarter()
{
}

int headerStarter::isA(int aType)
    { return (aType == headerStarter_E); }

void headerStarter::printSelf()
{
  printf("HEADER");
  printf(";\n");
}

/********************************************************************/

/* holeBottomCondition */

holeBottomCondition::holeBottomCondition(){}


holeBottomCondition::~holeBottomCondition(){}

int holeBottomCondition::isA(int aType)
    { return (aType == holeBottomCondition_E); }

/********************************************************************/

/* inProcessGeometry */

inProcessGeometry::inProcessGeometry(){}

inProcessGeometry::inProcessGeometry(
 advancedBrepShapeRepresentation * asIsIn,
 advancedBrepShapeRepresentation * toBeIn,
 advancedBrepShapeRepresentation * removalIn)
{
  asIs = asIsIn;
  toBe = toBeIn;
  removal = removalIn;
}

inProcessGeometry::~inProcessGeometry()
{
}

int inProcessGeometry::isA(int aType)
    { return (aType == inProcessGeometry_E); }

void inProcessGeometry::printSelf()
{
  printf("IN_PROCESS_GEOMETRY");
  printf("(");
  if (asIs)
    asIs->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (toBe)
    toBe->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (removal)
    removal->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* instanceId */

instanceId::instanceId(){}

instanceId::instanceId(
 int valIn)
{
  val = valIn;
}

instanceId::~instanceId()
{
}

int instanceId::isA(int aType)
    { return (aType == instanceId_E); }

void instanceId::printSelf()
{
  printf("#");
  printf("%d", val);
}

/********************************************************************/

/* integer */

integer::integer(){}

integer::integer(
 int valIn)
{
  val = valIn;
}

integer::~integer()
{
}

int integer::isA(int aType)
    { return (aType == integer_E); }

void integer::printSelf()
{
  printf("%d", val);
}

/********************************************************************/

/* knotType */

knotType::knotType(){}


knotType::~knotType(){}

int knotType::isA(int aType)
    { return (aType == knotType_E); }

/********************************************************************/

/* knotTypePiecewiseBezierKnots */

knotTypePiecewiseBezierKnots::knotTypePiecewiseBezierKnots(){}


knotTypePiecewiseBezierKnots::~knotTypePiecewiseBezierKnots()
{
}

int knotTypePiecewiseBezierKnots::isA(int aType)
    { return ((aType == knotTypePiecewiseBezierKnots_E) ||
	      (aType == knotType_E));
    }

void knotTypePiecewiseBezierKnots::printSelf()
{
  printf(".PIECEWISE_BEZIER_KNOTS.");
}

/********************************************************************/

/* knotTypeQuasiUniformKnots */

knotTypeQuasiUniformKnots::knotTypeQuasiUniformKnots(){}


knotTypeQuasiUniformKnots::~knotTypeQuasiUniformKnots()
{
}

int knotTypeQuasiUniformKnots::isA(int aType)
    { return ((aType == knotTypeQuasiUniformKnots_E) ||
	      (aType == knotType_E));
    }

void knotTypeQuasiUniformKnots::printSelf()
{
  printf(".QUASI_UNIFORM_KNOTS.");
}

/********************************************************************/

/* knotTypeUniformKnots */

knotTypeUniformKnots::knotTypeUniformKnots(){}


knotTypeUniformKnots::~knotTypeUniformKnots()
{
}

int knotTypeUniformKnots::isA(int aType)
    { return ((aType == knotTypeUniformKnots_E) ||
	      (aType == knotType_E));
    }

void knotTypeUniformKnots::printSelf()
{
  printf(".UNIFORM_KNOTS.");
}

/********************************************************************/

/* knotTypeUnspecified */

knotTypeUnspecified::knotTypeUnspecified(){}


knotTypeUnspecified::~knotTypeUnspecified()
{
}

int knotTypeUnspecified::isA(int aType)
    { return ((aType == knotTypeUnspecified_E) ||
	      (aType == knotType_E));
    }

void knotTypeUnspecified::printSelf()
{
  printf(".UNSPECIFIED.");
}

/********************************************************************/

/* leadingLineStrategy */

leadingLineStrategy::leadingLineStrategy(){}

leadingLineStrategy::leadingLineStrategy(
 pathmodeType * pathmodeIn,
 cutmodeType * cutmodeIn,
 tolerances * itsMillingTolerancesIn,
 real * stepoverIn,
 boundedCurve * itsLineIn) :
   freeformStrategy(
     pathmodeIn,
     cutmodeIn,
     itsMillingTolerancesIn,
     stepoverIn)
{
   itsLine = itsLineIn;
}

leadingLineStrategy::~leadingLineStrategy()
{
  delete pathmode;
  delete cutmode;
  delete stepover;
}

int leadingLineStrategy::isA(int aType)
    { return ((aType == leadingLineStrategy_E) ||
	      (aType == freeformStrategy_E));
    }

void leadingLineStrategy::printSelf()
{
  printf("LEADING_LINE_STRATEGY");
  printf("(");
  pathmode->printSelf();
  printf(",");
  cutmode->printSelf();
  printf(",");
  itsMillingTolerances->iId->printSelf();
  printf(",");
  if (stepover)
    stepover->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsLine))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* leftOrRight */

leftOrRight::leftOrRight(){}


leftOrRight::~leftOrRight(){}

int leftOrRight::isA(int aType)
    { return (aType == leftOrRight_E); }

/********************************************************************/

/* leftOrRightLeft */

leftOrRightLeft::leftOrRightLeft(){}


leftOrRightLeft::~leftOrRightLeft()
{
}

int leftOrRightLeft::isA(int aType)
    { return ((aType == leftOrRightLeft_E) ||
	      (aType == leftOrRight_E));
    }

void leftOrRightLeft::printSelf()
{
  printf(".LEFT.");
}

/********************************************************************/

/* leftOrRightRight */

leftOrRightRight::leftOrRightRight(){}


leftOrRightRight::~leftOrRightRight()
{
}

int leftOrRightRight::isA(int aType)
    { return ((aType == leftOrRightRight_E) ||
	      (aType == leftOrRight_E));
    }

void leftOrRightRight::printSelf()
{
  printf(".RIGHT.");
}

/********************************************************************/

/* localTime */

localTime::localTime(){}

localTime::localTime(
 int hourComponentIn,
 integer * minuteComponentIn,
 real * secondComponentIn,
 coordinatedUniversalTimeOffset * zoneIn)
{
  hourComponent = hourComponentIn;
  minuteComponent = minuteComponentIn;
  secondComponent = secondComponentIn;
  zone = zoneIn;
}

localTime::~localTime()
{
  delete minuteComponent;
  delete secondComponent;
}

int localTime::isA(int aType)
    { return (aType == localTime_E); }

void localTime::printSelf()
{
  printf("LOCAL_TIME");
  printf("(");
  printf("%d", hourComponent);
  if (minuteComponent)
    minuteComponent->printSelf();
  else
    printf("$");
  if (secondComponent)
    secondComponent->printSelf();
  else
    printf("$");
  zone->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* logical */

logical::logical(){}


logical::~logical(){}

int logical::isA(int aType)
    { return (aType == logical_E); }

/********************************************************************/

/* logicalFalse */

logicalFalse::logicalFalse(){}


logicalFalse::~logicalFalse()
{
}

int logicalFalse::isA(int aType)
    { return ((aType == logicalFalse_E) ||
	      (aType == logical_E));
    }

void logicalFalse::printSelf()
{
  printf(".F.");
}

/********************************************************************/

/* logicalTrue */

logicalTrue::logicalTrue(){}


logicalTrue::~logicalTrue()
{
}

int logicalTrue::isA(int aType)
    { return ((aType == logicalTrue_E) ||
	      (aType == logical_E));
    }

void logicalTrue::printSelf()
{
  printf(".T.");
}

/********************************************************************/

/* logicalUnknown */

logicalUnknown::logicalUnknown(){}


logicalUnknown::~logicalUnknown()
{
}

int logicalUnknown::isA(int aType)
    { return ((aType == logicalUnknown_E) ||
	      (aType == logical_E));
    }

void logicalUnknown::printSelf()
{
  printf(".U.");
}

/********************************************************************/

/* machinedSurface */

machinedSurface::machinedSurface(){}

machinedSurface::machinedSurface(
 machiningFeature * itsMachiningFeatureIn,
 bottomOrSide * surfaceElementIn)
{
  itsMachiningFeature = itsMachiningFeatureIn;
  surfaceElement = surfaceElementIn;
}

machinedSurface::~machinedSurface()
{
  delete surfaceElement;
}

int machinedSurface::isA(int aType)
    { return (aType == machinedSurface_E); }

void machinedSurface::printSelf()
{
  printf("MACHINED_SURFACE");
  printf("(");
  (dynamic_cast<instance *>(itsMachiningFeature))->iId->printSelf();
  printf(",");
  surfaceElement->printSelf();
  printf(")");
}

/********************************************************************/

/* machineFunctions */

machineFunctions::machineFunctions(){}


machineFunctions::~machineFunctions(){}

int machineFunctions::isA(int aType)
    { return (aType == machineFunctions_E); }

/********************************************************************/

/* machiningTool */

machiningTool::machiningTool(){}

machiningTool::machiningTool(
 char * itsIdIn)
{
  itsId = itsIdIn;
}

machiningTool::~machiningTool(){}

int machiningTool::isA(int aType)
    { return (aType == machiningTool_E); }

/********************************************************************/

/* manufacturingFeature */

manufacturingFeature::manufacturingFeature(){}

manufacturingFeature::manufacturingFeature(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn)
{
  itsId = itsIdIn;
  itsWorkpiece = itsWorkpieceIn;
  itsOperations = itsOperationsIn;
}

manufacturingFeature::~manufacturingFeature(){}

int manufacturingFeature::isA(int aType)
    { return (aType == manufacturingFeature_E); }

/********************************************************************/

/* material */

material::material(){}

material::material(
 char * standardIdentifierIn,
 char * materialIdentifierIn,
 parenPropertyParameterList * materialPropertyIn)
{
  standardIdentifier = standardIdentifierIn;
  materialIdentifier = materialIdentifierIn;
  materialProperty = materialPropertyIn;
}

material::~material()
{
  delete standardIdentifier;
  delete materialIdentifier;
  delete materialProperty;
}

int material::isA(int aType)
    { return (aType == material_E); }

void material::printSelf()
{
  printf("MATERIAL");
  printf("(");
  printString(standardIdentifier);
  printf(",");
  printString(materialIdentifier);
  printf(",");
  materialProperty->printSelf();
  printf(")");
}

/********************************************************************/

/* millingMachineFunctions */

millingMachineFunctions::millingMachineFunctions(){}

millingMachineFunctions::millingMachineFunctions(
 boolean * coolantIn,
 real * coolantPressureIn,
 boolean * mistIn,
 boolean * throughSpindleCoolantIn,
 real * throughPressureIn,
 parenStringList * axisClampingIn,
 boolean * chipRemovalIn,
 direction * orientedSpindleStopIn,
 processModelList * itsProcessModelIn,
 parenPropertyParameterList * otherFunctionsIn)
{
  coolant = coolantIn;
  coolantPressure = coolantPressureIn;
  mist = mistIn;
  throughSpindleCoolant = throughSpindleCoolantIn;
  throughPressure = throughPressureIn;
  axisClamping = axisClampingIn;
  chipRemoval = chipRemovalIn;
  orientedSpindleStop = orientedSpindleStopIn;
  itsProcessModel = itsProcessModelIn;
  otherFunctions = otherFunctionsIn;
}

millingMachineFunctions::~millingMachineFunctions()
{
  delete coolant;
  delete coolantPressure;
  delete mist;
  delete throughSpindleCoolant;
  delete throughPressure;
  delete axisClamping;
  delete chipRemoval;
  delete otherFunctions;
}

int millingMachineFunctions::isA(int aType)
    { return ((aType == millingMachineFunctions_E) ||
	      (aType == machineFunctions_E));
    }

void millingMachineFunctions::printSelf()
{
  printf("MILLING_MACHINE_FUNCTIONS");
  printf("(");
  coolant->printSelf();
  printf(",");
  if (coolantPressure)
    coolantPressure->printSelf();
  else
    printf("$");
  printf(",");
  if (mist)
    mist->printSelf();
  else
    printf("$");
  printf(",");
  throughSpindleCoolant->printSelf();
  printf(",");
  if (throughPressure)
    throughPressure->printSelf();
  else
    printf("$");
  printf(",");
  axisClamping->printSelf();
  printf(",");
  chipRemoval->printSelf();
  printf(",");
  if (orientedSpindleStop)
    orientedSpindleStop->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsProcessModel)
    itsProcessModel->iId->printSelf();
  else
    printf("$");
  printf(",");
  otherFunctions->printSelf();
  printf(")");
}

/********************************************************************/

/* millingToolDimension */

millingToolDimension::millingToolDimension(){}

millingToolDimension::millingToolDimension(
 double diameterIn,
 real * toolTopAngleIn,
 real * toolCircumferenceAngleIn,
 real * cuttingEdgeLengthIn,
 real * edgeRadiusIn,
 real * edgeCenterVerticalIn,
 real * edgeCenterHorizontalIn)
{
  diameter = diameterIn;
  toolTopAngle = toolTopAngleIn;
  toolCircumferenceAngle = toolCircumferenceAngleIn;
  cuttingEdgeLength = cuttingEdgeLengthIn;
  edgeRadius = edgeRadiusIn;
  edgeCenterVertical = edgeCenterVerticalIn;
  edgeCenterHorizontal = edgeCenterHorizontalIn;
}

millingToolDimension::~millingToolDimension()
{
  delete toolTopAngle;
  delete toolCircumferenceAngle;
  delete cuttingEdgeLength;
  delete edgeRadius;
  delete edgeCenterVertical;
  delete edgeCenterHorizontal;
}

int millingToolDimension::isA(int aType)
    { return (aType == millingToolDimension_E); }

void millingToolDimension::printSelf()
{
  printf("MILLING_TOOL_DIMENSION");
  printf("(");
  printDouble(diameter);
  printf(",");
  if (toolTopAngle)
    toolTopAngle->printSelf();
  else
    printf("$");
  printf(",");
  if (toolCircumferenceAngle)
    toolCircumferenceAngle->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingEdgeLength)
    cuttingEdgeLength->printSelf();
  else
    printf("$");
  printf(",");
  if (edgeRadius)
    edgeRadius->printSelf();
  else
    printf("$");
  printf(",");
  if (edgeCenterVertical)
    edgeCenterVertical->printSelf();
  else
    printf("$");
  printf(",");
  if (edgeCenterHorizontal)
    edgeCenterHorizontal->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* multipleArityBooleanExpression */

multipleArityBooleanExpression::multipleArityBooleanExpression(){}

multipleArityBooleanExpression::multipleArityBooleanExpression(
 parenBooleanExpressionListFull * operandsIn)
{
  operands = operandsIn;
}

multipleArityBooleanExpression::~multipleArityBooleanExpression(){}

int multipleArityBooleanExpression::isA(int aType)
    { return ((aType == multipleArityBooleanExpression_E) ||
	      (aType == booleanExpression_E));
    }

/********************************************************************/

/* ncFunction */

ncFunction::ncFunction(){}

ncFunction::ncFunction(
 char * itsIdIn) :
   executable(
     itsIdIn)
    {}

ncFunction::~ncFunction(){}

int ncFunction::isA(int aType)
    { return ((aType == ncFunction_E) ||
	      (aType == executable_E));
    }

/********************************************************************/

/* offsetVector */

offsetVector::offsetVector(){}

offsetVector::offsetVector(
 parenNcVariableListFull * translateIn,
 parenNcVariableListFull * rotateIn)
{
  translate = translateIn;
  rotate = rotateIn;
}

offsetVector::~offsetVector()
{
  delete translate;
  delete rotate;
}

int offsetVector::isA(int aType)
    { return (aType == offsetVector_E); }

void offsetVector::printSelf()
{
  printf("OFFSET_VECTOR");
  printf("(");
  translate->printSelf();
  printf(",");
  if (rotate)
    rotate->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* operation */

operation::operation(){}

operation::operation(
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn)
{
  itsToolpath = itsToolpathIn;
  itsToolDirection = itsToolDirectionIn;
}

operation::~operation(){}

int operation::isA(int aType)
    { return (aType == operation_E); }

/********************************************************************/

/* optionalStop */

optionalStop::optionalStop(){}

optionalStop::optionalStop(
 char * itsIdIn) :
   ncFunction(
     itsIdIn)
    {}

optionalStop::~optionalStop()
{
  delete itsId;
}

int optionalStop::isA(int aType)
    { return ((aType == optionalStop_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void optionalStop::printSelf()
{
  printf("OPTIONAL_STOP");
  printf("(");
  printString(itsId);
  printf(")");
}

/********************************************************************/

/* orExpression */

orExpression::orExpression(){}

orExpression::orExpression(
 parenBooleanExpressionListFull * operandsIn) :
   multipleArityBooleanExpression(
     operandsIn)
    {}

orExpression::~orExpression()
{
  delete operands;
}

int orExpression::isA(int aType)
    { return ((aType == orExpression_E) ||
	      (aType == multipleArityBooleanExpression_E) ||
	      (aType == booleanExpression_E));
    }

void orExpression::printSelf()
{
  printf("OR_EXPRESSION");
  printf("(");
  operands->printSelf();
  printf(")");
}

/********************************************************************/

/* ordinalDate */

ordinalDate::ordinalDate(){}

ordinalDate::ordinalDate(
 int yearComponentIn,
 int dayComponentIn) :
   date(
     yearComponentIn)
{
   dayComponent = dayComponentIn;
}

ordinalDate::~ordinalDate()
{
}

int ordinalDate::isA(int aType)
    { return ((aType == ordinalDate_E) ||
	      (aType == date_E));
    }

void ordinalDate::printSelf()
{
  printf("ORDINAL_DATE");
  printf("(");
  printf("%d", yearComponent);
  printf(",");
  printf("%d", dayComponent);
  printf(")");
}

/********************************************************************/

/* parenAxis2placement3dListFull */

parenAxis2placement3dListFull::parenAxis2placement3dListFull(){}

parenAxis2placement3dListFull::parenAxis2placement3dListFull(
 std::list<axis2placement3d *> * theListIn)
{
  theList = theListIn;
}

parenAxis2placement3dListFull::~parenAxis2placement3dListFull()
{
  delete theList;
}

int parenAxis2placement3dListFull::isA(int aType)
    { return (aType == parenAxis2placement3dListFull_E); }

void parenAxis2placement3dListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<axis2placement3d *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenBooleanExpressionListFull */

parenBooleanExpressionListFull::parenBooleanExpressionListFull(){}

parenBooleanExpressionListFull::parenBooleanExpressionListFull(
 std::list<booleanExpression *> * theListIn)
{
  theList = theListIn;
}

parenBooleanExpressionListFull::~parenBooleanExpressionListFull()
{
  delete theList;
}

int parenBooleanExpressionListFull::isA(int aType)
    { return (aType == parenBooleanExpressionListFull_E); }

void parenBooleanExpressionListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<booleanExpression *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenBossList */

parenBossList::parenBossList(){}

parenBossList::parenBossList(
 std::list<boss *> * theListIn)
{
  theList = theListIn;
}

int parenBossList::isA(int aType)
    { return (aType == parenBossList_E); }

void parenBossList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<boss *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenBossList::~parenBossList()
{
  delete theList;
}

/********************************************************************/

/* parenBoundedCurveListFull */

parenBoundedCurveListFull::parenBoundedCurveListFull(){}

parenBoundedCurveListFull::parenBoundedCurveListFull(
 std::list<boundedCurve *> * theListIn)
{
  theList = theListIn;
}

parenBoundedCurveListFull::~parenBoundedCurveListFull()
{
  delete theList;
}

int parenBoundedCurveListFull::isA(int aType)
    { return (aType == parenBoundedCurveListFull_E); }

void parenBoundedCurveListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<boundedCurve *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenBoundedSurfaceListFull */

parenBoundedSurfaceListFull::parenBoundedSurfaceListFull(){}

parenBoundedSurfaceListFull::parenBoundedSurfaceListFull(
 std::list<boundedSurface *> * theListIn)
{
  theList = theListIn;
}

parenBoundedSurfaceListFull::~parenBoundedSurfaceListFull()
{
  delete theList;
}

int parenBoundedSurfaceListFull::isA(int aType)
    { return (aType == parenBoundedSurfaceListFull_E); }

void parenBoundedSurfaceListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<boundedSurface *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenCartesianPointList */

parenCartesianPointList::parenCartesianPointList(){}

parenCartesianPointList::parenCartesianPointList(
 std::list<cartesianPoint *> * theListIn)
{
  theList = theListIn;
}

int parenCartesianPointList::isA(int aType)
    { return (aType == parenCartesianPointList_E); }

void parenCartesianPointList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<cartesianPoint *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenCartesianPointList::~parenCartesianPointList()
{
  delete theList;
}

/********************************************************************/

/* parenCartesianPointListFull */

parenCartesianPointListFull::parenCartesianPointListFull(){}

parenCartesianPointListFull::parenCartesianPointListFull(
 std::list<cartesianPoint *> * theListIn)
{
  theList = theListIn;
}

parenCartesianPointListFull::~parenCartesianPointListFull()
{
  delete theList;
}

int parenCartesianPointListFull::isA(int aType)
    { return (aType == parenCartesianPointListFull_E); }

void parenCartesianPointListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<cartesianPoint *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenCircularOffsetList */

parenCircularOffsetList::parenCircularOffsetList(){}

parenCircularOffsetList::parenCircularOffsetList(
 std::list<circularOffset *> * theListIn)
{
  theList = theListIn;
}

int parenCircularOffsetList::isA(int aType)
    { return (aType == parenCircularOffsetList_E); }

void parenCircularOffsetList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<circularOffset *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenCircularOffsetList::~parenCircularOffsetList()
{
  delete theList;
}

/********************************************************************/

/* parenCircularOmitList */

parenCircularOmitList::parenCircularOmitList(){}

parenCircularOmitList::parenCircularOmitList(
 std::list<circularOmit *> * theListIn)
{
  theList = theListIn;
}

int parenCircularOmitList::isA(int aType)
    { return (aType == parenCircularOmitList_E); }

void parenCircularOmitList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<circularOmit *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenCircularOmitList::~parenCircularOmitList()
{
  delete theList;
}

/********************************************************************/

/* parenCompositeCurveSegmentListFull */

parenCompositeCurveSegmentListFull::parenCompositeCurveSegmentListFull(){}

parenCompositeCurveSegmentListFull::parenCompositeCurveSegmentListFull(
 std::list<compositeCurveSegment *> * theListIn)
{
  theList = theListIn;
}

parenCompositeCurveSegmentListFull::~parenCompositeCurveSegmentListFull()
{
  delete theList;
}

int parenCompositeCurveSegmentListFull::isA(int aType)
    { return (aType == parenCompositeCurveSegmentListFull_E); }

void parenCompositeCurveSegmentListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<compositeCurveSegment *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenCompoundFeatureSelectListFull */

parenCompoundFeatureSelectListFull::parenCompoundFeatureSelectListFull(){}

parenCompoundFeatureSelectListFull::parenCompoundFeatureSelectListFull(
 std::list<compoundFeatureSelect *> * theListIn)
{
  theList = theListIn;
}

parenCompoundFeatureSelectListFull::~parenCompoundFeatureSelectListFull()
{
  delete theList;
}

int parenCompoundFeatureSelectListFull::isA(int aType)
    { return (aType == parenCompoundFeatureSelectListFull_E); }

void parenCompoundFeatureSelectListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<compoundFeatureSelect *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenCuttingComponentListFull */

parenCuttingComponentListFull::parenCuttingComponentListFull(){}

parenCuttingComponentListFull::parenCuttingComponentListFull(
 std::list<cuttingComponent *> * theListIn)
{
  theList = theListIn;
}

parenCuttingComponentListFull::~parenCuttingComponentListFull()
{
  delete theList;
}

int parenCuttingComponentListFull::isA(int aType)
    { return (aType == parenCuttingComponentListFull_E); }

void parenCuttingComponentListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<cuttingComponent *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenExecutableList */

parenExecutableList::parenExecutableList(){}

parenExecutableList::parenExecutableList(
 std::list<executable *> * theListIn)
{
  theList = theListIn;
}

int parenExecutableList::isA(int aType)
    { return (aType == parenExecutableList_E); }

void parenExecutableList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<executable *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenExecutableList::~parenExecutableList()
{
  delete theList;
}

/********************************************************************/

/* parenExecutableListFull */

parenExecutableListFull::parenExecutableListFull(){}

parenExecutableListFull::parenExecutableListFull(
 std::list<executable *> * theListIn)
{
  theList = theListIn;
}

parenExecutableListFull::~parenExecutableListFull()
{
  delete theList;
}

int parenExecutableListFull::isA(int aType)
    { return (aType == parenExecutableListFull_E); }

void parenExecutableListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<executable *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenFaceBoundListFull */

parenFaceBoundListFull::parenFaceBoundListFull(){}

parenFaceBoundListFull::parenFaceBoundListFull(
 std::list<faceBound *> * theListIn)
{
  theList = theListIn;
}

parenFaceBoundListFull::~parenFaceBoundListFull()
{
  delete theList;
}

int parenFaceBoundListFull::isA(int aType)
    { return (aType == parenFaceBoundListFull_E); }

void parenFaceBoundListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<faceBound *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenFaceListFull */

parenFaceListFull::parenFaceListFull(){}

parenFaceListFull::parenFaceListFull(
 std::list<face *> * theListIn)
{
  theList = theListIn;
}

parenFaceListFull::~parenFaceListFull()
{
  delete theList;
}

int parenFaceListFull::isA(int aType)
    { return (aType == parenFaceListFull_E); }

void parenFaceListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<face *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenIntegerListFull */

parenIntegerListFull::parenIntegerListFull(){}

parenIntegerListFull::parenIntegerListFull(
 std::list<integer *> * theListIn)
{
  theList = theListIn;
}

parenIntegerListFull::~parenIntegerListFull()
{
  {
    std::list<integer *>::iterator iter;
    for (iter = theList->begin();
         iter != theList->end();
         ++iter)
      {
        delete *iter;
      }
  }
  delete theList;
}

int parenIntegerListFull::isA(int aType)
    { return (aType == parenIntegerListFull_E); }

void parenIntegerListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<integer *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenMachinedSurfaceListFull */

parenMachinedSurfaceListFull::parenMachinedSurfaceListFull(){}

parenMachinedSurfaceListFull::parenMachinedSurfaceListFull(
 std::list<machinedSurface *> * theListIn)
{
  theList = theListIn;
}

parenMachinedSurfaceListFull::~parenMachinedSurfaceListFull()
{
  delete theList;
}

int parenMachinedSurfaceListFull::isA(int aType)
    { return (aType == parenMachinedSurfaceListFull_E); }

void parenMachinedSurfaceListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<machinedSurface *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenMachiningFeatureListFull */

parenMachiningFeatureListFull::parenMachiningFeatureListFull(){}

parenMachiningFeatureListFull::parenMachiningFeatureListFull(
 std::list<machiningFeature *> * theListIn)
{
  theList = theListIn;
}

parenMachiningFeatureListFull::~parenMachiningFeatureListFull()
{
  delete theList;
}

int parenMachiningFeatureListFull::isA(int aType)
    { return (aType == parenMachiningFeatureListFull_E); }

void parenMachiningFeatureListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<machiningFeature *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenMachiningOperationList */

parenMachiningOperationList::parenMachiningOperationList(){}

parenMachiningOperationList::parenMachiningOperationList(
 std::list<machiningOperation *> * theListIn)
{
  theList = theListIn;
}

int parenMachiningOperationList::isA(int aType)
    { return (aType == parenMachiningOperationList_E); }

void parenMachiningOperationList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<machiningOperation *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenMachiningOperationList::~parenMachiningOperationList()
{
  delete theList;
}

/********************************************************************/

/* parenNcVariableListFull */

parenNcVariableListFull::parenNcVariableListFull(){}

parenNcVariableListFull::parenNcVariableListFull(
 std::list<ncVariable *> * theListIn)
{
  theList = theListIn;
}

parenNcVariableListFull::~parenNcVariableListFull()
{
  delete theList;
}

int parenNcVariableListFull::isA(int aType)
    { return (aType == parenNcVariableListFull_E); }

void parenNcVariableListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<ncVariable *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenOrientedEdgeListFull */

parenOrientedEdgeListFull::parenOrientedEdgeListFull(){}

parenOrientedEdgeListFull::parenOrientedEdgeListFull(
 std::list<orientedEdge *> * theListIn)
{
  theList = theListIn;
}

parenOrientedEdgeListFull::~parenOrientedEdgeListFull()
{
  delete theList;
}

int parenOrientedEdgeListFull::isA(int aType)
    { return (aType == parenOrientedEdgeListFull_E); }

void parenOrientedEdgeListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<orientedEdge *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenParenCartesianPointListFullListFull */

parenParenCartesianPointListFullListFull::parenParenCartesianPointListFullListFull(){}

parenParenCartesianPointListFullListFull::parenParenCartesianPointListFullListFull(
 std::list<parenCartesianPointListFull *> * theListIn)
{
  theList = theListIn;
}

parenParenCartesianPointListFullListFull::~parenParenCartesianPointListFullListFull()
{
  {
    std::list<parenCartesianPointListFull *>::iterator iter;
    for (iter = theList->begin();
         iter != theList->end();
         ++iter)
      {
        delete *iter;
      }
  }
  delete theList;
}

int parenParenCartesianPointListFullListFull::isA(int aType)
    { return (aType == parenParenCartesianPointListFullListFull_E); }

void parenParenCartesianPointListFullListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<parenCartesianPointListFull *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenParenRealListFullListFull */

parenParenRealListFullListFull::parenParenRealListFullListFull(){}

parenParenRealListFullListFull::parenParenRealListFullListFull(
 std::list<parenRealListFull *> * theListIn)
{
  theList = theListIn;
}

parenParenRealListFullListFull::~parenParenRealListFullListFull()
{
  {
    std::list<parenRealListFull *>::iterator iter;
    for (iter = theList->begin();
         iter != theList->end();
         ++iter)
      {
        delete *iter;
      }
  }
  delete theList;
}

int parenParenRealListFullListFull::isA(int aType)
    { return (aType == parenParenRealListFullListFull_E); }

void parenParenRealListFullListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<parenRealListFull *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenProcessModelLiszt */

parenProcessModelLiszt::parenProcessModelLiszt(){}

parenProcessModelLiszt::parenProcessModelLiszt(
 std::list<processModel *> * theListIn)
{
  theList = theListIn;
}

parenProcessModelLiszt::~parenProcessModelLiszt()
{
  delete theList;
}

int parenProcessModelLiszt::isA(int aType)
    { return (aType == parenProcessModelLiszt_E); }

void parenProcessModelLiszt::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<processModel *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenPropertyParameterList */

parenPropertyParameterList::parenPropertyParameterList(){}

parenPropertyParameterList::parenPropertyParameterList(
 std::list<propertyParameter *> * theListIn)
{
  theList = theListIn;
}

int parenPropertyParameterList::isA(int aType)
    { return (aType == parenPropertyParameterList_E); }

void parenPropertyParameterList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<propertyParameter *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenPropertyParameterList::~parenPropertyParameterList()
{
  delete theList;
}

/********************************************************************/

/* parenRealListFull */

parenRealListFull::parenRealListFull(){}

parenRealListFull::parenRealListFull(
 std::list<real *> * theListIn)
{
  theList = theListIn;
}

parenRealListFull::~parenRealListFull()
{
  {
    std::list<real *>::iterator iter;
    for (iter = theList->begin();
         iter != theList->end();
         ++iter)
      {
        delete *iter;
      }
  }
  delete theList;
}

int parenRealListFull::isA(int aType)
    { return (aType == parenRealListFull_E); }

void parenRealListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<real *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenRectangularOffsetList */

parenRectangularOffsetList::parenRectangularOffsetList(){}

parenRectangularOffsetList::parenRectangularOffsetList(
 std::list<rectangularOffset *> * theListIn)
{
  theList = theListIn;
}

int parenRectangularOffsetList::isA(int aType)
    { return (aType == parenRectangularOffsetList_E); }

void parenRectangularOffsetList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<rectangularOffset *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenRectangularOffsetList::~parenRectangularOffsetList()
{
  delete theList;
}

/********************************************************************/

/* parenRectangularOmitList */

parenRectangularOmitList::parenRectangularOmitList(){}

parenRectangularOmitList::parenRectangularOmitList(
 std::list<rectangularOmit *> * theListIn)
{
  theList = theListIn;
}

int parenRectangularOmitList::isA(int aType)
    { return (aType == parenRectangularOmitList_E); }

void parenRectangularOmitList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<rectangularOmit *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenRectangularOmitList::~parenRectangularOmitList()
{
  delete theList;
}

/********************************************************************/

/* parenRepresentationItemListFull */

parenRepresentationItemListFull::parenRepresentationItemListFull(){}

parenRepresentationItemListFull::parenRepresentationItemListFull(
 std::list<representationItem *> * theListIn)
{
  theList = theListIn;
}

parenRepresentationItemListFull::~parenRepresentationItemListFull()
{
  delete theList;
}

int parenRepresentationItemListFull::isA(int aType)
    { return (aType == parenRepresentationItemListFull_E); }

void parenRepresentationItemListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<representationItem *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenSetupInstructionList */

parenSetupInstructionList::parenSetupInstructionList(){}

parenSetupInstructionList::parenSetupInstructionList(
 std::list<setupInstruction *> * theListIn)
{
  theList = theListIn;
}

int parenSetupInstructionList::isA(int aType)
    { return (aType == parenSetupInstructionList_E); }

void parenSetupInstructionList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<setupInstruction *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenSetupInstructionList::~parenSetupInstructionList()
{
  delete theList;
}

/********************************************************************/

/* parenSlotEndTypeList */

parenSlotEndTypeList::parenSlotEndTypeList(){}

parenSlotEndTypeList::parenSlotEndTypeList(
 std::list<slotEndType *> * theListIn)
{
  theList = theListIn;
}

int parenSlotEndTypeList::isA(int aType)
    { return (aType == parenSlotEndTypeList_E); }

void parenSlotEndTypeList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<slotEndType *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenSlotEndTypeList::~parenSlotEndTypeList()
{
  delete theList;
}

/********************************************************************/

/* parenSpecificationUsageConstraintList */

parenSpecificationUsageConstraintList::parenSpecificationUsageConstraintList(){}

parenSpecificationUsageConstraintList::parenSpecificationUsageConstraintList(
 std::list<specificationUsageConstraint *> * theListIn)
{
  theList = theListIn;
}

int parenSpecificationUsageConstraintList::isA(int aType)
    { return (aType == parenSpecificationUsageConstraintList_E); }

void parenSpecificationUsageConstraintList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<specificationUsageConstraint *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenSpecificationUsageConstraintList::~parenSpecificationUsageConstraintList()
{
  delete theList;
}

/********************************************************************/

/* parenStringList */

parenStringList::parenStringList(){}

parenStringList::parenStringList(
 std::list<char *> * theListIn)
{
  theList = theListIn;
}

int parenStringList::isA(int aType)
    { return (aType == parenStringList_E); }

void parenStringList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<char *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          printString(*iter);
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenStringList::~parenStringList()
{
  {
    std::list<char *>::iterator iter;
    for (iter = theList->begin();
         iter != theList->end();
         ++iter)
      {
        delete *iter;
      }
  }
  delete theList;
}

/********************************************************************/

/* parenStringListFull */

parenStringListFull::parenStringListFull(){}

parenStringListFull::parenStringListFull(
 std::list<char *> * theListIn)
{
  theList = theListIn;
}

parenStringListFull::~parenStringListFull()
{
  {
    std::list<char *>::iterator iter;
    for (iter = theList->begin();
         iter != theList->end();
         ++iter)
      {
        delete *iter;
      }
  }
  delete theList;
}

int parenStringListFull::isA(int aType)
    { return (aType == parenStringListFull_E); }

void parenStringListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<char *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          printString(*iter);
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenToolpathLisztFull */

parenToolpathLisztFull::parenToolpathLisztFull(){}

parenToolpathLisztFull::parenToolpathLisztFull(
 std::list<toolpath *> * theListIn)
{
  theList = theListIn;
}

parenToolpathLisztFull::~parenToolpathLisztFull()
{
  delete theList;
}

int parenToolpathLisztFull::isA(int aType)
    { return (aType == parenToolpathLisztFull_E); }

void parenToolpathLisztFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<toolpath *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (dynamic_cast<instance *>(*iter))->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenTrimmingSelectListFull */

parenTrimmingSelectListFull::parenTrimmingSelectListFull(){}

parenTrimmingSelectListFull::parenTrimmingSelectListFull(
 std::list<trimmingSelect *> * theListIn)
{
  theList = theListIn;
}

parenTrimmingSelectListFull::~parenTrimmingSelectListFull()
{
  delete theList;
}

int parenTrimmingSelectListFull::isA(int aType)
    { return (aType == parenTrimmingSelectListFull_E); }

void parenTrimmingSelectListFull::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<trimmingSelect *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

/********************************************************************/

/* parenWorkpieceList */

parenWorkpieceList::parenWorkpieceList(){}

parenWorkpieceList::parenWorkpieceList(
 std::list<workpiece *> * theListIn)
{
  theList = theListIn;
}

int parenWorkpieceList::isA(int aType)
    { return (aType == parenWorkpieceList_E); }

void parenWorkpieceList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<workpiece *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenWorkpieceList::~parenWorkpieceList()
{
  delete theList;
}

/********************************************************************/

/* parenWorkpieceSetupList */

parenWorkpieceSetupList::parenWorkpieceSetupList(){}

parenWorkpieceSetupList::parenWorkpieceSetupList(
 std::list<workpieceSetup *> * theListIn)
{
  theList = theListIn;
}

int parenWorkpieceSetupList::isA(int aType)
    { return (aType == parenWorkpieceSetupList_E); }

void parenWorkpieceSetupList::printSelf()
{
  printf("(");
  if (theList->begin() != theList->end())
    {
      std::list<workpieceSetup *>::iterator iter;
      for (iter = theList->begin(); ; )
        {
          (*iter)->iId->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenWorkpieceSetupList::~parenWorkpieceSetupList()
{
  delete theList;
}

/********************************************************************/

/* partialAreaDefinition */

partialAreaDefinition::partialAreaDefinition(){}

partialAreaDefinition::partialAreaDefinition(
 double effectiveLengthIn,
 axis2placement3d * placementIn,
 real * maximumLengthIn)
{
  effectiveLength = effectiveLengthIn;
  placement = placementIn;
  maximumLength = maximumLengthIn;
}

partialAreaDefinition::~partialAreaDefinition()
{
  delete maximumLength;
}

int partialAreaDefinition::isA(int aType)
    { return (aType == partialAreaDefinition_E); }

void partialAreaDefinition::printSelf()
{
  printf("PARTIAL_AREA_DEFINITION");
  printf("(");
  printDouble(effectiveLength);
  printf(",");
  placement->iId->printSelf();
  printf(",");
  if (maximumLength)
    maximumLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* pathmodeType */

pathmodeType::pathmodeType(){}


pathmodeType::~pathmodeType(){}

int pathmodeType::isA(int aType)
    { return (aType == pathmodeType_E); }

/********************************************************************/

/* pathmodeTypeForward */

pathmodeTypeForward::pathmodeTypeForward(){}


pathmodeTypeForward::~pathmodeTypeForward()
{
}

int pathmodeTypeForward::isA(int aType)
    { return ((aType == pathmodeTypeForward_E) ||
	      (aType == pathmodeType_E));
    }

void pathmodeTypeForward::printSelf()
{
  printf(".FORWARD.");
}

/********************************************************************/

/* pathmodeTypeZigzag */

pathmodeTypeZigzag::pathmodeTypeZigzag(){}


pathmodeTypeZigzag::~pathmodeTypeZigzag()
{
}

int pathmodeTypeZigzag::isA(int aType)
    { return ((aType == pathmodeTypeZigzag_E) ||
	      (aType == pathmodeType_E));
    }

void pathmodeTypeZigzag::printSelf()
{
  printf(".ZIGZAG.");
}

/********************************************************************/

/* person */

person::person(){}

person::person(
 char * idIn,
 aString * lastNameIn,
 aString * firstNameIn,
 parenStringListFull * middleNamesIn,
 parenStringListFull * prefixTitlesIn,
 parenStringListFull * suffixTitlesIn)
{
  id = idIn;
  lastName = lastNameIn;
  firstName = firstNameIn;
  middleNames = middleNamesIn;
  prefixTitles = prefixTitlesIn;
  suffixTitles = suffixTitlesIn;
}

person::~person()
{
  delete id;
  delete lastName;
  delete firstName;
  delete middleNames;
  delete prefixTitles;
  delete suffixTitles;
}

int person::isA(int aType)
    { return (aType == person_E); }

void person::printSelf()
{
  printf("PERSON");
  printf("(");
  printString(id);
  printf(",");
  if (lastName)
    lastName->printSelf();
  else
    printf("$");
  printf(",");
  if (firstName)
    firstName->printSelf();
  else
    printf("$");
  printf(",");
  if (middleNames)
    middleNames->printSelf();
  else
    printf("$");
  printf(",");
  if (prefixTitles)
    prefixTitles->printSelf();
  else
    printf("$");
  printf(",");
  if (suffixTitles)
    suffixTitles->printSelf();
  else
    printf("$");
  printf(",");
  printf(")");
}

/********************************************************************/

/* personAndAddress */

personAndAddress::personAndAddress(){}

personAndAddress::personAndAddress(
 person * itsPersonIn,
 address * itsAddressIn)
{
  itsPerson = itsPersonIn;
  itsAddress = itsAddressIn;
}

personAndAddress::~personAndAddress()
{
}

int personAndAddress::isA(int aType)
    { return (aType == personAndAddress_E); }

void personAndAddress::printSelf()
{
  printf("PERSON_AND_ADDRESS");
  printf("(");
  itsPerson->iId->printSelf();
  printf(",");
  if (itsAddress)
    itsAddress->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* planeCcStrategy */

planeCcStrategy::planeCcStrategy(){}

planeCcStrategy::planeCcStrategy(
 pathmodeType * pathmodeIn,
 cutmodeType * cutmodeIn,
 tolerances * itsMillingTolerancesIn,
 real * stepoverIn,
 direction * itsPlaneNormalIn) :
   freeformStrategy(
     pathmodeIn,
     cutmodeIn,
     itsMillingTolerancesIn,
     stepoverIn)
{
   itsPlaneNormal = itsPlaneNormalIn;
}

planeCcStrategy::~planeCcStrategy()
{
  delete pathmode;
  delete cutmode;
  delete stepover;
}

int planeCcStrategy::isA(int aType)
    { return ((aType == planeCcStrategy_E) ||
	      (aType == freeformStrategy_E));
    }

void planeCcStrategy::printSelf()
{
  printf("PLANE_CC_STRATEGY");
  printf("(");
  pathmode->printSelf();
  printf(",");
  cutmode->printSelf();
  printf(",");
  itsMillingTolerances->iId->printSelf();
  printf(",");
  if (stepover)
    stepover->printSelf();
  else
    printf("$");
  printf(",");
  itsPlaneNormal->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* planeClStrategy */

planeClStrategy::planeClStrategy(){}

planeClStrategy::planeClStrategy(
 pathmodeType * pathmodeIn,
 cutmodeType * cutmodeIn,
 tolerances * itsMillingTolerancesIn,
 real * stepoverIn,
 direction * itsPlaneNormalIn) :
   freeformStrategy(
     pathmodeIn,
     cutmodeIn,
     itsMillingTolerancesIn,
     stepoverIn)
{
   itsPlaneNormal = itsPlaneNormalIn;
}

planeClStrategy::~planeClStrategy()
{
  delete pathmode;
  delete cutmode;
  delete stepover;
}

int planeClStrategy::isA(int aType)
    { return ((aType == planeClStrategy_E) ||
	      (aType == freeformStrategy_E));
    }

void planeClStrategy::printSelf()
{
  printf("PLANE_CL_STRATEGY");
  printf("(");
  pathmode->printSelf();
  printf(",");
  cutmode->printSelf();
  printf(",");
  itsMillingTolerances->iId->printSelf();
  printf(",");
  if (stepover)
    stepover->printSelf();
  else
    printf("$");
  printf(",");
  itsPlaneNormal->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* plungeStrategy */

plungeStrategy::plungeStrategy(){}

plungeStrategy::plungeStrategy(
 direction * toolOrientationIn) :
   approachRetractStrategy(
     toolOrientationIn)
    {}

plungeStrategy::~plungeStrategy(){}

int plungeStrategy::isA(int aType)
    { return ((aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }

/********************************************************************/

/* plungeHelix */

plungeHelix::plungeHelix(){}

plungeHelix::plungeHelix(
 direction * toolOrientationIn,
 double radiusIn,
 double angleIn) :
   plungeStrategy(
     toolOrientationIn)
{
   radius = radiusIn;
   angle = angleIn;
}

plungeHelix::~plungeHelix()
{
}

int plungeHelix::isA(int aType)
    { return ((aType == plungeHelix_E) ||
	      (aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }

void plungeHelix::printSelf()
{
  printf("PLUNGE_HELIX");
  printf("(");
  if (toolOrientation)
    toolOrientation->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(radius);
  printf(",");
  printDouble(angle);
  printf(")");
}

/********************************************************************/

/* plungeRamp */

plungeRamp::plungeRamp(){}

plungeRamp::plungeRamp(
 direction * toolOrientationIn,
 double angleIn) :
   plungeStrategy(
     toolOrientationIn)
{
   angle = angleIn;
}

plungeRamp::~plungeRamp()
{
}

int plungeRamp::isA(int aType)
    { return ((aType == plungeRamp_E) ||
	      (aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }

void plungeRamp::printSelf()
{
  printf("PLUNGE_RAMP");
  printf("(");
  if (toolOrientation)
    toolOrientation->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(")");
}

/********************************************************************/

/* plungeToolaxis */

plungeToolaxis::plungeToolaxis(){}

plungeToolaxis::plungeToolaxis(
 direction * toolOrientationIn) :
   plungeStrategy(
     toolOrientationIn)
    {}

plungeToolaxis::~plungeToolaxis()
{
}

int plungeToolaxis::isA(int aType)
    { return ((aType == plungeToolaxis_E) ||
	      (aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }

void plungeToolaxis::printSelf()
{
  printf("PLUNGE_TOOLAXIS");
  printf("(");
  if (toolOrientation)
    toolOrientation->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* plungeZigzag */

plungeZigzag::plungeZigzag(){}

plungeZigzag::plungeZigzag(
 direction * toolOrientationIn,
 double angleIn,
 double widthIn) :
   plungeStrategy(
     toolOrientationIn)
{
   angle = angleIn;
   width = widthIn;
}

plungeZigzag::~plungeZigzag()
{
}

int plungeZigzag::isA(int aType)
    { return ((aType == plungeZigzag_E) ||
	      (aType == plungeStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }

void plungeZigzag::printSelf()
{
  printf("PLUNGE_ZIGZAG");
  printf("(");
  if (toolOrientation)
    toolOrientation->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(",");
  printDouble(width);
  printf(")");
}

/********************************************************************/

/* pocketBottomCondition */

pocketBottomCondition::pocketBottomCondition(){}


pocketBottomCondition::~pocketBottomCondition(){}

int pocketBottomCondition::isA(int aType)
    { return (aType == pocketBottomCondition_E); }

/********************************************************************/

/* processModel */

processModel::processModel(){}

processModel::processModel(
 char * iniDataFileIn,
 char * itsTypeIn)
{
  iniDataFile = iniDataFileIn;
  itsType = itsTypeIn;
}

processModel::~processModel()
{
  delete iniDataFile;
  delete itsType;
}

int processModel::isA(int aType)
    { return (aType == processModel_E); }

void processModel::printSelf()
{
  printf("PROCESS_MODEL");
  printf("(");
  printString(iniDataFile);
  printf(",");
  printString(itsType);
  printf(")");
}

/********************************************************************/

/* processModelList */

processModelList::processModelList(){}

processModelList::processModelList(
 parenProcessModelLiszt * itsListIn)
{
  itsList = itsListIn;
}

processModelList::~processModelList()
{
  delete itsList;
}

int processModelList::isA(int aType)
    { return (aType == processModelList_E); }

void processModelList::printSelf()
{
  printf("PROCESS_MODEL_LIST");
  printf("(");
  itsList->printSelf();
  printf(")");
}

/********************************************************************/

/* profile */

profile::profile(){}

profile::profile(
 axis2placement3d * placementIn)
{
  placement = placementIn;
}

profile::~profile(){}

int profile::isA(int aType)
    { return (aType == profile_E); }

/********************************************************************/

/* profileSelect */

profileSelect::profileSelect(){}


profileSelect::~profileSelect(){}

int profileSelect::isA(int aType)
    { return (aType == profileSelect_E); }

/********************************************************************/

/* programStructure */

programStructure::programStructure(){}

programStructure::programStructure(
 char * itsIdIn) :
   executable(
     itsIdIn)
    {}

programStructure::~programStructure(){}

int programStructure::isA(int aType)
    { return ((aType == programStructure_E) ||
	      (aType == executable_E));
    }

/********************************************************************/

/* programStop */

programStop::programStop(){}

programStop::programStop(
 char * itsIdIn) :
   ncFunction(
     itsIdIn)
    {}

programStop::~programStop()
{
  delete itsId;
}

int programStop::isA(int aType)
    { return ((aType == programStop_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void programStop::printSelf()
{
  printf("PROGRAM_STOP");
  printf("(");
  printString(itsId);
  printf(")");
}

/********************************************************************/

/* project */

project::project(){}

project::project(
 char * itsIdIn,
 workplan * mainWorkplanIn,
 parenWorkpieceList * itsWorkpiecesIn,
 personAndAddress * itsOwnerIn,
 dateAndTime * itsReleaseIn,
 approval * itsStatusIn)
{
  itsId = itsIdIn;
  mainWorkplan = mainWorkplanIn;
  itsWorkpieces = itsWorkpiecesIn;
  itsOwner = itsOwnerIn;
  itsRelease = itsReleaseIn;
  itsStatus = itsStatusIn;
}

project::~project()
{
  delete itsId;
  delete itsWorkpieces;
}

int project::isA(int aType)
    { return (aType == project_E); }

void project::printSelf()
{
  printf("PROJECT");
  printf("(");
  printString(itsId);
  printf(",");
  mainWorkplan->iId->printSelf();
  printf(",");
  itsWorkpieces->printSelf();
  printf(",");
  if (itsOwner)
    itsOwner->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsRelease)
    itsRelease->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsStatus)
    itsStatus->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* propertyParameter */

propertyParameter::propertyParameter(){}

propertyParameter::propertyParameter(
 char * parameterNameIn)
{
  parameterName = parameterNameIn;
}

propertyParameter::~propertyParameter(){}

int propertyParameter::isA(int aType)
    { return (aType == propertyParameter_E); }

/********************************************************************/

/* radiusedPocketBottomCondition */

radiusedPocketBottomCondition::radiusedPocketBottomCondition(){}

radiusedPocketBottomCondition::radiusedPocketBottomCondition(
 cartesianPoint * floorRadiusCenterIn,
 tolerancedLengthMeasure * floorRadiusIn)
{
  floorRadiusCenter = floorRadiusCenterIn;
  floorRadius = floorRadiusIn;
}

radiusedPocketBottomCondition::~radiusedPocketBottomCondition()
{
}

int radiusedPocketBottomCondition::isA(int aType)
    { return ((aType == radiusedPocketBottomCondition_E) ||
	      (aType == pocketBottomCondition_E));
    }

void radiusedPocketBottomCondition::printSelf()
{
  printf("RADIUSED_POCKET_BOTTOM_CONDITION");
  printf("(");
  floorRadiusCenter->iId->printSelf();
  printf(",");
  floorRadius->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* rectangularOffset */

rectangularOffset::rectangularOffset(){}

rectangularOffset::rectangularOffset(
 direction * offsetDirectionIn,
 double offsetDistanceIn,
 int rowIndexIn,
 int columnIndexIn)
{
  offsetDirection = offsetDirectionIn;
  offsetDistance = offsetDistanceIn;
  rowIndex = rowIndexIn;
  columnIndex = columnIndexIn;
}

rectangularOffset::~rectangularOffset()
{
}

int rectangularOffset::isA(int aType)
    { return (aType == rectangularOffset_E); }

void rectangularOffset::printSelf()
{
  printf("RECTANGULAR_OFFSET");
  printf("(");
  offsetDirection->iId->printSelf();
  printf(",");
  printDouble(offsetDistance);
  printf(",");
  printf("%d", rowIndex);
  printf(",");
  printf("%d", columnIndex);
  printf(")");
}

/********************************************************************/

/* rectangularOmit */

rectangularOmit::rectangularOmit(){}

rectangularOmit::rectangularOmit(
 int rowIndexIn,
 int columnIndexIn)
{
  rowIndex = rowIndexIn;
  columnIndex = columnIndexIn;
}

rectangularOmit::~rectangularOmit()
{
}

int rectangularOmit::isA(int aType)
    { return (aType == rectangularOmit_E); }

void rectangularOmit::printSelf()
{
  printf("RECTANGULAROMIT");
  printf("(");
  printf("%d", rowIndex);
  printf(",");
  printf("%d", columnIndex);
  printf(")");
}

/********************************************************************/

/* region */

region::region(){}

region::region(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn) :
   manufacturingFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn)
{
   featurePlacement = featurePlacementIn;
}

region::~region(){}

int region::isA(int aType)
    { return ((aType == region_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* regionProjection */

regionProjection::regionProjection(){}

regionProjection::regionProjection(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 boundedCurve * projCurveIn,
 direction * projDirIn,
 tolerancedLengthMeasure * depthIn) :
   region(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn)
{
   projCurve = projCurveIn;
   projDir = projDirIn;
   depth = depthIn;
}

regionProjection::~regionProjection()
{
  delete itsId;
  delete itsOperations;
}

int regionProjection::isA(int aType)
    { return ((aType == regionProjection_E) ||
	      (aType == region_E) ||
	      (aType == manufacturingFeature_E));
    }

void regionProjection::printSelf()
{
  printf("REGION_PROJECTION");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  if (featurePlacement)
    featurePlacement->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(projCurve))->iId->printSelf();
  printf(",");
  projDir->iId->printSelf();
  printf(",");
  depth->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* regionSurfaceList */

regionSurfaceList::regionSurfaceList(){}

regionSurfaceList::regionSurfaceList(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 parenBoundedSurfaceListFull * surfaceListIn) :
   region(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn)
{
   surfaceList = surfaceListIn;
}

regionSurfaceList::~regionSurfaceList()
{
  delete itsId;
  delete itsOperations;
  delete surfaceList;
}

int regionSurfaceList::isA(int aType)
    { return ((aType == regionSurfaceList_E) ||
	      (aType == region_E) ||
	      (aType == manufacturingFeature_E));
    }

void regionSurfaceList::printSelf()
{
  printf("REGION_SURFACE_LIST");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  if (featurePlacement)
    featurePlacement->iId->printSelf();
  else
    printf("$");
  printf(",");
  surfaceList->printSelf();
  printf(")");
}

/********************************************************************/

/* representationParent */

representationParent::representationParent(){}

representationParent::representationParent(
 char * nameIn,
 parenRepresentationItemListFull * itemsIn,
 representationContext * contextOfItemsIn)
{
  name = nameIn;
  items = itemsIn;
  contextOfItems = contextOfItemsIn;
}

representationParent::~representationParent(){}

int representationParent::isA(int aType)
    { return (aType == representationParent_E); }

/********************************************************************/

/* representation */

representation::representation(){}

representation::representation(
 char * nameIn,
 parenRepresentationItemListFull * itemsIn,
 representationContext * contextOfItemsIn) :
   representationParent(
     nameIn,
     itemsIn,
     contextOfItemsIn)
    {}

representation::~representation()
{
  delete name;
  delete items;
  delete contextOfItems;
}

int representation::isA(int aType)
    { return ((aType == representation_E) ||
	      (aType == representationParent_E));
    }

void representation::printSelf()
{
  printf("REPRESENTATION");
  printf("(");
  printString(name);
  printf(",");
  items->printSelf();
  printf(",");
  contextOfItems->printSelf();
  printf(")");
}

/********************************************************************/

/* representationContext */

representationContext::representationContext(){}

representationContext::representationContext(
 char * contextIdentifierIn,
 char * contextTypeIn)
{
  contextIdentifier = contextIdentifierIn;
  contextType = contextTypeIn;
}

representationContext::~representationContext()
{
  delete contextIdentifier;
  delete contextType;
}

int representationContext::isA(int aType)
    { return (aType == representationContext_E); }

void representationContext::printSelf()
{
  printf("REPRESENTATIONCONTEXT");
  printf("(");
  printString(contextIdentifier);
  printf(",");
  printString(contextType);
  printf(")");
}

/********************************************************************/

/* representationItem */

representationItem::representationItem(){}

representationItem::representationItem(
 char * nameIn)
{
  name = nameIn;
}

representationItem::~representationItem(){}

int representationItem::isA(int aType)
    { return (aType == representationItem_E); }

/********************************************************************/

/* restrictedAreaSelect */

restrictedAreaSelect::restrictedAreaSelect(){}


restrictedAreaSelect::~restrictedAreaSelect(){}

int restrictedAreaSelect::isA(int aType)
    { return (aType == restrictedAreaSelect_E); }

/********************************************************************/

/* rotDirection */

rotDirection::rotDirection(){}


rotDirection::~rotDirection(){}

int rotDirection::isA(int aType)
    { return (aType == rotDirection_E); }

/********************************************************************/

/* rotDirectionCw */

rotDirectionCw::rotDirectionCw(){}


rotDirectionCw::~rotDirectionCw()
{
}

int rotDirectionCw::isA(int aType)
    { return ((aType == rotDirectionCw_E) ||
	      (aType == rotDirection_E));
    }

void rotDirectionCw::printSelf()
{
  printf(".CW.");
}

/********************************************************************/

/* rotDirectionCcw */

rotDirectionCcw::rotDirectionCcw(){}


rotDirectionCcw::~rotDirectionCcw()
{
}

int rotDirectionCcw::isA(int aType)
    { return ((aType == rotDirectionCcw_E) ||
	      (aType == rotDirection_E));
    }

void rotDirectionCcw::printSelf()
{
  printf(".CCW.");
}

/********************************************************************/

/* rvalue */

rvalue::rvalue(){}


rvalue::~rvalue(){}

int rvalue::isA(int aType)
    { return (aType == rvalue_E); }

/********************************************************************/

/* selective */

selective::selective(){}

selective::selective(
 char * itsIdIn,
 parenExecutableListFull * itsElementsIn) :
   programStructure(
     itsIdIn)
{
   itsElements = itsElementsIn;
}

selective::~selective()
{
  delete itsId;
  delete itsElements;
}

int selective::isA(int aType)
    { return ((aType == selective_E) ||
	      (aType == programStructure_E) ||
	      (aType == executable_E));
    }

void selective::printSelf()
{
  printf("SELECTIVE");
  printf("(");
  printString(itsId);
  printf(",");
  itsElements->printSelf();
  printf(")");
}

/********************************************************************/

/* setMark */

setMark::setMark(){}

setMark::setMark(
 char * itsIdIn) :
   ncFunction(
     itsIdIn)
    {}

setMark::~setMark()
{
  delete itsId;
}

int setMark::isA(int aType)
    { return ((aType == setMark_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void setMark::printSelf()
{
  printf("SET_MARK");
  printf("(");
  printString(itsId);
  printf(")");
}

/********************************************************************/

/* setup */

setup::setup(){}

setup::setup(
 char * itsIdIn,
 axis2placement3d * itsOriginIn,
 elementarySurface * itsSecplaneIn,
 parenWorkpieceSetupList * itsWorkpieceSetupIn)
{
  itsId = itsIdIn;
  itsOrigin = itsOriginIn;
  itsSecplane = itsSecplaneIn;
  itsWorkpieceSetup = itsWorkpieceSetupIn;
}

setup::~setup()
{
  delete itsId;
  delete itsWorkpieceSetup;
}

int setup::isA(int aType)
    { return (aType == setup_E); }

void setup::printSelf()
{
  printf("SETUP");
  printf("(");
  printString(itsId);
  printf(",");
  if (itsOrigin)
    itsOrigin->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsSecplane))->iId->printSelf();
  printf(",");
  itsWorkpieceSetup->printSelf();
  printf(")");
}

/********************************************************************/

/* setupInstruction */

setupInstruction::setupInstruction(){}

setupInstruction::setupInstruction(
 aString * descriptionIn,
 aString * externalDocumentIn)
{
  description = descriptionIn;
  externalDocument = externalDocumentIn;
}

setupInstruction::~setupInstruction()
{
  delete description;
  delete externalDocument;
}

int setupInstruction::isA(int aType)
    { return (aType == setupInstruction_E); }

void setupInstruction::printSelf()
{
  printf("SETUP_INSTRUCTION");
  printf("(");
  if (description)
    description->printSelf();
  else
    printf("$");
  printf(",");
  if (externalDocument)
    externalDocument->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* shapeRepresentationParent */

shapeRepresentationParent::shapeRepresentationParent(){}

shapeRepresentationParent::shapeRepresentationParent(
 char * nameIn,
 parenRepresentationItemListFull * itemsIn,
 representationContext * contextOfItemsIn) :
   representationParent(
     nameIn,
     itemsIn,
     contextOfItemsIn)
    {}

shapeRepresentationParent::~shapeRepresentationParent(){}

int shapeRepresentationParent::isA(int aType)
    { return ((aType == shapeRepresentationParent_E) ||
	      (aType == representationParent_E));
    }

/********************************************************************/

/* shapeRepresentation */

shapeRepresentation::shapeRepresentation(){}

shapeRepresentation::shapeRepresentation(
 char * nameIn,
 parenRepresentationItemListFull * itemsIn,
 representationContext * contextOfItemsIn) :
   shapeRepresentationParent(
     nameIn,
     itemsIn,
     contextOfItemsIn)
    {}

shapeRepresentation::~shapeRepresentation()
{
  delete name;
  delete items;
  delete contextOfItems;
}

int shapeRepresentation::isA(int aType)
    { return ((aType == shapeRepresentation_E) ||
	      (aType == shapeRepresentationParent_E) ||
	      (aType == representationParent_E));
    }

void shapeRepresentation::printSelf()
{
  printf("SHAPE_REPRESENTATION");
  printf("(");
  printString(name);
  printf(",");
  items->printSelf();
  printf(",");
  contextOfItems->printSelf();
  printf(")");
}

/********************************************************************/

/* slotEndType */

slotEndType::slotEndType(){}


slotEndType::~slotEndType(){}

int slotEndType::isA(int aType)
    { return (aType == slotEndType_E); }

/********************************************************************/

/* specification */

specification::specification(){}

specification::specification(
 parenSpecificationUsageConstraintList * constraintIn,
 char * specificationIdIn,
 aString * specificationDescriptionIn,
 aString * specificationClassIn)
{
  constraint = constraintIn;
  specificationId = specificationIdIn;
  specificationDescription = specificationDescriptionIn;
  specificationClass = specificationClassIn;
}

specification::~specification()
{
  delete constraint;
  delete specificationId;
  delete specificationDescription;
  delete specificationClass;
}

int specification::isA(int aType)
    { return (aType == specification_E); }

void specification::printSelf()
{
  printf("SPECIFICATION");
  printf("(");
  constraint->printSelf();
  printf(",");
  printString(specificationId);
  printf(",");
  if (specificationDescription)
    specificationDescription->printSelf();
  else
    printf("$");
  printf(",");
  if (specificationClass)
    specificationClass->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* specificationUsageConstraint */

specificationUsageConstraint::specificationUsageConstraint(){}

specificationUsageConstraint::specificationUsageConstraint(
 char * elementIn,
 char * classIdIn)
{
  element = elementIn;
  classId = classIdIn;
}

specificationUsageConstraint::~specificationUsageConstraint()
{
  delete element;
  delete classId;
}

int specificationUsageConstraint::isA(int aType)
    { return (aType == specificationUsageConstraint_E); }

void specificationUsageConstraint::printSelf()
{
  printf("SPECIFICATION_USAGE_CONSTRAINT");
  printf("(");
  printf(",");
  printString(element);
  printf(",");
  printString(classId);
  printf(")");
}

/********************************************************************/

/* strokeConnectionStrategy */

strokeConnectionStrategy::strokeConnectionStrategy(){}


strokeConnectionStrategy::~strokeConnectionStrategy(){}

int strokeConnectionStrategy::isA(int aType)
    { return (aType == strokeConnectionStrategy_E); }

/********************************************************************/

/* strokeConnectionStrategyDegouge */

strokeConnectionStrategyDegouge::strokeConnectionStrategyDegouge(){}


strokeConnectionStrategyDegouge::~strokeConnectionStrategyDegouge()
{
}

int strokeConnectionStrategyDegouge::isA(int aType)
    { return ((aType == strokeConnectionStrategyDegouge_E) ||
	      (aType == strokeConnectionStrategy_E));
    }

void strokeConnectionStrategyDegouge::printSelf()
{
  printf(".DEGOUGE.");
}

/********************************************************************/

/* strokeConnectionStrategyLiftShiftPlunge */

strokeConnectionStrategyLiftShiftPlunge::strokeConnectionStrategyLiftShiftPlunge(){}


strokeConnectionStrategyLiftShiftPlunge::~strokeConnectionStrategyLiftShiftPlunge()
{
}

int strokeConnectionStrategyLiftShiftPlunge::isA(int aType)
    { return ((aType == strokeConnectionStrategyLiftShiftPlunge_E) ||
	      (aType == strokeConnectionStrategy_E));
    }

void strokeConnectionStrategyLiftShiftPlunge::printSelf()
{
  printf(".LIFT_SHIFT_PLUNGE.");
}

/********************************************************************/

/* strokeConnectionStrategyLoopBack */

strokeConnectionStrategyLoopBack::strokeConnectionStrategyLoopBack(){}


strokeConnectionStrategyLoopBack::~strokeConnectionStrategyLoopBack()
{
}

int strokeConnectionStrategyLoopBack::isA(int aType)
    { return ((aType == strokeConnectionStrategyLoopBack_E) ||
	      (aType == strokeConnectionStrategy_E));
    }

void strokeConnectionStrategyLoopBack::printSelf()
{
  printf(".LOOP_BACK.");
}

/********************************************************************/

/* strokeConnectionStrategyStraightline */

strokeConnectionStrategyStraightline::strokeConnectionStrategyStraightline(){}


strokeConnectionStrategyStraightline::~strokeConnectionStrategyStraightline()
{
}

int strokeConnectionStrategyStraightline::isA(int aType)
    { return ((aType == strokeConnectionStrategyStraightline_E) ||
	      (aType == strokeConnectionStrategy_E));
    }

void strokeConnectionStrategyStraightline::printSelf()
{
  printf(".STRAIGHTLINE.");
}

/********************************************************************/

/* surfaceTextureParameter */

surfaceTextureParameter::surfaceTextureParameter(){}

surfaceTextureParameter::surfaceTextureParameter(
 double itsValueIn,
 char * parameterNameIn,
 char * measuringMethodIn,
 aString * parameterIndexIn,
 parenMachinedSurfaceListFull * appliedSurfacesIn)
{
  itsValue = itsValueIn;
  parameterName = parameterNameIn;
  measuringMethod = measuringMethodIn;
  parameterIndex = parameterIndexIn;
  appliedSurfaces = appliedSurfacesIn;
}

surfaceTextureParameter::~surfaceTextureParameter()
{
  delete parameterName;
  delete measuringMethod;
  delete parameterIndex;
  delete appliedSurfaces;
}

int surfaceTextureParameter::isA(int aType)
    { return (aType == surfaceTextureParameter_E); }

void surfaceTextureParameter::printSelf()
{
  printf("SURFACE_TEXTURE_PARAMETER");
  printf("(");
  printDouble(itsValue);
  printf(",");
  printString(parameterName);
  printf(",");
  printString(measuringMethod);
  printf(",");
  if (parameterIndex)
    parameterIndex->printSelf();
  else
    printf("$");
  printf(",");
  appliedSurfaces->printSelf();
  printf(")");
}

/********************************************************************/

/* taperSelect */

taperSelect::taperSelect(){}


taperSelect::~taperSelect(){}

int taperSelect::isA(int aType)
    { return (aType == taperSelect_E); }

/********************************************************************/

/* technology */

technology::technology(){}

technology::technology(
 real * feedrateIn,
 toolReferencePoint * feedrateReferenceIn)
{
  feedrate = feedrateIn;
  feedrateReference = feedrateReferenceIn;
}

technology::~technology(){}

int technology::isA(int aType)
    { return (aType == technology_E); }

/********************************************************************/

/* throughBottomCondition */

throughBottomCondition::throughBottomCondition(){}


throughBottomCondition::~throughBottomCondition()
{
}

int throughBottomCondition::isA(int aType)
    { return ((aType == throughBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }

void throughBottomCondition::printSelf()
{
  printf("THROUGH_BOTTOM_CONDITION");
  printf("(");
  printf(")");
}

/********************************************************************/

/* throughPocketBottomCondition */

throughPocketBottomCondition::throughPocketBottomCondition(){}


throughPocketBottomCondition::~throughPocketBottomCondition()
{
}

int throughPocketBottomCondition::isA(int aType)
    { return ((aType == throughPocketBottomCondition_E) ||
	      (aType == pocketBottomCondition_E));
    }

void throughPocketBottomCondition::printSelf()
{
  printf("THROUGH_POCKET_BOTTOM_CONDITION");
  printf("(");
  printf(")");
}

/********************************************************************/

/* throughProfileFloor */

throughProfileFloor::throughProfileFloor(){}


throughProfileFloor::~throughProfileFloor()
{
}

int throughProfileFloor::isA(int aType)
    { return ((aType == throughProfileFloor_E) ||
	      (aType == profileSelect_E));
    }

void throughProfileFloor::printSelf()
{
  printf("THROUGH_PROFILE_FLOOR");
  printf("(");
  printf(")");
}

/********************************************************************/

/* tolerancedLengthMeasure */

tolerancedLengthMeasure::tolerancedLengthMeasure(){}

tolerancedLengthMeasure::tolerancedLengthMeasure(
 double theoreticalSizeIn,
 plusMinusValue * implicitToleranceIn)
{
  theoreticalSize = theoreticalSizeIn;
  implicitTolerance = implicitToleranceIn;
}

tolerancedLengthMeasure::~tolerancedLengthMeasure()
{
}

int tolerancedLengthMeasure::isA(int aType)
    { return (aType == tolerancedLengthMeasure_E); }

void tolerancedLengthMeasure::printSelf()
{
  printf("TOLERANCED_LENGTH_MEASURE");
  printf("(");
  printDouble(theoreticalSize);
  printf(",");
  implicitTolerance->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* tolerances */

tolerances::tolerances(){}

tolerances::tolerances(
 double chordalToleranceIn,
 double scallopHeightIn)
{
  chordalTolerance = chordalToleranceIn;
  scallopHeight = scallopHeightIn;
}

tolerances::~tolerances()
{
}

int tolerances::isA(int aType)
    { return (aType == tolerances_E); }

void tolerances::printSelf()
{
  printf("TOLERANCES");
  printf("(");
  printDouble(chordalTolerance);
  printf(",");
  printDouble(scallopHeight);
  printf(")");
}

/********************************************************************/

/* toleranceSelect */

toleranceSelect::toleranceSelect(){}


toleranceSelect::~toleranceSelect(){}

int toleranceSelect::isA(int aType)
    { return (aType == toleranceSelect_E); }

/********************************************************************/

/* toolBody */

toolBody::toolBody(){}


toolBody::~toolBody(){}

int toolBody::isA(int aType)
    { return (aType == toolBody_E); }

/********************************************************************/

/* toolDirection */

toolDirection::toolDirection(){}


toolDirection::~toolDirection(){}

int toolDirection::isA(int aType)
    { return (aType == toolDirection_E); }

/********************************************************************/

/* toolDirectionForMilling */

toolDirectionForMilling::toolDirectionForMilling(){}


toolDirectionForMilling::~toolDirectionForMilling(){}

int toolDirectionForMilling::isA(int aType)
    { return (aType == toolDirectionForMilling_E); }

/********************************************************************/

/* toolpath */

toolpath::toolpath(){}

toolpath::toolpath(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn)
{
  itsPriority = itsPriorityIn;
  itsType = itsTypeIn;
  itsSpeed = itsSpeedIn;
  itsTechnology = itsTechnologyIn;
  itsMachineFunctions = itsMachineFunctionsIn;
}

toolpath::~toolpath(){}

int toolpath::isA(int aType)
    { return (aType == toolpath_E); }

/********************************************************************/

/* toolpathList */

toolpathList::toolpathList(){}

toolpathList::toolpathList(
 parenToolpathLisztFull * itsListIn)
{
  itsList = itsListIn;
}

toolpathList::~toolpathList()
{
  delete itsList;
}

int toolpathList::isA(int aType)
    { return (aType == toolpathList_E); }

void toolpathList::printSelf()
{
  printf("TOOLPATH_LIST");
  printf("(");
  itsList->printSelf();
  printf(")");
}

/********************************************************************/

/* toolpathSpeedprofile */

toolpathSpeedprofile::toolpathSpeedprofile(){}


toolpathSpeedprofile::~toolpathSpeedprofile(){}

int toolpathSpeedprofile::isA(int aType)
    { return (aType == toolpathSpeedprofile_E); }

void toolpathSpeedprofile::printSelf()
{
  if (this->isA(real_E))
    (dynamic_cast<real *>(this))->printSelf();
  else if (this->isA(speedName_E))
    (dynamic_cast<speedName *>(this))->printSelf();
  else if (this->isA(toolpathSpeed_E))
    (dynamic_cast<instance *>(this))->iId->printSelf();
}

/********************************************************************/

/* toolpathType */

toolpathType::toolpathType(){}


toolpathType::~toolpathType(){}

int toolpathType::isA(int aType)
    { return (aType == toolpathType_E); }

/********************************************************************/

/* toolpathTypeApproach */

toolpathTypeApproach::toolpathTypeApproach(){}


toolpathTypeApproach::~toolpathTypeApproach()
{
}

int toolpathTypeApproach::isA(int aType)
    { return ((aType == toolpathTypeApproach_E) ||
	      (aType == toolpathType_E));
    }

void toolpathTypeApproach::printSelf()
{
  printf(".APPROACH.");
}

/********************************************************************/

/* toolpathTypeConnect */

toolpathTypeConnect::toolpathTypeConnect(){}


toolpathTypeConnect::~toolpathTypeConnect()
{
}

int toolpathTypeConnect::isA(int aType)
    { return ((aType == toolpathTypeConnect_E) ||
	      (aType == toolpathType_E));
    }

void toolpathTypeConnect::printSelf()
{
  printf(".CONNECT.");
}

/********************************************************************/

/* toolpathTypeContact */

toolpathTypeContact::toolpathTypeContact(){}


toolpathTypeContact::~toolpathTypeContact()
{
}

int toolpathTypeContact::isA(int aType)
    { return ((aType == toolpathTypeContact_E) ||
	      (aType == toolpathType_E));
    }

void toolpathTypeContact::printSelf()
{
  printf(".CONTACT.");
}

/********************************************************************/

/* toolpathTypeLift */

toolpathTypeLift::toolpathTypeLift(){}


toolpathTypeLift::~toolpathTypeLift()
{
}

int toolpathTypeLift::isA(int aType)
    { return ((aType == toolpathTypeLift_E) ||
	      (aType == toolpathType_E));
    }

void toolpathTypeLift::printSelf()
{
  printf(".LIFT.");
}

/********************************************************************/

/* toolpathTypeNonContact */

toolpathTypeNonContact::toolpathTypeNonContact(){}


toolpathTypeNonContact::~toolpathTypeNonContact()
{
}

int toolpathTypeNonContact::isA(int aType)
    { return ((aType == toolpathTypeNonContact_E) ||
	      (aType == toolpathType_E));
    }

void toolpathTypeNonContact::printSelf()
{
  printf(".NONCONTACT.");
}

/********************************************************************/

/* toolpathTypeTrajectoryPath */

toolpathTypeTrajectoryPath::toolpathTypeTrajectoryPath(){}


toolpathTypeTrajectoryPath::~toolpathTypeTrajectoryPath()
{
}

int toolpathTypeTrajectoryPath::isA(int aType)
    { return ((aType == toolpathTypeTrajectoryPath_E) ||
	      (aType == toolpathType_E));
    }

void toolpathTypeTrajectoryPath::printSelf()
{
  printf(".TRAJECTORY_PATH.");
}

/********************************************************************/

/* toolReferencePoint */

toolReferencePoint::toolReferencePoint(){}


toolReferencePoint::~toolReferencePoint(){}

int toolReferencePoint::isA(int aType)
    { return (aType == toolReferencePoint_E); }

/********************************************************************/

/* toolReferencePointCcp */

toolReferencePointCcp::toolReferencePointCcp(){}


toolReferencePointCcp::~toolReferencePointCcp()
{
}

int toolReferencePointCcp::isA(int aType)
    { return ((aType == toolReferencePointCcp_E) ||
	      (aType == toolReferencePoint_E));
    }

void toolReferencePointCcp::printSelf()
{
  printf(".CCP.");
}

/********************************************************************/

/* toolReferencePointTcp */

toolReferencePointTcp::toolReferencePointTcp(){}


toolReferencePointTcp::~toolReferencePointTcp()
{
}

int toolReferencePointTcp::isA(int aType)
    { return ((aType == toolReferencePointTcp_E) ||
	      (aType == toolReferencePoint_E));
    }

void toolReferencePointTcp::printSelf()
{
  printf(".TCP.");
}

/********************************************************************/

/* topologicalRepresentationItem */

topologicalRepresentationItem::topologicalRepresentationItem(){}

topologicalRepresentationItem::topologicalRepresentationItem(
 char * nameIn) :
   representationItem(
     nameIn)
    {}

topologicalRepresentationItem::~topologicalRepresentationItem(){}

int topologicalRepresentationItem::isA(int aType)
    { return ((aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* touchProbe */

touchProbe::touchProbe(){}

touchProbe::touchProbe(
 char * itsIdIn)
{
  itsId = itsIdIn;
}

touchProbe::~touchProbe()
{
  delete itsId;
}

int touchProbe::isA(int aType)
    { return (aType == touchProbe_E); }

void touchProbe::printSelf()
{
  printf("TOUCH_PROBE");
  printf("(");
  printString(itsId);
  printf(")");
}

/********************************************************************/

/* trajectory */

trajectory::trajectory(){}

trajectory::trajectory(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 boolean * itsDirectionIn) :
   toolpath(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn)
{
   itsDirection = itsDirectionIn;
}

trajectory::~trajectory(){}

int trajectory::isA(int aType)
    { return ((aType == trajectory_E) ||
	      (aType == toolpath_E));
    }

/********************************************************************/

/* transitionCode */

transitionCode::transitionCode(){}


transitionCode::~transitionCode(){}

int transitionCode::isA(int aType)
    { return (aType == transitionCode_E); }

/********************************************************************/

/* transitionCodeContinuous */

transitionCodeContinuous::transitionCodeContinuous(){}


transitionCodeContinuous::~transitionCodeContinuous()
{
}

int transitionCodeContinuous::isA(int aType)
    { return ((aType == transitionCodeContinuous_E) ||
	      (aType == transitionCode_E));
    }

void transitionCodeContinuous::printSelf()
{
  printf(".CONTINUOUS.");
}

/********************************************************************/

/* transitionCodeContSameGradient */

transitionCodeContSameGradient::transitionCodeContSameGradient(){}


transitionCodeContSameGradient::~transitionCodeContSameGradient()
{
}

int transitionCodeContSameGradient::isA(int aType)
    { return ((aType == transitionCodeContSameGradient_E) ||
	      (aType == transitionCode_E));
    }

void transitionCodeContSameGradient::printSelf()
{
  printf(".CONT_SAME_GRADIENT.");
}

/********************************************************************/

/* transitionCodeContSameGradientSameCurvature */

transitionCodeContSameGradientSameCurvature::transitionCodeContSameGradientSameCurvature(){}


transitionCodeContSameGradientSameCurvature::~transitionCodeContSameGradientSameCurvature()
{
}

int transitionCodeContSameGradientSameCurvature::isA(int aType)
    { return ((aType == transitionCodeContSameGradientSameCurvature_E) ||
	      (aType == transitionCode_E));
    }

void transitionCodeContSameGradientSameCurvature::printSelf()
{
  printf(".CONT_SAME_GRADIENT_SAME_CURVATURE.");
}

/********************************************************************/

/* transitionCodeDiscontinuous */

transitionCodeDiscontinuous::transitionCodeDiscontinuous(){}


transitionCodeDiscontinuous::~transitionCodeDiscontinuous()
{
}

int transitionCodeDiscontinuous::isA(int aType)
    { return ((aType == transitionCodeDiscontinuous_E) ||
	      (aType == transitionCode_E));
    }

void transitionCodeDiscontinuous::printSelf()
{
  printf(".DISCONTINUOUS.");
}

/********************************************************************/

/* transitionFeature */

transitionFeature::transitionFeature(){}

transitionFeature::transitionFeature(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 machiningFeature * firstFeatureIn,
 machiningFeature * secondFeatureIn) :
   manufacturingFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn)
{
   firstFeature = firstFeatureIn;
   secondFeature = secondFeatureIn;
}

transitionFeature::~transitionFeature(){}

int transitionFeature::isA(int aType)
    { return ((aType == transitionFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* travelPath */

travelPath::travelPath(){}

travelPath::travelPath(
 axis2placement3d * placementIn)
{
  placement = placementIn;
}

travelPath::~travelPath(){}

int travelPath::isA(int aType)
    { return (aType == travelPath_E); }

/********************************************************************/

/* trimmingPreference */

trimmingPreference::trimmingPreference(){}


trimmingPreference::~trimmingPreference(){}

int trimmingPreference::isA(int aType)
    { return (aType == trimmingPreference_E); }

/********************************************************************/

/* trimmingPreferenceCartesian */

trimmingPreferenceCartesian::trimmingPreferenceCartesian(){}


trimmingPreferenceCartesian::~trimmingPreferenceCartesian()
{
}

int trimmingPreferenceCartesian::isA(int aType)
    { return ((aType == trimmingPreferenceCartesian_E) ||
	      (aType == trimmingPreference_E));
    }

void trimmingPreferenceCartesian::printSelf()
{
  printf(".CARTESIAN.");
}

/********************************************************************/

/* trimmingPreferenceParameter */

trimmingPreferenceParameter::trimmingPreferenceParameter(){}


trimmingPreferenceParameter::~trimmingPreferenceParameter()
{
}

int trimmingPreferenceParameter::isA(int aType)
    { return ((aType == trimmingPreferenceParameter_E) ||
	      (aType == trimmingPreference_E));
    }

void trimmingPreferenceParameter::printSelf()
{
  printf(".PARAMETER.");
}

/********************************************************************/

/* trimmingPreferenceUnspecified */

trimmingPreferenceUnspecified::trimmingPreferenceUnspecified(){}


trimmingPreferenceUnspecified::~trimmingPreferenceUnspecified()
{
}

int trimmingPreferenceUnspecified::isA(int aType)
    { return ((aType == trimmingPreferenceUnspecified_E) ||
	      (aType == trimmingPreference_E));
    }

void trimmingPreferenceUnspecified::printSelf()
{
  printf(".UNSPECIFIED.");
}

/********************************************************************/

/* trimmingSelect */

trimmingSelect::trimmingSelect(){}


trimmingSelect::~trimmingSelect(){}

int trimmingSelect::isA(int aType)
    { return (aType == trimmingSelect_E); }

void trimmingSelect::printSelf()
{
  if (this->isA(cartesianPoint_E))
    (dynamic_cast<instance *>(this))->iId->printSelf();
  else if (this->isA(real_E))
    (dynamic_cast<real *>(this))->printSelf();
}

/********************************************************************/

/* twoAxes */

twoAxes::twoAxes(){}


twoAxes::~twoAxes()
{
}

int twoAxes::isA(int aType)
    { return ((aType == twoAxes_E) ||
	      (aType == toolDirection_E));
    }

void twoAxes::printSelf()
{
  printf("TWO_AXES");
  printf("(");
  printf(")");
}

/********************************************************************/

/* two5DmanufacturingFeature */

two5DmanufacturingFeature::two5DmanufacturingFeature(){}

two5DmanufacturingFeature::two5DmanufacturingFeature(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn) :
   manufacturingFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn)
{
   featurePlacement = featurePlacementIn;
}

two5DmanufacturingFeature::~two5DmanufacturingFeature(){}

int two5DmanufacturingFeature::isA(int aType)
    { return ((aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* two5DmillingStrategy */

two5DmillingStrategy::two5DmillingStrategy(){}

two5DmillingStrategy::two5DmillingStrategy(
 real * overlapIn,
 boolean * allowMultiplePassesIn)
{
  overlap = overlapIn;
  allowMultiplePasses = allowMultiplePassesIn;
}

two5DmillingStrategy::~two5DmillingStrategy(){}

int two5DmillingStrategy::isA(int aType)
    { return (aType == two5DmillingStrategy_E); }

/********************************************************************/

/* unaryBooleanExpression */

unaryBooleanExpression::unaryBooleanExpression(){}

unaryBooleanExpression::unaryBooleanExpression(
 booleanExpression * operandIn)
{
  operand = operandIn;
}

unaryBooleanExpression::~unaryBooleanExpression(){}

int unaryBooleanExpression::isA(int aType)
    { return ((aType == unaryBooleanExpression_E) ||
	      (aType == booleanExpression_E));
    }

/********************************************************************/

/* unidirectionalMilling */

unidirectionalMilling::unidirectionalMilling(){}

unidirectionalMilling::unidirectionalMilling(
 real * overlapIn,
 boolean * allowMultiplePassesIn,
 direction * feedDirectionIn,
 cutmodeType * cutmodeIn) :
   two5DmillingStrategy(
     overlapIn,
     allowMultiplePassesIn)
{
   feedDirection = feedDirectionIn;
   cutmode = cutmodeIn;
}

unidirectionalMilling::~unidirectionalMilling()
{
  delete overlap;
  delete allowMultiplePasses;
  delete cutmode;
}

int unidirectionalMilling::isA(int aType)
    { return ((aType == unidirectionalMilling_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void unidirectionalMilling::printSelf()
{
  printf("UNIDIRECTIONAL_MILLING");
  printf("(");
  if (overlap)
    overlap->printSelf();
  else
    printf("$");
  printf(",");
  if (allowMultiplePasses)
    allowMultiplePasses->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (cutmode)
    cutmode->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* unloadTool */

unloadTool::unloadTool(){}

unloadTool::unloadTool(
 char * itsIdIn,
 machiningTool * itsToolIn) :
   ncFunction(
     itsIdIn)
{
   itsTool = itsToolIn;
}

unloadTool::~unloadTool()
{
  delete itsId;
}

int unloadTool::isA(int aType)
    { return ((aType == unloadTool_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void unloadTool::printSelf()
{
  printf("UNLOAD_TOOL");
  printf("(");
  printString(itsId);
  printf(",");
  if (itsTool)
    (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* uvStrategy */

uvStrategy::uvStrategy(){}

uvStrategy::uvStrategy(
 pathmodeType * pathmodeIn,
 cutmodeType * cutmodeIn,
 tolerances * itsMillingTolerancesIn,
 real * stepoverIn,
 direction * forwardDirectionIn,
 direction * sidewardDirectionIn) :
   freeformStrategy(
     pathmodeIn,
     cutmodeIn,
     itsMillingTolerancesIn,
     stepoverIn)
{
   forwardDirection = forwardDirectionIn;
   sidewardDirection = sidewardDirectionIn;
}

uvStrategy::~uvStrategy()
{
  delete pathmode;
  delete cutmode;
  delete stepover;
}

int uvStrategy::isA(int aType)
    { return ((aType == uvStrategy_E) ||
	      (aType == freeformStrategy_E));
    }

void uvStrategy::printSelf()
{
  printf("UV_STRATEGY");
  printf("(");
  pathmode->printSelf();
  printf(",");
  cutmode->printSelf();
  printf(",");
  itsMillingTolerances->iId->printSelf();
  printf(",");
  if (stepover)
    stepover->printSelf();
  else
    printf("$");
  printf(",");
  forwardDirection->iId->printSelf();
  printf(",");
  sidewardDirection->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* vertex */

vertex::vertex(){}

vertex::vertex(
 char * nameIn) :
   topologicalRepresentationItem(
     nameIn)
    {}

vertex::~vertex(){}

int vertex::isA(int aType)
    { return ((aType == vertex_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* vertexPoint */

vertexPoint::vertexPoint(){}

vertexPoint::vertexPoint(
 char * nameIn,
 point * vertexGeometryIn) :
   vertex(
     nameIn)
{
   vertexGeometry = vertexGeometryIn;
}

vertexPoint::~vertexPoint()
{
  delete name;
}

int vertexPoint::isA(int aType)
    { return ((aType == vertexPoint_E) ||
	      (aType == vertex_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void vertexPoint::printSelf()
{
  printf("VERTEX_POINT");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(vertexGeometry))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* waitForMark */

waitForMark::waitForMark(){}

waitForMark::waitForMark(
 char * itsIdIn,
 channel * itsChannelIn) :
   ncFunction(
     itsIdIn)
{
   itsChannel = itsChannelIn;
}

waitForMark::~waitForMark()
{
  delete itsId;
}

int waitForMark::isA(int aType)
    { return ((aType == waitForMark_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void waitForMark::printSelf()
{
  printf("WAIT_FOR_MARK");
  printf("(");
  printString(itsId);
  printf(",");
  itsChannel->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* weekOfYearAndDayDate */

weekOfYearAndDayDate::weekOfYearAndDayDate(){}

weekOfYearAndDayDate::weekOfYearAndDayDate(
 int yearComponentIn,
 int weekComponentIn,
 integer * dayComponentIn) :
   date(
     yearComponentIn)
{
   weekComponent = weekComponentIn;
   dayComponent = dayComponentIn;
}

weekOfYearAndDayDate::~weekOfYearAndDayDate()
{
  delete dayComponent;
}

int weekOfYearAndDayDate::isA(int aType)
    { return ((aType == weekOfYearAndDayDate_E) ||
	      (aType == date_E));
    }

void weekOfYearAndDayDate::printSelf()
{
  printf("WEEEK_OF_YEAR_AND_DAY_DATE");
  printf("(");
  printf("%d", yearComponent);
  printf(",");
  printf("%d", weekComponent);
  printf(",");
  if (dayComponent)
    dayComponent->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* whileStatement */

whileStatement::whileStatement(){}

whileStatement::whileStatement(
 char * itsIdIn,
 booleanExpression * conditionIn,
 executable * bodyIn) :
   programStructure(
     itsIdIn)
{
   condition = conditionIn;
   body = bodyIn;
}

whileStatement::~whileStatement()
{
  delete itsId;
}

int whileStatement::isA(int aType)
    { return ((aType == whileStatement_E) ||
	      (aType == programStructure_E) ||
	      (aType == executable_E));
    }

void whileStatement::printSelf()
{
  printf("WHILE_STATEMENT");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(condition))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(body))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* woodruffSlotEndType */

woodruffSlotEndType::woodruffSlotEndType(){}

woodruffSlotEndType::woodruffSlotEndType(
 tolerancedLengthMeasure * radiusIn)
{
  radius = radiusIn;
}

woodruffSlotEndType::~woodruffSlotEndType()
{
}

int woodruffSlotEndType::isA(int aType)
    { return ((aType == woodruffSlotEndType_E) ||
	      (aType == slotEndType_E));
    }

void woodruffSlotEndType::printSelf()
{
  printf("WOODRUFF_SLOT_END_TYPE");
  printf("(");
  radius->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* workingstep */

workingstep::workingstep(){}

workingstep::workingstep(
 char * itsIdIn,
 elementarySurface * itsSecplaneIn) :
   executable(
     itsIdIn)
{
   itsSecplane = itsSecplaneIn;
}

workingstep::~workingstep(){}

int workingstep::isA(int aType)
    { return ((aType == workingstep_E) ||
	      (aType == executable_E));
    }

/********************************************************************/

/* workpiece */

workpiece::workpiece(){}

workpiece::workpiece(
 char * itsIdIn,
 material * itsMaterialIn,
 real * globalToleranceIn,
 workpiece * itsRawpieceIn,
 advancedBrepShapeRepresentation * itsGeometryIn,
 boundingGeometrySelect * itsBoundingGeometryIn,
 parenCartesianPointList * clampingPositionsIn)
{
  itsId = itsIdIn;
  itsMaterial = itsMaterialIn;
  globalTolerance = globalToleranceIn;
  itsRawpiece = itsRawpieceIn;
  itsGeometry = itsGeometryIn;
  itsBoundingGeometry = itsBoundingGeometryIn;
  clampingPositions = clampingPositionsIn;
}

workpiece::~workpiece()
{
  delete itsId;
  delete globalTolerance;
  delete clampingPositions;
}

int workpiece::isA(int aType)
    { return (aType == workpiece_E); }

void workpiece::printSelf()
{
  printf("WORKPIECE");
  printf("(");
  printString(itsId);
  printf(",");
  if (itsMaterial)
    itsMaterial->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (globalTolerance)
    globalTolerance->printSelf();
  else
    printf("$");
  printf(",");
  if (itsRawpiece)
    itsRawpiece->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsGeometry)
    itsGeometry->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsBoundingGeometry)
    (dynamic_cast<instance *>(itsBoundingGeometry))->iId->printSelf();
  else
    printf("$");
  printf(",");
  clampingPositions->printSelf();
  printf(")");
}

/********************************************************************/

/* workpieceSetup */

workpieceSetup::workpieceSetup(){}

workpieceSetup::workpieceSetup(
 workpiece * itsWorkpieceIn,
 axis2placement3d * itsOriginIn,
 offsetVector * itsOffsetIn,
 restrictedAreaSelect * itsRestrictedAreaIn,
 parenSetupInstructionList * itsInstructionsIn)
{
  itsWorkpiece = itsWorkpieceIn;
  itsOrigin = itsOriginIn;
  itsOffset = itsOffsetIn;
  itsRestrictedArea = itsRestrictedAreaIn;
  itsInstructions = itsInstructionsIn;
}

workpieceSetup::~workpieceSetup()
{
  delete itsOffset;
  delete itsInstructions;
}

int workpieceSetup::isA(int aType)
    { return (aType == workpieceSetup_E); }

void workpieceSetup::printSelf()
{
  printf("WORKPIECE_SETUP");
  printf("(");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOrigin->iId->printSelf();
  printf(",");
  if (itsOffset)
    itsOffset->printSelf();
  else
    printf("$");
  printf(",");
  if (itsRestrictedArea)
    (dynamic_cast<instance *>(itsRestrictedArea))->iId->printSelf();
  else
    printf("$");
  printf(",");
  itsInstructions->printSelf();
  printf(")");
}

/********************************************************************/

/* workplan */

workplan::workplan(){}

workplan::workplan(
 char * itsIdIn,
 parenExecutableList * itsElementsIn,
 channel * itsChannelIn,
 setup * itsSetupIn,
 inProcessGeometry * itsEffectIn) :
   programStructure(
     itsIdIn)
{
   itsElements = itsElementsIn;
   itsChannel = itsChannelIn;
   itsSetup = itsSetupIn;
   itsEffect = itsEffectIn;
}

workplan::~workplan()
{
  delete itsId;
  delete itsElements;
}

int workplan::isA(int aType)
    { return ((aType == workplan_E) ||
	      (aType == programStructure_E) ||
	      (aType == executable_E));
    }

void workplan::printSelf()
{
  printf("WORKPLAN");
  printf("(");
  printString(itsId);
  printf(",");
  itsElements->printSelf();
  printf(",");
  if (itsChannel)
    itsChannel->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsSetup)
    itsSetup->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsEffect)
    itsEffect->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* airStrategy */

airStrategy::airStrategy(){}

airStrategy::airStrategy(
 direction * toolOrientationIn) :
   approachRetractStrategy(
     toolOrientationIn)
    {}

airStrategy::~airStrategy(){}

int airStrategy::isA(int aType)
    { return ((aType == airStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }

/********************************************************************/

/* alongPath */

alongPath::alongPath(){}

alongPath::alongPath(
 direction * toolOrientationIn,
 toolpathList * pathIn) :
   approachRetractStrategy(
     toolOrientationIn)
{
   path = pathIn;
}

alongPath::~alongPath()
{
}

int alongPath::isA(int aType)
    { return ((aType == alongPath_E) ||
	      (aType == approachRetractStrategy_E));
    }

void alongPath::printSelf()
{
  printf("ALONG_PATH");
  printf("(");
  if (toolOrientation)
    toolOrientation->iId->printSelf();
  else
    printf("$");
  printf(",");
  path->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* andExpression */

andExpression::andExpression(){}

andExpression::andExpression(
 parenBooleanExpressionListFull * operandsIn) :
   multipleArityBooleanExpression(
     operandsIn)
    {}

andExpression::~andExpression()
{
  delete operands;
}

int andExpression::isA(int aType)
    { return ((aType == andExpression_E) ||
	      (aType == multipleArityBooleanExpression_E) ||
	      (aType == booleanExpression_E));
    }

void andExpression::printSelf()
{
  printf("AND_EXPRESSION");
  printf("(");
  operands->printSelf();
  printf(")");
}

/********************************************************************/

/* angleTaper */

angleTaper::angleTaper(){}

angleTaper::angleTaper(
 real * angleIn)
{
  angle = angleIn;
}

angleTaper::~angleTaper()
{
  delete angle;
}

int angleTaper::isA(int aType)
    { return ((aType == angleTaper_E) ||
	      (aType == taperSelect_E));
    }

void angleTaper::printSelf()
{
  printf("ANGLE_TAPER");
  printf("(");
  angle->printSelf();
  printf(")");
}

/********************************************************************/

/* apRetractAngle */

apRetractAngle::apRetractAngle(){}

apRetractAngle::apRetractAngle(
 direction * toolOrientationIn,
 double angleIn,
 double travelLengthIn) :
   airStrategy(
     toolOrientationIn)
{
   angle = angleIn;
   travelLength = travelLengthIn;
}

apRetractAngle::~apRetractAngle()
{
}

int apRetractAngle::isA(int aType)
    { return ((aType == apRetractAngle_E) ||
	      (aType == airStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }

void apRetractAngle::printSelf()
{
  printf("AP_RETRACT_ANGLE");
  printf("(");
  if (toolOrientation)
    toolOrientation->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(",");
  printDouble(travelLength);
  printf(")");
}

/********************************************************************/

/* apRetractTangent */

apRetractTangent::apRetractTangent(){}

apRetractTangent::apRetractTangent(
 direction * toolOrientationIn,
 double radiusIn) :
   airStrategy(
     toolOrientationIn)
{
   radius = radiusIn;
}

apRetractTangent::~apRetractTangent()
{
}

int apRetractTangent::isA(int aType)
    { return ((aType == apRetractTangent_E) ||
	      (aType == airStrategy_E) ||
	      (aType == approachRetractStrategy_E));
    }

void apRetractTangent::printSelf()
{
  printf("AP_RETRACT_TANGENT");
  printf("(");
  if (toolOrientation)
    toolOrientation->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(radius);
  printf(")");
}

/********************************************************************/

/* assignment */

assignment::assignment(){}

assignment::assignment(
 char * itsIdIn,
 ncVariable * itsLvalueIn,
 rvalue * itsRvalueIn) :
   programStructure(
     itsIdIn)
{
   itsLvalue = itsLvalueIn;
   itsRvalue = itsRvalueIn;
}

assignment::~assignment()
{
  delete itsId;
}

int assignment::isA(int aType)
    { return ((aType == assignment_E) ||
	      (aType == programStructure_E) ||
	      (aType == executable_E));
    }

void assignment::printSelf()
{
  printf("ASSIGNMENT");
  printf("(");
  printString(itsId);
  printf(",");
  itsLvalue->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsRvalue))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* axisTrajectory */

axisTrajectory::axisTrajectory(){}

axisTrajectory::axisTrajectory(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 boolean * itsDirectionIn,
 parenStringListFull * axisListIn,
 parenBoundedCurveListFull * commandsIn) :
   trajectory(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     itsDirectionIn)
{
   axisList = axisListIn;
   commands = commandsIn;
}

axisTrajectory::~axisTrajectory()
{
  delete itsPriority;
  delete itsType;
  delete itsDirection;
  delete axisList;
  delete commands;
}

int axisTrajectory::isA(int aType)
    { return ((aType == axisTrajectory_E) ||
	      (aType == trajectory_E) ||
	      (aType == toolpath_E));
    }

void axisTrajectory::printSelf()
{
  printf("AXIS_TRAJECTORY");
  printf("(");
  itsPriority->printSelf();
  printf(",");
  itsType->printSelf();
  printf(",");
  if (itsSpeed)
    itsSpeed->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachineFunctions)
    (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsDirection)
    itsDirection->printSelf();
  else
    printf("$");
  printf(",");
  axisList->printSelf();
  printf(",");
  commands->printSelf();
  printf(")");
}

/********************************************************************/

/* bidirectionalContour */

bidirectionalContour::bidirectionalContour(){}

bidirectionalContour::bidirectionalContour(
 real * overlapIn,
 boolean * allowMultiplePassesIn,
 direction * feedDirectionIn,
 leftOrRight * stepoverDirectionIn,
 rotDirection * rotationDirectionIn,
 cutmodeType * spiralCutmodeIn) :
   two5DmillingStrategy(
     overlapIn,
     allowMultiplePassesIn)
{
   feedDirection = feedDirectionIn;
   stepoverDirection = stepoverDirectionIn;
   rotationDirection = rotationDirectionIn;
   spiralCutmode = spiralCutmodeIn;
}

bidirectionalContour::~bidirectionalContour()
{
  delete overlap;
  delete allowMultiplePasses;
  delete stepoverDirection;
  delete rotationDirection;
  delete spiralCutmode;
}

int bidirectionalContour::isA(int aType)
    { return ((aType == bidirectionalContour_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void bidirectionalContour::printSelf()
{
  printf("BIDIRECTIONAL_CONTOUR");
  printf("(");
  if (overlap)
    overlap->printSelf();
  else
    printf("$");
  printf(",");
  if (allowMultiplePasses)
    allowMultiplePasses->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (stepoverDirection)
    stepoverDirection->printSelf();
  else
    printf("$");
  if (rotationDirection)
    rotationDirection->printSelf();
  else
    printf("$");
  if (spiralCutmode)
    spiralCutmode->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* bidirectionalMilling */

bidirectionalMilling::bidirectionalMilling(){}

bidirectionalMilling::bidirectionalMilling(
 real * overlapIn,
 boolean * allowMultiplePassesIn,
 direction * feedDirectionIn,
 leftOrRight * stepoverDirectionIn,
 strokeConnectionStrategy * itsStrokeConnectionStrategyIn) :
   two5DmillingStrategy(
     overlapIn,
     allowMultiplePassesIn)
{
   feedDirection = feedDirectionIn;
   stepoverDirection = stepoverDirectionIn;
   itsStrokeConnectionStrategy = itsStrokeConnectionStrategyIn;
}

bidirectionalMilling::~bidirectionalMilling()
{
  delete overlap;
  delete allowMultiplePasses;
  delete stepoverDirection;
  delete itsStrokeConnectionStrategy;
}

int bidirectionalMilling::isA(int aType)
    { return ((aType == bidirectionalMilling_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void bidirectionalMilling::printSelf()
{
  printf("BIDIRECTIONAL_MILLING");
  printf("(");
  if (overlap)
    overlap->printSelf();
  else
    printf("$");
  printf(",");
  if (allowMultiplePasses)
    allowMultiplePasses->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (stepoverDirection)
    stepoverDirection->printSelf();
  else
    printf("$");
  printf(",");
  if (itsStrokeConnectionStrategy)
    itsStrokeConnectionStrategy->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* binaryBooleanExpression */

binaryBooleanExpression::binaryBooleanExpression(){}

binaryBooleanExpression::binaryBooleanExpression(
 booleanExpression * operand1In,
 booleanExpression * operand2In)
{
  operand1 = operand1In;
  operand2 = operand2In;
}

binaryBooleanExpression::~binaryBooleanExpression(){}

int binaryBooleanExpression::isA(int aType)
    { return ((aType == binaryBooleanExpression_E) ||
	      (aType == booleanExpression_E));
    }

/********************************************************************/

/* blindBottomCondition */

blindBottomCondition::blindBottomCondition(){}


blindBottomCondition::~blindBottomCondition(){}

int blindBottomCondition::isA(int aType)
    { return ((aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }

/********************************************************************/

/* boundingGeometrySelect */

boundingGeometrySelect::boundingGeometrySelect(){}


boundingGeometrySelect::~boundingGeometrySelect(){}

int boundingGeometrySelect::isA(int aType)
    { return ((aType == boundingGeometrySelect_E) ||
	      (aType == restrictedAreaSelect_E));
    }

/********************************************************************/

/* calendarDate */

calendarDate::calendarDate(){}

calendarDate::calendarDate(
 int yearComponentIn,
 int dayComponentIn,
 int monthComponentIn) :
   date(
     yearComponentIn)
{
   dayComponent = dayComponentIn;
   monthComponent = monthComponentIn;
}

calendarDate::~calendarDate()
{
}

int calendarDate::isA(int aType)
    { return ((aType == calendarDate_E) ||
	      (aType == date_E));
    }

void calendarDate::printSelf()
{
  printf("CALENDAR_DATE");
  printf("(");
  printf("%d", yearComponent);
  printf(",");
  printf("%d", dayComponent);
  printf(",");
  printf("%d", monthComponent);
  printf(")");
}

/********************************************************************/

/* centerMilling */

centerMilling::centerMilling(){}

centerMilling::centerMilling(
 real * overlapIn,
 boolean * allowMultiplePassesIn) :
   two5DmillingStrategy(
     overlapIn,
     allowMultiplePassesIn)
    {}

centerMilling::~centerMilling()
{
  delete overlap;
  delete allowMultiplePasses;
}

int centerMilling::isA(int aType)
    { return ((aType == centerMilling_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void centerMilling::printSelf()
{
  printf("CENTER_MILLING");
  printf("(");
  if (overlap)
    overlap->printSelf();
  else
    printf("$");
  printf(",");
  if (allowMultiplePasses)
    allowMultiplePasses->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* chamfer */

chamfer::chamfer(){}

chamfer::chamfer(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 machiningFeature * firstFeatureIn,
 machiningFeature * secondFeatureIn,
 double angleToPlaneIn,
 tolerancedLengthMeasure * firstOffsetAmountIn) :
   transitionFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     firstFeatureIn,
     secondFeatureIn)
{
   angleToPlane = angleToPlaneIn;
   firstOffsetAmount = firstOffsetAmountIn;
}

chamfer::~chamfer()
{
  delete itsId;
  delete itsOperations;
}

int chamfer::isA(int aType)
    { return ((aType == chamfer_E) ||
	      (aType == transitionFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == manufacturingFeature_E));
    }

void chamfer::printSelf()
{
  printf("CHAMFER");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  (dynamic_cast<instance *>(firstFeature))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(secondFeature))->iId->printSelf();
  printf(",");
  printDouble(angleToPlane);
  printf(",");
  firstOffsetAmount->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* circularPath */

circularPath::circularPath(){}

circularPath::circularPath(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * radiusIn) :
   travelPath(
     placementIn)
{
   radius = radiusIn;
}

circularPath::~circularPath(){}

int circularPath::isA(int aType)
    { return ((aType == circularPath_E) ||
	      (aType == travelPath_E));
    }

/********************************************************************/

/* closedProfile */

closedProfile::closedProfile(){}

closedProfile::closedProfile(
 axis2placement3d * placementIn) :
   profile(
     placementIn)
    {}

closedProfile::~closedProfile(){}

int closedProfile::isA(int aType)
    { return ((aType == closedProfile_E) ||
	      (aType == profile_E));
    }

/********************************************************************/

/* comparisonEqual */

comparisonEqual::comparisonEqual(){}

comparisonEqual::comparisonEqual(
 ncVariable * operand1In,
 rvalue * operand2In) :
   comparisonExpression(
     operand1In,
     operand2In)
    {}

comparisonEqual::~comparisonEqual()
{
}

int comparisonEqual::isA(int aType)
    { return ((aType == comparisonEqual_E) ||
	      (aType == comparisonExpression_E) ||
	      (aType == booleanExpression_E));
    }

void comparisonEqual::printSelf()
{
  printf("COMPARISON_EQUAL");
  printf("(");
  operand1->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(operand2))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* comparisonGreater */

comparisonGreater::comparisonGreater(){}

comparisonGreater::comparisonGreater(
 ncVariable * operand1In,
 rvalue * operand2In) :
   comparisonExpression(
     operand1In,
     operand2In)
    {}

comparisonGreater::~comparisonGreater()
{
}

int comparisonGreater::isA(int aType)
    { return ((aType == comparisonGreater_E) ||
	      (aType == comparisonExpression_E) ||
	      (aType == booleanExpression_E));
    }

void comparisonGreater::printSelf()
{
  printf("COMPARISON_GREATER");
  printf("(");
  operand1->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(operand2))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* comparisonGreaterEqual */

comparisonGreaterEqual::comparisonGreaterEqual(){}

comparisonGreaterEqual::comparisonGreaterEqual(
 ncVariable * operand1In,
 rvalue * operand2In) :
   comparisonExpression(
     operand1In,
     operand2In)
    {}

comparisonGreaterEqual::~comparisonGreaterEqual()
{
}

int comparisonGreaterEqual::isA(int aType)
    { return ((aType == comparisonGreaterEqual_E) ||
	      (aType == comparisonExpression_E) ||
	      (aType == booleanExpression_E));
    }

void comparisonGreaterEqual::printSelf()
{
  printf("COMPARISON_GREATER_EQUAL");
  printf("(");
  operand1->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(operand2))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* comparisonLess */

comparisonLess::comparisonLess(){}

comparisonLess::comparisonLess(
 ncVariable * operand1In,
 rvalue * operand2In) :
   comparisonExpression(
     operand1In,
     operand2In)
    {}

comparisonLess::~comparisonLess()
{
}

int comparisonLess::isA(int aType)
    { return ((aType == comparisonLess_E) ||
	      (aType == comparisonExpression_E) ||
	      (aType == booleanExpression_E));
    }

void comparisonLess::printSelf()
{
  printf("COMPARISON_LESS");
  printf("(");
  operand1->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(operand2))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* comparisonLessEqual */

comparisonLessEqual::comparisonLessEqual(){}

comparisonLessEqual::comparisonLessEqual(
 ncVariable * operand1In,
 rvalue * operand2In) :
   comparisonExpression(
     operand1In,
     operand2In)
    {}

comparisonLessEqual::~comparisonLessEqual()
{
}

int comparisonLessEqual::isA(int aType)
    { return ((aType == comparisonLessEqual_E) ||
	      (aType == comparisonExpression_E) ||
	      (aType == booleanExpression_E));
    }

void comparisonLessEqual::printSelf()
{
  printf("COMPARISON_LESS_EQUAL");
  printf("(");
  operand1->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(operand2))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* comparisonNotEqual */

comparisonNotEqual::comparisonNotEqual(){}

comparisonNotEqual::comparisonNotEqual(
 ncVariable * operand1In,
 rvalue * operand2In) :
   comparisonExpression(
     operand1In,
     operand2In)
    {}

comparisonNotEqual::~comparisonNotEqual()
{
}

int comparisonNotEqual::isA(int aType)
    { return ((aType == comparisonNotEqual_E) ||
	      (aType == comparisonExpression_E) ||
	      (aType == booleanExpression_E));
    }

void comparisonNotEqual::printSelf()
{
  printf("COMPARISON_NOT_EQUAL");
  printf("(");
  operand1->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(operand2))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* completeCircularPath */

completeCircularPath::completeCircularPath(){}

completeCircularPath::completeCircularPath(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * radiusIn) :
   circularPath(
     placementIn,
     radiusIn)
    {}

completeCircularPath::~completeCircularPath()
{
}

int completeCircularPath::isA(int aType)
    { return ((aType == completeCircularPath_E) ||
	      (aType == circularPath_E) ||
	      (aType == travelPath_E));
    }

void completeCircularPath::printSelf()
{
  printf("COMPLETE_CIRCULAR_PATH");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  radius->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* compoundFeature */

compoundFeature::compoundFeature(){}

compoundFeature::compoundFeature(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 parenCompoundFeatureSelectListFull * elementsIn) :
   two5DmanufacturingFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn)
{
   elements = elementsIn;
}

compoundFeature::~compoundFeature(){}

int compoundFeature::isA(int aType)
    { return ((aType == compoundFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* conicalHoleBottom */

conicalHoleBottom::conicalHoleBottom(){}

conicalHoleBottom::conicalHoleBottom(
 real * tipAngleIn,
 tolerancedLengthMeasure * tipRadiusIn)
{
  tipAngle = tipAngleIn;
  tipRadius = tipRadiusIn;
}

conicalHoleBottom::~conicalHoleBottom()
{
  delete tipAngle;
}

int conicalHoleBottom::isA(int aType)
    { return ((aType == conicalHoleBottom_E) ||
	      (aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }

void conicalHoleBottom::printSelf()
{
  printf("CONICAL_HOLE_BOTTOM");
  printf("(");
  tipAngle->printSelf();
  printf(",");
  if (tipRadius)
    tipRadius->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* connectedFaceSet */

connectedFaceSet::connectedFaceSet(){}

connectedFaceSet::connectedFaceSet(
 char * nameIn,
 parenFaceListFull * cfsFacesIn) :
   topologicalRepresentationItem(
     nameIn)
{
   cfsFaces = cfsFacesIn;
}

connectedFaceSet::~connectedFaceSet(){}

int connectedFaceSet::isA(int aType)
    { return ((aType == connectedFaceSet_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* contourBidirectional */

contourBidirectional::contourBidirectional(){}

contourBidirectional::contourBidirectional(
 real * overlapIn,
 boolean * allowMultiplePassesIn,
 direction * feedDirectionIn,
 leftOrRight * stepoverDirectionIn,
 rotDirection * rotationDirectionIn,
 cutmodeType * spiralCutmodeIn) :
   two5DmillingStrategy(
     overlapIn,
     allowMultiplePassesIn)
{
   feedDirection = feedDirectionIn;
   stepoverDirection = stepoverDirectionIn;
   rotationDirection = rotationDirectionIn;
   spiralCutmode = spiralCutmodeIn;
}

contourBidirectional::~contourBidirectional()
{
  delete overlap;
  delete allowMultiplePasses;
  delete stepoverDirection;
  delete rotationDirection;
  delete spiralCutmode;
}

int contourBidirectional::isA(int aType)
    { return ((aType == contourBidirectional_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void contourBidirectional::printSelf()
{
  printf("CONTOUR_BIDIRECTIONAL");
  printf("(");
  if (overlap)
    overlap->printSelf();
  else
    printf("$");
  printf(",");
  if (allowMultiplePasses)
    allowMultiplePasses->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (stepoverDirection)
    stepoverDirection->printSelf();
  else
    printf("$");
  if (rotationDirection)
    rotationDirection->printSelf();
  else
    printf("$");
  if (spiralCutmode)
    spiralCutmode->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* contourParallel */

contourParallel::contourParallel(){}

contourParallel::contourParallel(
 real * overlapIn,
 boolean * allowMultiplePassesIn,
 rotDirection * rotationDirectionIn,
 cutmodeType * cutmodeIn) :
   two5DmillingStrategy(
     overlapIn,
     allowMultiplePassesIn)
{
   rotationDirection = rotationDirectionIn;
   cutmode = cutmodeIn;
}

contourParallel::~contourParallel()
{
  delete overlap;
  delete allowMultiplePasses;
  delete rotationDirection;
  delete cutmode;
}

int contourParallel::isA(int aType)
    { return ((aType == contourParallel_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void contourParallel::printSelf()
{
  printf("CONTOUR_PARALLEL");
  printf("(");
  if (overlap)
    overlap->printSelf();
  else
    printf("$");
  printf(",");
  if (allowMultiplePasses)
    allowMultiplePasses->printSelf();
  else
    printf("$");
  printf(",");
  rotationDirection->printSelf();
  printf(",");
  if (cutmode)
    cutmode->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* contourSpiral */

contourSpiral::contourSpiral(){}

contourSpiral::contourSpiral(
 real * overlapIn,
 boolean * allowMultiplePassesIn,
 rotDirection * rotationDirectionIn,
 cutmodeType * cutmodeIn) :
   two5DmillingStrategy(
     overlapIn,
     allowMultiplePassesIn)
{
   rotationDirection = rotationDirectionIn;
   cutmode = cutmodeIn;
}

contourSpiral::~contourSpiral()
{
  delete overlap;
  delete allowMultiplePasses;
  delete rotationDirection;
  delete cutmode;
}

int contourSpiral::isA(int aType)
    { return ((aType == contourSpiral_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void contourSpiral::printSelf()
{
  printf("CONTOUR_SPIRAL");
  printf("(");
  if (overlap)
    overlap->printSelf();
  else
    printf("$");
  printf(",");
  if (allowMultiplePasses)
    allowMultiplePasses->printSelf();
  else
    printf("$");
  printf(",");
  rotationDirection->printSelf();
  printf(",");
  if (cutmode)
    cutmode->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* counterboreHole */

counterboreHole::counterboreHole(){}

counterboreHole::counterboreHole(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 parenCompoundFeatureSelectListFull * elementsIn) :
   compoundFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     elementsIn)
    {}

counterboreHole::~counterboreHole()
{
  delete itsId;
  delete itsOperations;
  delete elements;
}

int counterboreHole::isA(int aType)
    { return ((aType == counterboreHole_E) ||
	      (aType == compoundFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void counterboreHole::printSelf()
{
  printf("COUNTERBORE_HOLE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  elements->printSelf();
  printf(")");
}

/********************************************************************/

/* countersunkHole */

countersunkHole::countersunkHole(){}

countersunkHole::countersunkHole(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 parenCompoundFeatureSelectListFull * elementsIn) :
   compoundFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     elementsIn)
    {}

countersunkHole::~countersunkHole()
{
  delete itsId;
  delete itsOperations;
  delete elements;
}

int countersunkHole::isA(int aType)
    { return ((aType == countersunkHole_E) ||
	      (aType == compoundFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void countersunkHole::printSelf()
{
  printf("COUNTERSUNK_HOLE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  elements->printSelf();
  printf(")");
}

/********************************************************************/

/* curveWithNormalVector */

curveWithNormalVector::curveWithNormalVector(){}

curveWithNormalVector::curveWithNormalVector(
 boundedCurve * basiccurveIn,
 boundedCurve * surfaceNormalIn)
{
  basiccurve = basiccurveIn;
  surfaceNormal = surfaceNormalIn;
}

curveWithNormalVector::~curveWithNormalVector()
{
}

int curveWithNormalVector::isA(int aType)
    { return ((aType == curveWithNormalVector_E) ||
	      (aType == curveWithSurfaceNormalSelect_E));
    }

void curveWithNormalVector::printSelf()
{
  printf("CURVE_WITH_NORMAL_VECTOR");
  printf("(");
  (dynamic_cast<instance *>(basiccurve))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(surfaceNormal))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* cutterLocationTrajectory */

cutterLocationTrajectory::cutterLocationTrajectory(){}

cutterLocationTrajectory::cutterLocationTrajectory(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 boolean * itsDirectionIn,
 boundedCurve * basiccurveIn,
 boundedCurve * itsToolaxisIn,
 boundedCurve * surfaceNormalIn) :
   trajectory(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     itsDirectionIn)
{
   basiccurve = basiccurveIn;
   itsToolaxis = itsToolaxisIn;
   surfaceNormal = surfaceNormalIn;
}

cutterLocationTrajectory::~cutterLocationTrajectory()
{
  delete itsPriority;
  delete itsType;
  delete itsDirection;
}

int cutterLocationTrajectory::isA(int aType)
    { return ((aType == cutterLocationTrajectory_E) ||
	      (aType == trajectory_E) ||
	      (aType == toolpath_E));
    }

void cutterLocationTrajectory::printSelf()
{
  printf("CUTTER_LOCATION_TRAJECTORY");
  printf("(");
  itsPriority->printSelf();
  printf(",");
  itsType->printSelf();
  printf(",");
  if (itsSpeed)
    itsSpeed->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachineFunctions)
    (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsDirection)
    itsDirection->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(basiccurve))->iId->printSelf();
  printf(",");
  if (itsToolaxis)
    (dynamic_cast<instance *>(itsToolaxis))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (surfaceNormal)
    (dynamic_cast<instance *>(surfaceNormal))->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* cuttingTool */

cuttingTool::cuttingTool(){}

cuttingTool::cuttingTool(
 char * itsIdIn,
 toolBody * itsToolBodyIn,
 parenCuttingComponentListFull * itsCuttingEdgeIn,
 real * overallAssemblyLengthIn) :
   machiningTool(
     itsIdIn)
{
   itsToolBody = itsToolBodyIn;
   itsCuttingEdge = itsCuttingEdgeIn;
   overallAssemblyLength = overallAssemblyLengthIn;
}

cuttingTool::~cuttingTool(){}

int cuttingTool::isA(int aType)
    { return ((aType == cuttingTool_E) ||
	      (aType == machiningTool_E));
    }

/********************************************************************/

/* definitionalRepresentation */

definitionalRepresentation::definitionalRepresentation(){}

definitionalRepresentation::definitionalRepresentation(
 char * nameIn,
 parenRepresentationItemListFull * itemsIn,
 representationContext * contextOfItemsIn) :
   representationParent(
     nameIn,
     itemsIn,
     contextOfItemsIn)
    {}

definitionalRepresentation::~definitionalRepresentation()
{
  delete name;
  delete items;
  delete contextOfItems;
}

int definitionalRepresentation::isA(int aType)
    { return ((aType == definitionalRepresentation_E) ||
	      (aType == representationParent_E));
    }

void definitionalRepresentation::printSelf()
{
  printf("DEFINITIONAL_REPRESENTATION");
  printf("(");
  printString(name);
  printf(",");
  items->printSelf();
  printf(",");
  contextOfItems->printSelf();
  printf(")");
}

/********************************************************************/

/* descriptiveParameter */

descriptiveParameter::descriptiveParameter(){}

descriptiveParameter::descriptiveParameter(
 char * parameterNameIn,
 char * descriptiveStringIn) :
   propertyParameter(
     parameterNameIn)
{
   descriptiveString = descriptiveStringIn;
}

descriptiveParameter::~descriptiveParameter()
{
  delete parameterName;
  delete descriptiveString;
}

int descriptiveParameter::isA(int aType)
    { return ((aType == descriptiveParameter_E) ||
	      (aType == propertyParameter_E));
    }

void descriptiveParameter::printSelf()
{
  printf("DESCRIPTIVE_PARAMETER");
  printf("(");
  printString(parameterName);
  printf(",");
  printString(descriptiveString);
  printf(")");
}

/********************************************************************/

/* diameterTaper */

diameterTaper::diameterTaper(){}

diameterTaper::diameterTaper(
 tolerancedLengthMeasure * finalDiameterIn)
{
  finalDiameter = finalDiameterIn;
}

diameterTaper::~diameterTaper()
{
}

int diameterTaper::isA(int aType)
    { return ((aType == diameterTaper_E) ||
	      (aType == taperSelect_E));
    }

void diameterTaper::printSelf()
{
  printf("DIAMETER_TAPER");
  printf("(");
  finalDiameter->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* displayMessage */

displayMessage::displayMessage(){}

displayMessage::displayMessage(
 char * itsIdIn,
 char * itsTextIn) :
   ncFunction(
     itsIdIn)
{
   itsText = itsTextIn;
}

displayMessage::~displayMessage()
{
  delete itsId;
  delete itsText;
}

int displayMessage::isA(int aType)
    { return ((aType == displayMessage_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void displayMessage::printSelf()
{
  printf("DISPLAY_MESSAGE");
  printf("(");
  printString(itsId);
  printf(",");
  printString(itsText);
  printf(")");
}

/********************************************************************/

/* edge */

edge::edge(){}

edge::edge(
 char * nameIn,
 vertex * edgeStartIn,
 vertex * edgeEndIn) :
   topologicalRepresentationItem(
     nameIn)
{
   edgeStart = edgeStartIn;
   edgeEnd = edgeEndIn;
}

edge::~edge(){}

int edge::isA(int aType)
    { return ((aType == edge_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* edgeCurve */

edgeCurve::edgeCurve(){}

edgeCurve::edgeCurve(
 char * nameIn,
 vertex * edgeStartIn,
 vertex * edgeEndIn,
 curve * edgeGeometryIn,
 boolean * sameSenseIn) :
   edge(
     nameIn,
     edgeStartIn,
     edgeEndIn)
{
   edgeGeometry = edgeGeometryIn;
   sameSense = sameSenseIn;
}

edgeCurve::~edgeCurve()
{
  delete name;
  delete sameSense;
}

int edgeCurve::isA(int aType)
    { return ((aType == edgeCurve_E) ||
	      (aType == edge_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void edgeCurve::printSelf()
{
  printf("EDGE_CURVE");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(edgeStart))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(edgeEnd))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(edgeGeometry))->iId->printSelf();
  printf(",");
  sameSense->printSelf();
  printf(")");
}

/********************************************************************/

/* edgeRound */

edgeRound::edgeRound(){}

edgeRound::edgeRound(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 machiningFeature * firstFeatureIn,
 machiningFeature * secondFeatureIn,
 tolerancedLengthMeasure * radiusIn,
 tolerancedLengthMeasure * firstOffsetAmountIn,
 tolerancedLengthMeasure * secondOffsetAmountIn) :
   transitionFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     firstFeatureIn,
     secondFeatureIn)
{
   radius = radiusIn;
   firstOffsetAmount = firstOffsetAmountIn;
   secondOffsetAmount = secondOffsetAmountIn;
}

edgeRound::~edgeRound()
{
  delete itsId;
  delete itsOperations;
}

int edgeRound::isA(int aType)
    { return ((aType == edgeRound_E) ||
	      (aType == transitionFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == manufacturingFeature_E));
    }

void edgeRound::printSelf()
{
  printf("EDGE_ROUND");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  (dynamic_cast<instance *>(firstFeature))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(secondFeature))->iId->printSelf();
  printf(",");
  radius->iId->printSelf();
  printf(",");
  if (firstOffsetAmount)
    firstOffsetAmount->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (secondOffsetAmount)
    secondOffsetAmount->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* exchangePallet */

exchangePallet::exchangePallet(){}

exchangePallet::exchangePallet(
 char * itsIdIn) :
   ncFunction(
     itsIdIn)
    {}

exchangePallet::~exchangePallet()
{
  delete itsId;
}

int exchangePallet::isA(int aType)
    { return ((aType == exchangePallet_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void exchangePallet::printSelf()
{
  printf("EXCHANGE_PALLET");
  printf("(");
  printString(itsId);
  printf(")");
}

/********************************************************************/

/* explicitStrategy */

explicitStrategy::explicitStrategy(){}

explicitStrategy::explicitStrategy(
 real * overlapIn,
 boolean * allowMultiplePassesIn) :
   two5DmillingStrategy(
     overlapIn,
     allowMultiplePassesIn)
    {}

explicitStrategy::~explicitStrategy()
{
  delete overlap;
  delete allowMultiplePasses;
}

int explicitStrategy::isA(int aType)
    { return ((aType == explicitStrategy_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void explicitStrategy::printSelf()
{
  printf("EXPLICIT_STRATEGY");
  printf("(");
  if (overlap)
    overlap->printSelf();
  else
    printf("$");
  printf(",");
  if (allowMultiplePasses)
    allowMultiplePasses->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* face */

face::face(){}

face::face(
 char * nameIn,
 parenFaceBoundListFull * boundsIn) :
   topologicalRepresentationItem(
     nameIn)
{
   bounds = boundsIn;
}

face::~face(){}

int face::isA(int aType)
    { return ((aType == face_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* faceBoundParent */

faceBoundParent::faceBoundParent(){}

faceBoundParent::faceBoundParent(
 char * nameIn,
 loop * boundIn,
 boolean * orientationIn) :
   topologicalRepresentationItem(
     nameIn)
{
   bound = boundIn;
   orientation = orientationIn;
}

faceBoundParent::~faceBoundParent(){}

int faceBoundParent::isA(int aType)
    { return ((aType == faceBoundParent_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* faceBound */

faceBound::faceBound(){}

faceBound::faceBound(
 char * nameIn,
 loop * boundIn,
 boolean * orientationIn) :
   faceBoundParent(
     nameIn,
     boundIn,
     orientationIn)
    {}

faceBound::~faceBound()
{
  delete name;
  delete orientation;
}

int faceBound::isA(int aType)
    { return ((aType == faceBound_E) ||
	      (aType == faceBoundParent_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void faceBound::printSelf()
{
  printf("FACE_BOUND");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(bound))->iId->printSelf();
  printf(",");
  orientation->printSelf();
  printf(")");
}

/********************************************************************/

/* faceOuterBound */

faceOuterBound::faceOuterBound(){}

faceOuterBound::faceOuterBound(
 char * nameIn,
 loop * boundIn,
 boolean * orientationIn) :
   faceBoundParent(
     nameIn,
     boundIn,
     orientationIn)
    {}

faceOuterBound::~faceOuterBound()
{
  delete name;
  delete orientation;
}

int faceOuterBound::isA(int aType)
    { return ((aType == faceOuterBound_E) ||
	      (aType == faceBoundParent_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void faceOuterBound::printSelf()
{
  printf("FACE_OUTER_BOUND");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(bound))->iId->printSelf();
  printf(",");
  orientation->printSelf();
  printf(")");
}

/********************************************************************/

/* faceSurface */

faceSurface::faceSurface(){}

faceSurface::faceSurface(
 char * nameIn,
 parenFaceBoundListFull * boundsIn,
 surface * faceGeometryIn,
 boolean * sameSenseIn) :
   face(
     nameIn,
     boundsIn)
{
   faceGeometry = faceGeometryIn;
   sameSense = sameSenseIn;
}

faceSurface::~faceSurface(){}

int faceSurface::isA(int aType)
    { return ((aType == faceSurface_E) ||
	      (aType == face_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* feedstop */

feedstop::feedstop(){}

feedstop::feedstop(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 double dwellIn) :
   toolpath(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn)
{
   dwell = dwellIn;
}

feedstop::~feedstop()
{
  delete itsPriority;
  delete itsType;
}

int feedstop::isA(int aType)
    { return ((aType == feedstop_E) ||
	      (aType == toolpath_E));
    }

void feedstop::printSelf()
{
  printf("FEEDSTOP");
  printf("(");
  itsPriority->printSelf();
  printf(",");
  itsType->printSelf();
  printf(",");
  if (itsSpeed)
    itsSpeed->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachineFunctions)
    (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(dwell);
  printf(")");
}

/********************************************************************/

/* fiveAxesVarTiltYaw */

fiveAxesVarTiltYaw::fiveAxesVarTiltYaw(){}


fiveAxesVarTiltYaw::~fiveAxesVarTiltYaw()
{
}

int fiveAxesVarTiltYaw::isA(int aType)
    { return ((aType == fiveAxesVarTiltYaw_E) ||
	      (aType == toolDirectionForMilling_E));
    }

void fiveAxesVarTiltYaw::printSelf()
{
  printf("FIVE_AXES_VAR_TILT_YAW");
  printf("(");
  printf(")");
}

/********************************************************************/

/* fiveAxesConstTiltYaw */

fiveAxesConstTiltYaw::fiveAxesConstTiltYaw(){}

fiveAxesConstTiltYaw::fiveAxesConstTiltYaw(
 double tiltAngleIn,
 double yawAngleIn)
{
  tiltAngle = tiltAngleIn;
  yawAngle = yawAngleIn;
}

fiveAxesConstTiltYaw::~fiveAxesConstTiltYaw()
{
}

int fiveAxesConstTiltYaw::isA(int aType)
    { return ((aType == fiveAxesConstTiltYaw_E) ||
	      (aType == toolDirectionForMilling_E));
    }

void fiveAxesConstTiltYaw::printSelf()
{
  printf("FIVE_AXES_CONST_TILT_YAW");
  printf("(");
  printDouble(tiltAngle);
  printf(",");
  printDouble(yawAngle);
  printf(")");
}

/********************************************************************/

/* flatHoleBottom */

flatHoleBottom::flatHoleBottom(){}


flatHoleBottom::~flatHoleBottom()
{
}

int flatHoleBottom::isA(int aType)
    { return ((aType == flatHoleBottom_E) ||
	      (aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }

void flatHoleBottom::printSelf()
{
  printf("FLAT_HOLE_BOTTOM");
  printf("(");
  printf(")");
}

/********************************************************************/

/* flatSlotEndType */

flatSlotEndType::flatSlotEndType(){}

flatSlotEndType::flatSlotEndType(
 tolerancedLengthMeasure * cornerRadius1In,
 tolerancedLengthMeasure * cornerRadius2In)
{
  cornerRadius1 = cornerRadius1In;
  cornerRadius2 = cornerRadius2In;
}

flatSlotEndType::~flatSlotEndType()
{
}

int flatSlotEndType::isA(int aType)
    { return ((aType == flatSlotEndType_E) ||
	      (aType == slotEndType_E));
    }

void flatSlotEndType::printSelf()
{
  printf("FLAT_SLOT_END_TYPE");
  printf("(");
  cornerRadius1->iId->printSelf();
  printf(",");
  cornerRadius2->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* flatWithRadiusHoleBottom */

flatWithRadiusHoleBottom::flatWithRadiusHoleBottom(){}

flatWithRadiusHoleBottom::flatWithRadiusHoleBottom(
 tolerancedLengthMeasure * cornerRadiusIn)
{
  cornerRadius = cornerRadiusIn;
}

flatWithRadiusHoleBottom::~flatWithRadiusHoleBottom()
{
}

int flatWithRadiusHoleBottom::isA(int aType)
    { return ((aType == flatWithRadiusHoleBottom_E) ||
	      (aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }

void flatWithRadiusHoleBottom::printSelf()
{
  printf("FLAT_WITH_RADIUS_HOLE_BOTTOM");
  printf("(");
  cornerRadius->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* generalClosedProfile */

generalClosedProfile::generalClosedProfile(){}

generalClosedProfile::generalClosedProfile(
 axis2placement3d * placementIn,
 boundedCurve * closedProfileShapeIn) :
   closedProfile(
     placementIn)
{
   closedProfileShape = closedProfileShapeIn;
}

generalClosedProfile::~generalClosedProfile()
{
}

int generalClosedProfile::isA(int aType)
    { return ((aType == generalClosedProfile_E) ||
	      (aType == closedProfile_E) ||
	      (aType == profile_E));
    }

void generalClosedProfile::printSelf()
{
  printf("GENERAL_CLOSED_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(closedProfileShape))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* generalPath */

generalPath::generalPath(){}

generalPath::generalPath(
 axis2placement3d * placementIn,
 boundedCurve * sweptPathIn) :
   travelPath(
     placementIn)
{
   sweptPath = sweptPathIn;
}

generalPath::~generalPath()
{
}

int generalPath::isA(int aType)
    { return ((aType == generalPath_E) ||
	      (aType == travelPath_E));
    }

void generalPath::printSelf()
{
  printf("GENERAL_PATH");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(sweptPath))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* generalPocketBottomCondition */

generalPocketBottomCondition::generalPocketBottomCondition(){}

generalPocketBottomCondition::generalPocketBottomCondition(
 region * shapeIn)
{
  shape = shapeIn;
}

generalPocketBottomCondition::~generalPocketBottomCondition()
{
}

int generalPocketBottomCondition::isA(int aType)
    { return ((aType == generalPocketBottomCondition_E) ||
	      (aType == pocketBottomCondition_E));
    }

void generalPocketBottomCondition::printSelf()
{
  printf("GENERAL_POCKET_BOTTOM_CONDITION");
  printf("(");
  (dynamic_cast<instance *>(shape))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* geometricRepresentationItem */

geometricRepresentationItem::geometricRepresentationItem(){}

geometricRepresentationItem::geometricRepresentationItem(
 char * nameIn) :
   representationItem(
     nameIn)
    {}

geometricRepresentationItem::~geometricRepresentationItem(){}

int geometricRepresentationItem::isA(int aType)
    { return ((aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* ifStatement */

ifStatement::ifStatement(){}

ifStatement::ifStatement(
 char * itsIdIn,
 booleanExpression * conditionIn,
 executable * trueBranchIn,
 executable * falseBranchIn) :
   programStructure(
     itsIdIn)
{
   condition = conditionIn;
   trueBranch = trueBranchIn;
   falseBranch = falseBranchIn;
}

ifStatement::~ifStatement()
{
  delete itsId;
}

int ifStatement::isA(int aType)
    { return ((aType == ifStatement_E) ||
	      (aType == programStructure_E) ||
	      (aType == executable_E));
    }

void ifStatement::printSelf()
{
  printf("IF_STATEMENT");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(condition))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(trueBranch))->iId->printSelf();
  printf(",");
  if (falseBranch)
    (dynamic_cast<instance *>(falseBranch))->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* indexPallet */

indexPallet::indexPallet(){}

indexPallet::indexPallet(
 char * itsIdIn,
 int its_indexIn) :
   ncFunction(
     itsIdIn)
{
   its_index = its_indexIn;
}

indexPallet::~indexPallet()
{
  delete itsId;
}

int indexPallet::isA(int aType)
    { return ((aType == indexPallet_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void indexPallet::printSelf()
{
  printf("INDEX_PALLET");
  printf("(");
  printString(itsId);
  printf(",");
  printf("%d", its_index);
  printf(")");
}

/********************************************************************/

/* indexTable */

indexTable::indexTable(){}

indexTable::indexTable(
 char * itsIdIn,
 int its_indexIn) :
   ncFunction(
     itsIdIn)
{
   its_index = its_indexIn;
}

indexTable::~indexTable()
{
  delete itsId;
}

int indexTable::isA(int aType)
    { return ((aType == indexTable_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void indexTable::printSelf()
{
  printf("INDEX_TABLE");
  printf("(");
  printString(itsId);
  printf(",");
  printf("%d", its_index);
  printf(")");
}

/********************************************************************/

/* limitsAndFits */

limitsAndFits::limitsAndFits(){}

limitsAndFits::limitsAndFits(
 double deviationIn,
 double gradeIn,
 fittingType * itsFittingTypeIn)
{
  deviation = deviationIn;
  grade = gradeIn;
  itsFittingType = itsFittingTypeIn;
}

limitsAndFits::~limitsAndFits()
{
  delete itsFittingType;
}

int limitsAndFits::isA(int aType)
    { return ((aType == limitsAndFits_E) ||
	      (aType == toleranceSelect_E));
    }

void limitsAndFits::printSelf()
{
  printf("LIMITSANDFITS");
  printf("(");
  printDouble(deviation);
  printf(",");
  printDouble(grade);
  printf(",");
  if (itsFittingType)
    itsFittingType->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* linearPath */

linearPath::linearPath(){}

linearPath::linearPath(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * distanceIn,
 direction * itsDirectionIn) :
   travelPath(
     placementIn)
{
   distance = distanceIn;
   itsDirection = itsDirectionIn;
}

linearPath::~linearPath()
{
}

int linearPath::isA(int aType)
    { return ((aType == linearPath_E) ||
	      (aType == travelPath_E));
    }

void linearPath::printSelf()
{
  printf("LINEAR_PATH");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  distance->iId->printSelf();
  printf(",");
  itsDirection->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* loadTool */

loadTool::loadTool(){}

loadTool::loadTool(
 char * itsIdIn,
 machiningTool * itsToolIn) :
   ncFunction(
     itsIdIn)
{
   itsTool = itsToolIn;
}

loadTool::~loadTool()
{
  delete itsId;
}

int loadTool::isA(int aType)
    { return ((aType == loadTool_E) ||
	      (aType == ncFunction_E) ||
	      (aType == executable_E));
    }

void loadTool::printSelf()
{
  printf("LOAD_TOOL");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* loop */

loop::loop(){}

loop::loop(
 char * nameIn) :
   topologicalRepresentationItem(
     nameIn)
    {}

loop::~loop(){}

int loop::isA(int aType)
    { return ((aType == loop_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* loopSlotEndType */

loopSlotEndType::loopSlotEndType(){}


loopSlotEndType::~loopSlotEndType()
{
}

int loopSlotEndType::isA(int aType)
    { return ((aType == loopSlotEndType_E) ||
	      (aType == slotEndType_E));
    }

void loopSlotEndType::printSelf()
{
  printf("LOOP_SLOT_END_TYPE");
  printf("(");
  printf(")");
}

/********************************************************************/

/* machiningFeature */

machiningFeature::machiningFeature(){}

machiningFeature::machiningFeature(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn) :
   two5DmanufacturingFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn)
{
   depth = depthIn;
}

machiningFeature::~machiningFeature(){}

int machiningFeature::isA(int aType)
    { return ((aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* machiningOperation */

machiningOperation::machiningOperation(){}

machiningOperation::machiningOperation(
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn,
 char * itsIdIn,
 real * retractPlaneIn,
 cartesianPoint * startPointIn,
 machiningTool * itsToolIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn) :
   operation(
     itsToolpathIn,
     itsToolDirectionIn)
{
   itsId = itsIdIn;
   retractPlane = retractPlaneIn;
   startPoint = startPointIn;
   itsTool = itsToolIn;
   itsTechnology = itsTechnologyIn;
   itsMachineFunctions = itsMachineFunctionsIn;
}

machiningOperation::~machiningOperation(){}

int machiningOperation::isA(int aType)
    { return ((aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* machiningWorkingstep */

machiningWorkingstep::machiningWorkingstep(){}

machiningWorkingstep::machiningWorkingstep(
 char * itsIdIn,
 elementarySurface * itsSecplaneIn,
 manufacturingFeature * itsFeatureIn,
 machiningOperation * itsOperationIn,
 inProcessGeometry * itsEffectIn) :
   workingstep(
     itsIdIn,
     itsSecplaneIn)
{
   itsFeature = itsFeatureIn;
   itsOperation = itsOperationIn;
   itsEffect = itsEffectIn;
}

machiningWorkingstep::~machiningWorkingstep()
{
  delete itsId;
}

int machiningWorkingstep::isA(int aType)
    { return ((aType == machiningWorkingstep_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }

void machiningWorkingstep::printSelf()
{
  printf("MACHINING_WORKINGSTEP");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(itsSecplane))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsFeature))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsOperation))->iId->printSelf();
  printf(",");
  if (itsEffect)
    itsEffect->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* millingCuttingTool */

millingCuttingTool::millingCuttingTool(){}

millingCuttingTool::millingCuttingTool(
 char * itsIdIn,
 toolBody * itsToolBodyIn,
 parenCuttingComponentListFull * itsCuttingEdgeIn,
 real * overallAssemblyLengthIn,
 direction * directionForSpindleOrientationIn,
 real * toolHolderDiameterForSpindleOrientationIn) :
   cuttingTool(
     itsIdIn,
     itsToolBodyIn,
     itsCuttingEdgeIn,
     overallAssemblyLengthIn)
{
   directionForSpindleOrientation = directionForSpindleOrientationIn;
   toolHolderDiameterForSpindleOrientation = toolHolderDiameterForSpindleOrientationIn;
}

millingCuttingTool::~millingCuttingTool()
{
  delete itsId;
  delete itsCuttingEdge;
  delete overallAssemblyLength;
  delete toolHolderDiameterForSpindleOrientation;
}

int millingCuttingTool::isA(int aType)
    { return ((aType == millingCuttingTool_E) ||
	      (aType == cuttingTool_E) ||
	      (aType == machiningTool_E));
    }

void millingCuttingTool::printSelf()
{
  printf("MILLING_CUTTING_TOOL");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(itsToolBody))->iId->printSelf();
  printf(",");
  itsCuttingEdge->printSelf();
  printf(",");
  if (overallAssemblyLength)
    overallAssemblyLength->printSelf();
  else
    printf("$");
  printf(",");
  if (directionForSpindleOrientation)
    directionForSpindleOrientation->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (toolHolderDiameterForSpindleOrientation)
    toolHolderDiameterForSpindleOrientation->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* millingMachiningOperation */

millingMachiningOperation::millingMachiningOperation(){}

millingMachiningOperation::millingMachiningOperation(
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn,
 char * itsIdIn,
 real * retractPlaneIn,
 cartesianPoint * startPointIn,
 machiningTool * itsToolIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 real * overcutLengthIn) :
   machiningOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn)
{
   overcutLength = overcutLengthIn;
}

millingMachiningOperation::~millingMachiningOperation(){}

int millingMachiningOperation::isA(int aType)
    { return ((aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* millingTechnology */

millingTechnology::millingTechnology(){}

millingTechnology::millingTechnology(
 real * feedrateIn,
 toolReferencePoint * feedrateReferenceIn,
 real * cutspeedIn,
 real * spindleIn,
 real * feedratePerToothIn,
 boolean * synchronizeSpindleWithFeedIn,
 boolean * inhibitFeedrateOverrideIn,
 boolean * inhibitSpindleOverrideIn,
 boolean * itsAdaptiveControlIn) :
   technology(
     feedrateIn,
     feedrateReferenceIn)
{
   cutspeed = cutspeedIn;
   spindle = spindleIn;
   feedratePerTooth = feedratePerToothIn;
   synchronizeSpindleWithFeed = synchronizeSpindleWithFeedIn;
   inhibitFeedrateOverride = inhibitFeedrateOverrideIn;
   inhibitSpindleOverride = inhibitSpindleOverrideIn;
   itsAdaptiveControl = itsAdaptiveControlIn;
}

millingTechnology::~millingTechnology()
{
  delete feedrate;
  delete feedrateReference;
  delete cutspeed;
  delete spindle;
  delete feedratePerTooth;
  delete synchronizeSpindleWithFeed;
  delete inhibitFeedrateOverride;
  delete inhibitSpindleOverride;
  delete itsAdaptiveControl;
}

int millingTechnology::isA(int aType)
    { return ((aType == millingTechnology_E) ||
	      (aType == technology_E));
    }

void millingTechnology::printSelf()
{
  printf("MILLING_TECHNOLOGY");
  printf("(");
  if (feedrate)
    feedrate->printSelf();
  else
    printf("$");
  printf(",");
  feedrateReference->printSelf();
  printf(",");
  if (cutspeed)
    cutspeed->printSelf();
  else
    printf("$");
  printf(",");
  if (spindle)
    spindle->printSelf();
  else
    printf("$");
  printf(",");
  if (feedratePerTooth)
    feedratePerTooth->printSelf();
  else
    printf("$");
  printf(",");
  synchronizeSpindleWithFeed->printSelf();
  printf(",");
  inhibitFeedrateOverride->printSelf();
  printf(",");
  inhibitSpindleOverride->printSelf();
  printf(",");
  if (itsAdaptiveControl)
    itsAdaptiveControl->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* millingToolBody */

millingToolBody::millingToolBody(){}

millingToolBody::millingToolBody(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn)
{
  dimension = dimensionIn;
  numberOfTeeth = numberOfTeethIn;
  handOfCut = handOfCutIn;
  coolantThroughTool = coolantThroughToolIn;
  pilotLength = pilotLengthIn;
}

millingToolBody::~millingToolBody(){}

int millingToolBody::isA(int aType)
    { return ((aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

/********************************************************************/

/* millingTypeOperation */

millingTypeOperation::millingTypeOperation(){}

millingTypeOperation::millingTypeOperation(
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
 approachRetractStrategy * retractIn) :
   millingMachiningOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn)
{
   approach = approachIn;
   retract = retractIn;
}

millingTypeOperation::~millingTypeOperation(){}

int millingTypeOperation::isA(int aType)
    { return ((aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* ncConstant */

ncConstant::ncConstant(){}

ncConstant::ncConstant(
 char * itsNameIn,
 real * initialValueIn)
{
  itsName = itsNameIn;
  initialValue = initialValueIn;
}

ncConstant::~ncConstant()
{
  delete itsName;
  delete initialValue;
}

int ncConstant::isA(int aType)
    { return ((aType == ncConstant_E) ||
	      (aType == rvalue_E));
    }

void ncConstant::printSelf()
{
  printf("NC_CONSTANT");
  printf("(");
  printString(itsName);
  printf(",");
  if (initialValue)
    initialValue->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* ncVariable */

ncVariable::ncVariable(){}

ncVariable::ncVariable(
 char * itsNameIn,
 real * initialValueIn)
{
  itsName = itsNameIn;
  initialValue = initialValueIn;
}

ncVariable::~ncVariable()
{
  delete itsName;
  delete initialValue;
}

int ncVariable::isA(int aType)
    { return ((aType == ncVariable_E) ||
	      (aType == rvalue_E));
    }

void ncVariable::printSelf()
{
  printf("NC_VARIABLE");
  printf("(");
  printString(itsName);
  printf(",");
  if (initialValue)
    initialValue->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* ngonClosedProfile */

ngonClosedProfile::ngonClosedProfile(){}

ngonClosedProfile::ngonClosedProfile(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * diameterIn,
 int numberOfSidesIn,
 boolean * circumscribedOrAcrossFlatsIn) :
   closedProfile(
     placementIn)
{
   diameter = diameterIn;
   numberOfSides = numberOfSidesIn;
   circumscribedOrAcrossFlats = circumscribedOrAcrossFlatsIn;
}

ngonClosedProfile::~ngonClosedProfile()
{
  delete circumscribedOrAcrossFlats;
}

int ngonClosedProfile::isA(int aType)
    { return ((aType == ngonClosedProfile_E) ||
	      (aType == closedProfile_E) ||
	      (aType == profile_E));
    }

void ngonClosedProfile::printSelf()
{
  printf("NGON_CLOSED_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  diameter->iId->printSelf();
  printf(",");
  printf("%d", numberOfSides);
  printf(",");
  circumscribedOrAcrossFlats->printSelf();
  printf(")");
}

/********************************************************************/

/* nonSequential */

nonSequential::nonSequential(){}

nonSequential::nonSequential(
 char * itsIdIn,
 parenExecutableListFull * itsElementsIn) :
   programStructure(
     itsIdIn)
{
   itsElements = itsElementsIn;
}

nonSequential::~nonSequential()
{
  delete itsId;
  delete itsElements;
}

int nonSequential::isA(int aType)
    { return ((aType == nonSequential_E) ||
	      (aType == programStructure_E) ||
	      (aType == executable_E));
    }

void nonSequential::printSelf()
{
  printf("NON_SEQUENTIAL");
  printf("(");
  printString(itsId);
  printf(",");
  itsElements->printSelf();
  printf(")");
}

/********************************************************************/

/* notExpression */

notExpression::notExpression(){}

notExpression::notExpression(
 booleanExpression * operandIn) :
   unaryBooleanExpression(
     operandIn)
    {}

notExpression::~notExpression()
{
}

int notExpression::isA(int aType)
    { return ((aType == notExpression_E) ||
	      (aType == unaryBooleanExpression_E) ||
	      (aType == booleanExpression_E));
    }

void notExpression::printSelf()
{
  printf("NOT_EXPRESSION");
  printf("(");
  (dynamic_cast<instance *>(operand))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* numericParameter */

numericParameter::numericParameter(){}

numericParameter::numericParameter(
 char * parameterNameIn,
 double itsParameterValueIn,
 char * itsParameterUnitIn) :
   propertyParameter(
     parameterNameIn)
{
   itsParameterValue = itsParameterValueIn;
   itsParameterUnit = itsParameterUnitIn;
}

numericParameter::~numericParameter()
{
  delete parameterName;
  delete itsParameterUnit;
}

int numericParameter::isA(int aType)
    { return ((aType == numericParameter_E) ||
	      (aType == propertyParameter_E));
    }

void numericParameter::printSelf()
{
  printf("NUMERIC_PARAMETER");
  printf("(");
  printString(parameterName);
  printf(",");
  printDouble(itsParameterValue);
  printf(",");
  printString(itsParameterUnit);
  printf(")");
}

/********************************************************************/

/* openProfile */

openProfile::openProfile(){}

openProfile::openProfile(
 axis2placement3d * placementIn) :
   profile(
     placementIn)
    {}

openProfile::~openProfile(){}

int openProfile::isA(int aType)
    { return ((aType == openProfile_E) ||
	      (aType == profile_E));
    }

/********************************************************************/

/* openShellParent */

openShellParent::openShellParent(){}

openShellParent::openShellParent(
 char * nameIn,
 parenFaceListFull * cfsFacesIn) :
   connectedFaceSet(
     nameIn,
     cfsFacesIn)
    {}

openShellParent::~openShellParent(){}

int openShellParent::isA(int aType)
    { return ((aType == openShellParent_E) ||
	      (aType == connectedFaceSet_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* openShell */

openShell::openShell(){}

openShell::openShell(
 char * nameIn,
 parenFaceListFull * cfsFacesIn) :
   openShellParent(
     nameIn,
     cfsFacesIn)
    {}

openShell::~openShell()
{
  delete name;
  delete cfsFaces;
}

int openShell::isA(int aType)
    { return ((aType == openShell_E) ||
	      (aType == openShellParent_E) ||
	      (aType == connectedFaceSet_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void openShell::printSelf()
{
  printf("OPEN_SHELL");
  printf("(");
  printString(name);
  printf(",");
  cfsFaces->printSelf();
  printf(")");
}

/********************************************************************/

/* openSlotEndType */

openSlotEndType::openSlotEndType(){}


openSlotEndType::~openSlotEndType()
{
}

int openSlotEndType::isA(int aType)
    { return ((aType == openSlotEndType_E) ||
	      (aType == slotEndType_E));
    }

void openSlotEndType::printSelf()
{
  printf("OPEN_SLOT_END_TYPE");
  printf("(");
  printf(")");
}

/********************************************************************/

/* orientedEdge */

orientedEdge::orientedEdge(){}

orientedEdge::orientedEdge(
 char * nameIn,
 vertex * edgeStartIn,
 vertex * edgeEndIn,
 edge * edgeElementIn,
 boolean * orientationIn) :
   edge(
     nameIn,
     edgeStartIn,
     edgeEndIn)
{
   edgeElement = edgeElementIn;
   orientation = orientationIn;
}

orientedEdge::~orientedEdge()
{
  delete name;
  delete orientation;
}

int orientedEdge::isA(int aType)
    { return ((aType == orientedEdge_E) ||
	      (aType == edge_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void orientedEdge::printSelf()
{
  printf("ORIENTED_EDGE");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(edgeStart))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(edgeEnd))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(edgeElement))->iId->printSelf();
  printf(",");
  orientation->printSelf();
  printf(")");
}

/********************************************************************/

/* parallel */

parallel::parallel(){}

parallel::parallel(
 char * itsIdIn,
 parenExecutableListFull * branchesIn) :
   programStructure(
     itsIdIn)
{
   branches = branchesIn;
}

parallel::~parallel()
{
  delete itsId;
  delete branches;
}

int parallel::isA(int aType)
    { return ((aType == parallel_E) ||
	      (aType == programStructure_E) ||
	      (aType == executable_E));
    }

void parallel::printSelf()
{
  printf("PARALLEL");
  printf("(");
  printString(itsId);
  printf(",");
  branches->printSelf();
  printf(")");
}

/********************************************************************/

/* parameterisedPath */

parameterisedPath::parameterisedPath(){}

parameterisedPath::parameterisedPath(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn) :
   toolpath(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn)
    {}

parameterisedPath::~parameterisedPath(){}

int parameterisedPath::isA(int aType)
    { return ((aType == parameterisedPath_E) ||
	      (aType == toolpath_E));
    }

/********************************************************************/

/* partialCircularPath */

partialCircularPath::partialCircularPath(){}

partialCircularPath::partialCircularPath(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * radiusIn,
 double sweepAngleIn) :
   circularPath(
     placementIn,
     radiusIn)
{
   sweepAngle = sweepAngleIn;
}

partialCircularPath::~partialCircularPath()
{
}

int partialCircularPath::isA(int aType)
    { return ((aType == partialCircularPath_E) ||
	      (aType == circularPath_E) ||
	      (aType == travelPath_E));
    }

void partialCircularPath::printSelf()
{
  printf("PARTIAL_CIRCULAR_PATH");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  radius->iId->printSelf();
  printf(",");
  printDouble(sweepAngle);
  printf(")");
}

/********************************************************************/

/* partialCircularProfile */

partialCircularProfile::partialCircularProfile(){}

partialCircularProfile::partialCircularProfile(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * radiusIn,
 double sweepAngleIn) :
   openProfile(
     placementIn)
{
   radius = radiusIn;
   sweepAngle = sweepAngleIn;
}

partialCircularProfile::~partialCircularProfile()
{
}

int partialCircularProfile::isA(int aType)
    { return ((aType == partialCircularProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }

void partialCircularProfile::printSelf()
{
  printf("PARTIAL_CIRCULAR_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  radius->iId->printSelf();
  printf(",");
  printDouble(sweepAngle);
  printf(")");
}

/********************************************************************/

/* placement */

placement::placement(){}

placement::placement(
 char * nameIn,
 cartesianPoint * locationIn) :
   geometricRepresentationItem(
     nameIn)
{
   location = locationIn;
}

placement::~placement(){}

int placement::isA(int aType)
    { return ((aType == placement_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* planarFace */

planarFace::planarFace(){}

planarFace::planarFace(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * courseOfTravelIn,
 linearProfile * removalBoundaryIn,
 closedProfile * faceBoundaryIn,
 parenBossList * itsBossIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   courseOfTravel = courseOfTravelIn;
   removalBoundary = removalBoundaryIn;
   faceBoundary = faceBoundaryIn;
   itsBoss = itsBossIn;
}

planarFace::~planarFace()
{
  delete itsId;
  delete itsOperations;
  delete itsBoss;
}

int planarFace::isA(int aType)
    { return ((aType == planarFace_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void planarFace::printSelf()
{
  printf("PLANAR_FACE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  courseOfTravel->iId->printSelf();
  printf(",");
  removalBoundary->iId->printSelf();
  printf(",");
  if (faceBoundary)
    (dynamic_cast<instance *>(faceBoundary))->iId->printSelf();
  else
    printf("$");
  printf(",");
  itsBoss->printSelf();
  printf(")");
}

/********************************************************************/

/* planarPocketBottomCondition */

planarPocketBottomCondition::planarPocketBottomCondition(){}


planarPocketBottomCondition::~planarPocketBottomCondition()
{
}

int planarPocketBottomCondition::isA(int aType)
    { return ((aType == planarPocketBottomCondition_E) ||
	      (aType == pocketBottomCondition_E));
    }

void planarPocketBottomCondition::printSelf()
{
  printf("PLANAR_POCKET_BOTTOM_CONDITION");
  printf("(");
  printf(")");
}

/********************************************************************/

/* plusMinusValue */

plusMinusValue::plusMinusValue(){}

plusMinusValue::plusMinusValue(
 double upperLimitIn,
 double lowerLimitIn,
 int significantDigitsIn)
{
  upperLimit = upperLimitIn;
  lowerLimit = lowerLimitIn;
  significantDigits = significantDigitsIn;
}

plusMinusValue::~plusMinusValue()
{
}

int plusMinusValue::isA(int aType)
    { return ((aType == plusMinusValue_E) ||
	      (aType == toleranceSelect_E));
    }

void plusMinusValue::printSelf()
{
  printf("PLUS_MINUS_VALUE");
  printf("(");
  printDouble(upperLimit);
  printf(",");
  printDouble(lowerLimit);
  printf(",");
  printf("%d", significantDigits);
  printf(")");
}

/********************************************************************/

/* pocket */

pocket::pocket(){}

pocket::pocket(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 parenBossList * itsBossIn,
 real * slopeIn,
 pocketBottomCondition * bottomConditionIn,
 tolerancedLengthMeasure * planarRadiusIn,
 tolerancedLengthMeasure * orthogonalRadiusIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   itsBoss = itsBossIn;
   slope = slopeIn;
   bottomCondition = bottomConditionIn;
   planarRadius = planarRadiusIn;
   orthogonalRadius = orthogonalRadiusIn;
}

pocket::~pocket(){}

int pocket::isA(int aType)
    { return ((aType == pocket_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* point */

point::point(){}

point::point(
 char * nameIn) :
   geometricRepresentationItem(
     nameIn)
    {}

point::~point(){}

int point::isA(int aType)
    { return ((aType == point_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* profileFeature */

profileFeature::profileFeature(){}

profileFeature::profileFeature(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * profileSweptShapeIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   profileSweptShape = profileSweptShapeIn;
}

profileFeature::~profileFeature(){}

int profileFeature::isA(int aType)
    { return ((aType == profileFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* profileFloor */

profileFloor::profileFloor(){}

profileFloor::profileFloor(
 real * floorRadiusIn,
 boolean * startOrEndIn)
{
  floorRadius = floorRadiusIn;
  startOrEnd = startOrEndIn;
}

profileFloor::~profileFloor(){}

int profileFloor::isA(int aType)
    { return ((aType == profileFloor_E) ||
	      (aType == profileSelect_E));
    }

/********************************************************************/

/* radiusedSlotEndType */

radiusedSlotEndType::radiusedSlotEndType(){}


radiusedSlotEndType::~radiusedSlotEndType()
{
}

int radiusedSlotEndType::isA(int aType)
    { return ((aType == radiusedSlotEndType_E) ||
	      (aType == slotEndType_E));
    }

void radiusedSlotEndType::printSelf()
{
  printf("RADIUSED_SLOT_END_TYPE");
  printf("(");
  printf(")");
}

/********************************************************************/

/* rapidMovement */

rapidMovement::rapidMovement(){}

rapidMovement::rapidMovement(
 char * itsIdIn,
 elementarySurface * itsSecplaneIn,
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn) :
   operation(
     itsToolpathIn,
     itsToolDirectionIn),
   workingstep(
     itsIdIn,
     itsSecplaneIn)
    {}

rapidMovement::~rapidMovement()
{
  delete itsId;
}

int rapidMovement::isA(int aType)
    { return ((aType == rapidMovement_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }

void rapidMovement::printSelf()
{
  printf("RAPID_MOVEMENT");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(itsSecplane))->iId->printSelf();
  printf(",");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* real */

real::real(){}

real::real(
 double valIn)
{
  val = valIn;
}

real::~real()
{
}

int real::isA(int aType)
    { return ((aType == real_E) ||
	      (aType == toolpathSpeedprofile_E) ||
	      (aType == trimmingSelect_E));
    }

void real::printSelf()
{
  printDouble(val);
}

/********************************************************************/

/* reamer */

reamer::reamer(){}

reamer::reamer(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

reamer::~reamer(){}

int reamer::isA(int aType)
    { return ((aType == reamer_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

/********************************************************************/

/* rectangularClosedProfile */

rectangularClosedProfile::rectangularClosedProfile(){}

rectangularClosedProfile::rectangularClosedProfile(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * profileWidthIn,
 tolerancedLengthMeasure * profileLengthIn) :
   closedProfile(
     placementIn)
{
   profileWidth = profileWidthIn;
   profileLength = profileLengthIn;
}

rectangularClosedProfile::~rectangularClosedProfile()
{
}

int rectangularClosedProfile::isA(int aType)
    { return ((aType == rectangularClosedProfile_E) ||
	      (aType == closedProfile_E) ||
	      (aType == profile_E));
    }

void rectangularClosedProfile::printSelf()
{
  printf("RECTANGULAR_CLOSED_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  profileWidth->iId->printSelf();
  printf(",");
  profileLength->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* replicateFeature */

replicateFeature::replicateFeature(){}

replicateFeature::replicateFeature(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 two5DmanufacturingFeature * replicateBaseFeatureIn) :
   two5DmanufacturingFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn)
{
   replicateBaseFeature = replicateBaseFeatureIn;
}

replicateFeature::~replicateFeature(){}

int replicateFeature::isA(int aType)
    { return ((aType == replicateFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* rightCircularCylinder */

rightCircularCylinder::rightCircularCylinder(){}

rightCircularCylinder::rightCircularCylinder(
 char * nameIn,
 axis1placement * positionIn,
 double heightIn,
 double radiusIn) :
   geometricRepresentationItem(
     nameIn)
{
   position = positionIn;
   height = heightIn;
   radius = radiusIn;
}

rightCircularCylinder::~rightCircularCylinder()
{
  delete name;
}

int rightCircularCylinder::isA(int aType)
    { return ((aType == rightCircularCylinder_E) ||
	      (aType == boundingGeometrySelect_E) ||
	      (aType == restrictedAreaSelect_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void rightCircularCylinder::printSelf()
{
  printf("RIGHT_CIRCULAR_CYLINDER");
  printf("(");
  printString(name);
  printf(",");
  position->iId->printSelf();
  printf(",");
  printDouble(height);
  printf(",");
  printDouble(radius);
  printf(")");
}

/********************************************************************/

/* roundedEnd */

roundedEnd::roundedEnd(){}

roundedEnd::roundedEnd(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * courseOfTravelIn,
 partialCircularProfile * partialCircularBoundaryIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   courseOfTravel = courseOfTravelIn;
   partialCircularBoundary = partialCircularBoundaryIn;
}

roundedEnd::~roundedEnd()
{
  delete itsId;
  delete itsOperations;
}

int roundedEnd::isA(int aType)
    { return ((aType == roundedEnd_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void roundedEnd::printSelf()
{
  printf("ROUNDED_END");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  courseOfTravel->iId->printSelf();
  printf(",");
  partialCircularBoundary->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* roundedUProfile */

roundedUProfile::roundedUProfile(){}

roundedUProfile::roundedUProfile(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * widthIn) :
   openProfile(
     placementIn)
{
   width = widthIn;
}

roundedUProfile::~roundedUProfile()
{
}

int roundedUProfile::isA(int aType)
    { return ((aType == roundedUProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }

void roundedUProfile::printSelf()
{
  printf("ROUNDED_U_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  width->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* roundHole */

roundHole::roundHole(){}

roundHole::roundHole(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 tolerancedLengthMeasure * diameterIn,
 taperSelect * changeInDiameterIn,
 holeBottomCondition * bottomConditionIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   diameter = diameterIn;
   changeInDiameter = changeInDiameterIn;
   bottomCondition = bottomConditionIn;
}

roundHole::~roundHole()
{
  delete itsId;
  delete itsOperations;
}

int roundHole::isA(int aType)
    { return ((aType == roundHole_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void roundHole::printSelf()
{
  printf("ROUND_HOLE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  diameter->iId->printSelf();
  printf(",");
  if (changeInDiameter)
    (dynamic_cast<instance *>(changeInDiameter))->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(bottomCondition))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* shapeProfile */

shapeProfile::shapeProfile(){}

shapeProfile::shapeProfile(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * profileSweptShapeIn,
 profileSelect * floorConditionIn,
 direction * removalDirectionIn) :
   profileFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     profileSweptShapeIn)
{
   floorCondition = floorConditionIn;
   removalDirection = removalDirectionIn;
}

shapeProfile::~shapeProfile(){}

int shapeProfile::isA(int aType)
    { return ((aType == shapeProfile_E) ||
	      (aType == profileFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* slot */

slot::slot(){}

slot::slot(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 travelPath * courseOfTravelIn,
 openProfile * sweptShapeIn,
 parenSlotEndTypeList * endConditionsIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   courseOfTravel = courseOfTravelIn;
   sweptShape = sweptShapeIn;
   endConditions = endConditionsIn;
}

slot::~slot()
{
  delete itsId;
  delete itsOperations;
  delete endConditions;
}

int slot::isA(int aType)
    { return ((aType == slot_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void slot::printSelf()
{
  printf("SLOT");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(courseOfTravel))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(sweptShape))->iId->printSelf();
  printf(",");
  endConditions->printSelf();
  printf(")");
}

/********************************************************************/

/* solidModel */

solidModel::solidModel(){}

solidModel::solidModel(
 char * nameIn) :
   geometricRepresentationItem(
     nameIn)
    {}

solidModel::~solidModel(){}

int solidModel::isA(int aType)
    { return ((aType == solidModel_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* speedName */

speedName::speedName(){}


speedName::~speedName()
{
}

int speedName::isA(int aType)
    { return ((aType == speedName_E) ||
	      (aType == toolpathSpeedprofile_E));
    }

void speedName::printSelf()
{
  printf(".RAPID.");
}

/********************************************************************/

/* sphericalCap */

sphericalCap::sphericalCap(){}

sphericalCap::sphericalCap(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 numericParameter * internalAngleIn,
 numericParameter * radiusIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   internalAngle = internalAngleIn;
   radius = radiusIn;
}

sphericalCap::~sphericalCap()
{
  delete itsId;
  delete itsOperations;
}

int sphericalCap::isA(int aType)
    { return ((aType == sphericalCap_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void sphericalCap::printSelf()
{
  printf("SPHERICAL_CAP");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  internalAngle->iId->printSelf();
  printf(",");
  radius->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* sphericalHoleBottom */

sphericalHoleBottom::sphericalHoleBottom(){}

sphericalHoleBottom::sphericalHoleBottom(
 tolerancedLengthMeasure * radiusIn)
{
  radius = radiusIn;
}

sphericalHoleBottom::~sphericalHoleBottom()
{
}

int sphericalHoleBottom::isA(int aType)
    { return ((aType == sphericalHoleBottom_E) ||
	      (aType == blindBottomCondition_E) ||
	      (aType == holeBottomCondition_E));
    }

void sphericalHoleBottom::printSelf()
{
  printf("SPHERICAL_HOLE_BOTTOM");
  printf("(");
  radius->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* squareUProfile */

squareUProfile::squareUProfile(){}

squareUProfile::squareUProfile(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * widthIn,
 tolerancedLengthMeasure * firstRadiusIn,
 double firstAngleIn,
 tolerancedLengthMeasure * secondRadiusIn,
 double secondAngleIn) :
   openProfile(
     placementIn)
{
   width = widthIn;
   firstRadius = firstRadiusIn;
   firstAngle = firstAngleIn;
   secondRadius = secondRadiusIn;
   secondAngle = secondAngleIn;
}

squareUProfile::~squareUProfile()
{
}

int squareUProfile::isA(int aType)
    { return ((aType == squareUProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }

void squareUProfile::printSelf()
{
  printf("SQUARE_U_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  width->iId->printSelf();
  printf(",");
  firstRadius->iId->printSelf();
  printf(",");
  printDouble(firstAngle);
  printf(",");
  secondRadius->iId->printSelf();
  printf(",");
  printDouble(secondAngle);
  printf(")");
}

/********************************************************************/

/* step */

step::step(){}

step::step(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * openBoundaryIn,
 veeProfile * wallBoundaryIn,
 parenBossList * itsBossIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   openBoundary = openBoundaryIn;
   wallBoundary = wallBoundaryIn;
   itsBoss = itsBossIn;
}

step::~step()
{
  delete itsId;
  delete itsOperations;
  delete itsBoss;
}

int step::isA(int aType)
    { return ((aType == step_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void step::printSelf()
{
  printf("STEP");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  openBoundary->iId->printSelf();
  printf(",");
  if (wallBoundary)
    wallBoundary->iId->printSelf();
  else
    printf("$");
  printf(",");
  itsBoss->printSelf();
  printf(")");
}

/********************************************************************/

/* surface */

surface::surface(){}

surface::surface(
 char * nameIn) :
   geometricRepresentationItem(
     nameIn)
    {}

surface::~surface(){}

int surface::isA(int aType)
    { return ((aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* sweptSurface */

sweptSurface::sweptSurface(){}

sweptSurface::sweptSurface(
 char * nameIn,
 curve * sweptCurveIn) :
   surface(
     nameIn)
{
   sweptCurve = sweptCurveIn;
}

sweptSurface::~sweptSurface(){}

int sweptSurface::isA(int aType)
    { return ((aType == sweptSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* tapParent */

tapParent::tapParent(){}

tapParent::tapParent(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

tapParent::~tapParent(){}

int tapParent::isA(int aType)
    { return ((aType == tapParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

/********************************************************************/

/* taperedReamer */

taperedReamer::taperedReamer(){}

taperedReamer::taperedReamer(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * taperAngleIn) :
   reamer(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   taperAngle = taperAngleIn;
}

taperedReamer::~taperedReamer()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete taperAngle;
}

int taperedReamer::isA(int aType)
    { return ((aType == taperedReamer_E) ||
	      (aType == reamer_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void taperedReamer::printSelf()
{
  printf("TAPERED_REAMER");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* teeProfile */

teeProfile::teeProfile(){}

teeProfile::teeProfile(
 axis2placement3d * placementIn,
 double firstAngleIn,
 double secondAngleIn,
 tolerancedLengthMeasure * crossBarWidthIn,
 tolerancedLengthMeasure * crossBarDepthIn,
 tolerancedLengthMeasure * radiusIn,
 tolerancedLengthMeasure * widthIn,
 tolerancedLengthMeasure * firstOffsetIn,
 tolerancedLengthMeasure * secondOffsetIn) :
   openProfile(
     placementIn)
{
   firstAngle = firstAngleIn;
   secondAngle = secondAngleIn;
   crossBarWidth = crossBarWidthIn;
   crossBarDepth = crossBarDepthIn;
   radius = radiusIn;
   width = widthIn;
   firstOffset = firstOffsetIn;
   secondOffset = secondOffsetIn;
}

teeProfile::~teeProfile()
{
}

int teeProfile::isA(int aType)
    { return ((aType == teeProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }

void teeProfile::printSelf()
{
  printf("TEE_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printDouble(firstAngle);
  printDouble(secondAngle);
  crossBarWidth->iId->printSelf();
  crossBarDepth->iId->printSelf();
  radius->iId->printSelf();
  width->iId->printSelf();
  firstOffset->iId->printSelf();
  secondOffset->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* thread */

thread::thread(){}

thread::thread(
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
 descriptiveParameter * threadHandIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   partialProfile = partialProfileIn;
   appliedShape = appliedShapeIn;
   innerOrOuterThread = innerOrOuterThreadIn;
   qualifier = qualifierIn;
   fitClass = fitClassIn;
   form = formIn;
   majorDiameter = majorDiameterIn;
   numberOfThreads = numberOfThreadsIn;
   threadHand = threadHandIn;
}

thread::~thread(){}

int thread::isA(int aType)
    { return ((aType == thread_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

/********************************************************************/

/* threeAxes */

threeAxes::threeAxes(){}


threeAxes::~threeAxes()
{
}

int threeAxes::isA(int aType)
    { return ((aType == threeAxes_E) ||
	      (aType == toolDirection_E));
    }

void threeAxes::printSelf()
{
  printf("THREE_AXES");
  printf("(");
  printf(")");
}

/********************************************************************/

/* threeAxesTiltedTool */

threeAxesTiltedTool::threeAxesTiltedTool(){}

threeAxesTiltedTool::threeAxesTiltedTool(
 direction * itsToolDirectionIn)
{
  itsToolDirection = itsToolDirectionIn;
}

threeAxesTiltedTool::~threeAxesTiltedTool()
{
}

int threeAxesTiltedTool::isA(int aType)
    { return ((aType == threeAxesTiltedTool_E) ||
	      (aType == toolDirectionForMilling_E));
    }

void threeAxesTiltedTool::printSelf()
{
  printf("THREE_AXES_TILTED_TOOL");
  printf("(");
  itsToolDirection->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* toolpathFeature */

toolpathFeature::toolpathFeature(){}

toolpathFeature::toolpathFeature(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
    {}

toolpathFeature::~toolpathFeature()
{
  delete itsId;
  delete itsOperations;
}

int toolpathFeature::isA(int aType)
    { return ((aType == toolpathFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void toolpathFeature::printSelf()
{
  printf("TOOLPATH_FEATURE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* toolpathSpeed */

toolpathSpeed::toolpathSpeed(){}

toolpathSpeed::toolpathSpeed(
 bSplineCurve * speedIn)
{
  speed = speedIn;
}

toolpathSpeed::~toolpathSpeed()
{
}

int toolpathSpeed::isA(int aType)
    { return ((aType == toolpathSpeed_E) ||
	      (aType == toolpathSpeedprofile_E));
    }

void toolpathSpeed::printSelf()
{
  printf("TOOLPATH_SPEED");
  printf("(");
  (dynamic_cast<instance *>(speed))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* topologicalRegion */

topologicalRegion::topologicalRegion(){}

topologicalRegion::topologicalRegion(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 char * nameIn,
 parenFaceListFull * cfsFacesIn) :
   openShellParent(
     nameIn,
     cfsFacesIn),
   region(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn)
    {}

topologicalRegion::~topologicalRegion()
{
  delete itsId;
  delete itsOperations;
  delete name;
  delete cfsFaces;
}

int topologicalRegion::isA(int aType)
    { return ((aType == topologicalRegion_E) ||
	      (aType == openShellParent_E) ||
	      (aType == connectedFaceSet_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E) ||
	      (aType == region_E) ||
	      (aType == manufacturingFeature_E));
    }

void topologicalRegion::printSelf()
{
  printf("TOPOLOGICAL_REGION");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  if (featurePlacement)
    featurePlacement->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(name);
  printf(",");
  cfsFaces->printSelf();
  printf(")");
}

/********************************************************************/

/* touchProbing */

touchProbing::touchProbing(){}

touchProbing::touchProbing(
 char * itsIdIn,
 elementarySurface * itsSecplaneIn,
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn,
 ncVariable * measuredOffsetIn) :
   operation(
     itsToolpathIn,
     itsToolDirectionIn),
   workingstep(
     itsIdIn,
     itsSecplaneIn)
{
   measuredOffset = measuredOffsetIn;
}

touchProbing::~touchProbing(){}

int touchProbing::isA(int aType)
    { return ((aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }

/********************************************************************/

/* two5DmillingOperation */

two5DmillingOperation::two5DmillingOperation(){}

two5DmillingOperation::two5DmillingOperation(
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
 two5DmillingStrategy * itsMachiningStrategyIn) :
   millingTypeOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn)
{
   itsMachiningStrategy = itsMachiningStrategyIn;
}

two5DmillingOperation::~two5DmillingOperation(){}

int two5DmillingOperation::isA(int aType)
    { return ((aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* userDefinedTool */

userDefinedTool::userDefinedTool(){}

userDefinedTool::userDefinedTool(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 char * identifierIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   identifier = identifierIn;
}

userDefinedTool::~userDefinedTool()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete identifier;
}

int userDefinedTool::isA(int aType)
    { return ((aType == userDefinedTool_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void userDefinedTool::printSelf()
{
  printf("USER_DEFINED_TOOL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  printString(identifier);
  printf(")");
}

/********************************************************************/

/* vector */

vector::vector(){}

vector::vector(
 char * nameIn,
 direction * orientationIn,
 double magnitudeIn) :
   geometricRepresentationItem(
     nameIn)
{
   orientation = orientationIn;
   magnitude = magnitudeIn;
}

vector::~vector()
{
  delete name;
}

int vector::isA(int aType)
    { return ((aType == vector_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void vector::printSelf()
{
  printf("VECTOR");
  printf("(");
  printString(name);
  printf(",");
  orientation->iId->printSelf();
  printf(",");
  printDouble(magnitude);
  printf(")");
}

/********************************************************************/

/* veeProfile */

veeProfile::veeProfile(){}

veeProfile::veeProfile(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * profileRadiusIn,
 double profileAngleIn,
 double tiltAngleIn) :
   openProfile(
     placementIn)
{
   profileRadius = profileRadiusIn;
   profileAngle = profileAngleIn;
   tiltAngle = tiltAngleIn;
}

veeProfile::~veeProfile()
{
}

int veeProfile::isA(int aType)
    { return ((aType == veeProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }

void veeProfile::printSelf()
{
  printf("VEE_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  profileRadius->iId->printSelf();
  printf(",");
  printDouble(profileAngle);
  printf(",");
  printDouble(tiltAngle);
  printf(")");
}

/********************************************************************/

/* vertexLoop */

vertexLoop::vertexLoop(){}

vertexLoop::vertexLoop(
 char * nameIn,
 vertex * loopVertexIn) :
   loop(
     nameIn)
{
   loopVertex = loopVertexIn;
}

vertexLoop::~vertexLoop()
{
  delete name;
}

int vertexLoop::isA(int aType)
    { return ((aType == vertexLoop_E) ||
	      (aType == loop_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void vertexLoop::printSelf()
{
  printf("VERTEX_LOOP");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(loopVertex))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* workpieceCompleteProbing */

workpieceCompleteProbing::workpieceCompleteProbing(){}

workpieceCompleteProbing::workpieceCompleteProbing(
 char * itsIdIn,
 elementarySurface * itsSecplaneIn,
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn,
 ncVariable * measuredOffsetIn,
 workpiece * itsWorkpieceIn,
 tolerancedLengthMeasure * probingDistanceIn,
 touchProbe * itsProbeIn,
 offsetVector * computedOffsetIn) :
   touchProbing(
     itsIdIn,
     itsSecplaneIn,
     itsToolpathIn,
     itsToolDirectionIn,
     measuredOffsetIn)
{
   itsWorkpiece = itsWorkpieceIn;
   probingDistance = probingDistanceIn;
   itsProbe = itsProbeIn;
   computedOffset = computedOffsetIn;
}

workpieceCompleteProbing::~workpieceCompleteProbing()
{
  delete itsId;
  delete computedOffset;
}

int workpieceCompleteProbing::isA(int aType)
    { return ((aType == workpieceCompleteProbing_E) ||
	      (aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }

void workpieceCompleteProbing::printSelf()
{
  printf("WORKPIECE_COMPLETE_PROBING");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(itsSecplane))->iId->printSelf();
  printf(",");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  measuredOffset->iId->printSelf();
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  probingDistance->iId->printSelf();
  printf(",");
  itsProbe->iId->printSelf();
  printf(",");
  computedOffset->printSelf();
  printf(")");
}

/********************************************************************/

/* workpieceProbing */

workpieceProbing::workpieceProbing(){}

workpieceProbing::workpieceProbing(
 char * itsIdIn,
 elementarySurface * itsSecplaneIn,
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn,
 ncVariable * measuredOffsetIn,
 axis2placement3d * startPositionIn,
 workpiece * itsWorkpieceIn,
 direction * itsDirectionIn,
 tolerancedLengthMeasure * expectedValueIn,
 touchProbe * itsProbeIn) :
   touchProbing(
     itsIdIn,
     itsSecplaneIn,
     itsToolpathIn,
     itsToolDirectionIn,
     measuredOffsetIn)
{
   startPosition = startPositionIn;
   itsWorkpiece = itsWorkpieceIn;
   itsDirection = itsDirectionIn;
   expectedValue = expectedValueIn;
   itsProbe = itsProbeIn;
}

workpieceProbing::~workpieceProbing()
{
  delete itsId;
}

int workpieceProbing::isA(int aType)
    { return ((aType == workpieceProbing_E) ||
	      (aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }

void workpieceProbing::printSelf()
{
  printf("WORKPIECE_PROBING");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(itsSecplane))->iId->printSelf();
  printf(",");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  measuredOffset->iId->printSelf();
  printf(",");
  startPosition->iId->printSelf();
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsDirection->iId->printSelf();
  printf(",");
  expectedValue->iId->printSelf();
  printf(",");
  itsProbe->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* xorExpression */

xorExpression::xorExpression(){}

xorExpression::xorExpression(
 booleanExpression * operand1In,
 booleanExpression * operand2In) :
   binaryBooleanExpression(
     operand1In,
     operand2In)
    {}

xorExpression::~xorExpression()
{
}

int xorExpression::isA(int aType)
    { return ((aType == xorExpression_E) ||
	      (aType == binaryBooleanExpression_E) ||
	      (aType == booleanExpression_E));
    }

void xorExpression::printSelf()
{
  printf("XOR_EXPRESSION");
  printf("(");
  (dynamic_cast<instance *>(operand1))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(operand2))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* advancedBrepShapeRepresentation */

advancedBrepShapeRepresentation::advancedBrepShapeRepresentation(){}

advancedBrepShapeRepresentation::advancedBrepShapeRepresentation(
 char * nameIn,
 parenRepresentationItemListFull * itemsIn,
 representationContext * contextOfItemsIn) :
   shapeRepresentationParent(
     nameIn,
     itemsIn,
     contextOfItemsIn)
    {}

advancedBrepShapeRepresentation::~advancedBrepShapeRepresentation()
{
  delete name;
  delete items;
  delete contextOfItems;
}

int advancedBrepShapeRepresentation::isA(int aType)
    { return ((aType == advancedBrepShapeRepresentation_E) ||
	      (aType == boundingGeometrySelect_E) ||
	      (aType == restrictedAreaSelect_E) ||
	      (aType == shapeRepresentationParent_E) ||
	      (aType == representationParent_E));
    }

void advancedBrepShapeRepresentation::printSelf()
{
  printf("ADVANCED_BREP_SHAPE_REPRESENTATION");
  printf("(");
  printString(name);
  printf(",");
  items->printSelf();
  printf(",");
  contextOfItems->printSelf();
  printf(")");
}

/********************************************************************/

/* advancedFace */

advancedFace::advancedFace(){}

advancedFace::advancedFace(
 char * nameIn,
 parenFaceBoundListFull * boundsIn,
 surface * faceGeometryIn,
 boolean * sameSenseIn) :
   faceSurface(
     nameIn,
     boundsIn,
     faceGeometryIn,
     sameSenseIn)
    {}

advancedFace::~advancedFace()
{
  delete name;
  delete bounds;
  delete sameSense;
}

int advancedFace::isA(int aType)
    { return ((aType == advancedFace_E) ||
	      (aType == faceSurface_E) ||
	      (aType == face_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void advancedFace::printSelf()
{
  printf("ADVANCED_FACE");
  printf("(");
  printString(name);
  printf(",");
  bounds->printSelf();
  printf(",");
  (dynamic_cast<instance *>(faceGeometry))->iId->printSelf();
  printf(",");
  sameSense->printSelf();
  printf(")");
}

/********************************************************************/

/* approachLiftPath */

approachLiftPath::approachLiftPath(){}

approachLiftPath::approachLiftPath(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 cartesianPoint * fixPointIn,
 direction * fixPointDirIn) :
   parameterisedPath(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn)
{
   fixPoint = fixPointIn;
   fixPointDir = fixPointDirIn;
}

approachLiftPath::~approachLiftPath(){}

int approachLiftPath::isA(int aType)
    { return ((aType == approachLiftPath_E) ||
	      (aType == parameterisedPath_E) ||
	      (aType == toolpath_E));
    }

/********************************************************************/

/* axis1placement */

axis1placement::axis1placement(){}

axis1placement::axis1placement(
 char * nameIn,
 cartesianPoint * locationIn,
 direction * axisIn) :
   placement(
     nameIn,
     locationIn)
{
   axis = axisIn;
}

axis1placement::~axis1placement()
{
  delete name;
}

int axis1placement::isA(int aType)
    { return ((aType == axis1placement_E) ||
	      (aType == placement_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void axis1placement::printSelf()
{
  printf("AXIS1_PLACEMENT");
  printf("(");
  printString(name);
  printf(",");
  location->iId->printSelf();
  printf(",");
  axis->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* axis2placement3d */

axis2placement3d::axis2placement3d(){}

axis2placement3d::axis2placement3d(
 char * nameIn,
 cartesianPoint * locationIn,
 direction * axisIn,
 direction * refDirectionIn) :
   placement(
     nameIn,
     locationIn)
{
   axis = axisIn;
   refDirection = refDirectionIn;
}

axis2placement3d::~axis2placement3d()
{
  delete name;
}

int axis2placement3d::isA(int aType)
    { return ((aType == axis2placement3d_E) ||
	      (aType == placement_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void axis2placement3d::printSelf()
{
  printf("AXIS2_PLACEMENT_3D");
  printf("(");
  printString(name);
  printf(",");
  location->iId->printSelf();
  printf(",");
  axis->iId->printSelf();
  printf(",");
  if (refDirection)
    refDirection->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* block */

block::block(){}

block::block(
 char * nameIn,
 axis2placement3d * positionIn,
 double xIn,
 double yIn,
 double zIn) :
   geometricRepresentationItem(
     nameIn)
{
   position = positionIn;
   x = xIn;
   y = yIn;
   z = zIn;
}

block::~block()
{
  delete name;
}

int block::isA(int aType)
    { return ((aType == block_E) ||
	      (aType == boundingGeometrySelect_E) ||
	      (aType == restrictedAreaSelect_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void block::printSelf()
{
  printf("BLOCK");
  printf("(");
  printString(name);
  printf(",");
  position->iId->printSelf();
  printf(",");
  printDouble(x);
  printf(",");
  printDouble(y);
  printf(",");
  printDouble(z);
  printf(")");
}

/********************************************************************/

/* boringTool */

boringTool::boringTool(){}

boringTool::boringTool(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

boringTool::~boringTool()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int boringTool::isA(int aType)
    { return ((aType == boringTool_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void boringTool::printSelf()
{
  printf("BORING_TOOL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* boss */

boss::boss(){}

boss::boss(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 closedProfile * itsBoundaryIn,
 real * slopeIn) :
   machiningFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn)
{
   itsBoundary = itsBoundaryIn;
   slope = slopeIn;
}

boss::~boss()
{
  delete itsId;
  delete itsOperations;
  delete slope;
}

int boss::isA(int aType)
    { return ((aType == boss_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void boss::printSelf()
{
  printf("BOSS");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsBoundary))->iId->printSelf();
  printf(",");
  if (slope)
    slope->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* bottomAndSideMilling */

bottomAndSideMilling::bottomAndSideMilling(){}

bottomAndSideMilling::bottomAndSideMilling(
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
 real * allowanceBottomIn) :
   two5DmillingOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn,
     itsMachiningStrategyIn)
{
   axialCuttingDepth = axialCuttingDepthIn;
   radialCuttingDepth = radialCuttingDepthIn;
   allowanceSide = allowanceSideIn;
   allowanceBottom = allowanceBottomIn;
}

bottomAndSideMilling::~bottomAndSideMilling(){}

int bottomAndSideMilling::isA(int aType)
    { return ((aType == bottomAndSideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* bottomAndSideRoughMilling */

bottomAndSideRoughMilling::bottomAndSideRoughMilling(){}

bottomAndSideRoughMilling::bottomAndSideRoughMilling(
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
 real * allowanceBottomIn) :
   bottomAndSideMilling(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn,
     itsMachiningStrategyIn,
     axialCuttingDepthIn,
     radialCuttingDepthIn,
     allowanceSideIn,
     allowanceBottomIn)
    {}

bottomAndSideRoughMilling::~bottomAndSideRoughMilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete axialCuttingDepth;
  delete radialCuttingDepth;
  delete allowanceSide;
  delete allowanceBottom;
}

int bottomAndSideRoughMilling::isA(int aType)
    { return ((aType == bottomAndSideRoughMilling_E) ||
	      (aType == bottomAndSideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void bottomAndSideRoughMilling::printSelf()
{
  printf("BOTTOM_AND_SIDE_ROUGH_MILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (approach)
    (dynamic_cast<instance *>(approach))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (retract)
    (dynamic_cast<instance *>(retract))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    (dynamic_cast<instance *>(itsMachiningStrategy))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (axialCuttingDepth)
    axialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (radialCuttingDepth)
    radialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (allowanceSide)
    allowanceSide->printSelf();
  else
    printf("$");
  printf(",");
  if (allowanceBottom)
    allowanceBottom->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* boundedSurface */

boundedSurface::boundedSurface(){}

boundedSurface::boundedSurface(
 char * nameIn) :
   surface(
     nameIn)
    {}

boundedSurface::~boundedSurface(){}

int boundedSurface::isA(int aType)
    { return ((aType == boundedSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* bSplineSurface */

bSplineSurface::bSplineSurface(){}

bSplineSurface::bSplineSurface(
 char * nameIn,
 integer * uDegreeIn,
 integer * vDegreeIn,
 parenParenCartesianPointListFullListFull * controlPointsListIn,
 bSplineSurfaceForm * surfaceFormIn,
 logical * uClosedIn,
 logical * vClosedIn,
 logical * selfIntersectIn) :
   boundedSurface(
     nameIn)
{
   uDegree = uDegreeIn;
   vDegree = vDegreeIn;
   controlPointsList = controlPointsListIn;
   surfaceForm = surfaceFormIn;
   uClosed = uClosedIn;
   vClosed = vClosedIn;
   selfIntersect = selfIntersectIn;
}

bSplineSurface::~bSplineSurface(){}

int bSplineSurface::isA(int aType)
    { return ((aType == bSplineSurface_E) ||
	      (aType == boundedSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* bSplineSurfaceWithKnots */

bSplineSurfaceWithKnots::bSplineSurfaceWithKnots(){}

bSplineSurfaceWithKnots::bSplineSurfaceWithKnots(
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
 knotType * knotSpecIn) :
   bSplineSurface(
     nameIn,
     uDegreeIn,
     vDegreeIn,
     controlPointsListIn,
     surfaceFormIn,
     uClosedIn,
     vClosedIn,
     selfIntersectIn)
{
   uMultiplicities = uMultiplicitiesIn;
   vMultiplicities = vMultiplicitiesIn;
   uKnots = uKnotsIn;
   vKnots = vKnotsIn;
   knotSpec = knotSpecIn;
}

bSplineSurfaceWithKnots::~bSplineSurfaceWithKnots()
{
  delete name;
  delete uDegree;
  delete vDegree;
  delete controlPointsList;
  delete surfaceForm;
  delete uClosed;
  delete vClosed;
  delete selfIntersect;
  delete uMultiplicities;
  delete vMultiplicities;
  delete uKnots;
  delete vKnots;
  delete knotSpec;
}

int bSplineSurfaceWithKnots::isA(int aType)
    { return ((aType == bSplineSurfaceWithKnots_E) ||
	      (aType == bSplineSurface_E) ||
	      (aType == boundedSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void bSplineSurfaceWithKnots::printSelf()
{
  printf("B_SPLINE_SURFACE_WITH_KNOTS");
  printf("(");
  printString(name);
  printf(",");
  uDegree->printSelf();
  printf(",");
  vDegree->printSelf();
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  surfaceForm->printSelf();
  printf(",");
  uClosed->printSelf();
  printf(",");
  vClosed->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(",");
  uMultiplicities->printSelf();
  printf(",");
  vMultiplicities->printSelf();
  printf(",");
  uKnots->printSelf();
  printf(",");
  vKnots->printSelf();
  printf(",");
  knotSpec->printSelf();
  printf(")");
}

/********************************************************************/

/* cartesianPoint */

cartesianPoint::cartesianPoint(){}

cartesianPoint::cartesianPoint(
 char * nameIn,
 parenRealListFull * coordinatesIn) :
   point(
     nameIn)
{
   coordinates = coordinatesIn;
}

cartesianPoint::~cartesianPoint()
{
  delete name;
  delete coordinates;
}

int cartesianPoint::isA(int aType)
    { return ((aType == cartesianPoint_E) ||
	      (aType == point_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E) ||
	      (aType == trimmingSelect_E));
    }

void cartesianPoint::printSelf()
{
  printf("CARTESIAN_POINT");
  printf("(");
  printString(name);
  printf(",");
  coordinates->printSelf();
  printf(")");
}

/********************************************************************/

/* catalogueThread */

catalogueThread::catalogueThread(){}

catalogueThread::catalogueThread(
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
 specification * documentationIn) :
   thread(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     partialProfileIn,
     appliedShapeIn,
     innerOrOuterThreadIn,
     qualifierIn,
     fitClassIn,
     formIn,
     majorDiameterIn,
     numberOfThreadsIn,
     threadHandIn)
{
   documentation = documentationIn;
}

catalogueThread::~catalogueThread()
{
  delete itsId;
  delete itsOperations;
  delete appliedShape;
  delete innerOrOuterThread;
}

int catalogueThread::isA(int aType)
    { return ((aType == catalogueThread_E) ||
	      (aType == thread_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void catalogueThread::printSelf()
{
  printf("CATALOGUE_THREAD");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  partialProfile->iId->printSelf();
  printf(",");
  appliedShape->printSelf();
  printf(",");
  innerOrOuterThread->printSelf();
  printf(",");
  if (qualifier)
    qualifier->iId->printSelf();
  else
    printf("$");
  printf(",");
  fitClass->iId->printSelf();
  printf(",");
  form->iId->printSelf();
  printf(",");
  printDouble(majorDiameter);
  printf(",");
  numberOfThreads->iId->printSelf();
  printf(",");
  threadHand->iId->printSelf();
  printf(",");
  documentation->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* centerDrill */

centerDrill::centerDrill(){}

centerDrill::centerDrill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

centerDrill::~centerDrill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int centerDrill::isA(int aType)
    { return ((aType == centerDrill_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void centerDrill::printSelf()
{
  printf("CENTER_DRILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* circularClosedProfile */

circularClosedProfile::circularClosedProfile(){}

circularClosedProfile::circularClosedProfile(
 axis2placement3d * placementIn,
 tolerancedLengthMeasure * diameterIn) :
   closedProfile(
     placementIn)
{
   diameter = diameterIn;
}

circularClosedProfile::~circularClosedProfile()
{
}

int circularClosedProfile::isA(int aType)
    { return ((aType == circularClosedProfile_E) ||
	      (aType == closedProfile_E) ||
	      (aType == profile_E));
    }

void circularClosedProfile::printSelf()
{
  printf("CIRCULAR_CLOSED_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  diameter->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* circularClosedShapeProfile */

circularClosedShapeProfile::circularClosedShapeProfile(){}

circularClosedShapeProfile::circularClosedShapeProfile(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * profileSweptShapeIn,
 profileSelect * floorConditionIn,
 direction * removalDirectionIn,
 circularClosedProfile * closedBoundaryIn) :
   shapeProfile(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     profileSweptShapeIn,
     floorConditionIn,
     removalDirectionIn)
{
   closedBoundary = closedBoundaryIn;
}

circularClosedShapeProfile::~circularClosedShapeProfile()
{
  delete itsId;
  delete itsOperations;
}

int circularClosedShapeProfile::isA(int aType)
    { return ((aType == circularClosedShapeProfile_E) ||
	      (aType == shapeProfile_E) ||
	      (aType == profileFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void circularClosedShapeProfile::printSelf()
{
  printf("CIRCULAR_CLOSED_SHAPE_PROFILE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  profileSweptShape->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(floorCondition))->iId->printSelf();
  printf(",");
  removalDirection->iId->printSelf();
  printf(",");
  closedBoundary->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* circularPattern */

circularPattern::circularPattern(){}

circularPattern::circularPattern(
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
 double baseFeatureRotationIn) :
   replicateFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     replicateBaseFeatureIn)
{
   angleIncrement = angleIncrementIn;
   numberOfFeature = numberOfFeatureIn;
   relocatedBaseFeature = relocatedBaseFeatureIn;
   missingBaseFeature = missingBaseFeatureIn;
   baseFeatureDiameter = baseFeatureDiameterIn;
   baseFeatureRotation = baseFeatureRotationIn;
}

circularPattern::~circularPattern()
{
  delete itsId;
  delete itsOperations;
  delete relocatedBaseFeature;
  delete missingBaseFeature;
}

int circularPattern::isA(int aType)
    { return ((aType == circularPattern_E) ||
	      (aType == replicateFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void circularPattern::printSelf()
{
  printf("CIRCULAR_PATTERN");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(replicateBaseFeature))->iId->printSelf();
  printf(",");
  printDouble(angleIncrement);
  printf(",");
  printf("%d", numberOfFeature);
  printf(",");
  relocatedBaseFeature->printSelf();
  printf(",");
  missingBaseFeature->printSelf();
  printf(",");
  if (baseFeatureDiameter)
    baseFeatureDiameter->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(baseFeatureRotation);
  printf(")");
}

/********************************************************************/

/* closedPocket */

closedPocket::closedPocket(){}

closedPocket::closedPocket(
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
 closedProfile * featureBoundaryIn) :
   pocket(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     itsBossIn,
     slopeIn,
     bottomConditionIn,
     planarRadiusIn,
     orthogonalRadiusIn)
{
   featureBoundary = featureBoundaryIn;
}

closedPocket::~closedPocket()
{
  delete itsId;
  delete itsOperations;
  delete itsBoss;
  delete slope;
}

int closedPocket::isA(int aType)
    { return ((aType == closedPocket_E) ||
	      (aType == pocket_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void closedPocket::printSelf()
{
  printf("CLOSED_POCKET");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  itsBoss->printSelf();
  printf(",");
  if (slope)
    slope->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(bottomCondition))->iId->printSelf();
  printf(",");
  if (planarRadius)
    planarRadius->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (orthogonalRadius)
    orthogonalRadius->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(featureBoundary))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* closedShell */

closedShell::closedShell(){}

closedShell::closedShell(
 char * nameIn,
 parenFaceListFull * cfsFacesIn) :
   connectedFaceSet(
     nameIn,
     cfsFacesIn)
    {}

closedShell::~closedShell()
{
  delete name;
  delete cfsFaces;
}

int closedShell::isA(int aType)
    { return ((aType == closedShell_E) ||
	      (aType == connectedFaceSet_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void closedShell::printSelf()
{
  printf("CLOSED_SHELL");
  printf("(");
  printString(name);
  printf(",");
  cfsFaces->printSelf();
  printf(")");
}

/********************************************************************/

/* combinedDrillAndReamer */

combinedDrillAndReamer::combinedDrillAndReamer(){}

combinedDrillAndReamer::combinedDrillAndReamer(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * drillLengthIn) :
   reamer(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   drillLength = drillLengthIn;
}

combinedDrillAndReamer::~combinedDrillAndReamer()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete drillLength;
}

int combinedDrillAndReamer::isA(int aType)
    { return ((aType == combinedDrillAndReamer_E) ||
	      (aType == reamer_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void combinedDrillAndReamer::printSelf()
{
  printf("COMBINED_DRILL_AND_REAMER");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (drillLength)
    drillLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* combinedDrillAndTap */

combinedDrillAndTap::combinedDrillAndTap(){}

combinedDrillAndTap::combinedDrillAndTap(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * drillLengthIn) :
   tapParent(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   drillLength = drillLengthIn;
}

combinedDrillAndTap::~combinedDrillAndTap()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete drillLength;
}

int combinedDrillAndTap::isA(int aType)
    { return ((aType == combinedDrillAndTap_E) ||
	      (aType == tapParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void combinedDrillAndTap::printSelf()
{
  printf("COMBINED_DRILL_AND_TAP");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  if (drillLength)
    drillLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* connector */

connector::connector(){}

connector::connector(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn) :
   parameterisedPath(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn)
    {}

connector::~connector(){}

int connector::isA(int aType)
    { return ((aType == connector_E) ||
	      (aType == parameterisedPath_E) ||
	      (aType == toolpath_E));
    }

/********************************************************************/

/* connectSecplane */

connectSecplane::connectSecplane(){}

connectSecplane::connectSecplane(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 direction * upDirIn,
 direction * downDirIn) :
   connector(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn)
{
   upDir = upDirIn;
   downDir = downDirIn;
}

connectSecplane::~connectSecplane()
{
  delete itsPriority;
  delete itsType;
}

int connectSecplane::isA(int aType)
    { return ((aType == connectSecplane_E) ||
	      (aType == connector_E) ||
	      (aType == parameterisedPath_E) ||
	      (aType == toolpath_E));
    }

void connectSecplane::printSelf()
{
  printf("CONNECT_SECPLANE");
  printf("(");
  itsPriority->printSelf();
  printf(",");
  itsType->printSelf();
  printf(",");
  if (itsSpeed)
    itsSpeed->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachineFunctions)
    (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (upDir)
    upDir->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (downDir)
    downDir->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* counterboreParent */

counterboreParent::counterboreParent(){}

counterboreParent::counterboreParent(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

counterboreParent::~counterboreParent(){}

int counterboreParent::isA(int aType)
    { return ((aType == counterboreParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

/********************************************************************/

/* countersinkParent */

countersinkParent::countersinkParent(){}

countersinkParent::countersinkParent(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

countersinkParent::~countersinkParent(){}

int countersinkParent::isA(int aType)
    { return ((aType == countersinkParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

/********************************************************************/

/* curve */

curve::curve(){}

curve::curve(
 char * nameIn) :
   geometricRepresentationItem(
     nameIn)
    {}

curve::~curve(){}

int curve::isA(int aType)
    { return ((aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* definedThread */

definedThread::definedThread(){}

definedThread::definedThread(
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
 real * crestIn) :
   thread(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     partialProfileIn,
     appliedShapeIn,
     innerOrOuterThreadIn,
     qualifierIn,
     fitClassIn,
     formIn,
     majorDiameterIn,
     numberOfThreadsIn,
     threadHandIn)
{
   pitchDiameter = pitchDiameterIn;
   minorDiameter = minorDiameterIn;
   crest = crestIn;
}

definedThread::~definedThread()
{
  delete itsId;
  delete itsOperations;
  delete appliedShape;
  delete innerOrOuterThread;
  delete minorDiameter;
  delete crest;
}

int definedThread::isA(int aType)
    { return ((aType == definedThread_E) ||
	      (aType == thread_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void definedThread::printSelf()
{
  printf("DEFINED_THREAD");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  partialProfile->iId->printSelf();
  printf(",");
  appliedShape->printSelf();
  printf(",");
  innerOrOuterThread->printSelf();
  printf(",");
  if (qualifier)
    qualifier->iId->printSelf();
  else
    printf("$");
  printf(",");
  fitClass->iId->printSelf();
  printf(",");
  form->iId->printSelf();
  printf(",");
  printDouble(majorDiameter);
  printf(",");
  numberOfThreads->iId->printSelf();
  printf(",");
  threadHand->iId->printSelf();
  printf(",");
  printDouble(pitchDiameter);
  printf(",");
  if (minorDiameter)
    minorDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (crest)
    crest->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* direction */

direction::direction(){}

direction::direction(
 char * nameIn,
 parenRealListFull * directionRatiosIn) :
   geometricRepresentationItem(
     nameIn)
{
   directionRatios = directionRatiosIn;
}

direction::~direction()
{
  delete name;
  delete directionRatios;
}

int direction::isA(int aType)
    { return ((aType == direction_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void direction::printSelf()
{
  printf("DIRECTION");
  printf("(");
  printString(name);
  printf(",");
  directionRatios->printSelf();
  printf(")");
}

/********************************************************************/

/* drill */

drill::drill(){}

drill::drill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

drill::~drill(){}

int drill::isA(int aType)
    { return ((aType == drill_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

/********************************************************************/

/* drillingTypeOperation */

drillingTypeOperation::drillingTypeOperation(){}

drillingTypeOperation::drillingTypeOperation(
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
 drillingTypeStrategy * itsMachiningStrategyIn) :
   millingMachiningOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn)
{
   cuttingDepth = cuttingDepthIn;
   previousDiameter = previousDiameterIn;
   dwellTimeBottom = dwellTimeBottomIn;
   feedOnRetract = feedOnRetractIn;
   itsMachiningStrategy = itsMachiningStrategyIn;
}

drillingTypeOperation::~drillingTypeOperation(){}

int drillingTypeOperation::isA(int aType)
    { return ((aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* edgeLoop */

edgeLoop::edgeLoop(){}

edgeLoop::edgeLoop(
 char * nameIn,
 parenOrientedEdgeListFull * edgeListIn) :
   loop(
     nameIn)
{
   edgeList = edgeListIn;
}

edgeLoop::~edgeLoop()
{
  delete name;
  delete edgeList;
}

int edgeLoop::isA(int aType)
    { return ((aType == edgeLoop_E) ||
	      (aType == loop_E) ||
	      (aType == topologicalRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void edgeLoop::printSelf()
{
  printf("EDGE_LOOP");
  printf("(");
  printString(name);
  printf(",");
  edgeList->printSelf();
  printf(")");
}

/********************************************************************/

/* elementarySurface */

elementarySurface::elementarySurface(){}

elementarySurface::elementarySurface(
 char * nameIn,
 axis2placement3d * positionIn) :
   surface(
     nameIn)
{
   position = positionIn;
}

elementarySurface::~elementarySurface(){}

int elementarySurface::isA(int aType)
    { return ((aType == elementarySurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* freeformOperation */

freeformOperation::freeformOperation(){}

freeformOperation::freeformOperation(
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
 freeformStrategy * itsMachiningStrategyIn) :
   millingTypeOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn)
{
   itsMachiningStrategy = itsMachiningStrategyIn;
}

freeformOperation::~freeformOperation()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
}

int freeformOperation::isA(int aType)
    { return ((aType == freeformOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void freeformOperation::printSelf()
{
  printf("FREEFORM_OPERATION");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (approach)
    (dynamic_cast<instance *>(approach))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (retract)
    (dynamic_cast<instance *>(retract))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    (dynamic_cast<instance *>(itsMachiningStrategy))->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* generalOutsideProfile */

generalOutsideProfile::generalOutsideProfile(){}

generalOutsideProfile::generalOutsideProfile(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * profileSweptShapeIn,
 profile * featureBoundaryIn) :
   profileFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     profileSweptShapeIn)
{
   featureBoundary = featureBoundaryIn;
}

generalOutsideProfile::~generalOutsideProfile()
{
  delete itsId;
  delete itsOperations;
}

int generalOutsideProfile::isA(int aType)
    { return ((aType == generalOutsideProfile_E) ||
	      (aType == profileFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void generalOutsideProfile::printSelf()
{
  printf("GENERAL_OUTSIDE_PROFILE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  profileSweptShape->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(featureBoundary))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* generalPattern */

generalPattern::generalPattern(){}

generalPattern::generalPattern(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 two5DmanufacturingFeature * replicateBaseFeatureIn,
 parenAxis2placement3dListFull * replicateLocationsIn) :
   replicateFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     replicateBaseFeatureIn)
{
   replicateLocations = replicateLocationsIn;
}

generalPattern::~generalPattern()
{
  delete itsId;
  delete itsOperations;
  delete replicateLocations;
}

int generalPattern::isA(int aType)
    { return ((aType == generalPattern_E) ||
	      (aType == replicateFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void generalPattern::printSelf()
{
  printf("GENERAL_PATTERN");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(replicateBaseFeature))->iId->printSelf();
  printf(",");
  replicateLocations->printSelf();
  printf(")");
}

/********************************************************************/

/* generalProfile */

generalProfile::generalProfile(){}

generalProfile::generalProfile(
 axis2placement3d * placementIn,
 boundedCurve * itsProfileIn) :
   openProfile(
     placementIn)
{
   itsProfile = itsProfileIn;
}

generalProfile::~generalProfile()
{
}

int generalProfile::isA(int aType)
    { return ((aType == generalProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }

void generalProfile::printSelf()
{
  printf("GENERAL_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsProfile))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* generalProfileFloor */

generalProfileFloor::generalProfileFloor(){}

generalProfileFloor::generalProfileFloor(
 real * floorRadiusIn,
 boolean * startOrEndIn,
 face * floorIn) :
   profileFloor(
     floorRadiusIn,
     startOrEndIn)
{
   floor = floorIn;
}

generalProfileFloor::~generalProfileFloor()
{
  delete floorRadius;
  delete startOrEnd;
}

int generalProfileFloor::isA(int aType)
    { return ((aType == generalProfileFloor_E) ||
	      (aType == profileFloor_E) ||
	      (aType == profileSelect_E));
    }

void generalProfileFloor::printSelf()
{
  printf("GENERAL_PROFILE_FLOOR");
  printf("(");
  if (floorRadius)
    floorRadius->printSelf();
  else
    printf("$");
  printf(",");
  startOrEnd->printSelf();
  printf(",");
  (dynamic_cast<instance *>(floor))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* generalShapeProfile */

generalShapeProfile::generalShapeProfile(){}

generalShapeProfile::generalShapeProfile(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * profileSweptShapeIn,
 profileSelect * floorConditionIn,
 direction * removalDirectionIn,
 profile * profileBoundaryIn) :
   shapeProfile(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     profileSweptShapeIn,
     floorConditionIn,
     removalDirectionIn)
{
   profileBoundary = profileBoundaryIn;
}

generalShapeProfile::~generalShapeProfile()
{
  delete itsId;
  delete itsOperations;
}

int generalShapeProfile::isA(int aType)
    { return ((aType == generalShapeProfile_E) ||
	      (aType == shapeProfile_E) ||
	      (aType == profileFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void generalShapeProfile::printSelf()
{
  printf("GENERAL_SHAPE_PROFILE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  profileSweptShape->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(floorCondition))->iId->printSelf();
  printf(",");
  removalDirection->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(profileBoundary))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* helix */

helix::helix(){}

helix::helix(
 char * nameIn,
 axis2placement3d * positionIn,
 double radiusIn,
 double pitchIn) :
   curve(
     nameIn)
{
   position = positionIn;
   radius = radiusIn;
   pitch = pitchIn;
}

helix::~helix()
{
  delete name;
}

int helix::isA(int aType)
    { return ((aType == helix_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void helix::printSelf()
{
  printf("HELIX");
  printf("(");
  printString(name);
  printf(",");
  position->iId->printSelf();
  printf(",");
  printDouble(radius);
  printf(",");
  printDouble(pitch);
  printf(")");
}

/********************************************************************/

/* line */

line::line(){}

line::line(
 char * nameIn,
 cartesianPoint * pntIn,
 vector * dirIn) :
   curve(
     nameIn)
{
   pnt = pntIn;
   dir = dirIn;
}

line::~line()
{
  delete name;
}

int line::isA(int aType)
    { return ((aType == line_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void line::printSelf()
{
  printf("LINE");
  printf("(");
  printString(name);
  printf(",");
  pnt->iId->printSelf();
  printf(",");
  dir->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* linearProfile */

linearProfile::linearProfile(){}

linearProfile::linearProfile(
 axis2placement3d * placementIn,
 numericParameter * profileLengthIn) :
   openProfile(
     placementIn)
{
   profileLength = profileLengthIn;
}

linearProfile::~linearProfile()
{
}

int linearProfile::isA(int aType)
    { return ((aType == linearProfile_E) ||
	      (aType == openProfile_E) ||
	      (aType == profile_E));
    }

void linearProfile::printSelf()
{
  printf("LINEAR_PROFILE");
  printf("(");
  if (placement)
    placement->iId->printSelf();
  else
    printf("$");
  printf(",");
  profileLength->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* manifoldSolidBrep */

manifoldSolidBrep::manifoldSolidBrep(){}

manifoldSolidBrep::manifoldSolidBrep(
 char * nameIn,
 closedShell * outerIn) :
   solidModel(
     nameIn)
{
   outer = outerIn;
}

manifoldSolidBrep::~manifoldSolidBrep()
{
  delete name;
}

int manifoldSolidBrep::isA(int aType)
    { return ((aType == manifoldSolidBrep_E) ||
	      (aType == solidModel_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void manifoldSolidBrep::printSelf()
{
  printf("MANIFOLD_SOLID_BREP");
  printf("(");
  printString(name);
  printf(",");
  outer->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* millingCutter */

millingCutter::millingCutter(){}

millingCutter::millingCutter(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

millingCutter::~millingCutter(){}

int millingCutter::isA(int aType)
    { return ((aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

/********************************************************************/

/* millingThreadingTool */

millingThreadingTool::millingThreadingTool(){}

millingThreadingTool::millingThreadingTool(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingToolBody(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

millingThreadingTool::~millingThreadingTool()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int millingThreadingTool::isA(int aType)
    { return ((aType == millingThreadingTool_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void millingThreadingTool::printSelf()
{
  printf("MILLINGTHREADINGTOOL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* openPocket */

openPocket::openPocket(){}

openPocket::openPocket(
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
 openProfile * wallBoundaryIn) :
   pocket(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     itsBossIn,
     slopeIn,
     bottomConditionIn,
     planarRadiusIn,
     orthogonalRadiusIn)
{
   openBoundary = openBoundaryIn;
   wallBoundary = wallBoundaryIn;
}

openPocket::~openPocket()
{
  delete itsId;
  delete itsOperations;
  delete itsBoss;
  delete slope;
}

int openPocket::isA(int aType)
    { return ((aType == openPocket_E) ||
	      (aType == pocket_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void openPocket::printSelf()
{
  printf("OPEN_POCKET");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  itsBoss->printSelf();
  printf(",");
  if (slope)
    slope->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(bottomCondition))->iId->printSelf();
  printf(",");
  if (planarRadius)
    planarRadius->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (orthogonalRadius)
    orthogonalRadius->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(openBoundary))->iId->printSelf();
  printf(",");
  if (wallBoundary)
    (dynamic_cast<instance *>(wallBoundary))->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* partialCircularShapeProfile */

partialCircularShapeProfile::partialCircularShapeProfile(){}

partialCircularShapeProfile::partialCircularShapeProfile(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * profileSweptShapeIn,
 profileSelect * floorConditionIn,
 direction * removalDirectionIn,
 partialCircularProfile * openBoundaryIn) :
   shapeProfile(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     profileSweptShapeIn,
     floorConditionIn,
     removalDirectionIn)
{
   openBoundary = openBoundaryIn;
}

partialCircularShapeProfile::~partialCircularShapeProfile()
{
  delete itsId;
  delete itsOperations;
}

int partialCircularShapeProfile::isA(int aType)
    { return ((aType == partialCircularShapeProfile_E) ||
	      (aType == shapeProfile_E) ||
	      (aType == profileFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void partialCircularShapeProfile::printSelf()
{
  printf("PARTIAL_CIRCULAR_SHAPE_PROFILE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  profileSweptShape->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(floorCondition))->iId->printSelf();
  printf(",");
  removalDirection->iId->printSelf();
  printf(",");
  openBoundary->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* pcurveParent */

pcurveParent::pcurveParent(){}

pcurveParent::pcurveParent(
 char * nameIn,
 surface * basisSurfaceIn,
 definitionalRepresentation * referenceToCurveIn) :
   curve(
     nameIn)
{
   basisSurface = basisSurfaceIn;
   referenceToCurve = referenceToCurveIn;
}

pcurveParent::~pcurveParent(){}

int pcurveParent::isA(int aType)
    { return ((aType == pcurveParent_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* planarProfileFloor */

planarProfileFloor::planarProfileFloor(){}

planarProfileFloor::planarProfileFloor(
 real * floorRadiusIn,
 boolean * startOrEndIn,
 plane * floorIn) :
   profileFloor(
     floorRadiusIn,
     startOrEndIn)
{
   floor = floorIn;
}

planarProfileFloor::~planarProfileFloor()
{
  delete floorRadius;
  delete startOrEnd;
}

int planarProfileFloor::isA(int aType)
    { return ((aType == planarProfileFloor_E) ||
	      (aType == profileFloor_E) ||
	      (aType == profileSelect_E));
    }

void planarProfileFloor::printSelf()
{
  printf("PLANAR_PROFILE_FLOOR");
  printf("(");
  if (floorRadius)
    floorRadius->printSelf();
  else
    printf("$");
  printf(",");
  startOrEnd->printSelf();
  printf(",");
  floor->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* plane */

plane::plane(){}

plane::plane(
 char * nameIn,
 axis2placement3d * positionIn) :
   elementarySurface(
     nameIn,
     positionIn)
    {}

plane::~plane()
{
  delete name;
}

int plane::isA(int aType)
    { return ((aType == plane_E) ||
	      (aType == elementarySurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void plane::printSelf()
{
  printf("PLANE");
  printf("(");
  printString(name);
  printf(",");
  position->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* planeMilling */

planeMilling::planeMilling(){}

planeMilling::planeMilling(
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
 real * allowanceBottomIn) :
   two5DmillingOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn,
     itsMachiningStrategyIn)
{
   axialCuttingDepth = axialCuttingDepthIn;
   allowanceBottom = allowanceBottomIn;
}

planeMilling::~planeMilling(){}

int planeMilling::isA(int aType)
    { return ((aType == planeMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* planeRoughMilling */

planeRoughMilling::planeRoughMilling(){}

planeRoughMilling::planeRoughMilling(
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
 real * allowanceBottomIn) :
   planeMilling(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn,
     itsMachiningStrategyIn,
     axialCuttingDepthIn,
     allowanceBottomIn)
    {}

planeRoughMilling::~planeRoughMilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete axialCuttingDepth;
  delete allowanceBottom;
}

int planeRoughMilling::isA(int aType)
    { return ((aType == planeRoughMilling_E) ||
	      (aType == planeMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void planeRoughMilling::printSelf()
{
  printf("PLANE_ROUGH_MILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (approach)
    (dynamic_cast<instance *>(approach))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (retract)
    (dynamic_cast<instance *>(retract))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    (dynamic_cast<instance *>(itsMachiningStrategy))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (axialCuttingDepth)
    axialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (allowanceBottom)
    allowanceBottom->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* quasiUniformSurface */

quasiUniformSurface::quasiUniformSurface(){}

quasiUniformSurface::quasiUniformSurface(
 char * nameIn,
 integer * uDegreeIn,
 integer * vDegreeIn,
 parenParenCartesianPointListFullListFull * controlPointsListIn,
 bSplineSurfaceForm * surfaceFormIn,
 logical * uClosedIn,
 logical * vClosedIn,
 logical * selfIntersectIn) :
   bSplineSurface(
     nameIn,
     uDegreeIn,
     vDegreeIn,
     controlPointsListIn,
     surfaceFormIn,
     uClosedIn,
     vClosedIn,
     selfIntersectIn)
    {}

quasiUniformSurface::~quasiUniformSurface()
{
  delete name;
  delete uDegree;
  delete vDegree;
  delete controlPointsList;
  delete surfaceForm;
  delete uClosed;
  delete vClosed;
  delete selfIntersect;
}

int quasiUniformSurface::isA(int aType)
    { return ((aType == quasiUniformSurface_E) ||
	      (aType == bSplineSurface_E) ||
	      (aType == boundedSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void quasiUniformSurface::printSelf()
{
  printf("QUASI_UNIFORM_SURFACE");
  printf("(");
  printString(name);
  printf(",");
  uDegree->printSelf();
  printf(",");
  vDegree->printSelf();
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  surfaceForm->printSelf();
  printf(",");
  uClosed->printSelf();
  printf(",");
  vClosed->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(")");
}

/********************************************************************/

/* rationalBSplineSurface */

rationalBSplineSurface::rationalBSplineSurface(){}

rationalBSplineSurface::rationalBSplineSurface(
 char * nameIn,
 integer * uDegreeIn,
 integer * vDegreeIn,
 parenParenCartesianPointListFullListFull * controlPointsListIn,
 bSplineSurfaceForm * surfaceFormIn,
 logical * uClosedIn,
 logical * vClosedIn,
 logical * selfIntersectIn,
 parenParenRealListFullListFull * weightsDataIn) :
   bSplineSurface(
     nameIn,
     uDegreeIn,
     vDegreeIn,
     controlPointsListIn,
     surfaceFormIn,
     uClosedIn,
     vClosedIn,
     selfIntersectIn)
{
   weightsData = weightsDataIn;
}

rationalBSplineSurface::~rationalBSplineSurface()
{
  delete name;
  delete uDegree;
  delete vDegree;
  delete controlPointsList;
  delete surfaceForm;
  delete uClosed;
  delete vClosed;
  delete selfIntersect;
  delete weightsData;
}

int rationalBSplineSurface::isA(int aType)
    { return ((aType == rationalBSplineSurface_E) ||
	      (aType == bSplineSurface_E) ||
	      (aType == boundedSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void rationalBSplineSurface::printSelf()
{
  printf("RATIONAL_B_SPLINE_SURFACE");
  printf("(");
  printString(name);
  printf(",");
  uDegree->printSelf();
  printf(",");
  vDegree->printSelf();
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  surfaceForm->printSelf();
  printf(",");
  uClosed->printSelf();
  printf(",");
  vClosed->printSelf();
  printf(",");
  selfIntersect->printSelf();
  weightsData->printSelf();
  printf(")");
}

/********************************************************************/

/* rectangularClosedShapeProfile */

rectangularClosedShapeProfile::rectangularClosedShapeProfile(){}

rectangularClosedShapeProfile::rectangularClosedShapeProfile(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * profileSweptShapeIn,
 profileSelect * floorConditionIn,
 direction * removalDirectionIn,
 rectangularClosedProfile * closedBoundaryIn) :
   shapeProfile(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     profileSweptShapeIn,
     floorConditionIn,
     removalDirectionIn)
{
   closedBoundary = closedBoundaryIn;
}

rectangularClosedShapeProfile::~rectangularClosedShapeProfile()
{
  delete itsId;
  delete itsOperations;
}

int rectangularClosedShapeProfile::isA(int aType)
    { return ((aType == rectangularClosedShapeProfile_E) ||
	      (aType == shapeProfile_E) ||
	      (aType == profileFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void rectangularClosedShapeProfile::printSelf()
{
  printf("RECTANGULAR_CLOSED_SHAPE_PROFILE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  profileSweptShape->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(floorCondition))->iId->printSelf();
  printf(",");
  removalDirection->iId->printSelf();
  printf(",");
  closedBoundary->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* rectangularOpenShapeProfile */

rectangularOpenShapeProfile::rectangularOpenShapeProfile(){}

rectangularOpenShapeProfile::rectangularOpenShapeProfile(
 char * itsIdIn,
 workpiece * itsWorkpieceIn,
 parenMachiningOperationList * itsOperationsIn,
 axis2placement3d * featurePlacementIn,
 elementarySurface * depthIn,
 linearPath * profileSweptShapeIn,
 profileSelect * floorConditionIn,
 direction * removalDirectionIn,
 squareUProfile * openBoundaryIn) :
   shapeProfile(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     depthIn,
     profileSweptShapeIn,
     floorConditionIn,
     removalDirectionIn)
{
   openBoundary = openBoundaryIn;
}

rectangularOpenShapeProfile::~rectangularOpenShapeProfile()
{
  delete itsId;
  delete itsOperations;
}

int rectangularOpenShapeProfile::isA(int aType)
    { return ((aType == rectangularOpenShapeProfile_E) ||
	      (aType == shapeProfile_E) ||
	      (aType == profileFeature_E) ||
	      (aType == machiningFeature_E) ||
	      (aType == compoundFeatureSelect_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void rectangularOpenShapeProfile::printSelf()
{
  printf("RECTANGULAR_OPEN_SHAPE_PROFILE");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(depth))->iId->printSelf();
  printf(",");
  profileSweptShape->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(floorCondition))->iId->printSelf();
  printf(",");
  removalDirection->iId->printSelf();
  printf(",");
  openBoundary->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* rectangularPattern */

rectangularPattern::rectangularPattern(){}

rectangularPattern::rectangularPattern(
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
 parenRectangularOmitList * missingBaseFeatureIn) :
   replicateFeature(
     itsIdIn,
     itsWorkpieceIn,
     itsOperationsIn,
     featurePlacementIn,
     replicateBaseFeatureIn)
{
   spacing = spacingIn;
   itsDirection = itsDirectionIn;
   numberOfRows = numberOfRowsIn;
   numberOfColumns = numberOfColumnsIn;
   rowSpacing = rowSpacingIn;
   rowLayoutDirection = rowLayoutDirectionIn;
   relocatedBaseFeature = relocatedBaseFeatureIn;
   missingBaseFeature = missingBaseFeatureIn;
}

rectangularPattern::~rectangularPattern()
{
  delete itsId;
  delete itsOperations;
  delete numberOfRows;
  delete relocatedBaseFeature;
  delete missingBaseFeature;
}

int rectangularPattern::isA(int aType)
    { return ((aType == rectangularPattern_E) ||
	      (aType == replicateFeature_E) ||
	      (aType == two5DmanufacturingFeature_E) ||
	      (aType == manufacturingFeature_E));
    }

void rectangularPattern::printSelf()
{
  printf("RECTANGULAR_PATTERN");
  printf("(");
  printString(itsId);
  printf(",");
  itsWorkpiece->iId->printSelf();
  printf(",");
  itsOperations->printSelf();
  printf(",");
  featurePlacement->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(replicateBaseFeature))->iId->printSelf();
  spacing->iId->printSelf();
  printf(",");
  itsDirection->iId->printSelf();
  printf(",");
  if (numberOfRows)
    numberOfRows->printSelf();
  else
    printf("$");
  printf(",");
  printf("%d", numberOfColumns);
  printf(",");
  if (rowSpacing)
    rowSpacing->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (rowLayoutDirection)
    rowLayoutDirection->iId->printSelf();
  else
    printf("$");
  printf(",");
  relocatedBaseFeature->printSelf();
  printf(",");
  missingBaseFeature->printSelf();
  printf(")");
}

/********************************************************************/

/* sideMill */

sideMill::sideMill(){}

sideMill::sideMill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * lengthMeasureIn) :
   millingCutter(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   lengthMeasure = lengthMeasureIn;
}

sideMill::~sideMill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete lengthMeasure;
}

int sideMill::isA(int aType)
    { return ((aType == sideMill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void sideMill::printSelf()
{
  printf("SIDE_MILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (lengthMeasure)
    lengthMeasure->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* sideMilling */

sideMilling::sideMilling(){}

sideMilling::sideMilling(
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
 real * allowanceSideIn) :
   two5DmillingOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn,
     itsMachiningStrategyIn)
{
   axialCuttingDepth = axialCuttingDepthIn;
   radialCuttingDepth = radialCuttingDepthIn;
   allowanceSide = allowanceSideIn;
}

sideMilling::~sideMilling(){}

int sideMilling::isA(int aType)
    { return ((aType == sideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* sideFinishMilling */

sideFinishMilling::sideFinishMilling(){}

sideFinishMilling::sideFinishMilling(
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
 real * allowanceSideIn) :
   sideMilling(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn,
     itsMachiningStrategyIn,
     axialCuttingDepthIn,
     radialCuttingDepthIn,
     allowanceSideIn)
    {}

sideFinishMilling::~sideFinishMilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete axialCuttingDepth;
  delete radialCuttingDepth;
  delete allowanceSide;
}

int sideFinishMilling::isA(int aType)
    { return ((aType == sideFinishMilling_E) ||
	      (aType == sideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void sideFinishMilling::printSelf()
{
  printf("SIDE_FINISH_MILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (approach)
    (dynamic_cast<instance *>(approach))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (retract)
    (dynamic_cast<instance *>(retract))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    (dynamic_cast<instance *>(itsMachiningStrategy))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (axialCuttingDepth)
    axialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (radialCuttingDepth)
    radialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (allowanceSide)
    allowanceSide->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* sideRoughMilling */

sideRoughMilling::sideRoughMilling(){}

sideRoughMilling::sideRoughMilling(
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
 real * allowanceSideIn) :
   sideMilling(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn,
     itsMachiningStrategyIn,
     axialCuttingDepthIn,
     radialCuttingDepthIn,
     allowanceSideIn)
    {}

sideRoughMilling::~sideRoughMilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete axialCuttingDepth;
  delete radialCuttingDepth;
  delete allowanceSide;
}

int sideRoughMilling::isA(int aType)
    { return ((aType == sideRoughMilling_E) ||
	      (aType == sideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void sideRoughMilling::printSelf()
{
  printf("SIDE_ROUGH_MILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (approach)
    (dynamic_cast<instance *>(approach))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (retract)
    (dynamic_cast<instance *>(retract))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    (dynamic_cast<instance *>(itsMachiningStrategy))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (axialCuttingDepth)
    axialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (radialCuttingDepth)
    radialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (allowanceSide)
    allowanceSide->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* spadeDrill */

spadeDrill::spadeDrill(){}

spadeDrill::spadeDrill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   drill(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

spadeDrill::~spadeDrill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int spadeDrill::isA(int aType)
    { return ((aType == spadeDrill_E) ||
	      (aType == drill_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void spadeDrill::printSelf()
{
  printf("SPADE_DRILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* sphericalSurface */

sphericalSurface::sphericalSurface(){}

sphericalSurface::sphericalSurface(
 char * nameIn,
 axis2placement3d * positionIn,
 double radiusIn) :
   elementarySurface(
     nameIn,
     positionIn)
{
   radius = radiusIn;
}

sphericalSurface::~sphericalSurface()
{
  delete name;
}

int sphericalSurface::isA(int aType)
    { return ((aType == sphericalSurface_E) ||
	      (aType == elementarySurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void sphericalSurface::printSelf()
{
  printf("SPHERICAL_SURFACE");
  printf("(");
  printString(name);
  printf(",");
  position->iId->printSelf();
  printf(",");
  printDouble(radius);
  printf(")");
}

/********************************************************************/

/* surfaceOfLinearExtrusion */

surfaceOfLinearExtrusion::surfaceOfLinearExtrusion(){}

surfaceOfLinearExtrusion::surfaceOfLinearExtrusion(
 char * nameIn,
 curve * sweptCurveIn,
 vector * extrusionAxisIn) :
   sweptSurface(
     nameIn,
     sweptCurveIn)
{
   extrusionAxis = extrusionAxisIn;
}

surfaceOfLinearExtrusion::~surfaceOfLinearExtrusion()
{
  delete name;
}

int surfaceOfLinearExtrusion::isA(int aType)
    { return ((aType == surfaceOfLinearExtrusion_E) ||
	      (aType == sweptSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void surfaceOfLinearExtrusion::printSelf()
{
  printf("SURFACE_OF_LINEAR_EXTRUSION");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(sweptCurve))->iId->printSelf();
  printf(",");
  extrusionAxis->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* surfaceOfRevolution */

surfaceOfRevolution::surfaceOfRevolution(){}

surfaceOfRevolution::surfaceOfRevolution(
 char * nameIn,
 curve * sweptCurveIn,
 axis1placement * axisPositionIn) :
   sweptSurface(
     nameIn,
     sweptCurveIn)
{
   axisPosition = axisPositionIn;
}

surfaceOfRevolution::~surfaceOfRevolution()
{
  delete name;
}

int surfaceOfRevolution::isA(int aType)
    { return ((aType == surfaceOfRevolution_E) ||
	      (aType == sweptSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void surfaceOfRevolution::printSelf()
{
  printf("SURFACE_OF_REVOLUTION");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(sweptCurve))->iId->printSelf();
  printf(",");
  axisPosition->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* tap */

tap::tap(){}

tap::tap(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   tapParent(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

tap::~tap()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int tap::isA(int aType)
    { return ((aType == tap_E) ||
	      (aType == tapParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void tap::printSelf()
{
  printf("TAP");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* taperedTap */

taperedTap::taperedTap(){}

taperedTap::taperedTap(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * taperAngleIn) :
   tapParent(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   taperAngle = taperAngleIn;
}

taperedTap::~taperedTap()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete taperAngle;
}

int taperedTap::isA(int aType)
    { return ((aType == taperedTap_E) ||
	      (aType == tapParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void taperedTap::printSelf()
{
  printf("TAPERED_TAP");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* tapping */

tapping::tapping(){}

tapping::tapping(
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
 boolean * compensationChuckIn) :
   drillingTypeOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn)
{
   compensationChuck = compensationChuckIn;
}

tapping::~tapping()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete cuttingDepth;
  delete previousDiameter;
  delete dwellTimeBottom;
  delete feedOnRetract;
  delete compensationChuck;
}

int tapping::isA(int aType)
    { return ((aType == tapping_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void tapping::printSelf()
{
  printf("TAPPING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingDepth)
    cuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (previousDiameter)
    previousDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (dwellTimeBottom)
    dwellTimeBottom->printSelf();
  else
    printf("$");
  printf(",");
  if (feedOnRetract)
    feedOnRetract->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    itsMachiningStrategy->iId->printSelf();
  else
    printf("$");
  compensationChuck->printSelf();
  printf(")");
}

/********************************************************************/

/* threadDrilling */

threadDrilling::threadDrilling(){}

threadDrilling::threadDrilling(
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
 boolean * helicalMovementOnForwardIn) :
   drillingTypeOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn)
{
   helicalMovementOnForward = helicalMovementOnForwardIn;
}

threadDrilling::~threadDrilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete cuttingDepth;
  delete previousDiameter;
  delete dwellTimeBottom;
  delete feedOnRetract;
  delete helicalMovementOnForward;
}

int threadDrilling::isA(int aType)
    { return ((aType == threadDrilling_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void threadDrilling::printSelf()
{
  printf("THREAD_DRILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingDepth)
    cuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (previousDiameter)
    previousDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (dwellTimeBottom)
    dwellTimeBottom->printSelf();
  else
    printf("$");
  printf(",");
  if (feedOnRetract)
    feedOnRetract->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    itsMachiningStrategy->iId->printSelf();
  else
    printf("$");
  helicalMovementOnForward->printSelf();
  printf(")");
}

/********************************************************************/

/* threadMill */

threadMill::threadMill(){}

threadMill::threadMill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingCutter(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

threadMill::~threadMill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int threadMill::isA(int aType)
    { return ((aType == threadMill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void threadMill::printSelf()
{
  printf("THREAD_MILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* toolProbing */

toolProbing::toolProbing(){}

toolProbing::toolProbing(
 char * itsIdIn,
 elementarySurface * itsSecplaneIn,
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn,
 ncVariable * measuredOffsetIn,
 cartesianPoint * offsetIn,
 double maxWearIn,
 machiningTool * itsToolIn) :
   touchProbing(
     itsIdIn,
     itsSecplaneIn,
     itsToolpathIn,
     itsToolDirectionIn,
     measuredOffsetIn)
{
   offset = offsetIn;
   maxWear = maxWearIn;
   itsTool = itsToolIn;
}

toolProbing::~toolProbing(){}

int toolProbing::isA(int aType)
    { return ((aType == toolProbing_E) ||
	      (aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }

/********************************************************************/

/* toolRadiusProbing */

toolRadiusProbing::toolRadiusProbing(){}

toolRadiusProbing::toolRadiusProbing(
 char * itsIdIn,
 elementarySurface * itsSecplaneIn,
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn,
 ncVariable * measuredOffsetIn,
 cartesianPoint * offsetIn,
 double maxWearIn,
 machiningTool * itsToolIn) :
   toolProbing(
     itsIdIn,
     itsSecplaneIn,
     itsToolpathIn,
     itsToolDirectionIn,
     measuredOffsetIn,
     offsetIn,
     maxWearIn,
     itsToolIn)
    {}

toolRadiusProbing::~toolRadiusProbing()
{
  delete itsId;
}

int toolRadiusProbing::isA(int aType)
    { return ((aType == toolRadiusProbing_E) ||
	      (aType == toolProbing_E) ||
	      (aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }

void toolRadiusProbing::printSelf()
{
  printf("TOOL_RADIUS_PROBING");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(itsSecplane))->iId->printSelf();
  printf(",");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  measuredOffset->iId->printSelf();
  printf(",");
  offset->iId->printSelf();
  printf(",");
  printDouble(maxWear);
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* tSlotMill */

tSlotMill::tSlotMill(){}

tSlotMill::tSlotMill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * cuttingThicknessIn) :
   millingCutter(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   cuttingThickness = cuttingThicknessIn;
}

tSlotMill::~tSlotMill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete cuttingThickness;
}

int tSlotMill::isA(int aType)
    { return ((aType == tSlotMill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void tSlotMill::printSelf()
{
  printf("T_SLOT_MILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingThickness)
    cuttingThickness->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* twistDrillParent */

twistDrillParent::twistDrillParent(){}

twistDrillParent::twistDrillParent(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   drill(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

twistDrillParent::~twistDrillParent(){}

int twistDrillParent::isA(int aType)
    { return ((aType == twistDrillParent_E) ||
	      (aType == drill_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

/********************************************************************/

/* twistDrill */

twistDrill::twistDrill(){}

twistDrill::twistDrill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   twistDrillParent(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

twistDrill::~twistDrill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int twistDrill::isA(int aType)
    { return ((aType == twistDrill_E) ||
	      (aType == twistDrillParent_E) ||
	      (aType == drill_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void twistDrill::printSelf()
{
  printf("TWIST_DRILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* uniformSurface */

uniformSurface::uniformSurface(){}

uniformSurface::uniformSurface(
 char * nameIn,
 integer * uDegreeIn,
 integer * vDegreeIn,
 parenParenCartesianPointListFullListFull * controlPointsListIn,
 bSplineSurfaceForm * surfaceFormIn,
 logical * uClosedIn,
 logical * vClosedIn,
 logical * selfIntersectIn) :
   bSplineSurface(
     nameIn,
     uDegreeIn,
     vDegreeIn,
     controlPointsListIn,
     surfaceFormIn,
     uClosedIn,
     vClosedIn,
     selfIntersectIn)
    {}

uniformSurface::~uniformSurface()
{
  delete name;
  delete uDegree;
  delete vDegree;
  delete controlPointsList;
  delete surfaceForm;
  delete uClosed;
  delete vClosed;
  delete selfIntersect;
}

int uniformSurface::isA(int aType)
    { return ((aType == uniformSurface_E) ||
	      (aType == bSplineSurface_E) ||
	      (aType == boundedSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void uniformSurface::printSelf()
{
  printf("UNIFORM_SURFACE");
  printf("(");
  printString(name);
  printf(",");
  uDegree->printSelf();
  printf(",");
  vDegree->printSelf();
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  surfaceForm->printSelf();
  printf(",");
  uClosed->printSelf();
  printf(",");
  vClosed->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(")");
}

/********************************************************************/

/* woodruffKeyseatMill */

woodruffKeyseatMill::woodruffKeyseatMill(){}

woodruffKeyseatMill::woodruffKeyseatMill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * cutterWidthIn) :
   millingCutter(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   cutterWidth = cutterWidthIn;
}

woodruffKeyseatMill::~woodruffKeyseatMill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete cutterWidth;
}

int woodruffKeyseatMill::isA(int aType)
    { return ((aType == woodruffKeyseatMill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void woodruffKeyseatMill::printSelf()
{
  printf("WOORDRUFF_KEYSEAT_MILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cutterWidth)
    cutterWidth->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* apLiftPathAngle */

apLiftPathAngle::apLiftPathAngle(){}

apLiftPathAngle::apLiftPathAngle(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 cartesianPoint * fixPointIn,
 direction * fixPointDirIn,
 double angleIn,
 double benddistIn) :
   approachLiftPath(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     fixPointIn,
     fixPointDirIn)
{
   angle = angleIn;
   benddist = benddistIn;
}

apLiftPathAngle::~apLiftPathAngle()
{
  delete itsPriority;
  delete itsType;
}

int apLiftPathAngle::isA(int aType)
    { return ((aType == apLiftPathAngle_E) ||
	      (aType == approachLiftPath_E) ||
	      (aType == parameterisedPath_E) ||
	      (aType == toolpath_E));
    }

void apLiftPathAngle::printSelf()
{
  printf("AP_LIFT_PATH_ANGLE");
  printf("(");
  itsPriority->printSelf();
  printf(",");
  itsType->printSelf();
  printf(",");
  if (itsSpeed)
    itsSpeed->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachineFunctions)
    (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  else
    printf("$");
  printf(",");
  fixPoint->iId->printSelf();
  printf(",");
  if (fixPointDir)
    fixPointDir->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(",");
  printDouble(benddist);
  printf(")");
}

/********************************************************************/

/* apLiftPathTangent */

apLiftPathTangent::apLiftPathTangent(){}

apLiftPathTangent::apLiftPathTangent(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn,
 cartesianPoint * fixPointIn,
 direction * fixPointDirIn,
 double radiusIn) :
   approachLiftPath(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     fixPointIn,
     fixPointDirIn)
{
   radius = radiusIn;
}

apLiftPathTangent::~apLiftPathTangent()
{
  delete itsPriority;
  delete itsType;
}

int apLiftPathTangent::isA(int aType)
    { return ((aType == apLiftPathTangent_E) ||
	      (aType == approachLiftPath_E) ||
	      (aType == parameterisedPath_E) ||
	      (aType == toolpath_E));
    }

void apLiftPathTangent::printSelf()
{
  printf("AP_LIFT_PATH_TANGENT");
  printf("(");
  itsPriority->printSelf();
  printf(",");
  itsType->printSelf();
  printf(",");
  if (itsSpeed)
    itsSpeed->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachineFunctions)
    (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  else
    printf("$");
  printf(",");
  fixPoint->iId->printSelf();
  printf(",");
  if (fixPointDir)
    fixPointDir->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(radius);
  printf(")");
}

/********************************************************************/

/* backBoring */

backBoring::backBoring(){}

backBoring::backBoring(
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
 drillingTypeStrategy * itsMachiningStrategyIn) :
   drillingTypeOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn)
    {}

backBoring::~backBoring()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete cuttingDepth;
  delete previousDiameter;
  delete dwellTimeBottom;
  delete feedOnRetract;
}

int backBoring::isA(int aType)
    { return ((aType == backBoring_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void backBoring::printSelf()
{
  printf("BACK_BORING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingDepth)
    cuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (previousDiameter)
    previousDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (dwellTimeBottom)
    dwellTimeBottom->printSelf();
  else
    printf("$");
  printf(",");
  if (feedOnRetract)
    feedOnRetract->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    itsMachiningStrategy->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* backsideCounterbore */

backsideCounterbore::backsideCounterbore(){}

backsideCounterbore::backsideCounterbore(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   counterboreParent(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

backsideCounterbore::~backsideCounterbore()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int backsideCounterbore::isA(int aType)
    { return ((aType == backsideCounterbore_E) ||
	      (aType == counterboreParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void backsideCounterbore::printSelf()
{
  printf("BACKSIDE_COUNTERBORE");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* backsideCountersink */

backsideCountersink::backsideCountersink(){}

backsideCountersink::backsideCountersink(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * countersinkRadiusIn) :
   countersinkParent(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   countersinkRadius = countersinkRadiusIn;
}

backsideCountersink::~backsideCountersink()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete countersinkRadius;
}

int backsideCountersink::isA(int aType)
    { return ((aType == backsideCountersink_E) ||
	      (aType == countersinkParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void backsideCountersink::printSelf()
{
  printf("BACKSIDE_COUNTERSINK");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (countersinkRadius)
    countersinkRadius->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* bezierSurface */

bezierSurface::bezierSurface(){}

bezierSurface::bezierSurface(
 char * nameIn,
 integer * uDegreeIn,
 integer * vDegreeIn,
 parenParenCartesianPointListFullListFull * controlPointsListIn,
 bSplineSurfaceForm * surfaceFormIn,
 logical * uClosedIn,
 logical * vClosedIn,
 logical * selfIntersectIn) :
   bSplineSurface(
     nameIn,
     uDegreeIn,
     vDegreeIn,
     controlPointsListIn,
     surfaceFormIn,
     uClosedIn,
     vClosedIn,
     selfIntersectIn)
    {}

bezierSurface::~bezierSurface()
{
  delete name;
  delete uDegree;
  delete vDegree;
  delete controlPointsList;
  delete surfaceForm;
  delete uClosed;
  delete vClosed;
  delete selfIntersect;
}

int bezierSurface::isA(int aType)
    { return ((aType == bezierSurface_E) ||
	      (aType == bSplineSurface_E) ||
	      (aType == boundedSurface_E) ||
	      (aType == surface_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void bezierSurface::printSelf()
{
  printf("BEZIER_SURFACE");
  printf("(");
  printString(name);
  printf(",");
  uDegree->printSelf();
  printf(",");
  vDegree->printSelf();
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  surfaceForm->printSelf();
  printf(",");
  uClosed->printSelf();
  printf(",");
  vClosed->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(")");
}

/********************************************************************/

/* boringOperation */

boringOperation::boringOperation(){}

boringOperation::boringOperation(
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
 cartesianPoint * waitingPositionIn) :
   drillingTypeOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn)
{
   spindleStopAtBottom = spindleStopAtBottomIn;
   depthOfTestcut = depthOfTestcutIn;
   waitingPosition = waitingPositionIn;
}

boringOperation::~boringOperation(){}

int boringOperation::isA(int aType)
    { return ((aType == boringOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* bottomAndSideFinishMilling */

bottomAndSideFinishMilling::bottomAndSideFinishMilling(){}

bottomAndSideFinishMilling::bottomAndSideFinishMilling(
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
 real * allowanceBottomIn) :
   bottomAndSideMilling(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn,
     itsMachiningStrategyIn,
     axialCuttingDepthIn,
     radialCuttingDepthIn,
     allowanceSideIn,
     allowanceBottomIn)
    {}

bottomAndSideFinishMilling::~bottomAndSideFinishMilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete axialCuttingDepth;
  delete radialCuttingDepth;
  delete allowanceSide;
  delete allowanceBottom;
}

int bottomAndSideFinishMilling::isA(int aType)
    { return ((aType == bottomAndSideFinishMilling_E) ||
	      (aType == bottomAndSideMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void bottomAndSideFinishMilling::printSelf()
{
  printf("BOTTOM_AND_SIDE_FINISH_MILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (approach)
    (dynamic_cast<instance *>(approach))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (retract)
    (dynamic_cast<instance *>(retract))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    (dynamic_cast<instance *>(itsMachiningStrategy))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (axialCuttingDepth)
    axialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (radialCuttingDepth)
    radialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (allowanceSide)
    allowanceSide->printSelf();
  else
    printf("$");
  printf(",");
  if (allowanceBottom)
    allowanceBottom->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* boundedCurve */

boundedCurve::boundedCurve(){}

boundedCurve::boundedCurve(
 char * nameIn) :
   curve(
     nameIn)
    {}

boundedCurve::~boundedCurve(){}

int boundedCurve::isA(int aType)
    { return ((aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* boundedPCurve */

boundedPCurve::boundedPCurve(){}

boundedPCurve::boundedPCurve(
 char * nameIn,
 surface * basisSurfaceIn,
 definitionalRepresentation * referenceToCurveIn) :
   pcurveParent(
     nameIn,
     basisSurfaceIn,
     referenceToCurveIn)
    {}

boundedPCurve::~boundedPCurve()
{
  delete name;
}

int boundedPCurve::isA(int aType)
    { return ((aType == boundedPCurve_E) ||
	      (aType == curveWithSurfaceNormalSelect_E) ||
	      (aType == pcurveParent_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void boundedPCurve::printSelf()
{
  printf("BOUNDED_PCURVE");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(basisSurface))->iId->printSelf();
  printf(",");
  referenceToCurve->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* bSplineCurve */

bSplineCurve::bSplineCurve(){}

bSplineCurve::bSplineCurve(
 char * nameIn,
 int degreeIn,
 parenCartesianPointList * controlPointsListIn,
 bSplineCurveForm * curveFormIn,
 logical * closedCurveIn,
 logical * selfIntersectIn) :
   boundedCurve(
     nameIn)
{
   degree = degreeIn;
   controlPointsList = controlPointsListIn;
   curveForm = curveFormIn;
   closedCurve = closedCurveIn;
   selfIntersect = selfIntersectIn;
}

bSplineCurve::~bSplineCurve(){}

int bSplineCurve::isA(int aType)
    { return ((aType == bSplineCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* bSplineCurveWithKnots */

bSplineCurveWithKnots::bSplineCurveWithKnots(){}

bSplineCurveWithKnots::bSplineCurveWithKnots(
 char * nameIn,
 int degreeIn,
 parenCartesianPointList * controlPointsListIn,
 bSplineCurveForm * curveFormIn,
 logical * closedCurveIn,
 logical * selfIntersectIn,
 parenIntegerListFull * knotMultiplicitesIn,
 parenRealListFull * knotsIn,
 knotType * knotSpecIn) :
   bSplineCurve(
     nameIn,
     degreeIn,
     controlPointsListIn,
     curveFormIn,
     closedCurveIn,
     selfIntersectIn)
{
   knotMultiplicites = knotMultiplicitesIn;
   knots = knotsIn;
   knotSpec = knotSpecIn;
}

bSplineCurveWithKnots::~bSplineCurveWithKnots()
{
  delete name;
  delete controlPointsList;
  delete curveForm;
  delete closedCurve;
  delete selfIntersect;
  delete knotMultiplicites;
  delete knots;
  delete knotSpec;
}

int bSplineCurveWithKnots::isA(int aType)
    { return ((aType == bSplineCurveWithKnots_E) ||
	      (aType == bSplineCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void bSplineCurveWithKnots::printSelf()
{
  printf("B_SPLINE_CURVE_WITH_KNOTS");
  printf("(");
  printString(name);
  printf(",");
  printf("%d", degree);
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  curveForm->printSelf();
  printf(",");
  closedCurve->printSelf();
  printf(",");
  selfIntersect->printSelf();
  knotMultiplicites->printSelf();
  printf(",");
  knots->printSelf();
  printf(",");
  knotSpec->printSelf();
  printf(")");
}

/********************************************************************/

/* compositeCurve */

compositeCurve::compositeCurve(){}

compositeCurve::compositeCurve(
 char * nameIn,
 parenCompositeCurveSegmentListFull * segmentsIn,
 logical * selfIntersectIn) :
   boundedCurve(
     nameIn)
{
   segments = segmentsIn;
   selfIntersect = selfIntersectIn;
}

compositeCurve::~compositeCurve()
{
  delete name;
  delete segments;
  delete selfIntersect;
}

int compositeCurve::isA(int aType)
    { return ((aType == compositeCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void compositeCurve::printSelf()
{
  printf("COMPOSITE_CURVE");
  printf("(");
  printString(name);
  printf(",");
  segments->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(")");
}

/********************************************************************/

/* conic */

conic::conic(){}

conic::conic(
 char * nameIn,
 axis2placement3d * positionIn) :
   curve(
     nameIn)
{
   position = positionIn;
}

conic::~conic(){}

int conic::isA(int aType)
    { return ((aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

/********************************************************************/

/* connectDirect */

connectDirect::connectDirect(){}

connectDirect::connectDirect(
 boolean * itsPriorityIn,
 toolpathType * itsTypeIn,
 toolpathSpeedprofile * itsSpeedIn,
 technology * itsTechnologyIn,
 machineFunctions * itsMachineFunctionsIn) :
   connector(
     itsPriorityIn,
     itsTypeIn,
     itsSpeedIn,
     itsTechnologyIn,
     itsMachineFunctionsIn)
    {}

connectDirect::~connectDirect()
{
  delete itsPriority;
  delete itsType;
}

int connectDirect::isA(int aType)
    { return ((aType == connectDirect_E) ||
	      (aType == connector_E) ||
	      (aType == parameterisedPath_E) ||
	      (aType == toolpath_E));
    }

void connectDirect::printSelf()
{
  printf("CONNECT_DIRECT");
  printf("(");
  itsPriority->printSelf();
  printf(",");
  itsType->printSelf();
  printf(",");
  if (itsSpeed)
    itsSpeed->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachineFunctions)
    (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* counterbore */

counterbore::counterbore(){}

counterbore::counterbore(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   counterboreParent(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

counterbore::~counterbore()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int counterbore::isA(int aType)
    { return ((aType == counterbore_E) ||
	      (aType == counterboreParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void counterbore::printSelf()
{
  printf("COUNTERBORE");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* countersink */

countersink::countersink(){}

countersink::countersink(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * countersinkRadiusIn) :
   countersinkParent(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   countersinkRadius = countersinkRadiusIn;
}

countersink::~countersink()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete countersinkRadius;
}

int countersink::isA(int aType)
    { return ((aType == countersink_E) ||
	      (aType == countersinkParent_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void countersink::printSelf()
{
  printf("COUNTERSINK");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (countersinkRadius)
    countersinkRadius->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* dovetailMill */

dovetailMill::dovetailMill(){}

dovetailMill::dovetailMill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * includedAngleIn) :
   millingCutter(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   includedAngle = includedAngleIn;
}

dovetailMill::~dovetailMill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete includedAngle;
}

int dovetailMill::isA(int aType)
    { return ((aType == dovetailMill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void dovetailMill::printSelf()
{
  printf("DOVETAIL_MILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (includedAngle)
    includedAngle->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* drillingOperation */

drillingOperation::drillingOperation(){}

drillingOperation::drillingOperation(
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
 drillingTypeStrategy * itsMachiningStrategyIn) :
   drillingTypeOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn)
    {}

drillingOperation::~drillingOperation(){}

int drillingOperation::isA(int aType)
    { return ((aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

/********************************************************************/

/* ellipse */

ellipse::ellipse(){}

ellipse::ellipse(
 char * nameIn,
 axis2placement3d * positionIn,
 double semiAxis1In,
 double semiAxis2In) :
   conic(
     nameIn,
     positionIn)
{
   semiAxis1 = semiAxis1In;
   semiAxis2 = semiAxis2In;
}

ellipse::~ellipse()
{
  delete name;
}

int ellipse::isA(int aType)
    { return ((aType == ellipse_E) ||
	      (aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void ellipse::printSelf()
{
  printf("ELLIPSE");
  printf("(");
  printString(name);
  printf(",");
  position->iId->printSelf();
  printf(",");
  printDouble(semiAxis1);
  printf(",");
  printDouble(semiAxis2);
  printf(")");
}

/********************************************************************/

/* endmill */

endmill::endmill(){}

endmill::endmill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingCutter(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

endmill::~endmill(){}

int endmill::isA(int aType)
    { return ((aType == endmill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

/********************************************************************/

/* facemill */

facemill::facemill(){}

facemill::facemill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   millingCutter(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

facemill::~facemill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int facemill::isA(int aType)
    { return ((aType == facemill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void facemill::printSelf()
{
  printf("FACEMILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* hyperbola */

hyperbola::hyperbola(){}

hyperbola::hyperbola(
 char * nameIn,
 axis2placement3d * positionIn,
 double semiAxisIn,
 double semiImagAxisIn) :
   conic(
     nameIn,
     positionIn)
{
   semiAxis = semiAxisIn;
   semiImagAxis = semiImagAxisIn;
}

hyperbola::~hyperbola()
{
  delete name;
}

int hyperbola::isA(int aType)
    { return ((aType == hyperbola_E) ||
	      (aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void hyperbola::printSelf()
{
  printf("HYPERBOLA");
  printf("(");
  printString(name);
  printf(",");
  position->iId->printSelf();
  printf(",");
  printDouble(semiAxis);
  printf(",");
  printDouble(semiImagAxis);
  printf(")");
}

/********************************************************************/

/* multistepDrilling */

multistepDrilling::multistepDrilling(){}

multistepDrilling::multistepDrilling(
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
 real * dwellTimeStepIn) :
   drillingOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn)
{
   retractDistance = retractDistanceIn;
   firstDepth = firstDepthIn;
   depthOfStep = depthOfStepIn;
   dwellTimeStep = dwellTimeStepIn;
}

multistepDrilling::~multistepDrilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete cuttingDepth;
  delete previousDiameter;
  delete dwellTimeBottom;
  delete feedOnRetract;
  delete dwellTimeStep;
}

int multistepDrilling::isA(int aType)
    { return ((aType == multistepDrilling_E) ||
	      (aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void multistepDrilling::printSelf()
{
  printf("MULTISTEP_DRILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingDepth)
    cuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (previousDiameter)
    previousDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (dwellTimeBottom)
    dwellTimeBottom->printSelf();
  else
    printf("$");
  printf(",");
  if (feedOnRetract)
    feedOnRetract->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    itsMachiningStrategy->iId->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(retractDistance);
  printf(",");
  printDouble(firstDepth);
  printf(",");
  printDouble(depthOfStep);
  printf(",");
  if (dwellTimeStep)
    dwellTimeStep->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* parabola */

parabola::parabola(){}

parabola::parabola(
 char * nameIn,
 axis2placement3d * positionIn,
 double focalDistIn) :
   conic(
     nameIn,
     positionIn)
{
   focalDist = focalDistIn;
}

parabola::~parabola()
{
  delete name;
}

int parabola::isA(int aType)
    { return ((aType == parabola_E) ||
	      (aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void parabola::printSelf()
{
  printf("PARABOLA");
  printf("(");
  printString(name);
  printf(",");
  position->iId->printSelf();
  printf(",");
  printDouble(focalDist);
  printf(")");
}

/********************************************************************/

/* pcurve */

pcurve::pcurve(){}

pcurve::pcurve(
 char * nameIn,
 surface * basisSurfaceIn,
 definitionalRepresentation * referenceToCurveIn) :
   pcurveParent(
     nameIn,
     basisSurfaceIn,
     referenceToCurveIn)
    {}

pcurve::~pcurve()
{
  delete name;
}

int pcurve::isA(int aType)
    { return ((aType == pcurve_E) ||
	      (aType == pcurveParent_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void pcurve::printSelf()
{
  printf("PCURVE");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(basisSurface))->iId->printSelf();
  printf(",");
  referenceToCurve->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* planeFinishMilling */

planeFinishMilling::planeFinishMilling(){}

planeFinishMilling::planeFinishMilling(
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
 real * allowanceBottomIn) :
   planeMilling(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     approachIn,
     retractIn,
     itsMachiningStrategyIn,
     axialCuttingDepthIn,
     allowanceBottomIn)
    {}

planeFinishMilling::~planeFinishMilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete axialCuttingDepth;
  delete allowanceBottom;
}

int planeFinishMilling::isA(int aType)
    { return ((aType == planeFinishMilling_E) ||
	      (aType == planeMilling_E) ||
	      (aType == two5DmillingOperation_E) ||
	      (aType == millingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void planeFinishMilling::printSelf()
{
  printf("PLANE_FINISH_MILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (approach)
    (dynamic_cast<instance *>(approach))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (retract)
    (dynamic_cast<instance *>(retract))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    (dynamic_cast<instance *>(itsMachiningStrategy))->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (axialCuttingDepth)
    axialCuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (allowanceBottom)
    allowanceBottom->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* polyline */

polyline::polyline(){}

polyline::polyline(
 char * nameIn,
 parenCartesianPointListFull * pointsIn) :
   boundedCurve(
     nameIn)
{
   points = pointsIn;
}

polyline::~polyline()
{
  delete name;
  delete points;
}

int polyline::isA(int aType)
    { return ((aType == polyline_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void polyline::printSelf()
{
  printf("POLYLINE");
  printf("(");
  printString(name);
  printf(",");
  points->printSelf();
  printf(")");
}

/********************************************************************/

/* quasiUniformCurve */

quasiUniformCurve::quasiUniformCurve(){}

quasiUniformCurve::quasiUniformCurve(
 char * nameIn,
 int degreeIn,
 parenCartesianPointList * controlPointsListIn,
 bSplineCurveForm * curveFormIn,
 logical * closedCurveIn,
 logical * selfIntersectIn) :
   bSplineCurve(
     nameIn,
     degreeIn,
     controlPointsListIn,
     curveFormIn,
     closedCurveIn,
     selfIntersectIn)
    {}

quasiUniformCurve::~quasiUniformCurve()
{
  delete name;
  delete controlPointsList;
  delete curveForm;
  delete closedCurve;
  delete selfIntersect;
}

int quasiUniformCurve::isA(int aType)
    { return ((aType == quasiUniformCurve_E) ||
	      (aType == bSplineCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void quasiUniformCurve::printSelf()
{
  printf("QUASI_UNIFORM_CURVE");
  printf("(");
  printString(name);
  printf(",");
  printf("%d", degree);
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  curveForm->printSelf();
  printf(",");
  closedCurve->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(")");
}

/********************************************************************/

/* rationalBSplineCurve */

rationalBSplineCurve::rationalBSplineCurve(){}

rationalBSplineCurve::rationalBSplineCurve(
 char * nameIn,
 int degreeIn,
 parenCartesianPointList * controlPointsListIn,
 bSplineCurveForm * curveFormIn,
 logical * closedCurveIn,
 logical * selfIntersectIn,
 parenRealListFull * weightsDataIn) :
   bSplineCurve(
     nameIn,
     degreeIn,
     controlPointsListIn,
     curveFormIn,
     closedCurveIn,
     selfIntersectIn)
{
   weightsData = weightsDataIn;
}

rationalBSplineCurve::~rationalBSplineCurve()
{
  delete name;
  delete controlPointsList;
  delete curveForm;
  delete closedCurve;
  delete selfIntersect;
  delete weightsData;
}

int rationalBSplineCurve::isA(int aType)
    { return ((aType == rationalBSplineCurve_E) ||
	      (aType == bSplineCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void rationalBSplineCurve::printSelf()
{
  printf("RATIONAL_B_SPLINE_CURVE");
  printf("(");
  printString(name);
  printf(",");
  printf("%d", degree);
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  curveForm->printSelf();
  printf(",");
  closedCurve->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(",");
  weightsData->printSelf();
  printf(")");
}

/********************************************************************/

/* reaming */

reaming::reaming(){}

reaming::reaming(
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
 cartesianPoint * waitingPositionIn) :
   boringOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn,
     spindleStopAtBottomIn,
     depthOfTestcutIn,
     waitingPositionIn)
    {}

reaming::~reaming()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete cuttingDepth;
  delete previousDiameter;
  delete dwellTimeBottom;
  delete feedOnRetract;
  delete spindleStopAtBottom;
  delete depthOfTestcut;
}

int reaming::isA(int aType)
    { return ((aType == reaming_E) ||
	      (aType == boringOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void reaming::printSelf()
{
  printf("REAMING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingDepth)
    cuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (previousDiameter)
    previousDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (dwellTimeBottom)
    dwellTimeBottom->printSelf();
  else
    printf("$");
  printf(",");
  if (feedOnRetract)
    feedOnRetract->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    itsMachiningStrategy->iId->printSelf();
  else
    printf("$");
  printf(",");
  spindleStopAtBottom->printSelf();
  printf(",");
  if (depthOfTestcut)
    depthOfTestcut->printSelf();
  else
    printf("$");
  printf(",");
  if (waitingPosition)
    waitingPosition->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* taperedDrill */

taperedDrill::taperedDrill(){}

taperedDrill::taperedDrill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * taperAngleIn) :
   twistDrillParent(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   taperAngle = taperAngleIn;
}

taperedDrill::~taperedDrill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete taperAngle;
}

int taperedDrill::isA(int aType)
    { return ((aType == taperedDrill_E) ||
	      (aType == twistDrillParent_E) ||
	      (aType == drill_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void taperedDrill::printSelf()
{
  printf("TAPERED_DRILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* taperedEndmill */

taperedEndmill::taperedEndmill(){}

taperedEndmill::taperedEndmill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn,
 real * taperAngleIn) :
   endmill(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
{
   taperAngle = taperAngleIn;
}

taperedEndmill::~taperedEndmill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
  delete taperAngle;
}

int taperedEndmill::isA(int aType)
    { return ((aType == taperedEndmill_E) ||
	      (aType == endmill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void taperedEndmill::printSelf()
{
  printf("TAPERED_ENDMILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* toolLengthProbing */

toolLengthProbing::toolLengthProbing(){}

toolLengthProbing::toolLengthProbing(
 char * itsIdIn,
 elementarySurface * itsSecplaneIn,
 toolpathList * itsToolpathIn,
 toolDirection * itsToolDirectionIn,
 ncVariable * measuredOffsetIn,
 cartesianPoint * offsetIn,
 double maxWearIn,
 machiningTool * itsToolIn) :
   toolProbing(
     itsIdIn,
     itsSecplaneIn,
     itsToolpathIn,
     itsToolDirectionIn,
     measuredOffsetIn,
     offsetIn,
     maxWearIn,
     itsToolIn)
    {}

toolLengthProbing::~toolLengthProbing()
{
  delete itsId;
}

int toolLengthProbing::isA(int aType)
    { return ((aType == toolLengthProbing_E) ||
	      (aType == toolProbing_E) ||
	      (aType == touchProbing_E) ||
	      (aType == operation_E) ||
	      (aType == workingstep_E) ||
	      (aType == executable_E));
    }

void toolLengthProbing::printSelf()
{
  printf("TOOL_LENGTH_PROBING");
  printf("(");
  printString(itsId);
  printf(",");
  (dynamic_cast<instance *>(itsSecplane))->iId->printSelf();
  printf(",");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  measuredOffset->iId->printSelf();
  printf(",");
  offset->iId->printSelf();
  printf(",");
  printDouble(maxWear);
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(")");
}

/********************************************************************/

/* trimmedCurve */

trimmedCurve::trimmedCurve(){}

trimmedCurve::trimmedCurve(
 char * nameIn,
 curve * basisCurveIn,
 parenTrimmingSelectListFull * trim1In,
 parenTrimmingSelectListFull * trim2In,
 boolean * senseAgreementIn,
 trimmingPreference * masterRepresentationIn) :
   boundedCurve(
     nameIn)
{
   basisCurve = basisCurveIn;
   trim1 = trim1In;
   trim2 = trim2In;
   senseAgreement = senseAgreementIn;
   masterRepresentation = masterRepresentationIn;
}

trimmedCurve::~trimmedCurve()
{
  delete name;
  delete trim1;
  delete trim2;
  delete senseAgreement;
  delete masterRepresentation;
}

int trimmedCurve::isA(int aType)
    { return ((aType == trimmedCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void trimmedCurve::printSelf()
{
  printf("TRIMMED_CURVE");
  printf("(");
  printString(name);
  printf(",");
  (dynamic_cast<instance *>(basisCurve))->iId->printSelf();
  printf(",");
  trim1->printSelf();
  printf(",");
  trim2->printSelf();
  printf(",");
  senseAgreement->printSelf();
  printf(",");
  masterRepresentation->printSelf();
  printf(")");
}

/********************************************************************/

/* uniformCurve */

uniformCurve::uniformCurve(){}

uniformCurve::uniformCurve(
 char * nameIn,
 int degreeIn,
 parenCartesianPointList * controlPointsListIn,
 bSplineCurveForm * curveFormIn,
 logical * closedCurveIn,
 logical * selfIntersectIn) :
   bSplineCurve(
     nameIn,
     degreeIn,
     controlPointsListIn,
     curveFormIn,
     closedCurveIn,
     selfIntersectIn)
    {}

uniformCurve::~uniformCurve()
{
  delete name;
  delete controlPointsList;
  delete curveForm;
  delete closedCurve;
  delete selfIntersect;
}

int uniformCurve::isA(int aType)
    { return ((aType == uniformCurve_E) ||
	      (aType == bSplineCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void uniformCurve::printSelf()
{
  printf("UNIFORM_CURVE");
  printf("(");
  printString(name);
  printf(",");
  printf("%d", degree);
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  curveForm->printSelf();
  printf(",");
  closedCurve->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(")");
}

/********************************************************************/

/* ballEndmill */

ballEndmill::ballEndmill(){}

ballEndmill::ballEndmill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   endmill(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

ballEndmill::~ballEndmill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int ballEndmill::isA(int aType)
    { return ((aType == ballEndmill_E) ||
	      (aType == endmill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void ballEndmill::printSelf()
{
  printf("BALL_ENDMILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* bezierCurve */

bezierCurve::bezierCurve(){}

bezierCurve::bezierCurve(
 char * nameIn,
 int degreeIn,
 parenCartesianPointList * controlPointsListIn,
 bSplineCurveForm * curveFormIn,
 logical * closedCurveIn,
 logical * selfIntersectIn) :
   bSplineCurve(
     nameIn,
     degreeIn,
     controlPointsListIn,
     curveFormIn,
     closedCurveIn,
     selfIntersectIn)
    {}

bezierCurve::~bezierCurve()
{
  delete name;
  delete controlPointsList;
  delete curveForm;
  delete closedCurve;
  delete selfIntersect;
}

int bezierCurve::isA(int aType)
    { return ((aType == bezierCurve_E) ||
	      (aType == bSplineCurve_E) ||
	      (aType == boundedCurve_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void bezierCurve::printSelf()
{
  printf("BEZIER_CURVE");
  printf("(");
  printString(name);
  printf(",");
  printf("%d", degree);
  printf(",");
  controlPointsList->printSelf();
  printf(",");
  curveForm->printSelf();
  printf(",");
  closedCurve->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(")");
}

/********************************************************************/

/* boring */

boring::boring(){}

boring::boring(
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
 cartesianPoint * waitingPositionIn) :
   boringOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn,
     spindleStopAtBottomIn,
     depthOfTestcutIn,
     waitingPositionIn)
    {}

boring::~boring()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete cuttingDepth;
  delete previousDiameter;
  delete dwellTimeBottom;
  delete feedOnRetract;
  delete spindleStopAtBottom;
  delete depthOfTestcut;
}

int boring::isA(int aType)
    { return ((aType == boring_E) ||
	      (aType == boringOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void boring::printSelf()
{
  printf("BORING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingDepth)
    cuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (previousDiameter)
    previousDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (dwellTimeBottom)
    dwellTimeBottom->printSelf();
  else
    printf("$");
  printf(",");
  if (feedOnRetract)
    feedOnRetract->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    itsMachiningStrategy->iId->printSelf();
  else
    printf("$");
  printf(",");
  spindleStopAtBottom->printSelf();
  printf(",");
  if (depthOfTestcut)
    depthOfTestcut->printSelf();
  else
    printf("$");
  printf(",");
  if (waitingPosition)
    waitingPosition->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* bullnoseEndmill */

bullnoseEndmill::bullnoseEndmill(){}

bullnoseEndmill::bullnoseEndmill(
 millingToolDimension * dimensionIn,
 integer * numberOfTeethIn,
 hand * handOfCutIn,
 boolean * coolantThroughToolIn,
 real * pilotLengthIn) :
   endmill(
     dimensionIn,
     numberOfTeethIn,
     handOfCutIn,
     coolantThroughToolIn,
     pilotLengthIn)
    {}

bullnoseEndmill::~bullnoseEndmill()
{
  delete numberOfTeeth;
  delete handOfCut;
  delete coolantThroughTool;
  delete pilotLength;
}

int bullnoseEndmill::isA(int aType)
    { return ((aType == bullnoseEndmill_E) ||
	      (aType == endmill_E) ||
	      (aType == millingCutter_E) ||
	      (aType == millingToolBody_E) ||
	      (aType == toolBody_E));
    }

void bullnoseEndmill::printSelf()
{
  printf("BULLNOSE_ENDMILL");
  printf("(");
  dimension->iId->printSelf();
  printf(",");
  if (numberOfTeeth)
    numberOfTeeth->printSelf();
  else
    printf("$");
  printf(",");
  if (handOfCut)
    handOfCut->printSelf();
  else
    printf("$");
  printf(",");
  if (coolantThroughTool)
    coolantThroughTool->printSelf();
  else
    printf("$");
  printf(",");
  if (pilotLength)
    pilotLength->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* centerDrilling */

centerDrilling::centerDrilling(){}

centerDrilling::centerDrilling(
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
 drillingTypeStrategy * itsMachiningStrategyIn) :
   drillingOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn)
    {}

centerDrilling::~centerDrilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete cuttingDepth;
  delete previousDiameter;
  delete dwellTimeBottom;
  delete feedOnRetract;
}

int centerDrilling::isA(int aType)
    { return ((aType == centerDrilling_E) ||
	      (aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void centerDrilling::printSelf()
{
  printf("CENTER_DRILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingDepth)
    cuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (previousDiameter)
    previousDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (dwellTimeBottom)
    dwellTimeBottom->printSelf();
  else
    printf("$");
  printf(",");
  if (feedOnRetract)
    feedOnRetract->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    itsMachiningStrategy->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* circle */

circle::circle(){}

circle::circle(
 char * nameIn,
 axis2placement3d * positionIn,
 double radiusIn) :
   conic(
     nameIn,
     positionIn)
{
   radius = radiusIn;
}

circle::~circle()
{
  delete name;
}

int circle::isA(int aType)
    { return ((aType == circle_E) ||
	      (aType == conic_E) ||
	      (aType == curve_E) ||
	      (aType == geometricRepresentationItem_E) ||
	      (aType == representationItem_E));
    }

void circle::printSelf()
{
  printf("CIRCLE");
  printf("(");
  printString(name);
  printf(",");
  position->iId->printSelf();
  printf(",");
  printDouble(radius);
  printf(")");
}

/********************************************************************/

/* counterSinking */

counterSinking::counterSinking(){}

counterSinking::counterSinking(
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
 drillingTypeStrategy * itsMachiningStrategyIn) :
   drillingOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn)
    {}

counterSinking::~counterSinking()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete cuttingDepth;
  delete previousDiameter;
  delete dwellTimeBottom;
  delete feedOnRetract;
}

int counterSinking::isA(int aType)
    { return ((aType == counterSinking_E) ||
	      (aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void counterSinking::printSelf()
{
  printf("COUNTER_SINKING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingDepth)
    cuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (previousDiameter)
    previousDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (dwellTimeBottom)
    dwellTimeBottom->printSelf();
  else
    printf("$");
  printf(",");
  if (feedOnRetract)
    feedOnRetract->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    itsMachiningStrategy->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

/* drilling */

drilling::drilling(){}

drilling::drilling(
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
 drillingTypeStrategy * itsMachiningStrategyIn) :
   drillingOperation(
     itsToolpathIn,
     itsToolDirectionIn,
     itsIdIn,
     retractPlaneIn,
     startPointIn,
     itsToolIn,
     itsTechnologyIn,
     itsMachineFunctionsIn,
     overcutLengthIn,
     cuttingDepthIn,
     previousDiameterIn,
     dwellTimeBottomIn,
     feedOnRetractIn,
     itsMachiningStrategyIn)
    {}

drilling::~drilling()
{
  delete itsId;
  delete retractPlane;
  delete overcutLength;
  delete cuttingDepth;
  delete previousDiameter;
  delete dwellTimeBottom;
  delete feedOnRetract;
}

int drilling::isA(int aType)
    { return ((aType == drilling_E) ||
	      (aType == drillingOperation_E) ||
	      (aType == drillingTypeOperation_E) ||
	      (aType == millingMachiningOperation_E) ||
	      (aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

void drilling::printSelf()
{
  printf("DRILLING");
  printf("(");
  if (itsToolpath)
    itsToolpath->iId->printSelf();
  else
    printf("$");
  printf(",");
  if (itsToolDirection)
    (dynamic_cast<instance *>(itsToolDirection))->iId->printSelf();
  else
    printf("$");
  printf(",");
  printString(itsId);
  printf(",");
  if (retractPlane)
    retractPlane->printSelf();
  else
    printf("$");
  printf(",");
  if (startPoint)
    startPoint->iId->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsTool))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsTechnology))->iId->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsMachineFunctions))->iId->printSelf();
  printf(",");
  if (overcutLength)
    overcutLength->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingDepth)
    cuttingDepth->printSelf();
  else
    printf("$");
  printf(",");
  if (previousDiameter)
    previousDiameter->printSelf();
  else
    printf("$");
  printf(",");
  if (dwellTimeBottom)
    dwellTimeBottom->printSelf();
  else
    printf("$");
  printf(",");
  if (feedOnRetract)
    feedOnRetract->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    itsMachiningStrategy->iId->printSelf();
  else
    printf("$");
  printf(")");
}

/********************************************************************/

