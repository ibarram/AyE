# Variables
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = 
TARGET = AyED

# Reglas
all: $(TARGET)

$(TARGET): 001 002 003 004 005 006
	$(CC) $(LDFLAGS) -o 001_seno_serie_ini 001_seno_serie_ini.c

001: 001_seno_serie_ini.c
	$(CC) $(LDFLAGS) -o 001_seno_serie_ini 001_seno_serie_ini.c

002: 002_seno_serie_opt.c
	$(CC) $(LDFLAGS) -o 002_seno_serie_opt 002_seno_serie_opt.c

003: 003_seno_serie_par.c
	$(CC) $(LDFLAGS) -o 003_seno_serie_par 003_seno_serie_par.c

004: 004_billetes.c
	$(CC) $(LDFLAGS) -o 004_billetes 004_billetes.c

005: 005_distancia.c
	$(CC) $(LDFLAGS) -o 005_distancia 005_distancia.c

006: 006_mochila.c
	$(CC) $(LDFLAGS) -o 006_mochila 006_mochila.c

clean:
	rm -f 001_seno_serie_ini 002_seno_serie_opt 003_seno_serie_par 004_billetes 005_distancia 006_mochila
