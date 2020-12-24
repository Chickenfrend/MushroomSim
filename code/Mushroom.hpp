#ifndef __MUSHROOM
#define __MUSHROOM

#include <string> 
#include <memory>
#include "ShroomTracker.hpp"
#include "GameObject.hpp"

class Mushroom: public GameObject{
	private:
		std::string graphicsSymbol = "m";
		float density; //The density of the mycelium in whatever ground block (should this be kept in the ground object?).
		std::shared_ptr<ShroomTracker> organism; // A pointer to a shroom tracker object, which keeps track of what larger organism this mycelium block is part of.
	protected:
		int reproductiveAge; //The age at which the mycelium starts to produce mushrooms.
		bool isBlooming; //Whether or not the mycelium is making mushrooms
		std::string description; //The description of the mushroom. Possibly, this could be stored in the shroom tracker object to avoid unecessarily repeated storage of information. 
		std::string name; //The name of the mushrooms species.

	public:
		Mushroom(std::shared_ptr<WorldState>);
		Mushroom(std::shared_ptr<WorldState>, std::shared_ptr<ShroomTracker> sharedTracker);
		virtual bool checkSpreadConditions(); //Returns true if the mushroom is able to spread!
		virtual bool checkBloomConditions(); // Returns true if the mushroom is ready to bloom!
		void sporeRelease();

		float getDensity();

		bool getBloomingStatus();
		std::string getDescription();
		std::string getName();
		std::shared_ptr<ShroomTracker> getShroomTracker();
		Mushroom* generateMycelium(); //Produces a new mycelium block. Remember memory management! This allocates memory for the new mushroom pointer.

		void setShroomTracker(std::shared_ptr<ShroomTracker> tracker);

		std::string getASCIIGraphics();
};

#endif
