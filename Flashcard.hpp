////////////////////////////////////////////////////////////////////////////////
// File Name:      Flashcard.cpp
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


#include "Flashcard.hpp"



    Flashcard::Flashcard(std::string line){
            this->line = line; 

            int wordEnd = line.find(" - ");
            int defStart = wordEnd + 3;
            std::string def = line.substr(defStart);
            std::string word = line.substr(0, wordEnd);
            
            this->word = word;
            this->definition = def;
           
        }


    std::string Flashcard::getWord(){
      
        return word;
    }

    std::string Flashcard::getDefinition(){
        return definition;
    }

    void Flashcard::editDefintion(std::string def){
       definition = def;
       
    }

    void Flashcard::editWord(std::string newWord){
        word = newWord;
    }

           
        




