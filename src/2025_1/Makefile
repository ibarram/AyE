CC = gcc
LIB = libarram
001 = 001_seno_serie_ini

all: $(001)

$(001): $(001).c lib$(LIB).a
	$(CC) $(001).c -L. -l$(LIB) -o $(001)

lib$(LIB).a: $(LIB).o
	ar rcs lib$(LIB).a $(LIB).o

$(LIB).o: $(LIB).c
	$(CC) -c $(LIB).c -o $(LIB).o

clean:
	rm -f $(001) lib$(LIB).a $(LIB).o
