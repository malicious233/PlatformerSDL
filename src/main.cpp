#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "engine.h"
#include "player.h"
#include "game.h"
#include "collision.h"
#include "block.h"
#include "camera.h"

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING); 
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,600,0); 
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
 
	bool running = true;
	Uint64 previous_ticks = SDL_GetPerformanceCounter();

	Block block;

	LoadMap();
 
	while (running)
	{
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 delta_ticks = ticks - previous_ticks;
		previous_ticks = ticks; 
		delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency(); 
		
		SDL_Event event;
		while(SDL_PollEvent(&event)) 
		{
			switch(event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
 
			case SDL_KEYDOWN:
			{
				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE)
					running = false;

				keys[scancode] = true;
 
				break;
			}
 
			case SDL_KEYUP:
			{
				int scancode = event.key.keysym.scancode;
				keys[scancode] = false;
 
				break;
			}
			}
		}

		
 
		SDL_SetRenderDrawColor(render, 25, 25, 40, 255); 
		SDL_RenderClear(render);

		//Render blocks
		for (int i = 0; i < NUM_BLOCKS; i++)
		{
			Block* block = blocks[i];
			if (block == nullptr)
				continue;

			block->draw();
		}

		//Draw and update player
		player.update();
		player.draw();

		//Update camera
		camera.update();

		SDL_RenderPresent(render);
 
	}
}
