////////////////////////////////////////////////////////////////////////////////
// File Name:      Deck.hpp
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

#ifndef Final_Deck_HPP
#define Final_Deck_HPP

#include "Flashcard.hpp"

#include <string>
#include <vector>

class Deck{

    private:

        std::string deckName;

        //The vector used to store multiple flashcards
        std::vector <Flashcard> usersCards;
        static int deckCount;
        int deckSize;

    public:

        /**
         * @brief Default constructor of a Deck
         *
         *
         */
        Deck();

        /**
         * @brief Constructor that takes a name of a file to initialize a deck
         *
         * @param loadname the name to initialize a deck
         */
        Deck(std::string loadname);

        /**
         * @brief Adds a flashcard to the current deck
         *
         * @param card a card that will be added
         */
        void add(Flashcard card);

        /**
         * @brief Renames the deck to the user's choice
         *
         * @param newName the name the user chooses to call a deck
         */
        void renameDeck(std::string newName);

        /**
         * @brief Gets the name of the current deck
         *
         * @return the name of the current deck
         */
        std::string getDeckName();

        /**
         * @brief Gets the card based on the index in the deck
         *
         * @param index the position of the card 
         * @return the Flashcard selected
         */
        Flashcard& getCard(int index);

        /**
         * @brief Gets the number of cards in a deck
         *
         * @return the number of cards in the deck
         */
        int getDeckSize();

        /**
         * @brief Deletes a card based on the index in the deck
         *
         * @param index the position of the card to be deleted
         */
        void deleteCard(int index);
};



#endif //Final_Deck_HPP
