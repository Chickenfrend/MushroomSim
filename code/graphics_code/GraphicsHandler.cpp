#include "GraphicsHandler.hpp"

void GraphicsHandler::LaunchDisplay(){
	sf::RenderWindow window(sf::VideoMode(1600,900), "Mushroom Sim!");
	window.setVerticalSyncEnabled(true);
	tgui::Gui gui(window);
	tgui::Button::Ptr button = tgui::Button::create();
	tgui::EditBox::Ptr editBox = tgui::EditBox::create();
	gui.add(button);
	gui.add(editBox, "MyWidgetName");

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}

			gui.handleEvent(event);
			//Probably here we should pass the event to another function to check if it's an important key press, etc.
		}

		window.clear();
		gui.draw();
		window.display();
	}
}


sf::RectangleShape GraphicsHandler::makeSideRectangle(){
	sf::RectangleShape rectangle(sf::Vector2f(150,1400));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setOutlineThickness(-10.f);
	rectangle.setOutlineColor(sf::Color::Black);


	return rectangle;	
}
