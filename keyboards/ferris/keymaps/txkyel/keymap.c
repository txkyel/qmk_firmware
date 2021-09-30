#include QMK_KEYBOARD_H
#include "txkyel.h"

#define MO_NAV MO(NAV)
#define MO_SYM MO(SYM)

enum layers {
    BASE,
    SYM,
    NAV,
    NUM,
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
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   MO_NAV,  KC_SPC,      KC_LSFT, MO_SYM
    ),

    [NAV] = LAYOUT(
        KC_ESC,  KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_HOME, KC_UP,   KC_END,  KC_DEL,
        OS_GUI,  OS_ALT,  OS_SHFT, OS_CTRL, KC_G,        KC_M,    KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   _______, _______,     _______, _______
    ),

    [SYM] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    OS_CTRL, OS_SHFT, OS_ALT,  OS_GUI,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   _______, _______,     _______, _______
    ),

    [NUM] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   _______, _______,     _______, _______
    ),
};

uint16_t oneshot_cancel_keys[] = {
    MO_NAV,
    MO_SYM,
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
