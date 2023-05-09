#ifndef GAME_5x5__H
#define GAME_5x5__H


#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Game5x5Func.h"
using namespace std;
const int RECT_SIZE = 65;
const int step = 69;
// Toa do phan tu a[0][0]
int x0_5x5 = 131;
int y0_5x5 = 69;

void draw_O_5x5 (SDL_Renderer* renderer, int x, int y){
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

void draw_X_5x5 (SDL_Renderer* renderer, int x, int y){
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

void draw_5x5(SDL_Renderer* renderer, int x, int y, int a[5][5], grid _5x5grid, int turn){

    SDL_Texture* background = loadTextture("5x5grid.png", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    // Duyet tat ca cac phan tu cua ma tran va ve ra
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            int x, y;
            if (i == 0) y = _5x5grid.y0;
            else if (i == 1) y = _5x5grid.y1;
            else if (i == 2) y = _5x5grid.y2;
            else if (i == 3) y = _5x5grid.y3;
            else if (i == 4) y = _5x5grid.y4;

            if (j == 0) x = _5x5grid.x0;
            else if (j == 1) x = _5x5grid.x1;
            else if (j == 2) x = _5x5grid.x2;
            else if (j == 3) x = _5x5grid.x3;
            else if (j == 4) x = _5x5grid.x4;

            if (a[i][j] == 1) draw_X_5x5(renderer, x, y);
            else if (a[i][j] == 2) draw_O_5x5(renderer, x, y);
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
    if (turn == 1) draw_X_5x5(renderer, x, y); // Luot cua X
    // Dieu khien O_character
    if (turn == 2) draw_O_5x5(renderer, x, y); // Luot cua O
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(background);
    background = NULL;
}

int _check_5x5(int a[5][5]){
    // Kiem tra cac hang
    for (int i = 0; i < 5; i++){
        if (a[i][0] == 1 && a[i][1] == 1 && a[i][2] == 1 && a[i][3] == 1) return 1;
        else if (a[i][1] == 1 && a[i][2] == 1 && a[i][3] == 1 && a[i][4] == 1) return 1;
        else if (a[i][0] == 2 && a[i][1] == 2 && a[i][2] == 2 && a[i][3] == 2) return 2;
        else if (a[i][1] == 2 && a[i][2] == 2 && a[i][3] == 2 && a[i][4] == 2) return 2;
    }
    // Kiem tra cac cot
    for (int j = 0; j < 5; j++){
        if (a[0][j] == 1 && a[1][j] == 1 && a[2][j] == 1 &&a[3][j] == 1) return 1;
        else if (a[1][j] == 1 && a[2][j] == 1 &&a[3][j] == 1 && a[4][j] == 1) return 1;
        else if (a[0][j] == 2 && a[1][j] == 2 && a[2][j] == 2 &&a[3][j] == 2) return 2;
        else if (a[1][j] == 2 && a[2][j] == 2 &&a[3][j] == 2 && a[4][j] == 2) return 2;
    }
    // Kiem tra duong cheo
    if(a[0][3] == 1 && a[1][2] == 1 && a[2][1] == 1 && a[3][0] == 1) return 1;
    else if (a[0][3] == 2 && a[1][2] == 2 && a[2][1] == 2 && a[3][0] == 2) return 2;

    if (a[0][4] == 1 && a[1][3] == 1 && a[2][2] == 1 && a[3][1] == 1) return 1;
    else if (a[0][4] == 2 && a[1][3] == 2 && a[2][2] == 2 && a[3][1] == 2) return 2;

    if (a[1][3] == 1 && a[2][2] == 1 && a[3][1] == 1 && a[4][0] == 1) return 1;
    else if (a[1][3] == 2 && a[2][2] == 2 && a[3][1] == 2 && a[4][0] == 2) return 2;

    if (a[1][4] == 1 && a[2][3] == 1 && a[3][2] == 1 && a[4][1] == 1) return 1;
    else if (a[1][4] == 2 && a[2][3] == 2 && a[3][2] == 2 && a[4][1] == 2) return 2;

    if (a[0][1] == 1 && a[1][2] == 1 && a[2][3] == 1 && a[3][4] == 1) return 1;
    else if (a[0][1] == 2 && a[1][2] == 2 && a[2][3] == 2 && a[3][4] == 2) return 2;

    if (a[0][0] == 1 && a[1][1] == 1 && a[2][2] == 1 && a[3][3] == 1) return 1;
    else if (a[0][0] == 2 && a[1][1] == 2 && a[2][2] == 2 && a[3][3] == 2) return 2;

    if (a[1][1] == 1 && a[2][2] == 1 && a[3][3] == 1 && a[4][4] == 1) return 1;
    else if (a[1][1] == 2 && a[2][2] == 2 && a[3][3] == 2 && a[4][4] == 2) return 2;

    if (a[1][0] == 1 && a[2][1] == 1 && a[3][2] == 1 && a[4][3] == 1) return 1;
    else if (a[1][0] == 2 && a[2][1] == 2 && a[3][2] == 2 && a[4][3] == 2) return 2;
    // Kiem tra tat ca cac o da dc danh chua
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (a[i][j] == 0) return false;
        }
    }

    return 3; // Hòa
}

void _printf_5x5(int a[5][5]){
    cout << endl;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool turn_of_player_5x5 (SDL_Renderer* renderer, int a[5][5], int &x, int &y, grid _5x5grid){

    int turn = 1; // Luot cua X
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) == 0 ) SDL_Delay(10);
        else if (e.type == SDL_QUIT) return true;

        // Gioi han khoang tao hieu ung cua chuot
        for (int i = 0; i <= 4; i++){
                for (int j = 0; j <= 4; j++){
                   if (x0_5x5 + j*step < e.button.x  && e.button.x < x0_5x5 + j*step + RECT_SIZE
                        && y0_5x5 + i*step < e.button.y  && e.button.y < y0_5x5 + i*step + RECT_SIZE)
                 {
                    x = x0_5x5 + j*step;
                    y = y0_5x5 + i*step;
                 }
            }
        }

        if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT){
                cout << "mouse coordinates  " << e.button.x << " " << e.button.y << endl;

                // Gioi han khoang click button cua chuot la
                for (int i = 0; i <= 4; i++){
                    for (int j = 0; j <= 4; j++){
                       if (x0_5x5 + j*step < e.button.x  && e.button.x < x0_5x5 + j*step + RECT_SIZE
                            && y0_5x5 + i*step < e.button.y  && e.button.y < y0_5x5 + i*step + RECT_SIZE){
                                 if (a[i][j] == 0) {
                                        a[i][j] = 1;
                                        cout << "a" << i << j << endl;
                                        return false;
                                 }
                            }
                        }
                    }
                }
            }
        draw_5x5(renderer, x, y, a, _5x5grid, turn);
    }
    return false;
}

