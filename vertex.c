#include "vertex.h"


pvertex CreateNewVertex(int data){  
    pvertex vert = (pvertex)malloc(sizeof(vert));
    memset(vert,0,sizeof(vertex));
    vert->index = data;
    vert->edges = NULL;
    vert->next = NULL;
    return vert; 
}

pvertex GetVertex(int data, pvertex *head3){
    pvertex temp = *head3;
    while (temp){
        if (temp->index==data){
            return temp;            
        }
        temp=temp->next;
    }
    return NULL;
}
