#include <stdio.h>
#include <stdlib.h>


struct node_t {
        int data;
        struct node_t *next;
};

struct node_t * create_node(struct node_t *head, int n);
struct node_t * pop(struct node_t *head);
void enqueue(int **a, int *size,int data);
int dequeue(int **a, int *size);
int count_elements(struct node_t *head);
void print_stack(struct node_t *head);
void print_queue(int **a, int size);




int main(void)
{
        int tmp = 0;
        int size;
        char buf[32];
        printf("Enter the number of elemenets: ");
        fgets(buf, 32, stdin);
        size = atoi(buf);
        
        int *EvenQ = NULL;
        int *OddQ = NULL;
        int sizeE = 0;
        int sizeO = 0;
        struct node_t *head = NULL;
        for (int i = 0; i < size; i++) {
                printf("Enter the element: ");
                fgets(buf, 32, stdin);
                int n = atoi(buf);
                head = create_node(head, n);
        }
        print_stack(head);
        //printf("Count Elements: %d \n", count_elements(head));
        while (head) {
                if (((head -> data) % 2) == 0) {
                        enqueue(&EvenQ, &sizeE, head -> data);
                        //printf("evenQ %d \n", *(EvenQ + sizeE - 1));
                        head = pop(head);
                } else {
                        enqueue(&OddQ, &sizeO, head -> data);
                        //printf("OddQ %d \n", *(OddQ + sizeO - 1));                        
                        head = pop(head);
                }
        }
        print_queue(&EvenQ, sizeE);
        print_queue(&OddQ, sizeO);
        while(sizeE) {
                tmp = dequeue(&EvenQ, &sizeE);
                head = create_node(head, tmp);
        }
        print_queue(&EvenQ, sizeE);
        print_stack(head);
        //int sizeO2 = sizeO;
        while(sizeO) {
                tmp = dequeue(&OddQ, &sizeO);
                head = create_node (head, tmp);
        }
        print_stack(head);/*
        while(sizeO2 != sizeO) {
                //int tmp = pop();
                enqueue(&OddQ, &sizeO, head -> data);
                head = pop(head);
        }
        print_queue(&OddQ, sizeO);
        while(sizeO) { 
                tmp = dequeue(&OddQ, &sizeO);
                create_node(head, tmp);
        } 
        print_stack(head);*/
        return 0;
}
struct node_t * create_node(struct node_t *head, int n)
{
        if (head == NULL) {
                head = malloc(sizeof(struct node_t));
                head -> data = n;
                head -> next = NULL;
        } else {
                struct node_t *tmp = malloc (sizeof(struct node_t ));
                tmp -> data = n;
                tmp -> next = head;
                head = tmp;
        }
        return head;
}
struct node_t * pop(struct node_t *head)
{       
        if (head -> next == NULL) {
                free(head);
                head = NULL;
        } else {
                struct node_t *tmp = head -> next;
                free(head);
                head = tmp;
        }
        return head;
}
void enqueue(int **a, int *size, int data)
{
        if (*a == NULL) {
                *a = malloc(sizeof(int));
                (*size)++;
                *(*a + *size - 1) = data;
        } else {
                *a = realloc(*a, ((*size) + 1) * sizeof(int));
                (*size)++;
                *(*a + *size - 1) = data;
        }
        //printf("size: %d\n", *size);
}
int dequeue(int **a, int *size)
{
        int tmp = *a[0];
        for(int i = 1; i < *size; i++) {
                *a[i - 1] = *a[i];
        }
        *a = realloc(*a, ((*size - 1)) * sizeof(int));
        (*size)--;
        return tmp;
}
int count_elements(struct node_t *head)
{
        struct node_t *node = head;
        int count = 0;
        while(node) {
                count++;
                node = node -> next;
        }
        return count;
}
void print_stack(struct node_t *head)
{
        struct node_t *tmp = head;
        printf("Stack elements \n");
        while (tmp) {
                printf("%d \n", tmp -> data);
                tmp = tmp -> next;
        }
}
void print_queue(int **a, int size)
{
        printf("Queue: \n");
        for(int i = 0; i < size; i++) {
                printf("%d \n", *a[i]);
        }
        printf("\n\n"  );
}