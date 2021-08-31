#include "Game.hpp"
#include <iostream>
#include <Sprite.hpp>

Game*Game::instance;

Game &Game::GetInstance()
{

    if (Game::instance != nullptr)
        return *(Game::instance);
    else
    {
        Game::instance = new Game("Paulo Alvim - 170153657", 1024, 600);
        return *(Game::instance);
    }
}

Game::Game(std::string title, int width, int height)
{
    if (this->instance != nullptr)
    {
        std::cerr << "Instance already exists in game constructor" << std::endl;
        std::abort();
    }
    else
    {
        this->instance = this;
    }

    int sdlError = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

    if (sdlError != 0)
    {
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }

    sdlError = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

    if (sdlError == 0)
    {
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }

    sdlError = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,
                             MIX_DEFAULT_FORMAT,
                             MIX_DEFAULT_CHANNELS, 1024);

    if (sdlError != 0)
    {
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }

    Mix_AllocateChannels(32);

    this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (this->window == nullptr)
    {
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    if (this->renderer == nullptr)
    {
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }

    this->state = new State();
}

Game::~Game()
{
    delete this->state;

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State &Game::GetState()
{
    return *(this->state);
}

SDL_Renderer *Game::GetRenderer()
{
    return this->renderer;
}

void Game::Run()
{
    this->state->LoadAssets();

    while (!this->state->QuitRequested())
    {

        this->state->Update(33);
        this->state->Render();

        SDL_RenderPresent(this->renderer);

        SDL_Delay(33);
    }
}