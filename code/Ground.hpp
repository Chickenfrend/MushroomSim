#include "Mushroom.hpp"
#include "TreeRoot.hpp"
#include "TreeTrunk.hpp"
#include <memory>

class Ground{
	private:
		int density;
		int moisture;
		TreeRoot root;
		TreeTrunk trunk;
		Mushroom mushroom;

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

