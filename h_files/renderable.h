#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "utility.h"
#include "raylib.h"

class renderable {
	public:
		virtual utility::pos getPos() = 0;
		virtual Texture2D getSprite() = 0;
};

#endif
