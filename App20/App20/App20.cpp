
#include <iostream>
#include <SDL.h>
#include <ctime>
#include "SDL_functions.h"
#include "render_blocks.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 750;
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
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);

	renderHome(renderer);
	renderParallelepiped(renderer);
	renderSymbol(renderer);
	renderEnvelope(renderer);
	renderShip(renderer);
	renderField(renderer);
	renderSky(renderer);
	renderBands(renderer);

	SDL_RenderPresent(renderer);
	SDL_Delay(10000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

