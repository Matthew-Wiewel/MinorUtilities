map: map.o battlemap.o
	g++ -g -o map map.o battlemap.o
map.o: map.cpp battlemap.h
	g++ -c map.cpp battlemap.h
battlemap.o: battlemap.h battlemap.cpp
	g++ -c battlemap.cpp battlemap.h
clean:
	erase map.o battlemap.o battlemap.h.gch