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
#include "txkyel.h"

#ifdef TAP_DANCE_ENABLE
// Default Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [HC_BSPC]  = ACTION_TAP_HOLD_CTL(KC_BSPC),
    [HC_LEFT]  = ACTION_TAP_HOLD_CTL(KC_LEFT),
    [HC_RGHT]  = ACTION_TAP_HOLD_CTL(KC_RGHT),
    [HC_DEL]   = ACTION_TAP_HOLD_CTL(KC_DEL),
    [HC_WHIT] = ACTION_TAP_HOLD(KC_SPC, KC_TAB),
};
#endif
