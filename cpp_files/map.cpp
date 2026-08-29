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
	for(int i = 0; mapFile.get(character); i++) {
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
		if(input[i]) walls.push_back({x * 32,y * 32,32,32});
	}
}

std::vector<Rectangle> map::getWalls() {
	return walls;
}
