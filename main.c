//Matthew Salaciak
//29644490
//A3 - Question 2
// this is a C implementation of question 5 which was done in ruby
// I used the COMP 348 Course pack, and these two text books
// The C Programming Language by Dennis Ritchie and C Programming: A Modern Approach, 2nd Edition  by K.N. King
//also I used Dr. Hanna's notes from our COMP 249 course on linked lists implemeneted in java as a refresher


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
    
    
    
    
    //print out of inventory
    printEntireList(head);
    
    //add a car to inventory (this example shows it being added to Honda brand
    Add2Inventory(head, "Honda,RAV4,SE,1231km,2017,Sedan,AWD,auto,12516A,Used,5.5L/100km,{AC, Heated Seats, Heated Mirrors, Keyless Entry}");
    //see updated list of inventory with newly added car
    printEntireList(head);
    //this example shows how it creates a new carMaker object for this listing
    Add2Inventory(head, "BMW,328,XI,121km,2020,coupe,AWD,auto,1235Q,new,5.5L/100km,{AC, Heated Seats, Heated Mirrors, Keyless Entry}");
    
    //see updated list of inventory with newly added car
    printEntireList(head);
    
    
    //search funciton...you can search by everything except features / km / fuel ecomomy.  I left these out (Even though they are technically  (km/fuel ecomoy) implemented)
    //because i felt they were not useful in a inventory search system like ours. Also I wasn't even sure if we were suppose to create a search for eveything or just
    //car brand so i decided to implement a search for eveything i felt that made sense which is almost every paramter (i did the same with ruby Q5)
    
    //search for ID number
    searchInventory(head, "18131A");
    //search for status
    searchInventory(head, "Used");
    //Search by brand
    searchInventory(head, "Honda");
    //search for newly added brand
    searchInventory(head, "BMW");
    //search for trim
    searchInventory(head, "SE");
    
    
    //saves the new inventory to a text file - again please change to your file path.
    saveCatalogue2File(head,"/Users/matthew/Documents/school/WINTER 2020/COMP 348/A3_29644490/comp-348-question-2/comp-348-question-2/inventory-updated-C-program.txt");
    
    //clear memory
    free(head);
    
    return 0;
    
    
}

