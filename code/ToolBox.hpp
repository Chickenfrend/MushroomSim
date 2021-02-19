#ifndef __TOOLBOX
#define __TOOLBOX

#include <iostream>
#include <string>
#include "GlobalEnums.hpp"

namespace ToolBox{
	void ClearScreen();
	int MonthsToHours(int months);
	int HoursToMonths(int hours);
	int MonthsToDays(int months);
	int DaysToHours(int days);
	int HoursToDays(int hours);
	month stringToMonth(std::string _month);
}

#endif
