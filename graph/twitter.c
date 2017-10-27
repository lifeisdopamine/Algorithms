#include "twitter.h"
#include "graph.h"

#include<stdio.h>
#include <stdlib.h>
void sendTweet (int from, char tweet[])
{
        for (int i = 0; i < N; i++) {
                if (A[i]][from]) 
                        receiveTweet(i, tweet);
        }
}
void ReceiveTweet(int to, char tweet[])
{
        node_t * receiver = node[to];
        strcpy (receiver -> messageReceived[nbTweetsReceived], tweet);
        receiver -> nbTweetsReceived++;
        printf("%s: I received a new tweet: %s \n", receiver-> name, receiver -> messageReceived)
}
void follow(int i, int j)
{
        A[i][j] = 1;
        node[j].nbFollowers++;
}
void unfollow(int i, int j)
{
        A[i][j] = 0;
        node[j].nbFollowers--;
}
void printFollowersOf(int i)
{
        for(int k = 0; i < nbUsers; i++) {
                if(A[k][i])
                        printf("%s follows %s\n", node[k].name, node[i].name);
        }
}
void printFollowing(int i)
{
        for (int k = 0; i < nbUsers; i++) {
                if (A[i][k])
                        printf("%s follows %s", node[i].name, node[k].name);
        }
}
void commonFollowersOf(int i, int j)
{
        for (int k = 0; k < nbUsers; i++) {
                if (A[k][i] && A[k][j])
                        printf("%s and %s will have the same follower %s\n", node[i].name, node[j].name, node[k].name);
        }
}
void mostFollowedUser()
{
        int max = node[0].nbFollowers;
        int j;
        for(int i = 1; i < nbUsers; i++) {
                if (max < node[i].nbFollowers) {
                        max = node[i].nbFollowers;
                        j = i;
                }
        }
        printf("%s has most number of followers: %d\n", node[j].name, node[j].nbFollowers);
        
}
void printUsersBySortedNumberofFollowes()
{
        qsort(node, (size_t) nbUsers, sizeof(node_t), compare);
        for(int k = 0; k < nbUsers; k++) {
                printf("%s\t%d", node[k].name, node[k].nbFollowers);
        }
                 
}
int compare(node_t *n1, node_t *n2)
{
       return n1 -> nbFollowers - n2 -> nbFollowers;
}
