

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

element *head = NULL;

void push(int item ) {

        element *p = ( element *) malloc ( sizeof(element));
        p->item = item;
        p->next = head;
        head = p;
}

int peek() {
    return head->item;


}
boolean isEmpty() {
if (head == NULL) return true;
else
    return false;
}

int pop( ) {
    if ( ! isEmpty() )
    head = head->next;
    else return -1;

}

void displayStack() {

element *p = head;

printf ("\nThe stack now contains \n");

while ( ! isEmpty() ) {
    printf( "\n %d ", peek() );
    pop();
}


}
