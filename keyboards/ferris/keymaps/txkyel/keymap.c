#include QMK_KEYBOARD_H
#include "txkyel.h"

#define MO_NAV MO(NAV)
#define MO_NUM MO(NUM)
#define SFT_ENT LSFT_T(KC_ENT)

enum layers {
    BASE,
    NUM,
    NAV,
    GAME,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   MO_NUM,  KC_SPC,      SFT_ENT, MO_NAV
    ),

    [NAV] = LAYOUT(
        KC_TAB,  KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_PSCR, KC_HOME, KC_UP,   KC_END,  KC_DEL,
        OS_GUI,  OS_ALT,  OS_SHFT, OS_CTRL, KC_F11,      KC_INS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,      TO(GAME),XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,
                                   _______, _______,     _______, _______
    ),

    [NUM] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        OS_GUI,  OS_ALT,  OS_SHFT, OS_CTRL, KC_PLUS,     KC_MINS, KC_LPRN, KC_EQL,  KC_SCLN, KC_QUOT,
        KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,  KC_ASTR,     KC_SLSH, KC_RPRN, KC_COMM, KC_DOT,  KC_ESC,
                                   _______, _______,     _______, _______
    ),

    [GAME] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,        KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,        KC_G,    KC_M,    KC_N,    KC_E,    KC_I,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,        TO(BASE),KC_K,    KC_H,    KC_COMM, KC_DOT,
                                   _______, _______,     _______, _______
    ),
};

uint16_t oneshot_cancel_keys[] = {
    MO_NAV,
    MO_NUM,
};

uint16_t oneshot_ignore_keys[] = {
    MO_NAV,
    MO_NUM,
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
