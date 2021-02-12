#ifndef __WORLDSTATE
#define __WORLDSTATE

#include "GlobalEnums.hpp"
#include <string>
#include "world_event_code/WorldUpdateInfo.hpp"

using std::to_string;

// I implemented world age, seasons, etc, in world.hpp. Eventually, I should probably move those here.
class WorldState {
	public:
	WorldState();
	int getTotalMushOrganisms();
	void incrementTotalMushOrganisms();

	season getCurrentSeason();
	void updateAges(int hours);

	std::string getTotalAgeString();

	// These functions give you the total number of hours, days, years, etc, since the world began.
	int getAgeHours();
	int getAgeDays();
	int getAgeMonths();
	int getAgeYears();

	// These functions get you which month it is in the year, which day it is in the month, and which hour it is in the day.
	// I.E., getCurrentMonth() never returns anything larger than 12.
	int getCurrentMonth();
	int getCurrentDay();
	int getCurrentHour();
	WorldUpdateInfo& getUpdateInfo();

	private:
	int totalMushOrganisms = 0; // Keep track of how many unique mushrooms there are.
	int ageHours = 0;
	int ageDays = 0;
	int ageMonths = 0;
	int ageYears = 0;
	bool isRaining = false;
	bool isDay = true;
	season curSeason;
	WorldUpdateInfo updateInfo;
};

#endif
