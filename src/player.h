#pragma once

struct Player
{
	float x = 170.f;
	float y = 100.f;
	
	float velX;
	float velY;

	bool grounded;

	bool step(float dx, float dy);
	bool sweep(float dx, float dy);
	void update();
	void draw();
};
