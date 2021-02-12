#include "WorldUpdateInfo.hpp"

WorldUpdateInfo::WorldUpdateInfo() { updateInfo.setString(""); }

WorldUpdateInfo::WorldUpdateInfo(string info) { updateInfo.setString(info + "\n"); }

void WorldUpdateInfo::appendInfoLine(string info) { updateInfo.setString(updateInfo.getString() + info + "\n"); }
void WorldUpdateInfo::resetInfo() { updateInfo.setString(""); }

sf::Text WorldUpdateInfo::getText() { return updateInfo; }

