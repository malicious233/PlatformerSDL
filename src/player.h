#pragma once

struct Player
{
	float x = 100.f;
	float y = 100.f;
	
	float velX;
	float velY;

	bool grounded;

	bool step(float dx, float dy);
	void update();
	void draw();
};
