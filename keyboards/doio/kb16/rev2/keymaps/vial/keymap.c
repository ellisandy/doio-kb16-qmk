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

// OLED: per-layer machine name, drawn double-height
extern const unsigned char font[];

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
                 S(KC_TAB), KC_F12, C(KC_F10), A(C(KC_U)), CYCLE_LAYER,
                 _______, _______, _______, _______, _______,
                 KC_F13, _______, _______, _______, KC_F24,
                 A(S(KC_O)), KC_MPLY, KC_F15, KC_F16
            ),

/*  LINUX LAYER - Oracle Linux 9 / GNOME 40
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │Ovw│App│A↹ │Trm│   │Cyc│ │TO0│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │◀Ti│Max│Rst│Ti▶│
       ├───┼───┼───┼───┤
       │◀Ws│Ws▶│Scr│Are│      ┌───┐
       ├───┼───┼───┼───┤      │Mut│
       │Lck│Cls│Hid│Ntf│      └───┘
       └───┴───┴───┴───┘
    Knob1 ↺↻ workspace  |  Knob2 ↺↻ browser tab  |  Knob3 ↺↻ volume
*/
    /*  Row:    0        1        2        3        4       */
    /*  Linux (Oracle Linux 9 / GNOME 40) */
    [2] = LAYOUT(
                KC_LGUI,      G(KC_A),      A(KC_TAB),    C(A(KC_T)),   CYCLE_LAYER,
                G(KC_LEFT),   G(KC_UP),     G(KC_DOWN),   G(KC_RGHT),   TO(0),
                G(S(KC_PGUP)),G(S(KC_PGDN)),KC_PSCR,      S(KC_PSCR),   KC_MUTE,
                G(KC_L),      A(KC_F4),     G(KC_H),      G(KC_V)
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

/*  HOMELAB - property automation, driven from the MacBook
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │   │   │   │   │   │Cyc│ │TO0│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │   │   │   │   │
       ├───┼───┼───┼───┤
       │   │   │   │   │      ┌───┐
       ├───┼───┼───┼───┤      │Mut│
       │   │   │   │   │      └───┘
       └───┴───┴───┴───┘
    Deliberately KC_NO rather than _______: layers are exclusive, so transparent
    keys here would fall through and fire layer 0 (Zoom mute, QK_BOOT, the Hyper
    launchers). An empty layer should be genuinely empty.

    When filling this in: HYPR(KC_F18)..HYPR(KC_F24) are unclaimed. Layer 1 uses
    bare F18-F24 on its encoders, which is a different keycode, so there is no
    collision.
*/
    /*  Row:    0        1        2        3        4        */
    [5] = LAYOUT(
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CYCLE_LAYER,
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0),
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
            ),
};

#ifdef OLED_ENABLE

/* At double height a line holds 10 characters (128px / 12px per glyph).
 * Strings below are split on their first space onto two stacked lines when
 * both halves fit; otherwise they are drawn as one centered line. */
#define OLED_2X_COLS 10

static const char *const layer_names[] = {
    [0] = "Work Mac",
    [1] = "Gaming Rig",
    [2] = "Oracle Linux",
    [3] = "Lights",
    [4] = "Personal Mac",   /* still carries the Xcode bindings for now */
    [5] = "Homelab",
};

/* Friendly name flashed on the OLED when a key is pressed, so you get
 * confirmation of what you just fired. Grid keys only: the knob presses are
 * deliberately absent so that cycling layers shows the new layer name instead.
 * NULL = no label, screen keeps showing the layer name. */
#define KEY_FLASH_MS 1000

static const char *const key_labels[][4][4] = {
    [0] = {
        { "Zoom Mute", NULL,        NULL,        "Zoom Video" },
        { NULL,        NULL,        NULL,        "Bootload"   },
        { "Work Scene",NULL,        NULL,        NULL         },
        { "Outlook",   "F15 Zoom",  "F16 Slack", "Deadwood"   },
    },
    [1] = {
        { "Steam Ovl", "Screenshot","Mark Clip", "Discord Go" },
        { NULL,        NULL,        NULL,        "Bootload"   },
        { "F13",       NULL,        NULL,        NULL         },
        { "Disc Mute", "Play Pause","F15",       "F16"        },
    },
    [2] = {
        { "Overview",  "App Grid",  "Last App",  "Terminal"   },
        { "Tile Left", "Maximize",  "Restore",   "Tile Right" },
        { "Win Prev",  "Win Next",  "Screenshot","Area Shot"  },
        { "Lock",      "Close Win", "Hide Win",  "Notifs"     },
    },
    [3] = {
        { "Speed -",   "Speed +",   NULL,        "Bootload"   },
        { "Sat -",     "Sat +",     NULL,        NULL         },
        { "FX Prev",   "FX Next",   "Hue +",     NULL         },
        { "RGB Toggle","Bright -",  "Hue -",     "Bright +"   },
    },
    [4] = {
        { "Build",     "Test",      "Run",       "Stop"       },
        { "Navigator", "Project",   "Tests",     "Debug Area" },
        { "Comment",   "Jump Def",  "Open Quick","Find Proj"  },
        { "Step Over", "Step Into", "Step Out",  "Continue"   },
    },
    [5] = {   /* Homelab - empty until the automation keys are bound */
        { NULL, NULL, NULL, NULL },
        { NULL, NULL, NULL, NULL },
        { NULL, NULL, NULL, NULL },
        { NULL, NULL, NULL, NULL },
    },
};

