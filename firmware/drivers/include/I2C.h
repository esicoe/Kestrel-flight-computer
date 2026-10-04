/**
 * @file    I2C.h
 * @brief   I2C bus driver
 *          bus setup
 *          register read and write
 * @author  esicoe
 */

#ifndef I2C_H
#define I2C_H

#include "config.h"

/**
 * @brief   Initializes an I2C bus.
 *          Sets bus clock
 *          Sets GPIO function
 *          Disables internal pulls
 * @param   i2c         I2C instance, i2c0 or i2c1.
 * @return  True if the clock is set, false if it runs above the configured clock.
 * @note    Run once per bus before I2C_WRITE or I2C_READ.
 */
bool I2C_INIT(i2c_inst_t *i2c);

/**
 * @brief   Writes one byte to a device register.
 * Sends the register address and the data in one transaction.
 * Ends the transaction with a STOP.
 * @param   i2c         I2C instance, i2c0 or i2c1.
 * @param   address     7-bit device address.
 * @param   reg         Register address.
 * @param   data        Byte to write.
 * @return  PICO_OK on success.
 *          PICO_ERROR_GENERIC if the device does not acknowledge.
 *          PICO_ERROR_TIMEOUT if the transfer takes longer than 1 ms.
 * @note    Blocks for up to 1 ms.
 */
enum pico_error_codes I2C_WRITE(i2c_inst_t *i2c, uint8_t address, uint8_t reg, uint8_t data);

/**
 * @brief   Reads one byte from a device register.
 *          Writes the register address without a STOP.
 *          Reads the byte after a repeated START, then sends a STOP.
 * @param   i2c         I2C instance, i2c0 or i2c1.
 * @param   address     7-bit device address.
 * @param   reg         Register address.
 * @param   data        Pointer to where the byte is stored.
 * @return  PICO_OK on success.
 *          PICO_ERROR_GENERIC if the device does not acknowledge.
 *          PICO_ERROR_TIMEOUT if a transfer takes longer than 1 ms.
 * @note    Blocks for up to 2 ms. data is unchanged on error.
 */
enum pico_error_codes I2C_READ(i2c_inst_t *i2c, uint8_t address, uint8_t reg, uint8_t *data);

#endif // I2C_H
