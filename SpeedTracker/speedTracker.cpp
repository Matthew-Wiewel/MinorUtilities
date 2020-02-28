#include <iostream>
#include <fstream>
using namespace std;

void scoreDisplay(const char* message, int j, int m, int numGames)
{
	cout << message;
	cout << "\n\tThere have been " << numGames << " games.";
	cout << "\n\tJustin: " << j;
	cout << "\n\tMatthew: " << m;
}

void updateScore(int &playerScore, int& numGames)
{
	playerScore++;
	numGames++;
}

int main()
{
	fstream f;
	int numGames;
	int matthewScore;
	int justinScore;
	f.open("data.txt");
	
	f >> numGames;
	f >> matthewScore;
	f >> justinScore;
	
	scoreDisplay("\nAt the start of this session the scores were: \n", justinScore, matthewScore, numGames);
	
	cout << "\nTo enter new scores, enter 'j' for a Justin win, 'm' for a Matthew win, or 'q' to stop.";
	cout << "\nThis session: ";
	
	bool doLoop = true;
	char who;
	
	while(doLoop)
	{
		cin >> who;
		
		switch(who)
		{
			case 'j':
			case 'J':
			{
				updateScore(justinScore, numGames);
				break;
			}
			case 'm':
			case 'M':
			{
				updateScore(matthewScore, numGames);
				break;
			}
			case 'q':
			case 'Q':
			{
				doLoop = false;
				break;
			}
		}
	}
	
	scoreDisplay("\nAt the end of this session the scores are: \n", justinScore, matthewScore, numGames);
	
	return 0;
}
	
	