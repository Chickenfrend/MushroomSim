#ifndef __TREETRUNK
#define __TREETRUNK

#include <string>
#include <memory>
#include "GlobalEnums.hpp"
#include "TreeRoot.hpp"

class TreeTrunk{
	public:
		enum TreeStage : int{
			seed,
			sprout,
			seedling,
			sapling,
			mature,
			decline,
			snag
		};

		void age(); //This function calls the other age functions and updates all the counters for the trees age.

		void growTaller();
		void growRoots();
		virtual void growRootsCheck() = 0;

		bool getDeciduousStatus();
		int getDistanceTolerance();
		std::string getDescription();
		std::string getTreeType();
		std::string loadDescription(std::string name);

		void setCurrentSeason(season updatedSeason);
		//Concept. Since TreeTrunk doesn't have access to it's world, we can have it generate a new tree root object and pass it to ground or world, which can 
		//do the work of actually placing roots.
		TreeRoot* generateTreeRoot();	


		std::string getASCIIGraphics();

	private:
	protected:
		
		std::string treeType;
		std::string description;
		bool isDeciduous; 
		int maxDistance;//This is the distance the roots should grow from the tree (in blocks)
		int distance;//Actual distance of the roots.
		int distanceTolerance = 2; //How close this tree will spawn from other trees.
		int rootCircumference = 0; //The real root circumference of this tree.
		int maxRootCircumference = 3; //Maximum distance roots can grow.

		int ageHours = 0;
		int ageYears = 0;
		int ageMonths = 0;
		int ageDays = 0;
		int stage = seed;//This should be the stage of the tree. Young, old, etc. May have an enum for this.
		int currentSeason = spring;

		float height = 0;
		float circumference = 0;
		float maxHeight = 0;

		std::string graphicsSymbol = "T";

		void ageHour();
		void updateAgeDay();
		void updateAgeMonth();
		void updateAgeYear();
		virtual void updateStage();


};

#endif
