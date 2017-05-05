////////////////////////////////////////////////////////////////////////////////
// File Name:      Config.cpp
//
// Author:         Paul Marik, David Wissink 
// CS email:       marik@cs.wisc.edu, wissink@cs.wisc.edu
//
// Description:    Provides configuration for the flashcard generator
//
// Sources:        cppreference.com, <sources, if any>
//
// URL(s) of sources:
//                 http://en.cppreference.com/w/cpp/container/vector
//                 <URLs of your sources, if any>
////////////////////////////////////////////////////////////////////////////////

#include <string>

using namespace std;

        /** Configuration presets for the main menu 
        *
        **/
        const static string welcome_message = "---------- WELCOME TO FLASHCARD GENERATOR! ----------";
        const static string username_prompt = "Enter your FlashCard Generator username or create a new one: ";
        const static string yes_or_no = "(Y/N): ";
        const static string menu = "---------- FLASHCARD GENERATOR MENU ----------";
        const static string review_option = "(R)eview Cards";
        const static string edit_option = "(E)dit Decks";
        const static string generate_option = "(G)enerate Cards";
        const static string quit_option = "(Q)uit";
        const static string invalid_option_message = "Invalid Option, please try again: ";
        const static string exit_message = "*** Thanks for using FlashCard Generator! ***";
        const static string above_choice = "Please enter an option from those listed above: ";
        const static string no_decks_message = "No decks found! Please add decks to begin a study session!";
        const static string deck_list_message = "Please choose a deck from your current deck list: **";
