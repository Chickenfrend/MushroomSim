#ifndef __RANDOMSHROOMGENERATOR
#define __RANDOMSHROOMGENERATOR
#include "Chanterelle.hpp"
#include "AmanitaMuscaria.hpp"
#include <vector>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

class RandShroomGenerator{
	public:
		RandShroomGenerator(std::string _shroomPath, std::shared_ptr<WorldState> currentState);
		//This function allocates memory! If you call it you must either encapsulate the pointer
		//with a smart pointer or remember to delete it.
		Mushroom* generateMushroom();
	private:
		std::string forestPath;
		void GenerateLists();
		std::string pickRandom();
		std::vector<std::string> shroomNames;
		std::vector<int> intervals;
		std::shared_ptr<WorldState> worldState;
};

#endif
