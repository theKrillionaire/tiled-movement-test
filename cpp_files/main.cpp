#include <stdio.h>
#include <raylib.h>
#include <cstring>
#include <vector>
#include "player.h"
#include "render.h"
#include "map.h"

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
	
	
	std::vector<Rectangle> walls = { 
		{0, 0, 640, 32},
		{0, 0, 32, 480},
		{0, 448, 640, 32},
		{608, 0, 32, 480},
		{352, 64, 224, 128}
	};
	
	m.loadMap("map");
	m.makeWalls();
	walls = m.getWalls();
	for(Rectangle wall : walls) {
		printf("%f,%f,%f,%f", wall.x, wall.y, wall.width, wall.height);
	}
	
	std::vector<Texture2D> spritesBuffer = { LoadTexture("sprites/player.png") };
	std::vector<player::pos> positionsBuffer;
	
	while(!WindowShouldClose()) {	
	
		player::pos playerPosT = p.getPosT();
		p.update(walls);
		positionsBuffer = {playerPosT};
		r.drawScreen(spritesBuffer, positionsBuffer, debug, walls);
	
	}
	return 0;
}
