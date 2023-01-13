#include <stdio.h>
#include "graph.h"
#include "vertex.h"

int main(){
    char c = '\0';
    pvertex head = NULL;                             //the pointer vertex to all graphs created                                                                                 

    while (scanf(" %c", &c) != EOF){                 //reading data from standart input  
        if (c == "A"){                                 //the user can create a new graph inside the input various times              
            build_graph_cmd(head);                   //free of the memory our latest created graph                                
        }

    
    
    
    
    }
    deleteGraph_cmd(head);
    return 0;
}

