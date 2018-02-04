#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Card.hpp"
#include "CardDeck.hpp"
#include "Blackjack.hpp"

int main(void)
{
    std::srand(std::time(nullptr));
    Blackjack b = Blackjack();
    b.playGame();
    return 0;
}
