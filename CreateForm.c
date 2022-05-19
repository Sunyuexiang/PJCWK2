//
// Created by ASUS on 2022/5/20.
//

#include "CreateForm.h"
#include "GreateForm.h"
#include <stdio.h>
#include <SDL2/SDL.h>

#define Window_Width 1000
#define Window_Height 1000

SDL_Renderer *renderer;
SDL_Window *window;

void Draw(){
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void Event_Loop(){
    while (1){
        SDL_Event event;
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                break;
            }
        }
    }
}

int Begin(){
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
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED );
    if(renderer == NULL){
        SDL_Log("Can not create render,%s",SDL_GetError());
    }
    Draw();
    Event_Loop();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}

