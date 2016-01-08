
/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

#include "iso14649classes.h"
#include <stdio.h>   // for printf, etc.
using namespace iso14649;
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
  //delete inputStart;
  //delete inputHeader;
  //delete inputData;
  //delete inputEnd;
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

fileStart * inputFile::get_inputStart()
  {return inputStart;}
void inputFile::set_inputStart(fileStart * inputStartIn)
  {inputStart = inputStartIn;}
headerSection * inputFile::get_inputHeader()
  {return inputHeader;}
void inputFile::set_inputHeader(headerSection * inputHeaderIn)
  {inputHeader = inputHeaderIn;}
dataSection * inputFile::get_inputData()
  {return inputData;}
void inputFile::set_inputData(dataSection * inputDataIn)
  {inputData = inputDataIn;}
fileEnd * inputFile::get_inputEnd()
  {return inputEnd;}
void inputFile::set_inputEnd(fileEnd * inputEndIn)
  {inputEnd = inputEndIn;}

/********************************************************************/

/* instance */

instance::instance(){}

instance::instance(instanceId * iIdIn)
{
  iId = iIdIn;
}

instance::~instance(){}

instanceId * instance::get_iId(){return iId;}
void instance::set_iId(instanceId * iIdIn){iId = iIdIn;}

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
  //delete internalLocation;
  //delete streetNumber;
  //delete street;
  //delete postalBox;
  //delete town;
  //delete region;
  //delete postalCode;
  //delete country;
  //delete facsimileNumber;
  //delete telephoneNumber;
  //delete electronicMailAddress;
  //delete telexNumber;
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

aString * address::get_internalLocation()
  {return internalLocation;}
void address::set_internalLocation(aString * internalLocationIn)
  {internalLocation = internalLocationIn;}
aString * address::get_streetNumber()
  {return streetNumber;}
void address::set_streetNumber(aString * streetNumberIn)
  {streetNumber = streetNumberIn;}
aString * address::get_street()
  {return street;}
void address::set_street(aString * streetIn)
  {street = streetIn;}
aString * address::get_postalBox()
  {return postalBox;}
void address::set_postalBox(aString * postalBoxIn)
  {postalBox = postalBoxIn;}
aString * address::get_town()
  {return town;}
void address::set_town(aString * townIn)
  {town = townIn;}
aString * address::get_region()
  {return region;}
void address::set_region(aString * regionIn)
  {region = regionIn;}
aString * address::get_postalCode()
  {return postalCode;}
void address::set_postalCode(aString * postalCodeIn)
  {postalCode = postalCodeIn;}
aString * address::get_country()
  {return country;}
void address::set_country(aString * countryIn)
  {country = countryIn;}
aString * address::get_facsimileNumber()
  {return facsimileNumber;}
void address::set_facsimileNumber(aString * facsimileNumberIn)
  {facsimileNumber = facsimileNumberIn;}
aString * address::get_telephoneNumber()
  {return telephoneNumber;}
void address::set_telephoneNumber(aString * telephoneNumberIn)
  {telephoneNumber = telephoneNumberIn;}
aString * address::get_electronicMailAddress()
  {return electronicMailAddress;}
void address::set_electronicMailAddress(aString * electronicMailAddressIn)
  {electronicMailAddress = electronicMailAddressIn;}
aString * address::get_telexNumber()
  {return telexNumber;}
void address::set_telexNumber(aString * telexNumberIn)
  {telexNumber = telexNumberIn;}

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

direction * approachRetractStrategy::get_toolOrientation()
  {return toolOrientation;}
void approachRetractStrategy::set_toolOrientation(direction * toolOrientationIn)
  {toolOrientation = toolOrientationIn;}

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
  //delete level;
}

int approval::isA(int aType)
    { return (aType == approval_E); }

void approval::printSelf()
{
  printf("APPROVAL");
  printf("(");
  status->get_iId()->printSelf();
  printf(",");
  printString(level);
  printf(")");
}

approvalStatus * approval::get_status()
  {return status;}
void approval::set_status(approvalStatus * statusIn)
  {status = statusIn;}
char * approval::get_level()
  {return level;}
void approval::set_level(char * levelIn)
  {level = levelIn;}

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
  //delete name;
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

char * approvalStatus::get_name()
  {return name;}
void approvalStatus::set_name(char * nameIn)
  {name = nameIn;}

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
  //delete theString;
}

int aString::isA(int aType)
    { return (aType == aString_E); }

void aString::printSelf()
{
  printString(theString);
}

char * aString::get_theString()
  {return theString;}
void aString::set_theString(char * theStringIn)
  {theString = theStringIn;}

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
  //delete itsId;
	if (isItsIdLoaded){
		delete[] itsId;
	}
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

char * channel::get_itsId()
  {return itsId;}
void channel::set_itsId(char * itsIdIn)
  {itsId = itsIdIn;}

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

double circularOffset::get_angularOffset()
  {return angularOffset;}
void circularOffset::set_angularOffset(double angularOffsetIn)
  {angularOffset = angularOffsetIn;}
int circularOffset::get_index()
  {return index;}
void circularOffset::set_index(int indexIn)
  {index = indexIn;}

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

int circularOmit::get_index()
  {return index;}
void circularOmit::set_index(int indexIn)
  {index = indexIn;}

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

ncVariable * comparisonExpression::get_operand1()
  {return operand1;}
void comparisonExpression::set_operand1(ncVariable * operand1In)
  {operand1 = operand1In;}
rvalue * comparisonExpression::get_operand2()
  {return operand2;}
void comparisonExpression::set_operand2(rvalue * operand2In)
  {operand2 = operand2In;}

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
  //delete transition;
  //delete sameSense;
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
  (dynamic_cast<instance *>(parentCurve))->get_iId()->printSelf();
  printf(")");
}

transitionCode * compositeCurveSegment::get_transition()
  {return transition;}
void compositeCurveSegment::set_transition(transitionCode * transitionIn)
  {transition = transitionIn;}
boolean * compositeCurveSegment::get_sameSense()
  {return sameSense;}
void compositeCurveSegment::set_sameSense(boolean * sameSenseIn)
  {sameSense = sameSenseIn;}
curve * compositeCurveSegment::get_parentCurve()
  {return parentCurve;}
void compositeCurveSegment::set_parentCurve(curve * parentCurveIn)
  {parentCurve = parentCurveIn;}

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
  //delete minuteOffset;
  //delete sense;
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

int coordinatedUniversalTimeOffset::get_hourOffset()
  {return hourOffset;}
void coordinatedUniversalTimeOffset::set_hourOffset(int hourOffsetIn)
  {hourOffset = hourOffsetIn;}
integer * coordinatedUniversalTimeOffset::get_minuteOffset()
  {return minuteOffset;}
void coordinatedUniversalTimeOffset::set_minuteOffset(integer * minuteOffsetIn)
  {minuteOffset = minuteOffsetIn;}
aheadOrBehind * coordinatedUniversalTimeOffset::get_sense()
  {return sense;}
void coordinatedUniversalTimeOffset::set_sense(aheadOrBehind * senseIn)
  {sense = senseIn;}

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
  //delete itsPriority;
  //delete itsType;
  //delete itsDirection;
  //delete itsContactType;
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
    (dynamic_cast<instance *>(itsTechnology))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachineFunctions)
    (dynamic_cast<instance *>(itsMachineFunctions))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsDirection)
    itsDirection->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(basiccurve))->get_iId()->printSelf();
  printf(",");
  if (itsToolaxis)
    (dynamic_cast<instance *>(itsToolaxis))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsContactType)
    itsContactType->printSelf();
  else
    printf("$");
  printf(")");
}

boolean * cutterContactTrajectory::get_itsPriority()
  {return itsPriority;}
void cutterContactTrajectory::set_itsPriority(boolean * itsPriorityIn)
  {itsPriority = itsPriorityIn;}
toolpathType * cutterContactTrajectory::get_itsType()
  {return itsType;}
void cutterContactTrajectory::set_itsType(toolpathType * itsTypeIn)
  {itsType = itsTypeIn;}
toolpathSpeedprofile * cutterContactTrajectory::get_itsSpeed()
  {return itsSpeed;}
void cutterContactTrajectory::set_itsSpeed(toolpathSpeedprofile * itsSpeedIn)
  {itsSpeed = itsSpeedIn;}
technology * cutterContactTrajectory::get_itsTechnology()
  {return itsTechnology;}
void cutterContactTrajectory::set_itsTechnology(technology * itsTechnologyIn)
  {itsTechnology = itsTechnologyIn;}
machineFunctions * cutterContactTrajectory::get_itsMachineFunctions()
  {return itsMachineFunctions;}
void cutterContactTrajectory::set_itsMachineFunctions(machineFunctions * itsMachineFunctionsIn)
  {itsMachineFunctions = itsMachineFunctionsIn;}
boolean * cutterContactTrajectory::get_itsDirection()
  {return itsDirection;}
void cutterContactTrajectory::set_itsDirection(boolean * itsDirectionIn)
  {itsDirection = itsDirectionIn;}
curveWithSurfaceNormalSelect * cutterContactTrajectory::get_basiccurve()
  {return basiccurve;}
void cutterContactTrajectory::set_basiccurve(curveWithSurfaceNormalSelect * basiccurveIn)
  {basiccurve = basiccurveIn;}
boundedCurve * cutterContactTrajectory::get_itsToolaxis()
  {return itsToolaxis;}
void cutterContactTrajectory::set_itsToolaxis(boundedCurve * itsToolaxisIn)
  {itsToolaxis = itsToolaxisIn;}
contactType * cutterContactTrajectory::get_itsContactType()
  {return itsContactType;}
void cutterContactTrajectory::set_itsContactType(contactType * itsContactTypeIn)
  {itsContactType = itsContactTypeIn;}

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
  //delete expectedToolLife;
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
    itsMaterial->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (technologicalData)
    technologicalData->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (expectedToolLife)
    expectedToolLife->printSelf();
  else
    printf("$");
  printf(",");
  if (itsTechnology)
    itsTechnology->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

double cuttingComponent::get_toolOffsetLength()
  {return toolOffsetLength;}
void cuttingComponent::set_toolOffsetLength(double toolOffsetLengthIn)
  {toolOffsetLength = toolOffsetLengthIn;}
material * cuttingComponent::get_itsMaterial()
  {return itsMaterial;}
void cuttingComponent::set_itsMaterial(material * itsMaterialIn)
  {itsMaterial = itsMaterialIn;}
cuttingEdgeTechnologicalData * cuttingComponent::get_technologicalData()
  {return technologicalData;}
void cuttingComponent::set_technologicalData(cuttingEdgeTechnologicalData * technologicalDataIn)
  {technologicalData = technologicalDataIn;}
real * cuttingComponent::get_expectedToolLife()
  {return expectedToolLife;}
void cuttingComponent::set_expectedToolLife(real * expectedToolLifeIn)
  {expectedToolLife = expectedToolLifeIn;}
millingTechnology * cuttingComponent::get_itsTechnology()
  {return itsTechnology;}
void cuttingComponent::set_itsTechnology(millingTechnology * itsTechnologyIn)
  {itsTechnology = itsTechnologyIn;}

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
  //delete cuttingAngle;
  //delete freeAngle;
  //delete auxAngle;
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

real * cuttingEdgeTechnologicalData::get_cuttingAngle()
  {return cuttingAngle;}
void cuttingEdgeTechnologicalData::set_cuttingAngle(real * cuttingAngleIn)
  {cuttingAngle = cuttingAngleIn;}
real * cuttingEdgeTechnologicalData::get_freeAngle()
  {return freeAngle;}
void cuttingEdgeTechnologicalData::set_freeAngle(real * freeAngleIn)
  {freeAngle = freeAngleIn;}
real * cuttingEdgeTechnologicalData::get_auxAngle()
  {return auxAngle;}
void cuttingEdgeTechnologicalData::set_auxAngle(real * auxAngleIn)
  {auxAngle = auxAngleIn;}

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
  //delete dataStart;
  {
    std::list<instance *>::iterator iter;
    for (iter = items->begin(); iter != items->end(); ++iter)
      {
        //delete *iter;
      }
  }
  //delete items;
  //delete sectionEnd;
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
          (*iter)->get_iId()->printSelf();
          printf("=");
          (*iter)->printSelf();
          printf(";\n");
        }
    }
  sectionEnd->printSelf();
}

dataStarter * dataSection::get_dataStart()
  {return dataStart;}
void dataSection::set_dataStart(dataStarter * dataStartIn)
  {dataStart = dataStartIn;}
std::list<instance *> * dataSection::get_items()
  {return items;}
void dataSection::set_items(std::list<instance *> * itemsIn)
  {items = itemsIn;}
endSection * dataSection::get_sectionEnd()
  {return sectionEnd;}
void dataSection::set_sectionEnd(endSection * sectionEndIn)
  {sectionEnd = sectionEndIn;}

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

int date::get_yearComponent()
  {return yearComponent;}
void date::set_yearComponent(int yearComponentIn)
  {yearComponent = yearComponentIn;}

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
  (dynamic_cast<instance *>(dateComponent))->get_iId()->printSelf();
  printf(",");
  timeComponent->get_iId()->printSelf();
  printf(")");
}

date * dateAndTime::get_dateComponent()
  {return dateComponent;}
void dateAndTime::set_dateComponent(date * dateComponentIn)
  {dateComponent = dateComponentIn;}
localTime * dateAndTime::get_timeComponent()
  {return timeComponent;}
void dateAndTime::set_timeComponent(localTime * timeComponentIn)
  {timeComponent = timeComponentIn;}

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
  //delete reducedCutAtStart;
  //delete reducedFeedAtStart;
  //delete depthOfStart;
  //delete reducedCutAtEnd;
  //delete reducedFeedAtEnd;
  //delete depthOfEnd;
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

real * drillingTypeStrategy::get_reducedCutAtStart()
  {return reducedCutAtStart;}
void drillingTypeStrategy::set_reducedCutAtStart(real * reducedCutAtStartIn)
  {reducedCutAtStart = reducedCutAtStartIn;}
real * drillingTypeStrategy::get_reducedFeedAtStart()
  {return reducedFeedAtStart;}
void drillingTypeStrategy::set_reducedFeedAtStart(real * reducedFeedAtStartIn)
  {reducedFeedAtStart = reducedFeedAtStartIn;}
real * drillingTypeStrategy::get_depthOfStart()
  {return depthOfStart;}
void drillingTypeStrategy::set_depthOfStart(real * depthOfStartIn)
  {depthOfStart = depthOfStartIn;}
real * drillingTypeStrategy::get_reducedCutAtEnd()
  {return reducedCutAtEnd;}
void drillingTypeStrategy::set_reducedCutAtEnd(real * reducedCutAtEndIn)
  {reducedCutAtEnd = reducedCutAtEndIn;}
real * drillingTypeStrategy::get_reducedFeedAtEnd()
  {return reducedFeedAtEnd;}
void drillingTypeStrategy::set_reducedFeedAtEnd(real * reducedFeedAtEndIn)
  {reducedFeedAtEnd = reducedFeedAtEndIn;}
real * drillingTypeStrategy::get_depthOfEnd()
  {return depthOfEnd;}
void drillingTypeStrategy::set_depthOfEnd(real * depthOfEndIn)
  {depthOfEnd = depthOfEndIn;}

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

executable::~executable(){
	if (isItsIdLoaded){
		delete[] itsId;
	}
}

int executable::isA(int aType)
    { return (aType == executable_E); }

char * executable::get_itsId()
  {return itsId;}
void executable::set_itsId(char * itsIdIn)
  {itsId = itsIdIn;}

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
  //delete description;
  //delete implementationLevel;
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

parenStringListFull * fileDescription::get_description()
  {return description;}
void fileDescription::set_description(parenStringListFull * descriptionIn)
  {description = descriptionIn;}
char * fileDescription::get_implementationLevel()
  {return implementationLevel;}
void fileDescription::set_implementationLevel(char * implementationLevelIn)
  {implementationLevel = implementationLevelIn;}

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
  //delete name;
  //delete timeStamp;
  //delete author;
  //delete organization;
  //delete preprocessorVersion;
  //delete originatingSystem;
  //delete authorization;
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

char * fileName::get_name()
  {return name;}
void fileName::set_name(char * nameIn)
  {name = nameIn;}
char * fileName::get_timeStamp()
  {return timeStamp;}
void fileName::set_timeStamp(char * timeStampIn)
  {timeStamp = timeStampIn;}
parenStringListFull * fileName::get_author()
  {return author;}
void fileName::set_author(parenStringListFull * authorIn)
  {author = authorIn;}
parenStringListFull * fileName::get_organization()
  {return organization;}
void fileName::set_organization(parenStringListFull * organizationIn)
  {organization = organizationIn;}
char * fileName::get_preprocessorVersion()
  {return preprocessorVersion;}
void fileName::set_preprocessorVersion(char * preprocessorVersionIn)
  {preprocessorVersion = preprocessorVersionIn;}
char * fileName::get_originatingSystem()
  {return originatingSystem;}
void fileName::set_originatingSystem(char * originatingSystemIn)
  {originatingSystem = originatingSystemIn;}
char * fileName::get_authorization()
  {return authorization;}
void fileName::set_authorization(char * authorizationIn)
  {authorization = authorizationIn;}

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
  //delete schemaIdentifiers;
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

parenStringList * fileSchema::get_schemaIdentifiers()
  {return schemaIdentifiers;}
void fileSchema::set_schemaIdentifiers(parenStringList * schemaIdentifiersIn)
  {schemaIdentifiers = schemaIdentifiersIn;}

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

pathmodeType * freeformStrategy::get_pathmode()
  {return pathmode;}
void freeformStrategy::set_pathmode(pathmodeType * pathmodeIn)
  {pathmode = pathmodeIn;}
cutmodeType * freeformStrategy::get_cutmode()
  {return cutmode;}
void freeformStrategy::set_cutmode(cutmodeType * cutmodeIn)
  {cutmode = cutmodeIn;}
tolerances * freeformStrategy::get_itsMillingTolerances()
  {return itsMillingTolerances;}
void freeformStrategy::set_itsMillingTolerances(tolerances * itsMillingTolerancesIn)
  {itsMillingTolerances = itsMillingTolerancesIn;}
real * freeformStrategy::get_stepover()
  {return stepover;}
void freeformStrategy::set_stepover(real * stepoverIn)
  {stepover = stepoverIn;}

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
  //delete headerStart;
  //delete headerDescription;
  //delete headerName;
  //delete headerSchema;
  //delete sectionEnd;
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

headerStarter * headerSection::get_headerStart()
  {return headerStart;}
void headerSection::set_headerStart(headerStarter * headerStartIn)
  {headerStart = headerStartIn;}
fileDescription * headerSection::get_headerDescription()
  {return headerDescription;}
void headerSection::set_headerDescription(fileDescription * headerDescriptionIn)
  {headerDescription = headerDescriptionIn;}
fileName * headerSection::get_headerName()
  {return headerName;}
void headerSection::set_headerName(fileName * headerNameIn)
  {headerName = headerNameIn;}
fileSchema * headerSection::get_headerSchema()
  {return headerSchema;}
void headerSection::set_headerSchema(fileSchema * headerSchemaIn)
  {headerSchema = headerSchemaIn;}
endSection * headerSection::get_sectionEnd()
  {return sectionEnd;}
void headerSection::set_sectionEnd(endSection * sectionEndIn)
  {sectionEnd = sectionEndIn;}

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
    asIs->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (toBe)
    toBe->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (removal)
    removal->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

advancedBrepShapeRepresentation * inProcessGeometry::get_asIs()
  {return asIs;}
void inProcessGeometry::set_asIs(advancedBrepShapeRepresentation * asIsIn)
  {asIs = asIsIn;}
advancedBrepShapeRepresentation * inProcessGeometry::get_toBe()
  {return toBe;}
void inProcessGeometry::set_toBe(advancedBrepShapeRepresentation * toBeIn)
  {toBe = toBeIn;}
advancedBrepShapeRepresentation * inProcessGeometry::get_removal()
  {return removal;}
void inProcessGeometry::set_removal(advancedBrepShapeRepresentation * removalIn)
  {removal = removalIn;}

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

int instanceId::get_val()
  {return val;}
void instanceId::set_val(int valIn)
  {val = valIn;}

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

int integer::get_val()
  {return val;}
void integer::set_val(int valIn)
  {val = valIn;}

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
  //delete get_pathmode();
  //delete get_cutmode();
  //delete get_stepover();
}

int leadingLineStrategy::isA(int aType)
    { return ((aType == leadingLineStrategy_E) ||
	      (aType == freeformStrategy_E));
    }

void leadingLineStrategy::printSelf()
{
  printf("LEADING_LINE_STRATEGY");
  printf("(");
  get_pathmode()->printSelf();
  printf(",");
  get_cutmode()->printSelf();
  printf(",");
  get_itsMillingTolerances()->get_iId()->printSelf();
  printf(",");
  if (get_stepover())
    get_stepover()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsLine))->get_iId()->printSelf();
  printf(")");
}

boundedCurve * leadingLineStrategy::get_itsLine()
  {return itsLine;}
void leadingLineStrategy::set_itsLine(boundedCurve * itsLineIn)
  {itsLine = itsLineIn;}

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
  //delete minuteComponent;
  //delete secondComponent;
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
  zone->get_iId()->printSelf();
  printf(")");
}

int localTime::get_hourComponent()
  {return hourComponent;}
void localTime::set_hourComponent(int hourComponentIn)
  {hourComponent = hourComponentIn;}
integer * localTime::get_minuteComponent()
  {return minuteComponent;}
void localTime::set_minuteComponent(integer * minuteComponentIn)
  {minuteComponent = minuteComponentIn;}
real * localTime::get_secondComponent()
  {return secondComponent;}
void localTime::set_secondComponent(real * secondComponentIn)
  {secondComponent = secondComponentIn;}
coordinatedUniversalTimeOffset * localTime::get_zone()
  {return zone;}
void localTime::set_zone(coordinatedUniversalTimeOffset * zoneIn)
  {zone = zoneIn;}

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
  //delete surfaceElement;
}

int machinedSurface::isA(int aType)
    { return (aType == machinedSurface_E); }

void machinedSurface::printSelf()
{
  printf("MACHINED_SURFACE");
  printf("(");
  (dynamic_cast<instance *>(itsMachiningFeature))->get_iId()->printSelf();
  printf(",");
  surfaceElement->printSelf();
  printf(")");
}

machiningFeature * machinedSurface::get_itsMachiningFeature()
  {return itsMachiningFeature;}
void machinedSurface::set_itsMachiningFeature(machiningFeature * itsMachiningFeatureIn)
  {itsMachiningFeature = itsMachiningFeatureIn;}
bottomOrSide * machinedSurface::get_surfaceElement()
  {return surfaceElement;}
void machinedSurface::set_surfaceElement(bottomOrSide * surfaceElementIn)
  {surfaceElement = surfaceElementIn;}

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

machiningTool::~machiningTool(){
	if (isItsIdLoaded){
		delete[] itsId;
	}
}

int machiningTool::isA(int aType)
    { return (aType == machiningTool_E); }

char * machiningTool::get_itsId()
  {return itsId;}
void machiningTool::set_itsId(char * itsIdIn)
  {itsId = itsIdIn;}

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

manufacturingFeature::~manufacturingFeature(){
	if (isItsIdLoaded){
		delete[] itsId;
	}
}

