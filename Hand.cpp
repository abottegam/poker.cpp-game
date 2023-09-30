#include "Hand.h"
#include <iostream>
#include <algorithm>

std::vector<std::string> Hand::handNames = {"Royal Flush", "Straight Flush", "Four of a Kind", "Full House", "Flush", "Straight", "Three of a Kind", "Two Pair", "Pair", "High Card" };

Hand::Hand(DeckOfCard& deck){
    int i = 0;
    while (i<5)
    {
        hand.push_back(deck.dealCard());
        faceCount.push_back(hand[i].getFace());   
        i++;
    }
}

int const Hand::highCard(){
    int max = hand[0].getFace();
    int index=0;
    for (int i = 0; i < hand.size(); i++)
    {
        if (hand[i].getFace()>max)
        {
            max = hand[i].getFace();
            index = i;
        }
        
    }
    // for (int i = 0; i < hand.size(); i++)
    // {
    //     std::cout << hand[i].getFace() << std::endl;
    // }
    
    return max+1;
}

bool const Hand::pair(){
    int count = 0;
    for (int i = 0; i < hand.size(); i++)
    {
        for (int j = i+1; j < hand.size(); j++)
        {
            if (hand[i].getFace()==hand[j].getFace())
            {
                return true;
            }
        }
    }
    return false;
}

bool const Hand::twoPair() {
    int pairs = 0;
    for (size_t i = 0; i < hand.size(); i++) {
        for (size_t j = i + 1; j < hand.size(); j++) {
            if (hand[i].getFace()==hand[j].getFace()) {
                pairs++;
            }
        }
    }
    return pairs == 2;
}

bool const Hand::threeOfAKind() {
    // check if hand contains three of a kind
    for (size_t i = 0; i < hand.size(); i++) {
            int count = 0;
            for (size_t j = 0; j < hand.size(); j++) {
                if (hand[i].getFace() == hand[j].getFace()) {
                    count++;
                }
            }
            if (count == 3) {
                return true;
            }
        }
    return false;
}

bool const Hand::flush(){
    for (size_t i = 0; i < hand.size(); i++) {
        for (size_t j = 0; j < hand.size(); j++) {
            if (hand[i].getFace()!=hand[j].getFace()) {
                return false;
            }
        }
    }
    return true;
}

bool const Hand::straight(){
    //std::vector<int> temp = faceCount;
    for (int i = 0; i < faceCount.size(); i++) {
        for (int j = i + 1; j < faceCount.size(); j++)
        {
            if (faceCount[i] > faceCount[j]) {
                int temp = faceCount[i];
                faceCount[i] = faceCount[j];
                faceCount[j] = temp;
            }
        }
    }          // check if the hand contains a straight
    for (size_t i = 0; i < hand.size() - 1; i++) {
        if (faceCount[i] + 1 != faceCount[i + 1]) {
            return false;
        }
    }
    return true;
}

bool const Hand::fullHouse(){
    if(threeOfAKind() && pair()){
        return true;
    }
    return false;
}

bool const Hand::fourOfAKind(){
    for (size_t i = 0; i < hand.size(); i++) {
            int count = 0;
            for (size_t j = 0; j < hand.size(); j++) {
                if (hand[i].getFace() == hand[j].getFace()) {
                    count++;
                }
            }
            if (count == 4) {
                return true;
            }
        }
        return false;
}

bool const Hand::straightFlush(){
    if(flush() && straight()){
        return true;
    }
    return false;
}


bool const Hand::royalFlush(){
    for (int i = 0; i < faceCount.size(); i++) {
        for (int j = i + 1; j < faceCount.size(); j++)
        {
            if (faceCount[i] > faceCount[j]) {
                int temp = faceCount[i];
                faceCount[i] = faceCount[j];
                faceCount[j] = temp;
            }
        }
    }   
    //std::cout << straightFlush();
    if(straightFlush()){
        if (faceCount[0] != 0)
        {
            return false;
        }
        return true;
    }
    return false;
}

void const Hand::printHand() {
    // print cards in the hand
    std::cout << "Hand contains: \n";
    for (Card card : hand) {
        std::cout << card.toString() << "\n";
    }
    std::cout << std::endl;
    std::cout << handNames[getHand()] << " ";
    if(getHand()==9){
        switch (highCard())
        {
        case 13:
            std::cout << "King";
            break;
        case 12:
            std::cout << "Queen";
            break;
        case 11:
            std::cout << "Jack";
            break;
        case 10:
            std::cout << "ten";
            break;
        case 9:
            std::cout << "nine";
            break;
        case 8:
            std::cout << "eight";
            break;
        case 7:
            std::cout << "seven";
            break;
        case 6:
            std::cout << "six";
            break;
        case 5:
            std::cout << "five";
            break;       
        default:
            break;
        }
    }
    std::cout << std::endl;
}
int const Hand::getHand(){
    if (royalFlush())
    {
        return 0;
    }
    else if(straightFlush()){
        return 1;
    }
    else if(fourOfAKind()){
        return 2;
    }
    else if(fullHouse()){
        return 3;
    }
    else if(flush()){
        return 4;
    }
    else if(straight()){
        return 5;
    }
    else if(threeOfAKind()){
        return 6;
    }
    else if(twoPair()){
        return 7;
    }
    else if(pair()){
        return 8;
    }
    else{
        return 9;
    }
    
}