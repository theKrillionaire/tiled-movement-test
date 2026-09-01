#include "render.h"
#include <raylib.h>
#include <vector>
#include <stdio.h>
#include "map.h"
#include "renderable.h"
#include "utility.h"


void renderer::drawScreen(std::vector<renderable*> objects, bool debug, map::mapData* map) {
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();
	
	BeginDrawing();
		ClearBackground(BLACK);
		for(int i = 0; i < objects.size(); i++) {
			Texture2D sprite = objects[i]->getSprite();
			utility::pos pos = objects[i]->getPos();
			DrawTexture(sprite, pos.x, pos.y, WHITE);
		}
		for(int i = 0; i < map->walls.size();i++) {
			DrawRectangle(map->walls[i].x, map->walls[i].y, map->walls[i].width, map->walls[i].height, LIGHTGRAY);
		}
		if(debug) { 
			char buffer[64];
			snprintf(buffer, 64, "x%i, y%i\n", mouseX / 32 * 32, mouseY / 32 * 32);
			DrawText(buffer, 5,5, 20, WHITE);
		}
	EndDrawing();
	
}
