<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE AdapterType SYSTEM "http://www.holobloc.com/xml/LibraryElement.dtd">
<AdapterType Name="L3_AAssignMachine">
  <Identification Standard="61499-1"/>
  <VersionInfo Author="EQUEROL" Date="2008-04-22" Organization="UJI" Version="0.0"/>
  <CompilerInfo/>
  <InterfaceList>
    <EventInputs>
      <Event Comment="Confirmation from socket to check request" Name="CNF1" Type="Event">
        <With Var="MTypeS"/>
        <With Var="MStateS"/>
        <With Var="MPriorityS"/>
        <With Var="MAssignS"/>
      </Event>
      <Event Comment="Confirmation from socket to assign request" Name="CNF2" Type="Event">
        <With Var="MFinalAssignS"/>
      </Event>
    </EventInputs>
    <EventOutputs>
      <Event Comment="Plugin request to check needed machines" Name="CHK" Type="Event">
        <With Var="MTypeP"/>
        <With Var="MStateP"/>
        <With Var="MPriorityP"/>
        <With Var="MAssignP"/>
      </Event>
      <Event Comment="Plugin request to assign machines to the process plans" Name="ASG" Type="Event">
        <With Var="MFinalAssignP"/>
      </Event>
    </EventOutputs>
    <InputVars>
      <VarDeclaration ArraySize="15" Comment="Machine Type vector" Name="MTypeS" Type="USINT"/>
      <VarDeclaration ArraySize="15" Comment="Machine state vector" Name="MStateS" Type="USINT"/>
      <VarDeclaration ArraySize="15" Comment="Machine allocations priority vector" Name="MPriorityS" Type="INT"/>
      <VarDeclaration ArraySize="15" Comment="Machine-PP assignation vector" Name="MAssignS" Type="UINT"/>
      <VarDeclaration ArraySize="15" Comment="Machine-PP assignation vector" Name="MFinalAssignS" Type="UINT"/>
    </InputVars>
    <OutputVars>
      <VarDeclaration ArraySize="15" Comment="Machine Type vector" InitialValue="" Name="MTypeP" Type="USINT"/>
      <VarDeclaration ArraySize="15" Comment="Machine State vector" InitialValue="" Name="MStateP" Type="USINT"/>
      <VarDeclaration ArraySize="15" Comment="Machine allocations priority vector" InitialValue="" Name="MPriorityP" Type="INT"/>
      <VarDeclaration ArraySize="15" Comment="Machine-PP assignation vector" Name="MAssignP" Type="UINT"/>
      <VarDeclaration ArraySize="15" Comment="Machine-PP Assignation vector" Name="MFinalAssignP" Type="UINT"/>
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
