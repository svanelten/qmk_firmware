#include "svanelten.h"

// include german keymap for umlauts and special chars
#include "keymap_extras/keymap_german.h"

enum custom_keycodes {
  M_IME = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
        return false;
    }
  }
  else {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
        return false;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( KC_ESC,  KC_Q,    KC_W,     KC_E,     KC_R,           KC_T,           DE_Z,           KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC, 
                KC_TAB,  KC_A,    KC_S,     KC_D,     KC_F,           KC_G,           KC_H,           KC_J,     KC_K,     KC_L,     DE_PLUS,  DE_HASH, 
                KC_LSFT, DE_Y,    KC_X,     KC_C,     KC_V,           KC_B,           KC_N,           KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT, 
                KC_LCTL, KC_LGUI, KC_LALT,  KC_NO,    LT(1, KC_SPC),                  LT(2, KC_SPC),            MO(3),    KC_RSFT,  KC_NO,    KC_RCTL
              ),
  [1] = LAYOUT( KC_1,    KC_2,    KC_3,     KC_4,     KC_5,           KC_6,           KC_7,           KC_8,     KC_9,     KC_0,     DE_SS,    KC_EQL,
                KC_TRNS, KC_F1,   KC_F2,    KC_F3,    KC_F4,          KC_F5,          KC_F6,          KC_NO,    KC_7,     KC_8,     KC_9,     KC_0, 
                KC_TRNS, KC_F7,   KC_F8,    KC_F9,    KC_F10,         KC_F11,         KC_F12,         KC_NO,    KC_4,     KC_5,     KC_6,     KC_0, 
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO,    KC_TRNS,                        KC_TRNS,                  KC_1,     KC_2,     KC_NO,    KC_3
              ),
  [2] = LAYOUT( DE_CIRC, DE_AT,   KC_TRNS,  DE_EURO,  KC_TRNS,        KC_TRNS,        DE_SLSH,        DE_UE,    DE_BSLS,  DE_OE,    KC_INS,   KC_DEL, 
                KC_TRNS, DE_AE,   DE_SS,    KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_TRNS, 
                KC_TRNS, DE_LESS, KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END, 
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO,    KC_TRNS,                        KC_TRNS,                  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS
              ),
  [3] = LAYOUT( KC_TRNS, DE_RING, KC_TRNS,  KC_TRNS,  KC_TRNS,        DE_EQL,         DE_EQL,         DE_LESS,  DE_MORE,  DE_LBRC,  DE_RBRC,  KC_TRNS, 
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,        DE_EXLM,        DE_QST,         DE_LCBR,  DE_RCBR,  DE_LPRN,  DE_RPRN,  KC_TRNS, 
                KC_TRNS, DE_PIPE, KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,        DE_DQOT,  DE_QUOT,  DE_GRV,   DE_TILD,  KC_TRNS, 
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO,    KC_TRNS,                        KC_TRNS,                  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS
              )
};

void process_indicator_update(uint32_t state, uint8_t usb_led) {
  for (int i = 0; i < 3; i++) {
    setrgb(0, 0, 0, (LED_TYPE *)&led[i]);
  }
  setrgb(218, 23, 180, (LED_TYPE *)&led[0]);
  if (state & (1<<0)) {
  setrgb(32, 104, 255, (LED_TYPE *)&led[1]);
}

  if (state & (1<<1)) {
  setrgb(10, 255, 125, (LED_TYPE *)&led[2]);
}

    if (state & (1<<2)) {
  setrgb(158, 255, 255, (LED_TYPE *)&led[2]);
}

    if (state & (1<<3)) {
  setrgb(255, 255, 47, (LED_TYPE *)&led[2]);
}


  rgblight_set();
};

void keyboard_post_init_user(void) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

void led_set_user(uint8_t usb_led) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

uint32_t layer_state_set_user(uint32_t state) {
  process_indicator_update(state, host_keyboard_leds());
  return state;
};