int manufacturingFeature::isA(int aType)
    { return (aType == manufacturingFeature_E); }

char * manufacturingFeature::get_itsId()
  {return itsId;}
void manufacturingFeature::set_itsId(char * itsIdIn)
  {itsId = itsIdIn;}
workpiece * manufacturingFeature::get_itsWorkpiece()
  {return itsWorkpiece;}
void manufacturingFeature::set_itsWorkpiece(workpiece * itsWorkpieceIn)
  {itsWorkpiece = itsWorkpieceIn;}
parenMachiningOperationList * manufacturingFeature::get_itsOperations()
  {return itsOperations;}
void manufacturingFeature::set_itsOperations(parenMachiningOperationList * itsOperationsIn)
  {itsOperations = itsOperationsIn;}

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
  //delete standardIdentifier;
  //delete materialIdentifier;
  //delete materialProperty;
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

char * material::get_standardIdentifier()
  {return standardIdentifier;}
void material::set_standardIdentifier(char * standardIdentifierIn)
  {standardIdentifier = standardIdentifierIn;}
char * material::get_materialIdentifier()
  {return materialIdentifier;}
void material::set_materialIdentifier(char * materialIdentifierIn)
  {materialIdentifier = materialIdentifierIn;}
parenPropertyParameterList * material::get_materialProperty()
  {return materialProperty;}
void material::set_materialProperty(parenPropertyParameterList * materialPropertyIn)
  {materialProperty = materialPropertyIn;}

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
  //delete coolant;
  //delete coolantPressure;
  //delete mist;
  //delete throughSpindleCoolant;
  //delete throughPressure;
  //delete axisClamping;
  //delete chipRemoval;
  //delete otherFunctions;
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
    orientedSpindleStop->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsProcessModel)
    itsProcessModel->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  otherFunctions->printSelf();
  printf(")");
}

boolean * millingMachineFunctions::get_coolant()
  {return coolant;}
void millingMachineFunctions::set_coolant(boolean * coolantIn)
  {coolant = coolantIn;}
real * millingMachineFunctions::get_coolantPressure()
  {return coolantPressure;}
void millingMachineFunctions::set_coolantPressure(real * coolantPressureIn)
  {coolantPressure = coolantPressureIn;}
boolean * millingMachineFunctions::get_mist()
  {return mist;}
void millingMachineFunctions::set_mist(boolean * mistIn)
  {mist = mistIn;}
boolean * millingMachineFunctions::get_throughSpindleCoolant()
  {return throughSpindleCoolant;}
void millingMachineFunctions::set_throughSpindleCoolant(boolean * throughSpindleCoolantIn)
  {throughSpindleCoolant = throughSpindleCoolantIn;}
real * millingMachineFunctions::get_throughPressure()
  {return throughPressure;}
void millingMachineFunctions::set_throughPressure(real * throughPressureIn)
  {throughPressure = throughPressureIn;}
parenStringList * millingMachineFunctions::get_axisClamping()
  {return axisClamping;}
void millingMachineFunctions::set_axisClamping(parenStringList * axisClampingIn)
  {axisClamping = axisClampingIn;}
boolean * millingMachineFunctions::get_chipRemoval()
  {return chipRemoval;}
void millingMachineFunctions::set_chipRemoval(boolean * chipRemovalIn)
  {chipRemoval = chipRemovalIn;}
direction * millingMachineFunctions::get_orientedSpindleStop()
  {return orientedSpindleStop;}
void millingMachineFunctions::set_orientedSpindleStop(direction * orientedSpindleStopIn)
  {orientedSpindleStop = orientedSpindleStopIn;}
processModelList * millingMachineFunctions::get_itsProcessModel()
  {return itsProcessModel;}
void millingMachineFunctions::set_itsProcessModel(processModelList * itsProcessModelIn)
  {itsProcessModel = itsProcessModelIn;}
parenPropertyParameterList * millingMachineFunctions::get_otherFunctions()
  {return otherFunctions;}
void millingMachineFunctions::set_otherFunctions(parenPropertyParameterList * otherFunctionsIn)
  {otherFunctions = otherFunctionsIn;}

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
  //delete toolTopAngle;
  //delete toolCircumferenceAngle;
  //delete cuttingEdgeLength;
  //delete edgeRadius;
  //delete edgeCenterVertical;
  //delete edgeCenterHorizontal;
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

double millingToolDimension::get_diameter()
  {return diameter;}
void millingToolDimension::set_diameter(double diameterIn)
  {diameter = diameterIn;}
real * millingToolDimension::get_toolTopAngle()
  {return toolTopAngle;}
void millingToolDimension::set_toolTopAngle(real * toolTopAngleIn)
  {toolTopAngle = toolTopAngleIn;}
real * millingToolDimension::get_toolCircumferenceAngle()
  {return toolCircumferenceAngle;}
void millingToolDimension::set_toolCircumferenceAngle(real * toolCircumferenceAngleIn)
  {toolCircumferenceAngle = toolCircumferenceAngleIn;}
real * millingToolDimension::get_cuttingEdgeLength()
  {return cuttingEdgeLength;}
void millingToolDimension::set_cuttingEdgeLength(real * cuttingEdgeLengthIn)
  {cuttingEdgeLength = cuttingEdgeLengthIn;}
real * millingToolDimension::get_edgeRadius()
  {return edgeRadius;}
void millingToolDimension::set_edgeRadius(real * edgeRadiusIn)
  {edgeRadius = edgeRadiusIn;}
real * millingToolDimension::get_edgeCenterVertical()
  {return edgeCenterVertical;}
void millingToolDimension::set_edgeCenterVertical(real * edgeCenterVerticalIn)
  {edgeCenterVertical = edgeCenterVerticalIn;}
real * millingToolDimension::get_edgeCenterHorizontal()
  {return edgeCenterHorizontal;}
void millingToolDimension::set_edgeCenterHorizontal(real * edgeCenterHorizontalIn)
  {edgeCenterHorizontal = edgeCenterHorizontalIn;}

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

parenBooleanExpressionListFull * multipleArityBooleanExpression::get_operands()
  {return operands;}
void multipleArityBooleanExpression::set_operands(parenBooleanExpressionListFull * operandsIn)
  {operands = operandsIn;}

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
  //delete translate;
  //delete rotate;
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

parenNcVariableListFull * offsetVector::get_translate()
  {return translate;}
void offsetVector::set_translate(parenNcVariableListFull * translateIn)
  {translate = translateIn;}
parenNcVariableListFull * offsetVector::get_rotate()
  {return rotate;}
void offsetVector::set_rotate(parenNcVariableListFull * rotateIn)
  {rotate = rotateIn;}

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

toolpathList * operation::get_itsToolpath()
  {return itsToolpath;}
void operation::set_itsToolpath(toolpathList * itsToolpathIn)
  {itsToolpath = itsToolpathIn;}
toolDirection * operation::get_itsToolDirection()
  {return itsToolDirection;}
void operation::set_itsToolDirection(toolDirection * itsToolDirectionIn)
  {itsToolDirection = itsToolDirectionIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
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
  //delete get_operands();
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
  get_operands()->printSelf();
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
  printf("%d", get_yearComponent());
  printf(",");
  printf("%d", dayComponent);
  printf(")");
}

int ordinalDate::get_dayComponent()
  {return dayComponent;}
void ordinalDate::set_dayComponent(int dayComponentIn)
  {dayComponent = dayComponentIn;}

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
  //delete theList;
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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<axis2placement3d *> * parenAxis2placement3dListFull::get_theList()
  {return theList;}
void parenAxis2placement3dListFull::set_theList(std::list<axis2placement3d *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<booleanExpression *> * parenBooleanExpressionListFull::get_theList()
  {return theList;}
void parenBooleanExpressionListFull::set_theList(std::list<booleanExpression *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenBossList::~parenBossList()
{
  //delete theList;
}

std::list<boss *> * parenBossList::get_theList()
  {return theList;}
void parenBossList::set_theList(std::list<boss *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<boundedCurve *> * parenBoundedCurveListFull::get_theList()
  {return theList;}
void parenBoundedCurveListFull::set_theList(std::list<boundedCurve *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<boundedSurface *> * parenBoundedSurfaceListFull::get_theList()
  {return theList;}
void parenBoundedSurfaceListFull::set_theList(std::list<boundedSurface *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenCartesianPointList::~parenCartesianPointList()
{
  //delete theList;
}

std::list<cartesianPoint *> * parenCartesianPointList::get_theList()
  {return theList;}
void parenCartesianPointList::set_theList(std::list<cartesianPoint *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<cartesianPoint *> * parenCartesianPointListFull::get_theList()
  {return theList;}
void parenCartesianPointListFull::set_theList(std::list<cartesianPoint *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenCircularOffsetList::~parenCircularOffsetList()
{
  //delete theList;
}

std::list<circularOffset *> * parenCircularOffsetList::get_theList()
  {return theList;}
void parenCircularOffsetList::set_theList(std::list<circularOffset *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenCircularOmitList::~parenCircularOmitList()
{
  //delete theList;
}

std::list<circularOmit *> * parenCircularOmitList::get_theList()
  {return theList;}
void parenCircularOmitList::set_theList(std::list<circularOmit *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<compositeCurveSegment *> * parenCompositeCurveSegmentListFull::get_theList()
  {return theList;}
void parenCompositeCurveSegmentListFull::set_theList(std::list<compositeCurveSegment *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<compoundFeatureSelect *> * parenCompoundFeatureSelectListFull::get_theList()
  {return theList;}
void parenCompoundFeatureSelectListFull::set_theList(std::list<compoundFeatureSelect *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<cuttingComponent *> * parenCuttingComponentListFull::get_theList()
  {return theList;}
void parenCuttingComponentListFull::set_theList(std::list<cuttingComponent *> * theListIn)
  {theList = theListIn;}

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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenExecutableList::~parenExecutableList()
{
  //delete theList;
}

std::list<executable *> * parenExecutableList::get_theList()
  {return theList;}
void parenExecutableList::set_theList(std::list<executable *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<executable *> * parenExecutableListFull::get_theList()
  {return theList;}
void parenExecutableListFull::set_theList(std::list<executable *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<faceBound *> * parenFaceBoundListFull::get_theList()
  {return theList;}
void parenFaceBoundListFull::set_theList(std::list<faceBound *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<face *> * parenFaceListFull::get_theList()
  {return theList;}
void parenFaceListFull::set_theList(std::list<face *> * theListIn)
  {theList = theListIn;}

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
        //delete *iter;
      }
  }
  //delete theList;
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

std::list<integer *> * parenIntegerListFull::get_theList()
  {return theList;}
void parenIntegerListFull::set_theList(std::list<integer *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<machinedSurface *> * parenMachinedSurfaceListFull::get_theList()
  {return theList;}
void parenMachinedSurfaceListFull::set_theList(std::list<machinedSurface *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<machiningFeature *> * parenMachiningFeatureListFull::get_theList()
  {return theList;}
void parenMachiningFeatureListFull::set_theList(std::list<machiningFeature *> * theListIn)
  {theList = theListIn;}

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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenMachiningOperationList::~parenMachiningOperationList()
{
  //delete theList;
}

std::list<machiningOperation *> * parenMachiningOperationList::get_theList()
  {return theList;}
void parenMachiningOperationList::set_theList(std::list<machiningOperation *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<ncVariable *> * parenNcVariableListFull::get_theList()
  {return theList;}
void parenNcVariableListFull::set_theList(std::list<ncVariable *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<orientedEdge *> * parenOrientedEdgeListFull::get_theList()
  {return theList;}
void parenOrientedEdgeListFull::set_theList(std::list<orientedEdge *> * theListIn)
  {theList = theListIn;}

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
        //delete *iter;
      }
  }
  //delete theList;
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

std::list<parenCartesianPointListFull *> * parenParenCartesianPointListFullListFull::get_theList()
  {return theList;}
void parenParenCartesianPointListFullListFull::set_theList(std::list<parenCartesianPointListFull *> * theListIn)
  {theList = theListIn;}

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
        //delete *iter;
      }
  }
  //delete theList;
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

std::list<parenRealListFull *> * parenParenRealListFullListFull::get_theList()
  {return theList;}
void parenParenRealListFullListFull::set_theList(std::list<parenRealListFull *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<processModel *> * parenProcessModelLiszt::get_theList()
  {return theList;}
void parenProcessModelLiszt::set_theList(std::list<processModel *> * theListIn)
  {theList = theListIn;}

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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenPropertyParameterList::~parenPropertyParameterList()
{
  //delete theList;
}

std::list<propertyParameter *> * parenPropertyParameterList::get_theList()
  {return theList;}
void parenPropertyParameterList::set_theList(std::list<propertyParameter *> * theListIn)
  {theList = theListIn;}

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
        //delete *iter;
      }
  }
  //delete theList;
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

std::list<real *> * parenRealListFull::get_theList()
  {return theList;}
void parenRealListFull::set_theList(std::list<real *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenRectangularOffsetList::~parenRectangularOffsetList()
{
  //delete theList;
}

std::list<rectangularOffset *> * parenRectangularOffsetList::get_theList()
  {return theList;}
void parenRectangularOffsetList::set_theList(std::list<rectangularOffset *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenRectangularOmitList::~parenRectangularOmitList()
{
  //delete theList;
}

std::list<rectangularOmit *> * parenRectangularOmitList::get_theList()
  {return theList;}
void parenRectangularOmitList::set_theList(std::list<rectangularOmit *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<representationItem *> * parenRepresentationItemListFull::get_theList()
  {return theList;}
void parenRepresentationItemListFull::set_theList(std::list<representationItem *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenSetupInstructionList::~parenSetupInstructionList()
{
  //delete theList;
}

std::list<setupInstruction *> * parenSetupInstructionList::get_theList()
  {return theList;}
void parenSetupInstructionList::set_theList(std::list<setupInstruction *> * theListIn)
  {theList = theListIn;}

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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenSlotEndTypeList::~parenSlotEndTypeList()
{
  //delete theList;
}

std::list<slotEndType *> * parenSlotEndTypeList::get_theList()
  {return theList;}
void parenSlotEndTypeList::set_theList(std::list<slotEndType *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenSpecificationUsageConstraintList::~parenSpecificationUsageConstraintList()
{
  //delete theList;
}

std::list<specificationUsageConstraint *> * parenSpecificationUsageConstraintList::get_theList()
  {return theList;}
void parenSpecificationUsageConstraintList::set_theList(std::list<specificationUsageConstraint *> * theListIn)
  {theList = theListIn;}

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
        //delete *iter;
      }
  }
  //delete theList;
}

std::list<char *> * parenStringList::get_theList()
  {return theList;}
void parenStringList::set_theList(std::list<char *> * theListIn)
  {theList = theListIn;}

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
        //delete *iter;
      }
  }
  //delete theList;
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

std::list<char *> * parenStringListFull::get_theList()
  {return theList;}
void parenStringListFull::set_theList(std::list<char *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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
          (dynamic_cast<instance *>(*iter))->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

std::list<toolpath *> * parenToolpathLisztFull::get_theList()
  {return theList;}
void parenToolpathLisztFull::set_theList(std::list<toolpath *> * theListIn)
  {theList = theListIn;}

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
  //delete theList;
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

std::list<trimmingSelect *> * parenTrimmingSelectListFull::get_theList()
  {return theList;}
void parenTrimmingSelectListFull::set_theList(std::list<trimmingSelect *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenWorkpieceList::~parenWorkpieceList()
{
  //delete theList;
}

std::list<workpiece *> * parenWorkpieceList::get_theList()
  {return theList;}
void parenWorkpieceList::set_theList(std::list<workpiece *> * theListIn)
  {theList = theListIn;}

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
          (*iter)->get_iId()->printSelf();
          if (++iter == theList->end())
            break;
          printf(",");
        }
    }
  printf(")");
}

parenWorkpieceSetupList::~parenWorkpieceSetupList()
{
  //delete theList;
}

std::list<workpieceSetup *> * parenWorkpieceSetupList::get_theList()
  {return theList;}
void parenWorkpieceSetupList::set_theList(std::list<workpieceSetup *> * theListIn)
  {theList = theListIn;}

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
  //delete maximumLength;
}

int partialAreaDefinition::isA(int aType)
    { return (aType == partialAreaDefinition_E); }

void partialAreaDefinition::printSelf()
{
  printf("PARTIAL_AREA_DEFINITION");
  printf("(");
  printDouble(effectiveLength);
  printf(",");
  placement->get_iId()->printSelf();
  printf(",");
  if (maximumLength)
    maximumLength->printSelf();
  else
    printf("$");
  printf(")");
}

double partialAreaDefinition::get_effectiveLength()
  {return effectiveLength;}
void partialAreaDefinition::set_effectiveLength(double effectiveLengthIn)
  {effectiveLength = effectiveLengthIn;}
axis2placement3d * partialAreaDefinition::get_placement()
  {return placement;}
void partialAreaDefinition::set_placement(axis2placement3d * placementIn)
  {placement = placementIn;}
real * partialAreaDefinition::get_maximumLength()
  {return maximumLength;}
void partialAreaDefinition::set_maximumLength(real * maximumLengthIn)
  {maximumLength = maximumLengthIn;}

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
  //delete id;
  //delete lastName;
  //delete firstName;
  //delete middleNames;
  //delete prefixTitles;
  //delete suffixTitles;
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

char * person::get_id()
  {return id;}
void person::set_id(char * idIn)
  {id = idIn;}
aString * person::get_lastName()
  {return lastName;}
void person::set_lastName(aString * lastNameIn)
  {lastName = lastNameIn;}
aString * person::get_firstName()
  {return firstName;}
void person::set_firstName(aString * firstNameIn)
  {firstName = firstNameIn;}
parenStringListFull * person::get_middleNames()
  {return middleNames;}
void person::set_middleNames(parenStringListFull * middleNamesIn)
  {middleNames = middleNamesIn;}
parenStringListFull * person::get_prefixTitles()
  {return prefixTitles;}
void person::set_prefixTitles(parenStringListFull * prefixTitlesIn)
  {prefixTitles = prefixTitlesIn;}
parenStringListFull * person::get_suffixTitles()
  {return suffixTitles;}
void person::set_suffixTitles(parenStringListFull * suffixTitlesIn)
  {suffixTitles = suffixTitlesIn;}

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
  itsPerson->get_iId()->printSelf();
  printf(",");
  if (itsAddress)
    itsAddress->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

person * personAndAddress::get_itsPerson()
  {return itsPerson;}
void personAndAddress::set_itsPerson(person * itsPersonIn)
  {itsPerson = itsPersonIn;}
address * personAndAddress::get_itsAddress()
  {return itsAddress;}
void personAndAddress::set_itsAddress(address * itsAddressIn)
  {itsAddress = itsAddressIn;}

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
  //delete get_pathmode();
  //delete get_cutmode();
  //delete get_stepover();
}

int planeCcStrategy::isA(int aType)
    { return ((aType == planeCcStrategy_E) ||
	      (aType == freeformStrategy_E));
    }

void planeCcStrategy::printSelf()
{
  printf("PLANE_CC_STRATEGY");
  printf("(");
  get_pathmode()->printSelf();
  printf(",");
  get_cutmode()->printSelf();
  printf(",");
  get_itsMillingTolerances()->get_iId()->printSelf();
  printf(",");
  if (get_stepover())
    get_stepover()->printSelf();
  else
    printf("$");
  printf(",");
  itsPlaneNormal->get_iId()->printSelf();
  printf(")");
}

direction * planeCcStrategy::get_itsPlaneNormal()
  {return itsPlaneNormal;}
void planeCcStrategy::set_itsPlaneNormal(direction * itsPlaneNormalIn)
  {itsPlaneNormal = itsPlaneNormalIn;}

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
  //delete get_pathmode();
  //delete get_cutmode();
  //delete get_stepover();
}

int planeClStrategy::isA(int aType)
    { return ((aType == planeClStrategy_E) ||
	      (aType == freeformStrategy_E));
    }

void planeClStrategy::printSelf()
{
  printf("PLANE_CL_STRATEGY");
  printf("(");
  get_pathmode()->printSelf();
  printf(",");
  get_cutmode()->printSelf();
  printf(",");
  get_itsMillingTolerances()->get_iId()->printSelf();
  printf(",");
  if (get_stepover())
    get_stepover()->printSelf();
  else
    printf("$");
  printf(",");
  itsPlaneNormal->get_iId()->printSelf();
  printf(")");
}

direction * planeClStrategy::get_itsPlaneNormal()
  {return itsPlaneNormal;}
void planeClStrategy::set_itsPlaneNormal(direction * itsPlaneNormalIn)
  {itsPlaneNormal = itsPlaneNormalIn;}

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
  if (get_toolOrientation())
    get_toolOrientation()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(radius);
  printf(",");
  printDouble(angle);
  printf(")");
}

double plungeHelix::get_radius()
  {return radius;}
void plungeHelix::set_radius(double radiusIn)
  {radius = radiusIn;}
double plungeHelix::get_angle()
  {return angle;}
void plungeHelix::set_angle(double angleIn)
  {angle = angleIn;}

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
  if (get_toolOrientation())
    get_toolOrientation()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(")");
}

double plungeRamp::get_angle()
  {return angle;}
void plungeRamp::set_angle(double angleIn)
  {angle = angleIn;}

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
  if (get_toolOrientation())
    get_toolOrientation()->get_iId()->printSelf();
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
  if (get_toolOrientation())
    get_toolOrientation()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(",");
  printDouble(width);
  printf(")");
}

double plungeZigzag::get_angle()
  {return angle;}
void plungeZigzag::set_angle(double angleIn)
  {angle = angleIn;}
double plungeZigzag::get_width()
  {return width;}
void plungeZigzag::set_width(double widthIn)
  {width = widthIn;}

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
  //delete iniDataFile;
  //delete itsType;
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

char * processModel::get_iniDataFile()
  {return iniDataFile;}
void processModel::set_iniDataFile(char * iniDataFileIn)
  {iniDataFile = iniDataFileIn;}
char * processModel::get_itsType()
  {return itsType;}
void processModel::set_itsType(char * itsTypeIn)
  {itsType = itsTypeIn;}

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
  //delete itsList;
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

parenProcessModelLiszt * processModelList::get_itsList()
  {return itsList;}
void processModelList::set_itsList(parenProcessModelLiszt * itsListIn)
  {itsList = itsListIn;}

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

axis2placement3d * profile::get_placement()
  {return placement;}
void profile::set_placement(axis2placement3d * placementIn)
  {placement = placementIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
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
  //delete itsId;
  //delete itsWorkpieces;
}

int project::isA(int aType)
    { return (aType == project_E); }

void project::printSelf()
{
  printf("PROJECT");
  printf("(");
  printString(itsId);
  printf(",");
  mainWorkplan->get_iId()->printSelf();
  printf(",");
  itsWorkpieces->printSelf();
  printf(",");
  if (itsOwner)
    itsOwner->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsRelease)
    itsRelease->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsStatus)
    itsStatus->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

char * project::get_itsId()
  {return itsId;}
void project::set_itsId(char * itsIdIn)
  {itsId = itsIdIn;}
workplan * project::get_mainWorkplan()
  {return mainWorkplan;}
void project::set_mainWorkplan(workplan * mainWorkplanIn)
  {mainWorkplan = mainWorkplanIn;}
parenWorkpieceList * project::get_itsWorkpieces()
  {return itsWorkpieces;}
void project::set_itsWorkpieces(parenWorkpieceList * itsWorkpiecesIn)
  {itsWorkpieces = itsWorkpiecesIn;}
personAndAddress * project::get_itsOwner()
  {return itsOwner;}
void project::set_itsOwner(personAndAddress * itsOwnerIn)
  {itsOwner = itsOwnerIn;}
dateAndTime * project::get_itsRelease()
  {return itsRelease;}
void project::set_itsRelease(dateAndTime * itsReleaseIn)
  {itsRelease = itsReleaseIn;}
approval * project::get_itsStatus()
  {return itsStatus;}
void project::set_itsStatus(approval * itsStatusIn)
  {itsStatus = itsStatusIn;}

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

char * propertyParameter::get_parameterName()
  {return parameterName;}
void propertyParameter::set_parameterName(char * parameterNameIn)
  {parameterName = parameterNameIn;}

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
  floorRadiusCenter->get_iId()->printSelf();
  printf(",");
  floorRadius->get_iId()->printSelf();
  printf(")");
}

cartesianPoint * radiusedPocketBottomCondition::get_floorRadiusCenter()
  {return floorRadiusCenter;}
void radiusedPocketBottomCondition::set_floorRadiusCenter(cartesianPoint * floorRadiusCenterIn)
  {floorRadiusCenter = floorRadiusCenterIn;}
tolerancedLengthMeasure * radiusedPocketBottomCondition::get_floorRadius()
  {return floorRadius;}
void radiusedPocketBottomCondition::set_floorRadius(tolerancedLengthMeasure * floorRadiusIn)
  {floorRadius = floorRadiusIn;}

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
  offsetDirection->get_iId()->printSelf();
  printf(",");
  printDouble(offsetDistance);
  printf(",");
  printf("%d", rowIndex);
  printf(",");
  printf("%d", columnIndex);
  printf(")");
}

direction * rectangularOffset::get_offsetDirection()
  {return offsetDirection;}
void rectangularOffset::set_offsetDirection(direction * offsetDirectionIn)
  {offsetDirection = offsetDirectionIn;}
double rectangularOffset::get_offsetDistance()
  {return offsetDistance;}
void rectangularOffset::set_offsetDistance(double offsetDistanceIn)
  {offsetDistance = offsetDistanceIn;}
int rectangularOffset::get_rowIndex()
  {return rowIndex;}
void rectangularOffset::set_rowIndex(int rowIndexIn)
  {rowIndex = rowIndexIn;}
int rectangularOffset::get_columnIndex()
  {return columnIndex;}
void rectangularOffset::set_columnIndex(int columnIndexIn)
  {columnIndex = columnIndexIn;}

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

int rectangularOmit::get_rowIndex()
  {return rowIndex;}
void rectangularOmit::set_rowIndex(int rowIndexIn)
  {rowIndex = rowIndexIn;}
int rectangularOmit::get_columnIndex()
  {return columnIndex;}
void rectangularOmit::set_columnIndex(int columnIndexIn)
  {columnIndex = columnIndexIn;}

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

axis2placement3d * region::get_featurePlacement()
  {return featurePlacement;}
void region::set_featurePlacement(axis2placement3d * featurePlacementIn)
  {featurePlacement = featurePlacementIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  if (get_featurePlacement())
    get_featurePlacement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(projCurve))->get_iId()->printSelf();
  printf(",");
  projDir->get_iId()->printSelf();
  printf(",");
  depth->get_iId()->printSelf();
  printf(")");
}

