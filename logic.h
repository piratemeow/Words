#include<time.h>
#include<stdlib.h>
#include <SDL2/SDL_ttf.h>
#include<bits/stdc++.h>
#include "initializer.h"
using namespace std;
int strlen(char word[])
{
	int char_count=0;
	while (word[char_count])
	{
		char_count++;
	}

	return char_count;
}
char sdltocharacter(SDL_Event character)
{
	char ch;
	if (character.type == SDL_KEYUP)
	{
		switch (character.key.keysym.sym)
		{
			case SDLK_a :
				ch='a';
				break;
			case SDLK_b :
				ch ='b';
				break;
			case SDLK_c :
				ch ='c';
				break;
			case SDLK_d :
				ch ='d';
				break;
			case SDLK_e :
				ch ='e';
				break;
			case SDLK_f :
				ch ='f';
				break;
			case SDLK_g :
				ch ='g';
				break;
			case SDLK_h :
				ch ='h';
				break;
			case SDLK_i :
				ch ='i';
				break;
			case SDLK_j :
				ch ='j';
				break;
			case SDLK_k :
				ch ='k';
				break;
			case SDLK_l :
				ch ='l';
				break;
			case SDLK_m :
				ch ='m';
				break;
			case SDLK_n :
				ch ='n';
				break;
			case SDLK_o :
				ch ='o';
				break;
			case SDLK_p :
				ch ='p';
				break;
			case SDLK_q:
				ch='q';
				break;
			case SDLK_r:
				ch='r';
				break;
			case SDLK_s:
				ch='s';
				break;
			case SDLK_t:
				ch='t';
				break;

			case SDLK_u :
				ch ='u';
				break;
			case SDLK_v :
				ch ='v';
				break;
			case SDLK_w :
				ch ='w';
				break;
			case SDLK_x :
				ch ='x';
				break;
			case SDLK_y :
				ch ='y';
				break;
			case SDLK_z :
				ch ='z';
				break;
			case SDLK_RETURN:
				ch='\\';
				break;
			default :
				ch='-';
				break;
			
		}
	}

	//printf ("%c\n",ch);

	return ch;

}

int validity_check( char word[], char c, int position_array[])
{
	int n=strlen(word);
	int count = 0;
	int j=0;
	for (int i=0;i<n;i++)
	{
		if (word[i]==c)
		{
			position_array[j]=i;
			count ++;
			j++;
		}
	}
	return count;
}



void logic()
{
    srand(time(0));
	FILE *fil;
	fil=fopen("words","r");
	if (fil==NULL)
	{
		printf("Failed\n");
	}
	int word_count;

	fscanf(fil,"%d",&word_count);

	char words[word_count+5][100];

	for (int i=0;i<word_count;i++)
	{
		fscanf(fil,"%s",words[i]);
	}
  //  printf("%d",word_count);

	int word_pos = rand()%word_count;

    int dash_number = strlen(words[word_pos]);

    SDL_Texture *dashtex = NULL;


    SDL_Rect dash[dash_number] ;
    // surface = IMG_Load("underscor_.png");
	// dashtex = SDL_CreateTextureFromSurface(renderer,surface);
	// SDL_FreeSurface(surface);
	// SDL_QueryTexture(dashtex,NULL,NULL,&dash[0].w,&dash[0].h);
	TTF_Init();
	TTF_Font *font = TTF_OpenFont("montserrat/Montserrat-Medium.otf",20);
	
	surface = TTF_RenderText_Solid(font,"_",{0,0,0});

    SDL_Texture *under_score = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
	int dash_x_pos = 30;
	int dash_width =  20;
    for (int i=0;i<dash_number;i++)
    {
        dash[i].w = dash_width;
        dash[i].h = (int) 30;
        dash[i].x = dash_x_pos;
		dash_x_pos += 23;
        dash[i].y = 80 ;
        // SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,under_score,NULL,&dash[i]);
         //SDL_RenderPresent(renderer);
    }
	bool cls = false;
	//SDL_Event c; 
	
	 SDL_RenderPresent(renderer);
	//if(SDL_PollEvent(&c)){

		
			// if(c.type==SDL_KEYUP)
			// {
			// 	switch (c.key.keysym.sym)
			// 	{
			// 	case SDLK_a:
			// 	{
			// 		SDL_RenderPresent(renderer); 
			// 		printf("hello\n");
			// 		cls = true;
			// 		break;
			// 	}
			// 	}	
			// 	//SDL_Quit();
			// 	//SDL_DestroyWindow(window);
			// }

			// if (sdltocharacter(c)=='a')
			// 	SDL_RenderPresent(renderer);


	//}
	

	int character_count = 0;
	int correct_ch_count = 0;
	int position_array[dash_number];
	for (int i=0;i<dash_number;i++)
	{
		printf ("%c",words[word_pos][i]);
	}

	printf ("\n");
	//string s;
	
	while (character_count <=dash_number )
	{
		 if (SDL_PollEvent(&c)!=0 && c.type!=SDLK_RETURN)
		{
			
			if(c.type==SDL_QUIT)
			{
				quit =0;
				break;
			}

			if (c.type==SDL_KEYUP){
				
			
			char ch = sdltocharacter(c);
			if (ch=='\\')
				break;
			//s=ch;
			surface = TTF_RenderText_Solid(font,&ch,{0,0,0});
			SDL_Texture *chf = SDL_CreateTextureFromSurface(renderer,surface);
    		SDL_FreeSurface(surface);
			//string cf=ch;
			// int position_array[dash_number];
			memset(position_array,-1,sizeof position_array);
			if (validity_check(words[word_pos],ch,position_array))
			{
				//printf("YEs\n");
				for (int i=0;i<dash_number;i++)
				{
					if (position_array[i]!=-1)
					{
						// surface = TTF_RenderText_Solid(font,&ch,{0,0,0});
						// SDL_Texture *chf = SDL_CreateTextureFromSurface(renderer,surface);
    					// SDL_FreeSurface(surface);
						SDL_RenderCopy(renderer,chf,NULL,&dash[position_array[i]]);
						//character_count ++;
						correct_ch_count++;
					}
				}
				//correct_ch_count++;
				// SDL_RenderPresent(renderer);
			}
			character_count ++;
			SDL_RenderCopy(renderer,tex[character_count%7],NULL,&dest[character_count%7]);
			
			 SDL_RenderPresent(renderer);
			}
			//SDL_RenderCopy(renderer,tex[character_count],NULL,&dest[character_count]);
			 //SDL_RenderPresent(renderer);
			
		}
		
		
	}

	cout<<correct_ch_count<<" "<<character_count<<endl;
	if (correct_ch_count==dash_number)
		{
			printf ("Yes\n");
		}
	else
		printf ("No\n");
	quit=0;
	// SDL_RenderPresent(renderer);

	//printf("abc");
	//SDL_RenderPresent(renderer);

	
	
	// SDL_RenderPresent(renderer); 
 
   // SDL_RenderClear(renderer);
    //     SDL_RenderCopy(renderer,dashtex[i],NULL,&dash[i]);
    //     SDL_RenderPresent(renderer);

    return ;

}
