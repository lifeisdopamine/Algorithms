
typedef enum { false, true } boolean;

//typedef struct {
//int data[100];
//int count;
//} t_stack;

typedef struct element {
        int item;
        struct element *next;
} element;




void push(int item );
int pop();
boolean isEmpty();
int peek();
void displayStack();
