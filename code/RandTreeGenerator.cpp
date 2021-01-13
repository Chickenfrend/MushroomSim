#include "RandTreeGenerator.hpp"

RandTreeGenerator::RandTreeGenerator(std::string _forestPath){
	forestPath = _forestPath;
	GenerateLists();
}
