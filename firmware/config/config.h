/**
 * @file    config.h
 * @brief   pin map
 *          register map, values
 *          AT commands
 *          OPCODES
 * @author  esicoe
 */

#ifndef CONFIG_H
#define CONFIG_H

// STANDARD LIBRARY
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// RASPBERRY PI SDK
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/dma.h"
#include "hardware/pio.h"
#include "hardware/interp.h"
#include "hardware/timer.h"
#include "hardware/watchdog.h"
#include "hardware/clocks.h"
#include "hardware/uart.h"

// INTERNAL LIBRARY
#include "I2C.h"

// HELPERS
#define TIMEOUT_1MS     1000    // 1000 us
#define PYRO_OFF        false
#define PYRO_ON         true
#define LED_OFF         false
#define LED_ON          true

// PINOUT
#define PIN_SPI0_MOSI           19          // PIN 19
#define PIN_SPI0_MISO           16          // PIN 16
#define PIN_SPI0_SCK            18          // PIN 18
#define PIN_SPI0_CS             17          // GPIO17

#define PIN_SPI1_MOSI           31          // PIN 39
#define PIN_SPI1_MISO           28          // PIN 36
#define PIN_SPI1_SCK            30          // PIN 38
#define PIN_SPI1_CS             29          // PIN 37

#define PIN_I2C0_SCL            9           // PIN 7
#define PIN_I2C0_SDA            8           // PIN 6
#define PIN_IMU_INT             7           // PIN 4

#define PIN_I2C1_SCL            10          // PIN 8
#define PIN_I2C1_SDA            11          // PIN 9

#define PIN_UART0_TX            0           // PIN 77
#define PIN_UART0_RX            1           // PIN 78
#define PIN_GNSS_RST            2           // PIN 79

#define PIN_UART1_TX            24          // PIN 25
#define PIN_UART1_RX            25          // PIN 26
#define PIN_LORA_RST            20          // PIN 20

#define PIN_SERVO1_PWM          32          // PIN 40
#define PIN_SERVO2_PWM          36          // PIN 45

#define PIN_PYRO1               43          // PIN 54
#define PIN_PYRO2               44          // PIN 55
#define PIN_PYRO3               45          // PIN 56

#define PIN_LED_STATUSA         12          // PIN 11              
#define PIN_LED_STATUSB         13          // PIN 12
#define PIN_LED_STATUSC         14          // PIN 13

// CONFIGURATION
#define I2C0_CLOCK              400000UL        // 400 KHz
#define I2C1_CLOCK              400000UL        // 400 KHz
#define SPI0_CLOCK              20000000UL      // 20 MHz
#define SPI1_CLOCK              400000UL        // 400 KHz
#define UART0_BAUD              9600UL          // 9.6 KBd
#define UART1_BAUD              115200UL        // 115.2 KBd

