#include "GUIHandler.hpp"

void GUIHandler::addRightTextBox(tgui::Gui* gui){
	tgui::TextBox::Ptr rightTextBox = tgui::TextBox::create();
	rightTextBox->setSize(rightBoxWidthPercent, "100%");
	rightTextBox->setPosition("&.width - width", "0");
	rightTextBox->setText("Sample Text");

	gui->add(rightTextBox, tileInfoBoxName);
}

void GUIHandler::addBottomTextBox(tgui::Gui* gui){
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

sf::View GUIHandler::createView(){
	
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

float GUIHandler::tGuiPercentToFloat(std::string percent){
	percent.erase(std::remove(percent.begin(), percent.end(), '%'), percent.end());

	float result = std::stof(percent)/100;

	return result;
}