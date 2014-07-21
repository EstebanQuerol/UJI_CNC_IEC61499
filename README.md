UJI_CNC_IEC61499
================

Universitat Jaume I research project about the application of IEC 61499 standard into the manufacturing field. 

The objective of this project is to create an intermediate software layer that handles the conversion of a part’s process plan into G code understandable by a CNC machine.   The main advantage of this intermediate layer, with respect to the traditional methods, is that it will allow us to use more complex process plans and fully exploit the design and manufacturing knowledge, by determining the optimum machining operations’ sequence based on the process plan constraints and the actual state of the CNC machine and its tools.

To build this layer we will use the IEC61499 standard since it allows building reusable, standardized and distributable applications. Being able to adapt this intermediate layer to be used with different CNC controllers is also one of the main objectives of this project, since the manufacturing field is distinguished by the lack of interoperability between devices from different vendors.

To implement this layer we will use IEC61499 development software 4DIAC and its runtime FORTE. As CNC controller, in a 1st time, we will use a FAGOR Automation 8070 controller used in a multi axis milling machine that for the moment will be simulated.
