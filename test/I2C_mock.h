#ifndef LSM6_MOCK_H
#define LSM6_MOCK_H

#include <stdint.h>
#include <stdio.h>

void i2c_write_reg(uint8_t addr, uint8_t reg, uint8_t value);
void i2c_read_reg(uint8_t addr, uint8_t reg, uint8_t* value);

// Mock control
void mock_set_register(uint8_t reg, uint8_t value);
void mock_clear_registers(void);

#endif
