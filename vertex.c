#include "vertex.h"


void CreateNewVertex(pvertex *head, int data, pedge p, pvertex next){   
    (*head)->index = data;

    (*head)->edges = p;
    
}

int isExist(pvertex vert){
    if (vert->index!= NULL){
        return 1;
    }
    return 0;
}



void insert_vertex_cmd(pvertex *head){


}





void delete_vertex_cmd(pvertex *head){
    //free memory and set head to null 
}