#ifndef SEASONS_HANDLER
#define SEASONS_HANDLER

#include "GlobalEnums.hpp"
#include <map>
#include <string>

class SeasonsHandler {
	public:
	static month stringToMonth();
	static season stringToSeason();

	private:
	const std::map<std::string, month> stringMonthMap = {{"january", january}, {"february", february}, {"march", march},
							     {"april", april},	   {"may", may},	   {"june", june},
							     {"july", july},	   {"august", august},	   {"september", september},
							     {"october", october}, {"november", november}, {"december", december}};
	const std::map<std::string, season> stringSeasonMap = {{"winter", winter}, {"spring", spring}, {"summer", summer}, {"fall", fall}};
};
#endif
