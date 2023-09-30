#include "DeckOfCard.h"
#include <cstdlib>
#include <ctime>

DeckOfCard::DeckOfCard(){
    currentCard = 0;
    for (size_t i = 0; i < 52 ; i++)
    {
        deck.push_back(Card(i % 13, i / 13));
    }
    
}
    void DeckOfCard::shuffle(){
        srand(time(0));
        for (size_t i = 0; i < 2; i++)
        {
            for (size_t j = 0; j < 52; j++)
            {
                int ran = rand() % 52;
                Card temp = deck[i];
                deck[i] = deck[ran];
                deck[ran] = temp;
            }
            
        }
        currentCard = 0;
    }
    Card DeckOfCard::dealCard(){
        if(moreCards()){
            return deck[currentCard++];
        }
        else{ return Card(-1,-1); }
        
    }
    bool const DeckOfCard::moreCards(){
        return currentCard < 52;
    }