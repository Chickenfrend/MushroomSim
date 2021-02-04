#include "MoveViewCommand.hpp"


MoveViewCommand::MoveViewCommand(sf::RenderWindow* _window, sf::Keyboard::Key _key){
	window.reset(_window);
	key = _key;
}

void MoveViewCommand::execute(){
	sf::View curView = window->getView();
	switch(key){
		case sf::Keyboard::Key::Left:
			curView.move(-offset,0.f);
			break;
		case sf::Keyboard::Key::Right:
			curView.move(offset,0.f);
			break;
		case sf::Keyboard::Key::Up:
			curView.move(0.f, -offset);
			break;
		case sf::Keyboard::Key::Down:
			curView.move(0.f, offset);
			break;
		default:
			break;
	}
	window->setView(curView);
}


