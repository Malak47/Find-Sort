FLAGS = -Wall -g
CC = gcc
AR = ar
.PHONY = all clean

all: isort txtfind

isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o
txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o
isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c
txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c
clean:
	rm -f *.o isort txtfind