all: ll.c
	gcc -ggdb ll.c -o ll

clean:
	rm -rf ll