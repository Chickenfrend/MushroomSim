#ifndef __MUSHROOM
#define __MUSHROOM

#include <string> 
class Mushroom{
	private:
		float density;
		int reproductiveAge;
		bool isBlooming;
		std::string description;
		std::string name;
	public:
		virtual bool checkSpreadConditions();
		virtual void spread();
		virtual void sporeRelease();

		float getDensity();
		bool getBloomingStatus();
		std::string getDescription();
		std::string getName();
};

#endif
