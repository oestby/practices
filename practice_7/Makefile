CPP = g++
FLAGS = -std=c++17 -Wall
OBJS = bin/fib.o 
INCLUDE = -I include

main: bin/fib.o
	$(CPP) $(FLAGS) -o main main.cpp $(OBJS) $(INCLUDE)

bin/fib.o:
	$(CPP) $(FLAGS) -o bin/fib.o -c src/fib.cpp $(INCLUDE)

clean:
	rm main bin/*.o
