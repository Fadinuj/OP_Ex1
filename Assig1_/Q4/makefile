# Name of the target executable
TARGET = dijkstra

# Source file
SRC = dijkstra.cpp

# Compiler and flags (gcov instrumentation included)
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -fprofile-arcs -ftest-coverage -g
LDFLAGS = -lgcov

# Default target: compile the program with gcov support
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Run the compiled program
run: $(TARGET)
	./$(TARGET)

# Run gcov to generate code coverage report
coverage: $(TARGET)
	gcov $(SRC)

# Clean generated files (binary + coverage data)
clean:
	rm -f $(TARGET) *.gcda *.gcno *.gcov

# Run program and generate coverage in one step
full: run coverage
