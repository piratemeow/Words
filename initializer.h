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

    //SDL_Renderer *renderer = NULL;
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
    
    

    // if (!tex)
    // {
    //     printf("ERROR CREATING TEXTURE\n");

    //     SDL_DestroyRenderer(renderer);
    //     SDL_DestroyWindow(window);
    //     SDL_Quit();
    //     return 0;

    // }

    // SDL_Texture *back ;
    
    
    // SDL_Texture * tex[7];
    surface = IMG_Load("0.png");
    tex[0] = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("1.png");
    tex[1] = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("2.png");
    tex[2] = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("3.png");
    tex[3] = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("4.png");
    tex[4] = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("5.png");
    tex[5] = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("6.png");
    tex[6] = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);


    // surface = TTF_RenderText_Solid(font,"_",{0,0,0});
    // SDL_Texture *under_score = SDL_CreateTextureFromSurface(renderer,surface);
    // SDL_FreeSurface(surface);

    //SDL_Rect dest[7];
    SDL_QueryTexture(tex[0],NULL,NULL,&dest[0].w,&dest[0].h);

    for (int i=0; i<7 ;i++)
    {
    dest[i].w=(int) dest[0].w *1;
    dest[i].h = (int) dest[0].h *1;
    dest[i].x= (int) 750;
    dest[i].y = 0 ;
    
    }

   // SDL_RenderClear(renderer); this was changed

    SDL_RenderCopy(renderer,tex[0],NULL,&dest[0]);

    surface = TTF_RenderText_Solid(font,"NEXT ROUND",{0,0,0});

    Next_round = SDL_CreateTextureFromSurface (renderer,surface);

    next_round.w = 400;
    next_round.h = 100;
    next_round.x = 300;
    next_round.y = 500;

   // SDL_RenderCopy(renderer,Next_round,NULL,&next_round);
    SDL_FreeSurface(surface);
    //SDL_RenderPresent(renderer);


    // SDL_Delay(15000);
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);

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
