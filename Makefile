CXX = g++
CXXFLAGS = -Wall

SRC = src/main.cpp src/classes/Livro.cpp
OBJ = main.o Livro.o
EXEC = biblioteca

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Livro.o: src/classes/Livro.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)