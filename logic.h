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
	// if (character.type == SDL_KEYUP)
	// {
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
	//}

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

bool next_step()
{

	// SDL_Event mouse;
	int x,y;
	while (game)
	{
		SDL_PollEvent(&mouse);
		if(mouse.type==SDL_QUIT)
		{
			game = 0;
			return 0;
		}
		if (mouse.type==SDL_MOUSEMOTION)
		{
			
			SDL_GetMouseState(&x,&y);
			//cout<<x<<" "<<y<<endl;
		}
			if (SDL_MOUSEBUTTONUP==mouse.type)
			{
				if (SDL_BUTTON_LEFT==mouse.button.button){
				
				//return 1;
				if (x>=300 && x<=(300+400) && y<=(500+100) && y>=500)
				{
					cout<<"g\n";
					return 1;
				}
				}
			}
		}
	
	return 0;

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
	
	int character_count = 0;
	int correct_ch_count = 0;
	int position_array[dash_number];
	int life_count = 1 ;


	char ager_char = '9';

	bool flag = 1;
	for (int i=0;i<dash_number;i++)
	{
		printf ("%c",words[word_pos][i]);
	}

	printf ("\n");
	//string s;
	bool q=1;
	
	while (q)
	{    //character_count <=dash_number
		if (SDL_PollEvent(&c)!=0){
		if(c.type==SDL_QUIT )
			{
				
				q=0;
				game = 0;
				break;
				
			}
		else if (c.type==SDL_KEYUP)
		{
		 if (life_count<5)
		{
			
			char ch = sdltocharacter(c);
			if (ch==ager_char)
			{
				flag = 0;
			}
			else
			{
				ager_char = ch;
				flag = 1;
			}
			if (ch=='\\')
				break;
			//s=ch;
			cout<<ch<<endl;
			surface = TTF_RenderText_Solid(font,&ch,{0,0,0});
			SDL_Texture *chf = SDL_CreateTextureFromSurface(renderer,surface);
    		SDL_FreeSurface(surface);
			//string cf=ch;
			// int position_array[dash_number];
			memset(position_array,-1,sizeof position_array);
			if (validity_check(words[word_pos],ch,position_array))
			{
				//printf("YEs\n");
				if (flag){
				for (int i=0;i<dash_number;i++)
				{
					if (position_array[i]!=-1)
					{
						
						SDL_RenderCopy(renderer,chf,NULL,&dash[position_array[i]]);
						
						correct_ch_count++;
					}
				}
				}
				
			}
			//character_count ++;
			else{
			life_count++;
			}
			SDL_RenderCopy(renderer,tex[life_count],NULL,&dest[life_count]);
			
			 SDL_RenderPresent(renderer);
			}
			//SDL_RenderCopy(renderer,tex[character_count],NULL,&dest[character_count]);
			 //SDL_RenderPresent(renderer);
			else
			{
				q=0;
			}
		
		
		}
	}
	
	}
    cout<<correct_ch_count<<" "<<character_count<<endl;

	if (correct_ch_count==dash_number)
	{
		printf ("Yes\n");
	   	
					
	}
	else
		printf ("No\n");
	SDL_RenderCopy(renderer,Next_round,NULL,&next_round);
    SDL_RenderPresent(renderer);
	
	
	//goto hell;
    return ;

}
