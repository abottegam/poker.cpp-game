#ifndef HAND_H
#define HAND_H

#include "DeckOfCard.h"
#include <vector>


class Hand
{
private:
    std::vector<Card> hand;
    std::vector<int> faceCount;
    static std::vector<std::string> handNames;
    int handName;
public:
    Hand(DeckOfCard& deck);
    int const getHand();
    int const highCard();
    bool const pair();
    bool const twoPair();
    bool const threeOfAKind();
    bool const straight();
    bool const flush();
    bool const fullHouse();
    bool const fourOfAKind();
    bool const straightFlush();
    bool const royalFlush();
    void const printHand();
};

#endif