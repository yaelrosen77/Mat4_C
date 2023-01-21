#ifndef ALGO
#define ALGO
#include <stdio.h>
#include "graph.h"
#include "vertex.h"
#include "edge.h"
#define INFINITY 9999

int shortest_path(pvertex Va, pvertex Vb, pvertex head11);
void permutation(int *arr, pvertex head15, int st_ndx, int nd_ndx, int k);
void TSP(pvertex head14, int *arr, int ndx, int k);
void setData(pvertex head12);
void SetMinPath();
int tspprint();
void SetNumOfVertices(int a);

#endif