boundedCurve * regionProjection::get_projCurve()
  {return projCurve;}
void regionProjection::set_projCurve(boundedCurve * projCurveIn)
  {projCurve = projCurveIn;}
direction * regionProjection::get_projDir()
  {return projDir;}
void regionProjection::set_projDir(direction * projDirIn)
  {projDir = projDirIn;}
tolerancedLengthMeasure * regionProjection::get_depth()
  {return depth;}
void regionProjection::set_depth(tolerancedLengthMeasure * depthIn)
  {depth = depthIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete surfaceList;
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  if (get_featurePlacement())
    get_featurePlacement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  surfaceList->printSelf();
  printf(")");
}

parenBoundedSurfaceListFull * regionSurfaceList::get_surfaceList()
  {return surfaceList;}
void regionSurfaceList::set_surfaceList(parenBoundedSurfaceListFull * surfaceListIn)
  {surfaceList = surfaceListIn;}

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

char * representationParent::get_name()
  {return name;}
void representationParent::set_name(char * nameIn)
  {name = nameIn;}
parenRepresentationItemListFull * representationParent::get_items()
  {return items;}
void representationParent::set_items(parenRepresentationItemListFull * itemsIn)
  {items = itemsIn;}
representationContext * representationParent::get_contextOfItems()
  {return contextOfItems;}
void representationParent::set_contextOfItems(representationContext * contextOfItemsIn)
  {contextOfItems = contextOfItemsIn;}

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
  //delete[] get_name();
  //delete get_items();
  //delete get_contextOfItems();
}

int representation::isA(int aType)
    { return ((aType == representation_E) ||
	      (aType == representationParent_E));
    }

void representation::printSelf()
{
  printf("REPRESENTATION");
  printf("(");
  printString(get_name());
  printf(",");
  get_items()->printSelf();
  printf(",");
  get_contextOfItems()->printSelf();
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
  //delete contextIdentifier;
  //delete contextType;
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

char * representationContext::get_contextIdentifier()
  {return contextIdentifier;}
void representationContext::set_contextIdentifier(char * contextIdentifierIn)
  {contextIdentifier = contextIdentifierIn;}
char * representationContext::get_contextType()
  {return contextType;}
void representationContext::set_contextType(char * contextTypeIn)
  {contextType = contextTypeIn;}

/********************************************************************/

/* representationItem */

representationItem::representationItem(){}

representationItem::representationItem(
 char * nameIn)
{
  name = nameIn;
}

representationItem::~representationItem(){
	if (isItsIdLoaded){
		delete[] name;
	}
}

int representationItem::isA(int aType)
    { return (aType == representationItem_E); }

char * representationItem::get_name()
  {return name;}
void representationItem::set_name(char * nameIn)
  {name = nameIn;}

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
  //delete[] get_itsId();
  //delete itsElements;
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
  printString(get_itsId());
  printf(",");
  itsElements->printSelf();
  printf(")");
}

parenExecutableListFull * selective::get_itsElements()
  {return itsElements;}
void selective::set_itsElements(parenExecutableListFull * itsElementsIn)
  {itsElements = itsElementsIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
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
  //delete itsId;
  //delete itsWorkpieceSetup;
	if (isItsIdLoaded){
		delete[] itsId;
	}
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
    itsOrigin->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsSecplane))->get_iId()->printSelf();
  printf(",");
  itsWorkpieceSetup->printSelf();
  printf(")");
}

char * setup::get_itsId()
  {return itsId;}
void setup::set_itsId(char * itsIdIn)
  {itsId = itsIdIn;}
axis2placement3d * setup::get_itsOrigin()
  {return itsOrigin;}
void setup::set_itsOrigin(axis2placement3d * itsOriginIn)
  {itsOrigin = itsOriginIn;}
elementarySurface * setup::get_itsSecplane()
  {return itsSecplane;}
void setup::set_itsSecplane(elementarySurface * itsSecplaneIn)
  {itsSecplane = itsSecplaneIn;}
parenWorkpieceSetupList * setup::get_itsWorkpieceSetup()
  {return itsWorkpieceSetup;}
void setup::set_itsWorkpieceSetup(parenWorkpieceSetupList * itsWorkpieceSetupIn)
  {itsWorkpieceSetup = itsWorkpieceSetupIn;}

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
  //delete description;
  //delete externalDocument;
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

aString * setupInstruction::get_description()
  {return description;}
void setupInstruction::set_description(aString * descriptionIn)
  {description = descriptionIn;}
aString * setupInstruction::get_externalDocument()
  {return externalDocument;}
void setupInstruction::set_externalDocument(aString * externalDocumentIn)
  {externalDocument = externalDocumentIn;}

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
  //delete[] get_name();
  //delete get_items();
  //delete get_contextOfItems();
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
  printString(get_name());
  printf(",");
  get_items()->printSelf();
  printf(",");
  get_contextOfItems()->printSelf();
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
  //delete constraint;
  //delete specificationId;
  //delete specificationDescription;
  //delete specificationClass;
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

parenSpecificationUsageConstraintList * specification::get_constraint()
  {return constraint;}
void specification::set_constraint(parenSpecificationUsageConstraintList * constraintIn)
  {constraint = constraintIn;}
char * specification::get_specificationId()
  {return specificationId;}
void specification::set_specificationId(char * specificationIdIn)
  {specificationId = specificationIdIn;}
aString * specification::get_specificationDescription()
  {return specificationDescription;}
void specification::set_specificationDescription(aString * specificationDescriptionIn)
  {specificationDescription = specificationDescriptionIn;}
aString * specification::get_specificationClass()
  {return specificationClass;}
void specification::set_specificationClass(aString * specificationClassIn)
  {specificationClass = specificationClassIn;}

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
  //delete element;
  //delete classId;
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

char * specificationUsageConstraint::get_element()
  {return element;}
void specificationUsageConstraint::set_element(char * elementIn)
  {element = elementIn;}
char * specificationUsageConstraint::get_classId()
  {return classId;}
void specificationUsageConstraint::set_classId(char * classIdIn)
  {classId = classIdIn;}

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
  //delete parameterName;
  //delete measuringMethod;
  //delete parameterIndex;
  //delete appliedSurfaces;
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

double surfaceTextureParameter::get_itsValue()
  {return itsValue;}
void surfaceTextureParameter::set_itsValue(double itsValueIn)
  {itsValue = itsValueIn;}
char * surfaceTextureParameter::get_parameterName()
  {return parameterName;}
void surfaceTextureParameter::set_parameterName(char * parameterNameIn)
  {parameterName = parameterNameIn;}
char * surfaceTextureParameter::get_measuringMethod()
  {return measuringMethod;}
void surfaceTextureParameter::set_measuringMethod(char * measuringMethodIn)
  {measuringMethod = measuringMethodIn;}
aString * surfaceTextureParameter::get_parameterIndex()
  {return parameterIndex;}
void surfaceTextureParameter::set_parameterIndex(aString * parameterIndexIn)
  {parameterIndex = parameterIndexIn;}
parenMachinedSurfaceListFull * surfaceTextureParameter::get_appliedSurfaces()
  {return appliedSurfaces;}
void surfaceTextureParameter::set_appliedSurfaces(parenMachinedSurfaceListFull * appliedSurfacesIn)
  {appliedSurfaces = appliedSurfacesIn;}

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

real * technology::get_feedrate()
  {return feedrate;}
void technology::set_feedrate(real * feedrateIn)
  {feedrate = feedrateIn;}
toolReferencePoint * technology::get_feedrateReference()
  {return feedrateReference;}
void technology::set_feedrateReference(toolReferencePoint * feedrateReferenceIn)
  {feedrateReference = feedrateReferenceIn;}

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
  implicitTolerance->get_iId()->printSelf();
  printf(")");
}

double tolerancedLengthMeasure::get_theoreticalSize()
  {return theoreticalSize;}
void tolerancedLengthMeasure::set_theoreticalSize(double theoreticalSizeIn)
  {theoreticalSize = theoreticalSizeIn;}
plusMinusValue * tolerancedLengthMeasure::get_implicitTolerance()
  {return implicitTolerance;}
void tolerancedLengthMeasure::set_implicitTolerance(plusMinusValue * implicitToleranceIn)
  {implicitTolerance = implicitToleranceIn;}

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

double tolerances::get_chordalTolerance()
  {return chordalTolerance;}
void tolerances::set_chordalTolerance(double chordalToleranceIn)
  {chordalTolerance = chordalToleranceIn;}
double tolerances::get_scallopHeight()
  {return scallopHeight;}
void tolerances::set_scallopHeight(double scallopHeightIn)
  {scallopHeight = scallopHeightIn;}

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

boolean * toolpath::get_itsPriority()
  {return itsPriority;}
void toolpath::set_itsPriority(boolean * itsPriorityIn)
  {itsPriority = itsPriorityIn;}
toolpathType * toolpath::get_itsType()
  {return itsType;}
void toolpath::set_itsType(toolpathType * itsTypeIn)
  {itsType = itsTypeIn;}
toolpathSpeedprofile * toolpath::get_itsSpeed()
  {return itsSpeed;}
void toolpath::set_itsSpeed(toolpathSpeedprofile * itsSpeedIn)
  {itsSpeed = itsSpeedIn;}
technology * toolpath::get_itsTechnology()
  {return itsTechnology;}
void toolpath::set_itsTechnology(technology * itsTechnologyIn)
  {itsTechnology = itsTechnologyIn;}
machineFunctions * toolpath::get_itsMachineFunctions()
  {return itsMachineFunctions;}
void toolpath::set_itsMachineFunctions(machineFunctions * itsMachineFunctionsIn)
  {itsMachineFunctions = itsMachineFunctionsIn;}

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
  //delete itsList;
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

parenToolpathLisztFull * toolpathList::get_itsList()
  {return itsList;}
void toolpathList::set_itsList(parenToolpathLisztFull * itsListIn)
  {itsList = itsListIn;}

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
    (dynamic_cast<instance *>(this))->get_iId()->printSelf();
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
  //delete itsId;
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

char * touchProbe::get_itsId()
  {return itsId;}
void touchProbe::set_itsId(char * itsIdIn)
  {itsId = itsIdIn;}

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

boolean * trajectory::get_itsDirection()
  {return itsDirection;}
void trajectory::set_itsDirection(boolean * itsDirectionIn)
  {itsDirection = itsDirectionIn;}

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

machiningFeature * transitionFeature::get_firstFeature()
  {return firstFeature;}
void transitionFeature::set_firstFeature(machiningFeature * firstFeatureIn)
  {firstFeature = firstFeatureIn;}
machiningFeature * transitionFeature::get_secondFeature()
  {return secondFeature;}
void transitionFeature::set_secondFeature(machiningFeature * secondFeatureIn)
  {secondFeature = secondFeatureIn;}

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

axis2placement3d * travelPath::get_placement()
  {return placement;}
void travelPath::set_placement(axis2placement3d * placementIn)
  {placement = placementIn;}

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
    (dynamic_cast<instance *>(this))->get_iId()->printSelf();
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

axis2placement3d * two5DmanufacturingFeature::get_featurePlacement()
  {return featurePlacement;}
void two5DmanufacturingFeature::set_featurePlacement(axis2placement3d * featurePlacementIn)
  {featurePlacement = featurePlacementIn;}

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

real * two5DmillingStrategy::get_overlap()
  {return overlap;}
void two5DmillingStrategy::set_overlap(real * overlapIn)
  {overlap = overlapIn;}
boolean * two5DmillingStrategy::get_allowMultiplePasses()
  {return allowMultiplePasses;}
void two5DmillingStrategy::set_allowMultiplePasses(boolean * allowMultiplePassesIn)
  {allowMultiplePasses = allowMultiplePassesIn;}

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

booleanExpression * unaryBooleanExpression::get_operand()
  {return operand;}
void unaryBooleanExpression::set_operand(booleanExpression * operandIn)
  {operand = operandIn;}

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
  //delete get_overlap();
  //delete get_allowMultiplePasses();
  //delete cutmode;
}

int unidirectionalMilling::isA(int aType)
    { return ((aType == unidirectionalMilling_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void unidirectionalMilling::printSelf()
{
  printf("UNIDIRECTIONAL_MILLING");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (cutmode)
    cutmode->printSelf();
  else
    printf("$");
  printf(")");
}

direction * unidirectionalMilling::get_feedDirection()
  {return feedDirection;}
void unidirectionalMilling::set_feedDirection(direction * feedDirectionIn)
  {feedDirection = feedDirectionIn;}
cutmodeType * unidirectionalMilling::get_cutmode()
  {return cutmode;}
void unidirectionalMilling::set_cutmode(cutmodeType * cutmodeIn)
  {cutmode = cutmodeIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  if (itsTool)
    (dynamic_cast<instance *>(itsTool))->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

machiningTool * unloadTool::get_itsTool()
  {return itsTool;}
void unloadTool::set_itsTool(machiningTool * itsToolIn)
  {itsTool = itsToolIn;}

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
  //delete get_pathmode();
  //delete get_cutmode();
  //delete get_stepover();
}

int uvStrategy::isA(int aType)
    { return ((aType == uvStrategy_E) ||
	      (aType == freeformStrategy_E));
    }

void uvStrategy::printSelf()
{
  printf("UV_STRATEGY");
  printf("(");
  get_pathmode()->printSelf();
  printf(",");
  get_cutmode()->printSelf();
  printf(",");
  get_itsMillingTolerances()->get_iId()->printSelf();
  printf(",");
  if (get_stepover())
    get_stepover()->printSelf();
  else
    printf("$");
  printf(",");
  forwardDirection->get_iId()->printSelf();
  printf(",");
  sidewardDirection->get_iId()->printSelf();
  printf(")");
}

direction * uvStrategy::get_forwardDirection()
  {return forwardDirection;}
void uvStrategy::set_forwardDirection(direction * forwardDirectionIn)
  {forwardDirection = forwardDirectionIn;}
direction * uvStrategy::get_sidewardDirection()
  {return sidewardDirection;}
void uvStrategy::set_sidewardDirection(direction * sidewardDirectionIn)
  {sidewardDirection = sidewardDirectionIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(vertexGeometry))->get_iId()->printSelf();
  printf(")");
}

point * vertexPoint::get_vertexGeometry()
  {return vertexGeometry;}
void vertexPoint::set_vertexGeometry(point * vertexGeometryIn)
  {vertexGeometry = vertexGeometryIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  itsChannel->get_iId()->printSelf();
  printf(")");
}

channel * waitForMark::get_itsChannel()
  {return itsChannel;}
void waitForMark::set_itsChannel(channel * itsChannelIn)
  {itsChannel = itsChannelIn;}

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
  //delete dayComponent;
}

int weekOfYearAndDayDate::isA(int aType)
    { return ((aType == weekOfYearAndDayDate_E) ||
	      (aType == date_E));
    }

void weekOfYearAndDayDate::printSelf()
{
  printf("WEEEK_OF_YEAR_AND_DAY_DATE");
  printf("(");
  printf("%d", get_yearComponent());
  printf(",");
  printf("%d", weekComponent);
  printf(",");
  if (dayComponent)
    dayComponent->printSelf();
  else
    printf("$");
  printf(")");
}

int weekOfYearAndDayDate::get_weekComponent()
  {return weekComponent;}
void weekOfYearAndDayDate::set_weekComponent(int weekComponentIn)
  {weekComponent = weekComponentIn;}
integer * weekOfYearAndDayDate::get_dayComponent()
  {return dayComponent;}
void weekOfYearAndDayDate::set_dayComponent(integer * dayComponentIn)
  {dayComponent = dayComponentIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(condition))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(body))->get_iId()->printSelf();
  printf(")");
}

booleanExpression * whileStatement::get_condition()
  {return condition;}
void whileStatement::set_condition(booleanExpression * conditionIn)
  {condition = conditionIn;}
executable * whileStatement::get_body()
  {return body;}
void whileStatement::set_body(executable * bodyIn)
  {body = bodyIn;}

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
  radius->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * woodruffSlotEndType::get_radius()
  {return radius;}
void woodruffSlotEndType::set_radius(tolerancedLengthMeasure * radiusIn)
  {radius = radiusIn;}

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

elementarySurface * workingstep::get_itsSecplane()
  {return itsSecplane;}
void workingstep::set_itsSecplane(elementarySurface * itsSecplaneIn)
  {itsSecplane = itsSecplaneIn;}

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
  //delete itsId;
  //delete globalTolerance;
  //delete clampingPositions;
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
    itsMaterial->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (globalTolerance)
    globalTolerance->printSelf();
  else
    printf("$");
  printf(",");
  if (itsRawpiece)
    itsRawpiece->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsGeometry)
    itsGeometry->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsBoundingGeometry)
    (dynamic_cast<instance *>(itsBoundingGeometry))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  clampingPositions->printSelf();
  printf(")");
}

char * workpiece::get_itsId()
  {return itsId;}
void workpiece::set_itsId(char * itsIdIn)
  {itsId = itsIdIn;}
material * workpiece::get_itsMaterial()
  {return itsMaterial;}
void workpiece::set_itsMaterial(material * itsMaterialIn)
  {itsMaterial = itsMaterialIn;}
real * workpiece::get_globalTolerance()
  {return globalTolerance;}
void workpiece::set_globalTolerance(real * globalToleranceIn)
  {globalTolerance = globalToleranceIn;}
workpiece * workpiece::get_itsRawpiece()
  {return itsRawpiece;}
void workpiece::set_itsRawpiece(workpiece * itsRawpieceIn)
  {itsRawpiece = itsRawpieceIn;}
advancedBrepShapeRepresentation * workpiece::get_itsGeometry()
  {return itsGeometry;}
void workpiece::set_itsGeometry(advancedBrepShapeRepresentation * itsGeometryIn)
  {itsGeometry = itsGeometryIn;}
boundingGeometrySelect * workpiece::get_itsBoundingGeometry()
  {return itsBoundingGeometry;}
void workpiece::set_itsBoundingGeometry(boundingGeometrySelect * itsBoundingGeometryIn)
  {itsBoundingGeometry = itsBoundingGeometryIn;}
parenCartesianPointList * workpiece::get_clampingPositions()
  {return clampingPositions;}
void workpiece::set_clampingPositions(parenCartesianPointList * clampingPositionsIn)
  {clampingPositions = clampingPositionsIn;}

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
  //delete itsOffset;
  //delete itsInstructions;
}

int workpieceSetup::isA(int aType)
    { return (aType == workpieceSetup_E); }

void workpieceSetup::printSelf()
{
  printf("WORKPIECE_SETUP");
  printf("(");
  itsWorkpiece->get_iId()->printSelf();
  printf(",");
  itsOrigin->get_iId()->printSelf();
  printf(",");
  if (itsOffset)
    itsOffset->printSelf();
  else
    printf("$");
  printf(",");
  if (itsRestrictedArea)
    (dynamic_cast<instance *>(itsRestrictedArea))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  itsInstructions->printSelf();
  printf(")");
}

workpiece * workpieceSetup::get_itsWorkpiece()
  {return itsWorkpiece;}
void workpieceSetup::set_itsWorkpiece(workpiece * itsWorkpieceIn)
  {itsWorkpiece = itsWorkpieceIn;}
axis2placement3d * workpieceSetup::get_itsOrigin()
  {return itsOrigin;}
void workpieceSetup::set_itsOrigin(axis2placement3d * itsOriginIn)
  {itsOrigin = itsOriginIn;}
offsetVector * workpieceSetup::get_itsOffset()
  {return itsOffset;}
void workpieceSetup::set_itsOffset(offsetVector * itsOffsetIn)
  {itsOffset = itsOffsetIn;}
restrictedAreaSelect * workpieceSetup::get_itsRestrictedArea()
  {return itsRestrictedArea;}
void workpieceSetup::set_itsRestrictedArea(restrictedAreaSelect * itsRestrictedAreaIn)
  {itsRestrictedArea = itsRestrictedAreaIn;}
parenSetupInstructionList * workpieceSetup::get_itsInstructions()
  {return itsInstructions;}
