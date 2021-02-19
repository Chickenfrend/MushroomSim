#ifndef UPDATE_WORLD_COMMAND
#define UPDATE_WORLD_COMMAND

#include "Command.hpp"
#include "GUIHandler.hpp"
#include "GroundInfoWriter.hpp"
#include "../World.hpp"

class UpdateWorldCommand : public Command{
	public:
		UpdateWorldCommand(World& _world, GUIHandler& _gHandler, int _timeStep);
		virtual void execute();
	private:
		World& world;
		GUIHandler& gHandler;
		int timeStep;
};

#endif
