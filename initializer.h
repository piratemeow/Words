#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>


bool game_intialization(const char *title, int x_pos, int y_pos,int width, int height)
{
    // Initializing SDL
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        printf("ERROR INITIALIZING SDL.\n");

        return 0;
    }

    // Creating new window

    SDL_Window *window = NULL;
    window = SDL_CreateWindow(title, x_pos, y_pos, width, height, SDL_WINDOW_SHOWN);
    
    // If window creating fails
    if (window == NULL)
    {
        printf ("ERROR CREATEATING WINDOW\n");
        SDL_Quit();
        return 0;
    }

    // Creating renderer

    SDL_Renderer *renderer = NULL;
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

    SDL_Surface *surface = NULL;
    surface = IMG_Load("6.png");

    if (!surface)
    {
        printf ("ERROR SURFACING IMAGE\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }
    
    SDL_Texture * tex= SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    if (!tex)
    {
        printf("ERROR CREATING TEXTURE\n");

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }

    SDL_Rect dest;
    SDL_QueryTexture(tex,NULL,NULL,&dest.w,&dest.h);

    dest.w=(int) dest.w *1;
    dest.h = (int) dest.h *1;
    dest.x= (int) 900;
    dest.y = 0 ;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,tex,NULL,&dest);
    SDL_RenderPresent(renderer);


    SDL_Delay(15000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 1;

}