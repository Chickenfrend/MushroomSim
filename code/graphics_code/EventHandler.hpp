#ifndef __EVENT_HANDLER
#define __EVENT_HANDLER

#include "../World.hpp"
#include "AdjustZoomCommand.hpp"
#include "CursorDownCommand.hpp"
#include "CursorLeftCommand.hpp"
#include "CursorRightCommand.hpp"
#include "CursorUpCommand.hpp"
#include "GUIHandler.hpp"
#include "MoveViewCommand.hpp"
#include "UpdateWorldCommand.hpp"
#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>

class EventHandler {
	public:
	EventHandler(sf::RenderWindow &_window, World &_world, GUIHandler &_guiHandler);
	void setTimeStep(int _timeStep);
	Command *handleEvent(sf::Event event);

	private:
	sf::RenderWindow &window;
	World &world;
	GUIHandler &guiHandler;
	sf::Vector2f initialViewSize;
	int timeStep = 300;
	Command *handleKeyPress(sf::Event event);
	void handleMouseWheelScroll(sf::Event event);
};

#endif
