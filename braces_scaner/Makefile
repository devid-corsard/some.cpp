BIN = run
OUTDIR = bin
OUTPUT = $(OUTDIR)/$(BIN)
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++20
SOURCES = src/*.cpp
HEADERS = src/*.hpp

$(OUTPUT): $(SOURCES) $(HEADERS)
	mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -rf $(OUTDIR)
