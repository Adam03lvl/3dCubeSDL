#include<vector>
struct Vec3{
    float x,y,z,d;
};

enum Movx{
    RIGHT=-1,NOX,LEFT
};

enum Movy{
    DOWN=-1,NOY,UP
};

enum Movz{
    FRONT=-1,NOZ,BACK
};

class Cube{
public:
    Movx dirx;
    Movy diry;
    Movz dirz;
    float z, size;
    Vec3 origin;
    std::vector<Vec3> points;
    Cube();
    void move(float initx, float inity);
    void rotate(Vec3 &p, float x, float y, float z);
    ~Cube();
};
