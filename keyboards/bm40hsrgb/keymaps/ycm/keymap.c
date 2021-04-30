/* ycm's keyboard. hopefully this is the final version.
 * 4/27/2021
 */
#include QMK_KEYBOARD_H

enum layers {
  _qwerty,
  _symbol,
  _shrtct, // and window manager
  _functn, // mouse + media controls
  _keybrd
};

enum custom_strings {
  sclnspc
};

#define g_left LGUI(KC_LEFT)
#define a_left LALT(KC_LEFT)
#define g_rght LGUI(KC_RIGHT)
#define a_rght LALT(KC_RIGHT)
#define sg_left SGUI(KC_LEFT)
#define sa_left LSFT(LALT(KC_LEFT))
#define sa_rght LSFT(LALT(KC_RGHT))
#define sg_rght SGUI(KC_RGHT)

#define s_bsls LSFT(KC_BSLS)

#define g_grv LGUI(KC_GRV)
#define c_spc LCTL(KC_SPC)
#define ca_spc LCA(KC_SPC)

#define ca_u LCA(KC_U)
#define ca_up LCA(KC_UP)
#define ca_i LCA(KC_I)
#define ca_left LCA(KC_LEFT)
#define ca_c LCA(KC_C)
#define ca_rght LCA(KC_RGHT)
#define ca_j LCA(KC_J)
#define ca_down LCA(KC_DOWN)
#define ca_k LCA(KC_K)
#define ca_e LCA(KC_E)
#define ca_d LCA(KC_D)
#define ca_f LCA(KC_F)
#define ca_g LCA(KC_G)
#define ca_t LCA(KC_T)
#define ca_ent LCA(KC_ENT)
#define cag_left LCTL(LALT(LGUI(KC_LEFT)))
#define cag_rght LCTL(LALT(LGUI(KC_RGHT)))

#define sg_3 SGUI(KC_3)
#define sg_4 SGUI(KC_4)
#define sg_5 SGUI(KC_5)

#define g_eql LGUI(KC_EQL)
#define g_mins LGUI(KC_MINS)

#define g_1 LGUI(KC_1)
#define g_2 LGUI(KC_2)
#define g_3 LGUI(KC_3)
#define g_4 LGUI(KC_4)
#define g_5 LGUI(KC_5)
#define g_6 LGUI(KC_6)
#define g_7 LGUI(KC_7)
#define g_8 LGUI(KC_8)
#define g_9 LGUI(KC_9)
    
#define SYMBOL MO(_symbol)
#define SHRTCT MO(_shrtct)
#define FUNCTN MO(_functn)

#define RGB_BRGT_PCT 50
void set_rgb(int led_id, int r, int g, int b) {
  int r_adj = (int) ((float) r * 25.5 * RGB_BRGT_PCT / 100);
  int g_adj = (int) ((float) g * 25.5 * RGB_BRGT_PCT / 100);
  int b_adj = (int) ((float) b * 25.5 * RGB_BRGT_PCT / 100);

  rgb_matrix_set_color(led_id, r_adj,  g_adj, b_adj);
}


static bool lgui_is_pressed = false;
static bool lctl_is_pressed = false;
static bool scln_is_pressed = false;
static bool arrow_keys_were_pressed = false;

void press_or_release_key(uint16_t keycode, bool is_pressed) {
  if (is_pressed) register_code(keycode);
  else unregister_code(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case KC_H:
      if (record->event.pressed) {
        if (scln_is_pressed) {
          register_code(KC_LEFT);
          arrow_keys_were_pressed = true;
        }
        else register_code(KC_H);
      }
      else {
        if (scln_is_pressed) unregister_code(KC_LEFT);
        else unregister_code(KC_H);
      }
      return false;

    case KC_J:
      if (record->event.pressed) {
        if (scln_is_pressed) {
          register_code(KC_DOWN);
          arrow_keys_were_pressed = true;
        }
        else register_code(KC_J);
      }
      else {
        if (scln_is_pressed) unregister_code(KC_DOWN);
        else unregister_code(KC_J);
      }
      return false;
    
    case KC_K:
      if (record->event.pressed) {
        if (scln_is_pressed) {
          register_code(KC_UP);
          arrow_keys_were_pressed = true;
        }
        else register_code(KC_K);
      }
      else {
        if (scln_is_pressed) unregister_code(KC_UP);
        else unregister_code(KC_K);
      }
      return false;
    
    case KC_L:
      if (record->event.pressed) {
        if (scln_is_pressed) {
          register_code(KC_RGHT);
          arrow_keys_were_pressed = true;
        }
        else register_code(KC_L);
      }
      else {
        if (scln_is_pressed) unregister_code(KC_RGHT);
        else unregister_code(KC_L);
      }
      return false;

    case KC_SCLN:
      scln_is_pressed = record->event.pressed;
      if (scln_is_pressed) arrow_keys_were_pressed = false;
      else if (!(arrow_keys_were_pressed)) {
        register_code(KC_SCLN);
        unregister_code(KC_SCLN);
      }
      return false;

    case KC_LGUI:
      lgui_is_pressed = record->event.pressed;
      press_or_release_key(KC_LGUI, lgui_is_pressed);
      return false;

    case KC_LCTL:
      lctl_is_pressed = record->event.pressed;
      press_or_release_key(KC_LCTL, lctl_is_pressed);
      return false;

    default:
      return true; // Process all other keycodes normally
  }
}

