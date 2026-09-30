#include "LEDs.h"

void toggle_leds(enum LED_codes code) {
    gpio_init(LED_A);
    gpio_init(LED_B);
    gpio_init(LED_C);

    gpio_out(LED_A);
    gpio_out(LED_B);
    gpio_out(LED_C);

// gpio_set_drive_strength(LED_A, enum gpio_drive_strength GPIO_DRIVE_STRENGTH_12MA);
// gpio_set_drive_strength(LED_B, enum gpio_drive_strength GPIO_DRIVE_STRENGTH_12MA);
// gpio_set_drive_strength(LED_C, enum gpio_drive_strength GPIO_DRIVE_STRENGTH_12MA);
    
    gpio_put(LED_A, 0);
    gpio_put(LED_B, 0);
    gpio_put(LED_C, 0);

    if (code & 0b001) gpio_put(LED_A, 1);
    if (code & 0b010) gpio_put(LED_B, 1);
    if (code & 0b100) gpio_put(LED_C, 1);
}