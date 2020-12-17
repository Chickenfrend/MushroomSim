CXX = g++
CFLAGES = -std=c++17 -g -Wall

%.o : %.cpp
	$(CXX) -c $(CFLAGS) $<

terminal-test.exe: TerminalTest.o Ground.o Mushroom.o OakTrunk.o TreeRoot.o World.o TreeTrunk.o
	$(CXX) -o $@ $^

clean:
	$(RM) $(wildcard *.exe) $(wildcard *.o)
