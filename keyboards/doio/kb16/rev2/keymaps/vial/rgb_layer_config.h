#pragma once
#include QMK_KEYBOARD_H

// ----- Neutral / utility -----
#define C_OFF        (HSV){ .h = 0,   .s = 0,   .v = 0   }
#define C_DIM_WHITE  (HSV){ .h = 0,   .s = 0,   .v = 80  }
#define C_WHITE      (HSV){ .h = 0,   .s = 0,   .v = 255 }

// ----- Primary colors -----
#define C_RED        (HSV){ .h = 0,   .s = 255, .v = 180 }
#define C_GREEN      (HSV){ .h = 85,  .s = 255, .v = 180 }
#define C_BLUE       (HSV){ .h = 170, .s = 255, .v = 180 }

// ----- Secondary colors -----
#define C_YELLOW     (HSV){ .h = 43,  .s = 255, .v = 200 }
#define C_CYAN       (HSV){ .h = 128, .s = 255, .v = 180 }
#define C_MAGENTA    (HSV){ .h = 213, .s = 255, .v = 180 }

// ----- Warm / accent -----
#define C_ORANGE     (HSV){ .h = 21,  .s = 255, .v = 220 }
#define C_AMBER      (HSV){ .h = 32,  .s = 255, .v = 220 }
#define C_PINK       (HSV){ .h = 235, .s = 200, .v = 220 }

// ----- Cool / muted -----
#define C_TEAL       (HSV){ .h = 100, .s = 200, .v = 180 }
#define C_AQUA       (HSV){ .h = 120, .s = 180, .v = 200 }
#define C_INDIGO     (HSV){ .h = 191, .s = 255, .v = 160 }
#define C_PURPLE     (HSV){ .h = 191, .s = 255, .v = 180 }
#define C_LAVENDER   (HSV){ .h = 200, .s = 120, .v = 200 }

// ----- Status / semantic -----
#define C_SUCCESS    C_GREEN
#define C_WARNING    C_AMBER
#define C_ERROR      C_RED
#define C_INFO       C_CYAN

// ----- Base color per layer -----
static const HSV layer_base_hsv[] PROGMEM = {
    [0] = C_OFF,
    [1] = C_TEAL,
    [2] = C_PURPLE,
    [3] = C_CYAN,
    [4] = C_OFF,
    // Any unspecified layer defaults elsewhere
};

// One override entry = "On layer L, set key (row,col) to color"
typedef struct {
    uint8_t layer;
    uint8_t row;
    uint8_t col;
    HSV     hsv;
} layer_key_hsv_t;

// ----- Per-key overrides table -----
// Add/remove lines here; no code changes elsewhere.
static const layer_key_hsv_t layer_key_overrides[] PROGMEM = {
    // Primary Layer 0
    { 0, 2, 0, C_YELLOW },  // WORK SCENE (HYPR+F13)
    { 0, 0, 3, C_GREEN },     // Video/no-Video
    { 0, 0, 2, C_OFF },    // NO-OP
    { 0, 0, 1, C_OFF },    // NO-OP
    { 0, 0, 0, C_INDIGO }, // Mute/Un-Mute
    
    { 0, 1, 3, C_RED }, // BOOT / RESET
    { 0, 1, 2, C_OFF }, // NO-OP
    { 0, 1, 1, C_OFF }, // NO-OP
    { 0, 1, 0, C_OFF }, // NO-OP
    
    { 0, 2, 3, C_OFF }, // NO-OP
    { 0, 2, 2, C_OFF }, // NO-OP
    { 0, 2, 1, C_OFF }, // NO-OP
    
    { 0, 3, 3, C_YELLOW },  // DEADWOOD (HYPR+F17)
    { 0, 3, 2, C_RED },   // ZOOM (HYPR+F15)
    { 0, 3, 1, C_GREEN }, // SLACK (HYPR+F16)
    { 0, 3, 0, C_BLUE },  // OUTLOOK (HYPR+F14)

    // Primary Layer 1 - Windows test layer
    { 1, 0, 0, C_YELLOW },   // Steam overlay back (Shift+Tab)
    { 1, 0, 1, C_RED },      // Screenshot (F12)
    { 1, 0, 2, C_GREEN },    // Mark clip (Ctrl+F10)
    { 1, 0, 3, C_PURPLE },   // Start Discord stream (Alt+Ctrl+U)
    
    { 1, 1, 0, C_OFF },      // NO-OP
    { 1, 1, 1, C_OFF },      // NO-OP
    { 1, 1, 2, C_OFF },      // NO-OP
    { 1, 1, 3, C_OFF },      // NO-OP
    
    { 1, 2, 0, C_GREEN },    // F13 spare / game launch-ish
    { 1, 2, 1, C_OFF },      // NO-OP
    { 1, 2, 2, C_OFF },      // NO-OP
    { 1, 2, 3, C_OFF },      // NO-OP
    
    { 1, 3, 0, C_PINK },     // Discord mute
    { 1, 3, 1, C_BLUE },     // F14
    { 1, 3, 2, C_PURPLE },   // F15
    { 1, 3, 3, C_AMBER },    // F16
    { 1, 0, 4, C_YELLOW },   // Cycle layers button
    { 1, 2, 4, C_RED },      // Input 2 mute

    // Primary Layer 2
    { 2, 0, 0, C_OFF }, // NO-OP
    { 2, 0, 1, C_OFF }, // NO-OP
    { 2, 0, 2, C_OFF }, // NO-OP
    { 2, 0, 3, C_OFF }, // NO-OP
    
    { 2, 1, 0, C_OFF }, // NO-OP
    { 2, 1, 1, C_OFF }, // NO-OP
    { 2, 1, 2, C_OFF }, // NO-OP
    { 2, 1, 3, C_OFF }, // NO-OP
    
    { 2, 2, 0, C_OFF }, // NO-OP
    { 2, 2, 1, C_OFF }, // NO-OP
    { 2, 2, 2, C_OFF }, // NO-OP
    { 2, 2, 3, C_OFF }, // NO-OP
    
    { 2, 3, 0, C_OFF }, // NO-OP
    { 2, 3, 1, C_OFF }, // NO-OP
    { 2, 3, 2, C_OFF }, // NO-OP
    { 2, 3, 3, C_OFF }, // NO-OP
    
    // XCODE Layer 4
    { 4, 0, 0, C_RED },   // BUILD
    { 4, 0, 1, C_AMBER }, // TEST
    { 4, 0, 2, C_GREEN }, // RUN
    { 4, 0, 3, C_RED },   // STOP

    { 3, 0, 3, C_RED }, // BOOTLOADER
};
