#include QMK_KEYBOARD_H


extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _DEF = 0,
    _B,
    _n,
    _Fn,
    _sym,
    _Fnn,
    _Fnsym,
    _Mouse
};

enum custom_keycodes {
  Function = SAFE_RANGE,
  Bmode,
  NMode,
  SymMode,
  Mouse,
  JAPANESE,
  HIRA,
  KATA,
  JAPHIRA,
  JAPKATA,
  WIN8,
  WIN9,
  WIN0,
  WINL,
  WIN1,
  WIN2,
  WIN3,
  WIN4,
  WINLEFT,
  WINUP,
  WINDOWN,
  WINRIGHT,
  WINSPACE,
  WIN5,
  WIN6,
  WIN7,
  SHIFTTAB,
  ALTTAB,
  ALTF4,
  WINE,
  CTRL9,
  CTRL0,
  CTRLW,
  CTRL1,
  CTRL2,
  CTRL3,
  CTRL4,
  CTRLALTDEL,
  CTRLT,
  CTRLL,
  CTRLY,
  CTRL5,
  CTRL6,
  CTRL7,
  CTRL8,
  CTRLN
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.            
   * | Fn   |   B  |enter |  tab |  CTRL|   Esc|   
   * |------+------+------+------+------+------|            
   * | N    |unassi|   q  |   e  |   z  |   c  |            
   * |------+------+------+------+------+------|            
   * | Shift|RightC|   a  |   w  |   s  |   d  |            
   * |------+------+------+------+------+------|           
   * | Sym  |Middle|left  |up    |down  |right |            
   * |------+------+------+------+------+------|           
   * | LeftC|noKey | x    | r    |t     |o     |          
   * `-----------------------------------------'  
   */
  [_DEF] = LAYOUT_ortho_29(
        Function,     Bmode,KC_ENTER,KC_TAB,KC_LCTL,KC_ESCAPE, \
           NMode,     QK_RBT,    KC_Q,  KC_E,   KC_Z,     KC_C, \
         KC_LSFT,KC_MS_BTN2,    KC_A,  KC_W,   KC_S,     KC_D, \
         SymMode,     Mouse, KC_LEFT, KC_UP,KC_DOWN, KC_RIGHT, \
      KC_MS_BTN1,     KC_NO,    KC_X,  KC_R,   KC_T,     KC_O
      ),

  [_B] = LAYOUT_ortho_29(
        Function,     Bmode,KC_PSCR,KC_BACKSPACE,KC_DELETE,KC_PAUSE, \
           NMode,     KC_NO,    KC_Y,  KC_P,   KC_V,     KC_K, \
         KC_LSFT,KC_MS_BTN2,    KC_L,  KC_I,   KC_N,     KC_H, \
         SymMode,     Mouse, KC_F, KC_B,KC_U, KC_M, \
      KC_MS_BTN1,     KC_NO,    KC_G,  KC_COMMA,   KC_DOT,     KC_J
      ),
  [_n] = LAYOUT_ortho_29(
        Function,     Bmode,KC_ENTER,KC_TAB,KC_LCTL,KC_ESCAPE, \
           NMode,     KC_NO,    KC_9,  KC_0,   KC_MINUS,     KC_EQUAL, \
         KC_LSFT,KC_MS_BTN2,    KC_1,  KC_2,   KC_3,     KC_4, \
         SymMode,     Mouse, KC_5, KC_6,KC_7, KC_8, \
      KC_MS_BTN1,     KC_NO,    KC_LEFT_BRACKET,  KC_RIGHT_BRACKET,   KC_GRAVE,     KC_TRNS
      ),    
  [_Fn] = LAYOUT_ortho_29(
        Function,     Bmode,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
           NMode,     KC_NO,    KC_F9,  KC_F10,   KC_F11,     KC_F12, \
         KC_LSFT,KC_MS_BTN2,    KC_F1,  KC_F2,   KC_F3,     KC_F4, \
         SymMode,     Mouse, KC_F5, KC_F6,KC_F7, KC_F8, \
      KC_MS_BTN1,     KC_NO,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
      ),
  [_sym] = LAYOUT_ortho_29(
        Function,     Bmode,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK, \
           NMode,     KC_NO,    KC_BACKSLASH,  KC_SEMICOLON,   KC_QUOTE,     KC_TRNS, \
         KC_LSFT,KC_MS_BTN2,    JAPANESE,  HIRA,   KATA,     KC_LSFT, \
         SymMode,     Mouse, JAPHIRA, JAPKATA,KC_DOWN, KC_TRNS, \
      KC_MS_BTN1,     KC_NO,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
      ),
  [_Fnn] = LAYOUT_ortho_29(
        Function,     Bmode,WIN8,WIN9,WIN0,WINL, \
           NMode,     KC_NO,WIN1,WIN2,WIN3,WIN4, \
         KC_LSFT,KC_MS_BTN2,WINLEFT,WINUP,WINDOWN,WINRIGHT, \
         SymMode,     Mouse,WINSPACE,WIN5,WIN6,WIN7, \
      KC_MS_BTN1,     KC_NO,SHIFTTAB,ALTTAB,ALTF4,WINE
      ),
  [_Fnsym] = LAYOUT_ortho_29(
        Function,     Bmode,CTRL9,CTRL0,CTRLW,CTRLN, \
           NMode,     KC_NO,CTRL1,CTRL2,CTRL3,CTRL4, \
         KC_LSFT,KC_MS_BTN2,CTRLALTDEL,KC_COPY,KC_PASTE,KC_UNDO, \
         SymMode,     Mouse,CTRLT, KC_CUT, CTRLL,CTRLY, \
      KC_MS_BTN1,     KC_NO,CTRL5,CTRL6,CTRL7,CTRL8
      ),
  [_Mouse] = LAYOUT_ortho_29(
        Function,     Bmode,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
           NMode,     KC_NO,KC_ACL0,KC_ACL1,KC_ACL2,KC_TRNS, \
         KC_LSFT,KC_MS_BTN2,KC_WH_L,KC_WH_U,KC_WH_D,KC_WH_R, \
         SymMode,     Mouse,KC_MS_L,KC_MS_U,KC_MS_D,KC_WH_R, \
      KC_MS_BTN1,     KC_NO,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
      )
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool Fn_pressed = false;
  static bool B_pressed = false;
  static bool N_pressed = false;
  static bool Sym_pressed = false;
  static bool Mouse_pressed = false;

  switch (keycode) {
    case Function:
      Fn_pressed = record->event.pressed;
      if (Fn_pressed) {
        if (N_pressed){
          set_single_persistent_default_layer(_Fnn);
        } else{
          if (Sym_pressed) {
            set_single_persistent_default_layer(_Fnsym);
          } else{
            set_single_persistent_default_layer(_Fn);
          }
        }
      } else{
        if (Sym_pressed){
          set_single_persistent_default_layer(_sym);
        } else{
          if (N_pressed){
            set_single_persistent_default_layer(_n);
          } else{
            set_single_persistent_default_layer(_DEF);
          }
        }
      }
      return false;
      break;
      
    case Bmode:
      B_pressed = record->event.pressed;
      if (B_pressed) {
        set_single_persistent_default_layer(_B);
      } else{
        set_single_persistent_default_layer(_DEF);
      }
      return false;
      break;
      
    case NMode:
      N_pressed = record->event.pressed;
      if (N_pressed) {
        if (Fn_pressed){
          set_single_persistent_default_layer(_Fnn);
        } else{
          set_single_persistent_default_layer(_n);
        }
      } else{
        if (Fn_pressed){
          set_single_persistent_default_layer(_Fn);
        } else{
          set_single_persistent_default_layer(_DEF);
        }
      }
      return false;
      break;
    case SymMode:
      Sym_pressed = record->event.pressed;
      if (Sym_pressed) {
        if (Fn_pressed){
          set_single_persistent_default_layer(_Fnsym);
        } else{
          set_single_persistent_default_layer(_sym);
        }
      } else{
        if (Fn_pressed){
          set_single_persistent_default_layer(_Fn);
        } else{
          set_single_persistent_default_layer(_DEF);
        }
      }
      return false;
      break;
    case Mouse:
      Mouse_pressed = record->event.pressed;
      if (Mouse_pressed){
        set_single_persistent_default_layer(_Mouse);
      }
      return false;
      break;
    case JAPANESE:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_SPACE);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_SPACE);
      }
      return false;
      break;
    case HIRA:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_SPACE);
        unregister_code(KC_LCTL);
        unregister_code(KC_SPACE);
      }
      return false;
      break;
    case KATA:
      if (record->event.pressed){
        register_code(KC_LALT);
        register_code(KC_CAPS);
        unregister_code(KC_LALT);
        unregister_code(KC_CAPS);
      }
      return false;
      break;
    case JAPHIRA:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_SPACE);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_SPACE);
        register_code(KC_LCTL);
        register_code(KC_SPACE);
        unregister_code(KC_LCTL);
        unregister_code(KC_SPACE);
      }
      return false;
      break;
    case JAPKATA:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_SPACE);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_SPACE);
        register_code(KC_LALT);
        register_code(KC_CAPS);
        unregister_code(KC_LALT);
        unregister_code(KC_CAPS);
      }
      return false;
      break;
    case WIN0:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_0);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_0);
      }
      return false;
      break;
    case WIN1:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_1);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_1);
      }
      return false;
      break;
    case WIN2:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_2);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_2);
      }
      return false;
      break;
    case WIN3:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_3);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_3);
      }
      return false;
      break;
    case WIN4:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_4);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_4);
      }
      return false;
      break;
    case WIN5:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_5);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_5);
      }
      return false;
      break;
    case WIN6:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_6);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_6);
      }
      return false;
      break;
    case WIN7:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_7);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_7);
      }
      return false;
      break;
    case WIN8:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_8);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_8);
      }
      return false;
      break;
    case WIN9:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_9);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_9);
      }
      return false;
      break;
    case WINL:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_L);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_L);
      }
      return false;
      break;
    case WINLEFT:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_LEFT);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_LEFT);
      }
      return false;
      break;
    case WINUP:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_UP);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_UP);
      }
      return false;
      break;
    case WINDOWN:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_DOWN);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_DOWN);
      }
      return false;
      break;
    case WINRIGHT:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_RIGHT);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_RIGHT);
      }
      return false;
      break;
    case WINSPACE:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_SPACE);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_SPACE);
      }
      return false;
      break;
    case SHIFTTAB:
      if (record->event.pressed){
        register_code(KC_LSFT);
        register_code(KC_TAB);
        unregister_code(KC_LSFT);
        unregister_code(KC_TAB);
      }
      return false;
      break;
    case ALTTAB:
      if (record->event.pressed){
        register_code(KC_LALT);
        register_code(KC_TAB);
        unregister_code(KC_LALT);
        unregister_code(KC_TAB);
      }
      return false;
      break;
    case ALTF4:
      if (record->event.pressed){
        register_code(KC_LALT);
        register_code(KC_F4);
        unregister_code(KC_LALT);
        unregister_code(KC_F4);
      }
      return false;
      break;
    case WINE:
      if (record->event.pressed){
        register_code(KC_APPLICATION);
        register_code(KC_E);
        unregister_code(KC_APPLICATION);
        unregister_code(KC_E);
      }
      return false;
      break;
    case CTRL0:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_0);
        unregister_code(KC_LCTL);
        unregister_code(KC_0);
      }
      return false;
      break;
    case CTRL1:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_1);
        unregister_code(KC_LCTL);
        unregister_code(KC_1);
      }
      return false;
      break;
    case CTRL2:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_2);
        unregister_code(KC_LCTL);
        unregister_code(KC_2);
      }
      return false;
      break;
    case CTRL3:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_3);
        unregister_code(KC_LCTL);
        unregister_code(KC_3);
      }
      return false;
      break;
    case CTRL4:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_4);
        unregister_code(KC_LCTL);
        unregister_code(KC_4);
      }
      return false;
      break;
    case CTRL5:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_5);
        unregister_code(KC_LCTL);
        unregister_code(KC_5);
      }
      return false;
      break;
    case CTRL6:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_6);
        unregister_code(KC_LCTL);
        unregister_code(KC_6);
      }
      return false;
      break;
    case CTRL7:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_7);
        unregister_code(KC_LCTL);
        unregister_code(KC_7);
      }
      return false;
      break;
    case CTRL8:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_8);
        unregister_code(KC_LCTL);
        unregister_code(KC_8);
      }
      return false;
      break;
    case CTRL9:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_9);
        unregister_code(KC_LCTL);
        unregister_code(KC_9);
      }
      return false;
      break;
    case CTRLW:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_W);
        unregister_code(KC_LCTL);
        unregister_code(KC_W);
      }
      return false;
      break;
    case CTRLALTDEL:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_DELETE);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_DELETE);
      }
      return false;
      break;
    case CTRLY:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_Y);
        unregister_code(KC_LCTL);
        unregister_code(KC_Y);
      }
      return false;
      break;
    case CTRLT:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_T);
        unregister_code(KC_LCTL);
        unregister_code(KC_T);
      }
      return false;
      break;
    case CTRLL:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_L);
        unregister_code(KC_LCTL);
        unregister_code(KC_L);
      }
      return false;
      break;
    case CTRLN:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_N);
        unregister_code(KC_LCTL);
        unregister_code(KC_N);
      }
      return false;
      break;
  }
  return true;
}
