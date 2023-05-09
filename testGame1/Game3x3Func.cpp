#ifndef GAME_3x3__H
#define GAME_3x3__H


#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Game3x3Func.h"
using namespace std;

const int RECT_SIZE = 71;
const int step = 78;
// Toa do phan tu a[0][0]
int x0 = 186;
int y0 = 126;
void draw_O (SDL_Renderer* renderer, int x, int y){
    SDL_Texture* O_character = loadTextture("O_character.png", renderer);
    SDL_Rect O_characterRect;
    SDL_QueryTexture(O_character, NULL, NULL, &O_characterRect.w, &O_characterRect.h);
    O_characterRect.x = x;
    O_characterRect.y = y;
    O_characterRect.w = RECT_SIZE;
    O_characterRect.h = RECT_SIZE;
    SDL_RenderCopy( renderer, O_character, NULL, &O_characterRect);

    SDL_DestroyTexture(O_character);
    O_character = NULL;
}

void draw_X (SDL_Renderer* renderer, int x, int y){
    SDL_Texture* X_character = loadTextture("X_character.png", renderer);
    SDL_Rect X_characterRect;
    SDL_QueryTexture(X_character, NULL, NULL, &X_characterRect.w, &X_characterRect.h);
    X_characterRect.x = x;
    X_characterRect.y = y;
    X_characterRect.w = RECT_SIZE;
    X_characterRect.h = RECT_SIZE;
    SDL_RenderCopy( renderer, X_character, NULL, &X_characterRect);

    SDL_DestroyTexture(X_character);
    X_character = NULL;
}

void draw(SDL_Renderer* renderer, int x, int y, int a[3][3], grid3x3 _3x3grid, int turn){

    SDL_Texture* background = loadTextture("3x3grid.png", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    // Duyet cac gia tri trong ma tran va ve ra
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            int _x, _y;
            if (i == 0) _y = _3x3grid.y0;
            else if (i == 1) _y = _3x3grid.y1;
            else if (i == 2) _y = _3x3grid.y2;

            if (j == 0) _x = _3x3grid.x0;
            else if (j == 1) _x = _3x3grid.x1;
            else if (j == 2) _x = _3x3grid.x2;

            if (a[i][j] == 1) draw_X(renderer, _x, _y);
            else if (a[i][j] == 2) draw_O(renderer, _x, _y);
        }
    }


//    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    SDL_RenderClear(renderer); // Đổ màu cả màn hình

//    SDL_Rect rect;
//    rect.x = x;
//    rect.y = y;
//    rect.w = RECT_SIZE;
//    rect.h = RECT_SIZE;

//    SDL_SetRenderDrawColor(renderer, 0, 255, 210, 255); // chọn màu cho renderer
//    SDL_RenderDrawRect(renderer, &rect);
//    SDL_RenderPresent(renderer);

    // Dieu khien X_character
    if (turn == 1)draw_X(renderer, x, y); // Luot danh cua X
    // Dieu khien O_charater
    if (turn == 2)draw_O(renderer, x, y); // Luot danh cua O

    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(background);
    background = NULL;
}

int _check(int a[3][3]){
    // Kiem tra cac hang
    if (a[0][0] == 1 && a[0][1] == 1 && a[0][2] == 1) return 1;
    else if (a[0][0] == 2 && a[0][1] == 2 && a[0][2] == 2) return 2;

    else if (a[1][0] == 1 && a[1][1] == 1 && a[1][2] == 1) return 1;
    else if (a[1][0] == 2 && a[1][1] == 2 && a[1][2] == 2) return 2;

    else if (a[2][0] == 1 && a[2][1] == 1 && a[2][2] == 1) return 1;
    else if (a[2][0] == 2 && a[2][1] == 2 && a[2][2] == 2) return 2;
    // Kiem tra cac cot
    if (a[0][0] == 1 && a[1][0] == 1 && a[2][0] == 1) return 1;
    else if (a[0][0] == 2 && a[1][0] == 2 && a[2][0] == 2) return 2;

    if (a[0][1] == 1 && a[1][1] == 1 && a[2][1] == 1) return 1;
    else if (a[0][1] == 2 && a[1][1] == 2 && a[2][1] == 2) return 2;

    if (a[0][2] == 1 && a[1][2] == 1 && a[2][2] == 1) return 1;
    else if (a[0][2] == 2 && a[1][2] == 2 && a[2][2] == 2) return 2;
    // Kiem tra duong cheo
    if (a[0][0] == 1 && a[1][1] == 1 && a[2][2] == 1) return 1;
    else if (a[0][0] == 2 && a[1][1] == 2 && a[2][2] == 2) return 2;

    if (a[0][2] == 1 && a[1][1] == 1 && a[2][0] == 1) return 1;
    else if (a[0][2] == 2 && a[1][1] == 2 && a[2][0] == 2) return 2;

    // Kiem tra tat ca cac o da dc danh chua
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (a[i][j] == 0) return false;
        }
    }

    return 3; // Hòa
}

