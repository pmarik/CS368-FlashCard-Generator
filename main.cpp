////////////////////////////////////////////////////////////////////////////////
// File Name:      main.cpp
//
// Author:         Paul Marik, David Wissink 
// CS email:       marik@cs.wisc.edu, wissink@cs.wisc.edu
//
// Description:    main class to run the flashcard study tool.
//
// Sources:        cppreference.com, <sources, if any>
//
// URL(s) of sources:
//                 http://en.cppreference.com/w/cpp/container/vector
//                 <URLs of your sources, if any>
////////////////////////////////////////////////////////////////////////////////


#include "Flashcard.hpp"
#include "Deck.hpp"
#include "Config.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


string GetUsername();
bool EqualIgnoreCase(string, string);
vector<string> GetStringsFromFile(string);
void review(Deck studyDeck);
Deck& deckListOption();
Deck edit(Deck& editDeck);

static vector<Deck> allDecks;

/**
 *@brief controls the execution of the program
 *
 *
 */
int main() {

	
	//Display Welcome Message
	cout << endl << welcome_message << endl;
	
	//Get the username for the user
	string username = GetUsername();
	cout << endl << "Hello, " << username << "!" << endl;

	//Find the users previously generated cards, if any

	
	//Display the Main Menu Loop
	bool persist = true;
	while (persist) {
		
		//Display menu options
		cout << endl << menu << endl << review_option << endl << edit_option << endl << generate_option 
			<< endl << quit_option << endl;
		
		cout << above_choice;
		
		bool validOption = false;
		while (!validOption) {
			//Get the user's choice
			string option;
			getline(cin, option);
		
			//Decipher user option, and switch to correct mode
			if (EqualIgnoreCase(option, "Review") || EqualIgnoreCase(option, "R")) {
				validOption = true;
				
				validOption = true;
				
				if (allDecks.empty()){
					cout << no_decks_message << endl;
				}

				else{

					review(deckListOption());

					
				}


			} else if (EqualIgnoreCase(option, "Edit") || EqualIgnoreCase(option, "E")) {
				validOption = true;

				if (allDecks.empty()) {
					cout << no_decks_message << endl;
				}
				
				
		

				edit(deckListOption());
				
			} else if (EqualIgnoreCase(option, "Generate") || EqualIgnoreCase(option, "G")) {
				validOption = true;
				
				bool validFile;
				cout << "Enter the file you'd like to create flashcards from: ";
				
				//Get the file from the user to generate cards/deck
            	string fileName;
            	getline(cin, fileName);

				//Hold all of the lines from the user's' file
				vector<string> allStrings = GetStringsFromFile(fileName);
				
				//Create a new deck with the user's file data
				Deck usersDeck(fileName);

				//Create cards from each line of file and add them to the deck
				for(int i = 0; i < allStrings.size(); ++i){
					Flashcard card(allStrings[i]); 
					usersDeck.add(card);
				}
				
				//Notify the user the deck has been created with their cards
				cout << "*Generating deck*" << endl;

				allDecks.push_back(usersDeck);
				cout << "Cards added to your new deck: \"" << usersDeck.getDeckName() << "\" and was added to your list of decks" << endl;
				
				

				//Generate();
			} else if (EqualIgnoreCase(option, "Quit")|| EqualIgnoreCase(option, "Q")) {
				validOption = true;
				persist = false;
				cout << endl << exit_message << endl;
			} else {
				cout << invalid_option_message;
			
			}
		}
		
	}
	
	return 0;


	}

	/**
 	 * @brief Gets the username of a user
 	 *
  	 * @param N/A
 	 */
	string GetUsername() {
		
		//Initialize choice to enter while loop
		string username;
		bool validUsername = false;
		
		//User can repeatedly select username 
		while (!validUsername) {
			cout << username_prompt;
			getline(cin, username);
			cout << "Your username is " << username << ", correct? " << yes_or_no;
			
			//Variables regarding users choice 
			string choice;
			bool validChoice = false;
			
			//Ask user if the entered username is the one they want
			while (!validChoice) {
				getline(cin, choice);
				if (EqualIgnoreCase(choice, "YES") || EqualIgnoreCase(choice, "Y")) {
					validUsername = true;
					validChoice = true;
				} else if (EqualIgnoreCase(choice, "NO") || EqualIgnoreCase(choice, "N")) {
					validChoice = true;
				} else {
					cout << "Invalid option, please enter " << yes_or_no;
				}
			}
		}
		
		return username;
	}
	


	/**User LoadUser(string username) {
		
		
	}*/




	
	/**
	 *@brief compares to strings, ignoring differences in upper/lowercase letters
	 *@return returns true if the strings are the same, false otherwise
	 */
	bool EqualIgnoreCase(string s1, string s2) {
		//Convert each string to uppercase
		for(int i = 0; i < s1.size(); i++) {
			s1[i] = toupper(s1[i]);
		}
		for(int i = 0; i < s2.size(); i++) {
			s2[i] = toupper(s2[i]);
		}
		
		if(s1.compare(s2) == 0) {
			return true;
		} else {
			return false;
		}
	}


	/**
 	 * @brief Adds a line of text from file to a vector
 	 *
 	 * @param fileName the name of the user's file to get strings from'
 	 */
	vector<string> GetStringsFromFile(string fileName){
		fileName += ".txt";
		ifstream infile(fileName);
			
		vector<string> temp;

		string line;
		while(getline(infile, line)){
			temp.push_back(line);
		}

		infile.close();

		return temp;
	}
	

	/**
 	 * @brief Allows the user to review a chosen deck
 	 *
 	 * @param Deck studydeck - a Deck to retrieve cards and study from
 	 */
	void review(Deck studyDeck){
		
			cout << "Type in the correct word for each definition!" << endl;
			
			bool studyAgain = true;

			while(studyAgain){
				string userInput;
				
				for (int i = 0; i < studyDeck.getDeckSize(); ++i){

				cout << endl << (studyDeck.getCard(i)).getDefinition() << " --> ";
				
				getline(cin, userInput);

				if (EqualIgnoreCase(userInput, studyDeck.getCard(i).getWord())){
					cout << "Correct! Good Job!" << endl;
					}

				else{
					cout << "Incorrect! The right answer was: " << 
					studyDeck.getCard(i).getWord() << endl;
					}
				}	

				cout << "Do you want to study this deck again?" << yes_or_no;
				bool validOption = false;
				
				while (!validOption) {
					getline(cin, userInput);
					
					if (EqualIgnoreCase(userInput, "y") || EqualIgnoreCase(userInput, "yes")) {
						validOption = true;
					}
					else if (EqualIgnoreCase(userInput, "n") || EqualIgnoreCase(userInput, "no") ){
						validOption = true;
						studyAgain = false;
					} else {
						cout << invalid_option_message;
					}
				}
			}

	}
	Deck& deckListOption(){
				cout << deck_list_message << endl;

				for (int i = 0; i < allDecks.size(); ++i){
					cout << (allDecks[i]).getDeckName() << endl;
				}

				cout << "Enter the name of the deck from the list above: ";
				string chosenDeck;
				getline(cin, chosenDeck);

				int index = 0;
				for (int k = 0; k < allDecks.size(); ++k){
				string temp = (allDecks[k]).getDeckName();
				if (temp == chosenDeck){
					index = k;
					break;
					}
				}

					return allDecks[index];
	}
	Deck edit(Deck& editDeck){

		

				cout << "Would you like to: " << endl << "(A)dd a card" << endl << "(D)elete a card" << endl << "(C)hange a word"
					<< endl << "(M)odify a definition" << endl;

				cout << "Please enter an option from above: ";
				string userInput;
				getline(cin, userInput);

				if (userInput == "A"){
					cout << "Enter the word you would like to add: ";
					getline(cin, userInput);

					Flashcard newCard;
					newCard.setWord(userInput);

					cout << "Enter the Definition for this word: ";
					getline(cin, userInput);
					newCard.setDefintion(userInput);

					editDeck.add(newCard);

					cout << endl << "Your new card has been added to the deck!" << endl;

				}
				else if (userInput == "D"){

				}
				else if (userInput == "C"){

				}
				else if (userInput == "M"){

				}
	
				return editDeck;
	}
	
