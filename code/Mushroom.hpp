#ifndef __MUSHROOM
#define __MUSHROOM

#include <string> 
#include <memory>
#include "ShroomTracker.hpp"
class Mushroom{
	protected:
		char graphicsSymbol = 'm';
		float density; //The density of the mycelium in whatever ground block (should this be kept in the ground object?).
		int reproductiveAge; //The age at which the mycelium starts to produce mushrooms.
		bool isBlooming; //Whether or not the mycelium is making mushrooms
		std::string description; //The description of the mushroom. Possibly, this could be stored in the shroom tracker object to avoid unecessarily repeated storage of information. 
		std::string name; //The name of the mushrooms species.
		std::unique_ptr<ShroomTracker> organism; // A pointer to a shroom tracker object, which keeps track of what larger organism this mycelium block is part of.

	public:
		virtual bool checkSpreadConditions() = 0;
		void spread();
		void sporeRelease();

		float getDensity();
		bool getBloomingStatus();
		std::string getDescription();
		std::string getName();
		std::unique_ptr<ShroomTracker> getShroomTracker();

		void setShroomTracker(std::unique_ptr<ShroomTracker> tracker);

		char getASCIIGraphics();
};

#endif
