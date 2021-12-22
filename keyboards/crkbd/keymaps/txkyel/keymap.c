/*
Copyright 2019 @foostan
Copyright 2021 Kyle Xiao @txkyel

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

#include QMK_KEYBOARD_H
#include "txkyel.h"

#define MO_NAV MO(NAV)
#define MO_NUM MO(NUM)

#define CT_BSPC TD(HC_BSPC)
#define CT_LEFT TD(HC_LEFT)
#define CT_RGHT TD(HC_RGHT)

enum layers {
    BASE,
    NUM,
    NAV,
    MBTN,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_ENT, MO_NUM, KC_SPC, KC_LSFT, MO_NAV, KC_ESC
        //`--------------------------'  `--------------------------'
        ),

    [NUM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, OS_GUI, OS_ALT, OS_SHFT, OS_CTRL, KC_EQL, KC_MINS, KC_LPRN, KC_LBRC, KC_BSLS, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV, KC_PLUS, KC_UNDS, KC_RPRN, KC_RBRC, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______
        //`--------------------------'  `--------------------------'
        ),

    [NAV] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_PSCR, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_DEL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, OS_GUI, OS_ALT, OS_SHFT, OS_CTRL, XXXXXXX, CT_LEFT, KC_DOWN, KC_UP, CT_RGHT, XXXXXXX, KC_ENT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______
        //`--------------------------'  `--------------------------'
        ),

    [MBTN] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______
        //`--------------------------'  `--------------------------'
        )};

uint16_t oneshot_cancel_keys[] = {
    MO_NAV,
    MO_NUM,
};

uint16_t oneshot_ignore_keys[] = {
    MO_NAV, MO_NUM, OS_SHFT, OS_CTRL, OS_ALT, OS_GUI,
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

// Copied from https://github.com/manna-harbour/qmk_firmware/blob/crkbd/keyboards/crkbd/keymaps/manna-harbour/readme.org
#if defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE

static uint16_t mh_auto_buttons_timer;
extern int      tp_buttons;  // mousekey button state set in action.c and used in ps2_mouse.c

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
    if (mh_auto_buttons_timer) {
        mh_auto_buttons_timer = timer_read();
    } else {
        if (!tp_buttons) {
            layer_on(MBTN);
            mh_auto_buttons_timer = timer_read();
#    if defined CONSOLE_ENABLE
            print("mh_auto_buttons: on\n");
#    endif
        }
    }
}

void matrix_scan_user(void) {
    if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > MH_AUTO_BUTTONS_TIMEOUT)) {
        if (!tp_buttons) {
            layer_off(MBTN);
            mh_auto_buttons_timer = 0;
#    if defined CONSOLE_ENABLE
            print("mh_auto_buttons: off\n");
#    endif
        }
    }
}

#endif