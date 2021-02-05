#include "AdjustZoomCommand.hpp"

AdjustZoomCommand::AdjustZoomCommand(sf::RenderWindow& _window, float _delta, float _maxWidth, float _minWidth) : window(_window){
	delta = _delta;
	maxWidth = _maxWidth;
	minWidth = _minWidth;
}

void AdjustZoomCommand::execute(){
	sf::View gameView = window.getView();
	sf::Vector2f viewSize = gameView.getSize();

	float heightScale = viewSize.y/viewSize.x;
	if(!(viewSize.x >= maxWidth && delta < 0) && !(viewSize.x <= minWidth && delta > 0)){
		gameView.setSize(viewSize.x - delta*zoomFactor, viewSize.y - delta*zoomFactor*heightScale);
		window.setView(gameView);
	}
}


