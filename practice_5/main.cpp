#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Card.hpp"
#include "CardDeck.hpp"

int main(void)
{
    std::srand(std::time(nullptr));
    CardStruct card(Suit::DIAMONDS, Rank(10));

    CardDeck deck_1 = CardDeck();
    deck_1.print();
    deck_1.shuffle();
    deck_1.print();
    return 0;
}
