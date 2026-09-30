/**
    * @file     config.h
    * @brief    Pin assignments and bus configuration.
    * @author   esicoe
    * @date     2026/09/29
*/

#ifndef CONFIG_H
#define CONFIG_H

// Includes
    // Standard libraries
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

    // RP2350 SDK libraries
    #include "pico/stdlib.h"
    #include "hardware/gpio.h"

    // Internal libraries
    #include "LEDs.h"

#define     I2C1_BAUD       400000UL        // 400 kHz
#define     I2C0_BAUD       400000UL        // 400 kHz
#define     SPI0_BAUD       20000000UL      // 20 MHz
#define     SPI1_BAUD       12500000UL      // 12.5 MHz

#define     IMU_INT         7   // PIN 4
#define     GNSS_RST        2   // PIN 79
#define     LoRa_RST        20  // PIN 20
#define     LED_A           12  // PIN 11
#define     LED_B           13  // PIN 12
#define     LED_C           14  // PIN 13
#define     PYRO_1          43  // PIN 54
#define     PYRO_2          44  // PIN 55
#define     PYRO_3          45  // PIN 56
#define     SERVO_1         32  // PIN 40
#define     SERVO_2         36  // PIN 45

#define     I2C0_SDA        8   // PIN 6
#define     I2C0_SCL        9   // PIN 7
#define     I2C1_SDA        10  // PIN 8
#define     I2C1_SCL        11  // PIN 9
#define     SPI0_CS         17  // PIN 17
#define     SPI0_MISO       16  // PIN 16
#define     SPI0_MOSI       19  // PIN 19
#define     SPI0_SCK        18  // PIN 18
#define     SPI1_CS         29  // PIN 37
#define     SPI1_MISO       28  // PIN 36
#define     SPI1_MOSI       31  // PIN 39
#define     SPI1_SCK        30  // PIN 38
#define     UART0_TX        0   // PIN 77
#define     UART0_RX        1   // PIN 78
#define     UART1_TX        24  // PIN 25
#define     UART1_RX        25  // PIN 26

void board_init(void);

#endif // config_h