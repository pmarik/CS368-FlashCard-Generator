#include <iostream>

using namespace std;

const static string welcome_message = "---------- WELCOME TO FLASHCARD GENERATOR! ----------";
const static string username_prompt = "Enter your FlashCard Generator username or create a new one: ";
const static string yes_or_no = "(Y)es or (N)o: ";
const static string menu = "---------- FLASHCARD GENERATOR MENU ----------";
const static string review_option = "(R)eview Cards";
const static string edit_option = "(E)dit Decks";
const static string generate_option = "(G)enerate Cards";
const static string quit_option = "(Q)uit";
const static string invalid_option_message = "Invalid Option, please try again: ";
const static string exit_message = "Thanks for using FlashCard Generator!";


string GetUsername();
bool EqualIgnoreCase(string, string);

/**
*@brief controls the execution of the program
*
*
*/
int main() {
	
	//Display Welcome Message
	cout << welcome_message << endl;
	
	//Get the username for the user
	string username = GetUsername();
	cout << endl << "Hello, " << username << "!" << endl << endl;

	//Find the users previously generated cards, if any
	//User user = LoadUser(username);
	
	//Display the Main Menu Loop
	bool persist = true;
	while (persist) {
		
		//Display menu options
		cout << menu << endl << review_option << endl << edit_option << endl << generate_option 
			<< endl << quit_option << endl;
		
		cout << "Please enter an option from those listed above: ";
		
		bool validOption = false;
		while (!validOption) {
			//Get the user's choice
			string option;
			getline(cin, option);
		
			//Decipher user option, and switch to correct mode
			if (EqualIgnoreCase(option, "Review") || EqualIgnoreCase(option, "R")) {
				validOption = true;
				//Review();
			} else if (EqualIgnoreCase(option, "Edit") || EqualIgnoreCase(option, "E")) {
				validOption = true;
				//Edit();
			} else if (EqualIgnoreCase(option, "Generate") || EqualIgnoreCase(option, "G")) {
				validOption = true;
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
	
