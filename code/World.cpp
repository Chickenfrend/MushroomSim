#include "World.hpp"


void World::initWorld(){
	world.resize(size);

	for(int i = 0; i < size; i++){
		world.at(i).resize(size);
	}
}

Ground& World::getCurPos(){
	return world[curPos.first][curPos.second];
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

//Okay, so here we need to search a square with the current position at its center, which means we should start 
//at (curPos.first - dist, curPos.second - dist). 
//IF PROGRAM CRASHES, CHECK FOR OUT OF BOUND ERROR HERE!
std::vector<Ground*> World::getArea(int dist){
	std::vector<Ground*> result;	
	int maxHor = size - curPos.first;
	maxHor = std::min(maxHor, dist);
	int minHor = std::min(dist, curPos.first);
	int maxVert = size - curPos.second;
	maxVert = std::min(maxVert, dist);
	int minVert = std::min(dist, curPos.second);

	for(int i = curPos.first - minHor; i <= curPos.first + maxHor; i++){
		for(int j = curPos.second - minVert; j <= curPos.first + maxVert; j++){
			result.push_back(&world[i][j]);
		}
	}

	return result;
}

bool World::hasTreeInArea(int dist){
	std::vector<Ground*> area = getArea(dist);

	std::for_each(std::begin(area), std::end(area), [](Ground* const& value){
		if(value->getTreeTrunk() != NULL){
			return true; 		
		}
	});

	return false;
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


