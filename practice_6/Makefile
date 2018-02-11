CPP = g++
FLAGS = -std=c++17 -Wall
INCLUDE = -I include
SFML = -lsfml-graphics -lsfml-window -lsfml-system
OBJS = bin/person.o bin/car.o
GAME_OBJ = bin/cannon.o bin/utils.o  bin/GameObjects.o

all: main sfml-game

main: bin/person.o bin/car.o
	$(CPP) $(FLAGS) -o main main.cpp $(OBJS) $(INCLUDE)

sfml-game: bin/cannon.o bin/utils.o bin/GameObjects.o
	$(CPP) $(FLAGS) -o game game.cpp $(GAME_OBJ) $(INCLUDE) $(SFML)

bin/person.o: 
	$(CPP) $(FLAGS) -o bin/person.o -c src/person.cpp $(INCLUDE)

bin/car.o:
	$(CPP) $(FLAGS) -o bin/car.o -c src/car.cpp $(INCLUDE)

bin/cannon.o:
	$(CPP) $(FLAGS) -o bin/cannon.o -c src/cannonball.cpp $(INCLUDE)

bin/utils.o:
	$(CPP) $(FLAGS) -o bin/utils.o -c src/utilities.cpp $(INCLUDE)

bin/GameObjects.o:
	$(CPP) $(FLAGS) -o bin/GameObjects.o -c src/GameObjects.cpp $(INCLUDE)

clean:
	rm main sfml-game bin/*.o
