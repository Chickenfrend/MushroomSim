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
	return root.get();
}

TreeTrunk* Ground::getTreeTrunk(){
	return trunk.get();
}

Mushroom* Ground::getMushroom(){
	return mushroom.get();
}

void Ground::setTreeTrunk(TreeTrunk* t){
	trunk.reset(t);
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

void Ground::updateTreeSeason(){
	if(trunk != nullptr){
		trunk->setCurrentSeason(world->getCurrentSeason());
	}
}

void Ground::growTreeRoots(){
	if(trunk != nullptr){
		int rad = trunk->getRootRadius();	
		for(int i = -rad; i < rad; i++){
			for(int j = -rad; j < rad; i++){
				Ground* currentGround = world->getNearCurPos(i, j);	

				if(currentGround->getTreeTrunk() != nullptr &&  i != j && !((i == 0) && (j == rad)) && !((i == rad) && (j == 0))){
					if(!(currentGround->getTreeTrunk()) && !(currentGround->getTreeRoot())){
						currentGround->setTreeRoot(trunk->generateTreeRoot());
					}
				}
			}
		}
		trunk->setRootRadius(rad++);
	}
}

