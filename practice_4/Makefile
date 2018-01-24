CPP = g++
FLAGS = -std=c++17 -Wall
INCLUDE = include

main: utils tests
	$(CPP) $(FLAGS) -o main.o main.cpp src/utils.o src/tests.o -I $(INCLUDE)

utils:
	$(CPP) $(FLAGS) -o src/utils.o -c src/utilities.cpp -I $(INCLUDE)

tests:
	$(CPP) $(FLAGS) -o src/tests.o -c src/tests.cpp -I $(INCLUDE)

clean:
	rm *.o src/*.o