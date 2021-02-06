#include "UpdateWorldCommand.hpp"

UpdateWorldCommand::UpdateWorldCommand(World& _world, int _timeStep) : world(_world){
	timeStep = _timeStep;
}

void UpdateWorldCommand::execute(){
	world.update(timeStep);
}

