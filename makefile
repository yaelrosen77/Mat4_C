CC = gcc
FLAGS = -Wall -g -fPIC

all: graph 

graph: main.o vertex.o edge.o
	$(CC) $(FLAGS) -o graph main.o vertex.o edge.o

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

edge.o: edge.c edge.h
	$(CC) $(FLAGS) -c edge.c

vertex.o: vertex.c vertex.h
	$(CC) $(FLAGS) -c vertex.c

.PHONY: clean all

clean:
	rm -f graph *.o
