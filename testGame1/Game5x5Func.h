#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

struct grid{
    int x0, x1, x2, x3, x4;
    int y0, y1, y2, y3, y4;
    grid(int _x0, int _x1, int _x2, int _x3, int _x4, int _y0, int _y1, int _y2, int _y3, int _y4){
        x0 = _x0;
        y0 = _y0;
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
        x3 = _x3;
        y3 = _y3;
        x4 = _x4;
        y4 = _y4;
    }
};

void draw_O_5x5 (SDL_Renderer* renderer, int x, int y);

void draw_X_5x5 (SDL_Renderer* renderer, int x, int y);

void draw_5x5(SDL_Renderer* renderer, int x, int y, int a[5][5], grid _5x5grid, int turn);

int _check_5x5(int a[5][5]);

bool turn_of_player_5x5 (SDL_Renderer* renderer, int a[5][5], int &x, int &y, grid _5x5grid);

bool turn_of_player_5x5_2 (SDL_Renderer* renderer, int a[5][5], int &x, int &y, grid _5x5grid);

void turn_of_bot_5x5 (int a[5][5]);

void _printf_5x5(int a[5][5]);
