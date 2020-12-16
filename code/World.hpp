#ifndef __WORLD
#define __WORLD

#include "Ground.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include<stdlib.h>

/* Concept for later. We could make the world wrap, and add our own functions to add horizontally and vertically to curPos, which would
 * use modular addition to adjust the current position. Get north, south, etc, would also adjust accordingly.
 */
class World{
	private:
		enum season {spring, summer, fall, winter};
		bool isRaining;
		season curSeason;
		int size = 20;
		std::vector<std::vector<Ground>> world; 
		std::pair<int,int> curPos; 
		void initWorld(); //Called by generate world. Just, defines the vector for the world.

	public:
		void generateWorld(); //This will randomly generate a world, populating it with tree trunks randomly.
		void populateWorld(); //This will let the trees grow for a bit then randomly populate with mushrooms.
		void update(); //This should update the world one tick. Should change curPos and go through whole 2d list.
		void run(); //This will be some kind of while loop that keeps running update. May do this in main instead, not sure.

		Ground& getCurPos(); //Returns curpos
		Ground& getNorth(int dist = 1); //Should get whatever is dist north of curPos
		Ground& getSouth(int dist = 1); //Should get whatever is dist south of curPos
		Ground& getEast(int dist = 1); //Should get whatever is dist east of curPos
		Ground& getWest(int dist = 1); //Should get whatever is dist west of curPos
		std::vector<Ground*> getArea(int dist); //Returns a vector of pointers to the nearby ground tiles, within a certain distance in every direction from curPos. 

		bool hasTreeInArea(int dist); //If there's a tree trunk in a certain area, returns true. Calls getArea.

		//These functions should adjust the current position, as long as it's in scope.
		void moveNorth();
		void moveSouth();
		void moveEast();
		void moveWest();

		void resetCurPos();

		void printWorld(); //This, likely shouldn't really be used in the final version. For now it is convenient to print stuff to the terminal though.

			

		
};

#endif
