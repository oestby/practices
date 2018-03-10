CPP = g++
FLAGS = -g -std=c++17 -Wall
INCLUDE = -I include
OBJS = bin/matrix.o bin/vector.o bin/imageIO.o bin/image.o

main: main.cpp bin/matrix.o bin/vector.o bin/image.o bin/imageIO.o
	$(CPP) $(FLAGS) -o main main.cpp $(OBJS) $(INCLUDE)

bin/matrix.o: src/matrix.cpp
	$(CPP) $(FLAGS) -o bin/matrix.o -c src/matrix.cpp $(INCLUDE)

bin/vector.o: src/vector.cpp bin/matrix.o
	$(CPP) $(FLAGS) -o bin/vector.o -c src/vector.cpp $(INCLUDE)

bin/imageIO.o: src/ImageIO.cpp
	$(CPP) $(FLAGS) -o bin/imageIO.o -c src/ImageIO.cpp $(INCLUDE)

bin/image.o: src/Image.cpp
	$(CPP) $(FLAGS) -o bin/image.o -c src/Image.cpp $(INCLUDE)

.PHONY: clean

clean:
	rm main bin/*.o
