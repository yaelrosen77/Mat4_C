#ifndef VERTEX
#define VERTEX

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <string.h>

pvertex CreateNewVertex(int data);

pvertex GetVertex(int data, pvertex *p);

void DeleteVertex(int data, pvertex *head4);

#endif

