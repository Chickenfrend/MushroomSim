CXX = g++
CFLAGS = -std=c++17 -g -Wall -ltgui -lsfml-graphics -lsfml-window -lsfml-system
LIBS = -ltgui -lsfml-graphics -lsfml-window -lsfml-system

%.o : %.cpp
	$(CXX) -c $(CFLAGS) $<

gui_test.exe: GraphicsHandler.o graphicsTest.o
	$(CXX) -o $@ $^ $(LIBS)

clean: 
	$(RM) $(wildcard *.exe) $(wildcard *.o)
