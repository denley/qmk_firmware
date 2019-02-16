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

#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"

#define DV_UP KC_UP
#define DV_DOWN KC_DOWN
#define DV_LEFT KC_LEFT
#define DV_RGHT KC_RGHT
#define DV_MS_WH_UP KC_MS_WH_UP
#define DV_MS_WH_DOWN KC_MS_WH_DOWN
#define DV_PGUP KC_PGUP
#define DV_PGDN KC_PGDN
#define DV_HOME KC_HOME
#define DV_END KC_END
#define DV_DEL KC_DEL
#define DV_BSPC KC_BSPC
#define DV_LALT KC_LALT
#define DV_LGUI KC_LGUI
#define DV_LCTL KC_LCTL
#define DV_LSFT KC_LSFT
#define DV_SPC KC_SPC
#define DV_ENT KC_ENT
#define DV_TAB KC_TAB
#define DV_ESC KC_ESC

extern keymap_config_t keymap_config;

enum planck_layers {
  _DVORAK,
  _MOVE,
  _NUMERIC,
  _BRACKET,
  _ADJUST
};

#define NUMERIC MO(_NUMERIC)
#define BRACKET MO(_BRACKET)
#define MOVE MO(_MOVE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Numr | Move |    Space    | Brac |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    DV_ESC,  DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    DV_F,    DV_G,    DV_C,    DV_R,    DV_L,    DV_BSPC,
    DV_TAB,  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,    DV_ENT,
    DV_LSFT, DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,    DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,    XXXXXXX,
    DV_LCTL, DV_LALT, DV_LGUI, NUMERIC, MOVE,    DV_SPC,  DV_SPC,  BRACKET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Move
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      | PgUp |      |      |      |      |  Up  |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Home | PgDn | End  |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, DV_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DV_UP,   XXXXXXX, XXXXXXX, DV_DEL,
    _______, XXXXXXX, DV_HOME, DV_PGDN, DV_END,  XXXXXXX, XXXXXXX, DV_LEFT, DV_DOWN, DV_RGHT, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Numeric
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   ?  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   +  |   =  |   _  |   -  |      |      |   /  |   \  |   |  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMERIC] = LAYOUT_planck_grid(
    DV_TILD, DV_EXLM, DV_AT,   DV_HASH, DV_DLR,  DV_PERC, DV_CIRC, DV_AMPR, DV_ASTR, DV_QUES, XXXXXXX, DV_DEL,
    DV_GRV,  DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    DV_6,    DV_7,    DV_8,    DV_9,    DV_0,    XXXXXXX,
    _______, DV_PLUS, DV_EQL,  DV_UNDS, DV_MINS, XXXXXXX, XXXXXXX, DV_SLSH, DV_BSLS, DV_PIPE, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Bracket
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   <  |  [   |   {  |   (  |      |      |  )   |  }   |  ]   |  >   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BRACKET] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DV_DEL,
    _______, DV_LABK, DV_LBRC, DV_LCBR, DV_LPRN, XXXXXXX, XXXXXXX, DV_RPRN, DV_RCBR, DV_RBRC, DV_RABK, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Numeric + Bracket)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _NUMERIC, _BRACKET, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (clockwise) {
    #ifdef MOUSEKEY_ENABLE
      register_code(DV_MS_WH_DOWN);
      unregister_code(DV_MS_WH_DOWN);
    #else
      register_code(DV_PGDN);
      unregister_code(DV_PGDN);
    #endif
  } else {
    #ifdef MOUSEKEY_ENABLE
      register_code(DV_MS_WH_UP);
      unregister_code(DV_MS_WH_UP);
    #else
      register_code(DV_PGUP);
      unregister_code(DV_PGUP);
    #endif
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
      }
   }
}

