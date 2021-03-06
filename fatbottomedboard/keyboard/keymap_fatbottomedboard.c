/**
 * Copyright 2020 Andrea Benini <andreabenini ~at~ gmail>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * Keymap for FatBottomedBoard mod
 */
#include "keymap_fatbottomedboard.h"


/**
 *    [FatBottomedBoard Layout Template]      { 119 keymap, 20x6 }
 * 
 *    ,---------.   ,---.   ,---,---,---,---.  ,---,---,---,---.  ,---,---,---,---.  ,---,---,---.  ,---,---,---,---.
 *    |   WWW   |   |Esc|   | F1| F2| F3| F4|  | F5| F6| F7| F8|  | F9|F10|F11|F12|  |Prt|Lck|Mut|  |  1|  2|  3|  4|
 *    `---------'   `---'   `---'---'---'---'  `---'---'---'---'  `---'---'---'---'  `---'---'---'  `---'---'---'---'
 *    ,---------.   ,---.---.---.---.---.---.---.---.---.---.---.---.---.---------.  ,---,---,---.  ,---,---,---,---.
 *    |Undo|Redo|   | ~ |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BackSp |  |Ins|Hom|PgU|  |Num| / | * | - |
 *    |----+----'   .-------------------------------------------------------------'  .---+---+---'  '---+---+---+---'
 *    |Term|Code|   | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|   \   |  |Del|End|PgD|  |  7|  8|  9|   |
 *    |----+----'   .-------------------------------------------------------------'  `---'---'---'  '---+---+---| + |
 *    |Cut |Open|   | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|   Enter  |                 |  4|  5|  6|   |
 *    |----+----'   .-------------------------------------------------------------'      ,---.      '---+---+---+---'
 *    |Copy|Clos|   | Shift |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|    Shift    |      | ^ |      |  1|  2|  3|   |
 *    |----+----'   .----,----,----,--------------------------.----.----.----.----.  ,---+---+---.  '---'---+---|Ent|
 *    |Past|Save|   |Ctrl|Alt |Cmd |         S p a c e        |AltG| FN |Cmp |Ctrl|  | < | ¥ | > |  |     0 | . |   |
 *    `----'----'   `----'----'----`--------------------------'----'----'----'----'  `---'---'---'  `-------'---'---'
 * 
 * 
 *    - ROW -  1   2   3   4   5   6
 *      pin   C2  C3  C4  C5  C6  C7
 * 
 *    - COL -  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20
 *      pin   F2  F1  F0  E6  E7  B0  B1  B2  B3  B4  B5  B6  B7  D4  D5  D7  E0  E1  C0  C1
 */


