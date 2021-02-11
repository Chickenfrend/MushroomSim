#include "GameObject.hpp"

GameObject::GameObject(std::shared_ptr<WorldState> newState) {
  worldState = newState;
}

std::shared_ptr<WorldState> GameObject::getWorldState() { return worldState; }
