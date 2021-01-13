#ifndef __RANDOMTREEGENERATOR
#define __RANDOMTREEGENERATOR
#include "TreeTrunk.hpp"
#include <vector>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

class RandTreeGenerator{
	public:
		RandTreeGenerator(std::string _forestPath);
		TreeTrunk* generateTreeTrunk();
	private:
		std::string forestPath;
		void GenerateLists();
		std::vector<std::string> treeNames;
		std::vector<int> intervals;
};

#endif
