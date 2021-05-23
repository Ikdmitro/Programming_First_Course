void moveRhombus(SDL_Renderer* renderer) {
	srand(time(NULL));
	SDL_Event event;
	SDL_Point pointsRhombus[5] = { 0,50, 60,0, 120,50, 60,100, 0,50};
	
	setRenderColor(renderer, 255, 255, 255, 1);
	SDL_RenderClear(renderer);
	setRenderColor(renderer, 0, 0, 0, 1);
	renderLines(renderer,pointsRhombus,5);
	int r, b, g;
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	setRenderColor(renderer, r, g, b, 1);
	int x = pointsRhombus[0].x;
	int y = pointsRhombus[0].y;
	for (int i = x; i <= pointsRhombus[2].x; i++) {
		renderLine(renderer, i, y,pointsRhombus[1].x, pointsRhombus[1].y);
	}
	for (int i = x; i <= pointsRhombus[2].x; i++) {
		renderLine(renderer, i, y, pointsRhombus[3].x, pointsRhombus[3].y);
	}
	SDL_RenderPresent(renderer);
	bool quit = false;
	bool isBig = false;
	while (!quit) {
		SDL_PollEvent(&event);
		if (event.button.button == SDL_SCANCODE_ESCAPE || event.type == SDL_QUIT) quit = true;
		if (event.type == SDL_KEYDOWN) {
			setRenderColor(renderer, 255, 255, 255, 1);
			SDL_RenderClear(renderer);
			setRenderColor(renderer, 0, 0, 0, 1);
			if (event.button.button == SDL_SCANCODE_RIGHT && pointsRhombus[2].x < SCREEN_WIDTH) {
				for (int i = 0; i < 5; i++) {
					pointsRhombus[i].x++;
				}
			}
			if (event.button.button == SDL_SCANCODE_LEFT && pointsRhombus[0].x > 0) {
				for (int i = 0; i < 5; i++) {
					pointsRhombus[i].x--;
				}
			}
			if (event.button.button == SDL_SCANCODE_UP && pointsRhombus[1].y > 0) {
				for (int i = 0; i < 5; i++) {
					pointsRhombus[i].y--;
				}
			}
			if (event.button.button == SDL_SCANCODE_DOWN && pointsRhombus[3].y < SCREEN_HEIGHT) {
				for (int i = 0; i < 5; i++) {
					pointsRhombus[i].y++;
				}
			}
			if (event.button.button == SDL_SCANCODE_A) {
				r = rand() % 256;
				g = rand() % 256;
				b = rand() % 256;
			}
				setRenderColor(renderer, r, g, b, 1);
				int x = pointsRhombus[0].x;
				int y = pointsRhombus[0].y;
				for (int i = x; i <= pointsRhombus[2].x; i++) {
					renderLine(renderer, i, y, pointsRhombus[1].x, pointsRhombus[1].y);
				}
				for (int i = x; i <= pointsRhombus[2].x; i++) {
					renderLine(renderer, i, y, pointsRhombus[3].x, pointsRhombus[3].y);
				}
			renderLines(renderer, pointsRhombus, 5);
			SDL_RenderPresent(renderer);
			}
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			setRenderColor(renderer, 255, 255, 255, 1);
			SDL_RenderClear(renderer);
			setRenderColor(renderer, 0, 0, 0, 1);
			if (event.button.button == SDL_BUTTON_LEFT) {
				if (!isBig && pointsRhombus[0].x>60 && pointsRhombus[1].y > 60 && pointsRhombus[2].x < SCREEN_WIDTH - 60 && pointsRhombus[3].y < SCREEN_HEIGHT - 60) {
					isBig = true;
					pointsRhombus[0].x = pointsRhombus[4].x -= 60;
					pointsRhombus[1].y -= 50;
					pointsRhombus[2].x += 60;
					pointsRhombus[3].y += 50;
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				if (isBig) {
					isBig = false;
					pointsRhombus[0].x = pointsRhombus[4].x += 60;
					pointsRhombus[1].y += 50;
					pointsRhombus[2].x -= 60;
					pointsRhombus[3].y -= 50;
				}

			}
			setRenderColor(renderer, r, g, b, 1);
			int x = pointsRhombus[0].x;
			int y = pointsRhombus[0].y;
			for (int i = x; i <= pointsRhombus[2].x; i++) {
				renderLine(renderer, i, y, pointsRhombus[1].x, pointsRhombus[1].y);
			}
			for (int i = x; i <= pointsRhombus[2].x; i++) {
				renderLine(renderer, i, y, pointsRhombus[3].x, pointsRhombus[3].y);
			}
			renderLines(renderer, pointsRhombus, 5);
			SDL_RenderPresent(renderer);
		}
	}
}
struct circle {
	int startX, startY, radius;
};
void renderCircle(SDL_Renderer* renderer, int x0, int y0, int radius);
void appearanceCircles(SDL_Renderer *renderer) {
	srand(time(NULL));
	SDL_Event event;
	circle circles[10];
	int index = 0;
	setRenderColor(renderer, 255, 255, 255, 1);
	SDL_RenderClear(renderer);
	setRenderColor(renderer, 0, 0, 0, 1);
	bool quit = false;
	while (!quit) {
		SDL_PollEvent(&event);
		if (event.button.button == SDL_SCANCODE_ESCAPE || event.type == SDL_QUIT) quit = true;
		if (event.type == SDL_KEYDOWN && event.button.button == SDL_SCANCODE_SPACE) {
			if (index < 10) {
				bool flag;
				do {
					flag = true;
					circles[index].radius = rand() % (51) + 5;
					circles[index].startX = rand() % (SCREEN_WIDTH - circles[index].radius + 1) + circles[index].radius;
					circles[index].startY = rand() % (SCREEN_HEIGHT - circles[index].radius + 1) + circles[index].radius;
					for (int i = 0; i < index; i++) {
						if (sqrt((circles[index].startX - circles[i].startX) * (circles[index].startX - circles[i].startX) + (circles[index].startY - circles[i].startY) * (circles[index].startY -  circles[i].startY)) < circles[index].radius + circles[i].radius) {
							flag = false;
							break;
						}
					}
				} while (!flag);
				renderCircle(renderer, circles[index].startX, circles[index].startY, circles[index].radius);
				index++;
			}
			SDL_RenderPresent(renderer);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			int clickX = event.button.x;
			int clickY = event.button.y;
			bool isDel = false;
			for (int i = 0; i < index; i++) {
				if ((clickX - circles[i].startX) * (clickX - circles[i].startX) + (clickY - circles[i].startY) * (clickY - circles[i].startY) <= circles[i].radius * circles[i].radius) {
					for (int j = i; j < index - 1; j++) {
						circles[j].startX = circles[j + 1].startX;
						circles[j].startY = circles[j + 1].startY;
						circles[j].radius = circles[j + 1].radius;
					}
					isDel = true;
					break;
				}
			}
			if (isDel) {
				index--;
				setRenderColor(renderer, 255, 255, 255, 1);
				SDL_RenderClear(renderer);
				setRenderColor(renderer, 0, 0, 0, 1);
				for (int i = 0; i < index; i++) {
					renderCircle(renderer, circles[i].startX, circles[i].startY, circles[i].radius);
				}
				SDL_RenderPresent(renderer);
			}
		}
	}

}
struct pointsLabyrinth {
	int x1, x2, y1, y2;
};
void renderLabirynth(pointsLabyrinth* pointsLabyrinth, SDL_Renderer* renderer);
int checkWallLeft(pointsLabyrinth* pointsLabyrinth, SDL_Rect* rect);
int checkWallRight(pointsLabyrinth* pointsLabyrinth, SDL_Rect* rect);
int checkWallTop(pointsLabyrinth* pointsLabyrinth, SDL_Rect* rect);
int checkWallBottom(pointsLabyrinth* pointsLabyrinth, SDL_Rect* rect);

