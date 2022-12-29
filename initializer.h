#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "constants.h"
using namespace std;
bool game_intialization(const char *title, int x_pos, int y_pos,int width, int height)
{
    // Initializing SDL
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)!=0){
        printf("Error");
    }

    if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        printf("ERROR INITIALIZING SDL.\n");

        return 0;
    }

    // Creating new window

    //SDL_Window *window = NULL;
    window = SDL_CreateWindow(title, x_pos, y_pos, width, height, SDL_WINDOW_SHOWN);
    
    // If window creating fails
    if (window == NULL)
    {
        printf ("ERROR CREATEATING WINDOW\n");
        SDL_Quit();
        return 0;
    }

    // Creating renderer

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    renderer = SDL_CreateRenderer(window, -1, render_flags);

    if (renderer == NULL)
    {
        printf("ERROR CREATING RENDERER\n");

        return 0;
    }

    if (!IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG))
    {
        printf("ERROR INITIALIZING IMAGE\n");
        SDL_Quit();
        IMG_Quit();
        return 0;
    }
    
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("montserrat/Montserrat-Medium.otf",20);
    
   
    surface = IMG_Load("background.png");
    if (!surface)
    {
        printf ("ERROR SURFACING IMAGE\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }

    surface = TTF_RenderText_Solid(font,"NEXT ROUND",{0,0,0});

    Next_round = SDL_CreateTextureFromSurface (renderer,surface);

    next_round.w = 300;
    next_round.h = 100;
    next_round.x = 850;
    next_round.y = 550;


    SDL_FreeSurface(surface);
    surface = TTF_RenderText_Solid(font,"MENU",{0,0,0});
    menuee = SDL_CreateTextureFromSurface(renderer,surface);

    menu.x = 80;
    menu.y = 550;
    menu.h = 100;
    menu.w = 200;
    
    SDL_FreeSurface(surface);


   

    ans.x = 920;
    ans.y = 200;
    ans.h = 50;
    ans.w = 200;

    surface = TTF_RenderText_Solid(font,"CORRECT",{0,255,0});
    correct = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = TTF_RenderText_Solid(font,"INCORRECT",{255,0,0});
    incorrect = SDL_CreateTextureFromSurface(renderer,surface);

    SDL_FreeSurface(surface);

    hint.x = 50;
    hint.y = 200;
    hint.w = 500;
    hint.h = 50;
    

    return 1;
}


void main_render()
{
    surface = IMG_Load("background.png");
    back = SDL_CreateTextureFromSurface (renderer,surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer,back,NULL,NULL);
    SDL_RenderPresent (renderer);
}
