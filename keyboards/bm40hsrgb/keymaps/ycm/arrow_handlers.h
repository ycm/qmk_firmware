#include QMK_KEYBOARD_H

extern bool scln_is_pressed;
extern bool arrow_keys_were_pressed;
extern uint16_t scln_pressed_time;

#define SCLN_HOLD_TIMEOUT_MS 500

bool handle_arrow_key(bool pressed,
                      uint16_t regular_key,
                      uint16_t arrow_key,
                      uint16_t modifier_key) {
  if (pressed) {
    if (scln_is_pressed) {
      register_code(modifier_key);
      register_code(arrow_key);
      arrow_keys_were_pressed = true;
    }
    else register_code(regular_key);
  }
  else {
    unregister_code(modifier_key);
    unregister_code(arrow_key);
    unregister_code(regular_key);
  }
  return false;
}

bool handle_semicolon_key(bool pressed) {
  scln_is_pressed = pressed;
  if (scln_is_pressed) {
    scln_pressed_time = timer_read();
    arrow_keys_were_pressed = false;
  }
  else if (!(arrow_keys_were_pressed) &&
            (timer_read() - scln_pressed_time < SCLN_HOLD_TIMEOUT_MS)) {
    register_code(KC_SCLN);
    unregister_code(KC_SCLN);
  }
  return false;
}