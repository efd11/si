//
//  spaceInvaders.h
//  SpaceInvaders
//
//  Created by Ghassen Zayani on 24/09/2014.
//  Copyright (c) 2014 ___EnguerranDECTOR___. All rights reserved.
//

#ifndef SpaceInvaders_spaceInvaders_h
#define SpaceInvaders_spaceInvaders_h

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 650

#define E_WIDTH 30
#define E_HEIGHT 30

SDL_Window *window;
SDL_Renderer *renderer;



static SDL_Surface *sBackground;
static SDL_Surface *sText;
static SDL_Texture *tBackground;
static SDL_Texture *fusee;
static SDL_Texture *tText;

SDL_Rect backgroundpos;
SDL_Rect playerpos;

void init_invaders();
void display_invaders();
void move_invaders_down();

void display_missile();
void init_missile();
void move_missile_up();

SDL_Window *createwindow(const char* title, int x, int y, int w, int h, Uint32 flags);
SDL_Texture *loadtexture(SDL_Renderer *renderer, const char *file);

void handle_events();

#endif
