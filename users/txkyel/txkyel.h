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
#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
#    include "tap_dance.h"
// Tap Dance declarations for use in keymaps
enum hold_ctl_enum {
    HC_BSPC,
    HC_LEFT,
    HC_RGHT,
    HC_DEL,
    HC_WHIT,
};
#endif

#ifdef CALLUM_OS
#    include "callum_oneshot.h"
#endif
