#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;


struct grid3x3{
    int x0, x1, x2;
    int y0, y1, y2;
    grid3x3 (int _x0, int _x1, int _x2, int _y0, int _y1, int _y2){
        x0 = _x0;
        y0 = _y0;
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
};


void draw_O (SDL_Renderer* renderer, int x, int y);

void draw_X (SDL_Renderer* renderer, int x, int y);

void draw(SDL_Renderer* renderer, int x, int y, int a[3][3], grid3x3 _3x3grid, int turn);

int _check(int a[3][3]);

void _printf(int a[3][3]);

bool turn_of_player (SDL_Renderer* renderer, int a[3][3], int &x, int &y, grid3x3 _3x3grid);

bool turn_of_player_2 (SDL_Renderer* renderer, int a[3][3], int &x, int &y, grid3x3 _3x3grid);

void turn_of_bot (int a[3][3]);

void present_game_result (SDL_Renderer* renderer, int _result);
