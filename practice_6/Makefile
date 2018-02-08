CPP = g++
FLAGS = -std=c++17 -Wall
INCLUDE = -I include
OBJS = bin/person.o bin/car.o

main: bin/person.o bin/car.o
	$(CPP) $(FLAGS) -o main main.cpp $(OBJS) $(INCLUDE)

bin/person.o: 
	$(CPP) $(FLAGS) -o bin/person.o -c src/person.cpp $(INCLUDE)

bin/car.o:
	$(CPP) $(FLAGS) -o bin/car.o -c src/car.cpp $(INCLUDE)

clean:
	rm main bin/*.o