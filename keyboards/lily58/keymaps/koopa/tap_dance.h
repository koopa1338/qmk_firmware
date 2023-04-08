#pragma once
#include QMK_KEYBOARD_H

enum {
    TD_SINGLE_TAP        = 1,
    TD_SINGLE_HOLD       = 2,
    TD_DOUBLE_TAP        = 3,
    TD_DOUBLE_HOLD       = 4,
    TD_DOUBLE_SINGLE_TAP = 5, // send two single taps
    TD_TRIPLE_TAP        = 6,
    TD_TRIPLE_HOLD       = 7,
};

typedef struct {
    bool is_press_action;
    int  state;
} dancestep;

int current_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return TD_SINGLE_TAP;
        } else {
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted) {
            return TD_DOUBLE_SINGLE_TAP;
        } else if (state->pressed) {
            return TD_DOUBLE_HOLD;
        } else {
            return TD_DOUBLE_TAP;
        }
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) {
            return TD_TRIPLE_TAP;
        } else {
            return TD_TRIPLE_HOLD;
        }
    }

    return 8;
}

static dancestep dance_colon = {.is_press_action = true, .state = 0};

void dance_colon_finished(tap_dance_state_t *state, void *user_data) {
    dance_colon.state = current_dance(state);
    switch (dance_colon.state) {
        case TD_SINGLE_TAP:
            register_code(KC_SCLN);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_RSFT);
            register_code(KC_SCLN);
            unregister_code(KC_RSFT);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_RSFT);
            register_code(KC_SCLN);
            unregister_code(KC_SCLN);
            register_code(KC_SCLN);
            unregister_code(KC_RSFT);
            break;
    }
}
void dance_colon_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count <= 2) {
        unregister_code(KC_SCLN);
    }
}

enum { DANCE_COLON = 0 };

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_colon_finished, dance_colon_reset),
};
