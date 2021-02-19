#ifndef SEASONS_HANDLER
#define SEASONS_HANDLER

#include "GlobalEnums.hpp"
#include <map>
#include <string>

class SeasonsHandler {
	public:
	static month stringToMonth(std::string _month);
	static season stringToSeason(std::string _season);

	private:
	static const std::map<std::string, month> stringMonthMap;
	const std::map<std::string, season> stringSeasonMap = {{"winter", winter}, {"spring", spring}, {"summer", summer}, {"fall", fall}};
};
#endif
