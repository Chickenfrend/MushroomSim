#include "graphics_code/GUIHandler.hpp"
#include "graphics_code/SpriteHandler.hpp"
#include "graphics_code/EventHandler.hpp"
#include "World.hpp"

int main(){
	World world;

	world.generateWorld();
	world.populateWorld();

	GUIHandler gHandler;
	SpriteHandler sHandler;

	sf::RenderWindow window(sf::VideoMode(1600,900), "Mushroom Sim?");
	window.setVerticalSyncEnabled(true);
	tgui::Gui gui(window);

	gHandler.addRightTextBox(&gui);
	gHandler.addBottomTextBox(&gui);

	sf::View gameView;
	gameView = gHandler.createView();
	window.setView(gameView);

	sf::Texture shroomTexture;
	sf::Texture groundTexture;
	sf::Texture treeTrunkTexture;
	sf::Texture treeRootTexture;

	sHandler.prepareTexture(&shroomTexture, sHandler.texturePathFromName("Mushroom.png"));
	sHandler.prepareTexture(&groundTexture, sHandler.texturePathFromName("Ground.png"));
	sHandler.prepareTexture(&treeTrunkTexture, sHandler.texturePathFromName("TreeTrunk.png"));
	sHandler.prepareTexture(&treeRootTexture, sHandler.texturePathFromName("TreeRoot.png"));
	
	EventHandler eHandler(window, &world);

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}else if(event.type == sf::Event::Resized){
				gHandler.updateView(&gameView, event.size.width, event.size.height);
				window.setView(gameView);
			}
			
			gui.handleEvent(event);
			//Probably here we should pass the event to another function to check if it's an important key press, etc.
			std::unique_ptr<Command> currentCommand(eHandler.handleEvent(event));
			//Command* currentCommand = eHandler.handleEvent(event);

			if(currentCommand){
				currentCommand->execute();
			}

		}

		window.clear();
		sHandler.drawGraphics(world.getSpriteNames(), &shroomTexture, &groundTexture, &treeTrunkTexture, &treeRootTexture, &window);
		gui.draw();
		window.display();
	}

}
