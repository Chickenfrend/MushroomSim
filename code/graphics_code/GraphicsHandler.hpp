#ifndef __GRAPHICS_HANDLER
#define __GRAPHICS_HANDLER

#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <algorithm>
//#include "../World.hpp"

class GraphicsHandler{
	public:
		void LaunchDisplay();
	private:
		void addRightTextBox(tgui::Gui* gui);
		void addBottomTextBox(tgui::Gui* gui);
		float tGuiPercentToFloat(std::string percent);
		sf::View createView();
		std::string tileInfoBoxName = "rightTextBox";
		std::string worldUpdateBoxName = "bottomTextBox";
		std::string bottomBoxHeightPercent = "20%";
		std::string rightBoxWidthPercent = "15%";

};

#endif
