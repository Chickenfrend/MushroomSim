#include "CursorUpCommand.hpp"

CursorUpCommand::CursorUpCommand(World& _world) : world(_world){}

void CursorUpCommand::execute(){
	world.cursorUp();
}
