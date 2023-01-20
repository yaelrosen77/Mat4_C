#ifndef GRAPH
#define GRAPH

typedef struct vertex *pvertex;

typedef struct edge {
    int weight;
    pvertex endpoint;
    struct edge *nextE;
}edge, *pedge;

typedef struct vertex {
    int index;  
    pedge edges;
    struct vertex* next;
}vertex, *pvertex;


char build_graph_cmd(pvertex *head2);
void deleteGraph_cmd(pvertex *head);
char insert_vertex_cmd(pvertex *head6);
void printGraph_cmd(pvertex *head7);
void delete_vertex_cmd(pvertex *head8);

#endif
