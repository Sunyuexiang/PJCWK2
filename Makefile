EXE = main 
SRC = Main.c Interface.c User_Control.c Users_Create.c
LINKS = -lSDL2
INCDIR = -I/usr/include/SDL2 
all: 
	gcc -o $(EXE) $(SRC) $(LINKS) $(INCDIR)