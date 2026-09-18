# ---- Configuración ----
CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -O2 -Iinclude
LDFLAGS :=
LDLIBS  :=

TARGET  := demo.exe
SRCDIR  := 
OBJDIR  := build

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# ---- Etiquetas ----
.PHONY: all clean run rebuild

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"

clean:
	if exist "$(OBJDIR)" rmdir /S /Q "$(OBJDIR)"
	if exist "$(TARGET)" del /Q "$(TARGET)"

run: $(TARGET)
	.\$(TARGET)

rebuild: clean all