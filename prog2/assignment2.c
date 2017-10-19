
#include "a2ar.h"

int main(int argc, char *argv[])
//int main(void)
{
        int no = argc - 1;
        int i = 0;
        //char buf[32];
        E *mainStack, *OddStack,*EvenStack;
        mainStack = OddStack = EvenStack = NULL;
        int sizeM = 0, sizeO = 0, sizeE = 0;
        //mainStack = (int *) malloc(sizeof(int));
        //sizeM++;
        for (i = 1; i <= no; i++) {
                int q = atoi(argv[i]);
                mainStack = push(mainStack, &sizeM, q);
                printf("Peek of mainStack: %d \n", peek(mainStack));
        }
        printf("Peek of mainStack: %d \n", peek(mainStack));
        print_array(mainStack, sizeM);
        
        for(i = 0; i < sizeM; i++) {
                if ((mainStack[i] % 2) == 0) {
                        /*Even Number */
                        EvenStack = push(EvenStack, &sizeE, mainStack[i]);
                        printf("\n Peek of Even Stack: %d \n", peek(EvenStack));
                } else {
                        /*Odd Number */
                        OddStack = push(OddStack, &sizeO, mainStack[i]);
                        printf("\n Peek of Odd Stack: %d \n", peek(OddStack));
                }
        }
        printf("Odd Stack: \n");
        print_array(OddStack, sizeO);

        printf("\n\n\n");
        printf("Even Stack: \n");
        print_array(EvenStack, sizeE);
        for (i = 0; i < sizeM; i++)
                pop(mainStack, sizeM);

        for (i = 0; i < sizeO; i++)
                pop(OddStack, sizeO);

        for (i = 0; i < sizeE; i++)
                pop(EvenStack, sizeE);
        free(mainStack);
        free(OddStack);
        free(EvenStack);
        return 0;
}
