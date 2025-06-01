#include <stdint.h>
#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"

#define LGTA LGUI_T(KC_A)
#define LATS LALT_T(KC_S)
#define LCTD LCTL_T(KC_D)
#define LSTF LSFT_T(KC_F)
#define RSTJ RSFT_T(KC_J)
#define RCTK RCTL_T(KC_K)
#define RATL RALT_T(KC_L)
#define RGTSC RGUI_T(KC_SCLN)

#define LGTS LGUI_T(KC_S)
#define LATN LALT_T(KC_N)
#define LCTT LCTL_T(KC_T)
#define LSTH LSFT_T(KC_H)
#define RSTA RSFT_T(KC_A)
#define RCTE RCTL_T(KC_E)
#define RATI RALT_T(KC_I)
#define RGTC RGUI_T(KC_C)

#define G_NUM LT(_NUM, KC_G)
#define K_NUM LT(_NUM, KC_K)
#define DEL_SYM LT(_SYM, KC_DEL)
#define SPC_SYM LT(_SYM, KC_SPC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define R_NAV LT(_NAV, KC_R)
#define ESC_FUN LT(_FUN, KC_ESC)

#define HDPM DF(_PROMETH)
#define QWERTY DF(_QWERTY)
#define GAME TG(_GAME)

enum layer_names {
    _PROMETH,
    _QWERTY,
    _GAME,
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
    [_PROMETH] = LAYOUT_split_3x5_3(KC_V, KC_W, KC_G, KC_M, KC_J,     KC_SCLN, KC_DOT, KC_QUOT, KC_SLSH, KC_EQL,
                    //-------------------------------//-------------------------------------------//
                      LGTS, LATN, LCTT, LSTH, K_NUM,    KC_COMM, RSTA, RCTE, RATI, RGTC,
                    //-------------------------------//-------------------------------------------//
                      KC_F, KC_P, KC_D, KC_L, KC_X,     KC_MINS, KC_U, KC_O, KC_Y, KC_B,
                    //-------------------------------//-------------------------------------------//
                            KC_BSPC, R_NAV, DEL_SYM,    ESC_FUN, SPC_SYM, KC_ENT),

    [_QWERTY] = LAYOUT_split_3x5_3(KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P,
                    //-------------------------------//---------------------------------------//
                      LGTA, LATS, LCTD, LSTF, G_NUM,    KC_H, RSTJ, RCTK, RATL, RGTSC,
                    //-------------------------------//---------------------------------------//
                      KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                    //-------------------------------//---------------------------------------//
                          KC_BSPC, SPC_NAV, DEL_SYM,    ESC_FUN, SPC_SYM, KC_ENT),

    [_GAME] = LAYOUT_split_3x5_3(KC_Q, KC_W, KC_E, KC_R, KC_T,      KC_Y, KC_U, KC_I, KC_O, KC_P,
                    //-------------------------------//---------------------------------------//
                      KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K, KC_L, KC_SCLN,
                    //-------------------------------//---------------------------------------//
                      KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                    //-------------------------------//---------------------------------------//
                          KC_LCTL, KC_SPC, KC_LSFT,     ESC_FUN, SPC_SYM, KC_ENT),

    [_NUM] = LAYOUT_split_3x5_3(QK_BOOT, _______, _______, _______, _______,    KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
                   //--------------------------------------------//---------------------------------------//
                    KC_HOME, KC_PGUP, KC_PGDN, KC_END, _______,     KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
                   //--------------------------------------------//---------------------------------------//
                    _______, _______, _______, _______, _______,    KC_NUM, KC_P1, KC_P2, KC_P3, KC_PDOT,
                   //--------------------------------------------//---------------------------------------//
                                      _______, _______, _______,    KC_TAB, KC_P0, KC_PENT),

    [_NAV] = LAYOUT_split_3x5_3(A(KC_TAB), _______, KC_TAB, _______, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_MUTE,
                   //--------------------------------------------//----------------------------------------------//
                   C(KC_A), KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_VOLU,
                   //--------------------------------------------//----------------------------------------------//
                   C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B),     _______, _______, _______, _______, KC_VOLD,
                   //--------------------------------------------//----------------------------------------------//
                                      _______, _______, _______,    _______, _______, _______),

    [_FUN] = LAYOUT_split_3x5_3(KC_F1, KC_F2, KC_F3, KC_F4, KC_PSCR,       KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   //--------------------------------------//-------------------------------------------------//
                   KC_F5, KC_F6, KC_F7, KC_F8, KC_SCRL,        KC_INS, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
                   //--------------------------------------//-------------------------------------------------//
                   KC_F9, KC_F10, KC_F11, KC_F12, KC_BRK,      _______, _______, HDPM, QWERTY, GAME,
                   //--------------------------------------//-------------------------------------------------//
                               _______, _______, _______,      _______, _______, _______),

    [_SYM] = LAYOUT_split_3x5_3(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,  DCOLON, UPDIR, KC_LBRC, KC_RBRC, KC_EQL,
                   //-------------------------------------------//--------------------------------------------//
                   KC_GRV, KC_TILD, KC_LT, KC_GT, KC_HASH,     KC_PIPE, KC_CIRC, KC_LPRN, KC_RPRN, KC_QUOT,
                   //-------------------------------------------//--------------------------------------------//
                   KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, UPDIR,  KC_MINS, KC_DLR, KC_LCBR, KC_RCBR, KC_PIPE,
                   //-------------------------------------------//--------------------------------------------//
                                  _______, _______, CW_TOGG,   _______, CW_TOGG, _______),
};

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
