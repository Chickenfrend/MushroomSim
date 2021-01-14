#ifndef __MUSHROOM
#define __MUSHROOM

#include <string> 
#include <memory>
#include <vector>
#include "ShroomTracker.hpp"
#include "GameObject.hpp"
#include "ToolBox.hpp"
#include "TreeRoot.hpp"

class Mushroom: public GameObject{
	private:
		int ageHours = 0;
		int ageDays = 0;
		int ageYears = 0;
   		int ageMonths = 0;


		float density; //The density of the mycelium in whatever ground block (should this be kept in the ground object?).
		std::shared_ptr<ShroomTracker> organism; // A pointer to a shroom tracker object, which keeps track of what larger organism this mycelium block is part of.
        //Possible could be in shroom tracker...
        void storeValidTreeList();
        std::vector<std::string> validTrees;

	protected:
		int spreadFrequencyMonths = 0; //This variable is used when checking if it should spread. Setting it to 0 means it will spread yearly.
		int reproductiveAge; //The age at which the mycelium starts to produce mushrooms.
		bool isBlooming; //Whether or not the mycelium is making mushrooms
		bool canSpread = false;
		std::string description; //The description of the mushroom. Possibly, this could be stored in the shroom tracker object to avoid unecessarily repeated storage of information. 
		std::string name; //The name of the mushrooms species.
		std::string graphicsSymbol = "m";

	public:
		Mushroom(std::shared_ptr<WorldState>);
		Mushroom(std::shared_ptr<WorldState>, std::shared_ptr<ShroomTracker> sharedTracker);
		virtual void updateSpreadConditions(int hours);
		bool checkSpreadConditions(); //Returns true if the mushroom is able to spread!
		virtual bool checkBloomConditions(); // Returns true if the mushroom is ready to bloom!
		virtual bool checkSoilConditions(TreeRoot* root);

		void update(int hours);
		void sporeRelease();

		//Might be smart to keep these in GameObject.
		int getAgeHours();
		int getAgeDays();
		int getAgeMonths();
		void age(int hours);

		float getDensity();

		bool getBloomingStatus();
		std::string getDescription();
		std::string getName();
		std::shared_ptr<ShroomTracker> getShroomTracker();
		virtual Mushroom* generateMycelium() = 0; //Produces a new mycelium block. Remember memory management! This allocates memory for the new mushroom pointer.

		void setShroomTracker(std::shared_ptr<ShroomTracker> tracker);

		std::string getASCIIGraphics();
};

#endif
