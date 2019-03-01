/* Copyright 2019 REPLACE_WITH_YOUR_NAME
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
#include QMK_KEYBOARD_H

// include german keymap for umlauts and special chars
#include "keymap_extras/keymap_german.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes
{
  MC_GREETS = SAFE_RANGE,
  MC_GSTAT, // git status
  MC_GBRA,  // git branch
  MC_GADD,  // git add .
  MC_GCOM,  // git commit -m ""
  MC_GREM,  // git reset
  MC_GRST,  // git reset --hard

};

// Name all the layers
enum layers {
  _BASE,
  _MACRO,
  _GIT,
  _FSCK
};

// Define layer switches
#define L_BASE TO(_BASE)
#define L_MACRO TO(_MACRO)
#define L_GIT TO(_GIT)
#define L_FSCK TO(_FSCK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*  BASE
   *  |---------------------------------------|
   *  | L_BASE  | L_MACRO |  L_GIT  | L_FSCK  |
   *  |---------------------------------------|
   *  | NumLock | /       | *       | -       |
   *  |---------------------------------------|
   *  | 7       | 8       | 9       |         |
   *  |-----------------------------| +       |
   *  | 4       | 5       | 6       |         |
   *  |---------------------------------------|
   *  | 1       | 2       | 3       |         |
   *  |-----------------------------| Enter   |
   *  | 0                 | .       |         |
   *  |---------------------------------------|
   */
  
  [_BASE] = LAYOUT( /* Base */
        L_BASE,   L_MACRO,  L_GIT,    L_FSCK,
        KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS, 
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS, 
        KC_P4,    KC_P5,    KC_P6, 
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        KC_P0,              KC_PDOT 
  ),

  /*  MACRO
   *  |---------------------------------------|
   *  | L_BASE  | L_MACRO |  L_GIT  | L_FSCK  |
   *  |---------------------------------------|
   *  | NumLock | /       | *       | -       |
   *  |---------------------------------------|
   *  | 7       | 8       | 9       |         |
   *  |-----------------------------| +       |
   *  | 4       | 5       | 6       |         |
   *  |---------------------------------------|
   *  | 1       | 2       | 3       |         |
   *  |-----------------------------| Enter   |
   *  | MC_GREETS         | .       |         |
   *  |---------------------------------------|
   */
  
  [_MACRO] = LAYOUT(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_M,     KC_PSLS,  KC_PAST,  KC_PMNS, 
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS, 
        KC_P4,    KC_P5,    KC_P6, 
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        MC_GREETS,          KC_PDOT 
  ),

  /*  GIT
   *  |---------------------------------------|
   *  | L_BASE  | L_MACRO |  L_GIT  | L_FSCK  |
   *  |---------------------------------------|
   *  | stat    | bbranch | reset   | remove  |
   *  |---------------------------------------|
   *  | 7       | 8       | 9       |         |
   *  |-----------------------------| add     |
   *  | 4       | 5       | 6       |         |
   *  |---------------------------------------|
   *  | 1       | 2       | 3       |         |
   *  |-----------------------------| enter   |
   *  | commit            | .       |         |
   *  |---------------------------------------|
   */
  
  [_GIT] = LAYOUT(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        MC_GSTAT, MC_GBRA,  MC_GRST,  MC_GREM, 
        KC_P7,    KC_P8,    KC_P9,    MC_GADD, 
        KC_P4,    KC_P5,    KC_P6, 
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        MC_GCOM,            KC_PDOT 
  ),

  /*  FSCK
   *  |---------------------------------------|
   *  | L_BASE  | L_MACRO |  L_GIT  | L_FSCK  |
   *  |---------------------------------------|
   *  | NumLock | /       | *       | -       |
   *  |---------------------------------------|
   *  | 7       | 8       | 9       |         |
   *  |-----------------------------| +       |
   *  | 4       | 5       | 6       |         |
   *  |---------------------------------------|
   *  | 1       | 2       | 3       |         |
   *  |-----------------------------| Enter   |
   *  | MC_GREETS         | .       |         |
   *  |---------------------------------------|
   */
  
  [_FSCK] = LAYOUT(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_F,     KC_PSLS,  KC_PAST,  KC_PMNS, 
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS, 
        KC_P4,    KC_P5,    KC_P6, 
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,
        MC_GREETS,          KC_PDOT 
  )
};

/*
  MC_GSTAT, // git status
  MC_GBRA,  // git branch
  MC_GADD,  // git add .
  MC_GCOM,  // git commit -m ""
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MC_GREETS:
      if (record->event.pressed) {
        // when keycode MC_GREETS is pressed send string and do nothing else
        SEND_STRING("Viele Gr" SS_TAP(X_LBRACKET) SS_TAP(X_MINUS) "e," SS_TAP(X_ENTER) "sve");
        return true;
      } else {
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
  }
  return true;
}

void matrix_init_user(void) {

}

bool LAYER_0_LED_ON = 0;
bool LAYER_1_LED_ON = 0;
bool LAYER_2_LED_ON = 0;
bool LAYER_3_LED_ON = 0;

void matrix_scan_user(void)
{
  uint8_t layer = biton32(layer_state);

  if (layer == 0)
  {
    if (LAYER_0_LED_ON == 0)
    {
      dprint("Layer 0: switched on\n");
      PORTB &= ~(1 << 1);
      PORTB &= ~(1 << 2);
      PORTB &= ~(1 << 3);
      LAYER_0_LED_ON = 1;
      LAYER_1_LED_ON = 0;
      LAYER_2_LED_ON = 0;
      LAYER_3_LED_ON = 0;
    }
  }

  if (layer == 1)
  {
    if (LAYER_1_LED_ON == 0)
    {
      dprint("Layer 1: switched on\n");
      PORTB |= (1 << 1);
      PORTB &= ~(1 << 2);
      PORTB &= ~(1 << 3);
      LAYER_0_LED_ON = 0;
      LAYER_1_LED_ON = 1;
      LAYER_2_LED_ON = 0;
      LAYER_3_LED_ON = 0;
    }
  }

  if (layer == 2)
  {
    if (LAYER_2_LED_ON == 0)
    {
      dprint("Layer 2: switched on\n");
      PORTB &= ~(1 << 1);
      PORTB |= (1 << 2);
      PORTB &= ~(1 << 3);
      LAYER_0_LED_ON = 0;
      LAYER_1_LED_ON = 0;
      LAYER_2_LED_ON = 1;
      LAYER_3_LED_ON = 0;
    }
  }

  if (layer == 3)
  {
    if (LAYER_3_LED_ON == 0)
    {
      dprint("Layer 3: switched on\n");
      PORTB &= ~(1 << 1);
      PORTB &= ~(1 << 2);
      PORTB |= (1 << 3);
      LAYER_0_LED_ON = 0;
      LAYER_1_LED_ON = 0;
      LAYER_2_LED_ON = 0;
      LAYER_3_LED_ON = 1;
    }
  }
}

