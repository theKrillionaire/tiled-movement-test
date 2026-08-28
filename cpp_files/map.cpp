#include <raylib.h>
#include <stdio.h>
#include "map.h"
#include <vector>

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
