CC = gcc
FLAGS = -g -Wall

all: isort isort.o main.o txtfind maintxt.o txtfind.o

main.o: main.c isort.h
	$(CC) $(FLAGS) -c main.c

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

isort: main.o isort.o
	$(CC) $(FLAGS) main.o isort.o -o isort

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

maintxt.o: maintxt.c txtfind.h
	$(CC) $(FLAGS) -c maintxt.c

txtfind: maintxt.o txtfind.o
	$(CC) $(FLAGS) maintxt.o txtfind.o -o txtfind

.PHONY: clean all

clean:
	rm -f *.o isort txtfind
