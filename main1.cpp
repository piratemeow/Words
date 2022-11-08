//#include "initializer.h"
#include "logic.h"
#include "mode.h"
int width = 1080;
int height = 720;

int x_pos = SDL_WINDOWPOS_CENTERED;
int y_pos = SDL_WINDOWPOS_CENTERED;


int main ()


{
     game_intialization("WORDS",x_pos, y_pos, width, height);
     
    
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
      if (mode()==1)
      {
        SDL_RenderClear(renderer);
        main_render();
        logic_for_adult();
         while (next_step())
       {
         main_render();
         logic_for_adult();
         SDL_RenderClear(renderer);
        //logic();
       }
      }

       else if (mode()==0)
      {
        SDL_RenderClear(renderer);
        main_render();
        logic_for_kids();
         while (next_step())
       {
         main_render();
         logic_for_kids();
         SDL_RenderClear(renderer);
        //logic();
       }
      }

      else if (mode()==-1)
      {
        game = 0;
        break;
      }
      
       
    }
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

   
}
