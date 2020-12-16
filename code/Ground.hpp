#include "Mushroom.hpp"
#include "TreeRoot.hpp"
#include "TreeTrunk.hpp"
#include <memory>

class Ground{
	private:
		//Moisture and density are percentages that indicate how dense, and moist, respectively, the soil is.
		//Drainage rate is the rate at which moisture leaves the ground.
		float density;
		float moisture;
		float drainageRate;
		std::unique_ptr<TreeRoot> root;
		std::unique_ptr<TreeTrunk> trunk;
		std::unique_ptr<Mushroom> mushroom;

	public:
		Ground(float _density = 0.0f, float _moisture = 0.0f, float _drainageRate = 0.0f, std::unique_ptr<TreeRoot> r = NULL, std::unique_ptr<TreeTrunk> t = NULL, std::unique_ptr<Mushroom> m = NULL);
		float getDensity();
		void setDensity(float d);
		float getMoisture();
		void setMoisture(float m);
		std::unique_ptr<TreeRoot>& getTreeRoot();
		std::unique_ptr<TreeTrunk>& getTreeTrunk();
		std::unique_ptr<Mushroom>& getMushroom();
		void update();
};

