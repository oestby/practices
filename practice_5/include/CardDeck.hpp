#ifndef CARD_DECK_HPP
#define CARD_DECK_HPP

#include<vector>

#include "Card.hpp"

class CardDeck
{
    public:
        CardDeck();

        void print(void) const;
        void printShort(void) const;
        void shuffle(void);
        Card drawCard(void);
        
    private:
        std::vector<Card> cards;
        int currentCardIndex;

        void swap(int ind_1, int ind_2);
};

#endif
