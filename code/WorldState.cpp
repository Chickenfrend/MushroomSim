#include "WorldState.hpp"
using std::to_string;
WorldState::WorldState() {
	isRaining = false;
	curSeason = spring;
}
int WorldState::getTotalMushOrganisms() { return totalMushOrganisms; }

void WorldState::incrementTotalMushOrganisms() { totalMushOrganisms++; }

season WorldState::getCurrentSeason() { return curSeason; }

void WorldState::update(int hours) {
	int prevAgeDays = ageDays;
	updateAges(hours);
	if (prevAgeDays != ageDays) {
		updateCloudCover();
	}
	updateIfRaining();
}

// For now, this is how I'm doing it. But I think it'd be better to properly
// generate random percentages and such.
void WorldState::updateCloudCover() {
	int cloudCover = rand() % 100;
	int cloudCoverAdjust = rand();

	switch (curSeason) {
	case winter:
		cloudCoverAdjust = cloudCoverAdjust % 50;
		break;
	case spring:
		cloudCoverAdjust = -(cloudCoverAdjust % 30);
		break;
	case summer:
		cloudCoverAdjust = -(cloudCoverAdjust % 80);
		break;
	case fall:
		cloudCoverAdjust = cloudCoverAdjust % 20;
		break;
	}

	cloudCover += cloudCoverAdjust;

	if (cloudCover > 100) {
		cloudCover = 100;
	}
	if (cloudCover < 0) {
		cloudCover = 0;
	}
	cloudPercent = ((float)cloudCover) / 100.f;
	updateInfo.appendInfoLine("The cloud cover is now: " + to_string(cloudPercent));
}

void WorldState::updateIfRaining() {
	float chanceOfRain = 0.9f;
	chanceOfRain *= cloudPercent; 

	int rainRand = rand() % 100;
	if (float(rainRand) / 100.f < chanceOfRain) {
		if (isRaining == false) {
			updateInfo.appendInfoLine("It started raining!");
		}
		isRaining = true;
	} else {
		if (isRaining == true) {
			updateInfo.appendInfoLine("It stopped raining!");
		}
		isRaining = false;
	}
}

void WorldState::updateAges(int hours) {
	ageHours += hours;

	if (ageHours >= 24) {
		ageDays += ageHours / 24;
		ageHours = ageHours % 24;
	}

	if (ageDays >= 30) {
		ageMonths += ageDays / 30;
		ageDays = ageDays % 30;
	}

	if (ageMonths >= 12) {
		ageYears += ageMonths / 12;
		ageMonths = ageMonths % 12;
		curMonth = (month)ageMonths;
	}

	season beginningSeason = curSeason;
	if (ageMonths < 3) {
		curSeason = spring;
	} else if (ageMonths < 6) {
		curSeason = summer;
	} else if (ageMonths < 9) {
		curSeason = fall;
	} else {
		curSeason = winter;
	}
	if (beginningSeason != curSeason) {
		updateInfo.appendInfoLine("Season update to " + std::to_string(curSeason));
	}
}

string WorldState::getTotalAgeString() {
	string result =
	    "Years: " + to_string(ageYears) + " Months: " + to_string(ageMonths) + " Days: " + to_string(ageHours) + " Hours: " + to_string(ageHours);
	return result;
}

WorldUpdateInfo &WorldState::getUpdateInfo() { return updateInfo; }

int WorldState::getAgeHours() { return getAgeDays() * 24 + ageHours; }

int WorldState::getAgeDays() { return getAgeMonths() * 30 + ageDays; }

int WorldState::getAgeMonths() { return ageYears * 12 + ageMonths; }

int WorldState::getAgeYears() { return ageYears; }

int WorldState::getCurrentMonth() { return ageMonths; }

int WorldState::getCurrentDay() { return ageDays; }

int WorldState::getCurrentHour() { return ageHours; }
