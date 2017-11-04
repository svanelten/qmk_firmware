#include "xd60.h"
#include "action_layer.h"

// definitionen für die deutsche keymap
#include "keymap_extras/keymap_german.h"

#define _BL 0
#define _FL 1
#define _NL 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  [_BL] = KEYMAP(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_NO,    \
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,                KC_NO,    \
    MO(_FL),    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_NUHS,                KC_ENT,   \
    KC_LSFT,    DE_LESS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,      KC_RSFT,    KC_NO,    \
    KC_LCTL,    KC_LGUI,    KC_LALT,                            KC_SPC,                                                     KC_RALT,    KC_MENU,    KC_NO,      MO(_FL),    MO(_NL)),

  // 1: Function Layer
  [_FL] = KEYMAP(
    KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_TRNS,    KC_NO,    \
    KC_TRNS,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_NO,    \
    KC_TRNS,    KC_MPLY,    KC_MSTP,    KC_MPRV,    KC_MNXT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_HOME,    KC_UP,      KC_PGUP,    KC_PGDN,    KC_TRNS,                KC_ENT,   \
    KC_TRNS,    KC_INS,     KC_DEL,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_END,     KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_TRNS,    KC_TRNS,    KC_NO,    \
    KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,                                                    KC_DEL,     KC_INS,     KC_NO,      KC_TRNS,    KC_TRNS),

  // 1: Number Layer
  [_NL] = KEYMAP(
    RESET,      RGB_TOG,    RGB_HUI,    RGB_SAI,    RGB_VAI,    BL_TOGG,    BL_INC,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PSLS,    KC_PAST,    KC_PMNS,    KC_PEQL,    KC_NO,    \
    KC_TRNS,    RGB_MOD,    RGB_HUD,    RGB_SAD,    RGB_VAD,    KC_TRNS,    BL_DEC,     KC_TRNS,    KC_TRNS,    KC_7,       KC_8,       KC_9,       KC_PPLS,                KC_NO,    \
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_4,       KC_5,       KC_6,       KC_COMM,                KC_TRNS,  \
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_NO,      KC_0,       KC_NO,    \
    KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,                                                    KC_TRNS,    KC_TRNS,    KC_NO,      KC_TRNS,    KC_TRNS),
};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay  
  [1] = ACTION_LAYER_MOMENTARY(2),  // to Numpad overlay  
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
