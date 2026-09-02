#include "object.h"
#include "utility.h"
#include <raylib.h>
#include "renderable.h"

void object::setPos(utility::pos set) {
	pos = set;
}
void object::setSpr(Texture2D set) {
	sprite = set;
}

utility::pos object::getPos() {
	utility::pos posBig = {pos.x * 32, pos.y * 32 };
	return posBig;
}

Texture2D object::getSprite() {
	return sprite;
}
