/*
Assignment 2
Tony Gill
100282663
February 9, 2019

Algorithm was designed in the following series of steps:
1) Declare the key functions used throughout the game program globally outside the main function
2) Define main function with variables also defined
3) Prompt user to enter account present value
4) Take user input value entered for PV
5) Prompt user to enter interest rate
6) Take user input value entered for interest rate
7) Prompt user to enter account time in months
8) Take user input value entered for months
7) Output calculated future value for the account

Functions/Formulas

This program has two functions, the first of which is a future value function which calculates FV based on values
user entered in main function. The constructor is set up accordingly to record present value, interest rate and
number of months

The main function prompts user to enter values for the formula and then outputs the calculated results for account FV

Formula for converting decimal interger value to percentage = interestR = interestR / 100.0;

Formula for future value = presentV * pow(1 + interestR, timeMonths);


Revision History:
January 30, 2019: First working edition created
February 3, 2019: Final version revised and completed


*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Declares the function for the playing the game
void runGame();

// Declares the computer choice function
string getComputerChoice();

// Declares the user choice function
string getUserChoice();

// Declares the function for getting choices as a string represented by an integer
string getChoiceAsString(int);

// Declares function for displaying the choices made by user and computer 
void displayChoices(string, string);

// Declares function that determines the winner of the game based on choices
string winChoice(string, string);





int main()
{
	// Calls the runGame function
	runGame();


	return 0;
}

// Defines the the runGame function 
void runGame() {

	// runGame function body

	// Defines variable representing the choice made by computer
	string computerChoice;

	// Defines variable representing the choice made by user
	string userChoice;

	// Defines variable that defines the game winner
	string gameWin;


	// Retrieves/gets choice made by user 
	userChoice = getUserChoice();

	// Retrieves the choice made by computer 
	computerChoice = getComputerChoice();

	// displayChoices variable with parameters for user choice and computer choice 
	displayChoices(userChoice, computerChoice);

	// Sets gameWinner variable to findWinner where findWinner will overwrite gameWinner once found 
	gameWin = winChoice(userChoice, computerChoice);

	// Outputs the winner of the game
	cout << "Winning Choice: " << gameWin << endl;



}

// Defines the getUserChoice function 
string getUserChoice() {

	// getUserChoice function body

	// Defines variable for user 
	int user;

	// Defines variable for user choice
	string userChoice;


	// Prompts the user to enter a choice between 1 and 3, where 1 is Rock, 2 is Paper & 3 is Scissors
	cout << "User enter a choice between 1 and 3" << "\n1: Rock 2: Paper 3: Scissors" << endl;

	// Takes user input for number corresponding to choice entered by user
	cin >> user;

	// Specifys the valid range of choices that can be made by user between 1 and 3
	while (user != 1 && user != 2 && user != 3)
	{

		// Indicates to user that invalid choice outside specified range was made
		cout << "Invalid! Please choose between 1 and 3 only" << endl;

		cin >> user;
	}

	//Gets user choice as a string
	userChoice = getChoiceAsString(user);

	// Returns the choice made by user
	return userChoice;
}


// Defines the getComputerChoice function 
string getComputerChoice() {

	//getComputerChoice function body

	// Defines the variables for computer
	int comp;

	// Defines variable for computer choice
	string compChoice;


	unsigned seedTime = time(0);

	// Randomizes the computer choice 
	srand(seedTime);

	// Random choice made by computer from 3 available choices 
	comp = 1 + rand() % 3;

	// Gets the computer choice as string
	compChoice = getChoiceAsString(comp);

	// Returns the choice made by computer
	return compChoice;
}

// Defines the function for getting choice as a string 
string getChoiceAsString(int choice) {

	// getChoiceAsString function body

	// Conditional specifies that if 1 is chosen "Rock" is returned as string
	if (choice == 1)
		return "Rock";

	// Conditional specifies that if 2 is chosen "Paper" is returned as string
	else if (choice == 2)
		return "Paper";

	// If 3 was chosen "Scissor: is returned as string
	else
		return "Scissor";

}


// Defines the function for displaying choices  with parameters for the user and computer
void displayChoices(string user, string comp) {


	// Outputs the user choice 
	cout << "User has chosen: " << user << endl;

	// Outputs the computer choice
	cout << "Computer has chosen: " << comp << endl;

}

// Defines function for finding the winner of the game
string winChoice(string comp, string user) {

	// winChoice function body

	/* Conditional checks choices made by user and computer
	where computer has chosen rock and user chose scissor */
	if (comp == "Rock" && user == "Scissor") {

		// Rock beats scissors computer is the winner variable set to computer
		cout << "Computer Wins\t";

	}

	/* Conditional checks choices made by user and computer
	where computer has chosen rock and user chose paper */
	else if (comp == "Rock" && user == "Paper") {

		// Paper beats rock user is the winner variable set to user
		cout << "User Wins\t";

	}

	// Condition where computer has chosen paper and user chose rock
	else if (comp == "Paper" && user == "Rock") {

		// The computer is the winner variable set to computer
		cout << "Computer Wins\t";
	}

	//Condition where computer has chosen paper and user chosen scissor
	else if (comp == "Paper" && user == "Scissor") {

		// Winner variable set to user
		cout << "User Wins\t";
	}

	// Condition where computer has chosen scissor and user has chosen paper
	else if (comp == "Scissor" && user == "Paper") {

		// Winner variable set to computer
		cout << "Computer Wins\t";

	}
	// Condition where computer has chosen scissor and user chose rock
	else if (comp == " Scissor" && user == "Rock") {

		// Winner is user 
		cout << "User Wins\t";

	}
	// Condition where computer and user made same choice
	else

		// Output displays the game is a tie
		cout << "\nGame is a tie" << endl;


}