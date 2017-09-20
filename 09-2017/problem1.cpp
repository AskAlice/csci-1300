// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang
//
// Assignment 3
// Problem 1

#include <iostream>
using namespace std;

/*
* createInput takes a string, prompt as a paramter
* It then uses the parameter to create output a message that explains what the user is then going to input.
* It then uses cin to take an input, and then returns that input, a string, to finish the function.
*/
string createInput(string prompt){
	cout << prompt; //output the prompt
	string i; //define the input
	cin >> i; //take the input
	return i; //return the input
}
/*
* story1 - the third story.
* This function uses the createInput method to easily take inputs.
* It asks for a plural noun, an occupation, an animal name, and a place
* then it outputs a sentence using these variables
* then exit, leading back to the main menu. 
*/
void story1(void){
	string pluralNoun =  createInput("Enter a plural noun: ");
	string occupation =  createInput("Enter an occupation: ");
	string animalName = createInput("Enter an animal name: ");
	string place      =        createInput("Enter a place: ");
	cout << endl << "In the book War of the " << pluralNoun << ", the main character is an anonymous " << occupation << " who records the arrival of the " << animalName <<"s in " << place << "." << endl << endl;
	return;
}

/*
* story2 - the second story.
* This function uses the createInput method to easily take inputs.
* It asks for a plural name, and a state/country.
* then it outputs a sentence using these variables
*/
void story2(void){
	string name = createInput("Enter a name: ");
	string state = createInput("Enter a state/country: ");
	cout << endl << name << ", I've got a feeling we're not in " << state << " anymore." << endl << endl;
	return;
}

/*
* story3 - the third story
* This function uses the createInput method to easily take inputs.
* The inputs taken are a first name, a relative, and a verb.
* Once all the inputs are taken, it will echo out a string using these inputs.
*/
void story3(void){
	string firstName = createInput("Enter a first name: ");
	string relative = createInput("Enter a relative: ");
	string verb = createInput("Enter a verb: ");
	cout << endl << "Hello. my name is " << firstName << ". You killed my " << relative << ". Prepare to " << verb << "." << endl << endl;
	return;
}
/*
* This function is called initally by main, then again in a recursive-like manner as needed.
* It is the main menu of the game. 
* This function takes an input 1,2,3, or q. 
* If q is chosen, it says goodbye and the program exits.
* If 1, 2, or 3 is chosen, then it will call the corresponding story function, and then return to the menu when that function completes.
* If anything else is chosen, it will say that the choice is invalid and returns to the main menu. 
*/
void menu(void){
		cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: " << endl;
		string choice;
		cin >> choice;
		if(choice == "1"){
			story1();
			menu(); //once that story is over, it returns to the main menu.
		}
		else if(choice == "2"){
			story2();
			menu(); //once that story is over, it returns to the main menu.
		}
		else if(choice == "3"){
			story3();
			menu(); //once that story is over, it returns to the main menu.
		}
		else if(choice != "q"){
			cout << "Valid choice not selected." << endl;
			menu(); //once that story is over, it returns to the main menu.
		}
	cout << "good bye"; //this point is only reached when q is chosen.
}

/*
* This function calls the menu, which starts the game. 
* Returns 0 as to indicate no errors with the main function.
*/
int main(void){
	menu();
	return 0;
}