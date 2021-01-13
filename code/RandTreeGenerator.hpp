#ifndef __RANDOMTREEGENERATOR
#define __RANDOMTREEGENERATOR
#include "OakTrunk.hpp"
#include "PineTrunk.hpp"
#include <vector>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

class RandTreeGenerator{
	public:
		RandTreeGenerator(std::string _forestPath, std::shared_ptr<WorldState> currentState);
		//This function allocates memory! If you call it you must either encapsulate the pointer
		//with a smart pointer or remember to delete it.
		TreeTrunk* generateTreeTrunk();
	private:
		std::string forestPath;
		void GenerateLists();
		std::string pickRandom();
		std::vector<std::string> treeNames;
		std::vector<int> intervals;
		std::shared_ptr<WorldState> worldState;
};

#endif
