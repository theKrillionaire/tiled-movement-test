#include "render.h"
#include <raylib.h>
#include <vector>
#include <stdio.h>
#include "player.h"
#include "map.h"

void renderer::drawScreen(std::vector<Texture2D> sprites, std::vector<utility::pos> positions, bool debug, map::mapData map) {
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();
	
	BeginDrawing();
		ClearBackground(BLACK);
		for(int i = 0; i < sprites.size(); i++) {
			DrawTexture(sprites[i], positions[i].x, positions[i].y, WHITE);
		}
		for(int i = 0; i < map.walls.size();i++) {
			DrawRectangle(map.walls[i].x, map.walls[i].y, map.walls[i].width, map.walls[i].height, LIGHTGRAY);
		}
		if(debug) { 
			char buffer[64];
			snprintf(buffer, 64, "x%i, y%i\n", mouseX / 32 * 32, mouseY / 32 * 32);
			DrawText(buffer, 5,5, 20, WHITE);
		}
	EndDrawing();
	
}
