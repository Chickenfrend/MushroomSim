#ifndef __MUSHROOM
#define __MUSHROOM

#include <algorithm>
#include <fstream>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "GameObject.hpp"
#include "ShroomTracker.hpp"
#include "GlobalEnums.hpp"
#include "ToolBox.hpp"
#include "TreeRoot.hpp"

using std::ifstream;
using std::string;

class Mushroom : public GameObject {
	private:
	int ageHours = 0;
	int ageDays = 0;
	int ageYears = 0;
	int ageMonths = 0;

	float density; // The density of the mycelium in whatever ground block
		       // (should this be kept in the ground object?).
	std::shared_ptr<ShroomTracker> organism; // A pointer to a shroom tracker object, which keeps
						 // track of what larger organism this mycelium block is
						 // part of.
	// Possible could be in shroom tracker...
	std::set<std::string> validTrees;
	std::set<month> bloomMonths;

	protected:
	bool needsTreeList = true;
	bool checkIfValidTree(string treeName);

	// This variable is used when checking if it should spread.
	// Setting it to 0 means it will spread yearly.
	int spreadFrequencyMonths = 0;
	int reproductiveAge; // The age at which the mycelium starts to produce
			     // mushrooms.
	bool isBlooming;     // Whether or not the mycelium is making mushrooms
	bool canSpread = false;

	// The description of the mushroom. Possibly, this
	// could be stored in the shroom tracker object to
	// avoid unecessarily repeated storage of information.
	std::string description;
	std::string name; // The name of the mushrooms species.
	std::string graphicsSymbol = "m";
	void storeValidTreeList();
	void storeValidMonths();

	public:
	Mushroom(std::shared_ptr<WorldState>);
	Mushroom(std::shared_ptr<WorldState>, std::shared_ptr<ShroomTracker> sharedTracker);
	virtual void updateSpreadConditions(int hours);
	// Returns true if the mushroom is able
	// to spread!
	bool checkSpreadConditions();
	virtual bool checkBloomConditions(); // Returns true if the mushroom is
					     // ready to bloom!
	virtual bool checkSoilConditions(TreeRoot *root);

	std::string getShroomType();

	void update(int hours);
	void sporeRelease();

	// Might be smart to keep these in GameObject.
	int getAgeHours();
	int getAgeDays();
	int getAgeMonths();
	void age(int hours);

	float getDensity();

	bool getBloomingStatus();
	std::string getDescription();
	std::string getName();
	std::shared_ptr<ShroomTracker> getShroomTracker();
	virtual Mushroom *generateMycelium() = 0; // Produces a new mycelium block. Remember
						  // memory management! This allocates memory for
						  // the new mushroom pointer.

	void setShroomTracker(std::shared_ptr<ShroomTracker> tracker);

	std::string getASCIIGraphics();

	virtual ~Mushroom() {}
};

#endif
