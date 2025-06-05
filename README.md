# lsm6_driver
LSM6 IMU Driver Implementation &amp; Testing  

# to clone the repository
git clone --recurse-submodules https://github.com/706RobertoRLima/lsm6_driver.git
git submodule update --init --recursive

# Description

### Driver library

- Write a small, reusable **C / C++** library for an ST **LSM6** IMU (any recent variant).
- The API must allow a user to
    - initialize the device,
    - read accelerometer and gyroscope data and return acceleration and angular velocity

### Unit tests with mocks

- Add a test suite with unit test for the driver without the real hardware (mock the I²C/SPI transactions).


# Run commands

make test  -> Compiles all source files, links them into an executable test_runner inside build/, and then runs it.<br/>
make lib   -> Compiles only the main source file (lsm6.c) into an object file (lsm6.o) inside build/. Useful for building the library without running tests.<br/>
make clean -> Deletes the entire build/ directory and all compiled files, allowing for a clean rebuild.<br/>
make help  -> list of option<br/>
