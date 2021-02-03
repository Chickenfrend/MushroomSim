#include "graphics_code/GUIHandler.hpp"
#include "graphics_code/SpriteHandler.hpp"

int main(){
	GUIHandler gHandler;
	SpriteHandler sHandler;

	sf::RenderWindow window(sf::VideoMode(1600,900), "Mushroom Sim?");
	window.setVerticalSyncEnabled(true);
	tgui::Gui gui(window);

	gHandler.addRightTextBox(&gui);
	gHandler.addBottomTextBox(&gui);

	sf::View gameView;
	gameView = gHandler.createView();
	gameView.zoom(0.5f);
	window.setView(gameView);

	sf::Texture shroomTexture;
	sf::Texture groundTexture;
	sf::Texture treeTrunkTexture;
	sf::Texture treeRootTexture;

	sHandler.prepareTexture(&shroomTexture, sHandler.texturePathFromName("Mushroom.png"));
	sHandler.prepareTexture(&groundTexture, sHandler.texturePathFromName("Ground.png"));
	sHandler.prepareTexture(&treeTrunkTexture, sHandler.texturePathFromName("TreeTrunk.png"));
	sHandler.prepareTexture(&treeRootTexture, sHandler.texturePathFromName("TreeRoot.png"));

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
		sHandler.drawGraphics(testSpriteVect, &shroomTexture, &groundTexture, &treeTrunkTexture, &treeRootTexture, &window);
		gui.draw();
		window.display();
	}

}
