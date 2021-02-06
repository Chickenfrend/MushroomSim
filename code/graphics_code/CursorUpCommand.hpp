#ifndef CURSOR_UP_COMMAND
#define CURSOR_UP_COMMAND

#include "Command.hpp"

class CursorUpCommand : public Command{
	public:
		CursorUpCommand(World& _world);
		virtual void execute();
	private:
		World& world;
};

#endif
