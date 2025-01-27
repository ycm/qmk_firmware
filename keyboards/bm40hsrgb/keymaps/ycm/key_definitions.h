#include QMK_KEYBOARD_H

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
#define LSHORT MO(_lshort)
#define FUNCTN MO(_functn)
#define RSHORT MO(_rshort)
#define KEYBRD MO(_keybrd)