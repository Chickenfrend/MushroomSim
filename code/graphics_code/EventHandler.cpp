#include "EventHandler.hpp"

EventHandler::EventHandler(sf::RenderWindow& _window, World& _world) : window(_window), world{_world}{
	initialViewSize = window.getView().getSize();
}

void EventHandler::setTimeStep(int _timeStep){
	timeStep = _timeStep;
}

//Concept. To implement continous running, have a boolean in the world class that tells you if it should be running or not.
Command* EventHandler::handleEvent(sf::Event event){
	Command* result;
	switch(event.type){
		case sf::Event::KeyPressed:
			result = handleKeyPress(event);
			break;
		case sf::Event::MouseWheelScrolled:
			result = new AdjustZoomCommand(window, event.mouseWheelScroll.delta, initialViewSize.x, 300);
			break;
		default:
			result = nullptr;
	}

	return result;
	
}

Command* EventHandler::handleKeyPress(sf::Event event){
	Command* result;
	switch(event.key.code){
		case sf::Keyboard::Key::Left:
			result = new MoveViewCommand(window, event.key.code);
			break;
		case sf::Keyboard::Key::Right:
			result = new MoveViewCommand(window, event.key.code);
			break;
		case sf::Keyboard::Key::Up:
			result = new MoveViewCommand(window, event.key.code);
			break;
		case sf::Keyboard::Key::Down:
			result = new MoveViewCommand(window, event.key.code);
			break;
		case sf::Keyboard::Key::U:
			std::cout << "About to update world " << timeStep << " years!" << std::endl;
			result = new UpdateWorldCommand(world, timeStep);
			break;
		case sf::Keyboard::Key::A:
			result = new CursorLeftCommand(world);
			break;
		case sf::Keyboard::Key::D:
			result = new CursorRightCommand(world);
			break;
		case sf::Keyboard::Key::W:
			result = new CursorUpCommand(world);
			break;
		case sf::Keyboard::Key::S:
			result = new CursorDownCommand(world);
			break;
		default:
			result = nullptr;
	}
	return result;
}
