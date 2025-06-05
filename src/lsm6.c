#include "lsm6.h"

static int16_t read_word(uint8_t reg) {
    uint8_t low, high;
    READ_REG (LSM6_ADDR, reg, &low);
    READ_REG (LSM6_ADDR, reg + 1, &high);
    return (int16_t)((high << 8) | low);
}

bool lsm6_init(void) {
    uint8_t who_am_i;
    READ_REG (LSM6_ADDR, WHO_AM_I_REG, &who_am_i);
    if (who_am_i != WHO_AM_I_EXPECTED)
        return false;

    WRITE_REG (LSM6_ADDR, CTRL1_XL, 0x60); // 104 Hz, 2g, BW = 100 Hz
    WRITE_REG (LSM6_ADDR, CTRL2_G, 0x60);  // 104 Hz, 250 dps
    return true;
}

bool lsm6_read_accel(AccelData* data) {
    if (!data) return false;
    data->ax = read_word(OUTX_L_XL) * 0.061f / 1000.0f;
    data->ay = read_word(OUTX_L_XL + 2) * 0.061f / 1000.0f;
    data->az = read_word(OUTX_L_XL + 4) * 0.061f / 1000.0f;
    return true;
}

bool lsm6_read_gyro(GyroData* data) {
    if (!data) return false;
    data->gx = read_word(OUTX_L_G) * 8.75f / 1000.0f;
    data->gy = read_word(OUTX_L_G + 2) * 8.75f / 1000.0f;
    data->gz = read_word(OUTX_L_G + 4) * 8.75f / 1000.0f;
    return true;
}
