#include <vector>
#include <iostream>

#include "CardDeck.hpp"
#include "Utilities.hpp"

CardDeck::CardDeck():
currentCardIndex(0)
{
    for (int s = 0; s < 4; s++)
    {
        for (int r = 2; r < 15; r++)
        {
            cards.push_back(Card(Rank(r), Suit(s)));
        }
    }
    this->shuffle();
}

void
CardDeck::print(void) const
{
    for (auto deckIterator = this->cards.cbegin(); deckIterator != this->cards.cend(); ++deckIterator)
    {
        std::cout << deckIterator->toString() << std::endl;
    }
}

void
CardDeck::printShort(void) const
{
    for (auto deckIterator = this->cards.cbegin(); deckIterator != this->cards.cend(); ++deckIterator)
    {
        std::cout << deckIterator->toStringShort() << std::endl;
    }
}

void
CardDeck::shuffle(void)
{
    for (int i = 0; i < 10000; i++)
    {
        int a = randomWithLimits(0, 52), b = randomWithLimits(0, 52);
        this->swap(a,b);
    }

}

Card
CardDeck::drawCard(void)
{
    Card temp = this->cards.back();
    this->cards.pop_back();
    currentCardIndex++;
    return temp;
}

void
CardDeck::swap(int ind_1, int ind_2)
{
    Card temp = cards[ind_1];
    cards[ind_1] = cards[ind_2];
    cards[ind_2] = temp;    
}
