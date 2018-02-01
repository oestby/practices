#ifndef CARD_HPP
#define CARD_HPP

#include <string>

enum class Suit: int {CLUBS,DIAMONDS,HEARTS,SPADES};
enum Rank: int {TWO=2,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE};

struct CardStruct
{
    CardStruct(Suit s, Rank r): s(s), r(r) {}
    Suit s;
    Rank r;
};

std::string suitToString(Suit data);
std::string rankToString(Rank data);
std::string toString(CardStruct c);
std::string toStringShort(CardStruct c);

class Card
{
public:
    Card():
    valid(false) {};

    Card(Rank rank, Suit suit):
    rank(rank), suit(suit), valid(true) {};
    
    void initialize(Rank rank, Suit suit);
    Suit getSuit(void) const;
    Rank getRank(void) const;
    std::string toString(void) const;
    std::string toStringShort(void) const;

private:
    Rank rank;
    Suit suit;
    bool valid;

};



#endif
