#include <iostream>
#include <numeric>
#include<SDL2/SDL.h>
#include"headers/defs.h"
#include"headers/cube.h"
#include"headers/game.h"

Cube::Cube(){
    dirx=NOX;
    diry=NOY;
    dirz=NOZ;
    size=400;
    z=size/2;
    move((int)(WINDOW_WIDTH/2),(int)(WINDOW_HEIGHT/2));
}

void Cube::move(float initx, float inity){
    if(z<=1)z++;
    if(size<=10)return;

    origin=(Vec3){initx,inity,z};

    points={
        (Vec3){origin.x - size/2, origin.y - size/2,z-(size/2)},
        (Vec3){origin.x + size/2, origin.y - size/2,z-(size/2)},
        (Vec3){origin.x - size/2, origin.y + size/2,z-(size/2)},
        (Vec3){origin.x + size/2, origin.y + size/2,z-(size/2)},
        (Vec3){origin.x - size/2, origin.y - size/2,z+(size/2)},
        (Vec3){origin.x + size/2, origin.y - size/2,z+(size/2)},
        (Vec3){origin.x - size/2, origin.y + size/2,z+(size/2)},
        (Vec3){origin.x + size/2, origin.y + size/2,z+(size/2)}
    };
}

void Cube::rotate(Vec3 &p, float x, float y, float z){
    float rad=0;
    
    p.x-=origin.x;
    p.y-=origin.y;
    p.z-=origin.z;

    rad=x;
    p.y= std::cos(rad) * p.y - std::sin(rad) * p.z;
    p.z= std::sin(rad) * p.y + std::cos(rad) * p.z;

    rad=y;
    p.x= std::cos(rad) * p.x + std::sin(rad) * p.z;
    p.z= -std::sin(rad) * p.x + std::cos(rad) * p.z;

    rad=z;
    p.x= std::cos(rad) * p.x - std::sin(rad) * p.y;
    p.y= std::sin(rad) * p.x + std::cos(rad) * p.y;
    
    p.x+=origin.x;
    p.y+=origin.y;
    p.z+=origin.z;
}

Cube::~Cube(){
    
}
