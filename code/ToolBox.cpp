#include "ToolBox.hpp"

void ToolBox::ClearScreen(){
	for(int i = 0; i < 100; i++){
		std::cout << std::endl;
	}
}

int ToolBox::MonthsToHours(int months){
	return DaysToHours(MonthsToDays(months));
}

int ToolBox::HoursToMonths(int hours){
	return HoursToDays(hours)/30;	
}

int ToolBox::MonthsToDays(int months){
	return 30*months;
}

int ToolBox::DaysToHours(int days){
	return 24*days;
}

int ToolBox::HoursToDays(int hours){
	return hours/24;
}
