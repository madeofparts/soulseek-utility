CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++20

EXES = build/main

all: $(EXES)

build/main: src/main.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) src/main.cpp -o build/main

.PHONY: all clean
clean:
	rm -f $(EXES)
