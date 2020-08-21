# PI_CB_CNC_GRBL11
GRBL v1.1 firmware for PiBot Control Board HW Rev 2.3 and above

How To Use:
1. Download and install latest Arduino. E.g. installed to C:\Program Files (x86)\Arduino

2. Add PiBot Board Information to the Arduino. 
  * Locate "boards.txt" at Arduino install folder. e.g. C:\Program Files (x86)\Arduino\hardware\arduino\avr
  * Edit "boards.txt", add copy and paste the content at the end of this readme. You will need administrator right for doing so, if installed to the default folder. Recommend to use Notepad++ to do this.
   
3. Locate Arduino library folder, e.g. C:\Program Files (x86)\Arduino\libraries
  * Copy "PiBot_CNC_GRBL11" folder to library folder, you may need administrator rights.
  
4. Start Arduino IDE, from menu, select "Files" -> "Examples" -> "PiBot_CNC_GRBL11" -> "PiBotUploader".

5. from menu, select "Tools" -> "Board" -> "PiBot Controller Rev2.x". Then select the correct Port.

6. Read the instructions then click Upload.

NOTE: Before Uploading, ensure external stepper drivers are powered OFF. Switch set to "3D".

  
ATTACHMENT:
Contents to be added to the end of "boards.txt", do not including this line. Copy between (and includes) the hash(#) line.

```c

##############################################################
pibotmega2560r2.name=PiBot Controller Rev2.x

pibotmega2560r2.vid.0=0x1A86
pibotmega2560r2.pid.0=0x7523
pibotmega2560r2.vid.1=0x2341
pibotmega2560r2.pid.1=0x0042
pibotmega2560r2.vid.2=0x2A03
pibotmega2560r2.pid.2=0x0010
pibotmega2560r2.vid.3=0x2A03
pibotmega2560r2.pid.3=0x0042
pibotmega2560r2.vid.4=0x2341
pibotmega2560r2.pid.4=0x0210
pibotmega2560r2.vid.5=0x2341
pibotmega2560r2.pid.5=0x0242

pibotmega2560r2.upload.tool=avrdude
pibotmega2560r2.upload.maximum_data_size=8192

pibotmega2560r2.bootloader.tool=avrdude
pibotmega2560r2.bootloader.low_fuses=0xFF
pibotmega2560r2.bootloader.unlock_bits=0x3F
pibotmega2560r2.bootloader.lock_bits=0x0F

pibotmega2560r2.build.f_cpu=16000000L
pibotmega2560r2.build.core=arduino
pibotmega2560r2.build.variant=mega
pibotmega2560r2.build.board=AVR_MEGA2560

## Pibot Controller Rev 2.x
## -------------------------
pibotmega2560r2.menu.cpu.atmega2560=Mega 2560 Rev 2.x

pibotmega2560r2.menu.cpu.atmega2560.upload.protocol=wiring
pibotmega2560r2.menu.cpu.atmega2560.upload.maximum_size=253952
pibotmega2560r2.menu.cpu.atmega2560.upload.speed=115200

pibotmega2560r2.menu.cpu.atmega2560.bootloader.high_fuses=0xD8
pibotmega2560r2.menu.cpu.atmega2560.bootloader.extended_fuses=0xFD
pibotmega2560r2.menu.cpu.atmega2560.bootloader.file=stk500v2/stk500boot_v2_mega2560.hex

pibotmega2560r2.menu.cpu.atmega2560.build.mcu=atmega2560
pibotmega2560r2.menu.cpu.atmega2560.build.board=AVR_MEGA2560
##############################################################

```
