#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100
#define M 10

struct node_t {
        char *name;
        int nbTweetsSent;
        char messageSent[M][140];
        int nbTweetsReceived;
        char messageReceived[M][140];
        int nbFollowers;
};

int nbUsers = -1;
struct node_t **node;
int A[N][N];

void addNode(char name[]);
void addEdge(int from, int to);
void delete_Edge(int from, int to);
void sendTweet(int from, char tweet[]);
void ReceiveTweet(int to, char tweet[]);
void follow(int i, int j);
void unfollow(int i, int j);
void printFollowersOf(int i);
void printFollowing(int i);
void commonFollowersOf(int i, int j);
void mostFollowedUser();
void printUsersBySortedNumberofFollowers();
void isort();

int main(void)
{
        int i = 0, j = 0;
        addNode("a");
        addNode("b");
        addNode("c");
        addNode("d");

        addEdge(0, 1);
        addEdge(0, 2);
        addEdge(0, 3);
        addEdge(2, 3);
        follow(1, 3);
        follow(1, 0);
        follow(2, 3);
        follow(2, 3);
        follow(3, 1);
        follow(1, 0);
        follow(2, 0);

        sendTweet(1, "lifeisdopamine");

        printf("Printing the followers of %s \n", node[1] -> name);
        printFollowersOf(1);
        printf("Printing the followings of %s \n", node[2] -> name);
        printFollowing(2);
        //printf("Common followers of %s and %s:\n ", node[0] -> name, node[2] -> name);
        commonFollowersOf(0, 3);
        mostFollowedUser();
        printf("\n\n");
        printUsersBySortedNumberofFollowers();
        
        //printf("Printing Sent Tweets: \n");
        /*for(int k = 0; k <= nbUsers; k++) {
                printsentTweets(k);
                printReceivedTweets(k);
        }*/
        for (i = 0; i <= nbUsers; i++) {
                free(node[i] -> name);
        }
        for (i = 0; i <= nbUsers; i++) {
                free(node[i]);
        }
        free(node);
        return 0;
}
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