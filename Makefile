# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Include directories
INCLUDES = -I./include

# Source files
SRC = src/graph.cpp src/algorithms.cpp src/union_find.cpp src/priority_queue.cpp

# Output file for main demo
OUT = main

# === Main build target ===
$(OUT): main.cpp $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) main.cpp $(SRC) -o $(OUT)

# === Unit test executables ===
test/test_algorithms: test/test_algorithms.cpp $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) test/test_algorithms.cpp $(SRC) -o test/test_algorithms

test/test_data_structures: test/test_data_structures.cpp $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) test/test_data_structures.cpp $(SRC) -o test/test_data_structures

# === Run all tests ===
test: test/test_algorithms test/test_data_structures
	./test/test_algorithms
	./test/test_data_structures

# === Run the main demo ===
run: $(OUT)
	./$(OUT)

# === Valgrind memory check ===
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(OUT)

# === Clean build files ===
clean:
	rm -f $(OUT) test/test_algorithms test/test_data_structures
	