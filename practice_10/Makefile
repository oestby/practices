CPP = g++
FLAGS = -g -std=c++17 -Wall
INCLUDE = -I include
OBJS = bin/matrix.o

main: main.cpp bin/matrix.o bin/vector.o
	$(CPP) $(FLAGS) -o main main.cpp $(OBJS) $(INCLUDE)

bin/matrix.o: src/matrix.cpp
	$(CPP) $(FLAGS) -o bin/matrix.o -c src/matrix.cpp $(INCLUDE)

bin/vector.o: src/vector.cpp bin/matrix.o
	$(CPP) $(FLAGS) -o bin/vector.o -c src/vector.cpp $(INCLUDE)

.PHONY: clean

clean:
	rm main bin/*.o
