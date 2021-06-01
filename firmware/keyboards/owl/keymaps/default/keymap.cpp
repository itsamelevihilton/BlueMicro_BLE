/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

#if KEYBOARD_SIDE == LEFT

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
  KC_ESC, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    \
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    \
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    MOVE,    \
  KC_ESC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    SYMB,   KC_NO,\
   KC_NO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LWIN, KC_CAPS,\
                TROUBLE, KC_LALT, KC_LCTL, KC_BSPC,  KC_TAB,  KC_DEL,\
                                     NUMS,    MDIA,  KC_SPC,  KC_ENT\
    ));
void setupKeymap() {

  RotaryEncoder.begin(ENCODER_A_PIN, ENCODER_B_PIN);    // Initialize Encoder
  RotaryEncoder.setCallback(encoder_callback);    // Set callback
  RotaryEncoder.start();    // Start encoder

/*
uint32_t TEMPLATE[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
                                        KC_NO,   KC_NO,   KC_NO,   KC_NO\
);*/

uint32_t main[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_ESC, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    \
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    \
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    MOVE,    \
  KC_ESC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    SYMB,   KC_NO,\
   KC_NO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LWIN, KC_CAPS,\
                  KC_NO, KC_LALT, KC_LCTL, KC_BSPC,  KC_TAB,  KC_DEL,\
                                     NUMS,    MDIA,  KC_SPC,  KC_ENT \
);

uint32_t symb[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO, KC_BSLS, KC_UNDS, KC_LCBR, KC_RCBR,  KC_GRV,   KC_NO, \
    KC_NO,  KC_EQL, KC_MINS, KC_LBRC, KC_RBRC, KC_TILD,   KC_NO,   KC_NO,\
    KC_LSFT, KC_PIPE, KC_PLUS,   KC_LT,   KC_GT,   KC_NO, KC_LWIN, KC_CAPS,\
                      KC_NO, KC_LALT, KC_LCTL, KC_BSPC,  KC_TAB,  KC_DEL,\
                                         NUMS,    MDIA,  KC_SPC,  KC_ENT \
);

uint32_t game[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_ESC, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    \
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    \
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    MOVE,    \
  KC_ESC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    SYMB,   KC_NO,\          
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LWIN, KC_CAPS,\
                    KC_LALT, KC_LCTL,  KC_SPC, KC_BSPC,  KC_TAB,  KC_DEL,\
                                         NUMS,    MDIA,  KC_SPC,  KC_ENT \
);


uint32_t mdia[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO, KC_VOLD, KC_MUTE, KC_VOLU,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO, KC_MPRV, KC_MPLY, KC_MNXT,   KC_NO,   KC_NO,   KC_NO,\
    KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_LWIN, KC_CAPS,\
                      KC_NO, KC_LALT, KC_LCTL, KC_BSPC,  KC_TAB,  KC_DEL,\
                                         NUMS,    MDIA,  KC_SPC,  KC_ENT \
);

uint32_t nums[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO, KC_PSLS, KC_PAST, KC_NLCK,   KC_NO,   KC_NO, \
    KC_NO, KC_PMNS,   KC_P9,   KC_P8,   KC_P7,   KC_NO,   KC_NO, \
    KC_NO, KC_PPLS,   KC_P6,   KC_P5,   KC_P4,   KC_NO,   KC_NO,   KC_NO,\
    KC_LSFT, KC_PEQL,   KC_P3,   KC_P2,   KC_P1,   KC_NO, KC_LWIN, KC_CAPS,\
                      KC_NO, KC_PDOT,   KC_P0, KC_BSPC,  KC_TAB,  KC_DEL,\
                                         NUMS,    MDIA,  KC_SPC,  KC_ENT \
);

uint32_t move[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO, KC_PGUP,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO, KC_HOME,   KC_UP,  KC_END,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO, KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO,   KC_NO,\
    KC_LSFT,   KC_NO,   KC_NO, KC_PGDN,   KC_NO,   KC_NO, KC_LWIN, KC_CAPS,\
                      KC_NO, KC_LALT, KC_LCTL, KC_BSPC,  KC_TAB,  KC_DEL,\
                                         NUMS,    MDIA,  KC_SPC,  KC_ENT \
);

uint32_t tap[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
  KC_LPRN,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
                                        KC_NO,   KC_NO,   KC_NO,   KC_NO\
);

uint32_t hold[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
  KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
                                        KC_NO,   KC_NO,   KC_NO,   KC_NO\
);


uint32_t trouble[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   DEBUG,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,PRINT_BLE,PRINT_INFO,PRINT_BATTERY,KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_NO,BLEPROFILE_3,BLEPROFILE_2,BLEPROFILE_1,   KC_NO,   KC_NO,   KC_NO,\
                    KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
                                        KC_NO,   KC_NO,   KC_NO,   KC_NO\
);

/*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_MAIN, Method::PRESS, main[row][col]);
            matrix[row][col].addActivation(_MAIN, Method::MT_TAP, tap[row][col]);
            matrix[row][col].addActivation(_MAIN, Method::MT_HOLD, hold[row][col]);
            matrix[row][col].addActivation(_SYMB, Method::PRESS, symb[row][col]);
            matrix[row][col].addActivation(_GAME, Method::PRESS, game[row][col]);
            matrix[row][col].addActivation(_GAME, Method::MT_TAP, game[row][col]);
            matrix[row][col].addActivation(_GAME, Method::MT_HOLD, game[row][col]);
            matrix[row][col].addActivation(_MDIA, Method::PRESS, mdia[row][col]);
            matrix[row][col].addActivation(_NUMS, Method::PRESS, nums[row][col]);
            matrix[row][col].addActivation(_MOVE, Method::PRESS, move[row][col]);
            matrix[row][col].addActivation(_TROUBLE, Method::PRESS, trouble[row][col]);
        }
    }

    // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

}
void encoder_callback(int step)
{
//   uint8_t layer = keyboardstate.layer;
//   if ( step > 0 )
//   {
//       switch(layer)
//       {
//           case _MAIN: KeyScanner::add_to_encoderKeys(KC_WH_U); break;
//           default: ;
//       }
//   }else
//   {
//       switch(layer)
//       {
//           case _MAIN: KeyScanner::add_to_encoderKeys(KC_WH_D); break;
//           default: ;
//       }
//   }  
}
#endif

#if KEYBOARD_SIDE == RIGHT
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
             KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,TG(GAME),\
              KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,\
              MOVE,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,\
    KC_NO,    SYMB,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  KC_CAPS,  KC_TAB,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_NO,\
  KC_RWIN,  KC_ENT,  KC_SPC, KC_DOWN,   KC_UP, KC_RGHT, \
   KC_DEL, KC_BSPC,    MDIA,   NUMS \
    ));


void setupKeymap() {

  RotaryEncoder.begin(ENCODER_A_PIN, ENCODER_B_PIN);    // Initialize Encoder
  RotaryEncoder.setCallback(encoder_callback);    // Set callback
  RotaryEncoder.start();    // Start encoder
/*
uint32_t template[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO \
);*/

uint32_t main[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
             KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,TG(GAME),\
              KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,\
              MOVE,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,\
    KC_NO,    SYMB,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  KC_CAPS,  KC_TAB,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_RSFT,\
  KC_RWIN,  KC_ENT,  KC_SPC, KC_RCTL, KC_RALT,   KC_NO, \
   KC_DEL, KC_BSPC,    MDIA,    NUMS \
    );

uint32_t symb[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
              MOVE,  KC_GRV, KC_LCBR, KC_RCBR, KC_UNDS, KC_BSLS,   KC_NO, \
     KC_NO,   SYMB, KC_TILD, KC_LBRC, KC_RBRC, KC_MINS,  KC_EQL,   KC_NO, \
  KC_CAPS,  KC_TAB,   KC_NO,   KC_LT,   KC_GT, KC_PLUS, KC_PIPE,   KC_RSFT, \
  KC_RWIN,  KC_ENT,  KC_SPC, KC_RCTL, KC_RALT,   KC_NO, \
   KC_DEL, KC_BSPC,   KC_NO,   KC_NO \
);

uint32_t game[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
             KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,TG(GAME),\
              KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,\
              MOVE,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,\
    KC_NO,    SYMB,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  KC_CAPS,  KC_TAB,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_RSFT,\
  KC_RWIN,  KC_ENT,  KC_SPC, KC_RCTL, KC_RALT,   KC_NO, \
   KC_DEL, KC_BSPC,    MDIA,    NUMS \
);

uint32_t mdia[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO, KC_VOLD, KC_MUTE, KC_VOLU,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO, KC_MPRV, KC_MPLY, KC_MNXT,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO \
);

uint32_t nums[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO, KC_NLCK, KC_PAST, KC_PSLS,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9, KC_PMNS,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6, KC_PPLS,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3, KC_PEQL,   KC_RSFT, \
    KC_NO,   KC_NO,   KC_NO,   KC_P0, KC_PDOT,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO \
);

uint32_t move[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO, KC_PGUP,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO, KC_HOME,   KC_UP,  KC_END,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO, KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PGDN,   KC_NO,   KC_NO,   KC_RSFT, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO \
);

uint32_t tap[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_RPRN, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO \
);

uint32_t hold[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_RSFT, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO \
);

uint32_t trouble[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, TROUBLE, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO \
);


/*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_MAIN, Method::PRESS, main[row][col]);
            matrix[row][col].addActivation(_MAIN, Method::MT_TAP, tap[row][col]);
            matrix[row][col].addActivation(_MAIN, Method::MT_HOLD, hold[row][col]);
            matrix[row][col].addActivation(_SYMB, Method::PRESS, symb[row][col]);
            matrix[row][col].addActivation(_GAME, Method::PRESS, game[row][col]);
            matrix[row][col].addActivation(_GAME, Method::MT_TAP, game[row][col]);
            matrix[row][col].addActivation(_GAME, Method::MT_HOLD, game[row][col]);
            matrix[row][col].addActivation(_MDIA, Method::PRESS, mdia[row][col]);
            matrix[row][col].addActivation(_NUMS, Method::PRESS, nums[row][col]);
            matrix[row][col].addActivation(_TROUBLE, Method::PRESS, trouble[row][col]);
        }
    }

    // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

}
void encoder_callback(int step)
{
//   uint8_t layer = keyboardstate.layer;
//   if ( step > 0 )
//   {
//       switch(layer)
//       {
//           case _MAIN: KeyScanner::add_to_encoderKeys(KC_VOLU); break;
//           default: ;
//       }
//   }else
//   {
//       switch(layer)
//       {
//           case _MAIN: KeyScanner::add_to_encoderKeys(KC_VOLD); break;
//           default: ;
//       }
//   }  
}
#endif


