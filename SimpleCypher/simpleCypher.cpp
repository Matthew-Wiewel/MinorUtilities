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
	switch(c)
	{
		case 'a':
			return "1";
		case 'b':
			return "2";
		case 'c':
			return "3";
		case 'd':
			return "4";
		case 'e':
			return "5";
		case 'f':
			return "6";
		case 'g':
			return "7";
		case 'h':
			return "8";
		case 'i':
			return "9";
		case 'j':
			return "10";
		case 'k':
			return "11";
		case 'l':
			return "12";
		case 'm':
			return "13";
		case 'n':
			return "14";
		case 'o':
			return "15";
		case 'p':
			return "16";
		case 'q':
			return "17";
		case 'r':
			return "18";
		case 's':
			return "19";
		case 't':
			return "20";
		case 'u':
			return "21";
		case 'v':
			return "22";
		case 'w':
			return "23";
		case 'x':
			return "24";
		case 'y':
			return "25";
		case 'z':
			return "26";
		default:
			return " ";
	}
}