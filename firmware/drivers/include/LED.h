/**
 * @file    LED.h
 * @brief   Status LED initialization
 *          LED error and status driver functions
 * @author  esicoe
 */

#ifndef LED_H
#define LED_H

#include "config.h"

static repeating_timer_t TIMER_250MS;
static volatile uint8_t CURRENT_STATUS = 0;

static bool BLINK(repeating_timer_t *rt);
void LED_INIT(void);
void DISPLAY_ERROR(uint8_t status);
void DISPLAY_STATUS(uint8_t status);

#endif // LED_H