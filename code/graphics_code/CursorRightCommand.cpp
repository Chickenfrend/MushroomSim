#include "CursorRightCommand.hpp"

CursorRightCommand::CursorRightCommand(World& _world, GUIHandler& _guiHandler) : CursorMoveCommand(_world, _guiHandler){}

void CursorRightCommand::execute(){
	world.cursorRight();
	CursorMoveCommand::execute();
}
