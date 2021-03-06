#include "Ground.hpp"
#include "World.hpp"

Ground::Ground(float _density, float _moisture, float _drainageRate) {
	density = _density;
	moisture = _moisture;
	drainageRate = _drainageRate;

	root.reset(nullptr);
	trunk.reset(nullptr);
	trunk.reset(nullptr);
}

float Ground::getDensity() { return density; }

float Ground::getMoisture() { return moisture; }

int Ground::getNutrients() { return nutrients; }

void Ground::setMoisture(float m) { moisture = m; }

void Ground::setDensity(float d) { density = d; }

TreeRoot *Ground::getTreeRoot() {
	if (root != nullptr) {
		return root.get();
	} else {
		return nullptr;
	}
}

TreeTrunk *Ground::getTreeTrunk() {
	if (trunk != nullptr) {
		return trunk.get();
	} else {
		return nullptr;
	}
}

Mushroom *Ground::getMushroom() {
	if (mushroom != nullptr) {
		return mushroom.get();
	} else {
		return nullptr;
	}
}

bool Ground::hasTreeTrunk() {
	if (trunk.get() == nullptr) {
		return false;
	} else {
		return true;
	}
}
bool Ground::hasMushroom() {
	if (mushroom.get() == nullptr) {
		return false;
	} else {
		return true;
	}
}

bool Ground::hasTreeRoot() {
	if (root.get()) {
		return true;
	} else {
		return false;
	}
}

void Ground::setMushroom(Mushroom *m) { mushroom.reset(m); }

void Ground::setTreeTrunk(TreeTrunk *t) { trunk.reset(t); }

void Ground::setTreeRoot(TreeRoot *r) { root.reset(r); }

void Ground::setWorld(World *parentWorld) { world = parentWorld; }

std::string Ground::getASCIIGraphics() {
	if (trunk != nullptr) {
		return trunk->getASCIIGraphics();
	} else if (mushroom) {
		return mushroom->getASCIIGraphics();
	} else if (root) {
		return root->getASCIIGraphics();
	} else {
		return "\033[32mg\033[0m";
	}
}

std::string Ground::getSpriteName() {
	if (trunk) {
		return "TreeTrunk.png";
	} else if (mushroom) {
		return "Mycelium.png";
	} else if (root) {
		return "TreeRoot.png";
	} else {
		return "Ground.png";
	}
}

// This function is ugly...
void Ground::growTreeRoots() {
	if (trunk != nullptr) {
		int rad = trunk->getRootRadius() + 1;
		trunk->setRootRadius(rad);
		for (int i = -rad; i <= rad; i++) {
			for (int j = -rad; j <= rad; j++) {
				Ground *currentGround = world->getNearCurPos(i, j);
				if (currentGround != nullptr) {
					if ((currentGround->getTreeTrunk() == nullptr) &&
					    (((abs(i) != rad) || (abs(j) != rad)) && ((i != j) || (i != -j)))) {
						if (!(currentGround->getTreeTrunk()) && !(currentGround->getTreeRoot())) {
							currentGround->setTreeRoot(trunk->generateTreeRoot());
						}
					}
				}
			}
		}
	}
}

void Ground::growMushroom() {
	std::vector<Ground *> adjacent = world->getArea(1);
	std::vector<Ground *> empty;
	for (auto i : adjacent) {
		if (!(i->hasMushroom())) {
			empty.push_back(i);
		}
	}
	if (empty.size() != 0) {
		int randIndex = rand() % empty.size();

		if (mushroom->checkSoilConditions(empty.at(randIndex)->getTreeRoot())) {
			empty.at(randIndex)->setMushroom(mushroom->generateMycelium());
			mushroom->getShroomTracker()->incrementCount();
		}
	}
}

void Ground::update(int hours) {
	passiveNutrientGrowth(hours);
	if (hasTreeTrunk()) {
		trunk->age(hours);
		if (trunk->checkRootRequirements()) {
			growTreeRoots();
		}
	}
	if (hasMushroom()) {
		if (!mushroom->checkIfDead()) {
			int nutrientsToFeed = std::min(5 * hours, nutrients);
			mushroom->feed(nutrientsToFeed);
			nutrients -= nutrientsToFeed;
			mushroom->update(hours);
			if (mushroom->checkSpreadConditions()) {
				growMushroom();
			}
			if(mushroom->checkIfDead()){
				mushroom.reset(nullptr);
			}
		}else{
			mushroom.reset(nullptr);
		}
	}
	updateMoisture(hours);
}


// This will need to be changed
void Ground::updateMoisture(int timeDifference) {
	float hoursRained = world->getWorldState().getCumulativeRainHours();
	float newMoisture = accumulationRate * hoursRained;

	if (moisture - (drainageRate * timeDifference) > 0.f) {
		moisture -= drainageRate * timeDifference;
	} else {
		moisture = 0.f;
	}

	if (moisture + newMoisture < 1.f) {
		moisture += newMoisture;
	} else {
		moisture = 1.f;
	}
}

void Ground::passiveNutrientGrowth(int hours) {
	bool lessNutrientsThanMax = nutrients <= nutrientPassiveMax;
	if (nutrients + passiveNutrientGain * hours < nutrientPassiveMax) {
		nutrients += passiveNutrientGain * hours;
	} else if (lessNutrientsThanMax) {
		nutrients = nutrientPassiveMax;
	}
}

