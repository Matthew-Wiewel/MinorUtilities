#ifndef WIEWEL_BATTLEMAP_H
#define WIEWEL_BATTLEMAP_H

#include <string>
#include <iostream>

class battlemap
{
private: 
	struct square
	{
		char type;
		bool occupied;
		std::string occupant;
		
		bool is_occupied() { return occupied; }
		bool is_impassable() { return type == 'x'; }
	};
	
	int width;
	int height;
	square** arr; //TODO: figure out what the array holds, maybe use vector instead\
	
public:
	void placeholder();

};

#endif