#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define M 10
struct node_t {
        char *name;
        int nbTweetsSent;
        char messageSent[M][140];
        char messageReceived[M][140];
        int nbTweetsReceived;
        int nbFollowers;

};

int nbUsers = -1;
int A[10][10];
struct node_t **node = NULL;


int main(void)
{       
        char c, d;
        char buf[128];
        int i = 0, j = 0;
        printf("Twitter-like Structure \n\n");
        printf("Enter your choice:\n");

        printf("A. Add user\n");
        printf(". Follow user \n");
        printf(". See the Followers \n");
        printf(". Print the Most followed User \n");
        printf(". Print the users sorted by Followers \n");

        while((c = getchar()) == '\n') 
                d = c;

        switch (d) {
                case 'A':
                case 'a':

                        nbUsers++;        
                        node = realloc(node, sizeof(struct node_t *) * (nbUsers + 1));
                        node[nbUsers] = calloc(1, sizeof(struct node_t));                        
                        
                        printf("Enter your name: ");
                        fgets(buf, 128, stdin);
                        node[nbUsers] -> name = malloc(sizeof(char) * (strlen(buf) + 1));
                        strcpy(node[nbUsers] -> name, buf);
                        break;
                
                case 'b':
                case 'B':
                        printf("Enter your name: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        for (i; i <= nbUsers; i++) {
                                if (!(strcmp(node[i] -> name, buf)))
                                        break;
                        }
                        if ((i == nbUsers) && (!(strcmp(node[i] -> name, buf)))) {
                                printf("Error: Entered name is not in system \n");
                                break;
                        }
                        printf("Enter the name of the person you want to follow: ");
                        fgets(buf, 128, stdin);
                        check_string(buf);
                        for (j; j <= nbUsers; j++) {
                                if (!(strcmp(node[i] -> name, buf)))
                                        break;
                        }
                        if ((j == nbUsers) && (!(strcmp(node[j] -> name, buf)))) {
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
                        if ((i == nbUsers) && (!(strcmp(node[i] -> name, buf)))) {
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
                        if ((i == nbUsers) && (!(strcmp(node[i] -> name, buf)))) {
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
                        if ((i == nbUsers) && (!(strcmp(node[i] -> name, buf)))) {
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
                        if ((j == nbUsers) && (!(strcmp(node[j] -> name, buf)))) {
                                printf("Error: Entered name is not in system \n");
                                break;
                        }
                        commonFollowersOf(i, j);
                        break;

                case 'f':
                case 'F':
                        printUsersBySortedNumberofFollowers();
                        break;
                
                case 'q':
                case 'Q':
                        printf("Quitting\n");
                        break;
                default:
                        printf("Error: Please enter the valid input/choice \n");
                
        }
        
        return 0;
}
void check_string(char buf[]) 
{
        for (int i = 0; i < strlen(buf); i++) {
                if (isupper(buf[i]))
                        buf[i] = tolower(buf[i]);
        }
}