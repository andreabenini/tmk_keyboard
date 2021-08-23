/*
Copyright 2013 Jun Wako <wakojun@gmail.com>

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
#ifndef ACTION_CODE_H
#define ACTION_CODE_H

/* Action codes
 * ============
 * 16bit code: action_kind(4bit) + action_parameter(12bit)
 *
 *
 * Key Actions(00xx)
 * -----------------
 * ACT_MODS(000r):
 * 000r|0000|0000 0000    No action code
 * 000r|0000|0000 0001    Transparent code
 * 000r|0000| keycode     Key
 * 000r|mods|0000 0000    Modifiers
 * 000r|mods| keycode     Modifiers+key(Modified key)
 *   r: Left/Right flag(Left:0, Right:1)
 *
 * ACT_MODS_TAP(001r):
 * 001r|mods|0000 0000    Modifiers with OneShot[TAP]
 * 001r|mods|0000 0001    Modifiers with tap toggle[TAP]
 * 001r|mods|0000 00xx    (reserved)            (0x02-03)
 * 001r|mods| keycode     Modifiers with tap key[TAP]
 *
 *
 * Other Keys(01xx)
 * ----------------
 * ACT_USAGE(0100): TODO: Not needed?
 * 0100|00| usage(10)     System control(0x80) - General Desktop page(0x01)
 * 0100|01| usage(10)     Consumer control(0x01) - Consumer page(0x0C)
 * 0100|10| usage(10)     (reserved)
 * 0100|11| usage(10)     (reserved)
 *
 * ACT_MOUSEKEY(0101): TODO: Not needed?
 * 0101|xxxx| keycode     Mouse key
 *
 * 011x|xxxx xxxx xxxx    (reseved)
 *
 *
 * Layer Actions(10xx)
 * -------------------
 * ACT_LAYER(1000):
 * 1000|oo00|pppE BBBB   Default Layer Bitwise operation
 *   oo:    operation(00:AND, 01:OR, 10:XOR, 11:SET)
 *   ppp:   4-bit chunk part(0-7)
 *   EBBBB: bits and extra bit
 * 1000|ooee|pppE BBBB   Layer Bitwise Operation
 *   oo:    operation(00:AND, 01:OR, 10:XOR, 11:SET)
 *   ppp:   4-bit chunk part(0-7)
 *   EBBBB: bits and extra bit
 *   ee:    on event(01:press, 10:release, 11:both)
 *
 * 1001|xxxx|xxxx xxxx   (reserved)
 * 1001|oopp|BBBB BBBB   8-bit Bitwise Operation???
 *
 * ACT_LAYER_TAP(101x):
 * 101E|LLLL| keycode    On/Off with tap key    [TAP]
 * 101E|LLLL|110r mods   On/Off with modifiers  (0xC0-DF)[NOT TAP]
 *                       r: Left/Right flag(Left:0, Right:1)
 * 101E|LLLL|1111 0000   Invert with tap toggle (0xF0)   [TAP]
 * 101E|LLLL|1111 0001   On/Off                 (0xF1)   [NOT TAP]
 * 101E|LLLL|1111 0010   Off/On                 (0xF2)   [NOT TAP]
 * 101E|LLLL|1111 0011   Set/Clear              (0xF3)   [NOT TAP]
 * 101E|LLLL|1111 xxxx   (reserved)             (0xF4-FF)
 *   ELLLL: layer 0-31(E: extra bit for layer 16-31)
 *
 *
 * Extensions(11xx)
 * ----------------
 * ACT_MACRO(1100):
 * 1100|opt | id(8)      Macro play?
 * 1100|1111| id(8)      Macro record?
 *
 * ACT_BACKLIGHT(1101):
 * 1101|opt |level(8)    Backlight commands
 *
 * ACT_COMMAND(1110):
 * 1110|opt | id(8)      Built-in Command exec
 *
 * ACT_FUNCTION(1111):
 * 1111| address(12)     Function?
 * 1111|opt | id(8)      Function?
 */
