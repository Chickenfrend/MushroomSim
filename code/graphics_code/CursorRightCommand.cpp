#include "CursorRightCommand.hpp"

CursorRightCommand::CursorRightCommand(World& _world) : world(_world){}

void CursorRightCommand::execute(){
	std::cout << "About to move the cursor to the right" << std::endl;
	world.cursorRight();
}
