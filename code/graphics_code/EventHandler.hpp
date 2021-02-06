#ifndef __EVENT_HANDLER
#define __EVENT_HANDLER

#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include "GUIHandler.hpp"
#include "MoveViewCommand.hpp"
#include "AdjustZoomCommand.hpp"
#include "UpdateWorldCommand.hpp"
#include "CursorLeftCommand.hpp"
#include "CursorRightCommand.hpp"
#include "CursorUpCommand.hpp"
#include "CursorDownCommand.hpp"
#include "../World.hpp"

class EventHandler{
	public:
		EventHandler(sf::RenderWindow& _window, World& _world);
		void setTimeStep(int _timeStep);
		Command* handleEvent(sf::Event event);
		
	private:
		sf::RenderWindow& window;
		sf::Vector2f initialViewSize;
		World& world;
		int timeStep = 300;
		Command* handleKeyPress(sf::Event event);
		void handleMouseWheelScroll(sf::Event event);	
};


#endif
