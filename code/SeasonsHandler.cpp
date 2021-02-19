#include "SeasonsHandler.hpp"

const std::map<std::string, month> SeasonsHandler::stringMonthMap = {
    {"january", january}, {"february", february}, {"march", march},	    {"april", april},	  {"may", may},		  {"june", june},
    {"july", july},	  {"august", august},	  {"september", september}, {"october", october}, {"november", november}, {"december", december}};

month SeasonsHandler::stringToMonth(std::string _month) { return stringMonthMap.at(_month); }
