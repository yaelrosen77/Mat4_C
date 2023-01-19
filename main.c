#include <stdio.h>
#include "graph.h"
#include "vertex.h"
#include "edge.h"

int main(){
    char c = '\0';
    pvertex head = NULL;
    printf("pls enter your char\n");     
    scanf(" %c", &c);
    while (1){
        if (c == 'A'){
            c = build_graph_cmd(&head);
            printGraph_cmd(&head);
            printf("yay");
            scanf(" %c", &c);
        }
        // if(c == 'B'){
            // c = insert_node_cmd(&head);
            // printGraph_cmd(head);
        // }
    }   
    return 0;
}

char build_graph_cmd(pvertex *head2){
    int NumOfVertices; pvertex tempV; 
    int ndx;
    char c = '\0';
    // if(head2 != NULL){
    //     deleteGraph_cmd(head2);}
    printf("pls enter your num of vertices\n"); 
    scanf(" %d", &NumOfVertices);
    tempV = CreateNewVertex(0);
    *head2 = tempV;
    for (int i = 1; i<NumOfVertices; i++){
        pvertex tempV2 = CreateNewVertex(i);
        tempV->next=tempV2;
        tempV = tempV2;
        }
    printf("pls enter your choice\n");
    scanf(" %c", &c);
    while (1){
        if (c == 'n'){
            printf("pls enter your the new vertex\n");
            scanf(" %d",&ndx);
            tempV = GetVertex(ndx, head2);
            c = SetEdges(tempV, head2);}
        else {
            printf("\n");
            printf("no more creating edges\n");
            break;}
    }
    return c;
}

char insert_node_cmd(pvertex *head6){
    int ndx; 
    scanf(" %d\n",&ndx);
    pvertex p = GetVertex(ndx, head6);
    if (p){
        printf("Vertex exsists %d\n",p->index);
        DeleteEdges(p);
    }
    else{
        pvertex vRun = (*head6);
        while(vRun->next){
            printf("vRun: %d\n",vRun->index);
            vRun=vRun->next;}
        p = CreateNewVertex(ndx);
        vRun->next = p;
    }
    return SetEdges(p, head6);
}

void printGraph_cmd(pvertex *head6){
    pvertex * temp; pedge* edge_pointer= NULL;
    temp = head6;
    printf("Printing the graph !\n\n");
    while (1){
        if (temp){
            if ((*temp)->edges){
                edge_pointer = (&(*temp)->edges);}
            printf("Vertex index number is: %d\n", (*temp)->index);
            while (edge_pointer){
                printf("Vertex has an edge to vertex number %d with a weight %d \n", (*edge_pointer)->endpoint->index, (*edge_pointer)->weight);               
                if ((*edge_pointer)->next != NULL){
                    edge_pointer = (&((*edge_pointer)->next));}
                else {
                    break;}
            } 
            printf("\n");}
        if ((*temp)->next){
            temp = &((*temp)->next);
            edge_pointer = NULL;}
        else {
            break;}}
}
