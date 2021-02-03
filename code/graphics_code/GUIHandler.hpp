#ifndef __GUI_HANDLER
#define __GUI_HANDLER

#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <algorithm>
//#include "../World.hpp"

using std::vector;

class GUIHandler{
	public:
		void addRightTextBox(tgui::Gui* gui);
		void addBottomTextBox(tgui::Gui* gui);
		sf::View createView();
	private:
		float tGuiPercentToFloat(std::string percent);

		std::string tileInfoBoxName = "rightTextBox";
		std::string worldUpdateBoxName = "bottomTextBox";
		std::string bottomBoxHeightPercent = "20%";
		std::string rightBoxWidthPercent = "15%";
};

#endif