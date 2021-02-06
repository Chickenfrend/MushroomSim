#ifndef CURSOR_DOWN_COMMAND
#define CURSOR_DOWN_COMMAND

#include "Command.hpp"

class CursorDownCommand : public Command{
	public:
		CursorDownCommand(World& _world);
		virtual void execute();
	private:
		World& world;
};

#endif
