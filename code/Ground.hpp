#ifndef __GROUND
#define __GROUND

#include "Mushroom.hpp"
#include "TreeRoot.hpp"
#include "TreeTrunk.hpp"
#include "OakTrunk.hpp"
#include "World.hpp"
#include <memory>
#include <string>

class World;
class Ground{
	private:
		//Moisture and density are percentages that indicate how dense, and moist, respectively, the soil is.
		//Drainage rate is the rate at which moisture leaves the ground.
		float density;
		float moisture;
		float drainageRate;
		std::unique_ptr<TreeRoot> root;
		std::unique_ptr<Mushroom> mushroom;
		std::unique_ptr<TreeTrunk> trunk;
		World* world = nullptr;

	public:
		Ground(float _density = 0.0f, float _moisture = 0.0f, float _drainageRate = 0.0f);
		float getDensity();
		float getMoisture();
		TreeRoot* getTreeRoot();
		TreeTrunk* getTreeTrunk();
		Mushroom* getMushroom();
		bool hasTreeTrunk();
		
		void setDensity(float d);
		void setMoisture(float m);
		void setTreeTrunk(TreeTrunk* t);
		void setTreeRoot(TreeRoot* newroot);
		void setTreeSeason(int newSeason);
		void setWorld(World* parentWorld);
		void updateTreeSeason();
		void growTreeRoots();

		std::string getASCIIGraphics();//For now this is what we'll use to decide what to print in the world print function.

		void update(int hours);
};

#endif
