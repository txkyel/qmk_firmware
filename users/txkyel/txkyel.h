/* Copyright 2021 Kyle Xiao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include "quantum.h"
#include "tap_dance.h"

#ifdef TAP_DANCE_ENABLE
// Tap Dance declarations for use in keymaps
enum hold_ctl_enum {
    HC_BSPC,
    HC_LEFT,
    HC_RGHT,
    TH_TAB_DEL,
};
#endif

#ifdef MOUSEKEY_ENABLE
#    define MOUSEKEY_INTERVAL 16
#    define MOUSEKEY_DELAY 0
#    define MOUSEKEY_TIME_TO_MAX 60
#    define MOUSEKEY_MAX_SPEED 7
#    define MOUSEKEY_WHEEL_DELAY 0
#endif