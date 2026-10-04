/**
 * @file    I2C.h
 * @brief   I2C peripheral initialization.
 *          I2C R/W funcion.
 * @author  esicoe
 */

#ifndef I2C_H
#define I2C_H

#include "config.h"

/**
 * @brief   Initializes I2C0/I2C1.
 *          Sets bus clock.
 *          Sets GPIO function.
 *          Disables internal pulls.
 * @param   i2c         i2c0/i2c1.
 * @return  TRUE/FALSE based on set clock.
 */
bool I2C_INIT(i2c_inst_t *i2c);

/**
 * @brief   Writes one byte.
 * @param   i2c         i2c0/i2c1.
 * @param   address     Device I2C address.
 * @param   reg         Register address.
 * @param   data        Data to write.
 * @return  PICO_OK on success.
 *          PICO_ERROR_GENERIC on NACK.
 *          PICO_ERROR_TIMEOUT if the transaction takes >1ms.
 */
enum pico_error_codes I2C_WRITE(i2c_inst_t *i2c, uint8_t address, uint8_t reg, uint8_t data);

/**
 * @brief   Reads one byte.
 * @param   i2c         i2c0/i2c1.
 * @param   address     Device I2C address.
 * @param   reg         Register address.
 * @param   data        Pointer to outputted data.
 * @return  PICO_OK on success.
 *          PICO_ERROR_GENERIC on NACK.
 *          PICO_ERROR_TIMEOUT if the transaction takes >1ms.
 */
enum pico_error_codes I2C_READ(i2c_inst_t *i2c, uint8_t address, uint8_t reg, uint8_t *data);

#endif // I2C_H