void workpieceSetup::set_itsInstructions(parenSetupInstructionList * itsInstructionsIn)
  {itsInstructions = itsInstructionsIn;}

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
  //delete[] get_itsId();
  //delete itsElements;
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
  printString(get_itsId());
  printf(",");
  itsElements->printSelf();
  printf(",");
  if (itsChannel)
    itsChannel->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsSetup)
    itsSetup->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsEffect)
    itsEffect->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

parenExecutableList * workplan::get_itsElements()
  {return itsElements;}
void workplan::set_itsElements(parenExecutableList * itsElementsIn)
  {itsElements = itsElementsIn;}
channel * workplan::get_itsChannel()
  {return itsChannel;}
void workplan::set_itsChannel(channel * itsChannelIn)
  {itsChannel = itsChannelIn;}
setup * workplan::get_itsSetup()
  {return itsSetup;}
void workplan::set_itsSetup(setup * itsSetupIn)
  {itsSetup = itsSetupIn;}
inProcessGeometry * workplan::get_itsEffect()
  {return itsEffect;}
void workplan::set_itsEffect(inProcessGeometry * itsEffectIn)
  {itsEffect = itsEffectIn;}

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
  if (get_toolOrientation())
    get_toolOrientation()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  path->get_iId()->printSelf();
  printf(")");
}

toolpathList * alongPath::get_path()
  {return path;}
void alongPath::set_path(toolpathList * pathIn)
  {path = pathIn;}

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
  //delete get_operands();
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
  get_operands()->printSelf();
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
  //delete angle;
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

real * angleTaper::get_angle()
  {return angle;}
void angleTaper::set_angle(real * angleIn)
  {angle = angleIn;}

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
  if (get_toolOrientation())
    get_toolOrientation()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(",");
  printDouble(travelLength);
  printf(")");
}

double apRetractAngle::get_angle()
  {return angle;}
void apRetractAngle::set_angle(double angleIn)
  {angle = angleIn;}
double apRetractAngle::get_travelLength()
  {return travelLength;}
void apRetractAngle::set_travelLength(double travelLengthIn)
  {travelLength = travelLengthIn;}

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
  if (get_toolOrientation())
    get_toolOrientation()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(radius);
  printf(")");
}

double apRetractTangent::get_radius()
  {return radius;}
void apRetractTangent::set_radius(double radiusIn)
  {radius = radiusIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  itsLvalue->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsRvalue))->get_iId()->printSelf();
  printf(")");
}

ncVariable * assignment::get_itsLvalue()
  {return itsLvalue;}
void assignment::set_itsLvalue(ncVariable * itsLvalueIn)
  {itsLvalue = itsLvalueIn;}
rvalue * assignment::get_itsRvalue()
  {return itsRvalue;}
void assignment::set_itsRvalue(rvalue * itsRvalueIn)
  {itsRvalue = itsRvalueIn;}

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
  //delete get_itsPriority();
  //delete get_itsType();
  //delete get_itsDirection();
  //delete axisList;
  //delete commands;
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
  get_itsPriority()->printSelf();
  printf(",");
  get_itsType()->printSelf();
  printf(",");
  if (get_itsSpeed())
    get_itsSpeed()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsTechnology())
    (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachineFunctions())
    (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsDirection())
    get_itsDirection()->printSelf();
  else
    printf("$");
  printf(",");
  axisList->printSelf();
  printf(",");
  commands->printSelf();
  printf(")");
}

parenStringListFull * axisTrajectory::get_axisList()
  {return axisList;}
void axisTrajectory::set_axisList(parenStringListFull * axisListIn)
  {axisList = axisListIn;}
parenBoundedCurveListFull * axisTrajectory::get_commands()
  {return commands;}
void axisTrajectory::set_commands(parenBoundedCurveListFull * commandsIn)
  {commands = commandsIn;}

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
  //delete get_overlap();
  //delete get_allowMultiplePasses();
  //delete stepoverDirection;
  //delete rotationDirection;
  //delete spiralCutmode;
}

int bidirectionalContour::isA(int aType)
    { return ((aType == bidirectionalContour_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void bidirectionalContour::printSelf()
{
  printf("BIDIRECTIONAL_CONTOUR");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->get_iId()->printSelf();
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

direction * bidirectionalContour::get_feedDirection()
  {return feedDirection;}
void bidirectionalContour::set_feedDirection(direction * feedDirectionIn)
  {feedDirection = feedDirectionIn;}
leftOrRight * bidirectionalContour::get_stepoverDirection()
  {return stepoverDirection;}
void bidirectionalContour::set_stepoverDirection(leftOrRight * stepoverDirectionIn)
  {stepoverDirection = stepoverDirectionIn;}
rotDirection * bidirectionalContour::get_rotationDirection()
  {return rotationDirection;}
void bidirectionalContour::set_rotationDirection(rotDirection * rotationDirectionIn)
  {rotationDirection = rotationDirectionIn;}
cutmodeType * bidirectionalContour::get_spiralCutmode()
  {return spiralCutmode;}
void bidirectionalContour::set_spiralCutmode(cutmodeType * spiralCutmodeIn)
  {spiralCutmode = spiralCutmodeIn;}

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
  //delete get_overlap();
  //delete get_allowMultiplePasses();
  //delete stepoverDirection;
  //delete itsStrokeConnectionStrategy;
}

int bidirectionalMilling::isA(int aType)
    { return ((aType == bidirectionalMilling_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void bidirectionalMilling::printSelf()
{
  printf("BIDIRECTIONAL_MILLING");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->get_iId()->printSelf();
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

direction * bidirectionalMilling::get_feedDirection()
  {return feedDirection;}
void bidirectionalMilling::set_feedDirection(direction * feedDirectionIn)
  {feedDirection = feedDirectionIn;}
leftOrRight * bidirectionalMilling::get_stepoverDirection()
  {return stepoverDirection;}
void bidirectionalMilling::set_stepoverDirection(leftOrRight * stepoverDirectionIn)
  {stepoverDirection = stepoverDirectionIn;}
strokeConnectionStrategy * bidirectionalMilling::get_itsStrokeConnectionStrategy()
  {return itsStrokeConnectionStrategy;}
void bidirectionalMilling::set_itsStrokeConnectionStrategy(strokeConnectionStrategy * itsStrokeConnectionStrategyIn)
  {itsStrokeConnectionStrategy = itsStrokeConnectionStrategyIn;}

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

booleanExpression * binaryBooleanExpression::get_operand1()
  {return operand1;}
void binaryBooleanExpression::set_operand1(booleanExpression * operand1In)
  {operand1 = operand1In;}
booleanExpression * binaryBooleanExpression::get_operand2()
  {return operand2;}
void binaryBooleanExpression::set_operand2(booleanExpression * operand2In)
  {operand2 = operand2In;}

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
  printf("%d", get_yearComponent());
  printf(",");
  printf("%d", dayComponent);
  printf(",");
  printf("%d", monthComponent);
  printf(")");
}

int calendarDate::get_dayComponent()
  {return dayComponent;}
void calendarDate::set_dayComponent(int dayComponentIn)
  {dayComponent = dayComponentIn;}
int calendarDate::get_monthComponent()
  {return monthComponent;}
void calendarDate::set_monthComponent(int monthComponentIn)
  {monthComponent = monthComponentIn;}

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
  //delete get_overlap();
  //delete get_allowMultiplePasses();
}

int centerMilling::isA(int aType)
    { return ((aType == centerMilling_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void centerMilling::printSelf()
{
  printf("CENTER_MILLING");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_firstFeature()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_secondFeature()))->get_iId()->printSelf();
  printf(",");
  printDouble(angleToPlane);
  printf(",");
  firstOffsetAmount->get_iId()->printSelf();
  printf(")");
}

double chamfer::get_angleToPlane()
  {return angleToPlane;}
void chamfer::set_angleToPlane(double angleToPlaneIn)
  {angleToPlane = angleToPlaneIn;}
tolerancedLengthMeasure * chamfer::get_firstOffsetAmount()
  {return firstOffsetAmount;}
void chamfer::set_firstOffsetAmount(tolerancedLengthMeasure * firstOffsetAmountIn)
  {firstOffsetAmount = firstOffsetAmountIn;}

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

tolerancedLengthMeasure * circularPath::get_radius()
  {return radius;}
void circularPath::set_radius(tolerancedLengthMeasure * radiusIn)
  {radius = radiusIn;}

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
  get_operand1()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_operand2()))->get_iId()->printSelf();
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
  get_operand1()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_operand2()))->get_iId()->printSelf();
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
  get_operand1()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_operand2()))->get_iId()->printSelf();
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
  get_operand1()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_operand2()))->get_iId()->printSelf();
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
  get_operand1()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_operand2()))->get_iId()->printSelf();
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
  get_operand1()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_operand2()))->get_iId()->printSelf();
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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_radius()->get_iId()->printSelf();
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

parenCompoundFeatureSelectListFull * compoundFeature::get_elements()
  {return elements;}
void compoundFeature::set_elements(parenCompoundFeatureSelectListFull * elementsIn)
  {elements = elementsIn;}

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
  //delete tipAngle;
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
    tipRadius->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

real * conicalHoleBottom::get_tipAngle()
  {return tipAngle;}
void conicalHoleBottom::set_tipAngle(real * tipAngleIn)
  {tipAngle = tipAngleIn;}
tolerancedLengthMeasure * conicalHoleBottom::get_tipRadius()
  {return tipRadius;}
void conicalHoleBottom::set_tipRadius(tolerancedLengthMeasure * tipRadiusIn)
  {tipRadius = tipRadiusIn;}

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

parenFaceListFull * connectedFaceSet::get_cfsFaces()
  {return cfsFaces;}
void connectedFaceSet::set_cfsFaces(parenFaceListFull * cfsFacesIn)
  {cfsFaces = cfsFacesIn;}

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
  //delete get_overlap();
  //delete get_allowMultiplePasses();
  //delete stepoverDirection;
  //delete rotationDirection;
  //delete spiralCutmode;
}

int contourBidirectional::isA(int aType)
    { return ((aType == contourBidirectional_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void contourBidirectional::printSelf()
{
  printf("CONTOUR_BIDIRECTIONAL");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
  else
    printf("$");
  printf(",");
  if (feedDirection)
    feedDirection->get_iId()->printSelf();
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

direction * contourBidirectional::get_feedDirection()
  {return feedDirection;}
void contourBidirectional::set_feedDirection(direction * feedDirectionIn)
  {feedDirection = feedDirectionIn;}
leftOrRight * contourBidirectional::get_stepoverDirection()
  {return stepoverDirection;}
void contourBidirectional::set_stepoverDirection(leftOrRight * stepoverDirectionIn)
  {stepoverDirection = stepoverDirectionIn;}
rotDirection * contourBidirectional::get_rotationDirection()
  {return rotationDirection;}
void contourBidirectional::set_rotationDirection(rotDirection * rotationDirectionIn)
  {rotationDirection = rotationDirectionIn;}
cutmodeType * contourBidirectional::get_spiralCutmode()
  {return spiralCutmode;}
void contourBidirectional::set_spiralCutmode(cutmodeType * spiralCutmodeIn)
  {spiralCutmode = spiralCutmodeIn;}

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
  //delete get_overlap();
  //delete get_allowMultiplePasses();
  //delete rotationDirection;
  //delete cutmode;
}

int contourParallel::isA(int aType)
    { return ((aType == contourParallel_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void contourParallel::printSelf()
{
  printf("CONTOUR_PARALLEL");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
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

rotDirection * contourParallel::get_rotationDirection()
  {return rotationDirection;}
void contourParallel::set_rotationDirection(rotDirection * rotationDirectionIn)
  {rotationDirection = rotationDirectionIn;}
cutmodeType * contourParallel::get_cutmode()
  {return cutmode;}
void contourParallel::set_cutmode(cutmodeType * cutmodeIn)
  {cutmode = cutmodeIn;}

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
  //delete get_overlap();
  //delete get_allowMultiplePasses();
  //delete rotationDirection;
  //delete cutmode;
}

int contourSpiral::isA(int aType)
    { return ((aType == contourSpiral_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void contourSpiral::printSelf()
{
  printf("CONTOUR_SPIRAL");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
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

rotDirection * contourSpiral::get_rotationDirection()
  {return rotationDirection;}
void contourSpiral::set_rotationDirection(rotDirection * rotationDirectionIn)
  {rotationDirection = rotationDirectionIn;}
cutmodeType * contourSpiral::get_cutmode()
  {return cutmode;}
void contourSpiral::set_cutmode(cutmodeType * cutmodeIn)
  {cutmode = cutmodeIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete get_elements();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  get_elements()->printSelf();
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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete get_elements();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  get_elements()->printSelf();
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
  (dynamic_cast<instance *>(basiccurve))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(surfaceNormal))->get_iId()->printSelf();
  printf(")");
}

boundedCurve * curveWithNormalVector::get_basiccurve()
  {return basiccurve;}
void curveWithNormalVector::set_basiccurve(boundedCurve * basiccurveIn)
  {basiccurve = basiccurveIn;}
boundedCurve * curveWithNormalVector::get_surfaceNormal()
  {return surfaceNormal;}
void curveWithNormalVector::set_surfaceNormal(boundedCurve * surfaceNormalIn)
  {surfaceNormal = surfaceNormalIn;}

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
  //delete get_itsPriority();
  //delete get_itsType();
  //delete get_itsDirection();
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
  get_itsPriority()->printSelf();
  printf(",");
  get_itsType()->printSelf();
  printf(",");
  if (get_itsSpeed())
    get_itsSpeed()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsTechnology())
    (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachineFunctions())
    (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsDirection())
    get_itsDirection()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(basiccurve))->get_iId()->printSelf();
  printf(",");
  if (itsToolaxis)
    (dynamic_cast<instance *>(itsToolaxis))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (surfaceNormal)
    (dynamic_cast<instance *>(surfaceNormal))->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

boundedCurve * cutterLocationTrajectory::get_basiccurve()
  {return basiccurve;}
void cutterLocationTrajectory::set_basiccurve(boundedCurve * basiccurveIn)
  {basiccurve = basiccurveIn;}
boundedCurve * cutterLocationTrajectory::get_itsToolaxis()
  {return itsToolaxis;}
void cutterLocationTrajectory::set_itsToolaxis(boundedCurve * itsToolaxisIn)
  {itsToolaxis = itsToolaxisIn;}
boundedCurve * cutterLocationTrajectory::get_surfaceNormal()
  {return surfaceNormal;}
void cutterLocationTrajectory::set_surfaceNormal(boundedCurve * surfaceNormalIn)
  {surfaceNormal = surfaceNormalIn;}

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

toolBody * cuttingTool::get_itsToolBody()
  {return itsToolBody;}
void cuttingTool::set_itsToolBody(toolBody * itsToolBodyIn)
  {itsToolBody = itsToolBodyIn;}
parenCuttingComponentListFull * cuttingTool::get_itsCuttingEdge()
  {return itsCuttingEdge;}
void cuttingTool::set_itsCuttingEdge(parenCuttingComponentListFull * itsCuttingEdgeIn)
  {itsCuttingEdge = itsCuttingEdgeIn;}
real * cuttingTool::get_overallAssemblyLength()
  {return overallAssemblyLength;}
void cuttingTool::set_overallAssemblyLength(real * overallAssemblyLengthIn)
  {overallAssemblyLength = overallAssemblyLengthIn;}

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
  //delete[] get_name();
  //delete get_items();
  //delete get_contextOfItems();
}

int definitionalRepresentation::isA(int aType)
    { return ((aType == definitionalRepresentation_E) ||
	      (aType == representationParent_E));
    }

void definitionalRepresentation::printSelf()
{
  printf("DEFINITIONAL_REPRESENTATION");
  printf("(");
  printString(get_name());
  printf(",");
  get_items()->printSelf();
  printf(",");
  get_contextOfItems()->printSelf();
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
  //delete get_parameterName();
  //delete descriptiveString;
}

int descriptiveParameter::isA(int aType)
    { return ((aType == descriptiveParameter_E) ||
	      (aType == propertyParameter_E));
    }

void descriptiveParameter::printSelf()
{
  printf("DESCRIPTIVE_PARAMETER");
  printf("(");
  printString(get_parameterName());
  printf(",");
  printString(descriptiveString);
  printf(")");
}

char * descriptiveParameter::get_descriptiveString()
  {return descriptiveString;}
void descriptiveParameter::set_descriptiveString(char * descriptiveStringIn)
  {descriptiveString = descriptiveStringIn;}

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
  finalDiameter->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * diameterTaper::get_finalDiameter()
  {return finalDiameter;}
void diameterTaper::set_finalDiameter(tolerancedLengthMeasure * finalDiameterIn)
  {finalDiameter = finalDiameterIn;}

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
  //delete[] get_itsId();
  //delete itsText;
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
  printString(get_itsId());
  printf(",");
  printString(itsText);
  printf(")");
}

char * displayMessage::get_itsText()
  {return itsText;}
void displayMessage::set_itsText(char * itsTextIn)
  {itsText = itsTextIn;}

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

vertex * edge::get_edgeStart()
  {return edgeStart;}
void edge::set_edgeStart(vertex * edgeStartIn)
  {edgeStart = edgeStartIn;}
vertex * edge::get_edgeEnd()
  {return edgeEnd;}
void edge::set_edgeEnd(vertex * edgeEndIn)
  {edgeEnd = edgeEndIn;}

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
  //delete[] get_name();
  //delete sameSense;
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(get_edgeStart()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_edgeEnd()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(edgeGeometry))->get_iId()->printSelf();
  printf(",");
  sameSense->printSelf();
  printf(")");
}

curve * edgeCurve::get_edgeGeometry()
  {return edgeGeometry;}
void edgeCurve::set_edgeGeometry(curve * edgeGeometryIn)
  {edgeGeometry = edgeGeometryIn;}
boolean * edgeCurve::get_sameSense()
  {return sameSense;}
void edgeCurve::set_sameSense(boolean * sameSenseIn)
  {sameSense = sameSenseIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_firstFeature()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_secondFeature()))->get_iId()->printSelf();
  printf(",");
  radius->get_iId()->printSelf();
  printf(",");
  if (firstOffsetAmount)
    firstOffsetAmount->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (secondOffsetAmount)
    secondOffsetAmount->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

tolerancedLengthMeasure * edgeRound::get_radius()
  {return radius;}
void edgeRound::set_radius(tolerancedLengthMeasure * radiusIn)
  {radius = radiusIn;}
tolerancedLengthMeasure * edgeRound::get_firstOffsetAmount()
  {return firstOffsetAmount;}
void edgeRound::set_firstOffsetAmount(tolerancedLengthMeasure * firstOffsetAmountIn)
  {firstOffsetAmount = firstOffsetAmountIn;}
tolerancedLengthMeasure * edgeRound::get_secondOffsetAmount()
  {return secondOffsetAmount;}
void edgeRound::set_secondOffsetAmount(tolerancedLengthMeasure * secondOffsetAmountIn)
  {secondOffsetAmount = secondOffsetAmountIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
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
  //delete get_overlap();
  //delete get_allowMultiplePasses();
}

int explicitStrategy::isA(int aType)
    { return ((aType == explicitStrategy_E) ||
	      (aType == two5DmillingStrategy_E));
    }

void explicitStrategy::printSelf()
{
  printf("EXPLICIT_STRATEGY");
  printf("(");
  if (get_overlap())
    get_overlap()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowMultiplePasses())
    get_allowMultiplePasses()->printSelf();
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

parenFaceBoundListFull * face::get_bounds()
  {return bounds;}
void face::set_bounds(parenFaceBoundListFull * boundsIn)
  {bounds = boundsIn;}

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

loop * faceBoundParent::get_bound()
  {return bound;}
void faceBoundParent::set_bound(loop * boundIn)
  {bound = boundIn;}
boolean * faceBoundParent::get_orientation()
  {return orientation;}
void faceBoundParent::set_orientation(boolean * orientationIn)
  {orientation = orientationIn;}

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
  //delete[] get_name();
  //delete get_orientation();
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(get_bound()))->get_iId()->printSelf();
  printf(",");
  get_orientation()->printSelf();
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
  //delete[] get_name();
  //delete get_orientation();
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(get_bound()))->get_iId()->printSelf();
  printf(",");
  get_orientation()->printSelf();
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

surface * faceSurface::get_faceGeometry()
  {return faceGeometry;}
void faceSurface::set_faceGeometry(surface * faceGeometryIn)
  {faceGeometry = faceGeometryIn;}
boolean * faceSurface::get_sameSense()
  {return sameSense;}
void faceSurface::set_sameSense(boolean * sameSenseIn)
  {sameSense = sameSenseIn;}

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
  //delete get_itsPriority();
  //delete get_itsType();
}

int feedstop::isA(int aType)
    { return ((aType == feedstop_E) ||
	      (aType == toolpath_E));
    }

void feedstop::printSelf()
{
  printf("FEEDSTOP");
  printf("(");
  get_itsPriority()->printSelf();
  printf(",");
  get_itsType()->printSelf();
  printf(",");
  if (get_itsSpeed())
    get_itsSpeed()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsTechnology())
    (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachineFunctions())
    (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(dwell);
  printf(")");
}

double feedstop::get_dwell()
  {return dwell;}
void feedstop::set_dwell(double dwellIn)
  {dwell = dwellIn;}

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

double fiveAxesConstTiltYaw::get_tiltAngle()
  {return tiltAngle;}
void fiveAxesConstTiltYaw::set_tiltAngle(double tiltAngleIn)
  {tiltAngle = tiltAngleIn;}
double fiveAxesConstTiltYaw::get_yawAngle()
  {return yawAngle;}
void fiveAxesConstTiltYaw::set_yawAngle(double yawAngleIn)
  {yawAngle = yawAngleIn;}

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
  cornerRadius1->get_iId()->printSelf();
  printf(",");
  cornerRadius2->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * flatSlotEndType::get_cornerRadius1()
  {return cornerRadius1;}
void flatSlotEndType::set_cornerRadius1(tolerancedLengthMeasure * cornerRadius1In)
  {cornerRadius1 = cornerRadius1In;}
tolerancedLengthMeasure * flatSlotEndType::get_cornerRadius2()
  {return cornerRadius2;}
void flatSlotEndType::set_cornerRadius2(tolerancedLengthMeasure * cornerRadius2In)
  {cornerRadius2 = cornerRadius2In;}

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
  cornerRadius->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * flatWithRadiusHoleBottom::get_cornerRadius()
  {return cornerRadius;}
void flatWithRadiusHoleBottom::set_cornerRadius(tolerancedLengthMeasure * cornerRadiusIn)
  {cornerRadius = cornerRadiusIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(closedProfileShape))->get_iId()->printSelf();
  printf(")");
}

boundedCurve * generalClosedProfile::get_closedProfileShape()
  {return closedProfileShape;}
void generalClosedProfile::set_closedProfileShape(boundedCurve * closedProfileShapeIn)
  {closedProfileShape = closedProfileShapeIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(sweptPath))->get_iId()->printSelf();
  printf(")");
}

boundedCurve * generalPath::get_sweptPath()
  {return sweptPath;}
void generalPath::set_sweptPath(boundedCurve * sweptPathIn)
  {sweptPath = sweptPathIn;}

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
  (dynamic_cast<instance *>(shape))->get_iId()->printSelf();
  printf(")");
}

region * generalPocketBottomCondition::get_shape()
  {return shape;}
void generalPocketBottomCondition::set_shape(region * shapeIn)
  {shape = shapeIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(condition))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(trueBranch))->get_iId()->printSelf();
  printf(",");
  if (falseBranch)
    (dynamic_cast<instance *>(falseBranch))->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

