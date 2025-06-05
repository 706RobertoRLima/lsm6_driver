#include "unity.h"
#include "lsm6.h"
#include "lsm6_mock.h"

void setUp(void) {
    mock_clear_registers();
}

void tearDown(void) {
    
}

void test_init_should_succeed_when_whoami_matches(void) {
    mock_set_register(WHO_AM_I_REG, WHO_AM_I_EXPECTED);
    TEST_ASSERT_TRUE(lsm6_init());
}

void test_init_should_fail_on_wrong_whoami(void) {
    mock_set_register(WHO_AM_I_REG, 0x00);
    TEST_ASSERT_FALSE(lsm6_init());
}

void test_accel_read_returns_scaled_values(void) {
    mock_set_register(0x28, 0x10); // L
    mock_set_register(0x29, 0x00); // H -> 0x0010 = 16
    mock_set_register(0x2A, 0x20);
    mock_set_register(0x2B, 0x00);
    mock_set_register(0x2C, 0x30);
    mock_set_register(0x2D, 0x00);

    AccelData accel;
    lsm6_read_accel(&accel);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 0.000976f, accel.ax);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 0.001952f, accel.ay);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 0.002929f, accel.az);
}

void test_gyro_read_returns_scaled_values(void) {
    mock_set_register(0x22, 0x08);
    mock_set_register(0x23, 0x00);
    mock_set_register(0x24, 0x10);
    mock_set_register(0x25, 0x00);
    mock_set_register(0x26, 0x18);
    mock_set_register(0x27, 0x00);

    GyroData gyro;
    lsm6_read_gyro(&gyro);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 0.07f, gyro.gx);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 0.14f, gyro.gy);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 0.21f, gyro.gz);
}

//main function
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_init_should_succeed_when_whoami_matches);
    RUN_TEST(test_init_should_fail_on_wrong_whoami);
    return UNITY_END();
}
