#include "player.h"
#include <vector>
#include <raylib.h>

void player::update(std::vector<Rectangle> walls) {
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
	
}
