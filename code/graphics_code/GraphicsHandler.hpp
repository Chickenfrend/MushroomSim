#ifndef __GRAPHICS_HANDLER
#define __GRAPHICS_HANDLER

#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <algorithm>
//#include "../World.hpp"

using std::vector;

class GraphicsHandler{
	public:
		void LaunchDisplay();
		void addRightTextBox(tgui::Gui* gui);
		void addBottomTextBox(tgui::Gui* gui);
		void drawGraphics(vector<vector<std::string>> spriteNames, sf::Texture* shroom, sf::Texture* ground, sf::Texture* treeTrunk, sf::Texture* treeRoot,sf::RenderWindow curWindow);
	private:
		std::string texturePathFromName(std::string textureName);
		float tGuiPercentToFloat(std::string percent);
		void prepareTexture(sf::Texture* texture, std::string textPath);
		sf::View createView();
		std::string tileInfoBoxName = "rightTextBox";
		std::string worldUpdateBoxName = "bottomTextBox";
		std::string bottomBoxHeightPercent = "20%";
		std::string rightBoxWidthPercent = "15%";
};

#endif
