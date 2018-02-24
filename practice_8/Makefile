CPP = g++
FLAGS = -g -std=c++17 -Wall
OBJS = bin/*.o
INCLUDE = -I include

.PHONY: clean

main: main.cpp bin/filestreams.o bin/catalog.o
	$(CPP) $(FLAGS) $(OBJS) -o main main.cpp $(INCLUDE)

bin/filestreams.o: src/filestreams.cpp
	$(CPP) $(FLAGS) -o bin/filestreams.o -c src/filestreams.cpp $(INCLUDE)

bin/catalog.o: src/coursecatalog.cpp
	$(CPP) $(FLAGS) -o bin/catalog.o -c src/coursecatalog.cpp $(INCLUDE)

clean:
	rm bin/*.o main
