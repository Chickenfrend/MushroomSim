#include "GraphicsHandler.hpp"

void GraphicsHandler::LaunchDisplay(){

	sf::RenderWindow window(sf::VideoMode(1600,900), "Mushroom Sim?");
	window.setVerticalSyncEnabled(true);
	tgui::Gui gui(window);

	addRightTextBox(&gui);
	addBottomTextBox(&gui);

	sf::View gameView;
	gameView = createView();
	gameView.zoom(0.5f);
	window.setView(gameView);

	sf::Texture shroomTexture;
	sf::Texture groundTexture;
	sf::Texture treeTrunkTexture;
	sf::Texture treeRootTexture;
	
	prepareTexture(&shroomTexture, texturePathFromName("Mushroom.png"));
	prepareTexture(&groundTexture, texturePathFromName("Ground.png"));
	prepareTexture(&treeTrunkTexture, texturePathFromName("TreeTrunk.png"));
	prepareTexture(&treeRootTexture, texturePathFromName("TreeRoot.png"));

	vector<vector<std::string>> testSpriteVect;
	int testSize = 100;
	testSpriteVect.resize(testSize);
	for(int i = 0; i < testSize; i ++){
		testSpriteVect.at(i).resize(testSize);
	}

	for(int i = 0; i < testSize; i++){
		for(int j = 0; j < testSize; j++){
			testSpriteVect.at(i).at(j) = "Mushroom.png";
		}
	}

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			/*		
			if(event.type == sf::Event::Resized){
				sf::FloatRect visibleArea(0.f,0.f, event.size.width, event.size.height); 
				sf::View newView = sf::View(visibleArea);
				newView.zoom(0.25f); 
				window.setView(newView);
			}
			*/
			
			
			

			gui.handleEvent(event);
			//Probably here we should pass the event to another function to check if it's an important key press, etc.
		}

		window.clear();
		drawGraphics(testSpriteVect, &shroomTexture, &groundTexture, &treeTrunkTexture, &treeRootTexture, &window);
		gui.draw();
		window.display();
	}
}

void GraphicsHandler::drawGraphics(vector<vector<std::string>> spriteNames, sf::Texture* shroom, sf::Texture* ground, sf::Texture* treeTrunk, sf::Texture* treeRoot, sf::RenderWindow* curWindow){
	int size = spriteNames.size()*spriteNames.size();
	sf::VertexArray graphics(sf::Quads, size);
	sf::Texture* currentTexture = ground;

	int currentHorDist = 0; 
	int currentVertDist = 0;
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


void GraphicsHandler::addRightTextBox(tgui::Gui* gui){
	tgui::TextBox::Ptr rightTextBox = tgui::TextBox::create();
	rightTextBox->setSize(rightBoxWidthPercent, "100%");
	rightTextBox->setPosition("&.width - width", "0");
	rightTextBox->setText("Sample Text");

	gui->add(rightTextBox, tileInfoBoxName);
}

void GraphicsHandler::addBottomTextBox(tgui::Gui* gui){
	tgui::TextBox::Ptr bottomTextBox = tgui::TextBox::create();
	tgui::Widget::Ptr rightTextBox = gui->get(tileInfoBoxName);

	if(rightTextBox != nullptr){
		std::cout << "Found the right box name!";
		bottomTextBox->setSize("&.width - " + tileInfoBoxName + ".width", bottomBoxHeightPercent);
	}else{
		bottomTextBox->setSize("&.width", bottomBoxHeightPercent);
	}
	bottomTextBox->setPosition("0", "&.height - height");
	bottomTextBox->setText("Sample Text");

	gui->add(bottomTextBox, worldUpdateBoxName);
}

sf::View GraphicsHandler::createView(){
	
	float rightBoxFloat = tGuiPercentToFloat(rightBoxWidthPercent);
	float downBoxFloat = tGuiPercentToFloat(bottomBoxHeightPercent);

	float viewHeight = 1.0f - downBoxFloat;
	float viewWidth = 1.0f - rightBoxFloat;

	//sf::View newView(sf::Vector2f(800,800),sf::Vector2f(1600*viewHeight, 1600*viewWidth));
	sf::View newView(sf::FloatRect(0.f,0.f,1600.f*viewWidth,900.f*viewHeight));

	std::cout << "The view will have width " << viewWidth << " and height " << viewHeight << std::endl;

	newView.setViewport(sf::FloatRect(0.f, 0.f, viewWidth, viewHeight));

	return newView;
}

float GraphicsHandler::tGuiPercentToFloat(std::string percent){
	percent.erase(std::remove(percent.begin(), percent.end(), '%'), percent.end());

	float result = std::stof(percent)/100;

	return result;
}

void GraphicsHandler::prepareTexture(sf::Texture* texture, std::string textPath){
	if(!texture->loadFromFile(textPath)){
		throw "Could not load texture with path " + textPath; 
	}

}

std::string GraphicsHandler::texturePathFromName(std::string textureName){
	std::string result = "../../data/sprites/" + textureName;
	return result;
}


