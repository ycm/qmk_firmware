/* ycm's keyboard. hopefully this is the final version.
 * 4/27/2021
 */
#include QMK_KEYBOARD_H
#include "rgb_helpers.h"
#include "key_definitions.h"
#include "arrow_handlers.h"
#include "misc_shortcuts.h"
#include "text_handlers.h"

enum layers {
  _qwerty,
  _symbol,
  _lshort, // and window manager
  _functn, // mouse + media controls
  _keybrd
};

enum custom_keycodes {
  MACRO = SAFE_RANGE
};

static bool lgui_is_pressed = false;
static bool rgui_is_pressed = false;
static bool lctl_is_pressed = false;
bool scln_is_pressed = false;
bool arrow_keys_were_pressed = false;
uint16_t scln_pressed_time;
bool macro_is_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_H:
      return handle_arrow_key(record->event.pressed, KC_H, KC_LEFT, KC_NO);

    case KC_J:
      return handle_arrow_key(record->event.pressed, KC_J, KC_DOWN, KC_NO);

    case KC_K:
      return handle_arrow_key(record->event.pressed, KC_K, KC_UP, KC_NO);

    case KC_L: 
      return handle_arrow_key(record->event.pressed, KC_L, KC_RIGHT, KC_NO);

    case KC_Y:
      return handle_arrow_key(record->event.pressed, KC_Y, KC_LEFT, KC_LGUI);

    case KC_O: 
      if (scln_is_pressed)
        return handle_arrow_key(record->event.pressed, KC_O, KC_RIGHT, KC_LGUI);
      if (macro_is_pressed)
        return handle_shortcut_O(record->event.pressed);
      return true;
    
    case KC_P:
      return handle_shortcut_P(record->event.pressed);
      
    case KC_U:
      return handle_arrow_key(record->event.pressed, KC_U, KC_LEFT, KC_LALT);

    case KC_I: 
      if (scln_is_pressed)
        return handle_arrow_key(record->event.pressed, KC_I, KC_RIGHT, KC_LALT);
      if (macro_is_pressed)
        return handle_text_I(record->event.pressed);
      return true;

    case KC_W:
      return handle_arrow_key(record->event.pressed, KC_W, KC_HOME, KC_NO);

    case KC_A: 
      if (scln_is_pressed)
        return handle_arrow_key(record->event.pressed, KC_A, KC_PGUP, KC_NO);
      if (macro_is_pressed)
        return handle_text_A(record->event.pressed);
      return true;
      
    case KC_S:
      return handle_arrow_key(record->event.pressed, KC_S, KC_END, KC_NO);

    case KC_D:
      return handle_arrow_key(record->event.pressed, KC_D, KC_PGDN, KC_NO);

    case KC_F:
      return handle_text_F(record->event.pressed);

    case KC_E:
      return handle_text_E(record->event.pressed);

    case KC_SCLN:
      return handle_semicolon_key(record->event.pressed);

    case KC_QUOT:
      return handle_text_QUOT(record->event.pressed);

    case KC_LGUI:
      lgui_is_pressed = record->event.pressed;
      return true;

    case KC_RGUI:
      rgui_is_pressed = record->event.pressed;
      return true;

    case KC_LCTL:
      lctl_is_pressed = record->event.pressed;
      return true;

    case MACRO:
      macro_is_pressed = record->event.pressed;
      return false;

    default:
      return true;
  }
}

bool only_default_layer_is_on(void) {
  return !(IS_LAYER_ON(_symbol) ||
      IS_LAYER_ON(_lshort) ||
      IS_LAYER_ON(_functn) ||
      IS_LAYER_ON(_keybrd));
}

void rgb_matrix_indicators_user(void) {
  if (only_default_layer_is_on() && lgui_is_pressed) _lgui_rgb_on();
  if (only_default_layer_is_on() && rgui_is_pressed) _rgui_rgb_on();
  if (only_default_layer_is_on() && lctl_is_pressed) _lctl_rgb_on();
  if (only_default_layer_is_on() && scln_is_pressed) _scln_rgb_on();
  if (only_default_layer_is_on() && macro_is_pressed) _macro_rgb_on();
  if (IS_LAYER_ON(_symbol)) _symbol_rgb_on();
  if (IS_LAYER_ON(_lshort)) _lshort_rgb_on();
  if (IS_LAYER_ON(_functn)) _functn_rgb_on();
  if (IS_LAYER_ON(_keybrd)) _keybrd_rgb_on();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* _qwerty
  * Qwerty and arrows
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | Alt  | GUI  |LShort| Func |    Space    | Symb |Macro | GUI  | Left |Right |
  * `-----------------------------------------------------------------------------------'
  */
[_qwerty] = LAYOUT_planck_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LALT, KC_LGUI, LSHORT,  FUNCTN,  KC_SPC,           SYMBOL,  MACRO,   KC_RGUI, KC_LEFT, KEYBRD
),

 /* _symbol
  * Numbers and symbols
  * ,-----------------------------------------------------------------------------------.
  * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |  `   |      |      |      |      |      |      |  -   |  =   |  [   |  ]   |  \   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |  ^   |  $   |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
[_symbol] = LAYOUT_planck_mit(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_GRV,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, KC_CIRC, KC_DLR,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
),

 /* _lshort
  * Hotkeys
  * ,-----------------------------------------------------------------------------------.
  * |      |  ⌘7  |  ⌘8  |  ⌘9  |      |      |      |      |  NW  |  N   |  NE  | Del  |  
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |  ⌘4  |  ⌘5  |  ⌘6  |      |      |      |LScrn |  W   | Ctr  |  E   |RScrn |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |  ⌘1  |  ⌘2  |  ⌘3  |      |      |      | L2/3 |  SW  |  S   |  SE  | R2/3 |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Lang |      | Lang |      |      |     Max     |      | L1/3 | C1/3 | R1/3 |      |
  * `-----------------------------------------------------------------------------------'
  */
[_lshort] = LAYOUT_planck_mit(
    _______, g_1,     g_2,     g_3,     _______, _______, _______, _______, ca_u,    ca_up,   ca_i,    KC_DEL,
    _______, g_4,     g_5,     g_6,     _______, _______, _______, cag_left,ca_left, ca_c,    ca_rght, cag_rght,
    _______, g_7,     g_8,     g_9,     _______, _______, _______, ca_e,    ca_j,    ca_down, ca_k,    ca_t,
    c_spc,   _______, ca_spc,  _______, _______, ca_ent,           _______, ca_d,    ca_f,    ca_g,    _______
),

/* _functn
 * ,-----------------------------------------------------------------------------------.
 * |      | Ms1  | MsUp | Ms2  | MsWU |      |      | Mute | Vol- | Vol+ |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MsLft | MsDn |MsRgt | MsWD |      |      | Prev | Play | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F4  |  F5  |  F6  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |Brgt- |Brgt+ |  F3  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_functn] = LAYOUT_planck_mit(
    _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_DEL, 
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_BRID, KC_BRIU, KC_F3,   _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Hue- | Hue+ | Spd- | Spd+ |      |      |Debug |Reset |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Sat- | Sat+ |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Val- | Val+ |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RGB- | RGB+ |      |      |      |             |      |      |      |      | RGB  |
 * `-----------------------------------------------------------------------------------'
 */
[_keybrd] = LAYOUT_planck_mit(
    RGB_HUD, RGB_HUI, RGB_SPD, RGB_SPI, _______, _______, DEBUG,   RESET,   _______, _______, _______, _______,
    RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_RMOD,RGB_MOD, _______, _______, _______, RGB_TOG,          _______, _______, _______, _______, _______
)

};