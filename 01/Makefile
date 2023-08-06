CXX = g++-13
CXXFLAGS = -Wall -Wextra -std=c++11
OUTPUT = bin/game_over
SOURCES = src/*.cpp
HEADERS = src/*.hpp
DIR_GUARD=mkdir -p bin

$(OUTPUT): $(SOURCES) $(HEADERS)
	mkdir bin
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)
