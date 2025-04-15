# yarinkash1@gmail.com
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++2a
TARGET = main_exe
TEST_TARGET = test_exe

all: $(TARGET)

test: $(TEST_TARGET)

main: $(TARGET)
	./$(TARGET)

$(TARGET): main.o 
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o 

$(TEST_TARGET): SquareMatTest.o SquareMat.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) SquareMatTest.o SquareMat.o


main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp

SquareMatTest.o: SquareMatTest.cpp doctest.h
	$(CXX) $(CXXFLAGS) -c SquareMatTest.cpp

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f *.o main_exe test_exe

.PHONY: all clean valgrind main