#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>
#include <vector>
#include "utility.h"
#include "map.h"
#include "renderable.h"

class player : public renderable {
	public:
		player();
		void update(map::mapData map);
		utility::pos getPosT();
		void forcePlayerPos(int);
		utility::pos getPos() override;
		Texture2D getSprite() override;
	private:
		Texture2D sprite;
		utility::pos playerPos = {9,7};

		
};

#endif
