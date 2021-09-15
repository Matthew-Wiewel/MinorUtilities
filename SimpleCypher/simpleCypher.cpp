#include <iostream>
#include <string>
using namespace std;

string letterToNumber(char c);

int main()
{
	string input;
	string output = "";
	
	cout << "Enter the message to encrypt: ";
	getline(cin, input);
	
	for(char c : input)
	{
		output = output + (letterToNumber(c) + " ");
	}
	
	cout << output;
	
	return 0;
}


//TODO: switch this from cumbersome switch case and use atoi
string letterToNumber(char c)
{
	
	//it's a letter: let's encode it
	if(isalpha(c))
	{
		int asciiValue = int(c);
		
		if(asciiValue > 90)
			return to_string(asciiValue - 96); //lower-case letter
		else
			return to_string(asciiValue - 64); //upper-case letter
	}
	
	//not a letter: leave unchanged
	string leaveNonLetterUnchanged{c};
	return leaveNonLetterUnchanged;
}