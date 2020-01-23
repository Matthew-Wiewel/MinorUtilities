#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	fstream file;
	file.open("merchantOfVenus.txt"); //file containing the cultures' names
	vector<string> cultures;
	srand(time(0));
	
	//read the file and create vector that only have the undiscovered cultures in it
	string val;
	while(getline(file, val))
	{
		if(val[0] != '/')
			cultures.push_back(val);
	}
	
	//randomize the order of the cultures
	for(int i = 0; i < cultures.size(); i++)
	{
		int swapWith = rand() % cultures.size();
		swap(cultures[i], cultures[swapWith]);
	}
	
	//with the randomized vector, we can go through the elements one by one to get the cultures
	char cont;
	for(int i = 0; i < cultures.size(); i++)
	{	
		cout << "\nEnter 'n' for the next system discovered.";
		cin >> cont;
	
		cout << "\nYou have found " << cultures[i] << endl;
		cout << "\nThere are " << cultures.size() - (i + 1) << " cultures left to discover.";
	}
	
	cout << "\nAll systems found.";
	
	return 0;
}