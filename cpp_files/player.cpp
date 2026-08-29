#include "player.h"
#include <vector>
#include <raylib.h>

void player::update(std::vector<Rectangle> walls) {
	playerPos;
	pos playerPosT = {playerPos.x * 32, playerPos.y * 32 };
		
	pos newPos = {playerPos.x, playerPos.y};	
	
	if(IsKeyPressed(KEY_LEFT)) newPos.x--;
	else if(IsKeyPressed(KEY_RIGHT)) newPos.x++;
	if(IsKeyPressed(KEY_UP)) newPos.y--;
	else if(IsKeyPressed(KEY_DOWN)) newPos.y++;
	
	Rectangle playerColliderX = { newPos.x * 32, playerPosT.y, 32,32 };
	Rectangle playerColliderY = { playerPosT.x, newPos.y * 32, 32,32 };
	
	bool collideX = false;
	bool collideY = false;
	for(int i = 0; i < walls.size();i++) {
		if(CheckCollisionRecs(walls[i], playerColliderX)) collideX = true; 
		if(CheckCollisionRecs(walls[i], playerColliderY)) collideY = true; 
	}
	
	if(!collideX) playerPos.x = newPos.x;
	if(!collideY) playerPos.y = newPos.y;
	
}

player::pos player::getPosT() {
	pos playerPosT = { playerPos.x * 32, playerPos.y * 32 };
	return playerPosT;
}
