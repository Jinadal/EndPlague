#-------------------------------------------------------
#-------------------------------------------------------
#					NUEVO MAKEFILE		
#-------------------------------------------------------
#-------------------------------------------------------


#Compiler
CXX = g++
#CXX = clang++

#GETTING ALL .CPP
SOURCES := $(subst src/,,$(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp))

#ALL .H
HEADERS := $(subst .cpp,.h,$(SOURCES))

#ALL .O
OBJECTS := $(subst .cpp,.o,$(subst src/,bin/,$(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)))


#ALL DIRS
#GETTING ALL DIRS
DIRS := $(subst src,bin,$(wildcard src/. src/*/. src/*/*/.))



#EXTERNAL HOMES
IrrlichtHome := -I/usr/include/irrlicht -lIrrlicht
IrrlichtLibraries := -L/usr/include/irrlicht -lIrrlicht

BulletHome := -I/usr/include/bullet
BulletLibraries := -L/usr/lib64 -lLinearMath -lBulletDynamics -lBulletCollision

FmodHome := -Iinclude/fmod
FmodLibraries := -Llib

#INCLUDES && LIBRAIES
INCLUDES := $(addprefix -I,$(wildcard src/. src/*/. src/*/*/.)) $(FmodHome) $(BulletHome) $(IrrlichtHome) -I/usr/X11R6/include
LIBRAIES := $(FmodLibraries) $(IrrlichtLibraries) $(BulletLibraries) 


default:
	@mkdir -p $(DIRS)
	@make Ejecutable

#Linker
Ejecutable: $(OBJECTS)
	@echo Linkeando
	@$(CXX) -o bin/$@ $^ $(LIBRAIES) $(INCLUDES)
	@echo Proceso terminado


#REGlA Compiler
define REGLA
$(1): $(2)
	@echo Compilando: $(basename $(notdir $(1)))
	@$(CXX) -g -Wall -o $(1) -c $(2) $(INCLUDES)

endef
$(foreach O,$(OBJECTS),$(eval $(call REGLA,$(O),$(subst bin/,src/,$(O:.o=.cpp)))))


info:
	$(info $(OBJECTS))

all:
	@make clear
	@make

clear:
	@rm -f $(OBJECTS)
