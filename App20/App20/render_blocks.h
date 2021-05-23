void renderHome(SDL_Renderer* renderer) {
	renderLine(renderer, 100, 100, 125, 60);
	renderLine(renderer, 125, 60, 150, 100);
	SDL_Rect rect = { 100, 100, 50, 50 };
	renderRect(renderer, rect);
	rect.w = 20;
	rect.h = 30;
	rect.x = 115;
	rect.y = 120;
	renderRect(renderer, rect);
}
void renderParallelepiped(SDL_Renderer* renderer) {
	SDL_Rect rect = { 100, 300, 100, 50 };
	renderRect(renderer, rect);
	rect.x = 125;
	rect.y = 275;
	renderRect(renderer, rect);
	renderLine(renderer, 100, 300, 125, 275);
	renderLine(renderer, 200, 300, 225, 275);
	renderLine(renderer, 200, 350, 225, 325);
	renderLine(renderer, 100, 350, 125, 325);
}
void renderSymbol(SDL_Renderer* renderer) {
	SDL_Rect rect = { 390, 100, 70, 100 };
	renderRect(renderer, rect);
	renderLine(renderer, 375, 200, 475, 200);
	renderLine(renderer,375,200,375,220);
	renderLine(renderer, 475, 200, 475, 220);
}
void renderEnvelope(SDL_Renderer* renderer) {
	SDL_Rect rect = { 500, 100, 100, 40 };
	renderRect(renderer, rect);
	renderLine(renderer, 500, 100, 550, 120);
	renderLine(renderer, 550, 120, 600, 100);
}
void renderShip(SDL_Renderer* renderer) {
	//Отрисовка корпуса
	renderLine(renderer, 500, 250, 600, 250);
	renderLine(renderer, 500, 250, 525, 270);
	renderLine(renderer, 525, 270, 575, 270);
	renderLine(renderer, 575, 270, 600, 250);

	//Отрисовка флажка
	renderLine(renderer, 550, 250, 550, 200);
	renderLine(renderer, 550, 200, 570, 210);
	renderLine(renderer, 550, 220, 570, 210);
} 
void renderField(SDL_Renderer* renderer) {
	SDL_Rect rect;
	rect.w = 15;
	rect.h = 15;
	rect.x = 485;
	for (int i = 0; i < 8; i++) {
		rect.y = 385;
		rect.x += 15;
		for (int j = 0; j < 8; j++) {
			rect.y += 15;
			if ((i+j)%2 == 0) {
				renderFillRect(renderer,rect);
			} 
			else {
				renderRect(renderer,rect);
			}
		}
	}
}
void renderSky(SDL_Renderer* renderer) {
	srand(time(NULL));
	SDL_Rect rect = {100,400,200,100};
	setRenderColor(renderer, 63, 72, 204, 1);
	renderFillRect(renderer,rect);
	setRenderColor(renderer, 255, 255, 255, 1);
	int x = 100;
	int y = 400;
	int posX, posY;
	for (int i = 0; i < 20000; i+=100) {
		posX = x + rand() % 201;
		posY = y + rand() % 101;
		renderPoint(renderer,posX,posY);
	}
	setRenderColor(renderer, 0, 0, 0, 1);
}

void renderBands(SDL_Renderer* renderer) {
	SDL_Rect rect = { 300,550,150,150 };
	renderRect(renderer, rect);
	int x = 300;
	int y = 400;
	rect.w = 15;
	rect.h = 150;
	int posX, posY;
	for (int i = 0; i < 10; i++) {
		if (!(i % 2)) {
			renderRect(renderer, rect);
		}
		else {
			renderFillRect(renderer, rect);
		}
		rect.x += 15;
	}
	setRenderColor(renderer, 0, 0, 0, 1);
}