enum action_kind_id {
    /* Key Actions */
    ACT_MODS            = 0b0000,
    ACT_LMODS           = 0b0000,
    ACT_RMODS           = 0b0001,
    ACT_MODS_TAP        = 0b0010,
    ACT_LMODS_TAP       = 0b0010,
    ACT_RMODS_TAP       = 0b0011,
    /* Other Keys */
    ACT_USAGE           = 0b0100,
    ACT_MOUSEKEY        = 0b0101,
    /* Layer Actions */
    ACT_LAYER           = 0b1000,
    ACT_LAYER_TAP       = 0b1010, /* Layer  0-15 */
    ACT_LAYER_TAP_EXT   = 0b1011, /* Layer 16-31 */
    /* Extensions */
    ACT_MACRO           = 0b1100,
    ACT_BACKLIGHT       = 0b1101,
    ACT_COMMAND         = 0b1110,
    ACT_FUNCTION        = 0b1111
};


/* Action Code Struct
 *
 * NOTE:
 * In avr-gcc bit field seems to be assigned from LSB(bit0) to MSB(bit15).
 * AVR looks like a little endian in avr-gcc.
 * Not portable across compiler/endianness?
 *
 * Byte order and bit order of 0x1234:
 *   Big endian:                Little endian:
 *   --------------------       --------------------
 *   FEDC BA98  7654 3210       0123 4567  89AB CDEF
 *   0001 0010  0011 0100       0010 1100  0100 1000
 *     0x12       0x34            0x34       0x12
 */
typedef union {
    uint16_t code;
    struct action_kind {
        uint16_t param  :12;
        uint8_t  id     :4;
    } kind;
    struct action_key {
        uint8_t  code   :8;
        uint8_t  mods   :4;
        uint8_t  kind   :4;
    } key;
    struct action_layer_bitop {
        uint8_t  bits   :4;
        uint8_t  xbit   :1;
        uint8_t  part   :3;
        uint8_t  on     :2;
        uint8_t  op     :2;
        uint8_t  kind   :4;
    } layer_bitop;
    struct action_layer_tap {
        uint8_t  code   :8;
        uint8_t  val    :5;
        uint8_t  kind   :3;
    } layer_tap;
    struct action_usage {
        uint16_t code   :10;
        uint8_t  page   :2;
        uint8_t  kind   :4;
    } usage;
    struct action_backlight {
        uint8_t  level  :8;
        uint8_t  opt    :4;
        uint8_t  kind   :4;
    } backlight;
    struct action_command {
        uint8_t  id     :8;
        uint8_t  opt    :4;
        uint8_t  kind   :4;
    } command;
    struct action_function {
        uint8_t  id     :8;
        uint8_t  opt    :4;
        uint8_t  kind   :4;
    } func;
} action_t;


/* action utility */
#define ACTION_NO                       { .code = 0 }
#define ACTION_TRANSPARENT              { .code = 1 }
#define ACTION(kind, param)             { .code = ((kind)<<12 | (param)) }


/*
 * Key Actions
 */
/* Mod bits:    43210
 *   bit 0      ||||+- Control
 *   bit 1      |||+-- Shift
 *   bit 2      ||+--- Alt
 *   bit 3      |+---- Gui
 *   bit 4      +----- LR flag(Left:0, Right:1)
 */
