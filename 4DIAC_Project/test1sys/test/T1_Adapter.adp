<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE AdapterType SYSTEM "http://www.holobloc.com/xml/LibraryElement.dtd">
<AdapterType Name="T1_Adapter">
  <Identification Standard="61499-1"/>
  <VersionInfo Author="GE" Date="2008-04-22" Organization="4DIAC-Consortium" Version="0.0"/>
  <InterfaceList>
    <EventInputs>
      <Event Comment="Request from Socket" Name="REQ" Type="Event">
        <With Var="REQD"/>
      </Event>
      <Event Comment="Response from Socket" Name="RSP" Type="Event">
        <With Var="RSPD"/>
      </Event>
    </EventInputs>
    <EventOutputs>
      <Event Comment="Confirmation from Plug" Name="CNF" Type="Event">
        <With Var="CNFD"/>
      </Event>
      <Event Comment="Indication from Plug" Name="IND" Type="Event">
        <With Var="INDD"/>
      </Event>
    </EventOutputs>
    <InputVars>
      <VarDeclaration Comment="Request Data from Socket" Name="REQD" Type="STRING"/>
      <VarDeclaration Comment="Response Data from Socket" Name="RSPD" Type="STRING"/>
    </InputVars>
    <OutputVars>
      <VarDeclaration Comment="Confirmation Data from Plug" Name="CNFD" Type="STRING"/>
      <VarDeclaration Comment="Indication Data from Plug" Name="INDD" Type="STRING"/>
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
