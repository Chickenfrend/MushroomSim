#ifndef CURSOR_LEFT_COMMAND
#define CURSOR_LEFT_COMMAND

#include "Command.hpp"

class CursorLeftCommand : public Command{
	public:
		CursorLeftCommand(World& _world);
		virtual void execute();
	private:
		World& world;
};

#endif
