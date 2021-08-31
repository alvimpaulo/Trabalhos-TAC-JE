#ifndef STATE_H
#define STATE_H
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include <SDL_include.h>
#include <Sprite.hpp>
#include <Music.hpp>
class State
{
private:
    Sprite *bg;
    Music *music;
    bool quitRequested;

public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};

#endif