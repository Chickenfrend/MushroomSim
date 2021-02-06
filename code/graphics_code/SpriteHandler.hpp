#ifndef SPRITE_HANDLER
#define SPRITE_HANDLER

#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::pair;

class SpriteHandler{
	public:
		void drawGraphics(vector<vector<string>> spriteNames, sf::Texture* shroom, sf::Texture* ground, sf::Texture* treeTrunk, sf::Texture* treeRoot, sf::RenderWindow* curWindow);
		void drawCursor(pair<int,int> cursor, sf::RenderWindow& curWindow);
		void prepareTexture(sf::Texture* texture, std::string textPath);
		string texturePathFromName(string textureName);
};

#endif
