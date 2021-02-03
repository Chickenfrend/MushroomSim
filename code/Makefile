CXX = g++
ODIR=obj
GDIR = graphics_code
CFLAGS = -std=c++17 -g -Wall -I$(GDIR)
VPATH = ./graphics_code

LIBS = -lm
GLIBS = -ltgui -lsfml-graphics -lsfml-window -lsfml-system

_GDEPS = SpriteHandler.hpp GuiHandler.hpp
GDEPS = $(patsubst %, $(GDIR)/%,$(_GDEPS))

DEPS = ToolBox.hpp Ground.hpp Mushroom.hpp OakTrunk.hpp PineTrunk.hpp Chanterelle.hpp AmanitaMuscaria.hpp TreeRoot.hpp World.hpp TreeTrunk.hpp ShroomTracker.hpp WorldState.hpp GameObject.hpp RandTreeGenerator.hpp RandShroomGenerator.hpp $(patsubst %, $(GDIR)/%,$(G_DEPS))


_OBJ = main.o ToolBox.o Ground.o Mushroom.o OakTrunk.o PineTrunk.o Chanterelle.o AmanitaMuscaria.o TreeRoot.o World.o TreeTrunk.o ShroomTracker.o WorldState.o GameObject.o RandTreeGenerator.o RandShroomGenerator.o SpriteHandler.o GUIHandler.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#_GOBJ = SpriteHandler.o GuiHandler.o
#GOBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

#terminal-test.exe: TerminalTest.o $(OBJ)
#	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

mushroom-sim.exe: $(OBJ) 
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS) $(GLIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
