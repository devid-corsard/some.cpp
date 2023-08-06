CXX = g++-13
CXXFLAGS = -Wall -Wextra -std=c++11
OUTPUT = bin/game_over
SOURCES = src/main.cpp src/rand_up.cpp src/game.cpp
HEADERS = src/lib.hpp

$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)
