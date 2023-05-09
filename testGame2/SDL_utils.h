#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, const string &WINDOW_TITLE);

void logSDLError(std::ostream& os, const std::string &msg, bool fatal);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

SDL_Texture* loadTextture(string path, SDL_Renderer* renderer);
