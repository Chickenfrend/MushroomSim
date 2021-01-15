#ifndef __AMANITA_MUSCARIA
#define __AMANITA_MUSCARIA

#include "Mushroom.hpp"
#include <iostream>
using std::shared_ptr;

class AmanitaMuscaria: public Mushroom{
	public:
		AmanitaMuscaria(shared_ptr<WorldState> currentState);
		AmanitaMuscaria(shared_ptr<WorldState> currentState, shared_ptr<ShroomTracker> sharedTracker);

		bool checkSoilConditions(TreeRoot* root) override;

		Mushroom* generateMycelium();
};

#endif
