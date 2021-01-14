#include "RandTreeGenerator.hpp"
#include <string>

int main(){
	std::string path = "../data/mixedforest.csv";
	WorldState worldState;
	RandTreeGenerator treeGen(path, std::make_shared<WorldState>(worldState));

	TreeTrunk* newTrunk = treeGen.generateTreeTrunk();
	std::cout << "The tree generated is " << newTrunk->getTreeType();
}

