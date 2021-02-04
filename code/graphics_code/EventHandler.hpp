#ifndef __EVENT_HANDLER
#define __EVENT_HANDLER

#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include "GUIHandler.hpp"
#include "MoveViewCommand.hpp"

class EventHandler{
	public:
		EventHandler(sf::RenderWindow* _window);
		Command* handleEvent(sf::Event event);
		
	private:
		std::unique_ptr<sf::RenderWindow> window;
		void handleKeyPress(sf::Event event);
		void handleMouseWheelScroll(sf::Event event);
		MoveViewCommand* move_view;
		
};


#endif
