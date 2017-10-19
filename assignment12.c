#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int E;


void add_end(E item);
void add_pos(int pos, E item);
bool contains(E item);
int size();
bool isEmpty();
E get(int pos);
E remove_element(int pos);
void print_array();

int *a = NULL;
int asize;

int main(int argc, char *argv[])
{
        int item, pos;
        bool check;
        char c,d;
        char buf[32];
        asize = argc - 1;
        a = (int *) calloc(asize, sizeof(int));
        for (int i = 0; i < asize; i++) {
                a[i] = atoi(argv[i + 1]);
        }

        printf("A. Enter the number to add at the end of the list: \n");
        printf("B. Enter the number to add at the position \n");
        printf("C. Does it contain the element? \n");
        printf("D. Is the array empty? \n");
        printf("E. Get the value from the position \n");
        printf("F. Remove the element at position \n");
        printf("G. print the array \n");
        printf("Q. Quit \n");

        while ((c = getchar()) != '\n')
                d = c;
        while ((d != 'q') || (d != 'Q')) {
                switch (d) {

                        case 'a':
                        case 'A':
                                printf("Adding number at the end of the list \n");
                                printf("Enter the number to be added: ");
                                fgets(buf, 32, stdin);
                                item = atoi(buf);
                                printf("item: %d\n", item);
                                add_end(item);
                                print_array();
                                break;
                        case 'b':
                        case 'B':
                                printf("Adding number at the given position \n");
                                printf("Enter the positon: ");
                                fgets(buf, 32, stdin);
                                pos = atoi(buf);

                                printf("Enter the number: ");
                                fgets(buf, 32, stdin);
                                item = atoi(buf);
                                add_pos(pos, item);
                                print_array();
                                break;
                        case 'c':
                        case 'C':
                                printf("Find out if it contains the element \n");
                                printf("Enter the number: ");
                                fgets(buf, 32, stdin);
                                item = atoi(buf);
                                check = contains(item);
                                if (check == true)
                                        printf("%d is in the array :D \n", item);
                                else 
                                        printf("%d is not in the array :( \n", item);
                                break;
                        case 'D':
                        case 'd':
                                check = isEmpty();
                                if (check == true)
                                        printf("Array is empty \n");
                                else 
                                        printf("Array is not empty \n");
                                break;
                        case 'e':
                        case 'E':
                                printf("Getting the value from the given position \n");
                                printf("Enter the position \n");
                                fgets(buf, 32, stdin);
                                pos = atoi(buf);
                                item = get(pos);
                                if (item == -1) {
                                        printf("Error: Value can't be found \n");
                                        break;
                                }
                                printf("the value at position %d is %d \n", pos, get(pos));
                                break;
                        case 'f':
                        case 'F':
                                printf("Rempving element");
                                printf("Enter the position :");
                                fgets(buf, 32, stdin);
                                pos = atoi(buf);
                                printf("The element at %d is %d \n", pos, remove_element(pos));
                                break;
                        case 'g':
                        case 'G':
                                print_array();
                                break;
                        case 'q':
                        case 'Q':
                                printf("Quitting ");
                                free(a); 
                                return 0;                               
                                break;
                }
                printf("A. Enter the number to add at the end of the list: \n");
                printf("B. Enter the number to add at the position \n");
                printf("C. Does it contain the element? \n");
                printf("D. Is the array empty? \n");
                printf("E. Get the value from the position \n");
                printf("F. Remove the element at position \n");
                printf("G. Print the array \n");
                printf("Q. Quit \n");
        
                while ((c = getchar()) != '\n')
                        d = c;
        }
        return 0;
}
void add_end(E item)
{
                a = (int *) realloc (a, sizeof(int) * (asize + 1));
                if (!a) {
                        free(a);
                        return;
                }
                asize++;
                *(a + asize - 1) = item;
}
void add_pos(int pos, E item)
{
        if ((pos > asize) || (pos < 0)){
                printf("Error: Position can't be greater or equal to size. Array indexing begins at 0. \n\n");
                return;
        } else {
                a = (int *) realloc (a, sizeof(int) * (asize + 1));
                if (!a) {
                        free(a);
                        return;
                }
                asize++;
                for (int i = asize - 1; i > pos; i--) {
                        *(a + i) = *(a + i - 1);
                }
                *(a + pos) = item;
        }
}
bool contains(E item) 
{
        for (int i = 0; i < asize; i++) {
                if(a[i] == item)
                        return 1;
        }
        return 0;
}
int size()
{
        return asize;
}
bool isEmpty()
{
        if (asize == 0)
                return 1;
        return 0;
}
E get(int pos)
{
        if ((pos < 0) || (pos > asize))
                return -1;
        else 
                return *(a + pos);
}
E remove_element (int pos)
{
        if (pos < 0)
                pos = 0;
        else if (pos >= asize)
                pos = asize - 1;
        else {
                for (int i = pos; i < asize - 1; i++) {
                        *(a + i) = *(a + i + 1);
                }
                a = (int *) realloc (a, sizeof(int) * (asize - 1));
                (asize)--;
        }
        return get(pos);
}
void print_array()
{
        for (int i = 0; i < asize; i++) {
                printf("%d, ", *(a + i));
        }
        printf(". \n");
}