#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>
#include <vector>
#include "utility.h"
#include "map.h"

class player {
	public:
		void update(map::mapData map);
		utility::pos getPosT();
		void forcePlayerPos(int);
	private:
		utility::pos playerPos = {9,7};
		
};

#endif
