#include "TreeTrunk.hpp"

bool TreeTrunk::getDeciduousStatus(){
	return isDeciduous;
}

std::string TreeTrunk::getDescription(){
	return description;
}

std::string TreeTrunk::getTreeType(){
	return treeType;
}

char TreeTrunk::getASCIIGraphics(){
	return graphicsSymbol;
}
