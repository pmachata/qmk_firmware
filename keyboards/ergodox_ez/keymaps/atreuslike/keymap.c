#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers
#define COMB 3 // all sorts of stuff

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer (Dvorak)
 *
 * ,--------------------------------------------------.      ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|      |------+------+------+------+------+------+--------|
 * |  Esc   |   ,  |   .  |   P  |   Y  |      |      |      |      |      |   F  |   G  |   C  |   R  |   L    |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |   A    |   O  |   E  |   U  |   I  |      |------|      |------|      |   D  |   H  |   T  |   N  |   S    |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |   '    |   Q  |   J  |   K  |   X  |      |      |      |      |      |   B  |   M  |   W  |   V  |   Z    |
 * '--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   | Tab  |      | LGui | BkSp |Space |                                  |RShift| RCtl | RAlt |      | Enter|
 *   '----------------------------------'                                  `----------------------------------'
 *                                        ,-------------.  ,-------------.
 *                                        |      |      |  |      |      |
 *                                 ,------|------|------|  |------+------+------.
 *                                 |      |      |      |  |      |      |      |
 *                                 | SYM  |      |------|  |------|      | NUM  |
 *                                 |      |      |      |  |      |      |      |
 *                                 `--------------------'  `--------------------'
 */

[BASE] = KEYMAP(
        // left hand
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_NO,   KC_NO,
        KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_NO,
        KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_NO,   KC_NO,
        KC_TAB,  KC_NO,   KC_LGUI, KC_BSPC, KC_SPC,
                                                     KC_NO,   KC_NO,
                                                              KC_NO,
                                           MO(SYMB), KC_NO,   KC_NO,

        // right hand
        KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
                  KC_NO,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
        KC_NO,    KC_NO,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
                          KC_RSFT, KC_RCTL, KC_RALT, KC_NO,   KC_ENT,
        KC_NO,    KC_NO,
        KC_NO,
        KC_NO,    KC_NO,  MO(NUMB)
    ),

/* Symbol layer
 *
 * ,--------------------------------------------------.      ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|      |------+------+------+------+------+------+--------|
 * |        |   @  |   {  |   }  |   |  |      |      |      |      |      |   \  |   *  |   -  |   +  |        |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |   #    |   $  |   (  |   )  |   `  |      |------|      |------|      |   =  |   ;  |   :  |   &  |   !    |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |   %    |   ^  |   [  |   ]  |   ~  |      |      |      |      |      |   /  |      |   _  |      |   ?    |
 * '--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   |      |      | ###  |      |      |                                  | ###  | ###  | ###  |      |      |
 *   '----------------------------------'                                  `----------------------------------'
 *                                        ,-------------.  ,-------------.
 *                                        |      |      |  |      |      |
 *                                 ,------|------|------|  |------+------+------.
 *                                 |      |      |      |  |      |      |      |
 *                                 | ###  |      |------|  |------|      | COMB |
 *                                 |      |      |      |  |      |      |      |
 *                                 `--------------------'  `--------------------'
 */

[SYMB] = KEYMAP(
        // left hand
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_NO,   KC_NO,
        KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_NO,
        KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,
                                                     KC_NO,   KC_NO,
                                                              KC_NO,
                                            KC_TRNS, KC_NO,   KC_NO,

        // right hand
        KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,  KC_BSLS, KC_ASTR, KC_MINS, KC_PLUS, KC_NO,
                  KC_NO,  KC_EQL,  KC_SCLN, KC_FN6,  KC_AMPR, KC_EXLM,
        KC_NO,    KC_NO,  KC_SLSH, KC_NO,   KC_FN4,  KC_NO,   KC_FN5,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,
        KC_NO,    KC_NO,
        KC_NO,
        KC_NO,    KC_NO,  MO(COMB)
    ),

/* Numbers layer
 *
 * ,--------------------------------------------------.      ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|      |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |   8    |   7  |   5  |   3  |   1  |      |------|      |------|      |   9  |   0  |   2  |   4  |   6    |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |        |      | Down |  Up  |      |      |      |      |      |      |      | Left | Right|      |        |
 * '--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   |      |      | ###  | Del  |      |                                  | ###  | ###  | ###  |      |      |
 *   '----------------------------------'                                  `----------------------------------'
 *                                        ,-------------.  ,-------------.
 *                                        |      |      |  |      |      |
 *                                 ,------|------|------|  |------+------+------.
 *                                 |      |      |      |  |      |      |      |
 *                                 | COMB |      |------|  |------|      | ###  |
 *                                 |      |      |      |  |      |      |      |
 *                                 `--------------------'  `--------------------'
 */

[NUMB] = KEYMAP(
        // left hand
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_8,    KC_7,    KC_5,    KC_3,    KC_1,    KC_NO,
        KC_NO,   KC_NO,   KC_DOWN, KC_UP,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_TRNS, KC_DELT, KC_NO,
                                                     KC_NO,   KC_NO,
                                                              KC_NO,
                                           MO(COMB), KC_NO,   KC_NO,

        // right hand
        KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,  KC_9,    KC_0,    KC_2,    KC_4,    KC_6,
        KC_NO,    KC_NO,  KC_NO,   KC_LEFT, KC_RGHT, KC_NO,   KC_NO,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,
        KC_NO,    KC_NO,
        KC_NO,
        KC_NO,    KC_NO,  KC_TRNS
    ),

/* Combo layer
 *
 * ,--------------------------------------------------.      ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|      |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |   F8   |  F7  |  F5  |  F3  |  F1  |      |------|      |------|      |  F9  |  F10 |  F2  |  F4  | F6     |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |        |      |      |      |  F11 |      |      |      |      |      |      |      |  F12 |      |        |
 * '--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   |      |      | ###  |      |      |                                  | ###  | ###  | ###  |      |      |
 *   '----------------------------------'                                  `----------------------------------'
 *                                        ,-------------.  ,-------------.
 *                                        |      |      |  |      |      |
 *                                 ,------|------|------|  |------+------+------.
 *                                 |      |      |      |  |      |      |      |
 *                                 | ###  |      |------|  |------|      | ###  |
 *                                 |      |      |      |  |      |      |      |
 *                                 `--------------------'  `--------------------'
 */

[COMB] = KEYMAP(
        // left hand
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_F8,   KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F11,  KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,
                                                     KC_NO,   KC_NO,
                                                              KC_NO,
                                            KC_TRNS, KC_NO,   KC_NO,

        // right hand
        KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,  KC_F9,   KC_F10,  KC_F2,   KC_F4,   KC_F6,
        KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_F12,  KC_NO,   KC_NO,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,
        KC_NO,    KC_NO,
        KC_NO,
        KC_NO,    KC_NO,  KC_TRNS
    ),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),               // FN1 - Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(NUMB),               // FN2 - Layer 2 (Numbers)
    [3] = ACTION_SWAP_HANDS(),                         // FN3 - Momentary swap hands (mirror)
    [4] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),          // FN4 - Underscore
    [5] = ACTION_MODS_KEY(MOD_LSFT, KC_SLSH),          // FN5 - Question mark
    [6] = ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),          // FN6 - Colon
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();

    if (layer & 0x1) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

    if (layer & 0x2) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }
};
