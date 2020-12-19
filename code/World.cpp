#include "World.hpp"

World::World(){
	isRaining = false;
	curSeason = fall;

	curPos.first = 0;
	curPos.second = 0;
}

void World::initWorld(){
	world.resize(size);

	for(int i = 0; i < size; i++){
		world.at(i).resize(size);
	}
}

//While writing this function, I started to come to the realization that the way all my navigation functions use curPos might be stupid.
void World::generateWorld(){
	initWorld();
	if(world.empty()){
		std::cout << "Initialization of world failed! Your world is empty!" << std::endl;
	}

	/*std::vector<std::vector<Ground>>::iterator row;
	std::vector<Ground>::iterator col;

	for(row = world.begin(); row != world.end(); row++){
		for(col = row->begin(); col != row->end(); col++){
			
		}
	}
	*/

	for(curPos.first = 0; curPos.first < size; curPos.first++){
		for(curPos.second = 0;curPos.second < size; curPos.second++){
			Ground& currentGround = getCurPos();
			
			int treeChance = rand() % 100;

			TreeTrunk* newTrunk = new OakTrunk();
			if(treeChance < 15 && !hasTreeInArea(newTrunk->getDistanceTolerance()) && !currentGround.getTreeTrunk()){
				currentGround.setTreeTrunk(newTrunk);
				currentGround.setWorld(this);
			}
		}
	}

	resetCurPos();
}

//Okay, so here we need to search a square with the current position at its center, which means we should start 
//at (curPos.first - dist, curPos.second - dist). But, we need to adjust for if you happen to by the edges of the map.
std::vector<Ground*> World::getArea(int dist){
	std::vector<Ground*> result;	
	int maxHor = (size - 1) - curPos.first;
	maxHor = std::min(maxHor, dist);
	int minHor = std::min(dist, curPos.first);
	int maxVert = (size - 1) - curPos.second;
	maxVert = std::min(maxVert, dist);
	int minVert = std::min(dist, curPos.second);

	for(int i = curPos.first - minHor; i <= curPos.first + maxHor; i++){
		for(int j = curPos.second - minVert; j <= curPos.second + maxVert; j++){
			result.push_back(&world[i][j]);
		}
	}

	return result;
}

season World::getCurrentSeason(){
	return curSeason;
}

bool World::hasTreeInArea(int dist){
	std::vector<Ground*> area = getArea(dist);
	bool result = false; 

	if(area.empty()){
		std::cout << "Error! Your vector is empty!" << std::endl;
		return false;
	}

	
	std::for_each(std::begin(area), std::end(area), [&result](Ground* const& value){
		if(value->getTreeTrunk() != nullptr){
			result = true; 		
		}

	});

/*
	for(int i = 0; i < area.size(); i++){
		if(area[i]->getTreeTrunk() != nullptr){
			result = true;
		}
	}
	*/

	return result;
}


Ground& World::getCurPos(){
	return world[curPos.first][curPos.second];
}

Ground* World::getNearCurPos(int hor, int vert){
	if(0 <= curPos.first && curPos.first + hor < size && 0 <= curPos.second + vert && curPos.second + vert < size){
		return &world[curPos.first + hor][curPos.second + vert];
	}else{
		return nullptr;
	}
}

Ground& World::getNorth(int dist){

	if(curPos.second - dist >= 0){
		return world[curPos.first][curPos.second - dist];
	}
	return world[curPos.first][curPos.second];
}

Ground& World::getSouth(int dist){
	if(curPos.second + dist < size){
		return world[curPos.first][curPos.second + dist];
	}
	return world[curPos.first][curPos.second];
}

Ground& World::getWest(int dist){
	if(curPos.first - dist >= 0){
		return world[curPos.first - dist][curPos.second];
	}
	return world[curPos.first][curPos.second];
}

Ground& World::getEast(int dist){
	if(curPos.first + dist < size){
		return world[curPos.first + dist][curPos.second];
	}
	return world[curPos.first][curPos.second];
}

void World::moveNorth(){
	if(curPos.second - 1 >= 0){
		curPos.second--;
	}
}

void World::moveSouth(){
	if(curPos.second + 1 < size){
		curPos.second++;
	}
}

void World::moveWest(){
	if(curPos.first - 1 >= 0){
		curPos.first--;
	}
}

void World::moveEast(){
	if(curPos.first + 1 < size){
		curPos.first++;
	}
}

void World::resetCurPos(){
	curPos.first = 0;
	curPos.second = 0;
}

void World::printWorld(){
	for(curPos.first = 0;curPos.first < size; curPos.first++){
		for(curPos.second = 0;curPos.second < size; curPos.second++){
			std::cout << getCurPos().getASCIIGraphics();	
		}
		std::cout << std::endl;
	}

	resetCurPos();
}

