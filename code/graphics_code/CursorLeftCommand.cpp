#include "CursorLeftCommand.hpp"

CursorLeftCommand::CursorLeftCommand(World& _world) : world(_world){}

void CursorLeftCommand::execute(){
	world.cursorLeft();
}
