#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "../ECS/ECS.h"

const int FPS = 100;
const int MILLISECS_PER_FRAME = 1000 / FPS;

class Game {
  private:
    bool isRunning;
    int millisecondsPreviousFrame = 0;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Registry* registry;
  public:
    int windowWidth;
    int windowHeight;
    Game();
    ~Game();
    void Initialize();
    void Run();
    void Setup();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};

#endif