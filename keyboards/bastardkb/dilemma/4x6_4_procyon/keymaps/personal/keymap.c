/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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

#include "keymap_uk.h"

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
};

// mouse specific define overrides 
// normal mouse
#define Dilemma_MINIMUM_DEFAULT_DPI 150  // default is 400, this makes it more tolerable
#define Dilemma_DEFAULT_DPI_CONFIG_STEP 200  // default is 200
// sniping
#define DILEMMA_MINIMUM_SNIPING_DPI 200  // default is also 200
#define DILEMMA_SNIPING_DPI_CONFIG_STEP 100  // default is also 100
// scroll
#define DILEMMA_DRAGSCROLL_DPI 200  // default is 100

// colour specific overrides
#define LAYER_INDICATOR_BRIGHTNESS_INC 11  // default is 22
#define CAPSLOCK_INDICATOR_BRIGHTNESS_INC 38  // default is 76

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define POINT MO(LAYER_POINTER)   /// HACK: Can do tri-layer shenanigans by carefully placing this. see keymap.
#define PT_Z LT(LAYER_POINTER, UK_Z)
#define PT_SLSH LT(LAYER_POINTER, UK_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       UK_GRV,    UK_1,    UK_2,    UK_3,    UK_4,    UK_5,       UK_6,    UK_7,    UK_8,    UK_9,    UK_0, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,    UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,       UK_Y,    UK_U,    UK_I,    UK_O,    UK_P, UK_HASH,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TAB,    UK_A,    UK_S,    UK_D,    UK_F,    UK_G,       UK_H,    UK_J,    UK_K,    UK_L, UK_SCLN, UK_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,   PT_Z,    UK_X,    UK_C,    UK_V,    UK_B,       UK_N,    UK_M, UK_COMM,  UK_DOT, PT_SLSH, DRGSCRL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_LCTL, KC_LGUI,  LOWER,  KC_SPC,      KC_ENT,  RAISE, KC_BSPC, KC_MPLY
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  // Note, these are my custom layers that I set up to match my charybdis
  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,     KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       UK_GRV,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5,       UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    KC_F12, 
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, UK_EXLM, UK_AT,   UK_HASH, UK_DLR,  UK_PERC,    UK_CIRC, UK_AMPR, UK_ASTR, UK_LPRN, UK_RPRN, UK_PIPE, 
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, UK_EQL,  UK_MINS, UK_PLUS, UK_LCBR, UK_RCBR,    UK_LBRC, UK_RBRC, UK_SCLN, UK_COLN, UK_BSLS, KC_RSFT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, XXXXXXX, _______, XXXXXXX,    _______,   POINT, KC_DEL, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______,  KC_INS,  KC_PSCR, KC_APP, _______, _______,    KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,  KC_F12, 
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX, 
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_CAPS, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,_______,    XXXXXXX, KC_HOME, XXXXXXX, KC_END,  _______, _______, 
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, KC_LALT,    POINT, _______,    XXXXXXX, _______, XXXXXXX, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  // Note, in my firmware, I swapped lower and raise to better fit what I want. See the old code below:
/* 
  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______, XXXXXXX, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, _______, _______, XXXXXXX,    _______, XXXXXXX, XXXXXXX, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
*/

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,    XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, _______, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,DPI_RMOD,S_D_RMOD,    XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRG_TOG, SNIPING,  EE_CLR, QK_BOOT,    _______, KC_KP_0, XXXXXXX,KC_KP_DOT,_______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1,    KC_BTN3, KC_BTN1, KC_BTN2, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};
// clang-format on

//////////////////////////////////

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLEE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_LOWER]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_RAISE]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
