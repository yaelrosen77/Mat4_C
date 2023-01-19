#include "edge.h"
#include "vertex.h"

char SetEdges(pvertex p, pvertex *head4){
    printf("pls enter your endpoint or choice\n");
    char c = '\0'; 
    int ndx, weight;  
    if (scanf(" %c", &c)!= EOF){
        while (isDigit(c)){
            ndx = c - '0';
            printf("pls enter your weight\n");            
            scanf(" %d", &weight);
            CreateNewedge(p, ndx, weight, head4);
            printf("enter your index or exit :\n");
            if (scanf(" %c", &c) == EOF){
                break;}}
        }
    printf("you didnt want to add more edges\n");
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
        p->edges->next = NULL;
    }
    else{
        pedge temp = p->edges;
        while (temp->next){
            temp = temp->next;
        }
        temp->next = (pedge)malloc(sizeof(edge));
        temp->next->endpoint = GetVertex(vert_data, head5);
        temp->next->weight = weight;
        temp->next->next =NULL;
    }
}



void DeleteEdges(pvertex p){
    pedge Vedge = p->edges;
    while (Vedge){
        pedge temp = Vedge;
        Vedge = Vedge->next;
        free(temp);
    }
    
}
