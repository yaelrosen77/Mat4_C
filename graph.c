#include <stdio.h>
#include "graph.h"
#include "vertex.h"
#include "edge.h"

void build_graph_cmd(pvertex *head){
    char c = '\0';
    int flag = 0;
    int v2 = 0;
    int weight = 0;
    pedge edge_pointer = NULL;                                  
    int NumOfVertices = 0;
    int index = 0;
    if(head != NULL){
        deleteGraph_cmd(head);}
    scanf(" %d", &NumOfVertices);
    head = (pvertex) malloc(sizeof(vertex)*NumOfVertices);
    scanf(" %c", &c);
    if (c == "n"){flag = 1;}
    while (1){
        if (flag){
            scanf(" %d", &index);
            if (index = NumOfVertices-1){
                CreateNewVertex(head+(sizeof(vertex))*index, index, edge_pointer ,NULL);}
            else{ CreateNewVertex(head+(sizeof(vertex))*index, index, edge_pointer ,head+(sizeof(vertex))*(index+1));
                flag = 0;}
            }
    
        else { 
            if (!isExist(head+(sizeof(vertex))*v2)){
                if (index = NumOfVertices-1){
                CreateNewVertex(head+(sizeof(vertex))*v2, v2, edge_pointer ,NULL);}
            else{ CreateNewVertex(head+(sizeof(vertex))*v2, v2, edge_pointer ,head+(sizeof(vertex))*(v2+1));}
            }
            scanf(" %d", &weight);
            CreateNewEdge(edge_pointer, weight, endpoint, )
            



            
        }
        
    }
    
                                  
    
    
    
                          
        
    
    }                           
      




void deleteGraph_cmd(pvertex* head){
    //free the memory of the graph and set pointer to null 
}



void printGraph_cmd(pvertex head);

//validate_creation(int NumOfVertices, )