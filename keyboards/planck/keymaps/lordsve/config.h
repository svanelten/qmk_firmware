#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

// lighting
#ifndef LIGHT_CONFIG_H
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 5
#endif

// faux clicky sounds
#define AUDIO_CLICKY

// audio features
#ifdef AUDIO_ENABLE 
    #define STARTUP_SONG SONG(E1M1_DOOM)
    #define GOODBYE_SONG SONG(MARIO_MUSHROOM)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
    /* #define DEFAULT_LAYER_SONGS { SONG(COIN_SOUND),      \
    //                               SONG(MARIO_MUSHROOM),  \
    //                               SONG(CHROMATIC_SOUND)  \
                                 }
    */
#endif

/*  
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#endif
