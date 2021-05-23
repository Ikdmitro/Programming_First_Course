// App19.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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


// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
