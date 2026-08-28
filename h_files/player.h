#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>
#include <vector>

class player {
	private:
		int playerPos[2] = { 9, 7 };
	public:
		void update(std::vector<Rectangle> walls);
};

#endif
