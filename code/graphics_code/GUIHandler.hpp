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
		GUIHandler(tgui::Gui& _gui);

		void addRightTextBox(tgui::Gui* gui);
		void addBottomTextBox(tgui::Gui* gui);
		void clearRightTextBox();
		void clearBottomTextBox();
		tgui::TextBox::Ptr getRightTextBox();
		tgui::TextBox::Ptr getBottomTextBox();

		sf::View createView();
		void updateView(sf::View* view, float newWidth, float newHeight);
	private:
		tgui::Gui& gui;
		float tGuiPercentToFloat(std::string percent);

		std::string tileInfoBoxName = "rightTextBox";
		std::string worldUpdateBoxName = "bottomTextBox";
		std::string bottomBoxHeightPercent = "20%";
		std::string rightBoxWidthPercent = "15%";
};

#endif
