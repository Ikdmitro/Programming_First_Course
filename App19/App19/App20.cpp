// App19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SDL.h>
#include <cstdio>
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
int main(int argc, char* args[])
{
	setlocale(LC_ALL, "Russian");
	SDL_Rect rect;
	rect.x = 10;
	rect.y = 30;
	rect.w = 30;
	rect.h = 50;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_SetWindowTitle(window,"Renderer");

	//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 191, 143, 0));
	SDL_RenderDrawRect(renderer, &rect);
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
	SDL_RenderPresent(renderer);
	//SDL_RenderClear(renderer);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
