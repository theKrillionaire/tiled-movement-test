#include <stdio.h>
#include <raylib.h>
#include <cstring>
#include <vector>
#include "player.h"



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
	
	
	std::vector<Rectangle> walls = { 
		{0, 0, 640, 32},
		{0, 0, 32, 480},
		{0, 448, 640, 32},
		{608, 0, 32, 480},
		{352, 64, 224, 128}
	};
	
	
	while(!WindowShouldClose()) {	
	
	int playerPosT[2];
	p.getPosT(playerPosT);
	p.update(walls);
	
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();
	
			BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangle(playerPosT[0], playerPosT[1], 32, 32, RED);
			for(int i = 0; i < walls.size();i++) {
				DrawRectangle(walls[i].x, walls[i].y, walls[i].width, walls[i].height, LIGHTGRAY);
			}
			if(debug) { 
				char buffer[64];
				snprintf(buffer, 64, "x%i, y%i\n", mouseX / 32 * 32, mouseY / 32 * 32);
				DrawText(buffer, 5,5, 20, WHITE);
			}
		EndDrawing();
	}
	return 0;
}
