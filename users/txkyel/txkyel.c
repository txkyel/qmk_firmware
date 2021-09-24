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
    [HC_WHIT]  = ACTION_TAP_HOLD(KC_SPC, KC_TAB),
};
#endif

#ifdef CALLUM_OS
enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

uint16_t oneshot_cancel_keys[] = {
    KC_ESC,
};

uint16_t oneshot_ignore_keys[] = {
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

oneshot_action_t oneshot_actions[] = {
    ACTION_ONESHOT(KC_LSFT, OS_SHFT),
    ACTION_ONESHOT(KC_LCTL, OS_CTRL),
    ACTION_ONESHOT(KC_LALT, OS_ALT),
    ACTION_ONESHOT(KC_LGUI, OS_GUI),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    for (int i = 0; i < sizeof(oneshot_cancel_keys) / sizeof(uint16_t); i++) {
        if (keycode == oneshot_cancel_keys[i]) return true;
    }
    return false;
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    for (int i = 0; i < sizeof(oneshot_ignore_keys) / sizeof(uint16_t); i++) {
        if (keycode == oneshot_ignore_keys[i]) return true;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    for (int i = 0; i < sizeof(oneshot_actions) / sizeof(oneshot_action_t); i++) {
        update_oneshot(&oneshot_actions[i], keycode, record);
    }
    return true;
}
#endif
