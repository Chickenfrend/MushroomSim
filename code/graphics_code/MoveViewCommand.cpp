#include "MoveViewCommand.hpp"


MoveViewCommand::MoveViewCommand(sf::RenderWindow* _window, sf::Keyboard::Key _key){
	window.reset(_window);
	key = _key;
}


