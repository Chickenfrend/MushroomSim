#include <stdio.h>
#include "World.hpp"

int main(){
	World testworld;

	std::cout << "Generating world" << std::endl;

	testworld.generateWorld();

	testworld.printWorld();

	std::cout << "Populating world" << std::endl;

	testworld.populateWorld();

	testworld.printWorld();
}
