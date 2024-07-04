#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <cmath>
#include <iostream>
#include<SDL2/SDL.h>
#include"headers/defs.h"
#include"headers/cube.h"
#include"headers/game.h"

Game::Game(){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cerr<<"Error initializing SDL: "<<SDL_GetError()<<"\n";
        delete(this);
    }

    win = SDL_CreateWindow(
        "Cube",
        0,0,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_FULLSCREEN
    );

    if(!win){
        std::cerr<<"Error initializing window: "<<SDL_GetError()<<"\n";
        delete(this);
    }

    ren = SDL_CreateRenderer(win,-1,0);

    if(!ren){
        std::cerr<<"Error initializing renderer: "<<SDL_GetError()<<"\n";
        delete(this);
    }

    SDL_SetRelativeMouseMode(SDL_TRUE);
    is_running = true;
}

void Game::input(Cube* cube){
    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT){
            is_running=false;
        }
    }
}

void Game::update(float delta_time, Cube* cube){
    for(Vec3 &p: cube->points){
        cube->rotate(p,0.01*cube->diry,0.01*cube->dirx,0.01*cube->dirz);
    }

    cube->dirx = RIGHT;
    cube->diry = UP;
    cube->dirz = FRONT;
}

void Game::render(Cube* cube){
    SDL_SetRenderDrawColor(ren,40,40,40,255);
    SDL_RenderClear(ren);

    SDL_SetRenderDrawColor(ren,0,255,0,255);
    SDL_RenderDrawLine(ren,cube->points[0].x,cube->points[0].y,cube->points[1].x,cube->points[1].y);
    SDL_RenderDrawLine(ren,cube->points[0].x,cube->points[0].y,cube->points[2].x,cube->points[2].y);
    SDL_RenderDrawLine(ren,cube->points[3].x,cube->points[3].y,cube->points[1].x,cube->points[1].y);
    SDL_RenderDrawLine(ren,cube->points[3].x,cube->points[3].y,cube->points[2].x,cube->points[2].y);
    
    SDL_SetRenderDrawColor(ren,0,0,255,255);
    SDL_RenderDrawLine(ren,cube->points[4].x,cube->points[4].y,cube->points[5].x,cube->points[5].y);
    SDL_RenderDrawLine(ren,cube->points[4].x,cube->points[4].y,cube->points[6].x,cube->points[6].y);
    SDL_RenderDrawLine(ren,cube->points[7].x,cube->points[7].y,cube->points[5].x,cube->points[5].y);
    SDL_RenderDrawLine(ren,cube->points[7].x,cube->points[7].y,cube->points[6].x,cube->points[6].y);

    SDL_SetRenderDrawColor(ren,255,0,0,255);
    SDL_RenderDrawLine(ren,cube->points[4].x,cube->points[4].y,cube->points[0].x,cube->points[0].y);
    SDL_RenderDrawLine(ren,cube->points[5].x,cube->points[5].y,cube->points[1].x,cube->points[1].y);
    SDL_RenderDrawLine(ren,cube->points[6].x,cube->points[6].y,cube->points[2].x,cube->points[2].y);
    SDL_RenderDrawLine(ren,cube->points[7].x,cube->points[7].y,cube->points[3].x,cube->points[3].y);

    SDL_RenderPresent(ren);
}

Game::~Game(){
    SDL_DestroyWindow(win);    
    SDL_DestroyRenderer(ren);    
    SDL_Quit();
    exit(-1);
}
