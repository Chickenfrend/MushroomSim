#include "GraphicsHandler.hpp"

void GraphicsHandler::LaunchDisplay(){
	sf::RenderWindow window(sf::VideoMode(1600,900), "Mushroom Sim!");
	window.setVerticalSyncEnabled(true);
	tgui::Gui gui(window);
	tgui::Button::Ptr button = tgui::Button::create();
	tgui::EditBox::Ptr editBox = tgui::EditBox::create();
	gui.add(button);
	gui.add(editBox, "MyWidgetName");
	addRightTextBox(&gui);
	addBottomTextBox(&gui);
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

void GraphicsHandler::addRightTextBox(tgui::Gui* gui){
	tgui::TextBox::Ptr rightTextBox = tgui::TextBox::create();
	rightTextBox->setSize("15%", "100%");
	rightTextBox->setPosition("&.width - width", "0");
	rightTextBox->setText("Sample Text");

	gui->add(rightTextBox, tileInfoBoxName);
}

void GraphicsHandler::addBottomTextBox(tgui::Gui* gui){
	tgui::TextBox::Ptr bottomTextBox = tgui::TextBox::create();
	tgui::Widget::Ptr rightTextBox = gui->get(tileInfoBoxName);

	if(rightTextBox != nullptr){
		std::cout << "Found the right box name!";
		bottomTextBox->setSize("&.width - " + tileInfoBoxName + ".width", "20%");
	}else{
		bottomTextBox->setSize("&.width", "20%");
	}
	bottomTextBox->setPosition("0", "&.height - height");
	bottomTextBox->setText("Sample Text");

	gui->add(bottomTextBox, worldUpdateBoxName);
}


