
void mode_screen()
{
	TTF_Init();
	TTF_Font *font = TTF_OpenFont("montserrat/Montserrat-Medium.otf",20);
	surface = TTF_RenderText_Solid(font,"KIDS MODE",{0,0,0});
    SDL_Texture *kids[2];
    kids[0] = SDL_CreateTextureFromSurface(renderer,surface);
    kids[1] = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
	surface = TTF_RenderText_Solid(font,"QUIT",{0,0,0});
	SDL_Texture *quit = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
    SDL_Rect kid[2];
    kid[0].w = 200;
    kid[0].h = 150;
    kid[0].x = 500;
    kid[0].y = 100;
	
	SDL_Rect quit_button;
    quit_button.w = 150;
    quit_button.h = 100;
    quit_button.x = 530;
    quit_button.y = 500;
	//SDL_RenderCopy(renderer,quit,NULL,&quit_button);
    SDL_RenderCopy(renderer,kids[0],NULL,&kid[0]);

	surface = TTF_RenderText_Solid(font,"NORMAL MODE",{0,0,0});
    SDL_Texture *normal[2];
    normal[0] = SDL_CreateTextureFromSurface(renderer,surface);
    

	SDL_Rect normal_button;
	normal_button.w = 220;
	normal_button.h = 150;
	normal_button.x = 490;
	normal_button.y = 300;
	SDL_RenderCopy(renderer,normal[0],NULL,&normal_button);
	
	SDL_RenderPresent(renderer);
	return ;
}



int mode ()
{
    mode_screen();
    

    SDL_Event mode;
    while (game)
    {
        int x,y;
        SDL_PollEvent(&mode);
		if(mode.type==SDL_QUIT)
		{
			game = 0;
			return 0;
		}
		if (mode.type==SDL_MOUSEMOTION)
		{
			
			SDL_GetMouseState(&x,&y);
			
		}
			if (SDL_MOUSEBUTTONUP==mode.type && SDL_BUTTON_LEFT==mode.button.button)
			{
				
				
				//return 1;
				if (x>=500 && x<=(500+200) && y<=(100+150) && y>=100)
				{
					
                    
					return 0;
				}

				else if (x>=420 && x<=420+200 && y<=100+500 && y>=500)
				{
					return -1;
				}

				else if (x>=490 && x<=420+220 && y<=150+300 && y>=300)
				{
					return 1;
				}
				
			}
		
    }

    return 10;
}
