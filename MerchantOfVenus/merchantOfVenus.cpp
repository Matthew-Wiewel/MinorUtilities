#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	fstream file;
	file.open("merchantOfVenus.txt");
	int numReadIn = 14;
	char cont;
	vector<string> systems;
	srand(time(0));
	
	string val;
	while(file >> val)
	{
		if(val[0] != '/')
			systems.push_back(val);
	}
	
	for(int i = 0; i < systems.size(); i++)
	{
		int swapWith = rand() % systems.size();
		swap(systems[i], systems[swapWith]);
	}
	
	cout << "\nThere are " << systems.size() << " cultures left to discover.";
	cout << "\nEnter 'n' for the next system discovered.";
	
	for(int i = 0; i < systems.size(); i++)
	{
		cin >> cont;
		cout << "\nYou have found " << systems[i] << endl;
		
		cout << "\nThere are " << systems.size() - (i + 1) << " cultures left to discover.";
		cout << "\nEnter 'n' for the next system discovered.";
	}
	
	cout << "\nAll systems found.";
	
	return 0;
}

		