bool only_default_layer_is_on(void) {
  return !(IS_LAYER_ON(_symbol) ||
      IS_LAYER_ON(_shrtct) ||
      IS_LAYER_ON(_functn) ||
      IS_LAYER_ON(_keybrd));
}

//  0  1  2  3  4  5  6  7  8  9 10 11 
// 12 13 14 15 16 17 18 19 20 21 22 23 
// 24 25 26 27 28 29 30 31 32 33 34 35 
// 36 37 38 39 40  41   42 43 44 45 46 
void rgb_matrix_indicators_user(void) {
  if (only_default_layer_is_on() && lgui_is_pressed) {
    // tab
    set_rgb(0, 0, 7, 9);
    // q
    set_rgb(1, 9, 0, 0);
    // w
    set_rgb(2, 9, 0, 0);
    // r
    set_rgb(4, 9, 3, 0);
    // t
    set_rgb(5, 0, 7, 9);
    // u
    set_rgb(7, 9, 5, 0);
    // i
    set_rgb(8, 9, 5, 0);
    // o
    set_rgb(9, 1, 9, 1);
    // a
    set_rgb(13, 0, 7, 9);
    // s
    set_rgb(14, 1, 9, 1);
    // f
    set_rgb(16, 1, 9, 1);
    // h
    set_rgb(18, 0, 7, 9);
    // k
    set_rgb(18, 1, 9, 1);
    // l
    set_rgb(18, 0, 7, 9);
    // z
    set_rgb(25, 9, 3, 0);
    // x
    set_rgb(26, 9, 3, 0);
    // c
    set_rgb(27, 9, 3, 0);
    // v
    set_rgb(28, 9, 3, 0);
    // b
    set_rgb(29, 9, 5, 0);
    // n
    set_rgb(30, 0, 7, 9);
  }
  
  if (only_default_layer_is_on() && lctl_is_pressed) {
    for (int i = 0; i <= 11; i++) {
      set_rgb(i, 9, 1, 1);
      if (i % 2 == 0)
        set_rgb(i, 1, 9, 1);
    }
    for (int i = 12; i <= 23; i++) {
      set_rgb(i, 1, 9, 1);
      if (i % 2 == 0)
        set_rgb(i, 9, 1, 1);
    }
    for (int i = 24; i <= 35; i++) {
      set_rgb(i, 9, 1, 1);
      if (i % 2 == 0)
        set_rgb(i, 1, 9, 1);
    }
    for (int i = 36; i <= 41; i++) {
      set_rgb(i, 1, 9, 1);
      if (i % 2 == 0)
        set_rgb(i, 9, 1, 1);
    }
    for (int i = 42; i <= 46; i++) {
      set_rgb(i, 9, 1, 1);
      if (i % 2 == 0)
        set_rgb(i, 1, 9, 1);
    }
  }

  if (only_default_layer_is_on() && scln_is_pressed) {
    for (int i = 18; i <= 21; i++) {
      set_rgb(i, 9, 9, 9);
    }
  }

  if (IS_LAYER_ON(_symbol)) {
    // numpad
    set_rgb(39, 0, 7, 9);
    for (int i = 1; i <= 3; i++) {
      set_rgb(i, 0, 7, 9);
      set_rgb(i + 12, 0, 7, 9);
      set_rgb(i + 24, 0, 7, 9);
    }

    // parens + braces
    set_rgb(7, 9, 4, 0);
    set_rgb(8, 9, 4, 0);
    set_rgb(21, 9, 4, 0);
    set_rgb(22, 9, 4, 0);
    set_rgb(30, 9, 4, 0);
    set_rgb(31, 9, 4, 0);

    // other latex/markdown/programming symbols
    set_rgb(18, 9, 1, 1);
    set_rgb(20, 9, 1, 1);
    set_rgb(19, 1, 9, 1);
    set_rgb(6, 0, 7, 9);
    set_rgb(12, 0, 7, 9);

  }

  if (IS_LAYER_ON(_shrtct)) {
    // cmd + numbers
    for (int i = 1; i <= 3; i++) {
      set_rgb(i, 9, 2, 2);
      set_rgb(i + 12, 9, 2, 2);
      set_rgb(i + 24, 9, 2, 2);
    }

    // language switch
    set_rgb(36, 8, 4, 0);
    set_rgb(38, 8, 4, 0);

    // window mgmt
    for (int i = 8; i <= 10; i++) {
      set_rgb(i, 10, 10, 10);
      set_rgb(i + 12, 10, 10, 10);
      set_rgb(i + 24, 10, 10, 10);
      set_rgb(i + 35, 10, 10, 10);
    }
    set_rgb(41, 9, 2, 0);
    set_rgb(21, 9, 2, 0);
    set_rgb(19, 10, 10, 10);
    set_rgb(23, 10, 10, 10);
    set_rgb(31, 10, 10, 10);
    set_rgb(35, 10, 10, 10);

    //delete key
    set_rgb(11, 9, 2, 0);
  }

  if (IS_LAYER_ON(_functn)) {

    // function keys
    for (int i = 7; i <= 9; i++) {
      set_rgb(i, 6, 0, 9);
      set_rgb(i + 12, 6, 3, 9);
      set_rgb(i + 24, 6, 3, 9);
      set_rgb(i + 36, 6, 3, 9);
    }

    // mouse
    set_rgb(2, 9, 9, 9);
    set_rgb(13, 9, 9, 9);
    set_rgb(14, 9, 9, 9);
    set_rgb(15, 9, 9, 9);
    set_rgb(1, 9, 4, 0);
    set_rgb(3, 9, 4, 0);
    set_rgb(4, 9, 4, 0);
    set_rgb(16, 9, 4, 0);

    //delete key
    set_rgb(11, 9, 2, 0);
  }

  if (IS_LAYER_ON(_keybrd)) {
    rgb_matrix_set_color_all(0, 0, 0);
    set_rgb(6, 10, 0, 0);
    set_rgb(7, 10, 0, 0);

    for (int i = 0; i <= 1; i++) {
      set_rgb(i, 10, 0, 0);
      set_rgb(i + 12, 10, 0, 0);
      set_rgb(i + 24, 10, 0, 0);
      set_rgb(i + 36, 10, 0, 0);
    }
    set_rgb(2, 10, 0, 0);
    set_rgb(3, 10, 0, 0);
    set_rgb(46, 10, 0, 0);
  }
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
  * | Ctrl | Alt  | GUI  |Short | Func |    Space    | Symb | Left | Down |  Up  |Right |
  * `-----------------------------------------------------------------------------------'
  */
[_qwerty] = LAYOUT_planck_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LALT, KC_LGUI, SHRTCT,  FUNCTN,  KC_SPC,           SYMBOL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

 /* _symbol
  * Numbers and symbols
  * ,-----------------------------------------------------------------------------------.
  * |      |  7   |  8   |  9   |      |      |  #   |  (   |  )   |  -   |  =   |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |  `   |  4   |  5   |  6   |      |      |  ^   |  $   |  *   |  [   |  ]   |  \   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |  1   |  2   |  3   |      |      |  <   |  >   |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |  0   |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
[_symbol] = LAYOUT_planck_mit(
    _______, KC_1,    KC_2,    KC_3,    _______, _______, KC_HASH, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  _______,
    KC_GRV,  KC_4,    KC_5,    KC_6,    _______, _______, KC_CIRC, KC_DLR,  KC_ASTR, KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_7,    KC_8,    KC_9,    _______, _______, KC_LT,   KC_GT,   _______, _______, _______, _______,
    _______, _______, _______, KC_0,    _______, _______,          _______, _______, _______, _______, _______
),

 /* _shrtct
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
[_shrtct] = LAYOUT_planck_mit(
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
    RGB_RMOD,RGB_MOD, _______, _______, _______, _______,          _______, _______, _______, _______, RGB_TOG
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _symbol, _functn, _keybrd);
}

