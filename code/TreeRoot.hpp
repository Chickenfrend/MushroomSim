#ifndef __TREETRUNK
#define __TREETRUNK

#include "TreeTrunk.hpp"
namespace Objects{
	class TreeRoot{
		private:
			string treeType;
			bool isDeciduous;
			int distanceFromTrunk;
			std::unique_ptr<TreeTrunk> parentTrunk;
			std::pair<int,int> parentPos;
		public:

		
	}
}

#endif
