#ifndef CURSOR_MOVE_COMMAND
#define CURSOR_MOVE_COMMAND

#include "Command.hpp"
#include "../World.hpp"
#include "GUIHandler.hpp"
#include "GroundInfoWriter.hpp"

class CursorMoveCommand : public Command{
	public:
		CursorMoveCommand(World& _world, GUIHandler& _guiHandler);
		virtual void execute();
	protected:
		World& world;
		GUIHandler& guiHandler;
};

#endif
