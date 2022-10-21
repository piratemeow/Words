//#include "initializer.h"
#include "logic.h"
int width = 1080;
int height = 720;

int x_pos = SDL_WINDOWPOS_CENTERED;
int y_pos = SDL_WINDOWPOS_CENTERED;


int main ()


{

    bool x= game_intialization("WORDS",x_pos, y_pos, width, height);
    logic();

        SDL_Delay(15000);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

   
}
