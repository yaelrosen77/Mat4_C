#include "vertex.h"

pvertex CreateNewVertex(int data){  
    pvertex vert = (pvertex)malloc(sizeof(vertex));
    memset(vert,0,sizeof(vertex));
    vert->index = data;
    vert->edges = NULL;
    vert->isVisited = 0;
    vert->next = NULL;
    vert->dij = INFINITY;
    return vert; 
}

void dispatch_vert(pvertex p, pvertex *head16){
    pvertex temp = *head16;
    while (temp){
        if(temp == p){
            (*head16) = temp->next;
            free(temp);
        }
        else{
            while (temp->next){
                if (temp->next == p){
                    temp->next = p->next->next;
                    free(p);
                    temp = NULL;
                    break;
                }
                temp = temp->next;
            }
        }
    temp = NULL;
    }
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
