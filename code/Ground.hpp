#include "Mushroom.hpp"
#include "TreeRoot.hpp"
#include "TreeTrunk.hpp"
#include <memory>

class Ground{
	private:
		int density;
		int moisture;
		std::unique_ptr<TreeRoot> root;
		std::unique_ptr<TreeTrunk> trunk;
		std::unique_ptr<Mushroom> mushroom;

	public:
		int getDensity();
		void setDensity();
		int getMoisture();
		void setMoisture();
		int getTreeRoot();
		void getTreeTrunk();
		void getMushroom();
		void update();
};

