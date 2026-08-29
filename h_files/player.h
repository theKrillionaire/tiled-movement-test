#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>
#include <vector>

class player {
	public:
		struct pos {
			int x;
			int y;
		};
		void update(std::vector<Rectangle> walls);
		pos getPosT();
		void forcePlayerPos(int);
	private:
		player::pos playerPos = {9,7};
		
};

#endif
