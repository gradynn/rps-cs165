#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* 
GLOBAL VARIABLES - These are unchanging values that will be referenced throughout the program in order to 
compare choices' int values. The program is much more readable if we are able to reference 'Rock' as 
ROCK instead of 1.
*/
const int ROCK		= 1;
const int PAPER		= 2;
const int SCISSORS	= 3;
const int QUIT      = 4;

/*
	These fucntion protoypes tell the interepreter that these function definitions exist later in the program.
	Without them each function would have to be placed above all other functions that reference it. Given the relative
	complexity of the main function, it is not ideal to burry it at the bottom of the file.
*/
int getUserChoice();
int getComputerChoice();
void determineOutcome(int, int);
void displayChoice(int);

int main()
{
	int userChoice;		
	int computerChoice;	

	computerChoice = getComputerChoice();

	userChoice = getUserChoice();

	/*
		This while loop handles the quit function. Because if will likeley repeat multiple time before the user selects quit,
		most of the program logic of the main function is contained inside of this loop.
	*/
	while (userChoice != QUIT)
	{
		
		cout << "\nYou selected: ";
		displayChoice(userChoice);
		cout << "The computer selected: ";
		displayChoice(computerChoice);
		
		determineOutcome(userChoice, computerChoice);
		cout<<endl;

		computerChoice = getComputerChoice();

		userChoice = getUserChoice();
	}

	//system("PAUSE"); Doesn't with MAC command line.
	return 0;
}

/*
	This function if responsible for generating a random integer between one and three. This int is then returned and serves as
	the computers selection. The function srand uses the system time at the instant it is called to seed the random number generating
	function rand. This provides a sudo-random integer that varies with each function call.
*/
int getComputerChoice()
{
	srand(time(NULL));
	int i = ((rand() % 3) + 1);

	return i;
}

/*
	This function collects the user's inputted choice. It begins by prompting the user with the menu and then assigns a user inputted number to a variable j
	which is eventually, after validation, returns to the main function.
*/
int getUserChoice()
{
	int j;
    
	cout << "Game Menu: " << endl;
	cout << "----------" << endl;
	cout << "1) Rock" << endl;
	cout << "2) Paper" << endl;
	cout << "3) Scissors" << endl;
	cout << "4) Quit" << endl << endl;
	
	cout << "Enter your choice: ";
	cin >> j;

	/*
		This while loop serves as an input validator. It checks to see wether the users input is less than 0 or greater than 4.
		If that condition evaluates to true, the program enters the loop and prompts the user to re-enter a valid choice with an
		error message.
	*/
	while (j > 4 || j < 1) {
		cout << "Invalid selection. Enter 1, 2, 3, or 4: ";
		cin >> j;
	}
	
	return j;
}

/*
	This function, as the name suggests, determines the outcome of the random selections. It takes in two ints: the users choice and the computer's choice
	and evaluates wether the user won, the computer won, or they tied.
*/
void determineOutcome(int user, int computer)
{
	/*
		This if statement handles the user-win cases. The logic follows that of rock paper scissors. If none of the branches of this if statement are entered
		the result could not possible be a user win, so the program moves on the the next if statement.
	*/
	if (user == ROCK && computer == SCISSORS) {
		cout << "YOU win! Rock smashes scissors." << endl;
	} else if (user == SCISSORS && computer == PAPER){
		cout << "YOU win! Scissors cut paper." << endl;
	} else if (user == PAPER && computer == ROCK) {
		cout << "YOU win! Paper covers rock." << endl;
	}

	/*
		This if statement handles the computer-win cases. If none of these branches executes then there could not possibly be a computer win or a user win
		and so the program will move on to the next if statement.
	*/
	if (computer == ROCK && user == SCISSORS) {
		cout << "COMPUTER wins. Rock smashes scissors." << endl;
	} else if (computer == SCISSORS && user == PAPER) {
		cout << "COMPUTER winds. Scissors cut paper." << endl;
	} else if (computer == PAPER && user == ROCK) {
		cout << "COMPUTER wins. Paper covers rock." << endl;
	}

	/*
		This final if statement evaluates the only remaining possibility: a tie. If any of these branches executes then the program will output "Draw".
	*/
	if (computer == ROCK && user == ROCK) {
		cout << "DRAW." << endl;
	} else if (computer == PAPER && user == PAPER) {
		cout << "DRAW." << endl;
	} else if (computer == SCISSORS && user == SCISSORS) {
		cout << "DRAW." << endl;
	}
}

/*
	This function displays the choice it is passed as a word. It essentially translates the integer value of a choice to an English word and prints it.
*/
void displayChoice(int choice)
{
	if (choice == ROCK) {
		cout << "Rock \n";
	} else if (choice == PAPER) {
		cout << "Paper \n";
	} else if (choice == SCISSORS) {
		cout << "Scissors \n";
	}
}