#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /**   [Layer 0]     { Default }
     * 
     *    ,---------.   ,---.   ,---,---,---,---.  ,---,---,---,---.  ,---,---,---,---.  ,---,---,---.  ,---,---,---,---.
     *    |   WWW   |   |Esc|   | F1| F2| F3| F4|  | F5| F6| F7| F8|  | F9|F10|F11|F12|  |Prt|Lck|Mut|  |  1|  2|  3|  4|   21
     *    `---------'   `---'   `---'---'---'---'  `---'---'---'---'  `---'---'---'---'  `---'---'---'  `---'---'---'---'
     *    ,---------.   ,---.---.---.---.---.---.---.---.---.---.---.---.---.---------.  ,---,---,---.  ,---,---,---,---.
     *    |Undo|Redo|   | ~ |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BackSp |  |Ins|Hom|PgU|  |Num| / | * | - |   23
     *    |----+----'   .-------------------------------------------------------------'  .---+---+---'  '---+---+---+---'
     *    |Term|Code|   | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|   \   |  |Del|End|PgD|  |  7|  8|  9|   |   23  <-(R2)
     *    |----+----'   .-------------------------------------------------------------'  `---'---'---'  '---+---+---| + |
     *    |Cut |Open|   | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|   Enter  |                 |  4|  5|  6|   |   18
     *    |----+----'   .-------------------------------------------------------------'      ,---.      '---+---+---+---'
     *    |Copy|Clos|   | Shift |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|    Shift    |      | ^ |      |  1|  2|  3|   |   19
     *    |----+----'   .----,----,----,--------------------------.----.----.----.----.  ,---+---+---.  '---'---+---|Ent|
     *    |Past|Save|   |Ctrl|Alt |Cmd |         S p a c e        |AltG| FN |Cmp |Ctrl|  | < | ¥ | > |  |     0 | . |   |   15
     *    `----'----'   `----'----'----`--------------------------'----'----'----'----'  `---'---'---'  `-------'---'---'
     */
    KEYMAP(
              MYCM,      ESC,     F1, F2, F3, F4,    F5, F6, F7, F8,    F9,F10,F11,F12,  PSCR,SLCK,MUTE,    1,  2,  3,   4,
           UNDO,AGAIN,   GRV,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0, MINS, EQL,  BSPC,  INS, HOME,PGUP, NLCK,PSLS,PAST,PMNS, 
             C,   D,     TAB,    Q,  W,  E,  R,  T,  Y,  U,  I,  O,  P, LBRC,RBRC,BSLS,  DEL, END, PGDN,   P7, P8, P9,  PPLS,
           CUT,   F,     CAPS,    A,  S,  D,  F,  G,  H,  J,  K,  L, SCLN, QUOT,   ENT,                    P4, P5, P6,  
           COPY,  G,     LSFT,     Z,  X,  C,  V,  B,  N,  M, COMM,DOT, SLSH,     RSFT,        UP,         P1, P2, P3,  PENT,
           PASTE, H,     LCTL, LALT, LGUI,          SPC,           RALT,RGUI, 0,  RCTL,  LEFT,DOWN,RGHT,   P0,     PDOT
    ),


	// KEYMAP(
	// 	KC_W, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RESET, KC_A, KC_1, KC_2, KC_3, KC_4, 
	// 	KC_A, KC_B, KC_GRV, KC_1, KC_2, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_BSPC, KC_PSCR, KC_PGUP, KC_PSLS, KC_PAST, KC_PMNS, 
	// 	KC_C, KC_D, KC_TAB, KC_Q, KC_W, KC_3, KC_R, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_EQL, KC_INS, KC_HOME, KC_NLCK, KC_P8, KC_P9, KC_PPLS, 
	// 	KC_E, KC_F, KC_CAPS, KC_A, KC_S, KC_E, KC_F, KC_T, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_RBRC, KC_DEL, KC_END, KC_P7, KC_P5, KC_P6, KC_PENT, 
	// 	KC_COPY, KC_G, KC_LSFT, KC_Z, KC_X, KC_D, KC_V, KC_G, KC_H, KC_M, KC_DOT, KC_SLSH, KC_LSFT, KC_ENT, KC_BSLS, KC_UP, KC_PGDN, KC_P4, KC_P3, KC_PDOT, 
	// 	KC_PASTE, KC_H, KC_LCTL, KC_LALT, KC_LGUI, KC_C, KC_SPC, KC_B, KC_N, KC_COMM, KC_RALT, KC_RGUI, KC_0, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P1, KC_P2, KC_P0),


    /* Layer 0: Default Layer                                           60
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|    15
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|    14
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |    13
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn0|    13
     * `-----------------------------------------------------------'
     *       |Alt|Gui  |         Space         |Gui  |Alt|               5
     *       `-------------------------------------------'
     */
    // KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,   
    //        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,       
    //        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,             
    //        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN0,             
    //             LALT,LGUI,          SPC,                RGUI,RALT),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
    // KEYMAP(PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,   
    //        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS, UP, TRNS, BSPC,      
    //        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT,            
    //        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS,            
    //             TRNS,TRNS,          TRNS,               TRNS,TRNS),


};



/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
    [0]  = ACTION_LAYER_MOMENTARY(1),
    [1]  = ACTION_LAYER_MOMENTARY(2),
    [2]  = ACTION_LAYER_MOMENTARY(3),
    [3]  = ACTION_LAYER_MOMENTARY(4),
    [4]  = ACTION_LAYER_MOMENTARY(5),
    [5]  = ACTION_LAYER_MOMENTARY(6),
    [6]  = ACTION_LAYER_MOMENTARY(7),
    [7]  = ACTION_LAYER_TOGGLE(1),
    [8]  = ACTION_LAYER_TOGGLE(2),
    [9]  = ACTION_LAYER_TOGGLE(3),
    [10] = ACTION_LAYER_TAP_TOGGLE(1),
    [11] = ACTION_LAYER_TAP_TOGGLE(2),
    [12] = ACTION_LAYER_TAP_TOGGLE(3),
    [13] = ACTION_LAYER_TAP_KEY(1, KC_BSLASH),
    [14] = ACTION_LAYER_TAP_KEY(2, KC_TAB),
    [15] = ACTION_LAYER_TAP_KEY(3, KC_ENTER),
    [16] = ACTION_LAYER_TAP_KEY(4, KC_SPACE),
    [17] = ACTION_LAYER_TAP_KEY(5, KC_SCOLON),
    [18] = ACTION_LAYER_TAP_KEY(6, KC_QUOTE),
    [19] = ACTION_LAYER_TAP_KEY(7, KC_SLASH),
    [20] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPACE),
    [21] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_SPACE),
    [22] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_QUOTE),
    [23] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENTER),
    [24] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
    [25] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_BSPACE),
    [26] = ACTION_MODS_ONESHOT(MOD_LCTL),
    [27] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ESC),
    [28] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPACE),
    [29] = ACTION_MODS_ONESHOT(MOD_LSFT),
    [30] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_GRAVE),
    [31] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_BSLASH),
};
#else
const action_t fn_actions[] PROGMEM = {
    [0]  = ACTION_LAYER_MOMENTARY(1),
};
#endif
