CC = gcc
FLAGS = -Wall -g -fPIC

all: graph 

graph: main.o vertex.o edge.o algo.o
	$(CC) $(FLAGS) -o graph main.o vertex.o edge.o algo.o

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

edge.o: edge.c edge.h
	$(CC) $(FLAGS) -c edge.c

vertex.o: vertex.c vertex.h
	$(CC) $(FLAGS) -c vertex.c

algo.o: algo.c algo.h
	$(CC) $(FLAGS) -c algo.c

.PHONY: clean all

clean:
	rm -f graph *.o
