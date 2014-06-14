#include "CoreDialog.h"
#include <iostream>


CCoreDialog::CCoreDialog()
{
}

string CCoreDialog::promt(string windowCaption, string message)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		system("pause");
		exit(1);
	}
	if (TTF_Init() < 0)
	{
		system("pause");
		exit(1);
	}
	SDL_Window* window = SDL_CreateWindow(windowCaption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 200, NULL);
	if (window == NULL)
	{
		system("pause");
		exit(1);
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Event ev;
	if (renderer == NULL)
	{
		system("pause");
		exit(1);
	}
	TTF_Font* font=TTF_OpenFont("arial.ttf", 50);
	SDL_Surface* renderSurface;
	SDL_Texture* renderTexture;
	SDL_Rect PosSize;
	//BackgroundSize
	PosSize.h = 200;
	PosSize.w = 400;
	PosSize.x = 0;
	PosSize.y = 0;
	renderSurface = SDL_LoadBMP("bg.bmp");
	renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
	SDL_FreeSurface(renderSurface);
	SDL_RenderCopy(renderer, renderTexture, NULL, &PosSize);
	//TextColor
	SDL_Color MyCol;
	MyCol.b = 0;
	MyCol.r = 1;
	MyCol.g = 0;
	//TextSize
	PosSize.h = 50;
	PosSize.w = 200;
	PosSize.x = 1;
	PosSize.y = 1;
	
	renderSurface = TTF_RenderText_Blended(font, message.c_str(), MyCol);
	renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
	SDL_FreeSurface(renderSurface);
	SDL_RenderCopy(renderer, renderTexture, NULL, &PosSize);
	SDL_RenderPresent(renderer);
	//Ausgabe des Keys
	PosSize.h = 50;
	PosSize.w = 100;
	PosSize.x = 1;
	PosSize.y = 125;
	bool quitEvent = false;
	string tmp = "";
	while (!quitEvent)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_KEYDOWN)
			{
				if (ev.key.keysym.scancode == 40)
				{
					quitEvent = true;
				}
				else
				{
					SDL_RenderClear(renderer);
					tmp += ev.key.keysym.sym;
					renderSurface = SDL_LoadBMP("bg.bmp");
					renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
					SDL_FreeSurface(renderSurface);
					SDL_RenderCopy(renderer, renderTexture, NULL, &PosSize);
					renderSurface = TTF_RenderText_Blended(font, tmp.c_str(), MyCol);
					renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
					SDL_FreeSurface(renderSurface);
					SDL_RenderCopy(renderer, renderTexture, NULL, &PosSize);
					PosSize.w += 51;
					SDL_RenderPresent(renderer);
				}
			}
		}
	}

	//Muss noch gebessert werden, muss vernünftig terminiert werden
	SDL_DestroyWindow(window);

	return tmp;
}

CCoreDialog::~CCoreDialog()
{
}
