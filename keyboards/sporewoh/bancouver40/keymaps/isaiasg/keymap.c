/*
Copyright 2022 sporewoh

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

//colemak left hand home row mods
#define GUI_A  LGUI_T(KC_A)
#define ALT_R  LALT_T(KC_R)
#define CTRL_S LCTL_T(KC_S)
#define SHT_T  LSFT_T(KC_T)

//colemak right hand home row mods
#define SFT_N  RSFT_T(KC_N)
#define CTRL_E RCTL_T(KC_E)
#define ALT_I  LALT_T(KC_I)
#define GUI_O  RGUI_T(KC_O)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
        case ALT_R:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case GUI_A:
        case GUI_O:
        case ALT_I:
        case ALT_R:
        case SFT_N:
        case SHT_T:
        case CTRL_S:
        case CTRL_E:
            return true;
        default:
            return false;
    }
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_S)) {
        // one note screenshot
        register_code(KC_LSFT);
        tap_code16(LGUI(KC_S));
        unregister_code(KC_LSFT);
    }

    if (leader_sequence_one_key(KC_A)) {
        // select all
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }

    if (leader_sequence_one_key(KC_F)) {
        //find in all vs code
        register_code(KC_LSFT);
        SEND_STRING(SS_LCTL("f"));
        unregister_code(KC_LSFT);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_4x10(
     KC_Q,   KC_W,         KC_F,           KC_P,          KC_G,                   KC_J,          KC_L,            KC_U,   KC_Y, KC_QUOTE,
     GUI_A, ALT_R,       CTRL_S,          SHT_T,          KC_D,                   KC_H,         SFT_N,          CTRL_E,  ALT_I,    GUI_O,
     KC_Z,   KC_X,         KC_C,           KC_V,          KC_B,                   KC_K,          KC_M,         KC_COMM, KC_DOT,  KC_SLSH,
  QK_LEAD,  KC_NO, LT(3,KC_ESC), LT(1,KC_SPACE), LT(2, KC_TAB),         LT(5,KC_ENTER), LT(4,KC_BSPC), LT(6,KC_DELETE),  KC_NO,    KC_NO),
  
  [1] = LAYOUT_ortho_4x10(
    QK_BOOT,   KC_NO,   KC_NO,   KC_NO, KC_NO,      KC_AGIN, KC_PSTE,  KC_COPY,  KC_CUT,  KC_UNDO,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT,
    KC_NO,   KC_RALT,   KC_NO,   KC_NO, KC_NO,       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,   KC_END,
    KC_NO,     KC_NO,   KC_NO,   KC_NO, KC_NO,       KC_ENT, KC_BSPC,  KC_DEL,   KC_NO,    KC_NO ),
  
  [2] = LAYOUT_ortho_4x10(
    QK_BOOT,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,        KC_NO,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    KC_NO,   KC_RALT,   KC_NO,   KC_NO, KC_NO,        KC_NO,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
    KC_NO,     KC_NO,   KC_NO,   KC_NO, KC_NO,       KC_BTN2, KC_BTN1, KC_BTN3,   KC_NO,   KC_NO ),

  [3] = LAYOUT_ortho_4x10(
    QK_BOOT,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,        KC_NO,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    KC_NO,   KC_RALT,   KC_NO,   KC_NO, KC_NO,        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,     KC_NO,   KC_NO,   KC_NO, KC_NO,       KC_MSTP, KC_MPLY, KC_MUTE,   KC_NO,   KC_NO ),
  
  [4] = LAYOUT_ortho_4x10(
    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,        KC_NO,    KC_NO,   KC_NO,   KC_NO, QK_BOOT,
    KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,        KC_NO,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
     KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,        KC_NO,    KC_NO,   KC_NO, KC_RALT,   KC_NO,
      KC_NO,   KC_NO,  KC_DOT,    KC_0, KC_MINS,        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO ),
  
  [5] = LAYOUT_ortho_4x10(
    KC_LCBR,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,        KC_NO,    KC_NO,   KC_NO,   KC_NO, QK_BOOT,
    KC_COLN,   KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,        KC_NO,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD,  KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,        KC_NO,    KC_NO,   KC_NO, KC_RALT,   KC_NO,
      KC_NO,    KC_NO, KC_LPRN, KC_RPRN, KC_UNDS,        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO ),
  
  [6] = LAYOUT_ortho_4x10(
    KC_F12, KC_F7,  KC_F8,  KC_F9, KC_PSCR,        KC_NO,    KC_NO,   KC_NO,   KC_NO, QK_BOOT,
    KC_F11, KC_F4,  KC_F5,  KC_F6, KC_SCRL,        KC_NO,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10, KC_F1,  KC_F2,  KC_F3, KC_PAUS,        KC_NO,    KC_NO,   KC_NO, KC_RALT,   KC_NO,
     KC_NO, KC_NO, KC_APP, KC_SPC,  KC_TAB,        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO ),
};