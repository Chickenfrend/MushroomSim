CXX = g++
ODIR=obj
GDIR = graphics_code
WDIR = world_event_code
CFLAGS = -std=c++17 -g -Wall -I$(GDIR)
VPATH = ./graphics_code ./world_event_code

LIBS = -lm
GLIBS = -ltgui -lsfml-graphics -lsfml-window -lsfml-system

_WDEPS = WorldUpdateInfo.hpp
WDEPS = $(patsubst %, $(WDIR)/%,$(_WDEPS))

_GDEPS = SpriteHandler.hpp GuiHandler.hpp EventHandler.hpp Command.hpp MoveViewCommand.hpp UpdateWorldCommand.hpp AdjustZoomCommand.hpp CursorLeftCommand.hpp CursorRightCommand.hpp CursorDownCommand.hpp CursorUpCommand.hpp CursorMoveCommand.hpp GroundInfoWriter.hpp
GDEPS = $(patsubst %, $(GDIR)/%,$(_GDEPS))

DEPS = ToolBox.hpp Ground.hpp Mushroom.hpp OakTrunk.hpp PineTrunk.hpp Chanterelle.hpp AmanitaMuscaria.hpp TreeRoot.hpp World.hpp TreeTrunk.hpp ShroomTracker.hpp WorldState.hpp GameObject.hpp RandTreeGenerator.hpp RandShroomGenerator.hpp SeasonsHandler.hpp $(patsubst %, $(GDIR)/%,$(G_DEPS)) $(WDEPS)


_OBJ = main.o ToolBox.o Ground.o Mushroom.o OakTrunk.o PineTrunk.o Chanterelle.o AmanitaMuscaria.o TreeRoot.o World.o TreeTrunk.o ShroomTracker.o WorldState.o GameObject.o RandTreeGenerator.o RandShroomGenerator.o SpriteHandler.o GUIHandler.o EventHandler.o Command.o MoveViewCommand.o UpdateWorldCommand.o AdjustZoomCommand.o CursorLeftCommand.o CursorRightCommand.o CursorUpCommand.o CursorDownCommand.o CursorMoveCommand.o GroundInfoWriter.o WorldUpdateInfo.o SeasonsHandler.o
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
