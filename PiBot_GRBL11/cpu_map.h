/*
  cpu_map.h - CPU and pin mapping configuration file
  Part of Grbl

  Copyright (c) 2012-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* The cpu_map.h files serve as a central pin mapping selection file for different 
   processor types or alternative pin layouts. This version of Grbl supports only the 
   Arduino Mega2560. */

#ifndef cpu_map_h
#define cpu_map_h


#ifdef CPU_MAP_2560_INITIAL // (Arduino Mega 2560) Working @EliteEng

  // Serial port interrupt vectors
  #define SERIAL_RX USART0_RX_vect
  #define SERIAL_UDRE USART0_UDRE_vect

  // Define step pulse output pins. NOTE: All step bit pins must be on the same port.
  #define STEP_DDR      DDRA
  #define STEP_PORT     PORTA
  #define STEP_PIN      PINA
  #define X_STEP_BIT    2 // MEGA2560 Digital Pin 24
  #define Y_STEP_BIT    3 // MEGA2560 Digital Pin 25
  #define Z_STEP_BIT    4 // MEGA2560 Digital Pin 26
  #define STEP_MASK ((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)) // All step bits

  // Define step direction output pins. NOTE: All direction pins must be on the same port.
  #define DIRECTION_DDR     DDRC
  #define DIRECTION_PORT    PORTC
  #define DIRECTION_PIN     PINC
  #define X_DIRECTION_BIT   7 // MEGA2560 Digital Pin 30
  #define Y_DIRECTION_BIT   6 // MEGA2560 Digital Pin 31
  #define Z_DIRECTION_BIT   5 // MEGA2560 Digital Pin 32
  #define DIRECTION_MASK ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT)) // All direction bits

  // Define stepper driver enable/disable output pin.
  #define STEPPERS_DISABLE_DDR   DDRB
  #define STEPPERS_DISABLE_PORT  PORTB
  #define STEPPERS_DISABLE_BIT   7 // MEGA2560 Digital Pin 13
  #define STEPPERS_DISABLE_MASK (1<<STEPPERS_DISABLE_BIT)

  // Define homing/hard limit switch input pins and limit interrupt vectors. 
  // NOTE: All limit bit pins must be on the same port
  #define LIMIT_DDR       DDRB
  #define LIMIT_PORT      PORTB
  #define LIMIT_PIN       PINB
  #define X_LIMIT_BIT     4 // MEGA2560 Digital Pin 10
  #define Y_LIMIT_BIT     5 // MEGA2560 Digital Pin 11
  #define Z_LIMIT_BIT     6 // MEGA2560 Digital Pin 12
  #define LIMIT_INT       PCIE0  // Pin change interrupt enable pin
  #define LIMIT_INT_vect  PCINT0_vect 
  #define LIMIT_PCMSK     PCMSK0 // Pin change interrupt register
  #define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits

  // Define spindle enable and spindle direction output pins.
  #define SPINDLE_ENABLE_DDR      DDRH
  #define SPINDLE_ENABLE_PORT     PORTH
  #define SPINDLE_ENABLE_BIT      3 // MEGA2560 Digital Pin 6
  #define SPINDLE_DIRECTION_DDR   DDRE
  #define SPINDLE_DIRECTION_PORT  PORTE
  #define SPINDLE_DIRECTION_BIT   3 // MEGA2560 Digital Pin 5

  // Define flood and mist coolant enable output pins.
  #define COOLANT_FLOOD_DDR   DDRH
  #define COOLANT_FLOOD_PORT  PORTH
  #define COOLANT_FLOOD_BIT   5 // MEGA2560 Digital Pin 8
  #define COOLANT_MIST_DDR    DDRH
  #define COOLANT_MIST_PORT   PORTH
  #define COOLANT_MIST_BIT    6 // MEGA2560 Digital Pin 9

  // Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
  // NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
  #define CONTROL_DDR       DDRK
  #define CONTROL_PIN       PINK
  #define CONTROL_PORT      PORTK
  #define CONTROL_RESET_BIT         0  // MEGA2560 Analog Pin 8
  #define CONTROL_FEED_HOLD_BIT     1  // MEGA2560 Analog Pin 9
  #define CONTROL_CYCLE_START_BIT   2  // MEGA2560 Analog Pin 10
  #define CONTROL_SAFETY_DOOR_BIT   3  // MEGA2560 Analog Pin 11
  #define CONTROL_INT       PCIE2  // Pin change interrupt enable pin
  #define CONTROL_INT_vect  PCINT2_vect
  #define CONTROL_PCMSK     PCMSK2 // Pin change interrupt register
  #define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))

  // Define probe switch input pin.
  #define PROBE_DDR       DDRK
  #define PROBE_PIN       PINK
  #define PROBE_PORT      PORTK
  #define PROBE_BIT       7  // MEGA2560 Analog Pin 15
  #define PROBE_MASK      (1<<PROBE_BIT)

  // Advanced Configuration Below You should not need to touch these variables
  // Set Timer up to use TIMER4B which is attached to Digital Pin 7
  #define SPINDLE_PWM_MAX_VALUE     1024.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
  #ifndef SPINDLE_PWM_MIN_VALUE
    #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
  #endif
  #define SPINDLE_PWM_OFF_VALUE     0
  #define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)
  #define SPINDLE_TCCRA_REGISTER	TCCR4A
  #define SPINDLE_TCCRB_REGISTER	TCCR4B
  #define SPINDLE_OCR_REGISTER	  	OCR4B
  #define SPINDLE_COMB_BIT			COM4B1

  // 1/8 Prescaler, 16-bit Fast PWM mode
  #define SPINDLE_TCCRA_INIT_MASK ((1<<WGM40) | (1<<WGM41))
  #define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41)) 
  #define SPINDLE_OCRA_REGISTER   OCR4A // 16-bit Fast PWM mode requires top reset value stored here.
  #define SPINDLE_OCRA_TOP_VALUE  0x0400// PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

  // Define spindle output pins.
  #define SPINDLE_PWM_DDR		DDRH
  #define SPINDLE_PWM_PORT      PORTH
  #define SPINDLE_PWM_BIT		4 // MEGA2560 Digital Pin 7

