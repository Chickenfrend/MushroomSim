#include "GraphicsHandler.hpp"

void GraphicsHandler::LaunchDisplay(){
	sf::Window window(sf::VideoMode(800,600), "Mushroom Sim!");

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
			//Probably here we should pass the event to another function to check if it's an important key press, etc.
		}
	}
}
