CXX = g++
CFLAGS = -std=c++17 -g -Wall
ODIR=obj
GDIR = graphics_code

LIBS = -lm

DEPS = ToolBox.hpp Ground.hpp Mushroom.hpp OakTrunk.hpp PineTrunk.hpp Chanterelle.hpp AmanitaMuscaria.hpp TreeRoot.hpp World.hpp TreeTrunk.hpp ShroomTracker.hpp WorldState.hpp GameObject.hpp RandTreeGenerator.hpp RandShroomGenerator.hpp

_OBJ = TerminalTest.o ToolBox.o Ground.o Mushroom.o OakTrunk.o PineTrunk.o Chanterelle.o AmanitaMuscaria.o TreeRoot.o World.o TreeTrunk.o ShroomTracker.o WorldState.o GameObject.o RandTreeGenerator.o RandShroomGenerator.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o : %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS) 

terminal-test.exe: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core %(INCDIR)/*~
