# Variables
CC = gcc
CFLAGS =
EJ01 = 001_seno_serie_ini 001_seno_serie_ini
EJ02 = 002_seno_serie_opt 002_seno_serie_opt
EJ03 = 003_seno_serie_par 003_seno_serie_par
EJ04 = 004_billetes 004_billetes
EJ05 = 005_distancia 005_distancia
EJ06 = 006_mochila 006_mochila
EJ07 = 007_libreria
EJ07l= libarram

# Reglas
all: 001 002 003 004 005 006 007e 007d

001: $(EJ01).c
	$(CC) $(CFLAGS) -o $(EJ01).c

002: $(EJ02).c
	$(CC) $(CFLAGS) -o $(EJ02).c

003: $(EJ03).c
	$(CC) $(CFLAGS) -o $(EJ03).c

004: $(EJ04).c
	$(CC) $(CFLAGS) -o $(EJ04).c

005: $(EJ05).c
	$(CC) $(CFLAGS) -o $(EJ05).c

006: $(EJ06).c
	$(CC) $(CFLAGS) -o $(EJ06).c

007e: $(EJ07).c lib$(EJ07l).a
	$(CC) $(EJ07).c -L. -l$(EJ07l) -o $(EJ07)e

lib$(EJ07l).a: $(EJ07l).o
	ar rcs lib$(EJ07l).a $(EJ07l).o

$(EJ07l).o: $(EJ07l).c $(EJ07l).h
	$(CC) -c $(EJ07l).c -o $(EJ07l).o

007d: $(EJ07).c lib$(EJ07l).so
	$(CC) $(EJ07).c -L. -l$(EJ07l) -o $(EJ07)d

lib$(EJ07l).so: $(EJ07l).o
	$(CC) -shared -o lib$(EJ07l).so $(EJ07l).o

#$(EJ07l)2.o: $(EJ7l).c
#	$(CC) -c $(EJ07l).c -fPIC -o $(EJ07l).o

clean:
	rm -f $(EJ01) $(EJ02) $(EJ03) $(EJ04) $(EJ05) $(EJ06) $(EJ07)e $(EJ07l).o lib$(EJ07l).a $(EJ07)d lib$(EJ07l).so
