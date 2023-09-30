#include <iostream>
#include "Hand.h"
#include <string>

using std::string;


int main(){
    DeckOfCard myDeckOfCards;
    myDeckOfCards.shuffle();
    Hand myHand(myDeckOfCards);
    Hand otherHand(myDeckOfCards);
    myHand.printHand();
    std::cout << "------------------------------------" << std::endl;
    otherHand.printHand();
    if (myHand.getHand()==otherHand.getHand())
    {
        if(myHand.getHand()==9){
            if (myHand.highCard()==otherHand.highCard())
            {
                std::cout << "Its a tie!" << std::endl;
            }
            else if(myHand.highCard()>otherHand.highCard()){
                std::cout << "Player 1 wins" << std::endl;
            }
            else{
                std::cout << "Player 2 wins" << std::endl;
            }
            
        }
        else{
        std::cout << "Its a tie!" << std::endl;
        }
    }
    else if(myHand.getHand() < otherHand.getHand()){
        std::cout << "Player 1 wins";
    }
    else{
        std::cout << "Player 2 wins";
    }
}