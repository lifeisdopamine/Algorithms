#include <stdio.h>
#include <stdlib.h>

int main(void)
{       
        int *a = malloc(4*sizeof(int));
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        a[3] = 4;
        for(int i = 0; i < 4; i++)
                printf("Array before: %d \n", a[i]);
        printf("size of array: %zu \n", sizeof(a)/sizeof(a[0]));
        a = realloc(a, 3 * sizeof(int));
        for(int i = 0; i < 3; i++)
                printf("Array after: %d \n", a[i]);
        printf("size of array: %zu\n", sizeof(a)/sizeof(a[0]));
        return 0;
}