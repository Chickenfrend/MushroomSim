#include "RandTreeGenerator.hpp"

RandTreeGenerator::RandTreeGenerator(std::string _forestPath,
                                     std::shared_ptr<WorldState> currentState) {
  forestPath = _forestPath;
  worldState = currentState;
  GenerateLists();
}

void RandTreeGenerator::GenerateLists() {
  std::ifstream treeFile(forestPath + "/trees.csv");

  std::string line;
  std::string firstLine;
  std::string treeName;

  if (!treeFile.is_open()) {
    throw std::runtime_error("Could not open forest file");
  }

  if (treeFile.good()) {
    std::getline(treeFile, firstLine);
  } else {
    throw std::runtime_error("File is not good");
  }

  int index = 0;

  while (std::getline(treeFile, line)) {
    int currentWeight;
    std::istringstream stream(line);
    std::string tempString = "";
    std::getline(stream, tempString, ',');
    treeNames.push_back(tempString);

    stream >> currentWeight;

    if (index == 0) {
      intervals.push_back(currentWeight);
    } else {
      intervals.push_back(intervals[index - 1] + currentWeight);
    }

    index++;
  }

}

std::string RandTreeGenerator::pickRandom() {
  int randInt = rand() % intervals.back();
  for (size_t i = 0; i < intervals.size(); i++) {
    if (randInt < intervals[i]) {
      return treeNames[i];
    }
  }
  throw std::runtime_error(
      "Failed to pick a random tree. Bad or empty forest file?");
}

TreeTrunk *RandTreeGenerator::generateTreeTrunk() {
  std::string randTreeName = pickRandom();
  if (randTreeName == "OakTrunk") {
    return new OakTrunk(worldState);
  } else if (randTreeName == "PineTrunk") {
    return new PineTrunk(worldState);
  } else {
    std::string error = "Invalid tree name " + randTreeName;
    throw std::runtime_error(error);
    return new TreeTrunk(worldState);
  }
}
