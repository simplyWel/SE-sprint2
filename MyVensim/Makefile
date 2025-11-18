# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./src

# directory
SRC_DIR = src
TEST_UNIT_DIR = test/unit
TEST_FUNC_DIR = test/funcional
BIN_DIR = bin

# .cpp files in src 
SRC_CPP = $(wildcard $(SRC_DIR)/*.cpp)

# files in src directory, except for main.cpp
SRC_NO_MAIN = $(filter-out $(SRC_DIR)/main.cpp, $(SRC_CPP))

# tests files
UNIT_TEST_FILES = $(wildcard $(TEST_UNIT_DIR)/*.cpp)
FUNC_TEST_FILES = $(wildcard $(TEST_FUNC_DIR)/*.cpp)

# creates executables
PRODUCT = $(BIN_DIR)/product
UNIT_TEST = $(BIN_DIR)/unit_tests
FUNC_TEST = $(BIN_DIR)/funcional_tests

# all compiler
all: $(PRODUCT) $(UNIT_TEST) $(FUNC_TEST)

# compiler the product
$(PRODUCT): $(SRC_CPP)
	@$(CXX) $(CXXFLAGS) -o $(PRODUCT) $(SRC_CPP)

# Compiler units tests
$(UNIT_TEST): $(UNIT_TEST_FILES) $(SRC_NO_MAIN)
	@$(CXX) $(CXXFLAGS) -o $(UNIT_TEST) $(UNIT_TEST_FILES) $(SRC_NO_MAIN)

# Compiler funcional tests
$(FUNC_TEST): $(FUNC_TEST_FILES) $(SRC_NO_MAIN)
	@$(CXX) $(CXXFLAGS) -o $(FUNC_TEST) $(FUNC_TEST_FILES) $(SRC_NO_MAIN)

# clean executables 
clean:
	@rm -f $(PRODUCT) $(UNIT_TEST) $(FUNC_TEST)
