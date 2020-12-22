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

void TreeTrunk::updateStage(){
	if(getAgeHours() < 1){
		stage = seed;
		height = 0;
	}else if(stage == seed && getAgeMonths() >= 1 && currentSeason == spring){
		std::cout << "Current season is " << currentSeason << "so we are updating the stage of this tree to sprout" << std::endl;
		stage = sprout;
		height = 2;
	}else if(stage == sprout && getAgeMonths() >= 5){
		std::cout << "We are updating the stage of this tree to sapling" << std::endl;
		stage = sapling;
		height = 15;
	}else if(stage == sapling && ageYears >= 75){
		std::cout << "We are updating the stage of this tree to mature" << std::endl;
		stage = mature;
		height = 75;
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

void TreeTrunk::age(int hours){
	ageHours += hours;

	if(ageHours >= 24){
		ageDays += hours/24;
		ageHours = ageHours % 24;
	}

	if(ageDays >= 30){
		ageMonths += ageDays/30;
		ageDays = ageDays % 30;
	}

	if(ageMonths >= 12){
		ageYears += ageMonths/12;
		ageMonths = ageMonths % 12;
	}

	updateStage();
}

int TreeTrunk::getAgeHours(){
	return getAgeDays()*24 + ageHours;
}

int TreeTrunk::getAgeDays(){
	return getAgeMonths()*30 + ageDays;
}

int TreeTrunk::getAgeMonths(){
	return ageYears*12 + ageMonths;
}

void TreeTrunk::setCurrentSeason(season updatedSeason){
	currentSeason = updatedSeason;
}


std::string TreeTrunk::loadDescription(std::string name){
	return "temp string. Update loadDescription function eventually please";
}
