/*#include "graph.h"


//int nbUsers = 0;

void addNode(char name[])
{
        
        node[nbUsers] =  malloc(sizeof(node_t));
        strcpy(node[nbUsers].name, name);
        nbUsers++;

}
void addEdge(int from, int to)
{
        A[from][to] = 1;
}

void deleteNode(node_t n) 
{
        
}
void delete_Edge(int from, int to)
{
        A[from][to] = 0;
}*/


#include "graph.h"
#include <string.h>
#include <stdlib.h>

//int nbUsers = 0;


void addNode(char name[]) {

    node[nbUsers] = (node_t *) malloc( sizeof (node_t ));
    strcpy( node[nbUsers]->name, name  );
      nbUsers++;

}




void addEdge(int from, int to) {
    A[from][to] = 1;

}

void deleteNode(node_t n ) {


}



void deleteEdge(int from, int to) {
  A[from][to] = 0;

}
