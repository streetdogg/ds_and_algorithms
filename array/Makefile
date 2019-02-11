PROJECT=array
SRC= src/main.c src/array.c
INC=./inc/
TEST=src/test.c

all: $(SRC)
	gcc -Wall -O0 -ggdb $(SRC) -I$(INC) -o $(PROJECT)

clean:
	rm -rf $(PROJECT)