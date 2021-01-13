#ifndef __RANDOMTREEPICKER
#define __RANDOMTREEPICKER
#include "TreeTrunk.hpp"
#include <vector>

class RandTreeGenerator{
	public:
		RandTreeGenerator(std::string _forestPath);
		TreeTrunk* generateTreeTrunk();
	private:
		std::string forestPath;
		void GenerateLists();
		std::vector<std::string> treeNames;
		std::vector<int> weights;
};

#endif
