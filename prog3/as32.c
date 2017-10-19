/**
 * @author: Yash Shah, Namir Hassan, Brendan Wilson 
 * */

#include <stdio.h>
#include <stdlib.h>

struct node_t {
        int data;
        struct node_t *next;
};

void push(struct node_t **head, int item);
int pop(struct node_t **head);
void enqueue(int **a, int *size, int item);
int dequeue(int **a, int *size);
int isEmpty(struct node_t *head);
void print_stack(struct node_t *head);
void print_q(int *a, int size);

int main(void)
{
        int tmp = 0;
        struct node_t *head = NULL;
        int size;
        char buf[32];
        int *EvenQ = NULL;
        int *OddQ = NULL;
        printf("Enter the number of elements: ");
        fgets(buf, 32, stdin);
        size = atoi(buf);
        EvenQ = malloc(size * sizeof(int));
        OddQ = malloc(size * sizeof(int));
        int sizeE = 0;
        int sizeO = 0;

        for (int i = 0; i < size; i++) {
                printf("Enter the number: ");
                fgets(buf, 32, stdin);
                tmp = atoi(buf);
                push(&head, tmp);
        }
        printf("The stack is: \n");
        print_stack(head);

        while (!isEmpty(head)) {
                tmp = pop(&head);
                if ((tmp % 2) == 0)
                        enqueue(&EvenQ, &sizeE, tmp);
                else 
                        enqueue(&OddQ, &sizeO, tmp);
        }
        printf("Even queue is : \n");
        print_q(EvenQ, sizeE);
        printf("Odd queue is: \n");
        print_q(OddQ, sizeO);
        while(1) {
                if (sizeE) {
                        tmp = dequeue(&EvenQ, &sizeE);
                        printf("sizeE: %d\n", sizeE);
                        push(&head, tmp);
                }
                else 
                        break;
        }
        while (1) {
                if (sizeO) {
                        tmp = dequeue(&OddQ, &sizeO);
                        printf("sizeO: %d\n", sizeO);
                        push(&head, tmp);
                }
                else 
                        break;
        }
        
        return 0;
}

void push(struct node_t **head, int item)
{
        if (*head == NULL) {
                (*head) = malloc(sizeof(struct node_t));
                (*head) -> data = item;
                (*head) -> next = NULL;
        } else {/*
                struct node_t *tmp = NULL;
                //tmp = malloc(sizeof(struct node_t ));
                tmp = (*head -> next);
                *head = malloc(sizeof(struct node_t));
                (*head) -> data = item;
                (*head) -> next = tmp;*/
                struct node_t *tmp = *head;
                struct node_t *tmp1 = malloc(sizeof(struct node_t));
                tmp1 -> data = item;
                tmp1 -> next = tmp;
                *head = tmp1;
        }
}
int pop(struct node_t **head)
{
        int tmp = (*head) -> data;
        struct node_t *tmp2 = (*head) -> next;
        free(*head);
        (*head) = tmp2;
        return tmp;
}
void enqueue(int **a, int *size, int item)
{
        *(*a + *size) = item;
        (*size)++;
}
int dequeue(int **a, int *size)
{
        int tmp = *a[0];
        for(int i = 0; i < *size - 1; i++) {
                *a[i]  = *a[i + 1];
        }
        (*size)--;
        return tmp;
}
int isEmpty (struct node_t *head)
{
        if (head == NULL)
                return 1;
        return 0;
}
void print_stack(struct node_t *head)
{
        struct node_t *tmp = head;

        while (tmp) {
                printf("%d \n", tmp -> data);
                tmp = tmp -> next;
        }
        printf("\n\n");
}
void print_q(int *a, int size)
{
        for(int i = 0; i < size; i++) {
                printf("%d \n", a[i]);
        }
        printf("\n\n");
}