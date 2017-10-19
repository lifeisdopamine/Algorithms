#include "a2ar.h"

E * push(E *a, int *size, E item)
{
                a = realloc(a, ((*size) + 1) * sizeof(int));
                /*if(!a)
                        return NULL;*/
                (*size)++;
                printf("size: %d ", *size);
                a = (int *) SwapArr(a, size);
                a[0] = item;
        return a;
}
E* SwapArr(E *a, int *size) 
{
        for (int i = *size - 1; i >= 1; i--) {
                a[i] = a[i - 1];
        }
        return a;

}
void print_array(E a[], int size)
{
        for (int i = 0; i < size; i++) {
                printf("Array: %d, \n", a[i]);
        }
        printf("\n");
}
int peek(int *a) 
{
        return *a;
}
bool isEmpty(int a[])
{
        if (a != NULL)
                return 1;
        return 0;
}
void pop(int *a, int size)
{
        *a = 0;
        for (int i = 0; i < size; i++) {
                *(a + i) = *(a + i + 1);

        }
}
