Lego Mindstorms adaptations of eCos
===================================

This readme gives a brief overview on the steps necessary to build eCos for
the Lego Mindstorms nxt controller.


1. Download eCos source:
   For getting eCos please refer to the eCos getting started documentation:
   http://ecos.sourceware.org/getstart.html
   
2. Modify eCos source:
   The directory where this readme file is located contains the necessary changes
   and extensions that need to be applied to the eCos source tree.   

   2.1 The folder "mindstorms nxt" contains the eCos hal for Lego Mindstorms nxt
       Copy the whole folder into 
          packages/hal/arm/at91 
       directory of your eCos source tree.   
   2.2 Add the contents of the file "lmsecosdb.changes" at the end of the 
       ecos.db file of your eCos source tree. You can find this in the packages 
       directory.

3. Open the eCos config tool and select under Build->Repositories... the 
   directory where you have installed your eCos Source
   
4. Load (File->Open) the ecos configuration file "lms_ecos_config.ecc" provided with FORTE
   in the directory where this readme file resides.
   
5. In order to not destroy the original configuration I usually save the 
   configuration to a different place. This location is also the build location.
            
6. Generate the build tree Build -> Generate Build Tree

7. Build the eCos libraries: Build -> Library
    
8. After a successful build you should have the eCos target libraries in the 
   lms_ecos_config_install/lib directory located in the directory where you
   saved the configuration file for building at. The according include files are in
   lms_ecos_config_install/include. These are needed for the cmake configuration for building FORTE.
   
   8.1 stdint.h: currently eCos does not directly provide an stdint.h. a suitable stdint.h for eCOS is provided for example by the 
    uSTL package. It can be found here: http://opencores.org/ocsvn/openrisc/openrisc/trunk/rtos/ecos-3.0/packages/language/cxx/ustl/current/include/
    For compiling FORTE you will need to copy this file into the lms_ecos_config_install/include directory.


