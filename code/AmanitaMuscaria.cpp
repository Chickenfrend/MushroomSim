#include "AmanitaMuscaria.hpp"

AmanitaMuscaria::AmanitaMuscaria(shared_ptr<WorldState> currentState):Mushroom(currentState){
	name = "AmanitaMuscaria";
	isBlooming = false;
	description = "Stand in description";
	reproductiveAge = 3;
	graphicsSymbol = "\033[31mA\033[0m";
	storeValidTreeList();
}

AmanitaMuscaria::AmanitaMuscaria(shared_ptr<WorldState> currentState, shared_ptr<ShroomTracker> sharedTracker):Mushroom(currentState, sharedTracker){
	name = "AmanitaMuscaria";
	isBlooming = false;
	description = "Stand in description";
	reproductiveAge = 3;
	graphicsSymbol = "\033[31mA\033[0m";
	storeValidTreeList();
}

Mushroom* AmanitaMuscaria::generateMycelium(){
	Mushroom* newShroom = new AmanitaMuscaria(getWorldState(), getShroomTracker());

	return newShroom;
}

bool AmanitaMuscaria::checkSoilConditions(TreeRoot* root){
	if(!root){
		return false;
	}else if(checkIfValidTree(root->getTreeType())){
		return true;
	}else{
		return false;
	}
}
