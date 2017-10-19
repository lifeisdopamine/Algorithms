#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_array(int *a, int size);
void insert_element (int *a, int *size, int pos, int tmp);
void remove_element (int *a, int *size, int pos);
void swap_elements (int *a, int size, int pos);
void rev_swap(int *a, int size, int pos);
void replace_element( int *a, int size, int pos, int tmp);
int find_element(int *a, int size, int tmp);
void print_array (int *a, int size);


int main(void)
{
        int size, pos, tmp;
        char buf[32], c, d;
        int *a = NULL;
        printf("Enter the number of elements in the array: ");
        fgets(buf, 32, stdin);
        size = atoi(buf);
        a = (int *) calloc(size, sizeof(int));
        if (!a)
                return 0;
        init_array(a, size);
                
        printf("Here are the choices: \n");
        printf("A. Add element at certain position \n");
        printf("B. Remove element at certain position \n");
        printf("C. Find the particular element \n");
        printf("D. Replace an element with index \n");
        printf("E. Replace an element with values \n");
        printf("F. Counting elements \n");
        printf("G. Printing array \n");
        
        while ((c = getchar()) != '\n')
                d = c;

        while ((d != 'q') || (d != 'Q')) {
                switch (d) {
                        case 'a':
                        case 'A':
                                printf("Adding element: \n\n");
                                printf("Enter the position: ");
                                fgets (buf, 32, stdin);
                                pos = atoi(buf);
                                printf("Enter the number: ");
                                fgets (buf, 32, stdin);
                                tmp = atoi (buf);
                                insert_element (a, &size, pos, tmp);
                                if (!a)
                                        return 0;
                                print_array (a, size);
                                break;
                        case 'b':
                        case 'B':
                                printf("Removing element: \n\n");
                                printf("Enter the position: ");
                                fgets (buf, 32, stdin);
                                pos = atoi (buf);
                                remove_element (a, &size, pos);
                                print_array (a, size);
                                break;
                        case 'c':
                        case 'C':
                                printf("Finding an element: ");
                                printf("Enter the element:");
                                fgets (buf, 32, stdin);
                                tmp = atoi (buf);
                                pos = find_element (a, size, tmp);
                                if (pos >= 0)
                                        printf("Element is on place %d (0 indexing included) \n", pos);
                                else 
                                        printf("Error: I couldn't find the element :( \n");
                                print_array (a, size);
                                break;
                        case 'd':
                        case 'D':
                                printf("Replacing an element with index: \n\n");
                                printf("Enter index of an element: ");
                                fgets (buf, 32, stdin);
                                pos = atoi (buf);
                                printf("Enter the replacing value: ");
                                fgets (buf, 32, stdin);
                                tmp = atoi (buf);
                                if ((pos < size) && (pos >= 0))
                                        replace_element(a, size, pos, tmp);
                                else {
                                        printf("Error: Index has to be greater or equal to zero \n\n");
                                        break;
                                }
                                print_array (a, size);
                                break;
                        case 'e':
                        case 'E':
                                printf("Replacing an element with Value: \n\n");
                                printf("Enter the number you want it to be replaced: ");
                                fgets (buf, 32, stdin);
                                tmp = atoi (buf);
                                pos = find_element(a, size, tmp);
                                if (pos >= 0)
                                        replace_element(a, size, pos, tmp);
                                else {
                                        printf("Error: Element not found \n\n");
                                        break;
                                }
                                print_array (a, size);
                                break;
                        case 'f':
                        case 'F':
                                printf("Counting elements \n\n");
                                printf("Size of an array is %d \n", size);
                                break;
                        case 'g':
                        case 'G':
                                print_array  (a, size);
                                break;
                        case 'q':
                        case 'Q':
                                printf("You're exiting. Bye-bye! \n\n");
                                free(a);
                                return 0;
                        default:
                                printf("Error: Enter the right option. \n");
                }  
                printf("Here are the choices: \n");
                printf("A. Add element at certain position \n");
                printf("B. Remove element at certain position \n");
                printf("C. Find the particular element \n");
                printf("D. Replace an element with index \n");
                printf("E. Replace an element with values \n");
                printf("F. Counting elements \n");
                printf("G. Printing array \n");
                
                while ((c = getchar()) != '\n')
                        d = c;     
        }
        free(a);
        return 0;
}

void init_array (int *a, int size)
{
        char buf[32];

        for (int i = 0; i < size; i++) {
                printf("Enter the number at position %d: ",i);
                fgets(buf, 32, stdin);
                *(a + i) = atoi(buf);
        }
}
void insert_element (int *a, int *size, int pos, int tmp)
{
        if ((pos > *size) || (pos < 0)){
                printf("Error: Position can't be greater or equal to size. Array indexing begins at 0. \n\n");
                return;
        } else {
                a = (int *) realloc (a, sizeof(int) * (*size + 1));
                if (!a) {
                        free(a);
                        return;
                }
                (*size)++;
                swap_elements(a, *size, pos);
                *(a + pos) = tmp;
        }
}
void swap_elements (int *a, int size, int pos)
{
        for (int i = size - 1; i > pos; i--) {
                 *(a + i) = *(a + i - 1);
        }
} 
void rev_swap (int *a, int size, int pos)
{
        for (int i = pos; i < size - 1; i++) {
                *(a + i) = *(a + i + 1);
        }
}
void remove_element (int *a, int *size, int pos)
{
        rev_swap (a, *size, pos);
        a = (int *) realloc (a, sizeof(int) * (*size - 1));
        (*size)--;
}
void replace_element (int *a, int size, int pos, int tmp)
{
        *(a + pos) = tmp;
}
int find_element(int *a, int size, int tmp)
{
        int i = 0;
        for (i = 0; i < size; i++)
                if (*(a + i) == tmp)
                        return i;
        return -1;
}
void print_array (int *a, int size)
{
        printf("Array elements: ");
        for (int i = 0; i < size; i++) 
                printf("%d, ", *(a + i));
        printf(". \n");
}
