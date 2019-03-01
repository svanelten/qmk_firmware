#include QMK_KEYBOARD_H
// include german keymap for umlauts and special chars
#include "keymap_extras/keymap_german.h"

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _PROG 3

#define _______ KC_TRNS
#define ___x___ KC_NO

#define FN1 MO(_FN1)
#define FN2 MO(_FN2)
#define PROG MO(_PROG)
#define SP_FN1 LT(_FN1, KC_SPACE)
#define SP_FN2 LT(_FN2, KC_SPACE)
// #define BS_FN1 LT(_FN1, KC_BSPC)
// #define BS_FN2 LT(_FN2, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     DE_Z,     KC_U,     KC_I,     KC_O,     KC_P,     KC_P,   KC_BSPC,
    KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     DE_PLUS,  DE_HASH,
    KC_LSFT,  DE_Y,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   DE_MINS,  KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT,  PROG,     SP_FN1,   SP_FN2,   PROG,     KC_ALGR,  KC_RGUI,  KC_RCTL
  ),

  [_FN1] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,   _______,
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    _______,  _______,  _______,  DE_HASH,  _______,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_FN2] = LAYOUT(
    KC_TILD,  DE_AT,    _______,  DE_EURO,  _______,  _______,  DE_SLSH,  DE_UE,    DE_BSLS,  DE_OE,    KC_INS,   KC_DEL,   KC_DEL,
    _______,  DE_AE,    DE_SS,    _______,  _______,  _______,  _______,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______, 
    _______,  DE_LESS,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_PROG] = LAYOUT(
    DE_RING,  _______,  _______,  _______,  _______,  _______,  DE_LESS,  DE_MORE,  DE_LBRC,  DE_RBRC,  DE_QST,   _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  DE_LCBR,  DE_RCBR,  DE_LPRN,  DE_RPRN,  _______,
    _______,  DE_PIPE,  _______,  _______,  _______,  _______,  _______,  DE_DQOT,  DE_QUOT,  DE_GRV,   DE_TILD,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  )
};
