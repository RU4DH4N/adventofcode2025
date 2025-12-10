CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++14 -Iinclude -O3 -march=native -flto -DNDEBUG

SRC_DIR = src
BUILD_DIR = build
RESOURCE_DIR = resources

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

TARGET = $(BUILD_DIR)/program

all: $(TARGET) copy_resources

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build successful! Run with: ./$(TARGET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

copy_resources:
	@mkdir -p $(BUILD_DIR)/resources
	@cp -r $(RESOURCE_DIR)/* $(BUILD_DIR)/resources/ 2>/dev/null || true
	@echo "Resources copied to $(BUILD_DIR)/resources/"

clean:
	rm -rf $(BUILD_DIR)

run: all
	@cd $(BUILD_DIR) && ./program

.PHONY: all clean copy_resources run