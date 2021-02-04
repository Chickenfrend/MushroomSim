#ifndef COMMAND
#define COMMAND
#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include "../World.hpp"

class Command{
	public:
		virtual ~Command(){}
		virtual void execute() = 0;
};


#endif
