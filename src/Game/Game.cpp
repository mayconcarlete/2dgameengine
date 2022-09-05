#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>

#include "Game.h"
#include "../Logger/Logger.h"
#include "../ECS/ECS.h"

Game::Game(){
  // add implementation
  isRunning = false;
  Logger::Log("Game constructor called.");
}
Game::~Game(){
  // todo destroy
  Logger::Log("Game destructor called.");
}

void Game::Initialize(){
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    Logger::Err("Error initializing SDL.");
    return;
  }
  // fake fullscreen mode.
  // da para entender como fake fullscreen a tela cheia mas vendo o menu do desktop.
  // por exemplo a barra de menu do windows.
  // ja com o real fullscreen vc vai pegar a tela toda removendo ate o menu da tela.
  // to set to real full screen we need to call the function SDL_SetWindowFullscreen.
  SDL_DisplayMode displayMode;
  SDL_GetCurrentDisplayMode(0, &displayMode);
  windowWidth = 800; // displayMode.w;
  windowHeight = 600; // displayMode.h;

  // create a window.
  window = SDL_CreateWindow(
    "My Game Engine.",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    windowWidth,
    windowHeight,
    SDL_WINDOW_BORDERLESS
  );
  if(!window){
    Logger::Err("Error creating SDL window.");
    return;
  }
  renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );
  if(!renderer){
    Logger::Err("Error creating SDL Renderer.");
    return;
  }
  // to set to real full screen we need to call the function SDL_SetWindowFullscreen
  // SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
  isRunning = true;
}
void Game::ProcessInput(){
  SDL_Event sdlEvent;
  while(SDL_PollEvent(&sdlEvent)){
    switch (sdlEvent.type)
    {
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_KEYDOWN:
      if(sdlEvent.key.keysym.sym == SDLK_ESCAPE){
        isRunning = false;
      }
      if(sdlEvent.key.keysym.sym == SDLK_e){
        std::cout << "Tecla E apertada" << std::endl;
      }
      break;
    case SDL_KEYUP:
      if(sdlEvent.key.keysym.sym == SDLK_e){
        std::cout << "Tecla E soltada"<< std::endl;
      }
      break;
    }
  }

}


void Game::Setup(){
  // todo:
  // Entity tank = registry.CreateEntity();
  // tank.AddComponent<TransformComponent>();
  // tank.AddComponent<BoxCollider>();
  // tank.AddComponent<SpriteComponent>("./assets/images/tank.png")
}
void Game::Update(){
  // if we are too fast we going to waste time until we reach the MILLISECONDS_PER_FRAME
  // while(!SDL_TICKS_PASSED(SDL_GetTicks(), millisecondsPreviousFrame + MILLISECS_PER_FRAME));
  // usando o SDL_Delay a gente delega esse delay pro sistema operacional, economizando o uso de CPU.
  int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecondsPreviousFrame);
  if(timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME){
    SDL_Delay(timeToWait);
  }
  // the difference in ticks since the last frame, converted to seconds.
  double deltaTime = (SDL_GetTicks() - millisecondsPreviousFrame)/1000.0;
  // control the fps here until we reach the MILLISEC_PER_FRAME
  millisecondsPreviousFrame = SDL_GetTicks();
  // MovementSystem.Update();
  // CollisionSystem.Update();
  // DamageSystem.Update();
}
void Game::Render(){
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);
  // draw here
  // desenha um retangulo
  // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  // SDL_Rect player = {10, 10, 20, 20};
  // SDL_RenderFillRect(renderer, &player);

  // carrega um PNG
  // SDL_Surface* surface = IMG_Load("./assets/images/tank-tiger-right.png");
  // SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  // SDL_FreeSurface(surface);
  // SDL_Rect dstRect = {
  //   static_cast<int>(playerPosition.x), // parse float to integer
  //   static_cast<int>(playerPosition.y), // parse float to integer
  //   32,
  //   32
  // };
  // // render copy pode pegar um pedaço do png(onde está o null) bom para usar quando queremos
  // // pega só um pedaço da imagem.
  // SDL_RenderCopy(renderer, texture, NULL, &dstRect);
  // SDL_DestroyTexture(texture);


  // todo: Render Game Objects

  SDL_RenderPresent(renderer);
}

void Game::Run(){
  Setup();
  while(isRunning){
    ProcessInput();
    Update();
    Render();

  }
}

void Game::Destroy(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
