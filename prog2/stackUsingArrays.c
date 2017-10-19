

#include <stdio.h>
#include "stack.h"

t_stack stack;

void push(int item ) {
stack.data[stack.count] = item;
stack.count++;
}

int pop() {
int tos = stack.data[stack.count];
stack.data[stack.count] = 0;
stack.count--;
return tos;
}

boolean isEmpty() {

if ( stack.count == 0 ) return true;
else
    return false;

}

void displayStack() {
printf("\n The stack contains: \n");
while ( ! isEmpty() )  {
 printf("\n %d", peek() );
 pop();
}

}

int peek() {
return stack.data[stack.count-1];
}


