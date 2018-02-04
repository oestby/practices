#include <iostream>

#include "Blackjack.hpp"

Blackjack::Blackjack():
playerHand(0),
dealerHand(0),
playerCardsDrawn(0),
dealerCardsDrawn(0)
{
    //empty
}

bool
Blackjack::isAce(Card* const c) const
{
    if (c->getRank() == Rank::ACE)
    {
        return true;
    }
    else{
        return false;
    }
}

int
Blackjack::getCardValue(Card* const c) const
{
    if (this->isAce(c))
    {
        return -1;
    }
    else{
        if (static_cast<int>(c->getRank())>10)
        {
            return 10;
        }
        else{
        return static_cast<int>(c->getRank());
        }
    }
    
}

int
Blackjack::getPlayerCardValue(Card* const c) const
{
    if (this->isAce(c))
    {
        char choice = 'm';
        while (choice != 'o' && choice != 'e' ){
            std::cout << "Would you like this card to have a value of 11 or 1?" << std::endl
            << "Enter \"e\" for 11 or \"o\" for one:";
            std::cin >> choice;
            if (choice != 'o' || choice != 'e')
            {
                std::cout << "Not a valid option, try again!" << std::endl;
            }
        }
        if (choice == 'o') return 1;
        else return 11;
        
    }
    else{
        return static_cast<int>(c->getRank());
    }
}

int
Blackjack::getDealerCardValue(Card* const c) const
{
    if (this->isAce(c))
    {
        if (this->dealerHand + 11 > 21)
        {
            return 1;
        }
        else{
            return 11;
        }
    }
    else{
        return static_cast<int>(c->getRank());
    }
}

bool
Blackjack::askPlayerDrawCard(void) const
{
    std::cout << "Do you want to draw another card?" << std::endl;
    char choice;
    while (choice != 'y' && choice != 'n')
    {
        std::cout << "Yes or no? (y/n): ";
        std::cin >> choice;

        if (choice != 'y'|| choice != 'n')
        {
            std::cout << "That is not a valid answer, try again." << std::endl;
        }
    }
    if (choice == 'y') return true;
    else return false;
}

void
Blackjack::drawInitialCards(void)
{
    Card *c = new Card();
    *c = this->deck.drawCard();
    dealerHand += this->getDealerCardValue(c);
    dealerCardsDrawn++;
    std::cout << "The dealers first card is a " << c->toString() << std::endl;

    *c = this->deck.drawCard();
    dealerHand += this->getDealerCardValue(c);
    dealerCardsDrawn++;

    *c = this->deck.drawCard();
    playerHand+= this->getPlayerCardValue(c);
    playerHand++;
    std::cout << "You drew a " << c->toString() << std::endl;

    *c = this->deck.drawCard();
    playerHand += this->getPlayerCardValue(c);
    playerHand++;
    std::cout << "You drew a " << c->toString() << std::endl;
}

void
Blackjack::playGame(void)
{
    Card *c = new Card();
    std::cout << "Welcome to a game of Blackjack!" << std::endl 
    << "Let's draw the initial hands!" << std::endl << std::endl;

    this->drawInitialCards();

    while(this->askPlayerDrawCard())
    {
        *c = this->deck.drawCard();
        playerHand += this->getPlayerCardValue(c);
        playerCardsDrawn++;
        std::cout << "You drew a " << c->toString() << " and your hand is now "
        << playerHand << " points!" << std::endl;
        if (playerHand > 21) break;
        if (dealerHand > 17)
        {
            *c = this->deck.drawCard();
            dealerHand += this->getDealerCardValue(c);
            dealerCardsDrawn++;
        }        
    }
    if (playerHand > 20)
    {
        std::cout << "Shoot, you went over! Try again!" << std::endl;
    }
    else{
        std::cout << "And we are done!" << std::endl
        << "With a dealer value of " << dealerHand << " and a player value of "
        << playerHand << std::endl;
        if (playerHand > dealerHand)
        {
            std::cout << "Congratulations! You win!" << std::endl;
        }
        else{
            std::cout << "Too bad, the dealer won this one!" << std::endl;
        }
    }
}
