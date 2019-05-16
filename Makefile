
CXXFLAGS = -std=c++14 -g -Wall -Werror -w -Wl,-subsystem,windows
TARGET = main.exe

FILES_C = $(shell ls source)
FILES_O = $(subst .c,.o,$(FILES_C))

# Objetivo general
default: $(TARGET)

# Regla implicita: como generar ficheros .o a partir de .c
%.o: %.c Makefile 
	gcc $(CXXFLAGS) -c $< -o $@

# Generacion del ejecutable
$(TARGET): %.c %.o Makefile
	gcc main.o libmyutils.a -o $(TARGET) -lm

# Borrar ficheros
clean:
	/bin/rm -f *.o libmyutils.a $(TARGET)


