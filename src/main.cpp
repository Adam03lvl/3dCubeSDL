#include <iostream>
#include<SDL2/SDL.h>
#include"headers/defs.h"
#include"headers/cube.h"
#include"headers/game.h"

float delta_time(){
    static int last_frame_time=0;

    float time_to_wait=FRAME_TARGET_TIME-(SDL_GetTicks64()-last_frame_time);
    if(time_to_wait>0 && time_to_wait<=FRAME_TARGET_TIME){
        SDL_Delay(time_to_wait);
    }

    float delta_time=(SDL_GetTicks64()-last_frame_time)/1000.0;
    last_frame_time=SDL_GetTicks64();

    return delta_time;
}

int main(int argc, const char* argv[]){
    Game *game = new Game(); 
    Cube *cube = new Cube();
    float dt=0;

    while(game->is_running){
        dt=delta_time();
        game->input(cube); 
        game->update(dt,cube); 
        game->render(cube); 
    }

    delete(game);
    return 0;
}
