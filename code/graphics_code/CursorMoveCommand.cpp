#include "CursorMoveCommand.hpp"


CursorMoveCommand::CursorMoveCommand(World& _world, GUIHandler& _guiHandler) : world(_world), guiHandler(_guiHandler){}

void CursorMoveCommand::execute(){
	guiHandler.clearRightTextBox();
	GroundInfoWriter infoWriter(world.getCursorGround());
	infoWriter.writeToBox(guiHandler.getRightTextBox());
}
