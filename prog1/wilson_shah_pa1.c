/**
* Programming Assignment 1
* Author: Brendan Wilson && Yash Shah
* Date: 9/22/17
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* For boolean data type */
#define LEN 1024

typedef int E;

void add_end(E item);
void add(E pos, E item);
bool contains(E item);
E size(void);
bool isEmpty(void);
E get(E pos);
E remove_elem(E pos);
void list(void);

E *a;
E *b;
E elem_count = 0;
E i;

E main(void)
{
        char buf[LEN];
        printf("Input the amount of elements in the list: ");
        
        fgets(buf, LEN, stdin);
        sscanf(buf, "%d", &elem_count);
        
        a = malloc(sizeof(E) * elem_count);
        if (!a) // error checking for malloc
                return 0;
        b = malloc(sizeof(E) * elem_count);
        if (!b) // error checking for malloc
                return 0;
                
        for (i = 0; i < elem_count; i++) {
                printf("Input the element at pos %d: ", i);
                fgets(buf, LEN, stdin);
                sscanf(buf, "%d", &a[i]); //all invalid elements default to 0
        }
        printf("\n");
        LOOP: while(1)
        {
                E selection = 0;
                printf("Add Element to End of Array: 1\nAdd Element to Array: 2\n"
                       "See if Element is contained in Array: 3\nSee Size of Array: 4\n"
                       "See if the Array is Empty: 5\nGet the Value of an Element at a Position: 6\n"
                       "Remove Element from Array: 7\nList All Elements in the Array: 8\n"
                       "Quit: 9\n>> ");
                fgets(buf, LEN, stdin);
                sscanf(buf, "%d", &selection);

                if (selection == 1) {
                        /*If the selection is 1 then it will add values to the end of the array */
                        E item = 0;
                        printf("Enter the value of the Element to add: ");
                        fgets(buf, LEN, stdin);
                        sscanf(buf, "%d", &item);
                        add_end(item);
                        printf("...Done\n\n");
                }
                else if (selection == 2) {
                        /* If user enters 2, it will ask for values as well as position to add */
                        E item = 0;
                        E pos = 0;
                        printf("Enter the value of the Element to add: ");
                        fgets(buf, LEN, stdin);
                        sscanf(buf, "%d", &item);
                        printf("Enter the pos of the Element in the Array: ");
                        fgets(buf, LEN, stdin);
                        sscanf(buf, "%d", &pos);
                        if (pos > elem_count || pos < 0) {
                        /*Error checking for value of position */
                                printf("Invalid position, retrying\n\n");
                                goto LOOP;
                        }
                        add(pos, item);
                        printf("...Done\n\n");
                }
                else if (selection == 3) {
                        /*If selection is 3, then it will check if the given value is in the array or not */
                        if (elem_count == 0) {
                                printf("Empty Array, no elements to index\n\n");
                                goto LOOP;
                        }
                        E item = 0;
                        printf("Enter the value of the Element to check: ");
                        fgets(buf, LEN, stdin);
                        sscanf(buf, "%d", &item);
                        E isFound = 0;
                        isFound = contains(item);
                        if (isFound == 0)
                                printf("Item not found in the Array\n\n");
                        else if (isFound == 1)
                                printf("Item is in the Array\n\n");
                }
                else if (selection == 4) {
                        /*Selection 4 to find the size of the array */
                        E size_arr = 0;
                        size_arr = size();
                        if (size_arr != 1)
                                printf("Array contains %d Elements\n\n", size_arr);
                        else if (size_arr == 1)
                                printf("Array contains %d Element\n\n", size_arr);
                }
                else if (selection == 5) {
                        /* Selection 5 to check if array is empty */
                        E empty = 0;
                        empty = isEmpty();
                        if (empty == 0)
                                printf("Array is not empty\n\n");
                        else if (empty == 1)
                                printf("Array is empty\n\n");
                }
                else if (selection == 6) {
                        /* Selection 6 to get array element at the given position */
                        if (elem_count == 0) {
                                printf("Cannot index empty Array\n\n");
                                goto LOOP;
                        }
                        E pos = 0;
                        printf("Enter the pos of the Element in the Array: ");
                        fgets(buf, LEN, stdin);
                        sscanf(buf, "%d", &pos);
                        if (pos >= elem_count || pos < 0) {
                                printf("Invalid pos input\n\n");
                                goto LOOP;
                        }
                        E item = 0;
                        item = get(pos);
                        printf("Item at pos %d has a value of %d\n\n", pos, item);
                }
                else if (selection == 7) {
                        /*Selection 7 to remove element at position */
                        if (elem_count == 0) {
                                printf("Cannot delete from empty Array\n\n");
                                goto LOOP;
                        }
                        E pos = 0;
                        printf("Enter the pos of the Element in the Array: ");
                        fgets(buf, LEN, stdin);
                        sscanf(buf, "%d", &pos);
                        E item = 0;
                        if (pos >= elem_count || pos < 0) {
                                printf("Invalid pos input\n\n");
                                goto LOOP;
                        }
                        item = remove_elem(pos);
                        printf("...Done\nItem at position %d has been removed, it's value was %d\n\n", pos, item);
                }
                else if (selection == 8) {
                        /* To check if array is empty of not */
                        if (elem_count == 0) {
                                printf("Array is empty and has no contents\n\n");
                                goto LOOP;
                        }
                        list();
                }
                else if (selection == 9) {
                         /* To Quit*/
                        printf("Goodbye!\n");
                        free(a);
                        free(b);
                        exit(1);
                }
                else {
                        printf("Invalid settings entered, retrying\n\n");
                        goto LOOP;
                }
        }
}

//adds element to the end of list
void add_end(E item)
{
        elem_count++;
        a = realloc(a, sizeof(E) * elem_count);
        a[elem_count - 1] = item;
}

//adds element to any i in the list
void add(E pos, E item)
{
        if (pos == (elem_count - 1))
                add_end(item);
        else {
                elem_count++;
                a = realloc(a, sizeof(E) * elem_count);
                b = realloc(b, sizeof(E) * elem_count);
                for (i = 0; i < pos; i++) {
                        b[i] = a[i];
                }
                b[pos] = item;
                for (i = pos + 1; i < elem_count; i++) {
                        b[i] = a[i - 1];
                }
                for (i = 0; i < elem_count; i++) {
                        a[i] = b[i];
                }
        }
}

//returns 0 if elem not found or 1 if elem found
bool contains(E item)
{
        E isFound = 0;
        for (i = 0; i < elem_count; i++) {
                if (item == a[i])
                        isFound = 1;
        }
        return isFound;
}

//prints the size of the array
E size(void)
{
        return elem_count;
}

//returns 0 if not empty or 1 if empty
bool isEmpty(void)
{
        E empty = 0;
        if (elem_count == 0)
                empty = 1;
        return empty;
}

//returns the value of the element at a pos
E get(E pos)
{
        return(a[pos]);
}

//removes an element from the list
E remove_elem(E pos)
{
        E item = 0;
        item = a[pos];
        elem_count--;
        b = realloc(b, sizeof(E) * elem_count);
        for (i = 0; i < pos; i++)
                b[i] = a[i];
        for (i = pos; i < elem_count; i++)
                b[i] = a[i + 1];
        for (i = 0; i < elem_count; i++) {
                a[i] = b[i];
        }
        return item;
}

//lists all elements
void list(void)
{
        for (i = 0; i < elem_count; i++)
                printf("Elem %d = %d\n", i, a[i]);
        printf("\n");
}