void _printf(int a[3][3]){
    cout << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool turn_of_player (SDL_Renderer* renderer, int a[3][3], int &x, int &y, grid3x3 _3x3grid){

    int turn = 1; // Luot cua X
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) == 0 ) SDL_Delay(10);
        else if (e.type == SDL_QUIT) return true;

        // Gioi han khoang tao hieu ung cua chuot
        for (int i = 0; i <= 2; i++){
                for (int j = 0; j <= 2; j++){
                   if (x0 + j*step < e.button.x  && e.button.x < x0 + j*step + RECT_SIZE
                        && y0 + i*step < e.button.y  && e.button.y < y0 + i*step + RECT_SIZE)
                 {
                    x = x0 + j*step;
                    y = y0 + i*step;
                 }
            }
        }

        if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT){
                cout << "mouse coordinates  " << e.button.x << " " << e.button.y << endl;

                // Gioi han khoang click button cua chuot la
                for (int i = 0; i <= 2; i++){
                    for (int j = 0; j <= 2; j++){
                       if (x0 + j*step < e.button.x  && e.button.x < x0 + j*step + RECT_SIZE
                            && y0 + i*step < e.button.y  && e.button.y < y0 + i*step + RECT_SIZE){
                                 if (a[i][j] == 0) {
                                        a[i][j] = 1;
                                        return false;
                                 }
                            }
                        }
                    }
                }
            }
        draw(renderer, x, y, a, _3x3grid, turn);
    }
    return false;
}

bool turn_of_player_2 (SDL_Renderer* renderer, int a[3][3], int &x, int &y, grid3x3 _3x3grid){

    int turn = 2; // Luot cua O
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) == 0 ) SDL_Delay(10);
        else if (e.type == SDL_QUIT) return true;

        // Gioi han khoang tao hieu ung cua chuot
        for (int i = 0; i <= 2; i++){
                for (int j = 0; j <= 2; j++){
                   if (x0 + j*step < e.button.x  && e.button.x < x0 + j*step + RECT_SIZE
                        && y0 + i*step < e.button.y  && e.button.y < y0 + i*step + RECT_SIZE)
                 {
                    x = x0 + j*step;
                    y = y0 + i*step;
                 }
            }
        }

        if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT){
                cout << "mouse coordinates  " << e.button.x << " " << e.button.y << endl;

                // Gioi han khoang click button cua chuot la
                for (int i = 0; i <= 2; i++){
                    for (int j = 0; j <= 2; j++){
                       if (x0 + j*step < e.button.x  && e.button.x < x0 + j*step + RECT_SIZE
                            && y0 + i*step < e.button.y  && e.button.y < y0 + i*step + RECT_SIZE){
                                 if (a[i][j] == 0) {
                                        a[i][j] = 2;
                                        return false;
                                 }
                            }
                        }
                    }
                }
            }
        draw(renderer, x, y, a, _3x3grid, turn);
    }
    return false;
}

