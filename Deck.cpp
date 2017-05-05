////////////////////////////////////////////////////////////////////////////////
// File Name:      Deck.cpp
//
// Author:         Paul Marik, David Wissink 
// CS email:       marik@cs.wisc.edu, wissink@cs.wisc.edu
//
// Description:    Deck of flashcards for a user.
//
// Sources:        cppreference.com, <sources, if any>
//
// URL(s) of sources:
//                 http://en.cppreference.com/w/cpp/container/vector
//                 <URLs of your sources, if any>
////////////////////////////////////////////////////////////////////////////////

#include "Deck.hpp"


    int Deck::deckCount = 0;


    Deck::Deck(){

        //Keeps track of total number of decks created
        deckCount++;
        deckName = "Deck Number " + deckCount;
        deckSize = 0;
       

    }

    Deck::Deck(std::string loadname){
        
        deckName = loadname;
        deckCount++;
        deckSize = 0;
    }

    void Deck::add(Flashcard card){
    
        usersCards.push_back(card);
        deckSize++;

    }

    void Deck::renameDeck(std::string newName){
        deckName = newName;
    }

    std::string Deck::getDeckName(){
        return deckName;
    }

    Flashcard& Deck::getCard(int index){
        return usersCards[index];
    }

    int Deck::getDeckSize(){
        return deckSize;
    }

    void Deck::deleteCard(int index){
        //Deletes a card at specified index
        usersCards.erase(usersCards.begin() + index);
        deckSize--;
    }
    
