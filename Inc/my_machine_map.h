/*
  my_machine_map.h - driver code for STM32F4xx ARM HOP-30 processors

  Part of grblHAL

  Copyright (c) 2020-2021 Terje Io

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

#if TRINAMIC_ENABLE == 2130
#include "trinamic\tmc2130.h"
#endif

#if TRINAMIC_ENABLE == 2209
#include "trinamic\tmc2209.h"
#endif

#if N_ABC_MOTORS > 1
#error "Axis configuration is not supported!"
#endif

#define BOARD_NAME "HOP-30"
#define I2C_PORT 1
#define IS_NUCLEO_BOB
//#define HAS_IOPORTS
#define HAS_BOARD_INIT

//#define SPINDLE_SYNC_ENABLE 1

// Define step pulse output pins.
#define X_STEP_PORT GPIOA
#define X_STEP_PIN 6
#define Y_STEP_PORT GPIOB
#define Y_STEP_PIN 6
#define Z_STEP_PORT GPIOB
#define Z_STEP_PIN 10
#define STEP_OUTMODE GPIO_BITBAND
#define STEP_PINMODE PINMODE_OD // Uncomment for open drain outputs

// Define step direction output pins.
#define X_DIRECTION_PORT GPIOA
#define X_DIRECTION_PIN 7
#define Y_DIRECTION_PORT GPIOA
#define Y_DIRECTION_PIN 9
#define Z_DIRECTION_PORT GPIOB
#define Z_DIRECTION_PIN 4
#define DIRECTION_OUTMODE GPIO_BITBAND
#define DIRECTION_PINMODE PINMODE_OD // Uncomment for open drain outputs

// Define stepper driver enable/disable output pins.

#define X_ENABLE_PORT GPIOB
#define X_ENABLE_PIN 12
#define Y_ENABLE_PORT GPIOC
#define Y_ENABLE_PIN 7
#define Z_ENABLE_PORT GPIOA
#define Z_ENABLE_PIN 8
#define STEPPERS_ENABLE_PINMODE PINMODE_OD // Uncomment for open drain outputs

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT GPIOC
#define X_LIMIT_PIN 10
#define Y_LIMIT_PORT GPIOB
#define Y_LIMIT_PIN 7
#define Z_LIMIT_PORT GPIOC
#define Z_LIMIT_PIN 3
#define LIMIT_INMODE GPIO_BITBAND

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 1
#define M3_AVAILABLE
#define M3_STEP_PORT GPIOB
#define M3_STEP_PIN 8
#define M3_DIRECTION_PORT GPIOB
#define M3_DIRECTION_PIN 9
#define M3_LIMIT_PORT GPIOC
#define M3_LIMIT_PIN 11
#define M3_ENABLE_PORT GPIOB
#define M3_ENABLE_PIN 6
#endif

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT GPIOD
#define SPINDLE_ENABLE_PIN 2
#define SPINDLE_DIRECTION_PORT GPIOC
#define SPINDLE_DIRECTION_PIN 4
#define SPINDLE_DIRECTION_BIT (1 << SPINDLE_DIRECTION_PIN)

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT_BASE GPIOB_BASE
#define SPINDLE_PWM_PIN 0 //1

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT GPIOC
#define COOLANT_FLOOD_PIN 11

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define RESET_PORT GPIOA
#define RESET_PIN 1
#define FEED_HOLD_PORT GPIOA
#define FEED_HOLD_PIN 4
#define CYCLE_START_PORT GPIOB
#define CYCLE_START_PIN 0
#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PORT GPIOC
#define SAFETY_DOOR_PIN 8
#endif
#define CONTROL_INMODE GPIO_BITBAND

// Define probe switch input pin.
#define PROBE_PORT GPIOC
#define PROBE_PIN 0

// Spindle encoder pins.
#if SPINDLE_SYNC_ENABLE

#define SPINDLE_INDEX_PORT GPIOB
#define SPINDLE_INDEX_PIN 14
#define SPINDLE_INDEX_BIT (1 << SPINDLE_INDEX_PIN)

#define SPINDLE_PULSE_PORT GPIOD
#define SPINDLE_PULSE_PIN 2
#define SPINDLE_PULSE_BIT (1 << SPINDLE_PULSE_PIN)

#endif

#if KEYPAD_ENABLE
#define KEYPAD_PORT GPIOB
#define KEYPAD_STROBE_PIN 0
#define KEYPAD_STROBE_BIT (1 << KEYPAD_STROBE_PIN)
#endif

#if SDCARD_ENABLE
#define SD_CS_PORT GPIOC
#define SD_CS_PIN 8
#define SD_CS_BIT (1 << SD_CS_PIN)
#define SPI_PORT 1 // GPIOA, SCK_PIN = 5, MISO_PIN = 6, MOSI_PIN = 7
#endif

#if TRINAMIC_ENABLE
#define SPI_PORT 1 // GPIOA, SCK_PIN = 5, MISO_PIN = 6, MOSI_PIN = 7
#define MOTOR_CS_PORT GPIOB
#define MOTOR_CS_PIN 7
#endif

// EOF

