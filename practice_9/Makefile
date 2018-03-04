CPP = g++
INCLUDE = -I include -I SFML-2.4.2/include
LINK = -L SFML-2.4.2/lib -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = bin/*
FLAGS = -g -Wall -std=c++17

.PHONY: clean

minesweeper: main.cpp bin/minesweeper.o
	$(CPP) $(FLAGS) -o minesweeper main.cpp $(OBJECTS) $(INCLUDE) $(LINK)

bin/minesweeper.o: src/Minesweeper.cpp
	$(CPP) $(FLAGS) -o bin/minesweeper.o -c src/Minesweeper.cpp $(INCLUDE)
clean:
	rm bin/*.o minesweeper
