#ifndef ADJUST_ZOOM_COMMAND
#define ADJUST_ZOOM_COMMAND

#include "Command.hpp"

class AdjustZoomCommand : public Command{
	public:
		AdjustZoomCommand(sf::RenderWindow& _window, float _delta);
		virtual void execute();
	
	private:
		sf::RenderWindow& window;
		float delta;
		float zoomFactor = 10.f;

};

#endif
