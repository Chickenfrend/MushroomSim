#include "Mushroom.hpp"

Mushroom::Mushroom(std::shared_ptr<WorldState> currentState){
	worldState = currentState;

	worldState->incrementTotalMushOrganisms();
	ShroomTracker* tracker = new ShroomTracker(worldState->getTotalMushOrganisms());
	organism.reset(tracker);
}

Mushroom::Mushroom(std::shared_ptr<WorldState> currentState, std::shared_ptr<ShroomTracker> sharedTracker){
	worldState = currentState;
	organism = sharedTracker;
}

bool Mushroom::checkSpreadConditions(){
	return false;
}

bool Mushroom::checkBloomConditions(){
	return false;
}

float Mushroom::getDensity(){
	return density;
}

bool Mushroom::getBloomingStatus(){
	return isBlooming;
}

std::string Mushroom::getDescription(){
	return description;
}

std::string Mushroom::getName(){
	return name;
}

std::string Mushroom::getASCIIGraphics(){
	return graphicsSymbol;
}

std::shared_ptr<ShroomTracker> Mushroom::getShroomTracker(){
	return organism;
}

Mushroom* Mushroom::generateMycelium(){
	Mushroom* newShroom = new Mushroom(worldState, organism);

	return newShroom;
}

