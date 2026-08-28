#ifndef RENDER_H
#define RENDER_H

#include <raylib.h>
#include <vector>

class renderer {
	private:
		
	public:
		void drawScreen(std::vector<Texture2D> sprites, std::vector<int> positions, bool debug, std::vector<Rectangle> walls);
	
};

#endif
