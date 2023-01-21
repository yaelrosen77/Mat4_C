#include "algo.h"

int minPath = INFINITY;
int NumofVertices =0;

int shortest_path(pvertex Va, pvertex Vb, pvertex head11){
    int leftToVisit = NumofVertices, flag = 1;
    pvertex temp = NULL, dest = NULL;
    pedge edge_pointer;
    setData(head11);
    Va->dij = 0;
    while (flag){
        temp = head11;
        minPath = INFINITY;
        while (temp){
            if (temp->isVisited == 0 && temp->dij < minPath){
                minPath= temp->dij;
                dest = temp;}
            temp = temp->next;}
        if (!dest){
            temp = head11;
            while (1){
                if (!temp->isVisited){
                    dest = temp;

                    break;}
                temp = temp->next;}
        }
        if (dest->edges){
            if (dest->edges->endpoint){
                if ((dest->dij + dest->edges->weight) < (dest->edges->endpoint->dij)){
                    dest->edges->endpoint->dij = dest->dij + dest->edges->weight;}}

            edge_pointer = dest->edges->nextE;
            while (edge_pointer){
                if ((dest->dij + edge_pointer->weight) < (edge_pointer->endpoint->dij)){
                    edge_pointer->endpoint->dij = edge_pointer->weight + dest->dij;}
                edge_pointer = edge_pointer->nextE;}
        }
    dest->isVisited = 1;
    leftToVisit--;
    if (!leftToVisit){flag = 0;}
    }
    if (Vb->dij == INFINITY){return -1;}

    return (Vb->dij);
}

void setData(pvertex head12){
    pvertex temp = head12;
    while (temp){
        temp->isVisited = 0;
        temp->dij = INFINITY;
        temp = temp->next;
    }
}

void permutation(int *arr, pvertex head15, int st_ndx, int nd_ndx, int k){
    int i = st_ndx, temp;
    if (st_ndx == nd_ndx){
        TSP(head15, arr, (1+nd_ndx),k);
        return;}

    for (i = st_ndx; i <= nd_ndx; i++){
        temp = *(arr +sizeof(int)*i);
        *(arr +sizeof(int)*i) = *(arr + sizeof(int)*st_ndx);
        *(arr + sizeof(int)*st_ndx) = temp;
        permutation(arr, head15, st_ndx+1, nd_ndx, k);
        temp = *(arr +sizeof(int)*i);
        *(arr +sizeof(int)*i) = *(arr + sizeof(int)*st_ndx);
        *(arr + sizeof(int)*st_ndx) = temp;}
}


void TSP(pvertex head14, int *arr, int ndx, int k){
    int j=1, min_temp =0; pvertex dest, src = GetVertex(arr[0], &head14);
    while (j<k){
        dest = GetVertex(j, &head14);
        min_temp = min_temp+ shortest_path(src, dest, head14);
        src = GetVertex(j, &head14);
        j++;
    }
    if (minPath > min_temp){minPath = min_temp;}
}

int tspprint(){
    if (minPath==INFINITY){
        return -1;
    }
    return minPath;
}
    
void SetMinPath(){
    minPath = INFINITY;
}
    
void SetNumOfVertices(int a){
    NumofVertices = a;
}










