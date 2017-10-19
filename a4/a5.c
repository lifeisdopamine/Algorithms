#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1; 
int main(void)
{
        char buf[32];
        int size;
        printf("Enter the number of elements for deque: ");
        fgets(buf, 32, stdin);
        size = atoi(buf);
        int *deque = (int *) malloc(size * sizeof(int));
        
        for(int i = 0; i < size; i++) {
                printf("Enter the element from the front: ");
                fgets(buf,32, stdin);
                int tmp = atoi(buf);
                deque = addFront(deque, tmp);
        }
        for (int i = size - 1; i > front; i--) {
                printf("Enter the element from the back: ");
                fgets(buf, 32, stdin);
                int tmp = atoi(buf);
                deque = addRear(deque, tmp);
        }

        while (!isEmpty(deque)) {
                if(front != rear) {
                        
                }
        }
        

        
        return 0;
}