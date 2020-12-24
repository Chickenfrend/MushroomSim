#ifndef __GAMEOBJECT 
#define __GAMEOBJECT

#include "WorldState.hpp"
#include <memory>
class GameObject{
	private:
		std::shared_ptr<WorldState> worldState;
	public:
		GameObject(std::shared_ptr<WorldState> newState);
		std::shared_ptr<WorldState> getWorldState();
};
#endif
