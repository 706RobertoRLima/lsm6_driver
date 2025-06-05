#ifndef LSM6_H
#define LSM6_H

#include <stdint.h>
#include <stdbool.h>
#include <lsm6_cfg.h>

typedef struct {
    float ax, ay, az;
} AccelData;

typedef struct {
    float gx, gy, gz;
} GyroData;

bool lsm6_init(void);
bool lsm6_read_accel(AccelData* data);
bool lsm6_read_gyro(GyroData* data);

#endif // LSM6_H
