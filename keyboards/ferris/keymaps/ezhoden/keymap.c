#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  QWERTY,
  _LOWER,
  _RAISE
};

enum ferris_tap_dances {
  TD_Q_ESC,
  TD_A_TAB
};

// Tap dance key code definitions
#define KC_QESC TD(TD_Q_ESC)
#define KC_ATAB TD(TD_A_TAB)
#define KC_SCLE TD(TD_SEMICOLON_ENTER)

// Layers key code definitions
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)

// Modificators key code definitions

    // Win modificator
    #define KC_GGUI GUI_T(KC_G)
    #define KC_HGUI GUI_T(KC_H)

    // Shift modificator
    #define KC_LRSH RSFT_T(KC_L)
    #define KC_SSFT LSFT_T(KC_S)

    // Ctrl modificator
    #define KC_KCTL RCTL_T(KC_SCLN)
    #define KC_CLGV CTL_T(KC_GRV)

    // Alt modificator
    #define KC_FALT ALT_T(KC_F)
    #define KC_JALT ALT_T(KC_J)


// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT( /* QWERTY */
    KC_QESC, KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    KC_ATAB, KC_SSFT, KC_D,    KC_FALT, KC_GGUI,         KC_HGUI,    KC_JALT,  KC_KCTL,    KC_LRSH,   KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                                    KC_CLGV, KC_SPM2, KC_BSM1, KC_ENT
  ),

  [_LOWER] = LAYOUT( /* LOWER */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_ESC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BSLS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_RAISE] = LAYOUT( /* RAISE */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,         KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

// Tap dance actions definition
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
};
