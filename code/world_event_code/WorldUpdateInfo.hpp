#ifndef WORLD_UPDATE_INFO
#define WORLD_UPDATE_INFO

#include <TGUI/TGUI.hpp>
#include <string>
using std::string;

// This is a class to hold information on when the world updates.
// Possibly, will be used as a base class to store specific types of information

class WorldUpdateInfo {
	public:
	WorldUpdateInfo();
	WorldUpdateInfo(string info);

	void appendInfoLine(string info);
	void resetInfo();
	sf::Text getText();

	private:
	sf::Text updateInfo;
};

#endif
