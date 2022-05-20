//
// Created by ASUS on 2022/5/20.
//

#include "Users_Create.h"
#include <stdio.h>

#define Window_Width 800
#define Window_Height 800

int H;
int W;
SDL_Renderer *renderer;
SDL_Window *window;
SDL_Event  event;

void Event_Loop(){
    while (1){
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                break;
            }
        }
    }
}

int Initialize(){
    if(SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("Can not init Video,%s",SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow("Game of life",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              Window_Width,
                              Window_Height,SDL_WINDOW_SHOWN);
    if(window == NULL){
        SDL_Log("Can not create window,%s",SDL_GetError());
        return 1;
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        SDL_Log("Can not create render,%s",SDL_GetError());
    }

    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    int a,b,X,Y,i,j;
    a = 800/H;
    b = 800/W;
    Y = 0;
    for(i = 0;i < H;i++){
        X = 0;
        for (j = 0 ;j < W;j++){
            SDL_Rect r = {X + 2, Y + 2, a - 2, b - 2};
            SDL_RenderFillRect(renderer, &r);
            X = X + a;
        }
        Y = Y + b;
    }
}

void Draw_W(int i,int j){
    int a = 800/H;
    int b = 800/W;
    int X = a*i;
    int Y = b*j;
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_Rect r = {X + 2, Y + 2, a - 2, b - 2};
    SDL_RenderFillRect(renderer, &r);
    SDL_RenderPresent(renderer);
}

void Draw_B(int i,int j){
    int a = 800/H;
    int b = 800/W;
    int X = a*i;
    int Y = b*j;
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_Rect r = {X + 2, Y + 2, a - 2, b - 2};
    SDL_RenderFillRect(renderer, &r);
    SDL_RenderPresent(renderer);
}

void Users_Input(){
    printf("Enter the Width :");
    scanf("%d", &W);
    printf("Enter the High : ");
    scanf("%d", &H);
    int i,j;
    int Cells[H][W];
    for(i = 0; i < H ;i++){
        for(j = 0; j < W;j++){
            int c = rand()%2;
            if(c == 1){
                Cells[i][j] = c;
            }
            else{
                Cells[i][j] = c;
            }
        }
    }

    //手动输入循环Round次
    int d;
    int Round;
    printf("Enter the number that you want to loop:");
    scanf("%d",&Round);

    Initialize();

    for(d = 0; d < Round;d++) {
        //建一个外部全是0的新二维数组
        int New_Cells[H + 2][W + 2];
        for (i = 0; i < H + 2; i++) {
            for (j = 0; j < W + 2; j++) {
                New_Cells[i][j] = 0;
            }
        }

        for (i = 1; i <= H; i++) {
            for (j = 1; j <= W; j++) {
                New_Cells[i][j] = Cells[i - 1][j - 1];
            }
        }

        //改变生死

        int count;
        int temp[H][W];
        for (i = 1; i <= H; i++) {
            for (j = 1; j <= W; j++) {
                count = New_Cells[i - 1][j - 1] + New_Cells[i - 1][j] + New_Cells[i - 1][j + 1] + New_Cells[i][j - 1] +
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

        for (i = 0; i < H; i++) {
            for (j = 0; j < W; j++) {
                Cells[i][j] = temp[i][j];
            }
        }

        // 细胞全死 游戏结束

        int Count;
        int Multiply;
        Count = 0;
        Multiply = H*W;
        for(i = 0; i < H;i++){
            for(j = 0;j < W; j++){
                if(Cells[i][j] == 0){
                    Count++;
                }
            }
        }
        if(Count == Multiply) {
            printf("ALL cells die.");
            return;
        }

        for(i = 0;i < H;i++){
            for(j = 0;j < W;j++){
                if(Cells[i][j] == 1){
                    Draw_W(i,j);
                }
                if(Cells[i][j] == 0){
                    Draw_B(i,j);
                }
            }
        }
        SDL_Delay(1000);

        //写入文件

        FILE *fp = fopen("Result.txt", "a+");
        fputs("\n",fp);
        for (i = 0; i < H; i++) {
            for (j = 0; j < W; j++) {
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

int User_Create(){
    Users_Input();
    Event_Loop();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}