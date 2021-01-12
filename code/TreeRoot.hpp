#ifndef __TREEROOT
#define __TREEROOT

//#include "TreeTrunk.hpp"
#include <string>
#include <memory>
class TreeRoot{
    private:
        std::string treeType;
        bool isDeciduous;
        //std::unique_ptr<TreeTrunk> parentTrunk;
        //std::pair<int,int> parentPos;
    public:
        TreeRoot(std::string parentType, bool parentDeciduous);
        bool getIfDeciduous();
        
        std::string getASCIIGraphics();

    
};

#endif
