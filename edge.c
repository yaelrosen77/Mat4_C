#include "edge.h"


char SetEdges(pvertex p, pvertex *head4){
    char c = '\0'; 
    int ndx, weight =0;  
    if (scanf(" %c", &c)!= EOF){
        while (isDigit(c)){
            ndx = c - '0';
            scanf(" %d", &weight);
            CreateNewedge(p, ndx, weight, head4);
            if (scanf(" %c", &c) == EOF){
                break;}}
        }
    return c;
}
        

int isDigit(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

void CreateNewedge(pvertex p, int vert_data, int weight, pvertex *head5){
    if (p->edges == NULL){
        p->edges = (pedge)malloc(sizeof(edge));  
        p->edges->endpoint = GetVertex(vert_data, head5);
        p->edges->weight = weight;
        p->edges->nextE = NULL;
    }
    else{
        pedge temp = p->edges;
        while (temp->nextE){
            temp = temp->nextE;
        }
        temp->nextE = (pedge)malloc(sizeof(edge));
        temp->nextE->endpoint = GetVertex(vert_data, head5);
        temp->nextE->weight = weight;
        temp->nextE->nextE =NULL;
    }
}

void DeleteEdges(pvertex p){
    pedge temp = p->edges;
    pedge temp2 = NULL;
    while (temp){
        temp2 = temp;
        temp = temp->nextE;
        free(temp2);
    }
    p->edges = NULL;    
}

void DeletePointingEdges(pvertex p, pvertex* head9){
    pvertex temp = (*head9); pedge edge_pointer = NULL;
    while (temp){
        edge_pointer = temp->edges;
        while (edge_pointer){
            if(edge_pointer->endpoint == p){
                temp->edges = edge_pointer->nextE;
                free(edge_pointer);}
            else{
                while (edge_pointer->nextE){
                    if (edge_pointer->nextE->endpoint == p){
                        DelEdge(edge_pointer, edge_pointer->nextE->nextE);
                        edge_pointer = NULL;
                        break;
                    }
                    edge_pointer = edge_pointer->nextE;}
                }
        }
        temp = temp->next;
    }
}

void DelEdge(pedge prev, pedge next){
    free(prev->nextE);
    prev->nextE = next;
}





 




