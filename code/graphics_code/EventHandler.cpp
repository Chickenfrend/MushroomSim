#include "EventHandler.hpp"

EventHandler::EventHandler(sf::RenderWindow* _window){
	window.reset(_window);
}

//Concept. To implement continous running, have a boolean in the world class that tells you if it should be running or not.
void EventHandler::handleEvent(sf::Event event){

	switch(event.type){
		case sf::Event::KeyPressed:
			handleKeyPress(event);
			break;
		case sf::Event::MouseWheelScrolled:
			handleMouseWheelScroll(event);
			break;
		default:
			break;
	}
	
}
