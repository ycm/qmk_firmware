#include QMK_KEYBOARD_H

#define RGB_BRGT_PCT 50

//  0  1  2  3  4  5  6  7  8  9 10 11 
// 12 13 14 15 16 17 18 19 20 21 22 23 
// 24 25 26 27 28 29 30 31 32 33 34 35 
// 36 37 38 39 40  41   42 43 44 45 46 
void set_rgb(int led_id, int r, int g, int b) {
  int r_adj = (int) ((float) r * 25.5 * RGB_BRGT_PCT / 100);
  int g_adj = (int) ((float) g * 25.5 * RGB_BRGT_PCT / 100);
  int b_adj = (int) ((float) b * 25.5 * RGB_BRGT_PCT / 100);

  rgb_matrix_set_color(led_id, r_adj,  g_adj, b_adj);
}

void _lctl_rgb_on(void) {
  for (int i = 0; i <= 11; i++)
    set_rgb(i, 10, 10, 0);
  for (int i = 12; i <= 23; i++)
    set_rgb(i, 10, 5, 1);
  for (int i = 24; i <= 35; i++)
    set_rgb(i, 8, 1, 1);
  for (int i = 36; i <= 46; i++)
    set_rgb(i, 10, 2, 10);
}

void _lgui_rgb_on(void) {
  set_rgb(1, 9, 0, 0); // q
  set_rgb(2, 9, 0, 0); // w
  set_rgb(5, 0, 7, 9); // t
  set_rgb(14, 1, 9, 1); // s
  set_rgb(30, 0, 7, 9); // n
}

void _rgui_rgb_on(void) {
  set_rgb(9, 9, 4, 0);  // o
  set_rgb(10, 9, 4, 0); // p
  set_rgb(21, 0, 7, 9); // l
  set_rgb(34, 1, 9, 1); // /
}

void _scln_rgb_on(void) {
  for (int i = 6; i <= 9; i++) {
    set_rgb(i, 9, 9, 9);
    set_rgb(i + 12, 9, 9, 9);
  }
  set_rgb(2, 9, 9, 9);
  set_rgb(13, 9, 9, 9);
  set_rgb(14, 9, 9, 9);
  set_rgb(15, 9, 9, 9);
}

void _symbol_rgb_on(void) {
  // numpad
  set_rgb(40, 0, 7, 9);
  for (int i = 2; i <= 4; i++) {;;
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
  set_rgb(1, 0, 7, 9);
}

void _lshort_rgb_on(void) {
  // cmd + numbers
  for (int i = 2; i <= 4; i++) {
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

void _rshort_rgb_on(void) {
  set_rgb(9, 0, 7, 9);
  set_rgb(10, 0, 7, 9);
}

void _functn_rgb_on(void) {
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

void _keybrd_rgb_on(void) {
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
  set_rgb(41, 10, 0, 0);
}