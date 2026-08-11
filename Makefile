CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

EXES = build/test

all: $(EXES)

build/test: src/test.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) src/test.cpp -o build/test

.PHONY: all clean
clean:
	rm -f $(EXES)
