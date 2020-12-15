#ifndef __WORLD
#define __WORLD

#include "Ground.hpp"
#include <vector>

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
		void generateWorld(); //This will randomly generate a world
		void update(); //This should update the world one tick. Should change curPos and go through whole 2d list.
		void run(); //This will be some kind of while loop that keeps running update. May do this in main instead, not sure.

		Ground& getCurPos(); //Returns curpos
		Ground& getNorth(int dist = 1); //Should get whatever is dist north of curPos
		Ground& getSouth(int dist = 1); //Should get whatever is dist south of curPos
		Ground& getEast(int dist = 1); //Should get whatever is dist east of curPos
		Ground& getWest(int dist = 1); //Should get whatever is dist west of curPos

		//These functions should adjust the current position, as long as it's in scope.
		void moveNorth();
		void moveSouth();
		void moveEast();
		void moveWest();

		void printWorld(); //This, likely shouldn't really be used in the final version. For now it is convenient to print stuff to the terminal though.

			

		
};

#endif