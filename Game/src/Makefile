SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))
LIBS	:= -L./lib/linux/irrlicht -lIrrlicht
INCLUDE := -I. -I/usr/include/irrlicht
CC	:= g++

ejecutable: $(OBJECTS)
	$(CC) -o bin/$@ $^ $(INCLUDE) $(LIBS)

%.o: %.cpp
	$(CC) -o bin/$@ -c $^ $(INCLUDE) $(LIBS)

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))

#cidentifiable.o: cindentifiable.cpp
#	g++ -c cindentifiable.cpp -I.

#cwindow.o: cwindow.cpp
#	g++ -c cwindow.cpp -I.
