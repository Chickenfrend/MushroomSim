#include "AdjustZoomCommand.hpp"

AdjustZoomCommand::AdjustZoomCommand(sf::RenderWindow& _window, float _delta) : window(_window){
	delta = _delta;
}

void AdjustZoomCommand::execute(){
	sf::View gameView = window.getView();
	sf::Vector2f viewSize = gameView.getSize();

	float heightScale = viewSize.y/viewSize.x;
	gameView.setSize(viewSize.x - delta*zoomFactor, viewSize.y - delta*zoomFactor*heightScale);
	window.setView(gameView);
}


