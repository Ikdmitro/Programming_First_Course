
#include <iostream>
#include <SDL.h>
#include <ctime>
#include <malloc.h>
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 500;

#include "SDL_functions.h"
#include "tasks.h"
int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	setlocale(LC_ALL, "Russian");
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_SetWindowTitle(window, "Renderer");
	renderWindow(renderer);

	//rectDiagonal(renderer);
	//rectAccelerated(renderer);
    //fallingSnow(renderer);
	//snakeCrawling(renderer);
	//fallingScreen(renderer);
	pointsCircle(renderer);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

