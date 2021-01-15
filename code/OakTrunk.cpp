#include "OakTrunk.hpp"

OakTrunk::OakTrunk(std::shared_ptr<WorldState> currentState):TreeTrunk(currentState){
	treeType = "OakTree";
	description = loadDescription(treeType);
	isDeciduous = true;

	maxHeight = 90.0f;
	graphicsSymbol = "\033[33mO\033[0m";
}


