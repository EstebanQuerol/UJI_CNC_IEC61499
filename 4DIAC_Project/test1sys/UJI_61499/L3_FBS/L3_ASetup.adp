<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE AdapterType SYSTEM "http://www.holobloc.com/xml/LibraryElement.dtd">
<AdapterType Name="L3_ASetup">
  <Identification Standard="61499-1"/>
  <VersionInfo Author="EQUEROL" Date="2008-04-22" Organization="UJI" Version="0.0"/>
  <VersionInfo Author="EQUEROL" Date="2015-01-08" Organization="UJI" Remarks="modified output data" Version="1.0"/>
  <CompilerInfo/>
  <InterfaceList>
    <EventInputs>
      <Event Comment="Setup assignation confirmation" Name="CNF" Type="Event">
        <With Var="PartInfoS"/>
      </Event>
      <Event Comment="Completed setup indication" Name="IND" Type="Event">
        <With Var="PartInfoS"/>
        <With Var="ENDID"/>
      </Event>
    </EventInputs>
    <EventOutputs>
      <Event Comment="Plugin request to assign a setup" Name="REQ" Type="Event">
        <With Var="PartInfoP"/>
        <With Var="MID"/>
        <With Var="Setup"/>
      </Event>
      <Event Comment="Completed setup indication treatement resposne" Name="RSP" Type="Event">
        <With Var="MID"/>
      </Event>
    </EventOutputs>
    <InputVars>
      <VarDeclaration ArraySize="3" Comment="Part ID, Part Family, Part Type" Name="PartInfoS" Type="UINT"/>
      <VarDeclaration Comment="Setup execution returned code" Name="ENDID" Type="USINT"/>
    </InputVars>
    <OutputVars>
      <VarDeclaration ArraySize="3" Comment="PartID, Part Family, Part Type" Name="PartInfoP" Type="UINT"/>
      <VarDeclaration Comment="Destination machine identifier" Name="MID" Type="USINT"/>
      <VarDeclaration Comment="Subphase to be transmitted" Name="Setup" Type="STRING"/>
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
