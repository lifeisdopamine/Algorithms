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
        strcpy (receiver -> messageRecieved[nbTweetsReceived], tweet);
        receiver -> nbTweetsRecieved++;
        printf("%s: I received a new tweet: %s \n", receiver-> name, receiver -> messageRecieved);
}