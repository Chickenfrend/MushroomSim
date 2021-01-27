# MushroomSim

This is an unfinished mushroom growing simulator! It will simulate trees and mushrooms growing and spreading. 
Currently, it supports multiple mushrooms and trees, and the mushrooms spread their mycelium based off of which trees have roots under them.
Trees expand their roots according to their age and which season it is. Eventually the trees and mushrooms will be able to reproduce and 
die according to season and soil nutrients, and the mushrooms spread and bloom status will depend on the season, soil nutrients, and soil water contents.

# Motivation

This project was motivated by an interest in mushroom hunting, looking for edible mushrooms in the woods where I live in Oregon. Hopefully when complete,
this will serve as an interesting insight into the way mushrooms grow, and I hope to include detailed descriptions of the mushrooms and their 
growing conditions, that can be viewed by highlighting any mushrooms in the environment.

I chose to use C++ in order to get practice doing a larger scope object oriented project than I did in school, while also learning more about the C++ libraries,
with the hope of incorporating opengl down the line.

# Code Description and Function

The trees all inherit from a base tree class, and the mushrooms inherit from a base mushroom class. The base classes contain
most of the logic each species of tree or mushrooms need. Tree trunks and tree roots are coded separately, and tree trunks generate tree roots
at set times (when they're old enough). Each mushroom (really mycelium) block can only spread under certain conditions, and each block tracks its own age.
Each mushroom contains a smart pointer pointing to a "mushroom tracker" object, which allows the program to identify if two mushroom blocks are part of the 
same organism. All the mushrooms and trees exist as components of a "Ground" class, which itself exists as part of the "world" class, which is just a 
2d vector with a lot of helper functions. The "WorldState" class keeps track of world status that exists on a broader level, such as whether it's raining, 
what season it is, how old the world is, and so on. The World class contains a WorldState object as a component, and each mushroom and tree contains a 
shared_ptr which points to said WorldState object.

# Compiling

To compile the terminal based version of this, on Linux, go to the "code" file and type "make". Then, type ./terminal-test.exe. The mushrooms 
currently only spread every year or so, so add to that by pressing "+" to make each update faster. The run option is currently pretty broken and the options
don't work when in this mode, so you'll just have to press control c to exit if you choose to use it.

To compile the work in progress Gui, navigate to /code/graphics_code and type make. You will need to have TGUI version 8 and SFML installed on your machine for this
to work.
