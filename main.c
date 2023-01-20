#include <stdio.h>
#include "graph.h"
#include "vertex.h"
#include "edge.h"

int main(){
    char c = '\0';
    pvertex head = NULL;
    scanf(" %c", &c);
    while (1){
        if (c == 'A'){
            c = build_graph_cmd(&head);
            printGraph_cmd(&head);
        }
        if(c == 'B'){
            c = insert_node_cmd(&head);
            printGraph_cmd(&head);
        }
        if (c == 'D'){
            delete_vertex_cmd(&head);
            
        }
    }   
    return 0;
}

char build_graph_cmd(pvertex *head2){
    int NumOfVertices; pvertex tempV; 
    int ndx;
    char c = '\0';
    // if(head2 != NULL){
    //     deleteGraph_cmd(head2);}
    scanf(" %d", &NumOfVertices);
    tempV = CreateNewVertex(0);
    *head2 = tempV;
    for (int i = 1; i<NumOfVertices; i++){
        pvertex tempV2 = CreateNewVertex(i);
        tempV->next=tempV2;
        tempV = tempV2;
        }
    scanf(" %c", &c);
    while (1){
        if (c == 'n'){
            scanf(" %d",&ndx);
            tempV = GetVertex(ndx, head2);
            c = SetEdges(tempV, head2);}
        else {
            printf("\n");
            break;}
    }
    return c;
}

char insert_vertex_cmd(pvertex *head6){
    int ndx; 
    scanf(" %d\n",&ndx);
    pvertex p = GetVertex(ndx, head6);
    if (p){
        printf("Vertex exsists %d\n",p->index);
        if (p->edges){
            DeleteEdges(p);}}
    else{
        pvertex vRun = (*head6);
        while(vRun->next){
            vRun = vRun->next;}
        p = CreateNewVertex(ndx);
        vRun->next = p;
    }
    return SetEdges(p, head6);
}

void delete_vertex_cmd(pvertex *head8){
    int ndx; pvertex p;
    scanf(" %d\n",&ndx);
    p = GetVertex(ndx, head8);
    DeleteEdges(p);
}


void printGraph_cmd(pvertex *head7){
    pvertex * temp; pedge* edge_pointer= NULL; 
    temp = head7;
    printf("Printing the graph !\n\n");
    while (1){
        if (temp){
            if ((*temp)->edges){
                edge_pointer = (&(*temp)->edges);}
            printf("Vertex index number is: %d\n", (*temp)->index);
            while (edge_pointer){
                printf("Vertex has an edge to vertex number %d with a weight %d \n", (*edge_pointer)->endpoint->index, (*edge_pointer)->weight);              
                if ((*edge_pointer)->nextE != NULL){
                    edge_pointer = (&((*edge_pointer)->nextE));}
                else {
                    edge_pointer=NULL;}
            }
            printf("\n");}
            if ((*temp)->next){
                temp = &((*temp)->next);
                edge_pointer = NULL;}
                
            else {
                break;}}
}
