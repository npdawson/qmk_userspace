#include <stdint.h>
#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"

#include "keymap_japanese.h"

#define LGTA LGUI_T(KC_A)
#define LATS LALT_T(KC_S)
#define LCTD LCTL_T(KC_D)
#define LSTF LSFT_T(KC_F)
#define RSTJ RSFT_T(KC_J)
#define RCTK RCTL_T(KC_K)
#define RATL RALT_T(KC_L)
#define RGTSC RGUI_T(KC_SCLN)
#define G_NUM LT(_NUM, KC_G)

#define LGTS LGUI_T(KC_S)
#define LATN LALT_T(KC_N)
#define LCTT LCTL_T(KC_T)
#define LSTH LSFT_T(KC_H)
#define RSTA RSFT_T(KC_A)
#define RCTE RCTL_T(KC_E)
#define RATI RALT_T(KC_I)
#define RGTC RGUI_T(KC_C)
#define K_NUM LT(_NUM, KC_K)

#define MHK_SYM LT(_SYM, JP_MHEN)
#define HEN_FUN LT(_FUN, JP_HENK)

enum layers {
    _HD_PM,
    _QWERTY,
    _GAME,
    _TYPING,
    _NUM,
    _NAV,
    _FUN,
    _SYM
};

enum custom_keycodes {
    DCOLON = SAFE_RANGE,
    UPDIR,
};

const uint16_t PROGMEM combo_q[] = {KC_V, KC_W, COMBO_END};
const uint16_t PROGMEM combo_z[] = {KC_F, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_q, KC_Q),
    COMBO(combo_z, KC_Z),
};

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_EXLM},
    {KC_COMM, KC_QUES},
    {KC_SLSH, KC_BSLS},
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_HD_PM] = LAYOUT_split_4x6_5(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, JP_KANA,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_TAB, KC_V, KC_W, KC_G, KC_M, KC_J, KC_SCLN, KC_DOT, KC_QUOT, KC_SLSH, KC_EQL, KC_PIPE,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_ESC, LGTS, LATN, LCTT, LSTH, K_NUM, KC_COMM, RSTA, RCTE, RATI, RGTC, CW_TOGG,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_LPRN, KC_F, KC_P, KC_D, KC_L, KC_X, KC_MINS, KC_U, KC_O, KC_Y, KC_B, KC_RPRN,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_BSPC, KC_R, KC_DEL, KC_ESC, KC_SPC, KC_ENT, MO(_NAV), MHK_SYM, HEN_FUN, MO(_SYM)),

    [_QWERTY] = LAYOUT_split_4x6_5(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_ESC, LGTA, LATS, LCTD, LSTF, G_NUM, KC_H, RSTJ, RCTK, RATL, RGTSC, KC_QUOT,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             CW_TOGG, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_BSPC, KC_SPC, KC_DEL, KC_ESC, KC_SPC, KC_ENT, MO(_NAV), MHK_SYM, HEN_FUN, MO(_SYM)),

    [_GAME] = LAYOUT_split_4x6_5(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             _______, KC_A, KC_S, KC_D, KC_F, KC_G, _______, KC_J, KC_K, KC_L, KC_SCLN, _______,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, KC_LSFT, KC_LCTL, _______, _______),

    [_TYPING] = LAYOUT_split_4x6_5(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, JP_KANA,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_TAB, KC_V, KC_W, KC_G, KC_M, KC_J, KC_SCLN, KC_DOT, KC_QUOT, KC_SLSH, KC_EQL, KC_PIPE,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_ESC, KC_S, KC_N, KC_T, KC_H, KC_K, KC_COMM, KC_A, KC_E, KC_I, KC_C, CW_TOGG,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_LPRN, KC_F, KC_P, KC_D, KC_L, KC_X, KC_MINS, KC_U, KC_O, KC_Y, KC_B, KC_RPRN,
                             //-------------------------------------------------//-----------------------------------------------------------//
                             KC_BSPC, KC_R, KC_DEL, KC_ESC, KC_SPC, KC_ENT, MO(_NAV), MHK_SYM, HEN_FUN, MO(_SYM)),

    [_NUM] = LAYOUT_split_4x6_5(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             QK_BOOT, _______, _______, _______, _______, KC_LBRC, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PLUS,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END, _______, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PIPE,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, KC_NUM, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_UNDS,
                             //---------------------------------------------------------//-----------------------------------------------------------//
                             _______, _______, _______, _______, KC_P0, KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    [_NAV] = LAYOUT_split_4x6_5(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______, _______, _______, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, KC_MUTE,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, KC_VOLU,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B), _______, _______, _______, _______, _______, KC_VOLD,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX),

    [_FUN] = LAYOUT_split_4x6_5(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, KC_F5, KC_F6, KC_F7, KC_F8, KC_SCRL, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, KC_F9, KC_F10, KC_F11, KC_F12, KC_BRK, _______, _______, DF(_TYPING), DF(_HD_PM), DF(_QWERTY), TG(_GAME),
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX),

    [_SYM] = LAYOUT_split_4x6_5(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, KC_QUOT, KC_LT, KC_GT, KC_DQUO, KC_DOT, KC_AMPR, KC_AT, KC_LBRC, KC_RBRC, KC_PERC, KC_UNDS,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL, KC_HASH, KC_PIPE, KC_CIRC, KC_LPRN, KC_RPRN, KC_COLN, DCOLON,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, XXXXXXX, KC_SLSH, KC_ASTR, KC_BSLS, UPDIR, KC_TILD, KC_DLR, KC_LCBR, KC_RCBR, KC_QUES, KC_PIPE,
                             //---------------------------------------------------------//--------------------------------------------------------------//
                             _______, _______, _______, _______, _______, _______, XXXXXXX, _______, XXXXXXX, _______),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_4x6_5(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
             '*', '*', '*', '*', '*',  '*', '*', '*', '*', '*'
);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
        case DCOLON:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            break;
        case UPDIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            break;
    }
    return true;
}
