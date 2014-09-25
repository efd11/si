//
//  missile.c
//  SpaceInvaders
//
//  Created by Ghassen Zayani on 24/09/2014.
//  Copyright (c) 2014 ___EnguerranDECTOR___. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "spaceInvaders.h"

//static SDL_Texture *missile;
SDL_Rect missilepos;

//struct missile_t {
//
//	SDL_Rect missilepos;
//	unsigned int alive;
//};

struct missile_t {
	unsigned int alive;
};

void display_missile()
{
    int i;

    missilepos.x = playerpos.x + (playerpos.w / 2) - (missilepos.w /2);
    missilepos.y = playerpos.y - (missilepos.h + 10);
    missilepos.h = 24;
    missilepos.w = 10;
    
    fusee = loadtexture(renderer, "fusee.png");
    SDL_RenderCopy(renderer, fusee, NULL, &missilepos);

    for (i = 0; i <= 100; i++) {
        missilepos.y -= i;
    }
}

void move_missile_up()
{
	int i;
    
    for (i = 0; missilepos.y > 0; i++)
    {
      //  SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, fusee, 0, &missilepos);
        missilepos.y -= 1;
    }
}
