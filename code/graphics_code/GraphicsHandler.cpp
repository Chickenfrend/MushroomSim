#include "GraphicsHandler.hpp"

void GraphicsHandler::LaunchDisplay(){

	sf::RenderWindow window(sf::VideoMode(1600,900), "Mushroom Sim?");
	window.setVerticalSyncEnabled(true);
	tgui::Gui gui(window);

	addRightTextBox(&gui);
	addBottomTextBox(&gui);

	sf::View gameView;
	gameView = createView();
	window.setView(gameView);

	sf::Texture shroomTexture;
	sf::Texture groundTexture;
	sf::Texture treeTrunkTexture;
	sf::Texture treeRootTexture;
	
	prepareTexture(&shroomTexture, texturePathFromName("Mushroom.png"));
	prepareTexture(&groundTexture, texturePathFromName("Ground.png"));
	prepareTexture(&treeTrunkTexture, texturePathFromName("TreeTrunk.png"));
	prepareTexture(&treeRootTexture, texturePathFromName("TreeRoot.png"));

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			/*
			if(event.type == sf::Event::Resized){
				sf::FloatRect visibleArea(0.f,0.f, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
			*/

			gui.handleEvent(event);
			//Probably here we should pass the event to another function to check if it's an important key press, etc.
		}

		window.clear();
		gui.draw();
		window.display();
	}
}

void GraphicsHandler::drawGraphics(vector<vector<std::string>> spriteNames, sf::Texture* shroom, sf::Texture* ground, sf::Texture* treeTrunk, sf::Texture* treeRoot, sf::RenderWindow curWindow){
	int size = spriteNames.size()*spriteNames.size();
	sf::VertexArray graphics(sf::Quads, size);
	sf::Texture* currentTexture = ground;

	int currentHorDist = 0; 
	int currentVertDist = 0;
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
				throw "Error! Unexpexted texture name found in sprite name vector!";
			}
			
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
	//Defining what the view views
	sf::View newView;
	

	//How view is viewed

	float rightBoxFloat = tGuiPercentToFloat(rightBoxWidthPercent);
	float downBoxFloat = tGuiPercentToFloat(bottomBoxHeightPercent);

	float viewHeight = 1.0f - downBoxFloat;
	float viewWidth = 1.0f - rightBoxFloat;

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

std::string texturePathFromName(std::string textureName){
	std::string result = "../../data/sprites/" + textureName;
	return result;
}


