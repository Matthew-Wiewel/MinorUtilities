#include <iostream>
#include <ctime>
using namespace std;

void get_num_above_zero(int& num, const char* prompt);

int main()
{
	int rolls;
	int sides = 1;
	int roll;
	int sum;
	srand(time(0));
	
	while(sides != 0)
	{
		cout << "\nEnter number of sides to roll 1 die.";
		cout << "\nEnter -1 to make custom with multiple rolls.";
		cout << "\nEnter 0 to quit.";
		cout << "\nInput: ";
		cin >> sides;
		
		if(sides > 0)
		{
			roll = (rand() % sides) + 1;
			cout << "\nRolling 1 d" << sides << ": " << roll;
		}
		else if(sides < 0)
		{
			get_num_above_zero(rolls, "\nEnter number of rolls: ");
			get_num_above_zero(sides, "\nEnter number of sides: ");
			sum = 0;
			
			cout << "\nRolling d" << sides << " for " << rolls << " rolls.\n";
			for(int i = 0; i < rolls; i++)
			{
				roll = (rand() % sides) + 1;
				sum += roll;
				cout << roll << " ";
			}
			cout << "\nSum: " << sum;
			
			if(rolls == 2 && sides == 20)
			{
				int a = roll;
				int b = sum - roll;
				cout << "\nAdvantage: " << ((a > b) ? a : b);
				cout << "\nDisadvantage: " << ((a < b) ? a : b);
			}
		}
		
		cout << "\n";
	}
	
	return 0;
}

void get_num_above_zero(int& num, const char* prompt)
{
	do
	{
		cout << prompt;
		cin >> num;
		
		if(num < 1)
			cout << "\nError! Enter a number above 0!";
		
	}while(num < 1);
}