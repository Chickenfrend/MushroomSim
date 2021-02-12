#include "WorldUpdateInfo.hpp"

WorldUpdateInfo::WorldUpdateInfo() { updateInfo = ""; }

WorldUpdateInfo::WorldUpdateInfo(string info) { updateInfo += info + "\n"; }

void WorldUpdateInfo::appendInfoLine(string info) { updateInfo += info + "\n"; }
void WorldUpdateInfo::resetInfo() { updateInfo = ""; }

sf::String WorldUpdateInfo::getText() { return updateInfo; }

