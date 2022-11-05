//#include "initializer.h"
#include "logic.h"
int width = 1080;
int height = 720;

int x_pos = SDL_WINDOWPOS_CENTERED;
int y_pos = SDL_WINDOWPOS_CENTERED;


int main ()


{
     game_intialization("WORDS",x_pos, y_pos, width, height);
     
     SDL_Event e;
    while (game)
    {
      if (SDL_PollEvent(&e)!=0)
      {
          if(e.type==SDL_QUIT )
		      {
			      game = 0;
			      break;
          }	
         
      }
      main_render();
       logic();
       if (next_step())
       {
        SDL_RenderClear(renderer);
        //logic();
       }
       
    }
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

   
}
