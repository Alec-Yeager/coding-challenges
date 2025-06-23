CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = 42
SRC = src\\$(TARGET).cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o build\\$(TARGET)

run: $(TARGET)
	build\\$(TARGET) < input\\$(TARGET).txt