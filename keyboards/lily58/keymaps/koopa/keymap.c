#include QMK_KEYBOARD_H
#include "process_auto_shift.h"
#include "process_ucis.h"
#include "kaomoji.h"
#include "keymap.h"


enum layer_number {
    _BASE = 0,
    _L_1,
    _L_2,
    _L_N, // numpad layer
    _L_S, // setiings layer
    _L_J, // jump layer
};

#define TD_COLON KC_SCLN

#ifdef TAP_DANCE_ENABLE
#    include "tap_dance.h"
#    undef TD_COLON
#    define TD_COLON TD(DANCE_COLON)
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (layer 0)
 * ,-----------------------------------------------------.                        ,-----------------------------------------------------.
 * | UCIS   |   1    |   2    |   3    |   4    |   5    |                        |    6   |   7    |   8    |   9    |   0    | Numpad |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * |Cps word|   Q    |   W    |   E    |   R    |   T    |                        |    Y   |   U    |   I    |   O    |   P    |        |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * | LCTRL  |   A    |   S    |   D    |   F    |   G    |                        |    H   |   J    |   K    |   L    |   ;    |   '    |
 * |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
 * | LShift |   Z    |   X    |   C    |   V    |   B    |   Esc   |    |  Bspc   |    N   |   M    |   ,    |   .    |   "    | RShift |
 * `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
 *                         |  LAlt  |  LGUI  |  L_1   | /  Space   /    \  Enter/  \  |   L_2  |   L_S  |  RALT  |
 *                         |        |        |        |/          /      \  RShift  \ |        |        |        |
 *                         `-------------------------------------'        '----------''--------------------------'
 */

 [_BASE] = LAYOUT(

 // ,-----------------------------------------------------.                        ,-----------------------------------------------------.
     KC_UCIS ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                           KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,TO(_L_N),
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
     CW_TOGG ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                           KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_NO  ,
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
     KC_LCTL ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                           KC_H  ,  KC_J  ,  KC_K  ,  KC_L  ,TD_COLON,KC_QUOT ,
 // |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
     KC_LSFT ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  , KC_ESC  ,      KC_BSPC ,  KC_N  ,  KC_M  ,KC_COMM , KC_DOT , KC_DQT ,KC_RSFT ,
 // `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
                             KC_LALT ,KC_LGUI , MO(_L_1) ,  KC_SPC  ,      SC_SENT ,    MO(_L_2),MO(_L_S), KC_RALT
 //                         |        |        |        |/          /      \          \ |        |        |        |
 //                         `-------------------------------------'        '----------''--------------------------'
),
/* Layer 1
 * ,-----------------------------------------------------.                        ,-----------------------------------------------------.
 * |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |                        |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * |        |   !    |   @    |   #    |   $    |   %    |                        |   ^    |   &    |   *    |   ~    |        |        |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * | Ctrl   |   <    |   [    |   {    |   (    |   \    |                        |   /    |   )    |   }    |   ]    |   >    |        |
 * |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
 * | Shift  |        |        |   +    |   -    |   |    |         |    |  Del    |   ?    |   _    |   =    |   `    |        |        |
 * `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
 *                         |  LAlt  |        |        | /          /    \   Tab    \  |        |        | RAlt   |
 *                         |        |        |        |/          /      \          \ |        |        |        |
 *                         `-------------------------------------'        '----------''--------------------------'
 */
    #define INC LCTL(KC_EQUAL)
    #define DEC LCTL(KC_MINS)
[_L_1] = LAYOUT(

 // ,-----------------------------------------------------.                        ,-----------------------------------------------------.
       KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,                           KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 , KC_F12 ,
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
       KC_NO ,KC_EXLM ,  KC_AT ,KC_HASH , KC_DLR ,KC_PERC ,                         KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_TILD ,  KC_NO ,   INC  ,
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
     KC_TRNS ,  KC_LT ,KC_LBRC ,KC_LCBR ,KC_LPRN ,KC_BSLS ,                         KC_SLSH ,KC_RPRN ,KC_RCBR ,KC_RBRC ,  KC_GT ,   DEC  ,
 // |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
     KC_TRNS ,  KC_NO ,  KC_NO ,KC_PLUS ,KC_MINS ,KC_PIPE ,   KC_NO ,       KC_DEL ,KC_QUES ,KC_UNDS ,KC_EQUAL, KC_GRV ,  KC_NO ,KC_TRNS ,
 // `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
                              KC_TRNS,  KC_NO , KC_TRNS ,     KC_NO ,       KC_TAB ,      KC_NO ,  KC_NO , KC_TRNS
 //                         |        |        |        |/          /      \          \ |        |        |        |
 //                         `-------------------------------------'        '----------''--------------------------'
),
/* Layer 2
 * ,-----------------------------------------------------.                        ,-----------------------------------------------------.
 * |        |        |        |        |        |        |                        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * |        |        |        |   €    |        |        |                        |        |   ü    |        |   ö    |        |        |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |   ä    |   ß    |        |        |        |                        |   Left |  Down  |   Up   | Right  |        |        |
 * |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
 * | Shift  |   1    |   2    |   3    |   4    |   5    |         |    |         |    6   |   7    |   8    |   9    |   0    | Shift  |
 * `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
 *                         | LAlt   |        |        | /  Space   /    \          \  |        |        |  LAlt  |
 *                         |        |        |        |/          /      \          \ |        |        |        |
 *                         `-------------------------------------'        '----------''--------------------------'
 */

