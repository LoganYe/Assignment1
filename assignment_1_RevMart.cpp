//sum = RolltheDice(); sum is the value of two dices
//#include <csdlib>
#include <iostream>
#include <ctime>

using namespace std;

int RolltheDice()
{
	int a,b;
	
	a = rand() % 6 + 1;
	b = rand() % 6 + 1;
	
	cout << "dice number:" << a+b << endl;
	
	return a + b;
}

int DoTheGame()
{
	int sum,temp;
	
	sum = RolltheDice();
	if ((sum == 7)||(sum == 11)) 
		return 1;
	else if ((sum == 2)||(sum == 3)||(sum == 12))
		return 0;

	temp = sum;

	while(1)
	{
		sum = RolltheDice();
		if (sum == temp) 
			return 1;
		else if (sum == 7)
			return 0;
	}
}

/******* pass line *******/

int main()
{
	int balance = 1000;
	int start = 100;
	int wager = 100;
	int count = 10;
	int WinOrLose;
	int temp;
	
	srand((unsigned)time(NULL));
	
	while ((balance != 0) && (count != 0))
	{
		if (balance <= wager)
		{
			wager = balance;
		}
		
		WinOrLose = DoTheGame();   //do the game
		count--;
		
		if (WinOrLose == 1)
		{
			balance = balance + wager;
			wager = wager * 2;
		}
		else if (WinOrLose == 0)
		{
			balance = balance - wager;
			wager = start;
		}
		cout << "balance:" << balance << "\twager:" << wager << endl;
	}
	
	printf("Game Over!\n");
	if (balance == 0)
		printf("You have no money left!\n");
	if (count == 0)
		printf("Your balance left %d after 10 games.",balance);
	
	cin >> temp;
	return 1;
}

