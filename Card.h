#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
class Card
{
private:
    int face;
    int suit;
    static std::vector<std::string> faceNames;
    static std::vector<std::string> suitNames;
public:
    Card(int face_, int suit_);
    int const getFace();
    int const getSuit();
    std::string const toString();
};

#endif