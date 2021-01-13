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
        std::cout << "Got Here" << std::endl;
	}else{
        throw std::runtime_error("File is not good");
    }
	
	int index = 0;

	int weightSum = 0;
	while(std::getline(treeFile, line)){
		int currentWeight;
		std::istringstream stream(line);
        std::string tempString = "";
		std::getline(stream, tempString, ',');
        treeNames.push_back(tempString);

		stream >> currentWeight;

		if(index == 0){
			intervals.push_back(currentWeight);
		}else{
			intervals.push_back(intervals[index-1] + currentWeight);
		}

		index++;	
	}

    for(int i = 0; i < treeNames.size(); i++){
        std::cout << treeNames[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < intervals.size(); i++){
        std::cout << intervals[i] << " ";
    }
    std::cout << std::endl;


}
