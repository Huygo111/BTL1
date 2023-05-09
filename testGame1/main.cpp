#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <cstdlib>
#include "SDL_utils.h"
#include "Game3x3Func.h"
#include "Game5x5Func.h"
#include "GameMenu.h"
using namespace std;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 480;
const string WINDOW_TITLE = "Tic Tac Toe";
grid3x3 _3x3grid(186, 264, 342, 126, 204, 282);
grid _5x5grid(131, 200, 269, 338, 407, 69, 138, 207, 276, 345);

bool _3x3GameVsFriend(SDL_Renderer* renderer, SDL_Window* window){
    int a[3][3]={0,0,0,0,0,0,0,0,0};
        int x = _3x3grid.x0, y = _3x3grid.y0;
        while (true){
            bool quit;
            SDL_Delay(200);
            quit = turn_of_player(renderer, a, x, y, _3x3grid);
            if (quit == true) return true; // Thoat chuong trinh hoac khong
            SDL_Delay(300);

            // Kiem tra thang, thua, hoa
            if(_check(a) == 1){ cout << "X WIN !"; break; }
            else if(_check(a) == 2){ cout << "O WIN !"; break; }
            else if (_check(a) == 3){cout << "DRAW !"; break; }

            quit = turn_of_player_2(renderer, a, x, y, _3x3grid);
            if (quit == true) return true; // Thoat chuong trinh hoac khong

            // Kiem tra thang, thua, hoa
            if(_check(a) == 1){ cout << "X WIN !"; break; }
            else if(_check(a) == 2){ cout << "O WIN !"; break; }
            else if (_check(a) == 3){ cout << "DRAW !"; break; }
        }
        SDL_Delay(1000);
        present_game_result(renderer, _check(a));
        _printf(a);
        waitUntilKeyPressed();
        //quitSDL(window, renderer);
        return false;
}

bool _3x3GameVsBot(SDL_Renderer* renderer, SDL_Window* window){
        int a[3][3]={0,0,0,0,0,0,0,0,0};
        int x = _3x3grid.x0, y = _3x3grid.y0;

        bool RandOrder = rand() % 2; // RandOrder = 0 : O danh truoc; = 1 X danh truoc
        cout << "RandOrder " << RandOrder << endl;

        while (true){
            // O la bot danh nen truyen vao turn = 1 la luot cua X
            draw(renderer, x, y, a, _3x3grid, 1); // Render man hinh game ban dau
            SDL_Delay(500);

            bool quit; // quit trong tran

            if (RandOrder == 0){
                turn_of_bot(a);
                int turn = 1; // O la bot danh nen truyen vao turn = 1 la luot cua X
                draw(renderer, x, y, a, _3x3grid, turn);
            }
            else if (RandOrder == 1) quit = turn_of_player(renderer, a, x, y, _3x3grid);

            if(quit == true) return true;
            SDL_Delay(500);
            // Kiem tra thang, thua, hoa
            if(_check(a) == 1){ cout << "X WIN !"; break; }
            else if(_check(a) == 2){ cout << "O WIN !"; break; }
            else if (_check(a) == 3){cout << "DRAW !"; break; }


            if (RandOrder == 0) quit = turn_of_player(renderer, a, x, y, _3x3grid);
            else if (RandOrder == 1){
                turn_of_bot(a);
                int turn = 1; // O la bot danh nen truyen vao turn = 1 la luot cua X
                draw(renderer, x, y, a, _3x3grid, turn);
            }

            // Kiem tra thang, thua, hoa
            if(_check(a) == 1){ cout << "X WIN !"; break; }
            else if(_check(a) == 2){ cout << "O WIN !"; break; }
            else if (_check(a) == 3){cout << "DRAW !"; break; }

        }
        SDL_Delay(1000);
        present_game_result(renderer, _check(a));
        _printf(a);
        waitUntilKeyPressed();
        //quitSDL(window, renderer);
        return false;
}

