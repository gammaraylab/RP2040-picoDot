/*
  generic_map.h - driver code for RP2040 ARM processors

  Part of grblHAL

  Copyright (c) 2021-2025 Terje Io
  Copyright (c) 2021 Volksolive

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS
#error "Axis configuration is not supported!"
#endif

// Define step pulse output pins.
#define STEP_PORT               GPIO_PIO  // N_AXIS pin PIO SM
// x, y, z pins are 2,3 & 4
#define STEP_PINS_BASE          2         // N_AXIS number of consecutive pins are used by PIO
// Define step direction output pins.
#define DIRECTION_PORT          GPIO_OUTPUT
#define X_DIRECTION_PIN         5
#define Y_DIRECTION_PIN         6
#define Z_DIRECTION_PIN         7
#define DIRECTION_OUTMODE       GPIO_SHIFT5

// Define stepper driver enable/disable output pin.
#define ENABLE_PORT             GPIO_OUTPUT
#define STEPPERS_ENABLE_PIN     8

// Define homing/hard limit switch input pins.;
#define X_LIMIT_PIN             9
#define Y_LIMIT_PIN             10
#define Z_LIMIT_PIN             11
#define LIMIT_INMODE            GPIO_MAP

// Define auxiliary I/O
#define AUXINPUT0_PIN           22  //motor fault
#define AUXINPUT1_PIN           21
#define AUXINPUT2_PIN           28 // Probe

#define AUXOUTPUT0_PORT         GPIO_OUTPUT
#define AUXOUTPUT0_PIN          12
#define AUXOUTPUT1_PORT         GPIO_OUTPUT
#define AUXOUTPUT1_PIN          26
//#define AUXOUTPUT2_PORT         GPIO_OUTPUT
//#define AUXOUTPUT2_PIN          27
#define AUXOUTPUT3_PORT         GPIO_OUTPUT // Spindle PWM
#define AUXOUTPUT3_PIN          15
#define AUXOUTPUT4_PORT         GPIO_OUTPUT // Spindle direction
#define AUXOUTPUT4_PIN          14
#define AUXOUTPUT5_PORT         GPIO_OUTPUT // Spindle enable
#define AUXOUTPUT5_PIN          13   
#define AUXOUTPUT6_PORT         GPIO_OUTPUT // Coolant flood
#define AUXOUTPUT6_PIN          16   
#define AUXOUTPUT7_PORT         GPIO_OUTPUT // Coolant mist
#define AUXOUTPUT7_PIN          17   

// Define driver spindle pins
#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_PORT            GPIO_OUTPUT
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_PWM
#define SPINDLE_PWM_PIN         AUXOUTPUT3_PIN
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_DIR
#define SPINDLE_DIRECTION_PIN   AUXOUTPUT4_PIN
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_ENA   
#define SPINDLE_ENABLE_PIN      AUXOUTPUT5_PIN
#endif

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define RESET_PIN               18
#define FEED_HOLD_PIN           19
#define CYCLE_START_PIN         20

#if PROBE_ENABLE
#define PROBE_PIN               AUXINPUT2_PIN
#endif

#if MOTOR_FAULT_ENABLE
#define MOTOR_FAULT_PIN         AUXINPUT0_PIN
#endif
