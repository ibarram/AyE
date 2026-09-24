# ============================================================
#  Makefile para mingw32-make (MinGW / Windows)
#
#  Uso:
#    mingw32-make                                   -> compila con valores por defecto
#    mingw32-make TARGET=Ejemplo0xx                 -> otro programa
#    mingw32-make LIBNAME=milib                     -> otra librería (milib.c -> libmilib.lib)
#    mingw32-make TARGET=Ejemplo0xx LIBNAME=milib   -> ambos
#    mingw32-make lib LIBNAME=milib                 -> solo construye la librería
#    mingw32-make run TARGET=Ejemplo0xx             -> compila y ejecuta
#    mingw32-make clean                             -> borra objetos, librería y ejecutable
# ============================================================

# ---- Parámetros seleccionables ------------------------------
TARGET  ?= Ejemplo009
LIBNAME ?= libarram

# ---- Herramientas y banderas --------------------------------
CC      = gcc
AR      = ar
CFLAGS  ?= -Wall -O2
LDFLAGS = -L.
LDLIBS  = -l$(LIBNAME) -lm

# ---- Archivos derivados -------------------------------------
LIBSRC  = $(LIBNAME).c
LIBOBJ  = $(LIBNAME).o
LIBFILE = lib$(LIBNAME).lib
SRC     = $(TARGET).c
EXE     = $(TARGET).exe

# ---- Comando de borrado (cmd.exe o sh) ----------------------
ifeq ($(OS),Windows_NT)
  ifeq ($(findstring sh,$(SHELL)),sh)
    RM = rm -f
  else
    RM = del /Q /F
  endif
else
  RM = rm -f
endif

.PHONY: all lib run clean help

all: $(EXE)

lib: $(LIBFILE)

# Objeto de la librería
$(LIBOBJ): $(LIBSRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Librería estática
$(LIBFILE): $(LIBOBJ)
	$(AR) rcs $@ $^

# Ejecutable (se reconstruye si cambia la librería)
$(EXE): $(SRC) $(LIBFILE)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) $(LDLIBS) -o $@

run: $(EXE)
	.\$(EXE)

clean:
	-$(RM) $(LIBOBJ) $(LIBFILE) $(EXE)

help:
	@echo Uso: mingw32-make [all^|lib^|run^|clean] [TARGET=nombre] [LIBNAME=nombre]
	@echo   TARGET  actual: $(TARGET)
	@echo   LIBNAME actual: $(LIBNAME)