#include QMK_KEYBOARD_H
// include german keymap for umlauts and special chars
#include "keymap_extras/keymap_german.h"

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _PROG 3

#define _______ KC_TRNS
#define ___x___ KC_NO

enum custom_keycodes
{
  MC_GREETS = SAFE_RANGE,
  MC_GSTAT, // git status
  MC_GBRA,  // git branch
  MC_GADD,  // git add .
  MC_GCOM,  // git commit -m ""
  MC_GREM,  // git reset
  MC_GRST,  // git reset --hard
  MC_GPUL,  // git pull
  MC_GPSH,  // git push
  MC_GLOG   // git log
};

#define FN1 MO(_FN1)
#define FN2 MO(_FN2)
#define PROG MO(_PROG)
#define SP_FN1 LT(_FN1, KC_SPACE)
#define SP_FN2 LT(_FN2, KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     DE_Z,     KC_U,     KC_I,     KC_O,     KC_P,     KC_P,   KC_BSPC,
    KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     DE_PLUS,  DE_HASH,
    KC_LSFT,  DE_Y,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   DE_MINS,  KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT,  PROG,     SP_FN1,   SP_FN2,   PROG,     KC_ALGR,  KC_RGUI,  KC_RCTL
  ),

  [_FN1] = LAYOUT(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     DE_SS,    DE_SS,    _______,
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    _______,  _______,  _______,  DE_HASH,  _______,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_FN2] = LAYOUT(
    KC_GRV,   DE_AT,    _______,  DE_EURO,  _______,  _______,  DE_SLSH,  DE_UE,    DE_BSLS,  DE_OE,    KC_INS,   KC_DEL,   KC_DEL,
    _______,  DE_AE,    DE_SS,    _______,  _______,  MC_GREETS,_______,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______, 
    _______,  DE_LESS,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_PROG] = LAYOUT(
    DE_RING,  _______,  MC_GPUL,  MC_GPSH,  MC_GLOG,  _______,  DE_LESS,  DE_MORE,  DE_LBRC,  DE_RBRC,  DE_QST,   _______,  _______,
    _______,  _______,  MC_GSTAT, MC_GADD,  MC_GREM,  MC_GRST,  _______,  DE_LCBR,  DE_RCBR,  DE_LPRN,  DE_RPRN,  _______,
    _______,  DE_PIPE,  MC_GBRA,  _______,  _______,  _______,  _______,  DE_DQOT,  DE_QUOT,  DE_GRV,   DE_TILD,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
    case MC_GREETS:
      if (record->event.pressed)
      {
        // when keycode MC_GREETS is pressed send string and do nothing else
        SEND_STRING("Viele Gr" SS_TAP(X_LBRACKET) SS_TAP(X_MINUS) "e," SS_TAP(X_ENTER) "sve");
        return true;
      }
      else
      {
        // nothing on release
      }
      break;
    case MC_GSTAT:
      if (record->event.pressed)
      {
        SEND_STRING("git status" SS_TAP(X_ENTER));
        return true;
      }
      break;
    case MC_GBRA:
      if (record->event.pressed)
      {
        SEND_STRING("git branch" SS_TAP(X_ENTER));
        return true;
      }
      break;
    case MC_GADD:
      if (record->event.pressed)
      {
        SEND_STRING("git add ." SS_TAP(X_ENTER));
        return true;
      }
      break;
    case MC_GREM:
      if (record->event.pressed)
      {
        SEND_STRING("git reset" SS_TAP(X_ENTER));
        return true;
      }
      break;
    case MC_GCOM:
      if (record->event.pressed)
      {
        SEND_STRING("git commit " SS_TAP(X_SLASH) "m " SS_LSFT("2") SS_LSFT("2") SS_TAP(X_LEFT));
        return true;
      }
      break;
    case MC_GRST:
      if (record->event.pressed)
      {
        SEND_STRING("git reset " SS_TAP(X_SLASH) SS_TAP(X_SLASH) "hard");
        return true;
      }
      break;
    case MC_GPUL:
      if (record->event.pressed)
      {
        SEND_STRING("git pull" SS_TAP(X_ENTER));
        return true;
      }
      break;
    case MC_GPSH:
      if (record->event.pressed)
      {
          SEND_STRING("git push");
          return true;
      }
      break;
    case MC_GLOG:
      if (record->event.pressed)
      {
        SEND_STRING("git log" SS_TAP(X_ENTER));
        return true;
      }
      break;
    }
    return true;
}