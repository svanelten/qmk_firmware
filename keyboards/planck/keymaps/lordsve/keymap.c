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
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define _______ KC_TRNS
#define ___x___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
  * ,----------------------------------------------------------------------------------------------------------------------.
  * | ESC    | Q       | W       | E       | R       | T       | Y       | U       | I       | O       | P       | BKSP    |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * | Tab    | A       | S       | D       | F       | G       | H       | J       | K       | L       | +*      | #'      |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * | Shift  | Z       | X       | C       | V       | B       | N       | M       | ,       | .       | -       | Enter   |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * | Ctrl   | WIN     | Alt     | < >     | Raise   | Space             | Lower   | Left    | Down    | Up      | Right   |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    DE_Z,      KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,    KC_H,      KC_J,     KC_K,     KC_L,     DE_PLUS,  DE_HASH,
    KC_LSFT,  DE_Y,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,      KC_M,     KC_COMM,  KC_DOT,   DE_MINS,  KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT,  DE_LESS,  RAISE,    KC_SPC,  KC_SPC,    LOWER,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |        | F1      | F2      | F3      | F4      |         |         |         | ,       | /       | *       | -       |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | F5      | F6      | F7      | F8      |         |         |         | 7       | 8       | 9       | +       |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | F9      | F10     | F11     | F12     |         |         |         | 4       | 5       | 6       |         |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * |        |         |         |         |         |                   |         | 1       | 2       | 3       | 0       |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_planck_grid(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,  _______,  _______,  KC_PCMM,  KC_PSLS,  KC_PAST,  KC_PMNS,
    _______,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,  _______,  _______,  KC_7,     KC_8,     KC_9,     KC_PPLS,
    _______,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  KC_4,     KC_5,     KC_6,     _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_1,     KC_2,     KC_3,     KC_0
  ),

  /* Lower
  * ,----------------------------------------------------------------------------------------------------------------------.
  * | ^      |         |         |         |         |         |         | Ü       |         | Ö       | Ins     | Del     |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | Ä       | ß       | @       | €       |         | [       | ]       | (       | )       | {       | }       |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * |        | !       | "       | §       | $       | %       | &       | /       | \       | =       | ?       | '       |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * |        |         |         |         |         |                   |         | Home    | PGUP    | PGDN    | End     |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_planck_grid(
    DE_CIRC,  _______,  _______,  _______,  _______,  _______,  _______,  DE_UE,    _______,  DE_OE,    KC_INS,   KC_DEL,
    _______,  DE_AE,    DE_SS,    DE_AT,    DE_EURO,  _______,  DE_LBRC,  DE_RBRC,  DE_LPRN,  DE_RPRN,  DE_LCBR,  DE_RCBR,
    _______,  DE_EXLM,  DE_DQOT,  DE_PARA,  DE_DLR,   DE_PERC,  DE_AMPR,  DE_SLSH,  DE_BSLS,  DE_EQL,   DE_QST,   KC_EQL,
    _______,  _______,  _______,  DE_PIPE,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END
  ),
  /* Adjust (Lower + Raise)
  * ,----------------------------------------------------------------------------------------------------------------------.
  * | Play/Pa| Stop    | Prev    | Next    |         |         |         |         |         |         |         | Reset   |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * | Mute   | VOL_DEC | VOL_INC |         |         |         |         |         |         |         |         |         |
  * |--------+---------+---------+---------+---------+---------|---------+---------+---------+---------+---------+---------|
  * | BL_TOGG| BL_DEC  | BL_INC  | BL_MAX  |         |         |         |         |         |         |         |         |
  * |--------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  * | BL_BREA|         |         |         |         |                   |         |         | Sleep   | Wake    |         |
  * `----------------------------------------------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_planck_grid(
    KC_MPLY,  KC_MSTP,  KC_MNXT,  KC_MPRV,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,
    KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    BL_TOGG,  BL_DEC,   BL_INC,   BL_ON,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    BL_BRTG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SLEP,  KC_WAKE,  _______
  )

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
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
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
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
