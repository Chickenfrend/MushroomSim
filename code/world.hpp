#ifndef __WORLD
#define __WORLD

#include "ground.hpp"
class world{
	private:
		enum season {spring, summer, fall, winter};
		bool isRaining;
		season curSeason;
		int size = 20;
		vector<vector<Ground>> world; 
		std::pair<int,int> curPos; 
		void initWorld(); //Called by generate world. Just, defines the vector for the world.
	public:
		void generateWorld(); //This will randomly generate a world
		void update(); //This should update the world one tick. Should change curPos and go through whole 2d list.
		void run(); //This will be some kind of while loop that keeps running update. May do this in main instead, not sure.

		void getCurPos(); //Returns curpos
		void getNorth(); //Should get whatever is north of curPos
		void getSouth(); //Should get whatever is south of curPos
		void getEast(); //Should get whatever is east of curPos
		void getWest(); //Should get whatever is west of curPos

			

		
}

#endif
