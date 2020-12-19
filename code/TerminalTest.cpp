#include <stdio.h>
#include "World.hpp"

int main(){
	World testworld;

	testworld.generateWorld();

	testworld.printWorld();

	testworld.populateWorld();

	testworld.printWorld();
}
