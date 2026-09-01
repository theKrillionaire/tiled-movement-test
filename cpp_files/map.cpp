#include <raylib.h>
#include <stdio.h>
#include "map.h"
#include <vector>
#include <fstream>
#include <string>



void map::loadMap(char name[24]) {
	std::string filename = std::string("maps/") + name;
	std::ifstream mapFile(filename);
	char character;
	bool ab = false;
	char sizeBufferX[5];
	char sizeBufferY[5];
	int i = 0;
	int s = 0;
	int sizeI = 0;
	while(!ab) {
		mapFile.get(character);
		if (character != ',') {
			if(s == 0) {
				sizeBufferX[sizeI+1] = '\0';
				sizeBufferX[sizeI] = character;
			} else if(s == 1) {
				sizeBufferY[sizeI+1] = '\0';
				sizeBufferY[sizeI] = character;
			}
			i++;
			sizeI++;
		} else {
			if(s < 1) {
				s++;
				sizeI = 0;
			} else {
				ab = true;
			}
		}
	}
	map.sizeX = std::atoi(sizeBufferX);
	map.sizeY = std::atoi(sizeBufferY);
	for(; mapFile.get(character); i++) {
		if(character != '\n') {
 			input.push_back(character - '0');
		}
	}
	mapFile.close();
}

void map::makeWalls() {
	for(int i = 0; i < input.size(); i++) {
		int x = i % 20;
		int y = i / 20;
		if(input[i]) map.walls.push_back({x * 32,y * 32,32,32});
	}
}

std::vector<Rectangle> map::getWalls() {
	return map.walls;
}
void map::getMapSize(int* sizeXptr, int* sizeYptr) {
	*sizeXptr = map.sizeX;
	*sizeYptr = map.sizeY;
}
