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

#define  SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

SDL_Window *window;
SDL_Renderer *renderer;

SDL_Surface *sBackground;
SDL_Texture *tBackground, *fusee;

SDL_Rect bpos;
SDL_Rect mpos, mpart;

void init()
{
    
    if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO|SDL_INIT_EVENTS) < 0)
    {
        printf("error\n");
        exit(1);
    }
    window = SDL_CreateWindow("SPACE INVAIDERS", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    bpos.x = 0;
    bpos.y = 0;
    bpos.w = SCREEN_WIDTH;
    bpos.h = SCREEN_HEIGHT;
    
    mpos.x = 0;
    mpos.y = SCREEN_HEIGHT - 105;
    mpos.w = 50;
    mpos.h = 75;
    
    mpart.x = 0;
    mpart.y = 0;
    mpart.h = 23;
    mpart.w = 37;
}

void destroy()
{
    SDL_DestroyTexture(tBackground);
    SDL_FreeSurface(sBackground);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void load()
{
    int w, h;
    tBackground = IMG_LoadTexture(renderer, "background.jpg");
    fusee = IMG_LoadTexture(renderer, "/Users/ghassenzayani/Desktop/SPACE INVADERS/fusee.png");
    SDL_QueryTexture(tBackground, 0, 0, &w, &h);
}

int i = 1;

int main(int argc, const char * argv[])
{
    
    // insert code here...
    
    init();
    load();
    while (i == 1) {
        
        Uint32 towait;
        Uint32 time = SDL_GetTicks();
        
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, tBackground, 0, &bpos);
        SDL_RenderCopy(renderer, fusee, &mpart, &mpos);
        SDL_RenderPresent(renderer);
        towait = SDL_GetTicks() - time;
        if (towait < 16) {
            SDL_Delay(16 - towait);
            if (towait < 16) {
                SDL_Delay(16 - towait);
            }
        }
    }
    
    destroy();
    return 0;
}
