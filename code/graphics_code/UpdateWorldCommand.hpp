#ifndef UPDATE_WORLD_COMMAND
#define UPDATE_WOLRD_COMMAND

#include "Command.hpp"
#include "../World.hpp"

class UpdateWorldCommand : public Command{
	public:
		UpdateWorldCommand(World& _world, int _timeStep);
		virtual void execute();
	private:
		World& world;
		int timeStep;
};

#endif
