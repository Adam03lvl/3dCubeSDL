class Game{
public:
    SDL_Window* win;
    SDL_Renderer* ren;
    SDL_Event e;

    bool is_running;

    Game();
    void input(Cube* cube);
    void update(float delta_time, Cube* cube);
    void render(Cube* cube);
    ~Game();
};
