#include "player.h"
#include "engine.h"
#include "game.h"

void Player::update()
{
	// move
	if (keys[SDL_SCANCODE_D])
		velX += 600 * delta_time;
	if (keys[SDL_SCANCODE_A])
		velX -= 600 * delta_time;

	if (keys[SDL_SCANCODE_SPACE] && grounded)
	{
		velY = -300.f;
	}

	//Apply gravity
	velY += 600.f * delta_time;

	//Apply friction
	velX -= velX * 5.f * delta_time;

	//Apply velocity to position
	step(velX * delta_time, 0.f);
	step(0.f, velY * delta_time);
}

void Player::draw()
{
	SDL_SetRenderDrawColor(render, 150, 25, 40, 255);
	SDL_Rect rect = { (int)x - 16 - camera.x, (int)y - 16 - camera.y, 32, 32 };
	SDL_RenderFillRect(render, &rect);
}

bool Player::sweep(float dx, float dy)
{
	if (x + dx < 16.f || x + dx > 800.f - 16.f
		|| y + dy < 16.f || y + dy > 600.f - 16.f)
	{
		return true;
	}
	return false;
}

bool Player::step(float dx, float dy)
{
	if (sweep(dx, dy))
	{
		velY = 0;
		grounded = true;
		return false;
	}

	AABB playerBox = AABB::make_from_position_size(x + dx, y + dy, 32, 32);
	for (int i = 0; i < NUM_BLOCKS; i++)
	{
		Block* block = blocks[i];
		if (block == nullptr)
			continue;
		if (aabb_intersect(playerBox, block->getCollision()))
		{
			velY = 0;
			grounded = true;
			return false;
		}
	}

	

	x += dx;
	y += dy;
	
	grounded = false;
	return true;
}