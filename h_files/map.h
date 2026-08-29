#ifndef MAP_H
#define MAP_H

#include <vector>
#include <raylib.h>

class map {
	private:
		std::vector<Rectangle> walls;
		std::vector<int> input;
	public:
		void loadMap(char filename[24]);
		void makeWalls();
		std::vector<Rectangle> getWalls();
};

#endif
