#ifndef CURSOR_RIGHT_COMMAND
#define CURSOR_RIGHT_COMMAND

#include "CursorMoveCommand.hpp"

class CursorRightCommand : public CursorMoveCommand{
	public:
		CursorRightCommand(World& _world, GUIHandler& _guiHandler);
		virtual void execute();
};

#endif
