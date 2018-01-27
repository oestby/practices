CPP = g++
FLAGS = -std=c++17 -Wall
INCLUDE = include

main: utils tests mastermind
	$(CPP) $(FLAGS) -o main.o main.cpp src/utils.o src/tests.o src/mastermind.o -I $(INCLUDE)

utils:
	$(CPP) $(FLAGS) -o src/utils.o -c src/utilities.cpp -I $(INCLUDE)

tests:
	$(CPP) $(FLAGS) -o src/tests.o -c src/tests.cpp -I $(INCLUDE)

mastermind:
	$(CPP) $(FLAGS) -o src/mastermind.o -c src/mastermind.cpp -I $(INCLUDE)

clean:
	rm *.o src/*.o