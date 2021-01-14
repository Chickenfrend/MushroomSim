CXX = g++
CFLAGES = -std=c++17 -g -Wall

%.o : %.cpp
	$(CXX) -c $(CFLAGS) $<

terminal-test.exe: TerminalTest.o ToolBox.o Ground.o Mushroom.o OakTrunk.o PineTrunk.o Chanterelle.o TreeRoot.o World.o TreeTrunk.o ShroomTracker.o WorldState.o GameObject.o RandTreeGenerator.o
	$(CXX) -o $@ $^

clean:
	$(RM) $(wildcard *.exe) $(wildcard *.o)
