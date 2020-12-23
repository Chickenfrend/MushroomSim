#include "ShroomTracker.hpp"

ShroomTracker::ShroomTracker(int _id){
	id = _id;
}

int ShroomTracker::getId(){
	return id;
}

int ShroomTracker::getAge(){
	return age;
}

void ShroomTracker::incrementCount(){
	count++;
}

void ShroomTracker::setId(int _id){
	id = _id;
}


