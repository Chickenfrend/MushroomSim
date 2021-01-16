#include "RandShroomGenerator.hpp"

RandShroomGenerator::RandShroomGenerator(std::string _forestPath, std::shared_ptr<WorldState> currentState){
	forestPath = _forestPath;
	worldState = currentState;
	GenerateLists();
}

void RandShroomGenerator::GenerateLists(){
	std::ifstream shroomFile(forestPath + "/mushrooms.csv");

	std::string line;
	std::string firstLine;
	std::string treeName;
	int weight;

	if(!shroomFile.is_open()){
		throw std::runtime_error("Could not open forest file");
	}

	if(shroomFile.good()){
		std::getline(shroomFile, firstLine);
        std::cout << "Got Here" << std::endl;
	}else{
        throw std::runtime_error("File is not good");
    }
	
	int index = 0;

	int weightSum = 0;
	while(std::getline(shroomFile, line)){
		int currentWeight;
		std::istringstream stream(line);
        std::string tempString = "";
		std::getline(stream, tempString, ',');
        shroomNames.push_back(tempString);

		stream >> currentWeight;

		if(index == 0){
			intervals.push_back(currentWeight);
		}else{
			intervals.push_back(intervals[index-1] + currentWeight);
		}

		index++;	
	}

    for(int i = 0; i < shroomNames.size(); i++){
        std::cout << shroomNames[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < intervals.size(); i++){
        std::cout << intervals[i] << " ";
    }
    std::cout << std::endl;


}

std::string RandShroomGenerator::pickRandom(){
	int randInt = rand() % intervals.back();
	for(int i = 0; i < intervals.size(); i++){
	 	std::cout << "Got to for loop" << std::endl;	
		if(randInt < intervals[i]){
			std::cout << "Current interval is " << intervals[i] << std::endl;
			return shroomNames[i]; 
		}
	}
	throw std::runtime_error("Failed to pick a random tree. Bad or empty forest file?");
}

Mushroom* RandShroomGenerator::generateMushroom(){
	std::string randShroomName = pickRandom();
	if(randShroomName == "Chanterelle"){
		return new Chanterelle(worldState);
	}else if(randShroomName == "AmanitaMuscaria"){
		return new AmanitaMuscaria(worldState);
	}else{
		std::string error = "Invalid tree name " + randShroomName;
		throw std::runtime_error(error);
	}
}
