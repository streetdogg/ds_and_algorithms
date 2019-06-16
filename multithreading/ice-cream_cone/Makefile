PROJECT = ice-cream_cone
GCCFLAGS = -lpthread

run: $(PROJECT)
	clear
	./$(PROJECT)

$(PROJECT): $(PROJECT).o
	gcc $< $(GCCFLAGS) -o $(PROJECT)
	@rm $(PROJECT).o

%.o: %.c
	gcc -c $<

.PHONY: clean

clean:
	@rm $(PROJECT)