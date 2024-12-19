GCC= gcc
FLAG_O= -o
CFLAGS= -I ./include/
ENDFLAG= -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

SRCDIR= src
TARGET= main.exe
SRC_FILES= $(SRCDIR)\circle_obj.c $(SRCDIR)\InterfaceWindow.c
MAIN_SRC= main.c

all: $(TARGET)

$(TARGET):
	$(GCC) $(MAIN_SRC) $(SRC_FILES) $(CFLAGS) $(ENDFLAG) $(FLAG_O) $(TARGET) 

clean:
	del $(TARGET)

rebuild:
	make clean
	make all