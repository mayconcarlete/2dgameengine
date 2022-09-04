#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"


Game::Game(){
  // add implementation
  isRunning = false;
  std::cout << " Game constructor called." << std::endl;
}
Game::~Game(){
  // todo destroy
  std::cout << " Game destructor called." << std::endl;
}
void Game::Initialize(){
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cerr << "Error initializing SDL." << std::endl;
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
    std::cerr << "Error creating SDL window." <<std::endl;
    return;
  }
  renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );
  if(!renderer){
    std::cerr << "Error creating SDL Renderer." << std::endl;
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

}
void Game::Update(){}
void Game::Render(){
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);
  // draw here
  // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  // SDL_Rect player = {10, 10, 20, 20};
  // SDL_RenderFillRect(renderer, &player);

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