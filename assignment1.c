//sum = RolltheDice(); sum is the value of two dices
//#include <csdlib>
#include <iostream>
#include <ctime>

int RolltheDice()
{
	srand((unsigned)time(0));
	a = rand() % 6;
	b = rand() % 6;
	return a + b;
}
int DoTheGame()
{
	if ((sum == 7)||(sum == 11)) 
	return 1;
	else if ((sum == 2)||(sum == 3)||(sum == 12))
		return 0;

	temp = sum;

	do
	{
		sum = RolltheDice;
		if (sum == temp) 
			return 1;
			else if (sum == 7)
				return 0;
	}
	while ((sum == temp)||(sum == 7));
	break;
}

/******* pass line *******/

void main()
{
	int balance = 1000;
	int start = 100;
	int wager;
	int count = 10;
	int WinOrLose;

	do
	{
		if (balance <= wager)
		{
			wager = balance;
		} else {
			WinOrLose = DoTheGame;   //do the game
			if (WinOrLose == 1)
				balance = balance + wager;
				wager = start;
			else if (WinOrLose == 0)
				balance = balance - wager;
				wager = wager * 2;
		}
	}
	while ((balance == 0)||(count == 0));
	printf("Game Over!\n");
	if (balance == 0)
		printf("You have no money left!\n");
	if (count == 0)
		printf("Your balance left ", balance, " after 10 games.");
}
