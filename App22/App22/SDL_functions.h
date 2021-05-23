void renderWindow(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
	SDL_RenderClear(renderer);
}
void renderRect(SDL_Renderer* renderer, SDL_Rect rect) {
	SDL_RenderDrawRect(renderer, &rect);
}
void renderFillRect(SDL_Renderer* renderer, SDL_Rect rect) {
	SDL_RenderFillRect(renderer, &rect);
}
void renderLine(SDL_Renderer* renderer, int x1,int y1, int x2, int y2) {
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}
void renderPoint(SDL_Renderer* renderer, int x, int y) {
	SDL_RenderDrawPoint(renderer, x, y);
}
void setRenderColor(SDL_Renderer* renderer,int r, int g, int b, int alpha) {
	SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
}
void renderPoints(SDL_Renderer* renderer, SDL_Point* points, int count) {
	SDL_RenderDrawPoints(renderer, points, count);
}
void renderRects(SDL_Renderer* renderer, SDL_Rect* rects, int count) {
	SDL_RenderDrawRects(renderer, rects, count);
	}
void renderLines(SDL_Renderer* renderer, SDL_Point* points, int count){
	SDL_RenderDrawLines(renderer, points, count);
}