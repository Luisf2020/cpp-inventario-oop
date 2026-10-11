CXX ?= c++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

all: inventario

inventario: src/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run: inventario
	./inventario inventario.csv

clean:
	rm -f inventario

.PHONY: all run clean
