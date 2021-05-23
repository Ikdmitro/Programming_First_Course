void rectDiagonal(SDL_Renderer *renderer);
void rectAccelerated(SDL_Renderer *renderer);
void fallingSnow(SDL_Renderer* renderer);


void rectDiagonal(SDL_Renderer *renderer) {
	double mn;
	if (SCREEN_WIDTH > SCREEN_HEIGHT)
	{
		mn  = (double)SCREEN_WIDTH / SCREEN_HEIGHT;
	}
	else {
		mn = (double) SCREEN_HEIGHT / SCREEN_WIDTH;
	}
	SDL_Rect rect;
	rect.w = 100;
	rect.h = 50;
	int x = -rect.w;
	for (int i = 0; i <= SCREEN_WIDTH; i++) {
		setRenderColor(renderer, 255, 255, 255, 1);
		SDL_RenderClear(renderer);
		setRenderColor(renderer, 0, 0, 0, 1);
		if (SCREEN_WIDTH > SCREEN_HEIGHT) {
			rect.x = (int) i * mn;
			rect.y = (int) i;
		}
		else {
			rect.x = (int)i;
			rect.y = (int)i * mn;
		}
		renderRect(renderer, rect);
		SDL_RenderPresent(renderer);
		SDL_Delay(5);
	}
	SDL_RenderClear(renderer);
}
void rectAccelerated(SDL_Renderer* renderer) {
	int startY = SCREEN_HEIGHT/2;
	SDL_Rect rect;
	rect.w = 100;
	rect.h = 50;
	for (int i = -100; i <= SCREEN_WIDTH; i++) {
		setRenderColor(renderer, 255, 255, 255, 1);
		SDL_RenderClear(renderer);
		setRenderColor(renderer, 0, 0, 0, 1);
		rect.x = i;
		rect.y = startY;
		renderRect(renderer, rect);
		SDL_RenderPresent(renderer);
		SDL_Delay(SCREEN_WIDTH/100 - i/100);
	}
	SDL_RenderClear(renderer);
}
void fallingSnow(SDL_Renderer* renderer) {
	srand(time(NULL));
	SDL_Point points[SCREEN_WIDTH+1200];
	int argX;
	int startX, startY;
	for (int i = 0; i < SCREEN_WIDTH+1200; i++) {
		startX = rand() % (SCREEN_WIDTH + 1201) - 600;
	    startY = -(rand() % (1000 + 1));
		points[i].x = startX;
		points[i].y = startY;
	}
	for (int i = 0; i < 1000; i++) {
		setRenderColor(renderer, 255, 255, 255, 1);
		SDL_RenderClear(renderer);
		for (int j = 0; j < SCREEN_WIDTH+1000; j++) {
			argX = rand() % 4 - 2;
			points[j].y++;
			points[j].x+=argX;
			if (points[j].y >= SCREEN_HEIGHT+50 || points[j].x <=-1000 || points[j].x >= SCREEN_WIDTH + 1000) {
				startX = rand() % (SCREEN_WIDTH + 1201) - 600;
				startY = -(rand() % (1000 + 1));
				points[j].x = startX;
				points[j].y = startY;
			}
		}
		
		setRenderColor(renderer, 0, 0, 0, 1);
		renderPoints(renderer, points, SCREEN_WIDTH);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	SDL_RenderClear(renderer);
}
void fallingScreen(SDL_Renderer* renderer) {
	setRenderColor(renderer, 255, 255, 255, 1);
	SDL_RenderClear(renderer);
	setRenderColor(renderer, 0, 0, 0, 1);
	for (int i = 0; i < SCREEN_HEIGHT + 10; i++) {
		renderLine(renderer, 0, i, SCREEN_WIDTH, i);
		SDL_RenderPresent(renderer);
		SDL_Delay(SCREEN_HEIGHT / 100 - i /100);
	}
}
void snakeCrawling(SDL_Renderer* renderer) {
	SDL_Point points[1000];
	int unitSegment = 40;
	int lengthSnake = 400;
	int startY = SCREEN_HEIGHT / 2;
	for (int i = -1; i < SCREEN_WIDTH + lengthSnake; i++) {
		setRenderColor(renderer, 255, 255, 255, 1);
		SDL_RenderClear(renderer);
		setRenderColor(renderer, 0, 0, 0, 1);
		for (int j = 0; j < lengthSnake; j++) {
			points[j].x = points[j + 1].x;
			points[j].y = points[j + 1].y;
		}
		points[lengthSnake-1].x = i;
		points[lengthSnake-1].y = (double)abs(sin((double)points[lengthSnake - 1].x / unitSegment*2) * unitSegment - startY);
		renderLines(renderer, points,lengthSnake);

		//Head
		renderLine(renderer, points[lengthSnake - 1].x, points[lengthSnake - 1].y, points[lengthSnake - 1].x + 30, points[lengthSnake - 1].y);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
		SDL_RenderClear(renderer);
	}
	SDL_RenderClear(renderer);
}
void renderCircle(SDL_Renderer* renderer, int x0, int y0, int radius);
void pointsCircle(SDL_Renderer* renderer) {
	srand(time(NULL));
	SDL_Point points[3];
	SDL_Rect circlePoints[3];
	int argPoints[3];
	int startX = SCREEN_WIDTH / 2;
	int startY = SCREEN_HEIGHT / 2;
	float x, y;
	int radius = 150;
	for (int i = 0; i < 3; i++) {
		points[i].x = (int) i*200;
		points[i].y = (int) i*200;
		argPoints[i] = rand () % 10 - 5;
		circlePoints[i].w = circlePoints[i].h =  10;

	}
	for (int i = 0; i < 500; i++) {
		setRenderColor(renderer, 255, 255, 255, 1);
		SDL_RenderClear(renderer);
			for (int j = 0; j < 3; j++) {
				points[j].x+= argPoints[j];
				points[j].y+= argPoints[j];

				circlePoints[j].x = (int) (radius * (double)cos(3.14/180*points[j].x) + startX - 5);
				circlePoints[j].y = (int) (radius * (double)sin(3.14/180*points[j].y) + startY - 5);
				printf_s("%d %d %d %d \n", points[j].x, points[j].y, circlePoints[j].x, circlePoints[j].y);
			}
		setRenderColor(renderer, 0, 0, 0, 1);
		renderCircle(renderer, startX, startY, radius);
		renderRects(renderer, circlePoints, 3);
		SDL_RenderPresent(renderer);
		SDL_Delay(20);
	}
	SDL_RenderClear(renderer);
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