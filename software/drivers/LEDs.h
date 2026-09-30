/**
    * @file    LEDs.h
    * @brief   Debug LEDs toggling function.
    * @author  esicoe
    * @date    2026/09/29
*/

#ifndef LEDS_H
#define LEDS_H

#include "config.h"

enum LED_codes {
    OFF,
    A   = 0b001,
    B   = 0b010,
    C   = 0b100,
    AB  = 0b011,
    AC  = 0b101,
    BC  = 0b110,
    ABC = 0b111
};

#endif // LEDS_H