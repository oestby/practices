#include <iostream>

#include "Card.hpp"

int main(void)
{
    CardStruct card(Suit::DIAMONDS, ACE);

    std::cout << toString(card) << " - " << toStringShort(card) << std::endl;

    return 0;
}
