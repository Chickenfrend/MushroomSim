#ifndef __TREETRUNK
#define __TREETRUNK

#include <string>
#include <memory>

class TreeTrunk{
	private:
	protected:
		std::string treeType;
		std::string description;
		bool isDeciduous; 
		int maxDistance;//This is the distance the roots should grow from the tree (in blocks)
		int distance;//Actual distance of the roots.
		int distanceTolerance = 2; //How close this tree will spawn from other trees.

		int ageYears;
		int ageSeasons;
		int ageDays;
		int stage;//This should be the stage of the tree. Young, old, etc. May have an enum for this.

		float height;
		float circumference;
		float maxHeight;

		char graphicsSymbol;

	public:
		void ageDay();
		void ageSeason();
		void ageYear();
		void ageStage();

		void growTaller();
		void growRoots();
		virtual void growRootsCheck() = 0;

		bool getDeciduousStatus();
		int getDistanceTolerance();
		std::string getDescription();
		std::string getTreeType();
		std::string loadDescription(std::string name);

		char getASCIIGraphics();

};

#endif
