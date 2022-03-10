#pragma once
#include <SDL/SDL.h>
#include "camera.h"

extern SDL_Window* window;
extern SDL_Renderer* render;
extern Camera camera;
extern bool keys[SDL_NUM_SCANCODES];

extern float delta_time;
