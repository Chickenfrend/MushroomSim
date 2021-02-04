#ifndef __MOVE_VIEW_COMMAND 
#define __MOVE_VIEW_COMMAND

#include "Command.hpp"

class MoveViewCommand : public Command{
	public:
		~MoveViewCommand();
		MoveViewCommand(sf::RenderWindow* _window, sf::Keyboard::Key _key);
		void setKey(sf::Keyboard::Key _key);
		void setWindow(sf::RenderWindow* _window);
		virtual void execute();

	private:
		sf::RenderWindow* window;
		sf::Keyboard::Key key;
		float offset = 32;
	
};

#endif

