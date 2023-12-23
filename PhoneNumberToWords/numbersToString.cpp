#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	long phoneNumber = 0L;
	vector<vector<char>> charactersOfDigit = {
		{'-'},
		{'a','b','c'},
		{'d','e','f'},
		{'g','h','i'},
		{'j','k','l'},
		{'m','n','o'},
		{'p','q','r','s'},
		{'t','u','v'},
		{'w','x','y','z'},
		{'-'}
	};
	vector<string> wordOptions;
	vector<long> digits;
	
	digits = getDigits(phoneNumber);
	
	
	cout << "\nEnter the phone number as one contiguous number (ex: 12225558989 and NOT 1-222-555-8989): ";
	cin >> phoneNumber;
	
	
	
	
	cout << "\n\nHere are the possible words.\n\n";
}

void getWords(long number, const vector<vector<char>>& charactersOfDigit, string wordSoFar, vector<string>& wordOptions) 
{
	
	if(number < 10L) //we are at the last digit, let's make strings 
	{
		for(char c : charactersOfDigit[number])
			wordOptions.push_back(wordSoFar + c);
	}
	else
	{
		for(char
	}
	for(char c : charactersOfDigit[number])
	{
		if(number > 9L) //not at end, keep making permutations
			getWords(number % 10L /*next digit*/
}
	