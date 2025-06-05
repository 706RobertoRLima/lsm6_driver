# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I. -Iexternal/unity/src -Iapi -Isrc -Icfg -Iwrappers -Itest
BUILD_DIR = build

# Driver type (default: DEVELOPING)
DRIVER ?= DEVELOPING
CFLAGS += -DDRIVER_TYPE=$(DRIVER)

# Sources
SRC = src/lsm6.c
WRAPPERS = wrappers/lsm6_mock.c
TEST_SRC = test/ut_lsm6.c
UNITY_SRC = external/unity/src/unity.c

# Targets
TARGET = $(BUILD_DIR)/test_runner

# Object files
OBJS = $(SRC) $(WRAPPERS) $(TEST_SRC) $(UNITY_SRC)
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(OBJS)))

# Default target
all: test

# Build test target
test: $(BUILD_DIR) $(TARGET)
	./$(TARGET)

# Link final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files to object files
$(BUILD_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/%.o: wrappers/%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/%.o: test/%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/%.o: external/unity/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build/ exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)

# Optional: Just build the lsm6 object file (no test)
lib: $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC) -o $(BUILD_DIR)/lsm6.o

# Help
help:
	@echo "Available targets:"
	@echo "  make test     - Build and run unit tests (creates build/ directory)"
	@echo "  make lib      - Compile the library only (outputs lsm6.o in build/)"
	@echo "  make clean    - Remove all build artifacts"
	@echo "  make help     - Show this help message"
