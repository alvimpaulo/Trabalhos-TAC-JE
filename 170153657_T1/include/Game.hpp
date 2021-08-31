#ifndef GAME_H
#define GAME_H
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include <SDL_include.h>
#include <State.hpp>

class Game
{
private:
    static Game *instance;
    SDL_Window *window;
    SDL_Renderer *renderer;
    State *state;
    Game(std::string title, int width, int height);

public:
    ~Game();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();
    void Run();
};


#endif