static const char *key_flash_label = NULL;
static uint32_t    key_flash_time  = 0;

/* Draw one glyph scaled 2x from the 6x8 font: 12x16 pixels at (x, y). */
static void draw_char_2x(uint8_t x, uint8_t y, char c) {
    const uint16_t glyph = ((uint8_t)c - OLED_FONT_START) * OLED_FONT_WIDTH;

    for (uint8_t col = 0; col < OLED_FONT_WIDTH; col++) {
        const uint8_t bits = font[glyph + col];

        for (uint8_t row = 0; row < 8; row++) {
            const bool on = bits & (1 << row);
            const uint8_t px = x + (col * 2);
            const uint8_t py = y + (row * 2);

            oled_write_pixel(px,     py,     on);
            oled_write_pixel(px + 1, py,     on);
            oled_write_pixel(px,     py + 1, on);
            oled_write_pixel(px + 1, py + 1, on);
        }
    }
}

/* Horizontally centered double-height string. */
static void draw_line_2x(uint8_t y, const char *s) {
    const uint8_t len   = strlen(s);
    const uint8_t width = len * 12;
    uint8_t       x     = (width >= OLED_DISPLAY_WIDTH) ? 0 : (OLED_DISPLAY_WIDTH - width) / 2;

    for (uint8_t i = 0; i < len; i++) {
        draw_char_2x(x + (i * 12), y, s[i]);
    }
}

/* Draw a string, stacking it on two lines at the first space when both halves
 * fit; otherwise one centered line. */
static void draw_text_2x(const char *s) {
    const char *space = strchr(s, ' ');

    if (space != NULL) {
        const uint8_t first  = (uint8_t)(space - s);
        const uint8_t second = strlen(space + 1);

        if (first > 0 && first <= OLED_2X_COLS && second > 0 && second <= OLED_2X_COLS) {
            char head[OLED_2X_COLS + 1];
            memcpy(head, s, first);
            head[first] = '\0';

            draw_line_2x(0,  head);        // two stacked lines fill the 32px height
            draw_line_2x(16, space + 1);
            return;
        }
    }

    draw_line_2x(8, s);                    // one line, vertically centered
}

bool oled_task_user(void) {
    static uint8_t     last_layer = 0xFF;
    static const char *last_shown = NULL;

    const uint8_t layer = get_highest_layer(layer_state);

    /* A pressed key takes the screen briefly, then it reverts to the layer. */
    if (key_flash_label != NULL && timer_elapsed32(key_flash_time) >= KEY_FLASH_MS) {
        key_flash_label = NULL;
    }

    if (layer != last_layer || key_flash_label != last_shown) {
        last_layer = layer;
        last_shown = key_flash_label;

        oled_clear();
        if (key_flash_label != NULL) {
            draw_text_2x(key_flash_label);
        } else {
            draw_text_2x(layer < ARRAY_SIZE(layer_names) && layer_names[layer] != NULL
                             ? layer_names[layer]
                             : "Layer ?");
        }
    }

    return false;
}
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_F18, KC_F19), ENCODER_CCW_CW(KC_F20, KC_F21), ENCODER_CCW_CW(KC_F22, KC_F23) },
    [2] = { ENCODER_CCW_CW(G(KC_PGUP), G(KC_PGDN)), ENCODER_CCW_CW(C(KC_PGUP), C(KC_PGDN)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [5] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
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
#ifdef OLED_ENABLE
    /* Flash the friendly name of whatever was just pressed. Only the 4x4 grid
     * (cols 0-3); col 4 is the knob presses, which are left to show the layer. */
    if (record->event.pressed) {
        const uint8_t layer = get_highest_layer(layer_state);
        const uint8_t row   = record->event.key.row;
        const uint8_t col   = record->event.key.col;

        if (layer < ARRAY_SIZE(key_labels) && row < 4 && col < 4 && key_labels[layer][row][col] != NULL) {
            key_flash_label = key_labels[layer][row][col];
            key_flash_time  = timer_read32();
        }
    }
#endif

    switch (keycode) {
        case CYCLE_LAYER:
            if (record->event.pressed) {
                uint8_t layer = get_highest_layer(layer_state);
                layer_move((layer + 1) % 6);
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

/* RGB is owned by Vial (VIALRGB_ENABLE). No per-layer coloring here by design:
 * pick effects/colors live in the Vial GUI. The old palette + per-key override
 * table lives in rgb_layer_config.h, now unreferenced, if it is ever wanted back.
 */
