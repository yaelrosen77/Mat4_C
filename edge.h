#ifndef EDGE
#define EDGE

#include <stdlib.h>
#include <stdio.h>
#include "vertex.h"
#include "graph.h"

char SetEdges(pvertex p, pvertex* head4);

void CreateNewedge(pvertex p, int vert_data, int weight, pvertex *head5);

int isDigit(char c);

void DeleteEdges(pvertex p);

void DeletePointingEdges(pvertex p, pvertex *head9);

void DelEdge(pedge prev, pedge next);

#endif
