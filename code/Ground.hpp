#include "Mushroom.hpp"
#include "TreeRoot.hpp"
#include "TreeTrunk.hpp"
#include <memory>

class Ground{
	private:
		float density;
		float moisture;
		float drainageRate;
		std::unique_ptr<TreeRoot> root;
		std::unique_ptr<TreeTrunk> trunk;
		std::unique_ptr<Mushroom> mushroom;

	public:
		Ground(float _density = 0.0f, float _moisture = 0.0f, float _drainageRate = 0.0f, std::unique_ptr<TreeRoot> r = NULL, std::unique_ptr<TreeTrunk> t = NULL, std::unique_ptr<Mushroom> m = NULL);
		float getDensity();
		void setDensity();
		float getMoisture();
		void setMoisture(float moisture);
		TreeRoot& getTreeRoot();
		TreeTrunk& getTreeTrunk();
		Mushroom& getMushroom();
		void update();
};

