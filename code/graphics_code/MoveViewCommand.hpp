#ifndef __MOVE_VIEW_COMMAND 
#define __MOVE_VIEW_COMMAND

#include "Command.hpp"

class MoveViewCommand : public Command{
	public:
		MoveViewCommand(sf::RenderWindow* _window, sf::Keyboard::Key _key);
		virtual void execute();

	private:
		std::unique_ptr<sf::RenderWindow> window;
		sf::Keyboard::Key key;
	
};

#endif

