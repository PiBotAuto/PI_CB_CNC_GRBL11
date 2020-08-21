/***********************************************************************
This sketch compiles and uploads GRBL v1.1 to your PiBot Control Board 
HW Rev 2.3.

For tutorials and instructions configuration the firmware to your platform,
please visit https://www.pibot.com


To use:
- First make sure you have imported Grbl source code into your Arduino
  IDE. There are details on our Github website on how to do this.

- Select "PiBot Controller Rev2.x" from Boards and correct Serial Port
  in the Tools drop-down menu.

- Ensure external stepper drivers are powered OFF. Switch set to "3D".

- Then just click 'Upload'. The uploading may takes about 20s.


To configurate:
- In defaults.h, under "DEFAULTS_PIBOT_REV23" section:
  * Config your hardware platform parameters such as XYZ steps, rates,
    axis limits, spindle speeds etc,.
    
- In nuts_bolts.h
  * Config axis mirroring (dual axis) if necessary.

- In config.h
  * Set the homing styles and directions if necessary.
  * Config input and output polarity if necessary, e.g. limit switch or
    spindle enable.
  
This firmware is derived and modified from Gnea project created by Mr Jeon
and Mr Skogsrud. Please visit https://github.com/gnea/grbl for further
information. The original copyright (c) 2015 Sungeun K. Jeon released 
under the MIT-license. See license.txt for details.

***********************************************************************/

#include <grbl.h>

// Do not alter this file!