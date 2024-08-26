CC = gcc
SOURCE = libarram.c
OBJ = libarram.o
LIB = libarram
MAIN = 008_choco.c
TARGET = 008_choco

all: lib$(LIB).a $(MAIN)
	$(CC) $(MAIN) -L. -l$(LIB) -o $(TARGET)

lib$(LIB).a: $(OBJ)
	ar rcs lib$(LIB).a $(OBJ)

$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) -o $(OBJ)

clean:
	rm -f $(OBJ) lib$(LIB).a $(TARGET)
