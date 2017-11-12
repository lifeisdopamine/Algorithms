#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100
#define M 10
/*
struct node_t{
        char name[10];
        int nbTweetsSent;
        char messageSent[M][140];
        char messageReceived[M][140];
        int nbTweetsReceived;
        int nbFollowers;
};*/

struct node_t {
        char *name;
        int nbTweetsSent;
        char messageSent [M][140];
        char messageReceived [M][140];
        int nbTweetsReceived;
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
int compare(const void *n1, const void *n2);
void isort();
void check_string(char buf[]);
void printReceivedTweets(int i);
void printsentTweets(int i);

int main(void)
{
       char d[8];
        char buf[256];
        int i = 0, j = 0;
        printf("Twitter-like Structure \n\n");
        printf("Enter your choice:\n");

        printf("A. Add user\n");
        printf("B. Follow user \n");
        printf("C. See the Followers \n");
        printf("D. Print the Most followed User \n");
        printf("E. Print the common Followers\n");
        printf("F. Print the users sorted by Followers \n");
        printf("G. Send tweet \n");
        printf("Q. Quit\n\n");

        addNode("a");
        addNode("b");
        addNode("c");
        addNode("d");

        addEdge(0, 1);
        addEdge(0, 2);
        addEdge(0, 3);
        addEdge(2, 3);
        addEdge(1, 3);
        addEdge(1, 0);
        addEdge(2, 1);
        addEdge(3, 1);

        sendTweet(1, "lifeisdopamine");
        printFollowersOf(1);
        printFollowing(2);
        commonFollowersOf(0, 2);
        printUsersBySortedNumberofFollowers();
        while ((d[0] != 'q' ) && (d[0] != 'Q')) {
        
        fgets(d, 8, stdin);

        switch (d[0]) {
                case 'A':
                case 'a':

                        nbUsers++;        
                        node = realloc(node, sizeof(struct node_t **) * (nbUsers + 1));
                        node[nbUsers] = calloc(1, sizeof(struct node_t));                        
                        
                        printf("Enter your name: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        //addNode(buf);
                        node[nbUsers] -> name = malloc(sizeof(char) * (strlen(buf) + 1));
                        strcpy(node[nbUsers] -> name, buf);
                        break;
                
                case 'b':
                case 'B':
                        printf("Enter your name: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        for (i = 0; i <= nbUsers; i++) {
                                if (!(strcmp(node[i] -> name, buf)))
                                        break;
                        }
                        if ((i == nbUsers) && (strncmp(node[i] -> name, buf, strlen(node[i] -> name)))) {
                                printf("Error: Entered name is not in system \n");
                                break;
                        }
                        printf("Enter the name of the person you want to follow: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        for (j = 0; j <= nbUsers; j++) {
                                if (!(strcmp(node[j] -> name, buf)))
                                        break;
                        }
                        if ((j == nbUsers) && ((strncmp(node[j] -> name, buf, strlen(node[j] -> name))))) {
                                printf("Error: Entered name is not in system \n");
                                break;
                        }
                        follow(i, j);
                        break;

                case 'c':
                case 'C':
                        printf("Enter the person you want to see followers of: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        for (i = 0; i <= nbUsers; i++) {
                                if (!(strcmp(node[i] -> name, buf)))
                                        break;
                        }
                        if ((i == nbUsers) && ((strncmp(node[i] -> name, buf, strlen(node[i] -> name))))) {
                                printf("Error: Entered name is not in system \n");
                                break;
                        }
                        printFollowersOf(i);
                        break;
                case 'd':
                case 'D':
                        printf("Enter the name of a person you want to see followings of: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        for (i = 0; i <= nbUsers; i++) {
                                if (!(strcmp(node[i] -> name, buf)))
                                        break;
                        }
                        if ((i == nbUsers) && ((strncmp(node[i] -> name, buf, strlen(node[i] -> name))))) {
                                printf("Error: Entered name is not in system \n");
                                break;
                        }
                        printFollowing(i);
                        break;
                case 'e':
                case 'E':
                        printf("Enter the name of first person: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        for (i = 0; i <= nbUsers; i++) {
                                if (!(strcmp(node[i] -> name, buf)))
                                        break;
                        }
                        if ((i == nbUsers) && ((strncmp(node[i] -> name, buf, strlen(node[i] -> name))))) {
                                printf("Error: Entered name is not in system \n");
                                break;
                        }
                        printf("Enter the name of second person: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        for (j = 0; j <= nbUsers; j++) {
                                if (!(strcmp(node[j] -> name, buf)))
                                        break;
                        }
                        if ((j == nbUsers) && ((strncmp(node[j] -> name, buf, strlen(node[j] -> name))))) {
                                printf("Error: Entered name is not in system \n");
                                break;
                        }
                        commonFollowersOf(i, j);
                        break;

                case 'f':
                case 'F':
                        printUsersBySortedNumberofFollowers();
                        break;
                case 'G':
                case 'g':
                        printf("Enter the name of a person who wants to tweet: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        for (i = 0; i <= nbUsers; i++) {
                                if (!(strcmp(node[i] -> name, buf)))
                                        break;
                        }
                        if ((i == nbUsers) && ((strncmp(node[i] -> name, buf, strlen(node[i] -> name)))) == 0) {
                                printf("Error: Entered name is not in system \n");
                                break;
                        }
                        printf("Enter the tweet: ");
                        fgets(buf, 141, stdin);
                        sendTweet(i, buf);
                        break;
                case 'q':
                case 'Q':
                        printf("Quitting\n");
                        break;
                default:
                        printf("Error: Please enter the valid input/choice \n");
                
        }
        printf("A. Add user\n");
        printf("B. Follow user \n");
        printf("C. See the Followers \n");
        printf("D. Print the Most followed User \n");
        printf("E. Print the common Followers\n");
        printf("F. Print the users sorted by Followers \n");
        printf("G. Send tweet \n");
        printf("Q. Quit\n\n");
        }

        for (int k = 0; k < nbUsers; k++) {
                printsentTweets(k);
                printReceivedTweets(k);
        }
        /*
        addNode("A");
        addNode("B");
        addNode("C");

        addEdge(0, 1);
        addEdge(0, 2);
        addEdge(2, 0);
        addEdge(1, 2);
        //addEdge(1, 0);
        //addEdge(2, 1);
        
        sendTweet(1, "lifeisdopamine");
        printFollowersOf(1);
        printFollowing(2);
        commonFollowersOf(0, 2);
        printUsersBySortedNumberofFollowers();*/
        for (i = 0; i <= nbUsers; i++) {
                free(node[i] -> name);
        }
        for (i = 0; i <= nbUsers; i++) {
                free(node[i]);
        }
        free(node);
        
        /*
        
        
        free(node[2]);
        free(node[1]);
        free(node[0]);
        //free(node);*/
        return 0;
}
void addNode(char name1[])
{
       /* nbUsers++;
        node = realloc(node, sizeof(struct node_t **) * nbUsers);
        node[nbUsers] = calloc(1, sizeof(struct node_t));
        strncpy(node[nbUsers] -> name, name1, (strlen(name1) + 1));*/
        //strcpy(node[nbUsers] -> name, name1);
        //nbUsers++;
        //print_structure(node[nbUser])
        nbUsers++;        
        node = realloc(node, sizeof(struct node_t **) * (nbUsers + 1));
        node[nbUsers] = calloc(1, sizeof(struct node_t));                        
        node[nbUsers] -> name = malloc(sizeof(char) * (strlen(name1) + 1));
        strcpy(node[nbUsers] -> name, name1);

}
void addEdge(int from, int to)
{
        A[from][to] = 1;
        //(node[to - 1] -> nbFollowers)++;
        (node[to] -> nbFollowers)++;
}
void delete_Edge(int from, int to)
{
        A[from][to] = 0;
        //(node[to - 1] -> nbFollowers)--;
        (node[to] -> nbFollowers)--;
}
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
void ReceiveTweet(int to, char tweet[])
{
        struct node_t * receiver = node[to];
        strcpy(receiver -> messageReceived[receiver -> nbTweetsReceived], tweet);
        (receiver -> nbTweetsReceived)++;
        receiver -> nbTweetsReceived %= M;
        printf("%s: I received a new tweet: %s \n", receiver -> name, receiver -> messageReceived[receiver -> nbTweetsReceived]);
}
void follow(int i, int j)
{
        addEdge(i, j);
        //(node[j] -> nbFollowers)++;
}
void unfollow(int i, int j)
{
        delete_Edge(i, j);
       // (node[j] -> nbFollowers)--;
}
void printFollowersOf(int i)
{
        for (int k = 0; k <= nbUsers; k++) {
                if (A[k][i]) {
                        printf("Printing in printFollowersof \n");                        
                        printf("%s follows %s \n", node[k]->name, node[i]->name);
                }
        }
}
void printFollowing(int i)
{
        for (int k = 0; k <= nbUsers; k++) {
                if(A[i][k]) {
                        printf("Printing in printFollowing\n");                       
                        printf("%s follows %s\n", node[i]->name, node[k]->name);
                }
        }
}
void commonFollowersOf(int i, int j)
{
        int k;
        for (k = 0; k <= nbUsers; k++) {
                if (A[k][i] && A[k][j] && (k != i) && (k != j)) {
                        printf("printing in commonFollowersof\n");                        
                        printf("%s and %s will have the same follower %s\n", node[i]->name, node[j]->name, node[k]->name);
                }
        }
        if (k == nbUsers && (!A[k][i]) && (!A[k][j])) {
                printf("%s and %s don't have common Followers \n", node[i] -> name, node[j] -> name);
        }
}
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
        printf("In Most followed user\n");
        printf("%s has most numbers of Followers: %d\n", node[j]->name, node[j]->nbFollowers);
}

void printUsersBySortedNumberofFollowers()
{
        //qsort(node, 100, sizeof(struct node_t), compare);
        isort();
        for (int k = 0; k <= nbUsers; k++) {
                printf("Printing in print Users by sorted number of followers\n");
                printf("%s\t%d \n", node[k]->name, node[k] -> nbFollowers);
        }
}
int compare(const void *n1, const void *n2)
{
        struct node_t *l = (struct node_t *) n1;
        struct node_t *r = (struct node_t *) n2; 
        return l -> nbFollowers - r -> nbFollowers;
}
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
void check_string(char buf[]) 
{
        for (int i = 0; i < strlen(buf); i++) {
                if (isupper(buf[i]))
                        buf[i] = tolower(buf[i]);
                if (buf[i] == '\n')
                        buf[i] = '\0';
        }
}
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
}