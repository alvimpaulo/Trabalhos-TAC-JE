#ifndef SPRITE_H
#define SPRITE_H

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include <SDL_include.h>
#include <iostream>

class Sprite
{
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite();
    Sprite(std::string file);
    ~Sprite();

    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
};

#endif