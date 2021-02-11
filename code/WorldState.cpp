#include "WorldState.hpp"

WorldState::WorldState() {
  isRaining = false;
  curSeason = spring;
}
int WorldState::getTotalMushOrganisms() { return totalMushOrganisms; }

void WorldState::incrementTotalMushOrganisms() { totalMushOrganisms++; }

season WorldState::getCurrentSeason() { return curSeason; }

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
  }

  if (ageMonths < 3) {
    curSeason = spring;
  } else if (ageMonths < 6) {
    curSeason = summer;
  } else if (ageMonths < 9) {
    curSeason = fall;
  } else {
    curSeason = winter;
  }
}

int WorldState::getAgeHours() { return getAgeDays() * 24 + ageHours; }

int WorldState::getAgeDays() { return getAgeMonths() * 30 + ageDays; }

int WorldState::getAgeMonths() { return ageYears * 12 + ageMonths; }

int WorldState::getAgeYears() { return ageYears; }

int WorldState::getCurrentMonth() { return ageMonths; }

int WorldState::getCurrentDay() { return ageDays; }

int WorldState::getCurrentHour() { return ageHours; }
