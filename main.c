//Matthew Salaciak
//29644490
//A3 - Question 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multi-list.h"



int main(int argc, const char * argv[]) {
    
    
    //parse inventory
    
    //read the text file and create struct's that hold the inventory information
    FILE *file;
    
    //set a decent size char memory to read into
    char line[900][900];
    
    //ints to count lines
    int lineCounter = 0;
    int amountOfLines = 0;
    
    //open file to read
    file = fopen("/Users/matthew/Documents/school/WINTER 2020/COMP 348/A3_29644490/comp-348-question-2/comp-348-question-2/inventory-updated 2020-04-12 05:28:27 -0400.txt", "r");
    
    //read file into char line
    while(fgets(line[lineCounter], 900, file))
    {
        line[lineCounter][strlen(line[lineCounter]) - 1] = '\0';
        lineCounter++;
    }
    
    //assign amountOfLines to LineCouter
    amountOfLines = lineCounter;
    
    //test to see everything is there.
    for(lineCounter = 0; lineCounter < amountOfLines; ++lineCounter)
    {
        printf(" %s\n", line[lineCounter]);
    }
    
    
    //based on the amount of lines read, create carMarker structs from the array
    struct CarMaker manufacturers[amountOfLines];
    struct CarModel carModels[amountOfLines];
    
    //parse through strings and grab everything after the first ',' occurance
    //add this information to the CarModel struct array
    for(lineCounter = 0; lineCounter < amountOfLines; ++lineCounter)
    {
        char *parsedInventory = line[lineCounter];
        while (*parsedInventory != 0 && *(parsedInventory++) != ',') {}
        strcpy(carModels[lineCounter].model_listing, parsedInventory);
    }
    
    
    //test to see if it is there
    printf( "model listing: %s\n", carModels[0].model_listing);
    
    
    
    //parse through the start of each line to grab the manufacturuer name so we can assign it in the CarMaker Struct
    char delim[] = ",";
    
    char *ptr = strtok(line[0], delim);
    int parseCounter = 0;
    while (parseCounter <3)
    {
        strcpy(manufacturers[parseCounter].manufacturer, ptr);
        printf("%s\n", ptr);
        ptr = strtok(line[parseCounter+1], delim);
        
        parseCounter++;
    }
    
    //test to see it is properly transfered
    printf( "brand: %s\n", manufacturers[0].manufacturer);
    
    
    //create car inventory system
    CarMaker * head = NULL;
    head = (CarMaker *) malloc(sizeof(CarMaker));
    if (head == NULL) {
        return 1;
    }
    
   
    //    //input first elements
    head->test = 1; //first
    head -> size =0;
    strcpy(head->manufacturer,manufacturers[0].manufacturer);
    head->next = NULL;
    head->below = NULL;
    
    //
    //
//    insertCarMaker(head,manufacturers[1].manufacturer);
    insertCarModel(head, &carModels[0], manufacturers[0].manufacturer); // first - 1st below
    //
    //
    //
    //    insertCarMaker(head,5);  //2nd
    //    insertCarModel(head, 10, 5); //2nd - 1st below
    //
    //    insertCarMaker(head,7);  //3rd
    //    insertCarModel(head, 13, 7); //3rd - 1st below
    //    insertCarModel(head, 8, 1);
    //
//            printCarMakers(head);
//            printCarModels(head);
        printEntireList(head);
    //
    //    search(head, 7);
    
    
    
    //    free(head);
    
    return 0;
    
    
}


