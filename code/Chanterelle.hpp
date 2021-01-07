#ifndef __CHANTERELLE
#define __CHANTERELLE

#include "Mushroom.hpp"

class Chanterelle: public Mushroom{
	public:
		Chanterelle(std::shared_ptr<WorldState> currentState);
		Chanterelle(std::shared_ptr<WorldState> currentState, std::shared_ptr<ShroomTracker> sharedTracker);
};

#endif
