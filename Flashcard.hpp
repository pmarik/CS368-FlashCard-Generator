////////////////////////////////////////////////////////////////////////////////
// File Name:      Flashcard.hpp
//
// Author:         Paul Marik, David Wissink 
// CS email:       marik@cs.wisc.edu, wissink@cs.wisc.edu
//
// Description:    Represenation of the flashcards to be used in the flashcards
//                 generator.
//
// Sources:        cppreference.com, <sources, if any>
//
// URL(s) of sources:
//                 http://en.cppreference.com/w/cpp/container/vector
//                 <URLs of your sources, if any>
////////////////////////////////////////////////////////////////////////////////


#ifndef Final_Flashcard_HPP
#define Final_Flashcard_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Flashcard{
    
    private:

     std::string line;
     std::string word;
     std::string definition;

    public:
     /**
      * @brief Constructor for flashcards.
      *
      * @param string the filename of the user's document to generate cards from.
      */
     Flashcard(std::string line);

    /**
         * @brief Gets the word part of the flashcard
         *
         * @return the string word of the flashcard
         */
     std::string getWord();

    /**
         * @brief Gets the definition part of the flashcard
         *
         * @return the string defintion of the flashcard
         */
     std::string getDefinition();

    /**
         * @brief Changes the current defintion to a new definition
         *
         * @param def the new defintion 
         */
     void editDefintion(std::string def);

    /**
         * @brief Changes the current word to a new word
         *
         * @param newWord the new word 
         */
     void editWord(std::string newWord);




};

#endif //Final_Flashcard_HPP
        




