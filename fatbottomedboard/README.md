# Firmware mod
Firmware for FatBottomedBoard

## Links 
- Hints on classics layouts http://www.quadibloc.com/comp/kyb0301.htm  
- QMK Keyboard firmware builder https://kbfirmware.com/  

## Notes
QMK keyboard firmware builder is way better than TMK counterpart, use it to define wirings and create C defines
and `KEYMAP()` proper mappings. Later on you might adapt generated code to TMK firmware. Just take a look at
`kb.h` and `kb.c` generated files.  
**qmk.config.json** was generated from https://kbfirmware.com/, you might use it again and return
to that site to load configuration and alter it if needed.
