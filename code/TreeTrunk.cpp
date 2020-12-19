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

std::string TreeTrunk::getASCIIGraphics(){
	return graphicsSymbol;
}

int TreeTrunk::getRootRadius(){
	return rootRadius;
}

void TreeTrunk::setRootRadius(int newRad){
	rootRadius = newRad;
}

TreeRoot* TreeTrunk::generateTreeRoot(){
	TreeRoot* newRoot = new TreeRoot(treeType, isDeciduous);

	return newRoot;
}

int TreeTrunk::getDistanceTolerance(){
	return distanceTolerance;
}

void TreeTrunk::ageHour(){
	ageHours++;
}

void TreeTrunk::updateAgeDay(){
	ageDays = ageHours % 24;
}

void TreeTrunk::updateAgeMonth(){
	ageMonths = ageDays % 30;
}

void TreeTrunk::updateAgeYear(){
	ageYears = ageMonths % 12;
}

//This should 
void TreeTrunk::updateStage(){
	if(ageHours == 0){
		stage = seed; 
		height = 0;
	}else if(ageYears >= 75){
		stage = mature;
		height = 75;
	}else if(ageMonths >= 5){
		stage = sapling;
		height = 15;
	}
	else if(ageMonths >= 1 && currentSeason == spring){
		stage = sprout;
		height = 2;
	}
}

//This function is kind of stupid and I should definitely figure out a different way to do this.
bool TreeTrunk::checkRootRequirements(){
	if(stage == sprout && rootRadius == 0){
		return true;
	}else if(stage == sapling && rootRadius == 1){
		return true;
	}else if(stage == mature && rootRadius == 2){
		return true;
	}else{
		return false;
	}
}

void TreeTrunk::age(){
	ageHour();
	updateAgeDay();
	updateAgeMonth();
	updateAgeYear();
	updateStage();
}

void TreeTrunk::setCurrentSeason(season updatedSeason){
	currentSeason = updatedSeason;
}


std::string TreeTrunk::loadDescription(std::string name){
	return "temp string. Update loadDescription function eventually please";
}
