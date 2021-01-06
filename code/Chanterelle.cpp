#include "Chanterelle.hpp"

Chanterelle::Chanterelle(std::shared_ptr<WorldState> currentState):Mushroom(currentState){
	name = "Chanterelle";
	isBlooming = false; 
	description = "Stand In Description, to be replaced";
	reproductiveAge = 3;
}
