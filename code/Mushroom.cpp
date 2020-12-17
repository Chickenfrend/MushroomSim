#include "Mushroom.hpp"

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

char Mushroom::getASCIIGraphics(){
	return graphicsSymbol;
}