void turn_of_bot (int a[3][3]){
    cout << "run" << endl;

    // Kiem tra cac hang co the thang
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][0] == 2)
        {
            if (a[i][2] == 0)
            {
                a[i][2] = 2;
                cout << 5;
                return;
            }
        }
        else if (a[i][1] == a[i][2] && a[i][2] == 2)
        {
            if (a[i][0] == 0)
            {
                a[i][0] = 2;
                cout << 6;
                return;
            }
        }
        else if (a[i][0] == a[i][2] && a[i][2] == 2)
        {
            if (a[i][1] == 0)
            {
                a[i][1] = 2;
                cout << 7;
                return;
            }
        }
    }


    // Kiem tra cac cot
    for (int j = 0; j < 3; j++)
    {
        if (a[0][j] == a[1][j] && a[0][j] == 2)
        {
            if (a[2][j] == 0)
            {
                a[2][j] = 2;
                cout << 8;
                return;
            }
        }
        else if (a[1][j] == a[2][j] && a[2][j] == 2)
        {
            if (a[0][j] == 0)
            {
                a[0][j] = 2;
                cout << 9;
                return;
            }
        }
        else if (a[0][j] == a[2][j] && a[2][j] == 2)
        {
            if (a[1][j] == 0)
            {
                a[1][j] = 2;
                cout << 10;
                return;
            }
        }
    }

    // Kiem tra 2 duong cheo
    if (a[0][0] == a[1][1] && a[0][0] == 2 && a[2][2] == 0){
        a[2][2] = 2;
        cout << 11;
        return;
    }
    else if (a[0][0] == a[2][2] && a[0][0] == 2 && a[1][1] == 0){
        a[1][1] = 2;
        cout << 12;
        return;
    }
    else if (a[1][1] == a[2][2] && a[1][1] == 2 && a[0][0] == 0){
        a[0][0] = 2;
        cout << 13;
        return;
    }


    if (a[0][2] == a[1][1] && a[0][2] == 2 && a[2][0] == 0){
        a[2][0] = 2;
        return;
    }
    else if (a[0][2] == a[2][0] && a[2][0] == 2 && a[1][1] == 0){
        a[1][1] = 2;
        cout << 15;
        return;
    }
    else if (a[1][1] == a[2][0] && a[1][1] == 2 && a[0][2] == 0){
        a[0][2] = 2;
        cout << 16;
        return;
    }


    // Kiem tra cac hang co the thua
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][0] == 1)
        {
            if (a[i][2] == 0)
            {
                a[i][2] = 2;
                cout << 17;
                return;
            }
        }
        else if (a[i][1] == a[i][2] && a[i][2] == 1)
        {
            if (a[i][0] == 0)
            {
                a[i][0] = 2;
                cout << 18;
                return;
            }
        }
        else if (a[i][0] == a[i][2] && a[i][2] == 1)
        {
            if (a[i][1] == 0)
            {
                a[i][1] = 2;
                cout << 17;
                return;
            }
        }
    }


    // Kiem tra cac cot
    for (int j = 0; j < 3; j++)
    {
        if (a[0][j] == a[1][j] && a[0][j] == 1)
        {
            if (a[2][j] == 0)
            {
                a[2][j] = 2;
                cout << 18;
                return;
            }
        }
        else if (a[1][j] == a[2][j] && a[2][j] == 1)
        {
            if (a[0][j] == 0)
            {
                a[0][j] = 2;
                cout << 19;
                return;
            }
        }
        else if (a[0][j] == a[2][j] && a[2][j] == 1)
        {
            if (a[1][j] == 0)
            {
                a[1][j] = 2;
                cout << 20;
                return;
            }
        }
    }

    // Kiem tra 2 duong cheo
    if (a[0][0] == a[1][1] && a[0][0] == 1 && a[2][2] == 0){
        a[2][2] = 2;
        cout << 21;
        return;
    }
    else if (a[0][0] == a[2][2] && a[0][0] == 1 && a[1][1] == 0){
        a[1][1] = 2;
        cout << 22;
        return;
    }
    else if (a[1][1] == a[2][2] && a[1][1] == 1 && a[0][0] == 0){
        a[0][0] = 2;
        cout << 23;
        return;
    }


    if (a[0][2] == a[1][1] && a[0][2] == 1 && a[2][0] == 0){
        a[2][0] = 2;
        cout << 24;
        return;
    }
    else if (a[0][2] == a[2][0] && a[2][0] == 1 && a[1][1] == 0){
        a[1][1] = 2;
        cout << 25;
        return;
    }
    else if (a[1][1] == a[2][0] && a[1][1] == 1 && a[0][2] == 0){
        a[0][2] = 2;
        cout << 26;
        return;
    }

    // Ưu tiên đánh a[1][1] nếu chưa bị đánh
    if(a[1][1] == 0) {
        int Rand = rand() % 100 + 1; // 1->100
        // 80% đánh a[1][1]; 20% không đánh
        if (Rand <= 20){
            a[1][1] = 2;
            cout << 27;
            return;
        }
        else {
            a[1][1] = 2;
            cout << 27;
            return;
        }
    }

    // Đánh để thắng (Các hàng, cột, đường chéo có 3 ô trống hoặc chứa O)
    bool tmp1 = false, tmp2 = false, tmp3 = false, tmp4 = false;
    while(tmp1 != true || tmp2 != true || tmp3 != true || tmp4 != true){
        // Các hàng
        cout << "Run" << endl;
        int _rand = rand() % 4;
        if (_rand == 0){
            tmp1 = true;
            for (int i = 0; i < 3; i++){
                int num1 = 0, num2 = 0;
                for (int j = 0; j < 3; j++){
                    if (a[i][j] != 1) num1 += 1; // Đếm số ô khác X
                    if (a[i][j] == 0) num2 += 1; // Đếm số ô trống
                }
                if (num1 == 3 && num2 > 0){
                    while(true){
                        int Rand = rand() % 100 + 1; // 1->100
                        cout << "Rand " << Rand << endl;
                        // 20% a[i][1]; 40% a[i][0]; 40% a[i][2]
                        // Ưu tiên các ô ở góc
                        if (Rand <= 20 && a[i][1] == 0){
                            a[i][1] = 2;
                            cout << 28;
                            return;
                        }
                        if (20 < Rand && Rand <= 60 && a[i][0] == 0){
                            a[i][0] = 2;
                            cout << 28;
                            return;
                        }
                        if (60 < Rand && Rand <= 100 && a[i][2] == 0){
                            a[i][2] = 2;
                            cout << 28;
                            return;
                        }
                    }
                }
            }
        }


        // Các cột
        if (_rand == 1){
            tmp2 = true;
            for (int j = 0; j < 3; j++){
                int num1 = 0, num2 = 0;
                for (int i = 0; i < 3; i++){
                    if (a[i][j] != 1) num1 += 1; // Đếm số ô khác X
                    if (a[i][j] == 0) num2 += 1; // Đếm số ô trống
                }
                if (num1 == 3 && num2 > 0){
                    while(true){
                        int Rand = rand() % 100 + 1; // 1->100
                        cout << "Rand " << Rand << endl;
                        // 20% a[1][j]; 40% a[0][j]; 40% a[2][j]
                        // Ưu tiên các ô ở góc
                        if (Rand <= 20 && a[1][j] == 0){
                            a[1][j] = 2;
                            cout << 29;
                            return;
                        }
                        if (20 < Rand && Rand <= 60 && a[0][j] == 0){
                            a[0][j] = 2;
                            cout << 29;
                            return;
                        }
                        if (60 < Rand && Rand <= 100 && a[2][j] == 0){
                            a[2][j] = 2;
                            cout << 29;
                            return;
                        }
                    }
                }
            }
        }

        // 2 Cac duong cheo
        if (_rand == 2){
            tmp3 = true;
            if (a[0][0] != 1 && a[1][1] != 1 && a[2][2] != 1){
                if (a[0][0] == 0) {
                    a[0][0] = 2;
                    cout << 30;
                    return;
                }
                else if (a[2][2] == 0){
                    a[2][2] = 2;
                    cout << 30;
                    return;
                }
                else if (a[1][1] == 0){
                    a[1][1] = 2;
                    cout << 30;
                    return;
                }
            }
        }

        if (_rand == 3){
            tmp4 = true;
            if (a[0][2] != 1 && a[1][1] != 1 && a[2][0] != 1){
                if (a[0][2] == 0) {
                    a[0][2] = 2;
                    cout << 31;
                    return;
                }
                else if (a[1][1] == 0){
                    a[1][1] = 2;
                    cout << 31;
                    return;
                }
                else if (a[2][0] == 0){
                    a[2][0] = 2;
                    cout << 31;
                    return;
                }
            }
        }

    }

    while(true){
        int i = rand() % 3;
        int j = rand() % 3;
        if (a[i][j] == 0){
            cout << i << " " << j << " ";
            a[i][j] = 2;
            cout << 32 << endl;
            return;
        }
    }

}

void present_game_result (SDL_Renderer* renderer, int _result){
    if(_result == 1){
        SDL_Texture* X_WIN = loadTextture("X_WIN.png", renderer);
        SDL_RenderCopy( renderer, X_WIN, NULL, NULL);
        SDL_RenderPresent( renderer );

        SDL_DestroyTexture(X_WIN);
        X_WIN = NULL;
    }
    else if (_result == 2){
        SDL_Texture* O_WIN = loadTextture("O_WIN.png", renderer);
        SDL_RenderCopy( renderer, O_WIN, NULL, NULL);
        SDL_RenderPresent( renderer );

        SDL_DestroyTexture(O_WIN);
        O_WIN = NULL;
    }
    else if (_result == 3){
        SDL_Texture* _DRAW = loadTextture("_DRAW.png", renderer);
        SDL_RenderCopy( renderer, _DRAW, NULL, NULL);
        SDL_RenderPresent( renderer );

        SDL_DestroyTexture(_DRAW);
        _DRAW = NULL;
    }
}


#endif
