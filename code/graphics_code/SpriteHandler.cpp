#include "SpriteHandler.hpp"


void SpriteHandler::drawGraphics(vector<vector<string>> spriteNames, sf::Texture* shroom, sf::Texture* ground, sf::Texture* treeTrunk, sf::Texture* treeRoot, sf::RenderWindow* curWindow)
{

	int currentHorDist = 0; 
	int currentVertDist = 0;
	sf::Texture* currentTexture = ground;

	for(auto nameVect : spriteNames){
		for(auto name : nameVect){
			if(name == "Mushroom.png"){
				currentTexture = shroom;
			}else if(name == "Ground.png"){
				currentTexture = ground;
			}else if(name == "TreeTrunk.png"){
				currentTexture = treeTrunk;
			}else if(name == "TreeRoot.png"){
				currentTexture = treeRoot;
			}else{
				throw "Error! Unexpected texture name found in sprite name vector!";
			}

			//sf::Vector2i spritePixelPos = sf::Vector2i(currentHorDist, currentVertDist);
			//sf::Vector2f spriteWorldPos = curWindow->mapPixelToCoords(spritePixelPos);
			
			sf::Sprite currentSprite;
			currentSprite.setTexture(*currentTexture);
			//I am really not sure why, but for some reason what I thought was the vert position is actually the horizontal position.
			currentSprite.setPosition(currentVertDist, currentHorDist);
			curWindow->draw(currentSprite);
			
			currentHorDist += 16;
		}
		currentHorDist = 0;
		currentVertDist += 16;
	}

}

void SpriteHandler::drawCursor(pair<int,int> cursor, sf::RenderWindow& curWindow){
	sf::RectangleShape cursorSquare(sf::Vector2f(16.f,16.f));
	cursorSquare.setFillColor(sf::Color::White);
	cursorSquare.setPosition(16.f*cursor.first, 16.f*cursor.second);
	curWindow.draw(cursorSquare);
}


void SpriteHandler::prepareTexture(sf::Texture* texture, std::string textPath){
	if(!texture->loadFromFile(textPath)){
		throw "Could not load texture with path " + textPath; 
	}
}

string SpriteHandler::texturePathFromName(std::string textureName){
	string result = "../data/sprites/" + textureName;
	return result;
}
