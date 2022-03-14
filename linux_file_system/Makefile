CC = gcc
CFLAGS = -std=c99 -g -Wall -lm 
 
build: list.c list.h file.h
	$(CC) -o fsminishell list.c $(CFLAGS)

run: fsminishell
	./fsminishell

clean:
	rm -f fsminishell
	rm -f *.out
