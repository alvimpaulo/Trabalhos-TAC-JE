#include "Sprite.hpp"
#include <Game.hpp>

Sprite::Sprite()
{
    this->texture = nullptr;
}

Sprite::Sprite(std::string file)
{
    this->texture = nullptr;

    this->Open(file);
}

Sprite::~Sprite()
{
    if (this->texture != nullptr)
        SDL_DestroyTexture(this->texture);
}

void Sprite::Open(std::string file)
{
    if (this->texture != nullptr)
        SDL_DestroyTexture(this->texture);

    this->texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

    if (this->texture == nullptr)
    {
        std::cerr << "Error loading texture from file " << file << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }

    int queryError = SDL_QueryTexture(this->texture, nullptr, nullptr, &(this->width), &(this->height));
    if(queryError){
        std::cerr << "Error querying texture from file " << file << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }

    this->SetClip(0, 0, this->width, this->height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    this->clipRect.x = x;
    this->clipRect.y = y;
    this->clipRect.w = w;
    this->clipRect.h = h;
}

void Sprite::Render(int x, int y)
{
    if (this->texture == nullptr)
    {
        std::cerr << "Null texture" << std::endl;
        return;
    }

    SDL_Rect renderRect = SDL_Rect();
    renderRect.x = x;
    renderRect.y = y;
    renderRect.w = this->clipRect.w;
    renderRect.h = this->clipRect.h;
    int result = SDL_RenderCopy(Game::GetInstance().GetRenderer(), this->texture, &(this->clipRect), &renderRect);
    if (result != 0)
    {
        std::cerr << "Error updating sprite render " << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }
}

int Sprite::GetHeight()
{
    return this->height;
}

int Sprite::GetWidth()
{
    return this->width;
}

bool Sprite::IsOpen()
{
    return (this->texture != nullptr);
}