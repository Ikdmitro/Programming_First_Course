
#include <iostream>
#include <SDL.h>
#include "SDL_functions.h"
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 500;
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

	setRenderColor(renderer, 220, 220, 220, 1);
	int startX = SCREEN_WIDTH / 2;
	int startY = SCREEN_HEIGHT / 2;
	int unitSegment =  20;
	int lineUnitSegment = unitSegment / 2;
	int x, y;
	//Ось x
	renderLine(renderer, 0, startY, SCREEN_WIDTH, startY);
	//Ось y
	renderLine(renderer, startX, 0, startX, SCREEN_HEIGHT);
	for (int i = 0; i < SCREEN_WIDTH; i++) {
		if ((startX - i) % unitSegment == 0) {
	renderLine(renderer, i, startY-lineUnitSegment/2, i, startY+ lineUnitSegment/2);
		}
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		if ((startY - i) % unitSegment == 0) {
			renderLine(renderer, startX - lineUnitSegment / 2, i, startX + lineUnitSegment / 2, i);
		}
	}
	setRenderColor(renderer, 0, 0, 0, 1);
	for (int i = startX-unitSegment*5; i < startX + unitSegment * 5; i++) {
		x = i;
		y = startY - sin((double)(x-startX) / unitSegment) * unitSegment;
		renderPoint(renderer, x, y);
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(4000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

