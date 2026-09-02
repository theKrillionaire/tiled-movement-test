#ifndef OBJECT_H
#define OBJECT_H

#include <raylib.h>
#include "utility.h"
#include "renderable.h"

class object : public renderable {
	private:
		utility::pos pos;
		Texture2D sprite;
	public:
		void setPos(utility::pos set);
		void setSpr(Texture2D set);
		utility::pos getPos() override;
		Texture2D getSprite() override;
};

#endif
