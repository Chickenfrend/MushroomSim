#ifndef __GROUND
#define __GROUND

#include "Chanterelle.hpp"
#include "Mushroom.hpp"
#include "OakTrunk.hpp"
#include "TreeRoot.hpp"
#include "TreeTrunk.hpp"
#include <memory>
#include <string>

class World;
class Ground {
	public:
	Ground(float _density = 0.0f, float _moisture = 0.0f, float _drainageRate = 0.1f);
	float getDensity();
	float getMoisture();
	int getNutrients();
	TreeRoot *getTreeRoot();
	TreeTrunk *getTreeTrunk();
	Mushroom *getMushroom();
	bool hasTreeTrunk();
	bool hasMushroom();
	bool hasTreeRoot();

	void setDensity(float d);
	void setMoisture(float m);
	void setMushroom(Mushroom *m);
	void setTreeTrunk(TreeTrunk *t);
	void setTreeRoot(TreeRoot *newroot);
	void setWorld(World *parentWorld);

	void growTreeRoots();
	void growMushroom();

	std::string getASCIIGraphics(); // For now this is what we'll use to decide what to print in the world print function.
	std::string getSpriteName();	// This decides what sprite needs to be printed. Used by the gui hopefully.

	void update(int hours);

	private:
	// Moisture and density are percentages that indicate how dense, and moist, respectively, the soil is.
	// Drainage rate is the rate at which moisture leaves the ground.
	void updateMoisture(int timeDifference);
	void passiveNutrientGrowth(int hours);
	float density = 0.f;
	float moisture = 0.f;
	int nutrients = 10000;
	// How many nutrients the ground will passively regain each hour.
	int passiveNutrientGain = 5;
	int nutrientPassiveMax = 1000;
	// accumulationRate and drainageRate determine how fast the ground gains and loses water.
	float accumulationRate = 0.015f;
	float drainageRate = 0.01f;
	std::unique_ptr<TreeRoot> root;
	std::unique_ptr<Mushroom> mushroom;
	std::unique_ptr<TreeTrunk> trunk;
	World *world = nullptr;
};

#endif
