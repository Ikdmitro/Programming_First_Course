// App19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SDL.h>
#include <cstdio>
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 400;
int main(int argc, char* args[])
{	
	setlocale(LC_ALL, "Russian");
	SDL_Rect dest;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* myImage = SDL_LoadBMP("11.bmp");
	int imageWidth = myImage->w;
	int imageHeigth = myImage->h;
    dest.x = (SCREEN_WIDTH - imageWidth)/2;
    dest.y = (SCREEN_HEIGHT - imageHeigth)/2;
	if (myImage == NULL)
	{
		printf_s("Ошибка загрузки изображения");
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf_s("SDL не смог запуститься! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{		
		window = SDL_CreateWindow("Korneev", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf_s("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 52, 143, 0));
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_BlitSurface(myImage, NULL, screenSurface, &dest);
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
