struct Rect
{
	int x, y, dx, dy;
	int r, g, b;
};
#include <iostream>
#include <SDL.h>
#include <ctime>
#include <malloc.h>
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;

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

	moveRhombus(renderer);
	//labyrinth(renderer);
	//appearanceCircles(renderer);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

