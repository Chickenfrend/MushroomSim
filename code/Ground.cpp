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

std::unique_ptr<TreeRoot>& Ground::getTreeRoot(){
	return root;
}

TreeTrunk* Ground::getTreeTrunk(){
	if(trunk.get() != nullptr){
		return trunk.get();
	}else{
		return nullptr;
	}
}

std::unique_ptr<Mushroom>& Ground::getMushroom(){
	return mushroom;
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