void labyrinth(SDL_Renderer* renderer) {
	SDL_Event event;
	pointsLabyrinth pointsLabyrinth[11];
	setRenderColor(renderer, 255, 255, 255, 1);
	SDL_RenderClear(renderer);
	setRenderColor(renderer, 0, 0, 0, 1);
	renderLabirynth(pointsLabyrinth, renderer);
	SDL_Rect rect = {25,25,20,20};
	renderFillRect(renderer, rect);
	SDL_RenderPresent(renderer);
	bool quit = false; 
	while (!quit) {
		SDL_PollEvent(&event);
		if (event.button.button == SDL_SCANCODE_ESCAPE || event.type == SDL_QUIT) quit = true;
		if (event.type == SDL_KEYDOWN) {
			setRenderColor(renderer, 255, 255, 255, 1);
			SDL_RenderClear(renderer);
			setRenderColor(renderer, 0, 0, 0, 1);
			for (int i = 0; i < 11; i++) {
				renderLine(renderer, pointsLabyrinth[i].x1, pointsLabyrinth[i].y1, pointsLabyrinth[i].x2, pointsLabyrinth[i].y2);
			}
			if (event.button.button == SDL_SCANCODE_RIGHT && !checkWallRight(pointsLabyrinth, &rect)) {
					rect.x++;
			}
			if (event.button.button == SDL_SCANCODE_LEFT && !checkWallLeft(pointsLabyrinth, &rect)) {
					rect.x--;
			}
			if (event.button.button == SDL_SCANCODE_UP && !checkWallTop(pointsLabyrinth, &rect)) {
					rect.y--;
			}
			if (event.button.button == SDL_SCANCODE_DOWN && !checkWallBottom(pointsLabyrinth, &rect)) {
					rect.y++;
			}
			renderFillRect(renderer, rect);
			SDL_RenderPresent(renderer);
		}
	}
}


