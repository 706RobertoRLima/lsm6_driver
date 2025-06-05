#include "I2C_mock.h"
#include <string.h>

static uint8_t mock_regs[256];

void i2c_write_reg(uint8_t addr, uint8_t reg, uint8_t value) {
    mock_regs[reg] = value;
}

void i2c_read_reg(uint8_t addr, uint8_t reg, uint8_t* value) {
    *value = mock_regs[reg];
}

void mock_set_register(uint8_t reg, uint8_t value) {
    mock_regs[reg] = value;
}

void mock_clear_registers(void) {
    memset(mock_regs, 0, sizeof(mock_regs));
}

