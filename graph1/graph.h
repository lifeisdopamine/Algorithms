#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 10
int nbUsers = -1;
struct node_t **node;
int A[N][N];
struct node_t {
        char *name;
        int nbTweetsSent;
        char messageSent[M][140];
        int nbTweetsReceived;
        char messageReceived[M][140];
        int nbFollowers;
};


void addNode(char name[]);
void addEdge(int from, int to);
void delete_Edge(int from, int to);