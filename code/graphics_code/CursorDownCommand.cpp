#include "CursorDownCommand.hpp"

CursorDownCommand::CursorDownCommand(World& _world, GUIHandler& _guiHandler) : CursorMoveCommand(_world, _guiHandler){}

void CursorDownCommand::execute(){
	world.cursorDown();
	CursorMoveCommand::execute();
}
