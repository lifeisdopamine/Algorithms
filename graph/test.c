#include <stdio.h>
#include <stdlib.h>

struct node_t {
        char name[10];
        int k;
};

int compare(struct node_t *n1, struct node_t *n2);
int main(void)
{
        struct node_t node[] = {{"Yash", 32}, {"Ripa", 12} };
        size_t size = sizeof(node) / sizeof(node[0]);
        printf("Before q sort\n");
        printf("Name: %s \n", node[0].name);
        printf("Name 2: %s\n", node[1].name);
        qsort(node, size, sizeof(struct node_t), compare);
        printf("Name: %s \n", node[0].name);
        printf("Name 2: %s\n", node[1].name);
        return 0;
}
int compare(struct node_t *n1, struct node_t *n2)
{       
        return n1 -> k - n2 -> k;
}
