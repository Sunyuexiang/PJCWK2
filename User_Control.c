//
// Created by syx011020 on 22-5-20.
//

#include "User_Control.h"
#include <stdio.h>
#include <SDL2/SDL.h>

#define Window_Width 800
#define Window_Height 800

int H1;
int W1;
SDL_Renderer *renderer1;
SDL_Window *window1;
SDL_Event  event1;

void Event_Loop1(){
    while (1){
        if(SDL_PollEvent(&event1)){
            if(event1.type == SDL_QUIT){
                break;
            }
        }
    }
}

void Draw_W1(int i,int j){
    int a = 800/H1;
    int b = 800/W1;
    int X = a*i;
    int Y = b*j;
    SDL_SetRenderDrawColor(renderer1,255,255,255,255);
    SDL_Rect r = {X + 2, Y + 2, a - 2, b - 2};
    SDL_RenderFillRect(renderer1, &r);
    SDL_RenderPresent(renderer1);
}

void Draw_B1(int i,int j){
    int a = 800/H1;
    int b = 800/W1;
    int X = a*i;
    int Y = b*j;
    SDL_SetRenderDrawColor(renderer1,0,0,0,0);
    SDL_Rect r = {X + 2, Y + 2, a - 2, b - 2};
    SDL_RenderFillRect(renderer1, &r);
    SDL_RenderPresent(renderer1);
}

void Users_Control() {
    printf("Enter the Width :");
    scanf("%d", &H1);
    printf("Enter the High : ");
    scanf("%d", &W1);
    int i, j;
    int Cells[H1][W1];
    for (i = 0; i < H1; i++) {
        for (j = 0; j < W1; j++) {
            Cells[i][j] = 0;
        }
    }

    //手动输入循环Round次

    int d;
    int Round;
    printf("Enter the number that you want to loop:");
    scanf("%d", &Round);

    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Can not init Video,%s", SDL_GetError());
        return;
    }
    window1 = SDL_CreateWindow("Game of life",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               Window_Width,
                               Window_Height, SDL_WINDOW_SHOWN);
    if (window1 == NULL) {
        SDL_Log("Can not create window,%s", SDL_GetError());
        return;
    }
    renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_ACCELERATED);
    if (renderer1 == NULL) {
        SDL_Log("Can not create render,%s", SDL_GetError());
    }

    SDL_SetRenderDrawColor(renderer1, 0, 255, 255, 255);
    SDL_RenderClear(renderer1);

    SDL_SetRenderDrawColor(renderer1, 0, 0, 0, 0);
    int a, b, X, Y;
    a = 800 / H1;
    b = 800 / W1;
    Y = 0;
    for (i = 0; i < H1; i++) {
        X = 0;
        for (j = 0; j < W1; j++) {
            SDL_Rect r = {X + 2, Y + 2, a - 2, b - 2};
            SDL_RenderFillRect(renderer1, &r);
            X = X + a;
        }
        Y = Y + b;
    }
    SDL_RenderPresent(renderer1);

    int quit = 0;
    while (!quit) {
        int MouseX, MouseY;
        while (SDL_PollEvent(&event1)){
            if(event1.type == SDL_QUIT){
                quit = 1;
                SDL_DestroyRenderer(renderer1);
                SDL_DestroyWindow(window1);
            }
            if (event1.type == SDL_MOUSEMOTION) {
                MouseX = 0;
                MouseY = 0;
                SDL_GetMouseState(&MouseX, &MouseY);
            }

            int m, n;
            if (event1.type == SDL_MOUSEBUTTONDOWN) {
                m = MouseX / a;
                n = MouseY / b;
                if (event1.button.button == SDL_BUTTON_LEFT) {
                    Draw_B1(m,n);
                    Cells[n][m] = 0;
                }
                if (event1.button.button == SDL_BUTTON_RIGHT) {
                    Draw_W1(m,n);
                    Cells[n][m] = 1;
                }
            }
        }
    }

    /*for(i = 0;i < H;i++){
        for(j = 0;j < W;j++){
            if(Cells[i][j] == 1){
                printf("1 ");
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");*/

    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Can not init Video,%s", SDL_GetError());
        return;
    }
    window1 = SDL_CreateWindow("Game of life",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               Window_Width,
                               Window_Height, SDL_WINDOW_SHOWN);
    if (window1 == NULL) {
        SDL_Log("Can not create window,%s", SDL_GetError());
        return;
    }
    renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_ACCELERATED);
    if (renderer1 == NULL) {
        SDL_Log("Can not create render,%s", SDL_GetError());
    }
    SDL_SetRenderDrawColor(renderer1, 0, 255, 255, 255);
    SDL_RenderClear(renderer1);

    for (d = 1; d <= Round; d++) {
        int New_Cells[H1 + 2][W1 + 2];
        for (i = 0; i < H1 + 2; i++) {
            for (j = 0; j < W1 + 2; j++) {
                New_Cells[i][j] = 0;
            }
        }

        for (i = 1; i <= H1; i++) {
            for (j = 1; j <= W1; j++) {
                New_Cells[i][j] = Cells[i - 1][j - 1];
            }
        }

        //改变生死

        int count;
        int temp[H1][W1];
        for (i = 1; i <= H1; i++) {
            for (j = 1; j <= W1; j++) {
                count = New_Cells[i - 1][j - 1] + New_Cells[i - 1][j] + New_Cells[i - 1][j + 1] +
                        New_Cells[i][j - 1] +
                        New_Cells[i][j + 1]
                        + New_Cells[i + 1][j - 1] + New_Cells[i + 1][j] + New_Cells[i + 1][j + 1];
                if (count == 3) {
                    temp[i - 1][j - 1] = 1;
                } else if (count == 2) {
                    temp[i - 1][j - 1] = New_Cells[i][j];
                } else {
                    temp[i - 1][j - 1] = 0;
                }
            }
        }

        for (i = 0; i < H1; i++) {
            for (j = 0; j < W1; j++) {
                Cells[i][j] = temp[i][j];
            }
        }

        // 细胞全死 游戏结束

        int Count;
        int Multiply;
        Count = 0;
        Multiply = H1 * W1;
        for (i = 0; i < H1; i++) {
            for (j = 0; j < W1; j++) {
                if (Cells[i][j] == 0) {
                    Count++;
                }
            }
        }
        if (Count == Multiply) {
            printf("ALL cells die.");
        }

        for (i = 0; i < H1; i++) {
            for (j = 0; j < W1; j++) {
                if (Cells[i][j] == 1) {
                    Draw_W1(i, j);
                }
                if (Cells[i][j] == 0) {
                    Draw_B1(i, j);
                }
            }
        }
        //写入文件

        FILE *fp = fopen("Show.txt", "a+");
        fprintf(fp, "Round:%d\n",d);
        for (i = 0; i < H1; i++) {
            for (j = 0; j < W1; j++) {
                if (Cells[i][j] == 1) {
                    fputs("1 ", fp);
                } else {
                    fputs("0 ", fp);
                }
            }
            fputs("\n", fp);
        }
        fputs("\n", fp);
        fclose(fp);
    }
}

int Play_User_Control(){
    Users_Control();
    Event_Loop1();
    SDL_Delay(1000);
    SDL_DestroyRenderer(renderer1);
    SDL_DestroyWindow(window1);
    return 0;
}
