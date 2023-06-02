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

#pragma once

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

/* pin-out for PCB */
#define MATRIX_ROW_PINS { F0, F1, F4, F5 }
#define MATRIX_COL_PINS { B5, B4, D7, D6, D4, D5, D3, D2, D1, D0 }


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define DYNAMIC_KEYMAP_LAYER_COUNT 10

#define LEADER_NO_TIMEOUT
#define LEADER_TIMEOUT 350
#define LEADER_PER_KEY_TIMING

#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
#define QUICK_TAP_TERM 0

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
//#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
//#define AUTO_SHIFT_NO_SETUP
#define RETRO_SHIFT 500

#define TAPPING_TERM_PER_KEY

 //#define MOUSEKEY_INERTIA
#define MK_KINETIC_SPEED
