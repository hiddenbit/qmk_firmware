 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
  * Copyright 2022 Hiddenbit
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

extern uint8_t is_master;

enum layers {
    _QWERTY,
    _SPECIAL_CHARS,
    _NAVIGATION,
    _MACRO,
};

#define TO_NAV MO(_NAVIGATION)
#define TO_SPC MO(_SPECIAL_CHARS)
//#define TO_MCR MO(_MACRO)

// CMD when hold, screenshot when pressed
#define MY_L_ROT LGUI_T(SCMD(KC_3))

#define MY_UARR LSA(KC_K)
#define MY_RARR LSA(KC_L)
#define MY_DARR LSA(KC_J)
#define MY_LARR LSA(KC_H)
#define MY_BLLT LALT(KC_8)
#define MY_EUR LALT(KC_E)

//enum unicode_names {
//    BANG,
//    IRONY,
//    SNEK,
//    UARR,
//    RARR,
//    DARR,
//    LARR,
//    BLLT,
//    EUR,
//};
//const uint32_t PROGMEM unicode_map[] = {
//    [BANG]  = 0x203D,  // ‽
//    [IRONY] = 0x2E2E,  // ⸮
//    [SNEK]  = 0x1F40D, // 🐍
//    [UARR]  = 0x2091, // ↑
//    [RARR]  = 0x2192, // →
//    [DARR]  = 0x2193, // ↓
//    [LARR]  = 0x2190, // ←
//    [BLLT]  = 0x2022, // •
//    [EUR]   = 0x20AC, // €
//};


// enum {
//   TD_LBRC,
//   TD_RBRC,
// };
// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_LBRC)),
//   [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_RBRC)),
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    KC_ESC,    KC_1,    KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,    KC_0,     KC_MINS,
    KC_TAB,    KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     KC_BACKSLASH,
    KC_ESC,    KC_A,    KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    OSM(MOD_LSFT),KC_Z, KC_X,     KC_C,     KC_V,     KC_B,   MY_L_ROT,    XXXXXXX, KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT,
               OSM(MOD_LCTL), OSM(MOD_LALT),  OSM(MOD_LGUI),  KC_SPC,      KC_SPC,  TO_NAV,   TO_SPC,   MO(_MACRO)
    ),

    [_NAVIGATION] = LAYOUT(
    KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX,       XXXXXXX,   LCMD(KC_UP),   XXXXXXX, XXXXXXX,        XXXXXXX,
    KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,                      XXXXXXX,       KC_DELETE, KC_UP,         KC_BSPC, XXXXXXX,        XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     LCMD(KC_LEFT), KC_LEFT,   KC_DOWN,       KC_RGHT, LCMD(KC_RIGHT), XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  XXXXXXX,       XXXXXXX,   LCMD(KC_DOWN), XXXXXXX, XXXXXXX,        _______,
                               _______, _______, _______,  _______, _______,  _______,       _______,   _______
    ),

    [_SPECIAL_CHARS] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX,    MY_BLLT,  LSFT(KC_9), LSFT(KC_0),    XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, MY_EUR,  XXXXXXX, XXXXXXX,                     XXXXXXX, LSFT(KC_9), MY_UARR,  LSFT(KC_0), KC_LBRC,       KC_RBRC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, MY_LARR,    MY_DARR,  MY_RARR,    LSFT(KC_LBRC), LSFT(KC_RBRC),
    _______, KC_GRAVE,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, RGB_TOG,  XXXXXXX, KC_LBRC,    XXXXXXX,  KC_RBRC,    XXXXXXX,       _______,
                               _______, _______, _______,  _______, _______,  _______, _______, _______
    ),

    [_MACRO] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, DM_PLY1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  XXXXXXX, DM_PLY2, DM_REC2, DM_RSTP, XXXXXXX, _______,
                               _______, _______, _______,  _______, _______,  _______, _______, _______
    )
};








// Tap Dance declarations
// enum {
//     TD_ESC_CAPS,
// };

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    //[TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

// Add tap dance item to your keymap in place of a keycode
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // ...
    //TD(TD_ESC_CAPS)
    // ...
// };










//layer_state_t layer_state_set_user(layer_state_t state) {
//    state = update_tri_layer_state(state, _NAVIGATION, _SPECIAL_CHARS, _ADJUST);
//    return state;
//}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
    // 'logo', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00,
    0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83,
    0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80,
    0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0,
    0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00,
    0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06,
    0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}

void render_symbol_xy(int col, int row, int h, int w, int i) {
    int r, c;
    for (r = 0; r < h; r++) {
        oled_set_cursor(0, row + r);
        for (c = 0; c < w; c++) {
            oled_write_char(i + r * 32 + c, false);
        }
    }
}

void render_symbol_4x3(int col, int row, int i) {
    render_symbol_xy(col, row, 3, 4, i);
}
void render_symbol_5x2(int col, int row, int i) {
    render_symbol_xy(col, row, 2, 5, i);
}

void render_default_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            render_symbol_5x2(0, 0, 144);
            break;
        case _NAVIGATION:
            render_symbol_5x2(0, 0, 149);
            break;
        case _SPECIAL_CHARS:
            render_symbol_5x2(0, 0, 154);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

void render_status_main(void) {
    oled_clear();
    // Show keyboard layout
    render_default_layer_state();

    uint8_t mods = get_mods();
    if (mods & MOD_MASK_GUI) {
        render_symbol_4x3(0, 3, 140);
    }
    if (mods & MOD_MASK_SHIFT) {
        render_symbol_4x3(0, 6, 136);
    }
    if (mods & MOD_MASK_ALT) {
        render_symbol_4x3(0, 9, 132);
    }
    if (mods & MOD_MASK_CTRL) {
        render_symbol_4x3(0, 12, 128);
    }
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_lily58_logo();
  }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_L_ROT:
            if (record->tap.count && record->event.pressed) {
                register_code(KC_LEFT_GUI);
                register_code(KC_LEFT_SHIFT);
                tap_code(KC_3);
                unregister_code(KC_LEFT_SHIFT);
                unregister_code(KC_LEFT_GUI);
                return false;
            }
            break;
    }
    return true;
}
#endif // OLED_ENABLE


// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Encoder on master side
    if (clockwise) {
        // register_code(KC_LEFT_GUI);
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_TAB);
        unregister_code(KC_LEFT_SHIFT);
        // unregister_code(KC_LEFT_GUI);
    } else {
        // register_code(KC_LEFT_GUI);
        tap_code(KC_TAB);
        // tap_code(KC_R);
        // unregister_code(KC_LEFT_GUI);
    }
  }
  else if (index == 1) { // Encoder on slave side
    if(IS_LAYER_ON(_SPECIAL_CHARS)) {
      //
      if (clockwise) {
          rgblight_step_reverse();
      } else {
          rgblight_step();
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_VOLD);
      } else {
          tap_code(KC_VOLU);
      }
    }
  }
    return true;
}
#endif
