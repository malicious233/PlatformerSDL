#pragma once
#include "collision.h"
struct Block
{
	float x = 0;
	float y = 0;

	void draw();
	AABB getCollision() { return { x, y, x + 32, y + 32 }; }
};