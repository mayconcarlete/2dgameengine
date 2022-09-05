#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

class MovementSystem: public System {
  public:
  MovementSystem(){
    //todo: RequireComponent<TransformComponent>();
    // RequireComponent<...>();
  }
  void Update(){
    // todo:
    // Loop all entities that the system is interested in.
    for(auto entity: GetEntities()){
    // update Entity position based on its velocity
    // every frame of game loop.

    }
  }
}

#endif