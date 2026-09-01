#ifndef RENDER_H
#define RENDER_H

#include <raylib.h>
#include <vector>
#include "player.h"
#include "utility.h"
#include "map.h"

class renderer {
	private:
		
	public:
		void drawScreen(std::vector<Texture2D> sprites, std::vector<utility::pos> positions, bool debug, map::mapData map);
	
};

#endif
