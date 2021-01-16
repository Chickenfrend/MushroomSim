#include "World.hpp"

World::World(){
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
			currentGround.setWorld(this);
			
			int treeChance = rand() % 100;

			RandTreeGenerator treeGen(forestPath, std::make_shared<WorldState>(worldState));
			TreeTrunk* newTrunk = treeGen.generateTreeTrunk();
			if(treeChance < 5 && !hasTreeInArea(newTrunk->getDistanceTolerance()) && !currentGround.getTreeTrunk()){
				currentGround.setTreeTrunk(newTrunk);
			}
			/*if(curPos.first % 15 == 0 && curPos.second % 15 == 0){
				currentGround.setTreeTrunk(newTrunk);
				currentGround.setWorld(this);
			}*/
			else{
				delete newTrunk;
			}
		}
	}
	
	resetCurPos();
}

void World::populateWorld(){
	int count = 0;
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 360; j++){
			//std::cout << "About to update world on iteration " << count << "." << std::endl;
			update(24);
			count++;
		}	
		//std::cout << "Just went through year " << i << std::endl;
	}

	//This part places mushrooms
	while(!curPosAtEnd()){
		Ground& currentGround = getCurPos();
		int mushChance = rand() % 100;
		
		RandShroomGenerator shroomGen(forestPath, std::make_shared<WorldState>(worldState));	
		Mushroom* newShroom = shroomGen.generateMushroom();
		if(mushChance < 7 && !currentGround.hasTreeTrunk() && !currentGround.hasMushroom() && newShroom->checkSoilConditions(currentGround.getTreeRoot())){
			currentGround.setMushroom(newShroom);		
		}
		else{
			delete newShroom;
		}
		moveNext();
	}
	
	//update();
}

void World::update(int hours){
	resetCurPos();
	worldState.updateAges(hours);
	while(!curPosAtEnd()){
		getCurPos().update(hours);
		moveNext();
	}
	resetCurPos();
}

void World::run(){
	bool running = true;
	bool continuous = false;
	int timeStep = 10;
	while(running){
		printWorld();
		std::string selection = "";
		std::cout << "q to quit, r to run, u to update one step, + to add 10 hours to time step, - to remove 10 hours: " << std::endl;
		std::cout << "Each update is " << timeStep << " hours." << std::endl;

		int year = worldState.getAgeYears();
		int month = worldState.getCurrentMonth();
		int day = worldState.getCurrentDay();
		int hour = worldState.getCurrentHour();

		std::cout << "Year: " << year << " Month: " << month << " Day: " << day << " Hour: " << hour << std::endl;
		std::cin >> selection;
		std::cout << std::endl;

		if(selection == "q"){
			running = false;
		}else if(selection == "u"){
			update(timeStep);	
		}else if(selection == "r"){
			ToolBox::ClearScreen();
			continuous = true;
			while(continuous){
				printWorld();
				std::cout << "q to quit, p to stop running, + to add 10 hours to time step, - to remove 10 hours";	
				std::cout << "Each update is " << timeStep << " hours." << std::endl;

				update(timeStep);

				std::this_thread::sleep_for(std::chrono::milliseconds(32));

				ToolBox::ClearScreen();
			}
		}else if(selection == "+"){
			timeStep += 10;
		}else if(selection == "-"){
			if(timeStep + 10 >= 0){
				timeStep -= 10;
			}
		}

		

		ToolBox::ClearScreen();
	}
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
	if(0 <= curPos.first + hor && curPos.first + hor < size && 0 <= curPos.second + vert && curPos.second + vert < size){
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

void World::moveNext(){
	if(curPos.first < size-1){
		curPos.first++;
	}
	else if(curPos.second < size-1){
		curPos.first = 0;
		curPos.second++;
	}
}

bool World::curPosAtEnd(){
	if(curPos.first == (size - 1) && curPos.second == (size-1)){
		return true;
	}
	return false;
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


