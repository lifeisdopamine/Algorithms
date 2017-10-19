/*
* @name Programming Assignment 2
* @author Namir Hassan
* @group Yash Shah & Brendan Wilson
* @date 10/4/17
* @brief This program is designed to prompt user to enter a number,
* read that number, determine whether that number is even or odd,
* prints the entered numbers in reverse order, and print out the
* odd numbers and even numbers in the same order they were entered
*/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

element *mainStack = NULL;
element *evenStack = NULL;
element *oddStack = NULL;
element *tmpMainStack = NULL;


int main() {

	char buffer[SIZE];
	int items; 
	int item;
	int i = 0;

	printf("\nEnter a number of items: ");

	if(fgets(buffer, sizeof(buffer), stdin) != NULL) {

		items = atoi(buffer);
		//printf("%d\n", items);
		for(i = 0; i < items; i++) {
			printf("Enter a number for an item: ");
			if(fgets(buffer, sizeof(buffer), stdin) != NULL) {
			item = atoi(buffer);
			mainStack = push(item, mainStack);

			//printf("%d\n", item);

			}

		}

		printf("\n");
		displayStackOnly(mainStack);
		tmpMainStack = mainStack;
		
		while(tmpMainStack != NULL) {
			if(tmpMainStack->item % 2 == 0){
				//printf("%d is even\n", tmpMainStack->item);
				evenStack = push(tmpMainStack->item, evenStack);
			} else {
				//printf("%d is odd\n", tmpMainStack->item);
				oddStack = push(tmpMainStack->item, oddStack);
			}
			tmpMainStack = tmpMainStack->next;
		}
		displayStackOnly(oddStack);
		displayStackOnly(evenStack);
		

		printf("\n\n");



	} else {
		printf("Error: Can not read number.");
		exit(1);
	}

	return 0;
}

element *push(int item, element *head) {

element *p = ( element *) malloc ( sizeof(element));
p->item = item;
p->next = head;
head = p;
return head;
}

int peek(element *head) {
    return head->item;


}
boolean isEmpty(element *head) {
if (head == NULL) return true;
else
    return false;
}

element *pop(element *head) {
	int item;
	element *tmp = head;

    if ( ! isEmpty(head) ) {
    item = head->item;
    head = head->next;
    printf("Popped item: %d\n", item);
    
    free(tmp);

    return head;
	}
    else return NULL;

}

void displayStack(element *head) {

element *p = head;

printf ("\nThe stack now contains \n");

while ( ! isEmpty(head) ) {
    printf("%d\n", peek(head) );
    head = pop(head);
}

}

void displayStackOnly(element *head) {

element *p = head;

printf ("\n\nThe stack now contains \n");

while ( p != NULL ) {
    printf( "\n %d ", peek(p) );
    p = p->next;
}


}
