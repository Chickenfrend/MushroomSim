#ifndef SPRITE_HANDLER
#define SPRITE_HANDLER

#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>

using std::vector;
using std::string;
using std::pair;

class SpriteHandler{
	public:
		SpriteHandler();
		void drawGraphics(vector<vector<string>> spriteNames, sf::RenderWindow* curWindow);
		void drawCursor(pair<int,int> cursor, sf::RenderWindow& curWindow);
		string texturePathFromName(string textureName);
	private:
		void loadSpriteCoordinates();
		void prepareSpriteSheet();
		void prepareTexture(sf::Texture* texture, std::string textPath);
		sf::Texture spriteSheet;
		std::string spriteSheetPath = "../data/sprites/SpriteSheet.png";
		std::string spriteCoordPath = "../data/sprites/SpriteCoordinates.csv";
		std::map<string, pair<int,int>> spriteNameCoords;
};

#endif
