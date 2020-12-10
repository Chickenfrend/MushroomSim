#ifndef __TREETRUNK
#define __TREETRUNK

#include <string>
#include <memory>

class TreeTrunk{
	protected:
		std::string treeType;
		std::string description;
		bool isDeciduous; 
		int maxDistance;//This is the distance the roots should grow from the tree (in blocks)
		int distance;//Actual distance of the roots.

		int ageYears;
		int ageSeasons;
		int ageDays;
		int stage;//This should be the stage of the tree. Young, old, etc. May have an enum for this.

		float height;
		float circumference;
		float maxHeight;

	public:
		void ageDay();
		void ageSeason();
		void ageYear();
		void ageStage();

		void growTaller();
		void growRoots();
		virtual void growRootsCheck() = 0;

		bool getDeciduousStatus();
		std::string getDescription();
		std::string getTreeType();
		std::string loadDescription(std::string name);

};

#endif