booleanExpression * ifStatement::get_condition()
  {return condition;}
void ifStatement::set_condition(booleanExpression * conditionIn)
  {condition = conditionIn;}
executable * ifStatement::get_trueBranch()
  {return trueBranch;}
void ifStatement::set_trueBranch(executable * trueBranchIn)
  {trueBranch = trueBranchIn;}
executable * ifStatement::get_falseBranch()
  {return falseBranch;}
void ifStatement::set_falseBranch(executable * falseBranchIn)
  {falseBranch = falseBranchIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  printf("%d", its_index);
  printf(")");
}

int indexPallet::get_its_index()
  {return its_index;}
void indexPallet::set_its_index(int its_indexIn)
  {its_index = its_indexIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  printf("%d", its_index);
  printf(")");
}

int indexTable::get_its_index()
  {return its_index;}
void indexTable::set_its_index(int its_indexIn)
  {its_index = its_indexIn;}

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
  //delete itsFittingType;
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

double limitsAndFits::get_deviation()
  {return deviation;}
void limitsAndFits::set_deviation(double deviationIn)
  {deviation = deviationIn;}
double limitsAndFits::get_grade()
  {return grade;}
void limitsAndFits::set_grade(double gradeIn)
  {grade = gradeIn;}
fittingType * limitsAndFits::get_itsFittingType()
  {return itsFittingType;}
void limitsAndFits::set_itsFittingType(fittingType * itsFittingTypeIn)
  {itsFittingType = itsFittingTypeIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  distance->get_iId()->printSelf();
  printf(",");
  itsDirection->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * linearPath::get_distance()
  {return distance;}
void linearPath::set_distance(tolerancedLengthMeasure * distanceIn)
  {distance = distanceIn;}
direction * linearPath::get_itsDirection()
  {return itsDirection;}
void linearPath::set_itsDirection(direction * itsDirectionIn)
  {itsDirection = itsDirectionIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(itsTool))->get_iId()->printSelf();
  printf(")");
}

machiningTool * loadTool::get_itsTool()
  {return itsTool;}
void loadTool::set_itsTool(machiningTool * itsToolIn)
  {itsTool = itsToolIn;}

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

elementarySurface * machiningFeature::get_depth()
  {return depth;}
void machiningFeature::set_depth(elementarySurface * depthIn)
  {depth = depthIn;}

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

machiningOperation::~machiningOperation(){
	if (isItsIdLoaded){
		delete[] itsId;
	}
}

int machiningOperation::isA(int aType)
    { return ((aType == machiningOperation_E) ||
	      (aType == operation_E));
    }

char * machiningOperation::get_itsId()
  {return itsId;}
void machiningOperation::set_itsId(char * itsIdIn)
  {itsId = itsIdIn;}
real * machiningOperation::get_retractPlane()
  {return retractPlane;}
void machiningOperation::set_retractPlane(real * retractPlaneIn)
  {retractPlane = retractPlaneIn;}
cartesianPoint * machiningOperation::get_startPoint()
  {return startPoint;}
void machiningOperation::set_startPoint(cartesianPoint * startPointIn)
  {startPoint = startPointIn;}
machiningTool * machiningOperation::get_itsTool()
  {return itsTool;}
void machiningOperation::set_itsTool(machiningTool * itsToolIn)
  {itsTool = itsToolIn;}
technology * machiningOperation::get_itsTechnology()
  {return itsTechnology;}
void machiningOperation::set_itsTechnology(technology * itsTechnologyIn)
  {itsTechnology = itsTechnologyIn;}
machineFunctions * machiningOperation::get_itsMachineFunctions()
  {return itsMachineFunctions;}
void machiningOperation::set_itsMachineFunctions(machineFunctions * itsMachineFunctionsIn)
  {itsMachineFunctions = itsMachineFunctionsIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsFeature))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsOperation))->get_iId()->printSelf();
  printf(",");
  if (itsEffect)
    itsEffect->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

manufacturingFeature * machiningWorkingstep::get_itsFeature()
  {return itsFeature;}
void machiningWorkingstep::set_itsFeature(manufacturingFeature * itsFeatureIn)
  {itsFeature = itsFeatureIn;}
machiningOperation * machiningWorkingstep::get_itsOperation()
  {return itsOperation;}
void machiningWorkingstep::set_itsOperation(machiningOperation * itsOperationIn)
  {itsOperation = itsOperationIn;}
inProcessGeometry * machiningWorkingstep::get_itsEffect()
  {return itsEffect;}
void machiningWorkingstep::set_itsEffect(inProcessGeometry * itsEffectIn)
  {itsEffect = itsEffectIn;}

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
  //delete[] get_itsId();
  //delete get_itsCuttingEdge();
  //delete get_overallAssemblyLength();
  //delete toolHolderDiameterForSpindleOrientation;
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsToolBody()))->get_iId()->printSelf();
  printf(",");
  get_itsCuttingEdge()->printSelf();
  printf(",");
  if (get_overallAssemblyLength())
    get_overallAssemblyLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (directionForSpindleOrientation)
    directionForSpindleOrientation->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (toolHolderDiameterForSpindleOrientation)
    toolHolderDiameterForSpindleOrientation->printSelf();
  else
    printf("$");
  printf(")");
}

direction * millingCuttingTool::get_directionForSpindleOrientation()
  {return directionForSpindleOrientation;}
void millingCuttingTool::set_directionForSpindleOrientation(direction * directionForSpindleOrientationIn)
  {directionForSpindleOrientation = directionForSpindleOrientationIn;}
real * millingCuttingTool::get_toolHolderDiameterForSpindleOrientation()
  {return toolHolderDiameterForSpindleOrientation;}
void millingCuttingTool::set_toolHolderDiameterForSpindleOrientation(real * toolHolderDiameterForSpindleOrientationIn)
  {toolHolderDiameterForSpindleOrientation = toolHolderDiameterForSpindleOrientationIn;}

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

real * millingMachiningOperation::get_overcutLength()
  {return overcutLength;}
void millingMachiningOperation::set_overcutLength(real * overcutLengthIn)
  {overcutLength = overcutLengthIn;}

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
  //delete get_feedrate();
  //delete get_feedrateReference();
  //delete cutspeed;
  //delete spindle;
  //delete feedratePerTooth;
  //delete synchronizeSpindleWithFeed;
  //delete inhibitFeedrateOverride;
  //delete inhibitSpindleOverride;
  //delete itsAdaptiveControl;
}

int millingTechnology::isA(int aType)
    { return ((aType == millingTechnology_E) ||
	      (aType == technology_E));
    }

void millingTechnology::printSelf()
{
  printf("MILLING_TECHNOLOGY");
  printf("(");
  if (get_feedrate())
    get_feedrate()->printSelf();
  else
    printf("$");
  printf(",");
  get_feedrateReference()->printSelf();
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

real * millingTechnology::get_cutspeed()
  {return cutspeed;}
void millingTechnology::set_cutspeed(real * cutspeedIn)
  {cutspeed = cutspeedIn;}
real * millingTechnology::get_spindle()
  {return spindle;}
void millingTechnology::set_spindle(real * spindleIn)
  {spindle = spindleIn;}
real * millingTechnology::get_feedratePerTooth()
  {return feedratePerTooth;}
void millingTechnology::set_feedratePerTooth(real * feedratePerToothIn)
  {feedratePerTooth = feedratePerToothIn;}
boolean * millingTechnology::get_synchronizeSpindleWithFeed()
  {return synchronizeSpindleWithFeed;}
void millingTechnology::set_synchronizeSpindleWithFeed(boolean * synchronizeSpindleWithFeedIn)
  {synchronizeSpindleWithFeed = synchronizeSpindleWithFeedIn;}
boolean * millingTechnology::get_inhibitFeedrateOverride()
  {return inhibitFeedrateOverride;}
void millingTechnology::set_inhibitFeedrateOverride(boolean * inhibitFeedrateOverrideIn)
  {inhibitFeedrateOverride = inhibitFeedrateOverrideIn;}
boolean * millingTechnology::get_inhibitSpindleOverride()
  {return inhibitSpindleOverride;}
void millingTechnology::set_inhibitSpindleOverride(boolean * inhibitSpindleOverrideIn)
  {inhibitSpindleOverride = inhibitSpindleOverrideIn;}
boolean * millingTechnology::get_itsAdaptiveControl()
  {return itsAdaptiveControl;}
void millingTechnology::set_itsAdaptiveControl(boolean * itsAdaptiveControlIn)
  {itsAdaptiveControl = itsAdaptiveControlIn;}

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

millingToolDimension * millingToolBody::get_dimension()
  {return dimension;}
void millingToolBody::set_dimension(millingToolDimension * dimensionIn)
  {dimension = dimensionIn;}
integer * millingToolBody::get_numberOfTeeth()
  {return numberOfTeeth;}
void millingToolBody::set_numberOfTeeth(integer * numberOfTeethIn)
  {numberOfTeeth = numberOfTeethIn;}
hand * millingToolBody::get_handOfCut()
  {return handOfCut;}
void millingToolBody::set_handOfCut(hand * handOfCutIn)
  {handOfCut = handOfCutIn;}
boolean * millingToolBody::get_coolantThroughTool()
  {return coolantThroughTool;}
void millingToolBody::set_coolantThroughTool(boolean * coolantThroughToolIn)
  {coolantThroughTool = coolantThroughToolIn;}
real * millingToolBody::get_pilotLength()
  {return pilotLength;}
void millingToolBody::set_pilotLength(real * pilotLengthIn)
  {pilotLength = pilotLengthIn;}

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

approachRetractStrategy * millingTypeOperation::get_approach()
  {return approach;}
void millingTypeOperation::set_approach(approachRetractStrategy * approachIn)
  {approach = approachIn;}
approachRetractStrategy * millingTypeOperation::get_retract()
  {return retract;}
void millingTypeOperation::set_retract(approachRetractStrategy * retractIn)
  {retract = retractIn;}

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
  //delete itsName;
  //delete initialValue;
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

char * ncConstant::get_itsName()
  {return itsName;}
void ncConstant::set_itsName(char * itsNameIn)
  {itsName = itsNameIn;}
real * ncConstant::get_initialValue()
  {return initialValue;}
void ncConstant::set_initialValue(real * initialValueIn)
  {initialValue = initialValueIn;}

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
  //delete itsName;
  //delete initialValue;
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

char * ncVariable::get_itsName()
  {return itsName;}
void ncVariable::set_itsName(char * itsNameIn)
  {itsName = itsNameIn;}
real * ncVariable::get_initialValue()
  {return initialValue;}
void ncVariable::set_initialValue(real * initialValueIn)
  {initialValue = initialValueIn;}

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
  //delete circumscribedOrAcrossFlats;
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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  diameter->get_iId()->printSelf();
  printf(",");
  printf("%d", numberOfSides);
  printf(",");
  circumscribedOrAcrossFlats->printSelf();
  printf(")");
}

tolerancedLengthMeasure * ngonClosedProfile::get_diameter()
  {return diameter;}
void ngonClosedProfile::set_diameter(tolerancedLengthMeasure * diameterIn)
  {diameter = diameterIn;}
int ngonClosedProfile::get_numberOfSides()
  {return numberOfSides;}
void ngonClosedProfile::set_numberOfSides(int numberOfSidesIn)
  {numberOfSides = numberOfSidesIn;}
boolean * ngonClosedProfile::get_circumscribedOrAcrossFlats()
  {return circumscribedOrAcrossFlats;}
void ngonClosedProfile::set_circumscribedOrAcrossFlats(boolean * circumscribedOrAcrossFlatsIn)
  {circumscribedOrAcrossFlats = circumscribedOrAcrossFlatsIn;}

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
  //delete[] get_itsId();
  //delete itsElements;
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
  printString(get_itsId());
  printf(",");
  itsElements->printSelf();
  printf(")");
}

parenExecutableListFull * nonSequential::get_itsElements()
  {return itsElements;}
void nonSequential::set_itsElements(parenExecutableListFull * itsElementsIn)
  {itsElements = itsElementsIn;}

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
  (dynamic_cast<instance *>(get_operand()))->get_iId()->printSelf();
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
  //delete get_parameterName();
  //delete itsParameterUnit;
}

int numericParameter::isA(int aType)
    { return ((aType == numericParameter_E) ||
	      (aType == propertyParameter_E));
    }

void numericParameter::printSelf()
{
  printf("NUMERIC_PARAMETER");
  printf("(");
  printString(get_parameterName());
  printf(",");
  printDouble(itsParameterValue);
  printf(",");
  printString(itsParameterUnit);
  printf(")");
}

double numericParameter::get_itsParameterValue()
  {return itsParameterValue;}
void numericParameter::set_itsParameterValue(double itsParameterValueIn)
  {itsParameterValue = itsParameterValueIn;}
char * numericParameter::get_itsParameterUnit()
  {return itsParameterUnit;}
void numericParameter::set_itsParameterUnit(char * itsParameterUnitIn)
  {itsParameterUnit = itsParameterUnitIn;}

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
  //delete[] get_name();
  //delete get_cfsFaces();
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
  printString(get_name());
  printf(",");
  get_cfsFaces()->printSelf();
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
  //delete[] get_name();
  //delete orientation;
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(get_edgeStart()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_edgeEnd()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(edgeElement))->get_iId()->printSelf();
  printf(",");
  orientation->printSelf();
  printf(")");
}

edge * orientedEdge::get_edgeElement()
  {return edgeElement;}
void orientedEdge::set_edgeElement(edge * edgeElementIn)
  {edgeElement = edgeElementIn;}
boolean * orientedEdge::get_orientation()
  {return orientation;}
void orientedEdge::set_orientation(boolean * orientationIn)
  {orientation = orientationIn;}

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
  //delete[] get_itsId();
  //delete branches;
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
  printString(get_itsId());
  printf(",");
  branches->printSelf();
  printf(")");
}

parenExecutableListFull * parallel::get_branches()
  {return branches;}
void parallel::set_branches(parenExecutableListFull * branchesIn)
  {branches = branchesIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_radius()->get_iId()->printSelf();
  printf(",");
  printDouble(sweepAngle);
  printf(")");
}

double partialCircularPath::get_sweepAngle()
  {return sweepAngle;}
void partialCircularPath::set_sweepAngle(double sweepAngleIn)
  {sweepAngle = sweepAngleIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  radius->get_iId()->printSelf();
  printf(",");
  printDouble(sweepAngle);
  printf(")");
}

tolerancedLengthMeasure * partialCircularProfile::get_radius()
  {return radius;}
void partialCircularProfile::set_radius(tolerancedLengthMeasure * radiusIn)
  {radius = radiusIn;}
double partialCircularProfile::get_sweepAngle()
  {return sweepAngle;}
void partialCircularProfile::set_sweepAngle(double sweepAngleIn)
  {sweepAngle = sweepAngleIn;}

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

cartesianPoint * placement::get_location()
  {return location;}
void placement::set_location(cartesianPoint * locationIn)
  {location = locationIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete itsBoss;
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  courseOfTravel->get_iId()->printSelf();
  printf(",");
  removalBoundary->get_iId()->printSelf();
  printf(",");
  if (faceBoundary)
    (dynamic_cast<instance *>(faceBoundary))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  itsBoss->printSelf();
  printf(")");
}

linearPath * planarFace::get_courseOfTravel()
  {return courseOfTravel;}
void planarFace::set_courseOfTravel(linearPath * courseOfTravelIn)
  {courseOfTravel = courseOfTravelIn;}
linearProfile * planarFace::get_removalBoundary()
  {return removalBoundary;}
void planarFace::set_removalBoundary(linearProfile * removalBoundaryIn)
  {removalBoundary = removalBoundaryIn;}
closedProfile * planarFace::get_faceBoundary()
  {return faceBoundary;}
void planarFace::set_faceBoundary(closedProfile * faceBoundaryIn)
  {faceBoundary = faceBoundaryIn;}
parenBossList * planarFace::get_itsBoss()
  {return itsBoss;}
void planarFace::set_itsBoss(parenBossList * itsBossIn)
  {itsBoss = itsBossIn;}

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

double plusMinusValue::get_upperLimit()
  {return upperLimit;}
void plusMinusValue::set_upperLimit(double upperLimitIn)
  {upperLimit = upperLimitIn;}
double plusMinusValue::get_lowerLimit()
  {return lowerLimit;}
void plusMinusValue::set_lowerLimit(double lowerLimitIn)
  {lowerLimit = lowerLimitIn;}
int plusMinusValue::get_significantDigits()
  {return significantDigits;}
void plusMinusValue::set_significantDigits(int significantDigitsIn)
  {significantDigits = significantDigitsIn;}

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

parenBossList * pocket::get_itsBoss()
  {return itsBoss;}
void pocket::set_itsBoss(parenBossList * itsBossIn)
  {itsBoss = itsBossIn;}
real * pocket::get_slope()
  {return slope;}
void pocket::set_slope(real * slopeIn)
  {slope = slopeIn;}
pocketBottomCondition * pocket::get_bottomCondition()
  {return bottomCondition;}
void pocket::set_bottomCondition(pocketBottomCondition * bottomConditionIn)
  {bottomCondition = bottomConditionIn;}
tolerancedLengthMeasure * pocket::get_planarRadius()
  {return planarRadius;}
void pocket::set_planarRadius(tolerancedLengthMeasure * planarRadiusIn)
  {planarRadius = planarRadiusIn;}
tolerancedLengthMeasure * pocket::get_orthogonalRadius()
  {return orthogonalRadius;}
void pocket::set_orthogonalRadius(tolerancedLengthMeasure * orthogonalRadiusIn)
  {orthogonalRadius = orthogonalRadiusIn;}

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

linearPath * profileFeature::get_profileSweptShape()
  {return profileSweptShape;}
void profileFeature::set_profileSweptShape(linearPath * profileSweptShapeIn)
  {profileSweptShape = profileSweptShapeIn;}

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

real * profileFloor::get_floorRadius()
  {return floorRadius;}
void profileFloor::set_floorRadius(real * floorRadiusIn)
  {floorRadius = floorRadiusIn;}
boolean * profileFloor::get_startOrEnd()
  {return startOrEnd;}
