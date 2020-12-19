#include "OakTrunk.hpp"

OakTrunk::OakTrunk(){
	treeType = "Oak";
	description = loadDescription(treeType);
	isDeciduous = false;

	maxDistance = 90;
	maxHeight = 90.0f;
	graphicsSymbol = "\033[33mO\033[0m";
}

void OakTrunk::growRootsCheck(){
		
}

