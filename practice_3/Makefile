CPP = g++
FLAGS = -std=c++17
INCLUDE = -I include/
OBJS = cannonball.o utils.o
MAKEDIR = make/


all: main

main main.cpp: cannon utils
	$(CPP) $(FLAGS) -o main.o main.cpp $(MAKEDIR)* $(INCLUDE)

cannon cannonball.cpp:
	$(CPP) $(FLAGS) -o $(MAKEDIR)cannonball.o -c src/cannonball.cpp $(INCLUDE)

utils utilities.cpp:
	$(CPP) $(FLAGS) -o $(MAKEDIR)utils.o -c src/utilities.cpp $(INCLUDE)

clean:
	rm *.o make/*.o
