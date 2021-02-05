#ifndef ADJUST_ZOOM_COMMAND
#define ADJUST_ZOOM_COMMAND

#include "Command.hpp"

class AdjustZoomCommand : public Command{
	public:
		AdjustZoomCommand(sf::RenderWindow& _window, float _delta, float _maxWidth, float _minWidth);
		virtual void execute();
	
	private:
		sf::RenderWindow& window;
		float delta;
		float maxWidth;
		float minWidth;
		float zoomFactor = 10.f;


};

#endif
