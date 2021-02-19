#include "UpdateWorldCommand.hpp"

UpdateWorldCommand::UpdateWorldCommand(World& _world, GUIHandler& _gHandler, int _timeStep) : world(_world), gHandler(_gHandler){
	timeStep = _timeStep;
}

void UpdateWorldCommand::execute(){
	world.update(timeStep);
	gHandler.updateBottomTextBox(world.getWorldState().getUpdateInfo().getText());
	gHandler.clearRightTextBox();
	GroundInfoWriter infoWriter(world.getCursorGround());
	infoWriter.writeToBox(gHandler.getRightTextBox());

}

