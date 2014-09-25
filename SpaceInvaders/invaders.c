//
//  invaders.c
//  SpaceInvaders
//
//  Created by Ghassen Zayani on 24/09/2014.
//  Copyright (c) 2014 ___EnguerranDECTOR___. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "spaceInvaders.h"

static SDL_Texture *invader;

struct enemy_t {
    SDL_Rect invaderpos;
    unsigned int alive;
};

struct invaders_t {
    struct enemy_t enemy[5][10];
    unsigned int killed;
   	int state;
    int state_speed;
    Uint32 state_time;
};

struct invaders_t invaders;

void init_invaders()
{
    // invaders.killed = 0;
    //  invaders.state_speed = 1000;
    invaders.state_time = SDL_GetTicks();
    
    int i;
    int j;
    int x = 100;
    int y = 50;
    
    invader = loadtexture(renderer, "invader.png");

    for (i = 0; i < 5; i++) {
        
        for (j = 0; j < 10; j++)
        {
            invaders.enemy[i][j].alive = 1;
            invaders.enemy[i][j].invaderpos.x = x;
            invaders.enemy[i][j].invaderpos.y = y;
            invaders.enemy[i][j].invaderpos.w = E_WIDTH;
            invaders.enemy[i][j].invaderpos.h = E_HEIGHT;
            x += E_WIDTH + 30;
        }
        x = 100;
        y += E_HEIGHT + 30;
    }
}

void display_invaders()
{
    SDL_Rect dest;
    int i;
    int j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            dest.x = invaders.enemy[i][j].invaderpos.x;
            dest.y = invaders.enemy[i][j].invaderpos.y;
            dest.w = invaders.enemy[i][j].invaderpos.w;
            dest.h = invaders.enemy[i][j].invaderpos.h;
            SDL_RenderCopy(renderer, invader, 0, &dest);
        }
    }
}

void move_invaders_down()
{
	int i;
    int j;
    
    for (i = 0; i < 5; i++) {
		for (j = 0; j < 10; j++) {
            invaders.enemy[i][j].invaderpos.y += 1;
		}
	}
}
