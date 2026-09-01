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
		void drawScreen(const std::vector<renderable*>* objects, const bool debug, const map::mapData* map);
	
};

#endif
