#include "GlobalEnums.hpp"

//I implemented world age, seasons, etc, in world.hpp. Eventually, I should probably move those here.
class WorldState{
	private:
		int totalMushOrganisms = 0; //Keep track of how many unique mushrooms there are.
		int ageHours = 0;
		int ageDays = 0;
		int ageMonths = 0;
		int ageYears = 0;
		bool isRaining = false;
		bool isDay = true;
		season curSeason;

	public:
		WorldState();
		int getTotalMushOrganisms();
		void incrementTotalMushOrganisms();

		season getCurrentSeason();
		void updateAges(int hours);


};
