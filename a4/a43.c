#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node_t {
        int data;
        struct node_t *next;
};
struct node_t * push(struct node_t *head, int tmp);
bool isEmpty(struct node_t *s);
struct node_t *enqueue(struct node_t *q, int tmp);
int pop(struct node_t **head);
int dequeue(struct node_t **q);
void print_sq(struct node_t *head);
int main(void)
{
        int size2 = 0;
        int size1 = 0;
        struct node_t *head1 = NULL;
        struct node_t *head2 = NULL;
        struct node_t *head3 = NULL;
        int m = 0;
        int n = 0;
        char buf[32];
        struct node_t *OddQ = NULL;
        struct node_t *EvenQ = NULL;
        int tmp;
        printf("Enter the size of first stack:");
        fgets(buf, 32, stdin);
        n = atoi(buf);

        printf("Enter the size of second stack: ");
        fgets(buf, 32, stdin);
        m = atoi(buf);
        printf("For first Stack: \n");
        for (int i = 0; i < n; i++) {
                printf("Enter element: ");
                fgets(buf, 32, stdin);
                tmp = atoi(buf);
                head1 = push(head1, tmp);
        }
        print_sq(head1);

        printf("For second Stack: \n");
        for (int i = 0; i < m; i++) {
                printf("Enter element: ");
                fgets(buf, 32, stdin);
                tmp = atoi(buf);
                head2 = push(head2, tmp);
        }
        print_sq(head2);
        
        while( !isEmpty(head1) && !isEmpty(head2)) { /* So, this loop doesn't become infinite loop */

/** It is popping all the elements from the 1st stack.
 *  These elements belong to stack2.
 * size1 and size2 are number of odd elements which are being stored in one stack when other is being processed. */
                for (int i = 0; i < size1; i++) {

                        tmp = pop(&head1);
                        head2 = push(head2, tmp);
                        size2++;
                }
                size1 = 0;
                if (!isEmpty(head1)) {
                        tmp = pop(&head1);
                        if(!(tmp % 2)) {
                                head3 = push(head3, tmp);
                        } else {
                                head2 = push(head2, tmp);
                                size2++;
                        }
                }

                for (int i = 0; i < size2; i++) {
                        tmp = pop(&head2);
                        head1 = push(head1, tmp);
                        size1++;
                }
                size2 = 0;
                if ( !isEmpty (head2)) {
                        tmp = pop(&head2);
                        if (!(tmp % 2)) {
                                head3 = push(head3, tmp);
                        } else {
                                head1 = push(head1, tmp);
                                size1++;
                        }
                }
        }
        while (!isEmpty(head1) || !isEmpty(head2)) {
                if (!isEmpty(head1)) {
                        tmp = pop(&head1);
                        head3 = push(head3, tmp);
                }
                if (!isEmpty(head2)) {
                        tmp = pop(&head2);
                        head3 = push(head3, tmp);
                }
        }
        print_sq(head3);
}

struct node_t * push(struct node_t *head, int tmp)
{
        if (head == NULL) {
                head = malloc(sizeof(struct node_t));
                head -> data = tmp;
                head -> next = NULL;
        } else {
                struct node_t *tmp1 = head;
                tmp1 = malloc(sizeof(struct node_t));
                tmp1 -> data = tmp;
                tmp1 -> next = head;
                head = tmp1;
        }
        return head;
}
/**
 * Function which returns true if Stack/Queue is empty. False if not
 * @param struct node_t *s is pointer to stack/queue
 * @return true if stack/queue is empty; false if not.
 */
bool isEmpty(struct node_t *s)
{
        if (s == NULL)
                return true;
        return false;
}
/**
 * Function to enqueue element in linked list queue
 * @param *q is the pointer to the first element of queue
 * @param tmp is the integer to be inserted
 * @return the first element of queue
 * */
struct node_t *enqueue(struct node_t *q, int tmp)
{
        if (q == NULL) {
                q = malloc(sizeof(struct node_t));
                q -> data = tmp;
                q -> next = NULL;
        } else {
                struct node_t *tmp2 = malloc(sizeof(struct node_t));
                tmp2 -> data = tmp;
                struct node_t *tmp1 = q;
                while (tmp1 -> next)
                        tmp1 = tmp1 -> next;
                tmp1 -> next = tmp2;
                tmp2 -> next = NULL;
        }
        return q;
}

int pop(struct node_t **head)
{
        int tmp = (*head) -> data;
        struct node_t *tmp1 = (*head) -> next;
        free((*head));
        (*head) = tmp1;
        return tmp;
}
int dequeue(struct node_t **q)
{
        int tmp = (*q) -> data;
        struct node_t *tmp1 = (*q) -> next;
        free((*q));
        (*q) = tmp1;
        return tmp;
}
void print_sq(struct node_t *head)
{
        struct node_t *tmp = head;
        printf("Elements are: ");
        while(tmp) {
                printf("%d, ", tmp -> data);
                tmp = tmp -> next;
        }
        printf(" \n\n");
}