#include "graph.h"

int nbUsers = 0;

void addNode(char name[])
{
        
        node[nbUsers] = (node_t *) malloc(sizeof(struct node_t));
        strcpy(node[nbUsers] -> name, name);
        nbUsers++;

}
void addEdge(node_t from, node_t to)
{
        A[from][to] = 1;
}
void deleteNode(node_t n);
void delete_Edge(int from, int to)
{
        A[from][to] = 0;
}