void renderLabirynth(pointsLabyrinth *pointsLabyrinth, SDL_Renderer *renderer) {
	//Горизонтальные линии
	//1 линия
	pointsLabyrinth[0].x1 = 20;
	pointsLabyrinth[0].y1 = 20;
	pointsLabyrinth[0].x2 = 20;
	pointsLabyrinth[0].y2 = 420;
	//2 линия
	pointsLabyrinth[1].x1 = 220;
	pointsLabyrinth[1].y1 = 120;
	pointsLabyrinth[1].x2 = 220;
	pointsLabyrinth[1].y2 = 220;
	//3 линия
	pointsLabyrinth[2].x1 = 320;
	pointsLabyrinth[2].y1 = 20;
	pointsLabyrinth[2].x2 = 320;
	pointsLabyrinth[2].y2 = 120;
	//4 линия
	pointsLabyrinth[3].x1 = 420;
	pointsLabyrinth[3].y1 = 120;
	pointsLabyrinth[3].x2 = 420;
	pointsLabyrinth[3].y2 = 420;
	//5 линия
	pointsLabyrinth[4].x1 = 520;
	pointsLabyrinth[4].y1 = 20;
	pointsLabyrinth[4].x2 = 520;
	pointsLabyrinth[4].y2 = 520;
	//6 линия
	pointsLabyrinth[5].x1 = 220;
	pointsLabyrinth[5].y1 = 320;
	pointsLabyrinth[5].x2 = 220;
	pointsLabyrinth[5].y2 = 520;
	//Вертикальные линии
	//7 линия
	pointsLabyrinth[6].x1 = 20;
	pointsLabyrinth[6].y1 = 20;
	pointsLabyrinth[6].x2 = 520;
	pointsLabyrinth[6].y2 = 20;
	//8 линия
	pointsLabyrinth[7].x1 = 20;
	pointsLabyrinth[7].y1 = 220;
	pointsLabyrinth[7].x2 = 420;
	pointsLabyrinth[7].y2 = 220;
	//9 линия
	pointsLabyrinth[8].x1 = 20;
	pointsLabyrinth[8].y1 = 420;
	pointsLabyrinth[8].x2 = 120;
	pointsLabyrinth[8].y2 = 420;
	//10 линия
	pointsLabyrinth[9].x1 = 20;
	pointsLabyrinth[9].y1 = 520;
	pointsLabyrinth[9].x2 = 520;
	pointsLabyrinth[9].y2 = 520;
	//11 линия
	pointsLabyrinth[10].x1 = 20;
	pointsLabyrinth[10].y1 = 120;
	pointsLabyrinth[10].x2 = 120;
	pointsLabyrinth[10].y2 = 120;
	for (int i = 0; i < 50; i++) {
		renderLine(renderer, pointsLabyrinth[i].x1, pointsLabyrinth[i].y1, pointsLabyrinth[i].x2, pointsLabyrinth[i].y2);
	}
}
int checkWallLeft(pointsLabyrinth *pointsLabyrinth, SDL_Rect* rect) {
	for (int i = 0; i < 11;i++) {
			if (rect->x == pointsLabyrinth[i].x2 && rect->y > pointsLabyrinth[i].y1 - rect->h && rect->y+rect->h < pointsLabyrinth[i].y2 + rect->h) {
				return true;
}
	}
		return false;
}
int checkWallRight(pointsLabyrinth* pointsLabyrinth, SDL_Rect* rect) {
	for (int i = 0; i < 11; i++) {
		if (rect->x + rect->w == pointsLabyrinth[i].x1 && rect->y > pointsLabyrinth[i].y1 - rect->h && rect->y + rect->h < pointsLabyrinth[i].y2 + rect->h) {
			return true;
		}
	}
	return false;
}
int checkWallTop(pointsLabyrinth* pointsLabyrinth, SDL_Rect* rect) {
	for (int i = 0; i < 11; i++) {
		if (rect->y== pointsLabyrinth[i].y2 && rect->x > pointsLabyrinth[i].x1 - rect->h && rect->x + rect->h < pointsLabyrinth[i].x2 + rect->h) {
			return true;
		}
	}
	return false;
}
int checkWallBottom(pointsLabyrinth* pointsLabyrinth, SDL_Rect* rect) {
	for (int i = 0; i < 11; i++) {
		if (rect->y + rect->h == pointsLabyrinth[i].y1 && rect->x > pointsLabyrinth[i].x1 - rect->h && rect->x + rect->h < pointsLabyrinth[i].x2 + rect->h) {
			return true;
		}
	}
	return false;
}
void renderCircle(SDL_Renderer* renderer, int x0, int y0, int radius)
{
	double pi = 3.14;
	double pih = pi / 2.0; 
	int prec = 60; //точность
	double i = 0;    

	int x = (double)radius * cos(0);
	int y = (double)radius * sin(0);
	int x1 = x;
	int y1 = y;

	double step = pih / (double)prec; 
	for (i = step; i <= pih; i += step)
	{
		x1 = (double)radius * cos(i) + 0.5; 
		y1 = (double)radius * sin(i) + 0.5; 

		if ((x != x1) || (y != y1))
		{
			renderLine(renderer, x0 + x, y0 - y, x0 + x1, y0 - y1);
			renderLine(renderer, x0 - x, y0 - y, x0 - x1, y0 - y1);
			renderLine(renderer, x0 - x, y0 + y, x0 - x1, y0 + y1);
			renderLine(renderer, x0 + x, y0 + y, x0 + x1, y0 + y1);
		}
		x = x1;
		y = y1;
	}
	if (x != 0)
	{
		x = 0;
		renderLine(renderer, x0 + x, y0 - y, x0 + x1, y0 - y1);
		renderLine(renderer, x0 - x, y0 - y, x0 - x1, y0 - y1);
		renderLine(renderer, x0 - x, y0 + y, x0 - x1, y0 + y1);
		renderLine(renderer, x0 + x, y0 + y, x0 + x1, y0 + y1);
	}
}