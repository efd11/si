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

void init()
{
    
    if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO|SDL_INIT_EVENTS) < 0)
    {
        printf("error\n");
        exit(1);
    }
    window = SDL_CreateWindow("SPACE INVAIDERS", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    
   // bpos->x = 0;
   // bpos->y = 0;
   // bpos->w = SCREEN_WIDTH;
   // bpos->h = SCREEN_HEIGHT;
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
  
    tBackground = IMG_LoadTexture(renderer, "/Users/ghassenzayani/Desktop/SPACE INVADERS/release/si/SpaceInvaders/background.jpg");
}
int i = 1;

int main(int argc, const char * argv[])
{
    
    // insert code here...
    
    
    init();
    load();
    while (i == 1) {
        
        //Uint32 towait;
        //Uint32 time = SDL_GetTicks();
        
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, tBackground, 0, bpos);
        SDL_RenderPresent(renderer);
        
    }
    
    destroy();
    return 0;
}
