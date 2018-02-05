#include <string>
#include <sstream>

#include "Card.hpp"

std::string
suitToString(Suit data)
{
    switch(data)
    {
        case Suit::CLUBS:
        return "clubs";
        break;
        case Suit::DIAMONDS:
        return "diamonds";
        break;
        case Suit::HEARTS:
        return "hearts";
        break;
        case Suit::SPADES:
        return "spades";
        break;
        default:
        return " ";
        break;
    }
}

std::string
rankToString(Rank data)
{
    switch(data)
    {
        case Rank::TWO:
        return "two";
        break;
        case Rank::THREE:
        return "three";
        break;
        case Rank::FOUR:
        return "four";
        break;
        case Rank::FIVE:
        return "five";
        break;
        case Rank::SIX:
        return "six";
        break;
        case Rank::SEVEN:
        return "seven";
        break;
        case Rank::EIGHT:
        return "eight";
        break;
        case Rank::NINE:
        return "nine";
        break;
        case Rank::TEN:
        return "ten";
        break;
        case Rank::JACK:
        return "jack";
        break;
        case Rank::QUEEN:
        return "queen";
        break;
        case Rank::KING:
        return "king";
        break;
        case Rank::ACE:
        return "ace";
        break;
        default:
        return " ";
        break;
    }
}

std::string
toString(CardStruct c)
{
    std::string msg = rankToString(c.r) + " of " + suitToString(c.s);
    return msg;
}

std::string
toStringShort(CardStruct c)
{
    std::string suit = suitToString(c.s);
    std::string msg = suit.substr(0,1) + std::to_string(static_cast<int>(c.r));
    return msg;
}

void
Card::initialize(Rank rank, Suit suit)
{
    this->suit = suit;
    this->rank = rank;
    this->valid = true;
}

std::string
Card::toString(void) const
{  
    if (!(this->valid))
    {
        return "Invalid card!";
    }
    std::string msg = rankToString(this->rank) + " of " + suitToString(this->suit);
    return msg;
}

std::string
Card::toStringShort(void) const
{
    std::string suit = suitToString(this->suit);
    std::string msg = suit.substr(0,1) +std::to_string(static_cast<int>(this->rank));
    return msg;
}

Suit
Card::getSuit(void) const
{
    return this->suit;
}

Rank
Card::getRank(void) const
{
    return this->rank;
}
