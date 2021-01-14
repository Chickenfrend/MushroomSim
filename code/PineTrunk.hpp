#ifndef __PINETRUNK
#define __PINETRUNK

#include "TreeTrunk.hpp"

class PineTrunk: public TreeTrunk{
	public:
		PineTrunk(std::shared_ptr<WorldState> currentState);
		virtual bool checkRootRequirements();
	protected:
		virtual void updateStage();

};

#endif