[_L_2] = LAYOUT(
 // ,-----------------------------------------------------.                        ,-----------------------------------------------------.
       KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                           KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
       KC_NO ,  KC_NO ,  KC_NO ,   EUR  ,  KC_NO ,  KC_NO ,                           KC_NO ,   UE   ,  KC_NO ,   OE   ,  KC_NO ,  KC_NO ,
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   AE   ,   SS   ,  KC_NO ,  KC_NO ,  KC_NO ,                          KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT,  KC_NO ,  KC_NO ,
 // |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,   KC_NO ,        KC_NO ,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,KC_TRNS ,
 // `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
                              KC_TRNS,  KC_NO ,  KC_NO ,     KC_SPC ,        KC_NO ,     KC_NO  , KC_NO  , KC_TRNS
 //                         |        |        |        |/          /      \          \ |        |        |        |
 //                         `-------------------------------------'        '----------''--------------------------'
),
/* Numpad layer
 * ,-----------------------------------------------------.                        ,-----------------------------------------------------.
 * |        |        |        |        |        |        |                        |  Num   |        |        |        |        |  BASE  |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                        |   ^    |   7    |   8    |   9    |   =    |        |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                        |   +    |   4    |   5    |   6    |   -    |        |
 * |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |         |    |   Bspc  |   *    |   1    |   2    |   3    |   /    |        |
 * `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
 *                         |        |        |  L_1   | /          /    \   Enter  \  |   0    |   ,    |        |
 *                         |        |        |        |/          /      \          \ |        |        |        |
 *                         `-------------------------------------'        '----------''--------------------------' */

[_L_N] = LAYOUT(
 // ,-----------------------------------------------------.                        ,-----------------------------------------------------.
       KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                          KC_NUM ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,TO(_BASE),
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
       KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                         KC_CIRC , KC_P7  , KC_P8  , KC_P9  ,KC_PEQL ,  KC_NO ,
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
       KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                         KC_PPLS , KC_P4  , KC_P5  , KC_P6  ,KC_PMNS ,  KC_NO ,
 // |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
       KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,   KC_NO ,      KC_BSPC ,KC_PAST , KC_P1  , KC_P2  , KC_P3  ,KC_PSLS ,  KC_NO ,
 // `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
                              KC_NO  ,  KC_NO ,MO(_L_1),     KC_SPC ,      KC_PENT ,      KC_0  ,KC_COMM , KC_NO
 //                         |        |        |        |/          /      \          \ |        |        |        |
 //                         `-------------------------------------'        '----------''--------------------------'
),
/* Settings layer
 * ,-----------------------------------------------------.                        ,-----------------------------------------------------.
 * |        |        |        |        |        |        |                        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                        |  Home  | PgDown |  PgUp  |  End   |        |        |
 * |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | AS Dec  |    | AS Inc  |        |        |        |        |        |        |
 * `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
 *                         |        |        |        | /  Space   /    \AS Toggle \  |        |        |        |
 *                         |        |        |        |/          /      \          \ |        |        |        |
 *                         `-------------------------------------'        '----------''--------------------------'
 */

[_L_S] = LAYOUT(
 // ,-----------------------------------------------------.                        ,-----------------------------------------------------.
       KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                           KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
       KC_NO ,  KC_NO ,  KC_NO , KC_NO  ,  KC_NO ,  KC_NO ,                           KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,
 // |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
       KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                         KC_HOME ,KC_PGDN ,KC_PGUP , KC_END ,  KC_NO ,  KC_NO ,
 // |--------+--------+--------+--------+--------+--------|---------.    ,---------|--------+--------+--------+--------+--------+--------|
       KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO , AS_DOWN ,        AS_UP ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,
 // `-----------------------------------------------------|---------|    |---------|-----------------------------------------------------'
                               KC_NO ,   KC_NO ,   KC_NO ,  AS_TOGG ,        KC_NO ,     KC_NO  ,  KC_NO ,  KC_NO
 //                         |        |        |        |/          /      \          \ |        |        |        |
 //                         `-------------------------------------'        '----------''--------------------------'
),
};

// clang-format on

#ifdef OLED_ENABLE
#    include "bongo_cat.h"
#    include "oled_driver.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void render_default_layer_state(void) {
    oled_clear();
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base"), false);
            break;
        case _L_1:
            oled_write_P(PSTR("L1"), false);
            break;
        case _L_2:
            oled_write_P(PSTR("L2"), false);
            break;
        case _L_N:
            oled_write_P(PSTR("Numpad"), false);
            oled_advance_page(true);
            oled_advance_page(true);
            oled_write_P(PSTR("Numlock: "), false);
            led_t led_state = host_keyboard_led_state();
            oled_write_P(led_state.num_lock ? PSTR("on") : PSTR("off"), false);
            break;
        case _L_S:
            oled_write_P(PSTR("Settings"), false);
            oled_advance_page(true);
            oled_advance_page(true);
            oled_write_P(PSTR("Auto Shift: "), false);
            if (!get_autoshift_state()) {
                oled_write_P(PSTR("off"), false);
            } else {
                oled_write(get_u8_str(get_generic_autoshift_timeout(), ' '), false);
            }
            break;
        case _L_J:
            oled_write_P(PSTR("Jump"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_default_layer_state();
    } else {
        draw_bongo();
    }
    return false;
}

#endif // OLED_ENABLE

// void ucis_start_user(void);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_UCIS:
            if (record->event.pressed) {
                ucis_start();
            }
            return false;
    }
    return true;
}
