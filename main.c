//Matthew Salaciak
//29644490
//A3 - Question 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multi-list.h"



int main(int argc, const char * argv[]) {
    
    //declare head of top list elements
    node * head = NULL;
    head = (node *) malloc(sizeof(node));
    if (head == NULL) {
        return 1;
    }
    
    
    head->test = 1; //first
    head->next = NULL;
    head->below = NULL;
    
    insertCarModel(head, 2, 1); // first - 1st below
    

    
    insertCarMaker(head,5);  //2nd
    insertCarModel(head, 10, 5); //2nd - 1st below
    
     insertCarMaker(head,7);  //3rd
     insertCarModel(head, 13, 7); //3rd - 1st below
    
//    printCarMakers(head);
//    printCarModels(head);
    printEntireList(head);
    
//
//    CarMaker;
//
//    FILE *file;
//
//
//    char line[900][900];
//    char fname[20];
//
//    int i = 0;
//    int tot = 0;
//
//
//    file = fopen("/Users/matthew/Documents/school/WINTER 2020/COMP 348/A3_29644490/comp-348-question-2/comp-348-question-2/inventory-updated 2020-04-12 05:28:27 -0400.txt", "r");
//
//    while(fgets(line[i], 900, file))
//    {
//        line[i][strlen(line[i]) - 1] = '\0';
//        i++;
//    }
//    tot = i;
//    printf("\n The content of the file %s  are : \n",fname);
//    for(i = 0; i < tot; ++i)
//    {
////        printf(" %s\n", line[i]);
//    }
//    printf("\n");
//
//
//    printf(" %d\n" , i);
//
//
//    char delim[] = ",";
//
//        char *ptr = strtok(line[0], delim);
//    while (ptr != NULL)
//    {
//        printf("'%s'\n", ptr);
//        ptr = strtok(NULL, delim);
//    }
//
//
//
//
    
 printf( "Welcome to C!\n" );
//      printf("The integer is: %d\n", 5);
    return 0;
    
    
}


