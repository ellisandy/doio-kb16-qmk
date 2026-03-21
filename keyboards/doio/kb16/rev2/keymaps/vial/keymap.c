/* Copyright 2022 DOIO
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
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
 * You should have received a copy of the GNU General Public License * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// OLED animation
#include "lib/layer_status/layer_status.h"

// Xcode shortcut aliases
#define XCODE_BUILD         G(KC_B)      // Cmd+B
#define XCODE_TEST          G(KC_U)      // Cmd+T
#define XCODE_RUN           G(KC_R)      // Cmd+R
#define XCODE_STOP          G(KC_DOT)    // Cmd+.

#define XCODE_GPT_HELP      G(KC_0)      // Cmd+0 (Navigator)
#define XCODE_NAV_PROJECT   G(KC_1)      // Cmd+1 (Project navigator)
#define XCODE_NAV_TEST      G(KC_8)      // Cmd+8 (Test navigator)

#define XCODE_TOGGLE_DEBUG  G(S(KC_Y))   // Cmd+Shift+Y (Toggle debug area)
#define XCODE_CONTINUE      G(A(KC_Y))   // Cmd+Option+Y (Continue/Pause)

#define XCODE_COMMENT       G(KC_SLSH)   // Cmd+/
#define XCODE_JUMP_DEF      G(A(KC_J))   // Cmd+Option+J (Jump to Definition)
#define XCODE_OPEN_QUICKLY  G(S(KC_O))   // Cmd+Shift+O
#define XCODE_FIND_PROJECT  G(S(KC_F))   // Cmd+Shift+F

#define XCODE_STEP_OVER     KC_F6
#define XCODE_STEP_INTO     KC_F7
#define XCODE_STEP_OUT      KC_F8

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum custom_keycodes {
    CMD_SPACE_HOME = SAFE_RANGE,
    MAC_OPEN_MAIL,
    MAC_OPEN_SLACK,
    MAC_OPEN_ZOOM,
    MAC_OPEN_BAMBU,
    MAC_OPEN_OUTLOOK,
    MAC_ZOOM_MUTE,
    MAC_ZOOM_VIDEO,
    CYCLE_LAYER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │ 1 │ 2 │ 3 │ 4 │   │Ply│ │TO1│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │ 5 │ 6 │ 7 │ 8 │
       ├───┼───┼───┼───┤
       │ 9 │ 0 │ ↑ │Ent│      ┌───┐
       ├───┼───┼───┼───┤      │Mut│
       │Fn2│ ← │ ↓ │ → │      └───┘
       └───┴───┴───┴───┘
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │ ! │ @ │ # │ $ │   │   │ │   │
       ├───┼───┼───┼───┤   └───┘ └───┘
       │ % │ ^ │ & │ * │
       ├───┼───┼───┼───┤
       │ ( │ ) │   │   │      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │   │   │   │   │      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0         1        2        3         4      */
    [0] = LAYOUT(
                 G(S(KC_A)), _______, _______, G(S(KC_V)), CYCLE_LAYER,
                 _______, _______, _______, QK_BOOT, TO(0),
                 HYPR(KC_F13), _______, _______, _______, KC_MUTE,
                 HYPR(KC_F14), HYPR(KC_F15), HYPR(KC_F16), HYPR(KC_F17)
            ),

/*
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │   │   │   │   │   │   │ │   │
       ├───┼───┼───┼───┤   └───┘ └───┘
       │   │   │   │   │
       ├───┼───┼───┼───┤
       │   │   │   │   │      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │   │   │   │   │      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4       */
    [1] = LAYOUT(
                 KC_F17, _______, _______, _______, CYCLE_LAYER,
                 _______, _______, _______, _______, _______,
                 KC_F13, _______, _______, _______, KC_F24,
                 C(S(A(KC_M))), C(S(A(KC_S))), KC_F15, KC_F16
            ),

/*
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │   │   │   │   │   │   │ │   │
       ├───┼───┼───┼───┤   └───┘ └───┘
       │   │   │   │   │
       ├───┼───┼───┼───┤
       │   │   │   │   │      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │   │   │   │   │      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4       */
    [2] = LAYOUT(
                _______, _______, _______, _______, CYCLE_LAYER,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______
            ),


/*
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │Spd│Spi│   │   │   │   │ │TO4│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │Sad│Sai│   │   │
       ├───┼───┼───┼───┤
       │Prv│Nxt│Hui│   │      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │Tog│Vad│Hud│Vai│      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4        */
    [3] = LAYOUT(
                RM_SPDD, RM_SPDU, _______, QK_BOOT, CYCLE_LAYER,
                RM_SATD, RM_SATU, _______, _______, _______,
                RM_PREV, RM_NEXT, RM_HUEU, _______, _______,
                RM_TOGG, RM_VALD, RM_HUED, RM_VALU
            ),
