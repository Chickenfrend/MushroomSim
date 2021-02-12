#include "PineTrunk.hpp"

#include <string>

PineTrunk::PineTrunk(std::shared_ptr<WorldState> currentState)
    : TreeTrunk(currentState) {
  treeType = "PineTree";
  description = loadDescription(treeType);
  isDeciduous = false;

  maxHeight = 150.0f;
  graphicsSymbol = "\033[33mP\033[0m";
}

bool PineTrunk::checkRootRequirements() {
  if (stage == sprout && rootRadius == 0) {
    return true;
  } else if (stage == sapling && rootRadius == 1) {
    return true;
  } else if (stage == mature && rootRadius == 2) {
    return true;
  } else {
    return false;
  }

  return false;
}

void PineTrunk::updateStage() {
  if (getAgeHours() < 1) {
    stage = seed;
    height = 0;
  } else if (stage == seed && getAgeDays() >= 15) {
    stage = sprout;
    height = 2; } else if (stage == sprout && getAgeMonths() >= 2) {
    stage = sapling;
    height = 15;
  } else if (stage == sapling && ageYears >= 30) {
    stage = mature;
    height = 100;
  }
}
