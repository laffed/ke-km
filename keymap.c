/* Copyright 2023 Alex Stepanov
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,   // default layer
    _KEYPAD, // arrow keys, shifted symbols, HOME, END, PGUP, PGDN, FKeys, CTRL(TAB)
    _NUMPAD  // numpad keys
};

/* ,------------------------------------------------------------------------------------------------------------------------.
* | Esc | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 |                           | F9 | F10 | F11 | F12 |PSCR|SLCK|PAUS|KPAD|BOOT|
* |--------+------+------+------+-------+------+--------------------------------+------+------+------+------+------+--------|
* |   -_   |  1!  |  2@  |  3#  |  4$   |  5%  |                                |  6^  |  7&  |  8*  |  9(  |  0)  |  =+    |
* |--------+------+------+------+-------+------|                                +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R   |   T  |                                |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+-------+------|                                |------+------+------+------+------+--------|
* | Del    |   A  |   S  |   D  |   F   |   G  |                                |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+-------+------|                                |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V   |   B  |                                |   N  |   M  |  ,.  |  .>  |  /?  |Sht/Ent |
* `--------+------+------+------+-------+-------                                `------+------+------+------+------+--------'
*          | `~   | Gui  | Esc  |MO(Num)|                                              | [{   |  ]}  |      |      |
*          `----------------------------'                                              `---------------------------'
*                                        ,---------------.         ,---------------.
*                                        |Alt+Tab|  Alt  |         |  Alt  |TO(Num)|
*                                 ,------|------ |-------|         |-------+-------+------.
*                                 |      |       | Shift |         | Shift |       |      |
*                                 | BkSp | KPAD  |-------|         |------ | KPAD  | Space|
*                                 |      |       | Ctrl  |         | Ctrl  |       |      |
*                                 `----------------------'         `----------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_pretty(
KC_ESC,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,                 KC_F9,KC_F10,KC_F11,KC_F12,KC_PSCR,KC_SCRL,KC_PAUS,KC_NO,QK_BOOT,
KC_EQL,KC_1,KC_2,KC_3,KC_4,KC_5,                                       KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,
KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,                                        KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLS,
KC_LCTL,KC_A,KC_S,KC_D,KC_F,KC_G,                                        KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,
MO(_KEYPAD),KC_Z,KC_X,KC_C,KC_V,KC_B,                                       KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,
KC_NO,KC_GRV,KC_9,KC_0,                                                     KC_LBRC,KC_RBRC, KC_LBRC, KC_RBRC,
                          KC_ESC,KC_LALT,                   KC_F16,KC_RCTL,
                          KC_LGUI,                                KC_DEL,
                          KC_BSPC,KC_LSFT,MO(_KEYPAD),            KC_RGUI,KC_ENT,KC_SPC
),
/* ,------------------------------------------------------------------------------------------------------------------------.
* |   |   |   |   |   |   |   |   |                                              |   |   |   |   |   |   |   | TO(BASE) |   |
* |--------+------+------+------+------+------+---------------------------------+------+------+------+------+------+--------|
* |   _    |   !  |  @   |  #   |  $   |  %   |                                 |  ^   |  &   |  *   |  (   |  )   |   +    |
* |--------+------+------+------+------+------|                                 |------+------+------+------+------+--------|
* |        |  F1  |  F2  |  F3  | F4   |  F5  |                                 |      | Home |  Up  | End  |      |   |    |
* |--------+------+------+------+------+------|                                 |------+------+------+------+------+--------|
* |        |  F6  |  F7  |  F8  | F9   |  F10 |                                 | Pgup | Lft  | Dwn  | Rgt  |  :   |   "    |
* |--------+------+------+------+------+------|                                 |------+------+------+------+------+--------|
* | CapsLk |      |      |      | F11  |  F12 |                                 | Pgdn |      |  <   |  >   |  ?   |        |
* `--------+------+------+------+------+------'                                 `------+------+------+------+------+--------'
*          |   ~  | INS  |      |      |                                               |  {   |  }   |      |      |
*          `---------------------------'                                               `---------------------------'
*                                        ,--------------.         ,--------------------.
*                                        |Ctl+Tab|      |         |      |      |      |
*                                 ,------|------ |------|         |------+------+------.
*                                 |      |       |Shift |         |Shift |      |      |
*                                 |      |       |------|         |------|      |      |
*                                 |      |       | Ctrl |         | Ctrl |      |      |
*                                 `-------------- ------'         `--------------------'
*/
[_KEYPAD] = LAYOUT_pretty(
 KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                 KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
 KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
 KC_TRNS,KC_TRNS,KC_TRNS,KC_9,KC_0,KC_TRNS,                                   KC_TRNS,KC_MINS,KC_BSLS,KC_TRNS,KC_TRNS,KC_TRNS,
 KC_TRNS,KC_TRNS,KC_TRNS,KC_LBRC,KC_RBRC,KC_GRV,                                KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,KC_TRNS,KC_TRNS,
 KC_TRNS,KC_TRNS,KC_TRNS,KC_COMM,KC_DOT,KC_TRNS,                                 KC_TRNS,KC_MUTE,KC_VOLD,KC_VOLU,KC_TRNS,KC_TRNS,
 KC_TRNS,KC_LCTL,KC_NO,KC_NO,                                            KC_MPLY,KC_MPRV,KC_MNXT,KC_TRNS,
                                KC_TRNS,KC_TRNS,             KC_RALT,KC_NO,
                                KC_TRNS,                        KC_TRNS,
                                KC_TRNS,KC_TRNS,KC_TRNS,            KC_TRNS,KC_TRNS,KC_TRNS
),
/*,--------+------+------+------+------+------+                           +------+------+------+------+------+--------.
* |        |      |      |      |      |      |                           |      | Base |  =   |  /   |  *   |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |  7   |  8   |  9   |  -   |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |  Del   |      |      |      |      |      |                           |      |  4   |  5   |  6   |  +   |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |  BkSp  |      |      |      |      |      |                           |      |  1   |  2   |  3   |Enter | Enter  |
* `--------+------+------+------+------+------'                           `------+------+------+------+------+--------'
*          |      |      |      |      |                                         |  .   |Enter |      |      |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        |      |      |         |      | Base |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      |      |         |      |      |      |
*                                 | BkSp |      |------|         |------|      |  0   |
*                                 |      |      |      |         |      |      |      |
*                                 `--------------------'         `--------------------'
*/

