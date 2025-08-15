CC = gcc
001 = 01_Ejemplo
002 = 02_Ejemplo
003 = 03_Ejemplo
004 = 04_Ejemplo
005 = 05_Ejemplo
006 = 06_Ejemplo
LIB = libarram
007 = 07_Ejemplo

all: $(001) $(002) $(003) $(004) $(005) $(006) $(007)

$(001): $(001).c
	$(CC) $(001).c -o $(001)

$(002): $(002).c
	$(CC) $(002).c -o $(002)

$(003): $(003).c
	$(CC) $(003).c -o $(003)

$(004): $(004).c
	$(CC) $(004).c -o $(004)

$(005): $(005).c
	$(CC) $(005).c -o $(005)

$(LIB).o: $(LIB).c
	$(CC) -c $(LIB).c -o $(LIB).o

lib$(LIB).a: $(LIB).o
	ar rcs lib$(LIB).a $(LIB).o

$(006):  $(006).c lib$(LIB).a
	$(CC) $(006).c -L. -l$(LIB) -o $(006)

$(007):  $(007).c lib$(LIB).a
	$(CC) $(007).c -L. -l$(LIB) -o $(007)

clean:
	rm -f $(001) $(002) $(003) $(004) $(005) $(006) $(LIB).o lib$(LIB).a $(007)