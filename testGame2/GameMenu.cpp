#ifndef GAME_MENU__H
#define GAME_MENU__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"

using namespace std;


const int RECT_LENGTH = 374;
const int RECT_WIDE = 45;
const int step = 57;

const int x0 = 112;
const int y0 = 125;


void draw_button_frame (SDL_Renderer* renderer, int x, int y){
    SDL_Texture* background = loadTextture("GameMenu.png", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    SDL_Texture* X_character = loadTextture("ButtonFrame.png", renderer);
    SDL_Rect X_characterRect;
    SDL_QueryTexture(X_character, NULL, NULL, &X_characterRect.w, &X_characterRect.h);
    X_characterRect.x = x;
    X_characterRect.y = y;
    X_characterRect.w = RECT_LENGTH + 3;
    X_characterRect.h = RECT_WIDE + 3;
    SDL_RenderCopy( renderer, X_character, NULL, &X_characterRect);

    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(background);
    background = NULL;
    SDL_DestroyTexture(X_character);
    X_character = NULL;
}

int choose_options(SDL_Renderer* renderer, int &x, int &y){

    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) == 0 ) SDL_Delay(10);
        else if (e.type == SDL_QUIT) return 0;

        // Gioi han khoang tao hieu ung button cua chuot
        if (x0 < e.button.x  && e.button.x <  x0 + RECT_LENGTH && y0 < e.button.y  && e.button.y < y0 + RECT_WIDE){
            x = x0;
            y = y0;
        }
        else if (x0 < e.button.x  && e.button.x <  x0 + RECT_LENGTH
                 && y0 + step < e.button.y  && e.button.y < y0 + step + RECT_WIDE ){
            x = x0;
            y = y0 + step;
        }
        else if (x0 < e.button.x  && e.button.x <  x0 + RECT_LENGTH
                 && y0 + 2*step < e.button.y  && e.button.y < y0 + 2*step + RECT_WIDE ){
            x = x0;
            y = y0 + 2*step;
        }
        else if (x0 < e.button.x  && e.button.x <  x0 + RECT_LENGTH
                 && y0 + 3*step < e.button.y  && e.button.y < y0 + 3*step + RECT_WIDE ){
            x = x0;
            y = y0 + 3*step;
        }
        draw_button_frame(renderer, x, y);
        SDL_RenderPresent(renderer);
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT)
                cout << "mouse coordinates  " << e.button.x << " " << e.button.y << endl;

                // Gioi han khoang click button cua chuot la
                if (x0 < e.button.x  && e.button.x <  x0 + RECT_LENGTH
                    && y0 < e.button.y  && e.button.y < y0 + RECT_WIDE) return 1;
                if (x0 < e.button.x  && e.button.x <  x0 + RECT_LENGTH
                    && y0 + step < e.button.y  && e.button.y < y0 + step + RECT_WIDE ) return 2;
                if (x0 < e.button.x  && e.button.x <  x0 + RECT_LENGTH
                    && y0 + 2*step < e.button.y  && e.button.y < y0 + 2*step + RECT_WIDE ) return 3;
                if (x0 < e.button.x  && e.button.x <  x0 + RECT_LENGTH
                    && y0 + 3*step < e.button.y  && e.button.y < y0 + 3*step + RECT_WIDE ) return 4;
        }
    }

}

#endif
