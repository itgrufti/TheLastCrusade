#include "CoreDialog.h"
#include <Windows.h>
#include <iostream>
#include <irrKlang.h>
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

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
	ISoundEngine* soundEngine = createIrrKlangDevice();

	if (!soundEngine)
	{
		return 0; // error starting up the engine
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
	int mouseX = 0;
	int mouseY = 0;
	while (!quitEvent)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_MOUSEMOTION)
			{
				mouseX = ev.motion.x;
				mouseY = ev.motion.y;

			}
			//Handle mouebutton click
			if (ev.type == SDL_MOUSEBUTTONDOWN)
			{
				int x = ev.button.x; 
				int y = ev.button.y;
				if (x > 139 && x<241 && y>159 && y < 191)
				{
					quitEvent = true;
				}
			}
			//Handle keyboard
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
							PosSize.w -= 10;
						}
						characterDelete = false;
					}
					else
					{
						//Limiting the lenght of the input
						if (tmp.length() < MAX_INPUT_LENGHT)
						{
							tmp += key;
							PosSize.w += 10;
						}
					}
					//Limiting the lenght of the input
				}


				}
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
				

				if (mouseX > 139 && mouseX<241 && mouseY>159 && mouseY < 191)
				{
					SDL_Rect ButtonPos;
					ButtonPos.h = 30;
					ButtonPos.w = 100;
					ButtonPos.x = 140;
					ButtonPos.y = 160;
					renderSurface = SDL_LoadBMP("buttonHover.bmp");
					renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);
					SDL_FreeSurface(renderSurface);
					SDL_RenderCopy(renderer, renderTexture, NULL, &ButtonPos);
				}



				SDL_RenderPresent(renderer);
			}
		}
	}

	SDL_DestroyWindow(window);
	soundEngine->play2D("boing.ogg");
	Sleep(200);
	return tmp;
}

CCoreDialog::~CCoreDialog()
{
}
