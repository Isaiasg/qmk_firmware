#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

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

#define MK_KINETIC_SPEED