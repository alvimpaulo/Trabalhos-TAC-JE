#include "Music.hpp"

Music::Music()
{
    this->music = nullptr;
}
Music::Music(std::string file)
{
    this->music = nullptr;
    this->Open(file);
}

Music::~Music()
{
    this->Stop();
    if (this->music)
        Mix_FreeMusic(this->music);
}

void Music::Play(int times)
{

    if (this->music == nullptr)
    {
        std::cerr << "Music not loaded, please load it first" << std::endl;
        return;
    }

    int result = Mix_PlayMusic(this->music, times);
    if (result != 0)
    {
        std::cerr << "Error playing music" << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }
}
void Music::Stop(int msToStop)
{
    if (this->music)
    {
        int result = Mix_FadeOutMusic(msToStop);
        if (result == 0)
        {
            std::cerr << "Error stoping music" << std::endl;
            std::cerr << Mix_GetError() << std::endl;
            std::abort();
        }
    }
}
void Music::Open(std::string file)
{
    this->music = Mix_LoadMUS(file.c_str());
    if (this->music == nullptr)
    {
        std::cerr << "Error opening music from file " << file << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        std::abort();
    }
}
bool Music::isOpen()
{
    return this->music != nullptr;
}