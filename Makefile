GCC= gcc
FLAG_O= -o
CFLAGS= -I C:/raylib/w64devkit/x86_64-w64-mingw32/include -O2
ENDFLAG= -L C:/raylib/w64devkit/x86_64-w64-mingw32/lib -lraylib -lopengl32 -lgdi32 -lwinmm

SRCDIR= src
TARGET= main.exe
SRC_FILES= $(SRCDIR)\circle_obj.c $(SRCDIR)\InterfaceWindow.c
MAIN_SRC= main.c
DIR= builds


all: $(TARGET)

$(TARGET):
	$(GCC) $(MAIN_SRC) $(SRC_FILES) $(CFLAGS) $(ENDFLAG) $(FLAG_O) $(DIR)\$(TARGET) 

clean:
	del $(DIR)\$(TARGET)

rebuild:
	make clean
	make all