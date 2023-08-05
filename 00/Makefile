# CXX = g++
CXX = g++-13
CXXFLAGS = -Wall -Wextra -std=c++11
OUTPUT = bin/factorial_program
SOURCES = src/main.cpp src/factorial.cpp
HEADERS = src/factorial.h

$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)
