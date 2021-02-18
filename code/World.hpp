#ifndef __WORLD
#define __WORLD

#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "GlobalEnums.hpp"
#include "Ground.hpp"
#include "RandShroomGenerator.hpp"
#include "RandTreeGenerator.hpp"
#include "ToolBox.hpp"
#include "world_event_code/WorldUpdateInfo.hpp"

/* Concept for later. We could make the world wrap, and add our own functions to
 * add horizontally and vertically to curPos, which would use modular addition
 * to adjust the current position. Get north, south, etc, would also adjust
 * accordingly.
 */

class World {
	public:
	World();
	// This will randomly generate a world,
	// populating it with tree trunks randomly.
	void generateWorld();
	// This will let the trees grow for a bit then
	// randomly populate with mushrooms.
	// This needs to be changed so that it just tells each tree to grow a certain amount.
	// The way it works now is very inefficient.
	void populateWorld();
	// This should update the world one tick. Should change
	// curPos and go through whole 2d list.
	// Right now, it updates everything just, hours hours. Which is honestly kind of unmaintanable
	// due to the fact we'll need to update ground moisture, etc, based off how much the world has rained.
	// Would probably be better to set a max update of, maybe, 24 hours, and then if it goes above that we can
	// just loop and update hours % 24 times. It should be easier to guess the average rainfall over the course of a day
	// or less than it would be over the course of months.
	// WE SHOULD CALCULATE THE AVERAGE RAINFALL ONLY ONCE AT THE BEGINNING OF THE UPDATE!
	void update(int hours);
	// This will be some kind of while loop that keeps running
	// update. May do this in main instead, not sure.
	void run();
	bool hasTreeInArea(int dist); // If there's a tree trunk in a certain
				      // area, returns true. Calls getArea.

	Ground &getCurPos();			  // Returns the ground at curpos, not curPos
						  // itself.
	Ground *getNearCurPos(int hor, int vert); // This gets the position hor horizontally from
						  // curPos, and vert vertically from curPos.

	// The following are flawed since they return references when it's very
	// possible we might wind up exceeding the vector bounds. In those cases
	// it would be better to return a null pointer or throw an exception.
	// Either these need to be changed to return pointers, or we should just be very careful when
	// we call them.
	Ground &getNorth(int dist = 1);		 // Should get whatever is dist north of curPos
	Ground &getSouth(int dist = 1);		 // Should get whatever is dist south of curPos
	Ground &getEast(int dist = 1);		 // Should get whatever is dist east of curPos
	Ground &getWest(int dist = 1);		 // Should get whatever is dist west of curPos
	std::vector<Ground *> getArea(int dist); // dist is the distance from curPos in which to get.
						 // Square area centered on curPos.

	// Note that these functions just adjust curPos.
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();

	// This moves curPos to the next valid position. Useful so that we can
	// iterate through the world without always having to explicitly write
	// Double nested loops.
	void moveNext();

	bool curPosAtEnd();

	void resetCurPos();

	// These functions adjust the position of the cursor
	void cursorRight();
	void cursorLeft();
	void cursorUp();
	void cursorDown();
	std::pair<int, int> getCursor();

	Ground &getCursorGround();

	void printWorld(); // This, likely shouldn't really be used in the
			   // final version. For now it is convenient to print
			   // stuff to the terminal though.
	std::vector<std::vector<std::string>> getSpriteNames();
	WorldState &getWorldState();

	private:
	bool isRunning = false;
	WorldState worldState;

	std::string forestPath = "../data/forests/mixedforest";
	int size = 100;
	std::vector<std::vector<Ground>> world;
	std::vector<std::vector<std::string>> spriteList;
	std::pair<int, int> curPos;
	std::pair<int, int> cursor;

	void initWorld(); // Called by generate world. Just, defines the vector
			  // for the world.
};

#endif
