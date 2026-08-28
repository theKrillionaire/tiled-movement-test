#include <stdio.h>
#include <raylib.h>
#include <cstring>
#include <vector>

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
	
	int playerPos[2] = { 9, 7 };
	//Rectangle playerCollider = { playerPos[0] * 32, playerPos[1] * 32, 32,32 };
	
	std::vector<Rectangle> walls = { 
		{0, 0, 640, 32},
		{0, 0, 32, 480},
		{0, 448, 640, 32},
		{608, 0, 32, 480},
		{352, 64, 224, 128}
	};
	
	
	while(!WindowShouldClose()) {
		// logic
		int playerPosT[2] = { playerPos[0] * 32, playerPos[1] * 32 };
		
		int newPos[2] = {playerPos[0], playerPos[1]};
		int mouseX = GetMouseX();
		int mouseY = GetMouseY();	
			

		
		if(IsKeyPressed(KEY_LEFT)) newPos[0]--;
		else if(IsKeyPressed(KEY_RIGHT)) newPos[0]++;
		if(IsKeyPressed(KEY_UP)) newPos[1]--;
		else if(IsKeyPressed(KEY_DOWN)) newPos[1]++;
		
		Rectangle playerColliderX = { newPos[0] * 32, playerPosT[1], 32,32 };
		Rectangle playerColliderY = { playerPosT[0], newPos[1] * 32, 32,32 };
		
		bool collideX = false;
		bool collideY = false;
		for(int i = 0; i < walls.size();i++) {
			if(CheckCollisionRecs(walls[i], playerColliderX)) collideX = true; 
			if(CheckCollisionRecs(walls[i], playerColliderY)) collideY = true; 
		}
		
		if(!collideX) playerPos[0] = newPos[0];
		if(!collideY) playerPos[1] = newPos[1];
		
		

		//drawing
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
