# compiler variables
CXX= g++
CXXFLAGS= -Wall -Og -std=c++11
LDLIBS= -lm
BIN= auto_diff

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

.PHONY: clean
clean:
	rm -f $(BIN) *.o


