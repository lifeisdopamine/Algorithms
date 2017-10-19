#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        printf("Twitter Example: \n");

        addNode("A");
        addNode("B");
        addNode("C");
        
        addEdge(0, 2);
        addEdge(0, 1);
        addEdge(2, 0);
        addEdge(1, 2);

        sendTweet(0, "hi there!");
        return 0;
}


