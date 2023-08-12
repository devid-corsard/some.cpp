BIN = run
OUTDIR = bin
OUTPUT = $(OUTDIR)/$(BIN)
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++20
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

$(OUTPUT): $(OBJECTS)
	mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(OUTPUT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(OUTDIR)

.PHONY: clean