enum mods_bit {
    MOD_NONE = 0x0000,
    MOD_LCTL = 0x0100,
    MOD_LSFT = 0x0200,
    MOD_LALT = 0x0400,
    MOD_LGUI = 0x0800,
    MOD_RCTL = 0x1100,
    MOD_RSFT = 0x1200,
    MOD_RALT = 0x1400,
    MOD_RGUI = 0x1800,
};
enum mods_codes {
    MODS_ONESHOT = 0x00,
    MODS_TAP_TOGGLE = 0x01,
};
#define ACTION_KEY(key)                 ACTION(ACT_MODS, (key))
#define ACTION_MODS(mods)               ACTION(ACT_MODS, ((mods)&0x1f00) | 0)
#define ACTION_MODS_KEY(mods, key)      ACTION(ACT_MODS, ((mods)&0x1f00) | (key))
#define ACTION_MODS_TAP_KEY(mods, key)  ACTION(ACT_MODS_TAP, ((mods)&0x1f00) | (key))
#define ACTION_MODS_ONESHOT(mods)       ACTION(ACT_MODS_TAP, ((mods)&0x1f00) | MODS_ONESHOT)
#define ACTION_MODS_TAP_TOGGLE(mods)    ACTION(ACT_MODS_TAP, ((mods)&0x1f00) | MODS_TAP_TOGGLE)


/*
 * Other Keys
 */
enum usage_pages {
    PAGE_SYSTEM,
    PAGE_CONSUMER
};
#define ACTION_USAGE_SYSTEM(id)         ACTION(ACT_USAGE, PAGE_SYSTEM<<10 | (id))
#define ACTION_USAGE_CONSUMER(id)       ACTION(ACT_USAGE, PAGE_CONSUMER<<10 | (id))
#define ACTION_MOUSEKEY(key)            ACTION(ACT_MOUSEKEY, key)



/* 
 * Layer Actions
 */
enum layer_param_on {
    ON_PRESS    = 1,
    ON_RELEASE  = 2,
    ON_BOTH     = 3,
};
enum layer_param_bit_op {
    OP_BIT_AND = 0,
    OP_BIT_OR  = 1,
    OP_BIT_XOR = 2,
    OP_BIT_SET = 3,
};
enum layer_pram_tap_op {
    OP_TAP_TOGGLE = 0xF0,
    OP_ON_OFF,
    OP_OFF_ON,
    OP_SET_CLEAR,
};
#define ACTION_LAYER_BITOP(op, part, bits, on)      ACTION(ACT_LAYER, (op)<<10 | (on)<<8 | (part)<<5 | ((bits)&0x1f))
#define ACTION_LAYER_TAP(layer, key)                ACTION(ACT_LAYER_TAP, (layer)<<8 | (key))
/* Default Layer */
#define ACTION_DEFAULT_LAYER_SET(layer)             ACTION_DEFAULT_LAYER_BIT_SET((layer)/4, 1<<((layer)%4))
#define ACTION_DEFAULT_LAYER_TOGGLE(layer)          ACTION_DEFAULT_LAYER_BIT_XOR((layer)/4, 1<<((layer)%4))
/* Layer Operation */
#define ACTION_LAYER_CLEAR(on)                      ACTION_LAYER_BIT_AND(0, 0, (on))
#define ACTION_LAYER_MOMENTARY(layer)               ACTION_LAYER_ON_OFF(layer)
#define ACTION_LAYER_TOGGLE(layer)                  ACTION_LAYER_INVERT(layer, ON_RELEASE)
#define ACTION_LAYER_INVERT(layer, on)              ACTION_LAYER_BIT_XOR((layer)/4,   1<<((layer)%4),  (on))
#define ACTION_LAYER_ON(layer, on)                  ACTION_LAYER_BIT_OR( (layer)/4,   1<<((layer)%4),  (on))
#define ACTION_LAYER_OFF(layer, on)                 ACTION_LAYER_BIT_AND((layer)/4, ~(1<<((layer)%4)), (on))
#define ACTION_LAYER_SET(layer, on)                 ACTION_LAYER_BIT_SET((layer)/4,   1<<((layer)%4),  (on))
#define ACTION_LAYER_ON_OFF(layer)                  ACTION_LAYER_TAP((layer), OP_ON_OFF)
#define ACTION_LAYER_OFF_ON(layer)                  ACTION_LAYER_TAP((layer), OP_OFF_ON)
#define ACTION_LAYER_SET_CLEAR(layer)               ACTION_LAYER_TAP((layer), OP_SET_CLEAR)
#define ACTION_LAYER_MODS(layer, mods)              ACTION_LAYER_TAP((layer), 0xc0 | (((mods)>>8)&0x1f))
/* With Tapping */
#define ACTION_LAYER_TAP_KEY(layer, key)            ACTION_LAYER_TAP((layer), (key))
#define ACTION_LAYER_TAP_TOGGLE(layer)              ACTION_LAYER_TAP((layer), OP_TAP_TOGGLE)
/* Bitwise Operation */
#define ACTION_LAYER_BIT_AND(part, bits, on)        ACTION_LAYER_BITOP(OP_BIT_AND, (part), (bits), (on))
#define ACTION_LAYER_BIT_OR( part, bits, on)        ACTION_LAYER_BITOP(OP_BIT_OR,  (part), (bits), (on))
#define ACTION_LAYER_BIT_XOR(part, bits, on)        ACTION_LAYER_BITOP(OP_BIT_XOR, (part), (bits), (on))
#define ACTION_LAYER_BIT_SET(part, bits, on)        ACTION_LAYER_BITOP(OP_BIT_SET, (part), (bits), (on))
/* Default Layer Bitwise Operation */
#define ACTION_DEFAULT_LAYER_BIT_AND(part, bits)    ACTION_LAYER_BITOP(OP_BIT_AND, (part), (bits), 0)
#define ACTION_DEFAULT_LAYER_BIT_OR( part, bits)    ACTION_LAYER_BITOP(OP_BIT_OR,  (part), (bits), 0)
#define ACTION_DEFAULT_LAYER_BIT_XOR(part, bits)    ACTION_LAYER_BITOP(OP_BIT_XOR, (part), (bits), 0)
#define ACTION_DEFAULT_LAYER_BIT_SET(part, bits)    ACTION_LAYER_BITOP(OP_BIT_SET, (part), (bits), 0)


