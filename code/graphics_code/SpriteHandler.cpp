#include "SpriteHandler.hpp"

SpriteHandler::SpriteHandler(){
	loadSpriteCoordinates();
	prepareSpriteSheet();
}

void SpriteHandler::drawGraphics(vector<vector<string>> spriteNames, sf::RenderWindow *curWindow) {

	int currentHorDist = 0;
	int currentVertDist = 0;
	pair<int, int> spriteCoords;

	for (auto nameVect : spriteNames) {
		for (auto name : nameVect) {
			if(spriteNameCoords.find(name) != spriteNameCoords.end()){
				spriteCoords = spriteNameCoords.at(name);
			}else{
				throw std::runtime_error("Unkown texture name " + name);
			}
			

			// sf::Vector2i spritePixelPos = sf::Vector2i(currentHorDist, currentVertDist);
			// sf::Vector2f spriteWorldPos = curWindow->mapPixelToCoords(spritePixelPos);

			sf::Sprite currentSprite;
			currentSprite.setTexture(spriteSheet);
			currentSprite.setTextureRect(sf::IntRect(16*spriteCoords.first, 16*spriteCoords.second, 16, 16));
			// I am really not sure why, but for some reason what I thought was the vert position is actually the horizontal position.
			currentSprite.setPosition(currentVertDist, currentHorDist);
			curWindow->draw(currentSprite);

			currentHorDist += 16;
		}
		currentHorDist = 0;
		currentVertDist += 16;
	}
}

void SpriteHandler::loadSpriteCoordinates() {
	std::ifstream coordFile(spriteCoordPath);

	std::string line;
	std::string firstLine;
	std::string treeName;

	if (!coordFile.is_open()) {
		throw std::runtime_error("Could not open the sprite coordinates file");
	}

	if (coordFile.good()) {
		std::getline(coordFile, firstLine);
	} else {
		throw std::runtime_error("Coordfile is not good");
	}

	while (std::getline(coordFile, line)) {
		string spriteName;
		string xPos, yPos;
		std::istringstream stream(line);
		std::getline(stream, spriteName, ',');
		std::getline(stream, xPos, ',');
		std::getline(stream, yPos);
		pair<int, int> coords = {std::stoi(xPos), std::stoi(yPos)};
		spriteNameCoords.insert({spriteName, coords});
	}
}

void SpriteHandler::prepareSpriteSheet(){
	if(!spriteSheet.loadFromFile(spriteSheetPath)){
		throw "Could not load sprite sheet!";
	}
}

void SpriteHandler::drawCursor(pair<int, int> cursor, sf::RenderWindow &curWindow) {
	sf::RectangleShape cursorSquare(sf::Vector2f(16.f, 16.f));
	cursorSquare.setFillColor(sf::Color::White);
	cursorSquare.setPosition(16.f * cursor.first, 16.f * cursor.second);
	curWindow.draw(cursorSquare);
}

void SpriteHandler::prepareTexture(sf::Texture *texture, std::string textPath) {
	if (!texture->loadFromFile(textPath)) {
		throw "Could not load texture with path " + textPath;
	}
}

string SpriteHandler::texturePathFromName(std::string textureName) {
	string result = "../data/sprites/" + textureName;
	return result;
}
