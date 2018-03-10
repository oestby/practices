CPP = g++
FLAGS = -g -std=c++17 -Wall
INCLUDE = -I include
OBJS = bin/matrix.o bin/vector.o bin/imageIO.o bin/image.o bin/line.o bin/rect.o

main: main.cpp matrices images
	$(CPP) $(FLAGS) -o main main.cpp $(OBJS) $(INCLUDE)

matrices: bin/matrix.o bin/vector.o
images: bin/image.o bin/imageIO.o bin/line.o bin/rect.o

bin/matrix.o: src/matrix.cpp
	$(CPP) $(FLAGS) -o bin/matrix.o -c src/matrix.cpp $(INCLUDE)

bin/vector.o: src/vector.cpp bin/matrix.o
	$(CPP) $(FLAGS) -o bin/vector.o -c src/vector.cpp $(INCLUDE)

bin/imageIO.o: src/ImageIO.cpp
	$(CPP) $(FLAGS) -o bin/imageIO.o -c src/ImageIO.cpp $(INCLUDE)

bin/image.o: src/Image.cpp
	$(CPP) $(FLAGS) -o bin/image.o -c src/Image.cpp $(INCLUDE)

bin/line.o: src/line.cpp
	$(CPP) $(FLAGS) -o bin/line.o -c src/line.cpp $(INCLUDE)

bin/rect.o: src/rectangle.cpp
	$(CPP) $(FLAGS) -o bin/rect.o -c src/rectangle.cpp $(INCLUDE)


.PHONY: clean

clean:
	rm main bin/*.o
