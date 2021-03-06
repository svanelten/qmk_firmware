
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_ALT 2
#define L_RAISE 4
#define L_LOWER 8
#define L_ADJUST 28
#define L_ADJUST_TRI 14

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    break;
  case L_ALT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ALTERNATE");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: RAISE");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: LOWER");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ADJUST");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Unknown: #'%ld'", layer_state);
  }

  return layer_state_str;
}
