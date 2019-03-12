#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮ ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │ │   Y  │   U  │   I  │   O  │   P  │  Å   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Esc  │   A  │   S  │   D  │   F  │   G  │ │   H  │   J  │   K  │   L  │   Ö  │  Ä   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│   Z  │   X  │   C  │   V  │   B  │ │   N  │   M  │   ,  │   .  │   -  │  =   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │   /  │ Alt  │Super │Lower │Space │ │Enter │Raise │ Bksp │   {  │   }  │  '   │
 * ╰──────┴──────┴──────┴──────┴──────┴──────╯ ╰──────┴──────┴──────┴──────┴──────┴──────╯
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T    ,  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , NO_AA  , \
   KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G    ,  KC_H   , KC_J   , KC_K   , KC_L   , NO_OSLH, NO_AE  , \
   KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B    ,  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, NO_EQL , \
   KC_LCTL, NO_SLSH, KC_LALT, KC_LGUI, LOWER  , KC_SPC  ,  KC_ENT , RAISE  , KC_BSPC, NO_LCBR, NO_RCBR, NO_APOS  \
),

/* Lower
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮ ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │Reset │      │      │      │      │      │ │  +   │  [   │  ]   │  "   │  &   │  $   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │ │  -   │  (   │  )   │  `   │  |   │  %   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │ │  *   │  <   │  >   │  !   │  ~   │  #   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │      │ Alt  │Super │██████│      │ │  ?   │Raise │  \   │  @   │  ^   │      │
 * ╰──────┴──────┴──────┴──────┴──────┴──────╯ ╰──────┴──────┴──────┴──────┴──────┴──────╯
 */

[_LOWER] = LAYOUT_ortho_4x12( \
  RESET  , _______, _______, _______, _______, _______  ,  NO_PLUS, NO_LBRC, NO_RBRC, NO_QUO2, NO_AMPR, NO_DLR , \
  _______, _______, _______, _______, _______, _______  ,  NO_MINS, NO_LPRN, NO_RPRN, NO_GRV , NO_PIPE, KC_PERC, \
  _______, _______, _______, _______, _______, _______  ,  NO_ASTR, NO_LESS, NO_GRTR, KC_EXLM, NO_TILD, KC_HASH, \
  _______, _______, _______, _______, _______, _______  ,  NO_QUES, _______, NO_BSLS, NO_AT  , NO_CIRC, _______  \
),

/* Raise
 * ╭──────┬──────┬──────┬──────┬──────┬──────╮ ╭──────┬──────┬──────┬──────┬──────┬──────╮
 * │      │   1  │   2  │   3  │   4  │   5  │ │   6  │   7  │   8  │   9  │   0  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │ │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ PgDn │  Up  │ PgUp │Insert│ Home │ │      │ Del  │ Vol+ │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Left │ Down │Right │Lower │ End  │ │      │██████│ Vol- │ Mute │      │      │
 * ╰──────┴──────┴──────┴──────┴──────┴──────╯ ╰──────┴──────┴──────┴──────┴──────┴──────╯
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5     ,  KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, \
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6    ,  KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12,  \
  _______, KC_PGDN, KC_UP  , KC_PGUP, KC_INS,  KC_HOME  ,  _______, KC_DEL , KC_VOLU, _______, _______, _______, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_END   ,  _______, _______, KC_VOLD, KC_MUTE, _______, _______  \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
  }
  return true;
}
