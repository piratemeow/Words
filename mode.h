
int mode ()
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
    kid[0].h = 100;
    kid[0].x = 420;
    kid[0].y = 100;

	SDL_Rect quit_button;
    quit_button.w = 200;
    quit_button.h = 100;
    quit_button.x = 420;
    quit_button.y = 500;
	SDL_RenderCopy(renderer,quit,NULL,&quit_button);
    SDL_RenderCopy(renderer,kids[0],NULL,&kid[0]);

	surface = TTF_RenderText_Solid(font,"NORMAL MODE",{0,0,0});
    SDL_Texture *normal[2];
    normal[0] = SDL_CreateTextureFromSurface(renderer,surface);
    

	SDL_Rect normal_button;
	normal_button.w= 200;
	normal_button.h = 100;
	normal_button.x = 420;
	normal_button.y = 300;
	SDL_RenderCopy(renderer,normal[0],NULL,&normal_button);
	SDL_RenderPresent(renderer);

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
			//cout<<x<<" "<<y<<endl;
		}
			if (SDL_MOUSEBUTTONUP==mode.type && SDL_BUTTON_LEFT==mode.button.button)
			{
				
				
				//return 1;
				if (x>=420 && x<=(420+200) && y<=(100+100) && y>=100)
				{
					cout<<"g\n";
                    
					return 0;
				}

				else if (x>=420 && x<=420+200 && y<=100+500 && y>=500)
				{
					return -1;
				}

				else if (x>=420 && x<=420+200 && y<=100+300 && y>=300)
				{
					return 1;
				}
				
			}
		
    }

    return 10;
}