[_NUMPAD] = LAYOUT_pretty(
 KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                 KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
 KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                   KC_NO,KC_NO,KC_EQL,KC_SLSH,KC_ASTR,KC_NO,
 KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                   KC_NO,KC_7,KC_8,KC_9,KC_MINS,KC_NO,
 KC_DEL,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                  KC_NO,KC_4,KC_5,KC_6,KC_PLUS,KC_NO,
 KC_BSPC,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                 KC_NO,KC_1,KC_2,KC_3,KC_ENT,KC_ENT,
 KC_NO,KC_NO,KC_NO,KC_NO,                                               KC_DOT,KC_ENT,KC_NO,KC_NO,
                                KC_NO,KC_NO,                  KC_NO,TO(_BASE),
                                KC_NO,                        KC_NO,
                                KC_BSPC,KC_NO,KC_NO,          KC_NO,KC_NO,KC_0
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  //set LEDs which are triggered by a layer change
  #ifdef LED_COMPOSE_PIN
    writePin(LED_COMPOSE_PIN, !layer_state_cmp(state, _KEYPAD));
  #endif

  #ifdef LED_NUM_LOCK_PIN
    writePin(LED_NUM_LOCK_PIN, !layer_state_cmp(state, _NUMPAD));
  #endif

  return state;
};

bool led_update_user(led_t led_state) {
  #ifdef LED_CAPS_LOCK_PIN
    writePin(LED_CAPS_LOCK_PIN, !led_state.caps_lock);
  #endif

  #ifdef LED_SCROLL_LOCK_PIN
    writePin(LED_SCROLL_LOCK_PIN, !led_state.scroll_lock);
  #endif
  
  //disable default processing of LEDs
  return false;
}
