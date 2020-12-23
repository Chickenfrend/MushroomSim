#include "GlobalEnums.hpp"

//I implemented world age, seasons, etc, in world.hpp. Eventually, I should probably move those here.
class WorldState{
	private:
		int totalMushOrganisms = 0; //Keep track of how many unique mushrooms there are.

	public:
		int getTotalMushOrganisms();
		void incrementTotalMushOrganisms();


};
