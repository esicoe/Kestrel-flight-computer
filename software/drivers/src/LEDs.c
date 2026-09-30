#include "config.h"

void toggle_leds(enum LED_codes code) {
    gpio_init(LED_A);
    gpio_init(LED_B);
    gpio_init(LED_C);

    gpio_set_dir(LED_A, 1);
    gpio_set_dir(LED_B, 1);
    gpio_set_dir(LED_C, 1);

    gpio_set_drive_strength(LED_A, GPIO_DRIVE_STRENGTH_2MA);
    gpio_set_drive_strength(LED_B, GPIO_DRIVE_STRENGTH_2MA);
    gpio_set_drive_strength(LED_C, GPIO_DRIVE_STRENGTH_2MA);

    gpio_put(LED_A, 0);
    gpio_put(LED_B, 0);
    gpio_put(LED_C, 0);

    if (code & 0b001) gpio_put(LED_A, 1);
    if (code & 0b010) gpio_put(LED_B, 1);
    if (code & 0b100) gpio_put(LED_C, 1);
}