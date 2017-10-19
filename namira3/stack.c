/*
* @name Programming Assignment 3
* @author Namir Hassan, Yash Shah & Brendan Wilson
* @date 10/10/17
* @brief This program is designed to prompt user to enter a number,
* read that number, add it to stack. ven elements are at the bottom 
* of the stack (in the same order they were initially entered) and all 
* odd elements are at the top of the stack in the reverse order in which 
* they were entered.
*/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

element *mainStack = NULL;
element *evenStack = NULL;
element *oddQueue = NULL;


int main(void) {

	char buffer[SIZE];
	int items; 
	int item;
	int i = 0;

	printf("\nEnter a number of items: ");

	if(fgets(buffer, sizeof(buffer), stdin) != NULL) { 

		items = atoi(buffer);

		// Push all the read items in a Stack (LIFO) elements.
		for(i = 0; i < items; i++) {
			printf("Enter a number for an item: ");
			if(fgets(buffer, sizeof(buffer), stdin) != NULL) {
				item = atoi(buffer);
				mainStack = push(item, mainStack);
			}
		}
		printf("\n");

		displayStackOnly(mainStack);
		printf("\n");
		
		// Pop all the Stack elements and repopulate in the same stack after separating evens and odds.
		for(i=0; i < items; i++){

			item = peek(mainStack);			
			mainStack = pop(mainStack);

			if (item % 2 == 0) {
				evenStack = push(item, evenStack); 
			} else {
				oddQueue = enQueue(item, oddQueue); 
					
					}
			//printf("popping item: %d\n", item);
		}
		//printf("\n");

	} else {
		printf("Error: Can not read number.");
		exit(1);
	}

	displayStackOnly(oddQueue);
	displayStackOnly(evenStack);
	

	
	while ( evenStack != NULL ) {
		item = peek(evenStack); 
		evenStack = pop(evenStack); 
		mainStack = push(item, mainStack);
	}

	while ( oddQueue != NULL ) {
		item = peek(oddQueue); 
		oddQueue = pop(oddQueue); 
		mainStack = push(item, mainStack);

	}

	displayStackOnly(mainStack);
	printf("\n");

	return 0;
}

element *push(int item, element *head) {

element *p = ( element *) malloc ( sizeof(element));
p->item = item;
p->next = head;
head = p;
return head;
}

element *enQueue(int item, element *head){
	
	element *tmp = NULL;
	element *p = ( element *) malloc ( sizeof(element));
	if(p == NULL) {
		printf("Error: Can't malloc space.\n");
		exit(1);
	}

	p->item = item;
	p->next = NULL; 

	if (head == NULL) { 
		head = p;
	} else {
		tmp = head;
		while(tmp->next != NULL) {
			tmp = tmp->next; 
		}
		
		tmp->next = p;
	}
	return head;
}

int peek(element *head) 
{
	return head->item;
}

boolean isEmpty(element *head) {
	if (head == NULL) 
		return true;
	else
    		return false;
}

element *pop(element *head) {
	int item;
	element *tmp = head;

	if ( ! isEmpty(head) ) {
		item = head->item;
		head = head->next;
		
		free(tmp);

		return head;
	}
	else
	     return NULL;

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
