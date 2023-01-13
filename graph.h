#ifndef GRAPH
#define GRAPH

typedef struct vertex{
    int index;  
    pedge edges;
    struct vertex* next;
}vertex, *pvertex;

typedef struct edge{
    int weight;
    pvertex endpoint;
    struct edge *next;
} edge, *pedge;


void build_graph_cmd(pvertex *head, int NumOfVertices);
void insert_node_cmd(pvertex *head);
void delete_node_cmd(pvertex *head);
void printGraph_cmd(pvertex head); //for self debug
void deleteGraph_cmd(pvertex* head);
void shortsPath_cmd(pvertex head);
void TSP_cmd(pvertex head);

#endif