# ---- Compiler setup ----
CXX       ?= g++
CXXFLAGS  ?= -std=c++17 -Wall -Wextra -Wpedantic -O2
INCLUDES  := -Isrc

# ---- Paths ----
BUILD_DIR := build

# ---- Binaries & Sources ----
TEST_BIN  := $(BUILD_DIR)/test_vector
TEST_SRC  := tests/test_vector_tasks.cpp

DEMO_BIN  := $(BUILD_DIR)/demo
DEMO_SRC  := src/main.cpp

LIB_SRC   := src/vector_tasks.cpp
LIB_HDR   := src/vector_tasks.hpp

# ---- Default ----
all: $(TEST_BIN) $(DEMO_BIN)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(TEST_BIN): $(TEST_SRC) $(LIB_SRC) $(LIB_HDR) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(TEST_SRC) $(LIB_SRC) -o $@

$(DEMO_BIN): $(DEMO_SRC) $(LIB_SRC) $(LIB_HDR) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEMO_SRC) $(LIB_SRC) -o $@

run-tests: $(TEST_BIN)
	$(TEST_BIN)

# Run demo with: make run-demo ARGS="1 2 3 -4"
ARGS ?= 1 2 3 -4
run-demo: $(DEMO_BIN)
	$(DEMO_BIN) $(ARGS)

# Sanitizers build (Address + Undefined)
ASANFLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer -O1
asan: CXXFLAGS += $(ASANFLAGS)
asan: clean all

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all run-tests run-demo asan clean