/*
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │C+b│c+T│c+R│m10│   │   │ │   │
       ├───┼───┼───┼───┤   └───┘ └───┘
       │   │   │   │   │
       ├───┼───┼───┼───┤
       │   │   │   │   │      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │   │   │   │   │      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4        */
    /*  XCode Keys */
    [4] = LAYOUT(
                XCODE_BUILD, XCODE_TEST, XCODE_RUN, XCODE_STOP, CYCLE_LAYER,
                XCODE_GPT_HELP, XCODE_NAV_PROJECT, XCODE_NAV_TEST, XCODE_TOGGLE_DEBUG, _______,
                XCODE_COMMENT, XCODE_JUMP_DEF, XCODE_OPEN_QUICKLY, XCODE_FIND_PROJECT, _______,
                XCODE_STEP_OVER, XCODE_STEP_INTO, XCODE_STEP_OUT, XCODE_CONTINUE
            ),
};

#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_F18, KC_F19), ENCODER_CCW_CW(KC_F20, KC_F21), ENCODER_CCW_CW(KC_F22, KC_F23) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

static void launch_app_via_spotlight(const char *name, uint16_t initial_delay_ms, uint16_t post_type_delay_ms) {
    // Cmd + Space (Spotlight)
    tap_code16(G(KC_SPC));

    // Give Spotlight a moment to appear
    if (initial_delay_ms) {
        wait_ms(initial_delay_ms);
    }

    // Type app/query name
    send_string(name);

    // Optional small delay before launching
    if (post_type_delay_ms) {
        wait_ms(post_type_delay_ms);
    }

    // Launch
    tap_code(KC_ENT);
}

/* MACROS */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CYCLE_LAYER:
            if (record->event.pressed) {
                uint8_t layer = get_highest_layer(layer_state);
                layer_move((layer + 1) % 5);
            }
            return false;
        case CMD_SPACE_HOME:
            if (record->event.pressed) {
                launch_app_via_spotlight("home", 50, 75);
            }
            return false; // handled CMD_SPACE_HOME, prevent fallthrough
            
        case MAC_OPEN_MAIL:
            if (record->event.pressed) {
                launch_app_via_spotlight("Mail", 75, 75);
            }
            return false;

        case MAC_OPEN_SLACK:
            if (record->event.pressed) {
                launch_app_via_spotlight("Slack", 75, 75);
            }
            return false;

        case MAC_OPEN_ZOOM:
            if (record->event.pressed) {
                launch_app_via_spotlight("zoom", 75, 75);
            }
            return false;

        case MAC_OPEN_OUTLOOK:
            if (record->event.pressed) {
                launch_app_via_spotlight("outlook", 150, 150);
            }
            return false;
        case MAC_ZOOM_VIDEO:
            if (record->event.pressed) {
                launch_app_via_spotlight("zoom", 150, 150);
                wait_ms(150);
                tap_code16(G(S(KC_V)));
            }
            return false;
        case MAC_ZOOM_MUTE:
            if (record->event.pressed) {
                launch_app_via_spotlight("zoom", 150, 150);
                wait_ms(150);
                tap_code16(G(S(KC_A)));
            }
            return false;
            
        case MAC_OPEN_BAMBU:
            if (record->event.pressed) {
                // Try common Spotlight names for the app. Adjust to your installed app name if needed.
                launch_app_via_spotlight("BambuStudio", 75, 75);
            }
            return false;
    }
    return true;
}

/* RGB */
#include QMK_KEYBOARD_H
#include "rgb_layer_config.h"

static inline void set_key_hsv(uint8_t row, uint8_t col, HSV hsv) {
    uint8_t led = g_led_config.matrix_co[row][col];
    if (led == NO_LED) return;

    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
}

static inline HSV read_hsv_from_progmem(const HSV *p) {
    HSV out;
    memcpy_P(&out, p, sizeof(out));
    return out;
}

static void apply_base_layer_color(uint8_t layer) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);

    HSV hsv = C_RED; // fallback default
    if (layer < (sizeof(layer_base_hsv) / sizeof(layer_base_hsv[0]))) {
        hsv = read_hsv_from_progmem(&layer_base_hsv[layer]);
    }

    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
}

void keyboard_post_init_user(void) {
    apply_base_layer_color(get_highest_layer(layer_state));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    apply_base_layer_color(get_highest_layer(state));
    return state;
}

bool rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_is_enabled()) return false;

    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t i = 0; i < (sizeof(layer_key_overrides) / sizeof(layer_key_overrides[0])); i++) {
        layer_key_hsv_t e;
        memcpy_P(&e, &layer_key_overrides[i], sizeof(e)); // pull entry from PROGMEM

        if (e.layer == layer) {
            set_key_hsv(e.row, e.col, e.hsv);
        }
    }
    return true;
}

