#include "CursorDownCommand.hpp"

CursorDownCommand::CursorDownCommand(World& _world) : world(_world){}

void CursorDownCommand::execute(){
	world.cursorDown();
}
