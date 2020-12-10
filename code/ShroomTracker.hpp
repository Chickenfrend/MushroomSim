#ifndef __SHROOMTRACKER
#define __SHROOMTRACKER

//The shroom tracker acts like the trunk does for tree roots, but for mycelium. 
//Since mushrooms don't have a trunk, or a point of origin, this is abstract and does not have a place in the world.
//Instead, if two Mushroom objects share the shame ShroomTracker, they are considered to be part of the same mushroom organism.
class ShroomTracker{
	int id;
	int age;
	int count;
	float mass;
};

#endif
