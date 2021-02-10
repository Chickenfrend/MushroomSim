#include "CursorUpCommand.hpp"

CursorUpCommand::CursorUpCommand(World& _world, GUIHandler& _guiHandler):CursorMoveCommand(_world, _guiHandler){}

void CursorUpCommand::execute(){
	world.cursorUp();
	CursorMoveCommand::execute();
}
