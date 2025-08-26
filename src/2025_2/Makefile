CC = gcc
001 = 01_Ejemplo
002 = 02_Ejemplo
003 = 03_Ejemplo
004 = 04_Ejemplo
005 = 05_Ejemplo
006 = 06_Ejemplo
LIB = libarram
007 = 07_Ejemplo
008 = 08_Ejemplo
009 = 09_Ejemplo
010 = 10_Ejemplo

all: $(001) $(002) $(003) $(004) $(005) $(006) $(007) $(008) $(009) $(010)

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

$(008):  $(008).c lib$(LIB).a
	$(CC) $(008).c -L. -l$(LIB) -o $(008)

$(009):  $(009).c lib$(LIB).a
	$(CC) $(009).c -L. -l$(LIB) -o $(009)

$(010):  $(010).c lib$(LIB).a
	$(CC) -lm $(010).c -L. -l$(LIB) -o $(010)

clean:
	rm -f $(001) $(002) $(003) $(004) $(005) $(006) $(LIB).o lib$(LIB).a $(007) $(008) $(009) $(010)