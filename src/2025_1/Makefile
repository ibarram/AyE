CC = gcc
LIB = libarram
001 = 001_seno_serie_ini
002 = 002_seno_serie_conv
003 = 003_seno_serie_opt
004 = 004_main_argumentos
005 = 005_seno_serie_argumentos

all: $(001) $(002) $(003) $(004) $(005)

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

clean:
	rm -f $(001) $(002) $(003) $(004) $(005)