/*
 * Extensions
 */
/* Macro */
#define ACTION_MACRO(id)                ACTION(ACT_MACRO, (id))
#define ACTION_MACRO_TAP(id)            ACTION(ACT_MACRO, FUNC_TAP<<8 | (id))
#define ACTION_MACRO_OPT(id, opt)       ACTION(ACT_MACRO, (opt)<<8 | (id))

/* Backlight */
enum backlight_opt {
    BACKLIGHT_INCREASE = 0,
    BACKLIGHT_DECREASE = 1,
    BACKLIGHT_TOGGLE   = 2,
    BACKLIGHT_STEP     = 3,
    BACKLIGHT_LEVEL    = 4,
};
#define ACTION_BACKLIGHT_INCREASE()     ACTION(ACT_BACKLIGHT, BACKLIGHT_INCREASE << 8)
#define ACTION_BACKLIGHT_DECREASE()     ACTION(ACT_BACKLIGHT, BACKLIGHT_DECREASE << 8)
#define ACTION_BACKLIGHT_TOGGLE()       ACTION(ACT_BACKLIGHT, BACKLIGHT_TOGGLE << 8)
#define ACTION_BACKLIGHT_STEP()         ACTION(ACT_BACKLIGHT, BACKLIGHT_STEP << 8)
#define ACTION_BACKLIGHT_LEVEL(level)   ACTION(ACT_BACKLIGHT, BACKLIGHT_LEVEL << 8 | level)

/* Command */
enum command_ids {
    COMMAND_BOOTLOADER, // jump to bootloader
};
#define ACTION_COMMAND(id, opt)         ACTION(ACT_COMMAND,  (opt)<<8 | (id))

/* Function */
enum function_opts {
    FUNC_TAP = 0x8,     /* indciates function is tappable */
};
#define ACTION_FUNCTION(id)             ACTION(ACT_FUNCTION, (id))
#define ACTION_FUNCTION_TAP(id)         ACTION(ACT_FUNCTION, FUNC_TAP<<8 | (id))
#define ACTION_FUNCTION_OPT(id, opt)    ACTION(ACT_FUNCTION, (opt)<<8 | (id))

#endif /* ACTION_CODE_H */
