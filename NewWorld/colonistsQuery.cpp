#include <iostream>
#include <ctime>

/*
	in the board game New World
	you can either take 4 colonists each turn
	or roll a d6 for your number of colonists
	with a floor of 3
	This program was a way to run tests on which was better
	without doing the math
*/

int main()
{
	int num_rolls = 10000;
	int num_trials = 1000;
	int num_times_better = 0;
	int num_times_worse = 0;
	int num_times_equal = 0;
	srand(time((0)));
	
	for(int i = 0; i < num_trials; i++)
	{
		int num_colonists = 0;
		for(int j = 0; j < num_rolls; j++)
		{
			int roll = (rand() % 6) + 1;
			num_colonists = (roll > 3) ? num_colonists + roll : num_colonists + 3;
		}
		
		if(num_colonists > num_rolls * 4)
			num_times_better++;
		else if(num_colonists < num_rolls * 4)
			num_times_worse++;
		else
			num_times_equal++;
	}
	
	std::cout << "Number of times better: " << num_times_better
		 << "\nNumber of times worse: " << num_times_worse
		 << "\nNumber of times equal: " << num_times_equal;
	
	return 0;
}