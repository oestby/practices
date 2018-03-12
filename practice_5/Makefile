CPP = g++
FLAGS = -std=c++17 -Wall
INCLUDE = -I include
OBJS = bin/card.o bin/deck.o bin/utils.o bin/blackjack.o

main: main.cpp bin/card.o bin/deck.o bin/blackjack.o bin/utils.o
	$(CPP) $(FLAGS) -o main main.cpp $(OBJS) $(INCLUDE)

bin/card.o: src/Card.cpp
	$(CPP) $(FLAGS) -o bin/card.o -c src/Card.cpp $(INCLUDE)

bin/utils.o: src/Utilities.cpp
	$(CPP) $(FLAGS) -o bin/utils.o -c src/Utilities.cpp $(INCLUDE)

bin/deck.o: src/CardDeck.cpp 
	$(CPP) $(FLAGS) -o bin/deck.o -c src/CardDeck.cpp $(INCLUDE)

bin/blackjack.o: src/Blackjack.cpp
	$(CPP) $(FLAGS) -o bin/blackjack.o -c src/Blackjack.cpp $(INCLUDE)

clean:
	rm main bin/*.o
