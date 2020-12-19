#ifndef __TREEROOT
#define __TREEROOT

//#include "TreeTrunk.hpp"
#include <string>
#include <memory>
class TreeRoot{
	private:
		std::string treeType;
		bool isDeciduous;
		int distanceFromTrunk;
		//std::unique_ptr<TreeTrunk> parentTrunk;
		std::pair<int,int> parentPos;
	public:
		std::string getASCIIGraphics();

	
};

#endif
