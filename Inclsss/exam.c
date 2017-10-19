#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int oddQ = NULL;
        int evenQ = NULL;
        int mainStack = NULL;
        char buf[32];
        int size;
        printf("Enter the size: ");
        fgets(buf, 32, stdin);
        size = atoi(buf);
        mainStack = (int *) malloc(size * sizeof(int));

        for(int i = 0; i < size; i++) {
                printf("Enter the number: ");
                fgets(buf, 32, stdin);
                int tmp = atoi(buf);
                push(mainStack, tmp);
        }
        return 0;
}

void push(int *stack, int item) {
        
        }