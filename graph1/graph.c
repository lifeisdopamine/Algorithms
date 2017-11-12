#include "graph.h"


/**
 * To add node 
 * @param name1[] is the array which contains name of the new user
 * Functio to malloc one more element in node array of pointers and callocs the structure to newly added element
 */
void addNode(char name1[])
{
        nbUsers++;        
        node = realloc(node, sizeof(struct node_t **) * (nbUsers + 1));
        node[nbUsers] = calloc(1, sizeof(struct node_t));                        
        node[nbUsers] -> name = malloc(sizeof(char) * (strlen(name1) + 1));
        strcpy(node[nbUsers] -> name, name1);

}
/**
 * To add edge between two users
 **/
void addEdge(int from, int to)
{
        if (A[from][to])
                return;
        A[from][to] = 1;
        (node[to] -> nbFollowers)++;
}
/**
 * To delete edge between two users
 */
void delete_Edge(int from, int to)
{
        if (A[from][to] == 0)
                return;
        A[from][to] = 0;
        (node[to] -> nbFollowers)--;
}