bool turn_of_player_5x5_2 (SDL_Renderer* renderer, int a[5][5], int &x, int &y, grid _5x5grid){

    int turn = 2; // Luot cua O
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) == 0 ) SDL_Delay(10);
        else if (e.type == SDL_QUIT) return true;

        // Gioi han khoang tao hieu ung cua chuot
        for (int i = 0; i <= 4; i++){
                for (int j = 0; j <= 4; j++){
                   if (x0_5x5 + j*step < e.button.x  && e.button.x < x0_5x5 + j*step + RECT_SIZE
                        && y0_5x5 + i*step < e.button.y  && e.button.y < y0_5x5 + i*step + RECT_SIZE)
                 {
                    x = x0_5x5 + j*step;
                    y = y0_5x5 + i*step;
                 }
            }
        }

        if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT){
                cout << "mouse coordinates  " << e.button.x << " " << e.button.y << endl;

                // Gioi han khoang click button cua chuot la
                for (int i = 0; i <= 4; i++){
                    for (int j = 0; j <= 4; j++){
                       if (x0_5x5 + j*step < e.button.x  && e.button.x < x0_5x5 + j*step + RECT_SIZE
                            && y0_5x5 + i*step < e.button.y  && e.button.y < y0_5x5 + i*step + RECT_SIZE){
                                 if (a[i][j] == 0) {
                                        a[i][j] = 2;
                                        return false;
                                 }
                            }
                        }
                    }
                }
            }
        draw_5x5(renderer, x, y, a, _5x5grid, turn);
    }
    return false;
}

