#pragma once
#include "player.h"
#include "block.h"
#include "camera.h"


#define PROJECTILE_MAX 20
#define BRICK_MAX 8
#define MAX_HEALTH 5

#define MAP_COLS 15
#define MAP_ROWS 15
#define NUM_BLOCKS (MAP_COLS * MAP_ROWS)

extern Player player;
extern Block* blocks[MAP_COLS * MAP_ROWS];	
extern Camera camera;

extern int health;

void LoadMap();
