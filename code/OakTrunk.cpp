#include "OakTrunk.hpp"

OakTrunk::OakTrunk(){
	treeType = "Oak";
	description = loadDescription(treeType);
	isDeciduous = false;

	ageYears = 0;
	ageSeasons = 0;
	stage = 0;

	height = 0.0f;
	maxDistance = 90;
	circumference = 0.0f;
	maxHeight = 90.0f;
	graphicsSymbol = 'O';
}

void OakTrunk::growRootsCheck(){
		
}

