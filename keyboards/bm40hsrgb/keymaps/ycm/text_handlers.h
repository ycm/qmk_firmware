#include QMK_KEYBOARD_H

extern bool macro_is_pressed;

bool handle_text_A(bool pressed) {
  if (pressed) {
    if (macro_is_pressed) SEND_STRING("\\begin{align*}" SS_TAP(X_ENT) SS_TAP(X_ENT) "\\end{align*}" SS_TAP(X_UP) SS_TAP(X_TAB));
    else register_code(KC_A);
  }
  else unregister_code(KC_A);
  return false;
}

bool handle_text_F(bool pressed) {
  if (pressed) {
    if (macro_is_pressed) SEND_STRING("\\frac{}{}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    else register_code(KC_F);
  }
  else unregister_code(KC_F);
  return false;
}

bool handle_text_E(bool pressed) {
  if (pressed) {
    if (macro_is_pressed) SEND_STRING("\\begin{enumerate}" SS_TAP(X_ENT) SS_TAP(X_ENT) "\\end{enumerate}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
    else register_code(KC_E);
  }
  else unregister_code(KC_E);
  return false;
}

bool handle_text_I(bool pressed) {
  if (pressed) {
    if (macro_is_pressed) SEND_STRING("\\begin{itemize}" SS_TAP(X_ENT) SS_TAP(X_ENT) "\\end{itemize}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
    else register_code(KC_I);
  }
  else unregister_code(KC_I);
  return false;
}

bool handle_text_QUOT(bool pressed) {
  if (pressed) {
    if (macro_is_pressed) SEND_STRING("\\[" SS_TAP(X_ENT) SS_TAP(X_ENT) "\\]" SS_TAP(X_UP) SS_TAP(X_TAB));
    else register_code(KC_QUOT);
  }
  else unregister_code(KC_QUOT);
  return false;
}