//Matthew Salaciak
//29644490
//A3 - Question 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multi-list.h"

void convertListings2Catalougue(CarMaker *head,char *fileName);
void Add2Inventory (CarMaker *head, char * car);

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
    
    
    
    //            printEntireList(head);
    //            Add2Inventory(head, "Honda, CRV, 102km");
    //            printEntireList(head);
    
    
//    search(head, "Toyota");
    
    
    
    free(head);
    
    return 0;
    
    
}


void convertListings2Catalougue(CarMaker *head,char *fileName){
    FILE *file;
    
    //set a decent size char memory to read into
    char line[900][900];
    
    //ints to count lines
    int lineCounter = 0;
    int amountOfLines = 0;
    
    //open file to read
    file = fopen(fileName, "r");
    
    
    //read file into char line
    while(fgets(line[lineCounter], 900, file))
    {
        line[lineCounter][strlen(line[lineCounter]) - 1] = '\0';
        lineCounter++;
        
    }
    
    
    amountOfLines = lineCounter;
    
    
    
    
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
    
    
    
    //parse through the start of each line to grab the manufacturuer name so we can assign it in the CarMaker Struct
    char delim[] = ",";
    
    char *ptr = strtok(line[0], delim);
    
    int parseCounter = 0;
    while (parseCounter <amountOfLines)
    {
        strcpy(carModels[parseCounter].brand, ptr);
        strcpy(manufacturers[parseCounter].manufacturer, ptr);
        
        
        ptr = strtok(line[parseCounter+1], delim);
        
        
        parseCounter++;
    }
    
    
    
    //create car inventory system
    
    //    //input first elements
    head -> size =0;
    strcpy(head->manufacturer,manufacturers[0].manufacturer);
    head->next = NULL;
    head->below = NULL;
    
    insertCarModel(head, &carModels[0], manufacturers[0].manufacturer); //first - 1st below
    
    //starts at lineCounter 1 because we already used the first array position to initialize the multi-linked list
    for(lineCounter=1; lineCounter < amountOfLines; lineCounter++){
        insertCarMaker(head,manufacturers[lineCounter].manufacturer);
        insertCarModel(head, &carModels[lineCounter], carModels[lineCounter].brand);
        
        
        
    }
    
    
    
}

void Add2Inventory (CarMaker *head, char * car) {
    
    //    char line[900][900];
    
    //ints to count lines
    int lineCounter = 1;
    int amountOfLines = 1;
    
    
    amountOfLines = lineCounter;
    struct CarModel newCar;
    struct CarMaker newMaker;
    
    
    
    
    
    char *parsedInventory = car;
    while (*parsedInventory != 0 && *(parsedInventory++) != ',') {}
    strcpy(newCar.model_listing, parsedInventory);
    
    
    
    
    
    
    char listing[25];
    strcpy(listing, car);
    char delim[] = ",";
    
    char *ptr = strtok(listing, delim);
    
    strcpy(newCar.brand, ptr);
    strcpy(newMaker.manufacturer, ptr);
    
    insertCarMaker(head,newMaker.manufacturer);
    insertCarModel(head, &newCar, newCar.brand);
    

}
