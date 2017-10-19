
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 100
#define M 10
int nbUsers = 0;
typedef struct {
        char name[10];
        int nbTweetsSent;
        char messageSent[M][140];
        char messageReceived[M][140];
        int nbTweetsReceived;
} node_t;


typedef struct {
        
}

int A[N][N];

void addNode(char name[]);
void addEdge(int from, int to);
void deleteNode(int n);
void delete_Edge(int from, int to);
