#include<time.h>
#include<stdlib.h>
#include "initializer.h"
int strlen(char word[])
{
	int char_count=0;
	while (word[char_count])
	{
		char_count++;
	}

	return char_count;
}


int validity_check( char word[], char c)
{
	int n=strlen(word);

	for (int i=0;i<n;i++)
	{
		if (word[i]==c)
		{
			return 1;
		}
	}
	return 0;
}

void print_word(char word[])
{
	int n=strlen(word);
	printf("      ");
	for (int i=0;i<n;i++)
	{
		printf("%c",word[i]);
	}

	printf("\n");
	return;
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

	
    int dash_number = strlen(words[rand()%word_count]);
    SDL_Texture *dashtex = NULL;


    SDL_Rect dash[dash_number] ;
    surface = IMG_Load("underscor_.png");
	dashtex = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(dashtex,NULL,NULL,&dash[0].w,&dash[0].h);
	int dash_x_pos = 10;
	int dash_width = dash[0].w *.3;
    for (int i=0;i<dash_number;i++)
    {
        dash[i].w = dash_width;
        dash[i].h = (int) dash[0].h;
        dash[i].x = dash_x_pos;
		dash_x_pos += dash[i].w;
        dash[i].y = 10 ;
        // SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,dashtex,NULL,&dash[i]);
         //SDL_RenderPresent(renderer);
    }
	
	printf("%d\n",dash_number);
	SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    //     SDL_RenderCopy(renderer,dashtex[i],NULL,&dash[i]);
    //     SDL_RenderPresent(renderer);

    return ;

}
