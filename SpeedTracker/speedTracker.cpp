#include <iostream>
#include <fstream>
using namespace std;

//helper function for display of information at the beginning and end of the program
void scoreDisplay(int j, int m, int numGames)
{
	cout << "\nAt the end of this session the scores are: \n";
	cout << "\n\tThere have been " << numGames << " games.";
	cout << "\n\tJustin: " << j;
	cout << "\n\tMatthew: " << m;
}

//function to encapsulate logic of updating a player's score
void updateScore(int& playerScore, int& numGames)
{
	playerScore++;
	numGames++; //another point necessitates another game having been played
}

void negateScore(int& playerScore, int& numGames)
{
	playerScore--;
	numGames--;
}

int main()
{
	fstream file;
	int numGames;
	int matthewScore;
	int justinScore;
	
	//read in data of previous session
	file.open("data.txt");
	file >> numGames;
	file >> matthewScore;
	file >> justinScore;
	
	scoreDisplay("\nAt the start of this session the scores were: \n", justinScore, matthewScore, numGames);
	
	cout << "\nTo enter new scores, enter 'j' for a Justin win, 'm' for a Matthew win, or 'q' to stop.";
	cout << "\nTo remove a score, enter \"-j\" or \"-m\" to remove a win from Justin or Matthew respectively.";
	cout << "\nThis session: ";
	
	//variables for while loop
	bool doLoop = true;
	char who;
	
	//keep looping while there is input until the q
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
			case '-':
			{
				cin >> who;
				if(who == 'j' || who == 'J')
					negateScore(justinScore, numGames);
				else if(who == 'm' || who == 'M')
					negateScore(matthewScore, numGames);
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
	
	scoreDisplay(justinScore, matthewScore, numGames);
	
	file.close(); //closing prior to writing is necessary in order to clear the file for the new data
	file.open("data.txt"); //hence the purpose of this close and open
	
	//write the data to the file
	file << numGames << "\n" << matthewScore << "\n" << justinScore;	
	file.close();
	
	return 0;
}
	
	
