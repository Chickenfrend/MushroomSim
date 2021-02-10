#ifndef CURSOR_DOWN_COMMAND
#define CURSOR_DOWN_COMMAND

#include "CursorMoveCommand.hpp"

class CursorDownCommand : public CursorMoveCommand{
	public:
		CursorDownCommand(World& _world, GUIHandler& _guiHandler);
		virtual void execute() override;
};

#endif
