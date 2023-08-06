#include QMK_KEYBOARD_H
#include "keymap.h"

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case AE:
        case OE:
        case UE:
            return true;
    }
    return false;
}
