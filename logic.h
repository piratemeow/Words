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
    printf("%d",word_count);
    int dash_number = rand() % word_count;
    SDL_Texture *dashtex[dash_number];


    SDL_Rect dash[dash_number];
    
    for (int i=0;i<dash_number;i++)
    {
        surface = IMG_Load("underscor.png");

        dashtex[i] = SDL_CreateTextureFromSurface(renderer,surface);
        //SDL_FreeSurface(surface);

        SDL_QueryTexture(dashtex[i],NULL,NULL,&dash[i].w,&dash[i].h);

        dash[i].w=(int) dash[i].w * 1 ;
        dash[i].h = (int) dash[i].h *1;
        dash[i].x= (int) 10*i+10;
        dash[i].y = 10 ;
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,dashtex[i],NULL,&dash[i]);
        SDL_RenderPresent(renderer);
    }
    //  SDL_RenderClear(renderer);
    //     SDL_RenderCopy(renderer,dashtex[i],NULL,&dash[i]);
    //     SDL_RenderPresent(renderer);

    return ;

}
