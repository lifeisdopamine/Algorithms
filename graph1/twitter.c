#include "twitter.h"
#include "graph.h"
/**
 * To send tweet
 **/
void sendTweet(int from, char tweet[])
{
        for(int i = 0; i < N; i++) {
                if (A[i][from]) 
                        ReceiveTweet(i, tweet);
        }
        strcpy(node[from] -> messageSent[node[from] -> nbTweetsSent], tweet);
        (node[from] -> nbTweetsSent)++;
        node[from] -> nbTweetsSent %= M;
        
}
/**
 * To receive tweet */
void ReceiveTweet(int to, char tweet[])
{
        struct node_t * receiver = node[to];
        strcpy(receiver -> messageReceived[receiver -> nbTweetsReceived], tweet);
        (receiver -> nbTweetsReceived)++;
        receiver -> nbTweetsReceived %= M;
        printf("%s: I received a new tweet: %s \n", receiver -> name, receiver -> messageReceived[receiver -> nbTweetsReceived]);
}
/**
 * addEdge in twitter language */
void follow(int i, int j)
{
        addEdge(i, j);
}
/**
 * deleteEdge in twitter language */
void unfollow(int i, int j)
{
        delete_Edge(i, j);
}
/* to print the followers of user */
void printFollowersOf(int i)
{
        for (int k = 0; k <= nbUsers; k++) {
                if (A[k][i]) {
                        printf("Printing in printFollowersof \n");                        
                        printf("%s follows %s \n", node[k]->name, node[i]->name);
                }
        }
}
/* to print the following of user */
void printFollowing(int i)
{
        for (int k = 0; k <= nbUsers; k++) {
                if(A[i][k]) {
                        printf("%s follows %s\n", node[i]->name, node[k]->name);
                }
        }
}
/* Printing the common followers of a user */
void commonFollowersOf(int i, int j)
{
        int k;
        for (k = 0; k <= nbUsers; k++) {
                if (A[k][i] && A[k][j] && (k != i) && (k != j)) {
                        printf("%s and %s will have the same follower %s\n", node[i]->name, node[j]->name, node[k]->name);
                }
        }
        if (k == nbUsers && (!A[k][i]) && (!A[k][j])) {
                printf("%s and %s don't have common Followers \n", node[i] -> name, node[j] -> name);
        }
}
/* To see who is the most followed user */
void mostFollowedUser()
{
        int max = node[0]->nbFollowers;
        int j;
        for(int i = 1; i <= nbUsers; i++) {
                if (max < node[i]->nbFollowers) {
                        max = node[i]->nbFollowers;
                        j = i;
                }
        }
        printf("%s has most numbers of Followers: %d\n", node[j]->name, node[j]->nbFollowers);
}
/* To print the sorted followers by follower count */
void printUsersBySortedNumberofFollowers()
{
        //qsort(node, 100, sizeof(struct node_t), compare);
        isort();
        for (int k = 0; k <= nbUsers; k++) {
                printf("%s\t%d \n", node[k]->name, node[k] -> nbFollowers);
        }
}
/* Sorts the users by their follower count */
void isort()
{
        int i, j;
        struct node_t *key = NULL;
        for(i = 1; i < nbUsers; i++) {
                key = node[i];
                j = i - 1;

                while(j >= 0 && (node[j] -> nbFollowers) > (key -> nbFollowers)) {
                        node[j + 1] = node[j];
//                        node [j + 1] -> name = node[j] -> name;
                        j = j - 1;
                }
                node[j + 1] = key;
        }
}
/*
void printsentTweets(int i)
{
        printf("Sent tweets of %s \n", node[i] -> name);
        for (int j = 0; j < M; j++) {
                printf("%s\n",node[i] -> messageSent[j]);
        }
}
void printReceivedTweets(int i)
{
        printf("Received tweets of %s \n", node[i] -> name);
        for (int j = 0; j < M; j++) {
                printf("%s\n",node[i] -> messageReceived[j]);
        }
}*/