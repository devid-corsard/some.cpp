CXX = g++-13
CXXFLAGS = -Wall -Wextra -std=c++20
OUTPUT = bin/game
SOURCES = src/*.cpp
HEADERS = src/*.hpp
DIR_GUARD=mkdir -p bin

$(OUTPUT): $(SOURCES) $(HEADERS)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)
