#include "CoreDialog.h"
#include <iostream>

#define MAX_INPUT_LENGHT 25

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
	SDL_Rect WindowTextPosSize;
	//BackgroundSize
	SDL_Rect BGSize;
	BGSize.h = 200;
	BGSize.w = 400;
	BGSize.x = 0;
	BGSize.y = 0;
	renderSurface = SDL_LoadBMP("dialog.bmp");
	if (renderSurface == NULL)
	{
		cout << "error";
	}
	renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
	SDL_FreeSurface(renderSurface);
	SDL_RenderCopy(renderer, renderTexture, NULL, &BGSize);
	//TextColor
	SDL_Color textColor = { 255, 255, 255 };
	//TextSize
	WindowTextPosSize.h = 50;
	WindowTextPosSize.w = 200;
	WindowTextPosSize.x = 1;
	WindowTextPosSize.y = 1;
	
	renderSurface = TTF_RenderText_Blended(font, message.c_str(), textColor);
	renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
	SDL_FreeSurface(renderSurface);
	SDL_RenderCopy(renderer, renderTexture, NULL, &WindowTextPosSize);
	SDL_RenderPresent(renderer);



	//Ausgabe des Keys
	PosSize.h = 20;
	PosSize.w = 10;
	PosSize.x = 75;
	PosSize.y = 110;
	bool quitEvent = false;
	string tmp = "";
	bool shiftIndicator = false;
	bool characterDelete = false;
	while (!quitEvent)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_KEYUP)
			{
				if (ev.key.keysym.scancode == 225)
				{
					//Left Shift
					shiftIndicator = false;
				}
			}
			if (ev.type == SDL_KEYDOWN)
			{
				if (ev.key.keysym.scancode == 40)
				{
					//Enter
					quitEvent = true;
				}
				if (ev.key.keysym.scancode == 42)
				{
					//backspace
					characterDelete = true;
				}
				if (ev.key.keysym.scancode == 225)
				{
					//Left Shift
					shiftIndicator = true;
				}
				else if (quitEvent==false)
				{
					SDL_RenderClear(renderer);
					char key = ev.key.keysym.sym;
					if (shiftIndicator)
					{
						key = toupper(key);
						//shiftIndicator = false;
					}
					if (characterDelete)
					{
						if (tmp.length() > 0)
						{
							tmp.pop_back();
							PosSize.w -= 20;
						}
						characterDelete = false;
					}
					else
					{
						//Limiting the lenght of the input
						if (tmp.length() < MAX_INPUT_LENGHT)
						{
							tmp += key;
						}
					}
					//Limiting the lenght of the input
					if (tmp.length() < MAX_INPUT_LENGHT)
					{
						//Rendering Background
						renderSurface = SDL_LoadBMP("dialog.bmp");
						renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
						SDL_FreeSurface(renderSurface);
						SDL_RenderCopy(renderer, renderTexture, NULL, &BGSize);
						//rendering WindowText
						renderSurface = TTF_RenderText_Blended(font, message.c_str(), textColor);
						renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
						SDL_FreeSurface(renderSurface);
						SDL_RenderCopy(renderer, renderTexture, NULL, &WindowTextPosSize);
						//Rendering user input

						renderSurface = TTF_RenderText_Blended(font, tmp.c_str(), textColor);
						renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
						SDL_FreeSurface(renderSurface);
						SDL_RenderCopy(renderer, renderTexture, NULL, &PosSize);
						PosSize.w += 10;
						SDL_RenderPresent(renderer);
					}
				}
			}
		}
	}

	SDL_DestroyWindow(window);

	return tmp;
}

CCoreDialog::~CCoreDialog()
{
}