#endif


#ifdef CPU_MAP_2560_PIBOT_REV23 // PiBot Rev 2.0-2.3
  #include "nuts_bolts.h"

  // Serial port interrupt vectors
  #define SERIAL_RX USART0_RX_vect
  #define SERIAL_UDRE USART0_UDRE_vect
  
  // Define ports and pins
  #define DDR(port) DDR##port
  #define _DDR(port) DDR(port)
  #define PORT(port) PORT##port
  #define _PORT(port) PORT(port)
  #define PIN(pin) PIN##pin
  #define _PIN(pin) PIN(pin)
  
  // Define step pulse output pins.
  #define STEP_PORT_0 A
  #define STEP_PORT_1 A
  #define STEP_PORT_2 J
  #define STEP_PORT_3 C
  #define STEP_PORT_4 C
  #define STEP_BIT_0 2  // X Step - Pin A2
  #define STEP_BIT_1 5  // Y Step - Pin A5
  #define STEP_BIT_2 0  // Z Step - Pin J0
  #define STEP_BIT_3 5  // A Step - Pin C5
  #define STEP_BIT_4 2  // T Step - Pin C2
  #define _STEP_BIT(i) STEP_BIT_##i
  #define STEP_BIT(i) _STEP_BIT(i)
  #define STEP_DDR(i) _DDR(STEP_PORT_##i)
  #define _STEP_PORT(i) _PORT(STEP_PORT_##i)
  #define STEP_PORT(i) _STEP_PORT(i)
  #define STEP_PIN(i) _PIN(STEP_PORT_##i)

  // Define step direction output pins.
  #define DIRECTION_PORT_0 A
  #define DIRECTION_PORT_1 A
  #define DIRECTION_PORT_2 J
  #define DIRECTION_PORT_3 C
  #define DIRECTION_PORT_4 C
  #define DIRECTION_BIT_0 1 // X Dir - Pin A1
  #define DIRECTION_BIT_1 4 // Y Dir - Pin A4
  #define DIRECTION_BIT_2 1 // Z Dir - Pin J1
  #define DIRECTION_BIT_3 6 // A Dir - Pin C6
  #define DIRECTION_BIT_4 3 // T Dir - Pin C3
  #define _DIRECTION_BIT(i) DIRECTION_BIT_##i
  #define DIRECTION_BIT(i) _DIRECTION_BIT(i)
  #define DIRECTION_DDR(i) _DDR(DIRECTION_PORT_##i)
  #define _DIRECTION_PORT(i) _PORT(DIRECTION_PORT_##i)
  #define DIRECTION_PORT(i) _DIRECTION_PORT(i)
  #define DIRECTION_PIN(i) _PIN(DIRECTION_PORT_##i)

  // Define stepper driver enable/disable output pin.
  #define STEPPER_DISABLE_PORT_0 A
  #define STEPPER_DISABLE_PORT_1 A
  #define STEPPER_DISABLE_PORT_2 G
  #define STEPPER_DISABLE_PORT_3 C
  #define STEPPER_DISABLE_PORT_4 C
  #define STEPPER_DISABLE_BIT_0 0 // X Enable - Pin A0
  #define STEPPER_DISABLE_BIT_1 3 // Y Enable - Pin A3
  #define STEPPER_DISABLE_BIT_2 2 // Z Enable - Pin G2
  #define STEPPER_DISABLE_BIT_3 7 // A Enable - Pin C7
  #define STEPPER_DISABLE_BIT_4 4 // T Enable - Pin C4
  #define STEPPER_DISABLE_BIT(i) STEPPER_DISABLE_BIT_##i
  #define STEPPER_DISABLE_DDR(i) _DDR(STEPPER_DISABLE_PORT_##i)
  #define STEPPER_DISABLE_PORT(i) _PORT(STEPPER_DISABLE_PORT_##i)
  #define STEPPER_DISABLE_PIN(i) _PIN(STEPPER_DISABLE_PORT_##i)

  // Define homing/hard limit switch input pins and limit interrupt vectors. 
  #define MIN_LIMIT_PORT_0 K
  #define MIN_LIMIT_PORT_1 K
  #define MIN_LIMIT_PORT_2 K
  #define MIN_LIMIT_BIT_0 0 // X Limit Min - Pin K0
  #define MIN_LIMIT_BIT_1 2 // Y Limit Min - Pin K2
  #define MIN_LIMIT_BIT_2 4 // Z Limit Min - Pin K4
  #define _MIN_LIMIT_BIT(i) MIN_LIMIT_BIT_##i
  #define MIN_LIMIT_BIT(i) _MIN_LIMIT_BIT(i)
  #define MIN_LIMIT_DDR(i) _DDR(MIN_LIMIT_PORT_##i)
  #define MIN_LIMIT_PORT(i) _PORT(MIN_LIMIT_PORT_##i)
  #define MIN_LIMIT_PIN(i) _PIN(MIN_LIMIT_PORT_##i)

  #define MAX_LIMIT_PORT_0 K
  #define MAX_LIMIT_PORT_1 K
  #define MAX_LIMIT_PORT_2 K
  #define MAX_LIMIT_BIT_0 1 // X Limit Max - Pin K1
  #define MAX_LIMIT_BIT_1 3 // Y Limit Max - Pin K3
  #define MAX_LIMIT_BIT_2 5 // Z Limit Max - Pin K5
  #define _MAX_LIMIT_BIT(i) MAX_LIMIT_BIT_##i
  #define MAX_LIMIT_BIT(i) _MAX_LIMIT_BIT(i)
  #define MAX_LIMIT_DDR(i) _DDR(MAX_LIMIT_PORT_##i)
  #define MAX_LIMIT_PORT(i) _PORT(MAX_LIMIT_PORT_##i)
  #define MAX_LIMIT_PIN(i) _PIN(MAX_LIMIT_PORT_##i)

  //#define LIMIT_INT			PCIE2        // Pin change interrupt enable pin
  //#define LIMIT_INT_vect	    PCINT2_vect 
  //#define LIMIT_PCMSK 		PCMSK2       // Pin change interrupt register

  //#define LIMIT_MASK       ((1<<MIN_LIMIT_BIT_0)|(1<<MIN_LIMIT_BIT_1)|(1<<MIN_LIMIT_BIT_2)|(1<<MAX_LIMIT_BIT_0)|(1<<MAX_LIMIT_BIT_1)|(1<<MAX_LIMIT_BIT_2)) // All limit bits
  #define DISABLE_HW_LIMITS

  // Define spindle enable and spindle direction output pins.
  #define SPINDLE_ENABLE_DDR      DDRL
  #define SPINDLE_ENABLE_PORT     PORTL
  #define SPINDLE_ENABLE_BIT      1 // MEGA2560 Pin L1
  #define SPINDLE_DIRECTION_DDR   DDRL
  #define SPINDLE_DIRECTION_PORT  PORTL
  #define SPINDLE_DIRECTION_BIT   0 // MEGA2560 Pin L0

  // Define flood and mist coolant enable output pins.
  #define COOLANT_FLOOD_DDR   DDRE
  #define COOLANT_FLOOD_PORT  PORTE
  #define COOLANT_FLOOD_BIT   5 // MEGA2560 Digital Pin PE5
  #define COOLANT_MIST_DDR    DDRH
  #define COOLANT_MIST_PORT   PORTH
  #define COOLANT_MIST_BIT    5 // MEGA2560 Digital Pin PH5

  // Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
  // NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
  #define CONTROL_DDR       DDRB
  #define CONTROL_PIN       PINB
  #define CONTROL_PORT      PORTB
  #define CONTROL_RESET_BIT         5  // Pin B5
  #define CONTROL_FEED_HOLD_BIT     7  // Pin B7
  #define CONTROL_CYCLE_START_BIT   6  // Pin B6
  //#define CONTROL_SAFETY_DOOR_BIT   4  // Pin B
  #define CONTROL_INT       PCIE2  // Pin change interrupt enable pin
  #define CONTROL_INT_vect  PCINT2_vect
  #define CONTROL_PCMSK     PCMSK2 // Pin change interrupt register
  //#define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))
  #define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT))

  // Define probe switch input pin.
  #define PROBE_DDR       DDRB
  #define PROBE_PIN       PINB
  #define PROBE_PORT      PORTB
  #define PROBE_BIT       4  // MEGA2560 B4
  #define PROBE_MASK      (1<<PROBE_BIT)

  // Advanced Configuration Below You should not need to touch these variables
  // Set Timer up to use TIMER2B which is attached to Digital Pin 9
  #define SPINDLE_PWM_MAX_VALUE     255.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
  #ifndef SPINDLE_PWM_MIN_VALUE
  #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
  #endif
  #define SPINDLE_PWM_OFF_VALUE     0
  #define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

  //Set Timer up to use TIMER2B which is attached to Digital Pin 9
  #define SPINDLE_TCCRA_REGISTER    TCCR2A
  #define SPINDLE_TCCRB_REGISTER    TCCR2B
  #define SPINDLE_OCR_REGISTER      OCR2B
  #define SPINDLE_COMB_BIT          COM2B1

  // 1/8 Prescaler, 8-bit Fast PWM mode
  #define SPINDLE_TCCRA_INIT_MASK ((1<<WGM20) | (1<<WGM21))
  #define SPINDLE_TCCRB_INIT_MASK ((1<<WGM22) | (1<<CS21)) 
  #define SPINDLE_OCRA_REGISTER   OCR2A // 8-bit Fast PWM mode requires top reset value stored here.
  #define SPINDLE_OCRA_TOP_VALUE  0xFE // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

  // Define spindle output pins.
  #define SPINDLE_PWM_DDR   DDRH
  #define SPINDLE_PWM_PORT  PORTH
  #define SPINDLE_PWM_BIT   6 // MEGA2560 Digital Pin PH6

#endif


/* 
#ifdef CPU_MAP_CUSTOM_PROC
  // For a custom pin map or different processor, copy and edit one of the available cpu
  // map files and modify it to your needs. Make sure the defined name is also changed in
  // the config.h file.
#endif
*/

#endif
