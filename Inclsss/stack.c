#include <stdio.h>
#include <stdlib.h>


typedef enum {false, true} boolean;
typedef struct {
        int data[100];
        int count;
} t_stack;

t_stack stack;
void push(int item) 
{
        stack.data[stack.count++] = item;
}
int pop() 
{
        int top = stack.data[stack.count];
        stack.data[stack.count--] = 0;
        return top;
}
int peek()
{
        return stack.data[stack.count];
}/*
typedef isEmpty()
{
        if (stack.count == 0)
                return true;
        return false;
}*/
int main(void)
{
        stack.count = 0;
        
        push(4);
        push(8);
        push(13);
        push(43);
        printf("The top of the stack is %d \n", peek());
        pop();
        printf("The top of the stack is %d \n", peek());
        
        return 0;
}