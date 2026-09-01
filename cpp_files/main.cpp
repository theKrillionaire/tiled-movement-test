#include <stdio.h>
#include <raylib.h>
#include <cstring>
#include <vector>
#include "player.h"
#include "render.h"
#include "map.h"
#include "utility.h"
#include "renderable.h"

int main(int argc, char** argv) {
	bool debug = false;
	if(argc > 1) {
		if(strcmp("-d",argv[1]) == 0) debug = true;
	}
	
	const char* wName = "Tile-based movement test";
	const int wSize[2] = {640,480};
	InitWindow(wSize[0], wSize[1], wName);
	SetTargetFPS(30);
	
	const int tileSize = 32;
	
	player p;
	renderer r;
	map m;
	
	
	map::mapData map;
	
	m.loadMap("map");
	m.makeWalls();
	map.walls = m.getWalls();
	m.getMapSize(&map.sizeX, &map.sizeY);
	for(Rectangle wall : map.walls) {
		printf("%f,%f,%f,%f", wall.x / 32, wall.y / 32, wall.width / 32, wall.height / 32);
	}
	printf("sizeX: %i, sizeY: %i", map.sizeX, map.sizeY);
	
	std::vector<renderable*> renderObjects = { &p };
	
	while(!WindowShouldClose()) {	
		utility::pos playerPosT = p.getPosT();
		p.update(map);
		r.drawScreen(&renderObjects, debug, &map);
	
	}
	return 0;
}
