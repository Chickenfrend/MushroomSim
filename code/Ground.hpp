#include "Mushroom.hpp"
#include "TreeRoot.hpp"
#include "TreeTrunk.hpp"
#include "OakTrunk.hpp"
#include <memory>

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

	public:
		Ground(float _density = 0.0f, float _moisture = 0.0f, float _drainageRate = 0.0f, std::unique_ptr<TreeRoot> r = nullptr, std::unique_ptr<TreeTrunk> t = nullptr, std::unique_ptr<Mushroom> m = nullptr);
		float getDensity();
		float getMoisture();
		std::unique_ptr<TreeRoot>& getTreeRoot();
		std::unique_ptr<TreeTrunk>& getTreeTrunk();
		std::unique_ptr<Mushroom>& getMushroom();
		
		void setDensity(float d);
		void setMoisture(float m);
		void setTreeTrunk(TreeTrunk* t);

		char getASCIIGraphics();//For now this is what we'll use to decide what to print in the world print function.

		void update();
};

