#include "Mushroom.hpp"

Mushroom::Mushroom(std::shared_ptr<WorldState> currentState):GameObject(currentState){

	getWorldState()->incrementTotalMushOrganisms();
	ShroomTracker* tracker = new ShroomTracker(getWorldState()->getTotalMushOrganisms());
	organism.reset(tracker);
}

Mushroom::Mushroom(std::shared_ptr<WorldState> currentState, std::shared_ptr<ShroomTracker> sharedTracker):GameObject(currentState){
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
	Mushroom* newShroom = new Mushroom(getWorldState(), organism);

	return newShroom;
}

