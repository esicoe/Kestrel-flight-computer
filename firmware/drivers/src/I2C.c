#include "I2C.h"

bool I2C_INIT(i2c_inst_t *i2c) {
    unsigned long SPEED;
    
    if (i2c == i2c0) {
        SPEED = i2c_init(i2c0, I2C0_CLOCK);

        if (SPEED > I2C0_CLOCK) return false;

        gpio_set_function(PIN_I2C0_SCL, GPIO_FUNC_I2C);    
        gpio_set_function(PIN_I2C0_SDA, GPIO_FUNC_I2C);
        
        gpio_disable_pulls(PIN_I2C0_SCL);
        gpio_disable_pulls(PIN_I2C0_SDA);
        
        return true;
    }
    else {
        SPEED = i2c_init(i2c1, I2C1_CLOCK);

        if (SPEED > I2C1_CLOCK) return false;

        gpio_set_function(PIN_I2C1_SCL, GPIO_FUNC_I2C);    
        gpio_set_function(PIN_I2C1_SDA, GPIO_FUNC_I2C);
        
        gpio_disable_pulls(PIN_I2C1_SCL);
        gpio_disable_pulls(PIN_I2C1_SDA);

        return true;
    }
}

enum pico_error_codes I2C_WRITE(i2c_inst_t *i2c, uint8_t address, uint8_t reg, uint8_t data) {
    int I2C_STATUS;

    uint8_t buffer[2] = {reg, data};

    I2C_STATUS = i2c_write_timeout_us(i2c, address, buffer, 2, false, TIMEOUT_1MS);

    if (I2C_STATUS > 0) return PICO_OK;

    return (enum pico_error_codes)I2C_STATUS;
}

enum pico_error_codes I2C_READ(i2c_inst_t *i2c, uint8_t address, uint8_t reg, uint8_t *data) {
    int I2C_STATUS;

    I2C_STATUS = i2c_write_timeout_us(i2c, address, &reg, 1, true, TIMEOUT_1MS);

    if (I2C_STATUS < 0) return (enum pico_error_codes)(I2C_STATUS);

    I2C_STATUS = i2c_read_timeout_us(i2c, address, data, 1, false, TIMEOUT_1MS);

    if (I2C_STATUS > 0) return PICO_OK;

    return (enum pico_error_codes)I2C_STATUS;
}