#include "CursorLeftCommand.hpp"

CursorLeftCommand::CursorLeftCommand(World& _world, GUIHandler& _guiHandler) : CursorMoveCommand(_world,_guiHandler){}

void CursorLeftCommand::execute(){
	world.cursorLeft();
	CursorMoveCommand::execute();
}
