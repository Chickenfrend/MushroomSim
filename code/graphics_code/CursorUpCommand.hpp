#ifndef CURSOR_UP_COMMAND
#define CURSOR_UP_COMMAND

#include "CursorMoveCommand.hpp"

class CursorUpCommand : public CursorMoveCommand{
	public:
		CursorUpCommand(World& _world, GUIHandler& _guiHandler);
		void execute() override;
};

#endif