void profileFloor::set_startOrEnd(boolean * startOrEndIn)
  {startOrEnd = startOrEndIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_iId()->printSelf();
  printf(",");
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
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

double real::get_val()
  {return val;}
void real::set_val(double valIn)
  {val = valIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  profileWidth->get_iId()->printSelf();
  printf(",");
  profileLength->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * rectangularClosedProfile::get_profileWidth()
  {return profileWidth;}
void rectangularClosedProfile::set_profileWidth(tolerancedLengthMeasure * profileWidthIn)
  {profileWidth = profileWidthIn;}
tolerancedLengthMeasure * rectangularClosedProfile::get_profileLength()
  {return profileLength;}
void rectangularClosedProfile::set_profileLength(tolerancedLengthMeasure * profileLengthIn)
  {profileLength = profileLengthIn;}

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

two5DmanufacturingFeature * replicateFeature::get_replicateBaseFeature()
  {return replicateBaseFeature;}
void replicateFeature::set_replicateBaseFeature(two5DmanufacturingFeature * replicateBaseFeatureIn)
  {replicateBaseFeature = replicateBaseFeatureIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  position->get_iId()->printSelf();
  printf(",");
  printDouble(height);
  printf(",");
  printDouble(radius);
  printf(")");
}

axis1placement * rightCircularCylinder::get_position()
  {return position;}
void rightCircularCylinder::set_position(axis1placement * positionIn)
  {position = positionIn;}
double rightCircularCylinder::get_height()
  {return height;}
void rightCircularCylinder::set_height(double heightIn)
  {height = heightIn;}
double rightCircularCylinder::get_radius()
  {return radius;}
void rightCircularCylinder::set_radius(double radiusIn)
  {radius = radiusIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  courseOfTravel->get_iId()->printSelf();
  printf(",");
  partialCircularBoundary->get_iId()->printSelf();
  printf(")");
}

linearPath * roundedEnd::get_courseOfTravel()
  {return courseOfTravel;}
void roundedEnd::set_courseOfTravel(linearPath * courseOfTravelIn)
  {courseOfTravel = courseOfTravelIn;}
partialCircularProfile * roundedEnd::get_partialCircularBoundary()
  {return partialCircularBoundary;}
void roundedEnd::set_partialCircularBoundary(partialCircularProfile * partialCircularBoundaryIn)
  {partialCircularBoundary = partialCircularBoundaryIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  width->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * roundedUProfile::get_width()
  {return width;}
void roundedUProfile::set_width(tolerancedLengthMeasure * widthIn)
  {width = widthIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  diameter->get_iId()->printSelf();
  printf(",");
  if (changeInDiameter)
    (dynamic_cast<instance *>(changeInDiameter))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(bottomCondition))->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * roundHole::get_diameter()
  {return diameter;}
void roundHole::set_diameter(tolerancedLengthMeasure * diameterIn)
  {diameter = diameterIn;}
taperSelect * roundHole::get_changeInDiameter()
  {return changeInDiameter;}
void roundHole::set_changeInDiameter(taperSelect * changeInDiameterIn)
  {changeInDiameter = changeInDiameterIn;}
holeBottomCondition * roundHole::get_bottomCondition()
  {return bottomCondition;}
void roundHole::set_bottomCondition(holeBottomCondition * bottomConditionIn)
  {bottomCondition = bottomConditionIn;}

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

profileSelect * shapeProfile::get_floorCondition()
  {return floorCondition;}
void shapeProfile::set_floorCondition(profileSelect * floorConditionIn)
  {floorCondition = floorConditionIn;}
direction * shapeProfile::get_removalDirection()
  {return removalDirection;}
void shapeProfile::set_removalDirection(direction * removalDirectionIn)
  {removalDirection = removalDirectionIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete endConditions;
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(courseOfTravel))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(sweptShape))->get_iId()->printSelf();
  printf(",");
  endConditions->printSelf();
  printf(")");
}

travelPath * slot::get_courseOfTravel()
  {return courseOfTravel;}
void slot::set_courseOfTravel(travelPath * courseOfTravelIn)
  {courseOfTravel = courseOfTravelIn;}
openProfile * slot::get_sweptShape()
  {return sweptShape;}
void slot::set_sweptShape(openProfile * sweptShapeIn)
  {sweptShape = sweptShapeIn;}
parenSlotEndTypeList * slot::get_endConditions()
  {return endConditions;}
void slot::set_endConditions(parenSlotEndTypeList * endConditionsIn)
  {endConditions = endConditionsIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  internalAngle->get_iId()->printSelf();
  printf(",");
  radius->get_iId()->printSelf();
  printf(")");
}

numericParameter * sphericalCap::get_internalAngle()
  {return internalAngle;}
void sphericalCap::set_internalAngle(numericParameter * internalAngleIn)
  {internalAngle = internalAngleIn;}
numericParameter * sphericalCap::get_radius()
  {return radius;}
void sphericalCap::set_radius(numericParameter * radiusIn)
  {radius = radiusIn;}

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
  radius->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * sphericalHoleBottom::get_radius()
  {return radius;}
void sphericalHoleBottom::set_radius(tolerancedLengthMeasure * radiusIn)
  {radius = radiusIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  width->get_iId()->printSelf();
  printf(",");
  firstRadius->get_iId()->printSelf();
  printf(",");
  printDouble(firstAngle);
  printf(",");
  secondRadius->get_iId()->printSelf();
  printf(",");
  printDouble(secondAngle);
  printf(")");
}

tolerancedLengthMeasure * squareUProfile::get_width()
  {return width;}
void squareUProfile::set_width(tolerancedLengthMeasure * widthIn)
  {width = widthIn;}
tolerancedLengthMeasure * squareUProfile::get_firstRadius()
  {return firstRadius;}
void squareUProfile::set_firstRadius(tolerancedLengthMeasure * firstRadiusIn)
  {firstRadius = firstRadiusIn;}
double squareUProfile::get_firstAngle()
  {return firstAngle;}
void squareUProfile::set_firstAngle(double firstAngleIn)
  {firstAngle = firstAngleIn;}
tolerancedLengthMeasure * squareUProfile::get_secondRadius()
  {return secondRadius;}
void squareUProfile::set_secondRadius(tolerancedLengthMeasure * secondRadiusIn)
  {secondRadius = secondRadiusIn;}
double squareUProfile::get_secondAngle()
  {return secondAngle;}
void squareUProfile::set_secondAngle(double secondAngleIn)
  {secondAngle = secondAngleIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete itsBoss;
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  openBoundary->get_iId()->printSelf();
  printf(",");
  if (wallBoundary)
    wallBoundary->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  itsBoss->printSelf();
  printf(")");
}

linearPath * step::get_openBoundary()
  {return openBoundary;}
void step::set_openBoundary(linearPath * openBoundaryIn)
  {openBoundary = openBoundaryIn;}
veeProfile * step::get_wallBoundary()
  {return wallBoundary;}
void step::set_wallBoundary(veeProfile * wallBoundaryIn)
  {wallBoundary = wallBoundaryIn;}
parenBossList * step::get_itsBoss()
  {return itsBoss;}
void step::set_itsBoss(parenBossList * itsBossIn)
  {itsBoss = itsBossIn;}

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

curve * sweptSurface::get_sweptCurve()
  {return sweptCurve;}
void sweptSurface::set_sweptCurve(curve * sweptCurveIn)
  {sweptCurve = sweptCurveIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete taperAngle;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

real * taperedReamer::get_taperAngle()
  {return taperAngle;}
void taperedReamer::set_taperAngle(real * taperAngleIn)
  {taperAngle = taperAngleIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printDouble(firstAngle);
  printDouble(secondAngle);
  crossBarWidth->get_iId()->printSelf();
  crossBarDepth->get_iId()->printSelf();
  radius->get_iId()->printSelf();
  width->get_iId()->printSelf();
  firstOffset->get_iId()->printSelf();
  secondOffset->get_iId()->printSelf();
  printf(")");
}

double teeProfile::get_firstAngle()
  {return firstAngle;}
void teeProfile::set_firstAngle(double firstAngleIn)
  {firstAngle = firstAngleIn;}
double teeProfile::get_secondAngle()
  {return secondAngle;}
void teeProfile::set_secondAngle(double secondAngleIn)
  {secondAngle = secondAngleIn;}
tolerancedLengthMeasure * teeProfile::get_crossBarWidth()
  {return crossBarWidth;}
void teeProfile::set_crossBarWidth(tolerancedLengthMeasure * crossBarWidthIn)
  {crossBarWidth = crossBarWidthIn;}
tolerancedLengthMeasure * teeProfile::get_crossBarDepth()
  {return crossBarDepth;}
void teeProfile::set_crossBarDepth(tolerancedLengthMeasure * crossBarDepthIn)
  {crossBarDepth = crossBarDepthIn;}
tolerancedLengthMeasure * teeProfile::get_radius()
  {return radius;}
void teeProfile::set_radius(tolerancedLengthMeasure * radiusIn)
  {radius = radiusIn;}
tolerancedLengthMeasure * teeProfile::get_width()
  {return width;}
void teeProfile::set_width(tolerancedLengthMeasure * widthIn)
  {width = widthIn;}
tolerancedLengthMeasure * teeProfile::get_firstOffset()
  {return firstOffset;}
void teeProfile::set_firstOffset(tolerancedLengthMeasure * firstOffsetIn)
  {firstOffset = firstOffsetIn;}
tolerancedLengthMeasure * teeProfile::get_secondOffset()
  {return secondOffset;}
void teeProfile::set_secondOffset(tolerancedLengthMeasure * secondOffsetIn)
  {secondOffset = secondOffsetIn;}

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

partialAreaDefinition * thread::get_partialProfile()
  {return partialProfile;}
void thread::set_partialProfile(partialAreaDefinition * partialProfileIn)
  {partialProfile = partialProfileIn;}
parenMachiningFeatureListFull * thread::get_appliedShape()
  {return appliedShape;}
void thread::set_appliedShape(parenMachiningFeatureListFull * appliedShapeIn)
  {appliedShape = appliedShapeIn;}
boolean * thread::get_innerOrOuterThread()
  {return innerOrOuterThread;}
void thread::set_innerOrOuterThread(boolean * innerOrOuterThreadIn)
  {innerOrOuterThread = innerOrOuterThreadIn;}
descriptiveParameter * thread::get_qualifier()
  {return qualifier;}
void thread::set_qualifier(descriptiveParameter * qualifierIn)
  {qualifier = qualifierIn;}
descriptiveParameter * thread::get_fitClass()
  {return fitClass;}
void thread::set_fitClass(descriptiveParameter * fitClassIn)
  {fitClass = fitClassIn;}
descriptiveParameter * thread::get_form()
  {return form;}
void thread::set_form(descriptiveParameter * formIn)
  {form = formIn;}
double thread::get_majorDiameter()
  {return majorDiameter;}
void thread::set_majorDiameter(double majorDiameterIn)
  {majorDiameter = majorDiameterIn;}
numericParameter * thread::get_numberOfThreads()
  {return numberOfThreads;}
void thread::set_numberOfThreads(numericParameter * numberOfThreadsIn)
  {numberOfThreads = numberOfThreadsIn;}
descriptiveParameter * thread::get_threadHand()
  {return threadHand;}
void thread::set_threadHand(descriptiveParameter * threadHandIn)
  {threadHand = threadHandIn;}

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
  itsToolDirection->get_iId()->printSelf();
  printf(")");
}

direction * threeAxesTiltedTool::get_itsToolDirection()
  {return itsToolDirection;}
void threeAxesTiltedTool::set_itsToolDirection(direction * itsToolDirectionIn)
  {itsToolDirection = itsToolDirectionIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
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
  (dynamic_cast<instance *>(speed))->get_iId()->printSelf();
  printf(")");
}

bSplineCurve * toolpathSpeed::get_speed()
  {return speed;}
void toolpathSpeed::set_speed(bSplineCurve * speedIn)
  {speed = speedIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete[] get_name();
  //delete get_cfsFaces();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  if (get_featurePlacement())
    get_featurePlacement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_name());
  printf(",");
  get_cfsFaces()->printSelf();
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

ncVariable * touchProbing::get_measuredOffset()
  {return measuredOffset;}
void touchProbing::set_measuredOffset(ncVariable * measuredOffsetIn)
  {measuredOffset = measuredOffsetIn;}

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

two5DmillingStrategy * two5DmillingOperation::get_itsMachiningStrategy()
  {return itsMachiningStrategy;}
void two5DmillingOperation::set_itsMachiningStrategy(two5DmillingStrategy * itsMachiningStrategyIn)
  {itsMachiningStrategy = itsMachiningStrategyIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete identifier;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  printString(identifier);
  printf(")");
}

char * userDefinedTool::get_identifier()
  {return identifier;}
void userDefinedTool::set_identifier(char * identifierIn)
  {identifier = identifierIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  orientation->get_iId()->printSelf();
  printf(",");
  printDouble(magnitude);
  printf(")");
}

direction * vector::get_orientation()
  {return orientation;}
void vector::set_orientation(direction * orientationIn)
  {orientation = orientationIn;}
double vector::get_magnitude()
  {return magnitude;}
void vector::set_magnitude(double magnitudeIn)
  {magnitude = magnitudeIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  profileRadius->get_iId()->printSelf();
  printf(",");
  printDouble(profileAngle);
  printf(",");
  printDouble(tiltAngle);
  printf(")");
}

tolerancedLengthMeasure * veeProfile::get_profileRadius()
  {return profileRadius;}
void veeProfile::set_profileRadius(tolerancedLengthMeasure * profileRadiusIn)
  {profileRadius = profileRadiusIn;}
double veeProfile::get_profileAngle()
  {return profileAngle;}
void veeProfile::set_profileAngle(double profileAngleIn)
  {profileAngle = profileAngleIn;}
double veeProfile::get_tiltAngle()
  {return tiltAngle;}
void veeProfile::set_tiltAngle(double tiltAngleIn)
  {tiltAngle = tiltAngleIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(loopVertex))->get_iId()->printSelf();
  printf(")");
}

vertex * vertexLoop::get_loopVertex()
  {return loopVertex;}
void vertexLoop::set_loopVertex(vertex * loopVertexIn)
  {loopVertex = loopVertexIn;}

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
  //delete[] get_itsId();
  //delete computedOffset;
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_iId()->printSelf();
  printf(",");
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_measuredOffset()->get_iId()->printSelf();
  printf(",");
  itsWorkpiece->get_iId()->printSelf();
  printf(",");
  probingDistance->get_iId()->printSelf();
  printf(",");
  itsProbe->get_iId()->printSelf();
  printf(",");
  computedOffset->printSelf();
  printf(")");
}

workpiece * workpieceCompleteProbing::get_itsWorkpiece()
  {return itsWorkpiece;}
void workpieceCompleteProbing::set_itsWorkpiece(workpiece * itsWorkpieceIn)
  {itsWorkpiece = itsWorkpieceIn;}
tolerancedLengthMeasure * workpieceCompleteProbing::get_probingDistance()
  {return probingDistance;}
void workpieceCompleteProbing::set_probingDistance(tolerancedLengthMeasure * probingDistanceIn)
  {probingDistance = probingDistanceIn;}
touchProbe * workpieceCompleteProbing::get_itsProbe()
  {return itsProbe;}
void workpieceCompleteProbing::set_itsProbe(touchProbe * itsProbeIn)
  {itsProbe = itsProbeIn;}
offsetVector * workpieceCompleteProbing::get_computedOffset()
  {return computedOffset;}
void workpieceCompleteProbing::set_computedOffset(offsetVector * computedOffsetIn)
  {computedOffset = computedOffsetIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_iId()->printSelf();
  printf(",");
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_measuredOffset()->get_iId()->printSelf();
  printf(",");
  startPosition->get_iId()->printSelf();
  printf(",");
  itsWorkpiece->get_iId()->printSelf();
  printf(",");
  itsDirection->get_iId()->printSelf();
  printf(",");
  expectedValue->get_iId()->printSelf();
  printf(",");
  itsProbe->get_iId()->printSelf();
  printf(")");
}

axis2placement3d * workpieceProbing::get_startPosition()
  {return startPosition;}
void workpieceProbing::set_startPosition(axis2placement3d * startPositionIn)
  {startPosition = startPositionIn;}
workpiece * workpieceProbing::get_itsWorkpiece()
  {return itsWorkpiece;}
void workpieceProbing::set_itsWorkpiece(workpiece * itsWorkpieceIn)
  {itsWorkpiece = itsWorkpieceIn;}
direction * workpieceProbing::get_itsDirection()
  {return itsDirection;}
void workpieceProbing::set_itsDirection(direction * itsDirectionIn)
  {itsDirection = itsDirectionIn;}
tolerancedLengthMeasure * workpieceProbing::get_expectedValue()
  {return expectedValue;}
void workpieceProbing::set_expectedValue(tolerancedLengthMeasure * expectedValueIn)
  {expectedValue = expectedValueIn;}
touchProbe * workpieceProbing::get_itsProbe()
  {return itsProbe;}
void workpieceProbing::set_itsProbe(touchProbe * itsProbeIn)
  {itsProbe = itsProbeIn;}

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
  (dynamic_cast<instance *>(get_operand1()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_operand2()))->get_iId()->printSelf();
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
  //delete[] get_name();
  //delete get_items();
  //delete get_contextOfItems();
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
  printString(get_name());
  printf(",");
  get_items()->printSelf();
  printf(",");
  get_contextOfItems()->printSelf();
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
  //delete[] get_name();
  //delete get_bounds();
  //delete get_sameSense();
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
  printString(get_name());
  printf(",");
  get_bounds()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_faceGeometry()))->get_iId()->printSelf();
  printf(",");
  get_sameSense()->printSelf();
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

cartesianPoint * approachLiftPath::get_fixPoint()
  {return fixPoint;}
void approachLiftPath::set_fixPoint(cartesianPoint * fixPointIn)
  {fixPoint = fixPointIn;}
direction * approachLiftPath::get_fixPointDir()
  {return fixPointDir;}
void approachLiftPath::set_fixPointDir(direction * fixPointDirIn)
  {fixPointDir = fixPointDirIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  get_location()->get_iId()->printSelf();
  printf(",");
  axis->get_iId()->printSelf();
  printf(")");
}

direction * axis1placement::get_axis()
  {return axis;}
void axis1placement::set_axis(direction * axisIn)
  {axis = axisIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  get_location()->get_iId()->printSelf();
  printf(",");
  axis->get_iId()->printSelf();
  printf(",");
  if (refDirection)
    refDirection->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

direction * axis2placement3d::get_axis()
  {return axis;}
void axis2placement3d::set_axis(direction * axisIn)
  {axis = axisIn;}
direction * axis2placement3d::get_refDirection()
  {return refDirection;}
void axis2placement3d::set_refDirection(direction * refDirectionIn)
  {refDirection = refDirectionIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  position->get_iId()->printSelf();
  printf(",");
  printDouble(x);
  printf(",");
  printDouble(y);
  printf(",");
  printDouble(z);
  printf(")");
}

axis2placement3d * block::get_position()
  {return position;}
void block::set_position(axis2placement3d * positionIn)
  {position = positionIn;}
double block::get_x()
  {return x;}
void block::set_x(double xIn)
  {x = xIn;}
double block::get_y()
  {return y;}
void block::set_y(double yIn)
  {y = yIn;}
double block::get_z()
  {return z;}
void block::set_z(double zIn)
  {z = zIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete slope;
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(itsBoundary))->get_iId()->printSelf();
  printf(",");
  if (slope)
    slope->printSelf();
  else
    printf("$");
  printf(")");
}

closedProfile * boss::get_itsBoundary()
  {return itsBoundary;}
void boss::set_itsBoundary(closedProfile * itsBoundaryIn)
  {itsBoundary = itsBoundaryIn;}
real * boss::get_slope()
  {return slope;}
void boss::set_slope(real * slopeIn)
  {slope = slopeIn;}

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

real * bottomAndSideMilling::get_axialCuttingDepth()
  {return axialCuttingDepth;}
void bottomAndSideMilling::set_axialCuttingDepth(real * axialCuttingDepthIn)
  {axialCuttingDepth = axialCuttingDepthIn;}
real * bottomAndSideMilling::get_radialCuttingDepth()
  {return radialCuttingDepth;}
void bottomAndSideMilling::set_radialCuttingDepth(real * radialCuttingDepthIn)
  {radialCuttingDepth = radialCuttingDepthIn;}
real * bottomAndSideMilling::get_allowanceSide()
  {return allowanceSide;}
void bottomAndSideMilling::set_allowanceSide(real * allowanceSideIn)
  {allowanceSide = allowanceSideIn;}
real * bottomAndSideMilling::get_allowanceBottom()
  {return allowanceBottom;}
void bottomAndSideMilling::set_allowanceBottom(real * allowanceBottomIn)
  {allowanceBottom = allowanceBottomIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_axialCuttingDepth();
  //delete get_radialCuttingDepth();
  //delete get_allowanceSide();
  //delete get_allowanceBottom();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_radialCuttingDepth())
    get_radialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceSide())
    get_allowanceSide()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceBottom())
    get_allowanceBottom()->printSelf();
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

integer * bSplineSurface::get_uDegree()
  {return uDegree;}
void bSplineSurface::set_uDegree(integer * uDegreeIn)
  {uDegree = uDegreeIn;}
integer * bSplineSurface::get_vDegree()
  {return vDegree;}
void bSplineSurface::set_vDegree(integer * vDegreeIn)
  {vDegree = vDegreeIn;}
parenParenCartesianPointListFullListFull * bSplineSurface::get_controlPointsList()
  {return controlPointsList;}
void bSplineSurface::set_controlPointsList(parenParenCartesianPointListFullListFull * controlPointsListIn)
  {controlPointsList = controlPointsListIn;}
bSplineSurfaceForm * bSplineSurface::get_surfaceForm()
  {return surfaceForm;}
void bSplineSurface::set_surfaceForm(bSplineSurfaceForm * surfaceFormIn)
  {surfaceForm = surfaceFormIn;}
logical * bSplineSurface::get_uClosed()
  {return uClosed;}
void bSplineSurface::set_uClosed(logical * uClosedIn)
  {uClosed = uClosedIn;}
logical * bSplineSurface::get_vClosed()
  {return vClosed;}
void bSplineSurface::set_vClosed(logical * vClosedIn)
  {vClosed = vClosedIn;}
logical * bSplineSurface::get_selfIntersect()
  {return selfIntersect;}
void bSplineSurface::set_selfIntersect(logical * selfIntersectIn)
  {selfIntersect = selfIntersectIn;}

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
  //delete[] get_name();
  //delete get_uDegree();
  //delete get_vDegree();
  //delete get_controlPointsList();
  //delete get_surfaceForm();
  //delete get_uClosed();
  //delete get_vClosed();
  //delete get_selfIntersect();
  //delete uMultiplicities;
  //delete vMultiplicities;
  //delete uKnots;
  //delete vKnots;
  //delete knotSpec;
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
  printString(get_name());
  printf(",");
  get_uDegree()->printSelf();
  printf(",");
  get_vDegree()->printSelf();
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_surfaceForm()->printSelf();
  printf(",");
  get_uClosed()->printSelf();
  printf(",");
  get_vClosed()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
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

parenIntegerListFull * bSplineSurfaceWithKnots::get_uMultiplicities()
  {return uMultiplicities;}
void bSplineSurfaceWithKnots::set_uMultiplicities(parenIntegerListFull * uMultiplicitiesIn)
  {uMultiplicities = uMultiplicitiesIn;}
parenIntegerListFull * bSplineSurfaceWithKnots::get_vMultiplicities()
  {return vMultiplicities;}
void bSplineSurfaceWithKnots::set_vMultiplicities(parenIntegerListFull * vMultiplicitiesIn)
  {vMultiplicities = vMultiplicitiesIn;}
parenRealListFull * bSplineSurfaceWithKnots::get_uKnots()
  {return uKnots;}
void bSplineSurfaceWithKnots::set_uKnots(parenRealListFull * uKnotsIn)
  {uKnots = uKnotsIn;}
parenRealListFull * bSplineSurfaceWithKnots::get_vKnots()
  {return vKnots;}
void bSplineSurfaceWithKnots::set_vKnots(parenRealListFull * vKnotsIn)
  {vKnots = vKnotsIn;}
knotType * bSplineSurfaceWithKnots::get_knotSpec()
  {return knotSpec;}
void bSplineSurfaceWithKnots::set_knotSpec(knotType * knotSpecIn)
  {knotSpec = knotSpecIn;}

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
  //delete[] get_name();
  //delete coordinates;
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
  printString(get_name());
  printf(",");
  coordinates->printSelf();
  printf(")");
}

parenRealListFull * cartesianPoint::get_coordinates()
  {return coordinates;}
void cartesianPoint::set_coordinates(parenRealListFull * coordinatesIn)
  {coordinates = coordinatesIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete get_appliedShape();
  //delete get_innerOrOuterThread();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_partialProfile()->get_iId()->printSelf();
  printf(",");
  get_appliedShape()->printSelf();
  printf(",");
  get_innerOrOuterThread()->printSelf();
  printf(",");
  if (get_qualifier())
    get_qualifier()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_fitClass()->get_iId()->printSelf();
  printf(",");
  get_form()->get_iId()->printSelf();
  printf(",");
  printDouble(get_majorDiameter());
  printf(",");
  get_numberOfThreads()->get_iId()->printSelf();
  printf(",");
  get_threadHand()->get_iId()->printSelf();
  printf(",");
  documentation->get_iId()->printSelf();
  printf(")");
}

specification * catalogueThread::get_documentation()
  {return documentation;}
void catalogueThread::set_documentation(specification * documentationIn)
  {documentation = documentationIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  diameter->get_iId()->printSelf();
  printf(")");
}

tolerancedLengthMeasure * circularClosedProfile::get_diameter()
  {return diameter;}
void circularClosedProfile::set_diameter(tolerancedLengthMeasure * diameterIn)
  {diameter = diameterIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_profileSweptShape()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_floorCondition()))->get_iId()->printSelf();
  printf(",");
  get_removalDirection()->get_iId()->printSelf();
  printf(",");
  closedBoundary->get_iId()->printSelf();
  printf(")");
}

circularClosedProfile * circularClosedShapeProfile::get_closedBoundary()
  {return closedBoundary;}
void circularClosedShapeProfile::set_closedBoundary(circularClosedProfile * closedBoundaryIn)
  {closedBoundary = closedBoundaryIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete relocatedBaseFeature;
  //delete missingBaseFeature;
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_replicateBaseFeature()))->get_iId()->printSelf();
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
    baseFeatureDiameter->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(baseFeatureRotation);
  printf(")");
}

double circularPattern::get_angleIncrement()
  {return angleIncrement;}
void circularPattern::set_angleIncrement(double angleIncrementIn)
  {angleIncrement = angleIncrementIn;}
int circularPattern::get_numberOfFeature()
  {return numberOfFeature;}
void circularPattern::set_numberOfFeature(int numberOfFeatureIn)
  {numberOfFeature = numberOfFeatureIn;}
parenCircularOffsetList * circularPattern::get_relocatedBaseFeature()
  {return relocatedBaseFeature;}
void circularPattern::set_relocatedBaseFeature(parenCircularOffsetList * relocatedBaseFeatureIn)
  {relocatedBaseFeature = relocatedBaseFeatureIn;}
parenCircularOmitList * circularPattern::get_missingBaseFeature()
  {return missingBaseFeature;}
void circularPattern::set_missingBaseFeature(parenCircularOmitList * missingBaseFeatureIn)
  {missingBaseFeature = missingBaseFeatureIn;}
tolerancedLengthMeasure * circularPattern::get_baseFeatureDiameter()
  {return baseFeatureDiameter;}
void circularPattern::set_baseFeatureDiameter(tolerancedLengthMeasure * baseFeatureDiameterIn)
  {baseFeatureDiameter = baseFeatureDiameterIn;}
double circularPattern::get_baseFeatureRotation()
  {return baseFeatureRotation;}
void circularPattern::set_baseFeatureRotation(double baseFeatureRotationIn)
  {baseFeatureRotation = baseFeatureRotationIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete get_itsBoss();
  //delete get_slope();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_itsBoss()->printSelf();
  printf(",");
  if (get_slope())
    get_slope()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_bottomCondition()))->get_iId()->printSelf();
  printf(",");
  if (get_planarRadius())
    get_planarRadius()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_orthogonalRadius())
    get_orthogonalRadius()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(featureBoundary))->get_iId()->printSelf();
  printf(")");
}