bool _5x5GameVsFriend(SDL_Renderer* renderer, SDL_Window* window){
    int a[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            int x = _5x5grid.x0;
            int y = _5x5grid.y0;
        while (true){
            bool quit;
            SDL_Delay(300);
            quit = turn_of_player_5x5(renderer, a, x, y, _5x5grid);
            if(quit == true) return true;
            SDL_Delay(300);
            // Kiem tra thang, thua, hoa
            if(_check_5x5(a) == 1){ cout << "X WIN !"; break; }
            else if(_check_5x5(a) == 2){ cout << "O WIN !"; break; }
            else if (_check_5x5(a) == 3){cout << "DRAW !"; break; }

            quit = turn_of_player_5x5_2(renderer, a, x, y, _5x5grid);
            if(quit == true) return true;
            // Kiem tra thang, thua, hoa
            if(_check_5x5(a) == 1){ cout << "X WIN !"; break; }
            else if(_check_5x5(a) == 2){ cout << "O WIN !"; break; }
            else if (_check_5x5(a) == 3){ cout << "DRAW !"; break; }
        }
        SDL_Delay(1000);
        present_game_result(renderer, _check_5x5(a));
        _printf_5x5(a);
        waitUntilKeyPressed();
        //quitSDL(window, renderer);
        return false;
}

bool _5x5GameVsBot(SDL_Renderer* renderer, SDL_Window* window){
    int a[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            int x = _5x5grid.x0;
            int y = _5x5grid.y0;
            bool RandOrder = rand() % 2; // RandOrder = 0 : O danh truoc; = 1 X danh truoc
            cout << "RandOrder " << RandOrder << endl;

        while (true){
            // O la bot danh nen truyen vao turn = 1 la luot cua X
            draw_5x5(renderer, x, y, a, _5x5grid, 1); // Render man hinh game ban dau
            SDL_Delay(500);

            bool quit; // quit trong tran

            if (RandOrder == 0){
                turn_of_bot_5x5(a);
                int turn = 1; // O la bot danh nen truyen vao turn = 1 la luot cua X
                draw_5x5(renderer, x, y, a, _5x5grid, turn);
            }
            else if (RandOrder == 1) quit = turn_of_player_5x5(renderer, a, x, y, _5x5grid);

            if(quit == true) return true;
            SDL_Delay(500);
            // Kiem tra thang, thua, hoa
            if(_check_5x5(a) == 1){ cout << "X WIN !"; break; }
            else if(_check_5x5(a) == 2){ cout << "O WIN !"; break; }
            else if (_check_5x5(a) == 3){cout << "DRAW !"; break; }


            if (RandOrder == 0) quit = turn_of_player_5x5(renderer, a, x, y, _5x5grid);
            else if (RandOrder == 1){
                turn_of_bot_5x5(a);
                int turn = 1; // O la bot danh nen truyen vao turn = 1 la luot cua X
                draw_5x5(renderer, x, y, a, _5x5grid, turn);
            }

            // Kiem tra thang, thua, hoa
            if(_check_5x5(a) == 1){ cout << "X WIN !"; break; }
            else if(_check_5x5(a) == 2){ cout << "O WIN !"; break; }
            else if (_check_5x5(a) == 3){ cout << "DRAW !"; break; }
        }
        SDL_Delay(1000);
        present_game_result(renderer, _check_5x5(a));
        _printf_5x5(a);
        waitUntilKeyPressed();
        //quitSDL(window, renderer);
        return false;
}

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    int choice = 0;

    while(true){
        int x = 112;
        int y = 125;
        choice = choose_options(renderer, x, y);
        if (choice == 0) return 0;// Thoat chuong trinh
        else if (choice == 1){
            bool quit = _3x3GameVsFriend(renderer, window);
            if (quit == true) return 0;
        }
        else if (choice == 2) {
            bool quit = _5x5GameVsFriend(renderer, window);
            if (quit == true) return 0;
        }
        else if (choice == 3) {
            bool quit = _3x3GameVsBot(renderer, window);
            if (quit == true) return 0;
        }
        else if (choice == 4) {
            bool quit = _5x5GameVsBot(renderer, window);
            if (quit == true) return 0;
        }
    }

    return 0;
}




