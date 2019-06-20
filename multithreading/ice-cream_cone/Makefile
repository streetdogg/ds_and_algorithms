PROJECT = main
GCCFLAGS = -lpthread -I./

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

run: $(PROJECT)
	clear
	@./$(PROJECT)

$(PROJECT): $(OBJECTS)
	gcc $(OBJECTS) $(GCCFLAGS) -o $(PROJECT)
	@rm $(OBJECTS)

%.o: %.c %.h
	gcc -c $< $(GCCFLAGS)

.PHONY: clean

clean:
	@rm $(PROJECT)