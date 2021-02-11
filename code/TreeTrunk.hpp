#ifndef __TREETRUNK
#define __TREETRUNK

#include <iostream>
#include <memory>
#include <string>

#include "GameObject.hpp"
#include "GlobalEnums.hpp"
#include "TreeRoot.hpp"

class TreeTrunk : public GameObject {
	public:
	TreeTrunk(std::shared_ptr<WorldState> currentWorldState);
	enum TreeStage : int { seed, sprout, seedling, sapling, mature, decline, snag };

	void growTaller();
	void growRoots();

	bool getDeciduousStatus();
	virtual bool checkRootRequirements(); // Returns true if it's time to
					      // grow a new root layer!
	int getDistanceTolerance();
	std::string getDescription();
	std::string getTreeType();
	int getRootRadius();
	int getMaxRootRadius();

	std::string loadDescription(std::string name);

	void setRootRadius(int newRad);

	int getAgeHours();
	int getAgeDays();
	int getAgeMonths();
	void age(int hours); // This function ages the tree int hours and
			     // adjusts all the age variables.

	// Since TreeTrunk doesn't have access to it's world, we can have it
	// generate a new tree root object and pass it to ground or world, which
	// can do the work of actually placing roots. If you use this, remember
	// memory management! This allocates memory for a new pointer.
	TreeRoot *generateTreeRoot();

	std::string getASCIIGraphics();
	virtual ~TreeTrunk(){}

	private:
	protected:
	std::string treeType;
	std::string description;
	bool isDeciduous;
	int childRoots = 0;	   //
	int distance;		   // Actual distance of the roots.
	int distanceTolerance = 3; // How close this tree will spawn from other trees.
	int rootRadius = 0;	   // The real root circumference of this tree.
	int maxRootRadius = 2;	   // Maximum distance roots can grow.

	int ageHours = 0;
	int ageYears = 0;
	int ageMonths = 0;
	int ageDays = 0;
	int stage = seed; // This should be the stage of the tree. Young, old,
			  // etc. May have an enum for this.

	float height = 0;
	float circumference = 0;
	float maxHeight = 0;

	std::string graphicsSymbol = "T";

	virtual void updateStage();
};

#endif
