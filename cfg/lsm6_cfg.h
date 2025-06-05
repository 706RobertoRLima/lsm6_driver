#ifndef LSM6_CFG_H
#define LSM6_CFG_H

// define Drive type hardocode code:
// - PRODUCTION: Real/production Driver.
// - DEVELOPING: wrappers/Mock.
//#define DRIVER_TYPE DEVELOPING

// or 
// define the drive externally using flag -D
#ifndef DRIVER_TYPE
    #error "DRIVER_TYPE must be defined as -DDRIVER_TYPE=PRODUCTION or -DDRIVER_TYPE=DEVELOPING"
#endif

// Validação de valores possíveis
#if !defined(DRIVER_TYPE)
#error "DRIVER_TYPE must be defined as either PRODUCTION or DEVELOPING"
#endif

typedef enum {
    DRIVER_PRODUCTION,
    DRIVER_DEVELOPING
} DriverType;

// Select driver via macro
#if (DRIVER_TYPE == DEVELOPING)
#include "lsm6_mock.h"

    #define READ_REG(addr, reg, value_ptr)     i2c_read_reg((addr), (reg), (value_ptr))
    #define WRITE_REG(addr, reg, value)        i2c_write_reg((addr), (reg), (value))
#else //production extern IF
    #define READ_REG(addr, reg, value_ptr)     i2c_read_reg((addr), (reg), (value_ptr))  // 
    #define WRITE_REG(addr, reg, value)        i2c_write_reg((addr), (reg), (value))
#endif

#define LSM6_ADDR         0x6A
#define WHO_AM_I_REG      0x0F
#define CTRL1_XL          0x10
#define CTRL2_G           0x11
#define OUTX_L_G          0x22
#define OUTX_L_XL         0x28

#define WHO_AM_I_EXPECTED 0x69

#endif // LSM6_CFG_H
