#ifndef MAP_H
#define MAP_H

#include <vector>
#include <raylib.h>

class map {
	public:
		struct mapData {
			std::vector<Rectangle> walls;
			int sizeX;
			int sizeY;
		};
	private:
		mapData map;
		std::vector<int> input;
	public:
		void getMapSize(int* sizeXptr, int* sizeYptr);
		void loadMap(char filename[24]);
		void makeWalls();
		std::vector<Rectangle> getWalls();
};

#endif
