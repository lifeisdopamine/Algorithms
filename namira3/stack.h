#define SIZE 32

typedef enum { false, true } boolean;

typedef struct element {
int item;
struct element *next;
} element;

element *push(int item, element *head);
element *enQueue(int item, element *head);
element *pop(element *head);
boolean isEmpty(element *head);
int peek(element *head);
void displayStack(element *head);
void displayStackOnly(element *head);
