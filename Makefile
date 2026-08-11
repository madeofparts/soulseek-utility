EXES = build/test

all: $(EXES)
clean:
	rm -f $(EXES)

build/test: src/test.cpp
	g++ src/test.cpp -o build/test
.PHONY: all clean
