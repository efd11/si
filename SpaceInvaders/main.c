//
//  main.c
//  SpaceInvaders
//
//  Created by Enguerran DECTOR on 21/09/2014.
//  Copyright (c) 2014 ___EnguerranDECTOR___. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "SDL2_ttf/SDL_ttf.h"
#include "spaceInvaders.h"

Mix_Music *music;
TTF_Font *font;

void init()
{
    if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO|SDL_INIT_EVENTS) < 0)
    {
        printf("Display error\n");
        exit(1);
    }
    
    TTF_Init();
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("Music error\n");
        exit(1);
    }
    window = createwindow("SPACE INVAIDERS", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    backgroundpos.x = 0;
    backgroundpos.y = 0;
    backgroundpos.w = SCREEN_WIDTH;
    backgroundpos.h = SCREEN_HEIGHT;
    playerpos.x = 50;
    playerpos.y = SCREEN_HEIGHT - 100;
    playerpos.w = 81;
    playerpos.h = 50;
}

void load()
{
    int w;
    int h;
    
    tBackground = loadtexture(renderer, "background.jpg");
    fusee = loadtexture(renderer, "fusee.png");
    SDL_QueryTexture(tBackground, 0, 0, &w, &h);
    music = Mix_LoadMUS("spaceinvaders1.mpeg");
    font = TTF_OpenFont("Arial.ttf", 25);
    if (!font)
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    sText = TTF_RenderText_Solid(font, "GAME OVER", color);
    if (!sText)
    {
        printf("TTF_RenderText_Solid: %s\n", TTF_GetError());
    }
    tText = SDL_CreateTextureFromSurface(renderer, sText);
    if (!music)
    {
        printf("Mix_LoadMUS Error: %s\n", Mix_GetError());
    }
}

void destroy()
{
    Mix_FreeMusic(music);
    SDL_DestroyTexture(tBackground);
    SDL_FreeSurface(sBackground);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, const char * argv[])
{
    int quit = 1;
    init();
    load();
    if (Mix_PlayMusic(music, 0) < 0)
    {
        printf("PlayMusic Error\n");
        exit(1);
    }
    init_missile();
    init_invaders();
    while (quit)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, tBackground, 0, &backgroundpos);
        SDL_RenderCopy(renderer, fusee, 0, &playerpos);
        display_invaders();
        handle_events();
        move_invaders_down();
        if (gameover == 1)
            SDL_RenderCopy(renderer, tText, 0, &backgroundpos);
        event();
        move_missile_up();
    }
    destroy();
    return 0;
}
