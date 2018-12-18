#-------------------------------------------------------
#-------------------------------------------------------
#					NUEVO MAKEFILE		
#-------------------------------------------------------
#-------------------------------------------------------

#Este makefile es mucho mas eficiente que e anterior, pero
#genera un .o al lado de cada .cpp, en el futuro la solucion
#pasa por generar eso .o dentro de bin/, pero esta por llegar
#solo complila si hay modificaciones en el .cpp o en el .h
#no complila nada si se han hecho modficaciones en un .h que no
#tiene .cpp.


#Compiler
CXX = g++
#CXX = clang++

#GETTING ALL CPPS
SOURCES := $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)

#ALL HEADERS
HEADERS := $(subst .cpp,.h,$(SOURCES))

#ALL DIRS
#GETTING ALL DIRS
DIRS := $(dir $(SOURCES))

#ALL .O
#OBJECTS := $(addprefix bin/,$(subst .cpp,.o,$(notdir $(SOURCES))))
#OBJECTS := $(subst .cpp,.o,$(SOURCESNP))
OBJECTS := $(subst .cpp,.o,$(SOURCES))


#EXTERNAL HOMES
IrrlichtHome := /usr/include/irrlicht

BulletHome := /usr/include/bullet
BulletLibraries := /usr/lib64

FmodHome := include/fmod
FmodLibraries := lib

#INCLUDES && LIBRAIES
INCLUDES := $(addprefix -I,$(wildcard src/. src/*/. src/*/*/.)) -I$(FmodHome) -I$(BulletHome) -I$(IrrlichtHome) -I/usr/X11R6/include
LIBRAIES := -L$(FmodLibraries) -L$(IrrlichtHome) -lIrrlicht -L$(BulletLibraries) -lLinearMath -lBulletDynamics -lBulletCollision


#Linker
bin/Ejecutable: $(OBJECTS)
	@echo Linkeando
	@$(CXX) -o $@ $^ $(LIBRAIES)
	@echo Proceso terminado



#Compiler
%.o: %.cpp %.h
	@echo Compilando: $(notdir $<)
	@$(CXX) -g -Wall -o $@ -c $< $(INCLUDES)


info:
	$(info $(LIBRAIES))
	$(info $(SOURCESNP))
	$(info $(HEADERS))
	$(info $(DIRS))
	$(info $(OBJECTS))

all:
	@rm -f $(OBJECTS)
	@make

clear:
	@rm -f $(OBJECTS)
