#include "Mushroom.hpp"

Mushroom::Mushroom(std::shared_ptr<WorldState> currentState) : GameObject(currentState) {
	getWorldState()->incrementTotalMushOrganisms();
	ShroomTracker *tracker = new ShroomTracker(getWorldState()->getTotalMushOrganisms());
	organism.reset(tracker);
}

Mushroom::Mushroom(std::shared_ptr<WorldState> currentState, std::shared_ptr<ShroomTracker> sharedTracker) : GameObject(currentState) {
	organism = sharedTracker;
}

void Mushroom::storeValidTreeList() {
	string treeListPath = "../descriptions/mushrooms/" + name + "/valid_trees.txt";
	ifstream treeList(treeListPath);
	string line;

	if (!treeList.is_open()) {
		throw std::runtime_error("Could not open the tree list file.");
	}

	while (std::getline(treeList, line)) {
		validTrees.insert(line);
	}

	if (validTrees.empty()) {
		std::cerr << "Warning: Mushroom " << name << " has no valid trees. It won't grow anywhere!";
	}
}

void Mushroom::storeValidMonths(){
	string monthListPath = "../descriptions/mushrooms/" + name + "/valid_months.txt";	
	ifstream monthList(monthListPath);	
	string line;
	if (!monthList.is_open()) {
		throw std::runtime_error("Could not open the month list file.");
	}

	while(std::getline(monthList, line)){
		bloomMonths.insert(SeasonsHandler::stringToMonth(line));
	}

	if(bloomMonths.empty()){
		std::cerr << "Warning: Mushroom " << name << " has no valid months. It won't ever bloom!";
	}
}

bool Mushroom::checkIfValidTree(string treeName) {
	if (validTrees.find(treeName) != validTrees.end()) {
		return true;
	} else {
		return false;
	}
}

bool Mushroom::checkSpreadConditions() { return canSpread; }

bool Mushroom::checkBloomConditions() { return false; }

bool Mushroom::checkSoilConditions(TreeRoot *root) {
	if (!root) {
		return false;
	} else if (root->getIfDeciduous()) {
		return true;
	} else {
		return false;
	}
}

float Mushroom::getDensity() { return density; }

std::string Mushroom::getShroomType() { return name; }

bool Mushroom::getBloomingStatus() { return isBlooming; }

std::string Mushroom::getDescription() { return description; }

std::string Mushroom::getName() { return name; }

std::string Mushroom::getASCIIGraphics() { return graphicsSymbol; }

std::shared_ptr<ShroomTracker> Mushroom::getShroomTracker() { return organism; }

/*Mushroom* Mushroom::generateMycelium(){
	Mushroom* newShroom = new Mushroom(getWorldState(), organism);

	return newShroom;
}*/

void Mushroom::updateSpreadConditions(int hours) {
	if (ageMonths != spreadFrequencyMonths && ToolBox::HoursToMonths(getAgeHours() + hours) % 12 == spreadFrequencyMonths &&
	    getAgeMonths() != 0) {
		canSpread = true;
	} else {
		canSpread = false;
	}
}

void Mushroom::update(int hours) {
	updateSpreadConditions(hours);
	age(hours);
}

void Mushroom::age(int hours) {
	ageHours += hours;

	if (ageHours >= 24) {
		ageDays += ageHours / 24;
		ageHours = ageHours % 24;
	}

	if (ageDays >= 30) {
		ageMonths += ageDays / 30;
		ageDays = ageDays % 30;
	}

	if (ageMonths >= 12) {
		ageYears += ageMonths / 12;
		ageMonths = ageMonths % 12;
	}
}

int Mushroom::getAgeHours() { return getAgeDays() * 24 + ageHours; }

int Mushroom::getAgeDays() { return getAgeMonths() * 30 + ageDays; }

int Mushroom::getAgeMonths() { return ageYears * 12 + ageMonths; }
