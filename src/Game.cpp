#include <iostream>
#include "Game.h"


Game::Game(){
  // add implementation
  std::cout << " Game constructor called." << std::endl;
}
Game::~Game(){
  // todo destroy
  std::cout << " Game destructor called." << std::endl;
}
void Game::Initialize(){

}
void Game::Run(){

}
void Game::ProcessInput(){}
void Game::Update(){}
void Game::Render(){}
void Game::Destroy(){}
