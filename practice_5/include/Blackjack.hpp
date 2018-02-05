#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "CardDeck.hpp"

class Blackjack
{
public:
    Blackjack();
    bool isAce(Card* const c) const;
    int getCardValue(Card* const c) const;
    int getPlayerCardValue(Card* const c) const;
    int getDealerCardValue(Card* const c) const;
    bool askPlayerDrawCard(void) const;
    void drawInitialCards(void);
    void playGame(void);

private:
    int playerHand, dealerHand, playerCardsDrawn, dealerCardsDrawn;
    CardDeck deck;

};

#endif
