#ifndef RENDER_H
#define RENDER_H

#include <raylib.h>
#include <vector>
#include "player.h"

class renderer {
	private:
		
	public:
		void drawScreen(std::vector<Texture2D> sprites, std::vector<player::pos> positions, bool debug, std::vector<Rectangle> walls);
	
};

#endif
