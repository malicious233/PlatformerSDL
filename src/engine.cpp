#include "engine.h"
#include "camera.h"

SDL_Window* window;
SDL_Renderer* render;
Camera camera;

bool keys[SDL_NUM_SCANCODES] = { false };

float delta_time = 0.f;
