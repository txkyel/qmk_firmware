/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD

#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
#    define RGBLIGHT_ANIMATIONS
#    define RGBLED_NUM 54
#    undef RGBLED_SPLIT
#    define RGBLED_SPLIT \
        { 27, 27 }
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP  10
#    define RGBLIGHT_SAT_STEP  17
#    define RGBLIGHT_VAL_STEP  17
#endif

// Rotate mouse
#ifdef PS2_MOUSE_ENABLE
#    define PS2_MOUSE_ROTATE 270
#endif

// Taken from https://github.com/joric/jorne/wiki/Trackpoint
#ifdef PS2_USE_BUSYWAIT
#    define PS2_CLOCK_PORT PORTD
#    define PS2_CLOCK_PIN PIND
#    define PS2_CLOCK_DDR DDRD
#    define PS2_CLOCK_BIT 0
#    define PS2_DATA_PORT PORTD
#    define PS2_DATA_PIN PIND
#    define PS2_DATA_DDR DDRD
#    define PS2_DATA_BIT 1
#endif

// Taken from https://github.com/manna-harbour/qmk_firmware/blob/crkbd/keyboards/crkbd/keymaps/manna-harbour/readme.org
#ifdef PS2_USE_INT
#    define PS2_CLOCK_PORT PORTD
#    define PS2_CLOCK_PIN PIND
#    define PS2_CLOCK_DDR DDRD
#    define PS2_CLOCK_BIT 2
#    define PS2_DATA_PORT PORTD
#    define PS2_DATA_PIN PIND
#    define PS2_DATA_DDR DDRD
#    define PS2_DATA_BIT 5

#    define PS2_INT_INIT()                          \
        do {                                        \
            EICRA |= ((1 << ISC01) | (0 << ISC00)); \
        } while (0)
#    define PS2_INT_ON()          \
        do {                      \
            EIMSK |= (1 << INT0); \
        } while (0)
#    define PS2_INT_OFF()          \
        do {                       \
            EIMSK &= ~(1 << INT0); \
        } while (0)
#    define PS2_INT_VECT INT0_vect
#endif