CPP = g++
FLAGS = -g -std=c++17 -Wall
OBJS = bin/fib.o bin/matrix.o
INCLUDE = -I include

main: bin/fib.o bin/matrix.o
	$(CPP) $(FLAGS) -o main main.cpp $(OBJS) $(INCLUDE)

bin/fib.o: src/fib.cpp
	$(CPP) $(FLAGS) -o bin/fib.o -c src/fib.cpp $(INCLUDE)

bin/matrix.o: src/matrix.cpp
	$(CPP) $(FLAGS) -o bin/matrix.o -c src/matrix.cpp $(INCLUDE)

.PHONY: clean
clean:
	rm main bin/*.o
