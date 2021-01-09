#include "Ground.hpp"

Ground::Ground(float _density, float _moisture, float _drainageRate){
	density = _density;
	moisture = _moisture;
	drainageRate = _drainageRate;

	root.reset(nullptr);
	trunk.reset(nullptr);
	trunk.reset(nullptr);
}

float Ground::getDensity(){
	return density;
}

float Ground::getMoisture(){
	return moisture;
}

void Ground::setMoisture(float m){
	moisture = m;
}

void Ground::setDensity(float d){
	density = d;
}

TreeRoot* Ground::getTreeRoot(){
	if(root != nullptr){
		return root.get();
	}else{
		return nullptr;
	}

}

TreeTrunk* Ground::getTreeTrunk(){
	if(trunk != nullptr){
		return trunk.get();
	}else{
		return nullptr;
	}
}

Mushroom* Ground::getMushroom(){
	if(mushroom != nullptr){
		return mushroom.get();
	}else{
		return nullptr;
	}
}

bool Ground::hasTreeTrunk(){
	if(trunk.get() == nullptr){
		return false;
	}else{
		return true;
	}
}

bool Ground::hasMushroom(){
	if(mushroom.get() == nullptr){
		return false;
	}else{
		return true;
	}
}

void Ground::setMushroom(Mushroom* m){
	mushroom.reset(m);
}

void Ground::setTreeTrunk(TreeTrunk* t){
	trunk.reset(t);
}

void Ground::setTreeRoot(TreeRoot* r){
	root.reset(r);
}

void Ground::setWorld(World* parentWorld){
	world = parentWorld;
}

std::string Ground::getASCIIGraphics(){
	if(trunk != nullptr){
		return trunk->getASCIIGraphics();
	}
	else if(mushroom){
		return mushroom->getASCIIGraphics();
	}
	else if(root){
		return root->getASCIIGraphics();
	}
	else{
		return "\033[32mg\033[0m";
	}
}

//This function is ugly...
void Ground::growTreeRoots(){
	if(trunk != nullptr){
		int rad = trunk->getRootRadius() + 1;	
		trunk->setRootRadius(rad);
		for(int i = -rad; i <= rad; i++){
			for(int j = -rad; j <= rad; j++){
				Ground* currentGround = world->getNearCurPos(i, j);	
				if(currentGround != nullptr){
					if((currentGround->getTreeTrunk() == nullptr) &&  (((abs(i) != rad) || (abs(j) != rad)) && ((i != j) || (i != -j)))){
						if(!(currentGround->getTreeTrunk()) && !(currentGround->getTreeRoot())){
							currentGround->setTreeRoot(trunk->generateTreeRoot());
						}
					}
				}
			}
		}
	}
}

void Ground::growMushroom(){
	std::vector<Ground*> adjacent = world->getArea(1);	
	std::vector<Ground*> empty;
	for(auto i : adjacent){
		if(!(i->hasMushroom())){
			empty.push_back(i);
		}
	}
	if(empty.size() != 0){
		int randIndex = rand() % empty.size();

		empty.at(randIndex)->setMushroom(mushroom->generateMycelium());
		mushroom->getShroomTracker()->incrementCount();
	}
}

void Ground::update(int hours){
	if(hasTreeTrunk()){
		trunk->age(hours);
		if(trunk->checkRootRequirements()){
			growTreeRoots();
		}
	}
	if(hasMushroom()){
		mushroom->age(hours);
		if(mushroom->checkSpreadConditions()){
			growMushroom();
		}
	}
}

