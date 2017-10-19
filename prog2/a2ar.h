#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

E *push(E a[], int *size, E item);
E *SwapArr(E a[], int *size);
void print_array(E a[], int size);
int peek(int a[]);
bool isEmpty(int a[]);        
void pop(int a[], int size);