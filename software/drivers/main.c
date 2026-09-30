#include "config.h"

int main(void) {
    board_init();

    toggle_leds(ABC);

    while(true);
}