void turn_of_bot_5x5 (int a[5][5]){
    // I. Kiem cac TH co the thang
    // 1. Kiem tra cac hang co the thang
    // a. Cac hang tu phan tu 0->3
    for (int i = 0; i < 5; i++){
        int num = 0; // So luong phan tu O trong hang
        for (int j = 0; j < 4; j++){
            if (a[i][j] == 2) num += 1;
        }
        if (num == 3) { // Neu so luong O la 3 thi ktra phan tu con lai con trong k ?
            for (int k = 0; k < 4; k++){
                if (a[i][k] == 0) {
                    a[i][k] = 2;
                    cout << "I.1.a" << endl;
                    return;
                }
            }
        }
    }

    //b. Cac hang tu phan tu 1->4
    for (int i = 0; i < 5; i++){
        int num = 0; // So luong phan tu O trong hang
        for (int j = 1; j < 5; j++){
            if (a[i][j] == 2) num += 1;
        }
        if (num == 3) { // Neu so luong O la 3 thi ktra phan tu con lai con trong k ?
            for (int k = 1; k < 5; k++){
                if (a[i][k] == 0) {
                    a[i][k] = 2;
                    cout << "I.1.b" << endl;
                    return;
                }
            }
        }
    }

    // 2. Kiem tra cac cot co the thang
    // a. Cac cot tu phan tu 0->3
    for (int j = 0; j < 5; j++){
        int num = 0; // So luong phan tu O trong hang
        for (int i = 0; i < 4; i++){
            if (a[i][j] == 2) num += 1;
        }
        if (num == 3) { // Neu so luong O la 3 thi ktra phan tu con lai con trong k ?
            for (int k = 0; k < 4; k++){
                if (a[k][j] == 0) {
                    a[k][j] = 2;
                    cout << "I.2.a" << endl;
                    return;
                }
            }
        }
    }

    //b. Cac cot tu phan tu 1->4
    for (int j = 0; j < 5; j++){
        int num = 0; // So luong phan tu O trong hang
        for (int i = 1; i < 5; i++){
            if (a[i][j] == 2) num += 1;
        }
        if (num == 3) { // Neu so luong O la 3 thi ktra phan tu con lai con trong k ?
            for (int k = 1; k < 5; k++){
                if (a[k][j] == 0) {
                    a[k][j] = 2;
                    cout << "I.2.b" << endl;
                    return;
                }
            }
        }
    }

    //3. Kiem tra cac duong cheo
    //a. Duong cheo tu a[0][3]->a[3][0]
    int numI3a = 0; // Dem so luong phan tu O
    for (int i = 0; i < 4; i++){
        if (a[i][3-i] == 2) numI3a += 1;
    }
    if (numI3a == 3){ // Neu so luong O bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 0; i < 4; i++){
            if (a[i][3-i] == 0) {
                a[i][3-i] = 2;
                cout << "I.3.a" << endl;
                return;
            }
        }
    }

    //b. Duong cheo tu a[1][4]->a[4][1]
    int numI3b = 0; // Dem so luong phan tu O
    for (int i = 1; i < 5; i++){
        if (a[i][5-i] == 2) numI3b += 1;
    }
    if (numI3b == 3){ // Neu so luong O bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 1; i < 5; i++){
            if (a[i][5-i] == 0) {
                a[i][5-i] = 2;
                cout << "I.3.b" << endl;
                return;
            }
        }
    }

    //c. Duong cheo tu a[0][1]->a[3][4]
    int numI3c = 0; // Dem so luong phan tu O
    for (int i = 0; i < 4; i++){
        if (a[i][i+1] == 2) numI3c += 1;
    }
    if (numI3c == 3){ // Neu so luong O bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 0; i < 4; i++){
            if (a[i][i+1] == 0) {
                a[i][i+1] = 2;
                cout << "I.3.c" << endl;
                return;
            }
        }
    }

    //d. Duong cheo tu a[1][0]->a[4][3]
    int numI3d = 0; // Dem so luong phan tu O
    for (int i = 1; i < 5; i++){
        if (a[i][i-1] == 2) numI3d += 1;
    }
    if (numI3d == 3){ // Neu so luong O bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 1; i < 5; i++){
            if (a[i][i-1] == 0) {
                a[i][i-1] = 2;
                cout << "I.3.d" << endl;
                return;
            }
        }
    }

    //e. Duong cheo tu a[0][0]->a[3][3]
    int numI3e = 0; // Dem so luong phan tu O
    for (int i = 0; i < 4; i++){
        if (a[i][i] == 2) numI3e += 1;
    }
    if (numI3e == 3){ // Neu so luong O bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 0; i < 4; i++){
            if(a[i][i] == 0){
                a[i][i] = 2;
                cout << "I.3.e" << endl;
                return;
            }
        }
    }

    //f. Duong cheo tu a[1][1]->a[4][4]
    int numI3f = 0; // Dem so luong phan tu O
    for (int i = 1; i < 5; i++){
        if (a[i][i] == 2) numI3f += 1;
    }
    if (numI3f == 3){ // Neu so luong O bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 1; i < 5; i++){
            if(a[i][i] == 0){
                a[i][i] = 2;
                cout << "I.3.f" << endl;
                return;
            }
        }
    }

    //g. Duong cheo tu a[0][4]->a[3][1]
    int numI3g = 0;// Dem so luong phan tu O
    for (int i = 0; i < 4; i++){
        if(a[i][4-i] == 2) numI3g += 1;
    }
    if (numI3g == 3){// Neu so luong O bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 0; i < 4; i++){
            if(a[i][4-i] == 0){
                a[i][4-i] = 2;
                cout << "I.3.g" << endl;
                return;
            }
        }
    }

    //h. Duong cheo tu a[1][3]->a[4][0]
    int numI3h = 0;// Dem so luong phan tu O
    for (int i = 1; i < 5; i++){
        if(a[i][4-i] == 2) numI3h += 1;
    }
    if (numI3h == 3){// Neu so luong O bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 1; i < 5; i++){
            if(a[i][4-i] == 0){
                a[i][4-i] = 2;
                cout << "I.3.h" << endl;
                return;
            }
        }
    }

    // II. Kiem cac TH co the thua
    // 1. Kiem tra cac hang co the thua
    // a. Cac hang tu phan tu 0->3
    for (int i = 0; i < 5; i++){
        int num = 0; // So luong phan tu X trong hang
        for (int j = 0; j < 4; j++){
            if (a[i][j] == 1) num += 1;
        }
        if (num == 3) { // Neu so luong X la 3 thi ktra phan tu con lai con trong k ?
            for (int k = 0; k < 4; k++){
                if (a[i][k] == 0) {
                    a[i][k] = 2;
                    cout << "II.1.a" << endl;
                    return;
                }
            }
        }
    }

    //b. Cac hang tu phan tu 1->4
    for (int i = 0; i < 5; i++){
        int num = 0; // So luong phan tu X trong hang
        for (int j = 1; j < 5; j++){
            if (a[i][j] == 1) num += 1;
        }
        if (num == 3) { // Neu so luong X la 3 thi ktra phan tu con lai con trong k ?
            for (int k = 1; k < 5; k++){
                if (a[i][k] == 0) {
                    a[i][k] = 2;
                    cout << "II.1.b" << endl;
                    return;
                }
            }
        }
    }

    // 2. Kiem tra cac cot co the thua
    // a. Cac cot tu phan tu 0->3
    for (int j = 0; j < 5; j++){
        int num = 0; // So luong phan tu X trong hang
        for (int i = 0; i < 4; i++){
            if (a[i][j] == 1) num += 1;
        }
        if (num == 3) { // Neu so luong X la 3 thi ktra phan tu con lai con trong k ?
            for (int k = 0; k < 4; k++){
                if (a[k][j] == 0) {
                    a[k][j] = 2;
                    cout << "II.2.a" << endl;
                    return;
                }
            }
        }
    }

    //b. Cac cot tu phan tu 1->4
    for (int j = 0; j < 5; j++){
        int num = 0; // So luong phan tu x trong hang
        for (int i = 1; i < 5; i++){
            if (a[i][j] == 1) num += 1;
        }
        if (num == 3) { // Neu so luong X la 3 thi ktra phan tu con lai con trong k ?
            for (int k = 1; k < 5; k++){
                if (a[k][j] == 0) {
                    a[k][j] = 2;
                    cout << "II.2.b" << endl;
                    return;
                }
            }
        }
    }

    //3. Kiem tra cac duong cheo
    //a. Duong cheo tu a[0][3]->a[3][0]
    int numII3a = 0; // Dem so luong phan tu X
    for (int i = 0; i < 4; i++){
        if (a[i][3-i] == 1) numII3a += 1;
    }
    if (numII3a == 3){ // Neu so luong X bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 0; i < 4; i++){
            if (a[i][3-i] == 0) {
                a[i][3-i] = 2;
                cout << "II.3.a" << endl;
                return;
            }
        }
    }

    //b. Duong cheo tu a[1][4]->a[4][1]
    int numII3b = 0; // Dem so luong phan tu X
    for (int i = 1; i < 5; i++){
        if (a[i][5-i] == 1) numII3b += 1;
    }
    if (numII3b == 3){ // Neu so luong X bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 1; i < 5; i++){
            if (a[i][5-i] == 0) {
                a[i][5-i] = 2;
                cout << "II.3.b" << endl;
                return;
            }
        }
    }

    //c. Duong cheo tu a[0][1]->a[3][4]
    int numII3c = 0; // Dem so luong phan tu X
    for (int i = 0; i < 4; i++){
        if (a[i][i+1] == 1) numII3c += 1;
    }
    if (numII3c == 3){ // Neu so luong X bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 0; i < 4; i++){
            if (a[i][i+1] == 0) {
                a[i][i+1] = 2;
                cout << "II.3.c" << endl;
                return;
            }
        }
    }

    //d. Duong cheo tu a[1][0]->a[4][3]
    int numII3d = 0; // Dem so luong phan tu X
    for (int i = 1; i < 5; i++){
        if (a[i][i-1] == 1) numII3d += 1;
    }
    if (numII3d == 3){ // Neu so luong X bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 1; i < 5; i++){
            if (a[i][i-1] == 0) {
                a[i][i-1] = 2;
                cout << "II.3.d" << endl;
                return;
            }
        }
    }

    //e. Duong cheo tu a[0][0]->a[3][3]
    int numII3e = 0; // Dem so luong phan tu X
    for (int i = 0; i < 4; i++){
        if (a[i][i] == 1) numII3e += 1;
    }
    if (numII3e == 3){ // Neu so luong X bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 0; i < 4; i++){
            if(a[i][i] == 0){
                a[i][i] = 2;
                cout << "II.3.e" << endl;
                return;
            }
        }
    }

    //f. Duong cheo tu a[1][1]->a[4][4]
    int numII3f = 0; // Dem so luong phan tu X
    for (int i = 1; i < 5; i++){
        if (a[i][i] == 1) numII3f += 1;
    }
    if (numII3f == 3){ // Neu so luong X bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 1; i < 5; i++){
            if(a[i][i] == 0){
                a[i][i] = 2;
                cout << "II.3.f" << endl;
                return;
            }
        }
    }

    //g. Duong cheo tu a[0][4]->a[3][1]
    int numII3g = 0;// Dem so luong phan tu X
    for (int i = 0; i < 4; i++){
        if(a[i][4-i] == 1) numII3g += 1;
    }
    if (numII3g == 3){// Neu so luong X bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 0; i < 4; i++){
            if(a[i][4-i] == 0){
                a[i][4-i] = 2;
                cout << "II.3.g" << endl;
                return;
            }
        }
    }

    //h. Duong cheo tu a[1][3]->a[4][0]
    int numII3h = 0;// Dem so luong phan tu X
    for (int i = 1; i < 5; i++){
        if(a[i][4-i] == 1) numII3h += 1;
    }
    if (numII3h == 3){// Neu so luong X bang 3 thi kiem tra phan tu con lai con trong k ?
        for (int i = 1; i < 5; i++){
            if(a[i][4-i] == 0){
                a[i][4-i] = 2;
                cout << "II.3.h" << endl;
                return;
            }
        }
    }

    //III. Các TH tiền chiến thắng
    //1. Các hàng có 2 phần tử O trong ô (1->3) và các ô còn lại trống
    for (int i = 0; i < 5; i++){
        int num1 = 0, num2 = 0;
        // Đếm số lượng O trong các ô (1->3)
        for (int j = 1; j < 4; j++){
            if(a[i][j] == 2) num1 += 1;
        }
        // Đếm số lượng ô trống trong các ô (0->4)
        for (int j = 0; j < 5; j++){
            if(a[i][j] == 0) num2 += 1;
        }
        // Nếu số lượng O trong ô (1->3) là 2 và còn 3 ô trống
        if (num1 == 2 && num2 == 3){
            // Tìm ô trống còn lại trong các ô (1->3)
            for(int k = 1; k < 4; k++){
                if (a[i][k] == 0){
                    a[i][k] = 2;
                    cout << "III.1" << endl;
                    return;
                }
            }
        }
    }

    //2. Các cột có 2 phần tử O trong ô (1->3) và các ô còn lại trống
    for (int j = 0; j < 5; j++){
        int num1 = 0, num2 = 0;
        // Đếm số lượng O trong các ô (1->3)
        for (int i = 1; i < 4; i++){
            if(a[i][j] == 2) num1 += 1;
        }
        // Đếm số lượng ô trống trong các ô (0->4)
        for (int i = 0; i < 5; i++){
            if(a[i][j] == 0) num2 += 1;
        }
        // Nếu số lượng O trong ô (1->3) là 2 và còn 3 ô trống
        if (num1 == 2 && num2 == 3){
            // Tìm ô trống còn lại trong các ô (1->3)
            for(int k = 1; k < 4; k++){
                if (a[k][j] == 0){
                    a[k][j] = 2;
                    cout << "III.2" << endl;
                    return;
                }
            }
        }
    }

    //3. Đường chéo có 2 phần tử O trong ô (1->3) và các ô còn lại trống
    //a. Đường chéo a[0][0]->a[4][4]
    int numIII3a_1 = 0, numIII3a_2 = 0;
    // Đếm số lượng O trong các ô a[1][1]->a[3][3]
    for (int i = 1; i < 4; i++){
        if (a[i][i] == 2) numIII3a_1 += 1;
    }
    // Đếm số lượng ô trống trong các ô a[0][0]->a[4][4]
    for (int i = 0; i < 5; i++){
        if (a[i][i] == 0) numIII3a_2 += 1;
    }
    if (numIII3a_1 == 2 && numIII3a_2 == 3){
        // Tìm ô trống trong các ô a[1][1]->a[3][3]
        for (int i = 1; i < 4; i++){
            if (a[i][i] == 0){
                a[i][i] = 2;
                cout << "III.3.a" << endl;
                return;
            }
        }
    }

    //b. Đường chéo a[0][4]->a[4][0]
    int numIII3b_1 = 0, numIII3b_2 = 0;
    // Đếm số lượng O trong các ô a[1][3]->a[3][1]
    for (int i = 1; i < 4; i++){
        if (a[i][4-i] == 2) numIII3b_1 += 1;
    }
    // Đếm số lượng ô trống trong các ô a[0][4]->a[4][0]
    for (int i = 0; i < 5; i++){
        if (a[i][4-i] == 0) numIII3b_2 += 1;
    }
    if (numIII3b_1 == 2 && numIII3b_2 == 3){
        // Tìm ô trống trong các ô a[1][3]->a[3][1]
        for (int i = 1; i < 4; i++){
            if (a[i][4-i] == 0){
                a[i][4-i] = 2;
                cout << "III.3.b" << endl;
                return;
            }
        }
    }

    //IV. Các TH tiền thua cuộc
    //1. Các hàng có 2 phần tử X trong ô (1->3) và các ô còn lại trống
    for (int i = 0; i < 5; i++){
        int num1 = 0, num2 = 0;
        // Đếm số lượng X trong các ô (1->3)
        for (int j = 1; j < 4; j++){
            if(a[i][j] == 1) num1 += 1;
        }
        // Đếm số lượng ô trống trong các ô (0->4)
        for (int j = 0; j < 5; j++){
            if(a[i][j] == 0) num2 += 1;
        }
        // Nếu số lượng X trong ô (1->3) là 2 và còn 3 ô trống
        if (num1 == 2 && num2 == 3){
            // Tìm ô trống còn lại trong các ô (1->3)
            for(int k = 1; k < 4; k++){
                if (a[i][k] == 0){
                    a[i][k] = 2;
                    cout << "IV.1" << endl;
                    return;
                }
            }
        }
    }

    //2. Các cột có 2 phần tử X trong ô (1->3) và các ô còn lại trống
    for (int j = 0; j < 5; j++){
        int num1 = 0, num2 = 0;
        // Đếm số lượng X trong các ô (1->3)
        for (int i = 1; i < 4; i++){
            if(a[i][j] == 1) num1 += 1;
        }
        // Đếm số lượng ô trống trong các ô (0->4)
        for (int i = 0; i < 5; i++){
            if(a[i][j] == 0) num2 += 1;
        }
        // Nếu số lượng X trong ô (1->3) là 2 và còn 3 ô trống
        if (num1 == 2 && num2 == 3){
            // Tìm ô trống còn lại trong các ô (1->3)
            for(int k = 1; k < 4; k++){
                if (a[k][j] == 0){
                    a[k][j] = 2;
                    cout << "IV.2" << endl;
                    return;
                }
            }
        }
    }

    //3. Đường chéo có 2 phần tử X trong ô (1->3) và các ô còn lại trống
    //a. Đường chéo a[0][0]->a[4][4]
    int numIV3a_1 = 0, numIV3a_2 = 0;
    // Đếm số lượng X trong các ô a[1][1]->a[3][3]
    for (int i = 1; i < 4; i++){
        if (a[i][i] == 1) numIV3a_1 += 1;
    }
    // Đếm số lượng ô trống trong các ô a[0][0]->a[4][4]
    for (int i = 0; i < 5; i++){
        if (a[i][i] == 0) numIV3a_2 += 1;
    }
    if (numIV3a_1 == 2 && numIV3a_2 == 3){
        // Tìm ô trống trong các ô a[1][1]->a[3][3]
        for (int i = 1; i < 4; i++){
            if (a[i][i] == 0){
                a[i][i] = 2;
                cout << "IV.3.a" << endl;
                return;
            }
        }
    }

    //b. Đường chéo a[0][4]->a[4][0]
    int numIV3b_1 = 0, numIV3b_2 = 0;
    // Đếm số lượng X trong các ô a[1][3]->a[3][1]
    for (int i = 1; i < 4; i++){
        if (a[i][4-i] == 1) numIV3b_1 += 1;
    }
    // Đếm số lượng ô trống trong các ô a[0][4]->a[4][0]
    for (int i = 0; i < 5; i++){
        if (a[i][4-i] == 0) numIV3b_2 += 1;
    }
    if (numIV3b_1 == 2 && numIV3b_2 == 3){
        // Tìm ô trống trong các ô a[1][3]->a[3][1]
        for (int i = 1; i < 4; i++){
            if (a[i][4-i] == 0){
                a[i][4-i] = 2;
                cout << "IV.3.b" << endl;
                return;
            }
        }
    }


    //V. Đánh để thắng (các hàng, cột, đường chéo có đủ 4 ô chỉ gồm ô trống hoặc O)
    //Ưu tiên các hàng i=(1->3), các cột j=(1->3)
    bool tmp1a = false, tmp1b = false, tmp2a = false, tmp2b = false, tmp3a = false, tmp3b = false;
    while(tmp1a != true || tmp1b != true || tmp2a != true || tmp2a != true || tmp2b != true || tmp3a != true || tmp3b != true){
        int RandOrder = rand() % 6; // Random thu tu

        //1. Hàng i=(1->3)
        //a. Các phần tử a[i][0]->a[i][3]
        if (RandOrder == 0){
            tmp1a = true;
            for (int i = 1; i < 4; i++){
                int num1 = 0, num2 = 0;
                // Các phần tử a[i][0]->a[i][3]
                for (int j = 0; j < 4; j++){
                    if (a[i][j] != 1) num1 += 1; // Đếm số ô khác X
                    if (a[i][j] == 0) num2 += 1; // Đếm số ô trống
                }
                // Nếu có 4 ô trống/O và còn ô trống thì tìm 1 trong các ô để đánh
                if (num1 == 4 && num2 > 0){
                    while(true){
                        int RandOption = rand() % 100 + 1;
                        // 10 % a[i][0]; 30% a[i][1]; 30% a[i][2]; 30% a[i][3];
                        if (RandOption <= 10 && a[i][0] == 0) {
                            a[i][0] = 2;
                            cout << "V.1.a" << endl;
                            return;
                        }
                        else if (10 < RandOption && RandOption <= 40 && a[i][1] == 0){
                            a[i][1] = 2;
                            cout << "V.1.a" << endl;
                            return;
                        }
                        else if (40 < RandOption && RandOption <= 70 && a[i][2] == 0){
                            a[i][2] = 2;
                            cout << "V.1.a" << endl;
                            return;
                        }
                        else if (70 < RandOption && RandOption <= 100 && a[i][3] == 0){
                            a[i][3] = 2;
                            cout << "V.1.a" << endl;
                            return;
                        }
                    }
                }
            }
        }

        //b. Các phần tử a[i][1]->a[i][4]
        if (RandOrder == 1){
            tmp1b = true;
            for (int i = 1; i < 4; i++){
                int num1 = 0, num2 = 0;
                // Các phần tử a[i][1]->a[i][4]
                for (int j = 1; j < 5; j++){
                    if (a[i][j] != 1) num1 += 1; // Đếm số ô khác X
                    if (a[i][j] == 0) num2 += 1; // Đếm số ô trống
                }
                // Nếu có 4 ô trống/O và còn ô trống thì tìm 1 trong các ô để đánh
                if (num1 == 4 && num2 > 0){
                    while(true){
                        int RandOption = rand() % 100 + 1;
                        // 10 % a[i][4]; 30% a[i][1]; 30% a[i][2]; 30% a[i][3];
                        if (RandOption <= 10 && a[i][4] == 0) {
                            a[i][4] = 2;
                            cout << "V.1.b" << endl;
                            return;
                        }
                        else if (10 < RandOption && RandOption <= 40 && a[i][1] == 0){
                            a[i][1] = 2;
                            cout << "V.1.b" << endl;
                            return;
                        }
                        else if (40 < RandOption && RandOption <= 70 && a[i][2] == 0){
                            a[i][2] = 2;
                            cout << "V.1.b" << endl;
                            return;
                        }
                        else if (70 < RandOption && RandOption <= 100 && a[i][3] == 0){
                            a[i][3] = 2;
                            cout << "V.1.b" << endl;
                            return;
                        }
                    }
                }
            }
        }

        //2. Cột j=(1->3)
        //a. Các phần tử a[0][j]->a[3][j]
        if (RandOrder == 2){
            tmp2a = true;
            for (int j = 1; j < 4; j++){
                int num1 = 0, num2 = 0;
                // Các phần tử a[0][j]->a[3][j]
                for (int i = 0; i < 4; i++){
                    if (a[i][j] != 1) num1 += 1; // Đếm số ô khác X
                    if (a[i][j] == 0) num2 += 1; // Đếm số ô trống
                }
                // Nếu có 4 ô trống/O và còn ô trống thì tìm 1 trong các ô để đánh
                if (num1 == 4 && num2 > 0){
                    while(true){
                        int RandOption = rand() % 100 + 1;
                        // 10% a[0][j]; 30% a[1][j]; 30% a[2][j]; 30% a[3][j];
                        if (RandOption <= 10 && a[0][j] == 0) {
                            a[0][j] = 2;
                            cout << "V.2.a" << endl;
                            return;
                        }
                        else if (10 < RandOption && RandOption <= 40 && a[1][j] == 0){
                            a[1][j] = 2;
                            cout << "V.2.a" << endl;
                            return;
                        }
                        else if (40 < RandOption && RandOption <= 70 && a[2][j] == 0){
                            a[2][j] = 2;
                            cout << "V.2.a" << endl;
                            return;
                        }
                        else if (70 < RandOption && RandOption <= 100 && a[3][j] == 0){
                            a[3][j] = 2;
                            cout << "V.2.a" << endl;
                            return;
                        }
                    }
                }
            }
        }

        //b. Các phần tử a[1][j]->a[4][j]
        if (RandOrder == 3){
            tmp2b = true;
            for (int j = 1; j < 4; j++){
                int num1 = 0, num2 = 0;
                // Các phần tử a[i][1]->a[i][4]
                for (int i = 1; i < 5; i++){
                    if (a[i][j] != 1) num1 += 1; // Đếm số ô khác X
                    if (a[i][j] == 0) num2 += 1; // Đếm số ô trống
                }
                // Nếu có 4 ô trống/O và còn ô trống thì tìm 1 trong các ô để đánh
                if (num1 == 4 && num2 > 0){
                    while(true){
                        int RandOption = rand() % 100 + 1;
                        // 10% a[4][j]; 30% a[1][j]; 30% a[2][j]; 30% a[3][j];
                        if (RandOption <= 10 && a[0][j] == 0) {
                            a[4][j] = 2;
                            cout << "V.2.b" << endl;
                            return;
                        }
                        else if (10 < RandOption && RandOption <= 40 && a[1][j] == 0){
                            a[1][j] = 2;
                            cout << "V.2.b" << endl;
                            return;
                        }
                        else if (40 < RandOption && RandOption <= 70 && a[2][j] == 0){
                            a[2][j] = 2;
                            cout << "V.2.b" << endl;
                            return;
                        }
                        else if (70 < RandOption && RandOption <= 100 && a[3][j] == 0){
                            a[3][j] = 2;
                            cout << "V.2.b" << endl;
                            return;
                        }
                    }
                }
            }
        }

        //3. Đường chéo
        //a. a[0][0]->a[3][3] và a[1][1]->a[4][4]
        if (RandOrder == 4){
            tmp3a = true;
            if (a[0][0] != 1 && a[1][1] != 1 && a[2][2] != 1 && a[3][3] != 1){
                if (a[1][1] == 0) {
                    a[1][1] = 2;
                    cout << "V.3.a" << endl;
                    return;
                }
                else if (a[2][2] == 0) {
                    a[2][2] = 2;
                    cout << "V.3.a" << endl;
                    return;
                }
                else if (a[3][3] == 0) {
                    a[3][3] = 2;
                    cout << "V.3.a" << endl;
                    return;
                }
                else if (a[0][0] == 0) {
                    a[0][0] = 2;
                    cout << "V.3.a" << endl;
                    return;
                }
            }

            if (a[4][4] != 1 && a[1][1] != 1 && a[2][2] != 1 && a[3][3] != 1){
                if (a[1][1] == 0) {
                    a[1][1] = 2;
                    cout << "V.3.a" << endl;
                    return;
                }
                else if (a[2][2] == 0) {
                    a[2][2] = 2;
                    cout << "V.3.a" << endl;
                    return;
                }
                else if (a[3][3] == 0) {
                    a[3][3] = 2;
                    cout << "V.3.a" << endl;
                    return;
                }
                else if (a[4][4] == 0) {
                    a[4][4] = 2;
                    cout << "V.3.a" << endl;
                    return;
                }
            }
        }


        //b. a[0][4]->a[3][1] và a[1][3]->a[4][0]
        if (RandOrder == 5){
            tmp3b = true;
            if (a[0][4] != 1 && a[1][3] != 1 && a[2][2] != 1 && a[3][1] != 1){
                if (a[1][3] == 0) {
                    a[1][3] = 2;
                    cout << "V.3.b" << endl;
                    return;
                }
                else if (a[2][2] == 0) {
                    a[2][2] = 2;
                    cout << "V.3.b" << endl;
                    return;
                }
                else if (a[3][1] == 0) {
                    a[3][1] = 2;
                    cout << "V.3.b" << endl;
                    return;
                }
                else if (a[0][4] == 0) {
                    a[0][4] = 2;
                    cout << "V.3.b" << endl;
                    return;
                }
            }

            if (a[1][3] != 1 && a[2][2] != 1 && a[3][1] != 1 && a[4][0] != 1){
                if (a[1][3] == 0) {
                    a[1][3] = 2;
                    cout << "V.3.b" << endl;
                    return;
                }
                else if (a[2][2] == 0) {
                    a[2][2] = 2;
                    cout << "V.3.b" << endl;
                    return;
                }
                else if (a[3][1] == 0) {
                    a[3][1] = 2;
                    cout << "V.3.b" << endl;
                    return;
                }
                else if (a[4][0] == 0) {
                    a[4][0] = 2;
                    cout << "V.3.b" << endl;
                    return;
                }
            }
        }

    }




    while(true){
            int i = rand() % 5;
            int j = rand() % 5;
            if (a[i][j] == 0){
                cout << "rand a" << i << j << endl;
                a[i][j] = 2;
                return;
            }
        }
}

void present_game_result_5x5 (SDL_Renderer* renderer, int _result){
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
