#include "TreeRoot.hpp"

TreeRoot::TreeRoot(std::string parentType, bool parentDeciduous) {
  treeType = parentType;
  isDeciduous = parentDeciduous;
}

std::string TreeRoot::getASCIIGraphics() { return "r"; }

bool TreeRoot::getIfDeciduous() { return isDeciduous; }

std::string TreeRoot::getTreeType() { return treeType; }
