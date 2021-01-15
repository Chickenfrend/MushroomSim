#include "AmanitaMuscaria.hpp"

AmanitaMuscaria::AmanitaMuscaria(shared_ptr<WorldState> currentState):Mushroom(currentState){
	name = "AmanitaMuscaria";
	isBlooming = false;
	description = "Stand in description";
	reproductiveAge = 3;
	graphicsSymbol = "\033[31mA\033[0m";
}

AmanitaMuscaria::AmanitaMuscaria(shared_ptr<WorldState> currentState, shared_ptr<ShroomTracker> sharedTracker):Mushroom(currentState, sharedTracker){
	name = "AmanitaMuscaria";
	isBlooming = false;
	description = "Stand in description";
	reproductiveAge = 3;
	graphicsSymbol = "\033[31mA\033[0m";
}

Mushroom* AmanitaMuscaria::generateMycelium(){
	Mushroom* newShroom = new AmanitaMuscaria(getWorldState(), getShroomTracker());

	return newShroom;
}

bool AmanitaMuscaria::checkSoilConditions(TreeRoot* root){
	if(checkIfValidTree(root->getTreeType())){
		return true;
	}else{
		return false;
	}
}
