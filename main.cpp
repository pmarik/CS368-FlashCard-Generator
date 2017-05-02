#include <iostream>

using namespace std;

const static string welcome_message = "---------- WELCOME TO FLASHCARD GENERATOR! ----------";
const static string username_prompt = "Enter your FlashCard Generator username or create a new one: ";
const static string yes_or_no = "(Y)es or (N)o: ";
const static string menu = "---------- FLASHCARD GENERATOR MENU ----------";
const static string review_option = "(R)eview";
const static string edit_option = "(E)dit";
const static string generate_option = "(G)enerate Cards";
const static string quit_option = "(Q)uit";
const static string invalid_option_message = "Valid options are: R, E, G, Q";


string GetUsername();

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

	//Find the users previously generated cards, if any
	//User user = LoadUser(username);
	
	//Display the Main Menu Loop
	bool persist = true;
	while (persist) {
		
		//Display menu options
		cout << menu << endl << review_option << endl << edit_option << endl << generate_option 
			<< endl << quit_option << endl;
			
		//Get the user's choice
		string option;
		cout << "Please enter an option from those listed above: ";
		getline(cin, option);
		
		//Decipher user option, and switch to correct mode
		if (option.find("R") == 0 || option.find("r") == 0) {
			//Review();
		} else if (option.find("E") == 0 || option.find("e") == 0) {
			//Edit();
		} else if (option.find("G") == 0 || option.find("g") == 0) {
			//Generate();
		} else if (option.find("Q") == 0 || option.find("q") == 0) {
			persist = false;
			cout << exit_message << endl;
		} else {
			cout << invalid_option_message;
			
		}
		
	}
	
	return 0;


	}
	
	string GetUsername() {
		
		//Initialize choice to enter while loop
		string username;
		string choice = "n";
		
		//User can repeatedly select username 
		while (choice.find("n") == 0 || choice.find("N") == 0) {
			cout << username_prompt;
			getline(cin, username);
			cout << "Your username is " << username << ", correct? " << yes_or_no;
			getline(cin, choice);
		}
		
		return username;
	}
	
	/**User LoadUser(string username) {
		
		
	}*/
	
