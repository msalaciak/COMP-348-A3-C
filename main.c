//Matthew Salaciak
//29644490
//A3 - Question 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multi-list.h"



int main(int argc, const char * argv[]) {
    
    
    //create the head of our multi-linked list
    CarMaker * head = NULL;
    head = (CarMaker *) malloc(sizeof(CarMaker));
    if (head == NULL) {
        return 1;
    }
    
    //call the convertListing2Catalougue, so we can create the inventory system from the file!
    // note you will have to change this to your absolute path - I made this with xcode and setting up relative paths is a nightmare
    
    convertListings2Catalougue(head, "/Users/matthew/Documents/school/WINTER 2020/COMP 348/A3_29644490/comp-348-question-2/comp-348-question-2/inventory-updated 2020-04-12 05:28:27 -0400.txt");
    
    
    
//                printEntireList(head);
                Add2Inventory(head, "Toyota,RAV4,SE,1231km,2017,Sedan,AWD,auto,12516A,Used,5.5L/100km,{AC, Heated Seats, Heated Mirrors, Keyless Entry}");
                printEntireList(head);
    
    
    searchInventory(head, "SE");
    
    
    
    free(head);
    
    return 0;
    
    
}

