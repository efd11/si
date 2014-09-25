//
//  events.c
//  SpaceInvaders
//
//  Created by Enguerran DECTOR on 25/09/2014.
//  Copyright (c) 2014 ___EnguerranDECTOR___. All rights reserved.
//

#include <SDL2/SDL.h>
#include "spaceInvaders.h"

SDL_Event e;

int right;
int left;
int up;

void handle_keydown()
{
    switch (e.key.keysym.sym)
    {
        case SDLK_RIGHT:
            right = 1;
            break;
        case SDLK_LEFT:
            left = 1;
            break;
        case SDLK_UP:
            up = 1;
            break;
    }
}

void handle_keyup()
{
    switch (e.key.keysym.sym)
    {
        case SDLK_RIGHT:
            right = 0;
            break;
        case SDLK_LEFT:
            left = 0;
            break;
    }
}

void handle_keys()
{
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                handle_keydown();
                break;
            case SDL_KEYUP:
                handle_keyup();
                break;
            default:
                break;
        }
    }
}

void handle_events()
{
    Uint32 towait;
    Uint32 time;
    
    right = 0;
    left = 0;
    up = 0;
    handle_keys();
    if (right)
        playerpos.x += 8;
    if (left)
        playerpos.x -= 8;
    if (up)
    {
        display_missile();
        //        move_missile_up();
    }
    SDL_RenderPresent(renderer);
    time = SDL_GetTicks();
    towait = SDL_GetTicks() - time;
    if (towait < 16)
        SDL_Delay(16 - towait);
}
