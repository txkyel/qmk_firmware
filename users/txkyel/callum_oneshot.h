#pragma once
#include "txkyel.h"

// Represents the four states a oneshot key can be in
typedef enum {
    OS_UP_UNQUEUED,
    OS_UP_QUEUED,
    OS_DOWN_UNUSED,
    OS_DOWN_USED,
} oneshot_state;

typedef struct {
    oneshot_state state;
    uint16_t      mod;
    uint16_t      trigger;
} oneshot_action_t;

#    define ACTION_ONESHOT(mod, trigger) \
        { OS_UP_UNQUEUED, mod, trigger, }

/**
 * Custom oneshot mod implementation that doesn't rely on timers. 
 * If a mod is used while it is held it will be unregistered on keyup as normal, 
 * otherwise it will be queued and only released after the next non-mod keyup.
 */
void update_oneshot(oneshot_action_t *action, uint16_t keycode, keyrecord_t *record);

/**
 * Initialization process for Callum oneshot keys.
 * For now this has to be run in matrix_init_user because I can't
 * see another way to making these key options dynamic as possible
 * without  having to hijacking quantum keycodes.
 */
void init_oneshot(void);
bool is_oneshot_cancel_key(uint16_t keycode);
bool is_oneshot_ignored_key(uint16_t keycode);

extern oneshot_action_t oneshot_actions[];
