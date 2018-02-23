CPP = g++
FLAGS = -std=c++17 -Wall
OBJS = bin/fib.o bin/matrix.o
INCLUDE = -I include

default: clean main

main: bin/fib.o bin/matrix.o
	$(CPP) $(FLAGS) -o main main.cpp $(OBJS) $(INCLUDE)

bin/fib.o:
	$(CPP) $(FLAGS) -o bin/fib.o -c src/fib.cpp $(INCLUDE)

bin/matrix.o:
	$(CPP) $(FLAGS) -o bin/matrix.o -c src/matrix.cpp $(INCLUDE)

clean:
	rm main bin/*.o
