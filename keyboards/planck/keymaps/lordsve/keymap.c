/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"
#include "muse.h"

// include german keymap for umlauts and special chars
#include "keymap_extras/keymap_german.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE,
  _ALT
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
};

#define ALT LT(_ALT, KC_SPACE)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define MOUSE MO(_MOUSE)
#define _______ KC_TRNS
#define ___x___ KC_NO

// define this to save space
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
  * ,----------------------------------------------------------------------------------------------------------------------.
  * | ESC    | Q       | W       | E       | R       | T       | Y       | U       | I       | O       | P       | BKSP    |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * | Tab    | A       | S       | D       | F       | G       | H       | J       | K       | L       | +*      | #'      |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * | Shift  | Z       | X       | C       | V       | B       | N       | M       | ,       | .       | -       | Enter   |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * | Ctrl   | WIN     | Alt     | Mouse   | Raise   | Alt               | Lower    |         | AltGr   | RWin    | RCtrl   |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    DE_Z,      KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,    KC_H,      KC_J,     KC_K,     KC_L,     DE_PLUS,  DE_HASH,
    KC_LSFT,  DE_Y,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,      KC_M,     KC_COMM,  KC_DOT,   DE_MINS,  KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT,  MOUSE,    RAISE,    ALT,     ALT,       ALT,      LOWER,    KC_ALGR,  KC_RGUI,  KC_RCTRL
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * | 1      | 2       | 3       | 4       | 5       | 6       | 7       | 8       | 9       | 0       | ß       | '       |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | F1      | F2      | F3      | F4      | F5      | F6      |         | 7       | 8       | 9       | 0       |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | F7      | F8      | F9      | F10     | F11     | F12     |         | 4       | 5       | 6       |         |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * |        |         |         | Mouse   | Raise   | Alt               | Lower   | 1       | 2       | 3       | 0       |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_planck_grid(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     DE_SS,    KC_EQL,   
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    _______,  KC_7,     KC_8,     KC_9,     KC_0,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  KC_4,     KC_5,     KC_6,     _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_1,     KC_2,     KC_3,     KC_0
  ),

  /* Alt
  * ,----------------------------------------------------------------------------------------------------------------------.
  * | ^      | @       |         | €       |         |         | /       | Ü       | \       | Ö       | Ins     | Del     |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | Ä       | ß       |         |         |         |         |         | PgUp    | Up      | PgDown  |         |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | <       |         |         |         |         |         | Start   | Left    | Down    | Right   | End     |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * |        |         |         | Mouse   | Raise   | Alt               | Lower   |         |         |         |         |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_ALT] = LAYOUT_planck_grid(
    DE_CIRC,  DE_AT,    _______,  DE_EURO,  _______,  _______,  DE_SLSH,  DE_UE,    DE_BSLS,  DE_OE,    KC_INS,   KC_DEL,
    _______,  DE_AE,    DE_SS,    _______,  _______,  _______,  _______,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______,
    _______,  DE_LESS,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  /* Lower
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |        | °       |         |         |         | =       | =       | <       | >       | [       | ]       |         |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        |         |         |         |         | !       | ?       | {       | }       | (       | )       |         |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | |       |         |         |         |         |         | "       | '       | `       | ~       |         |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * |        |         |         | Mouse   | Raise   | Alt               | Lower   |         |         |         |         |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_planck_grid(
    _______,  DE_RING,  _______,  _______,  _______,  DE_EQL,   DE_EQL,   DE_LESS,  DE_MORE,  DE_LBRC,  DE_RBRC,  _______,
    _______,  _______,  _______,  _______,  _______,  DE_EXLM,  DE_QST,   DE_LCBR,  DE_RCBR,  DE_LPRN,  DE_RPRN,  _______,
    _______,  DE_PIPE,  _______,  _______,  _______,  _______,  _______,  DE_DQOT,  DE_QUOT,  DE_GRV,   DE_TILD,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),
  
  /* Adjust (Lower + Raise)
  * ,----------------------------------------------------------------------------------------------------------------------.
  * | Play/Pa| Stop    | Prev    | Next    |         | MU_TOGG | CK_TOGG |         |         |         |         | Reset   |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * | Mute   | VOL_DEC | VOL_INC |         |         | MU_CYC  |         |         |         |         |         |         |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * | BL_TOGG| BL_DEC  | BL_INC  | BL_MAX  |         |         |         |         |         |         |         |         |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * | BL_BREA|         |         |         |         |                   |         |         | Sleep   | Wake    |         |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_planck_grid(
    KC_MPLY,  KC_MSTP,  KC_MNXT,  KC_MPRV,  _______,  MU_TOG,   CK_TOGG,  _______,  _______,  _______,  _______,  RESET,
    KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  MU_MOD,   _______,  _______,  _______,  _______,  _______,  _______,
    BL_TOGG,  BL_DEC,   BL_INC,   BL_ON,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    BL_BRTG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SLEP,  KC_WAKE,  _______
  ),

  /* Mouse
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |        | Accl 0  |         |         |         |         |         |         |         |         |         |         |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | Acc 1   |         |         |         |         |         |         | L MB    | Up      | R MB    | Wheel U |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | Acc 2   |         |         |         |         |         |         | Left    | Down    | Right   | Wheel D |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * |        |         |         |         |         | L MB              |         |         |         |         | R MB    |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_MOUSE] = LAYOUT_planck_grid(
    ___x___,  KC_ACL0,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,
    ___x___,  KC_ACL1,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,
    ___x___,  KC_ACL2,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,
    ___x___,  ___x___,  ___x___,  _______,  ___x___,  KC_BTN1,  KC_BTN1,  ___x___,  ___x___,  ___x___,  ___x___,  KC_BTN2
  )
};

#ifdef AUDIO_ENABLE
  float layersound[][2] = SONG(TERMINAL_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
      case 3:
#ifdef AUDIO_ENABLE
        PLAY_SONG(layersound);
#endif
        break;
      default:
        break;
    }

  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_MOUSE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          //PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          //PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  // #ifdef AUDIO_ENABLE
  //   if (muse_mode) {
  //     if (muse_counter == 0) {
  //       uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
  //       if (muse_note != last_muse_note) {
  //         stop_note(compute_freq_for_midi_note(last_muse_note));
  //         play_note(compute_freq_for_midi_note(muse_note), 0xF);
  //         last_muse_note = muse_note;
  //       }
  //     }
  //     muse_counter = (muse_counter + 1) % muse_tempo;
  //   }
  // #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
