#ifndef __GRAPHICS_HANDLER
#define __GRAPHICS_HANDLER

#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
//#include "../World.hpp"

class GraphicsHandler{
	public:
		void LaunchDisplay();
	private:
		void addRightTextBox(tgui::Gui* gui);
		void addBottomTextBox(tgui::Gui* gui);
		std::string tileInfoBoxName = "rightTextBox";
		std::string worldUpdateBoxName = "bottomTextBox";
};

#endif
