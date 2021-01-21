#ifndef __GRAPHICS_HANDLER
#define __GRAPHICS_HANDLER

#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
//#include "../World.hpp"

class GraphicsHandler{
	public:
		void LaunchDisplay();
	private:
		sf::RectangleShape makeSideRectangle();
};

#endif
