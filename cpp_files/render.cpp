#include "render.h"
#include <raylib.h>
#include <vector>
#include <stdio.h>
#include "player.h"

void renderer::drawScreen(std::vector<Texture2D> sprites, std::vector<player::pos> positions, bool debug, std::vector<Rectangle> walls) {
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();
	
	BeginDrawing();
		ClearBackground(BLACK);
		for(int i = 0; i < sprites.size(); i++) {
			DrawTexture(sprites[i], positions[i].x, positions[i].y, WHITE);
		}
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
