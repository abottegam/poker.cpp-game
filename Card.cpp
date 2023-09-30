#include "Card.h"
#include <string>
#include <vector>

std::vector<std::string> Card::faceNames = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
std::vector<std::string> Card::suitNames = {"Hearts", "Diamonds", "Clubs", "Spades"};

    int const Card::getFace(){
        return face;
    }
    int const Card::getSuit(){
        return suit;
    }
    Card::Card(int face_, int suit_){
        face = face_;
        suit = suit_;
    }
    std::string const Card::toString(){
        // std::string s1 = face + " of " + suit;
        return faceNames[face] + " of " + suitNames[suit];
    }


