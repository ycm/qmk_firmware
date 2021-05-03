#include QMK_KEYBOARD_H

extern bool macro_is_pressed;

bool handle_shortcut_O(bool pressed) {
  if (pressed) {
    if (macro_is_pressed) SEND_STRING(SS_LGUI("-"));
    else register_code(KC_O);
  }
  else unregister_code(KC_O);
  return false;
}

bool handle_shortcut_P(bool pressed) {
  if (pressed) {
    if (macro_is_pressed) SEND_STRING(SS_LGUI("="));
    else register_code(KC_P);
  }
  else unregister_code(KC_P);
  return false;
}
