#include "graph.h"
#include "twitter.h"


int main(void)
{
        int i = 0;
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