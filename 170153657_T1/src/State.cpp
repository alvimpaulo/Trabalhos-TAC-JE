#include "State.hpp"
#include <Sprite.hpp>
#include <Music.hpp>
#include <Game.hpp>

State::State()
{
    this->quitRequested = false;
    this->bg = nullptr;
    this->music = nullptr;
}

bool State::QuitRequested()
{
    return this->quitRequested;
}

void State::LoadAssets()
{
    this->bg = new Sprite("assets/img/ocean.jpg");
    this->music = new Music("assets/audio/stageState.ogg");
    this->music->Play();
}

void State::Update(float dt)
{
    if (SDL_QuitRequested())
    {
        this->quitRequested = true;
    }
}

void State::Render()
{   
    this->bg->Render(0, 0);
}