#include "BMP585.h"

bool BMP585_INIT(void) {
    bool STATUS = false;
    uint8_t output = 0;

    STATUS = I2C_READ(i2c0, ADDRESS_BARO, REGISTER_BARO_CHIP_ID, &output, 1);
    if (!STATUS) {
        
    }
}
STATUS = I2C_READ(i2c0, ADDRESS_BARO,BLANK ,&output, 1);
