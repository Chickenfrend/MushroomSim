#ifndef CURSOR_RIGHT_COMMAND
#define CURSOR_RIGHT_COMMAND

#include "Command.hpp"

class CursorRightCommand : public Command{
	public:
		CursorRightCommand(World& _world);
		virtual void execute();
	private:
		World& world;
};

#endif
