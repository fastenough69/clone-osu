GCC= gcc
FLAG_O= -o
CFLAGS= -I ./include/
ENDFLAG= -L ./lib/ -lraylib -framework OpenGL -framework Cocoa -framework IOKit

SRCDIR= src
TARGET= main
SRC_FILES= $(SRCDIR)/circle_obj.c $(SRCDIR)/InterfaceWindow.c
MAIN_SRC= main.c

all: $(TARGET)

$(TARGET):
	$(GCC) $(MAIN_SRC) $(SRC_FILES) $(CFLAGS) $(ENDFLAG) $(FLAG_O) $(TARGET)

clean:
	rm -f $(TARGET)

rebuild:
	make clean
	make all