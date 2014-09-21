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

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 650

#define E_WIDTH 30
#define E_HEIGHT 30

SDL_Window *window;
SDL_Renderer *renderer;

static SDL_Surface *sBackground;
static SDL_Texture *tBackground;
static SDL_Texture *fusee;
static SDL_Texture *missile;
static SDL_Texture *invader;

SDL_Rect bpos;
SDL_Rect mpos;
SDL_Rect missilepos;



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

int right, left = 0;

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
    
    mpos.x = 50;
    mpos.y = SCREEN_HEIGHT - 100;
    mpos.w = 81;
    mpos.h = 50;
    
    
}

void init_invaders() {
    

    invaders.killed = 0;
    invaders.state_speed = 1000;
    invaders.state_time = SDL_GetTicks();

    int i,j;
    int x = 100;
    int y = 50;
    
    for (i = 0; i < 5; i++) {
        
        for (j = 0; j < 10; j++) {
            
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

void display_missile() {
    
    missilepos.x = mpos.x + (mpos.w / 2) - (missilepos.w /2);
    missilepos.y = mpos.y - missilepos.h;
    missilepos.h = 24;
    missilepos.w = 10;
    
    SDL_RenderCopy(renderer, fusee, 0, &missilepos);
    
}

void display_invaders() {
    
    SDL_Rect src, dest;
    int i,j;
    
    src.w = E_WIDTH;
    src.h = E_HEIGHT;
    
    for (i = 0; i < 5; i++) {
        
        for (j = 0; j < 10; j++) {
            
            if (invaders.enemy[i][j].alive == 1) {
                
                //purple
                if(i == 0) {
                    
                    if (invaders.state == 0) {
                        
                        src.x = 0;
                        src.y = 0;
                        
                    } else {
                        
                        src.x = 30;
                        src.y = 0;
                    }
                    
                    //green
                } else if (i > 0 && i < 3) {
                    
                    if (invaders.state == 0) {
                        
                        src.x = 0;
                        src.y = E_HEIGHT;
                        
                    } else {
                        
                        src.x = 30;
                        src.y = E_HEIGHT;
                    }
                    
                    //red
                } else {
                    
                    if (invaders.state == 0) {
                        
                        src.x = 0;
                        src.y = E_HEIGHT * 2;
                        
                    } else {
                        
                        src.x = 30;
                        src.y = E_HEIGHT * 2;	
                    }
                }
                
                dest.x = invaders.enemy[i][j].invaderpos.x;
                dest.y = invaders.enemy[i][j].invaderpos.y;
                dest.w = invaders.enemy[i][j].invaderpos.w;
                dest.h = invaders.enemy[i][j].invaderpos.h;
                
//              SDL_BlitSurface(invadersmap, &src, sBackground, &dest);
                SDL_RenderCopy(renderer, invader, 0, &dest);
            }
        }
    }
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
    fusee = IMG_LoadTexture(renderer, "fusee.png");
    invader = IMG_LoadTexture(renderer, "invader.png");
    missile = IMG_LoadTexture(renderer, "missile.png");
    SDL_QueryTexture(tBackground, 0, 0, &w, &h);
}

void event()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        right = 1;
                        break;
                    case SDLK_LEFT:
                        left = 1;
                        break;
                }
            break;
            case SDL_KEYUP:
                switch (e.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        right = 0;
                        break;
                    case SDLK_LEFT:
                        left = 0;
                        break;
                
                }
            break;
            default:
            break;
                
        }
    }
}

int i = 1;

int main(int argc, const char * argv[])
{
    
    // insert code here...
    
    init();
    init_invaders();
    load();
    while (i == 1) {
        
        Uint32 towait;
        Uint32 time = SDL_GetTicks();
        
        event();
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, tBackground, 0, &bpos);
        SDL_RenderCopy(renderer, fusee, 0, &mpos);
        display_invaders();
        display_missile();
        SDL_RenderPresent(renderer);
        
        if (right)
        {
            mpos.x += 8;
        }
        if (left)
        {
            mpos.x -= 8;
        }
        
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
