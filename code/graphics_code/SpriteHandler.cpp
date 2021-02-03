#include "SpriteHandler.hpp"


void SpriteHandler::drawGraphics(vector<vector<string>> spriteNames, sf::Texture* shroom, sf::Texture* ground, sf::Texture* treeTrunk, sf::Texture* treeRoot, sf::RenderWindow* curWindow){

	int size = spriteNames.size()*spriteNames.size();
	int currentHorDist = 0; 
	int currentVertDist = 0;
	sf::Texture* currentTexture = ground;

	for(auto nameVect : spriteNames){
		std::cout << "About to iterate through namevector with size " << nameVect.size() << std::endl;
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
				throw "Error! Unexpexted texture name found in sprite name vector!";
			}

			//sf::Vector2i spritePixelPos = sf::Vector2i(currentHorDist, currentVertDist);
			//sf::Vector2f spriteWorldPos = curWindow->mapPixelToCoords(spritePixelPos);
			
			std::cout << "About to draw a sprite!" << std::endl;
			sf::Sprite currentSprite;
			currentSprite.setTexture(*currentTexture);
			currentSprite.setPosition(sf::Vector2f(currentHorDist, currentVertDist));
			curWindow->draw(currentSprite);
			
			currentHorDist += 16;
		}
		currentHorDist = 0;
		currentVertDist += 16;
	}

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
