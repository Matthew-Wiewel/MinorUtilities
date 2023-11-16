#ifndef WIEWEL_BATTLEMAP_H
#define WIEWEL_BATTLEMAP_H

#include <string>
#include <iostream>

const char IMPASSABLE = 'x';
const char ROUGH = 'r';
const char OPEN = '-';

class battlemap
{
private: 
	struct square
	{
		char type;
		bool is_occupied;
		std::string occupant;
		
		bool is_impassable() { return type == IMPASSABLE; }
	};
	
	int width;
	int height;
	square** arr; //TODO: figure out what the array holds, maybe use vector instead\
	
	~battlemap()
	{
		for(int i = 0; i < height; i++)
			delete[] arr[i];
		delete[] arr;
	}
	
public:
	void placeholder();

};

#endif