#ifndef DECKOFCARD_H
#define DECKOFCARD_H

#include "Card.h"
#include <vector>

class DeckOfCard
{
private:
    std::vector<Card> deck;
    int currentCard;
public:
    DeckOfCard();
    void shuffle();
    Card dealCard();
    bool const moreCards();
};


#endif