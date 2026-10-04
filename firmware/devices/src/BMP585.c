#include "BMP585.h"

bool BMP585_INIT() {
    int STATUS;

    STATUS = I2C_INIT(i2c1);

    if (STATUS == false) return false;

    int R_CHIP_ID;
    int* R_CHIP_ID = &R_CHIP_ID;

    I2C_READ(i2c1, BARO_ADDRESS, BARO_CHIP_ID, &R_CHIP_ID);


}