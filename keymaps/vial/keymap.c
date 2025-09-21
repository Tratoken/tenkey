// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
  _1ST = 0,
  _2ND,
  _3RD,
  _4TH
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ┌─────┬─────┬─────┬─────┐
     * │ F1  │ F2  │ F3  │ F4  │
     * ├─────┼─────┼─────┼─────┤
     * │ NUM │  /  │  *  │  -  │
     * ├─────┼─────┼─────┼─────┤
     * │  7  │  8  │  9  │     │
     * ├─────┼─────┼─────┤  +  │
     * │  4  │  5  │  6  │     │
     * ├─────┼─────┼─────┼─────┤
     * │  1  │  2  │  3  │     │
     * ├─────┴─────┼─────┤ Ent │
     * │     0     │  .  │     │
     * └───────────┴─────┴─────┘
     */
    [_1ST] = LAYOUT(
      KC_F1,  KC_F2,  KC_F3, KC_F4,
      KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
      KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
      KC_P4,   KC_P5,   KC_P6,
      KC_P1,   KC_P2,   KC_P3,  KC_PENT,
          KC_P0,   KC_PDOT
    ),
    [_2ND] = LAYOUT(
      KC_F1,  KC_F2,  KC_F3, KC_F4,
      KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
      KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
      KC_P4,   KC_P5,   KC_P6,
      KC_P1,   KC_P2,   KC_P3,  KC_PENT,
          KC_P0,   KC_PDOT
    ),
    [_3RD] = LAYOUT(
      KC_F1,  KC_F2,  KC_F3, KC_F4,
      KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
      KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
      KC_P4,   KC_P5,   KC_P6,
      KC_P1,   KC_P2,   KC_P3,  KC_PENT,
          KC_P0,   KC_PDOT
    ),
    [_4TH] = LAYOUT(
      KC_F1,  KC_F2,  KC_F3, KC_F4,
      KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
      KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
      KC_P4,   KC_P5,   KC_P6,
      KC_P1,   KC_P2,   KC_P3,  KC_PENT,
          KC_P0,   KC_PDOT
    ) 
  };

  /////// LED Setting ////////

#ifdef RGBLIGHT_LAYERS

const rgblight_segment_t PROGMEM rgb_layer_1st[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 170,255,100}  //BLUE
);
const rgblight_segment_t PROGMEM rgb_layer_2nd[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 0,255,100}   //RED
);
const rgblight_segment_t PROGMEM rgb_layer_3rd[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 85,255,100}   //GREEN
);
const rgblight_segment_t PROGMEM rgb_layer_4th[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 0,0,100}   // WHITE
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_1st,
    rgb_layer_2nd,
    rgb_layer_3rd,
    rgb_layer_4th
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _1ST));
    rgblight_set_layer_state(1, layer_state_cmp(state, _2ND));
    rgblight_set_layer_state(2, layer_state_cmp(state, _3RD));
    rgblight_set_layer_state(3, layer_state_cmp(state, _4TH));
    return state;
}

#endif // RGBLIGHT_LAYERS
