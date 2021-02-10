#ifndef CURSOR_LEFT_COMMAND
#define CURSOR_LEFT_COMMAND

#include "CursorMoveCommand.hpp"

class CursorLeftCommand : public CursorMoveCommand{
	public:
		CursorLeftCommand(World& _world, GUIHandler& _guiHandler);
		virtual void execute();
};

#endif
