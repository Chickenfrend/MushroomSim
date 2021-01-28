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

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(gameView.getCenter());
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
		window.draw(shape);
		window.display();
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


