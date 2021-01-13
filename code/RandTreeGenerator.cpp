#include "RandTreeGenerator.hpp"

RandTreeGenerator::RandTreeGenerator(std::string _forestPath){
	forestPath = _forestPath;
	GenerateLists();
}

void RandTreeGenerator::GenerateLists(){
	std::ifstream treeFile(forestPath);

	std::string line;
	std::string firstLine;
	std::string treeName;
	int weight;

	if(!treeFile.is_open()){
		throw std::runtime_error("Could not open file");
	}

	if(treeFile.good()){
		std::getline(treeFile, firstLine);
	}
	
	int index = 0;

	int weightSum = 0;
	while(std::getline(treeFile, line)){
		int currentWeight;
		std::istringstream stream(line);
		std::getline(stream, treeNames[index], ',');

		stream >> currentWeight;

		if(index == 0){
			intervals[index] = 0;
		}else{
			intervals[index] = intervals[index-1] + currentWeight;
		}

		index++;	
	}
}
