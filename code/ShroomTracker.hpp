#ifndef __SHROOMTRACKER
#define __SHROOMTRACKER

//The shroom tracker acts like the trunk does for tree roots, but for mycelium. 
//Since mushrooms don't have a trunk, or a point of origin, this is abstract and does not have a place in the world.
//Instead, if two Mushroom objects share the shame ShroomTracker, they are considered to be part of the same mushroom organism.
class ShroomTracker{
	private:	
		int id;
		int age = 0;
		int count = 0;
		float mass = 0;
	public:
		ShroomTracker(int _id);
		int getId();
		int getAge();
		void incrementCount();

		void setId(int _id);
};

#endif