// REGISTER ADDRESSES
    // IMU
    #define IMU_FUNC_CFG_ACCESS         0x01U   // R/W
    #define IMU_PIN_CTRL                0x02U   // R/W
    #define IMU_IF_CFG                  0x03U   // R/W
    #define IMU_FIFO_CTRL1              0x07U   // R/W
    #define IMU_FIFO_CTRL2              0x08U   // R/W
    #define IMU_FIFO_CTRL3              0x09U   // R/W
    #define IMU_FIFO_CTRL4              0x0AU   // R/W
    #define IMU_COUNTER_BDR_REG1        0x0BU   // R/W
    #define IMU_INT1_CTRL               0x0DU   // R/W
    #define IMU_INT2_CTRL               0x0EU   // R/W
    #define IMU_WHO_AM_I                0x0FU   // R
    #define IMU_CTRL1                   0x10U   // R/W
    #define IMU_CTRL2                   0x11U   // R/W
    #define IMU_CTRL3                   0x12U   // R/W
    #define IMU_CTRL4                   0x13U   // R/W
    #define IMU_CTRL5                   0x14U   // R/W
    #define IMU_CTRL6                   0x15U   // R/W
    #define IMU_CTRL7                   0x16U   // R/W
    #define IMU_CTRL8                   0x17U   // R/W
    #define IMU_CTRL9                   0x18U   // R/W
    #define IMU_CTRL10                  0x19U   // R/W
    #define IMU_CTRL_STATUS             0x1AU   // R/W
    #define IMU_FIFO_STATUS1            0x1BU   // R
    #define IMU_FIFO_STATUS2            0x1CU   // R
    #define IMU_ALL_INT_SRC             0x1DU   // R
    #define IMU_STATUS_REG              0x1EU   // R
    #define IMU_OUT_TEMP_LSB            0x20U   // R
    #define IMU_OUT_TEMP_MSB            0x21U   // R
    #define IMU_OUTX_LSB_G              0x22U   // R
    #define IMU_OUTX_MSB_G              0x23U   // R
    #define IMU_OUTY_LSB_G              0x24U   // R
    #define IMU_OUTY_MSB_G              0x25U   // R
    #define IMU_OUTZ_LSB_G              0x26U   // R
    #define IMU_OUTZ_MSB_G              0x27U   // R
    #define IMU_OUTX_LSB_A              0x28U   // R
    #define IMU_OUTX_MSB_A              0x29U   // R
    #define IMU_OUTY_LSB_A              0x2AU   // R
    #define IMU_OUTY_MSB_A              0x2BU   // R
    #define IMU_OUTZ_LSB_A              0x2CU   // R
    #define IMU_OUTZ_MSB_A              0x2DU   // R
    #define IMU_TIMESTAMP0              0x40U   // R
    #define IMU_TIMESTAMP1              0x41U   // R
    #define IMU_TIMESTAMP2              0x42U   // R
    #define IMU_TIMESTAMP3              0x43U   // R
    #define IMU_INTERNAL_FREQ           0x4FU   // R
    #define IMU_FUNCTIONS_ENABLE        0x50U   // R/W
    #define IMU_TAP_CFG0                0x56U   // R/W
    #define IMU_MD1_CFG                 0x5EU   // R/W
    #define IMU_MD2_CFG                 0x5FU   // R/W
    #define IMU_X_OFS_USR               0x73U   // R/W
    #define IMU_Y_OFS_USR               0x74U   // R/W
    #define IMU_Z_OFS_USR               0x75U   // R/W
    #define IMU_FIFO_DATA_OUT_TAG       0x78U   // R
    
    // BAROMETER
    #define BARO_CHIP_ID                0x01U   // R
    #define BARO_REV_ID                 0x02U   // R
    #define BARO_CHIP_STATUS            0x11U   // R
    #define BARO_DRIVE_CONFIG           0x13U   // R/W
    #define BARO_INT_CONFIG             0x14U   // R/W
    #define BARO_INT_SOURCE             0x15U   // R/W
    #define BARO_FIFO_CONFIG            0x16U   // R/W
    #define BARO_FIFO_COUNT             0x17U   // R
    #define BARO_FIFO_SEL               0x18U   // R/W
    #define BARO_TEMP_DATA_XLSB         0x1DU   // R
    #define BARO_TEMP_DATA_LSB          0x1EU   // R
    #define BARO_TEMP_DATA_MSB          0x1FU   // R
    #define BARO_PRESS_DATA_XLSB        0x20U   // R
    #define BARO_PRESS_DATA_LSB         0x21U   // R
    #define BARO_PRESS_DATA_MSB         0x22U   // R
    #define BARO_INT_STATUS             0x27U   // R
    #define BARO_STATUS                 0x28U   // R
    #define BARO_FIFO_DATA              0x29U   // R
    #define BARO_NVM_ADDR               0x2BU   // R/W
    #define BARO_NVM_DATA_LSB           0x2CU   // R/W
    #define BARO_NVM_DATA_MSB           0x2DU   // R/W
    #define BARO_DSP_CONFIG             0x30U   // R/W
    #define BARO_DSP_IIR                0x31U   // R/W
    #define BARO_OOR_THR_P_LSB          0x32U   // R/W
    #define BARO_OOR_THR_P_MSB          0x33U   // R/W
    #define BARO_OOR_RANGE              0x34U   // R/W
    #define BARO_OOR_CONFIG             0x35U   // R/W
    #define BARO_OSR_CONFIG             0x36U   // R/W
    #define BARO_ODR_CONFIG             0x37U   // R/W
    #define BARO_OSR_EFF                0x38U   // R
    #define BARO_CMD                    0x7EU   // R/W

// REGISTER VALUES
    // IMU
    #define IMU_WHO_AM_I_VALUE          0x70U
    #define IMU_CTRL3_SW_RESET          0x01U
    #define IMU_CTRL3_VALUE             0x44U
    #define IMU_CTRL8_VALUE             0x07U
    #define IMU_CTRL6_VALUE             0x04U
    #define IMU_CTRL1_VALUE             0x08U
    #define IMU_CTRL2_VALUE             0x08U
    #define IMU_INT1_CTRL_VALUE         0x01U

    // BAROMETER
    #define BARO_CHIP_ID_VALUE          0x51U
    #define BARO_CMD_SOFT_RESET         0xB6U
    #define BARO_OSR_CONFIG_VALUE       0x58U
    #define BARO_DSP_IIR_VALUE          0x00U
    #define BARO_INT_SOURCE_VALUE       0x01U
    #define BARO_ODR_CONFIG_VALUE       0xBDU

