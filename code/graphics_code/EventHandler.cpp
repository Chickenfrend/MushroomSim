#include "EventHandler.hpp"

EventHandler::EventHandler(sf::RenderWindow& _window, World* _world) : window(_window){
	world = _world;
}

void EventHandler::setTimeStep(int _timeStep){
	timeStep = _timeStep;
}

//Concept. To implement continous running, have a boolean in the world class that tells you if it should be running or not.
Command* EventHandler::handleEvent(sf::Event event){
	switch(event.type){
		case sf::Event::KeyPressed:
			return handleKeyPress(event);
			break;
		/*
		case sf::Event::MouseWheelScrolled:
			handleMouseWheelScroll(event);
			break;
			*/
		default:
			return nullptr;
	}
	
}

Command* EventHandler::handleKeyPress(sf::Event event){
	switch(event.key.code){
		case sf::Keyboard::Key::Left:
			return new MoveViewCommand(window, event.key.code);
			break;
		case sf::Keyboard::Key::Right:
			return new MoveViewCommand(window, event.key.code);
			break;
		case sf::Keyboard::Key::Up:
			return new MoveViewCommand(window, event.key.code);
			break;
		case sf::Keyboard::Key::Down:
			return new MoveViewCommand(window, event.key.code);
			break;
		case sf::Keyboard::Key::U:
			std::cout << "About to update world " << timeStep << " years!" << std::endl;
			return new UpdateWorldCommand(world, timeStep);
			break;
		default:
			return nullptr;
	}
}
