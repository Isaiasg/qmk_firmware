/* Copyright 2022 Yiancar
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

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

//colemak left hand home row mods
#define GUI_A HOME_A
#define ALT_R LALT_T(KC_R)
#define SFT_S LCTL_T(KC_S)
#define CTRL_T LSFT_T(KC_T)

//colemak right hand home row mods
#define CTL_N RSFT_T(KC_N)
#define SFT_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

#define KC_AGIN RCTL(KC_Y)
#define KC_UNDO RCTL(KC_Z)
#define KC_CUT  RCTL(KC_X)
#define KC_COPY RCTL(KC_C)
#define KC_PSTE RCTL(KC_V)
#define KC_AGAIN KC_AGIN
#define KC_PASTE KC_PSTE

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_S:
        case ALT_R:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HOME_A:
        case HOME_S:
        case HOME_D:
        case HOME_F:
        case HOME_J:
        case HOME_K:
        case HOME_L:
        case HOME_SCLN:
        case GUI_O:
        case ALT_I:
        case ALT_R:
        case SFT_E:
        case SFT_S:
        case CTRL_T:
        case CTL_N:
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
[0] = LAYOUT_65_ansi( /* Base */
    QK_GESC,    KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,      KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
    KC_TAB,     KC_Q,       KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,      KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    CW_TOGG,    HOME_A,     HOME_S, HOME_D, HOME_F, KC_G,   KC_H,   HOME_J, HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT, KC_ENT,           KC_PGDN, 
    MO(1),      KC_Z,       KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,   MO(1),            KC_UP,   KC_END,
    MO(3),      MO(4),      QK_LEAD,                KC_SPC,                          KC_WSCH, LCTL(KC_X),KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT),

[1] = LAYOUT_65_ansi( /* FN */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AGIN, KC_UNDO, KC_CUT, KC_COPY,  KC_PSTE, KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS,                               TG(2),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[2] = LAYOUT_65_ansi( /* Empty for dynamic keymaps */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, GUI_A,   ALT_R,   SFT_S,   CTRL_T,  KC_D,    KC_H,    CTL_N,   SFT_E,   ALT_I,   GUI_O,   KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS,                               TG(2),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[3] = LAYOUT_65_ansi( /* Empty for dynamic keymaps */
    KC_A,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS,                               KC_BTN2, KC_BTN1, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS),

[4] = LAYOUT_65_ansi( /* FN */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AGIN, KC_UNDO, KC_CUT, KC_COPY,  KC_PSTE, KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_VOLU, KC_VOLD, KC_MUTE,                KC_TRNS,                               KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};
