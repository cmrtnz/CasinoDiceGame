/*
Module Name: Casino Game
Date Written: 9/13/2019
Author: Cedric Martinez
Purpose: Run a casino game where we roll two dice and determine if the user wins or loses, and manages their money
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

bool game(int& stake, int& rollCount);
int rollDie(int& rollCount);
void greeting();

int main()
{
	greeting();

	cout << "What is your stake amount? ";
	int stake, rollCount = 0;

	cin >> stake;

	//Checking to make sure stake is valid
	while (stake <= 0) {
		cout << "Invalid input, try again with a positive number: ";
		cin >> stake;
	}

	//Storing original stake for later messages
	int originalStake = stake;

	//Allows user to continue betting until they run out of money
	while (stake > 0) {
		int bet;
		cout << "Enter your bet (Enter 0 if you want to leave with your money): ";
		cin >> bet;

		//Allows user to leave with their winnings
		if (bet == 0) {
			break;
		}
		//Checking for a valid bet
		while (bet > stake || bet < 0) {
			cout << "Your bet is more than your stake or negative, please enter a valid bet: ";
			cin >> bet;
		}
		//Running game function to find if they win (true) or lose (false)
		bool win = game(stake, rollCount);
		if (win) {
			stake += bet;
			cout << "You won that bet! Your total stake amount is now: " << stake << "\n";
		}
		else {
			stake -= bet;
			cout << "Sorry, it looks like that one didn't go your way. Your total stake amount is now: " << stake << "\n";
		}
		//Continues until the user reaches 0 or taps out with their money
	}

	//Messages based on how much their stake changed from the beginning
	if (stake == 0) {
		cout << "\nIt looks like you have no money left. Sorry, game over.\n";
	}
	else if (originalStake > stake) {
		cout << "\nIt looks like you lost some money, but at least you didn't lose everything.\n";
	}
	else if (originalStake < stake) {
		cout << "\nNice! You made some money from the casino!\n";
	}
	else if (originalStake == stake) {
		cout << "\nIt looks like you broke even.\n";
	}


	cout << "Roll count: " << rollCount << "\n";
	cout << "Final stake amount: " << stake << "\n\n";


}


//Returning true indicates a winning bet while returning false indicates a loss
bool game(int& stake, int& rollCount) {

	cout << "Let's roll the dice!\n";
	_getch();

	int roll = rollDie(rollCount);
	int point;

	//This switch statement either gives the thrower the auto-loss for 2, 3, and 12, gives them a win for 7 and 11, or stores their roll as the "point"
	switch (roll) {
	case 2: return false;
		break;
	case 3: return false;
		break;
	case 4: point = 4;
		break;
	case 5: point = 5;
		break;
	case 6: point = 6;
		break;
	case 7: return true;
		break;
	case 8: point = 8;
		break;
	case 9: point = 9;
		break;
	case 10: point = 10;
		break;
	case 11: return true;
		break;
	case 12: return false;
		break;
	default: break;
	}

	//Rolling 7 is an automatic loss
	while (roll != 7) {

		cout << "Point: " << point << "\n" ;
		cout << "Let's roll the dice!\n\n";
		system("pause");
		roll = rollDie(rollCount);
	

		//Rolling the point will take you out of the while loop as well
		if (roll == point) {
			break;
		}
		
	}

	if (roll == point) {
		return true;
	}
	if (roll == 7) {
		return false;
	}

	return false;

}

int rollDie(int& rollCount) {
	int die1, die2, sum;

	//Randomizes die 1 and die 2 from 1 - 6
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
	cout << "\nDie 1 is " << die1 << ".\n";
	cout << "Die 2 is " << die2 << ".\n";

	sum = die1 + die2;
	cout << "The dice throw resulted in " << sum << "\n\n";
	//Keeping count of the number of rolls
	rollCount++;
	return sum;



}


//function explaining the rules of the game
void greeting() {
	cout << "Hello, welcome to the casino!\n";
	cout << "We will be throwing 2 dice randomly and if their sum equals 7 or 11, you win! If their sum is 2, 3, or 12, you lose.\n";
	cout << "Roll any other number, and we will continue rolling until you either roll a 7, which will result in a loss";
	cout << ", or the first number you rolled, called the \"point\" number, which will result in a win. Good luck!\n\n";

}

