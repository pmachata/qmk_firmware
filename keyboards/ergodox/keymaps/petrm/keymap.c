#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define QWER 1 // QWERTY layout
#define SYMB 2 // symbols
#define MDIA 3 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  DF_QWER,
  DF_BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer (Dvorak)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |   7  |   5  |   3  |   1  | QWER |           |      |   9  |   0  |   2  |   4  |   6  |   8    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   :  |   ,  |   .  |   P  |   Y  | Tab  |           | Tab  |   F  |   G  |   C  |   R  |   L  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Mirror |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |        |
 * |--------+------+------+------+------+------| Del  |           | BkSp |------+------+------+------+------+--------|
 * | LShift |   '  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------|
 *   |  `   |      | MDIA | Left | Right|                                       |  Up  | Down |      |      |        |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Alt  | LGui |       | App  | Ctrl |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space| SYM  |------|       |------| Esc  |Enter |
 *                                 |      |      | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */

[BASE] = KEYMAP(
        // left hand
        KC_NO,   KC_NO,    KC_7,    KC_5,    KC_3,   KC_1,  DF_QWER,
        KC_NO,   KC_SCLN,  KC_COMM, KC_DOT,  KC_P,   KC_Y,  KC_TAB,
        KC_FN3,  KC_A,     KC_O,    KC_E,    KC_U,   KC_I,
        KC_LSFT, KC_QUOT,  KC_Q,    KC_J,    KC_K,   KC_X,  KC_DELT,
        KC_GRV,  KC_NO,    KC_FN2,  KC_LEFT, KC_RGHT,
                                                    KC_LALT,  KC_LGUI,
                                                              KC_HOME,
                                            KC_SPC, MO(SYMB), KC_END,

        // right hand
        KC_NO,    KC_9, KC_0,  KC_2,    KC_4,    KC_6,   KC_8,
        KC_TAB,   KC_F, KC_G,  KC_C,    KC_R,    KC_L,   KC_NO,
                  KC_D, KC_H,  KC_T,    KC_N,    KC_S,   KC_NO,
        KC_BSPC,  KC_B, KC_M,  KC_W,    KC_V,    KC_Z,   KC_RSFT,
                        KC_UP, KC_DOWN, KC_NO,   KC_NO,  KC_NO,
        ALT_T(KC_APP), KC_RCTL,
        KC_PGUP,
        KC_PGDN, KC_ESC, KC_ENT
    ),

/* QWERTY layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------|
 *   |Grv   |  '"  |      | Left | Right|                                       |  Up  | Down |   [  |   ]  |        |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWER] = KEYMAP(
        // left hand
        KC_EQL,    KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   DF_BASE,
        KC_TRNS,   KC_Q,       KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_TRNS,   KC_A,       KC_S,   KC_D,   KC_F,   KC_G,
        KC_TRNS,   KC_Z,       KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_GRV,    KC_QUOT,    KC_FN2, KC_LEFT,KC_RGHT,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
        KC_TRNS,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,    KC_MINS,
        KC_TRNS,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,    KC_BSLS,
                     KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN, KC_TRNS,
        KC_TRNS,     KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH, KC_TRNS,
                             KC_UP, KC_DOWN,KC_LBRC,KC_RBRC, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |      |  F7  |  F5  |  F3  |  F1  |  F11 |           |  F12 |  F9  |  F10 |  F2  |  F4  |  F6  |   F8   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   @  |   {  |   }  |   |  |      |           |      |  \   |   *  |   -  |   +  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------|  =   |   [  |   ]  |   &  |   !  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |      |      |   ~  |      |           |      |  /   |      |   _  |      |   ?  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = KEYMAP(
       // left hand
       VRSN,    KC_TRNS, KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F11,
       KC_TRNS, KC_TRNS, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
       KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
       KC_TRNS, KC_PERC, KC_CIRC, KC_TRNS, KC_TRNS, KC_TILD, KC_TRNS,
          EPRM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_F12,  KC_F9,   KC_F10,  KC_F2,   KC_F4,   KC_F6,   KC_F8,
       KC_TRNS, KC_BSLS, KC_ASTR, KC_MINS, KC_PLUS, KC_TRNS, KC_TRNS,
                KC_EQL,  KC_LBRC, KC_RBRC, KC_AMPR, KC_EXLM, KC_TRNS,
       KC_TRNS, KC_SLSH, KC_TRNS, KC_FN4,  KC_TRNS, KC_FN5,  KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |MsLeft|MsRght|                                       | MsUp |MsDown| Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Left  |      |      |       |WhUp  |Middle|Right |
 *                                 |Button|      |------|       |------|Button|Button|
 *                                 |      |      |      |       |WhDown|      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_R,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_MS_U, KC_MS_D, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_MS_WH_UP,
       KC_MS_WH_DOWN, KC_BTN3, KC_BTN2
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),               // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA),               // FN2 - Momentary Layer 2 (Media)
    [3] = ACTION_SWAP_HANDS(),                         // FN3 - Momentary swap hands (mirror)
    [4] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),          // FN4 - Underscore
    [5] = ACTION_MODS_KEY(MOD_LSFT, KC_SLSH),          // FN5 - Question mark
};
static bool blue_led = false;

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;

    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;

  case DF_QWER:
      if (record->event.pressed) {
          blue_led = true;
          default_layer_set(1UL << QWER);
      }
      return false;

  case DF_BASE:
      if (record->event.pressed) {
          blue_led = false;
          default_layer_set(1UL << BASE);
      }
      return false;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

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

    if (blue_led) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
};
