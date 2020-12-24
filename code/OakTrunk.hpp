#ifndef __OAKTRUNK
#define __OAKTRUNK

#include "TreeTrunk.hpp"

class OakTrunk: public TreeTrunk{
	public:
		OakTrunk(std::shared_ptr<WorldState> currentState);
		void growRootsCheck();

};

#endif