// OPCODES
    // FLASH
    #define FLASH_WRITE_ENABLE                      0x06U
    #define FLASH_VOLATILE_SR_WRITE_ENABLE          0x50U
    #define FLASH_WRITE_DISABLE                     0x04U
    #define FLASH_RELEASE_POWER_DOWN_ID             0xABU
    #define FLASH_MANUFACTURER_DEVICE_ID            0x90U
    #define FLASH_JEDEC_ID                          0x9FU
    #define FLASH_READ_UNIQUE_ID                    0x4BU
    #define FLASH_READ_DATA                         0x03U
    #define FLASH_FAST_READ                         0x0BU
    #define FLASH_PAGE_PROGRAM                      0x02U
    #define FLASH_SECTOR_ERASE_4KB                  0x20U
    #define FLASH_BLOCK_ERASE_32KB                  0x52U
    #define FLASH_BLOCK_ERASE_64KB                  0xD8U
    #define FLASH_CHIP_ERASE                        0xC7U
    #define FLASH_READ_STATUS_REGISTER_1            0x05U
    #define FLASH_WRITE_STATUS_REGISTER_1           0x01U
    #define FLASH_READ_STATUS_REGISTER_2            0x35U
    #define FLASH_WRITE_STATUS_REGISTER_2           0x31U
    #define FLASH_READ_STATUS_REGISTER_3            0x15U
    #define FLASH_WRITE_STATUS_REGISTER_3           0x11U
    #define FLASH_READ_SFDP_REGISTER                0x5AU
    #define FLASH_ERASE_SECURITY_REGISTER           0x44U
    #define FLASH_PROGRAM_SECURITY_REGISTER         0x42U
    #define FLASH_READ_SECURITY_REGISTER            0x48U
    #define FLASH_GLOBAL_BLOCK_LOCK                 0x7EU
    #define FLASH_GLOBAL_BLOCK_UNLOCK               0x98U
    #define FLASH_READ_BLOCK_LOCK                   0x3DU
    #define FLASH_INDIVIDUAL_BLOCK_LOCK             0x36U
    #define FLASH_INDIVIDUAL_BLOCK_UNLOCK           0x39U
    #define FLASH_ERASE_PROGRAM_SUSPEND             0x75U
    #define FLASH_ERASE_PROGRAM_RESUME              0x7AU
    #define FLASH_POWER_DOWN                        0xB9U
    #define FLASH_ENABLE_RESET                      0x66U
    #define FLASH_RESET_DEVICE                      0x99U
    
    // SD
    #define SD_GO_IDLE_STATE                0U
    #define SD_SEND_IF_COND                 8U
    #define SD_SEND_CSD                     9U
    #define SD_SEND_CID                     10U
    #define SD_STOP_TRANSMISSION            12U
    #define SD_SEND_STATUS                  13U
    #define SD_SET_BLOCKLEN                 16U
    #define SD_READ_SINGLE_BLOCK            17U
    #define SD_READ_MULTIPLE_BLOCK          18U
    #define SD_WRITE_BLOCK                  24U
    #define SD_WRITE_MULTIPLE_BLOCK         25U
    #define SD_ERASE_WR_BLK_START_ADDR      32U
    #define SD_ERASE_WR_BLK_END_ADDR        33U
    #define SD_ERASE                        38U
    #define SD_APP_CMD                      55U
    #define SD_READ_OCR                     58U
    #define SD_CRC_ON_OFF                   59U
    #define SD_APP_SD_STATUS                13U
    #define SD_APP_SET_WR_BLK_ERASE_COUNT   23U
    #define SD_APP_SD_SEND_OP_COND          41U
    #define SD_APP_SEND_SCR                 51U

    #define SD_START_BLOCK_TOKEN            0xFEU
    #define SD_START_MULTI_WRITE_TOKEN      0xFCU
    #define SD_STOP_TRAN_TOKEN              0xFDU
    
    // GNSS
    #define GNSS_UBX_SYNC_CHAR_1            0xB5U
    #define GNSS_UBX_SYNC_CHAR_2            0x62U

    #define GNSS_CLASS_NAV                  0x01U
    #define GNSS_CLASS_ACK                  0x05U
    #define GNSS_CLASS_CFG                  0x06U
    #define GNSS_CLASS_MON                  0x0AU

    #define GNSS_NAV_STATUS                 0x03U
    #define GNSS_NAV_PVT                    0x07U
    #define GNSS_NAV_SAT                    0x35U
    #define GNSS_ACK_NAK                    0x00U
    #define GNSS_ACK_ACK                    0x01U
    #define GNSS_CFG_RST                    0x04U
    #define GNSS_CFG_VALSET                 0x8AU
    #define GNSS_CFG_VALGET                 0x8BU
    #define GNSS_CFG_VALDEL                 0x8CU
    #define GNSS_MON_VER                    0x04U
    #define GNSS_MON_RF                     0x38U
    
    // LORA
    #define LORA_AT                         "AT"
    #define LORA_FIRMWARE_VERSION           "AT+VER=?"
    #define LORA_NETWORK_MODE               "AT+NWM="
    #define LORA_P2P_PARAMETERS             "AT+P2P="
    #define LORA_P2P_SEND                   "AT+PSEND="
    #define LORA_P2P_RECEIVE                "AT+PRECV="
    #define LORA_LOW_POWER_MODE             "AT+LPM="
    #define LORA_BAND                       "AT+BAND="
    #define LORA_EVENT_TX_DONE              "+EVT:TXP2P DONE"
    #define LORA_EVENT_RX                   "+EVT:RXP2P"
    
/**
 * @brief   Initializes critical board stuff
 * Sets PYRO pins LOW.
 * Sets USB flashing.
 * Sets LED PIN direction.
 * @param   None.
 * @return  None.
 * @note    Function must run first.
 */
void system_init(void);

#endif // CONFIG_H