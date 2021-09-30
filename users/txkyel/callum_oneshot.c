#include "quantum.h"
#include "callum_oneshot.h"

static inline void _update_oneshot_trigger(oneshot_action_t *action, keyrecord_t *record) {
    if (record->event.pressed) {
        // Trigger keydown
        if (action->state == OS_UP_UNQUEUED) {
            register_code(action->mod);
        }
        action->state = OS_DOWN_UNUSED;
    } else {
        // Trigger keyup
        switch (action->state) {
            case OS_DOWN_UNUSED:
                // If we didn't use the mod while trigger was held, queue it.
                action->state = OS_UP_QUEUED;
                break;
            case OS_DOWN_USED:
                // If we did use the mod while trigger was held, unregister it.
                action->state = OS_UP_UNQUEUED;
                unregister_code(action->mod);
                break;
            default:
                break;
        }
    }
}

static inline void _update_oneshot_no_trigger(oneshot_action_t *action, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_oneshot_cancel_key(keycode) && action->state != OS_UP_UNQUEUED) {
            // Cancel oneshot on designated cancel keydown.
            action->state = OS_UP_UNQUEUED;
            unregister_code(action->mod);
        }
    } else {
        if (!is_oneshot_ignored_key(keycode)) {
            // On non-ignored keyup, consider the oneshot used.
            switch (action->state) {
                case OS_DOWN_UNUSED:
                    action->state = OS_DOWN_USED;
                    break;
                case OS_UP_QUEUED:
                    action->state = OS_UP_UNQUEUED;
                    unregister_code(action->mod);
                    break;
                default:
                    break;
            }
        }
    }
}

void update_oneshot(oneshot_action_t *action, uint16_t keycode, keyrecord_t *record) {
    if (keycode == action->trigger) {
        _update_oneshot_trigger(action, record);
    } else {
        _update_oneshot_no_trigger(action, keycode, record);
    }
}
