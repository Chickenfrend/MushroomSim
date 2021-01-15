#include "Chanterelle.hpp"

Chanterelle::Chanterelle(std::shared_ptr<WorldState> currentState):Mushroom(currentState){
	name = "Chanterelle";
	isBlooming = false; 
	description = "Stand In Description, to be replaced";
	reproductiveAge = 3;
	graphicsSymbol = "\033[33mC\033[0m";
}

Chanterelle::Chanterelle(std::shared_ptr<WorldState> currentState, std::shared_ptr<ShroomTracker> sharedTracker):Mushroom(currentState, sharedTracker){
	name = "Chanterelle";
	isBlooming = false; 
	description = "Stand In Description, to be replaced";
	reproductiveAge = 3;
	graphicsSymbol = "\033[33mC\033[0m";

}

Mushroom* Chanterelle::generateMycelium(){
	Mushroom* newShroom = new Chanterelle(getWorldState(), getShroomTracker());

	return newShroom;
}
