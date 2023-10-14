/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2020 Ben Roesner (keycapsss.com)
Copyright 2022 Hiddenbit

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

/* Select hand configuration */
// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_unicode.md
#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP 6 // number of steps to cycle through the hue by
#    define RGBLIGHT_SAT_STEP 6 // number of steps to increment the saturation by
#    define RGBLIGHT_VAL_STEP 6 // number of steps to increment the brightness by
#    define RGBLIGHT_SLEEP //  the RGB lighting will be switched off when the host goes to sleep
#endif

#if defined(OLED_FONT_H)
#    undef OLED_FONT_H
#endif
#define OLED_FONT_H "keyboards/lily58/keymaps/hiddenbit/font.c"

// See: https://github.com/qmk/qmk_firmware/blob/master/docs/one_shot_keys.md
//#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
//#define ONESHOT_TIMEOUT 3000  /* Time (in ms) before the one shot key is released */


// → Umlaute: https://github.com/qmk/qmk_firmware/tree/master/users/spacebarracecar
// → Swap Hands: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_swap_hands.md
