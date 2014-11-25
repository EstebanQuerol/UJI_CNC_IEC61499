<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE AdapterType SYSTEM "http://www.holobloc.com/xml/LibraryElement.dtd">
<AdapterType Name="L3_APart">
  <Identification Standard="61499-1"/>
  <VersionInfo Author="EQUEROL" Date="2008-04-22" Organization="UJI" Version="0.0"/>
  <CompilerInfo/>
  <InterfaceList>
    <EventInputs>
      <Event Comment="Confirmation to the socket" Name="CNF" Type="Event"/>
      <Event Comment="Indication to the socket" Name="IND" Type="Event">
        <With Var="TypeS"/>
        <With Var="FamilyS"/>
        <With Var="PartIDS"/>
      </Event>
    </EventInputs>
    <EventOutputs>
      <Event Comment="Request from the plug" Name="REQ" Type="Event">
        <With Var="PartIDP"/>
        <With Var="FamilyP"/>
        <With Var="TypeP"/>
        <With Var="Lotsize"/>
        <With Var="Deadline"/>
      </Event>
      <Event Comment="Response from de plug" Name="RSP" Type="Event">
        <With Var="Deadline"/>
        <With Var="FamilyP"/>
        <With Var="TypeP"/>
      </Event>
    </EventOutputs>
    <InputVars>
      <VarDeclaration Comment="Identifier of the last created part" Name="PartIDS" Type="UINT"/>
      <VarDeclaration Comment="Part's Family" Name="FamilyS" Type="UINT"/>
      <VarDeclaration Comment="Part's Type" Name="TypeS" Type="UINT"/>
    </InputVars>
    <OutputVars>
      <VarDeclaration Comment="Identifier of the 1st part" Name="PartIDP" Type="UINT"/>
      <VarDeclaration Comment="Part's Family" Name="FamilyP" Type="UINT"/>
      <VarDeclaration Comment="Part's type" Name="TypeP" Type="UINT"/>
      <VarDeclaration Comment="Number of parts to be manufactured" Name="Lotsize" Type="UINT"/>
      <VarDeclaration Comment="Deadline of the next part to be delivered" Name="Deadline" Type="DATE_AND_TIME"/>
    </OutputVars>
  </InterfaceList>
  <Service LeftInterface="SOCKET" RightInterface="PLUG">
    <ServiceSequence Name="request_confirm">
      <ServiceTransaction>
        <InputPrimitive Event="REQ" Interface="SOCKET" Parameters="REQD"/>
        <OutputPrimitive Event="REQ" Interface="PLUG" Parameters="REQD"/>
      </ServiceTransaction>
      <ServiceTransaction>
        <InputPrimitive Event="CNF" Interface="PLUG" Parameters="CNFD"/>
        <OutputPrimitive Event="CNF" Interface="SOCKET" Parameters="CNFD"/>
      </ServiceTransaction>
    </ServiceSequence>
    <ServiceSequence Name="indication_response">
      <ServiceTransaction>
        <InputPrimitive Event="IND" Interface="PLUG" Parameters="INDD"/>
        <OutputPrimitive Event="IND" Interface="SOCKET" Parameters="INDD"/>
      </ServiceTransaction>
      <ServiceTransaction>
        <InputPrimitive Event="RSP" Interface="SOCKET" Parameters="RSPD"/>
        <OutputPrimitive Event="RSP" Interface="PLUG" Parameters="RSPD"/>
      </ServiceTransaction>
    </ServiceSequence>
  </Service>
</AdapterType>