closedProfile * closedPocket::get_featureBoundary()
  {return featureBoundary;}
void closedPocket::set_featureBoundary(closedProfile * featureBoundaryIn)
  {featureBoundary = featureBoundaryIn;}

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
  //delete[] get_name();
  //delete get_cfsFaces();
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
  printString(get_name());
  printf(",");
  get_cfsFaces()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete drillLength;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (drillLength)
    drillLength->printSelf();
  else
    printf("$");
  printf(")");
}

real * combinedDrillAndReamer::get_drillLength()
  {return drillLength;}
void combinedDrillAndReamer::set_drillLength(real * drillLengthIn)
  {drillLength = drillLengthIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete drillLength;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  if (drillLength)
    drillLength->printSelf();
  else
    printf("$");
  printf(")");
}

real * combinedDrillAndTap::get_drillLength()
  {return drillLength;}
void combinedDrillAndTap::set_drillLength(real * drillLengthIn)
  {drillLength = drillLengthIn;}

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
  //delete get_itsPriority();
  //delete get_itsType();
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
  get_itsPriority()->printSelf();
  printf(",");
  get_itsType()->printSelf();
  printf(",");
  if (get_itsSpeed())
    get_itsSpeed()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsTechnology())
    (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachineFunctions())
    (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (upDir)
    upDir->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (downDir)
    downDir->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

direction * connectSecplane::get_upDir()
  {return upDir;}
void connectSecplane::set_upDir(direction * upDirIn)
  {upDir = upDirIn;}
direction * connectSecplane::get_downDir()
  {return downDir;}
void connectSecplane::set_downDir(direction * downDirIn)
  {downDir = downDirIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete get_appliedShape();
  //delete get_innerOrOuterThread();
  //delete minorDiameter;
  //delete crest;
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_partialProfile()->get_iId()->printSelf();
  printf(",");
  get_appliedShape()->printSelf();
  printf(",");
  get_innerOrOuterThread()->printSelf();
  printf(",");
  if (get_qualifier())
    get_qualifier()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_fitClass()->get_iId()->printSelf();
  printf(",");
  get_form()->get_iId()->printSelf();
  printf(",");
  printDouble(get_majorDiameter());
  printf(",");
  get_numberOfThreads()->get_iId()->printSelf();
  printf(",");
  get_threadHand()->get_iId()->printSelf();
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

double definedThread::get_pitchDiameter()
  {return pitchDiameter;}
void definedThread::set_pitchDiameter(double pitchDiameterIn)
  {pitchDiameter = pitchDiameterIn;}
real * definedThread::get_minorDiameter()
  {return minorDiameter;}
void definedThread::set_minorDiameter(real * minorDiameterIn)
  {minorDiameter = minorDiameterIn;}
real * definedThread::get_crest()
  {return crest;}
void definedThread::set_crest(real * crestIn)
  {crest = crestIn;}

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
  //delete[] get_name();
  //delete directionRatios;
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
  printString(get_name());
  printf(",");
  directionRatios->printSelf();
  printf(")");
}

parenRealListFull * direction::get_directionRatios()
  {return directionRatios;}
void direction::set_directionRatios(parenRealListFull * directionRatiosIn)
  {directionRatios = directionRatiosIn;}

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

real * drillingTypeOperation::get_cuttingDepth()
  {return cuttingDepth;}
void drillingTypeOperation::set_cuttingDepth(real * cuttingDepthIn)
  {cuttingDepth = cuttingDepthIn;}
real * drillingTypeOperation::get_previousDiameter()
  {return previousDiameter;}
void drillingTypeOperation::set_previousDiameter(real * previousDiameterIn)
  {previousDiameter = previousDiameterIn;}
real * drillingTypeOperation::get_dwellTimeBottom()
  {return dwellTimeBottom;}
void drillingTypeOperation::set_dwellTimeBottom(real * dwellTimeBottomIn)
  {dwellTimeBottom = dwellTimeBottomIn;}
real * drillingTypeOperation::get_feedOnRetract()
  {return feedOnRetract;}
void drillingTypeOperation::set_feedOnRetract(real * feedOnRetractIn)
  {feedOnRetract = feedOnRetractIn;}
drillingTypeStrategy * drillingTypeOperation::get_itsMachiningStrategy()
  {return itsMachiningStrategy;}
void drillingTypeOperation::set_itsMachiningStrategy(drillingTypeStrategy * itsMachiningStrategyIn)
  {itsMachiningStrategy = itsMachiningStrategyIn;}

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
  //delete[] get_name();
  //delete edgeList;
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
  printString(get_name());
  printf(",");
  edgeList->printSelf();
  printf(")");
}

parenOrientedEdgeListFull * edgeLoop::get_edgeList()
  {return edgeList;}
void edgeLoop::set_edgeList(parenOrientedEdgeListFull * edgeListIn)
  {edgeList = edgeListIn;}

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

axis2placement3d * elementarySurface::get_position()
  {return position;}
void elementarySurface::set_position(axis2placement3d * positionIn)
  {position = positionIn;}

void elementarySurface::printSelf(){

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (itsMachiningStrategy)
    (dynamic_cast<instance *>(itsMachiningStrategy))->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

freeformStrategy * freeformOperation::get_itsMachiningStrategy()
  {return itsMachiningStrategy;}
void freeformOperation::set_itsMachiningStrategy(freeformStrategy * itsMachiningStrategyIn)
  {itsMachiningStrategy = itsMachiningStrategyIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_profileSweptShape()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(featureBoundary))->get_iId()->printSelf();
  printf(")");
}

profile * generalOutsideProfile::get_featureBoundary()
  {return featureBoundary;}
void generalOutsideProfile::set_featureBoundary(profile * featureBoundaryIn)
  {featureBoundary = featureBoundaryIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete replicateLocations;
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_replicateBaseFeature()))->get_iId()->printSelf();
  printf(",");
  replicateLocations->printSelf();
  printf(")");
}

parenAxis2placement3dListFull * generalPattern::get_replicateLocations()
  {return replicateLocations;}
void generalPattern::set_replicateLocations(parenAxis2placement3dListFull * replicateLocationsIn)
  {replicateLocations = replicateLocationsIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(itsProfile))->get_iId()->printSelf();
  printf(")");
}

boundedCurve * generalProfile::get_itsProfile()
  {return itsProfile;}
void generalProfile::set_itsProfile(boundedCurve * itsProfileIn)
  {itsProfile = itsProfileIn;}

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
  //delete get_floorRadius();
  //delete get_startOrEnd();
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
  if (get_floorRadius())
    get_floorRadius()->printSelf();
  else
    printf("$");
  printf(",");
  get_startOrEnd()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(floor))->get_iId()->printSelf();
  printf(")");
}

face * generalProfileFloor::get_floor()
  {return floor;}
void generalProfileFloor::set_floor(face * floorIn)
  {floor = floorIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_profileSweptShape()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_floorCondition()))->get_iId()->printSelf();
  printf(",");
  get_removalDirection()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(profileBoundary))->get_iId()->printSelf();
  printf(")");
}

profile * generalShapeProfile::get_profileBoundary()
  {return profileBoundary;}
void generalShapeProfile::set_profileBoundary(profile * profileBoundaryIn)
  {profileBoundary = profileBoundaryIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  position->get_iId()->printSelf();
  printf(",");
  printDouble(radius);
  printf(",");
  printDouble(pitch);
  printf(")");
}

axis2placement3d * helix::get_position()
  {return position;}
void helix::set_position(axis2placement3d * positionIn)
  {position = positionIn;}
double helix::get_radius()
  {return radius;}
void helix::set_radius(double radiusIn)
  {radius = radiusIn;}
double helix::get_pitch()
  {return pitch;}
void helix::set_pitch(double pitchIn)
  {pitch = pitchIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  pnt->get_iId()->printSelf();
  printf(",");
  dir->get_iId()->printSelf();
  printf(")");
}

cartesianPoint * line::get_pnt()
  {return pnt;}
void line::set_pnt(cartesianPoint * pntIn)
  {pnt = pntIn;}
vector * line::get_dir()
  {return dir;}
void line::set_dir(vector * dirIn)
  {dir = dirIn;}

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
  if (get_placement())
    get_placement()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  profileLength->get_iId()->printSelf();
  printf(")");
}

numericParameter * linearProfile::get_profileLength()
  {return profileLength;}
void linearProfile::set_profileLength(numericParameter * profileLengthIn)
  {profileLength = profileLengthIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  outer->get_iId()->printSelf();
  printf(")");
}

closedShell * manifoldSolidBrep::get_outer()
  {return outer;}
void manifoldSolidBrep::set_outer(closedShell * outerIn)
  {outer = outerIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete get_itsBoss();
  //delete get_slope();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_itsBoss()->printSelf();
  printf(",");
  if (get_slope())
    get_slope()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_bottomCondition()))->get_iId()->printSelf();
  printf(",");
  if (get_planarRadius())
    get_planarRadius()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_orthogonalRadius())
    get_orthogonalRadius()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(openBoundary))->get_iId()->printSelf();
  printf(",");
  if (wallBoundary)
    (dynamic_cast<instance *>(wallBoundary))->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

openProfile * openPocket::get_openBoundary()
  {return openBoundary;}
void openPocket::set_openBoundary(openProfile * openBoundaryIn)
  {openBoundary = openBoundaryIn;}
openProfile * openPocket::get_wallBoundary()
  {return wallBoundary;}
void openPocket::set_wallBoundary(openProfile * wallBoundaryIn)
  {wallBoundary = wallBoundaryIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_profileSweptShape()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_floorCondition()))->get_iId()->printSelf();
  printf(",");
  get_removalDirection()->get_iId()->printSelf();
  printf(",");
  openBoundary->get_iId()->printSelf();
  printf(")");
}

partialCircularProfile * partialCircularShapeProfile::get_openBoundary()
  {return openBoundary;}
void partialCircularShapeProfile::set_openBoundary(partialCircularProfile * openBoundaryIn)
  {openBoundary = openBoundaryIn;}

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

surface * pcurveParent::get_basisSurface()
  {return basisSurface;}
void pcurveParent::set_basisSurface(surface * basisSurfaceIn)
  {basisSurface = basisSurfaceIn;}
definitionalRepresentation * pcurveParent::get_referenceToCurve()
  {return referenceToCurve;}
void pcurveParent::set_referenceToCurve(definitionalRepresentation * referenceToCurveIn)
  {referenceToCurve = referenceToCurveIn;}

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
  //delete get_floorRadius();
  //delete get_startOrEnd();
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
  if (get_floorRadius())
    get_floorRadius()->printSelf();
  else
    printf("$");
  printf(",");
  get_startOrEnd()->printSelf();
  printf(",");
  floor->get_iId()->printSelf();
  printf(")");
}

plane * planarProfileFloor::get_floor()
  {return floor;}
void planarProfileFloor::set_floor(plane * floorIn)
  {floor = floorIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  get_position()->get_iId()->printSelf();
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

real * planeMilling::get_axialCuttingDepth()
  {return axialCuttingDepth;}
void planeMilling::set_axialCuttingDepth(real * axialCuttingDepthIn)
  {axialCuttingDepth = axialCuttingDepthIn;}
real * planeMilling::get_allowanceBottom()
  {return allowanceBottom;}
void planeMilling::set_allowanceBottom(real * allowanceBottomIn)
  {allowanceBottom = allowanceBottomIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_axialCuttingDepth();
  //delete get_allowanceBottom();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceBottom())
    get_allowanceBottom()->printSelf();
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
  //delete[] get_name();
  //delete get_uDegree();
  //delete get_vDegree();
  //delete get_controlPointsList();
  //delete get_surfaceForm();
  //delete get_uClosed();
  //delete get_vClosed();
  //delete get_selfIntersect();
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
  printString(get_name());
  printf(",");
  get_uDegree()->printSelf();
  printf(",");
  get_vDegree()->printSelf();
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_surfaceForm()->printSelf();
  printf(",");
  get_uClosed()->printSelf();
  printf(",");
  get_vClosed()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
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
  //delete[] get_name();
  //delete get_uDegree();
  //delete get_vDegree();
  //delete get_controlPointsList();
  //delete get_surfaceForm();
  //delete get_uClosed();
  //delete get_vClosed();
  //delete get_selfIntersect();
  //delete weightsData;
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
  printString(get_name());
  printf(",");
  get_uDegree()->printSelf();
  printf(",");
  get_vDegree()->printSelf();
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_surfaceForm()->printSelf();
  printf(",");
  get_uClosed()->printSelf();
  printf(",");
  get_vClosed()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
  weightsData->printSelf();
  printf(")");
}

parenParenRealListFullListFull * rationalBSplineSurface::get_weightsData()
  {return weightsData;}
void rationalBSplineSurface::set_weightsData(parenParenRealListFullListFull * weightsDataIn)
  {weightsData = weightsDataIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_profileSweptShape()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_floorCondition()))->get_iId()->printSelf();
  printf(",");
  get_removalDirection()->get_iId()->printSelf();
  printf(",");
  closedBoundary->get_iId()->printSelf();
  printf(")");
}

rectangularClosedProfile * rectangularClosedShapeProfile::get_closedBoundary()
  {return closedBoundary;}
void rectangularClosedShapeProfile::set_closedBoundary(rectangularClosedProfile * closedBoundaryIn)
  {closedBoundary = closedBoundaryIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_depth()))->get_iId()->printSelf();
  printf(",");
  get_profileSweptShape()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_floorCondition()))->get_iId()->printSelf();
  printf(",");
  get_removalDirection()->get_iId()->printSelf();
  printf(",");
  openBoundary->get_iId()->printSelf();
  printf(")");
}

squareUProfile * rectangularOpenShapeProfile::get_openBoundary()
  {return openBoundary;}
void rectangularOpenShapeProfile::set_openBoundary(squareUProfile * openBoundaryIn)
  {openBoundary = openBoundaryIn;}

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
  //delete[] get_itsId();
  //delete get_itsOperations();
  //delete numberOfRows;
  //delete relocatedBaseFeature;
  //delete missingBaseFeature;
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
  printString(get_itsId());
  printf(",");
  get_itsWorkpiece()->get_iId()->printSelf();
  printf(",");
  get_itsOperations()->printSelf();
  printf(",");
  get_featurePlacement()->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_replicateBaseFeature()))->get_iId()->printSelf();
  spacing->get_iId()->printSelf();
  printf(",");
  itsDirection->get_iId()->printSelf();
  printf(",");
  if (numberOfRows)
    numberOfRows->printSelf();
  else
    printf("$");
  printf(",");
  printf("%d", numberOfColumns);
  printf(",");
  if (rowSpacing)
    rowSpacing->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (rowLayoutDirection)
    rowLayoutDirection->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  relocatedBaseFeature->printSelf();
  printf(",");
  missingBaseFeature->printSelf();
  printf(")");
}

tolerancedLengthMeasure * rectangularPattern::get_spacing()
  {return spacing;}
void rectangularPattern::set_spacing(tolerancedLengthMeasure * spacingIn)
  {spacing = spacingIn;}
direction * rectangularPattern::get_itsDirection()
  {return itsDirection;}
void rectangularPattern::set_itsDirection(direction * itsDirectionIn)
  {itsDirection = itsDirectionIn;}
integer * rectangularPattern::get_numberOfRows()
  {return numberOfRows;}
void rectangularPattern::set_numberOfRows(integer * numberOfRowsIn)
  {numberOfRows = numberOfRowsIn;}
int rectangularPattern::get_numberOfColumns()
  {return numberOfColumns;}
void rectangularPattern::set_numberOfColumns(int numberOfColumnsIn)
  {numberOfColumns = numberOfColumnsIn;}
tolerancedLengthMeasure * rectangularPattern::get_rowSpacing()
  {return rowSpacing;}
void rectangularPattern::set_rowSpacing(tolerancedLengthMeasure * rowSpacingIn)
  {rowSpacing = rowSpacingIn;}
direction * rectangularPattern::get_rowLayoutDirection()
  {return rowLayoutDirection;}
void rectangularPattern::set_rowLayoutDirection(direction * rowLayoutDirectionIn)
  {rowLayoutDirection = rowLayoutDirectionIn;}
parenRectangularOffsetList * rectangularPattern::get_relocatedBaseFeature()
  {return relocatedBaseFeature;}
void rectangularPattern::set_relocatedBaseFeature(parenRectangularOffsetList * relocatedBaseFeatureIn)
  {relocatedBaseFeature = relocatedBaseFeatureIn;}
parenRectangularOmitList * rectangularPattern::get_missingBaseFeature()
  {return missingBaseFeature;}
void rectangularPattern::set_missingBaseFeature(parenRectangularOmitList * missingBaseFeatureIn)
  {missingBaseFeature = missingBaseFeatureIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete lengthMeasure;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (lengthMeasure)
    lengthMeasure->printSelf();
  else
    printf("$");
  printf(")");
}

real * sideMill::get_lengthMeasure()
  {return lengthMeasure;}
void sideMill::set_lengthMeasure(real * lengthMeasureIn)
  {lengthMeasure = lengthMeasureIn;}

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

real * sideMilling::get_axialCuttingDepth()
  {return axialCuttingDepth;}
void sideMilling::set_axialCuttingDepth(real * axialCuttingDepthIn)
  {axialCuttingDepth = axialCuttingDepthIn;}
real * sideMilling::get_radialCuttingDepth()
  {return radialCuttingDepth;}
void sideMilling::set_radialCuttingDepth(real * radialCuttingDepthIn)
  {radialCuttingDepth = radialCuttingDepthIn;}
real * sideMilling::get_allowanceSide()
  {return allowanceSide;}
void sideMilling::set_allowanceSide(real * allowanceSideIn)
  {allowanceSide = allowanceSideIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_axialCuttingDepth();
  //delete get_radialCuttingDepth();
  //delete get_allowanceSide();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_radialCuttingDepth())
    get_radialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceSide())
    get_allowanceSide()->printSelf();
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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_axialCuttingDepth();
  //delete get_radialCuttingDepth();
  //delete get_allowanceSide();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_radialCuttingDepth())
    get_radialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceSide())
    get_allowanceSide()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  get_position()->get_iId()->printSelf();
  printf(",");
  printDouble(radius);
  printf(")");
}

double sphericalSurface::get_radius()
  {return radius;}
void sphericalSurface::set_radius(double radiusIn)
  {radius = radiusIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(get_sweptCurve()))->get_iId()->printSelf();
  printf(",");
  extrusionAxis->get_iId()->printSelf();
  printf(")");
}

vector * surfaceOfLinearExtrusion::get_extrusionAxis()
  {return extrusionAxis;}
void surfaceOfLinearExtrusion::set_extrusionAxis(vector * extrusionAxisIn)
  {extrusionAxis = extrusionAxisIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(get_sweptCurve()))->get_iId()->printSelf();
  printf(",");
  axisPosition->get_iId()->printSelf();
  printf(")");
}

axis1placement * surfaceOfRevolution::get_axisPosition()
  {return axisPosition;}
void surfaceOfRevolution::set_axisPosition(axis1placement * axisPositionIn)
  {axisPosition = axisPositionIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete taperAngle;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

real * taperedTap::get_taperAngle()
  {return taperAngle;}
void taperedTap::set_taperAngle(real * taperAngleIn)
  {taperAngle = taperAngleIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_cuttingDepth();
  //delete get_previousDiameter();
  //delete get_dwellTimeBottom();
  //delete get_feedOnRetract();
  //delete compensationChuck;
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_iId()->printSelf();
  else
    printf("$");
  compensationChuck->printSelf();
  printf(")");
}

boolean * tapping::get_compensationChuck()
  {return compensationChuck;}
void tapping::set_compensationChuck(boolean * compensationChuckIn)
  {compensationChuck = compensationChuckIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_cuttingDepth();
  //delete get_previousDiameter();
  //delete get_dwellTimeBottom();
  //delete get_feedOnRetract();
  //delete helicalMovementOnForward;
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_iId()->printSelf();
  else
    printf("$");
  helicalMovementOnForward->printSelf();
  printf(")");
}

boolean * threadDrilling::get_helicalMovementOnForward()
  {return helicalMovementOnForward;}
void threadDrilling::set_helicalMovementOnForward(boolean * helicalMovementOnForwardIn)
  {helicalMovementOnForward = helicalMovementOnForwardIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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

cartesianPoint * toolProbing::get_offset()
  {return offset;}
void toolProbing::set_offset(cartesianPoint * offsetIn)
  {offset = offsetIn;}
double toolProbing::get_maxWear()
  {return maxWear;}
void toolProbing::set_maxWear(double maxWearIn)
  {maxWear = maxWearIn;}
machiningTool * toolProbing::get_itsTool()
  {return itsTool;}
void toolProbing::set_itsTool(machiningTool * itsToolIn)
  {itsTool = itsToolIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_iId()->printSelf();
  printf(",");
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_measuredOffset()->get_iId()->printSelf();
  printf(",");
  get_offset()->get_iId()->printSelf();
  printf(",");
  printDouble(get_maxWear());
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete cuttingThickness;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (cuttingThickness)
    cuttingThickness->printSelf();
  else
    printf("$");
  printf(")");
}

real * tSlotMill::get_cuttingThickness()
  {return cuttingThickness;}
void tSlotMill::set_cuttingThickness(real * cuttingThicknessIn)
  {cuttingThickness = cuttingThicknessIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete[] get_name();
  //delete get_uDegree();
  //delete get_vDegree();
  //delete get_controlPointsList();
  //delete get_surfaceForm();
  //delete get_uClosed();
  //delete get_vClosed();
  //delete get_selfIntersect();
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
  printString(get_name());
  printf(",");
  get_uDegree()->printSelf();
  printf(",");
  get_vDegree()->printSelf();
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_surfaceForm()->printSelf();
  printf(",");
  get_uClosed()->printSelf();
  printf(",");
  get_vClosed()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete cutterWidth;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (cutterWidth)
    cutterWidth->printSelf();
  else
    printf("$");
  printf(")");
}

real * woodruffKeyseatMill::get_cutterWidth()
  {return cutterWidth;}
void woodruffKeyseatMill::set_cutterWidth(real * cutterWidthIn)
  {cutterWidth = cutterWidthIn;}

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
  //delete get_itsPriority();
  //delete get_itsType();
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
  get_itsPriority()->printSelf();
  printf(",");
  get_itsType()->printSelf();
  printf(",");
  if (get_itsSpeed())
    get_itsSpeed()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsTechnology())
    (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachineFunctions())
    (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_fixPoint()->get_iId()->printSelf();
  printf(",");
  if (get_fixPointDir())
    get_fixPointDir()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(angle);
  printf(",");
  printDouble(benddist);
  printf(")");
}

double apLiftPathAngle::get_angle()
  {return angle;}
void apLiftPathAngle::set_angle(double angleIn)
  {angle = angleIn;}
double apLiftPathAngle::get_benddist()
  {return benddist;}
void apLiftPathAngle::set_benddist(double benddistIn)
  {benddist = benddistIn;}

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
  //delete get_itsPriority();
  //delete get_itsType();
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
  get_itsPriority()->printSelf();
  printf(",");
  get_itsType()->printSelf();
  printf(",");
  if (get_itsSpeed())
    get_itsSpeed()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsTechnology())
    (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachineFunctions())
    (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_fixPoint()->get_iId()->printSelf();
  printf(",");
  if (get_fixPointDir())
    get_fixPointDir()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printDouble(radius);
  printf(")");
}

