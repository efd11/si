//
//  xfunctions.c
//  SpaceInvaders
//
//  Created by Enguerran DECTOR on 25/09/2014.
//  Copyright (c) 2014 ___EnguerranDECTOR___. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "spaceInvaders.h"

SDL_Window *createwindow(const char* title, int x, int y, int w, int h, Uint32 flags)
{
    SDL_Window *tmpwindow = SDL_CreateWindow(title, x, y, w, h, flags);
    if (tmpwindow == NULL)
    {
        printf("CreateWindow Error\n");
        exit(1);
    }
    return tmpwindow;
}

SDL_Texture *loadtexture(SDL_Renderer *renderer, const char *file)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, file);
    if (texture == NULL)
    {
        printf("LoadTexture Error\n");
        exit(1);
    }
    return texture;
}
