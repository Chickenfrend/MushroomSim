#include "World.hpp"


void World::initWorld(){
}

Ground& World::getCurPos(){
	return world[std::get<0>(curPos)][std::get<1>(curPos)];
}

Ground& World::getNorth(int dist){
	if(std::get<1>(curPos) - dist >= 0){
		return world[std::get<0>(curPos)][std::get<1>(curPos) - dist];
	}
	return world[std::get<0>(curPos)][std::get<1>(curPos)];
}

Ground& World::getSouth(int dist){
	if(std::get<1>(curPos) + dist < size){
		return world[std::get<0>(curPos)][std::get<1>(curPos) + dist];
	}
	return world[std::get<0>(curPos)][std::get<1>(curPos)];
}

Ground& World::getWest(int dist){
	if(std::get<0>(curPos) - dist >= 0){
		return world[std::get<0>(curPos) - dist][std::get<1>(curPos)];
	}
	return world[std::get<0>(curPos)][std::get<1>(curPos)];
}

Ground& World::getEast(int dist){
	if(std::get<0>(curPos) + dist < size){
		return world[std::get<0>(curPos) + dist][std::get<1>(curPos)];
	}
	return world[std::get<0>(curPos)][std::get<1>(curPos)];
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