double apLiftPathTangent::get_radius()
  {return radius;}
void apLiftPathTangent::set_radius(double radiusIn)
  {radius = radiusIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_cuttingDepth();
  //delete get_previousDiameter();
  //delete get_dwellTimeBottom();
  //delete get_feedOnRetract();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_iId()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete countersinkRadius;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (countersinkRadius)
    countersinkRadius->printSelf();
  else
    printf("$");
  printf(")");
}

real * backsideCountersink::get_countersinkRadius()
  {return countersinkRadius;}
void backsideCountersink::set_countersinkRadius(real * countersinkRadiusIn)
  {countersinkRadius = countersinkRadiusIn;}

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
  //delete[] get_name();
  //delete get_uDegree();
  //delete get_vDegree();
  //delete get_controlPointsList();
  //delete get_surfaceForm();
  //delete get_uClosed();
  //delete get_vClosed();
  //delete get_selfIntersect();
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
  printString(get_name());
  printf(",");
  get_uDegree()->printSelf();
  printf(",");
  get_vDegree()->printSelf();
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_surfaceForm()->printSelf();
  printf(",");
  get_uClosed()->printSelf();
  printf(",");
  get_vClosed()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
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

boolean * boringOperation::get_spindleStopAtBottom()
  {return spindleStopAtBottom;}
void boringOperation::set_spindleStopAtBottom(boolean * spindleStopAtBottomIn)
  {spindleStopAtBottom = spindleStopAtBottomIn;}
real * boringOperation::get_depthOfTestcut()
  {return depthOfTestcut;}
void boringOperation::set_depthOfTestcut(real * depthOfTestcutIn)
  {depthOfTestcut = depthOfTestcutIn;}
cartesianPoint * boringOperation::get_waitingPosition()
  {return waitingPosition;}
void boringOperation::set_waitingPosition(cartesianPoint * waitingPositionIn)
  {waitingPosition = waitingPositionIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_axialCuttingDepth();
  //delete get_radialCuttingDepth();
  //delete get_allowanceSide();
  //delete get_allowanceBottom();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_radialCuttingDepth())
    get_radialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceSide())
    get_allowanceSide()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceBottom())
    get_allowanceBottom()->printSelf();
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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(get_basisSurface()))->get_iId()->printSelf();
  printf(",");
  get_referenceToCurve()->get_iId()->printSelf();
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

int bSplineCurve::get_degree()
  {return degree;}
void bSplineCurve::set_degree(int degreeIn)
  {degree = degreeIn;}
parenCartesianPointList * bSplineCurve::get_controlPointsList()
  {return controlPointsList;}
void bSplineCurve::set_controlPointsList(parenCartesianPointList * controlPointsListIn)
  {controlPointsList = controlPointsListIn;}
bSplineCurveForm * bSplineCurve::get_curveForm()
  {return curveForm;}
void bSplineCurve::set_curveForm(bSplineCurveForm * curveFormIn)
  {curveForm = curveFormIn;}
logical * bSplineCurve::get_closedCurve()
  {return closedCurve;}
void bSplineCurve::set_closedCurve(logical * closedCurveIn)
  {closedCurve = closedCurveIn;}
logical * bSplineCurve::get_selfIntersect()
  {return selfIntersect;}
void bSplineCurve::set_selfIntersect(logical * selfIntersectIn)
  {selfIntersect = selfIntersectIn;}

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
  //delete[] get_name();
  //delete get_controlPointsList();
  //delete get_curveForm();
  //delete get_closedCurve();
  //delete get_selfIntersect();
  //delete knotMultiplicites;
  //delete knots;
  //delete knotSpec;
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
  printString(get_name());
  printf(",");
  printf("%d", get_degree());
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_curveForm()->printSelf();
  printf(",");
  get_closedCurve()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
  knotMultiplicites->printSelf();
  printf(",");
  knots->printSelf();
  printf(",");
  knotSpec->printSelf();
  printf(")");
}

parenIntegerListFull * bSplineCurveWithKnots::get_knotMultiplicites()
  {return knotMultiplicites;}
void bSplineCurveWithKnots::set_knotMultiplicites(parenIntegerListFull * knotMultiplicitesIn)
  {knotMultiplicites = knotMultiplicitesIn;}
parenRealListFull * bSplineCurveWithKnots::get_knots()
  {return knots;}
void bSplineCurveWithKnots::set_knots(parenRealListFull * knotsIn)
  {knots = knotsIn;}
knotType * bSplineCurveWithKnots::get_knotSpec()
  {return knotSpec;}
void bSplineCurveWithKnots::set_knotSpec(knotType * knotSpecIn)
  {knotSpec = knotSpecIn;}

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
  //delete[] get_name();
  //delete segments;
  //delete selfIntersect;
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
  printString(get_name());
  printf(",");
  segments->printSelf();
  printf(",");
  selfIntersect->printSelf();
  printf(")");
}

parenCompositeCurveSegmentListFull * compositeCurve::get_segments()
  {return segments;}
void compositeCurve::set_segments(parenCompositeCurveSegmentListFull * segmentsIn)
  {segments = segmentsIn;}
logical * compositeCurve::get_selfIntersect()
  {return selfIntersect;}
void compositeCurve::set_selfIntersect(logical * selfIntersectIn)
  {selfIntersect = selfIntersectIn;}

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

axis2placement3d * conic::get_position()
  {return position;}
void conic::set_position(axis2placement3d * positionIn)
  {position = positionIn;}

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
  //delete get_itsPriority();
  //delete get_itsType();
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
  get_itsPriority()->printSelf();
  printf(",");
  get_itsType()->printSelf();
  printf(",");
  if (get_itsSpeed())
    get_itsSpeed()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsTechnology())
    (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachineFunctions())
    (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete countersinkRadius;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (countersinkRadius)
    countersinkRadius->printSelf();
  else
    printf("$");
  printf(")");
}

real * countersink::get_countersinkRadius()
  {return countersinkRadius;}
void countersink::set_countersinkRadius(real * countersinkRadiusIn)
  {countersinkRadius = countersinkRadiusIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete includedAngle;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (includedAngle)
    includedAngle->printSelf();
  else
    printf("$");
  printf(")");
}

real * dovetailMill::get_includedAngle()
  {return includedAngle;}
void dovetailMill::set_includedAngle(real * includedAngleIn)
  {includedAngle = includedAngleIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  get_position()->get_iId()->printSelf();
  printf(",");
  printDouble(semiAxis1);
  printf(",");
  printDouble(semiAxis2);
  printf(")");
}

double ellipse::get_semiAxis1()
  {return semiAxis1;}
void ellipse::set_semiAxis1(double semiAxis1In)
  {semiAxis1 = semiAxis1In;}
double ellipse::get_semiAxis2()
  {return semiAxis2;}
void ellipse::set_semiAxis2(double semiAxis2In)
  {semiAxis2 = semiAxis2In;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  get_position()->get_iId()->printSelf();
  printf(",");
  printDouble(semiAxis);
  printf(",");
  printDouble(semiImagAxis);
  printf(")");
}

double hyperbola::get_semiAxis()
  {return semiAxis;}
void hyperbola::set_semiAxis(double semiAxisIn)
  {semiAxis = semiAxisIn;}
double hyperbola::get_semiImagAxis()
  {return semiImagAxis;}
void hyperbola::set_semiImagAxis(double semiImagAxisIn)
  {semiImagAxis = semiImagAxisIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_cuttingDepth();
  //delete get_previousDiameter();
  //delete get_dwellTimeBottom();
  //delete get_feedOnRetract();
  //delete dwellTimeStep;
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_iId()->printSelf();
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

double multistepDrilling::get_retractDistance()
  {return retractDistance;}
void multistepDrilling::set_retractDistance(double retractDistanceIn)
  {retractDistance = retractDistanceIn;}
double multistepDrilling::get_firstDepth()
  {return firstDepth;}
void multistepDrilling::set_firstDepth(double firstDepthIn)
  {firstDepth = firstDepthIn;}
double multistepDrilling::get_depthOfStep()
  {return depthOfStep;}
void multistepDrilling::set_depthOfStep(double depthOfStepIn)
  {depthOfStep = depthOfStepIn;}
real * multistepDrilling::get_dwellTimeStep()
  {return dwellTimeStep;}
void multistepDrilling::set_dwellTimeStep(real * dwellTimeStepIn)
  {dwellTimeStep = dwellTimeStepIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  get_position()->get_iId()->printSelf();
  printf(",");
  printDouble(focalDist);
  printf(")");
}

double parabola::get_focalDist()
  {return focalDist;}
void parabola::set_focalDist(double focalDistIn)
  {focalDist = focalDistIn;}

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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(get_basisSurface()))->get_iId()->printSelf();
  printf(",");
  get_referenceToCurve()->get_iId()->printSelf();
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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_axialCuttingDepth();
  //delete get_allowanceBottom();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_approach())
    (dynamic_cast<instance *>(get_approach()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_retract())
    (dynamic_cast<instance *>(get_retract()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    (dynamic_cast<instance *>(get_itsMachiningStrategy()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_axialCuttingDepth())
    get_axialCuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_allowanceBottom())
    get_allowanceBottom()->printSelf();
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
  //delete[] get_name();
  //delete points;
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
  printString(get_name());
  printf(",");
  points->printSelf();
  printf(")");
}

parenCartesianPointListFull * polyline::get_points()
  {return points;}
void polyline::set_points(parenCartesianPointListFull * pointsIn)
  {points = pointsIn;}

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
  //delete[] get_name();
  //delete get_controlPointsList();
  //delete get_curveForm();
  //delete get_closedCurve();
  //delete get_selfIntersect();
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
  printString(get_name());
  printf(",");
  printf("%d", get_degree());
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_curveForm()->printSelf();
  printf(",");
  get_closedCurve()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
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
  //delete[] get_name();
  //delete get_controlPointsList();
  //delete get_curveForm();
  //delete get_closedCurve();
  //delete get_selfIntersect();
  //delete weightsData;
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
  printString(get_name());
  printf(",");
  printf("%d", get_degree());
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_curveForm()->printSelf();
  printf(",");
  get_closedCurve()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
  printf(",");
  weightsData->printSelf();
  printf(")");
}

parenRealListFull * rationalBSplineCurve::get_weightsData()
  {return weightsData;}
void rationalBSplineCurve::set_weightsData(parenRealListFull * weightsDataIn)
  {weightsData = weightsDataIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_cuttingDepth();
  //delete get_previousDiameter();
  //delete get_dwellTimeBottom();
  //delete get_feedOnRetract();
  //delete get_spindleStopAtBottom();
  //delete get_depthOfTestcut();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_spindleStopAtBottom()->printSelf();
  printf(",");
  if (get_depthOfTestcut())
    get_depthOfTestcut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_waitingPosition())
    get_waitingPosition()->get_iId()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete taperAngle;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

real * taperedDrill::get_taperAngle()
  {return taperAngle;}
void taperedDrill::set_taperAngle(real * taperAngleIn)
  {taperAngle = taperAngleIn;}

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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
  //delete taperAngle;
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (taperAngle)
    taperAngle->printSelf();
  else
    printf("$");
  printf(")");
}

real * taperedEndmill::get_taperAngle()
  {return taperAngle;}
void taperedEndmill::set_taperAngle(real * taperAngleIn)
  {taperAngle = taperAngleIn;}

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
  //delete[] get_itsId();
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
  printString(get_itsId());
  printf(",");
  (dynamic_cast<instance *>(get_itsSecplane()))->get_iId()->printSelf();
  printf(",");
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_measuredOffset()->get_iId()->printSelf();
  printf(",");
  get_offset()->get_iId()->printSelf();
  printf(",");
  printDouble(get_maxWear());
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
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
  //delete[] get_name();
  //delete trim1;
  //delete trim2;
  //delete senseAgreement;
  //delete masterRepresentation;
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
  printString(get_name());
  printf(",");
  (dynamic_cast<instance *>(basisCurve))->get_iId()->printSelf();
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

curve * trimmedCurve::get_basisCurve()
  {return basisCurve;}
void trimmedCurve::set_basisCurve(curve * basisCurveIn)
  {basisCurve = basisCurveIn;}
parenTrimmingSelectListFull * trimmedCurve::get_trim1()
  {return trim1;}
void trimmedCurve::set_trim1(parenTrimmingSelectListFull * trim1In)
  {trim1 = trim1In;}
parenTrimmingSelectListFull * trimmedCurve::get_trim2()
  {return trim2;}
void trimmedCurve::set_trim2(parenTrimmingSelectListFull * trim2In)
  {trim2 = trim2In;}
boolean * trimmedCurve::get_senseAgreement()
  {return senseAgreement;}
void trimmedCurve::set_senseAgreement(boolean * senseAgreementIn)
  {senseAgreement = senseAgreementIn;}
trimmingPreference * trimmedCurve::get_masterRepresentation()
  {return masterRepresentation;}
void trimmedCurve::set_masterRepresentation(trimmingPreference * masterRepresentationIn)
  {masterRepresentation = masterRepresentationIn;}

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
  //delete[] get_name();
  //delete get_controlPointsList();
  //delete get_curveForm();
  //delete get_closedCurve();
  //delete get_selfIntersect();
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
  printString(get_name());
  printf(",");
  printf("%d", get_degree());
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_curveForm()->printSelf();
  printf(",");
  get_closedCurve()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete[] get_name();
  //delete get_controlPointsList();
  //delete get_curveForm();
  //delete get_closedCurve();
  //delete get_selfIntersect();
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
  printString(get_name());
  printf(",");
  printf("%d", get_degree());
  printf(",");
  get_controlPointsList()->printSelf();
  printf(",");
  get_curveForm()->printSelf();
  printf(",");
  get_closedCurve()->printSelf();
  printf(",");
  get_selfIntersect()->printSelf();
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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_cuttingDepth();
  //delete get_previousDiameter();
  //delete get_dwellTimeBottom();
  //delete get_feedOnRetract();
  //delete get_spindleStopAtBottom();
  //delete get_depthOfTestcut();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  get_spindleStopAtBottom()->printSelf();
  printf(",");
  if (get_depthOfTestcut())
    get_depthOfTestcut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_waitingPosition())
    get_waitingPosition()->get_iId()->printSelf();
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
  //delete get_numberOfTeeth();
  //delete get_handOfCut();
  //delete get_coolantThroughTool();
  //delete get_pilotLength();
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
  get_dimension()->get_iId()->printSelf();
  printf(",");
  if (get_numberOfTeeth())
    get_numberOfTeeth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_handOfCut())
    get_handOfCut()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_coolantThroughTool())
    get_coolantThroughTool()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_pilotLength())
    get_pilotLength()->printSelf();
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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_cuttingDepth();
  //delete get_previousDiameter();
  //delete get_dwellTimeBottom();
  //delete get_feedOnRetract();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_iId()->printSelf();
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
  //delete[] get_name();
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
  printString(get_name());
  printf(",");
  get_position()->get_iId()->printSelf();
  printf(",");
  printDouble(radius);
  printf(")");
}

double circle::get_radius()
  {return radius;}
void circle::set_radius(double radiusIn)
  {radius = radiusIn;}

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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_cuttingDepth();
  //delete get_previousDiameter();
  //delete get_dwellTimeBottom();
  //delete get_feedOnRetract();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_iId()->printSelf();
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
  //delete[] get_itsId();
  //delete get_retractPlane();
  //delete get_overcutLength();
  //delete get_cuttingDepth();
  //delete get_previousDiameter();
  //delete get_dwellTimeBottom();
  //delete get_feedOnRetract();
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
  if (get_itsToolpath())
    get_itsToolpath()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsToolDirection())
    (dynamic_cast<instance *>(get_itsToolDirection()))->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  printString(get_itsId());
  printf(",");
  if (get_retractPlane())
    get_retractPlane()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_startPoint())
    get_startPoint()->get_iId()->printSelf();
  else
    printf("$");
  printf(",");
  (dynamic_cast<instance *>(get_itsTool()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsTechnology()))->get_iId()->printSelf();
  printf(",");
  (dynamic_cast<instance *>(get_itsMachineFunctions()))->get_iId()->printSelf();
  printf(",");
  if (get_overcutLength())
    get_overcutLength()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_cuttingDepth())
    get_cuttingDepth()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_previousDiameter())
    get_previousDiameter()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_dwellTimeBottom())
    get_dwellTimeBottom()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_feedOnRetract())
    get_feedOnRetract()->printSelf();
  else
    printf("$");
  printf(",");
  if (get_itsMachiningStrategy())
    get_itsMachiningStrategy()->get_iId()->printSelf();
  else
    printf("$");
  printf(")");
}

BOOST_CLASS_EXPORT_IMPLEMENT(workplan)
BOOST_CLASS_EXPORT_IMPLEMENT(setup)
BOOST_CLASS_EXPORT_IMPLEMENT(block);
BOOST_CLASS_EXPORT_IMPLEMENT(machiningWorkingstep)
BOOST_CLASS_EXPORT_IMPLEMENT(rectangularClosedProfile)
BOOST_CLASS_EXPORT_IMPLEMENT(circularClosedProfile)
BOOST_CLASS_EXPORT_IMPLEMENT(planarFace)
BOOST_CLASS_EXPORT_IMPLEMENT(closedPocket)
BOOST_CLASS_EXPORT_IMPLEMENT(openPocket)
BOOST_CLASS_EXPORT_IMPLEMENT(roundHole)
BOOST_CLASS_EXPORT_IMPLEMENT(slot)
BOOST_CLASS_EXPORT_IMPLEMENT(step)
BOOST_CLASS_EXPORT_IMPLEMENT(generalOutsideProfile)
BOOST_CLASS_EXPORT_IMPLEMENT(generalPath)
BOOST_CLASS_EXPORT_IMPLEMENT(linearPath)
BOOST_CLASS_EXPORT_IMPLEMENT(partialCircularPath)
BOOST_CLASS_EXPORT_IMPLEMENT(completeCircularPath)
BOOST_CLASS_EXPORT_IMPLEMENT(roundedUProfile)
BOOST_CLASS_EXPORT_IMPLEMENT(partialCircularProfile)
BOOST_CLASS_EXPORT_IMPLEMENT(teeProfile)
BOOST_CLASS_EXPORT_IMPLEMENT(squareUProfile)
BOOST_CLASS_EXPORT_IMPLEMENT(veeProfile)
BOOST_CLASS_EXPORT_IMPLEMENT(generalProfile)
BOOST_CLASS_EXPORT_IMPLEMENT(woodruffSlotEndType)
BOOST_CLASS_EXPORT_IMPLEMENT(flatSlotEndType)
BOOST_CLASS_EXPORT_IMPLEMENT(loopSlotEndType)
BOOST_CLASS_EXPORT_IMPLEMENT(openSlotEndType)
BOOST_CLASS_EXPORT_IMPLEMENT(radiusedSlotEndType)
BOOST_CLASS_EXPORT_IMPLEMENT(radiusedPocketBottomCondition)
BOOST_CLASS_EXPORT_IMPLEMENT(throughPocketBottomCondition)
BOOST_CLASS_EXPORT_IMPLEMENT(planarPocketBottomCondition)
BOOST_CLASS_EXPORT_IMPLEMENT(generalPocketBottomCondition)
BOOST_CLASS_EXPORT_IMPLEMENT(planeRoughMilling)
BOOST_CLASS_EXPORT_IMPLEMENT(planeFinishMilling)
BOOST_CLASS_EXPORT_IMPLEMENT(sideRoughMilling)
BOOST_CLASS_EXPORT_IMPLEMENT(sideFinishMilling)
BOOST_CLASS_EXPORT_IMPLEMENT(bottomAndSideRoughMilling)
BOOST_CLASS_EXPORT_IMPLEMENT(bottomAndSideFinishMilling)
BOOST_CLASS_EXPORT_IMPLEMENT(millingCuttingTool)
BOOST_CLASS_EXPORT_IMPLEMENT(two5DmillingStrategy)
BOOST_CLASS_EXPORT_IMPLEMENT(unidirectionalMilling)
BOOST_CLASS_EXPORT_IMPLEMENT(bidirectionalContour)
BOOST_CLASS_EXPORT_IMPLEMENT(bidirectionalMilling)
BOOST_CLASS_EXPORT_IMPLEMENT(contourParallel)
BOOST_CLASS_EXPORT_IMPLEMENT(contourBidirectional)
BOOST_CLASS_EXPORT_IMPLEMENT(contourSpiral)
BOOST_CLASS_EXPORT_IMPLEMENT(centerMilling)
BOOST_CLASS_EXPORT_IMPLEMENT(cutmodeTypeClimb)
BOOST_CLASS_EXPORT_IMPLEMENT(cutmodeTypeConventional)
BOOST_CLASS_EXPORT_IMPLEMENT(leftOrRightRight)
BOOST_CLASS_EXPORT_IMPLEMENT(leftOrRightLeft)
BOOST_CLASS_EXPORT_IMPLEMENT(rotDirectionCw)
BOOST_CLASS_EXPORT_IMPLEMENT(rotDirectionCcw)
BOOST_CLASS_EXPORT_IMPLEMENT(strokeConnectionStrategyStraightline)
BOOST_CLASS_EXPORT_IMPLEMENT(strokeConnectionStrategyLoopBack)
BOOST_CLASS_EXPORT_IMPLEMENT(strokeConnectionStrategyLiftShiftPlunge)
BOOST_CLASS_EXPORT_IMPLEMENT(strokeConnectionStrategyDegouge)
BOOST_CLASS_EXPORT_IMPLEMENT(approachRetractStrategy)
BOOST_CLASS_EXPORT_IMPLEMENT(apRetractAngle)
BOOST_CLASS_EXPORT_IMPLEMENT(millingTechnology)
BOOST_CLASS_EXPORT_IMPLEMENT(booleanTrue)
BOOST_CLASS_EXPORT_IMPLEMENT(booleanFalse)
BOOST_CLASS_EXPORT_IMPLEMENT(toolReferencePointCcp)
BOOST_CLASS_EXPORT_IMPLEMENT(toolReferencePointTcp)
BOOST_CLASS_EXPORT_IMPLEMENT(diameterTaper)
BOOST_CLASS_EXPORT_IMPLEMENT(angleTaper)
BOOST_CLASS_EXPORT_IMPLEMENT(throughBottomCondition)
BOOST_CLASS_EXPORT_IMPLEMENT(conicalHoleBottom)
BOOST_CLASS_EXPORT_IMPLEMENT(flatHoleBottom)
BOOST_CLASS_EXPORT_IMPLEMENT(flatWithRadiusHoleBottom)
BOOST_CLASS_EXPORT_IMPLEMENT(sphericalHoleBottom)
BOOST_CLASS_EXPORT_IMPLEMENT(backBoring)
BOOST_CLASS_EXPORT_IMPLEMENT(tapping)
BOOST_CLASS_EXPORT_IMPLEMENT(threadDrilling)
BOOST_CLASS_EXPORT_IMPLEMENT(drilling)
BOOST_CLASS_EXPORT_IMPLEMENT(centerDrilling)
BOOST_CLASS_EXPORT_IMPLEMENT(counterSinking)
BOOST_CLASS_EXPORT_IMPLEMENT(multistepDrilling)
BOOST_CLASS_EXPORT_IMPLEMENT(reaming)
BOOST_CLASS_EXPORT_IMPLEMENT(boring)
BOOST_CLASS_EXPORT_IMPLEMENT(polyline)
/********************************************************************/

