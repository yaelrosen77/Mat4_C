#include "graph.h"
#include <stdio.h>
#include "vertex.h"
#include "edge.h"
#include "algo.h"
#include <stdlib.h>

int NumOfVertices = 0;

int main(){
    char c = '\0';
    pvertex head = NULL;
    int scani = 1;

    while (1){
        if (scani){
            if (scanf(" %c",&c)==EOF){break;}
        }
        if (c == 'A'){
            c = build_graph_cmd(&head);
    //        printGraph_cmd(&head);
            scani = 0;
        }
        if(c == 'B'){
            c = insert_vertex_cmd(&head);
  //          printGraph_cmd(&head);
            scani = 0;
        }
        if (c == 'D'){
            delete_vertex_cmd(&head);
 //           printGraph_cmd(&head);
            scani = 1;
        }
        if (c == 'S'){
            shortest_path_cmd(head);
            scani = 1;
        }
        if (c == 'T'){
            tsp_cmd(&head);
            scani = 1;
        }
    }
    deleteGraph_cmd(&head);   
    return 0;
}

char build_graph_cmd(pvertex *head2){
    pvertex tempV = NULL; 
    int ndx = 0;
    char c = '\0';
    if(*head2){
        deleteGraph_cmd(head2);}
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
    int ndx =0;
    scanf(" %d\n",&ndx);
    pvertex p = GetVertex(ndx, head6);
    if (p){
        if (p->edges){
            DeleteEdges(p);}}
    else{
        NumOfVertices++;
        pvertex vRun = (*head6);
        while(vRun->next){
            vRun = vRun->next;}
        p = CreateNewVertex(ndx);
        vRun->next = p;
    }
    return SetEdges(p, head6);
}

void delete_vertex_cmd(pvertex *head8){
    int ndx=0; pvertex p= NULL;
    scanf(" %d\n",&ndx);
    p = GetVertex(ndx, head8);
    DeleteEdges(p);
    DeletePointingEdges(p, head8);
    dispatch_vert(p, head8);
}

void shortest_path_cmd(pvertex head10){
    SetNumOfVertices(NumOfVertices);
    int vertA=0, vertB=0;
    scanf(" %d\n",&vertA);
    scanf(" %d\n",&vertB);
    pvertex Va = GetVertex(vertA, &head10);
    pvertex Vb = GetVertex(vertB, &head10);
    printf("Dijsktra shortest path: %d\n",shortest_path(Va, Vb, head10));
    SetMinPath();
}

void tsp_cmd(pvertex *head13){
    SetNumOfVertices(NumOfVertices);
    int i=0, k=0;                         // maximum 6 nodes to check
    scanf(" %d", &k);
    int * arr = (int*) malloc(sizeof(int)*k);
    for (i = 0; i <k; i++)
        scanf(" %d", &(arr[i]));
    permutation(arr, *head13, 0, k-1, k);
    printf("TSP shortest path: %d\n", tspprint());
    SetMinPath();
    free(arr);
}

void deleteGraph_cmd(pvertex *head8){
    pvertex p = *head8, temp= NULL;
    while (p){
        temp = p;
        if(p->edges){
            DeleteEdges(p);}
        p = p->next;
        free(temp);
    }
    *head8 = NULL;
    NumOfVertices = 0;
}
    
void printGraph_cmd(pvertex *head7){
    pvertex * temp= NULL; pedge* edge_pointer= NULL; 
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

