#ifndef VERTEX
#define VERTEX

#define INFINITY 9999
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edge.h"
#include <string.h>

pvertex CreateNewVertex(int data);

pvertex GetVertex(int data, pvertex *p);

void dispatch_vert(pvertex p, pvertex *head16);


#endif

