#include <stdio.h>
#include "edge.h"

void CreateNewEdge(pedge CurrentEdge, int weight, vertex endpoint, pedge next){
    CurrentEdge-> weight = weight;
    CurrentEdge-> endpoint = endpoint;
    CurrentEdge-> next = next;
}

